<?php

/**
 * Implements hook_drush_command().
 */
function smg_global_drush_command() {
  $items['smg-global-360-add-fields'] = array(
    'description' => 'Add new fields to 360 content type',
  );

  $items['smg-global-remove-webform-component'] = array(
    'description' => 'Specify a webform component to be deleted from ALL WEBFORMS on the site.  Use the form_key parameter.',
    'arguments' => array(
      'component' => 'The webform component',
    ),
  );

  $items['smg-global-cad-dashboard'] = array(
    'description' => dt('Generate a contributor analytics report for a 14 month period.'),
    'examples' => array(
      'Standard example' => 'drush smg-cad',
    ),
    'aliases' => array('smg-cad'),
  );

  $items['smg-global-staff-normalizer'] = array(
    'description' => dt('Normalize the staff editor names.'),
    'examples' => array(
      'Standard example' => 'drush smg-norm',
    ),
    'arguments' => array(
      'csvfile' => 'CSV file with name variants, with each line representing a different individual. Entry one on each line is their preferred name',
    ),
    'aliases' => array('smg-norm'),
  );

  $items['smg-global-viddler-csv'] = array(
    'description' => dt('Create a csv file of entities that have viddler ids'),
    'example' => array(
      'Standard example' => 'drush smg-global-viddler-csv',
    ),
  );

  $items['smg-global-waywire-import'] = array(
    'description' => dt('Imports waywire videos via csv file located in the: /sites/default/files folder'),
    'example' => array(
      'Standard example' => 'drush smg-cwi drush_waywire_import.csv',
    ),
    'arguments' => array(
      'csvfile' => 'CSV file name containing the following columns: entity_id and waywire_id',
    ),
    'aliases' => array('smg-cwi'),
  );

  return $items;
}

/**
 * Runs through the site database (pw/aw) and normalizes editor names, based on
 * the contents of a file supplied at the command line.
 *
 * File format, per line: [Preferred title]Preferred name**Name Variant 1**...
 * NOTE: Run 'drush cc all' after successful completion of this command.
 */
function drush_smg_global_staff_normalizer($csvfile = NULL) {
  if(variable_get('smg_global_site') == 'hcp') { // terminate the run if the site is HCP
    echo 'Unfortunately, this tool is not designed for use on Healthcare Packaging.';
    return;
  }

  if ($csvfile == NULL) { // verify that a filename has been provided.
    echo "Please provide a csv file name and path as an argument. \n";
    return;
  }

  $namebase = array() ; // this array will hold the contents of the passed csv file
  $csv_file = fopen(dirname(__FILE__) . '/' . $csvfile, r) or die('error opening csv file. please check the file name and path and try again.');

  // $editor = array('Alex Telischak', 'A1ex Telischak', 'AAlex Telischak');
  // $editor_title = 'Boom Boom';
  while (($csv_line = fgets($csv_file)) != FALSE) { // loop through each line of the passed csv
    $title_string_end = stripos($csv_line, ']'); // get where the title string ends. (closing ])
    $editor_title = substr($csv_line, 1, $title_string_end - 1); // extract the title to a separate string
    $csv_line = substr($csv_line, $title_string_end + 1, -1); // parse and remerge the read line to pull just names
    $editor = array_map('trim', explode('**', $csv_line)); // 0 position should _always_ been the 'preferred' name
    echo "..." . $editor[0] . ", " . $editor_title;
    $namebase[] = $editor;  // add this entry into the master base
    echo "...added to hash with " . count($editor). " variant(s). \n";
    $sql_update_master = "UPDATE field_data_field_byline as byline_table
                          RIGHT JOIN field_data_field_author_title AS title_table
                          ON byline_table.entity_id = title_table.entity_id
                          SET byline_table.field_byline_value = :name1,
                              byline_table.field_byline_format = :format,
                              title_table.field_author_title_value = :title1,
                              title_table.field_author_title_format = :format
                          WHERE byline_table.field_byline_value IN (:names)";
    $sql_update_master_args = array(':name1' => $editor[0],
                                    ':title1' => $editor_title,
                                    ':names' => $editor,
                                    ':format' => 'plain_text',
                                    );
try {
    db_query($sql_update_master, $sql_update_master_args);
 } catch (Exception $e) {
  echo 'Error:';
  echo $e;
 }
  }
}

/**
 * Calls the smg_global_cad function to generate an HTML email for review
 */
