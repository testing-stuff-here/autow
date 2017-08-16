
<?php if (!$page && arg(0) !== 'print'): ?>
	<div id="node-<?php print $node->nid; ?>" class="col-sm-6 col-md-6 awbs-teaser-box animated fadeIn" <?php print $attributes; ?>>
		<div class="row">
			<?php if (arg(0) == 'home'): ?>
				<div class="col-xs-12 awbs-teaser-eyebrow"><a href="/360-product-review" class="albert"><span class="awbs-eyebrow-text">360 Product Reviews</span></a></div>
			<?php endif; ?>
		</div>
		<div class="row awbs-teaser-image animated fadeIn">
			<div class="col-xs-12" title="<?php print $content['field_deckhead']['#items'][0]['value']; ?>">
					<a href="<?php print $node_url; ?>">
						<div class="awbs-teaser-image-image"
						<?php
							if (isset($content['field_image'])) {
								print 'style="background-image:url(' . image_style_url('three_sixty_gallery_block' ,$content['field_image']['#items'][0]['uri']) . ');';
							} else {
								print 'style="background-image:url(' . url("/sites/default/themes/awbs/images/aw-placeholder.png", array('absolute' => true)) . '); background-position:center!important;';
							}
						?>">
						</div>
					</a>
			</div>
		</div>
		<div class="row awbs-teaser-content animated fadeIn">
			<div class="col-xs-12 awbs-teaser-title"><a href="<?php print $node_url; ?>"><h3><?php print render($title); ?></h3></a></div>
			<div class="col-xs-12 awbs-teaser-deckhead"><?php print render($content['field_deckhead']); ?></div>
		</div>
	</div>
<?php endif; ?>



<?php if (($page) && arg(0) !== 'print'): ?>
	<div id="node-<?php print $node->nid; ?>" class="col-xs-12 awbs-360-content" <?php print $attributes; ?>>
  <div class="row awbs-content-top">
 		<h1 class="col-xs-12 col-md-9 awbs-content-title"><?php print $title; ?></h1>
   <div class="col-xs-12">

				<div class="row">
					<div class="col-xs-12 awbs-content-sharing">
						<div class="sharethis-wrapper row">
							<div class="col-xs-12">
								<?php include('includes/sharethis-wrapper.php'); ?>
							</div>
						</div>
					</div>
		   </div>

     <div class="col-xs-12 awbs-360-details-dropdown">
						<div class="row">
							<div class="col-xs-12 col-md-4 awbs-360-details-dropdown-cta" id="awbs-360-click-for-details"><i class="fa fa-fw fa-caret-right"></i> Click here for more details</div>
							<?php
							$options = array('absolute' => TRUE);
							$url = url('node/' . $content['field_companies'][0]['#href'], $options);
							$url = drupal_lookup_path('alias', $content['field_companies'][0]['#href']);
							?>
							<div class="col-xs-12 col-md-8 awbs-360-details-dropdown-company"><span>SUPPLIER:</span> <?php print "<a href='" . $url . "'>" . $content['field_companies'][0]['#title'] . "</a>"; ?></div>
						 <div class="col-xs-12 col-md-11 col-md-offset-1 awbs-360-details-dropdown-contents">
								<div class="row">
								<?php print	'<div class="col-xs-12 awbs-360-details-dropdown-contents-deckhead">' . render($content['field_deckhead']) . '</div>'; ?>
								<?php print '<div class="col-xs-12 awbs-360-details-dropdown-contents-content">' . render($content['body']) . '</div>'; ?>
							</div>
							</div>
						</div>
					</div>


					<div class="col-xs-12 awbs-360-image-wrapper">
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
    </div>

			</div>
	</div><!--/#node*-->
<?php endif; /* End Page */
