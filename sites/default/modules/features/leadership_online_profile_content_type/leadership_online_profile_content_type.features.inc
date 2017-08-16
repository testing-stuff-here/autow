<?php
/**
 * @file
 * leadership_online_profile_content_type.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function leadership_online_profile_content_type_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_image_default_styles().
 */
function leadership_online_profile_content_type_image_default_styles() {
  $styles = array();

  // Exported image style: ld_logo_max_width_390.
  $styles['ld_logo_max_width_390'] = array(
    'label' => 'ld_logo_max_width_390',
    'effects' => array(
      50 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 390,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function leadership_online_profile_content_type_node_info() {
  $items = array(
    'leadership_online_profile' => array(
      'name' => t('Leadership Online Profile'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
