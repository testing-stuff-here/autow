<?php
/**
 * @file
 * aquafadas_image_styles.features.inc
 */

/**
 * Implements hook_image_default_styles().
 */
function aquafadas_image_styles_image_default_styles() {
  $styles = array();

  // Exported image style: aquafadas_width_110.
  $styles['aquafadas_width_110'] = array(
    'name' => 'aquafadas_width_110',
    'effects' => array(
      34 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => '110',
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => '1',
      ),
    ),
  );

  // Exported image style: aquafadas_width_500.
  $styles['aquafadas_width_500'] = array(
    'name' => 'aquafadas_width_500',
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
          'width' => '500',
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => '1',
      ),
    ),
  );

  return $styles;
}
