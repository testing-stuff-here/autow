<?php

/**
 * @file
 * Contains forms and functions for administration
 *
 */

/**
 * Generates form for aw-taxonomy-mapping page
 */
function aw_taxonomy_mapping_form($form, &$form_state){

  $technology_options = _aw_new_vocab_term_options(13);
  $topics_options = _aw_new_vocab_term_options(14);

  // First get an array that represents the vocabulary terms
  // in a heirarchical list
  $automation_strategies = _aw_taxonomy_vocab_heirarchy(2); // 2 is the vid of Automation Strategies vocab

  // See if this form's values are saved
  $mapping_cache = variable_get('taxonomy_mapping');
  if($mapping_cache){
    $mapping_cache = json_decode($mapping_cache, true);
  }

  $form['taxonomy_map'] = array(
    '#tree' => TRUE,
    '#theme' => 'aw_page_alteration_taxonomy_map_table',
  );

  foreach($automation_strategies as $key => $row){
    $form['taxonomy_map'][$row['tid']]['term'] = array(
      '#markup' => str_repeat("&nbsp;", $row["depth"] * 8) . $row['name'],
    );
    $form['taxonomy_map'][$row['tid']]['include_children'] = array(
      '#type' => ($row["hasChild"]) ? 'checkbox' : 'value',
      '#default_value' => ($mapping_cache) ? $mapping_cache[$row['tid']]['include_children'] : 0,
    );
    $form['taxonomy_map'][$row['tid']]['delete'] = array(
      '#type' => 'checkbox',
      '#default_value' => ($mapping_cache) ? $mapping_cache[$row['tid']]['delete'] : 0,
    );
    $form['taxonomy_map'][$row['tid']]['new_term_technology'] = array(
      '#type' => 'select',
      '#options' => $technology_options,
      '#required' => FALSE,
      '#empty_option' => ' -- Select -- ',
    );
    $form['taxonomy_map'][$row['tid']]['new_term_topics'] = array(
      '#type' => 'select',
      '#options' => $topics_options,
      '#required' => FALSE,
      '#empty_option' => ' -- Select -- ',
    );
    if($mapping_cache){
      if(strlen($tech_term = $mapping_cache[$row['tid']]['new_term_technology']) > 0){
        $form['taxonomy_map'][$row['tid']]['new_term_technology']['#default_value'] = $tech_term;
      }
      if(strlen($topic_term = $mapping_cache[$row['tid']]['new_term_topics']) > 0){
        $form['taxonomy_map'][$row['tid']]['new_term_topics']['#default_value'] = $topic_term;
      }
    }
  }
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => 'Submit',
  );

  return $form;
}

/**
 * Submit Handler
 */
function aw_taxonomy_mapping_form_submit($form, &$form_state){
  $mapping_cache = $form_state['values']['taxonomy_map'];
  foreach($mapping_cache as $key => $value){
    if(strlen($value["new_term_technology"]) > 0){
      $mapping_cache[$key]["new_term"] = $value["new_term_technology"];
    }
    elseif(strlen($value["new_term_topics"]) > 0){
      $mapping_cache[$key]["new_term"] = $value["new_term_topics"];
    }
    else {
      $mapping_cache[$key]["new_term"] = FALSE;
    }
  }
  $mapping_cache = json_encode($mapping_cache);
  variable_set('taxonomy_mapping', $mapping_cache);
}

/**
 * Creates an array that represents the terms in a vocab, in a heirarchical manner
 *
 * @param int $vid Vocabulary Id
 */
function _aw_taxonomy_vocab_heirarchy($vid){
  $terms = taxonomy_get_tree($vid, 0, 1); // The 1 for the third param specifies only get first level of terms
  $heirarchy = _aw_taxonomy_construct_heirarchy($terms);
  $list = _aw_taxonomy_construct_list($heirarchy);

  return $list;
}

/**
 * Recursively constructs an array that represents a heirarchical vocab tree, where
 * the key is the tid of the term, and the value is either FALSE if there are no children
 * or it is an array containing all children
 *
 * @param array $terms An array of term objects for a given depth level in a vocab tree
 */
function _aw_taxonomy_construct_heirarchy($terms){
  $term_heirarchy = array();
  foreach($terms as $key => $value){
    if(sizeof($children = taxonomy_get_children($value->tid)) > 0){
      $children_array = _aw_taxonomy_construct_heirarchy($children);
      $term_heirarchy[$value->tid] = $children_array;
    }
    else {
      $term_heirarchy[$value->tid] = FALSE;
    }
  }
  return $term_heirarchy;
}

