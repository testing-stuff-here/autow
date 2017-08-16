<?php
include 'ArrayToXml.php';

class EngagePod {

  /**
   * Current version of the library
   *
   * Uses semantic versioning (http://semver.org/)
   *
   * @const string VERSION
   */
  const VERSION = '0.0.2';
  const TAB_DELIMITED_FORMAT = 2;

  private $_baseUrl;
  private $_session_encoding;
  private $_jsessionid;
  private $_username;
  private $_password;

  /**
   * Constructor
   *
   * Sets $this->_baseUrl based on the engage server specified in config
   */
  public function __construct($config, $login = TRUE)
  {
    // It would be a good thing to cache the jsessionid somewhere and reuse it across multiple requests
    // otherwise we are authenticating to the server once for every request
    $this->_baseUrl = 'http://api' . $config['engage_server'] . '.silverpop.com/XMLAPI';
    if($login) {
      $this->_login($config['username'], $config['password']);
    }
  }

  /**
   * Deconstructor
   */
  public function __destruct()
  {
    $this->_logout();
  }

  /**
   * Fetches the contents of a list
   *
   * $listType can be one of:
   *
   * 0 - Databases
   * 1 - Queries
   * 2 - Both Databases and Queries
   * 5 - Test Lists
   * 6 - Seed Lists
   * 13 - Suppression Lists
   * 15 - Relational Tables
   * 18 - Contact Lists
   *
   */
  public function getLists($listType = 2, $isPrivate = true, $folder = null)
  {
    $data["Envelope"] = array(
      "Body" => array(
        "GetLists" => array(
          "VISIBILITY" => ($isPrivate ? '0' : '1'),
          "FOLDER_ID" => $folder,
          "LIST_TYPE" => $listType,
          ),
        ),
      );
    $response = $this->_request($data);
    $result = $response["Envelope"]["Body"]["RESULT"];
    if ($this->_isSuccess($result)) {
      if (isset($result['LIST']))
        return $result['LIST'];
      else {
        return array(); //?
      }
    }
    else {
      throw new Exception("GetLists Error: ".$this->_getErrorFromResponse($response));
    }
  }

  /**
   * Get mailing templates
   *
   */
  public function getMailingTemplates($isPrivate = true)
  {
    $data["Envelope"] = array(
      "Body" => array(
        "GetMailingTemplates" => array(
          "VISIBILITY" => ($isPrivate ? '0' : '1'),
        ),
      ),
    );
    $response = $this->_request($data);
    $result = $response["Envelope"]["Body"]["RESULT"];
    if($this->_isSuccess($result)) {
      if(isset($result['MAILING_TEMPLATE']))
        return $result['MAILING_TEMPLATE'];
      else {
        return array(); //
      }
    }
    else {
      throw new Exception("GetLists Error: ".$this->_getErrorFromResponse($response));
    }
  }

  /**
   * Calculate a query
   *
   */
  public function calculateQuery($databaseID)
  {
    $data["Envelope"] = array(
      "Body" => array(
        "CalculateQuery" => array(
          "QUERY_ID" => $databaseID,
        ),
      ),
    );
    $response = $this->_request($data);
    $result = $response["Envelope"]["Body"]["RESULT"];
    if($this->_isSuccess($result)) {
      return $result["JOB_ID"];
    }
    else {
      // Not throwing Exception because I don't want it to fail if it doesn't have to
      // throw new Exception("Silverpop says: ".$response["Envelope"]["Body"]["Fault"]["FaultString"]);
      return FALSE;
    }
  }

  /**
   * Get scheduled mailings
   *
   */
  public function getScheduledMailings()
  {
    $data['Envelope'] = array(
      'Body' => array(
        'GetSentMailingsForOrg' => array(
          'SCHEDULED' => null,
        ),
      ),
    );
    $response = $this->_request($data);
    $result = $response["Envelope"]["Body"]["RESULT"];
    if($this->_isSuccess($result)) {
        return $result;
    }
    else {
      throw new Exception("Silverpop says: ".$response["Envelope"]["Body"]["Fault"]["FaultString"]);
    }
  }

