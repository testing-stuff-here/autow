<?php


/**
 * Implements template_preprocess_html().
 */
function aw960_preprocess_html(&$vars) {

  $node = (arg(0) == 'node' && is_numeric(arg(1))) ? node_load(arg(1)) : FALSE;

  // Add stylesheets for responsive design
  drupal_add_css(drupal_get_path('theme', 'aw960') . '/css/style_screen_min641.css', array('group'=> CSS_DEFAULT, 'every_page' => TRUE, 'weight' => 0, 'preprocess' => TRUE, 'media' => 'only screen and (min-width: 641px)'));
  drupal_add_css(drupal_get_path('theme', 'aw960') . '/css/style800.css', array('group'=> CSS_DEFAULT, 'every_page' => TRUE, 'weight' => 1, 'preprocess' => TRUE, 'media' => 'only screen and (max-width: 800px)'));
  drupal_add_css(drupal_get_path('theme', 'aw960') . '/css/style640.css', array('group'=> CSS_DEFAULT, 'every_page' => TRUE, 'weight' => 2, 'preprocess' => TRUE, 'media' => 'only screen and (max-width: 640px)'));
  drupal_add_css(drupal_get_path('theme', 'aw960') . '/css/style320.css', array('group'=> CSS_DEFAULT, 'every_page' => TRUE, 'weight' => 3, 'preprocess' => TRUE, 'media' => 'only screen and (max-width: 320px)'));

  if($vars['is_front'] == TRUE) {
    // Only adding the content rotator script to the home page
    drupal_add_js(drupal_get_path('theme', 'aw960') . '/js/view-gallery.js', 'file');
  }

  if($node) {
    if($node->uid == '3197' || $node->uid == '3198') {
      $vars['classes_array'][] = 'guest-blog';
    }

    // For newsletter and app registration forms
    if(in_array($node->nid, array('16127', '13025', '16131'))){
      $vars['classes_array'][] = 'smg-webform-two-column';
    }

  }

  // #2331
  if($node && in_array($node->nid, array('9484', '16131')) || (arg(0) == 'app-registration-web' && (arg(1)) && arg(1) == 'thank-you')){
    $vars['classes_array'][] = 'app-page';
  }

  /**
   * Protect window.console method calls, e.g. console is not defined on IE
   * unless dev tools are open, and IE doesn't define console.debug
   */
  $ie_console_js = <<<EOS
  (function() {
    if (!window.console) {
      window.console = {};
    }
    // union of Chrome, FF, IE, and Safari console methods
    var m = [
      "log", "info", "warn", "error", "debug", "trace", "dir", "group",
      "groupCollapsed", "groupEnd", "time", "timeEnd", "profile", "profileEnd",
      "dirxml", "assert", "count", "markTimeline", "timeStamp", "clear"
    ];
    // define undefined methods as noops to prevent errors
    for (var i = 0; i < m.length; i++) {
      if (!window.console[m[i]]) {
        window.console[m[i]] = function() {};
      }
    }
  })();
EOS;
  drupal_add_js($ie_console_js, array('type'=>'inline', 'scope'=>'header', 'group'=>JS_LIBRARY, 'weight'=>1));

  // Ticket #2093
  // add Silverpop web-tracking tag to header
  $engage_meta = array(
    '#tag' => 'meta',
    '#attributes' => array(
      'name' => 'com.silverpop.brandeddomains',
      'content' => 'www.pages05.net,www.automationworld.com,automationworld.com,greenerpackage.com,healthcarepackaging.com,packworld.com,page.automationworld.com,page.biz-library.com,page.healthcarepackaging.com,page.packworld.com,theautomationconference.com,totallyintegratedautomation.com',
    ),
  );
  drupal_add_html_head($engage_meta, 'engage_meta');
  $engage_script = array(
    '#tag' => 'script',
    '#attributes' => array(
      'src' => 'http://contentz.mkt51.net/lp/static/js/iMAWebCookie.js?5872ae98-13481d0a159-d7c8ec57ae636c7258d3eb0ef0e531f2&h=www.pages05.net',
    ),
    '#suffix' => '</script>',
  );
  drupal_add_html_head($engage_script, 'engage_script');

  $meta_ie_render_engine = array(
      '#type' => 'html_tag',
      '#tag' => 'meta',
      '#attributes' => array(
        'http-equiv' => 'X-UA-Compatible',
        'content' =>  'IE=edge,chrome=1',
      ),
      '#weight' => '-99999',
    );

  // Add header meta tag for IE to head
  drupal_add_html_head($meta_ie_render_engine, 'meta_ie_render_engine');

  #2353
  if(isset($vars['page']['sidebar_second'])) {
    if(array_key_exists('block_62', $vars['page']['sidebar_second'])){
      $traffic_js = <<<EOT
        jQuery(document).ready(function($){
          if($('#x08').find('.ta-item').length > 0){
            jQuery('#traffic-accelerator-break').show();
            jQuery('#x08').show();
            $('#block-block-62').show();
          }
          if($('#x07').find('.ta-item').length > 0){
            $('#traffic-accelerator-break').show();
            $('#x07').show();
            $('#block-block-62').show();
          }

          if($('#x08').find('.ta-item').length || $('#x07').find('.ta-item').length){
            $(".ta-item").each(function(i,e){
              var itemInfo = $(e).find(".ta-item-info");
              $(e).find(".ta-item-company").each(function(){
                $(this).appendTo(itemInfo);
              });
            });
          }
        });
EOT;
      drupal_add_js($traffic_js , array('type' => 'inline', 'scope' => 'header', 'every_page' => 'false' ));
    }
  }

  if ($node && $node->type == 'company') {
    $current_session = FALSE;
    $is_published_online_profile = FALSE;
    if (!empty($node->field_ld_session)) {
      foreach ($node->field_ld_session['und'] as $value) {
        if ($value['tid'] == variable_get('leadership_session_term')) {
          $current_session = TRUE;
          $online_profile = node_load(leadership_get_corresponding_nid($node->nid, 'leadership_online_profile', 'aw'));
          $is_published_online_profile = $online_profile->status == 1 ? TRUE : FALSE;
        }
      }
    }
    if ($current_session && $is_published_online_profile) {
      $vars['sidebar_second_region'] = '';
      foreach ($vars['classes_array'] as $key => $value) {
        if (in_array($value, array('one-sidebar sidebar-second', 'one-sidebar', 'sidebar-second'))) {
          unset($vars['classes_array'][$key]);
        }
      }
      $vars['classes_array'][] = 'leadership-company';
    }
  }

}

