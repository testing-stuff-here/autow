<?php
/**
 * @file
 * Feeds parser class for YouTube.
 */

/**
 * Class definition for YouTube Parser.
 *
 * Parses YouTube API v3 requests header.
 */
class FeedsYoutubeParser extends FeedsParser {

  /**
   * Parse the extra mapping sources provided by this parser.
   *
   * @param $fetcher_result FeedsFetcherResult
   * @param $source FeedsSource
   *
   * @see FeedsParser::parse()
   */
  public function parse(FeedsSource $source, FeedsFetcherResult $fetcher_result) {
    $libraries = libraries_load('google-api-php-client');

    $url = $source->config['FeedsHTTPFetcher']['source'];
    $parsed_url = parse_url($url);
    $url_path = ltrim($parsed_url["path"], "/");
    $path_parts = explode("/", $url_path);
    $api_type = $path_parts[2];

    $result = new FeedsParserResult();  

    $client = feeds_youtube_googleapi_youtube_client_factory();
    $youtube = new Google_Service_YouTube($client);

    if ($client->getAccessToken()) {
      $api_request_result = drupal_http_request($url);
      $search_response = json_decode($api_request_result->data, true);

      $video_results = array();

      foreach ($search_response['items'] as $search_result) {
        switch ($api_type) {
          case 'search':
            $videoId = $search_result['id']['videoId'];
            break;
          case 'playlistItems':
            $videoId = $search_result['snippet']['resourceId']['videoId'];
            break;
        }
        array_push($video_results, $videoId);
      }

      $video_ids = join(',', $video_results);

      $part = "contentDetails,id,snippet";

      if ($this->config['authenticated_on_channel']) {
        $part .= ",fileDetails,player,statistics,status,topicDetails";
      }

      try {
        $videos_response = $youtube->videos->listVideos($part, array(
          'id' => $video_ids,
        ));
      } catch (Exception $ex) {
        if(strpos($ex->getMessage(), 'Forbidden') > -1) {
          drupal_set_message(t('It seems you don\'t have access to read/view the results, please configure you feed importer !admin_link', array('!admin_link' => l('configure', "admin/structure/feeds/{$source->id}/settings/FeedsYoutubeParser"))), 'error');
        }
      }

      if (!empty($videos_response['items'])) {
        $result = $this->parseVideoItems($videos_response, $source, $fetcher_result);
      }
    }
    else {
      throw new Exception(t('FeedsYoutubeParser: Unauthorized token.'));
    }
    return $result;
  }

  /**
   * Add the extra mapping sources provided by this parser.
   */
  public function getMappingSources() {
    $mapping = array(
      'feed_title' => array(
        'name' => t('Feed title'),
        'description' => t('The title of the pulled feed.'),
      ),
      'guid' => array(
        'name' => t('GUID'),
      ),
      'video_id' => array(
        'name' => t('Video ID'),
        'description' => t('YouTube video unique ID.'),
      ),
      'title' => array(
        'name' => t('Video title'),
        'description' => t('Video title.'),
      ),
      'published_datetime' => array(
        'name' => t('Published on (Datetime)'),
      ),
      'published_timestamp' => array(
        'name' => t('Published on (Timestamp)'),
      ),
      'description' => array(
        'name' => t('Description'),
      ),
      'thumbnail_default' => array(
        'name' => t('Thumbnail (default)'),
        'description' => t('URL to default thumbnail of the video.'),
      ),
      'thumbnail_medium' => array(
        'name' => t('Thumbnail (medium)'),
        'description' => t('URL to medium size thumbnail of the video.'),
      ),
      'thumbnail_high' => array(
        'name' => t('Thumbnail (high)'),
        'description' => t('URL of the thumbnail of the video.'),
      ),
      'thumbnail_standard' => array(
        'name' => t('Thumbnail'),
        'description' => t('URL to high res thumbnail of the video.'),
      ),
      'category' => array(
        'name' => t('Category'),
      ),
      'tags' => array(
        'name' => t('Tags'),
        'description' => t('This can be imported directly with Taxonomy "tags" vocabularies.'),
      ),
      'video_url' => array(
        'name' => t('Video URL'),
        'description' => t('The URL of the video.'),
      ),
      'duration' => array(
        'name' => t('Duration (Formatted)'),
        'description' => t('Duration of the video in HH:MM:SS format.'),
      ),
      'duration_raw' => array(
        'name' => t('Duration (Seconds)'),
        'description' => t('Duration of the video in number of seconds.'),
      ),
    );
    
    $private = array(
      'embedded_player' => array(
        'name' => t('Embed Player'),
        'description' => t('Embed Player HTML code.'),
      ),
      'fav_count' => array(
        'name' => t('Favorite count'),
      ),
      'view_count' => array(
        'name' => t('View count'),
      ),
      'likes' => array(
        'name' => t('Number of likes'),
      ),
      'dislikes' => array(
        'name' => t('Number of dislikes'),
      ),
    );
    if (isset($this->config['authenticated_on_channel']) && 
      $this->config['authenticated_on_channel'] != 0) {
      $mapping += $private;
    }
    return parent::getMappingSources() + $mapping;
  }

