<?php if($view_mode != 'aw_gmfd_slide_in'): ?>
  <div id="node-<?php print $node->nid; ?>" class="awbs-teaser-box col-md-6"<?php print $attributes; ?>>
    <?php print render($content['field_form_description']); ?>
    <?php // print render($content['field_image']); ?>
    <div class="stage-one-title"><?php print $title; ?></div>
    <?php print render($content['body']); ?>
    <?php print render($content['webform']); ?>
  </div>
<?php else: ?>
  <div id="sliding-panel">
    <div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> xx clearfix"<?php print $attributes; ?>>
      <?php print render($content['field_image']); ?>
      <?php print render($content['field_form_description']); ?>
      <div class="stage-one-title"><?php print $title; ?></div>
      <?php print render($content['body']); ?>
      <?php print render($content['webform']); ?>
    </div>
    <div class="close-slide-in" >x</div>
  </div>
<?php endif;?>
