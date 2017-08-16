<?php
  
/**
 * Implements hook_drush_command().
 */  
function smg_script_drush_command() {
  $items = array();
  $items['title-add-company'] = array(
    'description' => 'Go through nodes, add "[company-name]:" to any products',
    'drupal dependencies' => array('smg_script'),
    'arguments' => array(
      'site' => t('The name of the web site, exactly like url domain, no spaces or hyphens'),
    ),
    'required-arguments' => TRUE,
    'examples' => array(
      'Packworld' => 'drush title-add-company packworld',
      'Healthcare Packaging' => 'drush title-add-company healthcarepackaging',
      'Automation World' => 'drush title-add-company automationworld',
    ),
    'aliases' => array('tac'),
  );
  $items['industry-type-alter'] = array( // #838
    'description' => 'Convert articles/blogs Industry Type taxonomy',
    'drupal dependencies' => array('smg_script'),
  );
  $items['add-nofollow'] = array(
    'description' => 'Go through all nodes that have the source type that was provided as the argument, and look for <a> tags, and add rel="nofollow" to each <a> tag',
    'drupal dependencies' => array('smg_script'),
    'arguments' => array(
      'tid' => t('The Source Type TID'),
      'tid2' => t('Second TID'),
      'tid3' => t('Third TID'),
      'tid4' => t('Fourth TID'),
    ),
    'required-arguments' => 1,
    'options' => array(
      'exclude' => 'NID\'s of nodes that are to be excluded from the command, comma delimeted (e.g. 100, 101)',
    ),
    'examples' => array(
      'Packworld - Supplier Submitted Content' => 'drush add-nofollow 163',
      'Packworld - Supplier Submitted and Lead Gen, excluding node 48786' => 'drush add-nofollow 163 165 --exclude=48786',
    ),
  );
  $items['fix-bad-company-node-reference'] = array(
    'description' => 'When you delete a company it causes errors on the nodes it was on. This script will find the companies and remove them from the nodes',
    'examples' => array('drush fix-bad-company-node-reference'),
  );
  return $items;
}

/**
 * #838 If article has all three of the previous Industry Type taxonomies, then just set that
 * article to have the new Industry Type term 'All'
 */
function drush_smg_script_industry_type_alter() {
  // Get all nodes with all three terms
  $query = new EntityFieldQuery();
  $query->entityCondition("entity_type", "node")
    //->entityCondition('bundle', 'video', '!=')
    ->fieldCondition("field_allterms", "tid", "106")
    ->fieldCondition("field_allterms", "tid", "107")
    ->fieldCondition("field_allterms", "tid", "105");

  $result = $query->execute();

  if (isset($result['node'])) {
    $nids = array_keys($result['node']);
    $nodes = entity_load('node', $nids);
    foreach ($nodes as $node) {
      $group_id = 12;
      foreach ($node->field_allterms['und'] as $key => $term) {
        if (in_array($term['tid'], array("105", "106", "107"))) {
          $group_id = $node->field_allterms['und'][$key]['group'];
          unset($node->field_allterms['und'][$key]);
        }
      }

      $node->field_allterms['und'][] = array(
        'vid' => '3',
        'tid' => '3000',
        'group' => $group_id,
      );
      node_save($node);
      drush_log(('Updated Node: ' . $node->nid), 'ok');
    }
  }
}

/**
 * Function will iterate through all of the site's article nodes, determining which nodes are products
 * It will prepend the name of the company and a colon to the title, for product nodes
 * @param $site - The name of the site: either packworld, healthcarepackaging, or automationworld
 *
 *   *************** DO NOT RUN THIS DRUSH COMMAND MORE THAN ONCE PER CODEBASE   
 *   *   WARNING   * YOU WILL GET FUNKY OUTPUT THAT WILL LOOK SOMETHING LIKE
 *   *************** COMPANY-NAME: COMPANY-NAME: ARTICLE-TITLE
 */
function drush_smg_script_title_add_company($site) {
  // array that will hold the tids of the following subtype taxonomy terms (on HCP and PW): Controls Product Brief,
  // Machine Product Brief, and Materials Product Brief.  And the term Product on AW.
  $subtype_tids = array();
  switch($site) {
    case 'packworld':
      $subtype_tids = array('176','174','175');
      break;
    case 'healthcarepackaging':
      $subtype_tids = array('6502', '6500', '6501');
      break;
    case 'automationworld':
      $subtype_tids = array('166');
      break;
  }
  
  // run a query that selects Article nodes tagged with the correct subtype tids
  $query = db_select('node','n');
  $query->join('field_data_field_companies', 'c', 'n.nid = c.entity_id');
  $query->join('field_data_field_term_subtype', 's', 'n.nid = s.entity_id');
  $results = $query
    ->condition('n.type', 'article', '=')
    ->condition('n.created',  922924800, '<')
    ->condition('s.field_term_subtype_tid', $subtype_tids, 'IN')
    ->fields('n', array('nid'))
    ->orderBy('n.created', 'DESC')
    ->execute();

  foreach($results as $result) {
    $node = node_load($result->nid);
    $article_title = $node->title;
    if(isset($node->field_companies['und'][0])) {
      $company = node_load($node->field_companies['und'][0]['nid']);
      $title = $company->title;
      $title = preg_replace('/Inc\./', 'Inc', $title);
      $node->title = $title . ': ' . $article_title;
      node_save($node);
    }
  }

}