  /**
   * Get the meta information for a list
   *
   */
  public function getListMetaData($databaseID)
  {
    $data["Envelope"] = array(
      "Body" => array(
        "GetListMetaData" => array(
          "LIST_ID" => $databaseID,
        ),
      ),
    );
    $response = $this->_request($data);
    $result = $response["Envelope"]["Body"]["RESULT"];
    if($this->_isSuccess($result)) {
      return $result;
    }
    else {
      throw new Exception("Silverpop says: ".$response["Envelope"]["Body"]["Fault"]["FaultString"]);
    }
  }

  /**
   * Remove a contact
   *
   */
  public function removeContact($databaseID, $email, $customer_id)
  {
    $data["Envelope"] = array(
      "Body" => array(
        "RemoveRecipient" => array(
          "LIST_ID" => $databaseID,
          "EMAIL" => $email,
          "COLUMN" => array(array("NAME"=>"customer_id", "VALUE"=>$customer_id)),
        ),
      ),
    );
    $response = $this->_request($data);
    $result = $response["Envelope"]["Body"]["RESULT"];
    if($this->_isSuccess($result)) {
      return true;
    }
    else {
      if($response["Envelope"]["Body"]["Fault"]["FaultString"]=="Error removing recipient from list. Recipient is not a member of this list."){
        return true;
      }
      else {
        throw new Exception("Silverpop says: ".$response["Envelope"]["Body"]["Fault"]["FaultString"]);
      }
    }
  }

  /**
   * Add a contact to a list
   *
   */
  public function addContact($databaseID, $updateIfFound, $columns)
  {
    $data["Envelope"] = array(
      "Body" => array(
        "AddRecipient" => array(
          "LIST_ID" => $databaseID,
          "CREATED_FROM" => 1,         // 1 = created manually, 2 = opted in
          // "SEND_AUTOREPLY"  => 'true',
          "UPDATE_IF_FOUND" => ($updateIfFound ? 'true' : 'false'),
          "COLUMN" => array(),
        ),
      ),
    );
    foreach($columns as $name => $value) {
      $data["Envelope"]["Body"]["AddRecipient"]["COLUMN"][] = array("NAME" => $name, "VALUE" => $value);
    }
    $response = $this->_request($data);
    $result = $response["Envelope"]["Body"]["RESULT"];
    if($this->_isSuccess($result)) {
      if(isset($result['RecipientId']))
        return $result['RecipientId'];
      else {
        throw new Exception('Recipient added but no recipient ID was returned from the server.');
      }
    }
    else {
      throw new Exception("AddRecipient Error: ".$this->_getErrorFromResponse($response));
    }
  }

  public function getContact($databaseID, $key, $column = 'EMAIL')
  {
    $data["Envelope"] = array(
      "Body" => array(
        "SelectRecipientData" => array(
          "LIST_ID" => $databaseID,
          $column   => $key
        ),
      ),
    );

    $response = $this->_request($data);
    $result = $response["Envelope"]["Body"]["RESULT"];
    if($this->_isSuccess($result)) {
      if(isset($result['RecipientId']))
        return $result;
      else {
        throw new Exception('Recipient added but no recipient ID was returned from the server.');
      }
    }
    else {
      return FALSE;
    }
  }

  /**
   * Double opt in a contact
   *
   * @param  string $databaseID
   * @param  string $email
   * @throw  Exception in case of error
   * @return int recipient ID
   */
  public function doubleOptInContact($databaseID, $email)
  {
    $data["Envelope"] = array(
      "Body" => array(
        "DoubleOptInRecipient" => array(
          "LIST_ID"         => $databaseID,
          "COLUMN"          => array(
            array(
              'NAME'  => 'EMAIL',
              'VALUE' => $email,
            ),
          ),
        ),
      ),
    );

    $response = $this->_request($data);
    $result = $response["Envelope"]["Body"]["RESULT"];
    if ($this->_isSuccess($result)) {
      if (isset($result['RecipientId']))
        return $result['RecipientId'];
      else {
        throw new Exception('Recipient added but no recipient ID was returned from the server.');
      }
    }

    throw new Exception("DoubleOptInRecipient Error: ".$this->_getErrorFromResponse($response));
  }

