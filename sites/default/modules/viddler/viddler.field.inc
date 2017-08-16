<?php

module_load_include('php', 'viddler', 'library/phpviddler');

/**
 * Implement hook_field_info().
 */
function viddler_field_info() {
  return array(
    'viddler_field' => array(
	    'label' => t('Viddler'),
  	  'description' => t('Stores the Viddler ID.'),
  	  'default_widget' => 'viddler_widget',
  	  'default_formatter' => 'viddler_default',
  	  'instance_settings' => array(
        'dimension' => array(),
				'input_type' => array(),
				'file_extensions' => 'mp4 ogg avi mov wmv flv ogv webm m4v',
				'file_directory' => 'videos/viddler',
      ),
	  ),
  );
}

/**
 * Implements hook_field_is_empty().
 */
function viddler_field_is_empty($item, $field) {
  return empty($item['value']);
}

/**
 * Implements hook_field_instance_settings_form().
 */
function viddler_field_instance_settings_form($field, $instance) {
  $settings = $instance['settings'];

	$form['dimension']['full'] = array(
		'#type' => 'fieldset',
		'#title' => t('Video Display Settings'),
		'#description' => t('These settings control how this video is displayed in its full size, which defaults to !widthx!height.', array('!width' => VIDDLER_DEFAULT_VIDEO_WIDTH, '!height' => VIDDLER_DEFAULT_VIDEO_HEIGHT)),
	);

  $form['dimension']['full']['width'] = array(
    '#type' => 'textfield',
    '#title' => t('Width'),
    '#default_value' => @$settings['dimension']['full']['width'] ? $settings['dimension']['full']['width'] : VIDDLER_DEFAULT_VIDEO_WIDTH,
    '#description' => t('The width of the video. It defaults to !width.', array('!width' => VIDDLER_DEFAULT_VIDEO_WIDTH)),
  );

  $form['dimension']['full']['height'] = array(
    '#type' => 'textfield',
    '#title' => t('Height'),
    '#default_value' => @$settings['dimension']['full']['height'] ? $settings['dimension']['full']['height'] : VIDDLER_DEFAULT_VIDEO_HEIGHT,
    '#description' => t('The height of the video. Leave blank to have Viddler set automatically.'),
  );

  $form['viddler_info'] = array(
		'#type' => 'fieldset',
		'#title' => t('Video Description Text'),
		'#description' => t('The text that will be below each field.'),
	);

	$form['viddler_info']['id_message'] = array(
    '#type' => 'textarea',
    '#title' => t('Viddler Id Message'),
    '#default_value' => @$settings['viddler_info']['id_message'] ? $settings['viddler_info']['id_message']: '',
    '#description' => t('Text Info that will be under the Viddler Id field.'),
  );

  $form['viddler_info']['title'] = array(
    '#type' => 'textarea',
    '#title' => t('Title Message'),
    '#default_value' => @$settings['viddler_info']['title'] ? $settings['viddler_info']['title']: '',
    '#description' => t('Text Info that will be under the Title field.'),
  );

  $form['viddler_info']['upload_message'] = array(
    '#type' => 'textarea',
    '#title' => t('Upload Message'),
    '#default_value' => @$settings['viddler_info']['upload_message'] ? $settings['viddler_info']['upload_message']: '',
    '#description' => t('Text Info that will be under the Upload Video field.'),
  );

  return $form;
}

/**
 * Implement hook_field_widget_info().
 */
function viddler_field_widget_info() {
  return array(
    'viddler_widget' => array(
	    'label' => t('Video'),
	    'field types' => array('viddler_field'),
			'behaviors' => array(
        'default value' => FIELD_BEHAVIOR_NONE,
      ),
			'settings' => array(
        'dimension' => array(
					'full' => array(
						'width' => VIDDLER_DEFAULT_VIDEO_WIDTH,
						'height' => VIDDLER_DEFAULT_VIDEO_HEIGHT
					)
				),
      ),
	  ),

	  'viddler_video_upload' => array(
      'label' => t('Video Upload'),
      'field types' => array('viddler_field'),
      'settings' => array(
      'progress_indicator' => 'throbber',
      ),
     'behaviors' => array(
        'default value' => FIELD_BEHAVIOR_NONE,
      ),
    ),
  );
}

/**
 * Implement hook_field_formatter_info().
 */
function viddler_field_formatter_info() {
  return array(
    'viddler_default' => array(
      'label' => t('Video'),
      'field types' => array('viddler_field'),
    ),
	  'viddler_image' => array(
	    'label' => t('Image'),
	    'field types' => array('viddler_field'),
			'settings' => array('image_style' => '', 'image_link' => ''),
	  ),
  );
}

