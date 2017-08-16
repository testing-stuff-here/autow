<?php

/**
 * Function for configuring the 360 Gallery Form
 */
function three_sixty_configuration_form() {
	
	global $base_url;
	
	// Default location 
	$default_360_gallery = $base_url . '/sites/default/files/360_gallery';
	
	$form['360_gallery_folder_location'] = array(
    '#type' => 'textfield',
    '#title' => t('Folder Location URL'),
		'#size'=> 100,
    '#description' => t('The folder location of where the galleries will be stored. Ex: http://www.sitename.com/sites/default/files/folderlocation'),
    '#default_value' => variable_get('360_gallery_folder_location', $default_360_gallery),
  );
	$form['360_gallery_height'] = array(
    '#type' => 'textfield',
    '#title' => t('Iframe Height'),
		'#size'=> 10,
    '#description' => t('The height of the iframe of all the 360 Galleries. (px, %)'),
    '#default_value' => variable_get('360_gallery_height', '1200px'),
  );
	$form['360_gallery_width'] = array(
    '#type' => 'textfield',
    '#title' => t('Iframe Width'),
		'#size'=> 10,
    '#description' => t('The width of the iframe of all the 360 Galleries. (px, %)'),
    '#default_value' => variable_get('360_gallery_width', '100%'),
  );

  return system_settings_form($form);
}