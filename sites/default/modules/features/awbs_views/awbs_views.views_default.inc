<?php
/**
 * @file
 * awbs_views.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function awbs_views_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'aaron_hand';
  $view->description = 'Views describing content of each AW Editor';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'AW Editors';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Aaron Hand';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '9';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Content: Byline */
  $handler->display->display_options['fields']['field_byline']['id'] = 'field_byline';
  $handler->display->display_options['fields']['field_byline']['table'] = 'field_data_field_byline';
  $handler->display->display_options['fields']['field_byline']['field'] = 'field_byline';
  $handler->display->display_options['fields']['field_byline']['label'] = '';
  $handler->display->display_options['fields']['field_byline']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_byline']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_byline']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_byline']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_byline']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_byline']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_byline']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_byline']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_byline']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_byline']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_byline']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_byline']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_byline']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_byline']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_byline']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_byline']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_byline']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_byline']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_byline']['field_api_classes'] = 0;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Byline (field_byline) */
  $handler->display->display_options['filters']['field_byline_value']['id'] = 'field_byline_value';
  $handler->display->display_options['filters']['field_byline_value']['table'] = 'field_data_field_byline';
  $handler->display->display_options['filters']['field_byline_value']['field'] = 'field_byline_value';
  $handler->display->display_options['filters']['field_byline_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_byline_value']['value'] = 'Aaron Hand';

  /* Display: Aaron Hand */
  $handler = $view->new_display('page', 'Aaron Hand', 'page');
  $handler->display->display_options['display_description'] = 'Aaron Hand';
  $handler->display->display_options['path'] = 'aaron-hand';

  /* Display: Stephanie Neil */
  $handler = $view->new_display('page_with_page_title', 'Stephanie Neil', 'page_with_page_title_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Stephanie Neil';
  $handler->display->display_options['display_description'] = 'Stephanie Neil';
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Byline (field_byline) */
  $handler->display->display_options['filters']['field_byline_value']['id'] = 'field_byline_value';
  $handler->display->display_options['filters']['field_byline_value']['table'] = 'field_data_field_byline';
  $handler->display->display_options['filters']['field_byline_value']['field'] = 'field_byline_value';
  $handler->display->display_options['filters']['field_byline_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_byline_value']['value'] = 'Stephanie Neil';
  $handler->display->display_options['path'] = 'stephanie-neil';

  /* Display: Pat Reynolds */
  $handler = $view->new_display('page_with_page_title', 'Pat Reynolds', 'page_with_page_title_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Pat Reynolds';
  $handler->display->display_options['display_description'] = 'Pat Reynolds';
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Byline (field_byline) */
  $handler->display->display_options['filters']['field_byline_value']['id'] = 'field_byline_value';
  $handler->display->display_options['filters']['field_byline_value']['table'] = 'field_data_field_byline';
  $handler->display->display_options['filters']['field_byline_value']['field'] = 'field_byline_value';
  $handler->display->display_options['filters']['field_byline_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_byline_value']['value'] = 'Pat Reynolds';
  $handler->display->display_options['path'] = 'pat-reynolds';

  /* Display: David Greenfield */
  $handler = $view->new_display('page_with_page_title', 'David Greenfield', 'page_with_page_title_3');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'David Greenfield';
  $handler->display->display_options['display_description'] = 'David Greenfield';
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Byline (field_byline) */
  $handler->display->display_options['filters']['field_byline_value']['id'] = 'field_byline_value';
  $handler->display->display_options['filters']['field_byline_value']['table'] = 'field_data_field_byline';
  $handler->display->display_options['filters']['field_byline_value']['field'] = 'field_byline_value';
  $handler->display->display_options['filters']['field_byline_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_byline_value']['value'] = 'David Greenfield';
  $handler->display->display_options['path'] = 'david-greenfield';

  /* Display: Automation World Editors */
  $handler = $view->new_display('page_with_page_title', 'Automation World Editors', 'page_with_page_title_4');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Automation World Editors';
  $handler->display->display_options['display_description'] = 'Automation World Editors';
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Byline (field_byline) */
  $handler->display->display_options['filters']['field_byline_value']['id'] = 'field_byline_value';
  $handler->display->display_options['filters']['field_byline_value']['table'] = 'field_data_field_byline';
  $handler->display->display_options['filters']['field_byline_value']['field'] = 'field_byline_value';
  $handler->display->display_options['filters']['field_byline_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_byline_value']['value'] = 'Aaron Hand';
  /* Filter criterion: Content: Byline (field_byline) */
  $handler->display->display_options['filters']['field_byline_value_1']['id'] = 'field_byline_value_1';
  $handler->display->display_options['filters']['field_byline_value_1']['table'] = 'field_data_field_byline';
  $handler->display->display_options['filters']['field_byline_value_1']['field'] = 'field_byline_value';
  $handler->display->display_options['filters']['field_byline_value_1']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_byline_value_1']['value'] = 'Pat Reynolds';
  /* Filter criterion: Content: Byline (field_byline) */
  $handler->display->display_options['filters']['field_byline_value_2']['id'] = 'field_byline_value_2';
  $handler->display->display_options['filters']['field_byline_value_2']['table'] = 'field_data_field_byline';
  $handler->display->display_options['filters']['field_byline_value_2']['field'] = 'field_byline_value';
  $handler->display->display_options['filters']['field_byline_value_2']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_byline_value_2']['value'] = 'Stephanie Neil';
  /* Filter criterion: Content: Byline (field_byline) */
  $handler->display->display_options['filters']['field_byline_value_3']['id'] = 'field_byline_value_3';
  $handler->display->display_options['filters']['field_byline_value_3']['table'] = 'field_data_field_byline';
  $handler->display->display_options['filters']['field_byline_value_3']['field'] = 'field_byline_value';
  $handler->display->display_options['filters']['field_byline_value_3']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_byline_value_3']['value'] = 'David Greenfield';
  $handler->display->display_options['path'] = 'aw-editors';
  $export['aaron_hand'] = $view;

  $view = new view;
  $view->name = 'admin_content';
  $view->description = 'Emulates the Drupal content administration page.';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Content';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Content';
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    5 => '5',
    4 => '4',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'title' => 'title',
    'timestamp' => 'title',
    'type' => 'type',
    'name' => 'name',
    'status' => 'status',
    'edit_node' => 'edit_node',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'timestamp' => array(
      'align' => '',
      'separator' => '',
    ),
    'type' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'status' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  $handler->display->display_options['style_options']['empty_table'] = 1;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = 'No content available.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  $handler->display->display_options['empty']['area']['tokenize'] = 0;
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Edit';
  $handler->display->display_options['fields']['edit_node']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['external'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['edit_node']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['edit_node']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['html'] = 0;
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['edit_node']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['edit_node']['hide_empty'] = 0;
  $handler->display->display_options['fields']['edit_node']['empty_zero'] = 0;
  /* Field: Bulk operations: Content */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = '';
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['external'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['html'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['hide_empty'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['empty_zero'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::node_assign_owner_action' => array(
      'selected' => 1,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'postpone_processing' => 0,
    ),
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 1,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'postpone_processing' => 0,
    ),
    'action::views_bulk_operations_script_action' => array(
      'selected' => 1,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'postpone_processing' => 0,
    ),
    'action::node_make_sticky_action' => array(
      'selected' => 1,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'postpone_processing' => 0,
    ),
    'action::node_make_unsticky_action' => array(
      'selected' => 1,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'postpone_processing' => 0,
    ),
    'action::views_bulk_operations_argument_selector_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_promote_action' => array(
      'selected' => 1,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'postpone_processing' => 0,
    ),
    'action::node_publish_action' => array(
      'selected' => 1,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'postpone_processing' => 0,
    ),
    'action::node_unpromote_action' => array(
      'selected' => 1,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'postpone_processing' => 0,
    ),
    'action::node_save_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'postpone_processing' => 0,
    ),
    'action::node_unpublish_action' => array(
      'selected' => 1,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'postpone_processing' => 0,
    ),
    'action::node_unpublish_by_keyword_action' => array(
      'selected' => 1,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'postpone_processing' => 0,
    ),
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['type']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['type']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['type']['alter']['external'] = 0;
  $handler->display->display_options['fields']['type']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['type']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['type']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['type']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['type']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['type']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['type']['alter']['html'] = 0;
  $handler->display->display_options['fields']['type']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['type']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['type']['hide_empty'] = 0;
  $handler->display->display_options['fields']['type']['empty_zero'] = 0;
  $handler->display->display_options['fields']['type']['link_to_node'] = 0;
  $handler->display->display_options['fields']['type']['machine_name'] = 0;
  /* Field: Content: Subtype */
  $handler->display->display_options['fields']['field_term_subtype']['id'] = 'field_term_subtype';
  $handler->display->display_options['fields']['field_term_subtype']['table'] = 'field_data_field_term_subtype';
  $handler->display->display_options['fields']['field_term_subtype']['field'] = 'field_term_subtype';
  $handler->display->display_options['fields']['field_term_subtype']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_term_subtype']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_term_subtype']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_term_subtype']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_term_subtype']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_term_subtype']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_term_subtype']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_term_subtype']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_term_subtype']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_term_subtype']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_term_subtype']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_term_subtype']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_term_subtype']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_term_subtype']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_term_subtype']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_term_subtype']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_term_subtype']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_term_subtype']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_term_subtype']['field_api_classes'] = 0;
  /* Field: Content: Source Type */
  $handler->display->display_options['fields']['field_term_source_type']['id'] = 'field_term_source_type';
  $handler->display->display_options['fields']['field_term_source_type']['table'] = 'field_data_field_term_source_type';
  $handler->display->display_options['fields']['field_term_source_type']['field'] = 'field_term_source_type';
  $handler->display->display_options['fields']['field_term_source_type']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_term_source_type']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_term_source_type']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_term_source_type']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_term_source_type']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_term_source_type']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_term_source_type']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_term_source_type']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_term_source_type']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_term_source_type']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_term_source_type']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_term_source_type']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_term_source_type']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_term_source_type']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_term_source_type']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_term_source_type']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_term_source_type']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_term_source_type']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_term_source_type']['field_api_classes'] = 0;
  /* Field: Content: Byline */
  $handler->display->display_options['fields']['field_byline']['id'] = 'field_byline';
  $handler->display->display_options['fields']['field_byline']['table'] = 'field_data_field_byline';
  $handler->display->display_options['fields']['field_byline']['field'] = 'field_byline';
  $handler->display->display_options['fields']['field_byline']['label'] = 'Author';
  $handler->display->display_options['fields']['field_byline']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_byline']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_byline']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_byline']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_byline']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_byline']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_byline']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_byline']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_byline']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_byline']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_byline']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_byline']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_byline']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_byline']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_byline']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_byline']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_byline']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_byline']['field_api_classes'] = 0;
  /* Field: Content: Companies */
  $handler->display->display_options['fields']['field_companies']['id'] = 'field_companies';
  $handler->display->display_options['fields']['field_companies']['table'] = 'field_data_field_companies';
  $handler->display->display_options['fields']['field_companies']['field'] = 'field_companies';
  $handler->display->display_options['fields']['field_companies']['label'] = 'CompanY';
  $handler->display->display_options['fields']['field_companies']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_companies']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_companies']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_companies']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_companies']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_companies']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_companies']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_companies']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_companies']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_companies']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_companies']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_companies']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_companies']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_companies']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_companies']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_companies']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_companies']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_companies']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_companies']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_companies']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_companies']['field_api_classes'] = 0;
  /* Field: Content: Has new content */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'history';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['label'] = 'New?';
  $handler->display->display_options['fields']['timestamp']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['timestamp']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['timestamp']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['timestamp']['alter']['external'] = 0;
  $handler->display->display_options['fields']['timestamp']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['timestamp']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['timestamp']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['timestamp']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['timestamp']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['timestamp']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['timestamp']['alter']['html'] = 0;
  $handler->display->display_options['fields']['timestamp']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['timestamp']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['timestamp']['hide_empty'] = 0;
  $handler->display->display_options['fields']['timestamp']['empty_zero'] = 0;
  $handler->display->display_options['fields']['timestamp']['link_to_node'] = 0;
  $handler->display->display_options['fields']['timestamp']['comments'] = 0;
  /* Field: Content: Published */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'node';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['status']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['status']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['status']['alter']['external'] = 0;
  $handler->display->display_options['fields']['status']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['status']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['status']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['status']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['status']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['status']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['status']['alter']['html'] = 0;
  $handler->display->display_options['fields']['status']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['status']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['status']['hide_empty'] = 0;
  $handler->display->display_options['fields']['status']['empty_zero'] = 0;
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['created']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['created']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['created']['alter']['external'] = 0;
  $handler->display->display_options['fields']['created']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['created']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['created']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['created']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['created']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['created']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['created']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['created']['alter']['html'] = 0;
  $handler->display->display_options['fields']['created']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['created']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['created']['hide_empty'] = 0;
  $handler->display->display_options['fields']['created']['empty_zero'] = 0;
  $handler->display->display_options['fields']['created']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'F j, Y';
  /* Sort criterion: Content: Updated date */
  $handler->display->display_options['sorts']['changed']['id'] = 'changed';
  $handler->display->display_options['sorts']['changed']['table'] = 'node';
  $handler->display->display_options['sorts']['changed']['field'] = 'changed';
  $handler->display->display_options['sorts']['changed']['order'] = 'DESC';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'AND',
  );
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Title ';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['required'] = 0;
  $handler->display->display_options['filters']['title']['expose']['multiple'] = FALSE;
  /* Filter criterion: Content: Byline (field_byline) */
  $handler->display->display_options['filters']['field_byline_value']['id'] = 'field_byline_value';
  $handler->display->display_options['filters']['field_byline_value']['table'] = 'field_data_field_byline';
  $handler->display->display_options['filters']['field_byline_value']['field'] = 'field_byline_value';
  $handler->display->display_options['filters']['field_byline_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_byline_value']['group'] = 1;
  $handler->display->display_options['filters']['field_byline_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_byline_value']['expose']['operator_id'] = 'field_byline_value_op';
  $handler->display->display_options['filters']['field_byline_value']['expose']['label'] = 'Author Name';
  $handler->display->display_options['filters']['field_byline_value']['expose']['operator'] = 'field_byline_value_op';
  $handler->display->display_options['filters']['field_byline_value']['expose']['identifier'] = 'field_byline_value';
  $handler->display->display_options['filters']['field_byline_value']['expose']['required'] = 0;
  $handler->display->display_options['filters']['field_byline_value']['expose']['multiple'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['filters']['type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Content: Type';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  $handler->display->display_options['filters']['type']['expose']['reduce'] = 0;
  /* Filter criterion: Content: Subtype (field_term_subtype) */
  $handler->display->display_options['filters']['field_term_subtype_tid']['id'] = 'field_term_subtype_tid';
  $handler->display->display_options['filters']['field_term_subtype_tid']['table'] = 'field_data_field_term_subtype';
  $handler->display->display_options['filters']['field_term_subtype_tid']['field'] = 'field_term_subtype_tid';
  $handler->display->display_options['filters']['field_term_subtype_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_term_subtype_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_term_subtype_tid']['expose']['operator_id'] = 'field_term_subtype_tid_op';
  $handler->display->display_options['filters']['field_term_subtype_tid']['expose']['label'] = 'Subtype';
  $handler->display->display_options['filters']['field_term_subtype_tid']['expose']['operator'] = 'field_term_subtype_tid_op';
  $handler->display->display_options['filters']['field_term_subtype_tid']['expose']['identifier'] = 'field_term_subtype_tid';
  $handler->display->display_options['filters']['field_term_subtype_tid']['expose']['reduce'] = 0;
  $handler->display->display_options['filters']['field_term_subtype_tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['field_term_subtype_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_term_subtype_tid']['vocabulary'] = 'subtype';
  $handler->display->display_options['filters']['field_term_subtype_tid']['error_message'] = 1;
  /* Filter criterion: Content: Source Type (field_term_source_type) */
  $handler->display->display_options['filters']['field_term_source_type_tid']['id'] = 'field_term_source_type_tid';
  $handler->display->display_options['filters']['field_term_source_type_tid']['table'] = 'field_data_field_term_source_type';
  $handler->display->display_options['filters']['field_term_source_type_tid']['field'] = 'field_term_source_type_tid';
  $handler->display->display_options['filters']['field_term_source_type_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_term_source_type_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_term_source_type_tid']['expose']['operator_id'] = 'field_term_source_type_tid_op';
  $handler->display->display_options['filters']['field_term_source_type_tid']['expose']['label'] = 'Source: Type';
  $handler->display->display_options['filters']['field_term_source_type_tid']['expose']['operator'] = 'field_term_source_type_tid_op';
  $handler->display->display_options['filters']['field_term_source_type_tid']['expose']['identifier'] = 'field_term_source_type_tid';
  $handler->display->display_options['filters']['field_term_source_type_tid']['expose']['reduce'] = 0;
  $handler->display->display_options['filters']['field_term_source_type_tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['field_term_source_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_term_source_type_tid']['vocabulary'] = 'source_type';
  $handler->display->display_options['filters']['field_term_source_type_tid']['error_message'] = 1;
  /* Filter criterion: Content: Company type (field_term_company_type) */
  $handler->display->display_options['filters']['field_term_company_type_tid']['id'] = 'field_term_company_type_tid';
  $handler->display->display_options['filters']['field_term_company_type_tid']['table'] = 'field_data_field_term_company_type';
  $handler->display->display_options['filters']['field_term_company_type_tid']['field'] = 'field_term_company_type_tid';
  $handler->display->display_options['filters']['field_term_company_type_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_term_company_type_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_term_company_type_tid']['expose']['operator_id'] = 'field_term_company_type_tid_op';
  $handler->display->display_options['filters']['field_term_company_type_tid']['expose']['label'] = 'Company type ';
  $handler->display->display_options['filters']['field_term_company_type_tid']['expose']['operator'] = 'field_term_company_type_tid_op';
  $handler->display->display_options['filters']['field_term_company_type_tid']['expose']['identifier'] = 'field_term_company_type_tid';
  $handler->display->display_options['filters']['field_term_company_type_tid']['expose']['reduce'] = 0;
  $handler->display->display_options['filters']['field_term_company_type_tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['field_term_company_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_term_company_type_tid']['vocabulary'] = 'company_type';
  $handler->display->display_options['filters']['field_term_company_type_tid']['error_message'] = 1;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 'All';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Published';
  $handler->display->display_options['filters']['status']['expose']['use_operator'] = FALSE;
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['expose']['multiple'] = FALSE;
  /* Filter criterion: Content: Coverage Type (field_term_coverage_type) */
  $handler->display->display_options['filters']['field_term_coverage_type_tid']['id'] = 'field_term_coverage_type_tid';
  $handler->display->display_options['filters']['field_term_coverage_type_tid']['table'] = 'field_data_field_term_coverage_type';
  $handler->display->display_options['filters']['field_term_coverage_type_tid']['field'] = 'field_term_coverage_type_tid';
  $handler->display->display_options['filters']['field_term_coverage_type_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_term_coverage_type_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_term_coverage_type_tid']['expose']['operator_id'] = 'field_term_coverage_type_tid_op';
  $handler->display->display_options['filters']['field_term_coverage_type_tid']['expose']['label'] = 'Coverage Type';
  $handler->display->display_options['filters']['field_term_coverage_type_tid']['expose']['operator'] = 'field_term_coverage_type_tid_op';
  $handler->display->display_options['filters']['field_term_coverage_type_tid']['expose']['identifier'] = 'field_term_coverage_type_tid';
  $handler->display->display_options['filters']['field_term_coverage_type_tid']['expose']['reduce'] = 0;
  $handler->display->display_options['filters']['field_term_coverage_type_tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['field_term_coverage_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_term_coverage_type_tid']['vocabulary'] = 'coverage_type';
  $handler->display->display_options['filters']['field_term_coverage_type_tid']['error_message'] = 1;
  /* Filter criterion: Content: Promoted to front page */
  $handler->display->display_options['filters']['promote']['id'] = 'promote';
  $handler->display->display_options['filters']['promote']['table'] = 'node';
  $handler->display->display_options['filters']['promote']['field'] = 'promote';
  $handler->display->display_options['filters']['promote']['value'] = 'All';
  $handler->display->display_options['filters']['promote']['group'] = 1;
  $handler->display->display_options['filters']['promote']['exposed'] = TRUE;
  $handler->display->display_options['filters']['promote']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['promote']['expose']['label'] = 'Promoted';
  $handler->display->display_options['filters']['promote']['expose']['use_operator'] = FALSE;
  $handler->display->display_options['filters']['promote']['expose']['operator'] = 'promote_op';
  $handler->display->display_options['filters']['promote']['expose']['identifier'] = 'promote';
  $handler->display->display_options['filters']['promote']['expose']['multiple'] = FALSE;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Edit';
  $handler->display->display_options['fields']['edit_node']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['external'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['edit_node']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['edit_node']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['html'] = 0;
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['edit_node']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['edit_node']['hide_empty'] = 0;
  $handler->display->display_options['fields']['edit_node']['empty_zero'] = 0;
  /* Field: Bulk operations: Content */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = '';
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['external'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['html'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['hide_empty'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['empty_zero'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::node_assign_owner_action' => array(
      'selected' => 1,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'postpone_processing' => 0,
    ),
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 1,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'postpone_processing' => 0,
    ),
    'action::views_bulk_operations_script_action' => array(
      'selected' => 1,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'postpone_processing' => 0,
    ),
    'action::node_make_sticky_action' => array(
      'selected' => 1,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'postpone_processing' => 0,
    ),
    'action::node_make_unsticky_action' => array(
      'selected' => 1,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'postpone_processing' => 0,
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
      'selected' => 1,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'postpone_processing' => 0,
    ),
    'action::node_publish_action' => array(
      'selected' => 1,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'postpone_processing' => 0,
    ),
    'action::node_unpromote_action' => array(
      'selected' => 1,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'postpone_processing' => 0,
    ),
    'action::node_save_action' => array(
      'selected' => 1,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'postpone_processing' => 0,
    ),
    'action::system_send_email_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'postpone_processing' => 0,
    ),
    'action::node_unpublish_action' => array(
      'selected' => 1,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'postpone_processing' => 0,
    ),
    'action::node_unpublish_by_keyword_action' => array(
      'selected' => 1,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'postpone_processing' => 0,
    ),
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['type']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['type']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['type']['alter']['external'] = 0;
  $handler->display->display_options['fields']['type']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['type']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['type']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['type']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['type']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['type']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['type']['alter']['html'] = 0;
  $handler->display->display_options['fields']['type']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['type']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['type']['hide_empty'] = 0;
  $handler->display->display_options['fields']['type']['empty_zero'] = 0;
  $handler->display->display_options['fields']['type']['link_to_node'] = 0;
  $handler->display->display_options['fields']['type']['machine_name'] = 0;
  /* Field: Content: Subtype */
  $handler->display->display_options['fields']['field_term_subtype']['id'] = 'field_term_subtype';
  $handler->display->display_options['fields']['field_term_subtype']['table'] = 'field_data_field_term_subtype';
  $handler->display->display_options['fields']['field_term_subtype']['field'] = 'field_term_subtype';
  $handler->display->display_options['fields']['field_term_subtype']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_term_subtype']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_term_subtype']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_term_subtype']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_term_subtype']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_term_subtype']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_term_subtype']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_term_subtype']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_term_subtype']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_term_subtype']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_term_subtype']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_term_subtype']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_term_subtype']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_term_subtype']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_term_subtype']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_term_subtype']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_term_subtype']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_term_subtype']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_term_subtype']['field_api_classes'] = 0;
  /* Field: Content: Source Type */
  $handler->display->display_options['fields']['field_term_source_type']['id'] = 'field_term_source_type';
  $handler->display->display_options['fields']['field_term_source_type']['table'] = 'field_data_field_term_source_type';
  $handler->display->display_options['fields']['field_term_source_type']['field'] = 'field_term_source_type';
  $handler->display->display_options['fields']['field_term_source_type']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_term_source_type']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_term_source_type']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_term_source_type']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_term_source_type']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_term_source_type']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_term_source_type']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_term_source_type']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_term_source_type']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_term_source_type']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_term_source_type']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_term_source_type']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_term_source_type']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_term_source_type']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_term_source_type']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_term_source_type']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_term_source_type']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_term_source_type']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_term_source_type']['field_api_classes'] = 0;
  /* Field: Content: Byline */
  $handler->display->display_options['fields']['field_byline']['id'] = 'field_byline';
  $handler->display->display_options['fields']['field_byline']['table'] = 'field_data_field_byline';
  $handler->display->display_options['fields']['field_byline']['field'] = 'field_byline';
  $handler->display->display_options['fields']['field_byline']['label'] = 'Author';
  $handler->display->display_options['fields']['field_byline']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_byline']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_byline']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_byline']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_byline']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_byline']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_byline']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_byline']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_byline']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_byline']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_byline']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_byline']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_byline']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_byline']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_byline']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_byline']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_byline']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_byline']['field_api_classes'] = 0;
  /* Field: Content: Companies */
  $handler->display->display_options['fields']['field_companies']['id'] = 'field_companies';
  $handler->display->display_options['fields']['field_companies']['table'] = 'field_data_field_companies';
  $handler->display->display_options['fields']['field_companies']['field'] = 'field_companies';
  $handler->display->display_options['fields']['field_companies']['label'] = 'CompanY';
  $handler->display->display_options['fields']['field_companies']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_companies']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_companies']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_companies']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_companies']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_companies']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_companies']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_companies']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_companies']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_companies']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_companies']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_companies']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_companies']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_companies']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_companies']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_companies']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_companies']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_companies']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_companies']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_companies']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_companies']['field_api_classes'] = 0;
  /* Field: Content: Has new content */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'history';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['label'] = 'New?';
  $handler->display->display_options['fields']['timestamp']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['timestamp']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['timestamp']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['timestamp']['alter']['external'] = 0;
  $handler->display->display_options['fields']['timestamp']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['timestamp']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['timestamp']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['timestamp']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['timestamp']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['timestamp']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['timestamp']['alter']['html'] = 0;
  $handler->display->display_options['fields']['timestamp']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['timestamp']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['timestamp']['hide_empty'] = 0;
  $handler->display->display_options['fields']['timestamp']['empty_zero'] = 0;
  $handler->display->display_options['fields']['timestamp']['link_to_node'] = 0;
  $handler->display->display_options['fields']['timestamp']['comments'] = 0;
  /* Field: Content: Published */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'node';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['status']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['status']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['status']['alter']['external'] = 0;
  $handler->display->display_options['fields']['status']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['status']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['status']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['status']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['status']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['status']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['status']['alter']['html'] = 0;
  $handler->display->display_options['fields']['status']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['status']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['status']['hide_empty'] = 0;
  $handler->display->display_options['fields']['status']['empty_zero'] = 0;
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['created']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['created']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['created']['alter']['external'] = 0;
  $handler->display->display_options['fields']['created']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['created']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['created']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['created']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['created']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['created']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['created']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['created']['alter']['html'] = 0;
  $handler->display->display_options['fields']['created']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['created']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['created']['hide_empty'] = 0;
  $handler->display->display_options['fields']['created']['empty_zero'] = 0;
  $handler->display->display_options['fields']['created']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'F j, Y';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Title ';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['required'] = 0;
  $handler->display->display_options['filters']['title']['expose']['multiple'] = FALSE;
  /* Filter criterion: Content: Byline (field_byline) */
  $handler->display->display_options['filters']['field_byline_value']['id'] = 'field_byline_value';
  $handler->display->display_options['filters']['field_byline_value']['table'] = 'field_data_field_byline';
  $handler->display->display_options['filters']['field_byline_value']['field'] = 'field_byline_value';
  $handler->display->display_options['filters']['field_byline_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_byline_value']['group'] = 1;
  $handler->display->display_options['filters']['field_byline_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_byline_value']['expose']['operator_id'] = 'field_byline_value_op';
  $handler->display->display_options['filters']['field_byline_value']['expose']['label'] = 'Author Name';
  $handler->display->display_options['filters']['field_byline_value']['expose']['operator'] = 'field_byline_value_op';
  $handler->display->display_options['filters']['field_byline_value']['expose']['identifier'] = 'field_byline_value';
  $handler->display->display_options['filters']['field_byline_value']['expose']['required'] = 0;
  $handler->display->display_options['filters']['field_byline_value']['expose']['multiple'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['filters']['type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Content: Type';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  $handler->display->display_options['filters']['type']['expose']['reduce'] = 0;
  /* Filter criterion: Content: Subtype (field_term_subtype) */
  $handler->display->display_options['filters']['field_term_subtype_tid']['id'] = 'field_term_subtype_tid';
  $handler->display->display_options['filters']['field_term_subtype_tid']['table'] = 'field_data_field_term_subtype';
  $handler->display->display_options['filters']['field_term_subtype_tid']['field'] = 'field_term_subtype_tid';
  $handler->display->display_options['filters']['field_term_subtype_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_term_subtype_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_term_subtype_tid']['expose']['operator_id'] = 'field_term_subtype_tid_op';
  $handler->display->display_options['filters']['field_term_subtype_tid']['expose']['label'] = 'Subtype';
  $handler->display->display_options['filters']['field_term_subtype_tid']['expose']['operator'] = 'field_term_subtype_tid_op';
  $handler->display->display_options['filters']['field_term_subtype_tid']['expose']['identifier'] = 'field_term_subtype_tid';
  $handler->display->display_options['filters']['field_term_subtype_tid']['expose']['reduce'] = 0;
  $handler->display->display_options['filters']['field_term_subtype_tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['field_term_subtype_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_term_subtype_tid']['vocabulary'] = 'subtype';
  $handler->display->display_options['filters']['field_term_subtype_tid']['error_message'] = 1;
  /* Filter criterion: Content: Source Type (field_term_source_type) */
  $handler->display->display_options['filters']['field_term_source_type_tid']['id'] = 'field_term_source_type_tid';
  $handler->display->display_options['filters']['field_term_source_type_tid']['table'] = 'field_data_field_term_source_type';
  $handler->display->display_options['filters']['field_term_source_type_tid']['field'] = 'field_term_source_type_tid';
  $handler->display->display_options['filters']['field_term_source_type_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_term_source_type_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_term_source_type_tid']['expose']['operator_id'] = 'field_term_source_type_tid_op';
  $handler->display->display_options['filters']['field_term_source_type_tid']['expose']['label'] = 'Source: Type';
  $handler->display->display_options['filters']['field_term_source_type_tid']['expose']['operator'] = 'field_term_source_type_tid_op';
  $handler->display->display_options['filters']['field_term_source_type_tid']['expose']['identifier'] = 'field_term_source_type_tid';
  $handler->display->display_options['filters']['field_term_source_type_tid']['expose']['reduce'] = 0;
  $handler->display->display_options['filters']['field_term_source_type_tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['field_term_source_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_term_source_type_tid']['vocabulary'] = 'source_type';
  $handler->display->display_options['filters']['field_term_source_type_tid']['error_message'] = 1;
  /* Filter criterion: Content: Company type (field_term_company_type) */
  $handler->display->display_options['filters']['field_term_company_type_tid']['id'] = 'field_term_company_type_tid';
  $handler->display->display_options['filters']['field_term_company_type_tid']['table'] = 'field_data_field_term_company_type';
  $handler->display->display_options['filters']['field_term_company_type_tid']['field'] = 'field_term_company_type_tid';
  $handler->display->display_options['filters']['field_term_company_type_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_term_company_type_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_term_company_type_tid']['expose']['operator_id'] = 'field_term_company_type_tid_op';
  $handler->display->display_options['filters']['field_term_company_type_tid']['expose']['label'] = 'Company type ';
  $handler->display->display_options['filters']['field_term_company_type_tid']['expose']['operator'] = 'field_term_company_type_tid_op';
  $handler->display->display_options['filters']['field_term_company_type_tid']['expose']['identifier'] = 'field_term_company_type_tid';
  $handler->display->display_options['filters']['field_term_company_type_tid']['expose']['reduce'] = 0;
  $handler->display->display_options['filters']['field_term_company_type_tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['field_term_company_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_term_company_type_tid']['vocabulary'] = 'company_type';
  $handler->display->display_options['filters']['field_term_company_type_tid']['error_message'] = 1;
  /* Filter criterion: Content: Coverage Type (field_term_coverage_type) */
  $handler->display->display_options['filters']['field_term_coverage_type_tid']['id'] = 'field_term_coverage_type_tid';
  $handler->display->display_options['filters']['field_term_coverage_type_tid']['table'] = 'field_data_field_term_coverage_type';
  $handler->display->display_options['filters']['field_term_coverage_type_tid']['field'] = 'field_term_coverage_type_tid';
  $handler->display->display_options['filters']['field_term_coverage_type_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_term_coverage_type_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_term_coverage_type_tid']['expose']['operator_id'] = 'field_term_coverage_type_tid_op';
  $handler->display->display_options['filters']['field_term_coverage_type_tid']['expose']['label'] = 'Coverage Type';
  $handler->display->display_options['filters']['field_term_coverage_type_tid']['expose']['operator'] = 'field_term_coverage_type_tid_op';
  $handler->display->display_options['filters']['field_term_coverage_type_tid']['expose']['identifier'] = 'field_term_coverage_type_tid';
  $handler->display->display_options['filters']['field_term_coverage_type_tid']['expose']['reduce'] = 0;
  $handler->display->display_options['filters']['field_term_coverage_type_tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['field_term_coverage_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_term_coverage_type_tid']['vocabulary'] = 'coverage_type';
  $handler->display->display_options['filters']['field_term_coverage_type_tid']['error_message'] = 1;
  /* Filter criterion: Content: Has taxonomy term */
  $handler->display->display_options['filters']['tid']['id'] = 'tid';
  $handler->display->display_options['filters']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['filters']['tid']['field'] = 'tid';
  $handler->display->display_options['filters']['tid']['group'] = 1;
  $handler->display->display_options['filters']['tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['tid']['expose']['operator_id'] = 'tid_op';
  $handler->display->display_options['filters']['tid']['expose']['label'] = 'Industry Type';
  $handler->display->display_options['filters']['tid']['expose']['operator'] = 'tid_op';
  $handler->display->display_options['filters']['tid']['expose']['identifier'] = 'tid';
  $handler->display->display_options['filters']['tid']['expose']['reduce'] = 0;
  $handler->display->display_options['filters']['tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['tid']['type'] = 'select';
  $handler->display->display_options['filters']['tid']['vocabulary'] = 'industry_type';
  $handler->display->display_options['filters']['tid']['error_message'] = 1;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 'All';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Published';
  $handler->display->display_options['filters']['status']['expose']['use_operator'] = FALSE;
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['expose']['multiple'] = FALSE;
  /* Filter criterion: Content: Promoted to front page */
  $handler->display->display_options['filters']['promote']['id'] = 'promote';
  $handler->display->display_options['filters']['promote']['table'] = 'node';
  $handler->display->display_options['filters']['promote']['field'] = 'promote';
  $handler->display->display_options['filters']['promote']['value'] = 'All';
  $handler->display->display_options['filters']['promote']['group'] = 1;
  $handler->display->display_options['filters']['promote']['exposed'] = TRUE;
  $handler->display->display_options['filters']['promote']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['promote']['expose']['label'] = 'Promoted';
  $handler->display->display_options['filters']['promote']['expose']['use_operator'] = FALSE;
  $handler->display->display_options['filters']['promote']['expose']['operator'] = 'promote_op';
  $handler->display->display_options['filters']['promote']['expose']['identifier'] = 'promote';
  $handler->display->display_options['filters']['promote']['expose']['multiple'] = FALSE;
  $handler->display->display_options['path'] = 'admin/browse';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Browse';
  $handler->display->display_options['menu']['description'] = 'Browse all Browse';
  $handler->display->display_options['menu']['weight'] = '-20';
  $handler->display->display_options['menu']['name'] = 'management';

  /* Display: 24 Hours */
  $handler = $view->new_display('page', '24 Hours', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Content From the Past 24 Hours';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Content: Deckhead */
  $handler->display->display_options['fields']['field_deckhead']['id'] = 'field_deckhead';
  $handler->display->display_options['fields']['field_deckhead']['table'] = 'field_data_field_deckhead';
  $handler->display->display_options['fields']['field_deckhead']['field'] = 'field_deckhead';
  $handler->display->display_options['fields']['field_deckhead']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_deckhead']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_deckhead']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_deckhead']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_deckhead']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_deckhead']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_deckhead']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_deckhead']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_deckhead']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_deckhead']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_deckhead']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_deckhead']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_deckhead']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_deckhead']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_deckhead']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_deckhead']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_deckhead']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_deckhead']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_deckhead']['field_api_classes'] = 0;
  /* Field: Content: Byline */
  $handler->display->display_options['fields']['field_byline']['id'] = 'field_byline';
  $handler->display->display_options['fields']['field_byline']['table'] = 'field_data_field_byline';
  $handler->display->display_options['fields']['field_byline']['field'] = 'field_byline';
  $handler->display->display_options['fields']['field_byline']['label'] = 'Author';
  $handler->display->display_options['fields']['field_byline']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_byline']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_byline']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_byline']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_byline']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_byline']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_byline']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_byline']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_byline']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_byline']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_byline']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_byline']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_byline']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_byline']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_byline']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_byline']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_byline']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_byline']['field_api_classes'] = 0;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['created']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['created']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['created']['alter']['external'] = 0;
  $handler->display->display_options['fields']['created']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['created']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['created']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['created']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['created']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['created']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['created']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['created']['alter']['html'] = 0;
  $handler->display->display_options['fields']['created']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['created']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['created']['hide_empty'] = 0;
  $handler->display->display_options['fields']['created']['empty_zero'] = 0;
  $handler->display->display_options['fields']['created']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'F j, Y';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['operator'] = 'not in';
  $handler->display->display_options['filters']['type']['value'] = array(
    '360_package_spin_rotate' => '360_package_spin_rotate',
    'page' => 'page',
    'company' => 'company',
    'magazine_covers' => 'magazine_covers',
    'webform' => 'webform',
  );
  /* Filter criterion: Content: Post date */
  $handler->display->display_options['filters']['created']['id'] = 'created';
  $handler->display->display_options['filters']['created']['table'] = 'node';
  $handler->display->display_options['filters']['created']['field'] = 'created';
  $handler->display->display_options['filters']['created']['operator'] = '>';
  $handler->display->display_options['filters']['created']['value']['value'] = '-24 hours';
  $handler->display->display_options['filters']['created']['value']['type'] = 'offset';
  $handler->display->display_options['filters']['created']['exposed'] = TRUE;
  $handler->display->display_options['filters']['created']['expose']['operator_id'] = 'created_op';
  $handler->display->display_options['filters']['created']['expose']['label'] = 'Post date';
  $handler->display->display_options['filters']['created']['expose']['operator'] = 'created_op';
  $handler->display->display_options['filters']['created']['expose']['identifier'] = 'created';
  $handler->display->display_options['filters']['created']['expose']['multiple'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['path'] = 'admin/today';

  /* Display: Needs Viddler Ids */
  $handler = $view->new_display('page', 'Needs Viddler Ids', 'page_2');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Edit';
  $handler->display->display_options['fields']['edit_node']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['external'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['edit_node']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['edit_node']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['html'] = 0;
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['edit_node']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['edit_node']['hide_empty'] = 0;
  $handler->display->display_options['fields']['edit_node']['empty_zero'] = 0;
  /* Field: Bulk operations: Content */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = '';
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['external'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['html'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['hide_empty'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['empty_zero'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::node_assign_owner_action' => array(
      'selected' => 1,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'postpone_processing' => 0,
    ),
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 1,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'postpone_processing' => 0,
    ),
    'action::views_bulk_operations_script_action' => array(
      'selected' => 1,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'postpone_processing' => 0,
    ),
    'action::node_make_sticky_action' => array(
      'selected' => 1,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'postpone_processing' => 0,
    ),
    'action::node_make_unsticky_action' => array(
      'selected' => 1,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'postpone_processing' => 0,
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
      'selected' => 1,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'postpone_processing' => 0,
    ),
    'action::node_publish_action' => array(
      'selected' => 1,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'postpone_processing' => 0,
    ),
    'action::node_unpromote_action' => array(
      'selected' => 1,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'postpone_processing' => 0,
    ),
    'action::node_save_action' => array(
      'selected' => 1,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'postpone_processing' => 0,
    ),
    'action::system_send_email_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'postpone_processing' => 0,
    ),
    'action::node_unpublish_action' => array(
      'selected' => 1,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'postpone_processing' => 0,
    ),
    'action::node_unpublish_by_keyword_action' => array(
      'selected' => 1,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'postpone_processing' => 0,
    ),
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['type']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['type']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['type']['alter']['external'] = 0;
  $handler->display->display_options['fields']['type']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['type']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['type']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['type']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['type']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['type']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['type']['alter']['html'] = 0;
  $handler->display->display_options['fields']['type']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['type']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['type']['hide_empty'] = 0;
  $handler->display->display_options['fields']['type']['empty_zero'] = 0;
  $handler->display->display_options['fields']['type']['link_to_node'] = 0;
  $handler->display->display_options['fields']['type']['machine_name'] = 0;
  /* Field: Content: Subtype */
  $handler->display->display_options['fields']['field_term_subtype']['id'] = 'field_term_subtype';
  $handler->display->display_options['fields']['field_term_subtype']['table'] = 'field_data_field_term_subtype';
  $handler->display->display_options['fields']['field_term_subtype']['field'] = 'field_term_subtype';
  $handler->display->display_options['fields']['field_term_subtype']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_term_subtype']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_term_subtype']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_term_subtype']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_term_subtype']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_term_subtype']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_term_subtype']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_term_subtype']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_term_subtype']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_term_subtype']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_term_subtype']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_term_subtype']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_term_subtype']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_term_subtype']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_term_subtype']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_term_subtype']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_term_subtype']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_term_subtype']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_term_subtype']['field_api_classes'] = 0;
  /* Field: Content: Source Type */
  $handler->display->display_options['fields']['field_term_source_type']['id'] = 'field_term_source_type';
  $handler->display->display_options['fields']['field_term_source_type']['table'] = 'field_data_field_term_source_type';
  $handler->display->display_options['fields']['field_term_source_type']['field'] = 'field_term_source_type';
  $handler->display->display_options['fields']['field_term_source_type']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_term_source_type']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_term_source_type']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_term_source_type']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_term_source_type']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_term_source_type']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_term_source_type']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_term_source_type']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_term_source_type']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_term_source_type']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_term_source_type']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_term_source_type']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_term_source_type']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_term_source_type']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_term_source_type']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_term_source_type']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_term_source_type']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_term_source_type']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_term_source_type']['field_api_classes'] = 0;
  /* Field: Content: Byline */
  $handler->display->display_options['fields']['field_byline']['id'] = 'field_byline';
  $handler->display->display_options['fields']['field_byline']['table'] = 'field_data_field_byline';
  $handler->display->display_options['fields']['field_byline']['field'] = 'field_byline';
  $handler->display->display_options['fields']['field_byline']['label'] = 'Author';
  $handler->display->display_options['fields']['field_byline']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_byline']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_byline']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_byline']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_byline']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_byline']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_byline']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_byline']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_byline']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_byline']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_byline']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_byline']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_byline']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_byline']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_byline']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_byline']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_byline']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_byline']['field_api_classes'] = 0;
  /* Field: Content: Companies */
  $handler->display->display_options['fields']['field_companies']['id'] = 'field_companies';
  $handler->display->display_options['fields']['field_companies']['table'] = 'field_data_field_companies';
  $handler->display->display_options['fields']['field_companies']['field'] = 'field_companies';
  $handler->display->display_options['fields']['field_companies']['label'] = 'CompanY';
  $handler->display->display_options['fields']['field_companies']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_companies']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_companies']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_companies']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_companies']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_companies']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_companies']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_companies']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_companies']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_companies']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_companies']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_companies']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_companies']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_companies']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_companies']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_companies']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_companies']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_companies']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_companies']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_companies']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_companies']['field_api_classes'] = 0;
  /* Field: Content: Has new content */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'history';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['label'] = 'New?';
  $handler->display->display_options['fields']['timestamp']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['timestamp']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['timestamp']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['timestamp']['alter']['external'] = 0;
  $handler->display->display_options['fields']['timestamp']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['timestamp']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['timestamp']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['timestamp']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['timestamp']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['timestamp']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['timestamp']['alter']['html'] = 0;
  $handler->display->display_options['fields']['timestamp']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['timestamp']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['timestamp']['hide_empty'] = 0;
  $handler->display->display_options['fields']['timestamp']['empty_zero'] = 0;
  $handler->display->display_options['fields']['timestamp']['link_to_node'] = 0;
  $handler->display->display_options['fields']['timestamp']['comments'] = 0;
  /* Field: Content: Published */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'node';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['status']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['status']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['status']['alter']['external'] = 0;
  $handler->display->display_options['fields']['status']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['status']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['status']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['status']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['status']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['status']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['status']['alter']['html'] = 0;
  $handler->display->display_options['fields']['status']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['status']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['status']['hide_empty'] = 0;
  $handler->display->display_options['fields']['status']['empty_zero'] = 0;
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['created']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['created']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['created']['alter']['external'] = 0;
  $handler->display->display_options['fields']['created']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['created']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['created']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['created']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['created']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['created']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['created']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['created']['alter']['html'] = 0;
  $handler->display->display_options['fields']['created']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['created']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['created']['hide_empty'] = 0;
  $handler->display->display_options['fields']['created']['empty_zero'] = 0;
  $handler->display->display_options['fields']['created']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'F j, Y';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Viddler ID (field_viddler_id) */
  $handler->display->display_options['filters']['field_viddler_id_value']['id'] = 'field_viddler_id_value';
  $handler->display->display_options['filters']['field_viddler_id_value']['table'] = 'field_data_field_viddler_id';
  $handler->display->display_options['filters']['field_viddler_id_value']['field'] = 'field_viddler_id_value';
  $handler->display->display_options['filters']['field_viddler_id_value']['operator'] = 'empty';
  /* Filter criterion: Content: Waywire Video (field_waywire_video:lb) */
  $handler->display->display_options['filters']['field_waywire_video_lb']['id'] = 'field_waywire_video_lb';
  $handler->display->display_options['filters']['field_waywire_video_lb']['table'] = 'field_data_field_waywire_video';
  $handler->display->display_options['filters']['field_waywire_video_lb']['field'] = 'field_waywire_video_lb';
  $handler->display->display_options['filters']['field_waywire_video_lb']['operator'] = 'not empty';
  $handler->display->display_options['path'] = 'admin/browse/viddler-waywire';
  $handler->display->display_options['menu']['title'] = 'Browse';
  $handler->display->display_options['menu']['description'] = 'Browse all Browse';
  $handler->display->display_options['menu']['weight'] = '-20';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;

  /* Display: Needs Viddler Ids Embedded */
  $handler = $view->new_display('page', 'Needs Viddler Ids Embedded', 'page_3');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Edit';
  $handler->display->display_options['fields']['edit_node']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['external'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['edit_node']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['edit_node']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['html'] = 0;
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['edit_node']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['edit_node']['hide_empty'] = 0;
  $handler->display->display_options['fields']['edit_node']['empty_zero'] = 0;
  /* Field: Bulk operations: Content */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = '';
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['external'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['html'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['hide_empty'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['empty_zero'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::node_assign_owner_action' => array(
      'selected' => 1,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'postpone_processing' => 0,
    ),
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 1,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'postpone_processing' => 0,
    ),
    'action::views_bulk_operations_script_action' => array(
      'selected' => 1,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'postpone_processing' => 0,
    ),
    'action::node_make_sticky_action' => array(
      'selected' => 1,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'postpone_processing' => 0,
    ),
    'action::node_make_unsticky_action' => array(
      'selected' => 1,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'postpone_processing' => 0,
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
      'selected' => 1,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'postpone_processing' => 0,
    ),
    'action::node_publish_action' => array(
      'selected' => 1,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'postpone_processing' => 0,
    ),
    'action::node_unpromote_action' => array(
      'selected' => 1,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'postpone_processing' => 0,
    ),
    'action::node_save_action' => array(
      'selected' => 1,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'postpone_processing' => 0,
    ),
    'action::system_send_email_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'postpone_processing' => 0,
    ),
    'action::node_unpublish_action' => array(
      'selected' => 1,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'postpone_processing' => 0,
    ),
    'action::node_unpublish_by_keyword_action' => array(
      'selected' => 1,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'postpone_processing' => 0,
    ),
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['type']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['type']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['type']['alter']['external'] = 0;
  $handler->display->display_options['fields']['type']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['type']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['type']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['type']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['type']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['type']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['type']['alter']['html'] = 0;
  $handler->display->display_options['fields']['type']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['type']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['type']['hide_empty'] = 0;
  $handler->display->display_options['fields']['type']['empty_zero'] = 0;
  $handler->display->display_options['fields']['type']['link_to_node'] = 0;
  $handler->display->display_options['fields']['type']['machine_name'] = 0;
  /* Field: Content: Subtype */
  $handler->display->display_options['fields']['field_term_subtype']['id'] = 'field_term_subtype';
  $handler->display->display_options['fields']['field_term_subtype']['table'] = 'field_data_field_term_subtype';
  $handler->display->display_options['fields']['field_term_subtype']['field'] = 'field_term_subtype';
  $handler->display->display_options['fields']['field_term_subtype']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_term_subtype']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_term_subtype']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_term_subtype']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_term_subtype']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_term_subtype']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_term_subtype']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_term_subtype']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_term_subtype']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_term_subtype']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_term_subtype']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_term_subtype']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_term_subtype']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_term_subtype']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_term_subtype']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_term_subtype']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_term_subtype']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_term_subtype']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_term_subtype']['field_api_classes'] = 0;
  /* Field: Content: Source Type */
  $handler->display->display_options['fields']['field_term_source_type']['id'] = 'field_term_source_type';
  $handler->display->display_options['fields']['field_term_source_type']['table'] = 'field_data_field_term_source_type';
  $handler->display->display_options['fields']['field_term_source_type']['field'] = 'field_term_source_type';
  $handler->display->display_options['fields']['field_term_source_type']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_term_source_type']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_term_source_type']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_term_source_type']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_term_source_type']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_term_source_type']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_term_source_type']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_term_source_type']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_term_source_type']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_term_source_type']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_term_source_type']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_term_source_type']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_term_source_type']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_term_source_type']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_term_source_type']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_term_source_type']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_term_source_type']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_term_source_type']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_term_source_type']['field_api_classes'] = 0;
  /* Field: Content: Byline */
  $handler->display->display_options['fields']['field_byline']['id'] = 'field_byline';
  $handler->display->display_options['fields']['field_byline']['table'] = 'field_data_field_byline';
  $handler->display->display_options['fields']['field_byline']['field'] = 'field_byline';
  $handler->display->display_options['fields']['field_byline']['label'] = 'Author';
  $handler->display->display_options['fields']['field_byline']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_byline']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_byline']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_byline']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_byline']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_byline']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_byline']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_byline']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_byline']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_byline']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_byline']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_byline']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_byline']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_byline']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_byline']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_byline']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_byline']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_byline']['field_api_classes'] = 0;
  /* Field: Content: Companies */
  $handler->display->display_options['fields']['field_companies']['id'] = 'field_companies';
  $handler->display->display_options['fields']['field_companies']['table'] = 'field_data_field_companies';
  $handler->display->display_options['fields']['field_companies']['field'] = 'field_companies';
  $handler->display->display_options['fields']['field_companies']['label'] = 'CompanY';
  $handler->display->display_options['fields']['field_companies']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_companies']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_companies']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_companies']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_companies']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_companies']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_companies']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_companies']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_companies']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_companies']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_companies']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_companies']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_companies']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_companies']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_companies']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_companies']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_companies']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_companies']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_companies']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_companies']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_companies']['field_api_classes'] = 0;
  /* Field: Content: Has new content */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'history';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['label'] = 'New?';
  $handler->display->display_options['fields']['timestamp']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['timestamp']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['timestamp']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['timestamp']['alter']['external'] = 0;
  $handler->display->display_options['fields']['timestamp']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['timestamp']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['timestamp']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['timestamp']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['timestamp']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['timestamp']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['timestamp']['alter']['html'] = 0;
  $handler->display->display_options['fields']['timestamp']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['timestamp']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['timestamp']['hide_empty'] = 0;
  $handler->display->display_options['fields']['timestamp']['empty_zero'] = 0;
  $handler->display->display_options['fields']['timestamp']['link_to_node'] = 0;
  $handler->display->display_options['fields']['timestamp']['comments'] = 0;
  /* Field: Content: Published */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'node';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['status']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['status']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['status']['alter']['external'] = 0;
  $handler->display->display_options['fields']['status']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['status']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['status']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['status']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['status']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['status']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['status']['alter']['html'] = 0;
  $handler->display->display_options['fields']['status']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['status']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['status']['hide_empty'] = 0;
  $handler->display->display_options['fields']['status']['empty_zero'] = 0;
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['created']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['created']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['created']['alter']['external'] = 0;
  $handler->display->display_options['fields']['created']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['created']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['created']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['created']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['created']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['created']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['created']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['created']['alter']['html'] = 0;
  $handler->display->display_options['fields']['created']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['created']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['created']['hide_empty'] = 0;
  $handler->display->display_options['fields']['created']['empty_zero'] = 0;
  $handler->display->display_options['fields']['created']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'F j, Y';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Body (body) */
  $handler->display->display_options['filters']['body_value']['id'] = 'body_value';
  $handler->display->display_options['filters']['body_value']['table'] = 'field_data_body';
  $handler->display->display_options['filters']['body_value']['field'] = 'body_value';
  $handler->display->display_options['filters']['body_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['body_value']['value'] = 'pmmimediagroup.waywire.com';
  $handler->display->display_options['path'] = 'admin/browse/viddler-waywire-embedded';
  $handler->display->display_options['menu']['title'] = 'Browse';
  $handler->display->display_options['menu']['description'] = 'Browse all Browse';
  $handler->display->display_options['menu']['weight'] = '-20';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $export['admin_content'] = $view;

  $view = new view;
  $view->name = 'fdt_coverage';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'FDT Coverage';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'FDT Device Integration Strategies';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['links'] = 1;
  $handler->display->display_options['row_options']['comments'] = 0;
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_image']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_image']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_image']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_image']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_image']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_image']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_image']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_image']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_image']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_image']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_image']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_image']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_image']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_image']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_image']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => 'fdt_head_block',
    'image_link' => 'content',
  );
  $handler->display->display_options['fields']['field_image']['field_api_classes'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Content: Deckhead */
  $handler->display->display_options['fields']['field_deckhead']['id'] = 'field_deckhead';
  $handler->display->display_options['fields']['field_deckhead']['table'] = 'field_data_field_deckhead';
  $handler->display->display_options['fields']['field_deckhead']['field'] = 'field_deckhead';
  $handler->display->display_options['fields']['field_deckhead']['label'] = '';
  $handler->display->display_options['fields']['field_deckhead']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_deckhead']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_deckhead']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_deckhead']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_deckhead']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_deckhead']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_deckhead']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_deckhead']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_deckhead']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_deckhead']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_deckhead']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_deckhead']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_deckhead']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_deckhead']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_deckhead']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_deckhead']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_deckhead']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_deckhead']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_deckhead']['field_api_classes'] = 0;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Has taxonomy term */
  $handler->display->display_options['filters']['tid']['id'] = 'tid';
  $handler->display->display_options['filters']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['filters']['tid']['field'] = 'tid';
  $handler->display->display_options['filters']['tid']['value'] = array(
    0 => '2218',
  );
  $handler->display->display_options['filters']['tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['tid']['vocabulary'] = 'coverage_type';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '1';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: View area */
  $handler->display->display_options['header']['view']['id'] = 'view';
  $handler->display->display_options['header']['view']['table'] = 'views';
  $handler->display->display_options['header']['view']['field'] = 'view';
  $handler->display->display_options['header']['view']['empty'] = FALSE;
  $handler->display->display_options['header']['view']['view_to_insert'] = 'fdt_coverage:block_1';
  $handler->display->display_options['header']['view']['inherit_arguments'] = 0;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Has taxonomy term */
  $handler->display->display_options['filters']['tid']['id'] = 'tid';
  $handler->display->display_options['filters']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['filters']['tid']['field'] = 'tid';
  $handler->display->display_options['filters']['tid']['value'] = array(
    0 => '2218',
  );
  $handler->display->display_options['filters']['tid']['group'] = 1;
  $handler->display->display_options['filters']['tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['tid']['vocabulary'] = 'coverage_type';
  $handler->display->display_options['path'] = 'device-integration-strategies';

  /* Display: FDT Header */
  $handler = $view->new_display('block', 'FDT Header', 'block_1');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = 0;
  $handler->display->display_options['row_options']['default_field_elements'] = 1;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = '<img id="fdt-banner" src="/sites/default/files/fdt/fdt-banner-7.jpg" />';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['header']['area']['tokenize'] = 0;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Has taxonomy term */
  $handler->display->display_options['filters']['tid']['id'] = 'tid';
  $handler->display->display_options['filters']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['filters']['tid']['field'] = 'tid';
  $handler->display->display_options['filters']['tid']['value'] = array(
    0 => '2218',
  );
  $handler->display->display_options['filters']['tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['tid']['vocabulary'] = 'coverage_type';
  /* Filter criterion: Content: Image (field_image:fid) */
  $handler->display->display_options['filters']['field_image_fid']['id'] = 'field_image_fid';
  $handler->display->display_options['filters']['field_image_fid']['table'] = 'field_data_field_image';
  $handler->display->display_options['filters']['field_image_fid']['field'] = 'field_image_fid';
  $handler->display->display_options['filters']['field_image_fid']['operator'] = 'not empty';
  $export['fdt_coverage'] = $view;

  $view = new view;
  $view->name = 'home_river_of_content';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Home - River of content';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['links'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Has taxonomy terms (with depth) */
  $handler->display->display_options['filters']['term_node_tid_depth']['id'] = 'term_node_tid_depth';
  $handler->display->display_options['filters']['term_node_tid_depth']['table'] = 'node';
  $handler->display->display_options['filters']['term_node_tid_depth']['field'] = 'term_node_tid_depth';
  $handler->display->display_options['filters']['term_node_tid_depth']['group'] = '0';
  $handler->display->display_options['filters']['term_node_tid_depth']['type'] = 'select';
  $handler->display->display_options['filters']['term_node_tid_depth']['vocabulary'] = 'source_type';
  $handler->display->display_options['filters']['term_node_tid_depth']['hierarchy'] = 1;
  $handler->display->display_options['filters']['term_node_tid_depth']['depth'] = '5';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Source Type (field_term_source_type) */
  $handler->display->display_options['filters']['field_term_source_type_tid']['id'] = 'field_term_source_type_tid';
  $handler->display->display_options['filters']['field_term_source_type_tid']['table'] = 'field_data_field_term_source_type';
  $handler->display->display_options['filters']['field_term_source_type_tid']['field'] = 'field_term_source_type_tid';
  $handler->display->display_options['filters']['field_term_source_type_tid']['value'] = array(
    138 => '138',
  );
  $handler->display->display_options['filters']['field_term_source_type_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_term_source_type_tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['field_term_source_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_term_source_type_tid']['vocabulary'] = 'source_type';
  $handler->display->display_options['filters']['field_term_source_type_tid']['hierarchy'] = 1;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'article' => 'article',
    'blog' => 'blog',
    'podcast' => 'podcast',
    'video' => 'video',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Promoted to front page */
  $handler->display->display_options['filters']['promote']['id'] = 'promote';
  $handler->display->display_options['filters']['promote']['table'] = 'node';
  $handler->display->display_options['filters']['promote']['field'] = 'promote';
  $handler->display->display_options['filters']['promote']['value'] = '0';
  $handler->display->display_options['filters']['promote']['group'] = 1;
  /* Filter criterion: Content: Coverage Type (field_term_coverage_type) */
  $handler->display->display_options['filters']['field_term_coverage_type_tid']['id'] = 'field_term_coverage_type_tid';
  $handler->display->display_options['filters']['field_term_coverage_type_tid']['table'] = 'field_data_field_term_coverage_type';
  $handler->display->display_options['filters']['field_term_coverage_type_tid']['field'] = 'field_term_coverage_type_tid';
  $handler->display->display_options['filters']['field_term_coverage_type_tid']['operator'] = 'not';
  $handler->display->display_options['filters']['field_term_coverage_type_tid']['value'] = array(
    1941 => '1941',
  );
  $handler->display->display_options['filters']['field_term_coverage_type_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_term_coverage_type_tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['field_term_coverage_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_term_coverage_type_tid']['vocabulary'] = 'coverage_type';
  $handler->display->display_options['filters']['field_term_coverage_type_tid']['hierarchy'] = 1;
  $handler->display->display_options['path'] = 'home';

  /* Display: Feed */
  $handler = $view->new_display('feed', 'Feed', 'feed_1');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '15';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'rss';
  $handler->display->display_options['row_plugin'] = 'node_rss';
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'AND',
  );
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Source Type (field_term_source_type) */
  $handler->display->display_options['filters']['field_term_source_type_tid']['id'] = 'field_term_source_type_tid';
  $handler->display->display_options['filters']['field_term_source_type_tid']['table'] = 'field_data_field_term_source_type';
  $handler->display->display_options['filters']['field_term_source_type_tid']['field'] = 'field_term_source_type_tid';
  $handler->display->display_options['filters']['field_term_source_type_tid']['value'] = array(
    138 => '138',
  );
  $handler->display->display_options['filters']['field_term_source_type_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_term_source_type_tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['field_term_source_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_term_source_type_tid']['vocabulary'] = 'source_type';
  /* Filter criterion: Content: Subtype (field_term_subtype) */
  $handler->display->display_options['filters']['field_term_subtype_tid']['id'] = 'field_term_subtype_tid';
  $handler->display->display_options['filters']['field_term_subtype_tid']['table'] = 'field_data_field_term_subtype';
  $handler->display->display_options['filters']['field_term_subtype_tid']['field'] = 'field_term_subtype_tid';
  $handler->display->display_options['filters']['field_term_subtype_tid']['operator'] = 'not';
  $handler->display->display_options['filters']['field_term_subtype_tid']['value'] = array(
    162 => '162',
  );
  $handler->display->display_options['filters']['field_term_subtype_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_term_subtype_tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['field_term_subtype_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_term_subtype_tid']['vocabulary'] = 'subtype';
  $handler->display->display_options['path'] = 'rss';

  /* Display: Interstital Demo */
  $handler = $view->new_display('page', 'Interstital Demo', 'page_1');
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '15';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Source Type (field_term_source_type) */
  $handler->display->display_options['filters']['field_term_source_type_tid']['id'] = 'field_term_source_type_tid';
  $handler->display->display_options['filters']['field_term_source_type_tid']['table'] = 'field_data_field_term_source_type';
  $handler->display->display_options['filters']['field_term_source_type_tid']['field'] = 'field_term_source_type_tid';
  $handler->display->display_options['filters']['field_term_source_type_tid']['value'] = array(
    138 => '138',
  );
  $handler->display->display_options['filters']['field_term_source_type_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_term_source_type_tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['field_term_source_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_term_source_type_tid']['vocabulary'] = 'source_type';
  $handler->display->display_options['filters']['field_term_source_type_tid']['hierarchy'] = 1;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'article' => 'article',
    'blog' => 'blog',
    'podcast' => 'podcast',
    'video' => 'video',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Promoted to front page */
  $handler->display->display_options['filters']['promote']['id'] = 'promote';
  $handler->display->display_options['filters']['promote']['table'] = 'node';
  $handler->display->display_options['filters']['promote']['field'] = 'promote';
  $handler->display->display_options['filters']['promote']['value'] = '0';
  $handler->display->display_options['filters']['promote']['group'] = 1;
  $handler->display->display_options['path'] = 'demo/interstitial';
  $export['home_river_of_content'] = $view;

  return $export;
}
