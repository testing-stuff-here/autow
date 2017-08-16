<?php if (!$page && arg(0) !== 'print'): ?>
 <div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> col-md-11" <?php print $attributes; ?>>
  <div class="row">
   <?php if (arg(0) == 'home'): ?>
    <div class="col-xs-12 awbs-teaser-eyebrow"><a href="<?php print drupal_get_path_alias('taxonomy/term/' . $content['field_term_subtype']['#items'][0]['tid']); ?>" class="albert"><span class="awbs-eyebrow-text"><?php print $content['field_term_subtype'][0]['#markup'];	?></span></a></div>
   <?php endif; ?>
  </div>
  <div class="row awbs-teaser-image animated fadeIn">
   <div class="col-xs-12">
    <a href="<?php print $node_url; ?>">
     <div class="awbs-teaser-image-image tactical-adjust"
     <?php
      if (isset($content['field_image'])) {
       print 'style="background-image:url(' . file_create_url($content['field_image']['#items'][0]['uri']) . ');';
      } else {
       print 'style="background-image:url(' . url("/sites/default/themes/awbs/images/aw-placeholder.png", array('absolute' => true)) . '); background-position:center!important;';
      }
     ?>"></div>
    </a>
   </div>
  </div>
  <div class="row awbs-teaser-content animated fadeIn">
   <div class="col-xs-12 awbs-teaser-title"><a href="<?php print $node_url; ?>"><h3><?php print render($title); ?></h3></a></div>
   <div class="col-xs-12 awbs-teaser-deckhead"><?php print render($content['field_deckhead']); ?></div>
  </div>
 </div>
<?php endif; ?>


<?php if (($page) && arg(0) !== 'print'): ?>

 <div class="col-xs-12 awbs-tb-wrapper">

  <div class="row awbs-content-top">
    <h1 class="col-xs-12 col-md-8 awbs-content-title"><?php print $title; ?></h1>
  </div>

  <div class="row awbs-content-top">
   <div class="col-xs-12 col-md-8 awbs-content-deckhead"><?php print strip_tags(render($content['field_deckhead'])); ?></div>
  </div>

  <div class="row">
   <div class="col-xs-12 col-md-5">

    <div class="row awbs-tb-hero-image">
     <div class="col-xs-12">
    <?php if(isset($content['field_image'])){
      print render($content['field_image']);
    } ?>
   </div>
  </div>

  <div class="row awbs-tb-download-button-wrapper">
    <div class="col-xs-10 col-xs-offset-1">
     <?php
      if (isset($download_field_url)) {
          if (!isset($doc_download_btn))
            print l(t('Download Tactical Brief'), $download_field_url, array('attributes' => array('class' => 'awbs-btn btn btn-block btn-sm')));
          else
            print $doc_download_btn;
        }
    ?>
    </div>
   </div>
  </div>
   <div class="col-xs-12 col-md-7 awbs-tb-content-body"><?php print render($content['body']); ?></div>
  </div>
  <?php if (isset($content['leadership_videos'])) {
   print render($content['leadership_videos']);
  }
  ?>
  <div class="row awbs-tb-bottom-rail">
   <div class="col-xs-12 col-md-10 awbs-tb-sponsor"><span class="awbs-tb-sponsor-tag">SPONSOR:</span> <?php print $node->field_companies['und'][0]['node']->title; ?></div>
   <div class="hidden-xs hidden-sm col-md-2">

     <div class="row">
      <div class="col-xs-12 awbs-content-sharing">
       <div class="sharethis-wrapper row">
         <div class="col-xs-12">
          <?php include('includes/sharethis-wrapper.php'); ?>
        </div>
       </div>
       </div>
     </div>

  </div>
  </div>
 </div>
<?php endif; ?>
