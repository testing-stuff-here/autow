<?php

/**
 * @file
 *
 * Extra functions for managing PURF module's custom cache tables
 */

/**
 * Function that creates a record in the cache_purf table for a given PURF
 *
 * @param String $nid The node id of the PURF
 * @param array|boolean $extra_component An extra component to add to cache (necessary when adding
 *   a new component to a PURF webform)
 */
function _smg_purf_update_cache($nid, $extra_component = false) {

  // Create an array that we will store in cache
  $missing_required_cache = array(
    'standard' => array(
      'non_dependency' => array(),
      'dependency' => array(),
    ),
  );

  $webform = _smg_pop_up_build_purf_and_prepopulate($nid, false);

  foreach ($webform['submitted'] as $key => &$form_element) {
    if (is_array($form_element) && isset($form_element['#webform_component']) && isset($form_element['#type']) && $form_element['#type'] != 'value') {
      $extra = $form_element['#webform_component']['extra'];
      if ( !(array_key_exists('custom_question', $extra)) || ((array_key_exists('custom_question', $extra)) && !$extra['custom_question']) ) {
        if (array_key_exists('#required', $form_element) && $form_element['#required'] && !isset($extra['dependency'])) {
          $question_type = 'non_dependency';
        }
        if (isset($extra['dependency'])) {
          $question_type = 'dependency';
        }
        $missing_required_cache['standard'][$question_type][$extra['silverpop_field']] = array(
          'key' => $key,
          'type' => $form_element['#webform_component']['type'],
          'silverpop_field' => $extra['silverpop_field'],
          'items' => ($form_element['#webform_component']['type'] == 'smg_select') ? $extra['items'] : FALSE,
          'multiple' => (isset($extra['multiple']) && $extra['multiple']),
        );
      } else {
        if (array_key_exists('#required', $form_element) && $form_element['#required'] && !isset($extra['dependency'])) {
          $question_type = 'non_dependency';
        }
        if (isset($extra['dependency'])) {
          $question_type = 'dependency';
        }
        $missing_required_cache['custom'][$question_type][$extra['leadworks_id']] = array(
          'key' => $key,
          'type' => $form_element['#webform_component']['type'],
          'leadworks_id' => $extra['leadworks_id'],
          'items' => ($form_element['#webform_component']['type'] == 'smg_select') ? $extra['items'] : FALSE,
          'multiple' => (isset($extra['multiple']) && $extra['multiple']),
        );
      }
    }
  }


  // Store the $missing_required_cache array in cache, but convert
  // to json string first
  $missing_required_cache = json_encode($missing_required_cache);
  cache_set($nid, $missing_required_cache, 'cache_purf');

}

/**
 * Determines whether or not a PURF (or multiple PURFs) have any incomplete
 * answers (for a given user), but does so using the cached information
 *
 * @param array $user_status
 *  Array containing information about which questions the user has answered
 * @param array $cached_data
 *  Contains info about the PURF fields so we don't have to rebuild the form
 * @param string $email
 *  The users email
 */
function _smg_purf_unanswered_standard_from_cache(&$user_status, &$cached_data, $email) {

  // Get user's Silverpop info
  $contact = playbook_fields_get_silverpop_contact_by_email($email);
  
  foreach ($cached_data as $purf_key => $value) {

    if (!is_array($value)) {
      continue;
    }

    $missing_cache = json_decode($value['data'], true);
    // Set decoded value in $cached_data array for later use
    $cached_data[$purf_key]['data_decoded'] = $missing_cache;
    $missing_required = array();

    foreach ($missing_cache['standard']['non_dependency'] as $key => $value) {
      $default = isset($contact[$key]) ? $contact[$key] : '';
      if ($value['type'] == 'smg_select' && $value['multiple']) {
        if (is_string($default) && strlen($default) > 0) {
          $default = explode(';', $default);
        }
      }
      if (is_string($default) && strlen($default) > 0 || is_array($default) && sizeof($default) > 0) {
        $user_status["submitted"][$value['key']] = $default;
      }
      else {
        $missing_required[] = $key;
      }
    }

    if (sizeof($missing_cache['standard']['dependency']) > 0) {
      foreach ($missing_cache['standard']['dependency'] as $key => $value) {
        $is_visible = playbook_fields_is_visible($user_status["submitted"], $value['dependency']);
      }
      if ($is_visible) {
        $default = isset($contact[$key]) ? $contact[$key] : '';
        if (is_string($default) && strlen($default) > 0 || is_array($default) && sizeof($default) > 0) {
          $visible_dependents[$key] = $default;
        }
        else {
          $missing_required[] = $key;
        }
      }
    }

    if (sizeof($missing_required) > 0) {
      if ($purf_key == 'main_purf') {
        $user_status['missing_required'] = $missing_required;
        $user_status["standardQuestionsTotal"] = count($missing_cache['standard']['non_dependency']);
        if (isset($visible_dependents) && sizeof($visible_dependents) > 0) {
          $user_status["standardQuestionsVisibleDependentsTotal"] = count($visible_dependents);
        }
      }
      else {
        $user_status['extra'][$purf_key]['missing_required'] = $missing_required;
        $user_status['extra'][$purf_key]["standardQuestionsTotal"] = count($missing_cache['standard']['non_dependency']);
        if (isset($visible_dependents) && sizeof($visible_dependents) > 0) {
          $user_status['extra'][$purf_key]["standardQuestionsVisibleDependentsTotal"] = count($visible_dependents);
        }
      }
    }
  }
}

