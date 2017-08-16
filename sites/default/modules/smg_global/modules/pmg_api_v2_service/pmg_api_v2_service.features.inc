<?php
/**
 * @file
 * pmg_api_v2_service.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function pmg_api_v2_service_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "services" && $api == "services") {
    return array("version" => "3");
  }
}
