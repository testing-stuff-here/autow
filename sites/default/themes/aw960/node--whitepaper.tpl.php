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
		<?php 	print '<span class="node-type">' . $types[$node->type]->name .'</span>' . '<span class="separator"> | </span>';	?>
		<span class="submitted">
		<?php // I use this to display the created date witout the author
		print date("F j, Y",$node->created);
		?>
		</span>
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

		<h1 id="page-title" class="rendered-title">
    <?php print $title;  print $star; ?>
    </h1>
    <?php if($node->status == TRUE): ?>
		  <?php include drupal_get_path('theme', 'aw960') . '/includes/share-buttons/widget-wrapper-text.inc'; ?>
		<?php endif; ?>
		<div class="widget-wrapper">
			<div class="terms">
					<?php //create the "posted in" section
					if(isset($node->field_allterms['und'])){
						echo "<span class='label'>FILED IN: &nbsp;</span>";
            $limited_terms = aw960_parse_allterms($node->field_allterms['und'], 3, array('3', '11')); // exclude '3':Industry Type, '11':'Blog Beat'

            print implode(', ',$limited_terms);
					}
					?>
			</div>
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
        // makes sure fields are enable in the content type default display
        print render($content['body']);

        // this field is rendered in the leadwise module
        print render($content['leadwise']);

        if (isset($content['field_whitepaper'][0]['#markup'])) {
          if (!isset($doc_download_btn))
            print l(t('Download White Paper'), $content['field_whitepaper'][0]['#markup'], array('attributes' => array('class' => 'blue-button2')));
          else
            print $doc_download_btn;
        }
      ?>
      <br />
      <br />

		</div>
		<?php
		if($node->type != 'blog') {
			  //Companies in Article
			if(isset($node->field_companies['und'])) {
				$companies = '<div id="companies" class="bottom-terms">
					<span class="label">COMPANIES IN THIS ARTICLE: </span>';

				$packager = $supplier = $association = $consultant = array();
				foreach ($node->field_companies['und'] as $company){
			    $node_company = node_load($company['nid']);
					$term_data = field_view_value('node', $node_company, 'field_term_company_type', $node_company->field_term_company_type['und'][0]);

          if ($term_data['#title']=='Supplier') {
            $supplier[] = l($node_company->title,'node/'.$node_company->nid);
          }
          else if($term_data['#title']=='End user') {
            $packager[] = l($node_company->title,'node/'.$node_company->nid);
          }
          else if($term_data['#title']=='Association') {
            $association[] = l($node_company->title,'node/'.$node_company->nid);
          }
					else if($term_data['#title']=='Consultant') {
            $consultant[] = l($node_company->title,'node/'.$node_company->nid);
          }
				}

				$company_array = array_merge($packager, $supplier, $association, $consultant);
				$companies .= implode(', ',	$company_array);
				$companies .= '</div>';
        print $companies;
      }

      //Taxonomies in Article
      if (isset($limited_terms)) {
			  $taxonomies = '<div id="nodetags" class="bottom-terms">
	  			<span class="label">FILED IN: </span>';
	        $taxonomies .= implode(', ',$limited_terms);
	  		$taxonomies .= '</div>';
	      print $taxonomies;
			}
		}
		?>

    <?php if(isset($content['leadership_videos'])): ?>
      <?php print render($content['leadership_videos']); ?>
    <?php endif; ?>

    <?php //add long disclaimer
      print $disclaimer2;
    ?>

		<div class="clearfix"></div>
    <!-- <div class="comment-bar">
      <div class="comment-count"><?php print $comment_count; ?></div>
    </div>
    <div class="comments-wrapper">
      <?php print render($content['comments']); ?>
    </div> -->

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
      print '<span class="term">' . $types[$node->type]->name . '</span>';echo '<span class="separator"> | </span>';
		  ?>
		  <span class="submitted">
			<?php // I use this to display the created date witout the author
			print date( "F j, Y",$node->created);
			?>
		  </span>
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
		<span class="more">
			<a href="<?php print url( 'node/' . $node->nid );?>">Full Article</a>
		</span>
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
