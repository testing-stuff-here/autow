<?php
require_once(drupal_get_path('module', 'playbook_fields') . '/includes/constants.inc');
/**
 * @file
 * Playbook Fields module textfield component.
 */

/**
 * Implements _webform_defaults_component().
 */
function _webform_defaults_smg_auto_address() {
  return array(
    'name' => '',
    'form_key' => NULL,
    'pid' => 0,
    'weight' => 0,
    'value' => '',
    'mandatory' => 0,
    'extra' => array(
      'width' => '',
      'maxlength' => '',
      'field_prefix' => '',
      'field_suffix' => '',
      'disabled' => 0,
      'unique' => 0,
      'title_display' => 0,
      'description' => '',
      'attributes' => array(),
      'private' => FALSE,
    ),
  );
}

/**
 * Implements _webform_theme_component().
 */
function _webform_theme_smg_auto_address() {
  return array(
    'webform_display_smg_auto_address' => array(
      'render element' => 'element',
      'file' => 'includes/smg_autocomplete_address.inc',
      'path' => drupal_get_path('module', 'playbook_fields'),
    ),
  );
}

/**
 * Implements _webform_edit_component().
 */
function _webform_edit_smg_auto_address($component) {
  $form = array();
  $form['display']['collapsible'] = array(
    '#type' => 'checkbox',
    '#title' => t('Collapsible'),
    '#default_value' => $component['extra']['collapsible'],
    '#description' => t('If this fieldset is collapsible, the user may open or close the fieldset.'),
    '#weight' => 0,
    '#parents' => array('extra', 'collapsible'),
  );
  $form['display']['collapsed'] = array(
    '#type' => 'checkbox',
    '#title' => t('Collapsed by Default'),
    '#default_value' => $component['extra']['collapsed'],
    '#description' => t('Collapsible fieldsets are "open" by default. Select this option to default the fieldset to "closed."'),
    '#weight' => 3,
    '#parents' => array('extra', 'collapsed'),
  );
  $form['custom_question'] = array(
    '#type' => 'checkbox',
    '#title' => t('Custom Question'),
    '#default_value' => $component['extra']['custom_question'],
    '#description' => t('Please specify if this form item is custom question on a registration form'),
    '#weight' => 0,
    '#parents' => array('extra', 'custom_question'),
  );
  $form['smg_pop_no_autosubmit'] = array(
    '#type' => 'checkbox',
    '#title' => t('Exclude from PURF submission'),
    '#default_value' => $component['extra']['smg_pop_no_autosubmit'],
    '#description' => '<strong>For PURFs Only:</strong> Exclude this question from PURF submissions <em>unless</em> it is a full PURF (i.e. all of the standard lead-gen questions and the custom questions).',
    '#weight' => 0,
    '#parents' => array('extra', 'smg_pop_no_autosubmit'),
  );
  $form['display']['width'] = array(
    '#type' => 'textfield',
    '#title' => t('Width'),
    '#default_value' => $component['extra']['width'],
    '#description' => t('Width of the textfield.') . ' ' . t('Leaving blank will use the default size.'),
    '#size' => 5,
    '#maxlength' => 10,
    '#weight' => 0,
    '#parents' => array('extra', 'width'),
  );
  $form['display']['field_prefix'] = array(
    '#type' => 'textfield',
    '#title' => t('Prefix text placed to the left of the textfield'),
    '#default_value' => $component['extra']['field_prefix'],
    '#description' => t('Examples: $, #, -.'),
    '#size' => 20,
    '#maxlength' => 127,
    '#weight' => 1.1,
    '#parents' => array('extra', 'field_prefix'),
  );
  $form['display']['field_suffix'] = array(
    '#type' => 'textfield',
    '#title' => t('Postfix text placed to the right of the textfield'),
    '#default_value' => $component['extra']['field_suffix'],
    '#description' => t('Examples: lb, kg, %.'),
    '#size' => 20,
    '#maxlength' => 127,
    '#weight' => 1.2,
    '#parents' => array('extra', 'field_suffix'),
  );
  $form['validation']['unique'] = array(
    '#type' => 'checkbox',
    '#title' => t('Unique'),
    '#return_value' => 1,
    '#description' => t('Check that all entered values for this field are unique. The same value is not allowed to be used twice.'),
    '#weight' => 1,
    '#default_value' => $component['extra']['unique'],
    '#parents' => array('extra', 'unique'),
  );
  $form['validation']['maxlength'] = array(
    '#type' => 'textfield',
    '#title' => t('Maxlength'),
    '#default_value' => $component['extra']['maxlength'],
    '#description' => t('Maximum length of the textfield value.'),
    '#size' => 5,
    '#maxlength' => 10,
    '#weight' => 2,
    '#parents' => array('extra', 'maxlength'),
  );
  $form['linking'] = array(
    '#type' => 'fieldset',
    '#title' => 'Data Linking',
    '#collapsible' => TRUE,
    '#weight' => 20,
    'leadworks_address1_id' => array(
      '#type' => 'textfield',
      '#title' => t('Leadworks Address 1 ID'),
      '#default_value' => isset($component['extra']['leadworks_address1_id']) ? $component['extra']['leadworks_address1_id'] : 16,
      '#description' => t('ID of corresponding Leadworks field for Address 1.'),
      '#size' => 20,
      '#maxlength' => 255,
      '#weight' => 0,
      '#parents' => array('extra', 'leadworks_address1_id'),
    ),
    'leadworks_address2_id' => array(
      '#type' => 'textfield',
      '#title' => t('Leadworks Address 2 ID'),
      '#default_value' => isset($component['extra']['leadworks_address2_id']) ? $component['extra']['leadworks_address2_id'] : 17,
      '#description' => t('ID of corresponding Leadworks field for Address 2.'),
      '#size' => 20,
      '#maxlength' => 255,
      '#weight' => 1,
      '#parents' => array('extra', 'leadworks_address2_id'),
    ),
    'leadworks_city_id' => array(
      '#type' => 'textfield',
      '#title' => t('Leadworks City ID'),
      '#default_value' => isset($component['extra']['leadworks_city_id']) ? $component['extra']['leadworks_city_id'] : 18,
      '#description' => t('ID of corresponding Leadworks field for City.'),
      '#size' => 20,
      '#maxlength' => 255,
      '#weight' => 2,
      '#parents' => array('extra', 'leadworks_city_id'),
    ),
    'leadworks_state_id' => array(
      '#type' => 'textfield',
      '#title' => t('Leadworks State ID'),
      '#default_value' => isset($component['extra']['leadworks_state_id']) ? $component['extra']['leadworks_state_id'] : 20,
      '#description' => t('ID of corresponding Leadworks field for State.'),
      '#size' => 20,
      '#maxlength' => 255,
      '#weight' => 3,
      '#parents' => array('extra', 'leadworks_state_id'),
    ),
    'leadworks_zip_id' => array(
      '#type' => 'textfield',
      '#title' => t('Leadworks Zip ID'),
      '#default_value' => isset($component['extra']['leadworks_zip_id']) ? $component['extra']['leadworks_zip_id'] : 19,
      '#description' => t('ID of corresponding Leadworks field for Zip/Postal code.'),
      '#size' => 20,
      '#maxlength' => 255,
      '#weight' => 4,
      '#parents' => array('extra', 'leadworks_zip_id'),
    ),
    'silverpop_field' => array(
      '#type' => 'textfield',
      '#title' => t('Silverpop field'),
      '#default_value' => isset($component['extra']['silverpop_field'])?$component['extra']['silverpop_field']:'Address Single Line',
      '#description' => t('Name of corresponding Silverpop field. Case sensitive. The value is the one-line Smartystreets verified address.'),
      '#size' => 40,
      '#maxlength' => 255,
      '#weight' => 6,
      '#parents' => array('extra', 'silverpop_field'),
    ),
    'gotowebinar_field' => array(
      '#type' => 'textfield',
      '#title' => t('GotoWebinar field'),
      '#default_value' => isset($component['extra']['gotowebinar_field'])?$component['extra']['gotowebinar_field']:'address',
      '#description' => t('Name of corresponding GotoWebinar field. Case sensitive.'),
      '#size' => 40,
      '#maxlength' => 255,
      '#weight' => 7,
      '#parents' => array('extra', 'gotowebinar_field'),
    ),
    'prepopulate' => array(
      '#type' => 'checkbox',
      '#title' => t('Prepopulate'),
      '#default_value' => isset($component['extra']['prepopulate'])?$component['extra']['prepopulate']:TRUE,
      '#description' => t('Check if you want this field to prepopulate with user data from this Silverpop field.'),
      '#weight' => 8,
      '#parents' => array('extra', 'prepopulate'),
    ),
  );
  $form['extra']['dependency'] = array(
    '#type' => 'textfield',
    '#title' => t('Dependency'),
    '#default_value' => isset($component['extra']['dependency']) ? $component['extra']['dependency'] : "('country' = 'UNITED STATES')",
    '#description' => t(DEPENDENCY_TEXT),
    '#weight' => 20,
    '#size' => 120,
    '#maxlength' => DEPENDENCY_LIMIT,
    '#required' => FALSE,
  );

  return $form;
}

