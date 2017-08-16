
<?php if ($page):?>
	<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?>"<?php print $attributes; ?>>
    <div id="three-sixty-gallery">
		  <!-- <a class="back-link" href="javascript:javascript:history.go(-1)">&laquo; Back</a> -->
		  <a class="back-link" href="/360-product-review">&laquo; 360°Product Review Gallery</a>
			<div class="sharethis-wrapper">
			  <?php if($node->status == TRUE): ?>
			  <span  class='st_linkedin_hcount' displayText='LinkedIn'></span>
  			<span  class='st_twitter_hcount' displayText='Tweet' st_via='automationworld' st_title='<?php echo $title . ' | AW'; ?>'></span>
  			<span  class='st_plusone_hcount' displayText="Google +"></span>
  			<span class="st_facebook_hcount" displayText="Facebook"></span>
  			<?php endif; ?>
		  </div>
			
			<h1 id="page-title" class="rendered-title">
				<?php print $title; ?>
			</h1>
		
			<h3 class="three-sixty-gallery-button">
			  <span class="360-content-triangle">&#9654;</span> Click to expand to see product details
				<?php if(isset($supplier)):?>
			  <span class="right">
			 	  <span class="label">SUPPLIER:</span>
			    <span class="company-name"><?php print $supplier; ?></span>
			  </span>
				<?php endif; ?>
				<?php if(isset($packager)):?>
			  <span class="right">
				  <span class="label">PACKAGER:</span>
				  <span class="company-name"><?php print $packager; ?></span>	
				</span>	
				<?php endif; ?>
			</h3>
		
			<div class="clear-fix"></div>
			  <div id="three-sixty-gallery-content" style="display:none;">
		
					<?php  // Get the Deck Head 
					print '<span class="deckhead">' .	render($content['field_deckhead']) . '</span>';
					?>                    
		
					<div class="content clearfix"<?php print $content_attributes; ?>>
			      <?php print render($content['body']); ?>
					</div>          
		
			</div><!--/#three-sixty-gallery-content-->
		</div><!--/#three-sixty-gallery-->
		
    <?php if(isset($content['360'])): ?>
      <?php if(isset($content['360'])): ?>
        <div id="wrapper-360">
          <?php print render($content['360']); ?>
        </div>
      <?php endif; ?>
		  
    <?php else: ?>		
  		<?php if(isset($content['three_sixty_iframe']) && $content['three_sixty_iframe']): ?>
  		  <?php print $content['three_sixty_iframe']; ?>
  	  <?php endif; ?>
	    <div class="three-sixty-gallery-instructions"><img src="/sites/default/themes/aw960/css/images/Instructions.png" /></div>
    <?php endif; ?>
	</div><!--/#node*-->
<?php endif; /* End Page */

// Teaser 
if (!$page && arg(0)!=='print'): ?>
	<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?>"<?php print $attributes; ?>>

		<?php print $user_picture; ?>
		<div class="content clearfix"<?php print $content_attributes; ?>>
			<?php
			  // I hide elements even if they exist or not in the content type, I will print these later
				hide($content['comments']);
				hide($content['links']);
				hide($content['body']);
	      hide($content['field_deckhead']);
				hide($content['field_term_subtype']);
			  //lets begin constructing the teaser below
			  
			?>	
			<?php print render($content);  // this will print the remaining fields since most of the fields are hidden , I assume the remaining field is image ?>
			
			<div class="term">
				<span class="submitted">
			    <?php  print date( "F j, Y", $node->created);	?>
			  </span> 
			</div>
			
			
			<?php print render($title_prefix); ?>
			<h2<?php print $title_attributes; ?>>
				<a href="<?php print $node_url; ?>"><?php print preg_replace('/\[break\]/', '<br />', $title); ?>
	        <?php /*print $star;*/ ?>
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

			<?php print render($title_suffix); ?>
			<div class="content">
				<?php print render($content['field_deckhead'])?>
			</div>

		</div>

	</div>
<?php endif; ?>
