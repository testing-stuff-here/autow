<?php

  //$blog_beat contains links to the blog beat and blog beat rss feed
  if (isset($node->field_allterms['und'])) {
    $limited_terms = aw960_parse_allterms($node->field_allterms['und'], 3, array('3', '11'));
    foreach ($node->field_allterms['und'] as $term) {
      switch ($term['tid']) {
        case '1876':
          $blog_beat = '<span><a href="/factory-automation-desk">Factory Automation Desk</a></span> <span><a href="/factory-automation-desk.rss"><img src="/sites/default/themes/aw960/css/images/icon_rss_bigger.png"></a></span>';
          break;
        case '1879':
          $blog_beat = '<span><a href="/batch-processing-desk">Batch Processing Desk</a></span> <span><a href="/batch-processing-desk.rss"><img src="/sites/default/themes/aw960/css/images/icon_rss_bigger.png"></a></span>';
          break;
        case '2195':
          $blog_beat = '<span><a href="/process-automation-desk">Process Automation Desk</a></span> <span><a href="/process-automation-desk.rss"><img src="/sites/default/themes/aw960/css/images/icon_rss_bigger.png"></a></span>';
          break;
        case '911':
          $blog_beat = '<span><a href="/packaging-automation-desk">Packaging Automation Desk</a></span> <span><a href="/packaging-automation-desk.rss"><img src="/sites/default/themes/aw960/css/images/icon_rss_bigger.png"></a></span>';
          break;
        case '1877':
          $blog_beat = '<span><a href="/nextgen-infrastructure-desk">NextGen Infrastructure Desk</a></span> <span><a href="/nextgen-infrastructure-desk.rss"><img src="/sites/default/themes/aw960/css/images/icon_rss_bigger.png"></a></span>';
          break;
      }
    }
  }

  //this sets author info to $author_photo, $author_twitter and $author_bio
  if (isset($node->uid) && ($account = user_load($node->uid))) {
    $author_name = $account->name;
    switch ($author_name) {
      case 'Dave Greenfield':
        $author_link = l($author_name, 'https://plus.google.com/102198816954209678196/posts?rel=author');
        $author_photo = '/sites/default/themes/aw960/css/images/greenfield_small.jpg';
        $author_twitter = 'DJGreenfield';
        $author_bio = aw960_render_block('personality', 'greenfield_bio');
        break;
      case 'Renee Robbins Bassett':
        $author_link = l($author_name, 'https://plus.google.com/116343574983779541134/posts?rel=author');
        $author_photo = '/sites/default/themes/aw960/css/images/bassett_66.jpg';
        $author_twitter = 'AutoM8now';
        $author_bio = aw960_render_block('personality', 'bassett_bio');
        break;
      case 'Aaron Hand':
        $author_link = l($author_name, 'https://plus.google.com/113031841111343220909/posts?rel=author');
        $author_photo = '/sites/default/themes/aw960/css/images/aaron_small.jpg';
        $author_twitter = 'AaronHand';
        $author_bio = aw960_render_block('personality', 'hand_bio');
        break;
      case 'Grant Gerke':
        $author_link = l($author_name, 'mailto:ggerke@automationworld.com');
        $author_photo = '/sites/default/themes/aw960/css/images/gerke_66.jpg';
        $author_twitter = 'AutoGrant';
        $author_bio = aw960_render_block('personality', 'gerke_bio');
        break;
      case 'Gary Mintchell':
        $author_link = l($author_name, 'mailto:gmintchell@automationworld.com');
        $author_photo = '/sites/default/themes/aw960/css/images/mintchell_66.jpg';
        $author_twitter = 'garymintchell';
        $author_bio = aw960_render_block('personality', 'mintchell_bio');
        break;
      case 'Pat Reynolds':
        $author_link = l($author_name, 'https://plus.google.com/u/0/111294908650262265839/posts?rel=author');
        $author_photo = '/sites/default/themes/aw960/css/images/reynolds_66.jpg';
        $author_twitter = 'Packcentric';
        $author_bio = aw960_render_block('personality', 'reynolds_bio');
        break;
      case 'Keith Campbell':
        $author_link = $author_name;
        $author_photo = '/sites/default/themes/aw960/css/images/Campbell_2.jpg';
        $author_twitter = '';
        $author_bio = aw960_render_block('personality', 'campbell');
        break;
      case 'Stephanie Neil':
        $author_link = $author_name;
        $author_photo = '/sites/default/themes/aw960/css/images/neil_small.jpg';
        $author_twitter = 'neilst';
        $author_bio = aw960_render_block('personality', 'stephanie_bio');
        break;
    }
    $author_photo = isset($author_photo) ? array(
      '#theme' => 'image',
      '#path' => $author_photo,
      '#width' => '66',
      '#height' => '69',
    ) : array();
  }

  $recent_blog_posts = aw960_render_block('personality', 'recent_blog_posts');

  if (isset($content['field_pull_quote']) && $content['field_pull_quote']) {
    aw960_dom_insert(render($content['field_pull_quote']), 1200, $content['body'][0]['#markup']);
  }

