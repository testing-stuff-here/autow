<?php
/***************************************************************
 * Field Type API hooks
 ***************************************************************/

/**
 * Implement hook_field_info().
 */
function reltw_field_info() {
  return array(
    'reltw_field' => array(
	    'label' => t('Multiple Terms'),
  	  'description' => t('Stores the primary vocab.'),
  	  'default_widget' => 'reltw_widget',
  	  'default_formatter' => 'reltw_default',
  	  'instance_settings' => array(
        'vids' => array(),
      ),
	  ),
  );
}

/**
 * Implement hook_field_schema().
 */
function reltw_field_schema($field) {
  $columns = array(
    'vid' => array('type' => 'int', 'length' => 11, 'not null' => FALSE),
    'tid' => array('type' => 'int', 'length' => 11, 'not null' => FALSE),
    'group' => array('type' => 'int', 'length' => 11, 'not null' => FALSE),
  );
  return array('columns' => $columns);
}


/**
 * Implement hook_field_is_empty().
 */
function reltw_field_is_empty($item, $field) {
	// we are dealing this in hook_field_validate()
  return false;
}

/***********************************************************************
 *  Field Type API: Formatter
 **********************************************************************/

/**
 * Implement hook_field_formatter_info().
 */
function reltw_field_formatter_info() {
  return array(
    'reltw_default' => array(
      'label' => t('Plain'),
      'field types' => array('reltw_field'),
    ),
  );
}

/**
 * Implements hook_field_instance_settings_form().
 */
function reltw_field_instance_settings_form($field, $instance) {
  $settings = $instance['settings'];

  $v = taxonomy_get_vocabularies();
  $options = array();
  foreach($v as $item) {
    $options[$item->vid] = $item->name;
  }
  $form['vids'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Vocabularies'),
    '#default_value' => $settings['vids'],
    '#description' => t('Description here'),
    '#options' => $options
  );

  return $form;
}

/**
 * Implements hook_field_formatter_view().
 */
function reltw_field_formatter_view($object_type, $object, $field, $instance, $langcode, $items, $display) {
  $element = array();

	$groups = array();
	foreach($items as $item) {
		if (!isset($item['vid'])) continue;
		$groups[$item['group']][] = $item;
	}

	$delta = 0;
	foreach($groups as $group) {
		$first = true;
		$markup = '';
		foreach($group as $item) {
			if ($first) {
				$vocab = taxonomy_vocabulary_load($item['vid']);
				$markup = $vocab->name;
				$first = false;
			}

			$term = taxonomy_term_load($item['tid']);
			if($term) {
			  $uri = entity_uri('taxonomy_term', $term);
			  $markup .= ' &raquo; ' . l($term->name, $uri['path'], $uri['options']);
		  }
		}

		$element[$delta] = array(
      '#markup' => $markup
    );
		$delta++;
	}

  return $element;
}

/**************************************************************************
 * Field Type API: Widget
 **************************************************************************/

/**
 * Implement hook_field_widget_info().
 */
function reltw_field_widget_info() {
  return array(
    'reltw_widget' => array(
	    'label' => t('Select list'),
	    'field types' => array('reltw_field'),
			'behaviors' => array(
        'multiple values' => FIELD_BEHAVIOR_CUSTOM,
				'default value' => FIELD_BEHAVIOR_NONE,
      ),
	  ),
  );
}

/**
 * Implement hook_field_widget().
 * Todo: When saving default value in settings, it also enter here. so i need to consider default values. and how to display them in the settings page
 */
