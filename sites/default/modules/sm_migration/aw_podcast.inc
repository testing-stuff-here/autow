<?php
class AwPodcastMigration extends AwArticleMigration {
	public $missing;
	
	public function __construct() {
    parent::__construct();

		$query = Database::getConnection('default', 'joomla')
							->select('jos_content', 'jcontent')
		         	->fields('jcontent')
							->condition('state', 1)
							->condition(db_or()->condition('modified', '2011-10-31 00:00:00', '>')->condition('created', '2011-10-31 00:00:00', '>'))
							->condition('content_type', array(
								JOOMLA_PW_CTID_PODCAST), 'IN');
		$query->leftJoin('content_category_xref', 'jcat', 'jcat.content_id=jcontent.id');
		$query->addExpression('GROUP_CONCAT(DISTINCT jcat.category_id SEPARATOR \'~\')', 'cat_list');
		$query->groupBy('jcontent.id');
		$query->orderBy('id');
		
		$count_query = Database::getConnection('default', 'joomla')
      ->select('jos_content', 'jcontent');
    $count_query->addExpression('COUNT(id)', 'cnt');
		
	  $this->source = new MigrateSourceSQL($query, array(), $count_query);
		$this->destination = new MigrateDestinationNode('podcast');
		
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

		$this->addFieldMapping('field_podcast', 'filename')
				 ->arguments(array('preserveFiles' => TRUE));
				
		$this->addFieldMapping('field_term_subtype', 'content_type')
		     ->issueGroup(t('DNM'));
	}
	
	function prepare($account, $row) {
		parent::prepare($account, $row);
		
		// Podcast file
		if ($row->filename) {
			$filename = basename($row->filename);
			$full_path = 'public://podcastmedia/' . $filename;
			
			$err = false;
			$realpath = drupal_realpath($full_path);
			if (!$realpath || !file_exists($realpath)) {
				//$this->missing[] = $full_path;
				debugm("Missing podcast file: [$row->id] $full_path");
				$err = true;
			}
			
			if (!$err) {
				$query = db_select('file_managed')
							 ->fields('file_managed')
							 ->condition('uri', $full_path)
							 ->execute();

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
					$file->description = $row->name;

					$account->field_podcast['und'][0] = (array)$file;
				}
			}
			
		}
	}
	
}

