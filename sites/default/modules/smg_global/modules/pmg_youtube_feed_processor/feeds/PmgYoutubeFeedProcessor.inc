<?php

/**
 * @file
 * Class definition of PmgYoutubeFeedProcessor.
 */

/**
 * Creates pmg youtube feed videos from feed items.
 */
class PmgYoutubeFeedProcessor extends FeedsProcessor {
  /**
   * Define entity type.
   */
  public function entityType() {
    return 'pmg_youtube_feed_video';
  }

    /**
   * Implements parent::entityInfo().
   */
  protected function entityInfo() {
    $info = parent::entityInfo();
    $info['label plural'] = t('PMG Youtube Feed Videos');
    return $info;
  }

  /**
   * Creates a pmg_youtube_feed_video in memory and returns it.
   */
  protected function newEntity(FeedsSource $source) {
    $values = array(
      'type' => $this->bundle(),
      'author_uid' => $this->config['author'],
    );
    return pmg_youtube_feed_video_create($values);
  }

  /**
   * Loads an existing pmg youtube feed video.
   */
  protected function entityLoad(FeedsSource $source, $id) {
    return pmg_youtube_feed_video_load($id);
  }

  /**
   * Save a pmg youtube feed video.
   */
  public function entitySave($entity) {
    return pmg_youtube_feed_video_save($entity);
  }

  /**
   * Delete a series of pmg youtube feed videos.
   */
  protected function entityDeleteMultiple($ids) {
    pmg_youtube_feed_video_delete_multiple($ids);
  }

  /**
   * Override parent::configDefaults().
   */
  public function configDefaults() {
    $return = array(
      'author' => 0,
    ) + parent::configDefaults();

    return $return;
  }

  /**
   * Override parent:configForm() to add custom config FAPI elements.
   */
  public function configForm(&$form_state) {
    $form = parent::configForm($form_state);
    unset($form['input_format']);

    $author = user_load($this->config['author']);
    $form['author'] = array(
      '#type' => 'textfield',
      '#title' => t('Author'),
      '#description' => t('Select the author of the organizations to be created - leave empty to assign "anonymous".'),
      '#autocomplete_path' => 'user/autocomplete',
      '#default_value' => empty($author->name) ?  'anonymous' : check_plain($author->name),
    );

    return $form;
  }

  /**
   * Reschedule if expiry time changes.
   */
  public function configFormSubmit(&$values) {
    if ($author = user_load_by_name($values['author'])) {
      $values['author'] = $author->uid;
    }
    else {
      $values['author'] = 0;
    }
    parent::configFormSubmit($values);
  }

  /**
   * Return available mapping targets.
   */
  public function getMappingTargets() {
    $targets = array(
      'name' => array(
        'name' => t('Title'),
        'description' => t('The YouTube video title.'),
      ),
      'changed' => array(
        'name' => t('Updated'),
        'description' => t('The date the video was updated.'),
      ),
      'video_created' => array(
        'name' => t('Published'),
        'description' => t('The YouTube published date.'),
      ),
      'video_url' => array(
        'name' => t('Media URL'),
        'description' => t('Video URL'),
      ),
      'video_duration' => array(
        'name' => t('Media Duration'),
        'description' => t('Video Duration'),
      ),
      'video_id' => array(
        'name' => t('Video ID'),
        'description' => t('YouTube Video ID'),
      ),
      'video_description' => array(
        'name' => t('Video Description'),
        'description' => t('YouTube Video Description'),
      ),
      'guid' => array(
        'name' => t('GUID'),
        'description' => t('The external GUID of the comment. E. g. the feed item GUID in the case of a syndication feed. May be unique.'),
        'optional_unique' => TRUE,
      ),
    );

    self::loadMappers();
    $entity_type = $this->entityType();
    $bundle = $this->bundle();
    drupal_alter('feeds_processor_targets', $targets, $entity_type, $bundle);

    return $targets;
  }

  /**
   * Override setTargetElement to operate on a target item.
   */
  public function setTargetElement(FeedsSource $source, $target_entity, $target_element, $value) {
    switch ($target_element) {
      case 'name':
        parent::setTargetElement($source, $target_entity, $target_element, $value);
        // When setting name, also setting company nid.
        $config =  $source->getConfig();
        if (isset($config['FeedsHTTPFetcher']['company_nid'])) {
          $target_entity->node_id = $config['FeedsHTTPFetcher']['company_nid'];
        }
        break;
      case 'created':
      case 'changed':
        parent::setTargetElement($source, $target_entity, $target_element, $value);
        break;
      case 'guid':
        // Setting GUID to feeds table and also the pmg youtube feed video table
        // (magnify_id)
        parent::setTargetElement($source, $target_entity, $target_element, $value);
        $target_entity->{$target_element} = $value;
        break;
      default:
        $target_entity->{$target_element} = $value;
        break;
    }
  }
}
