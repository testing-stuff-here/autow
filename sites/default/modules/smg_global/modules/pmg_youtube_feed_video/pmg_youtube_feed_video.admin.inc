<?php

/**
 * @file
 * PMG YouTube Feed Video editing UI.
 *
 * We make very little use of the EntityAPI interface for this - preferring
 * instead to use  views. That offers more flexibility to change a UI that will,
 * more often than not, be end-user facing.
 */

/**
 * UI controller.
 */
class PmgYoutubeFeedVideoUIController extends EntityDefaultUIController {

  /**
   * Overrides hook_menu() defaults. Main reason for doing this is that
   * parent class hook_menu() is optimized for entity type administration.
   */
  public function hook_menu() {

    $items = array();
    $id_count = count(explode('/', $this->path));
    $wildcard = isset($this->entityInfo['admin ui']['menu wildcard']) ? $this->entityInfo['admin ui']['menu wildcard'] : '%' . $this->entityType;

    $items[$this->path] = array(
      'title' => 'PMG YouTube Feed Videos',
      'description' => 'Add edit and update PMG YouTube Feed videos.',
      'page callback' => 'system_admin_menu_block_page',
      'access arguments' => array('access administration pages'),
      'file path' => drupal_get_path('module', 'system'),
      'file' => 'system.admin.inc',
    );

    // Change the overview menu type for the list of PMG YouTube Feed videos.
    $items[$this->path]['type'] = MENU_LOCAL_TASK;

    // Change the add page menu to multiple types of entities
    $items[$this->path . '/add'] = array(
      'title' => 'Add a PMG YouTube Feed video',
      'description' => 'Add a new PMG YouTube Feed video',
      'page callback'  => 'pmg_youtube_feed_video_add_page',
      'access callback'  => 'pmg_youtube_feed_video_access',
      'access arguments' => array('edit'),
      'type' => MENU_NORMAL_ITEM,
      'weight' => 20,
      'file' => 'pmg_youtube_feed_video.admin.inc',
      'file path' => drupal_get_path('module', $this->entityInfo['module']),
    );

    // Add menu items to add each different type of entity.
    foreach (pmg_youtube_feed_video_get_types() as $type) {
      $items[$this->path . '/add/' . $type->type] = array(
        'title' => 'Add ' . $type->label,
        'page callback' => 'pmg_youtube_feed_video_form_wrapper',
        'page arguments' => array(pmg_youtube_feed_video_create(array('type' => $type->type))),
        'access callback' => 'pmg_youtube_feed_video_access',
        'access arguments' => array('edit', 'edit ' . $type->type),
        'file' => 'pmg_youtube_feed_video.admin.inc',
        'file path' => drupal_get_path('module', $this->entityInfo['module'])
      );
    }

    // Loading and editing PMG YouTube Feed video entities
    $items[$this->path . '/pmg_youtube_feed_video/' . $wildcard] = array(
      'page callback' => 'pmg_youtube_feed_video_form_wrapper',
      'page arguments' => array($id_count + 1),
      'access callback' => 'pmg_youtube_feed_video_access',
      'access arguments' => array('edit', $id_count + 1),
      'weight' => 0,
      'context' => MENU_CONTEXT_PAGE | MENU_CONTEXT_INLINE,
      'file' => 'pmg_youtube_feed_video.admin.inc',
      'file path' => drupal_get_path('module', $this->entityInfo['module'])
    );
    $items[$this->path . '/pmg_youtube_feed_video/' . $wildcard . '/edit'] = array(
      'title' => 'Edit',
      'type' => MENU_DEFAULT_LOCAL_TASK,
      'weight' => -10,
      'context' => MENU_CONTEXT_PAGE | MENU_CONTEXT_INLINE,
    );

    $items[$this->path . '/pmg_youtube_feed_video/' . $wildcard . '/delete'] = array(
      'title' => 'Delete',
      'page callback' => 'pmg_youtube_feed_video_delete_form_wrapper',
      'page arguments' => array($id_count + 1),
      'access callback' => 'pmg_youtube_feed_video_access',
      'access arguments' => array('edit', $id_count + 1),
      'type' => MENU_LOCAL_TASK,
      'context' => MENU_CONTEXT_INLINE,
      'weight' => 10,
      'file' => 'pmg_youtube_feed_video.admin.inc',
      'file path' => drupal_get_path('module', $this->entityInfo['module'])
    );

    // Menu item for viewing PMG YouTube Feed videos
    $items['pmg_youtube_feed_video/' . $wildcard] = array(
      //'title' => 'Title',
      'title callback' => 'pmg_youtube_feed_video_page_title',
      'title arguments' => array(1),
      'page callback' => 'pmg_youtube_feed_video_page_view',
      'page arguments' => array(1),
      'access callback' => 'pmg_youtube_feed_video_access',
      'access arguments' => array('view', 1),
      'type' => MENU_CALLBACK,
    );
    return $items;
  }


