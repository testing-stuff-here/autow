<?php
/**
 * @file
 * opt_out_form.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function opt_out_form_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'body'
  $field_bases['body'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(
      0 => 'node',
    ),
    'field_name' => 'body',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'field_permissions' => array(
        'create' => 'create',
        'edit' => 'edit',
        'edit own' => 'edit own',
        'view' => 'view',
        'view own' => 'view own',
      ),
      'profile2_private' => FALSE,
    ),
    'translatable' => 1,
    'type' => 'text_with_summary',
  );

  // Exported field_base: 'field_image'
  $field_bases['field_image'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_image',
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
        'create' => 'create',
        'edit' => 'edit',
        'edit own' => 'edit own',
        'view' => 'view',
        'view own' => 'view own',
      ),
      'profile2_private' => FALSE,
      'uri_scheme' => 'public',
    ),
    'translatable' => 1,
    'type' => 'image',
  );

  return $field_bases;
}
