<?php
/**
 * @file
 * Admininstration for the PMG YouTube Feed Leadership integration
 */

/**
 * PMG YouTube Feed Setting form.
 */
function pmg_youtube_feed_leadership_settings_form() {
  $form['pmg_youtube_feed_leadership_importer_id'] = array(
    '#type'     => 'textfield',
    '#title'    => t('Feed Id'),
    '#description' => 'Enter the feed name that you will use to import PMG YouTube Feed videos.',
    '#required' => TRUE,
    '#default_value' => variable_get('pmg_youtube_feed_leadership_importer_id'),
  );
  $form['pmg_youtube_feed_leadership_youtube_api_key'] = array(
    '#type' => 'textfield',
    '#title' => t('YouTube API Key'),
    '#description' => 'Provide a YouTube API key',
    '#required' => TRUE,
    '#default_value' => variable_get('pmg_youtube_feed_leadership_youtube_api_key'),
  );
  $form['pmg_youtube_feed_leadership_widget_page_count'] = array(
    '#type' => 'textfield',
    '#title' => t('Number of Videos To Get From PMG YouTube Feed'),
    '#description' => 'Enter the most number of videos to get from PMG YouTube Feed. For example if I input 50 I will only get 50 of the latest videos from a client.',
    '#required' => TRUE,
    '#default_value' => variable_get('pmg_youtube_feed_leadership_widget_page_count'),
  );
  $form['pmg_youtube_feed_leadership_widget_datacard_count'] = array(
    '#type' => 'textfield',
    '#title' => t('Number of Videos in the Datacard'),
    '#description' => 'Enter the number of videos to be available in the datacard. This number should be double of what is initially shown.',
    '#required' => TRUE,
    '#default_value' => variable_get('pmg_youtube_feed_leadership_widget_datacard_count'),
  );
  $form['pmg_youtube_feed_leadership_widget_node_count'] = array(
    '#type' => 'textfield',
    '#title' => t('Number of Videos on the node page'),
    '#description' => 'Enter the number of videos to be available on the node page. This number should be double of what is initially shown.',
    '#required' => TRUE,
    '#default_value' => variable_get('pmg_youtube_feed_leadership_widget_node_count'),
  );

  return system_settings_form($form);
}

/**
 * YouTube username update form
 */
function pmg_youtube_feed_update_usernames() {

  $companies = pmg_youtube_feed_leadership_get_youtube_amplify_companies_from_current_session();

  drupal_add_css(".page-admin-leadership-pmg-youtube-feed-usernames .form-item.form-type-textfield {margin:0;} ", array('type' => 'inline'));

  $form['help'] = array(
    '#type' => 'markup',
    '#markup' => 'Add the company\'s YouTube username.  Optionally add the company\'s YouTube channel id and check the override box (some companies don\'t have a YouTube username).',
  );

  foreach ($companies as $company) {

    $form['companies']["{$company->nid}_data"] = array(
      '#type' => 'fieldset',
      '#attributes' => array('style' => array('padding: 0'))
    );
    $form['companies']["{$company->nid}_data"][$company->nid] = array(
      '#type' => 'textfield',
      '#title' => $company->title,
      '#attributes' => array('style' => array('margin: 0')),
      '#default_value' => $company->field_youtube_username_value,      
    );
    $form['companies']["{$company->nid}_data"]["old_waywire_tag"] = array(
      '#prefix' => "<div class='old-waywire-tag' style='padding-bottom:6px; font-style:italic;'>",
      '#suffix' => "</div>",
      '#markup' => "old waywire tag: <strong>{$company->field_waywire_tag_value}</strong>",
    );
    $form['companies']["{$company->nid}_data"]["{$company->nid}_override"] = array(
      '#type' => 'checkbox',
      '#title' => "override username with channel id",
      '#default_value' => $company->field_youtube_username_override_value,
    );
  }

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit'),
  );

  return $form;
}

function pmg_youtube_feed_update_usernames_submit($form, &$form_state) {
  
  foreach ($form_state['values'] as $nid => $value) {
    if (!array_key_exists("{$nid}_data", $form['companies'])) {
      continue;
    }

    // Get the current and old username values
    $value = (strlen($value) > 0) ? $value : NULL;
    $old_value = $form['companies']["{$nid}_data"][$nid]['#default_value'];

    // Get the current and old username override boolean values
    $override_data = $form_state['values']["{$nid}_override"];
    $override_value = (strlen($override_data) > 0) ? $override_data : NULL;
    $old_override_value = $form['companies']["{$nid}_data"]["{$nid}_override"]['#default_value'];

    if ($old_value !== $value || $override_value !== $old_override_value) {
      $company = entity_metadata_wrapper('node', node_load($nid));
      $company->field_youtube_username->set($value);
      $company->field_youtube_username_override->set($override_value);
      $company->save();
    }
  }
}

/**
 * Add the ability to get new videos and update caches json via buttons.
 */
function pmg_youtube_feed_leadership_update_dashboard() {

  $output = '<p>The following buttons can be used to update PMG YouTube Feed Videos.  Press the "Get New Videos" button to get the latest videos for all companies. Press the "Clear PMG YouTube Feed Videos Cache" to clear the cache in order for the new videos to appear right away.</p>';

  $output .= '<a href="/admin/pmg_youtube_feed_leadership/download" class="button"><input type="button" value="Get New Videos" style="background-color:transparent;"/></a>';
  $output .= '<a href="/admin/pmg_youtube_feed_leadership/clear-cache" class="button"><input type="button" value="Clear PMG YouTube Feed Videos Cache" style="background-color:transparent;"/></a>';

  return $output;
}

/**
 * @see pmg_youtube_feed_leadership_create_entities_for_all_companies().
 */
function pmg_youtube_feed_leadership_download_videos() {
  pmg_youtube_feed_leadership_create_entities_for_all_companies();
  drupal_goto('admin/pmg_youtube_feed_leadership/update');
}

/**
 * @see pmg_youtube_feed_leadership_create_json().
 */
function pmg_youtube_feed_leadership_clear_cache() {
  pmg_youtube_feed_leadership_create_json();
  drupal_goto('admin/pmg_youtube_feed_leadership/update');
}
