<?php
/**
 * @file
 *  Handles Leadership admin items
 */

/**
 * The dashboard page that lists all the companies in the current session.
 */
function leadership_dashboard() {
  $rows = array();
  $mapping = leadership_site_mappings(variable_get('smg_global_site'));
  $session_tid = variable_get('leadership_dashboard_session_term');
  $session_term = taxonomy_term_load($session_tid);
  $session_year = $session_term->name;

  $output = '<h1 class="ld-form-title">Companies in ' . $session_year . ' Session</h1>';
  $output .= '<p><a href="/admin/leadership/configure#edit-dashboard">Change dashboard session year.</a></p>';

  $header = array(
    'Company Name',
    'User Page',
    'Print Profile',
    'Data Card',
    'Online Profile',
  );

  $result = _leadership_get_current_company_profiles($mapping, $session_tid);

  while ($record = $result->fetchAssoc()) {
    // Get User info
    $user = user_load($record['user_id']);

    // Print Profile Info
	  $print_profile = node_load($record['print_node_id']);
	  // Only show this if it is approved
	  if ($print_profile->status) {
	    $print_menu = l('XML', 'admin/leadership/xml/' . $record['print_node_id']);
	    if(isset($print_profile->field_ld_print_logo['und'][0]['uri'])) {
	      $print_menu .= ' | ' . l('Logo', file_create_url($print_profile->field_ld_print_logo['und'][0]['uri']));
	    }
	    if(isset($print_profile->{$mapping['field_ld_print_photo1']}['und'][0]['uri'])) {
	      $print_menu .= ' | ' . l('Photo 1', file_create_url($print_profile->{$mapping['field_ld_print_photo1']}['und'][0]['uri']));
      }
      if(isset($print_profile->{$mapping['field_ld_print_photo2']}['und'][0]['uri'])) {
	      $print_menu .= ' | ' . l('Photo 2', file_create_url($print_profile->{$mapping['field_ld_print_photo2']}['und'][0]['uri']));
	    }
	    $print_menu .= ' ';
	  }
	  else {
	    $print_menu = '';
	  }
	  $print_profile_percent = content_complete_get_data($print_profile);

	  // Datacard Profile Info
  	$datacard_profile = node_load($record['datacard_node_id']);
  	$datacard_percent = content_complete_get_data($datacard_profile);

    // Online Profile Info
	  $online_profile = node_load($record['online_node_id']);
	  $online_profile_percent = content_complete_get_data($online_profile);

    $rows[] = array(
      l($record['title'], 'node/' . $record['nid'], array('attributes' => array('target' => '_blank'))),
      l($user->name . ' Profile', 'leaders/user/' . $record['user_id'], array('attributes' => array('target' => '_blank'))) . ' | ' . l('Edit', '/user/' . $record['user_id'] . '/edit', array('attributes' => array('target' => '_blank'))),
      $print_menu .  $print_profile_percent['percent'] . '% Complete - ' . leadership_node_status_string($print_profile->status) .  ' ' . l('Edit', 'node/' . ($record['print_node_id']) . '/edit', array('attributes' => array('target' => '_blank'))),
  	  $datacard_percent['percent'] . '% Complete - ' . leadership_node_status_string($datacard_profile->status) .  ' ' . l('Edit', 'node/' . ($record['datacard_node_id']) . '/edit', array('attributes' => array('target' => '_blank'))) .  ' ' .  l('View', 'node/' . ($record['datacard_node_id']), array('attributes' => array('target' => '_blank'))),
  	  $online_profile_percent['percent'] . '% Complete - ' . leadership_node_status_string($online_profile->status) .  ' ' . l('Edit', 'node/' . ($record['online_node_id']) . '/edit', array('attributes' => array('target' => '_blank'))) .  ' ' . l('View', 'node/' . ($record['online_node_id']), array('attributes' => array('target' => '_blank')))
    );
  }

  $output .= theme('table', array('header' => $header, 'rows' => $rows));

  return $output;
}

/**
 * Lists all the companies and also ability to add a company
 */
function leadership_companies() {
  $rows = array();
  $session_tid = variable_get('leadership_dashboard_session_term');
  $session_term = taxonomy_term_load($session_tid);
  $session_year = $session_term->name;

  $output = '<h1 class="ld-form-title">Add Companies To ' . $session_year . ' Session</h1>';
  $output .= '<p><a href="/admin/leadership/configure#edit-dashboard">Change dashboard session year.</a></p>';
  $output .= drupal_render(drupal_get_form('leadership_admin_company_form'));

  $header = array(
    'Company Name',
    'Remove From Session',
  );

  $companies = leadership_get_all_companies_in_current_session($session_tid);

  foreach ($companies as $company) {
    $rows[] = array(
      $company->title,
      l('Remove From Current Session', 'leaders/' . $company->nid . '/remove/session'),
    );
  }

  $output .= theme('table', array('header' => $header, 'rows' => $rows));

  return $output;
}

/**
 * Form to add a company to leadership
 */
function leadership_admin_company_form() {
  if (variable_get('smg_global_site') == 'aw') {
    $company_field_name = 'field_ld_company';
  }
  else {
    $company_field_name = 'field_companies';
  }

  $form['company'] = array(
    '#type' => 'textfield',
    '#size' => 60,
    '#title' => t('Company'),
    '#autocomplete_path' => "node_reference/autocomplete/user/user/$company_field_name",
    '#required' => TRUE,
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Add Company To Current Session'),
  );

  return $form;
}

/**
 * Submit handler for the admin company form
 */
function leadership_admin_company_form_submit($form, &$form_state) {
  $term_already_set = FALSE;

  // Get the nid fromt the automcomplete text
  preg_match('/.*?\[nid:(\d+)?]/', $form['company']['#value'], $matches);

  if (isset($matches[1])) {
    $node = node_load($matches[1]);
    if (isset($node->field_ld_session['und'])) {
      foreach ($node->field_ld_session['und'] as $terms) {
        if ($terms['tid'] == variable_get('leadership_dashboard_session_term')) {
          $term_already_set = TRUE;
        }
      }
    }

    // If it hasn't been set then set it
    if (!$term_already_set) {
      $node->field_ld_session['und'][] = array('tid' => variable_get('leadership_dashboard_session_term'));
      node_save($node);
      // Create all three nodes
      leadership_create_node($node->nid, $node->title, 'leadership_print_profile');
      leadership_create_node($node->nid, $node->title, 'leadership_online_profile');
      leadership_create_node($node->nid, $node->title, 'leadership_data_card');
    }

    // If PW got to add main categories form
    if (variable_get('smg_global_site') == 'pw') {
      drupal_goto('admin/leadership/add/main-categories/' . $matches[1]);
    }
    else {
      drupal_set_message(t('%company_name have been added. Now add user to the company!', array('%company_name' => $node->title)));
      drupal_goto('admin/leadership/user');
    }
  }
}

