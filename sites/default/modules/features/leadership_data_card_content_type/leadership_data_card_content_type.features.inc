<?php
/**
 * @file
 * leadership_data_card_content_type.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function leadership_data_card_content_type_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_image_default_styles().
 */
function leadership_data_card_content_type_image_default_styles() {
  $styles = array();

  // Exported image style: leadership-widget-large.
  $styles['leadership-widget-large'] = array(
    'label' => 'leadership-widget-large',
    'effects' => array(
      74 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 265,
          'height' => 95,
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
      75 => array(
        'name' => 'canvasactions_canvas2file',
        'data' => array(
          'xpos' => 'center',
          'ypos' => 125,
          'alpha' => 100,
          'path' => 'sites/default/modules/smg_global/modules/leadership/css/images/lia-widget.png',
          'dimensions' => 'maximum',
        ),
        'weight' => 2,
      ),
      76 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 300,
          'height' => 278,
          'upscale' => 0,
        ),
        'weight' => 3,
      ),
    ),
  );

  // Exported image style: leadership-widget-medium.
  $styles['leadership-widget-medium'] = array(
    'label' => 'leadership-widget-medium',
    'effects' => array(
      77 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 265,
          'height' => 95,
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
      78 => array(
        'name' => 'canvasactions_canvas2file',
        'data' => array(
          'xpos' => 'center',
          'ypos' => 126,
          'alpha' => 100,
          'path' => 'sites/default/modules/smg_global/modules/leadership/css/images/lia-widget.png',
          'dimensions' => 'maximum',
        ),
        'weight' => 2,
      ),
      79 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 210,
          'height' => 195,
          'upscale' => 0,
        ),
        'weight' => 3,
      ),
    ),
  );

  // Exported image style: leadership-widget-small.
  $styles['leadership-widget-small'] = array(
    'label' => 'leadership-widget-small',
    'effects' => array(
      80 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 265,
          'height' => 95,
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
      81 => array(
        'name' => 'canvasactions_canvas2file',
        'data' => array(
          'xpos' => 'center',
          'ypos' => 125,
          'alpha' => 100,
          'path' => 'sites/default/modules/smg_global/modules/leadership/css/images/lia-widget.png',
          'dimensions' => 'maximum',
        ),
        'weight' => 2,
      ),
      82 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 120,
          'height' => 111,
          'upscale' => 0,
        ),
        'weight' => 3,
      ),
    ),
  );

  // Exported image style: leadership_data_card_exec.
  $styles['leadership_data_card_exec'] = array(
    'label' => 'leadership_data_card_exec',
    'effects' => array(
      52 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 75,
          'height' => 92,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: leadership_data_card_logo.
  $styles['leadership_data_card_logo'] = array(
    'label' => 'leadership_data_card_logo',
    'effects' => array(
      53 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 150,
          'height' => 100,
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: leadership_data_card_product_photo.
  $styles['leadership_data_card_product_photo'] = array(
    'label' => 'leadership_data_card_product_photo',
    'effects' => array(
      54 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 80,
          'height' => 70,
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
function leadership_data_card_content_type_node_info() {
  $items = array(
    'leadership_data_card' => array(
      'name' => t('Leadership Data Card'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Company Name'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
