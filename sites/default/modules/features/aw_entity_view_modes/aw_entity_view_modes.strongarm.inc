<?php
/**
 * @file
 * aw_entity_view_modes.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function aw_entity_view_modes_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'entity_view_modes';
  $strongarm->value = array(
    'node' => array(
      'webinar_series_part' => array(
        'label' => 'Webinar Series Part',
        'custom settings' => 1,
      ),
    ),
  );
  $export['entity_view_modes'] = $strongarm;

  return $export;
}