// use to print blocks insidenode--article.tpl.php
function aw960_content_blocks($content,$block_ads,$block_related_articles,$block_ad1,$block_ad2){
  if(empty($block_ads)){
    $block_ads ='';
  }

  if(empty($block_related_articles)){
    $block_related_articles ='';
  }

  if(empty($block_ad1)){
    $block_ad1 ='';
  }

  if(empty($block_ad2)){
    $block_ad2 ='';
  }

  $striptags_content = strip_tags($content);
  $total_words = str_word_count($striptags_content);
  $total_characters = strlen($striptags_content);

  $block_related_articles_max = '<div class="maxwidth" >'. $block_related_articles.'</div>';

  $output = '';

  $insert = true;
  if (!module_exists('simplehtmldom')) {
    drupal_set_message('Please install simplehtmldom module to insert the blocks');
    $insert = false;
  }

  //Begin appending the responsive design blocks if total characters > 1600
  if($insert && $total_words>=400){
    $count_words = str_word_count($striptags_content);

    $matches = explode("</p>", $content);
    $total_count = 0;
    $inserted1 = $inserted2 = false;
    $p = '';

    // Computation at what point the tile blocks needs to be inserted
    // Based on the css (the padding of the words are a little big), I noticed that each block would fill up
    // 30 words and if there is an image it would take around 40 words. These are all assumptions and so far
    // the tests have not failed me. Feel free to change the numbers when styling changed
    $words_after_rel = 0;
    $total_reltw_block = count(explode('<div class="retlw-block">', $block_related_articles));
    $total_img = substr_count($block_related_articles, '<img');
    $words_after_rel = 200 + ((int)$total_reltw_block * 30) + ((int)$total_img * 11);

    foreach($matches as $key => $match) {
      $match = str_replace(array('<p>','</p>'),array('',''),$match);
      // insert skycraper ad here
      $html_obj = new simple_html_dom();
      $html_obj->load($match);
      $count = 0;
      $plaintext = $html_obj->find('text');
      foreach ($plaintext as $plain_text_obj ) {
        $count += str_word_count($plain_text_obj->innertext);
      }

      //$count = str_word_count($match);

      $total_count2 = $total_count + $count;
      //dsm($count.':'.$total_count, 'count');

      $processed = false;
      if (!$inserted1 && ($total_count2) >= 100) {
        // insert IMU here
        /* #1926 Removing Mobile Ads
        $block_text = '<div class="within-content-1" >' . $block_ad1 . '</div>'
                    . '<div class="within-content minwidth" >'. $block_related_articles.'</div>';
        */
        $block_text = '<div class="within-content minwidth" >'. $block_related_articles.'</div>';
        _aw960_insert_block($plaintext, 100, ' '.$block_text);
        $inserted1 = true;
        $processed = true;

      }

      if (!$inserted2 && ($total_count2) >= $words_after_rel) {
        // insert skycraper ad here
        $block_text = '<div class="within-content-2" >' . $block_ad1 . '</div>';
                   // . '<div class="within-content-3" >' . $block_ad2 . '</div>';
        _aw960_insert_block($plaintext, $words_after_rel, ' '.$block_text);

        $inserted2 = true;
        $processed = true;
      }

      if (!$processed) {
        $p .= $match . '</p>';
      }
      else {
        $p .= $html_obj->__toString() . '</p>';
      }


      $total_count += $count;
      if ($inserted1 && $inserted2) {
        $arr = array_splice($matches, $key+1, count($matches));
        $p .= implode('</p>', $arr);
        break;
      }
    }

    if (!$inserted2) {
      $p .= $block_ad2;
    }

    //$output = $p;
    $content  = $p;
  }
  if ($total_words < 100) {
    // if content < 100 words, display tile ads at the bottom followed by related articles
    $block_related_articles = '<div class="within-content maxwidth" >'. $block_related_articles.'</div>';
    $output = $content . $block_ad1 . $block_related_articles;
  }
  else if ($total_words < 400) {
    // display tile ads after 100 words and at the most bottom part the related articles block
    $count_words = str_word_count($striptags_content);
    $matches = explode("</p>", $content);
    $total_count = 0;
    $inserted = false;
    $p = '';
    foreach($matches as $match) {
      $textonly = strip_tags($match);
      $count = str_word_count($textonly);
      $total_count += $count;
      $p .= $match . '</p>';
      if (!$inserted && $total_count > 100) {
        $p .= $block_ads;
        $inserted = true;
      }
    }
    $block_related_articles = '<div class="within-content maxwidth" >'. $block_related_articles.'</div>';
    $output = $p . $block_ad1 . $block_related_articles;
  }
  else {
    $output = $content;
    /*
    // display related articles after 280 words (break only per paragraph).
    // display tile ads after 2 paragraphs below the the related articles block (ideally)
    $block_related_articles = '<div class="within-content minwidth" >'. $block_related_articles.'</div>';

    $count_words = str_word_count($striptags_content);
    $matches = explode("</p>", $content);
    $total_count = 0;
    $inserted_rel = false;
    $inserted_tile = false;
    $p = '';

    // Computation at what point we are adding the related block
    // I tested this with adding it at the middle and it way too low so im inserting at the 1/3 of the content
    // But minimum count, it should be inserted after 100 words.
    $break_rel = round($count_words / 3); // client wants it as high as possible
    if ($break_rel < 100) $break_rel = 100;
		else $break_rel = 200;

    // Computation at what point the tile blocks needs to be inserted
    // Based on the css (the padding of the words are a little big), I noticed that each block would fill up
    // 30 words and if there is an image it would take around 40 words. These are all assumptions and so far
    // the tests have not failed me. Feel free to change the numbers when styling changed
    $words_after_rel = 0;
    $total_reltw_block = count(explode('<div class="retlw-block">', $block_related_articles));
    $total_img = substr_count($block_related_articles, '<img');
    $words_after_rel = $break_rel + ((int)$total_reltw_block * 30) + ((int)$total_img * 10);
    //dsm($break_rel . ' | ' . $words_after_rel . ' = ' . $total_reltw_block . ' + ' . $total_img, 'computation');

    $after_rel_cnt = 0;
    foreach($matches as $match) {
      $textonly = strip_tags($match);
      $count = str_word_count($textonly);
      $total_count += $count;
      $p .= $match . '</p>';
      if (!$inserted_rel && $total_count > $break_rel) {
        $p .= $block_related_articles;
        $inserted_rel = true;
      }

      if ($inserted_rel && !$inserted_tile && $total_count > $words_after_rel) {
        // Ideally, we want to display the tile ads after the 2nd paragraph (visually)
        $after_rel_cnt++;
        if ($after_rel_cnt == 2) {
          $p .= $block_ads;
          $inserted_tile = true;
        }
      }
    }

    if (!$inserted_tile) {
      $p .= $block_ads;
    }

    $output = $p;
    */
  }

  // for the sake of 768 pixels wide RESPONSIVE DESIGN lets print the $block_ads & $block_related_articles
  // again at the end of the content. php cant detect client browser display screen, by default this is
  // hidden in the css
  $output = $output .'<div class="responsive-design">'
    . '<div>'
    . $block_related_articles_max . $block_ads
    . '</div>'
    . '</div>';

  print $output ;

  return '';
}

/**
 * Cut string to n symbols and add delim but do not break words.
 */
function _aw960_insert_block(&$domplaintext, $breakpoint, $insert_text) {
  $counter = 1;
  foreach ($domplaintext as $plain_text_obj ) {
    if (empty($plain_text_obj->innertext)) continue;

    $words = explode(' ', $plain_text_obj->innertext);
    $cnt_words = count($words);

    if (($counter+$cnt_words) < $breakpoint) {
      $counter += $cnt_words;
      continue;
    }
    //dsm($plain_text_obj->innertext, $counter . ':' . $cnt_words . ':'.$breakpoint);
    foreach($words as $wordkey => $word) {
      if ($counter == $breakpoint) {
        $innertext = $plain_text_obj->innertext;
        $lasthalf = array_splice($words, $wordkey);
        $plain_text_obj->innertext =  implode(' ', $words) . $insert_text . implode(' ', $lasthalf);
        //$counter += count($lasthalf);
        return true;
      }
      $counter++;
    }
  }

  $plain_text_obj->innertext = $insert_text . $plain_text_obj->innertext;
  return false;
}

/*This will modify the site pagers(homepage only)*/
function aw960_pager($variables) {
   if(arg(0)!='node'){ //this will bypass the node page (smartpaging)
      $tags = $variables['tags'];
      $element = $variables['element'];
      $parameters = $variables['parameters'];
      $quantity = 5;
      global $pager_page_array, $pager_total;

      // Calculate various markers within this pager piece:
      // Middle is used to "center" pages around the current page.
      $pager_middle = ceil($quantity / 2);
      // current is the page we are currently paged to
      $pager_current = $pager_page_array[$element] + 1;
      // first is the first page listed by this pager piece (re quantity)
      $pager_first = $pager_current - $pager_middle + 1;
      // last is the last page listed by this pager piece (re quantity)
      $pager_last = $pager_current + $quantity - $pager_middle;
      // max is the maximum page number
      $pager_max = $pager_total[$element];
      // End of marker calculations.

      // Prepare for generation loop.
      $i = $pager_first;
      if ($pager_last > $pager_max) {
        // Adjust "center" if at end of query.
        $i = $i + ($pager_max - $pager_last);
        $pager_last = $pager_max;
      }
      if ($i <= 0) {
        // Adjust "center" if at start of query.
        $pager_last = $pager_last + (1 - $i);
        $i = 1;
      }
      // End of generation loop preparation.
    if($pager_total[0]>5){ $next_label='Next >>';  $previous_label='<< Previous';}
    else {$next_label='';  $previous_label='';}

      $li_first = theme('pager_first', array('text' => (isset($tags[0]) ? $tags[0] : t('<< first')), 'element' => $element, 'parameters' => $parameters));
      $li_previous = theme('pager_previous', array('text' => (isset($tags[1]) ? $tags[1] : t($previous_label)), 'element' => $element, 'interval' => 1, 'parameters' => $parameters));
      $li_next = theme('pager_next', array('text' => (isset($tags[3]) ? $tags[3] : t($next_label)), 'element' => $element, 'interval' => 1, 'parameters' => $parameters));
      $li_last = theme('pager_last', array('text' => (isset($tags[4]) ? $tags[4] : t('last >>')), 'element' => $element, 'parameters' => $parameters));

      if ($pager_total[$element] > 1) {
        if ($li_first) {
          $items[] = array(
            'class' => array('pager-first'),
            'data' => $li_first,
          );
        }
        if ($li_previous) {
          $items[] = array(
            'class' => array('pager-previous'),
            'data' => $li_previous,
          );
        }

        // When there is more than one page, create the pager list.
        if ($i != $pager_max) {
          if ($i > 1) {
            $items[] = array(
              'class' => array('pager-ellipsis'),
              'data' => '...',
            );
          }
          // Now generate the actual pager piece.
          for (; $i <= $pager_last && $i <= $pager_max; $i++) {
            if ($i < $pager_current) {
              $items[] = array(
                'class' => array('pager-item'),
                'data' => theme('pager_previous', array('text' => $i, 'element' => $element, 'interval' => ($pager_current - $i), 'parameters' => $parameters)),
              );
            }
            if ($i == $pager_current) {
              $items[] = array(
                'class' => array('pager-current'),
                'data' => $i,
              );
            }
            if ($i > $pager_current) {
              $items[] = array(
                'class' => array('pager-item'),
                'data' => theme('pager_next', array('text' => $i, 'element' => $element, 'interval' => ($i - $pager_current), 'parameters' => $parameters)),
              );
            }
          }
          if ($i < $pager_max) {
            $items[] = array(
              'class' => array('pager-ellipsis'),
              'data' => '...',
            );
          }
        }
        // End generation.
        if ($li_next) {
          $items[] = array(
            'class' => array('pager-next'),
            'data' => $li_next,
          );
        }
        if ($li_last) {
          $items[] = array(
            'class' => array('pager-last'),
            'data' => $li_last,
          );
        }
        return '<h2 class="element-invisible">' . t('Pages') . '</h2>' . theme('item_list', array(
          'items' => $items,
          'attributes' => array('class' => array('pager')),
        ));
      }
  }
  else { //use the default theme_pager
      $tags = $variables['tags'];
      $element = $variables['element'];
      $parameters = $variables['parameters'];
      $quantity = $variables['quantity'];
      global $pager_page_array, $pager_total;

      // Calculate various markers within this pager piece:
      // Middle is used to "center" pages around the current page.
      $pager_middle = ceil($quantity / 2);
      // current is the page we are currently paged to
      $pager_current = $pager_page_array[$element] + 1;
      // first is the first page listed by this pager piece (re quantity)
      $pager_first = $pager_current - $pager_middle + 1;
      // last is the last page listed by this pager piece (re quantity)
      $pager_last = $pager_current + $quantity - $pager_middle;
      // max is the maximum page number
      $pager_max = $pager_total[$element];
      // End of marker calculations.

      // Prepare for generation loop.
      $i = $pager_first;
      if ($pager_last > $pager_max) {
        // Adjust "center" if at end of query.
        $i = $i + ($pager_max - $pager_last);
        $pager_last = $pager_max;
      }
      if ($i <= 0) {
        // Adjust "center" if at start of query.
        $pager_last = $pager_last + (1 - $i);
        $i = 1;
      }
      // End of generation loop preparation.

      $li_first = theme('pager_first', array('text' => (isset($tags[0]) ? $tags[0] : t('<< first')), 'element' => $element, 'parameters' => $parameters));
      $li_previous = theme('pager_previous', array('text' => (isset($tags[1]) ? $tags[1] : t('<< previous')), 'element' => $element, 'interval' => 1, 'parameters' => $parameters));
      $li_next = theme('pager_next', array('text' => (isset($tags[3]) ? $tags[3] : t('next >>')), 'element' => $element, 'interval' => 1, 'parameters' => $parameters));
      $li_last = theme('pager_last', array('text' => (isset($tags[4]) ? $tags[4] : t('last >>')), 'element' => $element, 'parameters' => $parameters));


      if ($pager_total[$element] > 1) {
        if ($li_first) {
          $items[] = array(
            'class' => array('pager-first'),
            'data' => $li_first,
          );
        }
        if ($li_previous) {
          $items[] = array(
            'class' => array('pager-previous'),
            'data' => $li_previous,
          );
        }

        // When there is more than one page, create the pager list.
        if ($i != $pager_max) {
          if ($i > 1) {
            $items[] = array(
              'class' => array('pager-ellipsis'),
              'data' => '',

            );
          }
          // Now generate the actual pager piece.
          for (; $i <= $pager_last && $i <= $pager_max; $i++) {
            if ($i < $pager_current) {
              $items[] = array(
                'class' => array('pager-item'),
                'data' => theme('pager_previous', array('text' => $i, 'element' => $element, 'interval' => ($pager_current - $i), 'parameters' => $parameters)),
              );
            }
            if ($i == $pager_current) {
              $items[] = array(
                'class' => array('pager-current'),
                'data' => $i,
              );
            }
            if ($i > $pager_current) {
              $items[] = array(
                'class' => array('pager-item'),
                'data' => theme('pager_next', array('text' => $i, 'element' => $element, 'interval' => ($i - $pager_current), 'parameters' => $parameters)),
              );
            }
          }
          if ($i < $pager_max) {
            $items[] = array(
              'class' => array('pager-ellipsis'),
              'data' => '',
            );
          }
        }
        // End generation.
        if ($li_next) {
          $items[] = array(
            'class' => array('pager-next'),
            'data' => $li_next,
          );
        }
        if ($li_last) {
          $items[] = array(
            'class' => array('pager-last'),
            'data' => $li_last,
          );
        }

        return '<h2 class="element-invisible">' . t('Pages') . '</h2>' . theme('item_list', array(
          'items' => $items,
          'attributes' => array('class' => array('pager')),
        ));
      }

  }
}

