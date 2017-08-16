<?php

/**
 * @file
 * Contains configuration for smgRelated module
 */
 
/**
 * Form for configuring the smgRelated Module
 */
function smgRelated_admin_settings_form($form, &$form_state) {
  $vocabs_raw = taxonomy_get_vocabularies();
  $vocabs[0] = '';
  foreach ($vocabs_raw as $vid => $vocab) {
    $vocabs[$vid] = check_plain($vocab->name);
  }
  $terms = smgRelated_get_for_taxonomy(variable_get('smgRelated_source_type'));
  $selected_vocab = isset($form_state['values']['smgRelated_source_type']) ? $form_state['values']['smgRelated_source_type'] : variable_get('smgRelated_source_type');
  
  $form['smgRelated_config'] = array(
    '#type'        => 'fieldset',
    '#title'       => t('Configuration'),
    '#description' => ('Configuration for the Related Block'),
  );
  
  $form['smgRelated_config']['smgRelated_term_count'] = array(
    '#type'          => 'textfield',
    '#title'         => 'Amount of Terms to Display',
    '#description'   => 'Sets the amount of terms to be displayed at one time in the Related Article Block',
    '#default_value' => variable_get('smgRelated_term_count', 3),
  );
  
  $form['smgRelated_config']['smgRelated_node_count'] = array(
    '#type'          => 'textfield',
    '#title'         => 'Amount of Nodes to Display',
    '#description'   => 'Sets the amount of nodes to be displayed per related taxonomy',
    '#default_value' => variable_get('smgRelated_node_count', 3), 
  );
  
  $form['smgRelated_config']['smgRelated_video_default'] = array(
    '#type'          => 'textfield',
    '#title'         => 'Amount of Videos to Display if no matching taxonomies',
    '#description'   => 'Sets the amount of videos to be displayed if there aren\'t anyt matching taxonomies',
    '#default_value' => variable_get('smgRelated_video_default', 6), 
  );
  
  $form['smgRelated_config']['smgRelated_on_sponsored'] = array(
    '#type'          => 'checkbox',
    '#title'         => 'Already Sponsored Nodes',
    '#description'   => 'Check if you like to display Sponsored articles on already sponsored nodes!',
    '#default_value' => variable_get('smgRelated_on_sponsored', FALSE), 
  );
  
  $form['taxonomy'] = array(
    '#type'        => 'fieldset',
    '#title'       => t('Taxonomy'),
    '#description' => ('Taxonomy Configuration'),
  );
  
  $form['taxonomy']['smgRelated_source_type'] = array(
    '#type'           => 'select',
    '#title'          => t('Source Type Vocabulary'),
    '#description'    => t('Choose which vocabulary should be used as the source type.'),
    '#options'        => $vocabs,
    '#default_value'  => $selected_vocab,
    '#ajax'           => array(
      'callback'      => 'smgRelated_source_type_callback',
      'wrapper'       => 'smgRelated-source-type',
    )
  );
  
  $form['taxonomy']['smgRelate_sponsored_terms'] = array(
    '#type'          => 'select',
    '#title'         => t('Source Type Terms'),
    '#multiple'      => TRUE,
    '#description'   => t('Choose which terms will be used as Sponsored Content'),
    '#prefix'        => '<div id="smgRelated-source-type">',
    '#suffix'        => '</div>',
    '#options'       => smgRelated_get_for_taxonomy($selected_vocab),
    '#default_value' => variable_get('smgRelate_sponsored_terms'),
  );
  
  $form['taxonomy']['smgRelate_exclude_vocab'] = array(
    '#type'          => 'select',
    '#title'         => t('Exclude Vocabularies'),
    '#multiple'      => TRUE,
    '#description'   => t('Choose which vocabulary terms should be excluded.'),
    '#options'       => $vocabs,
    '#default_value' => variable_get('smgRelate_exclude_vocab', ''),
  );
  
  return system_settings_form($form);
}

/**
 * Callback for displaying the terms
 */
function smgRelated_source_type_callback($form, $form_state) {
  if($form_state['values']['smgRelated_source_type']) {
    variable_set('smgRelated_source_type', $form_state['values']['smgRelated_source_type']);
  }
  
  return $form['taxonomy']['smgRelate_sponsored_terms'];
}