/**
 * Checks whether user has answered custom questions in PURF or PURFs, but uses
 * the database cache
 */
function _smg_purf_unanswered_custom_from_cache(&$user_status, $cached_data, $email) {

  // Combine all custom questions together before querying Leadworks
  $custom_questions = array();
  $missing_required = array();
  foreach ($cached_data as $key => $data) {

    if (!is_array($data)) {
      continue;
    }

    $value = $data['data_decoded'];
    if (isset($value['custom'])) {
      $custom_questions = array_merge($custom_questions, array_keys($value['custom']['non_dependency']), array_keys($value['custom']['dependency']));
    }
  }
  // Remove duplicates
  $custom_questions = array_unique($custom_questions);
  // Query leadworks
  $leadworks_fields = array('email'=>$email, 'ids'=>$custom_questions);
  $leadworks_fields_values = _smg_pop_up_leadworks_get_fields($leadworks_fields);
  $leadworks_fields_values_array = array();
  foreach ($leadworks_fields_values as $id => $value) {
    $leadworks_fields_values_array[$id] = $value;
  }

  foreach ($cached_data as $key => $data) {

    if (!is_array($data)) {
      continue;
    }

    $value = $data['data_decoded'];
    if (isset($value['custom'])) {
      $purf_custom = array_merge(array_keys($value['custom']['non_dependency']), array_keys($value['custom']['dependency']));
      $custom_q_details = array();
      foreach ($purf_custom as $field_id) {
        if ($leadworks_fields_values_array[$field_id] == NULL) {
          $custom_q_details['custom']['complete']= FALSE;
          $custom_q_details['custom']['unanswered'][] = $field_id;
        }
        else {
          $custom_q_details['custom']['answered'][$field_id] = $leadworks_fields_values_array[$field_id];
        }
      }

      // Add custom_q_details to user_status array, but check if it's the main purf
      if ($key == 'main_purf'){
        $user_status['custom'] = $custom_q_details['custom'];
      }
      else {
        $user_status['extra'][$key]['custom'] = $custom_q_details['custom'];
      }

      _smg_purf_unanswered_custom_from_cache_check_dependency($user_status, $key, $value, $leadworks_fields_values_array, $missing_required);

    }
  }
}

/**
 * Using a cached array, check the user's submissions to Leadworks against the array,
 * taking dependencies into account
 *
 * @param array $user_status
 *  Array containing information about which questions the user has or hasn't answered
 * @param string $purf_key
 *  Either 'main_purf' or a unique string representing an "Extra" PURF
 * @param array $cached_values
 *  User data from cache table
 * @param array $leadworks_fields_values_array
 *  Leadworks answers
 * @param array $missing_required
 *  @todo possibly remove $missing_required from param list and just initiate within function
 */
function _smg_purf_unanswered_custom_from_cache_check_dependency(&$user_status, $purf_key, $cached_values, $leadworks_fields_values_array, $missing_required) {

  foreach ($cached_values['custom']['non_dependency'] as $key => $value) {
    $default = isset($leadworks_fields_values_array[$key]) ? $leadworks_fields_values_array[$key] : '';
    if ($value['type'] == 'smg_select' && $value['multiple']) {
      $default = explode(';', $default);
    }
    if (is_string($default) && strlen($default) > 0 || is_array($default) && sizeof($default) > 0) {
      $submitted[$key] = $default;
    }
    else {
      $missing_required[] = $key;
    }
  }
  if (sizeof($cached_values['custom']['dependency']) > 0) {
    foreach ($cached_values['custom']['dependency'] as $key => $value) {
      $is_visible = playbook_fields_is_visible($submitted, $value['dependency']);
    }
    if ($is_visible) {
      $default = isset($leadworks_fields_values_array[$key]) ? $leadworks_fields_values_array[$key] : '';
      if (is_string($default) && strlen($default) > 0 || is_array($default) && sizeof($default) > 0) {
        $submitted[$key] = $default;
      }
      else {
        $missing_required[] = $key;
      }
    }
  }

  if (sizeof($missing_required) > 0) {
    if ($purf_key == 'main_purf') {
      $user_status['missing_required_custom'] = $missing_required;
    }
    else {
      $user_status['extra'][$purf_key]['missing_required_custom'] = $missing_required;
    }
  }

}

function _smg_purf_clear_cache($nid) {
  if (cache_get($nid, 'cache_purf')) {
    cache_clear_all($nid, 'cache_purf');
  }
}

/**
 * Submit handler for forms where we want to manage the PURF cache upon submission
 */
function _smg_purf_update_cache_on_submit($form, &$form_state) {
  _smg_purf_update_cache($form['#node']->nid);
}
