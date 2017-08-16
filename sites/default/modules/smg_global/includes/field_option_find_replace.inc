<?php
/**
 * @file
 * API endpoint for updating field option values in webforms.
 */

// Found option value w/o proper pick-code mapping, needed to replace
define('FIND_REPLACE_FOUND_REPLACED', 1);
// Found option value, already mapped, so didn't replace
define('FIND_REPLACE_FOUND_OK', 0);
// Didn't find option value
define('FIND_REPLACE_NOT_FOUND', -1);

/**
 * Endpoint that searches through site's webforms for instances
 * where a select list field is being used, and updates the values
 * and friendly names for that field.
 *
 * @return array
 */
function smg_global_field_option_find_replace() {

  ini_set("memory_limit", '-1');
  set_time_limit(0);

  if (!_smg_global_secure_by_ip()) {
    header("HTTP/1.0 401 Unauthorized");
    return NULL;
  }

  $post_body = json_decode(file_get_contents('php://input'), TRUE);

  $field_id = (!empty($post_body['fieldId'])) ? $post_body['fieldId'] : NULL;
  $silverpop_name = (!empty($post_body['silverpopName'])) ? $post_body['silverpopName'] : NULL;
  $value_mappings = (!empty($post_body['valueMappings'])) ? $post_body['valueMappings'] : NULL;

  // Load all webforms
  $webform_nids_query = db_select("webform", "w");
  $webform_nids_query->join("node", "n", "n.nid = w.nid");
  $webform_nids = $webform_nids_query
    ->fields("w", array("nid"))
    ->condition("n.status", 0, '>')
    ->execute()
    ->fetchAllAssoc("nid");

  $webforms = node_load_multiple(array_keys($webform_nids));

  $results = array();

  $viddler_force_update = variable_get('viddler_force_update', FALSE);
  variable_set('viddler_force_update', FALSE);

  foreach ($webforms as $webform) {
    foreach ($webform->webform["components"] as $cid => $component) {

      $found_leadworks_id = !empty($component["extra"]["leadworks_id"])
        && $component["extra"]["leadworks_id"] == $field_id;

      $found_silverpop_field = !empty($component["extra"]["silverpop_field"])
        && $component["extra"]["silverpop_field"] == $silverpop_name;

      if ($found_leadworks_id || $found_silverpop_field) {
        $result = _smg_global_update_webform_field_options($webform, $cid, $value_mappings);
        if ($result) $results[] = $result;
        continue;
      }

    }
  }

  variable_set('viddler_force_update', $viddler_force_update);

  return $results;

}

/**
 * This api call should be protected by limiting IP addresses
 * of callers.
 *
 * @return bool
 */
function _smg_global_secure_by_ip() {

  // True if working locally.
  if ($_SERVER['SERVER_ADDR'] == $_SERVER['REMOTE_ADDR']) return TRUE;

  $remote_ips = array($_SERVER['REMOTE_ADDR']);

  if (isset($_SERVER['HTTP_X_FORWARDED_FOR'])) {
    $remote_ips[] = $_SERVER['HTTP_X_FORWARDED_FOR'];
  }

  if (isset($_SERVER['HTTP_CF_CONNECTING_IP'])) {
    $remote_ips[] = $_SERVER['HTTP_CF_CONNECTING_IP'];
  }

  foreach ($remote_ips as $remote_ip) {
    if (in_array(
      $remote_ip,
      array(
        '52.14.178.21', // leadworks dev
        '74.121.198.155' // leadworks prod
      )
    )) {
      return TRUE;
    }
  }

  return FALSE;

}

/**
 * @param object $webform_node   - Webform node.
 * @param int    $cid            - Component id.
 * @param array  $value_mappings - Field option mappings.
 *
 * @return array
 *     Returns an array of results
 */
