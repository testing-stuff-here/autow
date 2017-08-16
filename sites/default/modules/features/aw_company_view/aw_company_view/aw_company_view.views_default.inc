<?php
/**
 * @file
 * aw_company_view.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function aw_company_view_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'company';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'company';
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
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
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
  /* Contextual filter: Content: Companies (field_companies) */
  $handler->display->display_options['arguments']['field_companies_nid']['id'] = 'field_companies_nid';
  $handler->display->display_options['arguments']['field_companies_nid']['table'] = 'field_data_field_companies';
  $handler->display->display_options['arguments']['field_companies_nid']['field'] = 'field_companies_nid';
  $handler->display->display_options['arguments']['field_companies_nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_companies_nid']['summary']['format'] = 'default_summary';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Source Type (field_term_source_type) */
  $handler->display->display_options['filters']['field_term_source_type_tid']['id'] = 'field_term_source_type_tid';
  $handler->display->display_options['filters']['field_term_source_type_tid']['table'] = 'field_data_field_term_source_type';
  $handler->display->display_options['filters']['field_term_source_type_tid']['field'] = 'field_term_source_type_tid';
  $handler->display->display_options['filters']['field_term_source_type_tid']['vocabulary'] = 'source_type';

  /* Display: Block - Feature Stories & Case Application */
  $handler = $view->new_display('block', 'Block - Feature Stories & Case Application', 'block_1');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'field_deckhead' => 'field_deckhead',
    'view_node' => 'view_node',
  );
  $handler->display->display_options['row_options']['hide_empty'] = 0;
  $handler->display->display_options['row_options']['default_field_elements'] = 1;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
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
  $handler->display->display_options['fields']['field_image']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_image']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_image']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_image']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_image']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_image']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => '190x190',
    'image_link' => 'content',
  );
  $handler->display->display_options['fields']['field_image']['field_api_classes'] = 0;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = '';
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
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['created']['hide_empty'] = 0;
  $handler->display->display_options['fields']['created']['empty_zero'] = 0;
  $handler->display->display_options['fields']['created']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'F d, Y';
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
  $handler->display->display_options['fields']['field_deckhead']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_deckhead']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_deckhead']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_deckhead']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_deckhead']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_deckhead']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_deckhead']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_deckhead']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_deckhead']['field_api_classes'] = 0;
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['external'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['view_node']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['view_node']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['html'] = 0;
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_node']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['view_node']['hide_empty'] = 0;
  $handler->display->display_options['fields']['view_node']['empty_zero'] = 0;
  $handler->display->display_options['fields']['view_node']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['view_node']['text'] = 'Full Article';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Companies (field_companies) */
  $handler->display->display_options['arguments']['field_companies_nid']['id'] = 'field_companies_nid';
  $handler->display->display_options['arguments']['field_companies_nid']['table'] = 'field_data_field_companies';
  $handler->display->display_options['arguments']['field_companies_nid']['field'] = 'field_companies_nid';
  $handler->display->display_options['arguments']['field_companies_nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_companies_nid']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['field_companies_nid']['default_argument_options']['index'] = '1';
  $handler->display->display_options['arguments']['field_companies_nid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_companies_nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_companies_nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_companies_nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_companies_nid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['field_companies_nid']['not'] = 0;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Subtype (field_term_subtype) */
  $handler->display->display_options['filters']['field_term_subtype_tid']['id'] = 'field_term_subtype_tid';
  $handler->display->display_options['filters']['field_term_subtype_tid']['table'] = 'field_data_field_term_subtype';
  $handler->display->display_options['filters']['field_term_subtype_tid']['field'] = 'field_term_subtype_tid';
  $handler->display->display_options['filters']['field_term_subtype_tid']['value'] = array(
    164 => '164',
    267 => '267',
    163 => '163',
  );
  $handler->display->display_options['filters']['field_term_subtype_tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['field_term_subtype_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_term_subtype_tid']['vocabulary'] = 'subtype';
  $handler->display->display_options['filters']['field_term_subtype_tid']['hierarchy'] = 1;
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

  /* Display: Page - Feature Stories & Case Application */
  $handler = $view->new_display('page', 'Page - Feature Stories & Case Application', 'page_1');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '9';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['links'] = 0;
  $handler->display->display_options['row_options']['comments'] = 0;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
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
  $handler->display->display_options['fields']['field_image']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_image']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_image']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_image']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_image']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_image']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => '190x190',
    'image_link' => 'content',
  );
  $handler->display->display_options['fields']['field_image']['field_api_classes'] = 0;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = '';
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
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['created']['hide_empty'] = 0;
  $handler->display->display_options['fields']['created']['empty_zero'] = 0;
  $handler->display->display_options['fields']['created']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'F j, Y';
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
  $handler->display->display_options['fields']['field_deckhead']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_deckhead']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_deckhead']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_deckhead']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_deckhead']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_deckhead']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_deckhead']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_deckhead']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_deckhead']['field_api_classes'] = 0;
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['external'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['view_node']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['view_node']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['html'] = 0;
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_node']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['view_node']['hide_empty'] = 0;
  $handler->display->display_options['fields']['view_node']['empty_zero'] = 0;
  $handler->display->display_options['fields']['view_node']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['view_node']['text'] = 'Full Article';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Companies (field_companies) */
  $handler->display->display_options['arguments']['field_companies_nid']['id'] = 'field_companies_nid';
  $handler->display->display_options['arguments']['field_companies_nid']['table'] = 'field_data_field_companies';
  $handler->display->display_options['arguments']['field_companies_nid']['field'] = 'field_companies_nid';
  $handler->display->display_options['arguments']['field_companies_nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_companies_nid']['title_enable'] = 1;
  $handler->display->display_options['arguments']['field_companies_nid']['title'] = 'Feature Stories involving %1';
  $handler->display->display_options['arguments']['field_companies_nid']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['field_companies_nid']['default_argument_options']['index'] = '1';
  $handler->display->display_options['arguments']['field_companies_nid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_companies_nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_companies_nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_companies_nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_companies_nid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['field_companies_nid']['not'] = 0;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Subtype (field_term_subtype) */
  $handler->display->display_options['filters']['field_term_subtype_tid']['id'] = 'field_term_subtype_tid';
  $handler->display->display_options['filters']['field_term_subtype_tid']['table'] = 'field_data_field_term_subtype';
  $handler->display->display_options['filters']['field_term_subtype_tid']['field'] = 'field_term_subtype_tid';
  $handler->display->display_options['filters']['field_term_subtype_tid']['value'] = array(
    164 => '164',
    267 => '267',
    163 => '163',
  );
  $handler->display->display_options['filters']['field_term_subtype_tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['field_term_subtype_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_term_subtype_tid']['vocabulary'] = 'subtype';
  $handler->display->display_options['filters']['field_term_subtype_tid']['hierarchy'] = 1;
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
  $handler->display->display_options['path'] = 'company/%/featured';

  /* Display: Block - Products */
  $handler = $view->new_display('block', 'Block - Products', 'block_2');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '8';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['style_options']['fill_single_line'] = 1;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = 0;
  $handler->display->display_options['row_options']['default_field_elements'] = 1;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
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
  $handler->display->display_options['fields']['field_image']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_image']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_image']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_image']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_image']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_image']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => '120x120',
    'image_link' => 'content',
  );
  $handler->display->display_options['fields']['field_image']['field_api_classes'] = 0;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = '';
  $handler->display->display_options['fields']['created']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['created']['alter']['text'] = '[created]';
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
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['created']['hide_empty'] = 0;
  $handler->display->display_options['fields']['created']['empty_zero'] = 0;
  $handler->display->display_options['fields']['created']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'F d, Y';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['title']['alter']['text'] = '<img src="/sites/default/themes/aw960/css/images/img-title.png" >[title]';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Companies (field_companies) */
  $handler->display->display_options['arguments']['field_companies_nid']['id'] = 'field_companies_nid';
  $handler->display->display_options['arguments']['field_companies_nid']['table'] = 'field_data_field_companies';
  $handler->display->display_options['arguments']['field_companies_nid']['field'] = 'field_companies_nid';
  $handler->display->display_options['arguments']['field_companies_nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_companies_nid']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['field_companies_nid']['default_argument_options']['index'] = '1';
  $handler->display->display_options['arguments']['field_companies_nid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_companies_nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_companies_nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_companies_nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_companies_nid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['field_companies_nid']['not'] = 0;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Subtype (field_term_subtype) */
  $handler->display->display_options['filters']['field_term_subtype_tid']['id'] = 'field_term_subtype_tid';
  $handler->display->display_options['filters']['field_term_subtype_tid']['table'] = 'field_data_field_term_subtype';
  $handler->display->display_options['filters']['field_term_subtype_tid']['field'] = 'field_term_subtype_tid';
  $handler->display->display_options['filters']['field_term_subtype_tid']['value'] = array(
    166 => '166',
  );
  $handler->display->display_options['filters']['field_term_subtype_tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['field_term_subtype_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_term_subtype_tid']['vocabulary'] = 'subtype';
  $handler->display->display_options['filters']['field_term_subtype_tid']['hierarchy'] = 1;
  /* Filter criterion: Content: Source Type (field_term_source_type) */
  $handler->display->display_options['filters']['field_term_source_type_tid']['id'] = 'field_term_source_type_tid';
  $handler->display->display_options['filters']['field_term_source_type_tid']['table'] = 'field_data_field_term_source_type';
  $handler->display->display_options['filters']['field_term_source_type_tid']['field'] = 'field_term_source_type_tid';
  $handler->display->display_options['filters']['field_term_source_type_tid']['value'] = array(
    0 => '138',
  );
  $handler->display->display_options['filters']['field_term_source_type_tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['field_term_source_type_tid']['vocabulary'] = 'source_type';

  /* Display: Page - products */
  $handler = $view->new_display('page', 'Page - products', 'page_2');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['links'] = 0;
  $handler->display->display_options['row_options']['comments'] = 0;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Companies (field_companies) */
  $handler->display->display_options['arguments']['field_companies_nid']['id'] = 'field_companies_nid';
  $handler->display->display_options['arguments']['field_companies_nid']['table'] = 'field_data_field_companies';
  $handler->display->display_options['arguments']['field_companies_nid']['field'] = 'field_companies_nid';
  $handler->display->display_options['arguments']['field_companies_nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_companies_nid']['title_enable'] = 1;
  $handler->display->display_options['arguments']['field_companies_nid']['title'] = 'Products involving %1';
  $handler->display->display_options['arguments']['field_companies_nid']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['field_companies_nid']['default_argument_options']['index'] = '1';
  $handler->display->display_options['arguments']['field_companies_nid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_companies_nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_companies_nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_companies_nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_companies_nid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['field_companies_nid']['not'] = 0;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Subtype (field_term_subtype) */
  $handler->display->display_options['filters']['field_term_subtype_tid']['id'] = 'field_term_subtype_tid';
  $handler->display->display_options['filters']['field_term_subtype_tid']['table'] = 'field_data_field_term_subtype';
  $handler->display->display_options['filters']['field_term_subtype_tid']['field'] = 'field_term_subtype_tid';
  $handler->display->display_options['filters']['field_term_subtype_tid']['value'] = array(
    166 => '166',
  );
  $handler->display->display_options['filters']['field_term_subtype_tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['field_term_subtype_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_term_subtype_tid']['vocabulary'] = 'subtype';
  $handler->display->display_options['filters']['field_term_subtype_tid']['hierarchy'] = 1;
  /* Filter criterion: Content: Source Type (field_term_source_type) */
  $handler->display->display_options['filters']['field_term_source_type_tid']['id'] = 'field_term_source_type_tid';
  $handler->display->display_options['filters']['field_term_source_type_tid']['table'] = 'field_data_field_term_source_type';
  $handler->display->display_options['filters']['field_term_source_type_tid']['field'] = 'field_term_source_type_tid';
  $handler->display->display_options['filters']['field_term_source_type_tid']['value'] = array(
    0 => '138',
  );
  $handler->display->display_options['filters']['field_term_source_type_tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['field_term_source_type_tid']['vocabulary'] = 'source_type';
  $handler->display->display_options['path'] = 'company/%/products';

  /* Display: Block - News */
  $handler = $view->new_display('block', 'Block - News', 'block_3');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '8';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'title' => 'title',
    'created' => 'created',
  );
  $handler->display->display_options['row_options']['separator'] = ' | ';
  $handler->display->display_options['row_options']['hide_empty'] = 0;
  $handler->display->display_options['row_options']['default_field_elements'] = 1;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['title']['alter']['text'] = '<img src="/sites/default/themes/aw960/css/images/img-title2.png">[title]';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = '';
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
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['created']['hide_empty'] = 0;
  $handler->display->display_options['fields']['created']['empty_zero'] = 0;
  $handler->display->display_options['fields']['created']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'F d, Y';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Companies (field_companies) */
  $handler->display->display_options['arguments']['field_companies_nid']['id'] = 'field_companies_nid';
  $handler->display->display_options['arguments']['field_companies_nid']['table'] = 'field_data_field_companies';
  $handler->display->display_options['arguments']['field_companies_nid']['field'] = 'field_companies_nid';
  $handler->display->display_options['arguments']['field_companies_nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_companies_nid']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['field_companies_nid']['default_argument_options']['index'] = '1';
  $handler->display->display_options['arguments']['field_companies_nid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_companies_nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_companies_nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_companies_nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_companies_nid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['field_companies_nid']['not'] = 0;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Subtype (field_term_subtype) */
  $handler->display->display_options['filters']['field_term_subtype_tid']['id'] = 'field_term_subtype_tid';
  $handler->display->display_options['filters']['field_term_subtype_tid']['table'] = 'field_data_field_term_subtype';
  $handler->display->display_options['filters']['field_term_subtype_tid']['field'] = 'field_term_subtype_tid';
  $handler->display->display_options['filters']['field_term_subtype_tid']['operator'] = 'not';
  $handler->display->display_options['filters']['field_term_subtype_tid']['value'] = array(
    267 => '267',
    163 => '163',
  );
  $handler->display->display_options['filters']['field_term_subtype_tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['field_term_subtype_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_term_subtype_tid']['vocabulary'] = 'subtype';
  $handler->display->display_options['filters']['field_term_subtype_tid']['hierarchy'] = 1;

  /* Display: Page - News */
  $handler = $view->new_display('page', 'Page - News', 'page_3');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '9';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['links'] = 0;
  $handler->display->display_options['row_options']['comments'] = 0;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Companies (field_companies) */
  $handler->display->display_options['arguments']['field_companies_nid']['id'] = 'field_companies_nid';
  $handler->display->display_options['arguments']['field_companies_nid']['table'] = 'field_data_field_companies';
  $handler->display->display_options['arguments']['field_companies_nid']['field'] = 'field_companies_nid';
  $handler->display->display_options['arguments']['field_companies_nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_companies_nid']['title_enable'] = 1;
  $handler->display->display_options['arguments']['field_companies_nid']['title'] = 'News involving %1';
  $handler->display->display_options['arguments']['field_companies_nid']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['field_companies_nid']['default_argument_options']['index'] = '1';
  $handler->display->display_options['arguments']['field_companies_nid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_companies_nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_companies_nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_companies_nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_companies_nid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['field_companies_nid']['not'] = 0;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Subtype (field_term_subtype) */
  $handler->display->display_options['filters']['field_term_subtype_tid']['id'] = 'field_term_subtype_tid';
  $handler->display->display_options['filters']['field_term_subtype_tid']['table'] = 'field_data_field_term_subtype';
  $handler->display->display_options['filters']['field_term_subtype_tid']['field'] = 'field_term_subtype_tid';
  $handler->display->display_options['filters']['field_term_subtype_tid']['value'] = array(
    162 => '162',
  );
  $handler->display->display_options['filters']['field_term_subtype_tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['field_term_subtype_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_term_subtype_tid']['vocabulary'] = 'subtype';
  $handler->display->display_options['filters']['field_term_subtype_tid']['hierarchy'] = 1;
  /* Filter criterion: Content: Source Type (field_term_source_type) */
  $handler->display->display_options['filters']['field_term_source_type_tid']['id'] = 'field_term_source_type_tid';
  $handler->display->display_options['filters']['field_term_source_type_tid']['table'] = 'field_data_field_term_source_type';
  $handler->display->display_options['filters']['field_term_source_type_tid']['field'] = 'field_term_source_type_tid';
  $handler->display->display_options['filters']['field_term_source_type_tid']['value'] = array(
    0 => '138',
  );
  $handler->display->display_options['filters']['field_term_source_type_tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['field_term_source_type_tid']['vocabulary'] = 'source_type';
  $handler->display->display_options['path'] = 'company/%/news';

  /* Display: Block - count */
  $handler = $view->new_display('block', 'Block - count', 'block_4');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '0';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Subtype (field_term_subtype) */
  $handler->display->display_options['arguments']['field_term_subtype_tid_1']['id'] = 'field_term_subtype_tid_1';
  $handler->display->display_options['arguments']['field_term_subtype_tid_1']['table'] = 'field_data_field_term_subtype';
  $handler->display->display_options['arguments']['field_term_subtype_tid_1']['field'] = 'field_term_subtype_tid';
  $handler->display->display_options['arguments']['field_term_subtype_tid_1']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_term_subtype_tid_1']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_term_subtype_tid_1']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_term_subtype_tid_1']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_term_subtype_tid_1']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_term_subtype_tid_1']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_term_subtype_tid_1']['break_phrase'] = 1;
  $handler->display->display_options['arguments']['field_term_subtype_tid_1']['not'] = 0;
  /* Contextual filter: Content: Companies (field_companies) */
  $handler->display->display_options['arguments']['field_companies_nid']['id'] = 'field_companies_nid';
  $handler->display->display_options['arguments']['field_companies_nid']['table'] = 'field_data_field_companies';
  $handler->display->display_options['arguments']['field_companies_nid']['field'] = 'field_companies_nid';
  $handler->display->display_options['arguments']['field_companies_nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_companies_nid']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['field_companies_nid']['default_argument_options']['index'] = '0';
  $handler->display->display_options['arguments']['field_companies_nid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_companies_nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_companies_nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_companies_nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_companies_nid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['field_companies_nid']['not'] = 0;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Source Type (field_term_source_type) */
  $handler->display->display_options['filters']['field_term_source_type_tid']['id'] = 'field_term_source_type_tid';
  $handler->display->display_options['filters']['field_term_source_type_tid']['table'] = 'field_data_field_term_source_type';
  $handler->display->display_options['filters']['field_term_source_type_tid']['field'] = 'field_term_source_type_tid';
  $handler->display->display_options['filters']['field_term_source_type_tid']['value'] = array(
    0 => '138',
  );
  $handler->display->display_options['filters']['field_term_source_type_tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['field_term_source_type_tid']['vocabulary'] = 'source_type';

  /* Display: Block - Videos */
  $handler = $view->new_display('block', 'Block - Videos', 'block_5');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'field_deckhead' => 'field_deckhead',
    'view_node' => 'view_node',
  );
  $handler->display->display_options['row_options']['hide_empty'] = 0;
  $handler->display->display_options['row_options']['default_field_elements'] = 1;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Viddler ID */
  $handler->display->display_options['fields']['field_viddler_id']['id'] = 'field_viddler_id';
  $handler->display->display_options['fields']['field_viddler_id']['table'] = 'field_data_field_viddler_id';
  $handler->display->display_options['fields']['field_viddler_id']['field'] = 'field_viddler_id';
  $handler->display->display_options['fields']['field_viddler_id']['label'] = '';
  $handler->display->display_options['fields']['field_viddler_id']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_viddler_id']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_viddler_id']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_viddler_id']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_viddler_id']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_viddler_id']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_viddler_id']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_viddler_id']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_viddler_id']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_viddler_id']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_viddler_id']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_viddler_id']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_viddler_id']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_viddler_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_viddler_id']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_viddler_id']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_viddler_id']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_viddler_id']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_viddler_id']['type'] = 'viddler_image';
  $handler->display->display_options['fields']['field_viddler_id']['settings'] = array(
    'image_style' => '190x190-video',
  );
  $handler->display->display_options['fields']['field_viddler_id']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_viddler_id']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_viddler_id']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_viddler_id']['delta_first_last'] = 0;
  $handler->display->display_options['fields']['field_viddler_id']['field_api_classes'] = 0;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = '';
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
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['created']['hide_empty'] = 0;
  $handler->display->display_options['fields']['created']['empty_zero'] = 0;
  $handler->display->display_options['fields']['created']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'F d, Y';
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
  $handler->display->display_options['fields']['field_deckhead']['alter']['max_length'] = '200';
  $handler->display->display_options['fields']['field_deckhead']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_deckhead']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_deckhead']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_deckhead']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_deckhead']['alter']['trim'] = 1;
  $handler->display->display_options['fields']['field_deckhead']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_deckhead']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_deckhead']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_deckhead']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_deckhead']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_deckhead']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_deckhead']['field_api_classes'] = 0;
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['external'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['view_node']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['view_node']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['html'] = 0;
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_node']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['view_node']['hide_empty'] = 0;
  $handler->display->display_options['fields']['view_node']['empty_zero'] = 0;
  $handler->display->display_options['fields']['view_node']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['view_node']['text'] = 'Full Article';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Companies (field_companies) */
  $handler->display->display_options['arguments']['field_companies_nid']['id'] = 'field_companies_nid';
  $handler->display->display_options['arguments']['field_companies_nid']['table'] = 'field_data_field_companies';
  $handler->display->display_options['arguments']['field_companies_nid']['field'] = 'field_companies_nid';
  $handler->display->display_options['arguments']['field_companies_nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_companies_nid']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['field_companies_nid']['default_argument_options']['index'] = '1';
  $handler->display->display_options['arguments']['field_companies_nid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_companies_nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_companies_nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_companies_nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_companies_nid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['field_companies_nid']['not'] = 0;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
    'video' => 'video',
  );

  /* Display: Page - Videos */
  $handler = $view->new_display('page', 'Page - Videos', 'page_4');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '9';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['links'] = 0;
  $handler->display->display_options['row_options']['comments'] = 0;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
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
  $handler->display->display_options['fields']['field_image']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_image']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_image']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_image']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_image']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_image']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => '190x190',
    'image_link' => 'content',
  );
  $handler->display->display_options['fields']['field_image']['field_api_classes'] = 0;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = '';
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
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['created']['hide_empty'] = 0;
  $handler->display->display_options['fields']['created']['empty_zero'] = 0;
  $handler->display->display_options['fields']['created']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'F j, Y';
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
  $handler->display->display_options['fields']['field_deckhead']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_deckhead']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_deckhead']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_deckhead']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_deckhead']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_deckhead']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_deckhead']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_deckhead']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_deckhead']['field_api_classes'] = 0;
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['external'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['view_node']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['view_node']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['html'] = 0;
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_node']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['view_node']['hide_empty'] = 0;
  $handler->display->display_options['fields']['view_node']['empty_zero'] = 0;
  $handler->display->display_options['fields']['view_node']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['view_node']['text'] = 'Full Article';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Companies (field_companies) */
  $handler->display->display_options['arguments']['field_companies_nid']['id'] = 'field_companies_nid';
  $handler->display->display_options['arguments']['field_companies_nid']['table'] = 'field_data_field_companies';
  $handler->display->display_options['arguments']['field_companies_nid']['field'] = 'field_companies_nid';
  $handler->display->display_options['arguments']['field_companies_nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_companies_nid']['title_enable'] = 1;
  $handler->display->display_options['arguments']['field_companies_nid']['title'] = 'Videos from %1';
  $handler->display->display_options['arguments']['field_companies_nid']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['field_companies_nid']['default_argument_options']['index'] = '1';
  $handler->display->display_options['arguments']['field_companies_nid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_companies_nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_companies_nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_companies_nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_companies_nid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['field_companies_nid']['not'] = 0;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
    'video' => 'video',
  );
  $handler->display->display_options['path'] = 'company/%/videos';
  $export['company'] = $view;

  return $export;
}
