<?php // this is created to preserved the default formating for basic page content type
?>
<?php $types = node_type_get_types(); //instead of using the machine name, this will fetch the node type names?>
<?php if ($page): ?>
<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?>"<?php print $attributes; ?>>
<div class="content clearfix"<?php print $content_attributes; ?>>

  <?php if (isset($current_session) && isset($is_published_print_profile) && $is_published_print_profile): ?>
   FOO
    <div class="leadership">
      <div class="leadership-left-section">
        <?php if (isset($data_card_company_logo)): ?>
          <img class="logo" src="<?php print $data_card_company_logo; ?>" />
        <?php endif; ?>
        <div class="location-info">
          <?php if (isset($print_location)): ?>
            <div class="city-state">
              <?php print $print_location; ?>
            </div>
          <?php endif; ?>
          <?php if (isset($print_website_url)): ?>
            <a onclick="ga('send', 'event', 'Leadership action', 'Profile Advertiser Web site click', '<?php print $title; ?>');" href="<?php print aw960_httpify($print_website_url); ?>" class="leadership-company-link">Visit Site</a>
          <?php endif; ?>
          <a href="https://www.surveymonkey.com/r/T96Y6MH" target="_blank" class="leadership--company-button">VOTE NOW</a>
        </div> <!-- / .location-info -->
      </div> <!-- / .leadership-left-section -->
      <div class="leadership-right-section">
        <h1 id="leadership-title"><?php print $title; ?></h1>
        <div class="contact">
          <?php if (isset($data_card_contact_image)): ?>
            <img class="exec-photo" src="<?php print $data_card_contact_image; ?>" alt=""/>
          <?php endif; ?>
          <?php if (isset($data_card_contact_info)): ?>
            <div class="contact-info"><?php print $data_card_contact_info; ?></div>
          <?php endif; ?>
          <?php if (isset($data_card_email)): ?>
            <a href="mailto:<?php print $data_card_email; ?>" class="leadership--company-button">CONTACT US</a>
          <?php endif; ?>
        </div> <!-- / .contact -->
        <div class="company-info">
          <?php if (isset($data_card_product_summary)): ?>
            <div class="product-summary">
              <strong>Product Summary: </strong><em><?php print $data_card_product_summary; ?></em>
            </div> <!-- / .product-summary -->
          <?php endif; ?>
          <?php if (isset($data_card_teaser)): ?>
            <div class="teaser">
              <?php print $data_card_teaser; ?>
            </div> <!-- / .teaser -->
          <?php endif; ?>
          <?php if (isset($categories) && $categories): ?>
            <div class="categories">
              <strong>Categories: </strong> <?php print $categories ?>
            </div>
          <?php endif; ?>
          <?php if (isset($online_profile_node)): ?>
            <div id="social-media">
              <?php if (isset($profile_facebook)) print $profile_facebook; ?>
              <?php if (isset($profile_linkedin)) print $profile_linkedin; ?>
              <?php if (isset($profile_google_plus)) print $profile_google_plus; ?>
              <?php if (isset($profile_twitter)) print $profile_twitter; ?>
              <?php if (isset($profile_youtube)) print $profile_youtube; ?>
              <?php if (isset($profile_pinterest)) print $profile_pinterest; ?>
            </div> <!-- / #social-media -->
          <?php endif; ?>
        </div> <!-- / .company-info  -->
      </div> <!-- / .leadership-right-section -->

    </div> <!-- / .leadership -->
  <?php else: ?>
   BAR
      <?php // the logo
        $hasimage = '';
        if(isset($node->field_logo['und'])){
          $hasimage = "has-image";
          $image = image_style_url('140x140', $node->field_logo['und'][0]['uri']);
          print '<img class="logo" src="'. $image .'">';
        }
        if(isset($node->field_logo[0])){
          $hasimage = "has-image";
          $image = image_style_url('135x135', $node->field_logo[0]['uri']);
          print '<img class="logo" src="'. $image .'">';
        }
      ?>

      <div class="company-info">
        <div class="<?php print $hasimage?>" >
          <?php //company info
            print '<h1>' . $title .'</h1>';

            $info = '';

            if(isset($node->field_address1['und'])){
              $info .= $node->field_address1['und'][0]['value'];
            }
            if(isset($node->field_address1[0])){
              $info .= $node->field_address1[0]['value'];
            }
            if(isset($node->field_address2['und'])){
              $info .= ' ' . $node->field_address2['und'][0]['value'];
            }
            if(isset($node->field_address2[0])){
              $info .= ' ' . $node->field_address2[0]['value'];
            }
            if(isset($node->field_city['und'])){
              $info .= '&nbsp;&nbsp;' . $node->field_city['und'][0]['value'];
            }
            if(isset($node->field_city[0])){
              $info .= '&nbsp;&nbsp;' . $node->field_city[0]['value'];
            }
            if(isset($node->field_state['und'])){
              $info .= ', ' . $node->field_state['und'][0]['value'];
            }
            if(isset($node->field_state[0])){
              $info .= ', ' . $node->field_state[0]['value'];
            }
            if(isset($node->field_zipcode['und'])){
              $info .= ' ' . $node->field_zipcode['und'][0]['value'];
            }
            if(isset($node->field_zipcode[0])){
              $info .= ' ' . $node->field_zipcode[0]['value'];
            }
            if(isset($node->field_phone['und'])){
              $info .= '&nbsp;&nbsp;' . $node->field_phone['und'][0]['value'];
            }
            if(isset($node->field_phone[0])){
              $info .= '&nbsp;&nbsp;' . $node->field_phone[0]['value'];
            }

            print '<div class="info">' . $info . '</div>';
            print render($content['field_link']);
          ?>
        </div>
      </div>
  <?php endif; ?>

  <?php if (isset($online_profile_node)): ?>
    <?php print drupal_render(node_view($online_profile_node)); ?>
  <?php endif; ?>

    <?php
      // get node id
      $argument = $node->nid;
      /*
      -----------------------------
      term name         | term id
      -----------------------------
      Case Application  | 267
      Feature article   | 163
      Product           | 166
      News              | 162
      -----------------------------
      */
      //Videos
      if (isset($video_grid)) {
        print '<video-grid></video-grid>';
      }
      else {
        $block = block_load('views', 'company-block_5');
        $block_content = _block_render_blocks(array($block));
        $build = _block_get_renderable_array($block_content);
        $render = drupal_render($build);
        if($render){
          print '<div class="title-wrapper"><span class="title">Videos </span> <span class="title2">from ' . $node->title . '</span></div>';
          print $render;
          $render = '';
        }
        $view = views_get_view('company');
        $view->get_total_rows = true;
        $view->set_display('page_4');
        $view->set_arguments(array($argument));
        $view->execute();
        $count = count( $view->result );
        if($count > 3){
        $count = $count - 3;
        $alias = explode("/",drupal_get_path_alias( 'node/' . arg(1)));
          print '<div class="more-links"><a href="/company/' . $alias[0] . '/videos"> See '.$count .' More videos</a></div>';
        }
      }

      //Feature Stories & Case Application Section
  		$block = block_load('views', 'company-block_1');
			$block_content = _block_render_blocks(array($block));
			$build = _block_get_renderable_array($block_content);
			$render = drupal_render($build);
      if($render){
        print '<div class="title-wrapper"><span class="title">Feature Stories and Case Applications </span> <span class="title2">involving ' . $node->title . '</span></div>';
        print $render;
        $render = '';
      }
      $view = views_get_view('company');
      $view->get_total_rows = true;
      $view->set_display('block_4');
      $view->set_arguments(array('267+163',$argument));
      $view->execute();
      $count = count( $view->result );
      if($count > 3){
      $count = $count - 3;
      $alias = explode("/",drupal_get_path_alias( 'node/' . arg(1)));
        print '<div class="more-links"><a href="/company/' . $alias[0] . '/featured"> See '.$count .' More Feature Stories</a></div>';
      }

      //Products Section
  		$block = block_load('views', 'company-block_2');
			$block_content = _block_render_blocks(array($block));
			$build = _block_get_renderable_array($block_content);
			$render = drupal_render($build);
      if($render){
        print '<div class="title-wrapper"><span class="title">Products </span> <span class="title2">from ' . $node->title . '</span></div>';
        print $render;
        $render = '';
      }
      $view = views_get_view('company');
      $view->get_total_rows = true;
      $view->set_display('block_4');
      $view->set_arguments(array(166,$argument));
      $view->execute();
      $count = count( $view->result );
      if($count > 8){
      $count = $count - 8;
      $alias = explode("/",drupal_get_path_alias( 'node/' . arg(1)));
        print '<div class="more-links"><a href="/company/' . $alias[0] . '/products"> See '.$count .' More Products</a></div>';
      }

      //News Section
  		$block = block_load('views', 'company-block_3');
			$block_content = _block_render_blocks(array($block));
			$build = _block_get_renderable_array($block_content);
			$render = drupal_render($build);
      if($render){
        print '<div class="title-wrapper"><span class="title">News </span> <span class="title2">from ' . $node->title . '</span></div>';
        print $render;
        $render = '';
      }
      $view = views_get_view('company');
      $view->get_total_rows = true;
      $view->set_display('block_4');
      $view->set_arguments(array(162,$argument));
      $view->execute();
      $count = count( $view->result );
      if($count > 8){
      $count = $count - 8;
      $alias = explode("/",drupal_get_path_alias( 'node/' . arg(1)));
        print '<div class="more-links"><a href="/company/' . $alias[0] . '/news"> See '.$count .' More News Items</a></div>';
      }

    ?>
</div>
</div>
<?php endif; ?>
