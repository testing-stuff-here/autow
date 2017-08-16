<?php
/**
 * @file
 * feature_360_gallery.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function feature_360_gallery_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = '360_gallery';
  $context->description = 'Remove the sidebar for all content type of 360° Package Spin & Rotate';
  $context->tag = 'theme';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        '360_package_spin_rotate' => '360_package_spin_rotate',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'region' => array(
      'aw960' => array(
        'disable' => array(
          'sidebar_second' => 'sidebar_second',
          'header_top' => 0,
          'header_block' => 0,
          'menu_bar' => 0,
          'content_top' => 0,
          'content' => 0,
          'footer' => 0,
          'footer_bottom' => 0,
          'footer_links' => 0,
          'dashboard_main' => 0,
          'dashboard_sidebar' => 0,
          'dashboard_inactive' => 0,
        ),
      ),
      'om' => array(
        'disable' => array(
          'header_block' => 0,
          'menu_bar' => 0,
          'highlighted' => 0,
          'sidebar_first' => 0,
          'sidebar_second' => 0,
          'content' => 0,
          'footer' => 0,
          'dashboard_main' => 0,
          'dashboard_sidebar' => 0,
          'dashboard_inactive' => 0,
        ),
      ),
      'seven' => array(
        'disable' => array(
          'content' => 0,
          'help' => 0,
          'page_top' => 0,
          'page_bottom' => 0,
          'sidebar_first' => 0,
          'dashboard_main' => 0,
          'dashboard_sidebar' => 0,
          'dashboard_inactive' => 0,
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Remove the sidebar for all content type of 360° Package Spin & Rotate');
  t('theme');
  $export['360_gallery'] = $context;

  return $export;
}