  /**
   * Update a contact.
   *
   * @param int    $databaseID
   * @param string $oldEmail
   * @param array  $columns
   * @return int recipient ID
   */
  public function updateContact($databaseID, $oldEmail, $columns)
  {
    $data["Envelope"] = array(
      "Body" => array(
        "UpdateRecipient" => array(
          "LIST_ID"         => $databaseID,
          "OLD_EMAIL"       => $oldEmail,
          "CREATED_FROM"    => 1,        // 1 = created manually
          "COLUMN" => array(),
        ),
      ),
    );
    foreach ($columns as $name => $value) {
      $data["Envelope"]["Body"]["UpdateRecipient"]["COLUMN"][] = array("NAME" => $name, "VALUE" => $value);
    }
    $response = $this->_request($data);
    $result = $response["Envelope"]["Body"]["RESULT"];
    if($this->_isSuccess($result)) {
      if(isset($result['RecipientId']))
        return $result['RecipientId'];
      else {
        throw new Exception('Recipient added but no recipient ID was returned from the server.');
      }
    }

    throw new Exception("UpdateRecipient Error: ".$this->_getErrorFromResponse($response));
  }

  /**
   * Opt out a contact
   *
   * @param int    $databaseID
   * @param string $email
   * @param array  $columns
   * @return boolean true on success
   */
  public function optOutContact($databaseID, $email, $columns = array())
  {
    $data["Envelope"] = array(
      "Body" => array(
         "OptOutRecipient" => array(
            "LIST_ID"         => $databaseID,
            "EMAIL"           => $email,
            "COLUMN" => array(),
        ),
      ),
    );
    $columns['EMAIL'] = $email;
    foreach($columns as $name => $value) {
      $data["Envelope"]["Body"]["OptOutRecipient"]["COLUMN"][] = array("NAME" => $name, "VALUE" => $value);
    }

    $response = $this->_request($data);
    $result = $response["Envelope"]["Body"]["RESULT"];

    if ($this->_isSuccess($result)) {
      return true;
    }

    throw new Exception("OptOutRecipient Error: ".$this->_getErrorFromResponse($response));
  }

  /**
   * Create a new query
   *
   * Takes a list of criteria and creates a query from them
   *
   * @param string $queryName The name of the new query
   * @param int $parentListId List that this query is derived from
   * @param string $columnName Column that the expression will run against
   * @param string $operators Operator that will be used for the expression
   * @param string $values
   * @param bool $isPrivate
   * @return int ListID of the query that was created
   */
  public function createQuery($queryName, $parentListId, $parentFolderId, $condition, $isPrivate = true)
  {
    $data['Envelope'] = array(
      'Body' => array(
        'CreateQuery' => array(
          'QUERY_NAME' => $queryName,
          'PARENT_LIST_ID' => $parentListId,
          'PARENT_FOLDER_ID' => $parentFolderId,
          'VISIBILITY' => ($isPrivate ? '0' : '1'),
          'CRITERIA' => array(
            'TYPE' => 'editable',
            'EXPRESSION' => $condition,
          ),
        ),
      ),
    );

    $response = $this->_request($data);
    $result = $response["Envelope"]["Body"]["RESULT"];

    if($this->_isSuccess($result)) {
      if(isset($result['ListId']))
        return $result['ListId'];
      else {
        throw new Exception('Query created but no query ID was returned from the server.');
      }
    }
    else {
      throw new Exception("createQuery Error: ".$this->_getErrorFromResponse($response));
    }
  }

