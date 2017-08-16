<?php
/**
 * Module settings page.
 */
function reltw_admin_settings($form, &$form_state) {
  $cache_options = drupal_map_assoc(array(0, 300, 600, 900, 1800, 3600, 7200, 21600, 43200, 86400, 604800, 1209600, 2419200, 4838400, 9676800, 31536000),  'format_interval');
  $cache_options[0] = t('Never');

  $form['reltw_cache_options'] = array(
    '#type' => 'select',
    '#title' => t('Cache Options'),
    '#default_value' => variable_get('reltw_cache_options', 3600),
    '#options' => $cache_options,
    '#required' => FALSE,
  );

  $form['reltw_clear_cache'] = array(
    '#type' => 'checkbox',
    '#title' => t('Clear Cache'),
    '#description' => t('Clear reltw Block Cache'),
  );
  
  $form['reltw_block_instance'] = array(
    '#type' => 'select',
    '#title' => t('Number of blocks to create'),
		'#default_value' => variable_get('reltw_block_instance', 0),
		'#options' => array(0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20),
  );
  
  if (module_exists('devel')) {
    $form['reltw_debug'] = array(
      '#type' => 'checkbox',
      '#title' => t('Debug'),
      '#description' => t('Enable display of queries'),
      '#default_value' => variable_get('reltw_debug', false),
    );
  }

  $form['#submit'][] = 'reltw_admin_settings_submit';
  return system_settings_form($form);
}


function reltw_admin_settings_submit($form, &$form_state) {
  if ($form_state['values']['reltw_clear_cache']) {
    cache_clear_all('*', 'cache_reltw', TRUE);
    drupal_set_message(t('reltw Block Cache is now cleared'));
  }

	variable_set('reltw_block_instance', (int)$form_state['values']['reltw_block_instance']);
	variable_set('reltw_debug', (int)$form_state['values']['reltw_debug']);
}