<?php

/**
 * @file external_submit.inc
 * author: Josh Salisbury
 * Functions for posting user-submitted data to AccelaWorks and Silverpop
 */

require_once(drupal_get_path('module', 'playbook_fields') . '/includes/silverpop_soap_client.inc');
require_once(drupal_get_path('module', 'playbook_fields') . '/includes/gotowebinars_client.inc');

/**
 * Helper function to concatenate all values with the same destination field
 * Returns all same-destination values concatened with " | "
 */
function playbook_fields_concatenate($fields_by_id) {
  $return = [];

  foreach ($fields_by_id as $id => $components) {
    switch (count($components)) {
      case 0:
        break;
      case 1:
        $return[$id] = $components[0]['value'];
        break;
      default:
        $v = [];
        foreach ($components as $component) {
          if (trim($component['value']) != '' && trim($component['value']) != 'Not applicable' && trim($component['value']) != 'Not provided') {
            if(isset($component['prepend']) && $component['prepend']) {
              $v[] = $component['name'] . ': ' . $component['value'];
            }
            else {
              $v[] = $component['value'];
            }
          }
        }
        $return[$id] = implode($v, ' | ');
        break;
    }
  }

  return $return;
}

/**
 * Report submitted data to AccelaWorks
 */
function _webform_smg_accela_post($fields, $sponsor_ids, $master_campaign_id, $billcode) {
  // Organize submitted values by Accela destination field
  $contact = [];
  foreach ($fields as $field) {
    if (isset($field['accela_id']) && trim($field['accela_id'])) {
      switch ($field['name']) {
        case 'Opt-in':
          $na_value = 'No';
          break;
        default:
          $na_value = '';
          break;
      }
      $contact[trim($field['accela_id'])][] = [
        'name' => $field['name'],
        'type' => $field['type'],
        'value' => empty($field['values'][0]) ? $na_value : $field['values'][0],
      ];
    } elseif ($field['type'] == 'smg_select' && $field['multiple'] == TRUE) {
      // Each option in a multi-select has its own Accela id, which populates as 'T' if selected, 'F' otherwise
      foreach ($field['option_accela_ids'] as $key => $option_accela_id) {
        if (isset($field['slugs'][$key]) && in_array($field['slugs'][$key], $field['values'])) {
          $value = 'T';
        } elseif (in_array($field['keys'][$key], $field['values'])) {
          $value = 'T';
        } else {
          $value = 'F';
        }

        $contact[trim($option_accela_id)] = [
          [
            'name' => $field['name'],
            'type' => $field['type'],
            'value' => ($contact[trim($option_accela_id)][0]['value'] == 'T' || $value == 'T') ? 'T' : 'F', //the "OR" operation here lets multiple form components have the same per-option ids. If any of them is true, we pass T to Accela
          ],
        ];
      }
    } elseif ($field['type'] == 'smg_grid') {
      foreach ($field['option_accela_ids'] as $q => $id) {
        $contact[trim($id)][] = [
          'name' => $field['name'],
          'type' => $field['type'],
          'value' => $field['values'][$q],
        ];
      }
    }
  }

  // Prepare Accela-ready array
  $accela_fields = playbook_fields_concatenate($contact);

  if (!$accela_fields) {
    return FALSE;
  }

  if (isset($accela_fields['Country'])) {
    if (stripos(strtoupper($accela_fields['Country']), 'UNITED STATES') !== FALSE) {
      // Accela expects to see "United States of America"
      $accela_fields['Country'] = 'United States of America';
    } else {
      $accela_fields['Country'] = ucwords(strtolower($accela_fields['Country']));
    }
  }

  // Begin building the url to post to AccelaWorks
  // This URL and account-level data is identical for every call to Accela
  $base_url = 'http://reg.accelacomm.com/servlet/Frs.frs?Context=LOGENTRY&Source_BC=' . $billcode;
  // We want the Source to be up front
  if (isset($accela_fields['Source'])) {
    $base_url .= '&Source=' . rawurlencode(trim($accela_fields['Source']));
    unset($accela_fields['Source']);
  }

  // Build out the cURL-ready questions string
  $url_questions = '';
  foreach ($accela_fields as $field => $value) {
    if (trim($value)) {
      $url_questions .= '&/LB/' . $billcode . '/' . trim($field) . '=' . rawurlencode(trim($value));
    }
  }

  /// The master campaign ID and each sponsor ID are posted individually
  foreach (array_merge([$master_campaign_id], $sponsor_ids) as $campaign_id) {
    // Assemble a URL string with GET values for sending data to Accela
    $accela_datapost_url = $base_url . '&Script=/LP/' . $campaign_id . '/reg' . $url_questions;

    $to = 'jsalisbury@summitmediagroup.com';
    $params = [
      'to'      => $to,
      'subject' => 'Accelaworks Datapost',
      'body'    => ['AccelaWorks Datapost', variable_get('site_name') . ':' . implode('/', arg()), 'question query string: ' . $accela_datapost_url],
      'headers' => [
        'From'      => $to,
        'Reply-To'  => $to,
      ],
    ];
    //drupal_mail('playbook_fields', 'accela_datapost', $to, language_default(), $params);

    // Log each individual non-posted Accela URL separately so that
    // resubmission is an option.
    //if ($bad_domain) {
    //  watchdog('playbook_fields', 'An email address with a domain that does not validate was supplied. No data was sent to Accela for this lead. The address: %email. The full cURL string which would have been posted: %curl', array('%email' => $accela_fields['EmailAddress'], '%curl' => $accela_datapost_url), WATCHDOG_ERROR);
    //  continue;
    //}

    // If the initialization fails, log the error and move on to the next
    // program
    $ch = curl_init($accela_datapost_url);

    if ($ch === FALSE) {
      //watchdog('playbook_fields', smg_prewatch(__FUNCTION__, __LINE__, -2, __FILE__) . 'cURL initialization failed. The Playbook for which this data should have been posted: %name. The full cURL string which would have been posted: %curl', array('%name' => $playbook['name'], '%curl' => $accela_datapost_url), WATCHDOG_ERROR);
      watchdog('playbook_fields', 'cURL initialization failed. The full cURL string which would have been posted: %curl', ['%curl' => $accela_datapost_url], WATCHDOG_ERROR);
      continue;
    }

    curl_setopt($ch, CURLOPT_RETURNTRANSFER, TRUE);
    curl_setopt($ch, CURLOPT_TIMEOUT, 4);
    // Log any failed posts with enough data to recover manually, but don't stop
    // execution
    if (curl_exec($ch) === FALSE) {
      //watchdog('playbook_fields', smg_prewatch(__FUNCTION__, __LINE__, -5, __FILE__) . 'Data from the Playbook named %name failed to post to the Accela Program with ID %id. The cURL call failed. The full cURL string which failed to post: %curl', array('%name' => $playbook['name'], '%id' => $campaign_id, '%curl' => $accela_datapost_url), WATCHDOG_ERROR);
      watchdog('playbook_fields', 'Data failed to post to the Accela Program with ID %id. The cURL call failed. The full cURL string which failed to post: %curl', ['%id' => $campaign_id, '%curl' => $accela_datapost_url], WATCHDOG_ERROR);
    }
    //Loging every post to accella
    else {
      watchdog('playbook_fields', 'Accela Post: %curl', ['%curl' => $accela_datapost_url], WATCHDOG_DEBUG);
    }

    curl_close($ch);

    // Wait for 300ms between submissions as per the AccelWorks recommendation.
    // For details: http://dev.summitpublish.com/ticket/763
    usleep(600000);
  }

  return TRUE;
}

