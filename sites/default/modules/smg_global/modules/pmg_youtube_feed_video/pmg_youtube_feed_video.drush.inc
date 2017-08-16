<?php
/**
 * @file
 * Drush commands
 */

/**
 * Implements pmg_youtube_feed_video_command().
 */
function pmg_youtube_feed_video_drush_command() {
  $items = array();
  $items['pmg-youtube-feed-video-delete'] = array(
    'description' => 'Delete Waywire Videos',
    'arguments' => array(
      'node_id' => 'Company node id that is associated to the company.',
    ),
  );
  return $items;
}

/**
 * Deletes the PMG YouTube Feed videos entities.
 *
 * @param integer $node_id
 *   The node id (company node id).
 */
function drush_pmg_youtube_feed_video_delete($node_id) {
  if (drush_confirm('This may delete all PMG YouTube Feed videos. Are you sure you want to continue?')) {
    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'pmg_youtube_feed_video');
    if ($node_id) {
      $query->propertyCondition('node_id', $node_id);
    }
    $result = $query->execute();

    if ($result['pmg_youtube_feed_video']) {
      $ids = array_keys($result['pmg_youtube_feed_video']);
      $pmg_youtube_feed_videos = pmg_youtube_feed_video_load_multiple($ids);
      foreach ($pmg_youtube_feed_videos as $pmg_youtube_feed_video) {
        echo "Deleted {$pmg_youtube_feed_video->name}\n";
        pmg_youtube_feed_video_delete($pmg_youtube_feed_video);
      }
    }
  }
}