/**
 * Implements _webform_render_component().
 */
function _webform_render_smg_auto_address($component, $value = NULL, $filter = TRUE) {
  // UN-COMMENT BELOW WHEN IMPLEMENTING FULLY (WITHOUT CUSTOM A/B TESTING)
  /*// Add Smarty Streets JS
  $options = array(
    'type' => 'external',
    'scope' => 'footer',
    'weight' => 0,
  );
  drupal_add_js('//d79i1fxsrar4t.cloudfront.net/jquery.liveaddress/2.8/jquery.liveaddress.min.js', $options);
  $options = array(
    'type' => 'file',
    'scope' => 'footer',
    'weight' => 50,
  );
  drupal_add_js(drupal_get_path('module', 'playbook_fields') . '/includes/smg_autocomplete_address.js', $options);*/

  $node = isset($component['nid']) ? node_load($component['nid']) : NULL;

  $element = array(
    '#type' => 'fieldset',
    '#title' => NULL,
    '#default_value' => $filter ? _webform_filter_values($component['value'], $node, NULL, NULL, FALSE) : $component['value'],
    '#required' => (isset($component['required'])) ? $component['required'] : $component['mandatory'], // Account for webform change @see https://www.drupal.org/node/1609324#webform-required
    '#weight' => $component['weight'],
    '#field_prefix' => empty($component['extra']['field_prefix']) ? NULL : ($filter ? _webform_filter_xss($component['extra']['field_prefix']) : $component['extra']['field_prefix']),
    '#field_suffix' => empty($component['extra']['field_suffix']) ? NULL : ($filter ? _webform_filter_xss($component['extra']['field_suffix']) : $component['extra']['field_suffix']),
    '#description' => $filter ? _webform_filter_descriptions($component['extra']['description'], $node) : $component['extra']['description'],
    '#collapsible' => $component['extra']['collapsible'],
    '#collapsed' => $component['extra']['collapsed'],
    '#attributes' => array('class' => array('webform-component-fieldset', 'autocomplete_address_fieldset', 'webform-component', 'webform-component-smg_autocomplete_address'), 'id' => 'webform-component-' . $component['form_key']),
    '#pre_render' => array('webform_fieldset_prerender', 'webform_element_title_display'),
    '#translatable' => array('title', 'description'),
  );

  $element['smg_autocomplete_address_text'] = array(
    '#type' => 'textfield',
    '#title' => $filter ? _webform_filter_xss($component['name']) : $component['name'],
    '#title_display' => $component['extra']['title_display'] ? $component['extra']['title_display'] : 'before',
    '#default_value' => $filter ? _webform_filter_values($component['value'], $node, NULL, NULL, FALSE) : $component['value'],
    '#required' => (isset($component['required'])) ? $component['required'] : $component['mandatory'], // Account for webform change @see https://www.drupal.org/node/1609324#webform-required
    '#weight' => $component['weight'],
    '#field_prefix' => empty($component['extra']['field_prefix']) ? NULL : ($filter ? _webform_filter_xss($component['extra']['field_prefix']) : $component['extra']['field_prefix']),
    '#field_suffix' => empty($component['extra']['field_suffix']) ? NULL : ($filter ? _webform_filter_xss($component['extra']['field_suffix']) : $component['extra']['field_suffix']),
    '#description' => $filter ? _webform_filter_descriptions($component['extra']['description'], $node) : $component['extra']['description'],
    '#attributes' => array('class' => array('autocomplete_address'), 'id' => 'smg_autocomplete_address_text', 'autocomplete' => 'smartystreets'),
    '#theme_wrappers' => array('webform_element'),
    '#translatable' => array('title', 'description', 'field_prefix', 'field_suffix'),
  );

  // Enforce uniqueness.
  if ($component['extra']['unique']) {
    $element['address_autocompleted']['#element_validate'][] = 'webform_validate_unique';
  }

  // Change the 'width' option to the correct 'size' option.
  if ($component['extra']['width'] > 0) {
    $element['address_autocompleted']['#size'] = $component['extra']['width'];
  }
  if ($component['extra']['maxlength'] > 0) {
    $element['address_autocompleted']['#maxlength'] = $component['extra']['maxlength'];
  }

  if (isset($value)) {
    $element['address_autocompleted']['#default_value'] = $value[0];
  }

  $element['address_response'] = array(
    '#type' => 'hidden',
    '#title' => 'Address Response',
    '#default_value' => '',
    '#attributes' => array('class' => array('autocomplete_address'), 'id' => 'smg_autocomplete_address_response', 'autocomplete' => 'off'),
  );

  $element['address_line_1'] = array(
    '#type' => 'hidden',
    '#title' => 'Line 1',
    '#default_value' => '',
    '#attributes' => array('class' => array('autocomplete_address'), 'id' => 'smg_autocomplete_address_line_1', 'autocomplete' => 'off'),
  );

  $element['address_line_2'] = array(
    '#type' => 'hidden',
    '#title' => 'Line 2',
    '#default_value' => '',
    '#attributes' => array('class' => array('autocomplete_address'), 'id' => 'smg_autocomplete_address_line_2', 'autocomplete' => 'off'),
  );

  $element['address_city'] = array(
    '#type' => 'hidden',
    '#title' => 'City',
    '#default_value' => '',
    '#attributes' => array('class' => array('autocomplete_address'), 'id' => 'smg_autocomplete_address_city', 'autocomplete' => 'off'),
  );

  $element['address_state'] = array(
    '#type' => 'hidden',
    '#title' => 'State',
    '#default_value' => '',
    '#attributes' => array('class' => array('autocomplete_address'), 'id' => 'smg_autocomplete_address_state', 'autocomplete' => 'off'),
  );

  $element['address_zip'] = array(
    '#type' => 'hidden',
    '#title' => 'State',
    '#default_value' => '',
    '#attributes' => array('class' => array('autocomplete_address'), 'id' => 'smg_autocomplete_address_zip', 'autocomplete' => 'off'),
  );

  return $element;
}

