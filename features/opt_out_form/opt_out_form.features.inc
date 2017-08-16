<?php
/**
 * @file
 * opt_out_form.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function opt_out_form_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_image_default_styles().
 */
function opt_out_form_image_default_styles() {
  $styles = array();

  // Exported image style: opt_out_form_logo.
  $styles['opt_out_form_logo'] = array(
    'label' => 'Opt Out Form Logo',
    'effects' => array(
      127 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 150,
          'height' => 80,
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
function opt_out_form_node_info() {
  $items = array(
    'opt_out_form' => array(
      'name' => t('Opt Out Form'),
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
