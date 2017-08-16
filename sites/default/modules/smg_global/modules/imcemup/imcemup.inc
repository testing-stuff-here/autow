<?php

/**
 * Custom content.
 */
function _imcemup_imce_content(&$imce) {
  $path = drupal_get_path('module', 'imcemup') . '/';
  // Uploadify library
  drupal_add_js($path . 'uploadify/swfobject.js');
  drupal_add_js($path . 'uploadify/uploadify.js');
  // imcemup
  drupal_add_js($path . 'imcemup.js');
  drupal_add_js($path . 'library/imcemup_library.js');
  drupal_add_css($path . 'library/imcemup.css');
  // js equivalent will be imce.conf.mupset
  $imce['mupset'] = array(
    'url' => url('imcemup'),
    'path' => base_path() . $path . 'uploadify/',
    'mupnum' => $imce['mupnum'],
    'filesize' => (int) $imce['filesize'],
    'token' => md5(session_id()),
    'uid' => $imce['uid'],
  );
}

/**
 * Upload path access check
 */
function _imcemup_access() {
  global $user;
  // Load the real user
  if (empty($user->uid)) {
    if (($uid = $_POST['_uid']) && ($token = $_POST['_token'])) {
      $result = db_query('SELECT sid FROM {sessions} WHERE uid = :uid', array(':uid' => $uid));
      foreach ($result as $sess) {
        if ($token === md5($sess->sid)) {
          // Destroy session if started. Need to manually set session started state to false.
          drupal_session_started() && session_destroy() && drupal_session_started(FALSE);
          // Set new session id.
          session_id($sess->sid);
          // Make sure we have the cookie value to prevent $user being anonymous on session start.
          $_COOKIE[session_name()] = $sess->sid;
          // Set the handlers(session_destroy destroyed), start the session, load the user.
          drupal_session_initialize();
          break;
        }
      }
    }
  }
  return imce_access();
}

/**
 * Process upload
 */
function imcemup_imce($scheme = NULL) {
  $_GET['dir'] = rawurldecode($_POST['_dir']);
  $_GET['jsop'] = 'upload';
  module_load_include('inc', 'imce', 'inc/imce.page');
  return imce($scheme);
}