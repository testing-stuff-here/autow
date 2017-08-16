<?php
/**
 * @file
 * pmg_youtube_feed_video_entity_type.features.inc
 */

/**
 * Implements hook_image_default_styles().
 */
function pmg_youtube_feed_video_entity_type_image_default_styles() {
  $styles = array();

  // Exported image style: pmg_youtube_feed_video_widget_grid.
  $styles['pmg_youtube_feed_video_widget_grid'] = array(
    'label' => 'pmg_youtube_feed_video_widget_grid',
    'effects' => array(
      131 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 210,
          'height' => 120,
        ),
        'weight' => 1,
      ),
      132 => array(
        'name' => 'canvasactions_file2canvas',
        'data' => array(
          'xpos' => 'center',
          'ypos' => 'center',
          'alpha' => 100,
          'path' => 'module://pmg_youtube_feed_video/images/videoplaybtn_44x44.png',
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: pmg_youtube_feed_video_widget_thumbnail.
  $styles['pmg_youtube_feed_video_widget_thumbnail'] = array(
    'label' => 'pmg_youtube_feed_video_widget_thumbnail',
    'effects' => array(
      127 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 160,
          'height' => 90,
        ),
        'weight' => 1,
      ),
      130 => array(
        'name' => 'canvasactions_file2canvas',
        'data' => array(
          'xpos' => 'center',
          'ypos' => 'center',
          'alpha' => 100,
          'path' => 'module://pmg_youtube_feed_video/images/videoplaybtn_44x44.png',
        ),
        'weight' => 2,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_default_pmg_youtube_feed_video_type().
 */
function pmg_youtube_feed_video_entity_type_default_pmg_youtube_feed_video_type() {
  $items = array();
  $items['leadership_video'] = entity_import('pmg_youtube_feed_video_type', '{
    "type" : "leadership_video",
    "label" : "Leadership Video",
    "weight" : "0",
    "data" : "",
    "rdf_mapping" : []
  }');
  return $items;
}
