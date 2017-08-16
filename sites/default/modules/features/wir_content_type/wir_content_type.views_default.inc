<?php
/**
 * @file
 * wir_content_type.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function wir_content_type_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'related_links';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Related Links';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Related Links';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Broken/missing handler */
  $handler->display->display_options['relationships']['field_related_sponsor_nid']['id'] = 'field_related_sponsor_nid';
  $handler->display->display_options['relationships']['field_related_sponsor_nid']['table'] = 'field_data_field_related_sponsor';
  $handler->display->display_options['relationships']['field_related_sponsor_nid']['field'] = 'field_related_sponsor_nid';
  $handler->display->display_options['relationships']['field_related_sponsor_nid']['label'] = 'Sponsor';
  $handler->display->display_options['relationships']['field_related_sponsor_nid']['required'] = 0;
  /* Field: Content: Sponsor links – Beyond Factory Walls */
  $handler->display->display_options['fields']['field_sponsor_links']['id'] = 'field_sponsor_links';
  $handler->display->display_options['fields']['field_sponsor_links']['table'] = 'field_data_field_sponsor_links';
  $handler->display->display_options['fields']['field_sponsor_links']['field'] = 'field_sponsor_links';
  $handler->display->display_options['fields']['field_sponsor_links']['relationship'] = 'field_wir_sponsor_target_id';
  $handler->display->display_options['fields']['field_sponsor_links']['label'] = '';
  $handler->display->display_options['fields']['field_sponsor_links']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_sponsor_links']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_sponsor_links']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_sponsor_links']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_sponsor_links']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_sponsor_links']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_sponsor_links']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_sponsor_links']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_sponsor_links']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_sponsor_links']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_sponsor_links']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_sponsor_links']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_sponsor_links']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_sponsor_links']['element_class'] = 'related-links__content';
  $handler->display->display_options['fields']['field_sponsor_links']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_sponsor_links']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_sponsor_links']['hide_empty'] = 1;
  $handler->display->display_options['fields']['field_sponsor_links']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_sponsor_links']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_sponsor_links']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_sponsor_links']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_sponsor_links']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_sponsor_links']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_sponsor_links']['delta_first_last'] = 0;
  $handler->display->display_options['fields']['field_sponsor_links']['multi_type'] = 'ul';
  $handler->display->display_options['fields']['field_sponsor_links']['field_api_classes'] = 0;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['nid']['not'] = 0;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'week_in_review' => 'week_in_review',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_wir_sponsor_target_id']['id'] = 'field_wir_sponsor_target_id';
  $handler->display->display_options['relationships']['field_wir_sponsor_target_id']['table'] = 'field_data_field_wir_sponsor';
  $handler->display->display_options['relationships']['field_wir_sponsor_target_id']['field'] = 'field_wir_sponsor_target_id';
  $handler->display->display_options['relationships']['field_wir_sponsor_target_id']['required'] = 1;
  $export['related_links'] = $view;

  $view = new view;
  $view->name = 'top_week_in_review';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Top week in review';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Top week in review';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['links'] = 1;
  $handler->display->display_options['row_options']['comments'] = 0;
  /* Field: Field: Large Image */
  $handler->display->display_options['fields']['field_360_fc_large']['id'] = 'field_360_fc_large';
  $handler->display->display_options['fields']['field_360_fc_large']['table'] = 'field_data_field_360_fc_large';
  $handler->display->display_options['fields']['field_360_fc_large']['field'] = 'field_360_fc_large';
  $handler->display->display_options['fields']['field_360_fc_large']['label'] = '';
  $handler->display->display_options['fields']['field_360_fc_large']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_360_fc_large']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_360_fc_large']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_360_fc_large']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_360_fc_large']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_360_fc_large']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_360_fc_large']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_360_fc_large']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_360_fc_large']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_360_fc_large']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_360_fc_large']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_360_fc_large']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_360_fc_large']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_360_fc_large']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_360_fc_large']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_360_fc_large']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_360_fc_large']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_360_fc_large']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_360_fc_large']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_360_fc_large']['settings'] = array(
    'image_style' => 'teaser',
    'image_link' => 'content',
  );
  $handler->display->display_options['fields']['field_360_fc_large']['field_api_classes'] = 0;
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
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'week_in_review' => 'week_in_review',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'btfw';
  $export['top_week_in_review'] = $view;

  $view = new view;
  $view->name = 'update_week_in_review_field_value';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Update week in review field value';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Update week in review field value';
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
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
  /* Field: Bulk operations: Content */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
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
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['hide_empty'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['empty_zero'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
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
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'show_all_tokens' => 1,
        'display_values' => array(
          'week_in_review::field_wir_sponsor' => 'week_in_review::field_wir_sponsor',
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
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
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
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_unpublish_by_keyword_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::pathauto_node_update_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
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
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'week_in_review' => 'week_in_review',
  );
  /* Filter criterion: Content: Post date */
  $handler->display->display_options['filters']['created']['id'] = 'created';
  $handler->display->display_options['filters']['created']['table'] = 'node';
  $handler->display->display_options['filters']['created']['field'] = 'created';
  $handler->display->display_options['filters']['created']['operator'] = '<';
  $handler->display->display_options['filters']['created']['value']['value'] = '2017-01-05 00:00:00';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'admin/content/update-week-in-review';
  $export['update_week_in_review_field_value'] = $view;

  $view = new view;
  $view->name = 'wir_related_links';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'WIR related links';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'WIR related block';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '2';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Coverage type */
  $handler->display->display_options['fields']['field_term_coverage']['id'] = 'field_term_coverage';
  $handler->display->display_options['fields']['field_term_coverage']['table'] = 'field_data_field_term_coverage';
  $handler->display->display_options['fields']['field_term_coverage']['field'] = 'field_term_coverage';
  $handler->display->display_options['fields']['field_term_coverage']['label'] = 'sponsored';
  $handler->display->display_options['fields']['field_term_coverage']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_term_coverage']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_term_coverage']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_term_coverage']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_term_coverage']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_term_coverage']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_term_coverage']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_term_coverage']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_term_coverage']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_term_coverage']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_term_coverage']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_term_coverage']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_term_coverage']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_term_coverage']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_term_coverage']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_term_coverage']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_term_coverage']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_term_coverage']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_term_coverage']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_term_coverage']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_term_coverage']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_term_coverage']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_term_coverage']['delta_first_last'] = 0;
  $handler->display->display_options['fields']['field_term_coverage']['field_api_classes'] = 0;
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
  /* Sort criterion: Global: Random */
  $handler->display->display_options['sorts']['random']['id'] = 'random';
  $handler->display->display_options['sorts']['random']['table'] = 'views';
  $handler->display->display_options['sorts']['random']['field'] = 'random';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Coverage Type (field_term_coverage_type) */
  $handler->display->display_options['filters']['field_term_coverage_type_tid']['id'] = 'field_term_coverage_type_tid';
  $handler->display->display_options['filters']['field_term_coverage_type_tid']['table'] = 'field_data_field_term_coverage_type';
  $handler->display->display_options['filters']['field_term_coverage_type_tid']['field'] = 'field_term_coverage_type_tid';
  $handler->display->display_options['filters']['field_term_coverage_type_tid']['value'] = array(
    3157 => '3157',
  );
  $handler->display->display_options['filters']['field_term_coverage_type_tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['field_term_coverage_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_term_coverage_type_tid']['vocabulary'] = 'coverage_type';
  $handler->display->display_options['filters']['field_term_coverage_type_tid']['hierarchy'] = 1;

  /* Display: original links */
  $handler = $view->new_display('block', 'original links', 'block');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['fields'] = FALSE;
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
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Coverage Type (field_term_coverage_type) */
  $handler->display->display_options['filters']['field_term_coverage_type_tid']['id'] = 'field_term_coverage_type_tid';
  $handler->display->display_options['filters']['field_term_coverage_type_tid']['table'] = 'field_data_field_term_coverage_type';
  $handler->display->display_options['filters']['field_term_coverage_type_tid']['field'] = 'field_term_coverage_type_tid';
  $handler->display->display_options['filters']['field_term_coverage_type_tid']['value'] = array(
    3157 => '3157',
  );
  $handler->display->display_options['filters']['field_term_coverage_type_tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['field_term_coverage_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_term_coverage_type_tid']['vocabulary'] = 'coverage_type';
  $handler->display->display_options['filters']['field_term_coverage_type_tid']['hierarchy'] = 1;
  /* Filter criterion: Content: Source Type (field_term_source_type) */
  $handler->display->display_options['filters']['field_term_source_type_tid']['id'] = 'field_term_source_type_tid';
  $handler->display->display_options['filters']['field_term_source_type_tid']['table'] = 'field_data_field_term_source_type';
  $handler->display->display_options['filters']['field_term_source_type_tid']['field'] = 'field_term_source_type_tid';
  $handler->display->display_options['filters']['field_term_source_type_tid']['value'] = array(
    138 => '138',
  );
  $handler->display->display_options['filters']['field_term_source_type_tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['field_term_source_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_term_source_type_tid']['vocabulary'] = 'source_type';
  $handler->display->display_options['filters']['field_term_source_type_tid']['hierarchy'] = 1;

  /* Display: sponsored links */
  $handler = $view->new_display('block', 'sponsored links', 'block_1');
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Coverage Type (field_term_coverage_type) */
  $handler->display->display_options['filters']['field_term_coverage_type_tid']['id'] = 'field_term_coverage_type_tid';
  $handler->display->display_options['filters']['field_term_coverage_type_tid']['table'] = 'field_data_field_term_coverage_type';
  $handler->display->display_options['filters']['field_term_coverage_type_tid']['field'] = 'field_term_coverage_type_tid';
  $handler->display->display_options['filters']['field_term_coverage_type_tid']['value'] = array(
    3157 => '3157',
  );
  $handler->display->display_options['filters']['field_term_coverage_type_tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['field_term_coverage_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_term_coverage_type_tid']['vocabulary'] = 'coverage_type';
  $handler->display->display_options['filters']['field_term_coverage_type_tid']['hierarchy'] = 1;
  /* Filter criterion: Content: Source Type (field_term_source_type) */
  $handler->display->display_options['filters']['field_term_source_type_tid']['id'] = 'field_term_source_type_tid';
  $handler->display->display_options['filters']['field_term_source_type_tid']['table'] = 'field_data_field_term_source_type';
  $handler->display->display_options['filters']['field_term_source_type_tid']['field'] = 'field_term_source_type_tid';
  $handler->display->display_options['filters']['field_term_source_type_tid']['value'] = array(
    139 => '139',
  );
  $handler->display->display_options['filters']['field_term_source_type_tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['field_term_source_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_term_source_type_tid']['vocabulary'] = 'source_type';
  $handler->display->display_options['filters']['field_term_source_type_tid']['hierarchy'] = 1;
  $export['wir_related_links'] = $view;

  return $export;
}
