<?php
/**
 * @file
 * wir_content_type.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function wir_content_type_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: navigation_week-in-review:node/add/week-in-review
  $menu_links['navigation_week-in-review:node/add/week-in-review'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'node/add/week-in-review',
    'router_path' => 'node/add/week-in-review',
    'link_title' => 'Week in Review',
    'options' => array(
      'attributes' => array(
        'title' => 'Week in review content. ',
      ),
      'identifier' => 'navigation_week-in-review:node/add/week-in-review',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'navigation_add-content:node/add',
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Week in Review');

  return $menu_links;
}
