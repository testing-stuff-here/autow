<?php
/**
 * @file
 * leadership_bulk_operations_view.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function leadership_bulk_operations_view_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'companies_bulk_operations';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Companies Bulk Operations';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Bulk Operations';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '100';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page'] = TRUE;
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options'] = '5, 10, 25, 50, 75, 100';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = TRUE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'title' => 'title',
    'field_ld_session' => 'field_ld_session',
  );
  $handler->display->display_options['style_options']['default'] = 'title';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_ld_session' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['sticky'] = TRUE;
  /* Field: Bulk operations: Content */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = '';
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '1';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::node_assign_owner_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::clone_action_clone' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_script_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_make_sticky_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_make_unsticky_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_modify_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 1,
      'label' => 'Change Leadership Session',
      'settings' => array(
        'show_all_tokens' => 0,
        'display_values' => array(
          'company::field_ld_session' => 'company::field_ld_session',
        ),
      ),
    ),
    'action::views_bulk_operations_argument_selector_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'url' => '',
      ),
    ),
    'action::node_promote_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_publish_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 1,
      'label' => 'Publish',
    ),
    'action::node_unpromote_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_save_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::system_send_email_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_unpublish_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 1,
      'label' => 'Unpublish',
    ),
    'action::node_unpublish_by_keyword_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Leadership Session */
  $handler->display->display_options['fields']['field_ld_session']['id'] = 'field_ld_session';
  $handler->display->display_options['fields']['field_ld_session']['table'] = 'field_data_field_ld_session';
  $handler->display->display_options['fields']['field_ld_session']['field'] = 'field_ld_session';
  $handler->display->display_options['fields']['field_ld_session']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_ld_session']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_ld_session']['delta_offset'] = '0';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title_1']['id'] = 'title_1';
  $handler->display->display_options['filters']['title_1']['table'] = 'node';
  $handler->display->display_options['filters']['title_1']['field'] = 'title';
  $handler->display->display_options['filters']['title_1']['operator'] = 'longerthan';
  $handler->display->display_options['filters']['title_1']['value'] = '0';
  $handler->display->display_options['filters']['title_1']['group'] = 1;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'company' => 'company',
    'leadership_data_card' => 'leadership_data_card',
    'leadership_online_profile' => 'leadership_online_profile',
    'leadership_print_profile' => 'leadership_print_profile',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['filters']['type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  $handler->display->display_options['filters']['type']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
    14 => 0,
    34306563 => 0,
    250584251 => 0,
  );
  $handler->display->display_options['filters']['type']['is_grouped'] = TRUE;
  $handler->display->display_options['filters']['type']['group_info']['label'] = 'Type';
  $handler->display->display_options['filters']['type']['group_info']['identifier'] = 'type';
  $handler->display->display_options['filters']['type']['group_info']['default_group'] = '1';
  $handler->display->display_options['filters']['type']['group_info']['group_items'] = array(
    1 => array(
      'title' => 'Company',
      'operator' => 'in',
      'value' => array(
        'company' => 'company',
        'all' => 0,
        '360_package_spin_rotate' => 0,
        'article' => 0,
        'page' => 0,
        'blog' => 0,
        'form_template' => 0,
        'leadership_data_card' => 0,
        'leadership_online_profile' => 0,
        'leadership_print_profile' => 0,
        'magazine_covers' => 0,
        'mobile_webform' => 0,
        'opt_out_form' => 0,
        'photo' => 0,
        'playbook' => 0,
        'podcast' => 0,
        'pop_up_registration' => 0,
        'registration_form' => 0,
        'showcase_expo_pack_profile' => 0,
        'slideshow' => 0,
        'stage_one_form' => 0,
        'video' => 0,
        'webform' => 0,
        'webcast' => 0,
        'webinar_registration' => 0,
        'whitepaper' => 0,
      ),
    ),
    2 => array(
      'title' => 'Data Card',
      'operator' => 'in',
      'value' => array(
        'leadership_data_card' => 'leadership_data_card',
        'all' => 0,
        '360_package_spin_rotate' => 0,
        'article' => 0,
        'page' => 0,
        'blog' => 0,
        'company' => 0,
        'form_template' => 0,
        'leadership_online_profile' => 0,
        'leadership_print_profile' => 0,
        'magazine_covers' => 0,
        'mobile_webform' => 0,
        'opt_out_form' => 0,
        'photo' => 0,
        'playbook' => 0,
        'podcast' => 0,
        'pop_up_registration' => 0,
        'registration_form' => 0,
        'showcase_expo_pack_profile' => 0,
        'slideshow' => 0,
        'stage_one_form' => 0,
        'video' => 0,
        'webform' => 0,
        'webcast' => 0,
        'webinar_registration' => 0,
        'whitepaper' => 0,
      ),
    ),
    3 => array(
      'title' => 'Online Profile',
      'operator' => 'in',
      'value' => array(
        'leadership_online_profile' => 'leadership_online_profile',
        'all' => 0,
        '360_package_spin_rotate' => 0,
        'article' => 0,
        'page' => 0,
        'blog' => 0,
        'company' => 0,
        'form_template' => 0,
        'leadership_data_card' => 0,
        'leadership_print_profile' => 0,
        'magazine_covers' => 0,
        'mobile_webform' => 0,
        'opt_out_form' => 0,
        'photo' => 0,
        'playbook' => 0,
        'podcast' => 0,
        'pop_up_registration' => 0,
        'registration_form' => 0,
        'showcase_expo_pack_profile' => 0,
        'slideshow' => 0,
        'stage_one_form' => 0,
        'video' => 0,
        'webform' => 0,
        'webcast' => 0,
        'webinar_registration' => 0,
        'whitepaper' => 0,
      ),
    ),
    4 => array(
      'title' => 'Print Profile',
      'operator' => 'in',
      'value' => array(
        'leadership_print_profile' => 'leadership_print_profile',
        'all' => 0,
        '360_package_spin_rotate' => 0,
        'article' => 0,
        'page' => 0,
        'blog' => 0,
        'company' => 0,
        'form_template' => 0,
        'leadership_data_card' => 0,
        'leadership_online_profile' => 0,
        'magazine_covers' => 0,
        'mobile_webform' => 0,
        'opt_out_form' => 0,
        'photo' => 0,
        'playbook' => 0,
        'podcast' => 0,
        'pop_up_registration' => 0,
        'registration_form' => 0,
        'showcase_expo_pack_profile' => 0,
        'slideshow' => 0,
        'stage_one_form' => 0,
        'video' => 0,
        'webform' => 0,
        'webcast' => 0,
        'webinar_registration' => 0,
        'whitepaper' => 0,
      ),
    ),
  );
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'allwords';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Company';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
    14 => 0,
    34306563 => 0,
    250584251 => 0,
  );
  /* Filter criterion: Content: Leadership Session (field_ld_session) */
  $handler->display->display_options['filters']['field_ld_session_tid']['id'] = 'field_ld_session_tid';
  $handler->display->display_options['filters']['field_ld_session_tid']['table'] = 'field_data_field_ld_session';
  $handler->display->display_options['filters']['field_ld_session_tid']['field'] = 'field_ld_session_tid';
  $handler->display->display_options['filters']['field_ld_session_tid']['value'] = '';
  $handler->display->display_options['filters']['field_ld_session_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_ld_session_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_ld_session_tid']['expose']['operator_id'] = 'field_ld_session_tid_op';
  $handler->display->display_options['filters']['field_ld_session_tid']['expose']['label'] = 'Leadership Session';
  $handler->display->display_options['filters']['field_ld_session_tid']['expose']['operator'] = 'field_ld_session_tid_op';
  $handler->display->display_options['filters']['field_ld_session_tid']['expose']['identifier'] = 'field_ld_session_tid';
  $handler->display->display_options['filters']['field_ld_session_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_ld_session_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
    14 => 0,
    34306563 => 0,
    250584251 => 0,
  );
  $handler->display->display_options['filters']['field_ld_session_tid']['vocabulary'] = 'leadership_session';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status_1']['id'] = 'status_1';
  $handler->display->display_options['filters']['status_1']['table'] = 'node';
  $handler->display->display_options['filters']['status_1']['field'] = 'status';
  $handler->display->display_options['filters']['status_1']['value'] = '1';
  $handler->display->display_options['filters']['status_1']['group'] = 1;
  $handler->display->display_options['filters']['status_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status_1']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['status_1']['expose']['label'] = 'Published';
  $handler->display->display_options['filters']['status_1']['expose']['operator'] = 'status_1_op';
  $handler->display->display_options['filters']['status_1']['expose']['identifier'] = 'status_1';
  $handler->display->display_options['filters']['status_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
    14 => 0,
    34306563 => 0,
    250584251 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'admin/leadership/bulk-operations';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Bulk Operations';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $export['companies_bulk_operations'] = $view;

  return $export;
}
