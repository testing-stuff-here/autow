<?php
/**
 * @file
 * lia_print_profile.features.inc
 */

/**
 * Implementation of hook_ctools_plugin_api().
 */
function lia_print_profile_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}

/**
 * Implementation of hook_node_info().
 */
function lia_print_profile_node_info() {
  $items = array(
    'leadership_print_profile' => array(
      'name' => t('Leadership Print Profile'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Company Name'),
      'help' => '',
    ),
  );
  return $items;
}
