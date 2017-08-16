<?php
/**
 * @file
 * leadership_data_card_content_type.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function leadership_data_card_content_type_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_leadership_data_card';
  $strongarm->value = '0';
  $export['comment_anonymous_leadership_data_card'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_leadership_data_card';
  $strongarm->value = 1;
  $export['comment_default_mode_leadership_data_card'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_leadership_data_card';
  $strongarm->value = '50';
  $export['comment_default_per_page_leadership_data_card'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_leadership_data_card';
  $strongarm->value = 1;
  $export['comment_form_location_leadership_data_card'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_leadership_data_card';
  $strongarm->value = '1';
  $export['comment_leadership_data_card'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_leadership_data_card';
  $strongarm->value = '1';
  $export['comment_preview_leadership_data_card'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_leadership_data_card';
  $strongarm->value = 1;
  $export['comment_subject_field_leadership_data_card'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_leadership_data_card';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_leadership_data_card'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_leadership_data_card';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_leadership_data_card'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_leadership_data_card';
  $strongarm->value = array(
    0 => 'status',
    1 => 'promote',
  );
  $export['node_options_leadership_data_card'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_leadership_data_card';
  $strongarm->value = '1';
  $export['node_preview_leadership_data_card'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_leadership_data_card';
  $strongarm->value = 1;
  $export['node_submitted_leadership_data_card'] = $strongarm;

  return $export;
}
