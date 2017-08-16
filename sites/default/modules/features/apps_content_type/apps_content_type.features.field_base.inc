<?php
/**
 * @file
 * apps_content_type.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function apps_content_type_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_app_more_information_link'
  $field_bases['field_app_more_information_link'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_app_more_information_link',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(),
    'locked' => 0,
    'module' => 'link',
    'settings' => array(
      'attributes' => array(
        'class' => '',
        'rel' => '',
        'target' => 'default',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 1,
      'title' => 'optional',
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
    ),
    'translatable' => 0,
    'type' => 'link_field',
  );

  // Exported field_base: 'field_app_platform_os_url'
  $field_bases['field_app_platform_os_url'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_app_platform_os_url',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(),
    'locked' => 0,
    'module' => 'link',
    'settings' => array(
      'attributes' => array(
        'class' => '',
        'rel' => '',
        'target' => 'default',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 1,
      'title' => 'optional',
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
    ),
    'translatable' => 0,
    'type' => 'link_field',
  );

  // Exported field_base: 'field_app_platforms_os'
  $field_bases['field_app_platforms_os'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_app_platforms_os',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(
      'tid' => array(
        0 => 'tid',
      ),
    ),
    'locked' => 0,
    'module' => 'taxonomy',
    'settings' => array(
      'allowed_values' => array(
        0 => array(
          'parent' => 0,
          'vocabulary' => 'app_platforms_os',
        ),
      ),
    ),
    'translatable' => 0,
    'type' => 'taxonomy_term_reference',
  );

  // Exported field_base: 'field_application_case_history'
  $field_bases['field_application_case_history'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_application_case_history',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(
      'nid' => array(
        0 => 'nid',
      ),
    ),
    'locked' => 0,
    'module' => 'node_reference',
    'settings' => array(
      'referenceable_types' => array(
        '360_package_spin_rotate' => 0,
        'apps' => 0,
        'article' => 'article',
        'blog' => 'blog',
        'company' => 0,
        'download' => 0,
        'form_template' => 0,
        'game' => 0,
        'leadership_data_card' => 0,
        'leadership_online_profile' => 0,
        'leadership_print_profile' => 0,
        'magazine_covers' => 0,
        'mobile_webform' => 0,
        'page' => 0,
        'playbook' => 0,
        'podcast' => 'podcast',
        'pop_up_registration' => 0,
        'registration_form' => 0,
        'stage_one_form' => 0,
        'team' => 0,
        'video' => 'video',
        'webform' => 0,
        'webinar' => 0,
        'webinar_registration' => 0,
        'whitepaper' => 'whitepaper',
      ),
      'view' => array(
        'args' => array(),
        'display_name' => '',
        'view_name' => '',
      ),
    ),
    'translatable' => 0,
    'type' => 'node_reference',
  );

  // Exported field_base: 'field_platforms_os'
  $field_bases['field_platforms_os'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_platforms_os',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(),
    'locked' => 0,
    'module' => 'field_collection',
    'settings' => array(
      'path' => '',
    ),
    'translatable' => 0,
    'type' => 'field_collection',
  );

  // Exported field_base: 'field_video_resources'
  $field_bases['field_video_resources'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_video_resources',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(
      'video_id' => array(
        0 => 'video_id',
      ),
    ),
    'locked' => 0,
    'module' => 'youtube',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'youtube',
  );

  return $field_bases;
}
