<?php if (!$page && arg(0) !== 'print'): ?>
  <div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> col-sm-6 col-md-6 awbs-teaser-box" <?php print $attributes; ?>>
   <div class="row">
    <?php if (arg(2) !== $content['field_term_subtype']['#items'][0]['tid']): ?>
     <div class="col-xs-12 awbs-teaser-eyebrow"><a href="<?php print drupal_get_path_alias('taxonomy/term/' . $content['field_term_subtype']['#items'][0]['tid']); ?>" class="albert"><span class="awbs-eyebrow-text"><?php print $content['field_term_subtype'][0]['#markup'];	?></span></a></div>
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


<!-- non feature article, long and short -->
<?php if (($page) && arg(0) !== 'print'): ?>
  <!-- image _always_ displays here -->


  <?php if ((isset($content['field_article_images'])) && ($content['field_article_images']['#items'] <> NULL)): ?>
   <div class="row">
    <div class="<?php if($node->field_article_length['und'][0]['value'] == 'long'): ?>col-md-8<?php else: ?>col-md-12<?php endif; ?>">
    <div class="owl-carousel awbs-article-carousel">

     <div>
       <img src="<?php print file_create_url($content['field_image']['#items'][0]['uri']); ?>" class="img-responsive center-block"  alt="<?php print $image['alt']; ?>" />
       <div class="row awbs-carousel-caption-box">
        <div class="col-xs-1 awbs-left"></div>
         <div class="col-xs-10"><?php print $content['field_image']['#items'][0]['title']; ?></div>
        <div class="col-xs-1 awbs-right"></div>
       </div>
     </div>

     <?php foreach($content['field_article_images']['#items'] as $image) { ?>
        <!-- print file_create_url($image['uri']); -->
        <div>
         <img src="<?php print file_create_url($image['uri']); ?>" class="img-responsive center-block"  alt="<?php print $image['alt']; ?>"/>
         <div class="row awbs-carousel-caption-box">
          <div class="col-xs-1 awbs-left"></div>
           <div class="col-xs-10"><?php print $image['title']; ?></div>
          <div class="col-xs-1 awbs-right"></div>
         </div>
        </div>
     <?php } ?>
    </div>
   </div>
    <?php if($node->field_article_length['und'][0]['value'] == 'long'): ?>
     <div class="col-md-4 awbs-fla-imu"></div>
    <?php endif; ?>
   </div>
  <?php else: ?>
  <div class="row">
   <div class="<?php if($node->field_article_length['und'][0]['value'] != 'long'): ?>col-md-12<?php else: ?>col-md-8<?php endif; ?> awbs-content-image short">
    <?php if ($content['field_image']['#items'][0]['filename'] <> NULL): ?>
     <img src="<?php print file_create_url($content['field_image']['#items'][0]['uri']); ?>" alt="<?php print file_create_url($content['field_image']['#items'][0]['alt']); ?>"  class="img-responsive center-block" />
    <?php endif; ?>
   </div>
    <?php if($node->field_article_length['und'][0]['value'] == 'long'): ?>
     <div class="col-md-4 awbs-fla-imu"></div>
    <?php endif; ?>
  </div>
 <?php endif; ?>



  <!-- on mobile only, (xs/sm), the title, et al, goes under the image. -->
  <!-- see page.tpl.php for md+ size layout -->
  <div class="row awbs-content-top">
   <section>
     <div class="col-xs-12">
      <!-- content-eyebrow :: this row does not exist on md+ sizing -->
      <div class="row">
       <div class="visible-xs visible-sm col-xs-10 col-sm-10 hidden-md hidden-lg awbs-content-eyebrow"><a href="#foo"><span class="awbs-eyebrow-text"><?php print $content['field_term_subtype'][0]['#markup'];	?></span></a></div>
      </div>

      <div class="row">
       <h1 class="visible-xs visible-sm col-xs-12 awbs-content-title"><?php print render($title); ?></h1>
       <div class="visible-xs visible-sm col-xs-12 awbs-content-deckhead"><?php print render($content['field_deckhead']); ?></div>
      </div>

     <?php if (isset($content['field_byline'])): ?>
     <div class="row awbs-content-byline">
       <div class="visible-xs visible-sm col-xs-12">By <span class="awbs-content-byline-text"><?php print $content['field_byline'][0]['#markup']; ?></span>
        <?php
          if (isset($content['field_author_title'])) {
           print ', ' . $content['field_author_title']['#items'][0]['value'] . ',';
         }
        ?>
        on <span class="awbs-content-byline-date"><?php print date("F j, Y",$node->created); ?></span></div>
     </div>
    <?php endif; ?>
    <?php if ($node->field_term_subtype['und'][0]['tid'] == '166'): ?>
      <div class="row awbs-content-byline">
       <div class="visible-xs visible-sm col-xs-12"><span class="awbs-content-byline-date"><?php print date("F j, Y",$node->created); ?></span></div>
      </div>
    <?php endif; ?>

     <!-- this, like the title, is above the image on md+ sizes. -->
      <div class="row">
       <div class="visible-xs visible-sm col-xs-12 awbs-content-sharing">
        <div class="sharethis-wrapper row">
          <div class="col-xs-12">
          <?php if($node->status == TRUE): ?>
            <?php include('includes/sharethis-wrapper.php'); ?>
          <?php endif; ?>
         </div>
        </div>
        </div>
      </div>
     </div>
    </section>
  </div>

  <div class="row" id="awbs-main-content"<?php print $content_attributes; ?>>
   <div class="col-md-12 awbs-body-text short">
     <?php print $content['body']['#items'][0]['value']; ?>
   </div>
 </div>
 <div class="row">

   <?php if (isset($content['leadership_videos'])) {
     print render($content['leadership_videos']);
   }
   ?>

<?php if ((isset($content['field_companies']['#items'])) && (count($content['field_companies']['#items'] > 0)) ):  ?>
     <div class="row awbs-companies-mentioned">
       <div class="col-xs-12 awbs-companies-mentioned-title">COMPANIES IN THIS ARTICLE</div>

       <?php
        $x = 0;
        $company_count = count($content['field_companies']['#items']);
          while ($x <= $company_count) {
        ?>

         <div class="col-md-3 awbs-companies-item"><a href="<?php print "/" . $content['field_companies'][$x]['#href']; ?>"><?php print $content['field_companies'][$x]['#title']; ?></a></div>
        <?php $x++; } ?>

     </div>
 <?php endif; ?>
 <div id="blueconic-offer">
 </div>
</div>




<?php endif; ?>