  /**
   * Send email
   *
   * Sends an email to the specified list_id ($targetID) using the template
   * $templateID. You can optionally include substitutions that will act on
   * the template to fill in dynamic bits of data.
   *
   * ## Example
   *
   *     $engage->sendEmail(123, 456, "Example Mailing with unique name", time() + 60, array(
   *         'SUBSTITUTIONS' => array(
   *             array(
   *                 'NAME' => 'FIELD_IN_TEMPLATE',
   *                 'VALUE' => "Dynamic value to replace in template",
   *             ),
   *         )
   *     ));
   *
   * @param int $templateID ID of template upon which to base the mailing.
   * @param int $targetID ID of database, query, or contact list to send the template-based mailing.
   * @param string $mailingName Name to assign to the generated mailing.
   * @param int $scheduledTimestamp When the mailing should be scheduled to send. This must be later than the current timestamp.
   * @param array $optionalElements An array of $key => $value, where $key can be one of SUBJECT, FROM_NAME, FROM_ADDRESS, REPLY_TO, SUBSTITUTIONS
   * @param bool $saveToSharedFolder
   * @return int $mailingID
   */
  public function sendEmail($templateID, $targetID, $mailingName, $scheduledTimestamp, $optionalElements = array(), $saveToSharedFolder = 0, $suppressionLists = array())
  {
    $data["Envelope"] = array(
      "Body" => array(
        "ScheduleMailing" => array(
          "SEND_HTML" => true,
          "SEND_TEXT" => true,
          "TEMPLATE_ID" => $templateID,
          "LIST_ID" => $targetID,
          "MAILING_NAME" => $mailingName,
          "VISIBILITY" => ($saveToSharedFolder ? '1' : '0'),
          "SCHEDULED" => date("m/d/Y h:i:s A",$scheduledTimestamp),
        ),
      ),
    );
    foreach($optionalElements as $key => $value) {
      $data["Envelope"]["Body"]["ScheduleMailing"][$key] = $value;
    }

    if(is_array($suppressionLists) && count($suppressionLists) > 0) {
      $data["Envelope"]["Body"]["ScheduleMailing"]['SUPPRESSION_LISTS']['SUPPRESSION_LIST_ID'] = $suppressionLists;
    }

    $response = $this->_request($data);
    $result = $response["Envelope"]["Body"]["RESULT"];
    if($this->_isSuccess($result)) {
      if(isset($result['MAILING_ID']))
        return $result['MAILING_ID'];
      else
        throw new Exception('Email scheduled but no mailing ID was returned from the server.');
    }
    else {
     throw new Exception("SendEmail Error: ".$this->_getErrorFromResponse($response));
    }
  }

  /**
   * Send a single transactional email
   *
   * Sends an email to the specified email address ($emailID) using the mailingId
   * of the autoresponder $mailingID. You can optionally include database keys
   * to match if multikey database is used (not for replacement).
   *
   * ## Example
   *
   *     $engage->sendMailing("someone@somedomain.com", 149482, array("COLUMNS" => array(
   *         'COLUMN' => array(
   *             array(
   *                 'Name' => 'FIELD_IN_TEMPLATE',
   *                 'Value' => "value to MATCH",
   *             ),
   *         )
   *     )));
   *
   * @param string $emailID ID of users email, must be opted in.
   * @param int $mailingID ID of template upon which to base the mailing.
   * @param array $optionalKeys additional keys to match reciepent
   * @return int $mailingID
   */
  public function sendMailing($emailID, $mailingID, $optionalKeys = array())
  {
    $data["Envelope"] = array(
      "Body" => array(
        "SendMailing" => array(
          "MailingId"         => $mailingID,
          "RecipientEmail"    => $emailID,
        ),
      ),
    );
    foreach($optionalKeys as $key => $value) {
      $data["Envelope"]["Body"]["SendMailing"][$key] = $value;
    }

    $response = $this->_request($data);
    $result = $response["Envelope"]["Body"]["RESULT"];

    if($this->_isSuccess($result)) {
      return true;
    }
    else {
      throw new Exception("SendEmail Error: ".$this->_getErrorFromResponse($response));
    }
  }

