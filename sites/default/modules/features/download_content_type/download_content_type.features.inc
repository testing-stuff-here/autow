<?php
/**
 * @file
 * download_content_type.features.inc
 */

/**
 * Implementation of hook_node_info().
 */
function download_content_type_node_info() {
  $items = array(
    'download' => array(
      'name' => t('Download'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
