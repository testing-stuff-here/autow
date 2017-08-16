<?php
/**
 * @file
 * pmg_api_v2_service.services.inc
 */

/**
 * Implements hook_default_services_endpoint().
 */
function pmg_api_v2_service_default_services_endpoint() {
  $export = array();

  $endpoint = new stdClass();
  $endpoint->disabled = FALSE; /* Edit this to true to make a default endpoint disabled initially */
  $endpoint->api_version = 3;
  $endpoint->name = 'api_v2';
  $endpoint->server = 'rest_server';
  $endpoint->path = 'api/v2';
  $endpoint->authentication = array(
    'services' => 'services',
  );
  $endpoint->server_settings = array();
  $endpoint->resources = array(
    'file' => array(
      'operations' => array(
        'create' => array(
          'enabled' => '1',
        ),
        'retrieve' => array(
          'enabled' => '1',
        ),
        'delete' => array(
          'enabled' => '1',
        ),
        'index' => array(
          'enabled' => '1',
        ),
      ),
      'actions' => array(
        'create_raw' => array(
          'enabled' => '1',
        ),
      ),
    ),
    'node' => array(
      'operations' => array(
        'retrieve' => array(
          'enabled' => '1',
        ),
        'update' => array(
          'enabled' => '1',
        ),
        'delete' => array(
          'enabled' => '1',
        ),
        'index' => array(
          'enabled' => '1',
        ),
      ),
      'relationships' => array(
        'files' => array(
          'enabled' => '1',
        ),
        'comments' => array(
          'enabled' => '1',
        ),
      ),
      'targeted_actions' => array(
        'attach_file' => array(
          'enabled' => '1',
        ),
      ),
    ),
    'node_uuid_search' => array(
      'operations' => array(
        'retrieve' => array(
          'enabled' => '1',
        ),
      ),
    ),
    'pmg_sync' => array(
      'actions' => array(
        'post' => array(
          'enabled' => '1',
        ),
      ),
    ),
    'user' => array(
      'operations' => array(
        'retrieve' => array(
          'enabled' => '1',
        ),
        'update' => array(
          'enabled' => '1',
        ),
        'delete' => array(
          'enabled' => '1',
        ),
        'index' => array(
          'enabled' => '1',
        ),
      ),
      'actions' => array(
        'login' => array(
          'enabled' => '1',
        ),
        'logout' => array(
          'enabled' => '1',
        ),
        'token' => array(
          'enabled' => '1',
        ),
        'request_new_password' => array(
          'enabled' => '1',
        ),
        'register' => array(
          'enabled' => '1',
        ),
      ),
      'targeted_actions' => array(
        'cancel' => array(
          'enabled' => '1',
        ),
        'password_reset' => array(
          'enabled' => '1',
        ),
        'resend_welcome_email' => array(
          'enabled' => '1',
        ),
      ),
    ),
  );
  $endpoint->debug = 0;
  $export['api_v2'] = $endpoint;

  return $export;
}
