<?php
class AwArticleMigration extends JoomlaMigration {
	
	public function __construct() {
    parent::__construct();

		$query = Database::getConnection('default', 'joomla')
							->select('jos_content', 'jcontent')
		         	->fields('jcontent')
							->condition('state', 1)
							->condition(db_or()->condition('modified', '2011-10-31 00:00:00', '>')->condition('created', '2011-10-31 00:00:00', '>'))
							->condition('jcontent.created_by_alias', 'Gary Mintchell, from the Feed Forward Blog%', 'NOT LIKE')
							->condition('jcontent.created_by_alias', 'Keith Campbell, On the Edge Blog%', 'NOT LIKE')
							->condition('content_type', array(
								 JOOMLA_PW_CTID_FEATURED_ARTICLE,
								 JOOMLA_PW_CTID_PRODUCT,
								 JOOMLA_PW_CTID_WEB_EXCLUSIVE,
								 JOOMLA_PW_CTID_NEWS,
								 JOOMLA_PW_CTID_RESEARCH,
								 JOOMLA_PW_CTID_PRIMER,
								 JOOMLA_PW_CTID_COLUMN,
								 JOOMLA_PW_CTID_EVENT,
								 JOOMLA_PW_CTID_ELEARNING,
								JOOMLA_PW_CTID_CASE_APPLICATION,
								JOOMLA_PW_CTID_PERSPECTIVE), 'IN');
		$query->leftJoin('content_category_xref', 'jcat', 'jcat.content_id=jcontent.id');
		$query->addExpression('GROUP_CONCAT(DISTINCT jcat.category_id SEPARATOR \'~\')', 'cat_list');
		$query->groupBy('jcontent.id');
		$query->orderBy('id', 'desc');
		
		$count_query = Database::getConnection('default', 'joomla')
      ->select('jos_content', 'jcontent');
    $count_query->addExpression('COUNT(id)', 'cnt');
		
	  $this->source = new MigrateSourceSQL($query, array(), $count_query);
		$this->destination = new MigrateDestinationNode('article');
		
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

		// Taxonomies
		$this->addFieldMapping('field_page', 'page_num');
		
		$this->addFieldMapping('field_term_source_type', 'is_sponsored')
				 ->callbacks(array($this, 'term_source_type_update'));
		
		$this->addFieldMapping('field_term_subtype', 'content_type')
				 ->callbacks(array($this, 'term_subtype_update'));
		
		
		// This is the list of vocabularies that can be added as "primary vocabularies".
		// Not all vocabularies are part of this list
		$this->all_pvocabs = array(
			'Automation Strategies',
			'Industry Type',
			'Industries',
		);
		
	}
	
	// public function prepareRow($row) {
	// 		parent::prepareRow($row);
	// 		print_r($row);
	// 		$row->modified = date('Y-m-d H:i:s');
	// 	}
	
