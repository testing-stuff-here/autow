<?php if ($teaser): ?>
  <div id="node-<?php print $node->nid; ?>"
       class="<?php print $classes; ?> col-sm-6 col-md-6 awbs-teaser-box" <?php print $attributes; ?>>
    <div class="row">
      <?php if (arg(0) == 'home'): ?>
        <div class="col-xs-12 awbs-teaser-eyebrow"><a
            href="<?php print drupal_get_path_alias('taxonomy/term/' . $content['field_term_subtype']['#items'][0]['tid']); ?>"
            class="albert"><span
              class="awbs-eyebrow-text"><?php print $content['field_term_subtype'][0]['#markup']; ?></span></a></div>
      <?php endif; ?>
    </div>

    <div class="row awbs-teaser-image animated fadeIn">
      <div class="col-xs-12">
        <?php if (isset($content['webinar_url'])): ?>
        <a href="<?php print $content['webinar_url']; ?>">
          <?php else: ?>
          <a href="<?php print $node_url; ?>" >
            <?php endif; ?>
            <div class="awbs-teaser-image-image"
              <?php
              if (isset($content['body']['#object']->field_image) && !empty($content['body']['#object']->field_image[LANGUAGE_NONE][0]['filename'])) {
                print 'style="background-image:url(' . url("/sites/default/files/" . $content['body']['#object']->field_image[LANGUAGE_NONE][0]['filename'], array('absolute' => true)) . '); background-position:center!important;"';
              }
              else {
                print 'style="background-image:url(' . url("/sites/default/themes/awbs/images/aw-placeholder.png", array('absolute' => true)) . '); background-position:center!important;"';
              }
              ?>>
            </div>
          </a>
      </div>
    </div>

    <div class="row awbs-teaser-content animated fadeIn">
      <div class="col-xs-12 awbs-teaser-title">
        <?php if (isset($content['webinar_url'])): ?>
        <a href="<?php print $content['webinar_url']; ?>">
          <?php else: ?>
          <a href="<?php print $node_url; ?>">
            <?php endif; ?>
            <h3><?php print render($title); ?></h3></a></div>
      <div class="col-xs-12 awbs-teaser-deckhead"><?php print render($content['field_deckhead']); ?></div>
    </div>
  </div>
<?php endif; ?>

<?php if ($page): ?>

  <?php
// @TODO Move to template.php
  $pre_launch = (time() <= $content['field_gotowebinar_webinar_date']['#items'][0]['value2']);
  $which_banner = ($pre_launch || empty($content['field_post_launch_banner'])) ? 'field_pre_launch_banner' : 'field_post_launch_banner';
  $types = node_type_get_types();
  ?>

  <div class="row" id="node-<?php print $node->nid; ?>">
    <?php if (isset($content[$which_banner])): ?>
      <div class="col-xs-12 col-md-10 awbs-webinar-img"><?php print render($content[$which_banner]); ?></div>
    <?php endif; ?>
    <div class="col-xs-12 col-md-10 awbs-webinar-title"><?php print $title; ?></div>
  </div>
  <div class="row">
    <div class="col-xs-12">
      <?php if ($pre_launch) {
        $date_items = $content['field_gotowebinar_webinar_date']['#items'][0];
        $date_str = date('l, F j, Y', $date_items['value']);

        if ($date_items['value'] == $date_items['value2']) {
          $time_str = date('g:i A T', $date_items['value']);
        }
        else {
          $time_str = date('g:i A', $date_items['value']) . ' &mdash; ' . date('g:i A T', $date_items['value2']);
        }
        ?>
        <div class="alert alert-info awbs-webinar-soon"><b>Date:</b> <?= $date_str ?> &bull;
          <b>Time:</b> <?= $time_str ?></div>
      <?php }
      else { ?>
        <div class="alert alert-success awbs-webinar-available">Available now for immediate viewing.</div>
      <?php } ?>
    </div>
  </div>
  <div class="row">
    <div class="hidden-xs hidden-sm col-md-6 awbs-content-sharing">
      <div class="sharethis-wrapper row">
        <div class="col-xs-12">
          <?php include('includes/sharethis-wrapper.php'); ?>
        </div>
      </div>
    </div>
  </div>
  <div class="row">
    <div class="col-xs-12 col-md-7 awbs-webinar-copy"><?php print render($content['field_image']);
      print $node->body['und'][0]['value']; ?></div>

    <div class="col-xs-12 col-md-5">
      <div class="row">
        <div class="col-xs-12">
          <?php print '<div class="awbs-webinar-webform-header">' . render($content['field_form_header']) . '</div>'; ?>
          <?php print render($content['webform']); ?>
        </div>
      </div>
      <div class="row">
        <div class="col-xs-12 awbs-webinar-speakers-header">SPEAKERS</div>
      </div>
      <div class="row">
        <div class="col-xs-12 awbs-webinar-speakers">
          <?php print render($content['field_expert']); ?>
        </div>
      </div>
    </div>

    <div class="col-xs-12 awbs-webinar-disclaimer">
      <?php print render($content['field_disclaimer']); ?>
    </div>
  </div>
  <script>
    jQuery(function () { // inline styling is bad and you should feel bad.
      jQuery('button[type="button"]').css('width', '');
    });
  </script>
<?php endif; ?>