function aw960_pager_link($variables) {
  global $base_url;
  $text = $variables['text'];
  $page_new = $variables['page_new'];
  $element = $variables['element'];
  $parameters = $variables['parameters'];
  $attributes = $variables['attributes'];

  $page = isset($_GET['page']) ? $_GET['page'] : '';
  if ($new_page = implode(',', pager_load_array($page_new[$element], $element, explode(',', $page)))) {
    $parameters['page'] = $new_page;
  }

  $query = array();
  if (count($parameters)) {
    $query = drupal_get_query_parameters($parameters, array());
  }
  if ($query_pager = pager_get_query_parameters()) {
    $query = array_merge($query, $query_pager);
  }

  // Set each pager link title
  if (!isset($attributes['title'])) {
    static $titles = NULL;
    if (!isset($titles)) {
      $titles = array(
        t('<< first') => t('Go to first page'),
        t('<< previous') => t('Go to previous page'),
        t('next >>') => t('Go to next page'),
        t('last >>') => t('Go to last page'),
      );
    }
    if (isset($titles[$text])) {
      $attributes['title'] = $titles[$text];
    }
    elseif (is_numeric($text)) {
      $attributes['title'] = t('Go to page @number', array('@number' => $text));
    }
  }

  // #1998 - removing string 'home' from urls
  // #
  $path = aw960_get_url($query);
  static $rel_prev = FALSE,
         $rel_next = FALSE;
  if (!$rel_prev && ($text == t('<< Previous'))) {
    $rel_prev = TRUE;
    drupal_add_html_head_link(array('rel' => 'prev', 'href' => $base_url . $path));
  }
  if (!$rel_next && ($text == t('Next >>'))) {
    $rel_next = TRUE;
    drupal_add_html_head_link(array('rel' => 'next', 'href' => $base_url . $path));
  }

  // @todo l() cannot be used here, since it adds an 'active' class based on the
  //   path only (which is always the current path for pager links). Apparently,
  //   none of the pager links is active at any time - but it should still be
  //   possible to use l() here.
  // @see http://drupal.org/node/1410574
  $attributes['href'] = $path;
  return '<a' . drupal_attributes($attributes) . '>' . check_plain($text) . '</a>';
}

/**
 * Removes home string from path and also creates url
 *
 * @param $query
 *  the url parameters
 *
 * @return $path
 *  the url path
 */
function aw960_get_url($query) {
  $path = $_GET['q'];
  if($path == 'home') {
    $path = '';
  }

  $path = url($path, array('query' => $query));

  return $path;
}

/**
 *Theme function for getting RSS links for the menu
 */
