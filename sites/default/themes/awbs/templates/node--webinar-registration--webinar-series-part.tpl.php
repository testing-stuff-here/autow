<?php
$pre_launch = (time() <= $content['field_gotowebinar_webinar_date']['#items'][0]['value2']);
?>

<div class="row" id="node-<?php print $node->nid; ?>">
  <div class="col-md-12 awbs-webinar-title"><h2><?php print $title; ?></h2></div>
</div>
<div class="row">
  <div class="col-md-12">
    <?php if ($pre_launch) {
      $date_items = $content['field_gotowebinar_webinar_date']['#items'][0];
      $date_str = date('l, F j, Y', $date_items['value']);

      if ($date_items['value'] == $date_items['value2']) {
        $time_str = date('g:i A T', $date_items['value']);
      } else {
        $time_str = date('g:i A', $date_items['value']) . ' &mdash; ' . date('g:i A T', $date_items['value2']);
      }
      ?>
      <div class="alert alert-info awbs-webinar-soon"><b>Date:</b> <?=$date_str?> &bull; <b>Time:</b> <?=$time_str?></div>
    <?php } else { ?>
      <div class="alert alert-success awbs-webinar-available">Available now for immediate viewing.</div>
    <?php } ?>
  </div>
</div>
<div class="row">

  <div class="col-md-12 awbs-webinar-copy"><?php print $node->body['und'][0]['value']; ?></div>
</div>
