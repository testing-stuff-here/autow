<?php

/**
 * @file
 * template.php
 */

/**
 * Comment at production @TODO
 */
/**
 * Implements hook_init().
 */
function awbs_init() {
  global $theme_key;
  if (strpos($theme_key, 'bootstrap') === FALSE) {
    include_once(drupal_get_path('theme', 'bootstrap') . '/theme/process.inc');
  }
}

/**
 * takes field_allterms and returns an array of themed links to the 3 most
 * specific terms
 */
function awbs_parse_allterms($allterms, $limit = 0, $exclude_vids = array()) {
  $ret = array();

  // fill $min_children with an array of the terms with fewest children (most specific) in each taxonomy group
  $min_children = array();
  foreach ($allterms as $id => $term) {
    if (in_array($term['vid'], $exclude_vids)) {
      continue;
    }
    $this_children = count(taxonomy_get_children($term['tid'], $term['vid']));
    if (!array_key_exists($term['group'], $min_children) || $this_children < $min_children[$term['group']]['count']) {
      $min_children[$term['group']] = array(
        'count' => $this_children,
        'id' => $id,
      );
    }
  }

  // fill $ret with links to first three terms
  foreach ($min_children as $group) {
    $term = taxonomy_term_load($allterms[$group['id']]['tid']);
    $ret[] = l($term->name, "taxonomy/term/{$term->tid}");
  }

  if ($limit > 0) {
    return array_slice($ret, 0, $limit);
  }
  else {
    return $ret;
  }
}

/**
 * Implements theme_preprocess_html
 */
function awbs_preprocess_html(&$variables, $hook) {
  $node = menu_get_object();
  if ($node && ($node->type == "article" || $node->type == "blog") && (!empty($node->field_companies))) {
    drupal_add_js('/' . drupal_get_path('theme', 'awbs') . '/dist/js/aw.adwert.js', array(
      'type' => 'external',
      'scope' => 'footer',
    ));
    drupal_add_js(array('AdvertFix' => array('isArticle' => TRUE)), 'setting');
  }
  if (drupal_is_front_page() === TRUE) {
    drupal_add_js('/' . drupal_get_path('theme', 'awbs') . '/dist/js/aw.adwert.js', array(
      'type' => 'external',
      'scope' => 'footer',
    ));
    drupal_add_js(array('AdvertFix' => array('isFront' => TRUE)), 'setting');
  }
  drupal_add_js('/' . drupal_get_path('theme', 'awbs') . '/dist/js/awbs.min.js', array(
    'type' => 'external',
    'scope' => 'footer',
  ));
  if ((arg(0) == 'node') && (arg(1) == 13046)) { // if this is the subscription node
    drupal_add_js('/' . drupal_get_path('theme', 'awbs') . '/dist/js/awbs.subscriptions.min.js', array(
      'type' => 'external',
      'scope' => 'footer',
    ));
  }

  // add Silverpop web-tracking tag to header
  $engage_meta = array(
    '#tag' => 'meta',
    '#attributes' => array(
      'name' => 'com.silverpop.brandeddomains',
      'content' => SP_TRACKING_DOMAINS,
    ),
  );
  drupal_add_html_head($engage_meta, 'engage_meta');

  drupal_add_js('/' . drupal_get_path('theme', 'awbs') . '/js/stitial.js', array(
  'type' => 'external',
  'scope' => 'footer',
  'every_page' => TRUE,
  ));

  // Now add silverpop external javascript file
  drupal_add_js(SP_COOKIE_SSL, array('type' => 'external', 'every_page' => TRUE, 'weight' => 200));
}

/**
 * Function for creating an http link
 *
 * @param $link
 *  The link that you want to verify if it has the correct prefix
 * @param $append
 *  The string you want to append
 * @param @allowed
 *  Allowed prefixes
 *
 * @return
 *  returns the appended link
 */
function aw960_httpify($link, $append = 'http://', $allowed = array(
  'http://',
  'https://',
)) {
  $link = trim($link);
  $found = FALSE;
  foreach ($allowed as $protocol) {
    if (strpos($link, $protocol) !== FALSE) {
      $found = TRUE;
    }
  }

  if ($found) {
    return $link;
  }

  return $append . $link;
}

