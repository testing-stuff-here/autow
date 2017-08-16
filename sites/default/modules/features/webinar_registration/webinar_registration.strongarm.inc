<?php
/**
 * @file
 * webinar_registration.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function webinar_registration_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_webinar_registration';
  $strongarm->value = '0';
  $export['comment_anonymous_webinar_registration'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_webinar_registration';
  $strongarm->value = 1;
  $export['comment_default_mode_webinar_registration'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_webinar_registration';
  $strongarm->value = '50';
  $export['comment_default_per_page_webinar_registration'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_webinar_registration';
  $strongarm->value = 1;
  $export['comment_form_location_webinar_registration'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_webinar_registration';
  $strongarm->value = '1';
  $export['comment_preview_webinar_registration'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_webinar_registration';
  $strongarm->value = 1;
  $export['comment_subject_field_webinar_registration'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_webinar_registration';
  $strongarm->value = '1';
  $export['comment_webinar_registration'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'date_format_custom';
  $strongarm->value = 'D, m/d/Y - g:ia';
  $export['date_format_custom'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__webinar_registration';
  $strongarm->value = array(
    'view_modes' => array(
      'teaser' => array(
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
      'print' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'jquerymobile_teaser' => array(
        'custom_settings' => TRUE,
      ),
      'aw_gmfd_slide_in' => array(
        'custom_settings' => FALSE,
      ),
      'webinar_series_part' => array(
        'custom_settings' => TRUE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'title' => array(
          'weight' => '0',
        ),
        'redirect' => array(
          'weight' => '21',
        ),
        'xmlsitemap' => array(
          'weight' => '23',
        ),
        'path' => array(
          'weight' => '22',
        ),
        'webform_template' => array(
          'weight' => '1',
        ),
        'metatags' => array(
          'weight' => '24',
        ),
      ),
      'display' => array(
        'webform' => array(
          'default' => array(
            'weight' => '10',
            'visible' => TRUE,
          ),
          'webinar_series_part' => array(
            'weight' => '10',
            'visible' => TRUE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_node__webinar_registration'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_webinar_registration';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_webinar_registration'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_webinar_registration';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_webinar_registration'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_webinar_registration';
  $strongarm->value = array(
    0 => 'status',
    1 => 'promote',
  );
  $export['node_options_webinar_registration'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_webinar_registration';
  $strongarm->value = '1';
  $export['node_preview_webinar_registration'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_webinar_registration';
  $strongarm->value = 1;
  $export['node_submitted_webinar_registration'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_webinar_registration_pattern';
  $strongarm->value = '';
  $export['pathauto_node_webinar_registration_pattern'] = $strongarm;

  return $export;
}
