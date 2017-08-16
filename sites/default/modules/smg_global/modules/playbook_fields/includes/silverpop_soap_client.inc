<?php

require_once(drupal_get_path('module', 'playbook_fields') . '/includes/constants.inc');
require_once(drupal_get_path('module', 'playbook_fields') . '/includes/silverpop_column.inc');
require_once(drupal_get_path('module', 'playbook_fields') . '/includes/silverpop_addrecipient.inc');
require_once(drupal_get_path('module', 'playbook_fields') . '/includes/silverpop_selectrecipient.inc');
require_once(drupal_get_path('module', 'playbook_fields') . '/includes/silverpop_addcontacttoprogram.inc');

class SilverpopSoapClient {
  private $client = NULL;
  private $sessionid = NULL;
  private $file_path = NULL;
  private $job_id = NULL;

  public function __construct() {
    //Login right when the object is created
    $this->login();
  }

  /**
    * Function for logging into SilverPop API
    */
  private function login() {
    $this->client = new SoapClient(SP_WSDL, array(
      "trace" => TRUE,
      'cache_wsdl' => WSDL_CACHE_NONE,
      'soap_version' => SOAP_1_1,
    ));

    try {
      $result = $this->client->Login(array('USERNAME'=> SP_USERNAME, 'PASSWORD'=> SP_PASSWORD));
      if($result->SUCCESS == FALSE) {
        watchdog('playbook_fields', 'Silverpop Client login failed. login(USERNAME:%username PASSWORD:%password) FaultString: %faultstring ErrorID: %faultcode', array('%username' => SP_USERNAME, '%password' => SP_PASSWORD, '%faultstring' => $result->Fault->FaultString, '%faultcode' => $result->Fault->FaultCode), WATCHDOG_ERROR);
      } else {
        $this->sessionid = $result->SESSIONID;
      }
    } catch (SoapFault $fault) {
      // *** Log Error
      //$this->log->log(array('login()', 'Failed Soap Call',$file_path));
      //TODO watchdog
    }
  }

  /**
    * Function for logging out of Silverpop API
    */
  public function logOut() {
    try {
      $headerbody = array('sessionid' => $this->sessionid);
      $header = new SOAPHeader('SilverpopApi:EngageService.SessionHeader', 'sessionHeader', $headerbody);
      $this->client->__setSoapHeaders($header);

      $result = $this->client->Logout();
    } catch (SoapFault $fault) {
      // *** Log Error
      //$this->log->log(array('logOut()', 'Failed Soap Call',$file_path));
      //TODO watchdog
    }
  }

  /**
    * Add a contact to Summit Media Group Audience Database
    */
  public function addContact($contact, $visitor_key = '') {
    $columns = array();

    $sync_fields = new stdClass();
    $sync_fields->SYNC_FIELD = new stdClass();
    $sync_fields->SYNC_FIELD->NAME = new SoapVar("EMAIL", XSD_STRING, '', '', 'NAME', SP_XSD);
    foreach ($contact as $name => $value) {
      $columns[] = new SilverpopColumn($name, $value);
      if (strtolower($name) == "email") {
        $sync_fields->SYNC_FIELD->VALUE = new SoapVar($value, XSD_STRING, '', '', 'VALUE', SP_XSD);
      }
    }

    //$visitor_key = isset($_COOKIE['com.silverpop.iMAWebCookie']) ? $_COOKIE['com.silverpop.iMAWebCookie'] : '';
    $recipient = new AddRecipientRequestType(DATABASE_ID, SP_OPT_IN, $columns, $visitor_key, false, true, true, $sync_fields);
    
    try {
      $headerbody = array('sessionid' => $this->sessionid);
      $header = new SOAPHeader('SilverpopApi:EngageService.SessionHeader', 'sessionHeader', $headerbody);
      $this->client->__setSoapHeaders($header);
      $response = $this->client->AddRecipient($recipient);
      
      // Save to playbook_fields_silverpop_api_tracking      
      $submission_data = &drupal_static('spop_submission_data');
      $submission_data = $this->client->__getLastRequest();
      $submission_id = &drupal_static('submission_id');
      $date = date('m/d/Y');
      $return = db_insert('playbook_fields_silverpop_api_tracking')
        ->fields(array('timestamp' => $date, 'submission_id' => $submission_id, 'submission_data' => $submission_data))
        ->execute();      

      //mail('jsalisbury@summitmediagroup.com','testytest',$this->client->__getLastRequest());
      return $response;
    } catch (SoapFault $fault) {
      $request = $this->client->__getLastRequest();
      $error = $fault->getMessage();
      watchdog('SilverpopSoapError', 'SummitMediaGroupAudienceDatabase request error. Reqest : <br/>  @request <br/> Error massage: <br/> @error', array(
        '@request' => $request,
        '@error' => $error
      ), WATCHDOG_ERROR);
    }
  }

