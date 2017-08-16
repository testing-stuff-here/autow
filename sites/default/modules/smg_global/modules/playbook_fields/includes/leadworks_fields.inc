<?php

/**
 * Validates fields in webform to ensure that the fields are present in the
 * Leadworks campaign.
 *
 * @param int $node
 *  The node ID of the webform that is being evaluated.
 *
 * @return string
 *  Returns either a string of unmatched fields, a congratulations message
 *  if all match, or an error message.
 */
function smg_validate_fields($node) {
  $node_object = node_load($node);
  $components = $node_object->webform['components'];
  $counter = 0;
  $errors = array();
  $list = array();
  $items = array();
  // get an array of the fields with attached leadworks ids.
  foreach ($components as $key => $value) {
    if (isset($value['extra']['leadworks_id'])) {
      $list[] .= $value['extra']['leadworks_id'];
    }
  }
  // email and source are required by all campaigns.  If the source field
  // is not on the form then inform the user.
  if (!in_array('source', $list)) {
    $errors[] .= "Missing 'source' field.";
  }
  foreach ($list as $key => $value) {
    // this section removes the email and source values from the array
    // so that they won't be compared against the field_ids
    if (($value == 'email') || ($value == 'source')) {
      unset($list[$key]);
    }
  }
  // resets the index values of the array.
  $list = array_values($list);
  // finds and sets the campaign id (cid) in the array to be sent.
  if (isset($node_object->field_master_leadworks_id['und'][0]['value'])) {
    $leadworks_master_id = $node_object->field_master_leadworks_id['und'][0]['value'];
    $list['cid'] .= $leadworks_master_id;
  }

  // Assemble a URL string with GET values for sending data to Leadworks.
  $query_list = http_build_query($list);
  // Change constant to production leadworks server.
  $ch = curl_init(LEADWORKS_VALIDATE_CAMPAIGN_FIELDS);

    // If the initialization fails, log the error and move on to the next
    // campaign.
  if ($ch === FALSE) {
    watchdog('playbook_fields', 'cURL initialization failed. The full cURL string which would have been posted: %curl', array('%curl' => $datapost_url), WATCHDOG_ERROR);
    continue;
  }

  curl_setopt($ch, CURLOPT_RETURNTRANSFER, TRUE);
  curl_setopt($ch, CURLOPT_TIMEOUT, 4);
  curl_setopt($ch, CURLOPT_POST, TRUE); //do an HTTP POST
  curl_setopt($ch, CURLOPT_POSTFIELDS, $query_list);
  // Log any failed posts with enough data to recover manually, but don't
  // stop execution.

  $curl_result = curl_exec($ch);
  if ($curl_result === FALSE) {
    watchdog('playbook_fields', 'The cURL call failed. The full query string which failed to post: %post', array('%id' => $campaign_id, '%post' => $post_fields), WATCHDOG_ERROR);
  }
  else {
    // since CURLOPT_RETURNTRANSFER is TRUE it will return the results of the
    // function it calls.  The leadworks method for this function returns
    // a json string which is decoded here.
    $result_array = json_decode($curl_result);
    // Loop through the returned values and search for matching field names
    // for a more human readable list.
    foreach ($result_array as $result) {
      foreach ($components as $value) {
        if ($value['extra']['leadworks_id'] == $result){
          $errors[] .= $value['name'];
        };
      }
    }
  }
  // close out the curl connection.
  curl_close($ch);
  // prepare a renderable array for displaying the output of the curl call
  if ($curl_result == 'Error') {
    $output = array(
      '#type' => 'markup',
      '#markup' => '<h2>Error</h2><p>' . t('There is no Leadworks Master Campaign ID associated with this Webform.') . '</p>',
    );
  }
  elseif (!empty($errors)) {
    $output = array(
      '#title' => 'The following items are not included in the Leadworks campaign:',
      '#theme' => 'item_list',
      '#items' => $errors,
    );
  }
  elseif (empty($errors) && ($curl_result != FALSE)) {
    $output = array(
      '#type' => 'markup',
      '#markup' => '<h2>Congratulations</h2><p>' . t('All Leadworks fields are present in the Leadworks campaign.') . '</p>',
    );
  }
  elseif (($curl_result == FALSE) || ($curl_result == 'Error')) {
    $output = array(
      '#type' => 'markup',
      '#markup' => '<h2>Error</h2><p>' . t('There was an error.  Please try again later.') . '</p>',
    );
  }

  return $output;
}

