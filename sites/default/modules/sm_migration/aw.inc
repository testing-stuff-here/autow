<?php
define('JOOMLA_IMG_FOLDER', 'images');

// Content Type Mapping
define('JOOMLA_PW_CTID_STATIC', 0);
define('JOOMLA_PW_CTID_FEATURED_ARTICLE', 1);
define('JOOMLA_PW_CTID_WHITE_PAPER', 2);
define('JOOMLA_PW_CTID_PRODUCT', 4);
define('JOOMLA_PW_CTID_WEB_EXCLUSIVE', 5);
define('JOOMLA_PW_CTID_NEWS', 7);
define('JOOMLA_PW_CTID_WEBCAST', 8);
define('JOOMLA_PW_CTID_PODCAST', 9);
define('JOOMLA_PW_CTID_RESEARCH', 10);
define('JOOMLA_PW_CTID_PRIMER', 11);
define('JOOMLA_PW_CTID_COLUMN', 12);
define('JOOMLA_PW_CTID_VIDEO', 13);
define('JOOMLA_PW_CTID_SLIDESHOW', 14);
define('JOOMLA_PW_CTID_BLOG', 15);
define('JOOMLA_PW_CTID_EVENT', 16);
define('JOOMLA_PW_CTID_ELEARNING', 17);
define('JOOMLA_PW_CTID_PERSPECTIVE', 18);
define('JOOMLA_PW_CTID_CASE_APPLICATION', 19);

// Category Mapping
define('JOOMLA_PW_CATID_PACKAGING_AUTOMATION', 96);

class PwTerms {
	public $terms;
	public $missing;
	
	/**
	 * We created a CSV file that list the Joomla Terms 
	 * The result would be
	 * 	$j_categories[JOOMLA_CAT_ID][] = array(
	 *		VOCABULARY_NAME,
	 *		LEVEL1 TERM NAME, 
	 *		LEVEL2 TERM NAME,
	 * 		LEVEL3 TERM NAME
	 *	);
	 */
	function map_joomla_terms() {
		$dir = dirname(__FILE__);

		$j_categories = array();

		for($i=2; $i<=2; $i++) {
			$filename = 'aw_terms_'.$i.'.csv';
			$file =  $dir . '/clientdata/'.$filename;

			$content = file_get_contents($file);

			$rows = explode("\n", $content);
			$cnt = 0;

			$vocab = '';
			$first = true;
			foreach($rows as $row) {
				$cnt++;
				if (empty($row)) continue;
				if ($first) {
					$first = false;
					continue;
				}

				$col = str_getcsv($row);
				
				if (!empty($col[0])) {
					$vocab = preg_replace('/(.*)\(.*\)/', '$1', $col[0]);
					$vocab = trim($vocab);
					$l1 = $l2 = $l3 = '';
				}

				$col[1] = trim(@$col[1]);
				$col[2] = trim(@$col[2]);
				if (!empty($col[1])) {
					$l1 = $col[1];
					$l2 = $l3 = '';
				}
				if (!empty($col[2])) {
					$l2 = $col[2];
					$l3 = '';
				}
				
				$l3 = isset($col[3]) ? $col[3] : '';

				$j_cat = '';
				if (isset($col[4])) {
					$j_cat = trim($col[4]);
				}

				if (!$j_cat) continue;
				if (!strstr($j_cat, '//')) continue;

				$conds = explode(';', $j_cat);
				foreach($conds as $cond) {
					$j_section = explode('//', $cond);
					
					$query = Database::getConnection('default', 'joomla')
								 ->select('jos_sections')
								 ->fields('jos_sections', array('id'))
								 ->condition('title', trim($j_section[0]))
								 ->execute();
								
					$section_id = $query->fetchField();
					if (!$section_id)	continue;

					$catname = html_entity_decode(trim($j_section[1]));
					$query = Database::getConnection('default', 'joomla')
								 ->select('jos_categories')
								 ->fields('jos_categories', array('id'))
								 ->condition('title', $catname)
								 ->condition('section', $section_id)
								 ->execute();
					$cat_id = $query->fetchField();
					
					if (!$cat_id)	{
						debugm('Joomla Mapping: unable to find ' . $catname . ' on section ' . trim($j_section[0]));
						continue;
					}
					
					$j_categories[$cat_id][] = array(
						$vocab,
						$l1, $l2, $l3,
						$section_id
					);
				}
			}
		}
		
		$this->terms['joomla'] = $j_categories;
	}
	
	/**
	 * These are the machine names we used for all our vocabularies in drupal
	 */
	function map_drupal_terms() {
		$this->terms['drupal'] = array(
			'automation strategies' => 'field_term_automation',
			'industry type' 				=> 'field_term_industry_type',
			'industries' 						=> 'field_term_industry',
			'source type' 					=> 'field_term_source_type',
			'coverage type' 				=> 'field_term_coverage_type',
			'column type' 					=> 'field_term_column_type',
			'tags' 									=> 'field_tags',
		);
	}
	