  /**
   * Import a table
   *
   * Requires a file to import and a mapping file to be in the 'upload' directory of the Engage FTP server
   *
   * Returns the data job id
   *
   */
  public function importTable($fileName, $mapFileName)
  {
    $data["Envelope"] = array(
      "Body" => array(
        "ImportTable" => array(
          "MAP_FILE" => $mapFileName,
          "SOURCE_FILE" => $fileName,
        ),
      ),
    );

    $response = $this->_request($data);
    $result = $response["Envelope"]["Body"]["RESULT"];

    if($this->_isSuccess($result)) {
      if(isset($result['JOB_ID']))
        return $result['JOB_ID'];
      else {
        throw new Exception('Import table query created but no job ID was returned from the server.');
      }
    }
    else {
      throw new Exception("importTable Error: ".$this->_getErrorFromResponse($response));
    }
  }

  /**
   * Purge a table
   *
   * Clear the contents of a table, useful before importing new content
   *
   * Returns the data job id
   *
   */
  public function purgeTable($tableName, $isPrivate = true)
  {
    $data["Envelope"] = array(
      "Body" => array(
        "PurgeTable" => array(
          "TABLE_NAME" => $tableName,
          "TABLE_VISIBILITY" => ($isPrivate ? '0' : '1'),
        ),
      ),
    );

    $response = $this->_request($data);
    $result = $response["Envelope"]["Body"]["RESULT"];

    if($this->_isSuccess($result)) {
      if(isset($result['JOB_ID']))
        return $result['JOB_ID'];
      else {
        throw new Exception('Purge table query created but no job ID was returned from the server.');
      }
    }
    else {
      throw new Exception("purgeTable Error: ".$this->_getErrorFromResponse($response));
    }
  }

  /**
   * Get a data job status
   *
   * Returns the status or throws an exception
   *
   */
  public function getJobStatus($jobId)
  {
    $data["Envelope"] = array(
      "Body" => array(
        "GetJobStatus" => array(
          "JOB_ID" => $jobId
        ),
      ),
    );

    $response = $this->_request($data);
    $result = $response["Envelope"]["Body"]["RESULT"];

    if($this->_isSuccess($result)) {
      if(isset($result['JOB_STATUS']))
        return $result;
      else {
        throw new Exception('Job status query was successful but no status was found.');
      }
    }
    else {
      throw new Exception("getJobStatus Error: ".$this->_getErrorFromResponse($response));
    }
  }

  /**
   * Start data export. The export will not actually return a file but will start the
   * export process. It will create a csv file that you will need to retrieve via
   * FTP.
   *
   * @param string $start_time
   *  start date/time in this format 06/01/2009 00:00:00
   * @param string $end_time
   *  end date/time in this format 06/01/2009 00:00:00
   * @param array $columns
   *  the column names that you want to use
   * @param int $export_format
   *   0 - CSV
   *   1 - Pipe separated file
   *   2 - Tab separated file
   *
   * @return array $result
   *  array containing JOB_ID and  FILE_PATH
   */
  public function startDataExport($start_time, $end_time, $columns = array(), $export_format = self::TAB_DELIMITED_FORMAT)
  {
    $data["Envelope"] = array(
      "Body" => array(
        "RawRecipientDataExport" => array(
          "EXPORT_FORMAT" => $export_format,
          "EVENT_DATE_START" => $start_time,
          "EVENT_DATE_END" => $end_time,
          "MOVE_TO_FTP" => TRUE,
          "CLICKS" => TRUE,
          "INCLUDE_TEST_MAILINGS" => TRUE,
        ),
      ),
    );

    if($columns) {
      foreach($columns as $column) {
        $columns_array["COLUMN"][] = array("NAME" => $column['silverpop']);
      }
      $data["Envelope"]["Body"]["RawRecipientDataExport"]["COLUMNS"] = $columns_array;
    }
    $response = $this->_request($data);
    $result = $response["Envelope"]["Body"]["RESULT"];

    if($this->_isSuccess($result)) {
      if(isset($result['MAILING']['JOB_ID']))
        return $result;
      else {
        throw new Exception('Failed to start exporting results.');
      }
    }
    else {
      throw new Exception("importTable Error: ".$this->_getErrorFromResponse($response));
    }
  }

