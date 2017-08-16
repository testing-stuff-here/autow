<?php
/**
 * @file
 * Class for running API calls to Services API calls.
 */

class PmgServicesApi {
  private $api_endpoint = '/api';
  private $username;
  private $password;
  private $protocol = 'https';
  private $host_name;
  private $api_uri;
  private $connected = FALSE;
  private $session_cookie;
  private $token;

  public function __construct($protocol, $host_name, $api_endpoint, $username, $password) {
    // Define target
    $this->protocol = $protocol;
    $this->host_name = $host_name;
    $this->$api_endpoint = $api_endpoint;
    $this->api_uri = $this->protocol . $this->host_name . $this->$api_endpoint . '/';
    // Automatically login
    $this->login($username, $password);
  }

  function __destruct() {
    // Automatically log out
    //$this->logout();
  }

  /**
   * Determines if the api is connected or not.
   */
  public function connected() {
    return $this->connected;
  }

  /**
   * Retrieve a node
   *
   * @param integer $id
   *   The UUID or the node id.
   *
   * @return mixed $response
   *   The response object.
   */
  public function retrieveNode($id) {
    $response = $this->request('GET', 'node/' . $id);

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


  /**
   * Attempts to create a node
   *
   * @param array $node
   *   A node array that a drupal node form would expect.
   *
   * @return mixed $response
   *   The response object.
   */
  public function createNode($node) {
    $response = $this->request('POST', 'node', $node);

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

  /**
   * Attempts to login a user.
   *
   * @param string $username
   *   Drupal username.
   * @param string $password
   *   Drupal password.
   *
   * @return boolean
   */
  private function login($username, $password) {
    if ($this->connected){
      return TRUE;
    }
    else {
      $response = $this->request('POST', 'user/login', array(
        'username' => $username,
        'password' => $password,
      ));

      if (empty($response) || empty($response->session_name) || empty($response->sessid)){
        return FALSE;
      }

      $this->connected = TRUE;
      $this->session_cookie = $response->session_name . '=' . $response->sessid;
      $this->token = $response->token;

      return TRUE;
    }
  }

  /**
   * Attempts to logout a user.
   *
   * @param string $username
   *   Drupal username.
   * @param string $password
   *   Drupal password.
   *
   * @return boolean
   */
  private function logout() {
    if (!$this->connected){
      return FALSE;
    }
    else {
      $response = $this->request('POST', 'user/logout');
      if (empty($response) ){
        return FALSE;
      }
      $this->connected = FALSE;
      $this->session_cookie = NULL;
      $this->token = NULL;

      return TRUE;
    }
  }

  /**
   * Retrieve file based on File id.
   *
   * @param integer $fid
   *  File id.
   *
   * @return mixed $response
   *   The response object.
   */
  public function retrieveFile($fid) {
    $response = $this->request('GET', "file/$fid");

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

  /**
   * Retrieve file based on File id.
   *
   * @param array $file
   *  Array holding the following indexes: filesize, filename, file, uid.
   *
   * @return mixed $response
   *   The response object.
   */
  public function createFile($uuid, $file) {
    $response = $this->request('POST', 'file/' . $uuid, $file);

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

  /**
   * Create PMG Sync Post api call.
   *
   * @param string $entity_type
   *
   * @return mixed $response
   *   The response object.
   */
  public function pmgSyncPost($entity_type, $data) {
    $response = $this->request('POST', 'pmg_sync/post/' . $entity_type, $data);

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

  /**
   * Search node by title.
   *
   * @param string $node_type
   *  The node type.
   * @param string $title
   *  The node title.
   *
   * @return mixed $response
   *   The response object.
   */
  public function pmgSyncNodeUUIDSearch($node_type, $uuid) {
    $response = $this->request('GET', 'node_uuid_search/' . urlencode($node_type) . '/' . urlencode($uuid));

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
    $service_url = $this->api_uri . $uri;

    // Set up the request.
    $curl = curl_init($service_url);
    curl_setopt($curl, CURLOPT_RETURNTRANSFER, TRUE);  // have curl_exec return the string
    if ($method == 'POST' || $method == 'PUT'){
      $json_data = json_encode($data);

      $headers = array(
        'Accept: application/json',
        'Content-Type: application/json',
        'Content-Length: ' . strlen($json_data),
      );

      if(!empty($this->token)){
        $headers[] = 'X-CSRF-Token:' . $this->token;
      }

      curl_setopt($curl, CURLOPT_HTTPHEADER, $headers);
      if ($method == 'PUT') {
        curl_setopt($curl, CURLOPT_CUSTOMREQUEST, "PUT");
      }
      else {
        curl_setopt($curl, CURLOPT_CUSTOMREQUEST, "POST");
      }

      curl_setopt($curl, CURLOPT_POSTFIELDS, $json_data);
    }
    else {
      $headers = array();

      if(!empty($this->token)){
        $headers[] = 'X-CSRF-Token:' . $this->token;
      }
      $headers[] = 'Accept: application/json';

      curl_setopt($curl, CURLOPT_HTTPHEADER, $headers);
    }
    if (!empty($this->session_cookie)){
      curl_setopt($curl, CURLOPT_COOKIE, $this->session_cookie);
    }
    // make the request
    curl_setopt($curl, CURLOPT_VERBOSE, true); // output to command line
    curl_setopt($curl, CURLOPT_SSL_VERIFYPEER, false);

    try {
      $curlResponse = new stdClass;
      $curlResponse->response = curl_exec($curl);
      $curlResponse->error = curl_error($curl);
      $curlResponse->info = curl_getinfo($curl);
    }
    catch(Exception $e) {
      return FALSE;
    }

    curl_close($curl);

    return json_decode($curlResponse->response);
  }
  /**
   * Create PMG Sync Post api call.
   *
   * @param
   * @return mixed $response
   *   The response object.
   */
  public function allUser() {
    $response = $this->request('GET', 'user?pagesize=10000&&fields=uid,name');

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