function aw960_preprocess_page(&$vars) {

  $args = arg();

  if(isset($vars['node'])){
    $nid = $vars['node']->nid;
    // Factory and Machine Automation Form.  Add JS file
    if($nid == '14229') {
      $fma_reg = <<<EOT
        jQuery(window).on("load", function(){ setTimeout( function(){ ewt.trackLink({name:'AW FMA Playbook Page Loaded', type:'playbook-aw_factory_machine_automation'}); }, 1000 ); });
EOT;
      drupal_add_js($fma_reg, array('type'=>'inline', 'every_page' => 'false'));
      drupal_add_js(drupal_get_path('theme', 'aw960') . '/js/playbook.js', 'file');
    }
    // Factory and Machine Automation Survey.  Add inline JS
    if($nid == '14496') {
      $fma_survey_js = <<<EOT
        jQuery(window).on("load", function(){ setTimeout( function(){ ewt.trackLink({name:'AW FMA Playbook - Survey', type:'playbook-aw_fma_survey'}); }, 1000 ); });
EOT;
      drupal_add_js($fma_survey_js, array('type'=>'inline', 'every_page' => 'false'));
    }

    // #2294 Set sidebar second region to an empty string
    // also unset margin_left
    if(in_array($nid, array('16127', '13025')) || in_array($vars['node']->type, array('leadership_online_profile'))){
      $vars['sidebar_second_region'] = '';
      $vars['page']['margin_left'] = FALSE;
    }

  }

  // #2331
  if(isset($vars['node']) && in_array($vars['node']->nid, array('9484', '16131')) || (arg(0) == 'app-registration-web' && (arg(1)) && arg(1) == 'thank-you')){
    $app_header_logo = '/' . drupal_get_path('theme', 'aw960') . '/images/AW_Logo.png';
    $app_header_home = '/' . drupal_get_path('theme', 'aw960') . '/images/homebtn40x37.png';
    $vars['app_header_logo'] = $app_header_logo;
    $vars['app_header_home'] = $app_header_home;
  }

  if($args[0] == 'playbooks-mod' && isset($args[1])) {
    $fma_thank_you_js = <<<EOT
      jQuery(window).on("load", function(){ setTimeout( function(){ try{ ewt.trackLink({name:'AW FMA Playbook - Thank You Page', type:'playbook-aw_fma_thank-you'}); }catch(e){ return false; } }, 1000 ); });
EOT;
    // Ticket #2093, adding custom event that fires after user submits the FAM Playbook Form
    // will wrap this in a switch clause so that we can group similar code together in the future
    switch($args[1]){
      case 14229:
        drupal_add_js($fma_thank_you_js, array('type' => 'inline', 'every_page' => 'false'));
    }
  }

  /*
  if($vars['is_front'] === TRUE && $vars['user']->uid == 0) {
    drupal_add_js(drupal_get_path('theme', 'aw960') .'/js/homeGoogleEvents.js');
    drupal_add_js(drupal_get_path('theme', 'aw960') .'/js/scrolldepth/jquery.scrolldepth.min.js');
    drupal_add_js('jQuery(function($){
      $.scrollDepth({
        label: "Scroll Depth - Home Page"
      });
    });', 'inline');
  }
  */

	//defualting the link to self
	$vars['rss_link'] = '#';
	//Based on the title the rss feedburner link is created
	$link = array(
		'Control' => 'http://feeds.feedburner.com/automationworld/controlandinstrumentationstrategies',
		'PLC' => 'http://feeds.feedburner.com/automationworld/plcs/controllers',
		'DCS' => 'http://feeds.feedburner.com/automationworld/distributedcontrolsystems',
		'HMI' => 'http://feeds.feedburner.com/automationworld/hmi',
		'Operations' => 'http://feeds.feedburner.com/automationworld/operationsengineering',
		'MES' => 'http://feeds.feedburner.com/automationworld/mes',
		'MOM' => 'http://feeds.feedburner.com/awmom',
		'Sensors' => 'http://feeds.feedburner.com/automationworld/sensors',
		'Information Management' => 'http://feeds.feedburner.com/awinformationmanagement',
		'Ethernet' => 'http://feeds.feedburner.com/awethernet',
		'Networking' => 'http://feeds.feedburner.com/automationworld/networking',
		'Cloud Computing' => 'http://feeds.feedburner.com/awcloudcomputing',
		'Safety' => 'http://feeds.feedburner.com/automationworld/safety',
		'Networks' => 'http://feeds.feedburner.com/automationworld/networksconnectivity',
		'AW Channels' => 'http://feeds.feedburner.com/automationworld/suppliernews',
		);
	if(isset($vars['title'])) {
    $title = trim($vars['title']);
		if(array_key_exists($title,$link)) {
		  $vars['rss_link'] = $link[$title];
	  }
	}

	//@TODO Rewrite all above to be by path instead of title name
	$args = arg();
	if(isset($args[1])){
    $path = $args[0] . '/'  . $args[1];
  }
  else {
    $path = $args[0];
  }

	// Based on the path set the rss_link variable to the FeedBurner Link.
  switch($path) {
	  case 'energy':
			$vars['rss_link'] = 'http://feeds.feedburner.com/awenergy';
			break;
		case 'security':
			$vars['rss_link'] = 'http://feeds.feedburner.com/automationworld/security';
			break;
		case 'opconnect':
			$vars['rss_link'] = 'http://feeds.feedburner.com/Opconnect';
			break;
		case 'manufacturing-intelligence':
			$vars['rss_link'] = 'http://feeds.feedburner.com/automationworld/mfg_intelligence';
			break;
		case 'tac2012':
			$vars['rss_link'] = 'http://feeds.feedburner.com/tac2012';
			break;
		case 'safety/process-safety':
			$vars['rss_link'] = 'http://feeds.feedburner.com/awprocess';
			break;
		case 'safety/machine-safety':
			$vars['rss_link'] = 'http://feeds.feedburner.com/automationworld/machinery';
			break;
		case 'informationmanagement/communication':
			$vars['rss_link'] = 'http://feeds.feedburner.com/automationworld/communication';
			break;
		case 'control/motion-control':
			$vars['rss_link'] = 'http://feeds.feedburner.com/automationworld/motion';
			break;
		case 'control/process-control':
			$vars['rss_link'] = 'http://feeds.feedburner.com/awprocesscontrol';
			break;
	  case 'control/instrumentation':
	 	  $vars['rss_link'] = 'http://feeds.feedburner.com/automationworld/instrumentation';
		  break;
		case 'operations/maintenance':
		  $vars['rss_link'] = 'http://feeds.feedburner.com/automationworld/maintenance';
			break;
		case 'informationmanagement/historians':
			$vars['rss_link'] = 'http://feeds.feedburner.com/automationworld/historians';
			break;
    case 'continuous-process-desk':
      $vars['rss_link'] = '/continuous-process-desk.rss';
      break;
    case 'discrete-manufacturing-desk':
      $vars['rss_link'] = '/discrete-manufacturing-desk.rss';
      break;
    case 'processing-packaging-desk':
      $vars['rss_link'] = '/processing-packaging-desk.rss';
      break;
    case 'nextgen-infrastructure-desk':
      $vars['rss_link'] = '/nextgen-infrastructure-desk.rss';
      break;
    case 'tac2013':
      $vars['rss_link'] = 'http://feeds.feedburner.com/TheAutomationConference2013';
      break;
  }

  // Add js to each page to modify main menu for responsive design.  See ticket #2135 (http://dev.summitpublish.com/ticket/2135)
  // get the html for the search block and pass it into Drupal's js settings.  Will be used to dynamically add the search block to the
  // responsive menu
  $search_block = drupal_render(drupal_get_form('search_form'));
  drupal_add_js(array('aw960' => array('searchHTML' => $search_block)), array('type' => 'setting'));
  drupal_add_js(drupal_get_path('theme', 'aw960') .'/js/responsiveMainMenu.js', array('type' => 'file', 'group' => JS_LIBRARY, 'weight' => 1));

  // #137 Leadership Companies
  if (isset($vars['node']) && $vars['node']->type == 'company') {
    $is_published_online_profile = FALSE;
    $current_session = FALSE;
    if (!empty($vars['node']->field_ld_session)) {
      foreach ($vars['node']->field_ld_session['und'] as $value) {
        if ($value['tid'] == variable_get('leadership_session_term')) {
          $current_session = TRUE;
          $online_profile = node_load(leadership_get_corresponding_nid($vars['node']->nid, 'leadership_online_profile', 'aw'));
          $is_published_online_profile = $online_profile->status == 1 ? TRUE : FALSE;
        }
      }
    }
    if ($current_session && $is_published_online_profile) {
      $vars['sidebar_second_region'] = '';
    }
  }

}

/**
 * Theme function for preprocessing a node
 */
