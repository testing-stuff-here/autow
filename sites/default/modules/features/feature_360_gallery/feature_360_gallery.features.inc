<?php
/**
 * @file
 * feature_360_gallery.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function feature_360_gallery_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function feature_360_gallery_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function feature_360_gallery_image_default_styles() {
  $styles = array();

  // Exported image style: three_sixty_gallery_block.
  $styles['three_sixty_gallery_block'] = array(
    'label' => 'three_sixty_gallery_block',
    'effects' => array(
      83 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 600,
          'height' => 400,
        ),
        'weight' => 1,
      ),
      84 => array(
        'name' => 'canvasactions_file2canvas',
        'data' => array(
          'xpos' => 'center',
          'ypos' => 'center',
          'alpha' => 100,
          'path' => 'sites/default/themes/awbs/images/360View_imageoverlay_block.png',
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: three_sixty_gallery_video.
  $styles['three_sixty_gallery_video'] = array(
    'effects' => array(
      38 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 200,
          'height' => 200,
        ),
        'weight' => 1,
      ),
      39 => array(
        'name' => 'canvasactions_file2canvas',
        'data' => array(
          'xpos' => 'center',
          'ypos' => 'center',
          'alpha' => 100,
          'path' => 'sites/default/themes/aw960/css/images/360View_imageoverlay.png',
        ),
        'weight' => 2,
      ),
    ),
    'label' => 'three_sixty_gallery_video',
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function feature_360_gallery_node_info() {
  $items = array(
    '360_package_spin_rotate' => array(
      'name' => t('360° Package Spin & Rotate'),
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
