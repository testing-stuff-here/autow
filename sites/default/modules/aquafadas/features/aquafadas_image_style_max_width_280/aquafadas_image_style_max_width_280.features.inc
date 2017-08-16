<?php
/**
 * @file
 * aquafadas_image_style_max_width_280.features.inc
 */

/**
 * Implements hook_image_default_styles().
 */
function aquafadas_image_style_max_width_280_image_default_styles() {
  $styles = array();

  // Exported image style: aquafadas_width_280.
  $styles['aquafadas_width_280'] = array(
    'name' => 'aquafadas_width_280',
    'effects' => array(
      33 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => '280',
          'height' => '',
          'upscale' => 1,
        ),
        'weight' => '1',
      ),
    ),
  );

  return $styles;
}
