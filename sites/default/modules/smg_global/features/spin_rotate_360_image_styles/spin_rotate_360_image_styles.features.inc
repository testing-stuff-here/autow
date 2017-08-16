<?php
/**
 * @file
 * spin_rotate_360_image_styles.features.inc
 */

/**
 * Implements hook_image_default_styles().
 */
function spin_rotate_360_image_styles_image_default_styles() {
  $styles = array();

  // Exported image style: 360_width_110.
  $styles['360_width_110'] = array(
    'effects' => array(
      36 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 110,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
    'label' => '360_width_110',
  );

  // Exported image style: 360_width_500.
  $styles['360_width_500'] = array(
    'effects' => array(
      35 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 500,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
    'label' => '360_width_500',
  );

  // Exported image style: three_sixty_gallery.
  $styles['three_sixty_gallery'] = array(
    'label' => 'three_sixty_gallery',
    'effects' => array(
      17 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 300,
          'height' => 200,
        ),
        'weight' => 1,
      ),
      18 => array(
        'name' => 'canvasactions_file2canvas',
        'data' => array(
          'xpos' => 'center',
          'ypos' => 'center',
          'alpha' => 100,
          'path' => 'sites/default/files/360View_imageoverlay.png',
        ),
        'weight' => 2,
      ),
    ),
  );

  return $styles;
}