/**
 * Report submitted data to Silverpop
 *
 * @param array $fields
 * @param object $node
 *
 * @return string
 */
function _webform_smg_silverpop_post($fields, $node) {

  $client = new SilverpopSoapClient();

  // Organize submitted values by Silverpop destination field
  $contact = [];
  $relational_fields = [];

  $fieldType = FALSE;
  foreach ($fields as $field) {

    $sp_field = trim($field['silverpop_field']);
    // Create array of $relational_fields.
    if (!empty($field['silverpop_audience_preferences_subscription']) && !empty($field['values'][0])) {
      $field_key = trim ($field['silverpop_audience_preferences_subscription']);
      $relational_fields[$field_key] = $field['values'][0];
    }
    if ($field['type'] != 'smg_auto_address' && empty($sp_field)) {
      continue;
    }

    // Grid fields get their submitted value keys appended to the values for readability
    if ($field['type'] == 'smg_grid') {
      foreach ($field['values'] as $k => $v) {
        $field['values'][$k] = "$k:$v";
      }
    }

    if ($field['type'] == 'smg_email') {
      $field['values'][0] = strtolower($field['values'][0]);
    }

    // Map Autocomplete Address components to Silverpop fields.
    if ($field['type'] == 'smg_auto_address') {
      $address_components = [];
      if (!empty($field['values']['smg_autocomplete_address_text']))
        $address_components['Address Single Line'] = $field['values']['smg_autocomplete_address_text'];
      if (!empty($field['values']['address_response']))
        $address_components['SmartyStreets Verified Address'] = $field['values']['address_response'];
      if (!empty($field['values']['address_line_1']))
        $address_components['Address 1'] = $field['values']['address_line_1'];
      if (!empty($field['values']['address_line_2']))
        $address_components['Address 2'] = $field['values']['address_line_2'];
      if (!empty($field['values']['address_city']))
        $address_components['City'] = $field['values']['address_city'];
      if (!empty($field['values']['address_state']))
        $address_components['State'] = $field['values']['address_state'];
      if (!empty($field['values']['address_zip']))
        $address_components['Zip'] = $field['values']['address_zip'];
      if (!empty($field['values']['smg_autocomplete_address_text']))
        $field['values'][] = $field['values']['smg_autocomplete_address_text'];
    }

    if ($field['name'] == 'Opt-in' && empty($field['values']))
      $field['values'] = ['No'];

    // The implosion below concatenates all multi-select answers for this field into one value
    $contact[$sp_field][] = [
      'name' => $field['name'],
      'type' => $field['type'],
      'value' => implode($field['values'], ';'),
      'prepend' => TRUE, // Always prepend question for silverpop (no matter if it isn't checked)
    ];

    // Get types of field and set in array to be accessed later.
    if ($field['silverpop_field']) {
      $fieldType[$field['silverpop_field']] = $field['type'];
    }
    else if ($field['silverpop_audience_preferences_subscription']) {
      $fieldType[$field['silverpop_audience_preferences_subscription']] = $field['type'];
    }
  }

  // Prepare Silverpop-ready array
  $silverpop_fields = playbook_fields_concatenate($contact);

  if (isset($silverpop_fields['Country'])) {
    $silverpop_fields['Country'] = strtoupper($silverpop_fields['Country']);
  }

  // Attempt to find an existing record for this user
  $existing_contact = null;
  if (isset($silverpop_fields['Email'])) {
    $existing_contact = playbook_fields_get_silverpop_contact_by_email($silverpop_fields['Email']);
  }

  $silverpop_fields = playbook_fields_add_contact_prepare($silverpop_fields, $existing_contact, $fieldType, $node);
  if ($silverpop_fields) {
    // Add address components to silverpop fields array.
    if (isset($address_components)) {
      foreach ($address_components as $key => $value) {
        $silverpop_fields[$key] = $value;
      }
    }

    foreach ($silverpop_fields as $key => $silverpop_field) {
      if ($silverpop_field == 'Not applicable' || $silverpop_field == '') {
        unset($silverpop_fields[$key]);
      }
    }

    // Add email to relational fieds.
    $relational_fields['Email'] = $silverpop_fields['Email'];

    $visitor_key = (isset($_COOKIE['spop_visitor_id'])) ? $_COOKIE['spop_visitor_id'] : '';
    // Check if field_brand_override is defined. Will use it if not empty. Otherwise, variable smg_global_site will be used.
    $brand_override = field_get_items('node', $node, 'field_brand_override', LANGUAGE_NONE);
    $brand = !empty($brand_override) ? strtoupper($brand_override[0]['value']) : strtoupper(variable_get('smg_global_site'));
    $query_params = drupal_get_query_parameters();
    foreach ($query_params as $query_key => $query_param) {
      if ($query_key != 'spMailingID' && $query_key != 'utm_source') {
        unset($query_params[$query_key]);
      }
    }
    try {
      $response = $client->addContact($silverpop_fields, $visitor_key);
      $client->addRelationalTableRecords($relational_fields, $brand, $query_params);
      // Should we check if addRelationalTableRecords gives error?
      if ($response->SUCCESS == TRUE) {
        return $response->RecipientId;
      } else {
        return null;
      }
    } catch (Exception $e) {
      return null;
    }
  } else {
    return null;
  }
}

/**
 * Report submitted data to GotoWebinars
 *
 * @param  array        $fields
 * @param  int          $webinar_id
 * @param  object|NULL  $node
 *
 * @return bool
 */
