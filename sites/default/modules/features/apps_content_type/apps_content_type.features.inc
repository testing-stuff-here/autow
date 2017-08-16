<?php
/**
 * @file
 * apps_content_type.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function apps_content_type_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function apps_content_type_node_info() {
  $items = array(
    'apps' => array(
      'name' => t('Apps'),
      'base' => 'node_content',
      'description' => t('Industrial Automation Vendors apps.'),
      'has_title' => '1',
      'title_label' => t('App Name'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