function drush_smg_global_cad_dashboard() { //
  $site_url = ''; // Used in the email body to link to live version of report on site
  $site_full_name = ''; // Used in subject/body to report full site name to reader

  switch(variable_get('smg_global_site')){
  case 'pw':
    $site_url = 'http://www.packworld.com/admin/reports/cad';
    $site_full_name = 'Packworld';
    $site_from = 'no-reply@packworld.com';
    break;
  case 'hcp':
    $site_url = 'http://www.healthcarepackaging.com/admin/reports/cad';
    $site_full_name = 'Healthcare Packaging';
    $site_from = 'no-reply@healthcarepackaging.com';
    break;
  case 'aw':
    $site_url = 'http://www.automationworld.com/admin/reports/cad';
    $site_full_name = 'Automation World';
    $site_from = 'no-reply@automationworld.com';
    break;
  case 'aw':
    $site_url = 'http://www.ppoem.com/admin/reports/cad';
    $site_full_name = 'P + P OEM';
    $site_from = 'no-reply@ppoem.com';
    break;
  };

  $this_year = date('Y');
  $output = smg_global_cad_dashboard($this_year);
  $module =  'htmlmail';   // module name (see ticket notes)
  $key = 'smg_cad_report';  // will look for htmlmail template with this key
  $language = language_default(); // same language as the user
  $params = array(); // empty
  $from = $site_from; // from system mailer
  $email = variable_get('smg_global_cad_dashboard'); // recipient(s)
  $send = TRUE; // send immediately?
  $fancy_date = date('l, F jS, Y'); // Full day, Full Month, Digit day(th/rd/st), Full Year
  $message = drupal_mail($module, $key, $email, $language, $params, $from, FALSE); // build the message, but don't send it yet.
  $subject = $site_full_name . ' Contributor Analytics'; // subject line

  $message['subject'] = $subject; // insert subject into message object
  $message['body'] = array(); // build body array
  $message['body'][0] = '<body style="font-family:Helvetica, sans-serif; font-size:14px; max-width:1000px;width:1000px;margin:0 auto; display:block;"><br /><div>Hello, </div>';
  $message['body'][1] = '<div>Here is the ' . $site_full_name . ' Contributor Analyis Report of original content for ' . $this_year . ' as of ' . $fancy_date . '. <a href="' . $site_url . '">View a live version of this report.</a></div>';
  $message['body'][2] = '<center><div style="height:1px;width:100%;background-color:#696969;"></div>';
    // add some basic inline css to clean things up.
    $output = str_replace('"even"', '"even" style="background-color:#eee;"',$output);
    $output = str_replace('"sticky-enabled"', '"sticky-enabled" style="font-family:Helvetica, sans-serif; font-size:14px;"',$output);
    $output = str_replace('<td>', '<td style="padding:4px;">', $output);
  $message['body'][3] = $output;
  $message['body'][4] = '<div style="height:1px;width:100%;background-color:#696969;"></div></center>';
  $message['body'][5] = '<div style="float:left;width:50%;">INTERNAL CONFIDENTIAL INFORMATION</div><div style="text-align:right;float:left;width:50%;">PMMI Media Group 330 N Wabash Chicago IL 60611</div>';
  $message['body'][6] = '</body>';
  $message['headers'] = array( // adjust the headers to make HTML email workable
    'From' => $from,
    'Sender' => $from,
    'Return-Path' => $from,
    'MIME-Version' => '1.0',
    'Content-Type' => 'text/html; charset=UTF-8; format=flowed',
    'Content-Transfer-Encoding' => '8Bit',
    'X-Mailer' => 'Drupal'
  );

  // Retrieve the responsible implementation for this message.
  $system = drupal_mail_system($module, $key);

  // Format the message body.
  $message = $system->format($message);

  // Send e-mail.
  $message['result'] = $system->mail($message);
}

/**
 * Add extra fields to the 360_package_spin_rotate content type
 *
 * NOTE: this function expects that the multiupload_filefield_widget is installed
 * and enabled
 */
