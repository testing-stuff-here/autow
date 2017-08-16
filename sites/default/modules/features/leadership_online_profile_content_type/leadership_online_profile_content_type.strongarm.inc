<?php
/**
 * @file
 * leadership_online_profile_content_type.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function leadership_online_profile_content_type_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_leadership_online_profile';
  $strongarm->value = '0';
  $export['comment_anonymous_leadership_online_profile'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_leadership_online_profile';
  $strongarm->value = 1;
  $export['comment_default_mode_leadership_online_profile'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_leadership_online_profile';
  $strongarm->value = '50';
  $export['comment_default_per_page_leadership_online_profile'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_leadership_online_profile';
  $strongarm->value = 1;
  $export['comment_form_location_leadership_online_profile'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_leadership_online_profile';
  $strongarm->value = '1';
  $export['comment_leadership_online_profile'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_leadership_online_profile';
  $strongarm->value = '1';
  $export['comment_preview_leadership_online_profile'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_leadership_online_profile';
  $strongarm->value = 1;
  $export['comment_subject_field_leadership_online_profile'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__leadership_online_profile';
  $strongarm->value = array(
    'view_modes' => array(
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'jquerymobile_teaser' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'rss' => array(
        'custom_settings' => FALSE,
      ),
      'search_index' => array(
        'custom_settings' => FALSE,
      ),
      'search_result' => array(
        'custom_settings' => FALSE,
      ),
      'aw_gmfd_slide_in' => array(
        'custom_settings' => FALSE,
      ),
      'print' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'metatags' => array(
          'weight' => '20',
        ),
        'title' => array(
          'weight' => '0',
        ),
        'redirect' => array(
          'weight' => '19',
        ),
        'xmlsitemap' => array(
          'weight' => '18',
        ),
        'path' => array(
          'weight' => '17',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_node__leadership_online_profile'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_leadership_online_profile';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_leadership_online_profile'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_leadership_online_profile';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_leadership_online_profile'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_leadership_online_profile';
  $strongarm->value = array(
    0 => 'status',
    1 => 'promote',
  );
  $export['node_options_leadership_online_profile'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_leadership_online_profile';
  $strongarm->value = '1';
  $export['node_preview_leadership_online_profile'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_leadership_online_profile';
  $strongarm->value = 1;
  $export['node_submitted_leadership_online_profile'] = $strongarm;

  return $export;
}
