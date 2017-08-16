<?php

function smg_node_update_drush_command() {
  $items['resave-nodes'] = [
    'callback'    => 'smg_node_update_setup_batch',
    'description' => t('Resave Nodes'),
    'arguments'   => [
      'date'      => "Node date",
      'node_type' => "Node type",
    ],
  ];
  return $items;
}

function smg_node_update_setup_batch($date=NULL, $node_type=NULL) {
  
  if (!drush_confirm('Are you sure you want resave nodes?')) drush_user_abort();
  
  $nodes_query = db_select('node', 'n')
    ->fields('n', array('nid'));

  if ($node_type) {
    $nodes_query->condition('type', $node_type);
  }
  if ($date) {
    $nodes_query->condition('created', strtotime($date), '<');
  }

  $all_nids = $nodes_query->execute()->fetchCol();

  // Break up all of our data so each process does not time out.
  $chunks = array_chunk($all_nids, 25);
  $count_chunks = count($chunks);

  for ($i=0; $i < $count_chunks; $i++) { 
    $operations[] = [
      'smg_node_update_get_nodes_and_save',
      [
        $chunks[$i],
        'details' => t('Resaving node batch @batch_count of @total_chunks', ['@batch_count'=>($i+1), '@total_chunks'=>$count_chunks]),
      ],
    ];
  }
 
  // Put all that information into our batch array.
  $batch = [
    'operations' => $operations,
    'title' => t('Resave Nodes batch process'),
    'init_message' => t('Setting up process..'),
    'error_message' => t('An error occurred'),
    'finished' => 'smg_node_update_finished_method'
  ];
 
  // Get the batch process all ready.
  batch_set($batch);
  $batch =& batch_get();
 
  // Because we are doing this on the back-end, we set progressive to false.
  $batch['progressive'] = FALSE;
 
  // Start processing the batch operations.
  drush_backend_batch_process();
}

function smg_node_update_get_nodes_and_save($data_chunk, $operation_details, &$context) {
  $context['message'] = $operation_details;
  foreach ($data_chunk as $node_id) {
    try {
      node_save(node_load($node_id));
      drush_log('Saved node: ' . $node_id, 'ok');
    }
    catch (Exception $e){
      drush_log('failed to save node: ' . $node_id, 'error');
    }
  }
  unset($node);
}
