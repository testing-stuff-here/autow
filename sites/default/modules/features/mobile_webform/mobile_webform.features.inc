<?php
/**
 * @file
 * mobile_webform.features.inc
 */

/**
 * Implements hook_node_info().
 */
function mobile_webform_node_info() {
  $items = array(
    'mobile_webform' => array(
      'name' => t('Mobile Webform'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
