<?php
/**
 * @file
 *
 * Provides basic functions for the PURF layout administration pages
 */

/**
 * Callback for the choose-layout page.  User selects which type of layout to use for this form
 * and we modify the smg_pop_up_layout database table
 */
function smg_pop_up_layout($form, $form_state, $node){
  // Check to see if DB record exists
  $result = db_query("SELECT * FROM smg_pop_up_layouts WHERE entity_id = :nid", array(':nid' => $node->nid))->fetch();
  $layout_default = NULL;
  if($result){
    $layout_default = ($result->layout_in_use == 'one_column') ? 'one' : 'two';
  }

  $form = array();
  $layout_options = array(
    'one' => t('One Column'),
    'two' => t('Two Column'),
  );
  $form['#prefix'] = '<div style="margin-bottom:100px;">';
  $form['#suffix'] = '</div>';
  $form['layout_style'] = array(
    '#title' => 'What kind of layout would you like to use for this pop-up form?',
    '#type' => 'radios',
    '#default_value' => $layout_default,
    '#options' => $layout_options,
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => 'Submit',

  );
  $form['#node'] = $node;
  return $form;
}

/**
 * Submit handler for smg_pop_up_layout form
 */
function smg_pop_up_layout_submit($form, &$form_state){
  //ddl($form_state);
  //ddl($form);

  $webform_nid = $form['#node']->nid;
  if(isset($form_state['values']['layout_style'])){
    $layout_style = ($form_state['values']['layout_style'] == 'one') ? 'one_column' : 'two_column';
    db_merge('smg_pop_up_layouts')
      ->key(array('entity_id' => $webform_nid))
      ->fields(array(
        'layout_in_use' => $layout_style,
      ))
      ->execute();
  }
}

/**
 * Page Callback for the Pop-Up Layout Template Drag & Drop Pages.  This will make use of one of the two templates
 * defined in our hook_theme.
 *
 * @param object $node
 *  The node object
 * @param string $layout_type
 *  Either one-column or two-column
 *
 * @return string
 *  HTML String
 */
function smg_pop_up_layout_template_build($node, $layout_type){

  $layout_type = _smg_pop_up_hyphens_to_underscores($layout_type);

  // Get webform components
  $components = smg_pop_up_layout_processor($node, $layout_type);

  $is_admin = path_is_admin(current_path());
  if ($is_admin){
    // Add jquery UI libraries
    drupal_add_css(drupal_get_path('module','smg_pop_up') . '/css/jquery-ui.css');
    drupal_add_js(drupal_get_path('module','smg_pop_up') . '/js/jquery-ui.min.js', array('type'=>'file', 'preprocess'=>FALSE, 'every_page'=>FALSE));
  }

  if($layout_type == 'one_column'){
    drupal_add_css(drupal_get_path('module','smg_pop_up') . '/css/one-column.css');
    drupal_add_js(drupal_get_path('module','smg_pop_up') . '/js/one-column.js');
    return theme('smg_pop_up_one_column', array('node' => $node, 'components' => $components));
  }
  else{
    drupal_add_css(drupal_get_path('module','smg_pop_up') . '/css/two-column.css', array('type' => 'file', 'group' => CSS_SYSTEM, 'every_page' => false, 'preprocess' => false));
    drupal_add_js(drupal_get_path('module','smg_pop_up') . '/js/two-column.js');
    return theme('smg_pop_up_two_column', array('node' => $node, 'components' => $components));
  }
}

/**
 * Constructs a structured array that will be passed to the theming functions for the layout admin pages.
 *
 * @param object $node
 *  The webform node
 * @param string $layout_type
 *  Either one_column or two_column
 *
 * @return array
 *  Structured array containing the fields in the PURF webform
 */