function _webform_smg_gotowebinars_post($fields, $webinar_id, $node = NULL) {
  if (!$webinar_id) {
    return FALSE;
  }

  if (isset($node) && $node->type == 'webinar_registration') {
    if(property_exists($node, 'field_gotowebinar_webinar_date') && isset($node->field_gotowebinar_webinar_date['und'])){
      $year_ago = time() - (60 * 60 * 24 * 365);
      $value2 = $node->field_gotowebinar_webinar_date['und'][0]['value2'];
      if($value2 < $year_ago){
        $_SESSION['webinar_access'] = TRUE;
        return FALSE;
      }
    }
    else {
      return FALSE;
    }
  }

  $registrant = [];
  foreach ($fields as $field) {
    if ($field['gotowebinar_field']) {
      $registrant[$field['gotowebinar_field']] = $field['values'][0];
    }
  }

  $oauth_en = new OAuth_En();
  $oauth_en->setAccessToken(GOTO_WEBINAR_AUTH_TOKEN);
  $oauth_en->setOrganizerKey(GOTO_WEBINAR_ORGANIZER_KEY);

  $oauth = new OAuth($oauth_en);
  $oauth->setWebinarId($webinar_id);
  $oauth->setRegistrantInfo($registrant);
  $response = $oauth->createRegistrant();

  if (isset($response->registrantKey)) {
    $_SESSION['webinar_access'] = TRUE;
    $_SESSION['response'] = $response;
    return TRUE;
  } else {
    if ($oauth->hasApiError()) {
      $oauth_error = $oauth->getApiError()->description;
      if ($oauth_error == 'Cannot register for a webinar that is in the past') {
        $_SESSION['webinar_access'] = TRUE;
        return TRUE;
      } else {
        $_SESSION['webinar_access'] = FALSE;
      }
    } else {
      $_SESSION['webinar_access'] = FALSE;
      $oauth_error = 'none';
    }

    $to = 'devuser@pmmimediagroup.com';
    $params = [
        'to'      => $to,
        'subject' => 'Webinar form error!',
        'body'    => ['Webinar Error', 'webinar id: ' . $webinar_id, 'oauth api error: ' . print_r($oauth->getApiError(), TRUE), 'fields: ' . print_r($fields, TRUE)],
        'headers' => [
          'From'      => $to,
          'Reply-To'  => $to,
        ],
    ];

    drupal_mail('playbook_fields', 'webinar_error', $to, language_default(), $params);
    return FALSE;
  }
}

/**
 * Convert a standard Silverpop value to a Salesforce picklist value
 */