function awbs_page_alter(&$page) {
  $node = menu_get_object();


  if (drupal_is_front_page()) {
    if (!isset($_GET['page'])) { // page 0
      $block = smg_global_block_render('views', '360_gallery-block_2');
    }
    else { // page 1+
      $block = smg_global_block_render('views', '360_gallery-block_1');
    }

    // ** this removes a couple of classes from the <section> tag that were causing weird overlay issues **
    $block = str_replace('<section id="block-views-360-gallery-block-1" class="block block-views contextual-links-region block-views-360_gallery-block_1 clearfix">', '<section id="block-views-360-gallery-block-2">', $block);
    $block = str_replace('<section id="block-views-360-gallery-block-1" class="block block-views block-views-360_gallery-block_1 clearfix">', '<section id="block-views-360-gallery-block-2">', $block);
    $block = str_replace('<section id="block-views-360-gallery-block-2" class="block block-views contextual-links-region clearfix">', '<section id="block-views-360-gallery-block-2">', $block);
    $block = str_replace('<section id="block-views-360-gallery-block-2" class="block block-views clearfix">', '<section id="block-views-360-gallery-block-2">', $block);

    $search = '<div class="views-row views-row-6 views-row-even">';
    $page['content']['system_main']['main']['#markup'] = str_replace($search, $block . $search, $page['content']['system_main']['main']['#markup']);
  }

  if ((isset($node)) && ($node->type == 'video')) {
    $video_block = smg_global_block_render('block', 67);
    $video_block = str_replace('hidden imuA', '', $video_block);
  }


}


/**
 * Implements theme_preprocess_page
 */
function awbs_preprocess_page(&$variables) {
  $variables['primary_nav'] = menu_tree(variable_get('menu_main_links_source', 'AW Bootstrap Navigation'));
  $search_html = render(module_invoke('search', 'block_view', 'search'));
  $search_html = str_replace('value="Search ..."', '', $search_html);
  $mobile_search_html = $search_html;
  $mobile_search_html = str_replace('<span class="input-group-btn"><button type="submit" class="btn btn-default">Search</button></span>', '', $mobile_search_html);
  $mobile_search_html = str_replace('input-group', 'input-group col-xs-10 col-xs-offset-1', $mobile_search_html);
  $search_html = str_replace('>Search</button>', '><i class="fa fa-fw fa-search"></i></button>', $search_html);
  $search_html = str_replace('<div class="input-group', '<div class="input-group col-xs-8 col-xs-offset-2', $search_html);
  $search_html = str_replace('btn btn-default', 'btn btn-lg awbs-btn', $search_html);
  $search_html = str_replace('class="form-control form-text"', 'class="form-control form-text awbs-input"', $search_html);
  $webinar_links = _awbs_preprocess_webinar_links();

  $deep_dive_links = _awbs_preprocess_deep_dives_links();

  $variables['search_block'] = $search_html;
  $variables['mobile_search_block'] = $mobile_search_html;
  $variables['webinar_links'] = $webinar_links;
  $variables['deep_dive_links'] = $deep_dive_links;

  if (variable_get('enable_expo_countdown')) {
    $variables['enable_expo_countdown'] = '<expo-countdown site="aw" ng-show="countryInclude"></expo-countdown>';
  }

  // @via: https://www.drupal.org/node/950434#comment-7227420
  $nid = arg(1);
  if (arg(0) == 'node' && is_numeric($nid)) {
    if (isset($variables['page']['content']['system_main']['nodes'][$nid])) {
      // make variables for the page available outside the page.tpl.php file
      $variables['node_content'] =& $variables['page']['content']['system_main']['nodes'][$nid];

      // switch to a special template for feature articles @TODO add after a certain date (may 21?)
      $node = $variables['node'];
      if ($node->field_term_subtype['und'][0]['tid'] == 163) {
        $variables['theme_hook_suggestions'][] = "page__node__featured_article";
      }


      $variables['theme_hook_suggestions'][] = "page__node__" . $node->type;

      // CSIA guest blogging consideration
      if (isset($node) && $node->type == 'blog') {
        $variables['csia'] = FALSE;
        if ($node->uid == '3197' || $node->uid == '3198') {
          $variables['csia'] = TRUE;
        }
      }

      // inject ShareThis script into our pages
      if ($node && $node->status == TRUE) {
        // add Share This Scripts
        $share_this_script = '<script type="text/javascript">var switchTo5x=true;</script><script type="text/javascript" src="https://ws.sharethis.com/button/buttons.js"></script><script type="text/javascript">stLight.options({publisher:\'8e3ea5bc-dfce-4ddf-8d7b-f1ddfb9b57ab\',onhover:false,doNotCopy:true});</script>';
        $element = array(
          '#type' => 'markup',
          '#markup' => $share_this_script,
        );

        drupal_add_html_head($element, 'share-this');
      }
    }
  }


  if (isset($variables['node'])) {
    /* Week in review */
    $node = $variables['node'];
    if ($node->type == 'week_in_review') {
      $variables['related_links'] = FALSE;
      $view = views_get_view_result('related_links', 'block', array($node->nid));
      $sponsor_links = $view[0]->field_field_sponsor_links;
      if (!empty($sponsor_links)) {
        $variables['related_links'] = TRUE;
      }
    }
  }
}

