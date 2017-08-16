<?php
class AwBlogMigration extends AwArticleMigration {
	public $missing;
	
	public function __construct() {
    parent::__construct();

		$query = Database::getConnection('default', 'joomla')
							->select('jos_content', 'jcontent')
		         	->fields('jcontent')
							->condition('state', 1)
							->condition(db_or()->condition('modified', '2011-10-31 00:00:00', '>')->condition('created', '2011-10-31 00:00:00', '>'))
							->condition(
								db_or()->condition('content_type', JOOMLA_PW_CTID_BLOG)
											 ->condition('jcontent.created_by_alias', 'Gary Mintchell, from the Feed Forward Blog%', 'LIKE')
											 ->condition('jcontent.created_by_alias', 'Keith Campbell, On the Edge Blog%', 'LIKE')
											);
							
		$query->leftJoin('content_category_xref', 'jcat', 'jcat.content_id=jcontent.id');
		$query->addExpression('GROUP_CONCAT(DISTINCT jcat.category_id SEPARATOR \'~\')', 'cat_list');
		$query->groupBy('jcontent.id');
		//$query->orderBy('modified');
		$query->orderBy('id', 'desc');
		$query->orderRandom();
		
		//$query->range(0,100);
		
		$count_query = Database::getConnection('default', 'joomla')
      ->select('jos_content', 'jcontent');
    $count_query->addExpression('COUNT(id)', 'cnt');
		
	  $this->source = new MigrateSourceSQL($query, array(), $count_query);
		$this->destination = new MigrateDestinationNode('blog');
		
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
	
		$this->addFieldMapping('field_term_subtype', 'content_type')
		     ->issueGroup(t('DNM'));
	}
	
	function prepare($account, $row) {
		parent::prepare($account, $row);
		
		// 
		if (strstr($row->created_by_alias, 'Gary Mintchell, from the Feed Forward Blog')) {
			$account->uid = 10;
		}
		else if (strstr($row->created_by_alias, 'Keith Campbell, On the Edge Blog')) {
			$account->uid = 11;
		}
		
	}
	
}

