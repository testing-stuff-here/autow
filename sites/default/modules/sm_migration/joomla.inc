<?php
/*
Documents 
  Advance source mapping - http://drupal.org/node/1012810
	Functions available - http://drupal.org/node/1132582
	Stubs for nodereference issue - http://drupal.org/node/1013506
	
	Field mappings - http://drupal.org/node/1133448
		advance for terms and filefields but lacks doc - http://drupal.org/node/1224042
		
	Highwater mark for incremental migration - http://drupal.org/node/1223936	
	
	blog
	  - http://btmash.com/article/2011-03-25/migrating-content-part-2-nodes
	
	DB API - http://drupal.org/node/1060924
*/
class JoomlaMigration extends Migration {
	public $basicFormat;
	public $terms;
	public $pwObj;
	
  public function __construct() {
    parent::__construct();

		$this->basicFormat = filter_format_load('full_html');
		
		$this->pwObj = new PwTerms();
		
		$this->pwObj->map_drupal_terms();
		$this->pwObj->map_joomla_terms();
		
		
		//$this->dependencies = array('JoomlaTerm');

		$query = Database::getConnection('default', 'joomla')
							->select('jos_content', 'jcontent')
		         	->fields('jcontent')
							->condition('state', 1);
		$query->leftJoin('content_category_xref', 'jcat', 'jcat.content_id=jcontent.id');
		$query->addExpression('GROUP_CONCAT(DISTINCT jcat.category_id)', 'cat_list');
		$query->groupBy('jcontent.id');
		//$query->orderBy('modified');
		//$query->orderBy('id');
		$query->orderRandom();
		$query->range(0,1);
		
		$count_query = Database::getConnection('default', 'joomla')
      ->select('jos_content', 'jcontent');
    $count_query->addExpression('COUNT(id)', 'cnt');
		
	  $this->source = new MigrateSourceSQL($query, array(), $count_query);
		$this->destination = new MigrateDestinationNode('article');
		//$this->systemOfRecord = Migration::DESTINATION;
		
		$this->map = new MigrateSQLMap($this->machineName,
      array(
        'id' => array('type' => 'int',
          'unsigned' => TRUE,
          'not null' => TRUE,
					'alias' => 'jcontent',
         )
      ),
      MigrateDestinationNode::getKeySchema(),
			'joomla'
	    );
		
	
		// Basic fields
    $this->addFieldMapping('title', 'title')
				 ->callbacks(array($this, 'title_update'));
		$this->addFieldMapping('uid')
         ->defaultValue(1);

		$arguments = MigrateTextFieldHandler::arguments(array('source_field' => 'introtext'), $this->basicFormat->format);	
    $this->addFieldMapping('body', 'fulltext')
				 ->arguments($arguments);
		$this->addFieldMapping('created', 'created')
				 ->callbacks(array($this, 'field_created_update'));

		
		// CCK Fields
		$this->addFieldMapping('field_joomla_id', 'id');	
		$this->addFieldMapping('field_duplicate', 'duped')
				 ->callbacks(array($this, 'field_duplicate_update'));
		$this->addFieldMapping('field_sponsor_expiration', 'sponsored_expiration')
				 ->callbacks(array($this, 'field_sponsor_expiration_update'));
		$this->addFieldMapping('field_accela_id', 'accela_id')
				 ->callbacks(array($this, 'field_accela_id_update'));
		
		$this->addFieldMapping('field_byline', 'created_by_alias')
				 ->callbacks(array($this, 'field_byline_update'));
		$this->addFieldMapping('field_author_title', 'created_by_alias')
				 ->callbacks(array($this, 'field_author_title_update'));
		$this->addFieldMapping('field_issue_date', 'issue')
				 ->callbacks(array($this, 'field_issue_date_update'));
	
		
		// Migrate specific settings
		$this->highwaterField = array(
      'name' => 'modified',
      'alias' => 'jcontent', 
    );
		
		$this->addFieldMapping('pathauto')
         ->defaultValue(FALSE);
			

    // Unmapped destination fields
    $this->addUnmigratedDestinations(array(
			'is_new', 
			'status', 
			'promote',
      'revision', 
			'language', 
			'sticky', 
			'changed', 
			'revision_uid',
      'path'
			));
		$this->addUnmigratedSources(array(
			'created_by', 
			'title_alias',
			'metakey', // they are using taxonomies
			'metadesc', // they are using the deckhead/summary
			'access', 
			//'page', 
			'ad_conductor', 
			'comments', 
			'source_id', 
			'ad_id', 
			'email_id', 
			'Postcard_QID', 
			//'Postcard_id', 
			'modified',
			'modified_by',
			'checked_out',
			'checked_out_time',
			'publish_up',
			'publish_down',
			'version',
			'ordering',
			'hits',
			'rec_id',
			'taxonomies', 	// duplicate of the jos_categories table. but this one seems more obsolete than the new tables
			'supplier', 		// we are using the companies table
			'parentid', 		// did not find any use in the site. all values are 0
			'attribs', 			// seems like joomla specific
			'urls', 				// all empty
			'mask', 				// all 0
			'catid', 				// values are either 110 (back issues) or 0. i noticed though that if the catid=0, the sectionid=0 
											// too which means they are static pages
			'content_type', // overwrite if needed. needed in Article content type
			'remoteuri',
			), t('Do Not Migrate'));
  }

