<?php if($page): ?>
<div class="row awbs-playbook-top-content">
 <div class="col-xs-12 col-md-5 awbs-playbook-hero-image">
  <?php print render($content['field_cover_image']); ?>
 </div>
 <div class="col-xs-12 col-md-7 awbs-playbook-hero-text">
  <div class="row">
   <?php print "<div class='col-xs-12 awbs-playbook-title'>" . $content['field_playbook_name'][0]['#markup'] . "</div>"; ?>
  </div>
  <div class="row">
   <?php print "<div class='col-xs-12 col-md-8 awbs-playbook-deckhead'>" . render($content['field_sub_title']) . "</div>"; ?>
  </div>
  <div class="row">
   <?php print "<div class='col-xs-12 awbs-playbook-copy'>" . render($content['field_top_copy']) . "</div>"; ?>
  </div>
 </div>
</div>
<div class="row awbs-playbook-bottom-content">
 <div class="col-xs-12 col-md-6">
  <div class="row">
   <div class="col-xs-12 awbs-playbook-experts-header">Experts sourced in this e-book</div>
   <div class="col-xs-12 awbs-playbook-experts">
    <?php print render($content['field_expert']); ?>
   </div>
  </div>
  <div class="row">
    <div class="col-xs-12 awbs-playbook-topics">
      <?php print render($content['body']); ?>
      <div id="playbook-sponsors">
        <?php if (isset($content['field_sponsor'][0])) { ?>
          <h5>This playbook is proudly sponsored by:</h5>
        <?php } ?>
        <?php if(isset($content['field_image'])):?>
          <?php print render($content['field_image']); ?>
        <?php else: ?>
          <div id="playbook-sponsors-inner">
            <?php print render($content['field_sponsor']); ?>
          </div>
        <?php endif; ?>
      </div>
    </div>
  </div>
 </div>
 <div class="col-xs-12 col-md-6 awbs-playbook-form">
  <div class="row awbs-playbook-form-preface">
   <div class="col-xs-8 col-xs-offset-2 awbs-playbook-form-preface-text">FILL OUT THE FORM BELOW FOR AN INSTANT DOWNLOAD</div>
  </div>
  <?php print render($content['webform']); ?>
  </div>
</div>
<div class="col-xs-12 col-md-12 awbs-playbook-disclaimer">
  <?php print render($content['field_disclaimer']); ?>
</div>
<script>
jQuery(function($) {
 console.log('pb');
 $("button[type='button']").css('width', '').addClass('idunno');
 $("button[type='submit']").removeClass('btn-default');
});
</script>
<?php endif; ?>
