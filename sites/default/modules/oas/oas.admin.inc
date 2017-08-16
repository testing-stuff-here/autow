<?php

/**
 * @file
 *  Contains all the configuration for OAS module
 */

/**
 * Form that handles the main oas configration
 */
function oas_admin_settings_form() {
  $form = array();
  $form['oas_config'] = array(
    '#type' => 'fieldset',
    '#title' => t('Configuration'),
    '#description' => t('Default config values'),
    '#collapsible' => TRUE,
  );

  $form['oas_config']['oas_url'] = array(
    '#type' => 'textfield',
    '#title' => 'OAS_url',
    '#default_value' => variable_get('oas_url', ''),
  );

  $form['oas_config']['oas_sitepage'] = array(
    '#type' => 'textfield',
    '#title' => 'OAS_sitepage',
    '#default_value' => variable_get('oas_sitepage', ''),
  );

  $form['oas_config']['oas_listpos'] = array(
    '#type' => 'textfield',
    '#title' => 'OAS_listpos',
    '#default_value' => variable_get('oas_listpos', OAS_DEFAULT_LISTPOS),
  );

  $form['oas_config']['oas_query'] = array(
    '#type' => 'textfield',
    '#title' => 'OAS_query',
    '#default_value' => variable_get('oas_query', ''),
  );

  $form['oas_config']['oas_target'] = array(
    '#type' => 'textfield',
    '#title' => 'OAS_target',
    '#default_value' => variable_get('oas_target', OAS_DEFAULT_TARGET),
  );

  $form['smg_survey_fieldset'] = array(
    '#type' => 'fieldset',
    '#title' => t('SMG Survey'),
  );
  
  $form['smg_survey_fieldset']['survey_interstitial_enabled'] = array(
    '#type' => 'checkbox',
    '#title' => 'Enable SMG Audience Census',
    '#default_value' => variable_get('survey_interstitial_enabled', ''),
  );

  $form['interstitial_fieldset'] = array(
    '#type' => 'fieldset',
    '#title' => t('Interstitial Settings'),
    '#collapsible' => TRUE, 
  );

  $form['interstitial_fieldset']['oas_interstitial_enabled'] = array(
 	  '#type' => 'checkbox',
 	  '#title' => 'Interstitial Ad',
 	  '#default_value' => variable_get('oas_interstitial_enabled', ''),  	
  );

  $form['interstitial_fieldset']['interstial_per_date'] = array(
    '#type' => 'fieldset',
    '#title' => t('Companies Running Interstitial'),
    '#collapsible' => TRUE, 
  );

  $companies = variable_get('oas_interstitial_companies');

  for($i=1; $i<=4; $i++) {
    $form['interstitial_fieldset']['interstial_per_date']['company_' . $i] = array(
      '#type' => 'fieldset',
      '#title' => t('Company ' . $i),
      '#collapsible' => TRUE, 
    );

    $form['interstitial_fieldset']['interstial_per_date']['company_' . $i]['oas_interstial_company_' . $i] = array(
      '#type' => 'textfield',
      '#size' => 60,
      '#title' => t('Company'),
      '#autocomplete_path' => 'node_reference/autocomplete/node/article/field_companies',
      '#default_value' => isset($companies['oas_interstial_company_' . $i]) ? $companies['oas_interstial_company_' . $i] : '',   
    );

    $form['interstitial_fieldset']['interstial_per_date']['company_' . $i]['oas_interstial_date_start_' . $i] = array(
      '#type' => 'date_popup',
      '#date_format' => 'Y-m-d H:i',
      '#title' => t('Start Date'),
      '#date_timezone' => 'America/Chicago',
      '#date_year_range' => '-3:+3',
      '#default_value' => isset($companies['oas_interstial_date_start_' . $i]) ? date('Y-m-d H:i', $companies['oas_interstial_date_start_' . $i]) : '', 
    );

    $form['interstitial_fieldset']['interstial_per_date']['company_' . $i]['oas_interstial_date_end_' . $i] = array(
      '#type' => 'date_popup',
      '#date_format' => 'Y-m-d H:i',
      '#title' => t('End Date'),
      '#date_timezone' => 'America/Chicago',
      '#date_year_range' => '-3:+3',
      '#default_value' => isset($companies['oas_interstial_date_end_' . $i]) ? date('Y-m-d H:i', $companies['oas_interstial_date_end_' . $i]) : '',
    );
  }
    
  $form['#submit'][] = 'oas_admin_settings_form_submit';

  return system_settings_form($form);

}

/**
 * Implements hook_form_validate()
 */
function oas_admin_settings_form_validate($form, &$form_state) {
  for($i = 1; $i <=4; $i++) {
    if(isset($form_state['values']['oas_interstial_company_' . $i]) && $form_state['values']['oas_interstial_company_' . $i] != '') {
      $companies['oas_interstial_company_' . $i] = $form_state['values']['oas_interstial_company_' . $i];
      $nid = _oas_get_autocomplete_nid($form_state['values']['oas_interstial_company_' . $i]);
      if(!$nid) {
        form_set_error('oas_interstial_company_' . $i, t('Must be a valid company'));
      }
    }
  }
}

/**
 * Implements hook_form_submit()
 */
function oas_admin_settings_form_submit($form, &$form_state) {
  $companies = array();
  for($i = 1; $i <=4; $i++) {
    if(isset($form_state['values']['oas_interstial_company_' . $i])) {
      $companies['oas_interstial_company_' . $i] = $form_state['values']['oas_interstial_company_' . $i];
      $nid = _oas_get_autocomplete_nid($form_state['values']['oas_interstial_company_' . $i]);
      if($nid) {
        $companies['oas_interstial_company_name_' . $i] = node_load($nid)->title;
        $companies['oas_interstial_company_path_' . $i] = drupal_lookup_path('alias', 'node/' . $nid);
      }
    }
    if(isset($form_state['values']['oas_interstial_date_start_' . $i])) {
      $companies['oas_interstial_date_start_' . $i] = strtotime($form_state['values']['oas_interstial_date_start_' . $i]);
    }
    if(isset($form_state['values']['oas_interstial_date_end_' . $i])) {
      $companies['oas_interstial_date_end_' . $i] = strtotime($form_state['values']['oas_interstial_date_end_' . $i]);
    }   
  }
  
  variable_set('oas_interstitial_companies', $companies);
  
  oas_interstitial_cron_job();   
  // Since you can turn off and on the interstitial need to clear the cache on submit
  cache_clear_all();

}