	/*
	The prepareRow() method is called by the source class next() method, after loading the data row. 
	The argument $row is a stdClass object containing the data as provided by the source. 
	*/
	public function prepareRow($row) {
	}
	
	function prepare(stdClass $account, stdClass $row) {
		$account->field_term_automation = array();
		$account->field_term_industry = array();
		
		// mark as legacy page
		$account->field_legacy['und'][0]['value'] = 1;
    
		// get the NID to force this as an update
		$query = db_select('field_data_field_joomla_id')
					 	->fields('node', array('nid', 'vid'))
					 	->condition('entity_type', 'node')
					 	->condition('deleted', '0')
						->condition('field_joomla_id_value', $row->id);
		$query->leftJoin('node', 'node', 'node.nid=field_data_field_joomla_id.entity_id AND node.vid=field_data_field_joomla_id.revision_id');
		$result = $query->execute();
		
		foreach ($result as $record) {
			$account->nid = $record->nid;
			$account->vid = $record->vid;
		}
		
		debugm('Processing Joomla ID: ' . $row->id);
		$joomla_body = $joomla_teaser = '';
		if (!empty($row->introtext)) {
      $joomla_body = $row->fulltext;
      $joomla_teaser = '';
    }
    else {
      $joomla_body = $row->fulltext;
      $joomla_teaser = ''; //text_summary($joomla_body);
    }
    
    // Deckhead added
		$account->field_deckhead['und'][0]['value'] = strip_tags($row->introtext);
		
		// prepend URL fix
		if (preg_match('/(<a href=["|\'])(www)\./', $joomla_body)) {
		  $joomla_body = preg_replace('/(<a href=["|\'])(www)\./', '$1http://www.', $joomla_body);
		  $joomla_teaser = preg_replace('/(<a href=["|\'])(www)\./', '$1http://www.', $joomla_teaser);
		}
		
		// add viddler ID - Video
		$viddler_id = '';
		if ($row->postcard_id && substr($row->postcard_id, 0, 13) == 'viddlerOuter-') {
		  $viddler_id = str_replace('viddlerOuter-', '', $row->postcard_id);
		  $account->field_viddler_id['und'][0]['value'] = $viddler_id;
		  
		  // <!--[if IE]> <!--<![endif]-->
  		$pattern = '@(<!--\[if IE\]>.*<!--<!\[endif\]-->)@';
  		if (preg_match($pattern, $joomla_body)) {
  		  $joomla_body = preg_replace($pattern, '', $joomla_body);
  		}
		}

    $joomla_body   = str_replace('{mospagebreak}', '', $joomla_body);
		$joomla_body   = str_replace('{easycomments}', '', $joomla_body);
		
		// Images
		if ($row->images) {
			$images = array();
		  $images = explode("\n", $row->images);

			$n = 0;
			foreach($images as $j_image) {
				$images_items = explode("|", $j_image);
				$joomla_img = trim($images_items[0]);

				if (!$joomla_img) continue;

				$filename = basename($joomla_img);
				$full_path = 'public://images/'.$joomla_img;

				$err = false;
				$realpath = drupal_realpath($full_path);
				if (!$realpath || !file_exists($realpath)) {
					continue;
				}

				$query = db_select('file_managed')
							 ->fields('file_managed')
							 ->condition('uri', $full_path)
							 ->execute();

				$file = null;
				foreach ($query as $file) {
					break;
				}

				if (!$file) {
					$file = new stdClass();
			    $file->fid = NULL;
			    $file->uri = $full_path;
			    $file->filename = basename($full_path);

			    $file = file_save($file);	
					file_usage_add($file, 'migrate', 'node', $file->fid);
				}

				if ($file) {
					$file->display = 1;
					
					$caption = htmldecode(str_replace('"', '\"', $images_items[4]));
  				$alt = htmldecode(str_replace('"', '\"', $images_items[2]));
  				$alt = substr($alt, 0, 128);
  				if (!$caption) {
  				  $caption = $alt;
  				}

  				$caption = substr($caption, 0, 128);
  				$file->title = $caption;
  				if ($alt) {
  				  $file->alt = $alt;
  				}
  				else {
  				  $file->alt = $caption;
  				}
					
					if ($n == 0) { 
						// main image
						$account->field_image['und'][] = (array)$file;
					}
					else { 
						// subimage
						$account->field_article_images['und'][] = (array)$file;
					}
				}

				$n++;
			}
			
      $joomla_teaser = $this->replace_mos_image($row->images, $joomla_teaser);
      $joomla_body   = $this->replace_mos_image($row->images, $joomla_body);
    }

		$joomla_teaser = $this->replace_image_link($joomla_teaser);
    $joomla_body   = $this->replace_image_link($joomla_body);

		$account->body['und'][0]['value'] = $joomla_body;
		$account->body['und'][0]['summary'] = $joomla_teaser;
		
		$account->field_sponsor_expiration = array();
		$account->field_sponsor_expiration['und'][0]['value'] = $row->sponsored_expiration;
		$this->_overrwite_empty_date_field($account, 'field_sponsor_expiration');
		
		$account->field_issue_date = array();
		$account->field_issue_date['und'][0]['value'] = $this->field_issue_date_update($row->issue);
		$this->_overrwite_empty_date_field($account, 'field_issue_date');
		
		// Adding taxonomies from our CSV file
		if ($row->cat_list) {
			$categories = explode('~', $row->cat_list);
			
			foreach($categories as $catid) {
				if (!isset($this->pwObj->terms['joomla'][$catid])) {
					continue;
				}
				
				$t1 = $this->pwObj->terms['joomla'][$catid];
				
				foreach($t1 as $t) {
					$vocab = trim(strtolower($t[0]));
					if (!$vocab) continue;
					
					$field = $this->pwObj->get_drupal_vocab_machine_name($vocab);
					if (!isset($account->{$field})) {
						$account->{$field} = array();
					}
					
					if ($t[1]) {
						$tid = $this->pwObj->find_term_tid($vocab, $t[1]);
						$parent_tid = $tid;
						$this->pwObj->migrate_assign_term($account, $vocab, $tid);
						
						if ($t[2]) {
							$tid = $this->pwObj->find_term_tid($vocab, $t[2], $parent_tid);
							$parent_tid = $tid;
							$this->pwObj->migrate_assign_term($account, $vocab, $tid);
							
							if ($t[3]) {
								if (strstr($t[3], ',')) {
									$tmp = explode(',', $t[3]);
									foreach($tmp as $_tmp) {
										$tid = $this->pwObj->find_term_tid($vocab, trim($_tmp), $parent_tid);
										$this->pwObj->migrate_assign_term($account, $vocab, $tid);
									}
								}
								else {
									$tid = $this->pwObj->find_term_tid($vocab, $t[3], $parent_tid);
									$this->pwObj->migrate_assign_term($account, $vocab, $tid);
								}
							}
						}
					}
					
				}
				
			}
		}
	}
	
