<?php
/**
 * @file
 * simple_lead_gen_form.features.inc
 */

/**
 * Implementation of hook_node_info().
 */
function simple_lead_gen_form_node_info() {
  $items = array(
    'simple_lead_gen_form' => array(
      'name' => t('Simple Lead Gen Form'),
      'base' => 'node_content',
      'description' => t('Summit Media Group Simple Lead-Generating Form'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
