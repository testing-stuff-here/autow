<?php
/**
 * @file
 * image_rotator_responsive.views_default.inc
 */

/**
 * Implementation of hook_views_default_views().
 */
function image_rotator_responsive_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'rotator_responsive';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Image Rotator Responsive';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Responsive View';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
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
    'image_style' => 'image_rotator',
    'image_link' => '',
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
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['title']['link_to_node'] = 0;
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
  $handler->display->display_options['fields']['field_deckhead']['alter']['max_length'] = '170';
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
  $handler->display->display_options['fields']['field_deckhead']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_deckhead']['field_api_classes'] = 0;
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['path']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['path']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['path']['alter']['external'] = 0;
  $handler->display->display_options['fields']['path']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['path']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['path']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['path']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['path']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['path']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['path']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['path']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['path']['alter']['html'] = 0;
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['path']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['path']['hide_empty'] = 0;
  $handler->display->display_options['fields']['path']['empty_zero'] = 0;
  $handler->display->display_options['fields']['path']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['path']['absolute'] = 0;
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
  /* Filter criterion: Content: Image (field_image:fid) */
  $handler->display->display_options['filters']['field_image_fid']['id'] = 'field_image_fid';
  $handler->display->display_options['filters']['field_image_fid']['table'] = 'field_data_field_image';
  $handler->display->display_options['filters']['field_image_fid']['field'] = 'field_image_fid';
  $handler->display->display_options['filters']['field_image_fid']['operator'] = 'not empty';
  $handler->display->display_options['filters']['field_image_fid']['group'] = 1;
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
    166 => '166',
    168 => '168',
  );
  $handler->display->display_options['filters']['field_term_subtype_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_term_subtype_tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['field_term_subtype_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_term_subtype_tid']['vocabulary'] = 'subtype';
  $handler->display->display_options['filters']['field_term_subtype_tid']['hierarchy'] = 1;
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
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'article' => 'article',
    'blog' => 'blog',
    'podcast' => 'podcast',
    'video' => 'video',
    'whitepaper' => 'whitepaper',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');

  /* Display: Responsive Content */
  $handler = $view->new_display('block', 'Responsive Content', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['links'] = 1;
  $handler->display->display_options['row_options']['comments'] = 0;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $export['rotator_responsive'] = $view;

  return $export;
}