/**
 * returns a rendered block
 *
 * @param $module : the name of the module that defines the block
 * @param $delta  : the block delta
 * @return string containing rendered block
 */
function awbs_render_block($module, $delta) {
  $block = block_load($module, $delta);
  $block_content = _block_render_blocks(array($block));
  $build = _block_get_renderable_array($block_content);
  return drupal_render($build);
}


/**
 * Implements theme_preprocess_node().
 */
function awbs_preprocess_node(&$vars) {
  $node = $vars['node'];
  $type = $vars['type'];

  if ($vars['view_mode'] == 'teaser') {
    $vars['theme_hook_suggestions'][] = 'node__' . $vars['node']->type . '__teaser';
    $vars['theme_hook_suggestions'][] = 'node__' . $vars['node']->nid . '__teaser';
  }

  $vars['tabs'] = menu_local_tabs();

  if (!empty($node)) {
    if ((isset($node->field_term_subtype)) && ($node->field_term_subtype['und'][0]['tid'] == 163)) {
      $vars['theme_hook_suggestions'][] = "node__featured_article";
    }
  }

  // CSIA guest blogging consideration
  if (isset($node) && $node->type == 'blog') {
    $vars['csia'] = FALSE;
    if ($node->uid == '3197' || $node->uid == '3198') {
      $vars['csia'] = TRUE;
    }
  }

  if (
    isset($node) &&
    $node->type == 'article' &&
    isset($node->field_article_length['und']) &&
    $node->field_article_length['und'][0]['value'] == 'long'
  ) {
    print '<div class="hidden inline-lia-datacard">' . drupal_render(_block_get_renderable_array(_block_render_blocks(array(block_load('leadership', 'leadership_data_card_block'))))) . '</div>';
  }

  // #23 Leadership Online Profile
  if ($vars['type'] == 'leadership_online_profile') {
    _awbs_preprocess_leadership_online_profile($vars);
  }

  if ($vars['type'] == 'company') {
    // Add LIA online profile to company node if in current session
    $current_session = FALSE;
    foreach ($vars['field_ld_session'] as $value) {
      if ($value['tid'] == variable_get('leadership_session_term')) {
        $current_session = TRUE;
      }
    }

    if ($current_session) {
      $site_id = variable_get('smg_global_site');
      // If in current session get the corresponding data card
      $dc_nid = leadership_get_corresponding_nid($vars['nid'], 'leadership_data_card', $site_id);
      $data_card_node = node_load($dc_nid);
      if ($data_card_node->status == 1) {
        /** @var Object $data_card_wrapper */
        $data_card_wrapper = entity_metadata_wrapper('node', $data_card_node);

        drupal_add_css(drupal_get_path('theme', 'aw960') . '/css/leadership-company-profile.css');

        $vars['current_session'] = TRUE;
        $vars['is_published_print_profile'] = FALSE;

        // Contact Photo
        if (!empty($data_card_node->field_ld_contact_photo)) {
          $image = $data_card_wrapper->field_ld_contact_photo->value();
          $vars['data_card_contact_image'] = image_style_url('leadership_data_card_exec', $image['uri']);
        }

        // Contact Name/Title
        if (!empty($data_card_node->field_ld_contact)) {
          $vars['data_card_contact_info'] = '<span class="node--company-contact-info">';
          $vars['data_card_contact_info'] .= '<span class="node--company-contact-name">' . $data_card_wrapper->field_ld_contact->value() . '</span>';
          if (!empty($data_card_node->field_ld_contact_title)) {
            $vars['data_card_contact_info'] .= '<strong>,</strong><br />';
            $vars['data_card_contact_info'] .= '<div class="node--company-contact-title">' . $data_card_wrapper->field_ld_contact_title->value() . '</div>';
          }
          $vars['data_card_contact_info'] .= '</span>';
        }

        // Contact email
        $print_prof_nid = leadership_get_corresponding_nid($vars['nid'], 'leadership_print_profile', $site_id);
        $print_prof_node = node_load($print_prof_nid);
        /** @var Object $print_prof_wrapper */
        $print_prof_wrapper = entity_metadata_wrapper('node', $print_prof_node);
        if (!empty($print_prof_node->field_ld_email)) {
          $vars['data_card_email'] = $print_prof_wrapper->field_ld_email->value();
        }

        // City / State
        if (!empty($print_prof_node->field_ld_address_city)) {
          $vars['print_location'] = $print_prof_wrapper->field_ld_address_city->value();
          if (!empty($print_prof_node->field_ld_state)) {
            $vars['print_location'] .= ', ' . $print_prof_wrapper->field_ld_state->value();
          }
        }

        // Website
        if (!empty($print_prof_node->field_ld_website)) {
          $vars['print_website_url'] = $print_prof_wrapper->field_ld_website->value();
        }

        // Logo
        if (!empty($data_card_node->field_ld_logo)) {
          $logo = $data_card_wrapper->field_ld_logo->value();
          $vars['data_card_company_logo'] = image_style_url('leadership_data_card_logo', $logo['uri']);
        }

        // Product Summary
        if (!empty($data_card_node->body)) {
          $datacard_body_field = $data_card_wrapper->body->value();
          $vars['data_card_product_summary'] = $datacard_body_field["value"];
        }

        // Teaser
        if (!empty($data_card_node->field_ld_teaser)) {
          $vars['data_card_teaser'] = $data_card_wrapper->field_ld_teaser->value();
        }

        // Get taxonomy terms from both Technology and Topics vocab.
        $categories = array();
        $taxonomy_field_names = array(
          'field_ld_categories_technologies',
          'field_ld_categories_topics',
        );
        foreach ($taxonomy_field_names as $name) {
          if (isset($print_prof_node->{$name}['und'][0])) {
            foreach ($print_prof_node->{$name}['und'] as $taxonomy) {
              $term = taxonomy_term_load($taxonomy['tid']);
              $categories[] = $term->name;
            }
          }
        }
        sort($categories);
        $vars['categories'] = implode(", ", $categories);

        // Add the online profile
        $online_prof_nid = leadership_get_corresponding_nid($vars['nid'], 'leadership_online_profile', $site_id);
        $online_prof_node = node_load($online_prof_nid);
        /** @var Object $online_prof_wrapper */
        $online_prof_wrapper = entity_metadata_wrapper('node', $online_prof_node);
        if ($online_prof_node->status == 1) {

          $vars['is_published_print_profile'] = TRUE;
          $vars['online_profile_node'] = $online_prof_node;
          $theme_path = '/' . drupal_get_path('theme', 'aw960');
          $css_path = $theme_path . '/css/images/';
          $company_name = $vars['title'];

          if (!empty($online_prof_node->field_ld_facebook)) {
            $facebook_link = $online_prof_wrapper->field_ld_facebook->value();
            $facebook_logo = $css_path . 'FB-f-Logo__blue_20.png';
            $vars['profile_facebook'] = l(
              "<img src='{$facebook_logo}' />",
              aw960_httpify($facebook_link['url']),
              array(
                'attributes' => array(
                  'target' => '_blank',
                  'onclick' => "ga('send', 'event', 'Leadership Action - Company', '{$company_name}', 'Facebook Click');",
                ),
                'html' => TRUE,
              )
            );
          }

          if (!empty($online_prof_node->field_ld_linkedin)) {
            $linkedin_link = $online_prof_wrapper->field_ld_linkedin->value();
            $linkedin_logo = $css_path . 'ln-20.png';
            $vars['profile_linkedin'] = l(
              "<img src='{$linkedin_logo}' />",
              aw960_httpify($linkedin_link['url']),
              array(
                'attributes' => array(
                  'target' => '_blank',
                  'onclick' => "ga('send', 'event', 'Leadership Action - Company', '{$company_name}', 'LinkedIn Click');",
                ),
                'html' => TRUE,
              )
            );
          }

          if (!empty($online_prof_node->field_ld_google_plus)) {
            $google_link = $online_prof_wrapper->field_ld_google_plus->value();
            $google_logo = $css_path . 'google_plus_20.jpg';
            $vars['profile_google_plus'] = l(
              "<img src='{$google_logo}' />",
              aw960_httpify($google_link['url']),
              array(
                'attributes' => array(
                  'target' => '_blank',
                  'onclick' => "ga('send', 'event', 'Leadership Action - Company', '{$company_name}', 'Google+ Click');",
                ),
                'html' => TRUE,
              )
            );
          }

          if (!empty($online_prof_node->field_ld_twitter)) {
            $twitter_link = $online_prof_wrapper->field_ld_twitter->value();
            $twitter_logo = $css_path . 'twitter2013.png';
            $vars['profile_twitter'] = l(
              "<img src='{$twitter_logo}' />",
              aw960_httpify($twitter_link['url']),
              array(
                'attributes' => array(
                  'target' => '_blank',
                  'onclick' => "ga('send', 'event', 'Leadership Action - Company', '{$company_name}', 'Twitter Click');",
                ),
                'html' => TRUE,
              )
            );
          }

          if (!empty($online_prof_node->field_ld_youtube)) {
            $youtube_link = $online_prof_wrapper->field_ld_youtube->value();
            $youtube_logo = $css_path . 'youtube_20.png';
            $vars['profile_youtube'] = l(
              "<img src='{$youtube_logo}' />",
              aw960_httpify($youtube_link['url']),
              array(
                'attributes' => array(
                  'target' => '_blank',
                  'onclick' => "ga('send', 'event', 'Leadership Action - Company', '{$company_name}', 'YouTube Click');",
                ),
                'html' => TRUE,
              )
            );
          }

          if (!empty($online_prof_node->field_ld_pinterest)) {
            $pinterest_link = $online_prof_wrapper->field_ld_pinterest->value();
            $pinterest_logo = $css_path . 'pinterest_20.png';
            $vars['profile_pinterest'] = l(
              "<img src='{$pinterest_logo}'",
              aw960_httpify($pinterest_link['url']),
              array(
                'attributes' => array(
                  'target' => '_blank',
                  'onclick' => "ga('send', 'event', 'Leadership Action - Company', '{$company_name}', 'Pinterest Click');",
                ),
                'html' => TRUE,
              )
            );
          }

        }

        // Add waywire videos
        $youtube_videos = pmg_youtube_feed_leadership_get_company_all_videos($vars['nid']);
        if ($youtube_videos) {
          $vars['video_grid'] = TRUE;
          drupal_add_js(array('smgVideoGrid' => $youtube_videos), 'setting');
          $video_widget_path = drupal_get_path('module', 'video_widget');
          drupal_add_js($video_widget_path . '/video_widget_includes/js/lightbox.js');
          drupal_add_js($video_widget_path . '/video_widget_includes/angular/videoGrid.js');
          drupal_add_css($video_widget_path . '/video_widget_includes/css/video_grid.css', array(
            'preprocess' => TRUE,
            'every_page' => FALSE,
          ));
        }
      }
    }
  }

  /* Download Content Type */
  if ($vars['type'] == 'download') {
    if (isset($vars['field_download_document'][0]['fid'])) {
      $classes = 'awbs-btn btn btn-block btn-sm ';
      if (!empty($vars['field_pop_up_registration'])) {
        $fc_item_id = $vars['field_pop_up_registration']['und'][0]['value'];
        $fc_array = entity_load('field_collection_item', array($fc_item_id));
        $fc = $fc_array[$fc_item_id];
        $ad_id = (isset($fc->field_smg_pop_ad_id['und'])) ? $fc->field_smg_pop_ad_id['und'][0]['value'] : 1;
        $classes .= 'ctools-use-modal-processed ctools-use-modal ctools-modal-smg-pop-up-style-two-column';
        $classes .= ' purf-ad-' . $ad_id . ' purf-unique-dwnpf';
      }
      $file_url = file_create_url($vars['field_download_document'][0]['uri']);
      $vars['download_field_url'] = $file_url;
      $doc_download_btn = '<a class="' . $classes . '" href="' . $file_url . '">Download Tacticle Brief</a>';
      $vars['doc_download_btn'] = $doc_download_btn;
    }
  }

  /* Whitepaper Content Type */
  if ($vars['type'] == 'whitepaper') {
    if (isset($vars['field_whitepaper'][0]['fid'])) {
      $classes = 'awbs-btn btn-default ';
      if (!empty($vars['field_pop_up_registration'])) {
        $fc_item_id = $vars['field_pop_up_registration']['und'][0]['value'];
        $fc_array = entity_load('field_collection_item', array($fc_item_id));
        $fc = $fc_array[$fc_item_id];
        $ad_id = (isset($fc->field_smg_pop_ad_id['und'])) ? $fc->field_smg_pop_ad_id['und'][0]['value'] : 1;
        $classes .= 'ctools-use-modal-processed ctools-use-modal ctools-modal-smg-pop-up-style-two-column';
        $classes .= ' purf-ad-' . $ad_id . ' purf-unique-dwnpf';
      }
      $file_url = file_create_url($vars['field_whitepaper'][0]['uri']);
      $doc_download_btn = '<a class="' . $classes . '" href="' . $file_url . '">Download White Paper</a>';
      $vars['doc_download_btn'] = $doc_download_btn;
    }
  }

  if (isset($node) && $node->type == 'webinar_registration') {
    $query = db_select('field_data_field_ws_webinar', 'webinar');
    $query->condition('field_ws_webinar_target_id', $node->nid)
      ->fields('webinar', array('entity_id'));
    $result = $query->execute()->fetchField();
    if ($result && !empty($result)) {
      $vars['content']['webinar_url'] = '/node/' . $result;
    }
  }
  $vote_now_url = variable_get('vote_now_link_url');
  if (isset($vote_now_url)) {
    $vars['vote_now_url'] = $vote_now_url;
  }

}