function _smg_global_update_webform_field_options($webform_node, $cid, $value_mappings) {

  global $base_url;

  $options = $webform_node->webform['components'][$cid]['extra']['items'];

  if (empty($options)) return NULL;

  $options = explode("\n", $options);

  $results = array(
    'title' => $webform_node->title,
    'path' => "{$base_url}/node/{$webform_node->nid}/webform/components/{$cid}#edit-extra-items",
    'updated' => array(),
    'no_match' => array()
  );

  foreach ($options as &$option) {

    $option = trim($option);

    // Exclude grouping syntax
    if (preg_match('/<.*>$/', $option)) continue;

    $old_option = $option;

    $match = _smg_global_update_webform_field_option($option, $value_mappings);

    if ($match === FIND_REPLACE_FOUND_REPLACED)
      $results['updated'][$old_option] = $option;
    else if ($match === FIND_REPLACE_NOT_FOUND)
      $results['no_match'][$old_option] = $option;
  }

  if (!empty($results['updated'])) {
    $webform_node->webform['components'][$cid]['extra']['items'] = implode("\n", $options);
    try {
      node_save($webform_node);
    }
    catch (Exception $e) {
      // Failed to update
      $results['updated'] = array();
      $results['error'] = TRUE;
      $results['error_message'] = $e->getMessage();
    }
  }

  $results['missing'] = _smg_global_find_missing_options($options, $value_mappings);

  return $results;

}

/**
 * Update a field option if there is a supplied mapping.
 *
 * @param string $option         - Actual option from the form component.
 * @param array  $value_mappings - 'Pick code' mappings in the form of
 *                                 `pick code` => `friendly name`.
 *
 * @return int
 *     1  - if found unmapped value and mapped it.
 *     0  - if found value, already mapped
 *     -1 - if didn't find value
 */
function _smg_global_update_webform_field_option(&$option, $value_mappings) {

  $value_and_display = explode("|", $option);
  $value = trim($value_and_display[0]);
  $display = !empty($value_and_display[1]) ? trim($value_and_display[1]) : NULL;

  $response = FIND_REPLACE_NOT_FOUND;

  // This is true when everything is already mapped correctly
  if (!empty($display) && array_search($display, $value_mappings) === $value) {
    $response = FIND_REPLACE_FOUND_OK;
  }

  // If above not true, then we have a 'value[|display name]', each
  // of which may be a pick code _or_ a friendly name in the
  // $value_mappings array

  // This could happen if the pick code was set to the wrong
  // display name.
  else if (array_key_exists($value, $value_mappings)) {
    $value_and_display[1] = $value_mappings[$value];
    $response = FIND_REPLACE_FOUND_REPLACED;
  }

  // If there is currently a 'value[|display name]' where the value
  // belongs to the array values of the $value_mappings array.  This
  // could happen if the value was never mapped in Drupal.
  else if (($pick_code = array_search(strtolower($value), array_map('strtolower', $value_mappings))) !== FALSE) {
    $value_and_display[0] = $pick_code;
    $value_and_display[1] = $value_mappings[$pick_code];
    $response = FIND_REPLACE_FOUND_REPLACED;
  }

  // If the existing 'display name' belongs to the array values of $value_mapping
  // (i.e. it corresponds to a friendly name), but the value doesn't equal
  // the corresponding pick code...for whatever reason.
  else if (
    !empty($display)
    && ($pick_code = array_search(strtolower($display), array_map('strtolower', $value_mappings))) !== FALSE
  ) {
    $value_and_display[0] = $pick_code;
    $value_and_display[1] = $value_mappings[$pick_code];
    $response = FIND_REPLACE_FOUND_REPLACED;
  }

  $option = implode("|", $value_and_display);

  return $response;

}

/**
 * Find field option values that are in LW but not in a given form.
 *
 * @param array $current_options
 * @param array $value_mappings
 *
 * @return array
 */
function _smg_global_find_missing_options($current_options, $value_mappings) {

  $non_missing_values = array();

  foreach ($current_options as $option) {

    // Exclude grouping syntax
    if (preg_match('/<.*>$/', $option)) continue;

    $value_and_display = explode("|", $option);
    $value = trim($value_and_display[0]);

    if (array_key_exists($value, $value_mappings)) {
      $non_missing_values[] = $value;
    }

  }

  $missing_values = array_diff(array_keys($value_mappings), $non_missing_values);

  $missing_values_with_mapping = array();

  foreach ($missing_values as $missing_value) {
    $missing_values_with_mapping[$missing_value] = $value_mappings[$missing_value];
  }

  return $missing_values_with_mapping;
}
