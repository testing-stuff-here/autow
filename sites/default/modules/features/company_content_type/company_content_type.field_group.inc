<?php
/**
 * @file
 * company_content_type.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function company_content_type_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_youtube_amplify|node|company|form';
  $field_group->group_name = 'group_youtube_amplify';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'company';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Youtube Amplify',
    'weight' => '20',
    'children' => array(
      0 => 'field_waywire_playlist_id',
      1 => 'field_waywire_tag',
      2 => 'field_youtube_amplified',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-youtube-amplify field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_youtube_amplify|node|company|form'] = $field_group;

  return $export;
}