function awbs_menu_tree(&$variables) {
  // return '<ul>' . $variables['tree'] . '</ul>';
  return $variables['tree'];
}

/**
 * Bootstrap theme wrapper function for the primary menu links.
 */
function awbs_menu_tree__primary(&$variables) {
  return '<ul">' . $variables['tree'] . '</ul>';
}

/**
 * Bootstrap theme wrapper function for the mobile menu links.
 */
function awbs_menu_tree__menu_mobile_main_menu(&$variables) {
  return '<ul class="menu">' . $variables['tree'] . '</ul>';
}


/**
 * Implementes hook_form_alter().
 */
function awbs_form_alter(&$form, &$form_state, $form_id) {
  if (isset($form['#node'])) {
    $node = $form['#node'];

    // #830 - Fix for saving a node giving white screen of death.
    // https://www.drupal.org/node/2156371#comment-8876967.
    $module = 'bootstrap';
    $name = 'theme/process';
    $theme = 'awbs';
    $type = 'inc';
    if (!isset($form_state['build_info']['files']["$module:$name.$type"])) {
      $file = drupal_get_path('theme', $module) . "/$name.$type";
      require_once DRUPAL_ROOT . '/' . $file;
      $form_state['build_info']['files']["$module:$name.$type"] = $file;
    }
  }

  if ($form_id == 'search_block_form') {
    $form['#attributes']['class'][] = 'col-xs-12 awbs-dropdown-searchbox';
  }

  if ((isset($node)) && ($node->type == 'stage_one_form')) {
    $form['#attributes']['class'][] = 'col-xs-12';
    $form['submitted']['email']['#attributes']['class'][] = 'form-control';
    $form['submitted']['email']['#attributes']['class'][] = 'awbs-input no-req-icon';
    $form['submitted']['email']['#attributes']['placeholder'][] = 'Enter your email address';
    $form['actions']['submit']['#attributes']['class'][] = 'btn-sm btn-block';
  }

  if ($form_id == 'webform_client_form_13043') {
    $form['#attributes']['class'][] = 'awbs-old-subscribe-form';
    $form['submitted']['country']['#attributes']['class'][] = 'awbs-select no-req-icon col-xs-12';
    $form['submitted']['email']['#attributes']['class'][] = 'awbs-input no-req-icon col-xs-12';
    $form['actions']['submit']['#attributes']['class'][0] = 'col-xs-12 btn-block awbs-btn btn-sm';
  }

  // embed an extra class in the magazine reg form to control width of the
  // drupal-injected form element. AT (10/5/2015)
  if ($form_id == 'webform_client_form_13025') {
    $form['#attributes']['class'][] = 'awbs-old-subscribe-form-adjust';
  }
}