function playbook_fields_ringlead_translate($field, $values) {
  switch ($field) {
    case '00NG0000009HKlb': //AW Industry
      $map = [
        'Oil and gas including LNG' =>                                        'Oil and gas including LNG',
        'Chemical Processing' =>                                              'Chemical Processing',
        'Food and Beverage' =>                                                'Food and Beverage',
        'Consumer Packaged Goods (Everything other than Food/Beverage)' =>    'Consumer Packaged Goods',
        'Pharmaceuticals' =>                                                  'Pharmaceuticals',
        'Electrical Utilities/Power Generation' =>                            'Electrical Utilities/Power Generation',
        'Paper, Wood and Allied products' =>                                  'Paper, Wood and Allied products',
        'Fabricated Metals' =>                                                'Fabricated Metals',
        'Packaging, Printing, Converting Machinery' =>                        'Packaging,Printing,Converting Machinery',
        'All Other Machinery (including material handling and conveying)' =>  'All other machinery',
        'Auto, truck, rail, marine transportation' =>                         'Auto,truck,rail,marine transportation',
        'Construction, agricultural, mining equipment' =>                     'Construction, agricultural, mining equip',
        'Medical equipment and devices' =>                                    'Medical equipment and devices',
        'Instrumentation, control, measurement products' =>                   'Instrumentation,control,measurement prod',
        'Computers, electronics, semiconductors' =>                           'Computers,electronics, semiconductors',
        'Plastics and rubber products' =>                                     'Plastics and rubber products',
        'Communication devices and equipment' =>                              'Communication devices and equipment',
        'Alternative Energy (Wind, hydro, solar, and bio fuels)' =>           'Alternative Energy',
        'Water and wastewater' =>                                             'Water and wastewater',
        'Aerospace, aircraft and defense products' =>                         'Aerospace, aircraft and defense products',
        'Consulting or systems integration' =>                                'Consulting or systems integration',
        'Other' =>                                                            'Other',
      ];
      break;
    case '00NG0000009HKki': //AW Automation Type
      $map = [
        'Discrete manufacturing/factory automation' =>  'Discrete manufacturing/factory auto.',
        'Batch/Hybrid processing' =>                    'Batch/Hybrid processing',
        'Continuous processing' =>                      'Continuous processing',
      ];
      break;
    case '00NG0000009HNMo': //PW HCP Industry
      $map = [
        'Meat, Poultry, Seafood' =>                                                   'Meat, Poultry, Seafood',
        'Fruits, Vegetables (Fresh, Canned, Frozen)' =>                               'Fruits,Vegetables(Fresh, Canned, Frozen)',
        'Grains, Seeds, Beans, Flour, Nuts' =>                                        'Grains, Seeds, Beans, Flour, Nuts',
        'Cereals, Breakfast Foods' =>                                                 'Cereals, Breakfast Foods',
        'Baked Goods, Cookies, Crackers, Pasta, Snack Foods' =>                       'Baked Goods,Cookies,Crackers,Pasta,Snack',
        'Confectionery Products, Sugar' =>                                            'Confectionery Products, Sugar',
        'Dairy Products' =>                                                           'Dairy Products',
        'Beverages (Soft Drinks, Juices, Alcoholic Beverages, Coffee, Tea)' =>        'Beverages',
        'Soups, Sauces, Condiments, Dressings, Spices, Syrup, Powders' =>             'Soups,Sauces,Conds,Dressing,Spice,Syrup',
        'Fats, Oils' =>                                                               'Fats, Oils',
        'Pet Foods, Animal Foods' =>                                                  'Pet Foods, Animal Foods',
        'Other Food and Beverage Products' =>                                         'Other Food and Beverage Products',
        'Pharmaceutical' =>                                                           'Pharmaceutical',
        'Medical Devices/Diagnostic Instruments' =>                                   'Medical Devices / Diagnostic Instruments',
        'Biological/Biopharmaceutical' =>                                             'Biological / Biopharmaceutical',
        'Nutraceutical, Vitamin, Dietary Supplement' =>                               'Nutraceutical,Vitamin,Dietary Supplement',
        'Government' =>                                                               'Government',
        'Cosmetics, Toiletries, Baby Products' =>                                     'Cosmetics, Toiletries, Baby Products',
        'Soap, Household Cleaners, Other Household Products' =>                       'Soap,HouseholdCleaners,OtherHouseProds',
        'Chemicals, Paints, Adhesives' =>                                             'Chemicals, Paints, Adhesives',
        'Apparel, Textiles' =>                                                        'Apparel, Textiles',
        'Consumer Electronics, Computers, Peripherals, Household Appliances' =>       'ConsElec,Comps,Peripherals,HouseholdApps',
        'Toys, Games, Sporting Goods' =>                                              'Toys, Games, Sporting Goods',
        'Plastic, Rubber Products' =>                                                 'Plastic, Rubber Products',
        'Paper, Printed Products, Office Supplies' =>                                 'Paper, Printed Products, Office Supplies',
        'Metal, Glass, Wood Products' =>                                              'Metal, Glass, Wood Products',
        'Machinery, Electronic' =>                                                    'Machinery, Electronic',
        'Food Stores, Food Service' =>                                                'Food Stores, Food Service',
        'Wholesalers, Distributors, Warehouses' =>                                    'Wholesalers, Distributors, Warehouses',
        'Other' =>                                                                    'Other',
        'Packaging Machinery' =>                                                      'Packaging Machinery',
        'Package Design Firm' =>                                                      'Package Design Firm',
        'Controls, Components, Integration Services, Line Automation' =>              'Controls,Components,IntServices,LineAuto',
        'Packaging Distributor' =>                                                    'Packaging Distributor',
        'Raw Materials (Board, Resin, Additives, etc.)' =>                            'Raw Materials Supplier',
        'Converted Package or Component (Film, Closures, Pouches, Lidding, etc.)' =>  'Converted Package or Component',
      ];
      break;
    case '00NG0000009HNMy': //PW HCP Job Duties
    case '00NG0000009HQqD': //PW HCP Job Duty Primary
      $map = [
        'Production/Operations/Quality' =>                                'Production/Operations/Quality',
        'Packaging Machinery Engineering' =>                              'Package Machinery Engineering',
        'Package Development Engineering/R&D' =>                          'Package Development Engineering/RD',
        'Package Design/Brand Management/Marketing' =>                    'Package Design/Brand Manage/Marketing',
        'Supply Chain: Logistics, Distribution, Warehouse Automation' =>  'Supply Chain: Logistics, Distribution',
        'Regulatory Affairs, Validation/Compliance' =>                    'Regulatory Affairs, Validation/Comp',
        'Procurement' =>                                                  'Procurement',
        'Other' =>                                                        'Other',
      ];
      break;
    case 'country':
      $map = [
        'AFGHANISTAN' => 'Afghanistan',
        'ALAND ISLANDS' => 'Aland Islands',
        'ALBANIA' => 'Albania',
        'ALGERIA' => 'Algeria',
        'AMERICAN SAMOA' => '',
        'ANDORRA' => 'Andorra',
        'ANGOLA' => 'Angola',
        'ANGUILLA' => 'Anguilla',
        'ANTARCTICA' => 'Antarctica',
        'ANTIGUA AND BARBUDA' => 'Antigua and Barbuda',
        'ARGENTINA' => 'Argentina',
        'ARMENIA' => 'Armenia',
        'ARUBA' => 'Aruba',
        'AUSTRALIA' => 'Australia',
        'AUSTRIA' => 'Austria',
        'AZERBAIJAN' => 'Azerbaijan',
        'BAHAMAS' => 'Bahamas',
        'BAHRAIN' => 'Bahrain',
        'BANGLADESH' => 'Bangladesh',
        'BARBADOS' => 'Barbados',
        'BELARUS' => 'Belarus',
        'BELGIUM' => 'Belgium',
        'BELIZE' => 'Belize',
        'BENIN' => 'Benin',
        'BERMUDA' => 'Bermuda',
        'BHUTAN' => 'Bhutan',
        'BOLIVIA' => 'Bolivia, Plurinational State of',
        'BOSNIA AND HERZEGOVINA' => 'Bosnia and Herzegovina',
        'BOTSWANA' => 'Botswana',
        'BOUVET ISLAND' => 'Bouvet Island',
        'BRAZIL' => 'Brazil',
        'BRITISH INDIAN OCEAN TERRITORY' => 'British Indian Ocean Territory',
        'BRITISH VIRGIN ISLANDS' => 'Virgin Islands, British',
        'BRUNEI' => 'Brunei Darussalam',
        'BULGARIA' => 'Bulgaria',
        'BURKINA FASO' => 'Burkina Faso',
        'BURUNDI' => 'Burundi',
        'CAMBODIA' => 'Cambodia',
        'CAMEROON' => 'Cameroon',
        'CANADA' => 'Canada',
        'CAPE VERDE' => 'Cape Verde',
        'CAYMAN ISLANDS' => 'Cayman Islands',
        'CENTRAL AFRICAN REPUBLIC' => 'Central African Republic',
        'CHAD' => 'Chad',
        'CHILE' => 'Chile',
        'CHINA' => 'China',
        'CHRISTMAS ISLAND' => 'Christmas Island',
        'COCOS (KEELING) ISLANDS' => 'Cocos (Keeling) Islands',
        'COLOMBIA' => 'Colombia',
        'COMOROS' => 'Comoros',
        'CONGO (BRAZZAVILLE)' => 'Congo',
        'CONGO (KINSHASA)' => 'Congo, the Democratic Republic of the',
        'COOK ISLANDS' => 'Cook Islands',
        'COSTA RICA' => 'Costa Rica',
        'IVORY COAST' => 'Cote d\'Ivoire',
        'CROATIA' => 'Croatia',
        'CUBA' => 'Cuba',
        'CURAÇAO' => 'Curaçao',
        'CYPRUS' => 'Cyprus',
        'CZECH REPUBLIC' => 'Czech Republic',
        'DENMARK' => 'Denmark',
        'DJIBOUTI' => 'Djibouti',
        'DOMINICA' => 'Dominica',
        'DOMINICAN REPUBLIC' => 'Dominican Republic',
        'ECUADOR' => 'Ecuador',
        'EGYPT' => 'Egypt',
        'EL SALVADOR' => 'El Salvador',
        'EQUATORIAL GUINEA' => 'Equatorial Guinea',
        'ERITREA' => 'Eritrea',
        'ESTONIA' => 'Estonia',
        'ETHIOPIA' => 'Ethiopia',
        'FALKLAND ISLANDS' => 'Falkland Islands (Malvinas)',
        'FAROE ISLANDS' => 'Faroe Islands',
        'FIJI' => 'Fiji',
        'FINLAND' => 'Finland',
        'FRANCE' => 'France',
        'FRENCH GUIANA' => 'French Guiana',
        'FRENCH POLYNESIA' => 'French Polynesia',
        'FRENCH SOUTHERN TERRITORIES' => 'French Southern Territories',
        'GABON' => 'Gabon',
        'GAMBIA' => 'Gambia',
        'GEORGIA' => 'Georgia',
        'GERMANY' => 'Germany',
        'GHANA' => 'Ghana',
        'GIBRALTAR' => 'Gibraltar',
        'GREECE' => 'Greece',
        'GREENLAND' => 'Greenland',
        'GRENADA' => 'Grenada',
        'GUADELOUPE' => 'Guadeloupe',
        'GUAM' => '',
        'GUATEMALA' => 'Guatemala',
        'GUERNSEY' => 'Guernsey',
        'GUINEA' => 'Guinea',
        'GUINEA-BISSAU' => 'Guinea-Bissau',
        'GUYANA' => 'Guyana',
        'HAITI' => 'Haiti',
        'HEARD ISLAND AND MCDONALD ISLANDS' => 'Heard Island and McDonald Islands',
        'VATICAN' => 'Holy See (Vatican City State)',
        'HONDURAS' => 'Honduras',
        'HONG KONG S.A.R., CHINA' => 'China',
        'HUNGARY' => 'Hungary',
        'ICELAND' => 'Iceland',
        'INDIA' => 'India',
        'INDONESIA' => 'Indonesia',
        'IRAN' => 'Iran, Islamic Republic of',
        'IRAQ' => 'Iraq',
        'IRELAND' => 'Ireland',
        'ISLE OF MAN' => 'Isle of Man',
        'ISRAEL' => 'Israel',
        'ITALY' => 'Italy',
        'JAMAICA' => 'Jamaica',
        'JAPAN' => 'Japan',
        'JERSEY' => 'Jersey',
        'JORDAN' => 'Jordan',
        'KAZAKHSTAN' => 'Kazakhstan',
        'KENYA' => 'Kenya',
        'KIRIBATI' => 'Kiribati',
        'NORTH KOREA' => 'Korea, Democratic People\'s Republic of',
        'SOUTH KOREA' => 'Korea, Republic of',
        'KUWAIT' => 'Kuwait',
        'KYRGYZSTAN' => 'Kyrgyzstan',
        'LAOS' => 'Lao People\'s Democratic Republic',
        'LATVIA' => 'Latvia',
        'LEBANON' => 'Lebanon',
        'LESOTHO' => 'Lesotho',
        'LIBERIA' => 'Liberia',
        'LIBYA' => 'Libyan Arab Jamahiriya',
        'LIECHTENSTEIN' => 'Liechtenstein',
        'LITHUANIA' => 'Lithuania',
        'LUXEMBOURG' => 'Luxembourg',
        'MACAO S.A.R., CHINA' => 'Macao',
        'MACEDONIA' => 'Macedonia, the former Yugoslav Republic of',
        'MADAGASCAR' => 'Madagascar',
        'MALAWI' => 'Malawi',
        'MALAYSIA' => 'Malaysia',
        'MALDIVES' => 'Maldives',
        'MALI' => 'Mali',
        'MALTA' => 'Malta',
        'MARSHALL ISLANDS' => '',
        'MARTINIQUE' => 'Martinique',
        'MAURITANIA' => 'Mauritania',
        'MAURITIUS' => 'Mauritius',
        'MAYOTTE' => 'Mayotte',
        'MEXICO' => 'Mexico',
        'MICRONESIA' => '',
        'MOLDOVA' => 'Moldova, Republic of',
        'MONACO' => 'Monaco',
        'MONGOLIA' => 'Mongolia',
        'MONTENEGRO' => 'Montenegro',
        'MONTSERRAT' => 'Montserrat',
        'MOROCCO' => 'Morocco',
        'MOZAMBIQUE' => 'Mozambique',
        'MYANMAR' => 'Myanmar',
        'NAMIBIA' => 'Namibia',
        'NAURU' => 'Nauru',
        'NEPAL' => 'Nepal',
        'NETHERLANDS' => 'Netherlands',
        'NETHERLANDS ANTILLES' => '',
        'NEW CALEDONIA' => 'New Caledonia',
        'NEW ZEALAND' => 'New Zealand',
        'NICARAGUA' => 'Nicaragua',
        'NIGER' => 'Niger',
        'NIGERIA' => 'Nigeria',
        'NIUE' => 'Niue',
        'NORFOLK ISLAND' => 'Norfolk Island',
        'NORTHERN MARIANA ISLANDS' => '',
        'NORWAY' => 'Norway',
        'OMAN' => 'Oman',
        'PAKISTAN' => 'Pakistan',
        'PALAU' => '',
        'PALESTINIAN TERRITORY' => 'Palestinian Territory, Occupied',
        'PANAMA' => 'Panama',
        'PAPUA NEW GUINEA' => 'Papua New Guinea',
        'PARAGUAY' => 'Paraguay',
        'PERU' => 'Peru',
        'PHILIPPINES' => 'Philippines',
        'PITCAIRN' => 'Pitcairn',
        'POLAND' => 'Poland',
        'PORTUGAL' => 'Portugal',
        'PUERTO RICO' => '',
        'QATAR' => 'Qatar',
        'REUNION' => 'Reunion',
        'ROMANIA' => 'Romania',
        'RUSSIA' => 'Russian Federation',
        'RWANDA' => 'Rwanda',
        'SAINT BARTHÉLEMY' => 'Saint Barthélemy',
        'SAINT HELENA' => 'Saint Helena, Ascension and Tristan da Cunha',
        'SAINT KITTS AND NEVIS' => 'Saint Kitts and Nevis',
        'SAINT LUCIA' => 'Saint Lucia',
        'SAINT MARTIN (FRENCH PART)' => 'Saint Martin (French part)',
        'SAINT PIERRE AND MIQUELON' => 'Saint Pierre and Miquelon',
        'SAINT VINCENT AND THE GRENADINES' => 'Saint Vincent and the Grenadines',
        'SAMOA' => 'Samoa',
        'SAN MARINO' => 'San Marino',
        'SAO TOME AND PRINCIPE' => 'Sao Tome and Principe',
        'SAUDI ARABIA' => 'Saudi Arabia',
        'SENEGAL' => 'Senegal',
        'SERBIA' => 'Serbia',
        'SEYCHELLES' => 'Seychelles',
        'SIERRA LEONE' => 'Sierra Leone',
        'SINGAPORE' => 'Singapore',
        'SLOVAKIA' => 'Slovakia',
        'SLOVENIA' => 'Slovenia',
        'SOLOMON ISLANDS' => 'Solomon Islands',
        'SOMALIA' => 'Somalia',
        'SOUTH AFRICA' => 'South Africa',
        'SOUTH GEORGIA AND THE SOUTH SANDWICH ISLANDS' => 'South Georgia and the South Sandwich Islands',
        'SPAIN' => 'Spain',
        'SRI LANKA' => 'Sri Lanka',
        'SUDAN' => 'Sudan',
        'SURINAME' => 'Suriname',
        'SVALBARD AND JAN MAYEN' => 'Svalbard and Jan Mayen',
        'SWAZILAND' => 'Swaziland',
        'SWEDEN' => 'Sweden',
        'SWITZERLAND' => 'Switzerland',
        'SYRIA' => 'Syrian Arab Republic',
        'TAIWAN' => 'China',
        'TAJIKISTAN' => 'Tajikistan',
        'TANZANIA' => 'Tanzania, United Republic of',
        'THAILAND' => 'Thailand',
        'TIMOR-LESTE' => 'Timor-Leste',
        'TOGO' => 'Togo',
        'TOKELAU' => 'Tokelau',
        'TONGA' => 'Tonga',
        'TRINIDAD AND TOBAGO' => 'Trinidad and Tobago',
        'TUNISIA' => 'Tunisia',
        'TURKEY' => 'Turkey',
        'TURKMENISTAN' => 'Turkmenistan',
        'TURKS AND CAICOS ISLANDS' => 'Turks and Caicos Islands',
        'TUVALU' => 'Tuvalu',
        'U.S. VIRGIN ISLANDS' => '',
        'UGANDA' => 'Uganda',
        'UKRAINE' => 'Ukraine',
        'UNITED ARAB EMIRATES' => 'United Arab Emirates',
        'UNITED KINGDOM' => 'United Kingdom',
        'UNITED STATES' => 'United States',
        'UNITED STATES MINOR OUTLYING ISLANDS' => '',
        'URUGUAY' => 'Uruguay',
        'UZBEKISTAN' => 'Uzbekistan',
        'VANUATU' => 'Vanuatu',
        'VENEZUELA' => 'Venezuela, Bolivarian Republic of',
        'VIETNAM' => 'Viet Nam',
        'WALLIS AND FUTUNA' => 'Wallis and Futuna',
        'WESTERN SAHARA' => 'Western Sahara',
        'YEMEN' => 'Yemen',
        'ZAMBIA' => 'Zambia',
        'ZIMBABWE' => 'Zimbabwe',
      ];
      break;
    case 'state':
      $map = [
        'AL' => 'Alabama',
        'AK' => 'Alaska',
        //'AS' => 'American Samoa',
        'AZ' => 'Arizona',
        'AR' => 'Arkansas',
        'CA' => 'California',
        'CO' => 'Colorado',
        'CT' => 'Connecticut',
        'DE' => 'Delaware',
        'DC' => 'District of Columbia',
        'FL' => 'Florida',
        'GA' => 'Georgia',
        //'GU' => 'Guam',
        'HI' => 'Hawaii',
        'ID' => 'Idaho',
        'IL' => 'Illinois',
        'IN' => 'Indiana',
        'IA' => 'Iowa',
        'KS' => 'Kansas',
        'KY' => 'Kentucky',
        'LA' => 'Louisiana',
        'ME' => 'Maine',
        //'MH' => 'Marshall Islands',
        'MD' => 'Maryland',
        'MA' => 'Massachusetts',
        'MI' => 'Michigan',
        'MN' => 'Minnesota',
        'MS' => 'Mississippi',
        'MO' => 'Missouri',
        'MT' => 'Montana',
        'NE' => 'Nebraska',
        'NV' => 'Nevada',
        'NH' => 'New Hampshire',
        'NJ' => 'New Jersey',
        'NM' => 'New Mexico',
        'NY' => 'New York',
        'NC' => 'North Carolina',
        'ND' => 'North Dakota',
        //'MP' => 'Northern Marianas Islands',
        'OH' => 'Ohio',
        'OK' => 'Oklahoma',
        'OR' => 'Oregon',
        //'PW' => 'Palau',
        'PA' => 'Pennsylvania',
        //'PR' => 'Puerto Rico',
        'RI' => 'Rhode Island',
        'SC' => 'South Carolina',
        'SD' => 'South Dakota',
        'TN' => 'Tennessee',
        'TX' => 'Texas',
        'UT' => 'Utah',
        'VT' => 'Vermont',
        //'VI' => 'Virgin Islands',
        'VA' => 'Virginia',
        'WA' => 'Washington',
        'WV' => 'West Virginia',
        'WI' => 'Wisconsin',
        'WY' => 'Wyoming',
        'Alberta' => 'Alberta',
        'British Columbia' => 'British Columbia',
        'Manitoba' => 'Manitoba',
        'New Brunswick' => 'New Brunswick',
        'Newfoundland and Labrador' => 'Newfoundland and Labrador',
        'Northwest Territories' => 'Northwest Territories',
        'Nova Scotia' => 'Nova Scotia',
        'Nunavut' => 'Nunavut',
        'Ontario' => 'Ontario',
        'Prince Edward Island' => 'Prince Edward Island',
        'Quebec' => 'Quebec',
        'Saskatchewan' => 'Saskatchewan',
        'Yukon' => 'Yukon Territories',
      ];
      break;
    default:
      $map = [];
      break;
  }

  $ret = [];
  foreach ($values as $v) {
    if (array_key_exists($v, $map)) {
      $ret[] = $map[$v];
    } else {
      $ret[] = $v;
      if ($map)
        mail('jsalisbury@summitmediagroup.com','Map error on ' . variable_get('site_name'), $v . print_r($map, TRUE));
    }
  }

  return $ret;
}