  /**
   * Call exportList command in Silverpop
   *
   * @param int $queryId
   *  the query id in Silverpop
   * @param string $export_format
   *  the following are allowed: "CSV", "TAB", or "PIPE"
   */
  public function exportList($queryId, $export_format = "TAB", $columns = array())
  {
    $data["Envelope"] = array(
      "Body" => array(
        "ExportList" => array(
          "EXPORT_TYPE" => "ALL",
          "EXPORT_FORMAT" => $export_format,
          "MOVE_TO_FTP" => TRUE,
          "LIST_ID" => $queryId,
        ),
      ),
    );

    if($columns) {
      foreach($columns as $column) {
        $columns_array[] = array("COLUMN" => $column['silverpop']);
      }
      $data["Envelope"]["Body"]["ExportList"]["EXPORT_COLUMNS"] = $columns_array;
    }

    $response = $this->_request($data);
    $result = $response["Envelope"]["Body"]["RESULT"];

    if($this->_isSuccess($result)) {
      if(isset($result['JOB_ID']))
        return $result;
      else {
        throw new Exception('Failed to start exporting results.');
      }
    }
    else {
      throw new Exception("importTable Error: ".$this->_getErrorFromResponse($response));
    }
  }

  /**
   * Get Aggregate Tracking Metrics for a Mailing
   *
   * @param int $mailing_id
   *  Required parameter specifying the Mailing ID
   * @param int $report_id
   *  Required parameter specifying the Report ID
   *
   * @return array $result
   *  mailing info
   */
  public function getAggregateTrackingForMailing($mailing_id, $report_id)
  {
    $data["Envelope"] = array(
      "Body" => array(
        "GetAggregateTrackingForMailing" => array(
          "MAILING_ID" => $mailing_id,
          "REPORT_ID" => $report_id,
          "PER_CLICK" => TRUE,
        ),
      ),
    );

    $response = $this->_request($data);
    $result = $response["Envelope"]["Body"]["RESULT"];
    if($this->_isSuccess($result)) {
      if(isset($result['Mailing']))
        return $result;
      else {
        throw new Exception('Recipient added but no recipient ID was returned from the server.');
      }
    }
    else {
      throw new Exception("getAggregateTrackingForMailing Error: Check Mailing ID or Report ID - ".$this->_getErrorFromResponse($response));
    }
  }

