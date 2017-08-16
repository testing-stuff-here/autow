<?php

/** 
 * @file 
 * Administration page callbacks for the content_complete module. 
 */

/**
 * Menu Callback Function.
 */
function content_complete_admin_settings() {
  return drupal_get_form('content_complete_admin_settings_form');
}

/**
 * Admin settings form.
 */
function content_complete_admin_settings_form() {
  $form['description'] = array(
    '#type' => 'item',
    '#description' => t('Rebuild the complete cache for all nodes of a Content-Complete-enabled type, using the Batch API. You need to select the fields for completeness checks per <a href="@content-types">content type</a>.', array('@content-types' => url('admin/structure/types'))),
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Rebuild Cache'),
  );
  
  return $form;
}

/** 
 * Handle form submission by beginning batch operation. 
 */
function content_complete_admin_settings_form_submit($form_id, &$form_state) {
  $num_operations = 1;
  $operations = array();
  for ($i = 0; $i<$num_operations; $i++) {
    $operations[] = array('content_complete_rebuild_cache', array());
  }

  $batch = array(
    'title' => t('Rebuilding Cache'),
    'operations' => $operations,
    'finished' => 'content_complete_rebuild_cache_finished', 
    'init_message' => t('The Content Complete cache rebuilding process is beginning.'), 
    'error_message' => t('The Content Complete cache rebuilding process encountered an error.'), 
    'file' => drupal_get_path('module', 'content_complete') . '/content_complete.admin.inc',
  ); 
  batch_set($batch); 
}



/** 
 * Batch callback operation.
 * 
 * @param $context 
 *  Batch context containing state information. 
 */ 
function content_complete_rebuild_cache(&$context) {
  // How many node cache rebuilds to process in each batch.
  $limit = 50;
  
  // Initialize sandbox the first time through.
  if (empty($context['sandbox'])) {
    // Clear the cache, we will rebuild it entirely.
    content_complete_clear_cache();
    
    // Types tagged for completeness (can be empty)
    $types = array_keys(content_complete_get_enabled_types()); 

    // Count the number of cache rebuilds we will have to do.
    $max = db_select('node')->condition('type', $types, 'IN')->countQuery()->execute()->fetchField();
    
    $context['sandbox']['progress'] = 0;
    $context['sandbox']['current_nid'] = 0;
    $context['sandbox']['list'] = $types;
    $context['sandbox']['max'] = $max;
  }

  // Retrieve range of nids to rebuild cache for
  $result = db_select('node', 'n')
              ->condition('type', $context['sandbox']['list'], 'IN')
              ->condition('nid', $context['sandbox']['current_nid'], '>')
              ->orderBy('nid')
              ->fields('n', array('nid'))
              ->range(0, $limit)
              ->execute();

  // Loop over all the nodes to process.
  foreach ($result as $record) {
    // Rebuild the cache, the actual operation.
    $node = node_load($record->nid);
    content_complete_get_data($node);
    
    // Store some result for post-processing in the finished callback.
    $context['results'][] = $node->nid;
        
    // Update progress information. 
    $context['sandbox']['progress']++; 
    $context['sandbox']['current_nid'] = $node->nid; 
    $context['message'] = t('Rebuilding complete cache for node %nid', array('%nid' => $node->nid)); 
  }
  
  // Let the batch engine know how close we are to completion. 
  if ($context['sandbox']['progress'] != $context['sandbox']['max']) { 
    $context['finished'] = $context['sandbox']['progress'] / $context['sandbox']['max']; 
  }
}

function content_complete_rebuild_cache_finished($success, $results, $operations) {  
  if ($success) {
    $message = format_plural(count($results), 'One node cache rebuilt.', '@count node caches rebuilt.');
    drupal_set_message($message); 
  } 
  else { 
    // A fatal error occurred during batch processing. 
    $error_operation = reset($operations); 
    $operation = array_shift($error_operation); 
    $arguments = array_shift($error_operation); 
    $arguments_as_string = implode(', ', $arguments);
    
    watchdog('content_complete', "Rebuild cache: error when calling operation '%s'('%s')", array($operation, $arguments_as_string)); 
    drupal_set_message(t('An error occurred and has been recorded in the system log.'), 'error'); 
  }
}

