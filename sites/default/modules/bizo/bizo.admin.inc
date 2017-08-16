<?php

/**
 * Menu callback for the String Overrides module to display its administration
 */
function bizo_admin_settings() {
  $form['bizo_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Bizo ID'),
    '#description' => t('The Bizo ID associated with your <a href="@bizo">Bizo</a> account.', array('@bizo' => 'http://www.bizo.com')),
    '#default_value' => variable_get('bizo_id', ''),
  );
  return system_settings_form($form);
}