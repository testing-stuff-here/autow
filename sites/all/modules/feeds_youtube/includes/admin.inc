<?php
/**
 * Implements hook_menu().
 */
function feeds_youtube_settings_from() {
  $form = array();
  $form['google_oauth_api_key'] = array(
    '#type' => 'textfield',
    '#required' => TRUE,
    '#description' => t('Google OAuth API Key'),
    '#title' => 'Google API key',
    '#length' => 50,
    '#default_value' => variable_get('google_oauth_api_key', ''),
  );
  $form['google_oauth_client_id'] = array(
    '#type' => 'textfield',
    '#required' => TRUE,
    '#description' => t('Google OAuth Client ID'),
    '#title' => 'Client ID',
    '#length' => 50,
    '#default_value' => variable_get('google_oauth_client_id', ''),
  );
  $form['google_oauth_client_secret'] = array(
    '#type' => 'textfield',
    '#required' => TRUE,
    '#description' => t('Google OAuth Client secret Key'),
    '#title' => 'Client secret Key',
    '#length' => 50,
    '#default_value' => variable_get('google_oauth_client_secret', ''),
  );
  return system_settings_form($form);
}

/**
 *  Custom menu callback to handle Google API authentication process.
 * 
 *  @return string HTML link to authenticate user on Google API.
 */
function feeds_youtube_authenticate() {
  $client = feeds_youtube_googleapi_youtube_client_factory();
  $feeds_youtube_api_settings = variable_get('feeds_youtube_api_settings', array());
  
  if (isset($_GET['code'])) {
    if (strval($feeds_youtube_api_settings['state']) !== strval($_GET['state'])) {
      die('The session state did not match.');
    }

    $client->authenticate($_GET['code']);
    $feeds_youtube_api_settings['token'] = $client->getAccessToken();
    $redirect = filter_var(url(current_path(), array('absolute' => TRUE)), FILTER_SANITIZE_URL);
    header('Location: ' . $redirect);
  }

  if ($client->getAccessToken() && !$client->isAccessTokenExpired()) {
    $client->revokeToken($feeds_youtube_api_settings['token']);
    variable_set('feeds_youtube_api_settings', $feeds_youtube_api_settings);
    drupal_set_message(t('You have successfully authenticated your website to use Google API.'));
    return l('Revoke Google API access', 'admin/structure/feeds/revoke-google-api-authentication', array('attributes' => array('class' => array('button'))));
  }

  $state = mt_rand();
  $client->setState($state);
  $feeds_youtube_api_settings['state'] = $state;
  $auth_url = $client->createAuthUrl();
  variable_set('feeds_youtube_api_settings', $feeds_youtube_api_settings);
  return l(t('Authenticate Google account'), $auth_url, array('attributes' => array('class' => array('button'))));
}

/**
 * Custom menu callback to revoke Google API access token.
 * 
 * @return string HTML link to authenticate user on Google API.
 */
function feeds_youtube_revoke_authentication() {
  $client = feeds_youtube_googleapi_youtube_client_factory();
  $feeds_youtube_api_settings = variable_get('feeds_youtube_api_settings', array());
  $client->revokeToken($feeds_youtube_api_settings['token']);
  $feeds_youtube_api_settings = array();
  variable_set('feeds_youtube_api_settings', $feeds_youtube_api_settings);
  drupal_set_message(t('Google Api Access Revoked.'));
  drupal_goto('admin/structure/feeds/google-api-authentication');
}