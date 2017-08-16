<?php

/**
 * @file
 * PMG YouTube Feed Video type editing UI.
 */

/**
 * UI controller.
 */
class PmgYoutubeFeedVideoTypeUIController extends EntityDefaultUIController {

  /**
   * Overrides hook_menu() defaults.
   */
  public function hook_menu() {
    $items = parent::hook_menu();
    $items[$this->path]['description'] = 'Manage PMG YouTube Feed entity types, including adding
    and removing fields and the display of fields.';
    return $items;
  }
}

/**
 * Generates the wawywire video type editing form.
 */
function pmg_youtube_feed_video_type_form($form, &$form_state, $pmg_youtube_feed_video_type, $op = 'edit') {

  if ($op == 'clone') {
    $pmg_youtube_feed_video_type->label .= ' (cloned)';
    $pmg_youtube_feed_video_type->type = '';
  }

  $form['label'] = array(
    '#title' => t('Label'),
    '#type' => 'textfield',
    '#default_value' => $pmg_youtube_feed_video_type->label,
    '#description' => t('The human-readable name of this PMG YouTube Feed video type.'),
    '#required' => TRUE,
    '#size' => 30,
  );
  // Machine-readable type name.
  $form['type'] = array(
    '#type' => 'machine_name',
    '#default_value' => isset($pmg_youtube_feed_video_type->type) ? $pmg_youtube_feed_video_type->type : '',
    '#maxlength' => 32,
    '#machine_name' => array(
      'exists' => 'pmg_youtube_feed_video_get_types',
      'source' => array('label'),
    ),
    '#description' => t('A unique machine-readable name for this PMG YouTube Feed video type. It must only contain lowercase letters, numbers, and underscores.'),
  );

  $form['data']['#tree'] = TRUE;

  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save PMG Youtube Feed video type'),
    '#weight' => 40,
  );

  return $form;
}

/**
 * Form API submit callback for the type form.
 */
function pmg_youtube_feed_video_type_form_submit(&$form, &$form_state) {
  $model_type = entity_ui_form_submit_build_entity($form, $form_state);
  $model_type->save();
  $form_state['redirect'] = 'admin/structure/pmg_youtube_feed_video_types';
}

/**
 * Form API submit callback for the delete button.
 */
function pmg_youtube_feed_video_type_form_submit_delete(&$form, &$form_state) {
  $form_state['redirect'] = 'admin/structure/pmg_youtube_feed_video_types/manage/' . $form_state['pmg_youtube_feed_video_type']->type . '/delete';
}
