<?php
/**
 * @file
 * webinar_registration.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function webinar_registration_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function webinar_registration_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function webinar_registration_node_info() {
  $items = array(
    'webinar_registration' => array(
      'name' => t('Webinar Registration'),
      'base' => 'node_content',
      'description' => t('Create a registration form for a GoToWebinar webinar'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
