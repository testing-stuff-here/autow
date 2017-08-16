<?php
/**
 * @file
 * Administration functions for playbook fields module.
 */

/**
 * Renders page with form to display the last time a user submitted each form.
 */
function playbook_fields_who_submitted() {
  $output = drupal_render(drupal_get_form('playbook_fields_who_submitted_form'));

  $output .= '<div id="result"></div>';

  return $output;
}

/**
 * Returns the playbook_fields_who_submitted form.
 */
function playbook_fields_who_submitted_form($form, &$form_state) {
  $form['email'] = array(
    '#type' => 'textfield',
    '#title' => t('Email'),
    '#required' => TRUE,
    '#description' => t('Enter Email Address'),
    '#size' => 60,
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Search'),
    '#ajax' => array(
      'callback' => 'playbook_fields_ajax_who_submitted',
      'wrapper' => 'result',
    ),
  );

  return $form;
}

/**
 * Returns a table of all the forms that they submitted.
 */
function playbook_fields_ajax_who_submitted($form, $form_state) {
  $output = '<h3>No Results</h3>';

  if (!empty( $form_state['values']['email'])) {
    // Query all the times the user with email has submitted forms.
    $query = "SELECT w.nid, n.title, ws.submitted, ws.sid, sp.id
              FROM {webform_submitted_data} w
              LEFT JOIN {node} n ON n.nid = w.nid
              LEFT JOIN {webform_submissions} ws ON w.sid = ws.sid
              LEFT JOIN {playbook_fields_silverpop_api_tracking} sp ON w.sid = sp.submission_id 
              WHERE w.data = :email
              ORDER BY ws.submitted DESC";
    $result = db_query($query, array(':email' => $form_state['values']['email']));

    $header = array(
      'Submission ID',
      'Submission Data',
      'Form',
      'Date',
    );

    $rows = array();
    $already_used = array();

    // Go through the query result and only one row per node so it only displays
    // the last time a user submitted a form.
    foreach ($result as $data) {      
      if (!in_array($data->nid, $already_used)) {
        $rows[] = array(
          l($data->sid, 'node/' . $data->nid . '/submission/' . $data->sid),
          ($data->id) ? l('View', 'admin/config/content/playbook-fields/view-submission/' . $data->sid) : '',      
          l(t($data->title), 'node/' . $data->nid),
          date("m/d/Y", $data->submitted),
        );

        $already_used[] = $data->nid;
      }
    }
    if ($rows) {
      $output = theme('table', array('header' => $header, 'rows' => $rows));
    }
  }

  return '<div id="result">' . $output . '</div>';
}

function playbook_fields_admin() {
  $output = drupal_render(drupal_get_form('playbook_fields_admin_form'));

  return $output;
}

function playbook_fields_admin_form($form, &$form_state) {

  $form['silverpop_ids'] = array(
    '#type' => 'textfield',
    '#title' => t("Silverpop Field"),
    '#description' => t("Enter the name of the Silverpop field to find all webform components that are using it"),
    '#size' => 60,
    '#maxlength' => 255,
    '#required' => FALSE,
  );
  $form['result'] = array(
    '#type' => 'markup',
    '#prefix' => '<div id="result">',
    '#suffix' => '</div>',
    '#markup' => '',
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => 'Search',
    '#ajax' => array(
      'callback' => 'playbook_fields_admin_silverpop_search',
      'wrapper' => 'result',
    ),
  );

  return $form;
}

function playbook_fields_admin_silverpop_search($form, $form_state) {

  if (isset($form_state['input']['silverpop_ids']) && strlen($form_state['input']['silverpop_ids']) > 0) {
    $input_value = $form_state['input']['silverpop_ids'];
    $element = $form['result'];

    // Get all smg components
    $result = db_query("SELECT * FROM webform_component WHERE type LIKE '%smg%'");

    $components = array();
    $silverpop_ids = array();
    foreach ($result as $record) {
      $components[] = array(
      'record' => $record,
      'extra' => (property_exists($record, 'extra')) ? unserialize($record->extra) : array(),
      );
    }
    foreach ($components as $key => $component) {
      if (isset($component['extra']['silverpop_field'])) {
        $silverpop_ids[$component['extra']['silverpop_field']][] = $key;
      }
    }
    
    if (!isset($silverpop_ids[$input_value])) {
      $element['#markup'] = '<h4>No Results</h4>';
      return $element;
    }

    $header = array(
      'Playbook Title',
      'Component Name',
      'Edit Component',
    );
    $rows = array();

    foreach ($silverpop_ids[$input_value] as $keyFromComponentArray) {
      $webform = node_load($components[$keyFromComponentArray]['record']->nid);
      $component_name = $components[$keyFromComponentArray]['record']->name;
      $component_id = $components[$keyFromComponentArray]['record']->cid;
      $rows[] = array(
        $webform->title,
        $component_name,
        l('Edit', 'node/' . $webform->nid . '/webform/components/' . $component_id),
      );
    }

    if ($rows) {
      $element['#markup'] = theme('table', array('header' => $header, 'rows' => $rows));
      return $element;
    }
  }

}

function playbook_fields_view_silverpop_submissions($sid) {
  // Look for submission
  $result = db_query("SELECT * FROM playbook_fields_silverpop_api_tracking WHERE submission_id = :sid", array(':sid' => $sid));
  $result = $result->fetchAssoc();
  
  if (!$result) {
    return '<h4>No Record Found</h4>';
  }

  if (isset($result['submission_data'])) {

    $p = xml_parser_create();
    xml_parse_into_struct($p, $result['submission_data'], $vals, $index);
    xml_parser_free($p);    
    $fieldArray = array();
    foreach ($vals as $key => $row) {
      if ($row['tag'] === 'NS1:VALUE') {
        $fieldArray[$vals[$key - 1]['value']] = $row['value'];
      }
    }    

    $header = array(
    'field',
    'value',
    );
    $rows = array();

    foreach($fieldArray as $field_name => $field_value) {
      $rows[] = array(
        $field_name,
        $field_value,
      );
    }

    if (count($rows) > 0) {
      return theme('table', array('header' => $header, 'rows' => $rows));
    }
    else {
      return '';
    }

  }
  
}