  /**
   * Create the markup for the add PMG YouTube Feed Video Entities page within the class
   * so it can easily be extended/overriden.
   */
  public function addPage() {
    $item = menu_get_item();
    $content = system_admin_menu_block($item);

    if (count($content) == 1) {
      $item = array_shift($content);
      drupal_goto($item['href']);
    }

    return theme('pmg_youtube_feed_video_add_list', array('content' => $content));
  }

}

/**
 * Form callback wrapper: create or edit a PMG YouTube Feed video.
 *
 * @param object $pmg_youtube_feed_video
 *   The PMG YouTube Feed video object being edited by this form.
 *
 * @see pmg_youtube_feed_video_edit_form()
 */
function pmg_youtube_feed_video_form_wrapper($pmg_youtube_feed_video) {
  // Add the breadcrumb for the form's location.
  pmg_youtube_feed_video_set_breadcrumb();
  return drupal_get_form('pmg_youtube_feed_video_edit_form', $pmg_youtube_feed_video);
}

/**
 * Form callback wrapper: delete a PMG YouTube Feed video.
 *
 * @param object $pmg_youtube_feed_video
 *   The PMG YouTube Feed viceo object being edited by this form.
 *
 * @see pmg_youtube_feed_video_edit_form()
 */
function pmg_youtube_feed_video_delete_form_wrapper($pmg_youtube_feed_video) {
  // Add the breadcrumb for the form's location.
  return drupal_get_form('pmg_youtube_feed_video_delete_form', $pmg_youtube_feed_video);
}

/**
 * Form callback: create or edit a PMG YouTube Feed video.
 *
 * @param object $pmg_youtube_feed_video
 *   The pmg_youtube_feed_video object to edit or for a create form an empty
 *   pmg_youtube_feed_video object with only a PMG YouTube Feed video type defined.
 */