function reltw_field_widget_form(&$form, &$form_state, $field, $instance, $langcode, $items, $delta, $element) {
	$fieldname 	= $field['field_name'];
	$parents 		= $form['#parents'];

	$id_prefix 	= implode('-', array_merge($parents, array($fieldname)));
  $wrapper_id = drupal_html_id($id_prefix . '-add-more-wrapper');
	$group_id = 0;

	if ($_POST && isset($_POST['op']) && $_POST[$fieldname][$langcode]) {
		$group_id = explode('-', $_POST['group_id']);
		$group_id = array_pop($group_id);

		switch($_POST['op']) {
			case 'Update':
				$items = _reltw_field_process_post_data($_POST[$fieldname][$langcode]);
			break;
		}

	}

	// Setting up the necessary css and js and other field settings for the page load. should not be done with ajax call
	$reltw_id = $instance['field_id'];
	$element['#prefix'] = '<div class="reltw-field-wrapper" id="reltw-field-'.$reltw_id.'">';
	$element['#suffix'] = '</div>';

	$settings =  array(
     'ReltwField' => array(
       'settings' => array(
         "reltw_id-$reltw_id" => array(
           'ajax_url' => url('reltw_field_ajax') . '/' . $fieldname,
        	),
       	),
     ),
  );

	$element['#attached']['css'][] = drupal_get_path('module', 'reltw') . '/reltw_field.css';
	$element['#attached']['js'][] = drupal_get_path('module', 'reltw') . '/reltw_field.js';
	if (!isset($_POST['reltw_id'])) {
    $element['#attached']['js'][] = array(
      'type' => 'setting',
      'data' => $settings,
    );
  }

	$element['#type'] = 'fieldset';
	$element['reltw_allowed_vids'] = array(
		'#type' => 'value',
		'#value' => $instance['settings']['vids'],
	);


	// Regroup the items into separate vocabulary groups. That's how our _reltw_field_create_field_group() works
	$groups = array();
	foreach($items as $item) {
		if (!isset($item['vid'])) continue;
		$groups[$item['group']][] = $item;
	}


	// resort the group numbers
	ksort($groups);
	$groups = array_merge(array(0=>0),$groups); // we want the group to start at 1, not 0
	unset($groups[0]);
	foreach($groups as $key => $group) {
		if ($group[0]['group'] == $key) continue;
		foreach($group as $item_key => $item) {
			$groups[$key][$item_key]['group'] = $key;
		}
	}

	// Creating the Fields
	foreach($groups as $group_id => $items) {
		$element += _reltw_field_create_field_group($group_id, $items, $instance['settings']['vids']);
	}

	// Add an empty select box if this was not still added
	$add_empty_box = false;

	if (!$groups) $add_empty_box = true;
	else if (!isset($element['reltw_group_'.$group_id]['reltw_field'])) $add_empty_box = true;
	else {
		$last_element = end($element['reltw_group_'.$group_id]['reltw_field']);
		if ($last_element['vid']) {
			$add_empty_box = true;
		}
	}

	if ($add_empty_box) {
		$group_id++;
		$element += _reltw_field_create_field_group($group_id, array(), $instance['settings']['vids']);
	}

	return $element;
}

/**
 * Creates the select field groups - vocabulary and term pairing
 */
function _reltw_field_create_field_group($group_id, $items, $allowed_vids) {
	$element = array();
	$element['reltw_group_'.$group_id] = array(
		'#type' => 'fieldset',
		'#attributes' => array('class' => array('reltw_group'))
		);
	$element['reltw_group_'.$group_id]['reltw_field'] = _reltw_field_create_field($items, $allowed_vids);

	return $element;
}

/**
 * Function that handles the logic of rearranging/recreating the select fields for parent - children pairing
 */
function _reltw_field_create_field($items, $allowed_vids, $ajax=false) {
	$element = array();

	$v = taxonomy_get_vocabularies();
  $vocabs = array('' => 'Select');
  foreach($v as $item) {
		if (in_array($item->vid, $allowed_vids))
    	$vocabs[$item->vid] = $item->name;
  }

	$selected_vid = 0;
	$selected_tid = array();
	foreach($items as $key => $item) {
		if (!$item['vid']) continue;

		if (!$selected_vid) {
			$selected_vid = $item['vid'];
		}

		$selected_tid[] = $item;
	}

	$level = 1;
	foreach ($selected_tid as $key => $item) {
		//if (!$item['tid']) continue;
		if ($item['vid'] != $selected_vid) break;

		// Set the vocabulary select field
		if ($key == 0) {
			$new_field['vid'] = array(
		    '#type' => 'select',
		    '#default_value' => $item['vid'],
				'#value' => $item['vid'],
				'#options' => $vocabs,
				'#attributes' => array('class' => array('vocab'))
		  );

			$term_options = array();
			$terms = taxonomy_get_tree($item['vid'], 0, 1);
			foreach($terms as $obj) {
				$term_options[$obj->tid] = $obj->name;
			}

			$new_field['tid'] = array(
		    '#type' => 'select',
		    '#default_value' => $item['tid'],
				'#value' => $item['tid'],
				'#options' => array('' => '') + $term_options,
				'#attributes' => array('class' => array('reltw-level' . $level))
		  );

			$element[$level++] = $new_field;

			// If vid changed, tid doesnt match anymore, we'll stop here
			if (!isset($element[$level - 1]['tid']['#options'][$item['tid']])) {
				break;
			}
		}

		if ($key > 0) {
			if (!isset($element[$level - 1]['tid']['#options'][$item['tid']])) {
				continue;
			}

			$element[$level - 1]['tid']['#default_value'] = $item['tid'];
			$element[$level - 1]['tid']['#value'] = $item['tid'];
		}

		// Get the children term select field
		$term_options = array();
		$terms = taxonomy_get_children($item['tid']);
		if ($terms) {
			foreach($terms as $obj) {
				$term_options[$obj->tid] = $obj->name;
			}

			$new_field['vid'] = array(
		    '#type' => 'hidden',
		    '#value' => $item['vid'],
		  );

			$new_field['tid'] = array(
		    '#type' => 'select',
		    '#default_value' => '',
				'#options' => array('' => '') + $term_options,
				'#attributes' => array('class' => array('reltw-level' . $level))
		  );

			$element[$level++] = $new_field;
		}

	}

	if (empty($element)) {
		$new_field['vid'] = array(
	    '#type' => 'select',
	    '#default_value' => 0,
			'#value' => 0,
			'#options' => $vocabs,
			'#attributes' => array('class' => array('vocab'))
	  );
		$element[$level] = $new_field;
	}




	return $element;
}


