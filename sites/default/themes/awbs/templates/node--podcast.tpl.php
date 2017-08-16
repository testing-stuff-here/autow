<?php //this will modify the teaser
if (!$page && arg(0)!=='print'): ?>

<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> col-sm-6 col-md-6 awbs-teaser-box" <?php print $attributes; ?>>
 <div class="row">
  <?php if (arg(0) == 'home'): ?>
     <div class="col-xs-12 awbs-teaser-eyebrow"><a href="/podcasts" class="albert"><span class="awbs-eyebrow-text">Podcast</span></a></div>
  <?php endif; ?>
 </div>
 <div class="row awbs-teaser-image animated fadeIn">
  <div class="col-xs-12">
   <a href="<?php print $node_url; ?>">
    <div class="awbs-teaser-image-image"
    <?php
     if (isset($content['field_image'])) {
      print 'style="background-image:url(' . image_style_url("teaser", $content['field_image']['#items'][0]['uri']) . ');';
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


<?php if ($page): ?>

 <div class="row awbs-content-top">
  <h1 class="col-xs-12 awbs-content-title"><?php print render($title); ?></h1>
  <div class="col-xs-12 awbs-content-deckhead"><?php print render($content['field_deckhead']); ?></div>

    <?php if (isset($content['field_byline'])): ?>
     <div class="col-xs-12">
      <div class="row awbs-content-byline">
        <div class="col-xs-12">By <span class="awbs-content-byline-text"><?php print $content['field_byline'][0]['#markup']; ?></span>
        <?php
         if (isset($content['field_author_title'])) {
          print ', ' . $content['field_author_title']['#items'][0]['value'] . ',';
        }
       ?>
       on <span class="awbs-content-byline-date"><?php print date("F j, Y",$node->created); ?></span></div>
    </div>
   </div>
   <?php endif; ?>
 </div>

 <div class="row">
  <div class="col-xs-12 awbs-content-sharing">
   <div class="sharethis-wrapper row">
     <div class="col-xs-12">
       <?php include('includes/sharethis-wrapper.php'); ?>
    </div>
   </div>
   </div>
 </div>


 <div class="row">
  <div class="col-md-8 awbs-content-image short">
   <?php if ($content['field_image']['#items'][0]['filename'] <> NULL): ?>
    <img src="<?php print '/sites/default/files/' . $content['field_image']['#items'][0]['filename']; ?>" alt="<?php print $image['alt']; ?>"  class="img-responsive center-block" />
   <?php endif; ?>
  </div>
 </div>

 <div class="row" id="awbs-main-content" <?php print $content_attributes; ?>>
  <div class="col-xs-8 awbs-body-podcast">
   <?php print render($content['field_podcast']); ?>
  </div>
  <div class="col-md-12 awbs-body-text awbs-body-podcast">
    <?php print $content['body']['#items'][0]['value']; ?>
  </div>
</div>
  <?php if (isset($content['leadership_videos'])) {
    print render($content['leadership_videos']);
  }
  ?>
<?php if ((isset($content['field_companies']['#items'])) && (count($content['field_companies']['#items'] > 0)) ):  ?>
 <div class="row">
    <div class="col-xs-12">
    <div class="row awbs-companies-mentioned">
      <div class="col-xs-12 awbs-companies-mentioned-title">COMPANIES IN THIS ARTICLE</div>

      <?php
       $x = 0;
       $company_count = count($content['field_companies']['#items'] > 0);
         while ($x <= $company_count) {

       ?>
        <div class="col-md-3 awbs-companies-item"><a href="<?php print $content['field_companies'][$x]['#node']; ?>"><?php print $content['field_companies'][$x]['#title']; ?></a></div>
       <?php $x++; } ?>

    </div>
   </div>
  </div>
<?php endif; ?>
<?php endif; ?>