/**
 * Given an array constructed by _aw_taxonomy_construct_heirarchy, this function
 * recursively constructs an array where each value represents one "node" in the
 * vocab tree, for example
 * Term 1
 * Term 1 > Sub 1
 * Term 1 > Sub 1 > Sub 2
 *
 * @param array $term_heir Term heirarchy array constructed by _aw_taxonomy_construct_heirarchy
 */
function _aw_taxonomy_construct_list($term_heir){
  $term_list = array();
  foreach($term_heir as $tid => $t_child){
    $term = taxonomy_term_load($tid);
    if($t_child){
      $term_list[] = array(
        "name" => $term->name,
        "tid" => $term->tid,
        "hasChild" => TRUE,
        "depth" => 0,
      );
      $children = _aw_taxonomy_construct_list($t_child);
      foreach($children as $child){
        $child["name"] = $term->name . " &raquo; " . $child["name"];
        $child["depth"] = 1 + $child["depth"];
        $term_list[] = $child;
      }
    }
    else {
      $term_list[$term->tid] = array(
        "name" => $term->name,
        "tid" => $term->tid,
        "hasChild" => FALSE,
        "depth" => 0,
      );
    }
  }
  return $term_list;
}

/**
 * AJAX Callback for the New Term field on the taxonomy map form
 */
function _aw_taxonomy_new_term_callback($form, &$form_state){
  if(isset($form_state['triggering_element'])){
    $trigger = $form_state['triggering_element']['#parents'][1];
    return $form['taxonomy_map'][$trigger]['new_terms'];
  }
}

/**
 * Constructs an array that will be used for the '#options' key for the new term field
 * in the taxonomy_map form.
 *
 * @param int $vid Vocabulary id
 */
function _aw_new_vocab_term_options($vid){
  $terms = taxonomy_get_tree($vid, 0, 1);
  $heirarchy = _aw_taxonomy_construct_heirarchy($terms);
  $options_array = array();
  foreach($heirarchy as $tid => $value){
    $term = taxonomy_term_load($tid);
    $options_array[$tid] = $term->name;
    if($value){
      foreach($value as $sub_tid => $sub_value){
        $sub_term = taxonomy_term_load($sub_tid);
        $options_array[$sub_tid] = ' --' . $sub_term->name;
      }
    }
  }

  return $options_array;
}

/**
 * Theme function
 */
function theme_aw_page_alteration_taxonomy_map_table($vars){
  $element = $vars['element'];
  $rows = array();
  foreach(element_children($element) as $key){
    $rows[] = array(
      array('data' => render($element[$key]['term'])),
      array('data' => render($element[$key]['include_children'])),
      array('data' => render($element[$key]['delete'])),
      array('data' => render($element[$key]['new_term_technology'])),
      array('data' => render($element[$key]['new_term_topics'])),
    );
  }

  $header = array(t('Term'), t('Include All Children'), t('Delete Term'),t('Technology Vocab'), t('Topics Vocab'));
  return theme('table', array('header'=>$header, 'rows'=>$rows));
}

/**
 * Generates form for the actual taxonomy update operation
 */
function aw_taxonomy_perform_update($form, &$form_state){
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => 'Perform Taxonomy Bulk Update',
  );

  return $form;
}

/**
 * Submit handler
 */
function aw_taxonomy_perform_update_submit($form, &$form_state){
  _aw_taxonomy_update_bulk();
}

/**
 * Uses batch api
 */
function _aw_taxonomy_update_bulk(){
  $batch = array(
    'operations' => array(
      array('_aw_taxonomy_update_bulk_process', array()),
    ),
    'finished' => '_aw_taxonomy_update_bulk_finished',
    'title' => t('Batch updating nodes'),
    'progress_message' => t('Processed @current out of @total'),
    'file' => drupal_get_path('module', 'aw_page_alteration') . '/includes/aw_page_alteration.admin.inc',
  );
  batch_set($batch);
}

