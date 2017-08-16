<?php
/**
 * @file
 * Waywire sitemap functionality.
 */

/**
 * Returns site admin.
 */
function smg_global_waywire_video_sitemap() {
  global $language_content;
  // If sitemap is cached, lets load the cached version.
  $sitemap = &drupal_static(__FUNCTION__);
  if (!isset($sitemap)) {
    if ($cache = cache_get('cache_waywire_video_sitemap')) {
      $sitemap = $cache->data;
    }
    else {
      $sitemap = smg_global_waywire_sitemap_update_cache();
    }
  }

  drupal_add_http_header('Content-Type', 'text/xml; charset=utf-8');
  print $sitemap;
}

/**
 * Sets the sitemap into cache.
 *
 * @param string $sitemap
 *   Return xml string.
 */
function smg_global_waywire_sitemap_update_cache() {
  global $language_content;
  $xml_rows = '';
  $cach_time = 1209600; // 2 weeks.

  // Table where deckhead is stored.
  $deckhead_table_name = 'field_data_field_deckhead';
  // Column where deckhead value is stored.
  $deckhead_value = 'field_deckhead_value';

  // Get all the fields that use waywire.
  $types = array_keys(waywire_field_info());
  $fields = array();
  foreach (field_info_fields() as $field) {
    if (in_array($field['type'], $types)) {
      $fields[] = $field;
    }
  }

  // Get all the data for each video.
  foreach ($fields as $field) {
    $table_prefixes = array(
      _field_sql_storage_tablename($field),
    );

    foreach ($table_prefixes as $table_prefix) {
      $query = db_select($table_prefix, 'v');
      $query->leftJoin($deckhead_table_name, 'deck', 'deck.entity_id = v.entity_id');
      $query->addField('v', $field['field_name'] . '_video_url', 'url');
      $query->addField('v', $field['field_name'] . '_thumbnail_url', 'thumbnail');
      $query->addField('v', $field['field_name'] . '_video_duration', 'video_duration');
      $query->addField('deck', $deckhead_value, 'deckhead');
      $query->leftJoin('node', 'n', 'n.nid = v.entity_id');
      $query->addField('n', 'title');
      $query->addField('n', 'created');
      $query->addField('n', 'nid');
      $query->orderBy('v.entity_id', 'DESC');
      $videos = $query->execute()->fetchAll();

      foreach ($videos as $video) {
        $xml_rows .= smg_global_waywire_sitemap_get_row($video);
      }
    }
  }

  // Create sitemap
  $xml = '<?xml version="1.0" encoding="UTF-8"?>';
  $xml .= '<urlset xmlns="http://www.sitemaps.org/schemas/sitemap/0.9" xmlns:video="http://www.google.com/schemas/sitemap-video/1.1">';
  $xml .= $xml_rows;
  $xml .= '</urlset>';

  cache_set('cache_waywire_video_sitemap', $xml, 'cache', time() + $cach_time);

  return $xml;
}

/**
 * Returns a sitemap xml row string.
 *
 * @param object $video
 *   Video result.
 *
 * @param string $xml
 *   XML string row.
 */
function smg_global_waywire_sitemap_get_row($video) {
  $xml = '<url>';
  $xml .= '<loc>' . url(drupal_get_path_alias('node/' . $video->nid), array('absolute' => TRUE)) . '</loc>';
  $xml .= '<video:video>';
  $xml .= '<video:thumbnail_loc>' . $video->thumbnail . '</video:thumbnail_loc>';
  $xml .= '<video:title>' . smg_global_waywire_clean($video->title) . '</video:title>';
  $xml .= '<video:description>' . smg_global_waywire_clean($video->deckhead) . '</video:description>';
  $xml .= '<video:player_loc allow_embed="true">' . $video->url . '/player</video:player_loc>';
  if ($video->video_duration) {
    $xml .= '<video:duration>' . $video->video_duration . '</video:duration>';
  }
  $xml .= '<video:publication_date>' . date('Y-m-d', $video->created) . '</video:publication_date>';
  $xml .= '<video:family_friendly>yes</video:family_friendly>';
  $xml .= '</video:video>';
  $xml .= '</url>';

  return $xml;
}

/**
 * Clean values so it is safe for xml.
 *
 * @param string $value
 *   Value to be cleaned.
 *
 * @param string
 *   Cleaned value.
 */
function smg_global_waywire_clean($value) {
  return htmlspecialchars(strip_tags($value), ENT_QUOTES, 'UTF-8');
}

/**
 * Implements hook_cron().
 */
function smg_global_waywire_sitemap_cron() {
  // Run once a day at 1:00am
  if (date('G') == 1) {
    smg_global_waywire_sitemap_update_cache();
    watchdog('smg_global', 'Waywire Sitemap Has been refreshed on %time', array('%time' => date("F j, Y, g:i a")));
  }
}

/**
 * Refresh the sitemap cache.
 */
function smg_global_waywire_sitemap_refresh() {
  smg_global_waywire_sitemap_update_cache();
  watchdog('smg_global', 'Waywire Sitemap Has been refreshed on %time', array('%time' => date("F j, Y, g:i a")));
  drupal_goto('videos.xml');
}