/**
 * Iterate through all of the nodes that match the source type provided as the argument
 * then look for <a> tags in each of the nodes deckhead and body fields, and add rel="nofollow"
 *
 * @param string $tid - The Source Type TID
 */
function drush_smg_script_add_nofollow($tid, $tid2 = null, $tid3 = null, $tid4 = null){
  $num_args = func_num_args(); // how many arguments were provided to this funciton
  $arg_list = func_get_args(); // get the function arguments
  $tids = array(); // will hold provided tids
  for($i = 0; $i < $num_args; $i++){
    $tids[] = $arg_list[$i];
  }
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type','node')
    ->propertyCondition('status',1)
    ->fieldCondition('field_term_source_type', 'tid', $tids, 'IN');

  $result = $query->execute();

  $nid_array = array();
  foreach($result['node'] as $node) {
    $nid_array[] = $node->nid;
  }

  $all_node = node_load_multiple($nid_array);
  
  // create an array of nodes to exclude from the command, based on nids that were passed as option 
  // to the command
  $avoid = array();
  if($avoid_nids = drush_get_option('exclude')){
    $avoid = explode(',', $avoid_nids);
  }

  $node_counter = 0;
  foreach($all_node as $nid => $node) {  
    $node_object = node_load($nid);
    $body = $node_object->body['und'][0]['value'];
    $body_safe = $node_object->body['und'][0]['safe_value'];
    $modified_body = preg_replace_callback('|<a( )href="([a-zA-Z0-9\.-_~:/\?#\[\]@\!\$\(\);\%]*)"|', 'modify_link', $body);
    $modified_safe = preg_replace_callback('|<a( )href="([a-zA-Z0-9\.-_~:/\?#\[\]@\!\$\(\);\%]*)"|', 'modify_link', $body_safe);
    $node_object->body['und'][0]['value'] = $modified_body;
    $node_object->body['und'][0]['safe_value'] = $modified_safe;

    $deckhead = $node_object->field_deckhead['und'][0]['value'];
    $deckhead_safe = $node_object->field_deckhead['und'][0]['safe_value'];
    $modified_deckhead = preg_replace_callback('|<a( )href="([a-zA-Z0-9\.-_~:/\?#\[\]@\!\$\(\);\%]*)"|', 'modify_link', $deckhead);
    $modified_safe = preg_replace_callback('|<a( )href="([a-zA-Z0-9\.-_~:/\?#\[\]@\!\$\(\);\%]*)"|', 'modify_link', $deckhead_safe);
    $node_object->field_deckhead['und'][0]['value'] = $modified_deckhead;
    $node_object->field_deckhead['und'][0]['safe_value'] = $modified_safe;
    if(!in_array($node_object->nid , $avoid)){
      node_save($node_object);
    }
    $node_counter++;
  }
  drush_log(($node_counter . ' Nodes were updated'), 'ok');
}

/**
 * Regex callback function
 */
function modify_link($matches) {
  if((strpos($matches[2], 'packworld') == false && strpos($matches[2], 'autoworld') == false && strpos($matches[2], 'healthcarepackaging') == false) && strpos($matches[2], 'http') !== false) {
    return '<a rel="nofollow" href="' . $matches[2] . '"';
  }else{
    return $matches[0];
  }
}

/**
 * Fix nodes that have bad company references.  Basically if you delete a company, all the nodes
 * that have that company give an error.
 */
function drush_smg_script_fix_bad_company_node_reference() {
  $query = db_select('field_data_field_companies', 'f')
    ->fields('f', array('entity_id', 'field_companies_nid'))
    ->where('f.field_companies_nid NOT IN(select nid from {node})');  
  $results = $query->execute();
  $i = 0;
  if($results) {
    foreach($results as $result) {
      echo "updated {$result->entity_id}\n";
      $node = node_load($result->entity_id);
      foreach($node->field_companies['und'] as $key => $n) {
        if($n['nid'] == $result->field_companies_nid) {
          unset($node->field_companies['und'][$key]);
        }
      }
      node_save($node);
      $i++;
    } 
  }
  
  echo "$i nodes updated!\n";
}