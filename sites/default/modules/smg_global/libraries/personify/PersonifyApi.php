<?php
/**
 * @file
 *  Class for Personify API calls.
 */

class PersonifyApi
{

  private $url;
  private $username;
  private $password;

  public function __construct($username, $password, $url) {
    $this->username = $username;
    $this->password = $password;
    $this->url = $url;
  }

  /**
   * Return stored procedure data.
   *
   * @param string $procedureName
   *   Stored procedure name.
   * @param string $parameterName
   *   Stored procedure parameter Name.
   * @param string $parameterValue
   *   Stored procedure value.
   * @param integer $direction
   *   The stored procedure direction.
   * @param integer $page
   *   The page you want the stored procedure to return.
   * @param integer $rowCountPerPage
   *   The amount of rows the storedProcudure will return
   *
   * @param array $data
   *   Array that contains data returned from Personify.  The result will most
   *   likely live in $data['Data']['NewDataSet']['Table'].
   */
  public function getStoredProcedure($procedureName, $parameterName, $parameterValue, $direction, $page = FALSE, $rowCountPerPage = FALSE)
  {
    $xml = <<<EOD
      <StoredProcedureRequest>
        <IsUserDefinedFunction>false</IsUserDefinedFunction>
        <StoredProcedureName>$procedureName</StoredProcedureName>
        <SPParameterList>
          <StoredProcedureParameter>
            <Name>$parameterName</Name>
            <Value>$parameterValue</Value>
            <Direction>$direction</Direction>
          </StoredProcedureParameter>
EOD;

    if ($page) {
      $xml .= <<<EOD
          <StoredProcedureParameter>
            <Name>@Page</Name>
            <Value>$page</Value>
            <Direction>$direction</Direction>
          </StoredProcedureParameter>
EOD;
    }

    if ($rowCountPerPage) {
      $xml .= <<<EOD
          <StoredProcedureParameter>
            <Name>@RowCountPerPage</Name>
            <Value>$rowCountPerPage</Value>
            <Direction>$direction</Direction>
          </StoredProcedureParameter>
EOD;
    }

    $xml .= <<<EOD
        </SPParameterList>
      </StoredProcedureRequest>
EOD;

    $data = $this->convertXMLResponseToArrray($this->curl('GetStoredProcedureDataXML', 'GET', $xml));

    return $data;
  }

  /**
   * Get Opt in data for a user.
   *
   * @param string $personifyId
   *   The identifier of the user in Personify.
   *
   * @return array $data
   *   The responose from the api.
   */
  public function getCustomerOptInOptions($personifyId)
  {
    $data = $this->curl('CusOptInOptions?$filter=MasterCustomerId+eq+\'' . $personifyId . '\'', 'GET', FALSE, 'application/json');

    return json_decode($data);
  }

  /**
   * Save Entity. If it is a new Entity it will need to be created first via
   * createEntity().
   *
   * @param string $entityName
   *  Entity name.
   * @param object $data
   *  The object you want to save.
   *
   * @return array $data
   *   The responose from the api.
   */
  public function saveEntity($entityName, $data)
  {
    $data = $this->curl('Save?EntityName=\'' . $entityName . '\'', 'POST', json_encode($data), 'application/json');

    return json_decode($data);
  }

  /**
   * Create Entity.
   *
   * @param string $entityName
   *   Entity name that you want to create.
   * @return array $data
   *   The responose from the api.
   */
  public function createEntity($entityName)
  {
    $data = $this->curl('Create?EntityName=\'' . $entityName . '\'', 'GET', FALSE, 'application/json');

    return json_decode($data);
  }

  /**
   * Php curl functionality for Personify.
   *
   * @param string $method
   *   Personify method.
   * @param string $postFields
   *   Post value.
   * @param string $contentType
   *   Header content type.
   *
   * @param string $data
   *   Curl return.
   */
  private function curl($method, $type, $postFields, $contentType = 'text/xml')
  {
    $ch = curl_init();

    curl_setopt($ch, CURLOPT_URL, $this->url . '/' . $method);

    if ($type == 'GET') {
      curl_setopt($ch, CURLOPT_HTTPGET, true);
    }
    if ($type == 'POST') {
      curl_setopt($ch, CURLOPT_POST, true);
    }
    curl_setopt($ch, CURLOPT_HTTPHEADER, array('Content-Type: ' . $contentType));
    if ($postFields) {
      curl_setopt($ch, CURLOPT_POSTFIELDS, $postFields);
    }
    curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1);
    curl_setopt($ch, CURLOPT_CONNECTTIMEOUT, 300);
    curl_setopt($ch, CURLOPT_USERPWD, $this->username . ":" . $this->password);
    curl_setopt($ch, CURLOPT_HTTPPROXYTUNNEL, 1);
    $data = curl_exec($ch);
    curl_close($ch);

    return $data;
  }

  /**
   * Convert XML response from xlm string to array.
   *
   * @param string $data
   *   Xml string.
   *
   * @param array $array_data
   *   Converted xml.
   */
  private function convertXMLResponseToArrray($data)
  {
    // Debug XML errors.
    // libxml_use_internal_errors(true);

    // Decode html characaters.
    $data = htmlspecialchars_decode($data);

    // Convert UTF-16 to UTF-8 to prevent errors.
    $data = preg_replace('/(<\?xml[^?]+?)utf-16/i', '$1utf-8', $data);

    // Convert to array.
    $array_data = json_decode(json_encode((array)simplexml_load_string($data)),1);

    // Debug XML errors.
    // $errors = libxml_get_errors();
    // if ($errors) {
    //   d($errors);
    // }

    return $array_data;
  }

}