/**
 * Implement hook_field_widget().
 * Todo: When saving default value in settings, it also enter here. so i need to consider default values. and how to display them in the settings page
 */
function viddler_field_widget_form(&$form, &$form_state, $field, $instance, $langcode, $items, $delta, $element) {

	$value = isset($items[$delta]['value']) ? $items[$delta]['value'] : '';
	$title = isset($items[$delta]['video_title']) ? $items[$delta]['video_title'] : '';
	$video_fid = isset($items[$delta]['video_fid']) ? $items[$delta]['video_fid'] : '';
	$t_url = isset($items[$delta]['thumbnail_url']) ? $items[$delta]['thumbnail_url'] : '';
	$t_fid = isset($items[$delta]['thumbnail_fid']) ? $items[$delta]['thumbnail_fid'] : '';
	$code = isset($items[$delta]['embed_code']) ? $items[$delta]['embed_code'] : '';

	switch ($instance['widget']['type']) {
	  case 'viddler_widget':
	    $element['value'] = $element + array(
        '#type' => 'textfield',
        '#default_value' => $value,
      );

    	$element['thumbnail_url'] = array(
        '#type' => 'value',
        '#value' => $t_url,
      );

    	$element['embed_code'] = array(
        '#type' => 'value',
        '#value' => $code,
      );

    	$element['thumbnail_fid'] = array(
        '#type' => 'value',
        '#value' => $t_fid,
      );
    break;
    case 'viddler_video_upload':
      // This widget only works with 1 Video per node.  Don't set to Unlimited or anything above 1.

      // Changing the default value to a value so it show up
      $value = isset($items[$delta]['value']) ? $items[$delta]['value'] : 'temp';

      // Hide/Unhide based on if there is a Viddler ID already
      if($value != 'temp') {
        $viddler_id_type = 'textfield';
        $viddler_title_type = 'hidden';
        $viddler_video_type = 'hidden';
      }
      else {
        $viddler_id_type = 'hidden';
        $viddler_title_type = 'textfield';
        $viddler_video_type = 'managed_file';
      }

      $element['value'] = array(
        '#type' => $viddler_id_type,
        '#title' => t('Viddler ID'),
        '#default_value' => $value,
        '#description' => t($instance['settings']['viddler_info']['id_message']),
      );

      $element['video_title'] = array(
        '#type' =>  $viddler_title_type,
        '#title' => t('Video Title'),
        '#description' => t($instance['settings']['viddler_info']['title']),
        '#default_value' => $title,
      );

      $element['video_fid'] = array(
        '#type' => $viddler_video_type,
        '#title' => t('Upload Video'),
        '#upload_validators' => array(
                            'file_validate_extensions' => array("wmv mp4 ogg avi mov wmv flv ogv webm"),
        ),
        '#upload_location' => 'public://' . $instance['settings']['file_directory'],
        '#default_value' => $video_fid,
        '#description' => t($instance['settings']['viddler_info']['upload_message']),
      );

    	$element['thumbnail_url'] = array(
        '#type' => 'value',
        '#value' => $t_url,
      );

    	$element['embed_code'] = array(
        '#type' => 'value',
        '#value' => $code,
      );

    	$element['thumbnail_fid'] = array(
        '#type' => 'value',
        '#value' => $t_fid,
      );

    break;
  }

	return $element;
}

/**
 * Implements hook_field_formatter_view().
 */
function viddler_field_formatter_view($object_type, $object, $field, $instance, $langcode, $items, $display) {
  $element = array();

	$api = variable_get('viddler_apikey', '');
	if (!$api) return $element;

	foreach ($items as $delta => $item) {
		if (!$viddler_id = $item['value']) continue;

		switch($display['type']) {
			case 'viddler_image':
			  // Check if the formatter involves a link.
			  if(isset($display['settings']['image_link'])) {
          if ($display['settings']['image_link'] == 'content') {
            $uri = entity_uri($object_type, $object);
          }
        }

				$file = file_load($item['thumbnail_fid']);

				if ($file) {
					$item['uri'] = $file->uri;
					$item['alt'] = $object->title;
					$item['title'] = '';
					$item['attributes'] = array();

					$element[$delta] = array(
			      '#theme' => 'image_formatter',
			      '#item' => $item,
			      '#image_style' => $display['settings']['image_style'],
			      '#path' => isset($uri) ? $uri : '',
			    );
				}

			break;
			default:
				$markup = $item['embed_code'];
				$element[$delta] = array('#markup' => $markup);
			break;
		}

	}


  return $element;
}

