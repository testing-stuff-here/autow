<?php

/**
 * @file
 * Some rules conditions/actions to check for completeness. 
 */
 
/**
 * Implements hook_rules_condition_info().
 * 
 * @ingroup rules
 * @see content_complete_completeness_percentage_form
 */
function content_complete_rules_condition_info() {
  return array(
    'content_complete_completeness_percentage' => array(
      'label' => t('Node completeness is more than the given value'),
      'base' => 'rules_condition_content_complete_completeness_percentage',
      'parameter' => array(
        'node' => array('type' => 'node', 'label' => t('Content')),
        'percentage' => array(
          'type' => 'integer',
          'label' => t('More than'),
          'description' => t('Example: 100, so this condition will pass if the node is 100% completed.'),
        ),
      ),
      'group' => t('Node'),
    ),
  );
}

/**
 * Rules Condition - Content Complete % is >= than
 * 
 * @param $node
 *   The node for which the condition is checked.
 * @param $percentage
 *   The completeness percentage to compare with
 * 
 * @see content_complete_rules_condition_info
 * 
 * @return TRUE or FALSE
 */
function rules_condition_content_complete_completeness_percentage($node, $percentage) {
  $data = content_complete_get_data($node);
  return $data['percent'] >= $percentage;
}