function smg_pop_up_layout_processor($node, $layout_type){

  // Check the database to see if current node already has a defined template layout (in the form of a JSON string)
  $layout_json = smg_pop_up_layout_template_query($node->nid, $layout_type);
  $components = array('components'=>array(), 'column1'=>array(), 'column2'=>array());
  if ($layout_json) {
    $components = smg_pop_up_layout_json_decode($layout_json, $node->nid);
  }

  $components['component_names'] = _smg_pop_up_components_generate_array($node->webform['components']);

  // Get the form_key and name for each field/component of the current webform that isn't saved in the JSON object
  $components['fields'] = array();
  foreach ($node->webform['components'] as $component) {
    if (!in_array($component['form_key'], $components['components'])) {
      $components['fields'][] = array(
        'form_key' => $component['form_key'],
        'name' => $component['name'],
        'type' => $component['type'],
      );
    }
  }

  return $components;
}

/**
 * This function checks the smg_pop_up_layouts and smg_pop_up_layouts_data tables in the database, to see if a given node has a saved layout.
 * If a layout_type (one_column or two_column) is supplied, it will return the JSON that represents the layout structure for that layout type,
 * as long as the JSON string is set.  Otherwise, we will return the JSON string for the node's chosen layout (i.e. the layout the user picked
 * on the node/[nid]/layout/choose-layout page).
 * @param int $nid Node Id
 * @param string $layout_type A layout type, either one_column or two_column
 *
 * @return JSON string if database record exists.  Or FALSE if record does not exist.
 */
function smg_pop_up_layout_template_query($nid, $layout_type = NULL){

  if ($layout_type) {
    $result = db_query('SELECT layout_json FROM smg_pop_up_layouts_data WHERE entity_id = :nid AND layout_type = :layout_type', array(':nid' => $nid, ':layout_type' => $layout_type))->fetchField();
    if ($result) {
      return $result;
    }
    else {
      return FALSE;
    }
  }

  // If layout_type is not supplied, get the webform's "chosen" layout type
  $chosen_layout = db_query('SELECT layout_in_use FROM smg_pop_up_layouts WHERE entity_id = :nid', array(':nid' => $nid))->fetchField();
  if ($chosen_layout) {
    $result = db_query('SELECT layout_json FROM smg_pop_up_layouts_data WHERE entity_id = :nid AND layout_type = :layout_type', array(':nid' => $nid, ':layout_type' => $chosen_layout))->fetchField();
    if ($result) {
      return $result;
    }
    else {
      return FALSE;
    }
  }
  return FALSE;
}

/**
 * Simply return the chosen layout type (one_column or two_column) for a given webform nid
 *
 * @param int $webform_nid
 *  The nid of the webform
 *
 * @return string
 *  String representing the chosen layout type for the PURF
 */
function smg_pop_up_layout_template_type_query($webform_nid){
  $chosen_layout = db_query('SELECT layout_in_use FROM smg_pop_up_layouts WHERE entity_id = :nid', array(':nid' => $webform_nid))->fetchField();
  if ($chosen_layout) {
    return $chosen_layout;
  }
  else {
    return 'one_column'; // default to one column if user never specified
  }
}

/**
 * This function inserts a row into the smg_pop_up_layouts_data table
 *
 * @param string $nid
 *  The node id of the PURF
 * @param string $layout_type
 *  The chosen layout type to be inserted
 * @param string $json
 *  JSON string representing the layout structure of the PURF
 */
function smg_pop_up_layout_template_insert($nid, $layout_type, $json = ''){

  db_merge('smg_pop_up_layouts_data')
    ->key(array('entity_id' => $nid, 'layout_type' => $layout_type))
    ->fields(array(
      'entity_id' => $nid,
      'layout_type' => $layout_type,
      'layout_saved' => 1,
      'layout_json' => $json,
    ))
    ->execute();
}

/**
 * Convert JSON string to an array that we can use for rendering
 * @param string $json JSON string that represents a layout structure for a registration form.
 * @param int $webform_nid The webform's nid
 *
 * For reference, the decoded JSON string should have the following structure:
 * object(
 *  column1 => array(
 *    row_1 => array(
 *      element_1 => array( id, width )
 *      element_2 => array( id, width )
 *    )
 *    row_2 => array()
 *    ....
 *    row_n => array()
 *  )
 *  column2 => array() // Only two column layout includes this
 * )
 *
 * @return array $layout_array This array contains the following:
 *    - The decoded JSON string that represents the webform's layout
 *    - An array called 'components' which simply lists all of the components for this webform
 *    - A string called 'layout_type' which will either be one_column or two_column
 */
