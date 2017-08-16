<?php
/**
 * @file
 * wir_content_type.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function wir_content_type_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create week_in_review content'.
  $permissions['create week_in_review content'] = array(
    'name' => 'create week_in_review content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any week_in_review content'.
  $permissions['delete any week_in_review content'] = array(
    'name' => 'delete any week_in_review content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own week_in_review content'.
  $permissions['delete own week_in_review content'] = array(
    'name' => 'delete own week_in_review content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any week_in_review content'.
  $permissions['edit any week_in_review content'] = array(
    'name' => 'edit any week_in_review content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own week_in_review content'.
  $permissions['edit own week_in_review content'] = array(
    'name' => 'edit own week_in_review content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'view any unpublished week_in_review content'.
  $permissions['view any unpublished week_in_review content'] = array(
    'name' => 'view any unpublished week_in_review content',
    'roles' => array(),
    'module' => 'view_unpublished',
  );

  return $permissions;
}
