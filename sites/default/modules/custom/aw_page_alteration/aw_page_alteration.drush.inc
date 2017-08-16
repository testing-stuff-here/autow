<?php

/**
 * Implements hook_drush_command()
 */
function aw_page_alteration_drush_command() {
  $items['aw-page-alteration-update-taxonomy'] = array(
    'description' => 'Update the field_terms field using new vocabularies (Technology and Topics)',
    'arguments' => array(
      'nid' => t('Node ID of node to update'),
    ),
  );

  return $items;
}

function drush_aw_page_alteration_update_taxonomy($nid){
  if($nid){
    $node = node_load($nid);
    if(property_exists($node, 'field_allterms') && isset($node->field_allterms['und'])){
      _aw_taxonomy_update_mapping_node($node);
    }
  }
  else {
    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'node');
    $query->propertyCondition('status',1);
    $query->fieldCondition('field_allterms', 'tid', 'NULL', '!=');
    $result = $query->execute();
  }
}

/**
 * Helper function, updates taxonomy for a given node
 */
function _aw_taxonomy_update_mapping_node($node){

  $new_allterms = array();
  $mapping_cache = variable_get('taxonomy_mapping');
  $mapping_cache = json_decode($mapping_cache, true);
  $mapping_cache = _aw_taxonomy_mapping_format($mapping_cache);
  $groups = array();
  foreach($node->field_allterms['und'] as $key => $term){
    $groups[$term['group']][$key] = $term;
  }
  foreach($groups as $group_key => $group){
    $group_term = end($group);
    if(array_key_exists($group_term['tid'], $mapping_cache) && $mapping_cache[$group_term['tid']]){
      if($mapping_cache[$group_term['tid']]['delete']){
        unset($groups[$group_key]);
      }
      else {
        $new_temp_group = array();
        $map_to_tid = $mapping_cache[$group_term['tid']]['tid'];
        $parents = taxonomy_get_parents_all($map_to_tid);
        $parents = array_reverse($parents);
        foreach($parents as $p){
          $new_temp_group[] = array(
            'vid' => $p->vid,
            'tid' => $p->tid,
            'group' => $group_key,
          );
        }
        $groups[$group_key] = $new_temp_group;
      }
    }
  }
  $new_group_number = 1;
  foreach($groups as $group_key2 => $group2){
    foreach($group2 as $group2_term_key => $group2_term){
      $group2[$group2_term_key]["group"] = $new_group_number;
    }
    $new_allterms = array_merge($new_allterms, $group2);
    $new_group_number++;
  }
  $node->field_allterms['und'] = $new_allterms;
  node_save($node);
}

/**
 * Helper function, converts the taxonomy_mapping variable into a more useful format
 */
function _aw_taxonomy_mapping_format($mapping_cache){
  $mapping_formatted = array();

  // Go through the form and look for terms with the "include_children" key set to true,
  // and copy it's mapping value into it's children
  foreach($mapping_cache as $tid => $t_map){
    if($t_map["include_children"] && $t_map["new_term"]){
      $parent_map_vocab = (strlen($t_map["new_term_technology"]) > 0) ? "new_term_technology" : ((strlen($t_map["new_term_topics"]) > 0) ? "new_term_topics" : FALSE);
      $children = taxonomy_get_children($tid);
      foreach($children as $child_tid => $child){
        $mapping_cache[$child_tid][$parent_map_vocab] = $t_map["new_term"];
        $mapping_cache[$child_tid]["new_term"] = $t_map["new_term"];
      }
    }
  }

  foreach($mapping_cache as $key => $value){
    if($value["new_term"] || $value["delete"]){
      $mapping_formatted[$key] = array(
        "tid" => $value["new_term"],
        "vid" => (strlen($value["new_term_technology"]) > 0) ? '13' : '14',
        "delete" => $value["delete"],
      );
    }
  }

  return $mapping_formatted;
}

