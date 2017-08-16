<?php // this will alter the nodes

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
  //headline star
  $star = pw960_headline_star($sourcetype,$coverage_type);

  if($content['field_term_subtype'][0]['#markup'] == 'Column'){
    if(isset($content['field_term_column_type']['#items'][0]['tid'])){
      $content['field_term_subtype'][0]['#markup'] = 'Column:';
    }
  }

?>
<?php if ($page): ?>
	<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
      <?php print $disclaimer1; ?>
      <?php if(isset($node->field_legacy['und'])&&!$node->field_legacy['und'][0]['value']): ?>
        <?php print render($content['field_term_subtype']);	?>
        <?php if($content['field_term_subtype'][0]['#markup'] == 'Column:'): ?>
          <?php print render($content['field_term_column_type']); ?>
        <?php endif; ?>
        <span class="separator"> | </span>
      <?php endif; ?>
			<span class="submitted">
				<?php // I use this to display the created date witout the author
				print date("F j, Y",$node->created);
				?>
			</span>
			<div class="sharethis-wrapper">
			  <?php if($node->status == TRUE): ?>
  				<span  class='st_linkedin_hcount' displayText='LinkedIn'></span>
    			<span  class='st_twitter_hcount' displayText='Tweet'  st_via='automationworld' st_title='<?php echo $title . ' | AW'; ?>'></span>
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
					$primary_terms = array();
					if (!isset($node->field_legacy['und'][0]) || $node->field_legacy['und'][0]['value'] == 0) {
					  if(isset($node->field_allterms['und'])){
              $limited_terms = aw960_parse_allterms($node->field_allterms['und'], 3, array('3', '11')); // exclude '3':Industry Type, '11':'Blog Beat'
  						echo "<span class='label'>FILED IN: &nbsp;</span>";

              print implode(', ',$limited_terms);
  					}
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
      // Get the Deck Head; displayed on first page only
      if(!isset($_GET['page'])){
			print '<div class="deckhead">' .	strip_tags(render($content['field_deckhead'])) . '</div>';
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

      $content_string = render($content['body']);

      $content_string .= render($content['field_waywire_video']);

      $content_string .= render($content['leadwise']);

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
        $content_string .= $companies;
      }

      //Taxonomies in Article
      if (isset($limited_terms) && $limited_terms) {
			  $taxonomies = '<div id="nodetags" class="bottom-terms">
	  			<span class="label">FILED IN: </span>';
	        $taxonomies .= implode(', ',$limited_terms);
	  		$taxonomies .= '</div>';
	      $content_string .= $taxonomies;
			}

      print $content_string;

      print render($content['ad']);
      ?>
		</div>
    <?php
      if(isset($content['leadership_videos'])) {
        print render($content['leadership_videos']);
      }
    ?>
    <?php //add long disclaimer
      print $disclaimer2;
    ?>
		<?php //this will print the subscription block from the pw_subscription module
				$block = block_load('aw_subscription', 'aw_subscription');
				$block_content = _block_render_blocks(array($block));
				$build = _block_get_renderable_array($block_content);
				$block_rendered = drupal_render($build);
				print $block_rendered;
    ?>
    <!-- <div class="comment-bar">
      <div class="comment-count"><?php print $comment_count; ?></div>
    </div>
    <div class="comments-wrapper">
      <?php print render($content['comments']); ?>
    </div> -->
	</div>
<?php endif; ?>

<?php //this will modify the teaser
if (!$page && arg(0)!=='print'): ?>
	<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
		<?php
		// lets extract the image, hide unnecessary fields
		hide($content['comments']);
		hide($content['links']);
		hide($content['body']);
		hide($content['field_deckhead']);
		hide($content['field_term_subtype']);
    hide($content['field_term_column_type']);
		// this will print the remaining fields since most of the fields are hidden , I assume the remaining field is image
		print render($content);
		?>

    <!-- If subtype is column and column type is set, add colon to end of subtype value -->
    <?php
    if($content['field_term_subtype'][0]['#markup'] == 'Column'){
      if(isset($content['field_term_column_type']['#items'][0]['tid'])){
        $content['field_term_subtype'][0]['#markup'] = 'Column:';
      }
    }

    ?>

		<?php if($is_front):?>
			<div class="term">
				<?php
				/* #1453
				//get the first L1 term
				if(isset($node->field_allterms['und'])){
				  $term = taxonomy_term_load($node->field_allterms['und'][0]['tid']); print $term->name;
			  echo '<span class="separator"> | </span>';
				}
				*/
				if(isset($node->field_legacy['und'])&&!$node->field_legacy['und'][0]['value']): ?>
		      <?php print render($content['field_term_subtype']);	?>
          <?php if($content['field_term_subtype'][0]['#markup'] == 'Column:'): ?>
            <?php print render($content['field_term_column_type']); ?>
          <?php endif; ?>
		      <span class="separator"> | </span>
		    <?php endif; ?>
				<span class="submitted">
			<?php
			  // I use this to display the created date witout the author
			  print date( "F j, Y", $node->created);
			?>
			</span>
			</div>
		<?php endif; ?>

		<?php if(!$is_front):?>
			<?php
			/* #1453
			//get the first L1 term
			if(isset($node->field_allterms['und'][1])&& !$node->field_legacy['und'][0]['value']){
			  $term = taxonomy_term_load($node->field_allterms['und'][1]['tid']);
			  print '<span class="term">' . $term->name . '</span>' ;
			  echo '<span class="separator"> | </span>';
			}
			*/

				if(isset($node->field_legacy['und'])&&!$node->field_legacy['und'][0]['value']): ?>
				  <span class="term"><?php print render($content['field_term_subtype']);?></span>
          <?php if($content['field_term_subtype'][0]['#markup'] == 'Column:'): ?>
            <?php print render($content['field_term_column_type']); ?>
          <?php endif; ?>
		      <span class="separator"> | </span>
		    <?php endif; ?>
			<span class="submitted">
			<?php
			  // I use this to display the created date witout the author
			  print date( "F j, Y", $node->created);
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

    <span style="display:none" class="headline" >
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
				<a href="<?php print url( 'node/' . $node->nid ); ?>">Full Article</a>
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
<?php


?>
<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?>"<?php print $attributes; ?>>
<div class="content clearfix"<?php print $content_attributes; ?>>
<?php if(!$node->field_legacy['und'][0]['value']): ?><?php
  if($content['field_term_subtype'][0]['#markup'] == 'Column'){
    if(isset($content['field_term_column_type']['#items'][0]['tid'])){
      $content['field_term_subtype'][0]['#markup'] = 'Column:';
    }
  }
  print render($content['field_term_subtype']) ;?>
          <?php if($content['field_term_subtype'][0]['#markup'] == 'Column:'): ?>
            <?php print render($content['field_term_column_type']); ?>
          <?php endif; ?>
          <span class="submitted"> | <?php endif; ?><?php print date( "F j, Y",$node->created); ?> </span>
<h1 id="page-title" class="rendered-title"><?php print $title; ?></h1>
<?php print '<span class="deckhead">' .	render($content['field_deckhead']) . '</span>';?>
<span class='submitted-author'>
  <b>
  <?php if(isset($author)): ?>
    By <span class="byline"><?php print $author; ?></span>
  <?php endif; ?>
  </b>
</span>
<?php print render($content['field_image']); ?>
<?php if($content['field_image'][0]['#item']['title']): ?>
  <p><?php print$content['field_image'][0]['#item']['title'] ?></p>
<?php endif;?>

<?php print render($content['field_article_images']); ?>
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
			    $association[] = '<li>' . l($node_company->title,'node/'.$node_company->nid) . '</li>';
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
			<?php if(isset($association)):?>
				<label class="type">Assocation:</label><span class="orange"></span><?php print '<ul>' . implode('',$association) . '</ul>';?>
			<?php endif; ?>
			<?php if(isset($consultant)):?>
				<label class="type">Consultant:</label><span class="orange"></span><?php print '<ul>' . implode('',$consultant) . '</ul>';?>
			<?php endif; ?>
		</div>
<?php endif; ?>
</div>
</div>
<?php endif; ?>