	function content_types() {
		$this->terms['contenttypes'] = array(
			'article' => 'article',
			'page' => 'page',
			'blog' => 'blog',
			'podcast' => 'podcast',
			'video' => 'video',
			'webcast' => 'webcast',
			'white paper' => 'whitepaper',
			'whitepaper' => 'whitepaper', // no space
		);
	}
	
	function assign_primary_vocab(&$account, $vocab, $term='') {
		$field = $this->get_drupal_vocab_machine_name($vocab);
		
		$primary = $field;
		if ($term) { // term was explicitly given
			$tid = $this->find_term_tid($vocab, $term);
			$primary .= ','.$tid;
		}
		
		if (isset($account->{$field}['und'])) {
			$account->field_vocab_primary['und'][0]['value'] = $primary;
			return true;
		}
		
		return false;
	}
	
	function get_cck_type_machine_name($term) {
		$term = strtolower($term);
		if (isset($this->terms['contenttypes'][$term])) 
			return $this->terms['contenttypes'][$term];
			
		return false;
	}
	
	function get_drupal_vocab_machine_name($vocab) {
		$vocab = trim(strtolower($vocab));
		if (!$vocab) return false;
		
		if (isset($this->terms['drupal'][$vocab])) {
			return $this->terms['drupal'][$vocab];
		}
		
		// We cannot allow this error
		//throw new MigrateException(t('The vocabulary [!vocab] was not found in our list of qualified vocabulary names. ', array('!vocab' => $vocab)));
	
		return false;
	}
	
	function assign_term($data, $vocab, $prefix_msg='') {
		$new = array();
		$vocab = strtolower($vocab);
		
		if (empty($data)) return $new;
		
		if ($vocab == 'industry type' && is_string($data)) {
			$data = $this->correct_industry_type($data);
		}
		
		if ($vocab == 'industries' && is_string($data)) {
			$data = $this->correct_industries($data);
		}
		
		if ($vocab == 'tags' && is_string($data)) {
			$data = explode(',', $data);
		}
		
		$track_parent = false;
		$last_key = 0; $parent_tid = 0;
		$parent_term = '';
		if ($vocab == 'automation strategies') {
			$track_parent = true;
		}
		
		foreach($data as $key => $term) {
			$term = trim($term);
			if (!$term) continue;
			//debugm("$prefix_msg [vocab: $vocab] [Term: $term] [Parent: $parent_term]");
			
			$term_arr = array();
			$tid = 0;
			
			if ($track_parent) {
				$tid = $this->find_term_tid($vocab, $term, $parent_tid);
			}
			else {
				$tid = $this->find_term_tid($vocab, $term);
			}
			
			if ($tid) {
				$new['und'][]['tid'] = $tid;
				if ($track_parent) {
					$parent_tid = $tid;
					$parent_term = $term;
				}	
				continue;
			}
			
			// something is wrong so let's continue to drill it down
			if (strstr($term, ',')) {
				$term_arr = explode(',', $term);
				
				foreach($term_arr as $newterm) {
					$newterm = trim($newterm);
					if (!$newterm) continue;
					
					if ($track_parent) {
						$tid = $this->find_term_tid($vocab, $newterm, $parent_tid);
					}
					else {
						$tid = $this->find_term_tid($vocab, $newterm);
					}
					
					if ($tid) {
						$new['und'][]['tid'] = $tid;	
						continue;
					}
					
					if ($track_parent) {
						debugm("$prefix_msg [Missing Term in Groups with Parent] [vocab: $vocab] [Group: $term] [Term: $newterm] [Parent: $parent_term]");
					}
					else {
						debugm("$prefix_msg [Missing Term in Groups] [vocab: $vocab] [Group: $term] [Term: $newterm]");
					}
				}
			}
			else {
				if ($track_parent) {
					debugm("$prefix_msg [Missing Term with Parent] [vocab: $vocab] [Term: $term] [Parent: $parent_term]");
				}
				else {
					debugm("$prefix_msg [Missing Term] [vocab: $vocab] [Term: $term]");
				}
			}

			// we still need to assign it here?
			if ($track_parent) {
				$parent_tid = $tid;
				$parent_term = $term;
			}	
			
		}

		if ($new) {
			//debugm($new);
		}
		return $new;
	}
	
	function migrate_assign_term(&$account, $vocab, $tid) {
		if (!$tid) return;
		$found = false;
		
		$field = $this->get_drupal_vocab_machine_name($vocab);
		if (!is_array($account->{$field}['und'])) {
			$account->{$field}['und'][]['tid'] = $tid;
		}
		
		foreach($account->{$field}['und'] as $v) {
			if ($v['tid'] == $tid) $found = true;
		}
		if (!$found) {
			$account->{$field}['und'][]['tid'] = $tid;
		}
	}