	function title_update($val) {
		//return $this->_htmldecode($val);
		$title = $val;
		if (strstr($title, '&amp;#145;') || strstr($title, '&amp;#146;')) {
			$title = str_replace('&amp;#145;', '\'', $title);
			$title = str_replace('&amp;#146;', '\'', $title);
		}
		
		if (strstr($title, '&amp;#147;') || strstr($title, '&amp;#148;')) {
			$title = str_replace('&amp;#147;', '"', $title);
			$title = str_replace('&amp;#148;', '"', $title);
		}

		$newtitle = $this->_htmldecode($title);
		
		$replacements = array(
			'&quot;' => '"',
			'&amp;#39;;' => '\'',
			'&eacute;' => utf8_encode('é'),
			'&Eacute;' => utf8_encode('É'),
			'&deg;' => utf8_encode('°'),
			'&lt;' => '<',
			'&gt;' => '>',
			'&amp;' => '&',
		);
		
		foreach($replacements as $find => $replace) {
			if (strstr($newtitle, $find)) {
				$newtitle = str_replace($find, $replace, $newtitle);
				$newtitle = utf8_encode($newtitle);
			}
		}
		
		return $newtitle;
	}
	
	function _htmldecode($val) {
		$val = html_entity_decode($val, ENT_QUOTES, 'UTF-8');
		$val = preg_replace('/(&#[0-9]{2})/', '$1;', $val);

		$val = iconv("UTF-8", "ASCII//TRANSLIT", $val); 
		return htmlentities(html_entity_decode(utf8_encode($val)));
	}
	
