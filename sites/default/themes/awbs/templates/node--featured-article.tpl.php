<?php if (!$page && arg(0)!=='print'): ?>
  <div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> col-sm-4 col-md-6 awbs-teaser-box" <?php print $attributes; ?>>
   <div class="row">
    <?php if (arg(2) !== $content['field_term_subtype']['#items'][0]['tid']): ?>
     <div class="col-xs-12 awbs-teaser-eyebrow"><a href="<?php print drupal_get_path_alias('taxonomy/term/' . $content['field_term_subtype']['#items'][0]['tid']); ?>" class="albert"><span class="awbs-eyebrow-text"><?php print $content['field_term_subtype'][0]['#markup']; ?></span></a></div>
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

<?php if ($page && arg(0)!=='print'): ?>

<div class="row awbs-content-top">
 <section>
   <div class="col-xs-12">
    <div class="row">
     <h1 class="col-xs-12 awbs-content-title"><?php print render($title); ?></h1>
    </div>
    <div class="row">
     <div class="col-xs-12 col-sm-12 col-md-6  awbs-content-sharing">
      <div class="sharethis-wrapper row">
        <div class="col-xs-12">
          <?php include('includes/sharethis-wrapper.php'); ?>
       </div>
      </div>
     </div>
     <div class="col-xs-12 col-sm-12 col-md-6 awbs-content-byline feature-article">
      By <span class="awbs-content-byline-text"><?php print $content['field_byline'][0]['#markup']; ?></span>
      <?php
        if (isset($content['field_author_title'])) {
         print ', ' . $content['field_author_title']['#items'][0]['value'] . ',';
       }
      ?>
      on <span class="awbs-content-byline-date"><?php print date("F j, Y",$node->created); ?></span>
     </div>
    </div>
    <div class="row">
     <div class="col-xs-12 awbs-content-deckhead feature-article">
        <?php
           if ($content['field_deckhead'] <> NULL) { // Print something field
               print render($content['field_deckhead']);
           }
        ?>
     </div>
</div>
</div>
</section>
</div>

<div class="row awbs-body-text feature-article" id="awbs-main-content">
 <div class="col-md-12" class="">
   <?php print $content['body']['#items'][0]['value']; ?>
 </div>
</div>
  <?php if (isset($content['leadership_videos'])) {
    print render($content['leadership_videos']);
  }
  ?>
<div class="row">
 <?php if ((isset($content['field_companies']['#items'])) && (count($content['field_companies']['#items'] > 0)) ):  ?>
   <div class="col-xs-12">
   <div class="row awbs-companies-mentioned feature-article">
     <div class="col-xs-12 awbs-companies-mentioned-title">COMPANIES IN THIS ARTICLE</div>

     <?php
      $x = 0;
      $company_count = count($content['field_companies']['#items']);
        while ($x <= $company_count) {
      ?>
       <div class="col-md-3 awbs-companies-item"><a href="<?php print "/" . $content['field_companies'][$x]['#href']; ?>"><?php print $content['field_companies'][$x]['#title']; ?></a></div>
      <?php $x++; } ?>

   </div>
  </div>
<?php endif; ?>
</div>



<div class="sidebar hidden">
 <?php print $content['field_blockquote']['#items'][0]['value']; ?>
</div>
<div class="pullquote hidden">
 <?php print $content['field_pullquote']['#items'][0]['value']; ?>
</div>
<div class="pullimage hidden">
 <div class="imagebox" style="background-image:url(<?php print file_create_url($content['field_article_images']['#items'][0]['uri']); ?>);">
        <span><?php print $content['field_article_images']['#items'][0]['title']; ?></span>
      </div>
</div>


<?php endif; ?>