	function find_vocab_vid($vocab) {
		if (isset($this->terms['vids'][$vocab])) {
			return $this->terms['vids'][$vocab];
		}

		$query = db_select('taxonomy_vocabulary')
		  ->fields('taxonomy_vocabulary', array('vid'))
		  ->where('lcase(name) = :vocab', array(':vocab' => $vocab))
		  ->execute();
		$vid = $query->fetchField();
		$this->terms['vids'][$vocab] = $vid;

		return $vid;
	}

	function find_term_tid($vocab, $term, $parent=null) {
		$vocab = strtolower($vocab);
		$vid = $this->find_vocab_vid($vocab);
		
		if ($parent != null) {
			if (!isset($this->terms['terms_parents'][$vid][$parent][$term])) {
				$query = db_select('taxonomy_term_data', 'term')
				  ->fields('term', array('tid'))
				  ->condition('vid', $vid)
				  ->where('lcase(name) = :term', array(':term' => strtolower($term)));

				$query->leftJoin('taxonomy_term_hierarchy', 'parent_table', 'parent_table.tid=term.tid');
				$query->where('parent_table.parent = :parent_tid', array(':parent_tid' => $parent));
				
				$result = $query->execute();
				$tid = 0;
				foreach($result as $record) {
					$tid = $record->tid;
					break;
				}

				$this->terms['terms_parents'][$vid][$term] = $tid;
				return $this->terms['terms_parents'][$vid][$term];
			}
		}
		
		if (!isset($this->terms['terms'][$vid][$term])) {
			$query = db_select('taxonomy_term_data', 'term')
			  ->fields('term', array('tid'))
			  ->condition('vid', $vid)
			  ->where('lcase(name) = :term', array(':term' => strtolower($term)));

			$result = $query->execute();
			$tid = 0;
			foreach($result as $record) {
				$tid = $record->tid;
				break;
			}

			$this->terms['terms'][$vid][$term] = $tid;
		}
		
		
		if ($vocab == 'tags' && $vid && !$this->terms['terms'][$vid][$term]) {
			// create the tag
			$term_obj = new stdClass();
			$term_obj->vid = $vid;
			$term_obj->name = trim($term);
			taxonomy_term_save($term_obj);
			$this->terms['terms'][$vid][$term] = $term_obj->tid;
			debugm('New term created for tags: ' . $term . ':' . $term_obj->tid);
		}

		return $this->terms['terms'][$vid][$term];
	}
	
	function correct_industry_type($term) {
		$term = trim($term);
		if (strtolower($term) == 'all') {
			return array('Batch Automation', 'Discrete Automation', 'Process Automation');
		}

		if (strstr($term, ',')) {
			$tmp = explode(',', $term);
			foreach($tmp as $key => &$_tmp) {
				if (empty($_tmp)) unset($tmp[$key]);
				$_tmp = trim($_tmp);
			}

			$term = $tmp;
		}

		if (is_string($term)) {
			$term = array($term);
		}

		foreach($term as &$_term) {
			switch($_term) {
				case 'Process': 
				case 'Batch': 
				case 'Discrete': 
				$_term .= ' Automation';
				break;
			}
		}

		return $term;
	}

	function correct_industries($term) {
		$term = trim($term);
		if (strtolower($term) == 'all') {
			return array('Food and Beverage',
			'Chemical',
			'Packaging',
			'OEM',
			'Pharmaceutical',
			'Medical',
			'Oil and Gas',
			'Fabricated Metals',
			'Print',
			'Automotive',
			'Construction',
			'Agriculture',
			'Mining',
			'Instrumentation Products',
			'Control Products',
			'Measurement Products',
			'Electronics',
			'Plastic and Rubber products',
			'Computers',
			'Semiconductors',
			'Aerospace',
			'Steel',
			'Communication Devices and Equipment',
			'Water and Wastewater',
			'System Integration',
			'Power',
			'Alternative Energy');
		}

		if (strstr($term, ',')) {
			$tmp = explode(',', $term);
			foreach($tmp as $key => &$_tmp) {
				if (empty($_tmp)) unset($tmp[$key]);
				$_tmp = trim($_tmp);
			}

			$term = $tmp;
		}

		if (is_string($term)) {
			$term = array($term);
		}

		return $term;
	}
}

function debugm($t, $title='') {
	if ($title)
		print '[Debug] ' . $title . ' :: ';
	if (is_array($t)) print_r($t);
	else print $t . "\n";
}

if(!function_exists('str_getcsv')) {
    function str_getcsv($input, $delimiter = ",", $enclosure = '"', $escape = "\\") {
        $fp = fopen("php://memory", 'r+');
        fputs($fp, $input);
        rewind($fp);
        $data = fgetcsv($fp, null, $delimiter, $enclosure); // $escape only got added in 5.3.0
        fclose($fp);
        return $data;
    }
}
