<div class="col-xs-12 awbs-csia-signup-form">
 <div class="row">
  <div class="col-xs-12 awbs-csia-header">
  Control Systems Integrators Report
 </div>
</div>
<div class="row awbs-csia-copy">
 <div class="col-xs-7 awbs-csia-copy-copy">
  Download AW's exclusive new survey results on system integrators, and gain access to the industry's premier integrator directory:
 </div>
 <div class="col-xs-5 awbs-csia-copy-image">
   <img src="/sites/default/files/CSIAHeroShot_V3.png">
 </div>
</div>
<div class="row awbs-csia-form">
  <div class="col-xs-12 awbs-csia-form-email">
    <?php print drupal_render($form['submitted']['email']); ?>
  </div>
  <div class="col-xs-12 awbs-csia-form-country">
    <?php print drupal_render($form['submitted']['country']); ?>
  </div>
  <div class="col-xs-12  awbs-csia-form-company">
   <?php print drupal_render($form['submitted']['which_best_describes_your_company']); ?>
  </div>

  <div class="col-xs-12 awbs-csia-form-submit">
   <?php $form['actions']['submit']['#attributes']['class'][] = 'btn-sm btn-block'; ?>

   <?php print drupal_render($form['actions']); ?>
   <?php print drupal_render_children($form); ?>
  </div>
</div>
</div>
<script>
jQuery(function() {
 jQuery('button[type="button"]').css('width','');
});
</script>