function pmg_youtube_feed_video_edit_form($form, &$form_state, $pmg_youtube_feed_video) {
  // Add the default field elements.
  $form['name'] = array(
    '#type' => 'textfield',
    '#title' => t('Title'),
    '#default_value' => isset($pmg_youtube_feed_video->name) ? $pmg_youtube_feed_video->name : '',
    '#size' => 255,
    '#required' => TRUE,
    '#weight' => -5,
  );

  $form['node_id'] = array(
    '#type' => 'textfield',
    '#size' => 60,
    '#title' => t('Company'),
    '#default_value' => isset($title) ? $title . ' [nid:' . $pmg_youtube_feed_video->node_id . ']' : '',
    '#autocomplete_path' => 'node_reference/autocomplete/user/user/field_ld_company',
    '#required' => FALSE,
  );

  $form['guid'] = array(
    '#type' => 'textfield',
    '#size' => 60,
    '#title' => t('GUID'),
    '#default_value' => isset($pmg_youtube_feed_video->guid) ? $pmg_youtube_feed_video->guid : '',
    '#required' => FALSE,
  );

  $form['video_created'] = array(
    '#type' => 'textfield',
    '#size' => 60,
    '#title' => t('PMG YouTube Feed Published'),
    '#default_value' => isset($pmg_youtube_feed_video->video_created) ? date('Y/m/d H:i:s', $pmg_youtube_feed_video->video_created) : '',
    '#required' => FALSE,
  );

  $form['video_url'] = array(
    '#type' => 'textfield',
    '#size' => 60,
    '#title' => t('PMG YouTube Feed Media URL'),
    '#default_value' => isset($pmg_youtube_feed_video->video_url) ? $pmg_youtube_feed_video->video_url : '',
    '#required' => FALSE,
  );
  $form['video_duration'] = array(
    '#type' => 'textfield',
    '#size' => 60,
    '#title' => t('PMG YouTube Feed Media Duration'),
    '#default_value' => isset($pmg_youtube_feed_video->video_duration) ? $pmg_youtube_feed_video->video_duration : '',
    '#required' => FALSE,
  );

  // Add the field related form elements.
  $form_state['pmg_youtube_feed_video'] = $pmg_youtube_feed_video;
  field_attach_form('pmg_youtube_feed_video', $pmg_youtube_feed_video, $form, $form_state);

  $form['actions'] = array(
    '#type' => 'container',
    '#attributes' => array('class' => array('form-actions')),
    '#weight' => 400,
  );

  // We add the form's #submit array to this button along with the actual submit
  // handler to preserve any submit handlers added by a form callback_wrapper.
  $submit = array();

  if (!empty($form['#submit'])) {
    $submit += $form['#submit'];
  }

  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save PMG YouTube Feed video'),
    '#submit' => $submit + array('pmg_youtube_feed_video_edit_form_submit'),
  );

  if (!empty($pmg_youtube_feed_video->name)) {
    $form['actions']['delete'] = array(
      '#type' => 'submit',
      '#value' => t('Delete PMG YouTube Feed video'),
      '#suffix' => l(t('Cancel'), 'admin/content/pmg_youtube_feed_videos'),
      '#submit' => $submit + array('pmg_youtube_feed_video_form_submit_delete'),
      '#weight' => 45,
    );
  }

  // We append the validate handler to #validate in case a form callback_wrapper
  // is used to add validate handlers earlier.
  $form['#validate'][] = 'pmg_youtube_feed_video_edit_form_validate';
  return $form;
}

/**
 * Form API validate callback for the PMG YouTube Feed video form.
 */
function pmg_youtube_feed_video_edit_form_validate(&$form, &$form_state) {
  $pmg_youtube_feed_video = $form_state['pmg_youtube_feed_video'];

  // Notify field widgets to validate their data.
  field_attach_form_validate('pmg_youtube_feed_video', $pmg_youtube_feed_video, $form, $form_state);
}

/**
 * Form API submit callback for the PMG YouTube Feed video form.
 *
 * @todo remove hard-coded link
 */
function pmg_youtube_feed_video_edit_form_submit(&$form, &$form_state) {

  $pmg_youtube_feed_video = entity_ui_controller('pmg_youtube_feed_video')->entityFormSubmitBuildEntity($form, $form_state);

  // Get the nid fromt the automcomplete text
  preg_match('/.*?\[nid:(\d+)?]/', $form['node_id']['#value'], $matches);

  if (isset($matches[1])) {
    $pmg_youtube_feed_video->node_id = $matches[1];
  }
  // Save the PMG YouTube Feed video and go back to the list of PMG YouTube Feed videos

  // Add in created and changed times.
  if ($pmg_youtube_feed_video->is_new = isset($pmg_youtube_feed_video->is_new) ? $pmg_youtube_feed_video->is_new : 0){
    $pmg_youtube_feed_video->created = time();
  }

  $pmg_youtube_feed_video->changed = time();
  $pmg_youtube_feed_video->save();
  $form_state['redirect'] = 'admin/content/pmg_youtube_feed_videos';
}

/**
 * Form API submit callback for the delete button.
 *
 * @todo Remove hard-coded path
 */