function aw960_preprocess_node(&$vars) {

	//gives page number of pager
	global $pager_page_array;
	$vars['pager'] = $pager_page_array;

	// *** Node type
  $types = node_type_get_types();
  $vars['node_type'] = $types[$vars['type']]->name;

  // *** Source Type
	$vars['show_block_33'] = TRUE;
  if(isset($vars['field_term_source_type'][0]['tid']) && $vars['field_term_source_type'][0]['tid']) {
    if($vars['field_term_source_type'][0]['tid'] == 139) {
      $vars['show_block_33'] = FALSE;
    }
  }

  // *** Video
  if($vars['type'] == 'video' && $vars['page'] == TRUE) {
    // Hide Preroll if Deep Dive
    if(isset($vars['field_term_coverage_type'][0]['tid']) && isset($vars['nid'])) {
      if($vars['field_term_coverage_type'][0]['tid'] != 1941 && $vars['nid'] != 13061) {
        $vars['show_preRoll'] = TRUE;
      }
    }

    $vars['attributes_array']['itemprop'] = 'video';
	  $vars['attributes_array']['itemscope itemtype'] = 'http://schema.org/VideoObject';

	  $vars['video_thumbnail'] = isset($vars['field_viddler_id'][0]['thumbnail_url']) ? $vars['field_viddler_id'][0]['thumbnail_url'] : "";
    $vars['embed_url'] = isset($vars['field_viddler_id'][0]['value']) ? 'http://www.viddler.com/embed/' . $vars['field_viddler_id'][0]['value'] : "";

    // If it has Waywire video overwrite viddler items.
    if (isset($vars['field_waywire_video'][0]['video_url'])) {
      $file = file_load($vars['field_waywire_video'][0]['thumbnail_fid']);
      $vars['video_thumbnail'] = file_create_url($file->uri);
      $vars['embed_url'] = $vars['field_waywire_video'][0]['video_url'];
    }

    if(isset($vars['field_deckhead'][0]['value'])) {
      $vars['deckhead'] = strip_tags($vars['field_deckhead'][0]['value']);
    }
  }

	// *** 360 Gallery
  if($vars['type'] == '360_package_spin_rotate') {
	  $three_sixty_gallery = TRUE;
	}
	else {
		$three_sixty_gallery = FALSE;
	}

  // *** Author
  $google_authors = array(
    'Renee Bassett' => 'https://plus.google.com/116343574983779541134/posts?rel=author',
    'Renee Robbins Bassett' => 'https://plus.google.com/116343574983779541134/posts?rel=author',
    'Renee R. Bassett' => 'https://plus.google.com/116343574983779541134/posts?rel=author',
    'Renee R Bassett' => 'https://plus.google.com/116343574983779541134/posts?rel=author',
    'David Greenfield' => 'https://plus.google.com/102198816954209678196/posts?rel=author',
    'Jim Butschli' => 'https://plus.google.com/110264771670135407685/posts?rel=author',
    'Anne Marie Mohan' => 'https://plus.google.com/116256092123665809543/posts?rel=author',
    'Aaron Hand' => 'https://plus.google.com/113031841111343220909/posts?rel=author',
    'Pat Reynolds' => 'https://plus.google.com/u/0/111294908650262265839/posts?rel=author',
    'Jim Chrzan' => 'https://plus.google.com/u/0/108463377751733582372/posts?rel=author',
  );
  if(isset($vars['field_byline']['und'][0]['safe_value'])) {
    if($vars['field_byline']['und'][0]['safe_value'] != ''){
      $byline = trim($vars['field_byline']['und'][0]['safe_value']);
      // look for one of $google_authors' names in $byline and make it a link to the corresponding google author profile
      foreach ($google_authors as $name => $google_profile) {
        $x = stripos($byline, $name);
        if ($x !== FALSE) {
          $byline = substr_replace($byline, l($name, $google_profile), $x, strlen($name));
        }
      }
      $vars['author'] = $byline;
    }
  }
  if(isset($vars['field_author_title']['und'][0]['value'])) {
    if($vars['field_author_title']['und'][0]['value'] != '') {
      $vars['author'] .= ', ' . trim($vars['field_author_title']['und'][0]['value']);
    }
  }
	// @TODO why do some content types have 'und' and some don't
	//  repeating this but need to figure out why there is a different
  if(isset($vars['field_byline'][0]['safe_value'])) {
    if($vars['field_byline'][0]['safe_value'] != ''){
      $vars['author'] = trim($vars['field_byline'][0]['safe_value']);
    }
  }
  if(isset($vars['field_author_title'][0]['value'])) {
    if($vars['field_author_title'][0]['value'] != '') {
      $vars['author'] .= ', ' . trim($vars['field_author_title'][0]['value']);
    }
  }

  // Blog author is only added to non AW authors ($google_authors)
  if($vars['type'] == 'blog') {
    if(isset($vars['field_byline'][0]['safe_value'])) {
      switch($vars['field_byline'][0]['safe_value']) {
        case 'Luigi De Bernardini':
          $vars['blog_author'] = l('Luigi De Bernardini', 'https://plus.google.com/108311784947327529744?rel=author');
          break;
        default:
          $vars['blog_author'] = $vars['field_byline'][0]['safe_value'];
          break;
      }
    }
  }

	// *** Companies
	if(isset($vars['field_companies'])) {
		$companies = $vars['field_companies'];
	}

  //Go through all the companies in this node
	if(isset($companies[0])) {
		foreach($companies as $company) {
			$node_company = node_load($company['nid']);
		  $term_data = field_view_value('node', $node_company, 'field_term_company_type', $node_company->field_term_company_type['und'][0]);
		  if ($term_data['#title']=='Supplier') {
				if($three_sixty_gallery) {
					//have the link go to the company name instead of our site.  Also add event tracking
					$company_node = node_load($node_company->nid);
          if(isset($company_node->field_link['und'][0]['url'])) {
						$company_link = $node_company->field_link['und'][0]['url'];
						if (!preg_match("~^(?:f|ht)tps?://~i", $company_link)) {
						  $company_link = "http://" . $company_link;
						}
					}
					$supplier[] = l($node_company->title, $company_link, array('attributes' => array('onclick' => "ga('send', 'event', '360 gallery exit click: " . $node_company->title . "', 'Clicked 360 gallery Supplier', '" . $company_node->field_link['und'][0]['url'] . "');", 'target'=>'_blank')));
				}
		    $supplier[] = l($node_company->title,'node/'.$node_company->nid);
				$all_companies = l($node_company->title,'node/'.$node_company->nid);
		  }
		  else if($term_data['#title']=='End user') {
		    $end_user[] = l($node_company->title,'node/'.$node_company->nid);
				$all_companies = l($node_company->title,'node/'.$node_company->nid);
		  }
			else if($term_data['#title']=='Association') {
		    $association[] = l($node_company->title,'node/'.$node_company->nid);
				$all_companies = l($node_company->title,'node/'.$node_company->nid);
		  }
			else if($term_data['#title']=='Consultant') {
		    $association[] = l($node_company->title,'node/'.$node_company->nid);
				$all_companies = l($node_company->title,'node/'.$node_company->nid);
		  }

		}
	}
	//@TODO fix templates to have templates use "all_companies" variable. Promet had logic in every template for this
	if(isset($all_comapnies)) {
		if (isset($company_array)) $company_array = array();
    $vars['all_companies'] = implode(', ',	$company_array);
	}

	//Supplier
	if(isset($supplier)) {
		//If 360 package than only show first company
		if($three_sixty_gallery) {
			$vars['supplier'] = $supplier[0];
		}

	}
	// *** End Companies

	// Make sure that Google doesn't crawl/index any of the comment pages
  $url_components = explode('/', request_uri());
  if ($url_components[1] == 'comment') {
    _aw960_robots_do_not_follow();
    // Show the comments so the anchor works correctly
    drupal_add_js('jQuery(document).ready(function ($) { $(".comments-wrapper").css("display", "block"); });', 'inline');
  }

  // Playbook Comment Form Node
  // look for the query string in the URL
  if($vars['nid'] == '14228'){
    $full_url = 'http://' . $_SERVER['HTTP_HOST'] . $_SERVER['REQUEST_URI'];
    $url_query = parse_url($full_url);
    if(array_key_exists('query', $url_query)){
      $pb_value = substr($url_query['query'], strpos($url_query['query'], '=') + 1);
      $pb_value = str_replace('_', ' ', $pb_value);
      $pb_value = str_replace('-', ' ', $pb_value);
      $pb_value = ucfirst($pb_value);
      $vars['title'] = str_replace('Automation World', $pb_value, $vars['title']);
    }
  }

  /*
  // Factory and Machine Automation Form.  Add JS file
  if($vars['nid'] == '14229') {
    //drupal_add_js("jQuery(window).load(setTimeout(function(){ ewt.trackLink({name:'AW FMA Playbook Page Loaded', type:'playbook-aw_factory_machine_automation'}); }, 5000));", array('type'=>'inline', 'every_page' => 'false'));
    drupal_add_js("jQuery(window).load(function(){ ewt.trackLink({name:'AW FMA Playbook Page Loaded', type:'playbook-aw_factory_machine_automation'}); });", array('type'=>'inline', 'every_page' => 'false', 'group' => JS_LIBRARY));
    drupal_add_js(drupal_get_path('theme', 'aw960') . '/js/playbook.js', 'file');
    //drupal_add_js("ewt.trackLink({name:'AW FAM Playbook Page Loaded',type:'playbook-aw_factory_machine_automation',link:null});", array('type' => 'inline','scope' => 'footer'));
  }
  // Factory and Machine Automation Survey.  Add inline JS
  if($vars['nid'] == '14496') {
    drupal_add_js("jQuery(window).load(setTimeout(function(){ ewt.trackLink({name:'AW FMA Playbook - Survey', type:'playbook-aw_fma_survey'}); }, 5000));", array('type'=>'inline', 'every_page' => 'false'));
  }
  //dpm($args);
  if($args[0] == 'playbooks-mod' && isset($args[1])) {
    // Ticket #2093, adding custom event that fires after user submits the FAM Playbook Form
    // will wrap this in a switch clause so that we can group similar code together in the future
    switch($args[1]){
      case 14229:
        drupal_add_js("jQuery(window).load(function(){ ewt.trackLink({name:'AW FMA Playbook - Thank You Page', type:'playbook-aw_fma_thank-you'}); });", array('type' => 'inline', 'every_page' => 'false'));
    }
  }
  */

  // add Silverpop external JS, for web-tracking
  // drupal_add_js('http://contentz.mkt51.net/lp/static/js/iMAWebCookie.js?5872ae98-13481d0a159-d7c8ec57ae636c7258d3eb0ef0e531f2&h=www.pages05.net', 'external');


  /* Download Content Type */
  if($vars['type'] == 'download'){
    $download_subtype = 'Tactical Brief';
    if(isset($vars['field_download_subtype']['und'])){
      $download_subtype = taxonomy_term_load($vars['field_download_subtype']['und'][0]['tid']);
      $download_subtype = $download_subtype->name;
      $vars['download_subtype'] = $download_subtype;
    }
    if(isset($vars['field_download_document'][0]['fid'])){
      $classes = 'download-document-button';
      if(isset($vars['field_pop_up_registration']['und'][0]['value'])){
        $fc_item_id = $vars['field_pop_up_registration']['und'][0]['value'];
        $fc_array = entity_load('field_collection_item', array($fc_item_id));
        $fc = $fc_array[$fc_item_id];
        $ad_id = (isset($fc->field_smg_pop_ad_id['und'])) ? $fc->field_smg_pop_ad_id['und'][0]['value'] : 1;
        $classes .= ' purf-ad-' . $ad_id . ' purf-unique-dwnpf';
      }
      $file_url = file_create_url($vars['field_download_document'][0]['uri']);
      $doc_download_btn = '<a class="' . $classes . '" href="' . $file_url . '">Download ' . $download_subtype . '</a>';
      $vars['doc_download_btn'] = $doc_download_btn;
    }
  }

  /* Whitepaper Content Type */
  if ($vars['type'] == 'whitepaper') {
    if (isset($vars['field_whitepaper'][0]['fid'])) {
      $classes = 'blue-button2';
      if (!empty($vars['field_pop_up_registration'])) {
        $fc_item_id = $vars['field_pop_up_registration']['und'][0]['value'];
        $fc_array = entity_load('field_collection_item', array($fc_item_id));
        $fc = $fc_array[$fc_item_id];
        $ad_id = (isset($fc->field_smg_pop_ad_id['und'])) ? $fc->field_smg_pop_ad_id['und'][0]['value'] : 1;
        $classes .= ' purf-ad-' . $ad_id . ' purf-unique-dwnpf';
      }
      $file_url = file_create_url($vars['field_whitepaper'][0]['uri']);
      $doc_download_btn = '<a class="' . $classes . '" href="' . $file_url . '">Download White Paper</a>';
      $vars['doc_download_btn'] = $doc_download_btn;
    }
  }

  if ($vars['type'] == 'apps'){
    // Go through each of the platforms that were set and create the image link.
    // Set the image of each taxonomy term.
    // @TODO Move this to a configuration page.
    $app_platforem_taxonomy_tids = array(
      2820 => array('image' => 'android_small.png'), // Android
      2818 => array('image' => 'ios_small.png'), // IOS
      2817 => array('image' => 'mac_small.png'), // MAC
      2819 => array('image' => 'web_small.png'), // Web Browser
      2821 => array('image' => 'windows_small.png'), // Windows
    );
    $count = 1;
    $vars['platform'] = '';

    if ($vars['field_platforms_os']) {
      // Go through the field collections and get tid and url.
      $items = entity_load('field_collection_item', $vars['field_platforms_os']);
      foreach ($items as $key => $platform) {
        if (isset($platform->field_app_platforms_os['und'][0]['tid']) && isset($platform->field_app_platform_os_url['und'][0]['url'])) {
          $tid = $platform->field_app_platforms_os['und'][0]['tid'];
          $taxonomy = taxonomy_term_load($tid);
          $image_url = isset($app_platforem_taxonomy_tids[$tid]) ? drupal_get_path('theme', 'aw960') . '/css/images/' . $app_platforem_taxonomy_tids[$tid]['image'] : '';

          // Set up into left and right div wrappers.
          if ($count == 1) {
            $vars['platform'] .= '<div class="apps-platforms-left">';
          }
          if ($count == 4) {
            $vars['platform'] .= '<div class="apps-platforms-right">';
          }

          $vars['platform'] .= '<div class="apps-platform-wrapper">';
          $vars['platform'] .= '<a href="' . $platform->field_app_platform_os_url['und'][0]['url'] . '" target="_blank"><img src="/' . $image_url . '" />';
          $vars['platform'] .= '<span class="apps-platform-name">' . $taxonomy->name . '</span>';
          $vars['platform'] .= '</a>';
          $vars['platform'] .= '</div>';

          // Close left and right div wrappers.
          if ($count == 3 || $count == count($items)) {
            $vars['platform'] .= '</div>';
          }
        }

        $count++;
      }
    }

  }

  // #23 Leadership Online Profile
  if($vars['type'] == 'leadership_online_profile'){
    _preprocess_leadership_online_profile($vars);
  }

  // #137 Company LIA
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
        $taxonomy_field_names = array('field_ld_categories_technologies', 'field_ld_categories_topics');
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
        $online_prof_wrapper = entity_metadata_wrapper('node', $online_prof_node);
        if ($online_prof_node->status == 1) {
          $vars['is_published_print_profile'] = TRUE;
          $vars['online_profile_node'] = $online_prof_node;
          $theme_path = '/' . drupal_get_path('theme', 'aw960');
          $css_path = $theme_path . '/css/images/';

          if (!empty($online_prof_node->field_ld_facebook)) {
            $facebook_link = $online_prof_wrapper->field_ld_facebook->value();
            $vars['profile_facebook'] = '<a onclick="ga(\'send\',\'event\',\'Leadership action\',\'Facebook click\',\'' . $vars['title'] . '\');" href="' . aw960_httpify($facebook_link['url']) . '" target="_blank"><img src="' . $css_path . 'FB-f-Logo__blue_20.png" /></a>';
          }

          if (!empty($online_prof_node->field_ld_linkedin)) {
            $linkedin_link = $online_prof_wrapper->field_ld_linkedin->value();
            $vars['profile_linkedin'] = '<a onclick="ga(\'send\',\'event\',\'Leadership action\',\'LinkedIn click\',\'' . $vars['title'] . '\');" href="' . aw960_httpify($linkedin_link['url']) . '" target="_blank"><img src="' . $css_path . 'ln-20.png" /></a>';
          }

          if (!empty($online_prof_node->field_ld_google_plus)) {
            $google_link = $online_prof_wrapper->field_ld_google_plus->value();
            $vars['profile_google_plus'] = '<a onclick="ga(\'send\',\'event\',\'Leadership action\',\'Google+ click\',\'' . $vars['title'] . '\');" href="' . aw960_httpify($google_link['url']) . '" target="_blank"><img src="' . $css_path . 'google_plus_20.jpg" /></a>';
          }

          if (!empty($online_prof_node->field_ld_twitter)) {
            $twitter_link = $online_prof_wrapper->field_ld_twitter->value();
            $vars['profile_twitter'] = '<a onclick="ga(\'send\',\'event\',\'Leadership action\',\'Twitter click\',\'' . $vars['title'] . '\');" href="' . aw960_httpify($twitter_link['url']) . '" target="_blank"><img src="' . $css_path . 'twitter2013.png" /></a>';
          }

          if (!empty($online_prof_node->field_ld_youtube)) {
            $youtube_link = $online_prof_wrapper->field_ld_youtube->value();
            $vars['profile_youtube'] = '<a onclick="ga(\'send\',\'event\',\'Leadership action\',\'Youtube click\',\'' . $vars['title'] . '\');" href="' . aw960_httpify($youtube_link['url']) . '" target="_blank"><img src="' . $css_path . 'youtube_20.png" /></a>';
          }

          if (!empty($online_prof_node->field_ld_pinterest)) {
            $pinterest_link = $online_prof_wrapper->field_ld_pinterest->value();
            $vars['profile_pinterest'] = '<a onclick="ga(\'send\',\'event\',\'Leadership action\',\'Pinterest click\',\'' . $vars['title'] . '\');" href="' . aw960_httpify($pinterest_link['url']) . '" target="_blank"><img src="' . $css_path . 'pinterest_20.png" /></a>';
          }

        }

        // Add waywire videos
        $waywire_videos = waywire_leadership_get_company_all_videos($vars['nid']);
        if ($waywire_videos) {
          $vars['video_grid'] = TRUE;
          drupal_add_js(array('smgVideoGrid' => $waywire_videos), 'setting');
          $video_widget_path = drupal_get_path('module', 'video_widget');
          drupal_add_js($video_widget_path . '/video_widget_includes/js/lightbox.js');
          drupal_add_js($video_widget_path . '/video_widget_includes/angular/videoGrid.js');
          drupal_add_css($video_widget_path . '/video_widget_includes/css/video_grid.css', array('preprocess'=>TRUE, 'every_page'=>FALSE));
        }
      }
    }
  }
  if ($vars['nid'] == '17506') {
    drupal_add_css(drupal_get_path('theme','aw960') . '/css/preferences.css');
  }
}