/**
 * Implements hook_field_formatter_settings_form().
 */
function viddler_field_formatter_settings_form($field, $instance, $view_mode, $form, &$form_state) {
  $display = $instance['display'][$view_mode];
  $settings = $display['settings'];

  $image_styles = image_style_options(FALSE);
  $element['image_style'] = array(
    '#title' => t('Image style'),
    '#type' => 'select',
    '#default_value' => $settings['image_style'],
    '#empty_option' => t('None (original image)'),
    '#options' => $image_styles,
  );

  $link_types = array(
    'content' => t('Content'),
    'file' => t('File'),
  );
  $element['image_link'] = array(
    '#title' => t('Link video image to'),
    '#type' => 'select',
    '#default_value' => $settings['image_link'],
    '#empty_option' => t('Nothing'),
    '#options' => $link_types,
  );

  return $element;
}

/**
 * Implements hook_field_formatter_settings_summary().
 */
function viddler_field_formatter_settings_summary($field, $instance, $view_mode) {
  $display = $instance['display'][$view_mode];
  $settings = $display['settings'];

  $summary = array();

	if ($display['type'] == 'viddler_image') {
		$image_styles = image_style_options(FALSE);
	  // Unset possible 'No defined styles' option.
	  unset($image_styles['']);
	  // Styles could be lost because of enabled/disabled modules that defines
	  // their styles in code.
	  if (isset($image_styles[$settings['image_style']])) {
	    $summary[] = t('Image style: @style', array('@style' => $image_styles[$settings['image_style']]));
	  }
	  else {
	    $summary[] = t('Original image');
	  }

	  $link_types = array(
      'content' => t('Linked to content'),
    );

	  // Display this setting only if image is linked.
    if (isset($link_types[$settings['image_link']])) {
      $summary[] = $link_types[$settings['image_link']];
    }

	}

  return implode('<br />', $summary);
}

function viddler_field_insert($entity_type, $entity, $field, $instance, $langcode, &$items) {
  #1792 - Uncomment when back up
	_viddler_return_video_details($entity_type, $entity, $instance, $items);
}

function viddler_field_update($entity_type, $entity, $field, $instance, $langcode, &$items) {
  list($id, $vid, $bundle) = entity_extract_ids($entity_type, $entity);

	// Build a display of the current FIDs.
  $current_viddler = array();
  foreach ($items as $item) {
    $current_viddler[] = $item['value'];
  }

	// Create a bare-bones entity so that we can load its previous values.
  $original = entity_create_stub_entity($entity_type, array($id, $vid, $bundle));
  field_attach_load($entity_type, array($id => $original), FIELD_LOAD_CURRENT, array('field_id' => $field['id']));

	$original_items = array();
	if (!empty($original->{$field['field_name']}[$langcode])) {
		$original_items = $original->{$field['field_name']}[$langcode];
	}

	_viddler_return_video_details($entity_type, $entity, $instance, $items, $original_items, $entity_type, $entity);

	// Compare the original field values with the ones that are being saved.
  $original_items = array();
  if (!empty($original->{$field['field_name']}[$langcode])) {
    foreach ($original->{$field['field_name']}[$langcode] as $key => $original_item) {
      $original_items[] = $original_item['value'];
      if (isset($original_item['value']) && !in_array($original_item['value'], $current_viddler) && $original_item['thumbnail_fid']) {
        // Decrement the file usage count by 1.
        $file = file_load($original_item['thumbnail_fid']);
				if ($file) {
	        file_usage_delete($file, 'viddler', $entity_type, $id, 1);
					file_delete($file);
				}
      }
    }
  }

}

function viddler_field_delete($entity_type, $entity, $field, $instance, $langcode, &$items) {
	list($id, $vid, $bundle) = entity_extract_ids($entity_type, $entity);
	foreach ($items as $delta => $item) {
    $file = file_load($item['thumbnail_fid']);
		if ($file) {
      file_usage_delete($file, 'viddler', $entity_type, $id, 1);
			file_delete($file);
		}
  }
}

/**
 * Get the embed code and save thumbnail locally so we can use it for image_styles
 */