  /**
   *  Convert youtube video duration to time interval.
   *
   *  @param $duration
   *    Youtube API V3 vdieo duration.
   */
  public function youTubeTimetoDuration($duration) {
    $di = new DateInterval($duration);
    $string = '';
    if ($di->h > 0) {
      $string .= $di->h . ':';
    }
    return $string . $di->i . ':' . $di->s;
  }

  /**
   * Parse YouTube video feed.
   *
   * @param Google_Service_YouTube_VideoListResponse $video_items
   * @param FeedsFetcherResult $fetcher_result
   * @param FeedsSource $source
   */
  private function parseVideoItems(Google_Service_YouTube_VideoListResponse $video_items, FeedsSource $source, FeedsFetcherResult $fetcher_result) {
    $fetcher_result->title = 'test';
    $result = new FeedsParserResult();

    foreach ($video_items->items as $key => $video) {
      $feed_title = $video['snippet']['title'];
      $id = $video->id;
      $video_url = 'http://www.youtube.com/watch?v=' . $video->id;
      $thumbnail_default = $video['snippet']['thumbnails']->default->url;
      $thumbnail_medium = $video['snippet']['thumbnails']->medium->url;
      $thumbnail_high = $video['snippet']['thumbnails']->high->url;
      $thumbnail_standard = $video['snippet']['thumbnails']->standard->url;
      $description = $video['snippet']['description'];
      $categoryId = $video['snippet']['categoryId'];
      $duration = $video['contentDetails']['duration'];
      $tags = implode(', ', $video['snippet']['tags']);
      $published = $video['snippet']->publishedAt;

      $item = array(
        'feed_title' => $feed_title,
        'video_id' => $id,
        'video_url' => $video_url,
        'title' => $feed_title,
        'description' => $description,
        'thumbnail_default' => $thumbnail_default,
        'thumbnail_medium' => $thumbnail_medium,
        'thumbnail_high' => $thumbnail_high,
        'thumbnail_standard' => $thumbnail_standard,
        'category' => $categoryId,
        'tags' => $tags,
        'duration' => $this->youTubeTimetoDuration($duration),
        'duration_raw' => $duration,
        'published_datetime' => date('Y-m-d H:i:s', strtotime($published)),
        'published_timestamp' => strtotime($published),
      );
      
      if (isset($this->config['authenticated_on_channel']) && 
        $this->config['authenticated_on_channel']) {

        $viewCount = $video['statistics']['viewCount'];
        $favCount = $video['statistics']['favoriteCount'];
        $likes = $video['statistics']['likeCount'];
        $dislikes = $video['statistics']['dislikeCount'];
        $embed = $video['player']->embedHtml;

        $item += array(
          'view_count' => $viewCount,
          'fav_count' => $favCount,
          'likes' => $likes,
          'dislikes' => $dislikes,
          'embedded_player' => $embed,
        );
      }

      $result->items[] = $item;
    }

    return $result;
  }

  
  /**
   * Define default configuration.
   */
  public function configDefaults() {
    return array(
      'authenticated_on_channel' => 0,
    );
  }
  
  /**
   * Build configuration form.
   */
  public function configForm(&$form_state) {
    $form = array();
    $form['authenticated_on_channel'] = array(
      '#type' => 'checkbox',
      '#title' => t('Authenticated on channel'),
      '#description' => t('If the channel you\'re retrieving data from, is owned by you or you\'re admin on it, opt in this option. You can Authenticate your access on youtube using "Authenticate Google API Account" tab.'),
      '#default_value' => isset($this->config['authenticated_on_channel']) ? $this->config['authenticated_on_channel'] : 0,
    );
    return $form;
  }
}