/**
 * Callback function to remove the current session taxonomy term from the company
 *
 * @param $nid
 *  the company node id
 *
 * @return
 *  after it saves the node it goes back to the Company Page
 */
function leadership_companies_remove_from_current_session($nid) {

  $node = node_load($nid);

  foreach ($node->field_ld_session['und'] as $key => $terms) {
    if ($terms['tid'] == variable_get('leadership_dashboard_session_term')) {
      unset($node->field_ld_session['und'][$key]);
      node_save($node);
    }
  }

  drupal_goto('admin/leadership/companies');
}

/**
 * Lists all the users that are associated to a company
 */
function leadership_user_config() {
  // Include the CTools tools that we need.
  ctools_include('ajax');
  ctools_include('modal');
  // Add CTools' javascript to the page.
  ctools_modal_add_js();

  $rows = array();

  $output = drupal_render(drupal_get_form('leadership_user_config_form'));
  $output .= drupal_render(drupal_get_form('leadership_user_update_form'));

  $header = array(
    'Username',
    'Email',
    'Company',
    'One-Time Login Link'
  );

  $users = leadership_get_current_users(variable_get('leadership_role_name'));
  if ($users) {
    foreach ($users as $user) {
      $rows[] = array(
        l($user['name'], 'user/' . $user['uid'] . '/edit'),
        $user['email'],
        $user['company'],
        l(t('One-Time Login Link'), 'admin/leadership/user/uli/' . $user['uid'] . '/nojs', array('attributes' => array('class' => array('ctools-use-modal')))),
      );
    }
  }

  $output .= theme('table', array('header' => $header, 'rows' => $rows));

  return $output;
}

/**
 * Function for adding a node and set the the company node reference
 *
 * @param $nid
 *  the node nid
 * @param $title
 *  the node title
 * @param $content_type
 *  the node content type
 */
function leadership_create_node($nid, $title, $content_type) {
  $mapping = leadership_site_mappings(variable_get('smg_global_site'));

  // Check to see if a node exists already
  $query = db_select($mapping['company_field_table'], 'companies')
        ->fields('companies', array('entity_id'))
        ->condition('companies.bundle', $content_type)
        ->condition('companies.' . $mapping['company_field_nid'], $nid);
  $result = $query->execute();

  while ($record = $result->fetchAssoc()) {
	  $nodes[] = $record;
	}

	// Only add a node if there isn't a node for this already
	if (!isset($nodes)) {

	  $node = new StdClass();
	  $node->type = $content_type;
	  $node->status = 0;
	  // Setting the title to the company name by default
	  $node->title = $title;
	  $node->{$mapping['company_field']}['und'][0]['nid'] = $nid;
	  $node->language = 'und';
	  $node->body = '';

	  // Setting these to an empty array to prevent warnings
	  if ($content_type == 'leadership_print_profile') {
	    $node->field_ld_address_1 = array();;
	    $node->field_ld_address_2 = array();
	    $node->field_ld_address_city = array();
	    $node->field_ld_categories_technologies = array();
	    $node->field_ld_categories_topics = array();
	    $node->field_ld_country = array();
	    $node->field_ld_email = array();
	    $node->field_ld_fax = array();
	    $node->field_ld_phone = array();
	    $node->field_ld_print_logo = array();
	    $node->field_ld_print_photo_1 = array();
	    $node->field_ld_print_photo_2 = array();
	    $node->field_ld_state = array();
	    $node->field_ld_website = array();
	    $node->field_ld_zip_postal_code = array();
	  }
	  if ($content_type == 'leadership_online_profile') {
	    $node->field_ld_employees = array();
	    $node->field_ld_facebook = array();
	    $node->field_ld_geo_distrib = array();
	    $node->field_ld_google_plus = array();
	    $node->field_ld_linkedin = array();
	    $node->field_ld_logo = array();
	    $node->field_ld_pinterest = array();
	    $node->field_ld_sales = array();
	    $node->field_ld_services = array();
	    $node->field_ld_training = array();
	    $node->field_ld_twitter = array();
	    $node->field_ld_years = array();
	    $node->field_ld_youtube = array();
	  }
	  node_object_prepare($node);
	  node_save($node);
	}
}

/**
 * Form that handles Adding Users
 */
function leadership_user_config_form() {
  if (variable_get('smg_global_site') == 'aw') {
    $company_field_name = 'field_ld_company';
  }
  else {
    $company_field_name = 'field_companies';
  }

  $form['name'] = array(
    '#type'     => 'textfield',
    '#title'    => t('Username'),
    '#size'     => 60,
    '#required' => TRUE,
  );
  $form['full_name'] = array(
    '#type' => 'textfield',
    '#title' => t('Full Name'),
    '#size' => 60,
    '#required' => TRUE,
  );
  $form['email'] = array(
    '#type' => 'textfield',
    '#title' => t('Email Address'),
    '#size' => 60,
    '#required' => TRUE,
  );
  $form['pass'] = array(
    '#type' => 'textfield',
    '#title' => t('Password'),
    '#size' => 60,
    '#required' => TRUE,
  );
  $form['company'] = array(
    '#type' => 'textfield',
    '#size' => 60,
    '#title' => t('Company'),
    //@TODO - use custom auto complete that only allows current companies
    '#autocomplete_path' => "node_reference/autocomplete/user/user/$company_field_name",
    '#description' => t('Only choose companies from current session'),
    '#required' => TRUE,
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Add User'),
  );

  return $form;
}

/**
 *  Implements hook_form_validate().
 */
function leadership_user_config_form_validate($form, &$form_state) {
  // Validate new username.
  if (isset($form_state['values']['name'])) {
    if ($error = user_validate_name($form_state['values']['name'])) {
      form_set_error('name', $error);
    }
    elseif ((bool) db_select('users')->fields('users', array('uid'))->condition('name', db_like($form_state['values']['name']), 'LIKE')->range(0, 1)->execute()->fetchField()) {
      form_set_error('name', t('The name %name is already taken.', array('%name' => $form_state['values']['name'])));
    }
  }

  // Validate the e-mail address, and check if it is taken by an existing user.
  if ($error = user_validate_mail($form_state['values']['email'])) {
    form_set_error('mail', $error);
  }
  elseif ((bool) db_select('users')->fields('users', array('uid'))->condition('mail', db_like($form_state['values']['email']), 'LIKE')->range(0, 1)->execute()->fetchField()) {
    // Format error message dependent on whether the user is logged in or not.
    if ($GLOBALS['user']->uid) {
      form_set_error('email', t('The e-mail address %email is already taken.', array('%email' => $form_state['values']['email'])));
    }
    else {
      form_set_error('mail', t('The e-mail address %email is already registered. <a href="@password">Have you forgotten your password?</a>', array('%email' => $form_state['values']['mail'], '@password' => url('user/password'))));
    }
  }
}