/**
 * Report submitted data to Ringlead (Salesforce app)
 */
function _webform_smg_ringlead_post($fields) {
  //$base_url = 'https://www.salesforce.com/servlet/servlet.WebToLead?encoding=UTF-8';
  $site_to_url = [
    'Automation World' => 'https://salesforce.ringlead.com/cgi-bin/2557/2/dedup.pl',
    'Packaging World' => 'https://salesforce.ringlead.com/cgi-bin/2557/3/dedup.pl',
    'Healthcare Packaging' => 'https://salesforce.ringlead.com/cgi-bin/2557/4/dedup.pl',
  ];

  $us_states = [
    "AL","AK","AZ","AR","CA","CO","CT","DE","FL","GA",
                     "HI","ID","IL","IN","IA","KS","KY","LA","ME","MD",
                     "MA","MI","MN","MS","MO","MT","NE","NV","NH","NJ",
                     "NM","NY","NC","ND","OH","OK","OR","PA","RI","SC",
                     "SD","TN","TX","UT","VT","VA","WA","WV","WI","WY"
  ];

  $us_other = ["DC","AS","GU","MH","MP","PW","PR","VI"];

  $canada_states = [
    "Alberta",
    "British Columbia",
    "Manitoba",
    "New Brunswick",
    "Newfoundland And Labrador",
    "Nova Scotia",
    "Northwest Territories",
    "Ontario",
    "Prince Edward Island",
    "Quebec",
    "Saskatchewan",
    "Yukon Territories",
    "Nunavut",
  ];
  $base_url = $site_to_url[variable_get('site_name')];
  $date = date('m/d/Y');

  // Automatically set demographic and verification dates when we're signing up for a magazine
  foreach ($fields as $field) {
    if ($field['salesforce_field'] == '00NG0000009HKn3' && $field['values'][0] == 'Yes') { // AW Mag Request
      $fields[] = [
        'salesforce_field' => '00NG0000009HKlH', // AW Demographic Date
        'values' => [$date],
      ];
      $fields[] = [
        'salesforce_field' => '00NG0000009HKo1', // AW Verification Date
        'values' => [$date],
      ];
    }
    if ($field['salesforce_field'] == '00NG0000009HNNX' && $field['values'][0] == 'Yes') { // PW Mag Request
      $fields[] = [
        'salesforce_field' => '00NG0000009HNMK', // PW Demographic Date
        'values' => [$date],
      ];
      $fields[] = [
        'salesforce_field' => '00NG0000009HNOf', // PW Verification Date
        'values' => [$date],
      ];
    }
    if ($field['salesforce_field'] == '00NG0000009HL3a' && $field['values'][0] == 'Yes') { // HCP Mag Request
      $fields[] = [
        'salesforce_field' => '00NG0000009HL3B', // HCP Demographic Date
        'values' => [$date],
      ];
      $fields[] = [
        'salesforce_field' => '00NG0000009HL4O', // HCP Verification Date
        'values' => [$date],
      ];
    }
  }

  // Organize submitted values by Salesforce destination field
  $contact = [];
  foreach ($fields as $field) {
    if (isset($field['salesforce_field']))
      $sf_field = trim($field['salesforce_field']);
    else
      continue;

    // The implosion below concatenates all multi-select answers for this field into one value
    $contact[$sf_field] = [
      'type' => $field['type'],
      'multiple' => $field['multiple'],
      //'value' => implode($field['values'], ';'),
      'values' => $field['values'],
    ];
  }

  if ($contact['country']['values'][0] != 'UNITED STATES' && $contact['country']['values'][0] != 'CANADA') {
    unset($contact['state']);
  } else {
    if (in_array($contact['state']['values'][0], $us_states)) {
      $contact['country']['values'] = ['UNITED STATES'];
    } elseif (in_array($contact['state']['values'][0], $us_other)) {
      $contact['country']['values'] = ['US Territories'];
    } elseif (in_array($contact['state']['values'][0], $canada_states)) {
      $contact['country']['values'] = ['CANADA'];
    }
  }

  // Form the query string that will be cUrled to Ringlead
  $query_str = '';
  foreach ($contact as $sf_field => $field) {
    $q_name = rawurlencode($sf_field);

    if ($sf_field == 'country') {
      $field['values'] = [
        ucwords(strtolower($field['values'][0]))
      ];
    }
    $mapped_values = playbook_fields_ringlead_translate($sf_field, $field['values']);

    // add all fields to $query_str
    // multiple-valued fields get looped over
    if ($field['type'] == 'smg_select' && $field['multiple'] == TRUE) {
      foreach ($mapped_values as $value) {
        $query_str .= $q_name . '=' . rawurlencode($value) . '&';
      }
    } else {
      $query_str .= $q_name . '=' . rawurlencode($mapped_values[0]) . '&';
    }
  }

  if ($query_str) {
    $curl = curl_init($base_url);
    curl_setopt($curl, CURLOPT_POST, TRUE); //do an HTTP POST
    curl_setopt($curl, CURLOPT_POSTFIELDS, substr($query_str, 0, -1)); //remove trailing '&'
    curl_setopt($curl, CURLOPT_SSL_VERIFYPEER, FALSE); //accept all SSL certs
    curl_setopt($curl, CURLOPT_RETURNTRANSFER, TRUE); //Ringlead will return the Salesforce ID of the submitted lead FIXME
    $sfid = curl_exec($curl);
    curl_close($curl);
    return $sfid;
  } else {
    return null;
  }
}

