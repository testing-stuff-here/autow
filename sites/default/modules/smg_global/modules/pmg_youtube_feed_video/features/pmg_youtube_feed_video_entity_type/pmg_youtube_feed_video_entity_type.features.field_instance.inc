<?php
/**
 * @file
 * pmg_youtube_feed_video_entity_type.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function pmg_youtube_feed_video_entity_type_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance:
  // 'pmg_youtube_feed_video-leadership_video-field_pmg_youtube_feed_image'
  $field_instances['pmg_youtube_feed_video-leadership_video-field_pmg_youtube_feed_image'] = array(
    'bundle' => 'leadership_video',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'pmg_youtube_feed_video',
    'field_name' => 'field_pmg_youtube_feed_image',
    'label' => 'Thumbnail',
    'required' => 0,
    'settings' => array(
      'alt_field' => 0,
      'alt_field_required' => 0,
      'default_image' => 0,
      'file_directory' => '',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '',
      'min_resolution' => '',
      'title_field' => 0,
      'title_field_required' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'image',
      'settings' => array(
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'throbber',
      ),
      'type' => 'image_image',
      'weight' => 31,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Thumbnail');

  return $field_instances;
}