  /**
   * Convert XML to Array
   *
   * Original source from http://www.bin-co.com/php/scripts/xml2array/
   */
  public function xml2array($contents, $get_attributes=1, $priority = 'tag')
  {
    if(!$contents) return array();

    if(!function_exists('xml_parser_create')) {
      //print "'xml_parser_create()' function not found!";
      return array();
    }

    //Get the XML parser of PHP - PHP must have this module for the parser to work
    $parser = xml_parser_create('');
    xml_parser_set_option($parser, XML_OPTION_TARGET_ENCODING, "UTF-8"); # http://minutillo.com/steve/weblog/2004/6/17/php-xml-and-character-encodings-a-tale-of-sadness-rage-and-data-loss
    xml_parser_set_option($parser, XML_OPTION_CASE_FOLDING, 0);
    xml_parser_set_option($parser, XML_OPTION_SKIP_WHITE, 1);
    xml_parse_into_struct($parser, trim($contents), $xml_values);
    xml_parser_free($parser);

    if(!$xml_values) return;//Hmm...

    //Initializations
    $xml_array = array();
    $parents = array();
    $opened_tags = array();
    $arr = array();

    $current = &$xml_array; //Refference

    //Go through the tags.
    $repeated_tag_index = array();//Multiple tags with same name will be turned into an array
    foreach($xml_values as $data) {
        unset($attributes,$value);//Remove existing values, or there will be trouble

        //This command will extract these variables into the foreach scope
        // tag(string), type(string), level(int), attributes(array).
        extract($data);//We could use the array by itself, but this cooler.

        $result = array();
        $attributes_data = array();

        if(isset($value)) {
            if($priority == 'tag') $result = $value;
            else $result['value'] = $value; //Put the value in a assoc array if we are in the 'Attribute' mode
        }

        //Set the attributes too.
        if(isset($attributes) and $get_attributes) {
            foreach($attributes as $attr => $val) {
                if($priority == 'tag') $attributes_data[$attr] = $val;
                else $result['attr'][$attr] = $val; //Set all the attributes in a array called 'attr'
            }
        }

        //See tag status and do the needed.
        if($type == "open") {//The starting of the tag '<tag>'
            $parent[$level-1] = &$current;
            if(!is_array($current) or (!in_array($tag, array_keys($current)))) { //Insert New tag
                $current[$tag] = $result;
                if($attributes_data) $current[$tag. '_attr'] = $attributes_data;
                $repeated_tag_index[$tag.'_'.$level] = 1;

                $current = &$current[$tag];

            } else { //There was another element with the same tag name

                if(isset($current[$tag][0])) {//If there is a 0th element it is already an array
                    $current[$tag][$repeated_tag_index[$tag.'_'.$level]] = $result;
                    $repeated_tag_index[$tag.'_'.$level]++;
                } else {//This section will make the value an array if multiple tags with the same name appear together
                    $current[$tag] = array($current[$tag],$result);//This will combine the existing item and the new item together to make an array
                    $repeated_tag_index[$tag.'_'.$level] = 2;

                    if(isset($current[$tag.'_attr'])) { //The attribute of the last(0th) tag must be moved as well
                        $current[$tag]['0_attr'] = $current[$tag.'_attr'];
                        unset($current[$tag.'_attr']);
                    }

                }
                $last_item_index = $repeated_tag_index[$tag.'_'.$level]-1;
                $current = &$current[$tag][$last_item_index];
            }

        } elseif($type == "complete") { //Tags that ends in 1 line '<tag />'
            //See if the key is already taken.
            if(!isset($current[$tag])) { //New Key
                $current[$tag] = $result;
                $repeated_tag_index[$tag.'_'.$level] = 1;
                if($priority == 'tag' and $attributes_data) $current[$tag. '_attr'] = $attributes_data;

            } else { //If taken, put all things inside a list(array)
                if(isset($current[$tag][0]) and is_array($current[$tag])) {//If it is already an array...

                    // ...push the new element into that array.
                    $current[$tag][$repeated_tag_index[$tag.'_'.$level]] = $result;

                    if($priority == 'tag' and $get_attributes and $attributes_data) {
                        $current[$tag][$repeated_tag_index[$tag.'_'.$level] . '_attr'] = $attributes_data;
                    }
                    $repeated_tag_index[$tag.'_'.$level]++;

                } else { //If it is not an array...
                    $current[$tag] = array($current[$tag],$result); //...Make it an array using using the existing value and the new value
                    $repeated_tag_index[$tag.'_'.$level] = 1;
                    if($priority == 'tag' and $get_attributes) {
                        if(isset($current[$tag.'_attr'])) { //The attribute of the last(0th) tag must be moved as well

                            $current[$tag]['0_attr'] = $current[$tag.'_attr'];
                            unset($current[$tag.'_attr']);
                        }

                        if($attributes_data) {
                            $current[$tag][$repeated_tag_index[$tag.'_'.$level] . '_attr'] = $attributes_data;
                        }
                    }
                    $repeated_tag_index[$tag.'_'.$level]++; //0 and 1 index is already taken
                }
            }

        } elseif($type == 'close') { //End of tag '</tag>'
            $current = &$parent[$level-1];
        }
    }

    return($xml_array);
  }

