<?php if ($page): ?>
  <div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?>"<?php print $attributes; ?>>
  	<?php if ($display_submitted): ?>
  	  <span class="node-type"><?php print $node_type; ?></span>
  	  <span class="separator"> | </span>
	  	<span class="submitted">
  			<?php // I use this to display the created date witout the author
  			print date( "F j, Y",$node->created);
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
		<h1 id="page-title" class="rendered-title"><?php print $title; ?></h1>

    <?php if($node->status == TRUE): ?>
      <?php include drupal_get_path('theme', 'aw960') . '/includes/share-buttons/widget-wrapper-text.inc'; ?>
    <?php endif; ?>
		<div class="widget-wrapper">
			<div class="terms">
					<?php
					// @todo - move this to template.php
					//create the "posted in" section
					$primary_terms = array();
					if (!isset($node->field_legacy['und'][0]) || $node->field_legacy['und'][0]['value'] == 0) {
					  if(isset($node->field_allterms['und'])){
  						echo "<span class='label'>FILED IN: &nbsp;</span>";
              foreach ($node->field_allterms['und'] as $termdata){
                if(!taxonomy_get_parents($termdata['tid']) && ($termdata['vid'] != 3) ){ // for all L1 terms that are not in "Industry Type (vid =3) vocabulary"
                  $term = taxonomy_term_load($termdata['tid']);
                  $primary_terms[] = l($term->name,'taxonomy/term/' . $term->tid);
                 }
              }

              $primary_terms = array_unique($primary_terms);

              // limit the terms
              $counter  = 0;
              $limit = 3;
              foreach ($primary_terms as $term){
                $limited_terms[] = $term;
                $counter++; if($counter == 3){break;}
              }

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
		  <?php if($content['body']):?>
		    <div class="deckhead"><?php print strip_tags(render($content['field_deckhead'])); ?></div>
		  <?php endif;?>

		  <?php if(isset($author)): ?>
		  <span class='submitted-author'>
		    <b>
		      By <?php print $author; ?>
		    </b>
		  </span>
		  <?php endif;?>

		  <div class="clearfix"></div>

		   <?php if(!isset($content['field_image'])):?>
        <div class="no-image">
      <?php endif; ?>

    	<div id="podcast-image-player">
    	  <?php if(isset($content['field_image'])):?>
       	  <?php print render($content['field_image']);?>
       	<?php endif; ?>
       	<div class="lower">
       	  <div class="lower-left">
         	</div>
          <div class="lower-right">
            <span class="label">PODCAST
              <span class="pipe">| &nbsp;</span>
            </span>
            <div class="podcast-body">
              <?php print render($content['body']); ?>
              <?php if(!$content['body']):?>
                  <?php print render($content['field_deckhead']); ?>
              <?php endif;?>
            </div>
          </div>
          <?php print render($content['field_podcast']); ?>
        </div>
     	</div>

     	<?php if(!isset($content['field_image'])):?>
        </div>
      <?php endif; ?>

      <div class="clearfix"></div>

     	<?php print render($content['field_sub_podcasts']); ?>

		  <?php if(isset($all_companies)): ?>
		    <div id="companies" class="bottom-terms">
  				<span class="label">COMPANIES IN THIS ARTICLE: </span>
  				<?php print $all_companies; ?>
  			</div>
			<?php endif;?>

			<?php
			// @todo move this to template.php
			if (!isset($node->field_legacy['und'][0]) || $node->field_legacy['und'][0]['value'] == 0) {
			  if(isset($node->field_allterms['und'])){
			    ?>
			    <div id="nodetags" class="bottom-terms">
  	  			<span class="label">FILED IN: </span>
  	  		<?php
			    print implode(', ',$limited_terms);
			    ?>
			    </div>
			    <?php
			  }
			}

			?>


      <!-- <div class="comment-bar">
        <div class="comment-count"><?php print $comment_count; ?></div>
      </div>
      <div class="comments-wrapper">
        <?php print render($content['comments']); ?>
      </div> -->
    </div>

    <?php if($show_block_33): ?>
      <?php print smg_global_block_render('block', 33); ?>
    <?php endif; ?>

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
		// this will print the remaining fields since most of the fields are hidden , I assume the remaining field is image
		print render($content);
		?>

    <div class="term">
      <span class="node-type"><?php print $node_type; ?></span>
      <span class="separator"> | </span>
      <span class="submitted">
        <?php // I use this to display the created date witout the author
        print date( "F j, Y",$node->created);
        ?>
      </span>
    </div>


		<?php print render($title_prefix); ?>
		<h2<?php print $title_attributes; ?>>
			<a href="<?php print $node_url; ?>"><?php print preg_replace('/\[break\]/', '<br />', $title); ?></a>
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
		</div>

	</div>
<?php endif; ?>
