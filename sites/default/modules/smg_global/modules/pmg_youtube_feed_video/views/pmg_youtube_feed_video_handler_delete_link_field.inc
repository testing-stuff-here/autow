<?php

/**
 * @file
 * Contains a Views field handler to take care of displaying deletes links
 * as fields
 */

class pmg_youtube_feed_video_handler_delete_link_field extends pmg_youtube_feed_video_handler_link_field {
  function construct() {
    parent::construct();
    $this->additional_fields['type'] = 'type';
  }

  function render($values) {
    $type = $values->{$this->aliases['type']};

    //Creating a dummy pmg_youtube_feed video to check access against
    $dummy_pmg_youtube_feed_video = (object) array('type' => $type);
    if (!pmg_youtube_feed_video_access('edit', $dummy_pmg_youtube_feed_video)) {
      return;
    }

    $text = !empty($this->options['text']) ? $this->options['text'] : t('delete');
    $id = $values->{$this->aliases['id']};

    return l($text, 'admin/content/pmg_youtube_feed_videos/pmg_youtube_feed_video/' . $id . '/delete');
  }
}
