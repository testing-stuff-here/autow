<?php

/**
 * @file
 * Theme implementation for Leadership Online Profiles
 *
 */
?>
<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
  <div id="leadership-online-profile-block">
    <div id="leadership-left-column">
      <div id="leadership-left-column-content">
        <div id="leadership-logo">
          <img src="/<?php print drupal_get_path('module','leadership'); ?>/css/images/LIA_white_255_2017.png">
        </div>
        <?php if(isset($content['field_ld_years'])): ?>
          <div class="item col-xs-12">
            <span class="label">Years in business:&nbsp;</span>
            <?php print render($content['field_ld_years']); ?>
          </div>
        <?php endif; ?>
        <?php if($content['field_ld_employees']): ?>
          <div class="item col-xs-12">
            <span class="label">Number of employees:&nbsp;</span>
            <?php print render($content['field_ld_employees']); ?>
          </div>
        <?php endif; ?>
        <?php if(isset($content['field_ld_geo_distrib'])): ?>
          <div class="item col-xs-12">
            <span class="label">Geographic sales distribution:&nbsp;</span>
            <?php print render($content['field_ld_geo_distrib']); ?>
          </div>
        <?php endif; ?>
        <?php if(isset($address)): ?>
          <div class="item col-xs-12">
            <span class="label">Address:&nbsp;</span>
            <?php print $address; ?>
          </div>
        <?php endif; ?>
        <?php if(isset($city)): ?>
          <div class="item col-xs-12">
            <span class="label">City:&nbsp;</span>
            <?php print $city; ?>
          </div>
        <?php endif; ?>
        <?php if(isset($state)): ?>
          <div class="item col-xs-12">
            <span class="label">State:&nbsp;</span>
            <?php print $state; ?>
          </div>
        <?php endif; ?>
        <?php if(isset($zip)): ?>
          <div class="item col-xs-12">
            <span class="label">Zipcode:&nbsp;</span>
            <?php print $zip; ?>
          </div>
        <?php endif; ?>
        <?php if(isset($country)): ?>
          <div class="item col-xs-12">
            <span class="label">Country:&nbsp;</span>
            <?php print $country; ?>
          </div>
        <?php endif; ?>
        <?php if(isset($phone)): ?>
          <div class="item col-xs-12">
            <span class="label">Phone:&nbsp;</span>
            <?php print $phone; ?>
          </div>
        <?php endif; ?>
        <?php if(isset($fax)): ?>
          <div class="item col-xs-12">
            <span class="label">Fax:&nbsp;</span>
            <?php print $fax; ?>
          </div>
        <?php endif; ?>
        <?php if(isset($sales)): ?>
          <div class="item col-xs-12">
            <span class="label">Sales Channel:&nbsp;</span>
            <?php print render($sales); ?>
          </div>
        <?php endif; ?>
      </div><!-- /#leadership-left-column-content -->
      <div class="clear"></div>
    </div><!-- /#leadership-left-column -->
    <div id="leadership-right-column">
      <h2><?php print $node->title; ?></h2>
      <?php if(isset($content['field_viddler_id'][0]['#markup'])): ?>
        // @TODO Add viddler field to content type then complete this section
      <?php elseif(isset($content['field_ld_logo'])): ?>
        <?php print render($content['field_ld_logo']); ?>
      <?php endif; ?>

      <!-- Print main copy -->
      <?php print render($content['body']); ?>

      <?php if(isset($content['field_ld_training'])): ?>
        <div id="leadership-training">
          <span class="label">Training:&nbsp;</span>
          <?php print render($content['field_ld_training']); ?>
        </div>
      <?php endif; ?>
    </div><!-- /#leadership-right-column -->
  </div>
</div>