  /**
   * Private method: authenticate with Silverpop
   *
   */
  private function _login($username, $password)
  {
    $data["Envelope"] = array(
      "Body" => array(
        "Login" => array(
          "USERNAME" => $username,
          "PASSWORD" => $password,
        ),
      ),
    );
    $response = $this->_request($data);
    $result = $response["Envelope"]["Body"]["RESULT"];
    if($this->_isSuccess($result)) {
      $this->_jsessionid = $result['SESSIONID'];
      $this->_session_encoding = $result['SESSION_ENCODING'];
      $this->_username = $username;
      $this->_password = $password;
    }
    else {
      throw new Exception("Login Error: ".$this->_getErrorFromResponse($response));
    }
  }

  private function _logout()
  {
    $data["Envelope"] = array(
      "Body" => array(
        "Logout" => array()));
    $response = $this->_request($data);
    $result = $response["Envelope"]["Body"]["RESULT"];
    if($this->_isSuccess($result)) {
      return TRUE;
    }
    else {
      //throw new Exception("Logout Error: ".$this->_getErrorFromResponse($response));
    }
  }

  /**
   * Private method: generate the full request url
   *
   */
  private function _getFullUrl()
  {
    return $this->_baseUrl . (isset($this->_session_encoding) ? $this->_session_encoding : '');
  }

  /**
   * Private method: make the request
   *
   */
  private function _request($data, $replace = array(), $attribs = array())
  {
    if(is_array($data)) {
      $atx = new ArrayToXML($data, $replace, $attribs);;
      $xml = $atx->getXML();
    }
    else {
      //assume raw xml otherwise, we need this because we have to build
      //  our own sometimes because assoc arrays don't support same name keys
      $xml = $data;
    }

    $fields = array(
      "jsessionid" => isset($this->_jsessionid) ? $this->_jsessionid : '',
      "xml" => $xml,
    );
    $response = $this->_httpPost($fields);
    if($response) {
      $arr = $this->xml2array($response);
      if(isset($arr["Envelope"]["Body"]["RESULT"]["SUCCESS"])) {
        return $arr;
      }
      else {
        throw new Exception("HTTP Error: Invalid data from the server");
      }
    }
    else {
      throw new Exception("HTTP request failed");
    }
  }

  /**
   * Private method: post the request to the url
   *
   */
  private function _httpPost($fields)
  {
    $fields_string = http_build_query($fields);
    //open connection
    $ch = curl_init();

    //set the url, number of POST vars, POST data
    curl_setopt($ch,CURLOPT_URL,$this->_getFullUrl());
    curl_setopt($ch,CURLOPT_POST,count($fields));
    curl_setopt($ch,CURLOPT_POSTFIELDS,$fields_string);
    curl_setopt($ch,CURLOPT_RETURNTRANSFER,true);

    //execute post
    $result = curl_exec($ch);

    //close connection
    curl_close($ch);

    return $result;
  }

  /**
   * Private method: parse an error response from Silverpop
   *
   */
  private function _getErrorFromResponse($response)
  {
    if(isset($response['Envelope']['Body']['Fault']['FaultString']) && !empty($response['Envelope']['Body']['Fault']['FaultString'])) {
      return $response['Envelope']['Body']['Fault']['FaultString'];
    }
    return 'Unknown Server Error';
  }

  /**
   * Private method: determine whether a request was successful
   *
   */
  private function _isSuccess($result)
  {
    if(isset($result['SUCCESS']) && in_array(strtolower($result["SUCCESS"]), array('true', 'success'))) {
      return true;
    }
    return false;
  }
}
