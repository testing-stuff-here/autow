<?php //I created this to modify the display of contents

  //Disclaimers
  // see template.php
  $sourcetype = '';

  if(isset($node->field_term_source_type['und'])){
   $sourcetype = $node->field_term_source_type['und'][0]['tid'];
  }
  if(isset($node->field_term_source_type[0])){
    $sourcetype =  $node->field_term_source_type[0]['tid'];
  }
  $disclaimer1 = pw960_short_disclaimer($sourcetype );
  $disclaimer2 = pw960_long_disclaimer($sourcetype );
  $disclaimer3_marker = pw960_disclaimer3_marker($sourcetype);
  if(isset($node->field_term_coverage_type['und'][0]['tid'])) {
	  $coverage_type = $node->field_term_coverage_type['und'][0]['tid'];
  }
  else {
	  $coverage_type = '';
  }
  //headline star
  $star = pw960_headline_star($sourcetype,$coverage_type);

?>
<?php $types = node_type_get_types(); //instead of using the machine name, this will fetch the node type names?>
<?php if ($page): ?>
  <div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?>"<?php print $attributes; ?>>
    <?php print $disclaimer1; ?>
	  <?php if ($display_submitted): ?>
		<?php 	print '<span class="node-type">' . $download_subtype .'</span>'; ?>
	  <?php endif; ?>
		<div class="sharethis-wrapper">
		  <?php if($node->status == TRUE): ?>
  			<span  class='st_linkedin_hcount' displayText='LinkedIn'></span>
  			<span  class='st_twitter_hcount' displayText='Tweet' st_via='automationworld' st_title='<?php echo $title . ' | AW'; ?>'></span>
  			<span  class='st_plusone_hcount' displayText="Google +"></span>
  			<span class="st_facebook_hcount" displayText="Facebook"></span>
			<?php endif; ?>
		</div>
		<div class="clearfix"></div>

		<h1 id="page-title" class="rendered-title" <?php ($node->type == 'video' ? print 'itemprop="name"' : print "");?>>
    <?php print $title;  print $star; ?>
    </h1>
    <?php if($node->status == TRUE): ?>
		  <?php include drupal_get_path('theme', 'aw960') . '/includes/share-buttons/widget-wrapper-text.inc'; ?>
		<?php endif; ?>
		<div class="widget-wrapper">
      <?php if(isset($node->field_companies['und'])): ?>
        <div class="download-companies">
          <div class="download-companies-sponsor">Sponsor: </div><?php print $node->field_companies['und'][0]['node']->title; ?>
        </div>
      <?php endif; ?>
			<?php if($node->status == TRUE): ?>
		  	<?php include drupal_get_path('theme', 'aw960') . '/includes/share-buttons/widget-wrapper-buttons.inc'; ?>
			<?php endif; ?>
		</div>
		<div class="content clearfix"<?php print $content_attributes; ?>>

			<?php
      // this field is rendered in the pwnode module
      print render($content['slideshow']);
      if(isset($deckhead)) {
        // Set the itemprop property for Video rich snippets
        print '<div class="deckhead" itemprop="description">' .	$deckhead . '</div>';
      }
      else {
        // Get the Deck Head; displayed on first page only
        if(!isset($_GET['page'])){
  			print '<div class="deckhead">' .	strip_tags(render($content['field_deckhead'])) . '</div>';
        }
      }
      ?>

			<span class='submitted-author'>
			  <b>
			  <?php if(isset($author)): ?>
			    By <span class="byline"><?php print $author; ?></span>
			  <?php endif; ?>
			  </b>
			</span>

      <?php
        if(isset($content['field_image'])){
          print render($content['field_image']);
        }
        // makes sure fields are enable in the content type default display
        print render($content['body']);
        //this field will display the pager from smart paging
        print render($content['smart_paging']);
        // this is only for those with field "field_viddler_id"

        // this field is rendered in the leadwise module
        print render($content['leadwise']);
      ?>

      <?php if(isset($doc_download_btn)): ?>
        <div class="download-document-button-wrapper">
          <?php print $doc_download_btn; ?>
        </div>
      <?php endif; ?>

		</div>
		<?php
		if($node->type != 'blog') {

      //Taxonomies in Article
      if (isset($limited_terms)) {
			  $taxonomies = '<div id="nodetags" class="bottom-terms">
	  			<span class="label">FILED IN: </span>';

	  			// limit the terms
	        /*$counter  = 0;
	        $limited_terms = array();
	        foreach ($terms as $term){
	          $limited_terms[] = $term;
	          $counter++; if($counter == 3){break;}
	        }*/
	        $taxonomies .= implode(', ',$limited_terms);
	  		$taxonomies .= '</div>';
	      print $taxonomies;
			}
		}
		/* // this will construct the companies
		if(isset($node->field_companies['und'])) : ?>
			<div id="companies">
				<label class="title">Companies in this article:<label>
				<?php
				foreach ($node->field_companies['und'] as $company){
				$node_company = node_load($company['nid']);
				$term_data = field_view_value('node', $node_company, 'field_term_company_type', $node_company->field_term_company_type['und'][0]);
				if ($term_data['#title']=='Supplier') { $supplier[] = l($node_company->title,'node/'.$node_company->nid);}
				else if($term_data['#title']=='Packager') { $packager[] = l($node_company->title,'node/'.$node_company->nid);}
				}
				?>
				<?php if(isset($packager)):?>
					<label class="type">Packager:</label><span class="orange"></span><?php print implode(', ',$packager);?><br>
				<?php endif; ?>

				<?php if(isset($supplier)):?>
					<label class="type">Supplier:</label><span class="orange"></span><?php print implode(', ',$supplier);?>
				<?php endif; ?>
			</div>
		<?php endif; */
		?>
    <?php //add long disclaimer
      print $disclaimer2;
    ?>

		<?php if(in_array($node->type,array('article','blog','podcast','video'))):?>
			<?php //this will print the webfrom block
        print aw960_render_block('webform', 'client-block-48400');
			?>
		<div class="clearfix"></div>
    <!-- <div class="comment-bar">
      <div class="comment-count"><?php print $comment_count; ?></div>
    </div>
    <div class="comments-wrapper">
      <?php print render($content['comments']); ?>
    </div> -->

		<?php endif; ?>

		<div class="clearfix">
		  <?php if (!empty($content['links'])): ?>
			<div class="links"><?php //print render($content['links']); ?></div>
		  <?php endif; ?>
		</div>
	</div>
