<div id="node-<?php print $node->nid; ?>"
     class="<?php print $classes; ?> col-sm-4 col-md-4 awbs-teaser-box" <?php print $attributes; ?>>
  <div class="row awbs-teaser-image animated fadeIn">
    <div class="col-xs-12">
      <a href="<?php print $node_url; ?>">
        <div class="awbs-teaser-image-image"
        <?php
        if (isset($content['field_360_fc_large'])) {
          print 'style="background-image:url(' . image_style_url("teaser", $content['field_360_fc_large']['#items'][0]['uri']) . ');';
        }
        else {
          print 'style="background-image:url(' . url("/sites/default/themes/awbs/images/aw-placeholder.png", array('absolute' => TRUE)) . '); background-position:center!important;';
        }
        ?>"> 
      </a>
    </div>
  </div>
</div>
<div class="row awbs-teaser-content animated fadeIn">
  <div class="col-xs-12 awbs-teaser-title"><a
      href="<?php print $node_url; ?>"><h3><?php print render($title); ?></h3>
    </a></div>
  <div
    class="col-xs-12 awbs-teaser-deckhead"><?php print strip_tags(render($content['body']), '<p>, <br>, <div>'); ?></div>
</div>

