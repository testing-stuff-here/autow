<?php
/**
 * @file
 * wir_content_type.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function wir_content_type_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'additional_settings__active_tab_week_in_review';
  $strongarm->value = 'edit-workflow';
  $export['additional_settings__active_tab_week_in_review'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'additional_settings__active_tab_wir_newletter_signup';
  $strongarm->value = 'edit-submission';
  $export['additional_settings__active_tab_wir_newletter_signup'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_week_in_review';
  $strongarm->value = '0';
  $export['comment_anonymous_week_in_review'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_week_in_review';
  $strongarm->value = 0;
  $export['comment_default_mode_week_in_review'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_week_in_review';
  $strongarm->value = '50';
  $export['comment_default_per_page_week_in_review'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_week_in_review';
  $strongarm->value = 1;
  $export['comment_form_location_week_in_review'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_week_in_review';
  $strongarm->value = '1';
  $export['comment_preview_week_in_review'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_week_in_review';
  $strongarm->value = 1;
  $export['comment_subject_field_week_in_review'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_week_in_review';
  $strongarm->value = '1';
  $export['comment_week_in_review'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_complete_week_in_review';
  $strongarm->value = '0';
  $export['content_complete_week_in_review'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_complete_wir_newletter_signup';
  $strongarm->value = '0';
  $export['content_complete_wir_newletter_signup'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__week_in_review';
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
          'weight' => '40',
        ),
        'title' => array(
          'weight' => '-5',
        ),
        'redirect' => array(
          'weight' => '30',
        ),
        'xmlsitemap' => array(
          'weight' => '30',
        ),
        'path' => array(
          'weight' => '30',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_node__week_in_review'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'maxlength_js_label_week_in_review';
  $strongarm->value = 'Content limited to @limit characters, remaining: <strong>@remaining</strong>';
  $export['maxlength_js_label_week_in_review'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'maxlength_js_label_wir_newletter_signup';
  $strongarm->value = 'Content limited to @limit characters, remaining: <strong>@remaining</strong>';
  $export['maxlength_js_label_wir_newletter_signup'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'maxlength_js_week_in_review';
  $strongarm->value = '';
  $export['maxlength_js_week_in_review'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'maxlength_js_wir_newletter_signup';
  $strongarm->value = '';
  $export['maxlength_js_wir_newletter_signup'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_week_in_review';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_week_in_review'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_wir_newletter_signup';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_wir_newletter_signup'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_week_in_review';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_week_in_review'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_wir_newletter_signup';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_wir_newletter_signup'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_week_in_review';
  $strongarm->value = array();
  $export['node_options_week_in_review'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_wir_newletter_signup';
  $strongarm->value = array(
    0 => 'status',
    1 => 'promote',
  );
  $export['node_options_wir_newletter_signup'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_week_in_review';
  $strongarm->value = '1';
  $export['node_preview_week_in_review'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_week_in_review';
  $strongarm->value = 0;
  $export['node_submitted_week_in_review'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_wir_newletter_signup';
  $strongarm->value = 1;
  $export['node_submitted_wir_newletter_signup'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'page_title_type_week_in_review';
  $strongarm->value = '';
  $export['page_title_type_week_in_review'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'page_title_type_week_in_review_showfield';
  $strongarm->value = 0;
  $export['page_title_type_week_in_review_showfield'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'page_title_type_wir_newletter_signup';
  $strongarm->value = '';
  $export['page_title_type_wir_newletter_signup'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'page_title_type_wir_newletter_signup_showfield';
  $strongarm->value = 0;
  $export['page_title_type_wir_newletter_signup_showfield'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'print_display_comment_week_in_review';
  $strongarm->value = 0;
  $export['print_display_comment_week_in_review'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'print_display_comment_wir_newletter_signup';
  $strongarm->value = 0;
  $export['print_display_comment_wir_newletter_signup'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'print_display_urllist_week_in_review';
  $strongarm->value = 1;
  $export['print_display_urllist_week_in_review'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'print_display_urllist_wir_newletter_signup';
  $strongarm->value = 1;
  $export['print_display_urllist_wir_newletter_signup'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'print_display_week_in_review';
  $strongarm->value = 1;
  $export['print_display_week_in_review'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'print_display_wir_newletter_signup';
  $strongarm->value = 1;
  $export['print_display_wir_newletter_signup'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'publish_button_content_type_week_in_review';
  $strongarm->value = 0;
  $export['publish_button_content_type_week_in_review'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'publish_button_content_type_wir_newletter_signup';
  $strongarm->value = 0;
  $export['publish_button_content_type_wir_newletter_signup'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'save_continue_week_in_review';
  $strongarm->value = 'Save and add fields';
  $export['save_continue_week_in_review'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'save_continue_wir_newletter_signup';
  $strongarm->value = 'Save and add fields';
  $export['save_continue_wir_newletter_signup'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_publish_enable_week_in_review';
  $strongarm->value = 0;
  $export['scheduler_publish_enable_week_in_review'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_publish_enable_wir_newletter_signup';
  $strongarm->value = 0;
  $export['scheduler_publish_enable_wir_newletter_signup'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_publish_required_week_in_review';
  $strongarm->value = 0;
  $export['scheduler_publish_required_week_in_review'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_publish_required_wir_newletter_signup';
  $strongarm->value = 0;
  $export['scheduler_publish_required_wir_newletter_signup'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_publish_revision_week_in_review';
  $strongarm->value = 0;
  $export['scheduler_publish_revision_week_in_review'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_publish_revision_wir_newletter_signup';
  $strongarm->value = 0;
  $export['scheduler_publish_revision_wir_newletter_signup'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_publish_touch_week_in_review';
  $strongarm->value = 0;
  $export['scheduler_publish_touch_week_in_review'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_publish_touch_wir_newletter_signup';
  $strongarm->value = 0;
  $export['scheduler_publish_touch_wir_newletter_signup'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_unpublish_enable_week_in_review';
  $strongarm->value = 0;
  $export['scheduler_unpublish_enable_week_in_review'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_unpublish_enable_wir_newletter_signup';
  $strongarm->value = 0;
  $export['scheduler_unpublish_enable_wir_newletter_signup'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_unpublish_required_week_in_review';
  $strongarm->value = 0;
  $export['scheduler_unpublish_required_week_in_review'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_unpublish_required_wir_newletter_signup';
  $strongarm->value = 0;
  $export['scheduler_unpublish_required_wir_newletter_signup'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_unpublish_revision_week_in_review';
  $strongarm->value = 0;
  $export['scheduler_unpublish_revision_week_in_review'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_unpublish_revision_wir_newletter_signup';
  $strongarm->value = 0;
  $export['scheduler_unpublish_revision_wir_newletter_signup'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'unique_field_comp_week_in_review';
  $strongarm->value = 'each';
  $export['unique_field_comp_week_in_review'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'unique_field_comp_wir_newletter_signup';
  $strongarm->value = 'each';
  $export['unique_field_comp_wir_newletter_signup'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'unique_field_fields_week_in_review';
  $strongarm->value = array();
  $export['unique_field_fields_week_in_review'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'unique_field_fields_wir_newletter_signup';
  $strongarm->value = array();
  $export['unique_field_fields_wir_newletter_signup'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'unique_field_scope_week_in_review';
  $strongarm->value = 'type';
  $export['unique_field_scope_week_in_review'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'unique_field_scope_wir_newletter_signup';
  $strongarm->value = 'type';
  $export['unique_field_scope_wir_newletter_signup'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'unique_field_show_matches_week_in_review';
  $strongarm->value = array();
  $export['unique_field_show_matches_week_in_review'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'unique_field_show_matches_wir_newletter_signup';
  $strongarm->value = array();
  $export['unique_field_show_matches_wir_newletter_signup'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'xmlsitemap_settings_node_week_in_review';
  $strongarm->value = array(
    'status' => '0',
    'priority' => '0.5',
  );
  $export['xmlsitemap_settings_node_week_in_review'] = $strongarm;

  return $export;
}