/**
 * Theme function for preprocessing all RSS rows.
 */
function aw960_preprocess_views_view_row_rss(&$vars) {
  $view = &$vars['view'];
  $options = &$vars['options'];
  $item = &$vars['row'];

  // Use the [id] of the returned results to determine the nid in [results]
  $result = &$vars['view']->result;
  $id = &$vars['id'];
  $node = node_load( $result[$id-1]->nid );

  $vars['node'] = $node;
  $vars['title'] = _aw960_processCRLF(check_plain($item->title));
  $vars['link'] = check_url($item->link);

  if(isset($node->body['und'][0]['value'])) {
    $vars['body'] = $node->body['und'][0]['value'];
  }
  else {
    $vars['body'] = '';
  }
  if(isset($node->field_deckhead['und'][0]['value'])) {
    $vars['description'] = $node->field_deckhead['und'][0]['value'];
    //creating separate description because the ipad version has to have & characters etc.. and the main feed can't
    $vars['descriptionipad'] = $vars['description'];
  }
  else {
    $vars['description'] = '';
    $vars['descriptionipad'] = '';
  }
  //capitalizing first letter of each word to match Joomla
  $vars['content_type'] = ucwords($node->type);
  if(isset($node->field_byline['und'][0]['value'])) {
    $vars['author_name'] = check_plain($node->field_byline['und'][0]['value']);
  }
  else {
    $vars['author_name'] = '';
  }
  if(isset($node->field_author_title['und'][0]['value'])) {
    $vars['author_title'] = check_plain($node->field_author_title['und'][0]['value']);
  }
  else {
    $vars['author_title'] = '';
  }
  $vars['date'] = date('F j, Y',$node->created);

  //$vars['item_elements'] = empty($item->elements) ? '' : format_xml_elements($item->elements);
}

/**
 * Theme function for processing all RSS rows.
 */
function aw960_process_views_view_row_rss(&$vars) {

  $description = $vars['descriptionipad'];
  $body = $vars['body'];

  //Change name of content type to match Joomla name so the app understands
  if($vars['content_type'] == 'Whitepaper') {
    $vars['content_type'] = 'White Paper';
  }

  //Perform the same functions like in Joomla to clean up the text - Remove bad characters
  _aw960_processCRLF($description);
  html_entity_decode($description);
  _aw960_StripSmartQuotes($description);
  trim($description);

  _aw960_processCRLF($body);
  html_entity_decode($body);
  _aw960_StripSmartQuotes($body);
  trim($body);

  //adding the author and title together
  if(!empty($vars['author_name'])) {
    $vars['author_name_title'] = $vars['author_name'] . ', ' . $vars['author_title'];
  }
  else {
    $vars['author_name_title'] = '';
  }

  //If Video set up link so the video works on the ipad
  if($vars['content_type'] == 'Video') {
    if(isset($vars['node']->field_viddler_id['und'][0]['value'])) {
      $vars['content_media'] = 'http://www.viddler.com/file/' . $vars['node']->field_viddler_id['und'][0]['value'] . '/html5';
    }
    else {
      $vars['content_media'] = '';
    }
    if(isset($vars['node']->field_viddler_id['und'][0]['value'])) {
      $vars['image_thumbnail'] = 'http://cdn-thumbs.viddler.com/thumbnail_2_' . $vars['node']->field_viddler_id['und'][0]['value'] . '_v1.jpg';
    }
    else {
      $vars['image_thumbnail'] = '';
    }
    //Sponsor News has a case that a video is stored on the customer site.
    if(isset($vars['node']->field_white_paper['und'][0]['url'])) {
	    $vars['content_media'] = $vars['node']->field_white_paper['und'][0]['url'];
	    //Use the image from the node since we are not using Viddler
	    if(isset($vars['node']->field_image['und'][0]['uri'])) {
		    $vars['image_thumbnail'] = image_style_url('thumbnail', $vars['node']->field_image['und'][0]['uri']);
		  }
	  }
  }
  //if White Paper content_media needs to be the link to the white paper
  elseif($vars['content_type'] == 'White Paper') {
	  if(isset($vars['node']->field_white_paper['und'][0]['url'])) {
      $vars['content_media'] = $vars['node']->field_white_paper['und'][0]['url'];
  	  $vars['image_thumbnail'] = '';
    }
    else {
	    $vars['content_media'] = '';
	    $vars['image_thumbnail'] = '';
    }
  }
  elseif(!empty($vars['node']->field_image['und'][0]['uri'])) {
  	$vars['content_media'] = file_create_url($vars['node']->field_image['und'][0]['uri']);
  	$vars['image_thumbnail'] = image_style_url('thumbnail', $vars['node']->field_image['und'][0]['uri']);
  }
  else {
    $vars['content_media'] = '';
    $vars['image_thumbnail'] = '';
  }

  //Get company info
  if(isset($vars['node']->field_companies['und'][0]['nid'])) {
    $company = node_load($vars['node']->field_companies['und'][0]['nid']);
    $vars['companyName'] = check_plain($company->title);
    if(isset($company->field_link['und'][0]['url'])) {
      $vars['companyUrl'] = $company->field_link['und'][0]['url'];
    }
    else {
	    $vars['companyUrl'] = '';
    }
  }
  else {
    $vars['companyName'] = '';
    $vars['companyUrl'] = '';
  }

  $vars['description'] =  check_plain($vars['description']);
  $vars['descriptionipad'] = $description;
  $vars['body'] = $body;

}

