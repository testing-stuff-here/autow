<?php

/**
 * @file
 * Theme implementation for Leadership Online Profiles
 *
 */
?>
<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
  <div id="leadership-online-profile-block" class="row">
    <div id="leadership-left-column" class="col-xs-12 col-sm-4">
      <div id="leadership-left-column-content" class="row">
        <div id="leadership-logo" class="col-xs-12">
          <img src="/<?php print drupal_get_path('module','leadership'); ?>/css/images/LIA_white_255_2017.png" class="img-responsive center-block">
        </div>
        <div class="col-xs-12">
          <?php if(isset($content['field_ld_years'])): ?>
            <div class="item row">
              <span class="label col-xs-6">Years in business:&nbsp;</span>
              <div class="col-xs-6"><?php print render($content['field_ld_years']); ?></div>
            </div>
          <?php endif; ?>
          <?php if($content['field_ld_employees']): ?>
            <div class="item row">
              <span class="label col-xs-6">Number of employees:&nbsp;</span>
              <div class="col-xs-6"><?php print render($content['field_ld_employees']); ?></div>
            </div>
          <?php endif; ?>
          <?php if(isset($content['field_ld_geo_distrib'])): ?>
            <div class="item row">
              <span class="label col-xs-6">Geographic sales distribution:&nbsp;</span>
              <div class="col-xs-6"><?php print render($content['field_ld_geo_distrib']); ?></div>
            </div>
          <?php endif; ?>
          <?php if(isset($address)): ?>
            <div class="item row">
              <span class="label col-xs-6">Address:&nbsp;</span>
              <div class="col-xs-6"><?php print $address; ?></div>
            </div>
          <?php endif; ?>
          <?php if(isset($city)): ?>
            <div class="item row">
              <span class="label col-xs-6">City:&nbsp;</span>
              <div class="col-xs-6"><?php print $city; ?></div>
            </div>
          <?php endif; ?>
          <?php if(isset($state)): ?>
            <div class="item row">
              <span class="label col-xs-6">State:&nbsp;</span>
              <div class="col-xs-6"><?php print $state; ?></div>
            </div>
          <?php endif; ?>
          <?php if(isset($zip)): ?>
            <div class="item row">
              <span class="label col-xs-6">Zipcode:&nbsp;</span>
              <div class="col-xs-6"><?php print $zip; ?></div>
            </div>
          <?php endif; ?>
          <?php if(isset($country)): ?>
            <div class="item row">
              <span class="label col-xs-6">Country:&nbsp;</span>
              <div class="col-xs-6"><?php print $country; ?></div>
            </div>
          <?php endif; ?>
          <?php if(isset($phone)): ?>
            <div class="item row">
              <span class="label col-xs-6">Phone:&nbsp;</span>
              <div class="col-xs-6"><?php print $phone; ?></div>
            </div>
          <?php endif; ?>
          <?php if(isset($fax)): ?>
            <div class="item row">
              <span class="label col-xs-6">Fax:&nbsp;</span>
              <div class="col-xs-6"><?php print $fax; ?></div>
            </div>
          <?php endif; ?>
          <?php if(isset($email)): ?>
            <div class="item row">
              <span class="label col-xs-6">Email:&nbsp;</span>
              <div class="col-xs-6"><?php print $email; ?></div>
            </div>
          <?php endif; ?>
          <?php if(isset($sales)): ?>
            <div class="item row">
              <span class="label col-xs-6">Sales Channel:&nbsp;</span>
              <div class="col-xs-6"><?php print render($sales); ?></div>
            </div>
          <?php endif; ?>
        </div>
      </div><!-- /#leadership-left-column-content -->
      <div class="clear"></div>
    </div><!-- /#leadership-left-column -->
    <div id="leadership-right-column" class="col-xs-12 col-sm-8">

      <?php if (isset($content['field_youtube_video'][0]['#video_id'])) : ?>
        <div class="company-profile-youtube" style="text-align:center;" >
          <?php print render($content['field_youtube_video']); ?>
        </div>
      <?php elseif(isset($content['field_ld_logo'])): ?>
        <?php print render($content['field_ld_logo']); ?>
      <?php endif; ?>

      <!-- Print main copy -->
      <?php print render($content['body']); ?>

      <?php if(isset($content['field_ld_training'])): ?>
        <div id="leadership-training">
          <span class="label col-xs-4">Training:&nbsp;</span>
          <?php print render($content['field_ld_training']); ?>
        </div>
      <?php endif; ?>
    </div><!-- /#leadership-right-column -->
  </div>
</div>