?>
<?php if ($page) { ?>
  <div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?>" <?php print $attributes; ?>>
    <div class="blog-beat">
      <?php isset($blog_beat) ? print $blog_beat : print ''; ?>
    </div>
    <h1 id="page-title" class="rendered-title">
      <?php print $title; ?>
    </h1>
    <div class="deckhead">
      <?php print strip_tags(render($content['field_deckhead'])); ?>
    </div>
    <div class="by-block">
      <div class="author-photo">
        <?php print render($author_photo); ?>
      </div>
      <?php if($node->uid != '3197' && $node->uid != '3198'): ?>
        <div class="by-line-1">
          <?php print date("F d, Y", $node->created); ?> | By <?php print $author_link; ?>
        </div>
      <?php endif; ?>
      <?php if($node->uid == '3197' || $node->uid == '3198'): ?>
        <div class="by-line-1">
          <?php
            $guest_byline = '';
            if(isset($content['field_byline']['#items'][0]['value'])) {
              $guest_byline = ' | By ' . $blog_author;
            }
          ?>
          <?php print date("F d, Y", $node->created); ?> <?php print $guest_byline; ?>
        </div>
      <?php endif; ?>
      <div class="by-line-2">
        <?php if (isset($author_twitter)) { ?>
          <span class="st_twitterfollow_hcount" displayText="Twitter Follow" st_username="<?=$author_twitter?>"></span>
        <?php } ?>
        <span class="posted-in">POSTED IN: </span><span class="taxonomy-terms"><?php print implode(', ', $limited_terms); ?></span>
      </div>
    </div><!-- /.by-block -->
    <?php if($node->status == TRUE): ?>
    <div id="sharethis-wrapper">
      <a class="print-this" href="/print/<?=$node->nid?>">
        <span class="sharethis-print sharethis-text">print</span>
      </a>
      <span class="st_email_custom sharethis-text" displayText="Email">email</span>
      <span class="st_facebook_hcount" displayText="Facebook"></span>
      <span class="st_twitter_hcount" displayText="Tweet" st_via='automationworld' st_title='<?php echo $title . ' | AW'; ?>'></span>
      <span class="st_plusone_hcount" displayText="Google +"></span>
      <span class="st_linkedin_hcount" displayText="LinkedIn"></span>
    </div>
    <?php endif; ?>
    <div class="slideshow">
      <?php print render($content['slideshow']); ?>
    </div>
    <div class="blog-body">
      <?php print render($content['body']); ?>
    </div>
    <!-- pull quote -->
    <?php if (isset($author_bio)) {
      print $author_bio;
    } ?>
    <!-- prev-next blog post -->
    <?php if ($recent_blog_posts) {
      print $recent_blog_posts;
    } ?>

    <?php if(isset($content['leadership_videos'])): ?>
      <?php print render($content['leadership_videos']); ?>
    <?php endif; ?>

    <!-- comments -->
    <!-- <div class="comment-bar">
      <div class="comment-count"><?php print $comment_count; ?></div>
    </div>
    <div class="comments-wrapper">
      <?php print render($content['comments']); ?>
    </div> -->
  </div><!-- /#node-nid -->
<?php } else if ($teaser) { ?>
  <?php hide($content['links']); ?>
  <div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
    <?php print render($content['field_image']); ?>
    <span class="term">Blog Post</span>
    <span class="separator"> | </span>
    <span class="submitted"><?php print date( "F j, Y", $node->created); ?></span>
    <h2 <?php print $title_attributes; ?>>
      <a href="<?=$node_url?>"><?php print $title;?></a>
    </h2>
    <div class="content">
      <?php print render($content['field_deckhead'])?>
      <span class="more">
        <?php print l("Full Post", "node/$node->nid"); ?>
      </span>
    </div>
  </div>
<?php } ?>