function _viddler_return_video_details($entity_type, $entity, $instance, &$items, $original_items = array()) {

  // If viddler id has text of 'temp' and there is a video_fid than we need to upload the video
  if($items && $items[0]['value'] == 'temp' && $items[0]['video_fid']) {

    $video = viddler_upload_to_viddler($items[0]);

    // Get the Viddler id
    $items[0]['value'] = $video['video']['id'];

  }

  $count = 0;

  list($id, $vid, $bundle) = entity_extract_ids($entity_type, $entity);

  // Looping through twice.  If it fails on one account than use the second account
  while($count < 2 && !isset($passed)) {
    $count++;

    if($count == 1) {
	    $api = variable_get('viddler_apikey', '');
    }

    if($count == 2 && variable_get('viddler_apikey2', '')) {
	    $api = variable_get('viddler_apikey2', '');
    }

  	if (!$api) {
  		drupal_set_message(t('Viddler API key is missing.'), 'error');
  		$items = array();
  		return;
  	}

  	$original_items_lookup = array();
  	if ($original_items) {
  		foreach ($original_items as $key => $original_item) {
  			$original_items_lookup[$key] = $original_item['value'];
      }
  	}

  	//module_load_include('module', 'media_internet', 'media_internet');

  	$viddler_connect = new Viddler_V2($api);
  	$media = new MediaInternetFileHandler('');

	  if($count == 1) {
  	  $session_id = viddler_get_sesssion_id($viddler_connect, variable_get('viddler_user', ''), variable_get('viddler_password', ''));
	  }
	  if($count == 2) {
	    $session_id = viddler_get_sesssion_id($viddler_connect, variable_get('viddler_user2', ''), variable_get('viddler_password2', ''));
	  }

  	$force_update = variable_get('viddler_force_update', false);

  	foreach($items as &$item) {

  		if (!$viddler_id = $item['value']) continue;

  		if ($item['value'] == 'x') {
  			$item['embed_code'] = '';
  			$item['thumbnail_url'] = '';
  			$item['thumbnail_fid'] = 0;
  			continue;
  		}

      $args = array('video_id' => $viddler_id);
      if ($session_id) {
        $args['sessionid'] = $session_id;
      }

  		$video = $viddler_connect->viddler_videos_getDetails($args);

  		if (isset($video['error'])) {
  			$item['embed_code'] = '';
  			$item['thumbnail_url'] = '';
  			$item['thumbnail_fid'] = 0;
  			continue;
  		}

  		// Get the embed code
  		if ($force_update || !$item['embed_code'] || !in_array($item['value'], $original_items_lookup)) {
  		  $width 	= $instance['settings']['dimension']['full']['width'];
  		  $args['width'] = $width;
  			$height = $instance['settings']['dimension']['full']['height'];
  			// Not using the height because I will let Viddler set it to keep the ratio the same
  			//$args['height'] = $height;
  			$autoplay = false;
  			$args['wmode'] = 'transparent';
        // Updating to the latest recommended embed code (iframe). Other types
        // can be found: http://developers.viddler.com/#viddler-videos-getembedcodetypes
        $args['embed_code_type'] = 5;

  			// we have more flexibility with widht and height when using getEmbedCode()
  			$code = $viddler_connect->viddler_videos_getEmbedCode($args);

  			// forbidden
        if (isset($code['error']['code'])) {
          if ($session_id) {
            $secret_args = array('sessionid' => $session_id, 'view_use_secret' => '1', 'video_id' => $viddler_id);
            $enable_secret = $viddler_connect->viddler_videos_setDetails($args);

            $code = $viddler_connect->viddler_videos_getEmbedCode($args);
            if (isset($code['error']['code'])) {
              $error_message[] = 'Unable to get the embed code. Please see the viddler error details: <br/>Error: 02-' . $code['error']['code'] . ': ' . $code['error']['details'];
              _viddler_log_error_watchdog($video, $code, $id);
            }
          }
  		    else {
  		      $error_message[] = 'Unable to get the embed code. Please see the viddler error details: <br/>Error: 02-' . $code['error']['code'] . ': ' . $code['error']['details'];
            _viddler_log_error_watchdog($video, $code, $id);
  		    }
        }
        else {
          $passed = TRUE;
        }

  			$embed_code = '';
  			if (isset($code['video']['embed_code'])) {
  		    $embed_code = $code['video']['embed_code'];
  		  }

  			$item['embed_code'] = $embed_code;
  		}

  		// Get the thumbnail
  		if ($force_update || !$item['thumbnail_url'] || !in_array($item['value'], $original_items_lookup)) {
  			$thumbnail_path = '';
  			if ($video && isset($video['video']['thumbnail_url']) && $video['video']['thumbnail_url']) {
  				$thumbnail_path = $video['video']['thumbnail_url'];

  				$file_obj = file_uri_to_object($thumbnail_path);
  				$media->preSave($file_obj);
  				$media->postSave($file_obj);

  				$item['thumbnail_url'] = $thumbnail_path;
  				$item['thumbnail_fid'] = $file_obj->fid;

  				file_usage_add($file_obj, 'viddler', $entity_type, $id);
  			}
  		}

  	}

	}

	// Only display the error if it wasn't embeded
	if(isset($error_message) && !isset($passed)) {
	  foreach($error_message as $message) {
	    drupal_set_message($message, 'error');
	  }
	}

}