  /**
   * Helper function for addRelationalTableRecords method.
   * Prepare predefined array.
   *
   * @param (string) $brand
   * @param (string) $opt_status
   * @param (string) $subscription
   * @param (string) $email
   * @param (array) $query_param
   * @return array
   */
  private function _prepare_predefined_array($brand, $opt_status, $subscription, $email, $query_param) {
    if ($opt_status == 'Yes') {
      $arr = [
        'Brand' => $brand,
        'Opt_Status' => $opt_status,
        'OptIn_Date' => date('m/d/Y'),
        'Subscription' => $subscription,
        'Email_Address' => $email,
      ];
    }
    else {
      $arr = [
        'Brand' => $brand,
        'Opt_Status' => $opt_status,
        'OptOut_Date' => date('m/d/Y'),
        'OptOut_Mailing_ID' => !empty($query_param['spMailingID']) ? $query_param['spMailingID'] : '',
        'UTM_Medium' => !empty($query_param['utm_source']) ? $query_param['utm_source'] : '',
        'Subscription' => $subscription,
        'Email_Address' => $email,
      ];

    }
    return $arr;
  }

  /**
   * Insert record in relational table.
   *
   * @param $relational_fields (array) record that must be inserted in Relational DB.
   * @param $brand (string) brand that we specify in external_submit.inc.
   * @return mixed Silverpop responce.
   */
  public function addRelationalTableRecords($relational_fields, $brand, $query_params) {
    try {
      if (empty($relational_fields['Email'])) {
        throw new Exception('The parameter Email cannot be an empty string.');
      }
      $headerbody = array('sessionid' => $this->sessionid);
      $header = new SOAPHeader('SilverpopApi:EngageService.SessionHeader', 'sessionHeader', $headerbody);
      $this->client->__setSoapHeaders($header);
      // Check if relational fields don't have Core key for Subscription.
      if (!empty($relational_fields['Core'])) {
        $predefined_keys = $this->_prepare_predefined_array($brand, $relational_fields['Core'], 'Core', $relational_fields['Email'], $query_params);
        unset($relational_fields['Core']);
      } else {
        $predefined_keys = $this->_prepare_predefined_array($brand, 'Yes', 'Core', $relational_fields['Email'], $query_params);
      }
      // Write body for InsertUpdateRelationalTable method.
      $prefix = 'rf1';
      $xml = new \XMLWriter();
      $xml->openMemory();
      // Creates an element InsertUpdateRelationalTable.
      $xml->startElementNs($prefix, "InsertUpdateRelationalTable", SP_RTQ);
      // Creates an element TABLE_ID.
      $xml->writeElementNs($prefix, 'TABLE_ID', SP_RTQ, RELATIONAL_TABLE_ID);
      // Creates an element ROWS.
      $xml->startElementNs($prefix, "ROWS", SP_RTQ);
      // Creates an element ROW.
      $xml->startElementNs($prefix, 'ROW', SP_RTQ);
      // It writes predefined variables, first.
      foreach ($predefined_keys as $attr_key => $attr_value) {
        // Creates an element COLUMN.
        $xml->startElementNs($prefix, 'COLUMN', SP_RTQ);
        // Adds an attribute to  COLUMN element.
        $xml->writeAttribute('name', $attr_key);
        $xml->text($attr_value);
        // Closes an element COLUMN.
        $xml->endElement();

      }
      // Closes an element ROW.
      $xml->endElement();

      // Secondly, write user input to XML. Will use $predefined_keys as xml mapping.
      foreach ($relational_fields as $rel_key => $rel_value) {
        if ($rel_key == 'Email') {
          continue;
        }
        $predefined_keys = $this->_prepare_predefined_array($brand, $rel_value, $rel_key, $relational_fields['Email'], $query_params);
        // Creates an element ROW.
        $xml->startElementNs($prefix, 'ROW', SP_RTQ);
        foreach ($predefined_keys as $attr_key => $attr_value) {
          // Creates an element COLUMN.
          $xml->startElementNs($prefix, 'COLUMN', SP_RTQ);
          // Adds an attribute to  COLUMN element.
          $xml->writeAttribute('name', $attr_key);
          $xml->text($attr_value);
          // Closes an element COLUMN.
          $xml->endElement();
        }
        // Closes an element ROW.
        $xml->endElement();
      }
      // Closes an element ROWS.
      $xml->endElement();
      // Closes an element InsertUpdateRelationalTable.
      $xml->endElement();
      $body = new SoapVar($xml->outputMemory(), XSD_ANYXML);
      $result = $this->client->InsertUpdateRelationalTable($body);
      // For debug purpose. Uncomment next line if you need it.
      // $request = $this->client->__getLastRequest();
      return $result;
    } catch (Exception $e) {
      $request = $this->client->__getLastRequest();
      $error = $e->getMessage();
      watchdog('SilverpopSoapError', 'InsertUpdateRelationalTable request error. Reqest : <br/>  @request <br/> Error massage: <br/> @error', array(
        '@request' => $request,
        '@error' => $error
      ), WATCHDOG_ERROR);
    }
  }

