<?php
/**
 * @file
 * Class for running API calls to Drupal Restful Ws.
 */

class PmgRestwsApi {
  private $api_endpoint = '';
  private $username;
  private $password;
  private $protocol = 'https';
  private $host_name;
  private $api_uri;
  private $connected = FALSE;
  private $session_cookie;
  private $token;
  private $crl;

  public function __construct($protocol, $host_name, $api_endpoint, $username, $password) {
    // Define target.
    $this->protocol = $protocol;
    $this->host_name = $host_name;
    $this->api_endpoint = $api_endpoint;
    $this->api_uri = $this->protocol . $this->host_name . $this->api_endpoint;

    // Automatically login.
    $this->username = $username;
    $this->password = $password;
  }

  /**
   * Login seciton of the curl command.
   */
  private function login() {
    curl_setopt($this->crl, CURLOPT_RETURNTRANSFER, 1);
    curl_setopt($this->crl, CURLOPT_USERAGENT, 'PHP script');
    curl_setopt($this->crl, CURLOPT_COOKIEJAR, "/tmp/cookie.txt");
    curl_setopt($this->crl, CURLOPT_COOKIEFILE, '/tmp/cookie.txt');

    // Login
    curl_setopt($this->crl, CURLOPT_URL,$this->api_uri . "user/login");
    curl_setopt($this->crl, CURLOPT_POST, TRUE);
    curl_setopt($this->crl, CURLOPT_POSTFIELDS, "name=" . $this->username . "&pass=" . $this->password . "&form_id=user_login");

    $this->session_cookie = session_name() . '=' . session_id();
    curl_setopt($this->crl, CURLOPT_COOKIE, $this->session_cookie);
    $ret = new stdClass;
    $ret->response = curl_exec($this->crl);
    $ret->error = curl_error($this->crl);
    $ret->info = curl_getinfo($this->crl);

    // Get RESTWS token.
    curl_setopt($this->crl, CURLOPT_HTTPGET, TRUE);
    curl_setopt($this->crl, CURLOPT_URL, $this->api_uri . 'restws/session/token');
    $ret = new stdClass;
    $ret->response = curl_exec($this->crl);
    $ret->error = curl_error($this->crl);
    $ret->info = curl_getinfo($this->crl);
    $this->token = $ret->response;
  }

  /**
   * Makes a request.
   *
   * @param string $method
   *   Type of method: GET, POST, etc...
   * @param string $uri
   *   The uri of the api call.
   * @param array $data
   *  Data passed in.
   *
   * @return mixed
   */
  private function request($method = 'GET', $uri, $data = array()) {
    $json_data = json_encode($data);
    $this->crl = curl_init();
    $this->login();
    curl_setopt($this->crl, CURLOPT_RETURNTRANSFER, TRUE);
    if ($method == 'PUT') {
      curl_setopt($this->crl, CURLOPT_CUSTOMREQUEST, "PUT");
      curl_setopt($this->crl, CURLOPT_POST, TRUE);
    }
    elseif ($method == 'POST') {
      curl_setopt($this->crl, CURLOPT_POST, TRUE);
    }

    curl_setopt($this->crl, CURLOPT_URL, $this->api_uri . $uri);
    curl_setopt($this->crl, CURLOPT_HTTPGET, FALSE);
    curl_setopt($this->crl, CURLOPT_POSTFIELDS, $json_data);
    curl_setopt($this->crl, CURLOPT_HTTPHEADER, array('Content-Type: application/json', 'Content-Length: ' . strlen($json_data), 'X-CSRF-Token: ' . $this->token));
    curl_setopt($this->crl, CURLOPT_COOKIE, $this->session_cookie);
    curl_setopt($this->crl, CURLOPT_NOBODY, FALSE);

    $curlResponse = new stdClass;
    $curlResponse->response = curl_exec($this->crl);
    $curlResponse->error = curl_error($this->crl);
    $curlResponse->info = curl_getinfo($this->crl);
    dsm($curlResponse);

    curl_close($this->crl);
    unset($this->crl);

    return json_decode($curlResponse->response);
  }

  /**
   * Create or update node.
   *
   * @param array $node
   *   The node data you want to create or update.
   * @param integer $nodeId
   *   The node id of the node you want to update.
   *
   * @param object $response
   *   Api reply.  Create returns array while update returns empty array.
   */
  public function node($node, $nodeId = FALSE, $format = '.json') {
    if ($nodeId) {
      $response = $this->request($method = 'PUT', 'node/' . $nodeId . $format, $node);
    }
    else {
      $response = $this->request($method = 'POST', 'node' . $format, $node);
    }

    return $response;
  }

  /**
   * Retrieve file based on File id.
   *
   * @param array $file
   *  Array holding the following indexes: filesize, filename, file, uid.
   *
   * @param mixed $response
   *   The response object.
   */
  public function createFile($file) {
    $response = $this->request('POST', 'file', $file);

    if (empty($response)){
      // @TODO Create email notification.
      return FALSE;
    }

    if (isset($response->form_errors)) {
      // @TODO email notification.

      return FALSE;
    }

    return $response;
  }
}