function awbs_theme() {
  $items = array();
  // create custom user-login.tpl.php
  $items['user_login'] = array(
    'render element' => 'form',
    'path' => drupal_get_path('theme', 'awbs') . '/templates',
    'template' => 'user-login',
    'preprocess functions' => array(
      'awbs_preprocess_user_login',
    ),
  );
  $items['webinar_links'] = array(
    'variables' => array('nodes' => NULL),
    'template' => 'webinar-links',
    'path' => drupal_get_path('theme', 'awbs') . '/templates',
  );

  $items['deep_dives_links'] = array(
    'variables' => array(
      'links' => NULL,
      'view_all_link' => NULL,
      ),
    'template' => 'deep_dives-links',
    'path' => drupal_get_path('theme', 'awbs') . '/templates',
  );

  return $items;
}

function awbs_preprocess_user_login(&$variables) {
  $variables['theme_hook_suggestions'][] = "user-login";
}

function awbs_blog_authorinfo($node) {
  $blogdata;

  if (isset($node->field_allterms['und'])) {
    //  $limited_terms = aw960_parse_allterms($node->field_allterms['und'], 3, array('3', '11'));
    foreach ($node->field_allterms['und'] as $term) {
      switch ($term['tid']) {
        case '1876':
          $blogdata['blogtitle'] = '<a href="/factory-automation-desk">Factory Automation Desk</a>';
          break;
        case '1879':
          $blogdata['blogtitle'] = '<a href="/batch-processing-desk">Batch Processing Desk</a>';
          break;
        case '2195':
          $blogdata['blogtitle'] = '<a href="/process-automation-desk">Process Automation Desk</a>';
          break;
        case '911':
          $blogdata['blogtitle'] = '<span><a href="/packaging-automation-desk">Packaging Automation Desk</a>';
          break;
        case '1877':
          $blogdata['blogtitle'] = '<a href="/nextgen-infrastructure-desk">NextGen Infrastructure Desk</a>';
          break;
      }
    }
  }

  if (isset($node->uid) && ($account = user_load($node->uid))) {
    $author_name = $account->name;
    switch ($author_name) {
      case 'Dave Greenfield':
        $blogdata['authorlink'] = l($author_name, 'https://plus.google.com/102198816954209678196/posts?rel=author');
        $blogdata['authorphoto'] = '/sites/default/themes/awbs/images/greenfield.png';
        $blogdata['authortwitter'] = 'DJGreenfield';
        $blogdata['authorlinkedin'] = 'davidjgreenfield';
        break;
      case 'Renee Robbins Bassett':
        $blogdata['authorlink'] = l($author_name, 'https://plus.google.com/116343574983779541134/posts?rel=author');
        $blogdata['authorphoto'] = '/sites/default/themes/aw960/css/images/bassett_66.jpg';
        $blogdata['authortwitter'] = 'AutoM8now';
        $blogdata['authorlinkedin'] = '';
        break;
      case 'Aaron Hand':
        $blogdata['authorlink'] = l($author_name, 'https://plus.google.com/113031841111343220909/posts?rel=author');
        $blogdata['authorphoto'] = '/sites/default/themes/awbs/images/hand.png';
        $blogdata['authortwitter'] = 'AaronHand';
        $blogdata['authorlinkedin'] = 'AaronHand';
        break;
      case 'Grant Gerke':
        $author_link = l($author_name, 'mailto:ggerke@automationworld.com');
        $blogdata['authorphoto'] = '/sites/default/themes/aw960/css/images/gerke_66.jpg';
        $blogdata['authortwitter'] = 'AutoGrant';
        $blogdata['authorlinkedin'] = '';
        break;
      case 'Gary Mintchell':
        $author_link = l($author_name, 'mailto:gmintchell@automationworld.com');
        $blogdata['authorphoto'] = '/sites/default/themes/aw960/css/images/mintchell_66.jpg';
        $blogdata['authortwitter'] = 'garymintchell';
        $blogdata['authorlinkedin'] = '';
        break;
      case 'Pat Reynolds':
        $author_link = l($author_name, 'https://plus.google.com/u/0/111294908650262265839/posts?rel=author');
        $blogdata['authorphoto'] = '/sites/default/themes/awbs/images/reynolds.png';
        $blogdata['authortwitter'] = 'Packcentric';
        $blogdata['authorlinkedin'] = '';
        break;
      case 'Keith Campbell':
        $author_link = $author_name;
        $blogdata['authorphoto'] = '/sites/default/themes/awbs/images/campbell.png';
        $blogdata['authortwitter'] = '';
        $blogdata['authorlinkedin'] = '';
        break;
      case 'Stephanie Neil':
        $author_link = $author_name;
        $blogdata['authorphoto'] = '/sites/default/themes/awbs/images/neil.png';
        $blogdata['authortwitter'] = 'neilst';
        $blogdata['authorlinkedin'] = '';
        break;
    }
    $author_photo = isset($author_photo) ? array(
      '#theme' => 'image',
      '#path' => $author_photo,
      '#width' => '66',
      '#height' => '69',
    ) : array();
  }

  return $blogdata;
}