function drush_smg_global_360_add_fields(){

  // Create the file multi upload field
  if(!field_info_field('field_360_multi_upload')){
    $multi_field = array(
      'field_name' => 'field_360_multi_upload',
      'type' => 'file',
      'cardinality' => '-1',
    );
    field_create_field($multi_field);
  }
  if(!field_info_instance('node', 'field_360_multi_upload', '360_package_spin_rotate')){
    $multi_instance = array(
      'field_name' => 'field_360_multi_upload',
      'entity_type' => 'node',
      'label' => 'Upload Images for 360 Gallery',
      'bundle' => '360_package_spin_rotate',
      'settings' => array(
        'user_register_form' => 0,
      ),
      'widget' => array(
        'type' => 'file_mfw',
        'module' => 'multiupload_filefield_widget',
        'settings' => array(
          'progress_indicator' => 'throbber'
        ),
      ),
      'settings' => array(
        'file_directory' => '360_gallery',
        'file_extensions' => 'txt jpg png gif jpeg'
      ),
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'type' => 'hidden'
        ),
        'teaser' => array(
          'label' => 'hidden',
          'type' => 'hidden',
        ),
      ),
      'description' => 'Please upload all of the <strong>LARGE IMAGES</strong> that were provided for this 360.  This is a multi-upload field, so select ALL of the files at once',
    );
    field_create_instance($multi_instance);
  }

  // Has the field_360_images field collection been created, if not create it
  if(!field_info_field('field_360_images')){
    $images_field = array(
      'field_name' => 'field_360_images',
      'type' => 'field_collection',
      'cardinality' => '-1',
    );
    field_create_field($images_field);
  }
  if(!field_info_instance('node', 'field_360_images', '360_package_spin_rotate')){
    $images_instance = array(
      'field_name' => 'field_360_images',
      'entity_type' => 'node',
      'label' => '360 Images',
      'bundle' => '360_package_spin_rotate',
      'settings' => array(
        'user_register_form' => 0,
      ),
      'widget' => array(
        'type' => 'field_collection_embed'
      ),
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'type' => 'hidden',
        ),
      ),
    );
    field_create_instance($images_instance);
  }

  if(!(field_info_field('field_360_fc_large'))){
    $fc_large_field = array(
      'field_name' => 'field_360_fc_large',
      'type' => 'image'
    );
    field_create_field($fc_large_field);
  }
  if(!field_info_instance('field_collection_item', 'field_360_fc_large', 'field_360_images')){
    $fc_large_instance = array(
      'field_name' => 'field_360_fc_large',
      'entity_type' => 'field_collection_item',
      'label' => 'Large Image',
      'settings' => array(
        'user_register_form' => 0,
        'file_extensions' => 'png gif jpg jpeg',
      ),
      'widget' => array(
        'type' => 'image_image',
      ),
      'bundle' => 'field_360_images',
    );
    field_create_instance($fc_large_instance);
  }

  if(!(field_info_field('field_360_fc_small'))){
    $fc_small_field = array(
      'field_name' => 'field_360_fc_small',
      'type' => 'image'
    );
    field_create_field($fc_small_field);
  }
  if(!field_info_instance('field_collection_item', 'field_360_fc_small', 'field_360_images')){
    $fc_small_instance = array(
      'field_name' => 'field_360_fc_small',
      'entity_type' => 'field_collection_item',
      'label' => 'Small Image',
      'settings' => array(
        'user_register_form' => 0,
        'file_extensions' => 'png gif jpg jpeg',
      ),
      'widget' => array(
        'type' => 'image_image',
      ),
      'bundle' => 'field_360_images',
    );
    field_create_instance($fc_small_instance);
  }

  if(!(field_info_field('field_360_fc_nav'))){
    $fc_nav_field = array(
      'field_name' => 'field_360_fc_nav',
      'type' => 'image'
    );
    field_create_field($fc_nav_field);
  }
  if(!field_info_instance('field_collection_item', 'field_360_fc_nav', 'field_360_images')){
    $fc_nav_instance = array(
      'field_name' => 'field_360_fc_nav',
      'entity_type' => 'field_collection_item',
      'label' => 'Navigator Image',
      'settings' => array(
        'user_register_form' => 0,
        'file_extensions' => 'png gif jpg jpeg',
      ),
      'widget' => array(
        'type' => 'image_image',
      ),
      'bundle' => 'field_360_images',
    );
    field_create_instance($fc_nav_instance);
  }

  if(!field_info_field('field_360_fc_x')){
    $fc_x_field = array(
      'field_name' => 'field_360_fc_x',
      'type' => 'text',
    );
    field_create_field($fc_x_field);
  }
  if(!field_info_instance('field_collection_item', 'field_360_fc_x', 'field_360_images')){
    $fc_x_instance = array(
      'field_name' => 'field_360_fc_x',
      'entity_type' => 'field_collection_item',
      'label' => 'X Coordinate',
      'settings' => array(
        'user_register_form' => 0,
      ),
      'bundle' => 'field_360_images',
      'widget' => array(
        'type' => 'textfield',
      ),
    );
    field_create_instance($fc_x_instance);
  }

  if(!field_info_field('field_360_fc_y')){
    $fc_y_field = array(
      'field_name' => 'field_360_fc_y',
      'type' => 'text',
    );
    field_create_field($fc_y_field);
  }
  if(!field_info_instance('field_collection_item', 'field_360_fc_y', 'field_360_images')){
    $fc_y_instance = array(
      'field_name' => 'field_360_fc_y',
      'entity_type' => 'field_collection_item',
      'label' => 'Y Coordinate',
      'settings' => array(
        'user_register_form' => 0,
      ),
      'bundle' => 'field_360_images',
      'widget' => array(
        'type' => 'textfield',
      ),
    );
    field_create_instance($fc_y_instance);
  }
}

