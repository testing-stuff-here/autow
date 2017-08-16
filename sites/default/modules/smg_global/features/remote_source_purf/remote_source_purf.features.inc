<?php
/**
 * @file
 * remote_source_purf.features.inc
 */

/**
 * Implementation of hook_node_info().
 */
function remote_source_purf_node_info() {
  $items = array(
    'remote_source_purf' => array(
      'name' => t('Remote Source PURF'),
      'base' => 'node_content',
      'description' => t('Apply a PURF to a webpage on a remote website.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