/**
 * Implements hook_field_update()
 * TODO: redo to use form_set_value(). see options_field_widget_validate()
 */
function reltw_field_insert($entity_type, $entity, $field, $instance, $langcode, &$items) {
	$fieldname = $field['field_name'];
	if (isset($_POST[$fieldname][$langcode])) {
		$items = _reltw_form_to_storage($field, $langcode);
		_reltw_cleanup_submitted_items($items);
	}

	// We maintain a denormalized table of term/node relationships, containing
  // only data for current, published nodes.
  if (variable_get('taxonomy_maintain_index_table', TRUE) && $field['storage']['type'] == 'field_sql_storage' && $entity_type == 'node' && $entity->status) {
    $query = db_insert('taxonomy_index')->fields(array('nid', 'tid', 'sticky', 'created', ));
    foreach ($items as $key => $item) {
			if ($item['tid'] == 0) {
				unset($items[$key]); // we cannot save an empty tid
				continue;
			}

      $query->values(array(
        'nid' => $entity->nid,
        'tid' => $item['tid'],
        'sticky' => $entity->sticky,
        'created' => $entity->created,
      ));
    }
    $query->execute();
  }
}

/**
 * Implements hook_implements_alter()
 */
function reltw_module_implements_alter(&$implementations, $hook) {
	switch ($hook) {
		// Making sure that the reltw runs after the taxonomy node_update because the taxonomy node_update deletes everything
	  case 'node_update':
     $m1 = $implementations['taxonomy'];
     unset($implementations['taxonomy']);

     $m2 = $implementations['reltw'];
     unset($implementations['reltw']);

     //hook_form_alter would be called on module m3 before module m2.
     $implementations['taxonomy'] = $m1;
     $implementations['reltw'] = $m2;
     break;
  }
}

/**
 * Implements hook_node_update()
 * Updating the taxonomy_index table with field_allterms tids
 */
function reltw_node_update($node) {

	$fieldname = 'field_allterms';
	$langcode = $node->language;
	$field = field_info_field($fieldname);

	if (isset($_POST[$fieldname][$langcode])) {
		$items = _reltw_form_to_storage($field, $langcode);
		_reltw_cleanup_submitted_items($items);
	}
	elseif (isset($node->{$fieldname}['und'])) {
	  $items = $node->{$fieldname}['und'];
	  _reltw_cleanup_submitted_items($items);
	}

	// We maintain a denormalized table of term/node relationships, containing
  // only data for current, published nodes.
  $status = NULL;
  if (variable_get('taxonomy_maintain_index_table', TRUE)) {
    // If a node property is not set in the node object when node_save() is
    // called, the old value from $node->original is used.
    if (!empty($node->original)) {
      $status = (int)(!empty($node->status) || (!isset($node->status) && !empty($node->original->status)));
      $sticky = (int)(!empty($node->sticky) || (!isset($node->sticky) && !empty($node->original->sticky)));
    }
    else {
      $status = (int)(!empty($node->status));
      $sticky = (int)(!empty($node->sticky));
    }
  }

  // We only maintain the taxonomy index for published nodes.
  if ($status) {
    // Insert index entries for all the node's terms.
    if (!empty($items)) {
      $query = db_insert('taxonomy_index')->fields(array('nid', 'tid', 'sticky', 'created'));

      foreach ($items as $key => $item) {
				if ($item['tid'] == 0) {
					unset($items[$key]); // we cannot save an empty tid
					continue;
				}

        $query->values(array(
          'nid' => $node->nid,
          'tid' => $item['tid'],
          'sticky' => $sticky,
          'created' => $node->created,
        ));
      }
      $query->execute();
    }
  }
}

/**
 * Implements hook_field_update()
 * TODO: redo to use form_set_value(). see options_field_widget_validate()
 */
