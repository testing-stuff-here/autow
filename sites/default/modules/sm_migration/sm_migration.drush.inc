<?php
include_once('aw.inc');
$global_missing = array();
$global_updated = array();


function sm_migration_drush_command() {
  $items = array();

  // Check for errors in google spreadsheet 
  $items['sm-check-t2'] = array(
	  'callback' => 'sm_migration_check_terms',
	  'description' => "Migrate script",
	);
	
	// run the google spreadsheet update
	$items['sm-up'] = array(
    'callback' => 'sm_migration_update_nodes',
    'description' => "Migrate script",
    'options' => array(
      'part' => 'values: full, companies, terms',
    ),
  );

  // Add related articles
	$items['sm-rel'] = array(
	  'callback' => 'sm_migration_update_related',
	  'description' => "Migrate script",
	  'options' => array(
	    'id' => 'list of ID for trying out the result. it could be "<123" or ">123" or "123" or "123,124"',
	    ),
	);

	// Adding primary terms
	$items['sm-primary-up'] = array(
	  'callback' => 'sm_migration_primary_term_update',
	  'description' => "Migrate script",
	  'arguments' => array(
	    'limit' => 'limit number of updates',
  	  ),
    'options' => array(
      'id' => 'list of ID for trying out the result. it could be "<123" or ">123" or "123" or "123,124"',
      ),
	);
	
	// Bug fix when running sm-up. It does not create the primary_term in all nodes. sm-primary-up will not update the node if there are no values in the primary_term field.
	$items['sm-primary-fix'] = array(
	  'callback' => 'sm_migration_primary_term_update_fix',
	  'description' => "Migrate script",
	  'arguments' => array(
	    'node_type' => 'node type',
	    'limit' => 'limit number of updates',
	    ),
    'options' => array(
      'id' => 'list of ID for trying out the result. it could be "<123" or ">123" or "123" or "123,124"',
      ),
	);
	
	// Updating viddler ID
	$items['sm-viddler-up'] = array(
	  'callback' => 'sm_migration_viddler_update',
	  'description' => "Migrate script",
		'arguments' => array(
	    'limit' => 'limit number of updates',
	  ),
	);
	
	// Add 301 redirects from joomla path to drupal path
	$items['sm-redirect-up'] = array(
	  'callback' => 'sm_migration_add_redirects',
	  'description' => "Migrate script",
	);
	
	// In the mid of the development of PW, Dave found error in updating images, titles, videos. This was the script that fixed those. This part was already implemented in the migrate script
	$items['sm-image-up'] = array(
	  'callback' => 'sm_migration_update_image',
	  'description' => "Migrate script",
		'options' => array(
      'id' => 'list of ID for trying out the result. it could be "<123" or ">123" or "123" or "123,124"',
      ),
	);
	
	$items['sm-title-fix'] = array(
	  'callback' => 'sm_migration_title_fix',
	  'description' => "Migrate script",
	);
	
  return $items;
}

function sm_migration_update_nodes() {
	global $global_missing, $global_updated;
	$dir = dirname(__FILE__);
	
	set_time_limit(3600);
	ini_set('memory_limit', '1G');
	
	$files = array(
		array('update_2011', '2011 AW content'),
	);
	
	$part = drush_get_option('part');
	switch($part) {
		case 'companies':
		case 'company':
			$part = 'companies';
		break;
		case 'terms':
		case 'term':
			$part = 'terms';
		break;
		default:
			$part = 'full';
	}
	
	foreach($files as $info) {
		$file =  $dir . '/clientdata/'.$info[0] . '.csv';
		$content = file_get_contents($file);

		$rows = explode("\n", $content);
		$cnt = 0;

		$vocab = '';
		$first = true;
		$global_missing = array();
		

		
		$obj_pw = new PwTerms();
		$obj_pw->map_joomla_terms();
		$obj_pw->map_drupal_terms();
		$obj_pw->content_types();

		foreach($rows as $row) {
			$cnt++;
			if (empty($row)) continue;
			if ($first) {
				$first = false;
				continue;
			}

			$col = str_getcsv($row);
			$col = format_csv_content($info[0], $col);
			if (!$col) continue;
			
			update_content($col, $obj_pw, $part);
		}
	}
	
}

