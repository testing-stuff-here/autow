<?php
/**
 * @file
 *   Holds drush functionality for hcp synchronization between sites.
 */

/**
 * Implements hook_drush_command().
 */
function aw_sync_drush_command() {
  $items = array();
  $items['aw-pfw-migrate'] = array(
    'description' => 'Migrates initial content to PFW from AW.',
    'required-arguments' => TRUE,
  );

  return $items;
}

/**
 * Drush command to start batch process to migrate nodes to PFW.
 */
function drush_aw_sync_aw_pfw_migrate() {
  if (drush_confirm('Are you sure you want migrate nodes to PFW?')) {
    drush_print('Processing...');
    $batch = array(
      'operations' => array(
        array('batch_aw_migrate_to_pfw', array()),
      ),
    );

    batch_set($batch);
    $batch['progressive'] = FALSE;
    drush_backend_batch_process();
  }
  else {
    drush_user_abort();
  }
}

/**
 * Migrate content from AW to PFW.
 */
function batch_aw_migrate_to_pfw() {
  $already_migrated_nodes = array();

  $tids = aw_sync_pfw_terms();
  $tids = implode(', ', $tids);

  $nodes = db_query("
    SELECT node.nid
    FROM {node} node
    WHERE node.nid IN
    (SELECT tn.nid AS nid
    FROM  {taxonomy_index} tn
    WHERE tn.tid IN ($tids)
    )"
  )->fetchAll();

  $filePath = realpath(drush_get_context('DRUSH_OLDCWD', getcwd())) . '/sites/default/files/drush_aw_sync_migrate.csv';
  $file = fopen($filePath, 'a+');

  // Check if there were any nodes already migrated. Don't migrate those.
  while(!feof($file)) {
    $line = fgetcsv($file);
    $already_migrated_nodes[] = $line[0];
  }

  fclose($file);

  foreach ($nodes as $node) {
    if (!in_array($node->nid, $already_migrated_nodes)) {
      $node = node_load($node->nid);
      $file = fopen($filePath, 'a+');
      aw_sync_process_node($node);
      fputcsv($file, array($node->nid));
      drupal_set_message(t('Migrated node @nid', array('@nid' => $node->nid)));
      fclose($file);
    }
  }
}