/**
 * See Trac 855 comments 131-135.
 * Articles have a varying number of CRLF pairs that are causing problems
 * 1. Remove all CR/LFs througout the article
 * 2. Replace <br/> and <p> and tags with temporary tag, say {LINEBREAK}
 * 3. Strip all HTML tags from the article. At this point there is no HTML or CR/LF pairs.
 * 4. Replace all contiguous #LINEBREAK# tags with a single CR/LF to create a single newline.
 */
function _aw960_processCRLF(&$text) {
  $text = preg_replace('/\x0D/', '', $text);
  $text = preg_replace('/\x0A/', '', $text);
  $text = str_replace( '<br>', '@LINEBREAK@', $text );
  $text = str_replace( '<br/>', '@LINEBREAK@', $text );
  $text = str_replace( '<br />', '@LINEBREAK@', $text );
  $text = str_replace( '</p>', '@LINEBREAK@', $text );
  $text = str_replace( '<p>', '', $text );
  $text = str_replace( '</li>', '@LINEBREAK@', $text );

  //Remove extra white spaces
  $text = preg_replace( '/\s{2,}/', '', $text);
  $text = preg_replace( "'<script[^>]*>.*?</script>'si", '', $text );
  $text = preg_replace( '/<a\s+.*?href="([^"]+)"[^>]*>([^<]+)<\/a>/is', '\2 (\1)', $text );
  $text = preg_replace( '/<!--.+?-->/', '', $text );
  $text = preg_replace( '/{.+?}/', '', $text );
  $text = preg_replace( '/&nbsp;/', ' ', $text );
  $text = preg_replace( '/&amp;/', ' ', $text );
  $text = preg_replace( '/&quot;/', '"', $text );
  $text = preg_replace( '/&#039;/', "'", $text );
  $text = preg_replace( '/&#9472;/', '--', $text );
  $text = preg_replace( '/&mdash;/', '--', $text );
  $text = preg_replace( '/&#8232;/', '', $text );
  $text = preg_replace( '/&ldquo;/', '"', $text );
  $text = preg_replace( '/&rdquo;/', '"', $text );
  $text = preg_replace( '/&#39;/', "'", $text );
  $text = preg_replace( '/&reg;/', '', $text );
  $text = preg_replace( '/&rsquo;/', "'", $text );
  $text = preg_replace( '/&hellip;/', "...", $text );
  $text = preg_replace( '/&#65533;/', "...", $text );
  //Had to remove the bulletpoint because it was causing the feed to fail.  Not sure how it allwows it in PW.
  //$text = preg_replace( '/&bull;/', "", $text );
  $text = preg_replace( '/&bull;/', "-", $text );
  $text = str_replace( '<li>', "- ", $text);
  $text = strip_tags( $text );
  $text = preg_replace( '/@LINEBREAK@\s/', '@LINEBREAK@', $text);
  $text = preg_replace( '/@LINEBREAK@@LINEBREAK@\s{2,}/', '@LINEBREAK@@LINEBREAK@', $text);
  //$text = htmlspecialchars( $text );

  while (strpos($text, '@LINEBREAK@@LINEBREAK@') !== false) {
    $text = str_replace( '@LINEBREAK@@LINEBREAK@', '@LINEBREAK@', $text );
  }
  $text = preg_replace( '([@]LINEBREAK[@])', "\n", $text );

  return $text;
}


/**
 *
 * This function pulled from the Joomla 1.5 plugin 'Strip Smart Quotes'
 * by Mango, http://www.toao.net/
 * Download here: http://www.toao.net/?s=StripSmartQuotes
 * Description: Joomla! plugin for removing smart/curly quotes, em-dashes and ellipses.
 *
 */
function _aw960_StripSmartQuotes($text) {
  // First, we replace any UTF-8 characters that exist.
  $text = str_replace(
  array("\xe2\x80\x98", "\xe2\x80\x99", "\xe2\x80\x9c", "\xe2\x80\x9d", "\xe2\x80\x93", "\xe2\x80\x94"),
  array("'", "'", '"', '"', '-', '--'),
  $text);
  // Next, their Windows-1252 equivalents.  These shouldn't be here as Joomla uses UTF-8, but I'm including this just in case.
  // NOTE by M29 - Joomla 1.5 uses UTF-8; Joomla 1.0 uses ISO-8859-1;
  $text = str_replace(
  array(chr(145), chr(146), chr(147), chr(148), chr(150), chr(151)),
  array("'", "'", '"', '"', '-', '--'),
  $text);
  return $text;
}



/*
* disclaimer funtions, used by node templates
* based on http://dev.summitpublish.com/wiki/projects/pw/2010/reqs/article_functionality#a4.3-Disclaimers
*/

function pw960_disclaimer3_marker($source_type){
  // used as a marker in views see aw_page_alteration.module and node templates
  //field_term_source_type
  $custom_content = 139;
  $lead_gen_campaign = 141;
  $supplier_submitted = 140;
  if((!empty($source_type)) && (($source_type==$custom_content)||($source_type==$lead_gen_campaign)||($source_type==$supplier_submitted))){
      return '<span style="display:none;">[CustomContent/LeadGenCampaign/SupplierSubmitted]</span>';
  }
  else {
    return '';
  }
}

//headline star
function pw960_headline_star($source_type, $coverage_type = ''){
	//Per Gran't request removing stars from opc and manufacturing intelligence
	$tids = array(143, 142);
	if(in_array($coverage_type, $tids)) {
		return '';
	}

  //field_term_source_type
  $custom_content = 139;
  $lead_gen_campaign = 141;
  $supplier_submitted = 140;
  if((!empty($source_type)) && (($source_type==$custom_content)||($source_type==$lead_gen_campaign)||($source_type==$supplier_submitted))){
    return '<img style="width:auto !important; border:0 !important; float:none !important;" src = "/sites/default/themes/aw960/css/images/star2.png" >';
  }
  else {
    return '';
  }
}

//disclaimer 2
function pw960_long_disclaimer($source_type){
  //field_term_source_type
  $custom_content = 139;
  $lead_gen_campaign = 141;
  $supplier_submitted = 140;
  if((!empty($source_type)) && ($source_type==$lead_gen_campaign)){
   return '<div class="long-disclaimer"><img style="width:auto !important;" src="/sites/default/themes/aw960/css/images/star.png">This content is sponsored by the supplier. Your contact information may be shared with this sponsor, as detailed in our <a href="/node/9230" target="_blank">Privacy Policy</a>. Your contact information will not shared with a sponsor whose content you have not reviewed.</div>';
  }
  else {
    return '';
  }
}

//disclaimer 1
function pw960_short_disclaimer($source_type){
  //field_term_source_type
  $custom_content = 139;
  $lead_gen_campaign = 141;
  $supplier_submitted = 140;
  if((!empty($source_type)) && (($source_type==$custom_content)||($source_type==$lead_gen_campaign)||($source_type==$supplier_submitted))){
    return '<div class="short-disclaimer">This content was submitted directly to this Web site by the supplier.</div>';
  }
  else {
    return '';
  }
}

/*
 This function is never used; see the corresponding template file instead.
*/
function aw960_preprocess_search_result(&$var) {

  //dsm($var);
  $var['info_split']['date'] = $var['result']['node']->created;
  return $var;
}

/* this will add the custom meta description
* called on node templates
*/
function aw960_add_meta_description($node_type,$content){
  switch($node_type){
    case 'article':
    case 'blog':
    case 'video':
    case 'podcast':
    case 'webcast':
    case 'whitepaper':
          $meta_description = array(
                    '#type' => 'html_tag',
                    '#tag' => 'meta',
                    '#attributes' => array(
                        'name' => 'description',
                        'content' =>  $content
                    )
                  );
          drupal_add_html_head( $meta_description, 'meta_description' );
    break;
  }
 }

/**
 * loads all comments submitted on node no. $nid
 */
// function aw960_load_comments_by_nid($nid) {
  // $query = db_select('comment', 'comment');
  // $query->condition('nid', $nid);
  // $query->fields('comment', array('cid', 'created'));
  // $query->orderBy('created', 'DESC');
  // $result = array();
  // foreach ($query->execute() as $row) {
    // $result[] = $row->cid;
  // }
  // return $result;
// }

/**
 * takes field_allterms and returns an array of themed links to the 3 most specific terms
 */
