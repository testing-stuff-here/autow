<?php
/**
 * @file
 *  Handles PMG Services admin items.
 */

/**
 * Lists all the silverpop forms (distince form_ids).
 *
 * @param string $output
 *   The html table.
 */
function pmg_services_silverpop_forms() {
  $forms = array();

  // Get distict form ids.
  $query = db_select('pmg_services_silverpop_post_log', 'pmg')
    ->distinct()
    ->fields('pmg', array('form_id'))
    ->orderBy('pmg.date', 'DESC'); // I'm hoping by ordering desc it will show the latest forms first.
  $result = $query->execute();

  while ($record = $result->fetchAssoc()) {
    $forms[] = array(l(t($record['form_id']), 'admin/pmg-services/silverpop/form/' . $record['form_id']));
  }

  $header = array(
    'Forms With Submission Data',
  );

  $output = theme('table', array('header' => $header, 'rows' => $forms));

  return $output;
}

/**
 * Lists the submissions for a form.
 *
 * @param string $form_id
 *   The Form Id.
 *
 * @return string $output
 *   Html output.
 */
function pmg_services_form_submissions($form_id) {
  $output = '';
  $limit = 50;

    // Add breadcrumb.
  global $base_url;
  $breadcrumb[] = l('PMG Services Silverpop Post Forms', 'admin/pmg-services/silverpop/post-forms');
  $breadcrumb[] = l(drupal_get_title(), $base_url . request_uri()); // Link to current URL
  drupal_set_breadcrumb($breadcrumb);

  // Get submissions from the database.
  $query = db_select('pmg_services_silverpop_post_log', 'pmg')
    ->extend('PagerDefault')
    ->fields('pmg', array('sid', 'email', 'form_id', 'date'))
    ->condition('form_id', $form_id)
    ->orderBy('pmg.date', 'DESC')
    ->limit($limit);
  $result = $query->execute()->fetchAll();

  if ($result) {
    // Set the header.
    foreach ($result[0] as $field_name => $value) {
      $header[] = $field_name;
    }

    // Set the row values.
    foreach ($result as $key => $data) {
      foreach ($data as $field_name => $value) {
        if ($field_name == 'date') {
          $value = date("m-d-Y g:i a", $value);
        }
        else if ($field_name == 'sid') {
          $value = l($value, 'admin/pmg-services/silverpop/submission/' . $value);
        }
        $rows[$key][] = $value;
      }
    }

    $output = theme('table', array('header' => $header, 'rows' => $rows));
    $output .= theme('pager');

  }

  return $output;
}

/**
 * Lists the values set in the data element which is the full Silverpop object.
 *
 * @param integer $sid
 *  Submission id.
 *
 * @param string $output
 *  Html output.
 */
function pmg_services_submission($sid) {
  $submission = pmg_services_get_submission($sid);

  // Add breadcrumb.
  global $base_url;
  $breadcrumb[] = l($submission['form_id'], 'admin/pmg-services/silverpop/form/' . $submission['form_id']);
  $breadcrumb[] = l(drupal_get_title(), $base_url . request_uri()); // Link to current URL
  drupal_set_breadcrumb($breadcrumb);

  $data = json_decode($submission['data']);

  if ($data) {
    $header = array(
      'Silverpop Field Name',
      'Value',
    );

    foreach ($data as $field_name => $value) {
      $rows[] = array(
        $field_name,
        $value,
      );
    }

    $output = theme('table', array('header' => $header, 'rows' => $rows));
  }

  return $output;
}

function pmg_services_get_submission($sid) {
  $query = db_select('pmg_services_silverpop_post_log', 'pmg')
    ->fields('pmg')
    ->condition('sid', $sid);
  $result = $query->execute()->fetchAssoc();

  return $result;
}
