<?php
/**
 * @file
 * awbs_article_.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function awbs_article__ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_image_default_styles().
 */
function awbs_article__image_default_styles() {
  $styles = array();

  // Exported image style: teaser.
  $styles['teaser'] = array(
    'label' => 'teaser',
    'effects' => array(
      83 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 600,
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
function awbs_article__node_info() {
  $items = array(
    'article' => array(
      'name' => t('Article'),
      'base' => 'node_content',
      'description' => t('News, features, products, supplier news, etc.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