	function prepare($account, $row) {
		parent::prepare($account, $row);
		$content = $account->body['und'][0]['value'];
		
		// If primary vocabulary was not set yet, assign any qualified vocabulary
		$this->pwObj->assign_primary_vocab($account, 'Automation Strategies');
		
		// Migrating the is_sponsored field to Drupal Source Type vocabulary - for Lead gen only
		if ($row->is_sponsored == 1) {
			if ($row->sponsored_expiration != '0000-00-00 00:00:00') {
				$tid = $this->pwObj->find_term_tid('Source type', 'Lead gen campaign');
				$account->field_term_source_type = array();
				$account->field_term_source_type['und'][0]['tid'] = $tid;
			}
		}
		
		// Mapping "Source type" and "Coverage Type"
		if ($row->is_sponsored == 2) {
			$suffix = substr($row->issue, strlen($row->issue)-1, 1);
			$vocab = 'Coverage Type';
			switch($suffix) {
				case 'O':
					$tid = $this->pwObj->find_term_tid($vocab, 'opc');
					$this->pwObj->migrate_assign_term($account, $vocab, $tid);
					$found = true;
				break;
				case 'M':
					$tid = $this->pwObj->find_term_tid($vocab, 'mfg_intelligence');
					$this->pwObj->migrate_assign_term($account, $vocab, $tid);
					$found = true;
				break;
				case 'B':
					$tid = $this->pwObj->find_term_tid($vocab, 'industrial_networking');
					$this->pwObj->migrate_assign_term($account, $vocab, $tid);
					$found = true;
				break;
				case 'T':
					$tid = $this->pwObj->find_term_tid($vocab, 'opsmanage');
					$this->pwObj->migrate_assign_term($account, $vocab, $tid);
					
					$tid = $this->pwObj->find_term_tid($vocab, '2010');
					$this->pwObj->migrate_assign_term($account, $vocab, $tid);
					$found = true;
				break;
				case 'X':
					$tid = $this->pwObj->find_term_tid($vocab, 'emerson_exchange');
					$this->pwObj->migrate_assign_term($account, $vocab, $tid);
					
					$tid = $this->pwObj->find_term_tid($vocab, '2008');
					$this->pwObj->migrate_assign_term($account, $vocab, $tid);
					$found = true;
				break;
				case 'F':
					$tid = $this->pwObj->find_term_tid($vocab, 'siemens_tia');
					$this->pwObj->migrate_assign_term($account, $vocab, $tid);
					$found = true;
				break;
				case 'I':
					$tid = $this->pwObj->find_term_tid($vocab, 'machines_italia');
					$this->pwObj->migrate_assign_term($account, $vocab, $tid);
					$found = true;
				break;
			}
			
			// nothing was really changed here so im not overwriting anything new
			/*if ($found) {
				$tid = $this->pwObj->find_term_tid('Source type', 'Custom Content');
				$account->field_term_source_type['und'][0]['tid'] = $tid;
			}*/
		}
		
		if ($row->eye == 'PROFINET') {
			$tid = $this->pwObj->find_term_tid($vocab, 'profinet_news');
			$this->pwObj->migrate_assign_term($account, $vocab, $tid);
			
			$tid = $this->pwObj->find_term_tid('Source type', 'Custom Content');
			$account->field_term_source_type['und'][0]['tid'] = $tid;
		}
		
		// Importing meta data from "Column Type"
		$vocab = 'Column Type';
		$maps = array(
			'FEED FORWARD' => array('Feed Forward', 'Feed Forward'),
			'INTEGRATOR VIEW' => array('Integrator View', 'Integrator View'),
			'ENTERPRISE VIEW' => array('Enterprise View', 'Enterprise View'),
			'ECONOMICS VIEW' => array('Economics View', 'Economics View'),
			'PINTO\'S PROSE' => array('Pinto\'s Prose', 'Pinto\'s Prose'),
			'INDUSTRY VIEW' => array('Industry View', 'Industry View'),
			'ECONOMY VIEW' => array('Economy View', 'Economy View'),
			'IT VIEW' => array('IT View', 'IT View'),
			'FINANCE VIEW' => array('Finance View', 'Finance View'),
			'The SETPOINT' => array('The Setpoint', 'Setpoint'),
		);
		
		$eye = strtoupper($row->eye);
		if (isset($maps[$eye])) {
			$tid = $this->pwObj->find_term_tid($vocab, $maps[$row->eye][0]);
			$this->pwObj->migrate_assign_term($account, $vocab, $tid);
			
			$tid = $this->pwObj->find_term_tid('Subtype', 'Column');
			if ($tid) {
				$account->field_term_subtype = array();
				$account->field_term_subtype['und'][0]['tid'] = $tid;
			}
		}
		
		
	}
	
	function term_source_type_update($val) {
		switch($val) {
			case 0: 	return 'Original content';
			case 1: 	return 'Supplier submitted';
			case 2: 	return 'Custom Content';
			default: 	return 'Original content';
		}
	}
	
	function term_subtype_update($val) {
		switch($val) {
			case JOOMLA_PW_CTID_NEWS:
			case JOOMLA_PW_CTID_WEB_EXCLUSIVE: 		return 'News';
			case JOOMLA_PW_CTID_FEATURED_ARTICLE: return 'Feature Article';
			case JOOMLA_PW_CTID_CASE_APPLICATION: return 'Case Application';
			case JOOMLA_PW_CTID_COLUMN:						return 'Column';
			case JOOMLA_PW_CTID_PRIMER:						return 'Primer';
			case JOOMLA_PW_CTID_PRODUCT: 					return 'Product'; 
			case JOOMLA_PW_CTID_RESEARCH:					return 'Research';
			case JOOMLA_PW_CTID_ELEARNING:				return 'Training';
			case JOOMLA_PW_CTID_PERSPECTIVE:				return 'Perspective';
		}
		
		return '';
	}

}