	function field_duplicate_update($val) {
		// the duped value for duplicate in joomla is 9
		if ($val == 1) return 1;
		else return 0;
	}
	
	function field_accela_id_update($val) {
		// there are 2 values in the database, a 4-8 character numbers, a URL or NULL
		// client wants to disregard the 4-8 characters
		// I assumed that if the character count is less than 9, then it is something we want to transfer
		if (strlen($val) < 9) return '';
		else return $val;
	}
	
	function field_display_related_update($val) {
		if ($val == 'Y') return 1;
		else return 0;
	}
	
	function field_sponsor_expiration_update($val) {
		// Issue 1: there seems to be a problem with date handling
		// if i pass 0000-00-00 00:00:00 - it would prompt me an error
		// 		date_timezone_set() expects parameter 1 to be DateTime, boolean given
		// if i pass an empty string - it would provide the date today as the value
		// the solution is to unset this field in the process() to make sure it provides the default value that we
		// set in the content type
		
		// Issue 2: Joomla is using the UTC timezone. Make sure to set the Drupal's timezone to UTC
		// so it saves the correct date in the database
		if ($val == '0000-00-00 00:00:00') {
			return '1951-01-01 00:00:00';
		}
		else return $val;
	}
	
	function field_byline_update($val) {
		return $this->_get_author_info($val, 'name');
	}
	
	function field_author_title_update($val) {
		return $this->_get_author_info($val, 'title');
	}
	
	function _get_author_info($val, $type) {
		$val = trim($val);
		if (!$val) return '';
		
		$val = str_replace('&#44;', ',', $val);
		$val = str_replace('&#44', ',', $val);
		$l = explode(',', $val);
		
		if (count($l) < 2) {
			if ($type == 'name') 
				return $val;
			else return '';
		}
		
		$key = ($type == 'name') ? 0 : 1;
		return $l[$key];
	}
	
	function field_created_update($val) {
		return strtotime($val);
	}
	
	/* see field_sponsor_expiration_update() for date's common issues */
	function field_issue_date_update($val) {
		// If Issue date ends in P, leave the issue date field empty
		if (!$val) {
			return '1951-01-01 00:00:00';
		}
		
		$date_part = substr($val, 0, 5);
		if (!preg_match('/([0-9]{2}\.[0-9]{2})/', $date_part)) {
			return '1951-01-01 00:00:00';
		}
		
		list($m, $y) = explode('.', $date_part);
		return date('Y-m', mktime(0, 0, 0, $m, 1, $y));
	}
	
	
	function _overrwite_empty_date_field(&$account, $fieldname) {
		$lookup = '1951-01-01';
		if (is_string($account->{$fieldname}) && substr($account->{$fieldname}, 0, 10) == $lookup) {
			unset($account->{$fieldname});
		} else if (is_array($account->{$fieldname}) && substr($account->{$fieldname}['und'][0]['value'], 0, 10) == $lookup) {
			unset($account->{$fieldname});
		}
	}
	
	function replace_mos_image($images_source, $text_source) {
	  $img =  preg_replace('/{mosimage}/', '', $text_source);
		$img =  preg_replace('/{mosiamge}/', '', $img);
		return $img;
		
	  $joomla_img_folder       = JOOMLA_IMG_FOLDER;
	  $joomla_path             = variable_get('joomla_path', JOOMLA_PATH);

	  $images = array();
	  $images = explode("\n", $images_source);
	  $image_string = '{mosimage}';

	  $n=0;
	  $images_items =array();
	  while (!(strpos($text_source, $image_string) === FALSE))  {
	    $images_items = explode("|", $images[$n]);

	    $images_replace = '<img src="'. base_path() . variable_get('file_public_path', conf_path() . '/files') 
				. "/$joomla_img_folder/{$images_items[0]}" .'"'
	      .' align="'. $images_items[1] .'" title="'. $images_items[2] .'" alt="'. $images_items[2] .'"/>';
	    $text_source = substr_replace($text_source, $images_replace, strpos($text_source, $image_string), 10) ;
	    $n++;
	  }

	  return $text_source;
	}
	
	function replace_image_link($text_source) {
	  //Fixs image string: src="images/
	  $image_string = 'src="images/';
	  $images_replace = 'src="'. base_path() . variable_get('file_public_path', conf_path() . '/files/') 
			. JOOMLA_IMG_FOLDER .'/';

	  $text_result = str_replace('src="images/', "$images_replace", $text_source);

	  return $text_result;
	}
}