function smg_pop_up_layout_json_decode($json, $webform_nid = NULL){
  $json_decoded = json_decode($json);
  $layout_array = array();

  // Specify which components have been saved in the components array
  $layout_array['components'] = array();

  // Specify the layout type (one_column or two_column).  If webform_nid not supplied, just default to two_column
  $layout_array['layout_type'] = (!is_null($webform_nid)) ? smg_pop_up_layout_template_type_query($webform_nid) : 'two_column';

  // Load the webform node
  $webform = (!is_null($webform_nid)) ? node_load((string)$webform_nid) : false;
  // Get an array of the webforms currently saved components, so that we can remove deleted components
  $webform_components = false;
  if ($webform) {
    $webform_components = array();
    foreach ($webform->webform['components'] as $key => $value) {
      $webform_components[$value['form_key']] = $value['name'];
    }
  }

  // Below, we go through the decoded JSON string, and convert all objects to arrays, for ease of use later on
  if ($json_decoded) {
    if (property_exists($json_decoded, 'column1')) {
      // Create a temp array, add values to it, sort it, then add to to column1
      $c1_rows = array();
      foreach ($json_decoded->column1 as $y_pos => $values) {
        // Each element stored in $values is an object.  We will cast each object as an array and store it in a new
        // array called $array_values
        $array_values = array();
        // iterate through $values so we can save the id of each element into the $layout_array['components'] array, and
        // cast each element as an array and save it to $array_values
        foreach ($values as $value) {
          $layout_array['components'][] = $value->id;
          if ($webform) {
            if (array_key_exists($value->id, $webform_components)) {
              $array_values[] = (array) $value;
            }
          }
        }
        $c1_rows[$y_pos] = $array_values;
      }
      ksort($c1_rows);
      $layout_array['column1'] = $c1_rows;
    }
    if (property_exists($json_decoded, 'column2')) {
      // Create a temp array, add values to it, sort it, then add to to column2
      $c2_rows = array();
      foreach ($json_decoded->column2 as $y_pos => $values) {
        // Each element stored in $values is an object.  We will cast each object as an array and store it in a new
        // array called $array_values
        $array_values = array();
        // iterate through $values so we can save the id of each element into the $layout_array['components'] array, and
        // cast each element as an array and save it to $array_values
        foreach ($values as $value) {
          $layout_array['components'][] = $value->id;
          if ($webform) {
            if (array_key_exists($value->id, $webform_components)) {
              $array_values[] = (array) $value;
            }
          }
        }
        $c2_rows[$y_pos] = $array_values;
      }
      ksort($c2_rows);
      $layout_array['column2'] = $c2_rows;
    }
  }
  return $layout_array;
}

/**
 * Form builder function for the submit button on the Layout Template Drag & Drop pages with standard $form and $form_state variables
 * @param string $layout_type
 *  Extra variable to specify if the form is for the one column or two column template
 * @param object $node
 *  Pass the webform node into the form
 *
 * @return array
 */
function smg_pop_up_layout_form($form, &$form_state, $layout_type, $node){

  $form = array();
  // Add the node to the form
  $form['#node'] = $node;
  $form['layout_reorder']['columns'] = array(
    '#type' => 'hidden',
    '#attributes' => array('id' => 'hidden-columns'),
    '#value' => $layout_type,
  );
  // The following hidden form element will hold the the jQuery reorder results as a JSON encoded string
  $form['layout_reorder']['hidden'] = array('#type' => 'hidden', '#default_value' => NULL, '#attributes' => array('id' => 'hidden-order'));
  // The following is simply generates a div to use as the wrapper for the ajax function
  $form['layout_reorder']['thank_you'] = array(
    '#type' => 'markup',
    '#prefix' => '<div id="reorder-thank-you">',
    '#suffix' => '</div>',
    '#weight' => 20,
  );
  // Pass the node into the $form_state array, to be used later
  $form_state['layout_reorder']['node'] = $node;
  $form['layout_reorder']['submit'] = array(
    '#type' => 'button',
    '#name' => 'template_submit',
    '#value' => 'Generate Layout',
    '#submit' => 'smg_pop_up_layout_reorder_callback',
    '#ajax' => array(
      'callback' => 'smg_pop_up_layout_reorder_callback',
      'wrapper' => 'reorder-thank-you',
      'method' => 'replace',
    ),
    '#limit_validation_errors' => array(),
  );
  return $form;
}

