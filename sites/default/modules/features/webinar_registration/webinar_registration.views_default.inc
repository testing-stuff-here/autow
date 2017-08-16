<?php
/**
 * @file
 * webinar_registration.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function webinar_registration_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'webinars';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Webinars';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Webinars';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '4';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Content: Taxonomy terms on node */
  $handler->display->display_options['relationships']['term_node_tid']['id'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['table'] = 'node';
  $handler->display->display_options['relationships']['term_node_tid']['field'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['vocabularies'] = array(
    'technologies' => 'technologies',
    'app_platforms_os' => 0,
    'automation_strategies' => 0,
    'blog_beat' => 0,
    'column_type_' => 0,
    'company_type' => 0,
    'coverage_type' => 0,
    'download_subtype' => 0,
    'industries' => 0,
    'industry_type' => 0,
    'leadership_session' => 0,
    'source_type' => 0,
    'sponsors' => 0,
    'subtype' => 0,
    'tags' => 0,
    'topics' => 0,
  );
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => '110x85',
    'image_link' => 'content',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '<span class="bullet">»</span> [title]';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Deckhead */
  $handler->display->display_options['fields']['field_deckhead']['id'] = 'field_deckhead';
  $handler->display->display_options['fields']['field_deckhead']['table'] = 'field_data_field_deckhead';
  $handler->display->display_options['fields']['field_deckhead']['field'] = 'field_deckhead';
  $handler->display->display_options['fields']['field_deckhead']['label'] = '';
  $handler->display->display_options['fields']['field_deckhead']['element_label_colon'] = FALSE;
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
    'webinar' => 'webinar',
    'webinar_registration' => 'webinar_registration',
  );
  /* Filter criterion: Content: GoToWebinar webinar date -  start date (field_gotowebinar_webinar_date) */
  $handler->display->display_options['filters']['field_gotowebinar_webinar_date_value']['id'] = 'field_gotowebinar_webinar_date_value';
  $handler->display->display_options['filters']['field_gotowebinar_webinar_date_value']['table'] = 'field_data_field_gotowebinar_webinar_date';
  $handler->display->display_options['filters']['field_gotowebinar_webinar_date_value']['field'] = 'field_gotowebinar_webinar_date_value';
  $handler->display->display_options['filters']['field_gotowebinar_webinar_date_value']['operator'] = '>';
  $handler->display->display_options['filters']['field_gotowebinar_webinar_date_value']['default_date'] = 'now';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_text'] = FALSE;
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
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
    'webinar' => 'webinar',
    'webinar_registration' => 'webinar_registration',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '15';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['links'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
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
    'webinar' => 'webinar',
    'webinar_registration' => 'webinar_registration',
  );
  $handler->display->display_options['path'] = 'webinars';

  /* Display: Upcoming webinars */
  $handler = $view->new_display('block', 'Upcoming webinars', 'upcoming_webinars');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Upcoming webinars';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '6';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'col-lg-4 col-md-6 col-sm-6 col-xs-12';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: All taxonomy terms */
  $handler->display->display_options['fields']['term_node_tid']['id'] = 'term_node_tid';
  $handler->display->display_options['fields']['term_node_tid']['table'] = 'node';
  $handler->display->display_options['fields']['term_node_tid']['field'] = 'term_node_tid';
  $handler->display->display_options['fields']['term_node_tid']['label'] = '';
  $handler->display->display_options['fields']['term_node_tid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['term_node_tid']['link_to_taxonomy'] = FALSE;
  $handler->display->display_options['fields']['term_node_tid']['limit'] = TRUE;
  $handler->display->display_options['fields']['term_node_tid']['vocabularies'] = array(
    'technologies' => 'technologies',
    'app_platforms_os' => 0,
    'automation_strategies' => 0,
    'blog_beat' => 0,
    'column_type_' => 0,
    'company_type' => 0,
    'coverage_type' => 0,
    'download_subtype' => 0,
    'industries' => 0,
    'industry_type' => 0,
    'leadership_session' => 0,
    'source_type' => 0,
    'sponsors' => 0,
    'subtype' => 0,
    'tags' => 0,
    'topics' => 0,
  );
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => '320x215',
    'image_link' => 'content',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '<span class="bullet">»</span> [title]';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['alter']['max_length'] = '150';
  $handler->display->display_options['fields']['body']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['html'] = TRUE;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_plain';
  /* Field: Content: GoToWebinar webinar date */
  $handler->display->display_options['fields']['field_gotowebinar_webinar_date']['id'] = 'field_gotowebinar_webinar_date';
  $handler->display->display_options['fields']['field_gotowebinar_webinar_date']['table'] = 'field_data_field_gotowebinar_webinar_date';
  $handler->display->display_options['fields']['field_gotowebinar_webinar_date']['field'] = 'field_gotowebinar_webinar_date';
  $handler->display->display_options['fields']['field_gotowebinar_webinar_date']['label'] = 'Date';
  $handler->display->display_options['fields']['field_gotowebinar_webinar_date']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
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
    'webinar_registration' => 'webinar_registration',
  );
  /* Filter criterion: Content: GoToWebinar webinar date -  start date (field_gotowebinar_webinar_date) */
  $handler->display->display_options['filters']['field_gotowebinar_webinar_date_value']['id'] = 'field_gotowebinar_webinar_date_value';
  $handler->display->display_options['filters']['field_gotowebinar_webinar_date_value']['table'] = 'field_data_field_gotowebinar_webinar_date';
  $handler->display->display_options['filters']['field_gotowebinar_webinar_date_value']['field'] = 'field_gotowebinar_webinar_date_value';
  $handler->display->display_options['filters']['field_gotowebinar_webinar_date_value']['operator'] = '>';
  $handler->display->display_options['filters']['field_gotowebinar_webinar_date_value']['default_date'] = 'now';

  /* Display: On Demand Webinars */
  $handler = $view->new_display('block', 'On Demand Webinars', 'on_demand_webinars');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'On Demand Webinars';
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['expose_sort_order'] = FALSE;
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'general' => array(
      'input_required' => 0,
      'text_input_required' => array(
        'text_input_required' => array(
          'value' => 'Select any filter and click on Apply to see results',
          'format' => 'full_html',
        ),
      ),
      'allow_secondary' => 0,
      'secondary_label' => 'Advanced options',
      'secondary_collapse_override' => '0',
    ),
    'tid' => array(
      'bef_format' => 'bef_links',
      'more_options' => array(
        'bef_select_all_none' => FALSE,
        'bef_collapsible' => 0,
        'autosubmit' => 0,
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
            1 => 'vocabulary',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
    'tid_1' => array(
      'bef_format' => 'bef_links',
      'more_options' => array(
        'bef_select_all_none' => FALSE,
        'bef_collapsible' => 0,
        'autosubmit' => 0,
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
            1 => 'vocabulary',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
  );
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '6';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'col-lg-4 col-md-6 col-sm-6 col-xs-12';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Taxonomy terms on node */
  $handler->display->display_options['relationships']['term_node_tid']['id'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['table'] = 'node';
  $handler->display->display_options['relationships']['term_node_tid']['field'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['vocabularies'] = array(
    'topics' => 'topics',
    'app_platforms_os' => 0,
    'automation_strategies' => 0,
    'blog_beat' => 0,
    'column_type_' => 0,
    'company_type' => 0,
    'coverage_type' => 0,
    'dfp_ad_categories' => 0,
    'download_subtype' => 0,
    'industries' => 0,
    'industry_type' => 0,
    'leadership_session' => 0,
    'source_type' => 0,
    'sponsors' => 0,
    'subtype' => 0,
    'tags' => 0,
    'technologies' => 0,
  );
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: All taxonomy terms */
  $handler->display->display_options['fields']['term_node_tid']['id'] = 'term_node_tid';
  $handler->display->display_options['fields']['term_node_tid']['table'] = 'node';
  $handler->display->display_options['fields']['term_node_tid']['field'] = 'term_node_tid';
  $handler->display->display_options['fields']['term_node_tid']['label'] = '';
  $handler->display->display_options['fields']['term_node_tid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['term_node_tid']['link_to_taxonomy'] = FALSE;
  $handler->display->display_options['fields']['term_node_tid']['limit'] = TRUE;
  $handler->display->display_options['fields']['term_node_tid']['vocabularies'] = array(
    'technologies' => 'technologies',
    'app_platforms_os' => 0,
    'automation_strategies' => 0,
    'blog_beat' => 0,
    'column_type_' => 0,
    'company_type' => 0,
    'coverage_type' => 0,
    'download_subtype' => 0,
    'industries' => 0,
    'industry_type' => 0,
    'leadership_session' => 0,
    'source_type' => 0,
    'sponsors' => 0,
    'subtype' => 0,
    'tags' => 0,
    'topics' => 0,
  );
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => '320x215',
    'image_link' => 'content',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '<span class="bullet">»</span> [title]';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['alter']['max_length'] = '150';
  $handler->display->display_options['fields']['body']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['html'] = TRUE;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_plain';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '600',
  );
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
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
    'webinar_registration' => 'webinar_registration',
  );
  /* Filter criterion: Content: GoToWebinar webinar date -  start date (field_gotowebinar_webinar_date) */
  $handler->display->display_options['filters']['field_gotowebinar_webinar_date_value']['id'] = 'field_gotowebinar_webinar_date_value';
  $handler->display->display_options['filters']['field_gotowebinar_webinar_date_value']['table'] = 'field_data_field_gotowebinar_webinar_date';
  $handler->display->display_options['filters']['field_gotowebinar_webinar_date_value']['field'] = 'field_gotowebinar_webinar_date_value';
  $handler->display->display_options['filters']['field_gotowebinar_webinar_date_value']['operator'] = '<';
  $handler->display->display_options['filters']['field_gotowebinar_webinar_date_value']['default_date'] = 'now';
  /* Filter criterion: Content: Has taxonomy term */
  $handler->display->display_options['filters']['tid']['id'] = 'tid';
  $handler->display->display_options['filters']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['filters']['tid']['field'] = 'tid';
  $handler->display->display_options['filters']['tid']['value'] = array(
    2699 => '2699',
    2705 => '2705',
    2709 => '2709',
    2718 => '2718',
    2717 => '2717',
    2720 => '2720',
  );
  $handler->display->display_options['filters']['tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['tid']['expose']['operator_id'] = 'tid_op';
  $handler->display->display_options['filters']['tid']['expose']['operator'] = 'tid_op';
  $handler->display->display_options['filters']['tid']['expose']['identifier'] = 'tid';
  $handler->display->display_options['filters']['tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    14 => 0,
    13 => 0,
  );
  $handler->display->display_options['filters']['tid']['expose']['reduce'] = TRUE;
  $handler->display->display_options['filters']['tid']['group_info']['label'] = 'Has taxonomy term';
  $handler->display->display_options['filters']['tid']['group_info']['identifier'] = 'tid';
  $handler->display->display_options['filters']['tid']['group_info']['default_group'] = '1';
  $handler->display->display_options['filters']['tid']['group_info']['group_items'] = array(
    1 => array(
      'title' => 'Test',
      'operator' => 'or',
      'value' => array(
        2685 => '2685',
        2686 => '2686',
        2727 => '2727',
        2687 => '2687',
        2688 => '2688',
        2755 => '2755',
        2728 => '2728',
        2729 => '2729',
        2689 => '2689',
        2690 => '2690',
        2691 => '2691',
        2692 => '2692',
        2693 => '2693',
        3366 => '3366',
        2694 => '2694',
        2695 => '2695',
        2696 => '2696',
        2756 => '2756',
        2697 => '2697',
        2730 => '2730',
        2733 => '2733',
        2731 => '2731',
        2732 => '2732',
        2734 => '2734',
        2735 => '2735',
        2699 => '2699',
        2700 => '2700',
        2698 => '2698',
        2701 => '2701',
        2702 => '2702',
        2703 => '2703',
        2704 => '2704',
        2705 => '2705',
        3368 => '3368',
        2706 => '2706',
        2736 => '2736',
        2707 => '2707',
        2708 => '2708',
        2709 => '2709',
        2710 => '2710',
        2711 => '2711',
        2712 => '2712',
        2713 => '2713',
        2737 => '2737',
        2714 => '2714',
        2715 => '2715',
        2716 => '2716',
        2718 => '2718',
        2719 => '2719',
        2717 => '2717',
        2720 => '2720',
        2721 => '2721',
        2722 => '2722',
        2738 => '2738',
        2739 => '2739',
        2723 => '2723',
        2724 => '2724',
        2725 => '2725',
        2740 => '2740',
        2726 => '2726',
        2754 => '2754',
        3367 => '3367',
        2741 => '2741',
      ),
    ),
    2 => array(
      'title' => 'test2',
      'operator' => 'or',
      'value' => array(
        2685 => '2685',
        2686 => '2686',
        2727 => '2727',
        2687 => '2687',
        2688 => '2688',
        2755 => '2755',
        2728 => '2728',
        2729 => '2729',
        2689 => '2689',
        2690 => '2690',
        2691 => '2691',
        2692 => '2692',
        2693 => '2693',
        3366 => '3366',
        2694 => '2694',
        2695 => '2695',
        2696 => '2696',
        2756 => '2756',
        2697 => '2697',
        2730 => '2730',
        2733 => '2733',
        2731 => '2731',
        2732 => '2732',
        2734 => '2734',
        2735 => '2735',
        2699 => '2699',
        2700 => '2700',
        2698 => '2698',
        2701 => '2701',
        2702 => '2702',
        2703 => '2703',
        2704 => '2704',
        2705 => '2705',
        3368 => '3368',
        2706 => '2706',
        2736 => '2736',
        2707 => '2707',
        2708 => '2708',
        2709 => '2709',
        2710 => '2710',
        2711 => '2711',
        2712 => '2712',
        2713 => '2713',
        2737 => '2737',
        2714 => '2714',
        2715 => '2715',
        2716 => '2716',
        2718 => '2718',
        2719 => '2719',
        2717 => '2717',
        2720 => '2720',
        2721 => '2721',
        2722 => '2722',
        2738 => '2738',
        2739 => '2739',
        2723 => '2723',
        2724 => '2724',
        2725 => '2725',
        2740 => '2740',
        2726 => '2726',
        2754 => '2754',
        3367 => '3367',
        2741 => '2741',
      ),
    ),
    3 => array(
      'title' => 'test3',
      'operator' => 'or',
      'value' => array(
        2685 => '2685',
        2686 => '2686',
        2727 => '2727',
        2687 => '2687',
        2688 => '2688',
        2755 => '2755',
        2728 => '2728',
        2729 => '2729',
        2689 => '2689',
        2690 => '2690',
        2691 => '2691',
        2692 => '2692',
        2693 => '2693',
        3366 => '3366',
        2694 => '2694',
        2695 => '2695',
        2696 => '2696',
        2756 => '2756',
        2697 => '2697',
        2730 => '2730',
        2733 => '2733',
        2731 => '2731',
        2732 => '2732',
        2734 => '2734',
        2735 => '2735',
        2699 => '2699',
        2700 => '2700',
        2698 => '2698',
        2701 => '2701',
        2702 => '2702',
        2703 => '2703',
        2704 => '2704',
        2705 => '2705',
        3368 => '3368',
        2706 => '2706',
        2736 => '2736',
        2707 => '2707',
        2708 => '2708',
        2709 => '2709',
        2710 => '2710',
        2711 => '2711',
        2712 => '2712',
        2713 => '2713',
        2737 => '2737',
        2714 => '2714',
        2715 => '2715',
        2716 => '2716',
        2718 => '2718',
        2719 => '2719',
        2717 => '2717',
        2720 => '2720',
        2721 => '2721',
        2722 => '2722',
        2738 => '2738',
        2739 => '2739',
        2723 => '2723',
        2724 => '2724',
        2725 => '2725',
        2740 => '2740',
        2726 => '2726',
        2754 => '2754',
        3367 => '3367',
        2741 => '2741',
      ),
    ),
  );
  $handler->display->display_options['filters']['tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['tid']['type'] = 'select';
  $handler->display->display_options['filters']['tid']['vocabulary'] = 'technologies';
  /* Filter criterion: Content: Has taxonomy term */
  $handler->display->display_options['filters']['tid_1']['id'] = 'tid_1';
  $handler->display->display_options['filters']['tid_1']['table'] = 'taxonomy_index';
  $handler->display->display_options['filters']['tid_1']['field'] = 'tid';
  $handler->display->display_options['filters']['tid_1']['value'] = array(
    2742 => '2742',
    2743 => '2743',
  );
  $handler->display->display_options['filters']['tid_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['tid_1']['expose']['operator_id'] = 'tid_1_op';
  $handler->display->display_options['filters']['tid_1']['expose']['operator'] = 'tid_1_op';
  $handler->display->display_options['filters']['tid_1']['expose']['identifier'] = 'tid_1';
  $handler->display->display_options['filters']['tid_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    14 => 0,
    13 => 0,
  );
  $handler->display->display_options['filters']['tid_1']['expose']['reduce'] = TRUE;
  $handler->display->display_options['filters']['tid_1']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['tid_1']['type'] = 'select';
  $handler->display->display_options['filters']['tid_1']['vocabulary'] = 'topics';
  $export['webinars'] = $view;

  return $export;
}
