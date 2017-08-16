<?php
/**
 * @file
 * download_node_type_view.features.inc
 */

/**
 * Implementation of hook_views_api().
 */
function download_node_type_view_views_api() {
  list($module, $api) = func_get_args();
  if ($module == "views" && $api == "views_default") {
    return array("version" => "3.0");
  }
}
