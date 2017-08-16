<?php // this is created to preserved the default formating for basic page content type ?>
<?php $types = node_type_get_types(); //instead of using the machine name, this will fetch the node type names?>
<?php if ($page): ?>
 <?php if (isset($current_session) && isset($is_published_print_profile) && $is_published_print_profile): ?>
  <div class="row leadership awbs-company-lia">
     <div class="leadership-left-section col-xs-12 col-sm-2">
       <?php if (isset($data_card_company_logo)): ?>
        <div class="row">
          <div class="col-xs-12">
           <img class="logo img-responsive center-block" src="<?php print $data_card_company_logo; ?>" />
          </div>
       </div>
       <?php endif; ?>
       <div class="location-info row">
         <?php if (isset($print_location)): ?>
           <div class="col-xs-12 city-state">
             <?php print $print_location; ?>
           </div>
         <?php endif; ?>
         <?php if (isset($print_website_url)): ?>
            <div class="col-xs-12">
             <a onclick="ga('send', 'event', 'Leadership Action - Company', '<?php print $title; ?>', 'Profile Page to Company Website Click');" href="<?php print aw960_httpify($print_website_url); ?>" class="leadership-company-link">Visit Site</a>
           </div>
         <?php endif; ?>
           <div class="col-xs-12 vote-now-button">
            <a href="<?php print $vote_now_url; ?>" target="_blank" class="btn btn-sm awbs-btn">VOTE NOW</a>
          </div>
       </div> <!-- / .location-info -->
     </div> <!-- / .leadership-left-section -->
     <div class="leadership-right-section col-xs-12 col-sm-10">
       <h1 id="leadership-title"><?php print $title; ?></h1>
       <div class="row">
       <div class="contact col-xs-12 col-sm-3">
         <?php if (isset($data_card_contact_image)): ?>
           <img class="exec-photo" src="<?php print $data_card_contact_image; ?>" alt=""/>
         <?php endif; ?>
         <?php if (isset($data_card_contact_info)): ?>
           <div class="contact-info"><?php print $data_card_contact_info; ?></div>
         <?php endif; ?>
         <?php if (isset($data_card_email)): ?>
           <a href="mailto:<?php print $data_card_email; ?>" class="btn btn-sm awbs-btn">CONTACT US</a>
         <?php endif; ?>
       </div> <!-- / .contact -->
       <div class="company-info col-xs-12 col-sm-9">
         <?php if (isset($data_card_product_summary)): ?>
           <div class="product-summary">
             <strong>Product Summary: </strong><em><?php print $data_card_product_summary; ?></em>
           </div> <!-- / .product-summary -->
         <?php endif; ?>
         <?php if (isset($data_card_teaser)): ?>
           <div class="teaser" style="margin-bottom:10px;">
             <?php print $data_card_teaser; ?>
             </br>
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
      </div>
     </div> <!-- / .leadership-right-section -->
   </div> <!-- / .leadership -->

 <?php if (isset($online_profile_node)): ?>
   <?php print drupal_render(node_view($online_profile_node)); ?>
 <?php endif; ?>

<?php else: ?> <!-- non-LIA -->

 <div class="row awbs-company-profile-top">
  <div class="col-xs-3 col-md-3">
   <div class="row">
   <?php // the logo
     $hasimage = '';
     if(isset($node->field_logo['und'])){
       $hasimage = "has-image";
       $image = image_style_url('140x140', $node->field_logo['und'][0]['uri']);
       //print '<img class="logo" src="'. $image .'">';
     }
     if(isset($node->field_logo[0])){
       $hasimage = "has-image";
       $image = image_style_url('135x135', $node->field_logo[0]['uri']);
       //print '<img class="logo" src="'. $image .'">';
     }
     ?>
     <div class="col-xs-12 awbs-company-profile-logo"><img src="<?php print $image; ?>" class="img-responsive"></div>
    </div>
   </div>

   <div class="col-xs-9 col-md-6 col-md-offset-3">
    <div class="row">
   <div class="col-xs-12 awbs-company-profile-name"><?php print $title; ?></div>

   <div class="col-xs-12 awbs-company-profile-address">
   <?php
    if(isset($node->field_address1['und'])){
      $info1 .= $node->field_address1['und'][0]['value'];
    }
    if(isset($node->field_address1[0])){
      $info1 .= $node->field_address1[0]['value'];
    }
    if(isset($node->field_address2['und'])){
      $info1 .= ' ' . $node->field_address2['und'][0]['value'];
    }
    if(isset($node->field_address2[0])){
      $info1 .= ' ' . $node->field_address2[0]['value'];
    }
    print $info1;
    ?>
   </div>
   <div class="col-xs-12 awbs-company-profile-csz">
    <?php
    if(isset($node->field_city['und'])){
      $info2 .= $node->field_city['und'][0]['value'];
    }
    if(isset($node->field_city[0])){
      $info2 .= ' ' . $node->field_city[0]['value'];
    }
    if(isset($node->field_state['und'])){
      $info2 .= ', ' . $node->field_state['und'][0]['value'];
    }
    if(isset($node->field_state[0])){
      $info2 .= ', ' . $node->field_state[0]['value'];
    }
    if(isset($node->field_zipcode['und'])){
      $info2 .= ' ' . $node->field_zipcode['und'][0]['value'];
    }
    if(isset($node->field_zipcode[0])){
      $info2 .= ' ' . $node->field_zipcode[0]['value'];
    }
    print $info2;
    ?>
   </div>
   <div class="col-xs-12 awbs-company-profile-phone-web">
    <?php
    if(isset($node->field_phone['und'])){
      $info3 .= $node->field_phone['und'][0]['value'];
    }
    if(isset($node->field_phone[0])){
      $info3 .= '&nbsp;&nbsp;' . $node->field_phone[0]['value'];
    }
      $info3 .= '&nbsp;&nbsp;' . render($content['field_link']);
    print $info3;
    ?>
   </div>
</div>
</div>
</div>

<div class="row">
 <?php if (isset($online_profile_node)): ?>
   <?php print drupal_render(node_view($online_profile_node)); ?>
 <?php endif; ?>
</div>




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
     print '<video-grid class="row col-xs-12"></video-grid><div class="clearfix"></div>';
   }
   else {
     $block = block_load('views', 'company-block_5');
     $block_content = _block_render_blocks(array($block));
     $build = _block_get_renderable_array($block_content);
     $render = drupal_render($build);
     if($render){
       print '<div class="title-wrapper"><span class="title"><strong>Videos </span> <span class="title2">from ' . $node->title . '</span></strong></div>';
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
       print '<div class="more-links"><a href="/company/' . $alias[1] . '/videos"> See '.$count .' More videos</a></div>';
     }
   }

   //Feature Stories & Case Application Section
 $block = block_load('views', 'company-block_1');
$block_content = _block_render_blocks(array($block));
$build = _block_get_renderable_array($block_content);
$render = drupal_render($build);
   if($render){
     print '<div class="title-wrapper"><span class="title"><strong>Feature Stories and Case Applications </span> <span class="title2">involving ' . $node->title . '</span></strong></div>';
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
     print '<div class="more-links"><a href="/company/' . $alias[1] . '/featured"> See '.$count .' More Feature Stories</a></div>';
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
     print '<div class="more-links"><a href="/company/' . $alias[1] . '/products"> See '.$count .' More Products</a></div>';
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
     print '<div class="more-links"><a href="/company/' . $alias[1] . '/news"> See '.$count .' More News Items</a></div>';
   }

 ?>

<?php endif; ?>
