<?php

/**
 * Menu callback for the String Overrides module to display its administration
 */
function quantcast_admin_settings() {
  $form['quantcast_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Quantcast ID'),
    '#description' => t('The Quantcast ID associated with your <a href="@quantcast">Quantcast</a> account.', array('@quantcast' => 'http://www.quantcast.com')),
    '#default_value' => variable_get('quantcast_id', ''),
  );
  return system_settings_form($form);
}