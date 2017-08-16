<?php
/**
 * @file
 * wir_content_type.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function wir_content_type_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function wir_content_type_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function wir_content_type_node_info() {
  $items = array(
    'week_in_review' => array(
      'name' => t('Week in Review'),
      'base' => 'node_content',
      'description' => t('Week in review content. '),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
