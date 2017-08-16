<?php

/**
 * @file
 * This is where the admin form for the rotating block lives
 */


/**
 * Implements hook_form().
 */
function block_rotator_form($form, &$form_state) {
  $block_array = variable_get('rotating_blocks', NULL);
  $form['block_rotator'] = array(
    '#markup' => t('This module allows users to create a block that will display a number of blocks a certain amount of the time. For example, you can choose to have one block 25% of the time and another 75% or any combination.'),
  );


  // Since there will be many trees with the same values, we need to set #tree
  // to be able to access them

  $form['#tree'] = TRUE;
  $form['blocks_fieldset'] = array(
    '#type' => 'fieldset',
    '#title' => t('Blocks included in the rotation'),

    // Wrap this up so the AJAX knows where to place the new blocks
    '#prefix' => '<div id="block-rotator-form-wrapper">',
    '#suffix' => '</div>',
  );

  $options = array();
  $blocks = _block_rehash();
  foreach ($blocks as $block) {
    $options[$block['module'] . '|' . $block['delta']] = $block['info'];
  }
  asort($options);

  if (empty($form_state['num_blocks'])) {
      $form_state['num_blocks'] = variable_get('rotating_blocks_count', 1);
  }
  // This is where the form is built on initial load and AJAX refresh
  for ($i = 0; $i < $form_state['num_blocks']; $i++) {
    if (isset($form_state['input']['blocks_fieldset']['block'][$i])) {
      $block_value = $form_state['input']['blocks_fieldset']['block'][$i]['block'];
      $percentage_value = $form_state['input']['blocks_fieldset']['block'][$i]['percentage'];
    } elseif (isset($block_array[$i]['block']) && !isset($form_state['input']['blocks_fieldset']['block'][$i])) {
      $block_value = $block_array[$i]['block'];
      $percentage_value = $block_array[$i]['percentage'];
    } else {
      $block_value = NULL;
      $percentage_value = '';
    }
    $form['blocks_fieldset']['block'][$i]['block'] = array(
      '#type' => 'select',
      '#title' => t('Block'),
      '#empty_option' => t('- None -'),
      '#value' => $block_value,
      '#options' => $options,
    );

    $form['blocks_fieldset']['block'][$i]['percentage'] = array(
      '#type' => 'textfield',
      '#title' => t('Percentage'),
      '#value' => $percentage_value,
      '#description' => t('Whole numbers only, no percent sign (%) needed.'),
    );
  }

  $form['blocks_fieldset']['add_block'] = array(
    '#type' => 'submit',
    '#value' => t('Add another block'),
    '#submit' => array('block_rotator_form_add_one'),
    '#ajax' => array(
      'callback' => 'block_rotator_add_more_callback',
      'wrapper' => 'block-rotator-form-wrapper',
    ),
  );

  if ($form_state['num_blocks'] > 1) {
    $form['blocks_fieldset']['remove_block'] = array(
      '#type' => 'submit',
      '#value' => t('Remove one'),
      '#submit' => array('block_rotator_form_remove_one'),
      '#ajax' => array(
        'callback' => 'block_rotator_add_more_callback',
        'wrapper' => 'block-rotator-form-wrapper',
      )
    );
  }

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit'),
  );
  return $form;

}

function block_rotator_add_more_callback($form, $form_state) {
  return $form['blocks_fieldset'];
}

function block_rotator_form_add_one($form, &$form_state) {
  $form_state['num_blocks']++;
  $form_state['rebuild'] = TRUE;
}

function block_rotator_form_remove_one($form, &$form_state) {
  if ($form_state['num_blocks'] > 1) {
    $form_state['num_blocks']--;
  }
  $form_state['rebuild'] = TRUE;
}

function block_rotator_form_submit($form, $form_state) {
  // Set the total to 0 before checking against percentages.
  $total = 0;
  // Save the number of blocks to a variable so that the admin page has the
  // correct number on load.
  variable_set('rotating_blocks_count', $form_state['num_blocks']);
  // Check to see if previous entries exist.
  if ($form_state['input']['blocks_fieldset']['block'][0]['percentage'] == "" || !isset($form_state['input']['blocks_fieldset']['block'])) {
    $rotating_blocks = NULL;
  } else {
    $rotating_blocks = $form_state['input']['blocks_fieldset']['block'];
  }
  // Cycle through and add the percentages together.
  foreach ($rotating_blocks as $block) {
    $total = $total + $block['percentage'];
  }
  // Check if the percentages add up to 100, and if not, send the error.
  if ($total == 100) {
    // Create an array of the blocks.
    $block_array = array();
    // Cycle through and place the block value with the percentage.
    foreach ($rotating_blocks as $block) {
      $block_array[$block['block']] = $block['percentage'];
    }
    // Call the helper function to create a base array of the selected
    // blocks.
    $full_array = create_base_rotating_block_array($block_array);

    // @TODO Decide if this would work better in a table than as variables.
    variable_set('rotating_blocks', $rotating_blocks);
    // This sets it up so the array is reset next time around.
    variable_set('rotating_block_counter', 100);
    variable_set('rotating_block_array', $full_array);
    // Give a success message if things went right, a warning if things went
    // wrong, and an error if the total didn't add up to 100%
    drupal_set_message(t('Rotating blocks saved'), 'status');
  } else if ($total == 0) {
    drupal_set_message(t('No percentages recorded'), 'warning');
  } else {
    drupal_set_message(t('Total percentage should equal 100'), 'error');
  }
}

function create_base_rotating_block_array($array) {
  $percentage_array = array();
  // Create an array of 100 items that matches the percentages of the selected
  // blocks
  foreach ($array as $key => $value) {
    for ($i = 0; $i < $value; $i++) {
      $percentage_array[] = $key;
    }
  }
  return $percentage_array;
}
