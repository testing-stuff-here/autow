<?php

/**
 * This field handler aggregates operations that can be done on a pmg_youtube_feed video
 * under a single field providing a more flexible way to present them in a view
 */
class pmg_youtube_feed_video_handler_pmg_youtube_feed_video_operations_field extends views_handler_field {
  function construct() {
    parent::construct();

    $this->additional_fields['id'] = 'id';
  }

  function query() {
    $this->ensure_my_table();
    $this->add_additional_fields();
  }

  function render($values) {

    $links = menu_contextual_links('pmg_youtube_feed_video', 'admin/content/pmg_youtube_feed_videos/pmg_youtube_feed_video', array($this->get_value($values, 'id')));

    if (!empty($links)) {
      return theme('links', array('links' => $links, 'attributes' => array('class' => array('links', 'inline', 'operations'))));
    }
  }
}
