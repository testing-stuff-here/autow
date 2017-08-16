<?php
/**
 * @file
 * playbook.features.inc
 */

/**
 * Implementation of hook_node_info().
 */
function playbook_node_info() {
  $items = array(
    'playbook' => array(
      'name' => t('Playbook'),
      'base' => 'node_content',
      'description' => t('Summit Media Group playbook'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