/*
 This function is never used; see the corresponding template file instead.
*/
function awbs_preprocess_search_results(&$var) {

  //dsm($var);
  $var['info_split']['date'] = $var['result']['node']->created;
  return $var;
}

/**
 * Function for preprocessing Leadership Online Profile nodes.  Called
 * from _preprocess_node
 *
 * @param array $vars The vars array from _preprocess_node
 */
function _awbs_preprocess_leadership_online_profile(&$vars) {
  $site_id = variable_get('smg_global_site');
  $print_profile_node = node_load(leadership_get_corresponding_nid($vars['field_ld_company'][0]['nid'], 'leadership_print_profile', $site_id));

  if (isset($print_profile_node->field_ld_address_1['und'])) {
    $vars['address'] = $print_profile_node->field_ld_address_1['und'][0]['value'];
    // If there is an "Address 2", append it to address 1
    if (isset($print_profile_node->field_ld_address_2['und'])) {
      $vars['address'] .= '<br/>' . $print_profile_node->field_ld_address_2['und'][0]['value'];
    }
  }
  if (isset($print_profile_node->field_ld_phone['und'])) {
    $vars['phone'] = $print_profile_node->field_ld_phone['und'][0]['value'];
  }
  if (isset($print_profile_node->field_ld_email['und'])) {
    $vars['email'] = $print_profile_node->field_ld_email['und'][0]['value'];
  }
  if (isset($print_profile_node->field_ld_country['und'])) {
    $vars['country'] = $print_profile_node->field_ld_country['und'][0]['value'];
  }
  if (isset($print_profile_node->field_ld_address_city['und'])) {
    $vars['city'] = $print_profile_node->field_ld_address_city['und'][0]['value'];
  }
  if (isset($print_profile_node->field_ld_state['und'])) {
    $vars['state'] = $print_profile_node->field_ld_state['und'][0]['value'];
  }
  if (isset($print_profile_node->field_ld_zip_postal_code['und'])) {
    $vars['zip'] = $print_profile_node->field_ld_zip_postal_code['und'][0]['value'];
  }
  if (isset($print_profile_node->field_ld_fax['und'])) {
    $vars['fax'] = $print_profile_node->field_ld_fax['und'][0]['value'];
  }

  if (isset($vars['node']->field_ld_sales['und'])) {
    $sales_values = array();
    foreach ($vars['node']->field_ld_sales['und'] as $value) {
      $sales_values[] = $value['value'];
    }
    $vars['sales'] = implode(', ', $sales_values);
  }
}