  /**
    * Fetch a contact from Summit Media Group Audience Database
    */
  public function getContact($key) {
    $contact = array();

    $select = new SelectRecipientRequestType(DATABASE_ID, $key);

    try {
      $headerbody = array('sessionid' => $this->sessionid);
      $header = new SOAPHeader('SilverpopApi:EngageService.SessionHeader', 'sessionHeader', $headerbody);
      $this->client->__setSoapHeaders($header);
      $response = $this->client->SelectRecipientData($select);
    } catch (SoapFault $fault) {
      //TODO watchdog
      throw $fault;
    }

    if ($response->SUCCESS) {
      foreach($response->COLUMNS->COLUMN as $column) {
        $contact[$column->NAME] = $column->VALUE;
      }
      $contact['Email'] = $response->EMAIL;
      $contact['Recipient ID'] = $response->RecipientId;
    }

    return $contact;
  }

  /**
    * Add a contact to a program
    */
  public function addContactToProgram($contact_id, $program_id) {
    $request = new AddContactToProgramRequestType($contact_id, $program_id);

    try {
      $headerbody = array('sessionid' => $this->sessionid);
      $header = new SOAPHeader('SilverpopApi:EngageService.SessionHeader', 'sessionHeader', $headerbody);
      $this->client->__setSoapHeaders($header);
      $response = $this->client->AddContactToProgram($request);
    } catch (SoapFault $fault) {
      //TODO watchdog
      throw $fault;
    }
  }

  /**
    *  Function for running loops to verify that the job has been complete
    *
    * @param $jobid
    *  string - Job ID of the current job
    */
  public function checkStatus($jobid) {
    //Getting time to prevent infinite loop
    $time_limit = time() + SP_SCRIPT_TIME_LIMIT;

    $status = $this->getJobStatus($jobid);

    //If Waiting than keep looping
    while($status->JOB_STATUS == 'WAITING' && time() < $time_limit) {
      $status = $this->getJobStatus($jobid);
    }

    //If Running than keep looping
    while($status->JOB_STATUS == 'RUNNING' && time() < $time_limit) {
      $status = $this->getJobStatus($jobid);
    }


    if($time <= $time_limit && $status->JOB_STATUS == 'COMPLETE') {
      //Done!!!!
    } else {
      // *** Log Error
      //$this->log->log(array('checkStatus(' . $job_id . ')', 'Failed during status check. JOB_STATUS=' . $status->JOB_STATUS . ' $time=' . date("H:i:s", $time) . ' $time_limit=' . date("H:i:s", $time_limit),$file_path));
      //TODO watchdog
    }
  }

  /**
    * Function for getting job status
    *
    * @param $job_id
    *  string - id provided when performing a job
    */
  public function getJobStatus($job_id) {
    try {
      $result = $this->client->GetJobStatus(array('JOB_ID' => $job_id));
    } catch (SoapFault $fault) {
      // *** Log Error
      //$this->log->log(array('GetJobStatus(' . $job_id . ')', 'Failed Soap Call',$file_path));
      //TODO watchdog
    }
    return $result;
  }

  /**
   * Function for showing debug information on the browser for a good api call
   */
  public function debugPass() {
    echo "REQUEST:\n";
    echo htmlentities($this->client->__getLastRequest());
    echo "<br />";
    echo "RESPONSE:\n";
    echo htmlentities($this->client->__getLastResponse());
  }


  /**
   * Function for showing debug information on the browser for a failed api call
   */
  public function debugFail() {
    print('<pre>');
    echo "GENERAL EXCEPTION:<br />".$fault->faultcode."-".$fault->faultstring."\n<br />";

    echo "EXCEPTION:\n";
    print_r($fault);

    echo "REQUEST:\n";
    echo htmlentities($this->client->__getLastRequest());
    echo "<br />";

    echo "REQUEST HEADERS:\n";
    echo $this->client->__getLastRequestHeaders();

    echo "RESPONSE HEADERS:\n";
    echo $this->client->__getLastResponseHeaders();

    echo "RESPONSE:\n";
    echo htmlentities($this->client->__getLastResponse());

    print('</pre>');
  }

  public function __destruct()
  {
    $this->logOut();
  }
}