function reltw_field_update($entity_type, $entity, $field, $instance, $langcode, &$items) {
	$fieldname = $field['field_name'];
	if (isset($_POST[$fieldname][$langcode])) {
		$items = _reltw_form_to_storage($field, $langcode);
		_reltw_cleanup_submitted_items($items);
	}

	if (variable_get('taxonomy_maintain_index_table', TRUE) && $field['storage']['type'] == 'field_sql_storage' && $entity_type == 'node') {
    $first_call = &drupal_static(__FUNCTION__, array());

		// Got the following code from taxonomy.module
    // We don't maintain data for old revisions, so clear all previous values
    // from the table. Since this hook runs once per field, per object, make
    // sure we only wipe values once.
    if (!isset($first_call[$entity->nid])) {
      $first_call[$entity->nid] = FALSE;
			foreach($instance['settings']['vids'] as $key => $vid) {
				if (!$vid) unset($instance['settings']['vids'][$key]);
			}

			$vids = implode(',', $instance['settings']['vids']);
			if ($vids) {
				db_query('DELETE taxonomy_index.*
					FROM {taxonomy_index} taxonomy_index
					LEFT JOIN {taxonomy_term_data} taxonomy_term_data ON taxonomy_term_data.tid = taxonomy_index.tid
					WHERE nid=37749 and taxonomy_term_data.vid IN ('.$vids.')');
			}
    }
    // Only save data to the table if the node is published.
    if ($entity->status) {
			$query = db_insert('taxonomy_index')->fields(array('nid', 'tid', 'sticky', 'created'));
      foreach ($items as $key => $item) {
				if ($item['tid'] == 0) {
					unset($items[$key]); // we cannot save an empty tid
					continue;
				}

				if(!taxonomy_term_load($item['tid'])) {
				  unset($items[$key]);
			  	// Remove the term from all_terms if it doesn't exist
			  	$delete_query = db_delete('field_data_field_allterms')
			  	  ->condition('field_allterms_tid')
			  	  ->execute();
					continue;
				}

				$query->values(array(
          'nid' => $entity->nid,
          'tid' => $item['tid'],
          'sticky' => $entity->sticky,
          'created' => $entity->created,
        ));
      }

      $query->execute();
    }
  }
}

/**
 * Remove items with tid=0 and regroup if necessary
 */
function _reltw_cleanup_submitted_items(&$items) {
  // cleanup
	$cleaned = false;
	foreach($items as $key => $item) {
	  if (!$item['tid']) {
	    unset($items[$key]);
	    $cleaned = true;
	  }
	}

	// regroup
	if ($cleaned) {
	  $group = 1; $last_group = 1;
  	$groups = array();
    foreach($items as $key => $item) {
  	  $groups[$item['group']][] = $item;
  	}

    $items = array();
    $group_id = 1;
    foreach($groups as $group) {
      foreach($group as $item) {
        $item['group'] = $group_id;
        $items[] = $item;
      }
      $group_id++;
    }
	}
}


/**
 * Implement hook_field_validate().
 * TODO: redo to use form_set_value(). see options_field_widget_validate()
 */
function reltw_field_validate($entity_type, $entity, $field, $instance, $langcode, $items, &$errors) {
	$items = _reltw_form_to_storage($field, $langcode);

	// Required validation
	if ($instance['required'] && empty($items)) {
		$errors[$field['field_name']][$langcode][0][] = array(
      'error' => "reltw_required",
      'message' => t('!name field is required.', array('!name' => $instance['label'])),
    );
  }
}

function _reltw_form_to_storage($field, $langcode) {
 	// Just like in reltw_field_widget_form(), we need to cleanup the values from $_POST because drupal's fields cannot
  // handle the logic of what we need the data to be
	$items = array();

	$fieldname = $field['field_name'];
	if (isset($_POST[$fieldname][$langcode])) {
		$items = _reltw_field_process_post_data($_POST[$fieldname][$langcode]);
	}

	return $items;
}


/**
 * Transforms submitted form values into field storage format.
 * returns
 * $items[0]['vid'] = 20;
 * $items[0]['tid'] = 388;
 * $items[0]['group'] = 1;
*/
function _reltw_field_process_post_data($post_data) {
	$items = array();
	foreach($post_data as $id => &$e) {
		foreach($e['reltw_field'] as $_e) {
			if (!$_e['vid']) continue;
			if (!isset($_e['tid']) || !$_e['tid']) $_e['tid'] = 0;
			// we don't clean it up here, instead do that during update or insert
			//if (!isset($_e['tid']) || !$_e['tid']) continue;

			$_e['group'] = str_replace('reltw_group_', '', $id);
			$items[] = $_e;
		}
	}

	return $items;
}

/**
 * Implement hook_field_error().
 * Not being used yet
 */
function reltw_field_widget_error($element, $error) {
  form_error($element, $error['message']);
}