/**
 * Function for uploading a video to Viddler
 *
 * @param $item
 *  array of the Viddler Id field items
 *
 * @return $video
 *  video object that contains the viddler id of the video
 */
function viddler_upload_to_viddler($item) {

  $fid = intval($item['video_fid']);
  $file = file_load($fid);

  if($fid != 0) {
    // ***
    // Create viddler object
    // Authenticate as you
    // Set session id
    // ***/
    $v = new Viddler_V2(variable_get('viddler_apikey', ''));
    $session_id = viddler_get_sesssion_id($v, variable_get('viddler_user', ''), variable_get('viddler_password', ''));

    if($session_id) {
      // ***
      // Call prepareUpload
      // Get endpoint
      // Get token
      // ***/
      $response = $v->viddler_videos_prepareUpload(array('sessionid' => $session_id));
      $endpoint = (isset($response['upload']['endpoint'])) ? $response['upload']['endpoint'] : NULL;
      $token    = (isset($response['upload']['token'])) ? $response['upload']['token'] : NULL;

      // If no title supplied than use the filename
      if($item['video_title']) {
        $title = $item['video_title'];
      }
      else {
        $title = $file->filename;
      }

      if (!empty($endpoint) || !empty($token)) {
        $query          =   array(
          'uploadtoken' =>  $token,
          'title'       =>  $title,
          'file'        =>  '@' .  drupal_realpath($file->uri),
        );


        // ***
        // Start up curl
        //
        // Example below tells curl to:
        // return the result rather than print to screen
        // follow any redirects
        // return the headers
        // return the body
        // have no timeout
        // use POST method
        // set POSTFIELDS
        // ***
        $ch = curl_init();
        curl_setopt($ch, CURLOPT_URL, $endpoint);
        curl_setopt($ch, CURLOPT_RETURNTRANSFER, TRUE);
        curl_setopt($ch, CURLOPT_FOLLOWLOCATION, TRUE);
        curl_setopt($ch, CURLOPT_HEADER, TRUE);
        curl_setopt($ch, CURLOPT_NOBODY, FALSE);
        curl_setopt($ch, CURLOPT_TIMEOUT, 0);
        curl_setopt($ch, CURLOPT_POST, TRUE);
        curl_setopt($ch, CURLOPT_POSTFIELDS, $query);
        $response     = curl_exec($ch);
        $info         = curl_getinfo($ch);
        $header_size  = $info['header_size'];
        $header       = substr($response, 0, $header_size);
        $video        = unserialize(substr($response, $header_size));
        curl_close($ch);

        /*
        // For checking Status

        $v->format = 'json';
        $res = $v->viddler_videos_uploadProgress(array(
          'sessionid' =>  $session_id,
          'token'     =>  urldecode($token)
        ));

        dsm($res);
        */

        return $video;

      }
    }
  }

}

/**
 * Function for getting Viddler Session ID
 *
 * @param $viddler_connect
 *  the Viddler connection object
 * @param $viddler_user
 *  the username associated with the Viddler Account
 * @param $viddler_password
 *  the password associated with the Viddler Account
 *
 * @return $session_id
 *  the Viddler session id
 */
function viddler_get_sesssion_id($viddler_connect, $viddler_user, $viddler_password) {

  $session_id = FALSE;

	$args = array('user' => $viddler_user, 'password' => urlencode($viddler_password));
	$session = $viddler_connect->viddler_users_auth($args);
	if (isset($session['auth']['sessionid'])) {
	  $session_id = $session['auth']['sessionid'];
	}

	return $session_id;

}

function _viddler_log_error_watchdog($video, $code, $id) {
  $watchdog_err = t('Viddler ID') . ': ' . $video['video']['id']
    . t('Error') . ': ' . $code['error']['code']
    . '<br/>' . t('Description') . ': ' . $code['error']['description']
    . '<br/>' . t('Details') . ': ' . $code['error']['details'];

  $watchdog_err .= '<br/><br/>' . t('Video Details below: ');
  foreach($video['video'] as $key => $val) {
    if (is_array($val)) $val = serialize($val);
    $watchdog_err .= '<br/>' . $key . ': ' . $val;
  }

  watchdog('viddler', $watchdog_err, $variables = array(), WATCHDOG_ERROR, l('node/'.$id,'node/'.$id));
}
