<?php

/**
 * @file
 *  Contains all the configuration for SMG FTAF module
 */

/**
 * Form that handles SMG FTAF configs
 */
function smg_ftaf_admin_settings_form() {
  $form = array();
  $form['smg_ftaf_config'] = array(
    '#type' => 'fieldset',
    '#title' => t('Configuration'),
    '#collapsible' => TRUE,
  );

  $sites = array(
    'aw' => 'AW',
    'pw' => 'PW',
    'hcp' => 'HCP',
  );
  $form['smg_ftaf_config']['site'] = array(
    '#type' => 'select',
    '#title' => 'Site',
    '#options' => $sites,
    '#default_value' => variable_get('ftaf_site', 'pw'),
  );
  $form['smg_ftaf_config']['playbooks'] = array(
    '#type' => 'textarea',
    '#rows' => '10',
    '#default_value' => variable_get('ftaf_playbooks', ''),
    '#description' => 'The possible values this field can contain. Enter one value per line, in the format key|label.<br>The key is the stored value. The label will be used in displayed values and edit forms.<br>The label is optional: if a line contains a single string, it will be used as key and label.',
  );

  $form['#submit'][] = 'smg_ftaf_admin_settings_form_submit';

  return system_settings_form($form);

}

/**
 * Implements hook_form_submit()
 */
function smg_ftaf_admin_settings_form_submit($form, &$form_state) {
  variable_set('ftaf_site', $form_state['values']['site']);
  variable_set('ftaf_playbooks', $form_state['values']['playbooks']);
}