function _aw_taxonomy_update_bulk_process(&$context) {

  if (!isset($context['sandbox']['progress'])){
    $context['sandbox']['progress'] = 0;
    $queryC = new EntityFieldQuery();
    $queryC->entityCondition('entity_type', 'node');
    $queryC->propertyCondition('status',1);
    $queryC->fieldCondition('field_allterms', 'tid', 'NULL', '!=');
    $count = $queryC->count()->execute();
    $context['sandbox']['max'] = $count;
  }

  $limit = 5;

  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node');
  $query->propertyCondition('status',1);
  $query->fieldCondition('field_allterms', 'tid', 'NULL', '!=');
  $query->range($context['sandbox']['progress'],$limit);
  $result = $query->execute();

  if(isset($result['node'])){
    $nids = array_keys($result['node']);
    $nodes = entity_load('node', $nids);
    foreach($nodes as $node){
      _aw_taxonomy_update_mapping_batch($node);
      $context['results'][] = check_plain($node->title);
      $context['sandbox']['progress']++;
      $context['message'] = t('Now processing node %progress out of %max', array('%progress'=>$context['sandbox']['progress'], '%max'=>$context['sandbox']['max']));
    }
  }

  if($context['sandbox']['progress'] < $context['sandbox']['max']){
    $context['finished'] = $context['sandbox']['progress'] / $context['sandbox']['max'];
  }

}

function _aw_taxonomy_update_bulk_finished($success, $results, $operations){
  if($success){
    $message = count($results) . ' processed.';
    drupal_set_message($message);
  }
  else {
    drupal_set_message('failed!', 'error');
  }
}


/**
 * Helper function, updates taxonomy for a given node
 */
function _aw_taxonomy_update_mapping_batch($node){

  $new_allterms = array();
  $mapping_cache = variable_get('taxonomy_mapping');
  $mapping_cache = json_decode($mapping_cache, true);
  $mapping_cache = _aw_taxonomy_mapping_format_batch($mapping_cache);
  $groups = array();
  foreach($node->field_allterms['und'] as $key => $term){
    $groups[$term['group']][$key] = $term;
  }
  $found = false;
  foreach($groups as $group_key => $group){
    $group_term = end($group);
    if(array_key_exists($group_term['tid'], $mapping_cache) && $mapping_cache[$group_term['tid']]){
      $found = true;
      if($mapping_cache[$group_term['tid']]['delete']){
        unset($groups[$group_key]);
      }
      else {
        $new_temp_group = array();
        $map_to_tid = $mapping_cache[$group_term['tid']]['tid'];
        $parents = taxonomy_get_parents_all($map_to_tid);
        $parents = array_reverse($parents);
        foreach($parents as $p){
          $new_temp_group[] = array(
            'vid' => $p->vid,
            'tid' => $p->tid,
            'group' => $group_key,
          );
        }
        $groups[$group_key] = $new_temp_group;
      }
    }
  }
  if(!$found){
    return;
  }
  $new_group_number = 1;
  foreach($groups as $group_key2 => $group2){
    foreach($group2 as $group2_term_key => $group2_term){
      $group2[$group2_term_key]["group"] = $new_group_number;
    }
    $new_allterms = array_merge($new_allterms, $group2);
    $new_group_number++;
  }
  $node->field_allterms['und'] = $new_allterms;
  node_save($node);
}

/**
 * Helper function, converts the taxonomy_mapping variable into a more useful format
 */
function _aw_taxonomy_mapping_format_batch($mapping_cache){
  $mapping_formatted = array();

  // Go through the form and look for terms with the "include_children" key set to true,
  // and copy it's mapping value into it's children
  foreach($mapping_cache as $tid => $t_map){
    if($t_map["include_children"] && $t_map["new_term"]){
      $parent_map_vocab = (strlen($t_map["new_term_technology"]) > 0) ? "new_term_technology" : ((strlen($t_map["new_term_topics"]) > 0) ? "new_term_topics" : FALSE);
      $children = taxonomy_get_children($tid);
      foreach($children as $child_tid => $child){
        $mapping_cache[$child_tid][$parent_map_vocab] = $t_map["new_term"];
        $mapping_cache[$child_tid]["new_term"] = $t_map["new_term"];
      }
    }
  }

  foreach($mapping_cache as $key => $value){
    if($value["new_term"] || $value["delete"]){
      $mapping_formatted[$key] = array(
        "tid" => $value["new_term"],
        "vid" => (strlen($value["new_term_technology"]) > 0) ? '13' : '14',
        "delete" => $value["delete"],
      );
    }
  }

  return $mapping_formatted;
}

