<?php
/**
 * @file
 * awbs_menus.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function awbs_menus_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-awbs-navigation.
  $menus['menu-awbs-navigation'] = array(
    'menu_name' => 'menu-awbs-navigation',
    'title' => 'AW Bootstrap Navigation',
    'description' => '',
  );
  // Exported menu: menu-mobile-main-menu.
  $menus['menu-mobile-main-menu'] = array(
    'menu_name' => 'menu-mobile-main-menu',
    'title' => 'Mobile Main Menu',
    'description' => '',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('AW Bootstrap Navigation');
  t('Mobile Main Menu');


  return $menus;
}
