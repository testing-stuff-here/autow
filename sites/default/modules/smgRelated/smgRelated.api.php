<?php

/**
 * Hook for handling the query for getting related nodes
 *
 * @param $tid - the term id
 * @param $used_nodes_already - all the nodes that have been used. Useful for excluding the nodes from the query
 * @param $sponsored - Boolean
 *
 * @see smgRelated_get_nodes()
 */
function hook_smgRelated_get_nodes($tid, $used_nodes_already, $sponsored = FALSE) {

}

/**
 * Hook for altering the way the default smgRelated block is rendered
 */
function hook_smgRelated_get_related_rendered_default($rendered, $path, $options) {
  
  return $rendered;
}

