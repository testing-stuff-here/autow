<?php
  $pre_launch = (time() <= $content['field_gotowebinar_webinar_date']['#items'][0]['value2']);
  $which_banner = ($pre_launch || empty($content['field_post_launch_banner'])) ? 'field_pre_launch_banner' : 'field_post_launch_banner';
  $types = node_type_get_types();
?>

<?php if ($page): ?>
  <div id="node-<?php print $node->nid; ?>">
    <div id="webinar-banner">
      <?php print render($content[$which_banner]); ?>
    </div>
    <div id="webinar-inner">
      <?php //dsm($content); ?>
      <div id="webinar-top">
        <h1 class="webinar-name"><?php print $title; ?></h1>
      </div> <!-- /#webinar-top -->
      <div id="webinar-bottom">
        <div id="webinar-bottom-col-1" class="webinar-bottom-col">
          <div id="webinar-experts">
            <h3>Speakers</h3>
            <div id="webinar-experts-inner">
              <?php print render($content['field_expert']); ?>
            </div>
          </div>
          <div class="social-media">
            <div class="header">SHARE THIS WEBINAR</div>
            <div class="sharethis-wrapper">
              <?php if($node->status == TRUE): ?>
                <span  class='st_linkedin_hcount' displayText='LinkedIn'></span>
          			<span  class='st_twitter_hcount' displayText='Tweet' st_via='automationworld' st_title='<?php echo $title . ' | AW'; ?>'></span>
          			<span  class='st_plusone_hcount' displayText="Google +"></span>
          			<span class="st_facebook_hcount" displayText="Facebook"></span>
        			<?php endif; ?>
            </div>
          </div>
        </div> <!-- /#webinar-bottom-col-1 -->
        <div id="webinar-bottom-col-2" class="webinar-bottom-col">
          <div id="webinar-description">
            <div class="webinar-date">
              <?php if ($pre_launch) {
                $date_items = $content['field_gotowebinar_webinar_date']['#items'][0];
                $date_str = date('l, F j, Y', $date_items['value']);

                if ($date_items['value'] == $date_items['value2']) {
                  $time_str = date('g:i A T', $date_items['value']);
                } else {
                  $time_str = date('g:i A', $date_items['value']) . ' &mdash; ' . date('g:i A T', $date_items['value2']);
                }
              ?>
                <b>Date:</b> <?=$date_str?> &bull; <b>Time:</b> <?=$time_str?>
              <?php } else { ?>
                Available now for immediate viewing.
              <?php } ?>
            </div>
            <div id="webinar-body">
              <?php print render($content['body']); ?>
            </div>
            <div id="webinar-disclaimer">
              <?php print render($content['field_disclaimer']); ?>
            </div>
          </div>
        </div> <!-- /#webinar-bottom-col-2 -->
        <div id="webinar-bottom-col-3" class="webinar-bottom-col">
          <div id="webinar-form">
            <div id="webinar-form-title"><?php print render($content['field_form_header']); ?></div>
            <div id="webinar-form-inner">
              <?php print render($content['webform']); ?>
            </div>
          </div>
        </div> <!-- /#webinar-bottom-col-3 -->
      </div> <!-- /#webinar-bottom -->
    </div> <!-- /#webinar-inner -->
  </div>
<?php endif; ?>
<?php if ($teaser): ?>
	<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
	  <?php if($is_front):?>
      <div class="term">
        <?php print $types[$node->type]->name; ?>
        <span class="separator"> | </span>
        <span class="submitted">
          <?php print date( "F j, Y", $node->created); ?>
        </span>
      </div>
	  <?php else: ?>
      <span class="term">
        <?php print $types[$node->type]->name; ?>
      </span>
      <span class="separator"> | </span>
		  <span class="submitted">
        <?php print date( "F j, Y", $node->created); ?>
		  </span>
	  <?php endif; ?>
	  
	  <?php print render($title_prefix); ?>
		<h2<?php print $title_attributes; ?>>
			<a href="<?php print $node_url; ?>"><?php print preg_replace('/\[break\]/', '<br />', $title); ?></a>
		</h2>
	  <?php print render($title_suffix); ?>
    
	  <div class="content">
      <?php print render($content['field_deckhead'])?>
      <span class="more">
        <a href="<?php print url( 'node/' . $node->nid );?>">Full Article</a>
      </span>
	  </div>
	</div>
<?php endif; ?>
