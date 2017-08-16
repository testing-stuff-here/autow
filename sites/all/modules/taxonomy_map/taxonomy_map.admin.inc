<?php

/**
 * @file
 * Contains all form manipulations required by Taxonomy Map
 */

/**
 * Form that holds all the taxonomy term mappings
 */
function taxonomy_map_mapping_form($form, &$form_state) {
  $taxonomy_options = taxonomy_map_get_all_taxonomy_form_options();

  $form = array('#tree' => TRUE);
  $items = array();

  if (empty($form_state['input']['old_items'])) {
    $items = taxonomy_map_load_mapping();
  }
  else {
    $items = $form_state['input']['old_items'];
  }

  foreach ($items as $item) {
    $form['old_items'][$item['id']]['id'] = array(
      '#type' => 'hidden',
      '#value' => $item['id'],
    );
    $form['old_items'][$item['id']]['tid'] = array(
      '#type' => 'select',
      '#options' => $taxonomy_options,
      '#default_value' => $item['tid'],
    );
    $form['old_items'][$item['id']]['path'] = array(
      '#type' => 'textfield',
      '#default_value' => $item['path'],
      '#size' => 50,
      '#maxlength' => 255,
    );
    $form['old_items'][$item['id']]['mapped_tid'] = array(
      '#type' => 'select',
      '#options' => $taxonomy_options,
      '#default_value' => $item['mapped_tid'],
    );
    $form['old_items'][$item['id']]['delete'] = array(
      '#markup' => l(t('delete'), 'admin/config/user-interface/taxonomy-map/properties/delete/' . $item['id']),
    );
  }

  $form['new_item']['tid'] = array(
    '#type' => 'select',
    '#options' => $taxonomy_options,
  );
  $form['new_item']['path'] = array(
    '#type' => 'textfield',
    '#default_value' => '',
    '#size' => 50,
    '#maxlength' => 255,
  );
  $form['new_item']['mapped_tid'] = array(
    '#type' => 'select',
    '#options' => $taxonomy_options,
  );

  $form['buttons']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save configuration'),
  );

  return $form;
}

/**
 * Form validation for taxonomy_map_mapping_form
 */
function taxonomy_map_mapping_form_validate(&$form, $form_state) {
  $values = $form_state['values'];
  $msg = array(
    'illegal_mapping' => t('You cannot have a mapping for both TAXONOMY and PATH. Please set selected TAXONOMY term to blank(first item) or remove the PATH value!'),
    'missing_mapping' => t('Please select a MAPPED TAXONOMY TERM!'),
    'same_mapping' => t('TAXONOMY cannot be the same as  MAPPED TAXONOMY TERM!'),
    'vocab' => t('VOCABULARY was chosen. Please select taxonomy term'),
    'path' => t('Invalid Path. Please insert a valid path!'),
  );

  if (!empty($values['old_items'])) {
    foreach ($values['old_items'] as $key => $value) {
      if ($value['tid'] !== '0' && $value['path'] != '') {
        form_set_error('old_items][' . $key . '][tid', $msg['illegal_mapping']);
        form_set_error('old_items][' . $key . '][path');
      }
      if ($value['mapped_tid'] === '0') {
        form_set_error('old_items][' . $key . '][mapped_tid', $msg['illegal_mapping']);
      }
      if ($value['tid'] == $value['mapped_tid']) {
        form_set_error('old_items][' . $key . '][mapped_tid', $msg['same_mapping']);
      }
      if (!is_numeric($value['tid'])) {
        form_set_error('old_items][' . $key . '][tid', $msg['vocab']);
      }
      if (!is_numeric($value['mapped_tid'])) {
        form_set_error('old_items][' . $key . '][mapped_tid', $msg['vocab']);
      }
      if ($value['tid'] === '0' && !drupal_valid_path($value['path'])) {
        form_set_error('old_items][' . $key . '][path', $msg['path']);
      }
    }
  }
  if (!empty($values['new_item'])) {
    if ($values['new_item']['tid'] !== '0' &&
       $values['new_item']['path'] !== '' &&
       $values['new_item']['mapped_tid'] !== '0') {
      if ($values['new_item']['tid'] != '0' && $values['new_item']['path'] != '') {
        form_set_error('new_item][tid', $msg['illegal_mapping']);
        form_set_error('new_item][path');
      }
      if ($values['new_item']['mapped_tid'] === '0') {
        form_set_error('new_item][mapped_tid', $msg['illegal_mapping']);
      }
      if ($values['new_item']['tid'] == $values['new_item']['mapped_tid']) {
        form_set_error('new_item][mapped_tid', $msg['same_mapping']);
      }
      if(!is_numeric($values['new_item']['tid'])) {
        form_set_error('new_item][tid', $msg['vocab']);
      }
      if (!is_numeric($values['new_item']['mapped_tid'])) {
        form_set_error('new_item][mapped_tid', $msg['vocab']);
      }
      if ($values['new_item']['path'] != '' && !drupal_valid_path($value['path'])) {
        form_set_error('new_item][path', $msg['path']);
      }
    }
  }
}

