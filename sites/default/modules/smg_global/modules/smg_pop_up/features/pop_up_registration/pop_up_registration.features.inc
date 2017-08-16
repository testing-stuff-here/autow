<?php
/**
 * @file
 * pop_up_registration.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function pop_up_registration_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function pop_up_registration_node_info() {
  $items = array(
    'pop_up_registration' => array(
      'name' => t('Pop-Up Registration'),
      'base' => 'node_content',
      'description' => t('Leadwise Pop Up Registration box.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