/**
 * Implements hook_form_submit()
 */
function leadership_user_config_form_submit($form, &$form_state) {
  $mapping = leadership_site_mappings(variable_get('smg_global_site'));

  // Get the nid from the automcomplete text
  preg_match('/.*?\[nid:(\d+)?]/', $form['company']['#value'], $matches);

  $user_roles = user_roles();

  if (isset($matches[1])) {
    $edit = array(
      'name' => $form['name']['#value'],
      'pass' => $form['pass']['#value'],
      'mail' => $form['email']['#value'],
      'status' => 1,
      'language' => 'en',
      'roles' => array(variable_get('leadership_role_name') => $user_roles[variable_get('leadership_role_name')]),
      $mapping['company_field'] => array(
        'und' => array(
          0 => array(
            'nid' => $matches[1]
          ),
        ),
      ),
      'field_full_name' => array(
        'und' => array(
          0 => array(
            'value' => $form['full_name']['#value']
           ),
         ),
       ),
    );

    $user = user_save(FALSE, $edit);

    if (!$user) {
      drupal_set_message(t('Failed to save user!'), 'status');
    }
    else {
      drupal_set_message(t('@user has been added!', array('@user' => $form['name']['#value'])), 'status');

      // Associate the user with the three profiles associated with that company
      $query = db_select('node', 'node')
            ->fields('node', array('nid', 'type', 'title'))
            ->condition('status', '1');
      $query->join($mapping['company_field_table'], 'companies', 'node.nid = companies.' . $mapping['company_field_nid']);
      $query->condition('companies.bundle',  array('leadership_data_card', 'leadership_online_profile', 'leadership_print_profile'),'IN');
      $query->addField('companies', $mapping['company_field_nid']);
      $query->addField('companies', 'bundle');
      $query->addField('companies', 'entity_id');
      $query->condition('companies.' . $mapping['company_field_nid'], $matches[1]);
      $result = $query->execute();

      while ($record = $result->fetchAssoc()) {
        // Update node with the new user
        $node = node_load($record['entity_id']);
        $node->uid = $user->uid;
        node_save($node);
        watchdog('action', 'Changed owner of @type %title to uid %name.', array('@type' => node_type_get_name($node), '%title' => $node->title, '%name' => $user->name));
    	}
    }
  }
  else {
    drupal_set_message(t('Problem with Company!'), 'status');
  }
}

/**
 * Form that handles editing Users
 */
function leadership_user_update_form() {
  $form['name'] = array(
    '#type'     => 'textfield',
    '#title'    => t('Current Username'),
    '#size'     => 60,
    '#required' => TRUE,
    '#autocomplete_path' => 'user/autocomplete',
  );
  $form['new_name'] = array(
    '#type' => 'textfield',
    '#title' => t('New username'),
    '#size' => 60,
    '#required' => FALSE,
  );
  $form['full_name'] = array(
    '#type' => 'textfield',
    '#title' => t('Full Name'),
    '#size' => 60,
    '#required' => TRUE,
  );
  $form['email'] = array(
    '#type' => 'textfield',
    '#title' => t('Email Address'),
    '#size' => 60,
    '#required' => TRUE,
  );
  $form['pass'] = array(
    '#type' => 'textfield',
    '#title' => t('Password'),
    '#size' => 60,
    '#required' => TRUE,
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Update User'),
  );

  return $form;
}

/**
 * Submission handler for Leadership admin user update form
 *
 * Updates an existing user with the specified username, full name,
 * password, and email address.
 */
function leadership_user_update_form_submit($form, &$form_state) {
  $values =& $form_state['values'];

  // Ensure that the user is loaded.
  $account = user_load_by_name($values['name']);
  if ($account === FALSE || !$account->uid) {
    drupal_set_message(t('An error ocurred during user account loading.  Please try again and contact the administrator if the error persists.'), 'error');
    return;
  }

  if (isset($form['new_name']['#value'])
    && !empty($form['new_name']['#value'])
  ) {
    $name = $form['new_name']['#value'];
  }
  else {
    $name = $form['name']['#value'];
  }

  $edit = array(
    'name' => $name,
    'pass' => $form['pass']['#value'],
    'mail' => $form['email']['#value'],
    /*'status' => 1,
    'language' => 'en',
    'roles' => array(variable_get('leadership_role_name') => $user_roles[variable_get('leadership_role_name')]),*/
    'field_full_name' => array(
      'und' => array(
        0 => array(
          'value' => $form['full_name']['#value']
        ),
      ),
    ),
  );

  $result = user_save($account, $edit);

  if ($result === FALSE) {
    drupal_set_message(t('User could not be updated!'));
  }
  else {
    drupal_set_message(t('User has been updated successfully!'));
  }
}

/**
 * Configuration of leadership
 */
