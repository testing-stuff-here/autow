<?php if($view_mode != 'aw_gmfd_slide_in'): ?>
  <div id="node-<?php print $node->nid; ?>" class="awbs-teaser-box awbs-teaser-download col-sm-6 col-md-6 animated fadeIn"<?php print $attributes; ?>>
   <div class="row">
    <div class="col-xs-12">
     <div class="row">
      <div class="col-xs-12 awbs-teaser-eyebrow"><span class="awbs-eyebrow-text">free download</span></div>
     </div>
     <div class="row awbs-teaser-download-top">
      <div class="col-xs-6 awbs-teaser-download-title"><?php print $title; ?></div>
      <div class="col-xs-6 awbs-teaser-download-image"><?php print render($content['field_image']); ?></div>
     </div>
     <div class="row awbs-teaser-download-middle">
      <div class="col-xs-12 awbs-teaser-download-body">
       <?php print render($content['body']); ?>
      </div>
     </div>
     <div class="row awbs-teaser-download-bottom">
      <div class="col-xs-12">
       <?php print render($content['webform']); ?>
      </div>
     </div>
    </div>
   </div>
  </div>
<?php else: ?>  
 <div id="sliding-panel" class="col-md-5">
  <div class="row slider-top" id="node-<?php print $node->nid; ?>" <?php print $attributes; ?>>
   <div class="col-xs-4 awbs-teaser-download-image"><?php print render($content['field_image']); ?></div>
    <?php //print render($content['field_form_description']); ?>
   <div class="col-xs-8">
    <div class="row">
     <div class="col-xs-12 awbs-teaser-download-title"><?php print $title; ?>
     </div>
     <div class="col-xs-12 awbs-teaser-download-body"><?php print render($content['body']); ?>
     </div>
    </div>
   </div>
  </div>

  <div class="row slider-bottom">
    <div class="col-xs-12 toc-playbook">
     <?php //print render($content['webform']); ?>
     <button class="btn-sm btn-block btn btn-default">
       <a href="http://opxleadershipnetwork.org/capital-equipment-total-cost-ownership/download/total-cost-ownership-playbook?csource=GMFD_aw" target="_blank">GET MY FREE DOWNLOAD &raquo;</a>
     </button>
    </div>
  </div>
  <div class="close-slide-in" ><i class="fa fa-fw fa-close"></i></div>
 </div>
<?php endif;?>
