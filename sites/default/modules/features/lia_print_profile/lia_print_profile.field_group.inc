<?php
/**
 * @file
 * lia_print_profile.field_group.inc
 */

/**
 * Implementation of hook_field_group_info().
 */
function lia_print_profile_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_comp_contact_info|node|leadership_print_profile|form';
  $field_group->group_name = 'group_comp_contact_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'leadership_print_profile';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Company Contact Information',
    'weight' => '8',
    'children' => array(
      0 => 'field_ld_address_1',
      1 => 'field_ld_address_2',
      2 => 'field_ld_address_city',
      3 => 'field_ld_country',
      4 => 'field_ld_email',
      5 => 'field_ld_fax',
      6 => 'field_ld_phone',
      7 => 'field_ld_state',
      8 => 'field_ld_website',
      9 => 'field_ld_zip_postal_code',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-comp-contact-info field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_comp_contact_info|node|leadership_print_profile|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_ld_categories|node|leadership_print_profile|form';
  $field_group->group_name = 'group_ld_categories';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'leadership_print_profile';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Categories',
    'weight' => '2',
    'children' => array(
      0 => 'field_ld_categories_technologies',
      1 => 'field_ld_categories_topics',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-ld-categories field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_ld_categories|node|leadership_print_profile|form'] = $field_group;

  return $export;
}
