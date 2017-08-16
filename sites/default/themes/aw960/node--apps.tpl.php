
  <?php if ($page || arg(0) == 'print'): ?>
  <div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?>"<?php print $attributes; ?>>

    <?php if (arg(0) != 'print'): ?>
      <div class="sharethis-wrapper">
        <?php if ($node->status == TRUE): ?>
          <span  class='st_linkedin_hcount' displayText='LinkedIn'></span>
          <span  class='st_twitter_hcount' displayText='Tweet'  st_via='automationworld' st_title='<?php echo $title . ' | AW'; ?>'></span>
          <span  class='st_plusone_hcount' displayText="Google +"></span>
          <span class="st_facebook_hcount" displayText="Facebook"></span>
        <?php endif; ?>
      </div>

      <div class="clearfix"></div>

      <h1 id="page-title" class="rendered-title"><?php print $title; ?></h1>

      <?php if($node->status == TRUE): ?>
        <?php include drupal_get_path('theme', 'aw960') . '/includes/share-buttons/widget-wrapper-text.inc'; ?>
      <?php endif; ?>
    <?php endif; ?>

    <div class="widget-wrapper">
      <div class="terms">
        <?php print render($content['field_companies']); ?>
      </div>

      <?php if($node->status == TRUE): ?>
        <?php include drupal_get_path('theme', 'aw960') . '/includes/share-buttons/widget-wrapper-buttons.inc'; ?>
      <?php endif; ?>
    </div>
    <div class="content clearfix"<?php print $content_attributes; ?>>
      <?php print render($content['field_image']); ?>
      <div class="widget-wrapper">
        <h3 class="apps-widget-wrapper-title">What It Does</h3>
      </div>
      <?php print render($content['body']); ?>

      <?php if ($content['field_application_case_history']): ?>
        <div class="widget-wrapper">
          <h3 class="apps-widget-wrapper-title">Application Case History</h3>
        </div>
        <?php print render($content['field_application_case_history']); ?>
      <?php endif; ?>

      <?php if ($platform): ?>
        <div class="widget-wrapper">
          <h3 class="apps-widget-wrapper-title">Platforms/OS</h3>
        </div>
        <?php print $platform; ?>
        <div class="clearfix"></div>
      <?php endif; ?>

      <?php if ($content['field_app_more_information_link']): ?>
        <div class="widget-wrapper">
          <h3 class="apps-widget-wrapper-title">More Information</h3>
        </div>
        <?php print render($content['field_app_more_information_link']); ?>
      <?php endif; ?>

      <?php if ($content['field_video_resources']): ?>
        <div class="widget-wrapper">
          <h3 class="apps-widget-wrapper-title">Video Resources</h3>
        </div>
        <?php print render($content['field_video_resources']); ?>
      <?php endif; ?>
    </div>
  </div>
<?php endif; ?>
<?php // Teaser
if (!$page && arg(0) != 'print') :?>
  <div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> apps-teaser clearfix"<?php print $attributes; ?>>
    <?php print render($content['field_image']); ?>
    <?php print render($content['field_companies']); ?>
    <h2<?php print $title_attributes; ?>>
      <a href="<?php print $node_url; ?>"><?php print $title ?></a>
    </h2>
    <?php print render($content['body']); ?>
  </div>
<?php endif; ?>
