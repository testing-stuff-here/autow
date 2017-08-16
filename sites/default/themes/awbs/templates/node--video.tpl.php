<?php if (!$page && arg(0)!=='print'): ?>
  <div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> col-sm-4 col-md-6 awbs-teaser-box" <?php print $attributes; ?>>
   <div class="row">
    <?php if (arg(0) == 'home'): ?>
     <div class="col-xs-12 awbs-teaser-eyebrow"><a href="/video" class="albert"><span class="awbs-eyebrow-text">Video</span></a></div>
    <?php endif; ?>
   </div>
   <div class="row awbs-teaser-image animated fadeIn">
    <div class="col-xs-12" title="<?php print $content['field_deckhead']['#items'][0]['value']; ?>">
      <a href="<?php print $node_url; ?>">
       <div class="awbs-teaser-image-image awbs-fake-play-arrow"
       <?php
        if (isset($content['field_viddler_id'])) {
         print 'style="background-image:url(' . file_create_url($content['field_viddler_id']['#items'][0]['thumbnail_url']) . ');"';
        } else {
         print 'style="background-image:url(' . url("/sites/default/themes/awbs/images/aw-placeholder.png", array('absolute' => true)) . '); background-position:center!important;"';
        }
       ?>></div>
      </a>
    </div>
   </div>
   <div class="row awbs-teaser-content animated fadeIn">
    <div class="col-xs-12 awbs-teaser-title"><a href="<?php print $node_url; ?>"><h3><?php print render($title); ?></h3></a></div>
    <div class="col-xs-12 awbs-teaser-deckhead"><?php print render($content['field_deckhead']); ?></div>
   </div>
  </div>
<?php endif; ?>


<!-- video page -->
<?php if (($page) && arg(0) !== 'print'): ?>
 <div class="col-xs-12 awbs-video-content">

 <div class="row awbs-content-top">
  <h1 class="col-xs-10 awbs-content-title"><?php print render($title); ?></h1>
  <?php if (isset($content['field_byline'])): ?>
    <div class="col-xs-12 awbs-content-byline">By <span class="awbs-content-byline-text"><?php print $content['field_byline'][0]['#markup']; ?></span>
     <?php
       if (isset($content['field_author_title'])) {
        print ', ' . $content['field_author_title']['#items'][0]['value'] . ',';
      }
     ?> on
     <span class="awbs-content-byline-date"><?php print date("F j, Y",$node->created); ?></span></div>
 <?php endif; ?>
 </div>
 <div class="row awbs-content-top">
  <div class="col-xs-12 awbs-content-sharing">
   <div class="sharethis-wrapper row">
      <div class="col-xs-12">
        <?php include('includes/sharethis-wrapper.php'); ?>
      </div>
   </div>
   </div>
 </div>

 <div class="row">
   <div class="col-xs-12 col-sm-12 col-md-8">
    <div class="row">
    <?php
            if (isset($content['field_viddler_id']) && $content['field_viddler_id']) {
              print  '<div class="col-xs-12 awbs-video-video">' . render($content['field_viddler_id']) . '</div>';
            }
    ?>
   </div>
   <div class="row awbs-video-caption-wrapper">
    <div class="col-xs-12 awbs-video-caption">
     <?php print '<div class="caption-content">' . $content['field_deckhead']['#items'][0]['value'] . '</div>'; ?>
     </div>
   </div>
   </div>
   <div class="hidden-xs hidden-sm col-md-3 col-md-offset-1">
    <?php
    $video_block = smg_global_block_render('block', 67);
    $video_block = str_replace('clearfix', 'clearfix awbs-block-image-ad" ', $video_block);
    $video_block = str_replace('hidden imuA', '', $video_block);
    ?>
    <?php print $video_block; ?>
   </div>
 </div>
</div>
<?php endif; ?>
<?php if (isset($content['leadership_videos'])) {
  print render($content['leadership_videos']);
}
?>