/**
 * Submit handler for the smg_pop_up_layout_form
 */
function smg_pop_up_layout_form_submit($form, &$form_state){

}

/**
 * Callback for the template-layout page's submit button.  This function simply needs to extract the encoded JSON string
 * from the hidden field, and pass the value to the template generating function.
 *
 * @param array $form
 * @param array $form_state
 *
 * @return string
 */
function smg_pop_up_layout_reorder_callback($form, &$form_state) {
  if (isset($form_state['values']['hidden']) && $form_state['values']['hidden']) {
    $nid = $form['#node']->nid;
    $layout_type = $form_state['values']['columns'];
    $json = $form_state['values']['hidden'];
    smg_pop_up_layout_template_insert($nid, $layout_type, $json);
  }
  return '<div id="reorder-thank-you">Thank You.</div>';
}

/**
 * Simple function to convert $layout_type hyphens to underscores
 *
 * @param string $layout_type
 *
 * @return string
 */
function _smg_pop_up_hyphens_to_underscores($layout_type) {
  return str_replace('-','_',$layout_type);
}

/**
 * This function helps with theming.  It takes the node->webform['components'] array and returns an array whose keys are
 * the webform elements' form_key and whose value is an array that contains element's name
 *
 * @param array $components
 *
 * @return array
 */
function _smg_pop_up_components_generate_array($components) {
  $components_array = array();
  foreach ($components as $component) {
    $components_array[$component['form_key']] = array(
      'name' => $component['name'],
    );
  }
  return $components_array;
}

/**
 * @param array $form
 */
function _smg_pop_up_layout_apply_default_layout_to_form(&$form) {
  $nid = $form['#node']->nid;

  $layout_array = _smg_pop_up_layout_get_layout_array($nid);

  // For the $layout_array['column1'] array, every element represents a row in column one.
  // Every row, in turn, contains one or more arrays, each of which represents an actual
  // form element.  Every form-element array contains the 'id' of the form-element, as well
  // as its width as a %.  We go through these elements to extract their widths, then we find
  // the form-element in $form['submitted'], and add the width under a new key called #percentage_width
  foreach ($layout_array['column1'] as $c1_row) {
    foreach ($c1_row as $c1_element) {
      $c1_element_id = $c1_element['id'];
      $form['submitted'][$c1_element_id]['#percent_width'] = $c1_element['width'];
    }
  }

  // If array layout type is two-column, then we repeat the above steps for column2
  if ($layout_array['layout_type'] == 'two_column') {
    foreach ($layout_array['column2'] as $c2_row) {
      foreach ($c2_row as $c2_element) {
        $c2_element_id = $c2_element['id'];
        $form['submitted'][$c2_element_id]['#percent_width'] = $c2_element['width'];
      }
    }
  }
}

/**
 * @param int $nid
 *
 * @return array
 */
function _smg_pop_up_layout_get_layout_array($nid) {
  $layout_array = &drupal_static(__FUNCTION__ . $nid);
  if (!$layout_array) {
    // Now, we need to get the layout structure for this pop-up registration node.  This is saved in the database as
    // a JSON string.  We first get the JSON string, then we decode it and convert to an array
    $layout_json = smg_pop_up_layout_template_query($nid);
    $layout_array = smg_pop_up_layout_json_decode($layout_json, $nid);
  }

  return $layout_array;
}