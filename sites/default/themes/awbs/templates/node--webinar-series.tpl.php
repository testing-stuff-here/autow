<?php
?>
<?php if ($page): ?>
  <div id="node-<?php print $node->nid; ?>">
    <div id="webinar-inner">
      <div id="webinar-top" class="row">
        <h1 class="webinar-name"><?php print $title; ?></h1>
      </div> <!-- /#webinar-top -->
      <div class="awbs-content-sharing">
              <div class="sharethis-wrapper row">
                 <?php if($node->status == TRUE): ?>
                 <?php include('includes/sharethis-wrapper.php'); ?>
                 <?php endif; ?>
              </div>
             </div>
      <div id="webinar-bottom" class="row">
        <div id="webinar-bottom-col-1" class="webinar-bottom-col col-md-7">
          <div class="webinar-description">
            <?php print render($content['field_ws_webinar']); ?>
          </div>
          <div class="webinar-disclaimer">
            <?php print render($content['field_disclaimer']); ?>
          </div>
        </div> <!-- /#webinar-bottom-col-1 -->
        <div id="webinar-bottom-col-2" class="webinar-bottom-col col-md-5">
          <div id="webinar-form" class="awbs-regpage-form">
            <div id="webinar-form-title" class="awbs-regpage-form-header">
              <?php if (isset($content['field_form_header'])): ?>
                <h2><?php print render($content['field_form_header']); ?></h2>
              <?php else: ?>
                <h2>Register Here</h2>
              <?php endif; ?>
            </div>
            <div id="webinar-form-inner">
              <?php print render($content['webform']); ?>
            </div>
          </div>
          <div id="webinar-sponsor-logo">
            <?php if (isset($content['field_sponsor_logo'])): ?>
              <h3>Sponsored By:</h3>
              <?php print render($content['field_sponsor_logo']) ?>
            <?php endif; ?>
          </div>
        </div> <!-- /#webinar-bottom-col-2 -->
      </div> <!-- /#webinar-bottom -->
    </div> <!-- /#webinar-inner -->
  </div>
  <script>
    jQuery(function() { // inline styling is bad and you should feel bad.
      jQuery('button[type="button"]').css('width','');
    });
  </script>
<?php endif; ?>