/**
 * Adds the gived recipient to the given Silverpop program using the Silverpop API
 */
function playbook_fields_add_contact_to_program($recipient_id, $program_id) {
  $client = new SilverpopSoapClient();
  $client->addContactToProgram($recipient_id, $program_id);
}

/**
 * Report submitted data to Leadworks
 *
 * @param  array         $fields
 * @param  array         $sponsor_ids
 * @param  string|array  $master_campaign_id
 * @return bool
 */
function playbook_fields_leadworks_post($fields, $sponsor_ids, $master_campaign_id) {

  // Organize submitted values by Leadworks destination field
  $contact = [];

  // Will use if form has an smg_password field set
  $password = NULL;

  foreach ($fields as $field) {
    if (isset($field['leadworks_id']) && trim($field['leadworks_id'])) {
      if ($field['type'] == 'smg_select' && $field['multiple']) {
        $value = implode(';', $field['values']);
      } else {
        $value = $field['values'][0];
      }
      $contact[trim($field['leadworks_id'])][] = [
        'name' => $field['name'],
        'value' => $value,
        'prepend' => $field['prepend'],
      ];
    }
    elseif ($field['type'] == 'smg_grid') {
      foreach ($field['option_leadworks_ids'] as $q => $id) {
        // If checkbox grid then it will be an array
        if(is_array($field['values'][$q])) {
          $checked_values = [];
          // Get all the checked values. If not checked the value will be 0.
          foreach($field['values'][$q] as $question => $value) {
            if($value !== 0) {
              $checked_values[] = $question;
            }
          }
          $contact[trim($id)][] = [
            'name' => $field['name'],
            'value' => implode(";",$checked_values),
            'prepend' => $field['prepend'],
          ];
        }
        // radio grid
        else {
          $contact[trim($id)][] = [
            'name' => $field['name'],
            'value' => $field['values'][$q],
            'prepend' => $field['prepend'],
          ];
        }
      }
    }
    elseif ($field['type'] == 'smg_password'){
      $password = ($field['values'][0] !== 'Not applicable') ? $field['values'][0] : NULL;
    }
    // Map Autocomplete Address components to Leadworks fields.
    elseif ($field['type'] == 'smg_auto_address') {
      if (isset($field['leadworks_address1_id']) && !empty($field['values']['address_line_1'])) {
        $contact[trim($field['leadworks_address1_id'])][] = [
          'name' => $field['name'],
          'value' => $field['values']['address_line_1'],
          'prepend' => $field['prepend'],
        ];
      }
      if (isset($field['leadworks_address2_id']) && !empty($field['values']['address_line_2'])) {
        $contact[trim($field['leadworks_address2_id'])][] = [
          'name' => $field['name'],
          'value' => $field['values']['address_line_2'],
          'prepend' => $field['prepend'],
        ];
      }
      if (isset($field['leadworks_city_id']) && !empty($field['values']['address_city'])) {
        $contact[trim($field['leadworks_city_id'])][] = [
          'name' => $field['name'],
          'value' => $field['values']['address_city'],
          'prepend' => $field['prepend'],
        ];
      }
      if (isset($field['leadworks_state_id']) && !empty($field['values']['address_state'])) {
        $contact[trim($field['leadworks_state_id'])][] = [
          'name' => $field['name'],
          'value' =>$field['values']['address_state'],
          'prepend' => $field['prepend'],
        ];
      }
      if (isset($field['leadworks_zip_id']) && !empty($field['values']['address_zip'])) {
        $contact[trim($field['leadworks_zip_id'])][] = [
          'name' => $field['name'],
          'value' => $field['values']['address_zip'],
          'prepend' => $field['prepend'],
        ];
      }
    }
  }

  $contact = playbook_fields_concatenate($contact);

  // email is the unique key for leads, so it is mandatory
  if (empty($contact['email'])) {
    return false;
  }
  else {
    if (is_array($contact['email']) && array_key_exists('value', $contact['email'])) {
      $email = $contact['email']['value'];
    }
    else {
      $email = $contact['email'];
    }
    $email = rawurlencode(trim($email));
  }

  // Build out the cURL-ready questions string
  $field_string = '';

  foreach ($contact as $field_id => $value) {
    if ($field_id == 'email') continue;
    if (trim($value)) {
      $field_string .= "&$field_id=" . rawurlencode(trim($value));
    }
  }

  $master_campaign_id = ((is_array($master_campaign_id))) ? $master_campaign_id : [$master_campaign_id];
  /// The master campaign ID and each sponsor ID are posted individually
  foreach (array_merge($master_campaign_id, $sponsor_ids) as $campaign_id) {
    // Assemble a URL string with GET values for sending data to Leadworks
    $post_fields = "email={$email}&cid={$campaign_id}{$field_string}";
    $ch = curl_init(LEADWORKS_BASE_URL);

    // If the initialization fails, log the error and move on to the next campaign
    if ($ch === FALSE) {
      watchdog('playbook_fields', 'cURL initialization failed. The full cURL string which would have been posted: %curl', ['%curl' => $ch], WATCHDOG_ERROR);
      continue;
    }

    curl_setopt($ch, CURLOPT_RETURNTRANSFER, TRUE);
    curl_setopt($ch, CURLOPT_TIMEOUT, 4);
    curl_setopt($ch, CURLOPT_POST, TRUE); //do an HTTP POST
    curl_setopt($ch, CURLOPT_POSTFIELDS, $post_fields);
    // Log any failed posts with enough data to recover manually, but don't stop
    // execution
    if (curl_exec($ch) === FALSE) {
      watchdog('playbook_fields', 'Data failed to post to the Leadworks campaign with ID %id. The cURL call failed. The full query string which failed to post: %post', ['%id' => $campaign_id, '%post' => $post_fields], WATCHDOG_ERROR);
    }

    curl_close($ch);

    // Wait for 300ms between submissions as per the AccelWorks recommendation.
    // For details: http://dev.summitpublish.com/ticket/763
    usleep(600000);
  }

  if($password){
    // Just in case we have source removing it
    $field_data = $contact;
    // Just in case we have source or email removing it
    if(isset($field_data['source'])) {
      unset($field_data['source']);
    }
    if(isset($field_data['email'])) {
      unset($field_data['email']);
    }

    playbook_fields_leadworks_password_post($contact['email'], $password, json_encode($field_data));
  }

  return TRUE;
}