/**
 * Removes one or more webform components
 */
function drush_smg_global_remove_webform_component() {
  $args = func_get_args(); // Get arguments

  // Get all webform nodes
  $webform_types = webform_variable_get('webform_node_types');
  $results = array();
  if ($webform_types) {
    $results = db_select('node', 'n')
      ->fields('n')
      ->condition('n.type', $webform_types, 'IN')
      ->execute()
      ->fetchAllAssoc('nid');
  }
  $nids = array_keys($results);
  $nodes = node_load_multiple($nids);

  // Go through each node and look for the supplied components arg(s)
  foreach ($nodes as $node) {
    $found_component = FALSE;
    foreach ($node->webform['components'] as $key => $component) {
      if (in_array($component['form_key'], $args)) {
        $found_component = TRUE;
        unset($node->webform['components'][$key]);
        drush_log(dt('Removed component ' . $component['form_key'] . ' from ' . $node->title), 'ok');
      }
    }
    if ($found_component)
      node_save($node);
  }
}

/**
 * Creates a csv file containing the bundle (node type), entity id (node id) and
 * viddler id and stores the output file in
 *  sites/default/files/drush_viddler.csv.
 */
function drush_smg_global_viddler_csv() {
  $site_id = variable_get('smg_global_site');

  // Set a string name of the source type that will be used in Waywire.
  $source_types = array(
    // PW & HCP
    162 => 'smg_original_content',
    163 => 'smg_supplier_submitted',
    165 => 'smg_lead_gen_campaign',
    164 => 'smg_custom_content',
    // AW
    138 => 'smg_original_content',
    140 => 'smg_supplier_submitted',
    141 => 'smg_lead_gen_campaign',
    139 => 'smg_custom_content',
  );

  // All the viddler ids are stored in table: field_data_field_viddler_id.
  $result = db_select('field_data_field_viddler_id', 'f')
    ->fields('f', array('bundle', 'entity_id', 'field_viddler_id_value'))
    ->condition('f.field_viddler_id_value', 'temp', '<>')
    ->execute();

  $filePath = realpath(drush_get_context('DRUSH_OLDCWD', getcwd())) . '/sites/default/files/drush_viddler.csv';
  $file = fopen($filePath, 'w');

  // Header of the first line.
  fputcsv($file, array('title', 'bundle', 'entity_id', 'viddler_id', 'tags'));

  while ($record = $result->fetchAssoc()) {
    $tags = array();
    $node = node_load($record['entity_id']);

    // Add source type tags.
    if (isset($node->field_term_source_type['und'][0]['tid'])) {
      $tags[] = $source_types[$node->field_term_source_type['und'][0]['tid']];
    }
    // Add a brand tag.
    $tags[] = "smg_brand_" . $site_id;

    $tag = implode(";", $tags);
    $record[] = $tag;

    // Add title to the beginning of the array.
    array_unshift($record, $node->title);

    fputcsv($file, $record);
  }
}

/**
 * Goes through csv file and saves waire wire id associeded to the node
 * (entity_id).
 *
 * @param string $csv_file
 *   The file name of the csv file. The csv file must be comma seperated and
 *   located in /sites/default/files.
 */
function drush_smg_global_waywire_import($csvfile = 'drush_waywire_import.csv') {
  // Open file.
  $filePath = realpath(drush_get_context('DRUSH_OLDCWD', getcwd())) . '/' . $csvfile;
  $file = fopen($filePath, 'r');

  // Headers of csv file.
  $headers = fgetcsv($file, 4096, ',');

  // Go through rows of csv file.
  while ($column = fgetcsv($file, 4096, ',')) {
    // Get associative array by combining the headers with the column.
    $column = array_combine($headers, $column);

    $node = node_load($column['entity_id']);

    // Set the waywire id
    $node->field_waywire_video['und'][0]['video_id'] = $column['waywire_id'];

    node_save($node);

    // If it failed during a node save it won't give back a nid in the node
    // object.
    if ($node->nid != $column['entity_id']) {
      echo "Error: Failed to save {$column['entity_id']}\n";
    }
    else {
      echo "Updated {$column['entity_id']} successfully\n";
    }
  }
}
