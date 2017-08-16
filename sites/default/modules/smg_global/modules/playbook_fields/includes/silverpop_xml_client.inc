<?php

require_once(drupal_get_path('module', 'playbook_fields') . '/includes/constants.inc');

class SilverpopXMLClient {
  private $sessionid = NULL;

  public function __construct() {
    //Login right when the object is created
    $this->login();
  }

  /**
    * Function for logging into SilverPop API
    */
  private function login() {
    $login_xml = 'xml=' . rawurlencode('<Envelope><Body><Login><USERNAME>' . SP_USERNAME . '</USERNAME><PASSWORD>' . SP_PASSWORD . '</PASSWORD></Login></Body></Envelope>');
    $curl = curl_init(SP_XAU);
    curl_setopt($curl, CURLOPT_RETURNTRANSFER, TRUE);
    curl_setopt($curl, CURLOPT_POST, TRUE);
    curl_setopt($curl, CURLOPT_POSTFIELDS, $login_xml);
    $parser = xml_parser_create();

    try {
      $result = curl_exec($curl);
      if (xml_parse_into_struct($parser, $result, $values, $index)) {
        $success = $values[$index['SUCCESS'][0]]['value'];
      } else {
        $success = FALSE;
      }
    } catch (SoapFault $fault) {
      //TODO watchdog
    } 

    if ($success == 'true') {
      $this->sessionid = $values[$index['SESSIONID'][0]]['value'];
    }

    xml_parser_free($parser);
    curl_close($curl);
  }
  
  /**
    * Function for logging out of Silverpop API
    */   
  /*public function logOut() {
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
  }*/

  /**
    * Fetch a contact from Summit Media Group Audience Database
    */
  public function getContact($key, $column = 'EMAIL') {
    $contact = array();
    if ($column == 'EMAIL') {
      $query_xml = 'xml=' . rawurlencode("<Envelope><Body><SelectRecipientData><LIST_ID>8847490</LIST_ID><RETURN_CONTACT_LISTS>true</RETURN_CONTACT_LISTS><COLUMN><NAME>$column</NAME><VALUE>$key</VALUE></COLUMN></SelectRecipientData></Body></Envelope>");
    } else {
      $query_xml = 'xml=' . rawurlencode("<Envelope><Body><SelectRecipientData><LIST_ID>8847490</LIST_ID><ENCODED_RECIPIENT_ID>$key</ENCODED_RECIPIENT_ID></SelectRecipientData></Body></Envelope>");
    }
    $curl = curl_init(SP_XAU . ';jsessionid=' . $this->sessionid);
    curl_setopt($curl, CURLOPT_RETURNTRANSFER, TRUE);
    curl_setopt($curl, CURLOPT_POST, TRUE);
    curl_setopt($curl, CURLOPT_POSTFIELDS, $query_xml);
    $parser = xml_parser_create();

    try {
      $result = curl_exec($curl);
      if (xml_parse_into_struct($parser, $result, $values, $index)) {
        $success = $values[$index['SUCCESS'][0]]['value'];
      } else {
        $success = FALSE;
      }
    } catch (SoapFault $fault) {
      //TODO watchdog
    }

    if ($success == 'TRUE') {
      preg_match_all('#<COLUMN>[^<>]*<NAME>([^<>]*)</NAME>[^<>]*<VALUE>([^<>]*)</VALUE>[^<>]*</COLUMN>#', $result, $matches, PREG_SET_ORDER);

      foreach ($matches as $m) {
        $contact[$m[1]] = $m[2];
      }

      // Get contact lists for contact.
      preg_match_all('#<CONTACT_LIST_ID>([^<>]*)</CONTACT_LIST_ID>#', $result, $contact_lists, PREG_SET_ORDER);

      if (!empty($contact_lists)) {
        foreach ($contact_lists as $contact_list) {
          if (isset($contact['Contact Lists']) && !empty($contact['Contact Lists'])) {
            $contact['Contact Lists'] .= ',' . $contact_list[1];
          }
          else {
            $contact['Contact Lists'] = $contact_list[1];
          }
        }
      }

      $contact['Email'] = $values[$index['EMAIL'][0]]['value'];
    }

    xml_parser_free($parser);
    curl_close($curl);
    return $contact;
  }

  /**
   * Adds user to contact list
   *
   * @param string|integer $listId
   *   Silverpop contact list ID
   * @param string $email
   *   User email
   */
  public function addUserToList($listId, $email) 
  {
    $query_xml = "<?xml version=\"1.0\"?>\n<Envelope><Body><AddContactToContactList><CONTACT_LIST_ID>$listId</CONTACT_LIST_ID><COLUMN><NAME>EMAIL</NAME><VALUE>$email</VALUE></COLUMN></AddContactToContactList></Body></Envelope>";
    $curl = curl_init(SP_XAU . ';jsessionid=' . $this->sessionid);
    curl_setopt($curl, CURLOPT_RETURNTRANSFER, TRUE);
    curl_setopt($curl, CURLOPT_POST, TRUE);
    curl_setopt($curl, CURLOPT_POSTFIELDS, $query_xml);
    curl_setopt($curl, CURLINFO_HEADER_OUT, true);
    curl_setopt($curl, CURLOPT_HTTPHEADER, array('Content-Type: text/xml; charset=UTF-8', 'Content-Length: ' . strlen($query_xml)));

    $responseXML = @curl_exec($curl);

    if ($responseXML === false) {
      throw new Exception('CURL error: ' . curl_error($curl));
    }

    curl_close($curl);

    if (!trim($responseXML)) {
      throw new Exception('Empty response from Engage');
    }

    $response = @simplexml_load_string('<?xml version="1.0"?>' . $responseXML);

    if ($response === false) {
      throw new Exception('Invalid XML response from Engage');
    }

    if (!isset($response->Body)) {
      throw new Exception('Engage response has no Body');
    }

    $success = strtoupper($response->Body->RESULT->SUCCESS);
    
    if (in_array($success, array('TRUE, SUCCESS'))) {
      return true;
    }
  }
  
  /**
   * Logout a user
   */
  public function logout()
  {    
     $logout_xml = 'xml=' . rawurlencode('<Envelope><Body><Logout/></Body></Envelope>');
     $curl = curl_init(SP_XAU . ';jsessionid=' . $this->sessionid);
     curl_setopt($curl, CURLOPT_RETURNTRANSFER, TRUE);
     curl_setopt($curl, CURLOPT_POST, TRUE);
     curl_setopt($curl, CURLOPT_POSTFIELDS, $logout_xml);
     try {
       $result = curl_exec($curl);
     } catch (SoapFault $fault) {
       //TODO watchdog
     } 
     curl_close($curl);
  }
  
  public function __destruct()
  {
    $this->logout();
  }
}