/**
 * Posts data to the App User table in Leadworks
 *
 * @param string $email
 *  the user email address
 * @param string $password
 *  the password needed to log into the app
 * @param string $field_data
 *  the JSON string of all the field data
 */
function playbook_fields_leadworks_password_post($email, $password, $field_data){
  $post_fields = [
    'email' => $email,
    'password' => $password,
    'field_data' => $field_data,
  ];
  $post_fields_http_query = http_build_query($post_fields);

  $ch = curl_init();
  curl_setopt($ch, CURLOPT_URL, LEADWORKS_APP_USER_POST);
  curl_setopt($ch, CURLOPT_POST, 1);
  curl_setopt($ch, CURLOPT_POSTFIELDS, $post_fields_http_query);
  curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1);
  $output = curl_exec($ch);
  curl_close($ch);
}

/**
 * Checks the App User table in Leadworks to see if there is a record
 * for the provided email
 */
function playbook_fields_leadworks_password_request($email){

  $get_array = ['email' => $email];
  $get_http = '?' . http_build_query($get_array);

  $ch = curl_init();
  curl_setopt($ch, CURLOPT_URL, LEADWORKS_APP_USER_GET . $get_http);
  curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1);
  $response = curl_exec($ch);
  curl_close($ch);

  $decoded_response = json_decode($response);

  return $decoded_response;
}