<?php endif; ?>

<?php //this will modify the teaser
if (!$page && arg(0)!=='print'): ?>
	<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>

	  <?php // lets extract the image, hide unnecessary fields
	  hide($content['comments']);
	  hide($content['links']);
	  hide($content['body']);
	  hide($content['field_deckhead']);
    if ($node->type == 'video') {
      print '<a href="' . url( 'node/' . $node->nid ) .'">' . render($content['field_viddler_id']) . '</a>';
    }
    else { // this will print the remaining fields since most of the fields are hidden , I assume the remaining field is image
       print render($content);
    }
    ?>

	  <?php if($is_front):?>
	  <div class="term">
		  <?php
		  /* #1453
		  //get the first L1 term
			if(isset($node->field_allterms['und'])){
		  $term = taxonomy_term_load($node->field_allterms['und'][0]['tid']); print $term->name;
		  print '<span class="separator"> | </span>';
      }
      */
      print $types[$node->type]->name;
      print '<span class="separator"> | </span>';
		  ?>
			  <span class="submitted">
				<?php // I use this to display the created date witout the author
				print date( "F j, Y",$node->created);
				?>
			  </span>
	  </div>
	  <?php endif; ?>

	  <?php if(!$is_front):?>
		  <?php
		  /* #1453
		  //get the first L1 term
			if(isset($node->field_allterms['und']) && !$node->field_legacy['und'][0]['value']){
		  $term = taxonomy_term_load($node->field_allterms['und'][1]['tid']); print '<span class="term">' . $term->name . '</span>';echo '<span class="separator"> | </span>';
		  //print '<span class="separator"> | </span>';
      }
      */
      //print '<span class="term">' . $types[$node->type]->name . '</span>';echo '<span class="separator"> | </span>';
		  ?>
		  <!-- <span class="submitted"> -->
			<?php // I use this to display the created date witout the author
			//print date( "F j, Y",$node->created);
			?>
		  <!-- </span>  -->
	  <?php endif; ?>

	  <?php print render($title_prefix); ?>
		<h2<?php print $title_attributes; ?>>
			<a href="<?php print $node_url; ?>"><?php print preg_replace('/\[break\]/', '<br />', $title); ?>
        <?php print $star; ?>
      </a>
		</h2>
	  <?php print render($title_suffix); ?>

    <span style="display:none" class="headline">
    <?php
    // I use this to display the created date and title,used by category views, so by default this is always hidden
    // Limit title
    $limit = 60;
    $summary = preg_replace('/\[break\]/', '<br />', $title);
       if (strlen($summary) > $limit){
          $summary = substr($summary, 0, strrpos(substr($summary, 0, $limit), ' ')) . '...';
          }
    ?>
    <a href="<?php print $node_url; ?>"><?php print $summary ?></a><span class="category-date"> | <?php print date("F j, Y",$node->created);?> </span>
    </span>

	  <div class="content">
		<?php print render($content['field_deckhead'])?>
		<div class="more download-tactical-more">
			<a href="<?php print url( 'node/' . $node->nid );?>">Download Tactical Brief &raquo;</a>
		</div>
      <?php
      // this will insert the marker for disclaimer 3
      // if the marker exist in the contents of home and categories, disclamer 3 will be displayed see aw_page_alteration.module
        print $disclaimer3_marker;
      ?>
	  </div>
	</div>
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
<?php print render($content['field_viddler_id']); ?>
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