function pmg_youtube_feed_video_form_submit_delete(&$form, &$form_state) {
  $form_state['redirect'] = 'admin/content/pmg_youtube_feed_videos/pmg_youtube_feed_video/' . $form_state['pmg_youtube_feed_video']->id. '/delete';
}

/**
 * Form callback: confirmation form for deleting a PMG YouTube Feed video.
 *
 * @param object $pmg_youtube_feed_video
 *   The pmg_youtube_feed_video to delete
 *
 * @see confirm_form()
 */
function pmg_youtube_feed_video_delete_form($form, &$form_state, $pmg_youtube_feed_video) {
  $form_state['pmg_youtube_feed_video'] = $pmg_youtube_feed_video;

  $form['#submit'][] = 'pmg_youtube_feed_video_delete_form_submit';

  $form = confirm_form($form,
    t('Are you sure you want to delete pmg_youtube_feed_video %name?', array('%name' => $pmg_youtube_feed_video->name)),
    'admin/content/pmg_youtube_feed_videos/pmg_youtube_feed_video',
    '<p>' . t('This action cannot be undone.') . '</p>',
    t('Delete'),
    t('Cancel'),
    'confirm'
  );

  return $form;
}

/**
 * Submit callback for pmg_youtube_feed_video_delete_form
 */
function pmg_youtube_feed_video_delete_form_submit($form, &$form_state) {
  $pmg_youtube_feed_video = $form_state['pmg_youtube_feed_video'];

  pmg_youtube_feed_video_delete($pmg_youtube_feed_video);

  drupal_set_message(t('The PMG YouTube Feed video %name has been deleted.', array('%name' => $pmg_youtube_feed_video->name)));
  watchdog('pmg_youtube_feed_video', 'Deleted PMG YouTube Feed video %name.', array('%name' => $pmg_youtube_feed_video->name));

  $form_state['redirect'] = 'admin/content/pmg_youtube_feed_videos';
}

/**
 * Page to add PMG YouTube Feed Video Entities.
 *
 * @todo Pass this through a proper theme function
 */
function pmg_youtube_feed_video_add_page() {
  $controller = entity_ui_controller('pmg_youtube_feed_video');
  return $controller->addPage();
}

/**
 * Displays the list of available PMG YouTube Feed video types for PMG YouTube Feed video
 * creation.
 *
 * @ingroup themeable
 */
function theme_pmg_youtube_feed_video_add_list($variables) {
  $content = $variables['content'];
  $output = '';
  if ($content) {
    $output = '<dl class="pmg-youtube-feed-video-type-list">';
    foreach ($content as $item) {
      $output .= '<dt>' . l($item['title'], $item['href']) . '</dt>';
      $output .= '<dd>' . filter_xss_admin($item['description']) . '</dd>';
    }
    $output .= '</dl>';
  }
  else {
    if (user_access('administer pmg youtube feed video types')) {
      $output = '<p>' . t('PMG YouTube Feed Video Entities cannot be added because you have not created any PMG YouTube Feed video types yet. Go to the <a href="@create-pmg-youtube-feed-video-type">PMG YouTube Feed video type creation page</a> to add a new PMG YouTube Feed video type.', array('@create-pmg-youtube-feed-video-type' => url('admin/structure/pmg_youtube_feed_video_types/add'))) . '</p>';
    }
    else {
      $output = '<p>' . t('No PMG YouTube Feed video types have been created yet for you to use.') . '</p>';
    }
  }

  return $output;
}

/**
 * Sets the breadcrumb for administrative PMG YouTube Feed video pages.
 */
function pmg_youtube_feed_video_set_breadcrumb() {
  $breadcrumb = array(
    l(t('Home'), '<front>'),
    l(t('Administration'), 'admin'),
    l(t('Content'), 'admin/content'),
    l(t('Models'), 'admin/content/pmg_youtube_feed_videos'),
  );

  drupal_set_breadcrumb($breadcrumb);
}
