<?php
/**
 * @file
 * webinar_series_content_type.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function webinar_series_content_type_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function webinar_series_content_type_node_info() {
  $items = array(
    'webinar_series' => array(
      'name' => t('Webinar Series'),
      'base' => 'node_content',
      'description' => t('Used to provide information on a series of related webinars and registration.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
