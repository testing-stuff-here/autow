<?php $types = node_type_get_types(); //instead of using the machine name, this will fetch the node type names?>


<?php //this will modify the teaser
if (!$page && arg(0)!=='print'): ?>
<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> col-sm-6 col-md-6 awbs-teaser-box" <?php print $attributes; ?>>
 <div class="row">
  <?php if (arg(0) == 'home'): ?>
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




<?php if ($page): ?>
  <style type="text/css">
    .ajax-progress-throbber {
        width:0;
    }
  </style>
  <div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?>"<?php print $attributes; ?>>
   <div class="row awbs-content-top">
    <section>
      <div class="col-xs-12">
       <div class="row">
       <h1 class="col-xs-12 awbs-white-paper-label">WHITE PAPER</h1>
        <h2 class="col-xs-12 awbs-content-title"><?php print render($title); ?></h2>
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

      <!-- this, like the title, is above the image on md+ sizes. -->
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
     </section>
   </div>

    <div class="row">
     <div class="col-md-8 awbs-content-image short">
      <?php if ($content['field_image']['#items'][0]['filename'] <> NULL): ?>
       <img src="<?php print file_create_url($content['field_image']['#items'][0]['uri']); ?>" alt="<?php print $image['alt']; ?>"  class="img-responsive center-block" />
      <?php endif; ?>
     </div>
       <div class="col-md-4">
         <div class="awbs-whitepaper-deckhead"><?php print render($content['field_deckhead']); ?></div>
        <?php
        print render($content['leadwise']);

        if (isset($content['field_whitepaper'][0]['#markup'])) {
          if (!isset($doc_download_btn))
            print l(t('Download White Paper'), $content['field_whitepaper'][0]['#markup'], array('attributes' => array('class' => 'awbs-btn btn-default')));
          else
            print $doc_download_btn;
        }
      ?>
    </div>
  </div>

  <?php if (isset($content['leadership_videos'])) {
    print render($content['leadership_videos']);
  }
  ?>

 <?php if ((isset($content['field_companies']['#items'])) && (count($content['field_companies']['#items'] > 0)) ):  ?>
  <div class="row">
      <div class="col-xs-12 awbs-whitepaper-companies">
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



<?php //print page
if (!$page && arg(0)=='print'): ?>
<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?>"<?php print $attributes; ?>>
<div class="content clearfix"<?php print $content_attributes; ?>>
<?php 	print '<span class="node-type">' . $types[$node->type]->name . '</span>';	?><?php print render($content['field_term_subtype']) ;?><span class="submitted"> | <?php print date( "F j, Y",$node->created); ?> </span>
<h1 id="page-title" class="rendered-title"><?php print $title; ?></h1>
<?php print '<span class="deckhead">' .	render($content['field_deckhead']) . '</span>';?>
<span class='submitted-author'>
  <b>
  <?php if(isset($author)): ?>
    By <span class="byline"><?php print $author; ?></span>
  <?php endif; ?>
  </b>
</span>
<?php print render($content['body']); ?>
<?php // this will construct the companies
	if(isset($node->field_companies['und'])) : ?>
		<div id="companies">
			<label class="title">Companies in this article:<label>
			<?php
			foreach ($node->field_companies['und'] as $company){
			  if (!isset($company['nid']) || !$company['nid']) continue;

			  $node_company = node_load($company['nid']);
			  $term_data = field_view_value('node', $node_company, 'field_term_company_type', $node_company->field_term_company_type['und'][0]);
			  if ($term_data['#title']=='Supplier') {
			    $supplier[] = '<li>' . l($node_company->title,'node/'.$node_company->nid) . '</li>';
			  }
			  else if($term_data['#title']=='Packager') {
			    $packager[] = '<li>' . l($node_company->title,'node/'.$node_company->nid) . '</li>';
			  }
			  else if($term_data['#title']=='Association') {
			    $assocation[] = '<li>' . l($node_company->title,'node/'.$node_company->nid) . '</li>';
			  }
				else if($term_data['#title']=='Consultant') {
			    $consultant[] = '<li>' . l($node_company->title,'node/'.$node_company->nid) . '</li>';
			  }
			}
			?>
			<?php if(isset($packager)):?>
				<label class="type">Packager:</label><span class="orange"></span><?php print '<ul>' . implode('',$packager) . '</ul>';?>
			<?php endif; ?>
			<?php if(isset($supplier)):?>
				<label class="type">Supplier:</label><span class="orange"></span><?php print '<ul>' . implode('',$supplier) . '</ul>';?>
			<?php endif; ?>
			<?php if(isset($assocation)):?>
			<label class="type">Association:</label><span class="orange"></span><?php print '<ul>' . implode('',$assocation) . '</ul>';?>
		<?php endif; ?>
			<?php if(isset($consultant)):?>
			<label class="type">Consultant:</label><span class="orange"></span><?php print '<ul>' . implode('',$consultant) . '</ul>';?>
		<?php endif; ?>
		</div>
<?php endif; ?>
</div>
</div>
<?php endif; ?>
