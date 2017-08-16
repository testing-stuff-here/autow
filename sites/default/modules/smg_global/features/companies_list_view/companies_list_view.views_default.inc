<?php
/**
 * @file
 * companies_list_view.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function companies_list_view_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'companies_list';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Companies List';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Companies List';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'administer nodes';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Company Name';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Personify ID */
  $handler->display->display_options['fields']['field_personify_id']['id'] = 'field_personify_id';
  $handler->display->display_options['fields']['field_personify_id']['table'] = 'field_data_field_personify_id';
  $handler->display->display_options['fields']['field_personify_id']['field'] = 'field_personify_id';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Published';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['expose']['remember_roles'] = array(
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
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'company' => 'company',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'admin/reports/companies';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Companies';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_xls';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['path'] = 'admin/reports/companies/xls';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );
  $handler->display->display_options['use_batch'] = 'batch';
  $handler->display->display_options['return_path'] = 'admin/reports/companies';
  $handler->display->display_options['segment_size'] = '100';

  /* Display: Personify Page */
  $handler = $view->new_display('page', 'Personify Page', 'page_personify');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Companies List - Personify IDs';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Company Name';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Personify ID */
  $handler->display->display_options['fields']['field_personify_id']['id'] = 'field_personify_id';
  $handler->display->display_options['fields']['field_personify_id']['table'] = 'field_data_field_personify_id';
  $handler->display->display_options['fields']['field_personify_id']['field'] = 'field_personify_id';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Published';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['expose']['remember_roles'] = array(
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
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'company' => 'company',
  );
  /* Filter criterion: Content: Expo Pack Session (field_ep_session) */
  $handler->display->display_options['filters']['field_ep_session_tid']['id'] = 'field_ep_session_tid';
  $handler->display->display_options['filters']['field_ep_session_tid']['table'] = 'field_data_field_ep_session';
  $handler->display->display_options['filters']['field_ep_session_tid']['field'] = 'field_ep_session_tid';
  $handler->display->display_options['filters']['field_ep_session_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_ep_session_tid']['expose']['operator_id'] = 'field_ep_session_tid_op';
  $handler->display->display_options['filters']['field_ep_session_tid']['expose']['label'] = 'Showcase Session';
  $handler->display->display_options['filters']['field_ep_session_tid']['expose']['operator'] = 'field_ep_session_tid_op';
  $handler->display->display_options['filters']['field_ep_session_tid']['expose']['identifier'] = 'field_ep_session_tid';
  $handler->display->display_options['filters']['field_ep_session_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_ep_session_tid']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_ep_session_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_ep_session_tid']['vocabulary'] = 'expo_pack_showcase_session';
  /* Filter criterion: Content: Leadership Session (field_ld_session) */
  $handler->display->display_options['filters']['field_ld_session_tid']['id'] = 'field_ld_session_tid';
  $handler->display->display_options['filters']['field_ld_session_tid']['table'] = 'field_data_field_ld_session';
  $handler->display->display_options['filters']['field_ld_session_tid']['field'] = 'field_ld_session_tid';
  $handler->display->display_options['filters']['field_ld_session_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_ld_session_tid']['expose']['operator_id'] = 'field_ld_session_tid_op';
  $handler->display->display_options['filters']['field_ld_session_tid']['expose']['label'] = 'LIP Session';
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
  $handler->display->display_options['filters']['field_ld_session_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_ld_session_tid']['vocabulary'] = 'leadership_session';
  $handler->display->display_options['path'] = 'admin/reports/companies/personify';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Personify IDs';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['weight'] = '0';

  /* Display: Data export 2 */
  $handler = $view->new_display('views_data_export', 'Data export 2', 'views_data_export_2');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Published';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['expose']['remember_roles'] = array(
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
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'company' => 'company',
  );
  /* Filter criterion: Content: Expo Pack Session (field_ep_session) */
  $handler->display->display_options['filters']['field_ep_session_tid']['id'] = 'field_ep_session_tid';
  $handler->display->display_options['filters']['field_ep_session_tid']['table'] = 'field_data_field_ep_session';
  $handler->display->display_options['filters']['field_ep_session_tid']['field'] = 'field_ep_session_tid';
  $handler->display->display_options['filters']['field_ep_session_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_ep_session_tid']['expose']['operator_id'] = 'field_ep_session_tid_op';
  $handler->display->display_options['filters']['field_ep_session_tid']['expose']['label'] = 'Expo Pack Session';
  $handler->display->display_options['filters']['field_ep_session_tid']['expose']['operator'] = 'field_ep_session_tid_op';
  $handler->display->display_options['filters']['field_ep_session_tid']['expose']['identifier'] = 'field_ep_session_tid';
  $handler->display->display_options['filters']['field_ep_session_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_ep_session_tid']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_ep_session_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_ep_session_tid']['vocabulary'] = 'expo_pack_showcase_session';
  /* Filter criterion: Content: Leadership Session (field_ld_session) */
  $handler->display->display_options['filters']['field_ld_session_tid']['id'] = 'field_ld_session_tid';
  $handler->display->display_options['filters']['field_ld_session_tid']['table'] = 'field_data_field_ld_session';
  $handler->display->display_options['filters']['field_ld_session_tid']['field'] = 'field_ld_session_tid';
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
  $handler->display->display_options['filters']['field_ld_session_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_ld_session_tid']['vocabulary'] = 'leadership_session';
  $handler->display->display_options['path'] = 'admin/reports/companies/personify/xls';
  $handler->display->display_options['displays'] = array(
    'page_personify' => 'page_personify',
    'default' => 0,
    'page' => 0,
  );
  $handler->display->display_options['use_batch'] = 'batch';
  $handler->display->display_options['return_path'] = 'admin/reports/companies/personify';
  $handler->display->display_options['segment_size'] = '100';
  $export['companies_list'] = $view;

  return $export;
}