/**
 * Form submission handler for taxonomy_map_mapping_form().
 */
function taxonomy_map_mapping_form_submit($form, &$form_state) {
  if (!empty($form_state['values']['old_items'])) {
    foreach ($form_state['values']['old_items'] as $id => $item) {
      $item['id'] = $id;
      taxonomy_map_set_mapping($item);
    }
  }
  if ($form_state['values']['new_item']['mapped_tid'] !== '0') {
    $item = $form_state['values']['new_item'];
    taxonomy_map_set_mapping($item);
  }

  cache_clear_all('*', 'cache_page', TRUE);

  drupal_set_message(check_plain(t('Configuration has been saved!')));
}

/**
 * Themes taxonomy_map_mapping_form()
 */
function theme_taxonomy_map_mapping_form($variables) {
  $form = $variables['form'];
  $output = '';

  // Theme Old Items table
  $rows = array();

  if (!empty($form['old_items'])) {
    foreach ($form['old_items'] as $key => $item) {
      if (is_numeric($key)) {
        $row = (isset($form['old_items'][$key]['#attributes']) && is_array($form['old_items'][$key]['#attributes'])) ? $form['old_items'][$key]['#attributes'] : array();
        $elements = array();
        $elements[] = array('data' => drupal_render($form['old_items'][$key]['tid']));
        $elements[] = array('data' => drupal_render($form['old_items'][$key]['path']));
        $elements[] = array('data' => drupal_render($form['old_items'][$key]['mapped_tid']));
        $elements[] = array('data' => drupal_render($form['old_items'][$key]['delete']));

        $row['id'] = 'taxonomy-map-properties-row-' . $key;
        $row['data'] = $elements;
        $rows[] = $row;
      }
    }
  }

  if (!empty($rows)) {
    $header = array(
      t('Taxonomy'),
      t('Path'),
      t('Mapped Taxonomy Term'),
      t('Operation'),
    );
    $output .= theme('table', array('header' => $header, 'rows' => $rows, 'attributes' => array('id' => 'taxonomy-map-old-item')));
  }

  // Theme New Item table
  $rows = array();
  if (!empty($form['new_item'])) {
    $row = (isset($form['new_item']['#attributes']) && is_array($form['new_item']['#attributes'])) ? $form['new_item']['#attributes'] : array();
    $elements = array();
    $elements[] = t('New Mapping:');
    $elements[] = array('data' => drupal_render($form['new_item']['tid']));
    $elements[] = array('data' => drupal_render($form['new_item']['path']));
    $elements[] = array('data' => drupal_render($form['new_item']['mapped_tid']));
    $row['data'] = $elements;
    $rows[] = $row;
  }

  if (!empty($rows)) {
    $header = array(
      '',
      t('Taxonomy'),
      t('Path'),
      t('Mapped Taxonomy Term'),
    );
    $output .= theme('table', array('header' => $header, 'rows' => $rows, 'attributes' => array('id' => 'taxonomy-map-new-item')));
  }

  $output .= drupal_render_children($form);

  return $output;
}
