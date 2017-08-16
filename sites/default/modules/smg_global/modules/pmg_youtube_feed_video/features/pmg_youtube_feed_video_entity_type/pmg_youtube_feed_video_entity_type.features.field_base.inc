<?php
/**
 * @file
 * pmg_youtube_feed_video_entity_type.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function pmg_youtube_feed_video_entity_type_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_pmg_youtube_feed_image'
  $field_bases['field_pmg_youtube_feed_image'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_pmg_youtube_feed_image',
    'indexes' => array(
      'fid' => array(
        0 => 'fid',
      ),
    ),
    'locked' => 0,
    'module' => 'image',
    'settings' => array(
      'default_image' => 0,
      'field_permissions' => array(
        'create' => 0,
        'edit' => 0,
        'edit own' => 0,
        'view' => 0,
        'view own' => 0,
      ),
      'profile2_private' => FALSE,
      'uri_scheme' => 'public',
    ),
    'translatable' => 0,
    'type' => 'image',
  );

  return $field_bases;
}
