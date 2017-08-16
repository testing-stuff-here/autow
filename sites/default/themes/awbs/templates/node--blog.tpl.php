<?php if ($teaser): ?>
 <?php
 foreach ($node->field_allterms['und'] as $term) {
   switch ($term['tid']) {
     case '1876':
       $blog_header = '<a href="/factory-automation-desk"><span class="awbs-eyebrow-text">Factory Automation Desk</span></a>';
       break;
     case '1879':
       $blog_header = '<a href="/batch-processing-desk"><span class="awbs-eyebrow-text">Batch Processing Desk</span></a>';
       break;
     case '2195':
       $blog_header = '<a href="/process-automation-desk"><span class="awbs-eyebrow-text">Process Automation Desk</span></a>';
       break;
     case '911':
       $blog_header = '<a href="/packaging-automation-desk"><span class="awbs-eyebrow-text">Packaging Automation Desk</span></a>';
       break;
     case '1877':
       $blog_header = '<a href="/nextgen-infrastructure-desk"><span class="awbs-eyebrow-text">NextGen Infrastructure Desk</span></a>';
       break;
   }
 }
 ?>
 <div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> col-sm-6 col-md-6 awbs-teaser-box"<?php print $attributes; ?>>
  <div class="row">
   <div class="col-xs-12 awbs-teaser-eyebrow">
    <?php if ($csia) {
            print "<a href='//www.automationworld.com/csia'><span class='awbs-eyebrow-text'>CSIA Guest Blog</span></a>";
          } else {
            print $blog_header;
          } ?>
    </div>
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
   <?php if ($content['field_article_images']['#items'] <> NULL): ?>
     <div class="owl-carousel awbs-article-carousel animated fadeIn">

      <?php if ($content['field_image']['#items'][0]['filename'] <> NULL): ?>
      <div>
        <img src="<?php print file_create_url($content['field_image']['#items'][0]['uri']); ?>" alt="<?php print $image['alt']; ?>" class="img-responsive center-block" />
        <div class="row awbs-carousel-caption-box">
         <div class="col-xs-1 awbs-left"></div>
          <div class="col-xs-10"><?php print $content['field_image']['#items'][0]['title']; ?></div>
         <div class="col-xs-1 awbs-right"></div>
        </div>
      </div>
      <?php endif; ?>

      <?php foreach($content['field_article_images']['#items'] as $image) { ?>
         <div>
          <img src="<?php print file_create_url($image['uri']); ?>" class="img-responsive center-block" alt="<?php print $image['alt']; ?>"/>
          <div class="row awbs-carousel-caption-box">
           <div class="col-xs-1 awbs-left"></div>
            <div class="col-xs-10"><?php print $image['title']; ?></div>
           <div class="col-xs-1 awbs-right"></div>
          </div>
         </div>
      <?php } ?>
     </div>
   <?php else: ?>
   <div class="row">
    <div class="col-md-12 awbs-content-image short">
     <?php if ($content['field_image']['#items'][0]['filename'] <> NULL): ?>
      <img src="<?php print file_create_url($content['field_image']['#items'][0]['uri']); ?>" class="img-responsive center-block" alt="<?php print $image['alt']; ?>"  />
    <?php endif; ?>
     </div>
   </div>
  <?php endif; ?>

   <!-- on mobile only, (xs/sm), the title, et al, goes under the image. -->
   <!-- see page.tpl.php for md+ size layout -->

   <div class="row awbs-content-top" id="node-<?php print $node->nid; ?>" <?php print $attributes; ?>>
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



      <!-- this, like the title, is above the image on md+ sizes. -->
       <div class="row">
        <div class="visible-xs visible-sm col-xs-12 awbs-content-sharing">
         <div class="sharethis-wrapper row">
           <div class="col-xs-12">
             <?php include('includes/sharethis-wrapper.php'); ?>
          </div>
         </div>
         </div>
       </div>
      </div>
     </section>
   </div>

   <div class="row awbs-body-text" id="awbs-main-content">
    <div class="col-md-12" class="awbs-body-text">
      <?php print $content['body']['#items'][0]['value']; ?>
    </div>
  </div>
  <div id="blueconic-offer">
 </div>
   <?php if (isset($content['leadership_videos'])) {
     print render($content['leadership_videos']);
   }
   ?>
  <div class="row">
   <?php if ((isset($content['field_companies']['#items'])) && (count($content['field_companies']['#items'] > 0)) ):  ?>
     <div class="col-xs-12">
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
    </div>
 <?php endif; ?>
    <div class="pullquote blogquote hidden">
       <?php print render($content['field_pull_quote']); ?>
    </div>
  </div>

 <?php endif; ?>

