<?php
/**
 * @file
 * feature_360_gallery.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function feature_360_gallery_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_360_package_spin_rotate';
  $strongarm->value = '1';
  $export['comment_360_package_spin_rotate'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_360_package_spin_rotate';
  $strongarm->value = '0';
  $export['comment_anonymous_360_package_spin_rotate'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_360_package_spin_rotate';
  $strongarm->value = 1;
  $export['comment_default_mode_360_package_spin_rotate'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_360_package_spin_rotate';
  $strongarm->value = '50';
  $export['comment_default_per_page_360_package_spin_rotate'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_360_package_spin_rotate';
  $strongarm->value = 1;
  $export['comment_form_location_360_package_spin_rotate'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_360_package_spin_rotate';
  $strongarm->value = '1';
  $export['comment_preview_360_package_spin_rotate'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_360_package_spin_rotate';
  $strongarm->value = 1;
  $export['comment_subject_field_360_package_spin_rotate'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__360_package_spin_rotate';
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
      'webinar_series_part' => array(
        'custom_settings' => TRUE,
      ),
      'aw_gmfd_slide_in' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'metatags' => array(
          'weight' => '13',
        ),
        'title' => array(
          'weight' => '0',
        ),
        'redirect' => array(
          'weight' => '11',
        ),
        'xmlsitemap' => array(
          'weight' => '12',
        ),
        'path' => array(
          'weight' => '10',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_node__360_package_spin_rotate'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_360_package_spin_rotate';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_360_package_spin_rotate'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_360_package_spin_rotate';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_360_package_spin_rotate'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_360_package_spin_rotate';
  $strongarm->value = array(
    0 => 'status',
    1 => 'promote',
  );
  $export['node_options_360_package_spin_rotate'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_360_package_spin_rotate';
  $strongarm->value = '1';
  $export['node_preview_360_package_spin_rotate'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_360_package_spin_rotate';
  $strongarm->value = 1;
  $export['node_submitted_360_package_spin_rotate'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_360_package_spin_rotate_pattern';
  $strongarm->value = '';
  $export['pathauto_node_360_package_spin_rotate_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_coverage_type_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_coverage_type_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_source_type_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_source_type_pattern'] = $strongarm;

  return $export;
}
