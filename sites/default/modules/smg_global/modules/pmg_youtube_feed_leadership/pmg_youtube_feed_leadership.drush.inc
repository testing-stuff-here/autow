<?php
/**
 * @file
 * Drush commands
 */

/**
 * Implements hook_drush_command().
 */
function pmg_youtube_feed_leadership_drush_command() {
  $items['pmg-youtube-feed-create-all'] = array(
    'description' => 'Create/Update PMG YouTube Feed videos for all Youtube amplify companies.',
  );
  $items['pmg-youtube-feed-create-cached-json'] = array(
    'description' => 'Goes through all the PMG YouTube Feed videos and sets up the cache table',
  );
  $items['pmg-youtube-feed-add-username-field'] = array(
    'description' => 'Adds a YouTube username field to company node',
  );
  $items['pmg-youtube-feed-uploads-playlist-field'] = array(
    'description' => 'Adds a field to Company node to store company\'s YouTube playlist ID',
  );
  $items['pmg-youtube-feed-username-override'] = array(
    'description' => 'Adds a boolean to specify that we are using a channel ID instead of YouTube username',
  );

  return $items;
}

/**
 * @see pmg_youtube_feed_leadership_create_entities_for_all_companies().
 */
function drush_pmg_youtube_feed_leadership_pmg_youtube_feed_create_all() {
  pmg_youtube_feed_leadership_create_entities_for_all_companies();
}

/**
 *
 * @see pmg_youtube_feed_leadership_create_json().
 */
function drush_pmg_youtube_feed_leadership_pmg_youtube_feed_create_cached_json() {
  pmg_youtube_feed_leadership_create_json();
}

/**
 * Creates a field and adds it to Company content type
 */
function drush_pmg_youtube_feed_leadership_pmg_youtube_feed_add_username_field() {
  if (!field_info_field('field_youtube_username')) {
    $field = array(
      'field_name' => 'field_youtube_username',
      'type' => 'text',
    );
    field_create_field($field);
  }

  if (!field_info_instance('node', 'field_youtube_username', 'company')) {
    $field_instance = array(
      'field_name' => 'field_youtube_username',
      'entity_type' => 'node',
      'label' => 'YouTube Username',
      'settings' => array(
        'user_register_form' => 0,
      ),
      'bundle' => 'company',
      'widget' => array(
        'type' => 'textfield',
      ),
    );
    field_create_instance($field_instance);
  }
}

/**
 * Adds a YouTube playlist ID field to company nodes.  Searches all companies with a
 * YouTube username value, and gets the playlist ID via YouTube API if ID missing.
 */
function drush_pmg_youtube_feed_leadership_pmg_youtube_feed_uploads_playlist_field() {
  if (!field_info_field('field_youtube_uploads_id')) {
    $field = array(
      'field_name' => 'field_youtube_uploads_id',
      'type' => 'text',
    );
    field_create_field($field);
  }
  if (!field_info_instance('node', 'field_youtube_uploads_id', 'company')) {
    $instance = array(
      'field_name' => 'field_youtube_uploads_id',
      'entity_type' => 'node',
      'label' => '',
      'settings' => array('user_register_form' => 0),
      'bundle' => 'company',
      'widget' => array(
        'type' => 'textfield',
      ),
    );
    field_create_instance($instance);
  }

  pmg_youtube_feed_leadership_get_uploads_playlist_id();
}

/**
 * Adds a boolean field to company nodes
 */
function drush_pmg_youtube_feed_leadership_pmg_youtube_feed_username_override() {
  if (!field_info_field('field_youtube_username_override')) {
    $field = array(
      'field_name' => 'field_youtube_username_override',
      'type' => 'list_boolean',
      'cardinality' => 1,
      'settings' => array(
        'allowed_values' => array(
          0 => '',
          1 => '',
        ),
      ),
    );
    field_create_field($field);
  }
  if (!field_info_instance('node', 'field_youtube_username_override', 'company')) {
    $instance = array(
      'field_name' => 'field_youtube_username_override',
      'entity_type' => 'node',
      'label' => 'Override YouTube username field with channel id.',
      'settings' => array(
        'user_register_form' => 0,
      ),
      'bundle' => 'company',
      'required' => FALSE,
      'widget' => array(
        'type' => 'options_onoff',
        'settings' => array('display_label' => 1),
      ),
      'default_value' => array(
        array(
          'value' => 0,
        )
      ),
    );
    field_create_instance($instance);
  }
}