function aw960_parse_allterms($allterms, $limit = 0, $exclude_vids = array()) {
  $ret = array();

  // fill $min_children with an array of the terms with fewest children (most specific) in each taxonomy group
  $min_children = array();
  foreach ($allterms as $id => $term) {
    if (in_array($term['vid'], $exclude_vids))
      continue;
    $this_children = count(taxonomy_get_children($term['tid'], $term['vid']));
    if (! array_key_exists($term['group'], $min_children) || $this_children < $min_children[$term['group']]['count']) {
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
  } else {
    return $ret;
  }
}

/**
 * returns a rendered block
 * @param $module: the name of the module that defines the block
 * @param $delta: the block delta
 * @return string containing rendered block
 */
function aw960_render_block($module, $delta){
  $block = block_load($module, $delta);
  $block_content = _block_render_blocks(array($block));
  $build = _block_get_renderable_array($block_content);
  return drupal_render($build);
}

/**
 * performs various modifications to the main menu to assist with styling
 */
function aw960_main_menu_style(&$menu_tree) {
  if($menu_tree) {
    foreach (element_children($menu_tree) as $item) {
      $menu_tree[$item]['#attributes']['class'][] = 'top-level';

      switch ($menu_tree[$item]['#title']) {
        case 'Home':
          $menu_tree[$item]['#title'] = '';
          $menu_tree[$item]['#attributes']['class'][] = 'div-small';
          $menu_tree[$item]['#attributes']['class'][] = 'home';
          break;
        case 'Topics':
        case 'Factory Automation':
        case 'Engineering':
        case 'Operations':
          $menu_tree[$item]['#attributes']['class'][] = 'div-small';
          break;
        case 'Products':
        case 'Process Automation':
          $menu_tree[$item]['#attributes']['class'][] = 'div-large';
          break;
      }

      foreach (element_children($menu_tree[$item]['#below']) as $subitem) {
        if ($menu_tree[$item]['#below'][$subitem]['#href'] == implode(arg(), '/'))
          $menu_tree[$item]['#below'][$subitem]['#attributes']['class'][] = 'current-page';
      }
    }
  }
}

/**
 * attempts to insert the contents of $what as near as possible to $where characters in $html, without splitting an html node
 *
 * @param $what string to insert
 * @param $where int. Char position at which to insert $what
 * @param $html string in which to insert $what
 *
 * @return TRUE if successful, FALSE otherwise
 */
function aw960_dom_insert($what, $where, &$html) {
  preg_match_all("/<(?:p|div)[^>]*>/", $html, $matches, PREG_PATTERN_ORDER | PREG_OFFSET_CAPTURE);
  $closest = null;
  foreach ($matches[0] as $match) {
    $dist = abs($match[1] - $where);
    if ($closest == null || $dist < $closest[1]) {
      $closest = array($match[1], $dist);
    }
  }
  if ($closest) {
    $html = substr($html, 0, $closest[0]) . $what . substr($html, $closest[0]);
    return TRUE;
  } else {
    return FALSE;
  }
}

/**
 * theme pullquotes for blog posts
 * this adds big opening and closing quotation marks to the text
 */
function aw960_field__field_pull_quote__blog($variables) {
  $output = '';
  $opening_quote = theme('image', array(
    'path' => '/sites/default/themes/aw960/css/images/pull-quote-opening-quote.png',
    'attributes' => array(
      'class' => array('opening-quote'),
    ),
  ));
  $closing_quote = theme('image', array(
    'path' => '/sites/default/themes/aw960/css/images/pull-quote-closing-quote.png',
    'attributes' => array(
      'class' => array('closing-quote'),
    ),
  ));

  // Render the label, if it's not hidden.
  if (!$variables['label_hidden']) {
    $output .= '<div class="field-label"' . $variables['title_attributes'] . '>' . $variables['label'] . ':&nbsp;</div>';
  }

  // Render the items.
  $output .= '<div class="field-items"' . $variables['content_attributes'] . '>';
  foreach ($variables['items'] as $delta => $item) {
    $classes = 'field-item ' . ($delta % 2 ? 'odd' : 'even');
    $output .= '<div class="pullquote"><div class="opening-quote">' . $opening_quote . '</div><div class="' . $classes . '"' . $variables['item_attributes'][$delta] . '>' . drupal_render($item) . $closing_quote . '</div></div>';
  }
  $output .= '</div>';

  // Render the top-level DIV.
  $output = '<div class="' . $variables['classes'] . '"' . $variables['attributes'] . '>' . $output . '</div>';

  return $output;
}

/**
 * Adds the onclick string used for Google Analytics Events
 *  Example: ga('send', 'event', 'Navigation', 'Main', 'Package Design');
 *
 * @param $event_category
 * @param $event_action
 * @param $event_label
 *
 * @return $google_event
 *  string containing all the event info
 */
function _aw960_google_event_onlick_event($event_category, $event_action = null, $event_label = null) {

  if($event_action && $event_label) {
    $google_event = "ga('send', 'event', '$event_category', '$event_action', '$event_label');";
  }
  else if($event_action) {
     $google_event = "ga('send', 'event', '$event_category', '$event_action');";
  }

  return $google_event;
}

/**
 * Adds a meta tag to the head so search engines don't
 * crawl and index the page
 */
function _aw960_robots_do_not_follow() {
  $elements = array(
    '#tag' => 'meta',
    '#attributes' => array(
      'name' => 'robots',
      'content' => 'noindex,follow',
    ),
  );
  drupal_add_html_head($elements, 'robots');
}

/**
 * Based on the criteria decide to show or not to show the title from page.tpl.php.
 *
 * @param string $title
 *
 * @param boolean $show
 */
function aw960_show_title($title) {
  $show = TRUE;
  if(empty($title)) {
    return FALSE;
  }
  $args = arg();
  if($args[0] == 'node') {
    $show = FALSE;
  }
  if(isset($args[2])) {
    switch($args[2]) {
      case 'videos':
      case 'featured':
      case 'products':
      case 'news':
       $show = FALSE;
    }
  }

  return $show;
}

/**
 * Function for preprocessing Leadership Online Profile nodes.  Called
 * from _preprocess_node
 *
 * @param array $vars The vars array from _preprocess_node
 */
function _preprocess_leadership_online_profile(&$vars) {
  // Add the leadership css file
  //drupal_add_css(drupal_get_path('module','leadership').'/css/leadership.css', array('type'=>'file', 'preprocess'=>TRUE, 'every_page'=>FALSE));
  $site_id = variable_get('smg_global_site');
  $print_profile_node = node_load(leadership_get_corresponding_nid($vars['field_ld_company'][0]['nid'], 'leadership_print_profile', $site_id));

  if(isset($print_profile_node->field_ld_address_1['und'])){
    $vars['address'] = $print_profile_node->field_ld_address_1['und'][0]['value'];
    // If there is an "Address 2", append it to address 1
    if(isset($print_profile_node->field_ld_address_2['und'])){
      $vars['address'] .= '<br/>' . $print_profile_node->field_ld_address_2['und'][0]['value'];
    }
  }
  if(isset($print_profile_node->field_ld_phone['und'])){
    $vars['phone'] = $print_profile_node->field_ld_phone['und'][0]['value'];
  }
  if(isset($print_profile_node->field_ld_country['und'])){
    $vars['country'] = $print_profile_node->field_ld_country['und'][0]['value'];
  }
  if(isset($print_profile_node->field_ld_address_city['und'])){
    $vars['city'] = $print_profile_node->field_ld_address_city['und'][0]['value'];
  }
  if(isset($print_profile_node->field_ld_state['und'])){
    $vars['state'] = $print_profile_node->field_ld_state['und'][0]['value'];
  }
  if(isset($print_profile_node->field_ld_zip_postal_code['und'])){
    $vars['zip'] = $print_profile_node->field_ld_zip_postal_code['und'][0]['value'];
  }
  if(isset($print_profile_node->field_ld_fax['und'])){
    $vars['fax'] = $print_profile_node->field_ld_fax['und'][0]['value'];
  }

  if(isset($vars['node']->field_ld_sales['und'])){
    $sales_values = array();
    foreach($vars['node']->field_ld_sales['und'] as $value){
      $sales_values[] = $value['value'];
    }
    $vars['sales'] = implode(', ', $sales_values);
  }
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
function aw960_httpify($link, $append = 'http://', $allowed = array('http://', 'https://')){
  $link = trim($link);
  $found = false;
  foreach($allowed as $protocol) {
    if(strpos($link, $protocol) !== FALSE) {
      $found = true;
    }
  }

  if($found) {
    return $link;
  }

  return $append.$link;
}

/**
 * Changes the logo's alt and title tags to reflect the brand name.
 *
 * @param $vars
 *   The page variables
 * @return $out
 *   Returns the logo-title div and its contents
 *
 */
function aw960_identity($vars) {
  if (!empty($vars['logo']) || !empty($vars['site_name']) || !empty($vars['site_slogan'])) {
    $out = '<div id="logo-title">';
    if (!empty($vars['logo'])) {
      $out .= '<a href="' . $vars['front_page'] . '" title="' . t('Automation World Home') . '" rel="home" id="logo"><img src="' . $vars['logo'] . '" alt="' . t('Automation World') . '" /></a>';
    }
    if (!empty($vars['site_name']) || !empty($vars['site_slogan'])) {
      $out .= '<div id="name-and-slogan">';
      if (!empty($vars['site_name'])) {
        $out .= '<h1 id="site-name"><a href="' . $vars['front_page'] . '" title="' . t('Home') . '" rel="home">' . $vars['site_name'] . '</a></h1>';
      }
      if (!empty($vars['site_slogan'])) {
        $out .= '<div id="site-slogan">' . $vars['site_slogan'] . '</div>';
      }
      $out .= '</div> <!-- /#name-and-slogan -->';
    }
    $out .= '</div> <!-- /#logo-title -->';
    return $out;
  }
}