/**
 * Implementes hook_views_pre_render().
 */
function awbs_views_pre_render(&$view) {
  if ($view->name == 'related_links') {
    $links_count = count($view->result[0]->field_field_sponsor_links);
    for ($i = 0; $i < $links_count; $i++) {
      $url = $view->result[0]->field_field_sponsor_links[$i]['raw']['url'];
      $company = $view->result[0]->_field_data['node_field_data_field_wir_sponsor_nid']['entity']->title;
      $title = $view->result[0]->field_field_sponsor_links[$i]['raw']['title'];
      $view->result[0]->field_field_sponsor_links[$i]['rendered']['#markup'] = '<a href="' . $url . '" onclick="ga(\'send\', \'event\', \'' . $company . ' Promo Links\', \'Click\', \'' . $title . '\');" target="_blank">' . $title . '</a>';
    }
  }
}

/**
 * Function for preprocessing Webinar links in hamburger menu.  Called
 * from _preprocess_page
 *
 */
function _awbs_preprocess_webinar_links() {
  $nodes = db_select('node', 'n')
    ->condition('type', 'webinar_registration')
    ->condition('n.status', NODE_PUBLISHED)
    ->fields('n', array('nid', 'title'))
    ->orderBy('n.changed', 'DESC')
    ->range(0, 4)
    ->execute()
    ->fetchAll();
  $render = theme('webinar_links', array('nodes' => $nodes));
  return $render;
 }


/**
 * Function for preprocessing Webinar links in hamburger menu.  Called
 * from _preprocess_page
 *
 */
function _awbs_preprocess_deep_dives_links() {
  $links = array();

  $view = views_get_view('video');

  $view->set_display('page_1');
  $view->set_items_per_page(3);
  $view->set_current_page(0);
  $view->execute();


  foreach($view->result as $key => $value) {
    $node = node_load($value->nid);
    $link = new stdClass();
    $link->title = $node->title;
    $link->path = drupal_get_path_alias('node/' . $value->nid);;
    $links[] = $link;
  }

  $render = theme('deep_dives_links', array(
    'links' => $links,
    'view_all_link' => $view->display['page_1']->display_options['path']));

  return $render;
 }
