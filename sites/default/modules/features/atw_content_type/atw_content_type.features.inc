<?php
/**
 * @file
 * atw_content_type.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function atw_content_type_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function atw_content_type_node_info() {
  $items = array(
    'around_the_world' => array(
      'name' => t('Around the World'),
      'base' => 'node_content',
      'description' => t('Adds new Automation Around the World content. '),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