function leadership_configure_form() {
  $site_id = variable_get('smg_global_site');

  $vocabs_raw = taxonomy_get_vocabularies();
  foreach ($vocabs_raw as $vid => $vocab) {
    $vocabs[$vid] = check_plain($vocab->name);
  }

  // Get the taxonomy terms for year if Session was selected.
  if (variable_get('leadership_session_vocab')) {
    $taxonomies = taxonomy_get_tree(variable_get('leadership_session_vocab'));
    foreach($taxonomies as $term) {
      $terms[$term->tid] = $term->name;
    }
  }

  // *** Admin User
  $form['admin_user'] = array(
    '#type' => 'fieldset',
    '#title' => t('Admin User'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  $form['admin_user']['leadership_admin_user_name'] = array(
    '#type' => 'textfield',
    '#title' => t('Admin User Full Name'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#default_value' => variable_get('leadership_admin_user_name'),
  );
  $form['admin_user']['leadership_admin_user_email'] = array(
    '#type' => 'textfield',
    '#title' => t('Admin User Email Address'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#default_value' => variable_get('leadership_admin_user_email'),
  );
  // *** Display
  $form['display'] = array(
    '#type' => 'fieldset',
    '#title' => t('Display'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  $form['display']['leadership_block_logo'] = array(
    '#type' => 'textfield',
    '#title' => t('All Companies Block Image'),
    '#description' => t('Path to the Image of the Leadership block for the current session'),
    '#default_value' => variable_get('leadership_block_logo'),
  );
  $form['display']['leadership_block_logo_next'] = array(
    '#type' => 'textfield',
    '#title' => t('Next Session All Companies Block Image '),
    '#description' => t('Path to the Image of the Leadership block for the next session'),
    '#default_value' => variable_get('leadership_block_logo_next'),
  );
  $form['display']['leadership_data_card_company_name_length'] = array(
    '#type' => 'textfield',
    '#title' => t('Datacard Company Name Length (Not Youtube Amplified)'),
    '#description' => t('The max number of characters before the rest gets truncated.'),
    '#size' => 3,
    '#default_value' => variable_get('leadership_data_card_company_name_length'),
  );
  $form['display']['leadership_data_card_company_name_length_youtube_amplified'] = array(
    '#type' => 'textfield',
    '#title' => t('Datacard Company Name Length (Youtube Amplified)'),
    '#size' => 3,
    '#description' => t('The max number of characters before the rest gets truncated.'),
    '#default_value' => variable_get('leadership_data_card_company_name_length_youtube_amplified'),
  );
  $form['display']['leadership_print_example'] = array(
    '#type' => 'textfield',
    '#title' => t('Print Example Image'),
    '#description' => t('Path to the Image of the example profile'),
    '#default_value' => variable_get('leadership_print_example'),
  );
  // *** Dashboard Settings
  $form['dashboard'] = array(
    '#type' => 'fieldset',
    '#title' => t('Dashboard Settings'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  if ($terms) {
    $form['dashboard']['leadership_dashboard_session_term'] = array(
      '#type'           => 'select',
      '#title'          => t('Session Year'),
      '#description'    => t('Choose which year to display in the leadership dashboard.'),
      '#options'        => $terms,
      '#default_value'  => variable_get('leadership_dashboard_session_term'),
    );
  }
  // *** Sessions
  $form['sessions'] = array(
    '#type' => 'fieldset',
    '#title' => t('Sessions'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  $form['sessions']['leadership_session_vocab'] = array(
    '#type' => 'select',
    '#title' => t('Session vocabulary'),
    '#description'    => t('Choose which vocabulary should be used as the Sessions.'),
    '#options'        => $vocabs,
    '#default_value'  => variable_get('leadership_session_vocab'),
  );
  // Only display the taxonomy terms if Session was selected.
  if ($terms) {
    $form['sessions']['leadership_session_term'] = array(
      '#type'           => 'select',
      '#title'          => t('Session Year'),
      '#description'    => t('Choose which year is the current session.'),
      '#options'        => $terms,
      '#default_value'  => variable_get('leadership_session_term'),
    );
  }
  // Only display the taxonomy terms if Session was selected.
  if ($terms) {
    $form['sessions']['leadership_session_term_next'] = array(
      '#type'           => 'select',
      '#title'          => t('Next Session Year'),
      '#description'    => t('Choose which year is the next session.'),
      '#options'        => $terms,
      '#default_value'  => variable_get('leadership_session_term_next'),
    );
  }
  $form['sessions']['leadership_switch_date'] = array(
    '#type'           => 'date',
    '#title'          => t('Session Switch Date'),
    '#description'    => t('Choose the date on which the session should be switched to the next session year.'),
    '#default_value'  => variable_get('leadership_switch_date'),
  );
  $form['sessions']['leadership_print_due_date'] = array(
    '#type' =>'textfield',
    '#title' => t('Date that Leadership Print Profile is Due'),
    '#description' => t('Use this format MM/DD/YYYY EX: 12/30/2014'),
    '#default_value' => variable_get('leadership_print_due_date'),
  );
  $form['sessions']['leadership_datacard_due_date'] = array(
    '#type' =>'textfield',
    '#title' => t('Date that Leadership Data Card Profile is Due'),
    '#description' => t('Use this format MM/DD/YYYY EX: 12/30/2014'),
    '#default_value' => variable_get('leadership_datacard_due_date'),
  );
  $form['sessions']['leadership_online_due_date'] = array(
    '#type' =>'textfield',
    '#title' => t('Date that Leadership Online Profile is Due'),
    '#description' => t('Use this format MM/DD/YYYY EX: 12/30/2014'),
    '#default_value' => variable_get('leadership_online_due_date'),
  );

  if ($site_id == 'pw') {
    $form['admin_categories'] = array(
      '#type'         => 'fieldset',
      '#title'        => t('Admin Categories'),
      '#collapsible'  => TRUE,
      '#collapsed'    => FALSE,
    );
    // Which vocab will admin configure
    $form['admin_categories']['leadership_admin_category_vocab'] = array(
      '#type'           => 'select',
      '#title'          => t('Admin Leadership Category'),
      '#description'    => t('Choose which vocabulary will the leadership admin need to configure. This will be only used by admins.'),
      '#options'        => $vocabs,
      '#default_value'  => variable_get('leadership_admin_category_vocab'),
    );
    if(variable_get('leadership_admin_category_vocab')) {

      $taxonomies = taxonomy_get_tree(variable_get('leadership_admin_category_vocab'));
      foreach($taxonomies as $term) {
        $admin_category_terms[$term->tid] = $term->name;
      }

      $form['admin_categories']['leadership_admin_category_machines'] = array(
        '#type'           => 'select',
        '#title'          => t('Machines Term'),
        '#description'    => t('Choose which term fits the Machines category.'),
        '#options'        => $admin_category_terms,
        '#default_value'  => variable_get('leadership_admin_category_machines'),
      );
      $form['admin_categories']['leadership_admin_category_materials'] = array(
        '#type'           => 'select',
        '#title'          => t('Materials Term'),
        '#description'    => t('Choose which term fits the Materials category.'),
        '#options'        => $admin_category_terms,
        '#default_value'  => variable_get('leadership_admin_category_materials'),
      );
      $form['admin_categories']['leadership_admin_category_services'] = array(
        '#type'           => 'select',
        '#title'          => t('Services Term'),
        '#description'    => t('Choose which term fits the Service category.'),
        '#options'        => $admin_category_terms,
        '#default_value'  => variable_get('leadership_admin_category_services'),
      );
    }
  }

  // Which vocab will user use
  $form['user_categories'] = array(
    '#type'         => 'fieldset',
    '#title'        => t('User Categories'),
    '#collapsible'  => TRUE,
    '#collapsed'    => FALSE,
  );
  $form['user_categories']['leadership_user_category_vocab'] = array(
    '#type'           => 'select',
    '#title'          => t('User Leadership Category'),
    '#description'    => t('Choose which vocabulary will the leadership user use.'),
    '#options'        => $vocabs,
    '#default_value'  => variable_get('leadership_user_category_vocab'),
    '#multiple'       => ($site_id == 'aw' || $site_id == 'ppoem') ? TRUE : FALSE,
  );
  if(variable_get('leadership_user_category_vocab') && $site_id == 'pw') {

    $taxonomies = taxonomy_get_tree(variable_get('leadership_user_category_vocab'));
    foreach($taxonomies as $term) {
      $user_category_terms[$term->tid] = $term->name;
    }

    $form['user_categories']['leadership_user_machinery'] = array(
      '#type'           => 'select',
      '#title'          => t('Machinery Term'),
      '#description'    => t('Choose which term fits the Machines category.'),
      '#options'        => $user_category_terms,
      '#default_value'  => variable_get('leadership_user_machinery'),
    );
    $form['user_categories']['leadership_user_materials'] = array(
      '#type'           => 'select',
      '#title'          => t('Materials Term'),
      '#description'    => t('Choose which term fits the Materials category.'),
      '#options'        => $user_category_terms,
      '#default_value'  => variable_get('leadership_user_materials'),
    );
    $form['user_categories']['leadership_user_service'] = array(
      '#type'           => 'select',
      '#title'          => t('Services Term'),
      '#description'    => t('Choose which term fits the Service category.'),
      '#options'        => $user_category_terms,
      '#default_value'  => variable_get('leadership_user_service'),
    );
  }

  // *** Roles
  $form['roles'] = array(
    '#type' => 'fieldset',
    '#title' => t('Roles'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  $form['roles']['leadership_role_name'] = array(
    '#type' => 'select',
    '#title' => t('User Role'),
    '#description' => t('Choose which Role will the user be.'),
    '#options'        => user_roles(),
    '#default_value'  => variable_get('leadership_role_name'),
  );

  // *** Notifications
  $form['profile_notifications'] = array(
    '#type' => 'fieldset',
    '#title' => t('Profile Notifications'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  $form['profile_notifications']['profile_notifications_state'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable Notifications'),
    '#description' => t('If this setting is enabled, then on the first of the month, the system will look for companies that have an unapproved data-card and/or an unapproved online-profile.  An email notification will be sent to any sales representative that is associated with that company.'),
    '#default_value' => variable_get('profile_notifications_state'),
  );
  $form['profile_notifications']['profile_default_email'] = array(
    '#type' => 'textfield',
    '#title' => t('Default Email'),
    '#description' => t('Please provide an email address to be used in the cases where a company doesn\'t have any associated sales reps.'),
    '#default_value' => variable_get('profile_default_email'),
  );

  // *** Youtube Amplify
  $form['youtube_amplify'] = array(
    '#type' => 'fieldset',
    '#title' => t('Youtube Amplify'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  $form['youtube_amplify']['youtube_amplify_admin_email'] = array(
    '#type' => 'textfield',
    '#title' => t('Youtube Amplify Admin Email'),
    '#description' => t('Please provide an email address to the person that will be configuring videos in PMG Youtube Feed.'),
    '#default_value' => variable_get('youtube_amplify_admin_email'),
  );

  // *** Company Vote link
  $form['company_vote_link'] = array(
    '#type' => 'fieldset',
    '#title' => t('Vote Now Link'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['company_vote_link']['vote_now_link_url'] = array(
    '#type' => 'textfield',
    '#title' => t('Vote now link'),
    '#description' => t('Please provide a link for the Vote Now button on company profiles.'),
    '#default_value' => variable_get('vote_now_link_url'),
  );

  return system_settings_form($form);
}

/**
 * Configuration of leadership notifications
 */
function leadership_notifications_form() {
  // Get the taxonomy terms for year if Session was selected.
  if (variable_get('leadership_session_vocab')) {
    $taxonomies = taxonomy_get_tree(variable_get('leadership_session_vocab'));
    foreach($taxonomies as $term) {
      $terms[$term->tid] = $term->name;
    }
  }

  // Define variables for one-time login notifications.
  $send_one_time_login_notifications_link = l(t('Send notification to all leadership company contacts with one-time login link'), 'admin/leadership/notifications/one-time-send');
  $one_time_notification_message_help_text = '<p>This notification will be sent to all leadership contacts irregardles of session year. The following tokens may be used:</p><ul><li>[user:name]</li><li> [user:field_full_name]</li><li>[user:one-time-login-url]</li><li>[site:name]</li></ul>';
  $one_time_notification_message_default = variable_get('leadership_one_time_login_notification');

  // Define variables for unapproved print profiles notifications.
  $send_unapproved_notifications_link = l(t('Send notification to all leadership company contacts that did not approve their Print Profile'), 'admin/leadership/notifications/unapproved-send');
  $unapproved_notification_message_help_text = '<p>This notification will be sent to the contact of each company in the current session with an unapproved print profile. The following tokens may be used:</p><ul><li>[user:name]</li><li> [user:field_full_name]</li><li>[user:one-time-login-url]</li><li>[site:name]</li><li>[leadership:company]</li></ul>';
  $unapproved_notification_message_default = variable_get('leadership_unapproved_print_profile_notification');

  $form['leadership_otln'] = array(
    '#type' => 'fieldset',
    '#title' => t('One-time Login Notificaton'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  $form['leadership_otln']['leadership_one_time_login_notification'] = array(
    '#type' => 'textarea',
    '#title' => t('One-Time Login Message'),
    '#description' => t($one_time_notification_message_help_text),
    '#default_value' => $one_time_notification_message_default,
  );

  $form['leadership_otln']['leadership_one_time_login_notification_send'] = array(
    '#markup' => $send_one_time_login_notifications_link,
  );

  $form['leadership_uppn'] = array(
    '#type' => 'fieldset',
    '#title' => t('Unapproved Print Profile Notification'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  if ($terms) {
    $form['leadership_uppn']['leadership_notifications_session_term'] = array(
      '#type'           => 'select',
      '#title'          => t('Session Year'),
      '#description'    => t('Choose which year to use for determining companies with unapproved profiles when sending notices. <strong>Make sure to save configuration before sending notifications after changing this.</strong>'),
      '#options'        => $terms,
      '#default_value'  => variable_get('leadership_notifications_session_term'),
    );
  }
  $form['leadership_uppn']['leadership_unapproved_print_profile_notification'] = array(
    '#type' => 'textarea',
    '#title' => t('Unapproved Print Profile Message'),
    '#description' => t($unapproved_notification_message_help_text),
    '#default_value' => $unapproved_notification_message_default,
  );
  $form['leadership_uppn']['leadership_unapproved_print_profile_notification_send'] = array(
    '#markup' => $send_unapproved_notifications_link,
  );

  return system_settings_form($form);
}

/**
 * Sends one-time login notification e-mails to all leadership users.
 */
function leadership_send_one_time_login_notifications() {
  $users = leadership_get_current_users(variable_get('leadership_role_name'));
  $leadership_admin_email = variable_get('leadership_admin_user_email');
  $from = (isset($leadership_admin_email)) ? $leadership_admin_email : variable_get('site_mail');
  $notification = variable_get('leadership_one_time_login_notification');

  foreach ($users as $user) {
    // Reset message to default with tokens.
    if (!empty($notification)) {
      $message = $notification;
      $message = nl2br($notification);
      $message = '<p style="font-size: 12px; font-family: "PT Sans",sans-serif;">' . $message . '</p>';
    }
    else {
      $message = '<p style="font-size: 12px; font-family: "PT Sans",sans-serif;">Hello [user:name],<br />Here is your one-time login link for [site:name]:<br />[user:one-time-login-url]<br />[site:name]</p>';
    }

    // Define variables used for message.
    $user_object = user_load($user['uid']);
    $to = $user['email'];
    $uli = _leadership_user_login_link($user_object);

    // Replace tokens in message.
    $message = str_replace('[user:one-time-login-url]', $uli, $message);
    $message = token_replace($message, array('user' => $user_object), array('language' => $language, 'sanitize' => FALSE, 'clear' => TRUE));
    $params['message'] = $message;

    // Send mail.
    drupal_mail('leadership', 'leadership_one_time_login_notification', $to, language_default(), $params, $from);
  }

  drupal_set_message(t('Notifications have been sent to leadership company contacts with one-time login link.'));
  drupal_goto('admin/leadership/notifications');
}

/**
 * Sends unapproved print profile notification e-mails to contacts of
 * leadership companies with unapproved print profiles.
 */
function leadership_send_unapproved_print_profile_notifications() {
  // Define variables used in message.
  $mapping = leadership_site_mappings(variable_get('smg_global_site'));
  $result = _leadership_get_current_company_profiles($mapping, variable_get('leadership_notifications_session_term'));
  $notification = variable_get('leadership_unapproved_print_profile_notification');
  $leadership_admin_email = variable_get('leadership_admin_user_email');
  $from = (isset($leadership_admin_email)) ? $leadership_admin_email : variable_get('site_mail');

  while ($record = $result->fetchAssoc()) {
    // Get Print Profile Info
	  $print_profile = node_load($record['print_node_id']);

	  // Send notification if print profile is unapproved.
	  if (empty($print_profile->status)) {
      // Get User Info
      $user = user_load($record['user_id']);
      $to = $user->mail;
      $uli = _leadership_user_login_link($user);

      // Reset message to default with tokens.
      if (!empty($notification)) {
        $message = nl2br($notification);
        $message = '<p style="font-size: 12px; font-family: "PT Sans",sans-serif;">' . $message . '</p>';
      }
      else {
        $message = '<p style="font-size: 12px; font-family: "PT Sans",sans-serif;">Hello [user:name],<br />The print profile for [leadership:company] is currently unapproved.<br />[site:name]</p>';
      }

      // Replace tokens in message.
      $message = str_replace('[leadership:company]', $record['title'], $message);
      $message = str_replace('[user:one-time-login-url]', $uli, $message);
      $message = token_replace($message, array('user' => $user), array('language' => $language, 'sanitize' => FALSE, 'clear' => TRUE));
      $params['message'] = $message;

      // Send mail.
      drupal_mail('leadership', 'leadership_unapproved_pp_notification', $to, language_default(), $params, $from);
    }
  }

  drupal_set_message(t('Notifications have been sent to leadership company contacts with unapproved print profiles.'));
  drupal_goto('admin/leadership/notifications');
}

/**
 * Gets all the companies in the current session
 *
 * @param integer $session
 *   The TID of the session for which to get company profiles.
 *
 * @return array
 *  companies in session
 */
function leadership_get_all_companies_in_current_session($session = NULL) {
  // If no session is supplied, use the current session.
  if (empty($session)) {
    $session = variable_get(leadership_session_term);
  }

  // Get all company names in current session
  $query = db_select('node', 'node')
        ->fields('node', array('title', 'nid'))
        ->condition('type', 'company')
        ->condition('status', '1')
        ->orderBy('title', 'asc');
  $query->leftJoin('field_data_field_ld_session', 'session', 'node.nid = session.entity_id');
  $query->condition('session.field_ld_session_tid', $session);
  $query->addField('session', 'field_ld_session_tid');
  $query->distinct();

  return $query->execute()->fetchAll();
}

/**
 * Export a company profile in xml format
 *
 * @param $nid
 *  the node id
 *
 * @return $xml
 *  sends an XML document directly, no HTML output
 */
function leadership_get_xml($nid) {
  $tids = array();
  $terms = array();
  $site_id = variable_get('smg_global_site');
  $mapping = leadership_site_mappings($site_id);

  $profile = node_load($nid);

  if ($site_id == 'aw') {
    // Get Taxonomy tids and names
    if (isset($profile->field_ld_categories_technologies['und'][0])) {
      foreach ($profile->field_ld_categories_technologies['und'] as $value) {
        $tids[] = $value['tid'];
      }
    }
    if (isset($profile->field_ld_categories_topics['und'][0])) {
      foreach ($profile->field_ld_categories_topics['und'] as $value) {
        $tids[] = $value['tid'];
      }
    }

    foreach ($tids as $tid) {
      $terms[] = taxonomy_term_load($tid)->name;
    }

    $Sub_Category = check_plain(implode("\n", $terms));
    $category_tids = implode(', ', $tids);
    $Website = $profile->{$mapping['print_ld_website']}['und'][0]['safe_value'];
  }
  elseif ($site_id === 'ppoem') {
    if (isset($profile->field_ld_categories_control_prod['und'][0])) {
      foreach ($profile->field_ld_categories_control_prod['und'] as $value) {
        $tids[] = $value['tid'];
      }
    }
    if (isset($profile->field_ld_categories_int_equip['und'][0])) {
      foreach ($profile->field_ld_categories_int_equip['und'] as $value) {
        $tids[] = $value['tid'];
      }
    }
    if (isset($profile->field_ld_categories_technologies['und'][0])) {
      foreach ($profile->field_ld_categories_technologies['und'] as $value) {
        $tids[] = $value['tid'];
      }
    }

    foreach ($tids as $tid) {
      $terms[] = taxonomy_term_load($tid)->name;
    }

    $Sub_Category = check_plain(implode("\n", $terms));
    $category_tids = implode(', ', $tids);
    $Website = $profile->{$mapping['print_ld_website']}['und'][0]['url'];
  }
  else {
    // *** Get Category Terms
    foreach($profile->field_ld_categories['und'] as $value) {

      // Get parents of all terms checked (They are uncheckable because I did a display none in css)
      // This will essentially be the main categories
      $parent_term_result = taxonomy_get_parents($value['tid']);
      foreach($parent_term_result as $parent_term_obj) {
        // Making sure there aren't any double. (They checked more than one per category)
        if(!in_array($parent_term_obj->name, $parent_terms)) {
          $parent_terms[] = $parent_term_obj->name;
        }
        if(!in_array($parent_term_obj->tid, $parent_tids)) {
          $parent_tids[] = $parent_term_obj->tid;
        }
      }

      $taxonomy_obj = taxonomy_term_load($value['tid']);
      $terms[] = $taxonomy_obj->name;
      $tids[] = $taxonomy_obj->tid;
    }

    $Category = check_plain(implode("\n", $parent_terms));
    $Category = str_replace('--', '—', $Category);
    $Sub_Category = check_plain(implode("\n", $terms));
    $Sub_Category = str_replace('--', '—', $Sub_Category);
    $category_tids = implode(', ', $tids);
    $Website = $profile->{$mapping['print_ld_website']}['und'][0]['url'];
  }

  $company_nid = $profile->{$mapping['company_field']}['und'][0]['nid'];
  $Company = check_plain($profile->title);
  $Company = str_replace('--', '—', $Company);
  $Address_1 = check_plain($profile->{$mapping['print_ld_address1']}['und'][0]['safe_value']);
  $Address_2 = check_plain($profile->{$mapping['print_ld_address2']}['und'][0]['safe_value']);
  $City = check_plain($profile->{$mapping['print_ld_city']}['und'][0]['safe_value']);
  $State = check_plain($profile->field_ld_state['und'][0]['value']);
  $Postal_Zipcode = check_plain($profile->{$mapping['print_ld_zipcode']}['und'][0]['safe_value']);
  $Country = check_plain($profile->{$mapping['print_ld_country']}['und'][0]['value']);
  // IF USA than just making it blank
  $Country = ($Country == 'United States') ? '' : $Country;
  $Phone = leadership_phone_number_output($profile->{$mapping['print_ld_phone']}['und'][0]['safe_value']);
  $Fax = leadership_phone_number_output($profile->{$mapping['print_ld_fax']}['und'][0]['safe_value']);
  $Email = $profile->{$mapping['print_ld_email']}['und'][0]['safe_value'];
  $Company_Profile = $profile->body['und'][0]['safe_value'];
  $Company_Profile = str_replace('--', '—', $Company_Profile);
  // Replace straight single quote with curly single quote.
  $Company_Profile = preg_replace("/\h+&#039;|&#39;/", " &#8216;", $Company_Profile);
  $Company_Profile = preg_replace("/(&#039;|&#39;)\h+/", "&#8217; ", $Company_Profile);
  $Company_Profile = preg_replace("/(&#039;|&#39;)/", "&#8217;", $Company_Profile);
  // Replace straight double quote with curly double quote.
  $Company_Profile = preg_replace("/\h+&quot;/", " &#8220;", $Company_Profile);
  $Company_Profile = preg_replace("/&quot;\h+/", "&#8221; ", $Company_Profile);
  $Company_Profile = str_replace("&quot;", "&#8221;", $Company_Profile);
  // Replace multiple carriage returns with one.
  $Company_Profile = preg_replace("/\s*\r+/", "", $Company_Profile);
  $Company_Profile = preg_replace("/[\s\r]*$/", "", $Company_Profile);
  $company = node_load($company_nid);
  $Supplier_Link = url('node/' . $company->nid, array('absolute' => TRUE));
  $Supplier_Link = ($pos = strpos($Supplier_Link, '//')) !== FALSE ? substr($Supplier_Link, $pos + 2) : $Supplier_Link;
  $session_tid = variable_get('leadership_dashboard_session_term');

    // Build the actual file string
  $xml = <<<EOF
<?xml version="1.0" encoding="UTF-8" ?>
<Root>
  <Ad>
    <Category>$Sub_Category</Category>
  </Ad>
  <Ad>
    <Company>$Company</Company>
    <Address_1>$Address_1</Address_1>
    <Address_2>$Address_2</Address_2>
    <City>$City</City>
    <State_Province>$State</State_Province>
    <Postal_Zipcode>$Postal_Zipcode</Postal_Zipcode>
    <Country>$Country</Country>
    <Phone>$Phone</Phone>
    <Fax>$Fax</Fax>
    <Email>$Email</Email>
    <Website>$Website</Website>
    <Company_Profile>$Company_Profile</Company_Profile>
    <Company2>$Company</Company2>
    <Supplier_Link>$Supplier_Link</Supplier_Link>

    <profile_nid>$profile->nid</profile_nid>
    <category_tids>$category_tids</category_tids>
    <session_tid>$session_tid</session_tid>
    <company_nid>$company_nid</company_nid>
  </Ad>
</Root>
EOF;

  $file = file_save_data($xml);
  if ($file) {
    file_transfer($file->uri, array('Content-Type' => 'text/xml', 'Content-Disposition' => 'attachment', 'filename' => $Company . '.xml'));
  }
}

/**
 * Function for basically taking the status of a node and returning string Approve or Unapproved
 *
 * @param $status
 *   the status of a node
 *
 * @return $status
 *   the string status of a node. Approved or Unapproved
 */
function leadership_node_status_string($status) {

  if ($status == 0) {
    $status = 'Unapproved';
  }
  if ($status == 1) {
    $status = 'Approved';
  }

  return $status;
}

/**
 * Function for returning the leadership formatted phone number
 */
function leadership_phone_number_output($phone_number) {

	$numbers_only = preg_replace('/[^\d]+/', '', $phone_number);

	$string_length = strlen($numbers_only);

	//Only US/Canada numbers will have this styling
	if($string_length == 10) {

		$areacode = substr($numbers_only, 0, 3);
		$prefix   = substr($numbers_only, 3, 3);
		$number   = substr($numbers_only, 6, 4);

		$phone_number = $areacode . '/' . $prefix  . '-' . $number;

	}
	if($string_length == 11 && substr($numbers_only, 0, 1) == 1) {

	  $areacode = substr($numbers_only, 1, 3);
		$prefix   = substr($numbers_only, 4, 3);
		$number   = substr($numbers_only, 7, 4);

	  $phone_number = $areacode . '/' . $prefix  . '-' . $number;

	}

	return $phone_number;
}

/**
 * Function for getting the current user with a certain role
 *
 * @param $role
 *  the role id
 *
 * @return $users
 *  array of user data
 *  - name - the users name
 *  - email - the users email
 *  - company - the company name that the user is associated with
 *  - uid - the user id
 */
function leadership_get_current_users($role = FALSE) {
  $mapping = leadership_site_mappings(variable_get('smg_global_site'));
  $users = array();

  // Get all the users with administer_leadership
  $query = db_select('users', 'user')
    ->fields('user', array('mail', 'name', 'uid'))
    ->condition('status', 1);
  $query->leftJoin($mapping['company_field_table'], 'company', 'user.uid = company.entity_id');
  $query->addField('company', $mapping['company_field_nid']);
  $query->condition('company.bundle', 'user');
  $query->leftJoin('users_roles ', 'role', 'role.uid = user.uid');
  if ($role) {
    $query->condition('role.rid', $role);
  }

  $result = $query->execute();

  while ($record = $result->fetchAssoc()) {
    $user['name'] = $record['name'];
	  $user['email'] = $record['mail'];
	  $user['company'] = node_load($record[$mapping['company_field_nid']])->title;
	  $user['uid'] = $record['uid'];
	  $users[] = $user;
	}

  return $users;
}

/**
 * Menu callback for admin/leadership/user/uli/%user/%ctools_js.
 * Displays generated one-time user login link in a popup.
 *
 * @param object $user
 *   The user object.
 */
function leadership_user_login_link_popup($user, $js = NULL) {
  $uli = _leadership_user_login_link($user);
  $popup_content = t('<p>One-time login link for @username.</p>', array('@username' => format_username($user)));
  $popup_content .=  '<p>' . $uli . '</p>';

  // Checking JavaScript is enabled.
  if (!$js) {
    // If JavaScript is disabled, add return link and output
    // content without the popup.
    $popup_content .= '<p>' . l(t('Return'), 'admin/leadership/user');
    return $popup_content;
  }

  // If everything is ok and JavaScript is enabled, add the necessary
  // libraries and JS to work with modal windows.
  ctools_include('modal');
  ctools_include('ajax');
  ctools_modal_add_js();

  // Forming a modal window.
  return (ctools_modal_render('User Login Link', $popup_content));
}

/**
 * Helper function to generate one-time log in link for user.
 *
 * @param object $user
 *   The user object.
 *
 * @return string $uli
 *   The one-time user login link.
 */
function _leadership_user_login_link($user) {
  $options['query']['destination'] = 'leaders/user/' . $user->uid;
  $uli = url(user_pass_reset_url($user) . '/login', $options);
  return ($uli);
}

/**
 * Render the form to add categories to one company.
 *
 * @param integer $company_nid
 *   The Company node id.
 * @return string
 *   Rendered form.
 */
function leadership_add_categories_to_one_company($company_nid) {
  return drupal_render(drupal_get_form('leadership_add_categories_to_one_company_form', $company_nid));
}

/**
 * Form to add a main categories to the company.
 *
 * @param object $form
 *   the form object.
 * @param object $form_state
 *   the from state object.
 * @param integer $company_nid
 *   The node id of the company.
 */
function leadership_add_categories_to_one_company_form($form, &$form_state, $company_nid) {
  $taxonomies = taxonomy_get_tree(variable_get('leadership_admin_category_vocab'));
  $node = node_load($company_nid);

  foreach($taxonomies as $term) {
    $admin_category_terms[$term->tid] = $term->name;
  }

  // Get default categories.
  $default_categories = array();
  if ($node->field_ld_main_categories['und']) {
    foreach ($node->field_ld_main_categories['und'] as $term) {
      $default_categories[] = $term['tid'];
    }
  }

  $form['categories'] = array(
    '#type'           => 'checkboxes',
    '#title'          => t('Main Leadership Categories'),
    '#description'    => t('Choose which categories this company belongs to. You can do it later but please make sure it must be set before the customer starts filling out the form.'),
    '#options'        => $admin_category_terms,
    '#multiple'       => TRUE,
    '#default_value'  => $default_categories,
  );
  $form['nid'] = array(
    '#type' => 'hidden',
    '#default_value' => $company_nid,
  );
  $form['submit'] = array(
    '#type'   => 'submit',
    '#value'  => t('Submit'),
  );

  return $form;
}

/**
 * Leadership one company categories submit handler.
 *
 * @param object $form
 *   the form object.
 * @param object $form_state
 *   the from state object.
 */
function leadership_add_categories_to_one_company_form_submit($form, &$form_state) {
  if ($form_state['values']['nid']) {
    $node = node_load($form_state['values']['nid']);
    // Just in case there are some terms already set.
    if (isset($node->field_ld_main_categories['und'])) {
      unset($node->field_ld_main_categories['und']);
    }
    // Add taxonomy terms.
    foreach ($form_state['values']['categories'] as $tid) {
      if ($tid) {
        $node->field_ld_main_categories['und'][] = array('tid' => $tid);
      }
    }

    node_save($node);
    drupal_set_message(t('Cagetories for %company_name have been added. Now add user to the company!', array('%company_name' => $node->title)));
    drupal_goto('admin/leadership/user');
  }
}

/**
 * Function that return the form for adding companies to one of the main
 * categories.
 *
 * @param integer $category
 *   The taxonomy term id of the main leadership category.
 */
function leadership_all_companies_category_form($form, &$form_state, $category) {
  // Get all company names in current session
  $query = db_select('node', 'node')
        ->fields('node', array('title', 'nid'))
        ->condition('type', 'company')
        ->condition('status', '1')
        ->orderBy('title', 'asc');
  $query->leftJoin('field_data_field_ld_session', 'session', 'node.nid = session.entity_id');
  $query->condition('session.field_ld_session_tid', variable_get('leadership_dashboard_session_term'));
  $query->addField('session', 'field_ld_session_tid');
  $query->leftJoin('field_data_field_ld_main_categories', 'main_categories', 'main_categories.entity_id = node.nid');
  $query->addField('main_categories', 'field_ld_main_categories_tid');
  $query->addField('main_categories', 'entity_id');
  $query->distinct();
  $result = $query->execute();

  while ($record = $result->fetchAssoc()) {
    $company_options[$record['nid']] = array(
      'company_name' => l($record['title'], '/node/' . $record['nid'], array('attributes' => array('target' => '_blank'))),
    );

    // Check to make there aren't any companies already set to this year.
    // Default check these companies
    if ($record['field_ld_main_categories_tid'] == $category) {
      $default_checked[$record['nid']] = 1;
    }
  }

  $header = array(
   'company_name' => t('Company Name'),
  );

  $form['companies'] = array(
    '#type' => 'tableselect',
    '#header' => $header,
    '#options' => $company_options,
    '#js_select' => FALSE,
    '#default_value' => $default_checked,
  );
  $form['category_id'] = array(
    '#type' => 'hidden',
    '#default_value' => $category,
  );

  $form['submit'] = array(
    '#type'   => 'submit',
    '#value'  => t('Submit'),
  );

  return $form;
}

/**
 * Submition handler for the leadership_all_companies_category_form.
 */
function leadership_all_companies_category_form_submit($form, &$form_state) {
  $category_tid = $form_state['values']['category_id'];
  foreach ($form_state['values']['companies'] as $key => $value) {
    $term_already_set = FALSE;
    $node = node_load($key);

    // Going through all checked values. If checked and not already saved then
    // resave node. If already saved than do not save node.
    if ($value) {
      // Check to see if the term is set
      if (!isset($node->field_ld_main_categories['und'])) {
        foreach ($node->field_ld_main_categories['und'] as $terms) {
          if ($terms['tid'] == $category_tid) {
            $term_already_set = TRUE;
          }
        }
      }

      // If it hasn't been set than set it.
      if (!$term_already_set) {
        $node->field_ld_main_categories['und'][] = array('tid' => $category_tid);
        node_save($node);
      }
    }

    // Going through all the not checked values. Just in case the user unchecked
    //  a company.
    if (!$value && isset($node->field_ld_main_categories['und'])) {
      foreach ($node->field_ld_main_categories['und'] as $key => $terms) {
        if ($terms['tid'] == $category_tid) {
          unset($node->field_ld_main_categories['und'][$key]);
          node_save($node);
        }
      }
    }
  }

  drupal_set_message(t('Category has been updated'));
  drupal_goto('admin/leadership');
}