/**
 * Implements _webform_display_component().
 */
function _webform_display_smg_auto_address($component, $value, $format = 'html') {
  return array(
    '#title' => $component['name'],
    '#weight' => $component['weight'],
    '#theme' => 'webform_display_smg_auto_address',
    '#theme_wrappers' => $format == 'html' ? array('webform_element') : array('webform_element_text'),
    '#field_prefix' => $component['extra']['field_prefix'],
    '#field_suffix' => $component['extra']['field_suffix'],
    '#format' => $format,
    '#value' => isset($value[0]) ? $value[0] : '',
    '#translatable' => array('title', 'field_prefix', 'field_suffix'),
  );
}

/**
 * Format the output of data for this component.
 */
function theme_webform_display_smg_auto_address($variables) {
  $element = $variables['element']['address_autocompleted'];
  $prefix = $element['#format'] == 'html' ? '' : $element['#field_prefix'];
  $suffix = $element['#format'] == 'html' ? '' : $element['#field_suffix'];
  $value = $element['#format'] == 'html' ? check_plain($element['#value']) : $element['#value'];
  return $value !== '' ? ($prefix . $value . $suffix) : ' ';
}

/**
 * Implements _webform_analysis_component().
 */
function _webform_analysis_smg_auto_address($component, $sids = array()) {
  $query = db_select('webform_submitted_data', 'wsd', array('fetch' => PDO::FETCH_ASSOC))
    ->fields('wsd', array('data'))
    ->condition('nid', $component['nid'])
    ->condition('cid', $component['cid']);

  if (count($sids)) {
    $query->condition('sid', $sids, 'IN');
  }

  $nonblanks = 0;
  $submissions = 0;
  $wordcount = 0;

  $result = $query->execute();
  foreach ($result as $data) {
    if (drupal_strlen(trim($data['data'])) > 0) {
      $nonblanks++;
      $wordcount += str_word_count(trim($data['data']));
    }
    $submissions++;
  }

  $rows[0] = array(t('Left Blank'), ($submissions - $nonblanks));
  $rows[1] = array(t('User entered value'), $nonblanks);
  $rows[2] = array(t('Average submission length in words (ex blanks)'), ($nonblanks != 0 ? number_format($wordcount/$nonblanks, 2) : '0'));
  return $rows;
}

/**
 * Implements _webform_table_component().
 */
function _webform_table_smg_auto_address($component, $value) {
  return check_plain(empty($value[0]) ? '' : $value[0]);
}

/**
 * Implements _webform_csv_headers_component().
 */
function _webform_csv_headers_smg_auto_address($component, $export_options) {
  $header = array();
  $header[0] = '';
  $header[1] = '';
  $header[2] = $component['name'];
  return $header;
}

/**
 * Implements _webform_csv_data_component().
 */
function _webform_csv_data_smg_auto_address($component, $export_options, $value) {
  return !isset($value[0]) ? '' : $value[0];
}