function sm_migration_title_fix() {
	global $global_missing, $global_updated;
	$dir = dirname(__FILE__);
	
	set_time_limit(3600);
	ini_set('memory_limit', '1G');
	
	$files = array(
		array('update_2011', '2011 AW content'),
	);
	
	foreach($files as $info) {
		$file =  $dir . '/clientdata/'.$info[0] . '.csv';
		$content = file_get_contents($file);

		$rows = explode("\n", $content);
		$cnt = 0;

		$vocab = '';
		$first = true;
		$global_missing = array();
		
		foreach($rows as $row) {
			$cnt++;
			if (empty($row)) continue;
			if ($first) {
				$first = false;
				continue;
			}

			$col = str_getcsv($row);
			$col = format_csv_content($info[0], $col);
			if (!$col) continue;
			
			
			$joomla_id = (int)$col['id'];
			
			$query = db_select('field_data_field_joomla_id')
    				 	->fields('node', array('nid'))
    				 	->condition('entity_type', 'node')
    				 	->condition('deleted', '0')
    					->condition('field_joomla_id_value', $joomla_id);
    	$query->leftJoin('node', 'node', 'node.nid=field_data_field_joomla_id.entity_id 
    		AND node.vid=field_data_field_joomla_id.revision_id');
    	$result = $query->execute();
      
    	$nid = false;
    	foreach ($result as $record) {
    		$nid = $record->nid;
    	}
    	
    	$node = node_load($nid);

    	if (!$nid) {
    		debugm('Missing joomla article id: ' . $joomla_id);
    		continue;
    	}
    	
    	$query = Database::getConnection('default', 'joomla')
								->select('jos_content', 'jcontent')
			         	->fields('jcontent', array('title'))
								->condition('jcontent.id', $joomla_id);
			$finder = $query->execute();
      
			foreach($finder as $finder1) {
			  $tmp = (array)$finder1;
				$node->title = $tmp['title'];
				debugm($joomla_id . ':' . $node->nid . ':'. $node->title);
				node_save($node);
				break;
			}
			
		}
	}
	
}

function _sm_get_joomla_ids_from_csv() {
  $dir = dirname(__FILE__);
	$file =  $dir . '/clientdata/joomla_ids.csv';
	$content = file_get_contents($file);

	$rows = explode("\n", $content);
	$cnt = 0;
	
	$results = array();
	foreach($rows as $row) {
		$cnt++;
		if (empty($row)) continue;
		
		// Only process text that begins with "Processing Joomla ID:"
		$col = str_getcsv($row);
		$find = 'Processing Joomla ID:';
		
		if (substr($col[0], 0, strlen($find)) != $find) continue;
		
		$joomla_id = (int)str_replace($find, '', $col[0]);
		$joomla_id = trim($joomla_id);
		$joomla_id = (int)$joomla_id;
		if (!$joomla_id) continue;
		
		$results[$joomla_id] = $joomla_id;
	}
	
	return $results;
}

/* Add related content to drupal  */
function sm_migration_update_related() {
	$joomla_ids = _sm_get_joomla_ids_from_csv();
	
	$cnt = 0;
	foreach($joomla_ids as $joomla_id) {
		$cnt++;
		
		// Get the node ID in drupal
		$query = db_select('field_data_field_joomla_id')
					 	->fields('node', array('nid'))
					 	->condition('entity_type', 'node')
					 	->condition('deleted', '0')
						->condition('field_joomla_id_value', $joomla_id);
		$query->leftJoin('node', 'node', 'node.nid=field_data_field_joomla_id.entity_id 
			AND node.vid=field_data_field_joomla_id.revision_id');
		$result = $query->execute();
    
		$nid = false;
		foreach ($result as $record) {
			$nid = $record->nid;
		}
    
		if (!$nid) {
			debugm('Missing node for joomla id: ' . $joomla_id);
			continue;
		}
		
		$node = node_load($nid);
		
		// Get all the related contents
		$query = Database::getConnection('default', 'joomla')
							->select('content_xref', 'jrelated')
		         	->fields('jrelated')
							->condition(db_or()->condition('content_id1', $joomla_id)->condition('content_id2', $joomla_id));
		$result = $query->execute();

		$ids = array();
		foreach ($result as $record) {
			if ($record->content_id1 != $joomla_id)
				$ids[$record->content_id1] = $record->content_id1;

			if ($record->content_id2 != $joomla_id)	
				$ids[$record->content_id2] = $record->content_id2;
		}

		if (!$ids) continue;
		
		$query = db_select('field_data_field_joomla_id')
					 	->fields('node', array('nid'))
					 	->condition('entity_type', 'node')
					 	->condition('deleted', '0')
						->condition('field_joomla_id_value', $ids, 'IN');
		$query->leftJoin('node', 'node', 'node.nid=field_data_field_joomla_id.entity_id AND node.vid=field_data_field_joomla_id.revision_id');
		$result = $query->execute();
		
		$node->field_related = array();
		$related_ids = '';
		
		foreach ($result as $record) {
			$node->field_related['und'][]['nid'] = $record->nid;
			$related_ids .= $record->nid . ',';
		}
		
		if ($node->field_related['und']) {
			$related_ids = trim($related_ids, ',');
			debugm("[Related ID found for {$joomla_id}] $related_ids");
		}
		
		node_save($node);
	}
	
	debugm('Total: ' . $cnt);
}

/* Helper function of sm_migration_update_nodes() */
function update_content($col, $obj_pw, $parts='full') {
	global $global_missing, $global_updated;
	
	$article_id = (int)$col['id'];
	if (!$article_id) {
		return false;
	}
	
	$query = db_select('field_data_field_joomla_id')
				 	->fields('node', array('nid'))
				 	->condition('entity_type', 'node')
				 	->condition('deleted', '0')
					->condition('field_joomla_id_value', $article_id);
	$query->leftJoin('node', 'node', 'node.nid=field_data_field_joomla_id.entity_id 
		AND node.vid=field_data_field_joomla_id.revision_id');
	$result = $query->execute();
	
	$nid = false;
	foreach ($result as $record) {
		$nid = $record->nid;
	}
	
	if (!$nid) {
		debugm('Missing joomla article id: ' . $article_id);
		return false;
	}
	
	if (!$node = node_load($nid)) {
		debugm('Invalid node: ' . $nid);
		return false;
	}
	
	update_content_terms($col, $obj_pw, $node);
	if (!isset($global_updated['joomla'][$col['id']])) {
		$global_updated['joomla'][$col['id']] = 1;
	}
	else {
		$global_updated['joomla'][$col['id']]++;
	}
	
	/*
	// dont want to override the headlines
	$title = trim($col['title']);
	if ($title) {
		$node->title = $title;
	}
	*/
	
	debugm('Processing Joomla ID: ' . $article_id);
	node_save($node);
	$global_updated['node'] = $node->nid;
	
	return true;
}

function update_content_terms($col, $obj_pw, &$node) {
	global $global_missing, $global_updated;
	
	$node->field_legacy['und'][0]['value'] = 0; // change this to "not legacy"
  
  foreach($col['terms'] as $term) {
		$vocab = trim($term['vocab']);
		if (empty($vocab)) continue;
		
		$field = $obj_pw->get_drupal_vocab_machine_name($vocab);
		
		if (empty($field)) {
			continue;
		}
		
		// TODO: check if the field is empty then it should retain the previous setup
		if ($terms = $obj_pw->assign_term($term['terms'], $vocab)) {
			if (isset($global_updated['joomla'][$col['id']])) {
				$list = array();
				foreach($node->{$field}['und'] as $tid) {
					$list[$tid['tid']] = $tid['tid'];
				}
				
				foreach($terms['und'] as $tid) {
					if (!isset($list[$tid['tid']])) {
						$node->{$field}['und'][]['tid'] = $tid['tid'];
					}
				}
			}
			else {
				$node->{$field} = array();
				$node->{$field} = $terms;
			}
		}
	}
	
	// Primary vocab will always be Automation strategies
	if (isset($col['primary']) && $col['primary']) {
		//debugm('Updating primary ' . $col['id']);
		$primary = $obj_pw->get_drupal_vocab_machine_name('Automation Strategies');
		$tid = $obj_pw->find_term_tid('Automation Strategies', $col['primary']);
		$primary .= ',' . $tid;
		
		$node->field_vocab_primary = array();
		$node->field_vocab_primary['und'][0]['value'] = $primary;
	}
	
	// They just want to store this. im storing in a text field
	if (isset($col['primary_term_industry']) && $col['primary_term_industry']) {
		$node->field_vocab_primary_industry = array();
		$tid = $obj_pw->find_term_tid('Industry type', $col['primary_term_industry']);
		$node->field_vocab_primary_industry['und'][0]['value'] = $tid;
	}
	
	// subtype can be a content type of a term
	if ($col['subtype']) {
		$node->field_term_subtype = array();
		$tid = $obj_pw->find_term_tid('Subtype', $col['subtype']);
		if ($tid) {
			$node->field_term_subtype['und'][0]['tid'] = $tid;
		}
		elseif ($cck_type = $obj_pw->get_cck_type_machine_name($col['subtype'])) {
			if (strtolower($node->type) != strtolower($col['subtype'])) {
				debugm('[Changing content type] ' . $node->type . ' > ' . $cck_type);
				$node->type = $cck_type;
			}
		} 
		else {	
			debugm('[Missing subtype] ' . $col['subtype']);
		}
	}
}

/* Helper function  */
function format_csv_content($type, $data) {
	$new_data = array();
	/*
	x0 = A Joomla ID - just numeric,
	x1 = B Joomla Content Type,
	x2 = C "Drupal vocab: ""Column Type""",
	x3 = D Headline ,
	x4 = E "Industry Type: comma separated, All ",
	x5 = F Industry Type - Primary,
	x6 = Primary Automation Strategy - Only used when content falls in two different Auto. strategy main categories.,
	7 = Automation Strategies (Level -1),
	8 = Level - 2 ,
	9 = Level - 3,
	10 = Industries ,
	11 = Keyword Phrases - Editor Tagging
	*/
	$new_data['id'] = $data[0];
	$new_data['subtype'] = $data[1];
	$new_data['title'] = $data[3];
	$new_data['primary'] = $data[6];
	$new_data['primary_term_industry'] = $data[5];
	
	$new_data['terms'] = array();
	$new_data['terms'][] = array(
		'vocab' => 'Column Type',
		'terms' => array($data[2])
		);
	$new_data['terms'][] = array(
		'vocab' => 'Industry Type',
		'terms' => $data[4]
		);
	$new_data['terms'][] = array(
		'vocab' => 'Automation Strategies',
		'terms' => array($data[7],$data[8],$data[9])
		);
	$new_data['terms'][] = array(
		'vocab' => 'Industries',
		'terms' => $data[10]
		);
	$new_data['terms'][] = array(
		'vocab' => 'Tags',
		'terms' => $data[11]
		);
	
	return $new_data;
}

/*  Check the google spreadsheet for errors */
function sm_migration_check_terms() {
	global $global_missing;
	$dir = dirname(__FILE__);
	
	$files = array(
		array('update_2011', '2011 AW content'),
	);
	
	foreach($files as $info) {
		debugm("=== BEGIN OF {$info[1]} ===");
		
		$file =  $dir . '/clientdata/'.$info[0] . '.csv';
		$content = file_get_contents($file);

		$rows = explode("\n", $content);
		$cnt = 0;

		$vocab = '';
		$first = true;
		$global_missing = array();

		
		$obj_pw = new PwTerms();
		$obj_pw->map_joomla_terms();
		$obj_pw->map_drupal_terms();
		$obj_pw->content_types();

		foreach($rows as $row) {
			$cnt++;
			if (empty($row)) continue;
			if ($first) {
				$first = false;
				continue;
			}

			$col = str_getcsv($row);
			$col = format_csv_content($info[0], $col);
			if (!$col) continue;
			
			// this will throw out an error if vocab name was not found
			if ($col['primary']) {
				$tid = $obj_pw->find_term_tid('Automation Strategies', $col['primary']);
				if (!$tid) {
					debugm("[row: $cnt] [Cant find Primary term] [term: {$col['primary']}]");
				}
			}
			
			foreach($col['terms'] as $term) {
				$vocab = trim($term['vocab']);
				if (empty($vocab)) continue;

				$field = $obj_pw->get_drupal_vocab_machine_name($vocab);
				
				// this will have internal check which terms are missing
				$obj_pw->assign_term($term['terms'], $vocab, "[row: $cnt] [id: {$col['id']}]");
			}

			if ($col['subtype']) {
				$tid = $obj_pw->find_term_tid('Subtype', $col['subtype']);
				if (!$tid && !$cck_type = $obj_pw->get_cck_type_machine_name($col['subtype'])) {
					debugm("[row: $cnt] [id: {$col['id']}] [Cant find subtype: {$col['subtype']}]");
				}
			}
		}
	
		debugm("=== END OF {$info[1]} ===\n");
	}
	
}

/* updates the primary field for empty values */
function sm_migration_primary_term_update_fix() {
	$query = db_select('node', 'node')
				 	->fields('node', array('nid'))
					->condition('type', '', '!=')
				 	->condition('status', '1');
				
	$query->orderBy('nid', 'asc');
	
	$id = drush_get_option('id');
	if ($id) {
		$first_char = substr($id, 0, 1);
		if ($first_char == '<') {
			$query->condition('nid', substr($id, 1), '<');
		}
		else if ($first_char == '>') {
			$query->condition('nid', substr($id, 1), '>');
		}
		else {
			$query->condition('nid', explode(',',$id), 'IN');
		}
	}
	
	$result = $query->execute();
	
	$nid = false;
	foreach ($result as $record) {
		$nid = $record->nid;
		$node = node_load($nid);
		
		if (!$node->field_vocab_primary || !isset($node->field_vocab_primary['und'][0])) {
			$node->field_vocab_primary['und'][0]['value'] = 'field_term_automation';
			
			debugm('Updating node: ' . $nid);
			node_save($node);
		}
		else {
		  debugm('Node: ' . $nid);
		}
	}
	
}

/*this updates the node when there is content in the primary */
function sm_migration_primary_term_update($limit = 0) {
	$term_fields = array(
		'field_term_automation' => 2,
		'field_term_industry_type' => 3,
		'field_term_industry' => 4,
	);
	
	$joomla_ids = _sm_get_joomla_ids_from_csv();
	foreach($joomla_ids as $joomla_id) {
    // get the primary term and start from there
  	$query = db_select('field_data_field_joomla_id')
					 	->fields('node', array('nid'))
					 	->condition('entity_type', 'node')
					 	->condition('deleted', '0')
						->condition('field_joomla_id_value', $joomla_id);
		$query->leftJoin('node', 'node', 'node.nid=field_data_field_joomla_id.entity_id 
			AND node.vid=field_data_field_joomla_id.revision_id');
		$result = $query->execute();

		$nid = false;
		foreach ($result as $record) {
			$nid = $record->nid;
		}

		if (!$nid) {
			debugm($cnt . ' Missing node id for joomla id: ' . $joomla);
			continue;
		}
		
		$primary_vocab = '';
		$new_data = array();
		$group_id = 0;
		foreach($term_fields as $fieldname => $vid) {
			$tree = taxonomy_get_tree($term_fields[$fieldname], 0);
			$tree2 = array();
			foreach($tree as $_tree) {
				$tid = (int)$_tree->tid;
				$tree2[$tid] = $_tree;
			}

			$query = db_select('field_data_'.$fieldname, $fieldname)
							->fields($fieldname)
						 	->condition('entity_id', $nid);
			$query->orderBy('entity_id', 'asc');
			$result = $query->execute();

			$cnt = 1;
			$assigned_terms = array();
			foreach ($result as $record) {
				$fieldname_column = $fieldname . '_tid';
				$tid = $record->{$fieldname_column};
				
				if (isset($tree2[$tid])) {
					$t = $tree2[$tid];
					$assigned_terms[$t->depth][$tid] = $t;
				}
			}
			
			if (!$assigned_terms) continue;
			
			// start with depth 2 - Level 3
			if (isset($assigned_terms[2])) {
				foreach($assigned_terms[2] as $term) {
					$new_data[$group_id][3] = array('tid' => $term->tid, 'vid' => $term->vid);
					
					if (!is_array($term->parents)) continue; // impossible because this is depth 2
					$term = $tree2[$term->parents[0]];
					$new_data[$group_id][2] = array('tid' => $term->tid, 'vid' => $term->vid);
					
					if (!is_array($term->parents)) continue; // impossible because this is depth 2
					$term = $tree2[$term->parents[0]];
					$new_data[$group_id][1] = array('tid' => $term->tid, 'vid' => $term->vid);
					
					ksort($new_data[$group_id]);
					$group_id++;
				}
			}
			
			// level 2
			if (isset($assigned_terms[1])) {
				foreach($assigned_terms[1] as $term) {
					$tmp = array();
					$tmp[2] = array('tid' => $term->tid, 'vid' => $term->vid);
					
					if (!is_array($term->parents)) continue; // impossible because this is depth 2
					$term = $tree2[$term->parents[0]];
					$tmp[1] = array('tid' => $term->tid, 'vid' => $term->vid);
					
					$found = false;
					foreach($new_data as $ref) {
						if ($ref['2']['tid'] == $tmp['2']['tid'] && $ref['1']['tid'] == $tmp['1']['tid']) {
							$found = true;
						}
					}
					
					if ($found) continue;
					
					ksort($tmp);
					$new_data[$group_id] = $tmp;
					
					$group_id++;
				}
			}
			
			// level 1
			if (isset($assigned_terms[0])) {
				foreach($assigned_terms[0] as $term) {
					$tmp = array();
					$tmp[1] = array('tid' => $term->tid, 'vid' => $term->vid);
					
					$found = false;
					foreach($new_data as $ref) {
						if ($ref['1']['tid'] == $tmp['1']['tid']) {
							//debugm($tmp, 'dup');
							$found = true;
						}
					}
					
					if ($found) continue;
					
					ksort($tmp);
					$new_data[$group_id] = $tmp;
					
					$group_id++;
				}
			}
			
			//debugm($debug_data);
			//debugm($new_data, 'new');
		}
		
		
		// Get the primary vocab to be the first selection
		$primary_data = $primary_terms = array();
		if ($node->field_vocab_primary_value) {
			$pvocab = explode(',', $node->field_vocab_primary_value);
			
			$vid = $term_fields[$pvocab[0]];
			unset($pvocab[0]);
			
			// get the first data with that vid
			// we're getting them all so we're grouping them properly
			foreach($new_data as $group_id => $data) {
				foreach($data as $item) {
					if ($item['vid'] == $vid) {
						$primary_data[$group_id] = $data;
						unset($new_data[$group_id]);
						ksort($new_data);
					}
				}
			}
			
			// get exact term matches
			$level = count($pvocab);
			if ($level) {
				$tmp = array();
				$delta = 1;
				foreach($pvocab as $tid) {
					$tmp[$delta++] = array('tid' => $tid, 'vid' => $vid);
				}
				
				$primary_terms = array();
				switch($level) {
					case 1:
						foreach($primary_data as $group_id => $ref) {
							if ($ref['1']['tid'] == $tmp['1']['tid']) {
								$primary_terms[$group_id] = $ref;
								unset($primary_data[$group_id]);
								ksort($primary_data);
								break;
							}
						}

						break;
						
					case 2:
						foreach($primary_data as $group_id => $ref) {
							if ($ref['1']['tid'] == $tmp['1']['tid'] && $ref['2']['tid'] == $tmp['2']['tid']) {
								$primary_terms[$group_id] = $ref;
								unset($primary_data[$group_id]);
								ksort($primary_data);
								break;
							}
						}

						break;

					case 3:
						foreach($primary_data as $group_id => $ref) {
							if ($ref['1']['tid'] == $tmp['1']['tid'] 
							 && $ref['2']['tid'] == $tmp['2']['tid']
							 && $ref['3']['tid'] == $tmp['3']['tid']) {
								$primary_terms[$group_id] = $ref;
								unset($primary_data[$group_id]);
								ksort($primary_data);
								break;
							}
						}

						break;	
				}
				
				if ($primary_terms) {
					$primary_data = array_merge($primary_terms, $primary_data);
				}
			} // end of switch ($level)
		} // end of if ($level)
		
		$new_data = array_merge($primary_data, $new_data);
		
		$node = node_load($nid);
		$node->field_allterms = array();
		
		foreach($new_data as $group_id => $data) {
			foreach($data as $item) {
				$node->field_allterms['und'][] = array(
					'vid' => $item['vid'],
					'tid' => $item['tid'],
					'group' => $group_id+1,
				);
			}
		}
		
		if ($node->field_allterms['und']) {
			debugm('Updating node: ' . $nid);
			//debugm($node->field_allterms['und']);
			node_save($node);
		}
  }
	
	// field_data_field_vocab_primary
}

/*this updates the node when there is content in the primary */
function sm_migration_primary_term_update_old($limit = 0) {
	$term_fields = array(
		'field_term_automation' => 2,
		'field_term_industry_type' => 3,
		'field_term_industry' => 4,
	);
	
	// get the primary term and start from there
	$query = db_select('field_data_field_vocab_primary', 'vocab_primary')
					->fields('vocab_primary')
				 	->condition('entity_type', 'node')
				 	->condition('deleted', '0');
	$query->orderBy('entity_id', 'desc');
	
	if ($limit) {
		list($start, $limit) = explode(',', $limit);
		$query->range($start, $limit);
	}
	
	$id = drush_get_option('id');
	if ($id) {
		$first_char = substr($id, 0, 1);
		if ($first_char == '<') {
			$query->condition('entity_id', substr($id, 1), '<');
		}
		else if ($first_char == '>') {
			$query->condition('entity_id', substr($id, 1), '>');
		}
		else {
			$query->condition('entity_id', explode(',',$id), 'IN');
		}
	}
	
	$nodes = $query->execute();
	
	foreach ($nodes as $node) {
		$primary_vocab = '';
		$nid = $node->entity_id;
		
		$new_data = array();
		$group_id = 0;
		foreach($term_fields as $fieldname => $vid) {
			$tree = taxonomy_get_tree($term_fields[$fieldname], 0);
			$tree2 = array();
			foreach($tree as $_tree) {
				$tid = (int)$_tree->tid;
				$tree2[$tid] = $_tree;
			}

			$query = db_select('field_data_'.$fieldname, $fieldname)
							->fields($fieldname)
						 	->condition('entity_id', $nid);
			$query->orderBy('entity_id', 'asc');
			$result = $query->execute();

			$cnt = 1;
			$assigned_terms = array();
			foreach ($result as $record) {
				$fieldname_column = $fieldname . '_tid';
				$tid = $record->{$fieldname_column};
				
				if (isset($tree2[$tid])) {
					$t = $tree2[$tid];
					$assigned_terms[$t->depth][$tid] = $t;
				}
			}
			
			if (!$assigned_terms) continue;
			
			// start with depth 2 - Level 3
			if (isset($assigned_terms[2])) {
				foreach($assigned_terms[2] as $term) {
					$new_data[$group_id][3] = array('tid' => $term->tid, 'vid' => $term->vid);
					
					if (!is_array($term->parents)) continue; // impossible because this is depth 2
					$term = $tree2[$term->parents[0]];
					$new_data[$group_id][2] = array('tid' => $term->tid, 'vid' => $term->vid);
					
					if (!is_array($term->parents)) continue; // impossible because this is depth 2
					$term = $tree2[$term->parents[0]];
					$new_data[$group_id][1] = array('tid' => $term->tid, 'vid' => $term->vid);
					
					ksort($new_data[$group_id]);
					$group_id++;
				}
			}
			
			// level 2
			if (isset($assigned_terms[1])) {
				foreach($assigned_terms[1] as $term) {
					$tmp = array();
					$tmp[2] = array('tid' => $term->tid, 'vid' => $term->vid);
					
					if (!is_array($term->parents)) continue; // impossible because this is depth 2
					$term = $tree2[$term->parents[0]];
					$tmp[1] = array('tid' => $term->tid, 'vid' => $term->vid);
					
					$found = false;
					foreach($new_data as $ref) {
						if ($ref['2']['tid'] == $tmp['2']['tid'] && $ref['1']['tid'] == $tmp['1']['tid']) {
							$found = true;
						}
					}
					
					if ($found) continue;
					
					ksort($tmp);
					$new_data[$group_id] = $tmp;
					
					$group_id++;
				}
			}
			
			// level 1
			if (isset($assigned_terms[0])) {
				foreach($assigned_terms[0] as $term) {
					$tmp = array();
					$tmp[1] = array('tid' => $term->tid, 'vid' => $term->vid);
					
					$found = false;
					foreach($new_data as $ref) {
						if ($ref['1']['tid'] == $tmp['1']['tid']) {
							//debugm($tmp, 'dup');
							$found = true;
						}
					}
					
					if ($found) continue;
					
					ksort($tmp);
					$new_data[$group_id] = $tmp;
					
					$group_id++;
				}
			}
			
			//debugm($debug_data);
			//debugm($new_data, 'new');
		}
		
		
		// Get the primary vocab to be the first selection
		$primary_data = $primary_terms = array();
		if ($node->field_vocab_primary_value) {
			$pvocab = explode(',', $node->field_vocab_primary_value);
			
			$vid = $term_fields[$pvocab[0]];
			unset($pvocab[0]);
			
			// get the first data with that vid
			// we're getting them all so we're grouping them properly
			foreach($new_data as $group_id => $data) {
				foreach($data as $item) {
					if ($item['vid'] == $vid) {
						$primary_data[$group_id] = $data;
						unset($new_data[$group_id]);
						ksort($new_data);
					}
				}
			}
			
			// get exact term matches
			$level = count($pvocab);
			if ($level) {
				$tmp = array();
				$delta = 1;
				foreach($pvocab as $tid) {
					$tmp[$delta++] = array('tid' => $tid, 'vid' => $vid);
				}
				
				$primary_terms = array();
				switch($level) {
					case 1:
						foreach($primary_data as $group_id => $ref) {
							if ($ref['1']['tid'] == $tmp['1']['tid']) {
								$primary_terms[$group_id] = $ref;
								unset($primary_data[$group_id]);
								ksort($primary_data);
								break;
							}
						}

						break;
						
					case 2:
						foreach($primary_data as $group_id => $ref) {
							if ($ref['1']['tid'] == $tmp['1']['tid'] && $ref['2']['tid'] == $tmp['2']['tid']) {
								$primary_terms[$group_id] = $ref;
								unset($primary_data[$group_id]);
								ksort($primary_data);
								break;
							}
						}

						break;

					case 3:
						foreach($primary_data as $group_id => $ref) {
							if ($ref['1']['tid'] == $tmp['1']['tid'] 
							 && $ref['2']['tid'] == $tmp['2']['tid']
							 && $ref['3']['tid'] == $tmp['3']['tid']) {
								$primary_terms[$group_id] = $ref;
								unset($primary_data[$group_id]);
								ksort($primary_data);
								break;
							}
						}

						break;	
				}
				
				if ($primary_terms) {
					$primary_data = array_merge($primary_terms, $primary_data);
				}
			} // end of switch ($level)
		} // end of if ($level)
		
		$new_data = array_merge($primary_data, $new_data);
		
		$node = node_load($nid);
		$node->field_allterms = array();
		
		foreach($new_data as $group_id => $data) {
			foreach($data as $item) {
				$node->field_allterms['und'][] = array(
					'vid' => $item['vid'],
					'tid' => $item['tid'],
					'group' => $group_id+1,
				);
			}
		}
		
		if ($node->field_allterms['und']) {
			debugm('Updating node: ' . $nid);
			node_save($node);
		}
			
	}
	
	// field_data_field_vocab_primary
}

/* Update the viddler field from a CSV file */
function sm_migration_viddler_update() {
  // Update from DB
  
  
  // Update from CSV
	$dir = dirname(__FILE__);
	
	$file =  $dir . '/clientdata/complete_aw_video_token.csv';
	$content = file_get_contents($file);

	$rows = explode("\n", $content);
	
	$limit = drush_get_option('limit');
	
	$first = true;
	$cnt = 0;
	foreach($rows as $row) {
		if (empty($row)) continue;
		if ($first) {
			$first = false;
			continue;
		}
		
		$cnt++;
		$col = str_getcsv($row);
		$article_id = trim($col[0]);
		$viddler = trim($col[1]);
		
		if (!$article_id || !$viddler) continue;
		
		$query = db_select('field_data_field_joomla_id')
					 	->fields('node', array('nid'))
					 	->condition('entity_type', 'node')
					 	->condition('deleted', '0')
						->condition('field_joomla_id_value', $article_id);
		$query->leftJoin('node', 'node', 'node.nid=field_data_field_joomla_id.entity_id 
			AND node.vid=field_data_field_joomla_id.revision_id');
		$result = $query->execute();

		$nid = false;
		foreach ($result as $record) {
			$nid = $record->nid;
		}

		if (!$nid) {
			debugm($cnt . ' Missing article id: ' . $article_id);
			continue;
		}
		
		$node = node_load($nid);
		$node->field_viddler_id['und'][0]['value'] = $viddler;
		node_save($node);
		debugm($cnt . ' Updated node: ' . $nid . ' viddler: ' . $viddler);
		
		if ($cnt >= $limit) break;
	}
	
}

/* Add redirects from joomla patht o drupal path */
function sm_migration_add_redirects() {
	$node_type_replacements = array(
		'article' => 'article',
		//'page' => '',
		'blog' => 'blog',
		//'company' => 'supplier',
		'podcast'=> 'podcast',
		'video' => 'video',
		'webcast' => 'webcast',
		'whitepaper' => 'whitepaper',
	);
	
	$joomla_ids = _sm_get_joomla_ids_from_csv();
  foreach($joomla_ids as $joomla_id) {
    $query = db_select('node', 'node')
  				 	->fields('jtable', array('field_joomla_id_value'))
  					->fields('node', array('nid', 'type'))
  				 	->condition('entity_type', 'node')
  				 	->condition('jtable.field_joomla_id_value', $joomla_id)
  				 	->condition('deleted', '0');
  	$query->leftJoin('field_data_field_joomla_id', 'jtable', 'node.nid=jtable.entity_id AND node.vid=jtable.revision_id');
  	$result = $query->execute();
  	
  	foreach ($result as $record) {
  	  $node_id = $record->nid;
  	  
  	  // ==== Code to Add redirects
  	  $type = isset($node_type_replacements[$record->type]) ? $node_type_replacements[$record->type] : false;
  	  
  	  if ($type == 'page' || $type == 'blog') continue; // no blog and page will be added manually

  		if ($type == 'article') {
  			$query = Database::getConnection('default', 'joomla')
  								->select('jos_content', 'jcontent')
  			         	->fields('jcontent', array('content_type'))
  								->condition('jcontent.id', $joomla_id);
  			$finder = $query->execute();

  			foreach($finder as $finder1) {
  				$type = term_subtype_update($finder1->content_type);
  			}
  		}

  		$patterns = array(
  			'view-' . $joomla_id => 'view-' . $joomla_id
  		);

  		if ($type) {
  			$patterns[$type . '-' . $joomla_id] = $type . '-' . $joomla_id;
  		}
  		else {
  			debugm('Missing content type: ' . $joomla_id . ':' . $node_id);
  		}
      
      
  		$query = db_select('redirect', 'redirect')
  						->fields('redirect', array('source'))
  					 	->condition('redirect', 'node/'.$node_id);
  		$redirects = $query->execute();
  		foreach($redirects as $redirect) {
  			if (isset($patterns[$redirect->source])) unset($patterns[$redirect->source]);
  		}
      
  		if (!$patterns) continue;

      foreach($patterns as $pattern) {
  			$redirect = new stdClass();
  			$redirect->type = 'redirect';
  			$redirect->source = $pattern;
  			$redirect->source_options = array();
  			$redirect->redirect = 'node/' . $node_id;
  			$redirect->redirect_options = array();
  			$redirect->language = LANGUAGE_NONE;
  			$redirect->status_code = 301;
        
  			redirect_save($redirect);
  		}
	  }
  }
}

/* Helper function  */
function term_subtype_update($val) {
	switch($val) {
		case JOOMLA_PW_CTID_FEATURED_ARTICLE: return 'feature';
		//case JOOMLA_PW_CTID_WHITE_PAPER: return 'whitepaper';
		case JOOMLA_PW_CTID_PRODUCT: return 'products';
		case JOOMLA_PW_CTID_WEB_EXCLUSIVE: return 'webonly';
		case JOOMLA_PW_CTID_NEWS: return 'news';
		//case JOOMLA_PW_CTID_PODCAST: return 'podcast';
		case JOOMLA_PW_CTID_RESEARCH: return 'research';
		case JOOMLA_PW_CTID_PRIMER: return 'primers';
		case JOOMLA_PW_CTID_COLUMN: return 'columns';
		//case JOOMLA_PW_CTID_VIDEO: return 'video';
		//case JOOMLA_PW_CTID_BLOG: return 'blog';
		case JOOMLA_PW_CTID_EVENT: return 'events';
		case JOOMLA_PW_CTID_ELEARNING: return 'eLearning';
		case JOOMLA_PW_CTID_PERSPECTIVE: return 'perspective';
		case JOOMLA_PW_CTID_CASE_APPLICATION: return 'case_application';
	}
	
	return false;
}

/* Legacy code */
function sm_migration_update_image() {
  set_time_limit(3600);
	ini_set('memory_limit', '256M');
  
  
	$id = drush_get_option('id');
	$limit = (int)drush_get_option('limit');
	
	$query = Database::getConnection('default', 'joomla')
						->select('jos_content', 'jcontent')
	         	->fields('jcontent')
						->condition('state', 1);
						//->condition('images', '', '!=');
	$query->groupBy('jcontent.id');
					
	if ($id) {
		$first_char = substr($id, 0, 1);
		if ($first_char == '<') {
			$query->condition('jcontent.id', substr($id, 1), '<');
		}
		else if ($first_char == '>') {
			$query->condition('jcontent.id', substr($id, 1), '>');
		}
		else {
			$query->condition('jcontent.id', explode(',',$id), 'IN');
		}
	}
	
	/*if ($limit) {
		list($start, $limit) = explode(',', $limit);
		
	}*/
	
	$query->orderBy('id', 'desc');
	$result = $query->execute();
	
	$ids = array();
	$cnt = 1;
	$process_cnt = 0;
	
	foreach ($result as $record) {
		$joomla_id = $record->id;
		
		$images = array();
	  $images = explode("\n", $record->images);
		$image_string = '{mosimage}';
		
		// Get the node object
		$query = db_select('field_data_field_joomla_id')
					 	->fields('node', array('nid'))
					 	->condition('entity_type', 'node')
					 	->condition('deleted', '0')
						->condition('field_joomla_id_value', $joomla_id);
		$query->leftJoin('node', 'node', 'node.nid=field_data_field_joomla_id.entity_id 
			AND node.vid=field_data_field_joomla_id.revision_id');
		$tmp = $query->execute();

		$nid = false;
		foreach ($tmp as $tmp2) {
			$nid = $tmp2->nid;
		}
		
		if (!$nid) {
			debugm('Missing article id: ' . $joomla_id);
			continue;
		}
		
		$n = 0;
		$node = node_load($nid);
		$node->field_image = array();
		$node->field_article_images = array();
		
		foreach($images as $j_image) {
			$images_items = explode("|", $j_image);
			$joomla_img = trim($images_items[0]);
			
			if (!$joomla_img) continue;
			
			$filename = basename($joomla_img);
			$full_path = 'public://images/'.$joomla_img;
			
			$err = false;
			$realpath = drupal_realpath($full_path);
			if (!$realpath || !file_exists($realpath)) {
				debugm("[jid:$joomla_id nid:$node->nid] Missing image file: $full_path");
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
					$node->field_image['und'][] = (array)$file;
				}
				else { 
					// subimage
					$node->field_article_images['und'][] = (array)$file;
				}
				
				$n++;
			}
		}
		
		$joomla_body = $joomla_teaser = '';
		$update_me = false;
		$joomla_body = $record->fulltext;
		if (!empty($record->introtext)) {
      $joomla_teaser = trim($record->introtext);
      $update_me = true;
    }
    else {
      $joomla_teaser = '';
    }
		
		// Image update
	  $update_me = true;
    $joomla_body   = str_replace('{mospagebreak}', '', $joomla_body);
		$joomla_body   = str_replace('{easycomments}', '', $joomla_body);

		$joomla_teaser = preg_replace('/{mosimage}/', '', $joomla_teaser);
    $joomla_body   = preg_replace('/{mosimage}/', '', $joomla_body);
		$joomla_teaser = preg_replace('/{mosiamge}/', '', $joomla_teaser);
    $joomla_body   = preg_replace('/{mosiamge}/', '', $joomla_body);

		$joomla_teaser = replace_image_link($joomla_teaser);
    $joomla_body   = replace_image_link($joomla_body);
    
		
		// Deckhead change
		$node->field_deckhead['und'][0]['value'] = strip_tags($joomla_teaser);
		
		
		// prepend URL
		if (preg_match('/(<a href=["|\'])(www)\./', $joomla_body)) {
		  $joomla_body = preg_replace('/(<a href=["|\'])(www)\./', '$1http://www.', $joomla_body);
		  $joomla_teaser = preg_replace('/(<a href=["|\'])(www)\./', '$1http://www.', $joomla_teaser);
		}
		
		// add viddler ID - Video
		$viddler_id = '';
		if ($record->postcard_id && substr($record->postcard_id, 0, 13) == 'viddlerOuter-') {
		  $viddler_id = str_replace('viddlerOuter-', '', $record->postcard_id);
		  $node->field_viddler_id['und'][0]['value'] = $viddler_id;
		  $update_me = true;
		  
		  // <!--[if IE]> <!--<![endif]-->
  		$pattern = '@(<!--\[if IE\]>.*<!--<!\[endif\]-->)@';
  		if (preg_match($pattern, $joomla_body)) {
  		  $joomla_body = preg_replace($pattern, '', $joomla_body);
  		  debugm('Found video embed ' . $node->nid . ' [jid:'.$joomla_id.']');
  		}
		}
		
		if ($update_me) {
		  $node->body['und'][0]['value'] = $joomla_body;
			$node->body['und'][0]['summary'] = '';
			
		  debugm('Saving node ' . $node->nid . ' [jid:'.$joomla_id.']');
		  node_save($node);
			$process_cnt++;
		}
		
		if ($limit && $process_cnt >= $limit) break;
	}
}

/* Helper function  */
function replace_image_link($text_source) {
  //Fixs image string: src="images/
  $image_string = 'src="images/';
  $images_replace = 'src="'. base_path() . variable_get('file_public_path', conf_path() . '/files/') 
		. 'images/';

  $text_result = str_replace('src="images/', "$images_replace", $text_source);

  return $text_result;
}

/* Helper function  */
function htmldecode($val) {
	$title = htmlspecialchars($val, ENT_QUOTES, 'UTF-8');
	
	$update = false;
	if (strstr($title, '&amp;#145;') || strstr($title, '&amp;#146;')) {
		$title = str_replace('&amp;#145;', '\'', $title);
		$title = str_replace('&amp;#146;', '\'', $title);
	}
	
	if (strstr($title, '&amp;#147;') || strstr($title, '&amp;#148;')) {
		$title = str_replace('&amp;#147;', '"', $title);
		$title = str_replace('&amp;#148;', '"', $title);
	}

	$val = $title;
	
	$val = html_entity_decode($val, ENT_QUOTES, 'UTF-8');
	$val = preg_replace('/(&#[0-9]{2})/', '$1;', $val);
	
	$val = iconv("UTF-8", "ASCII//TRANSLIT", $val); 
	$val = htmlentities(html_entity_decode(utf8_encode($val)));
	
	$replacements = array(
		'&quot;' => '"',
		'&amp;#39;;' => '\'',
		'&eacute;' => utf8_encode('é'),
		'&Eacute;' => utf8_encode('É'),
		'&deg;' => utf8_encode('°'),
		'&lt;' => '<',
		'&gt;' => '>',
		// this should be last
		'&amp;' => '&',
		'Nestl?' => 'Nestlé',
		'Expr?sses' => 'Exprésses',
		'Est?e' => 'Estée',
		'entr?e' => 'entrée',
		'L\'Or?al' => 'L\'Oréal',
		'Kl?ckner' => 'Klöckner',
		'?Qu?' => '¿Qué',
		'(R)' => '®',
		'(TM)' => '™',
		'pat?' => 'paté',
		'mariv?' => 'mariví',
		'?ask' => '¿ask',
		'd?cor' => 'décor',
		'consomm?' => 'consommé',
		'Pr?mio' => 'Prémio',
		'Gavi?a' => 'Gaviña',
		'Caf?' => 'Café',
		'S?o' => 'São',
		'360?' => '360º',
		'Clich?' => 'Cliché',
		'p?t?' => 'pâté',
		'S?ren Br?utigam' => 'Sören Bräutigam',
		'H?fliger' => 'Höfliger',
		'W?chter' => 'Wächter',
		'D?sseldorf' => 'Düsseldorf',
		'EtherNet/IP?' => 'EtherNet/IP£'
	);
	
	foreach($replacements as $find => $replace) {
		if (strstr($val, $find)) {
			$val = str_replace($find, $replace, $val);
			$val = utf8_encode($val);
		}
	}
	
	return $val;
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
