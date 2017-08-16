<?php foreach ($items as $item): ?>
  <?php
    $node = array_shift($item['node']);
    $node_object = node_load($node['#entity_view_mode']['id']);
    $pre_launch = (time() <= $node_object->field_gotowebinar_webinar_date[LANGUAGE_NONE][0]['value2']);
  ?>
  <div class="row">
    <h2 class="webinar-name">
      <?php print $node_object->title; ?>
    </h2>
    <div class="webinar-date">
      <?php if ($pre_launch) {
        $date_items = $node_object->field_gotowebinar_webinar_date[LANGUAGE_NONE][0];
        $date_str = date('l, F j, Y', $date_items['value']);

        if ($date_items['value'] == $date_items['value2']) {
          $time_str = date('g:i A T', $date_items['value']);
        }
        else {
          $time_str = date('g:i A', $date_items['value']) . ' &mdash; ' . date('g:i A T', $date_items['value2']);
        }
        ?>
        <div class="alert alert-info awbs-webinar-soon">
          <b>Date:</b> <?= $date_str ?> &bull; <b>Time:</b> <?= $time_str ?>
        </div>
      <?php }
      else { ?>
        <div class="alert alert-success awbs-webinar-available">Available now for immediate viewing.</div>
      <?php } ?>
    </div>
    <div class="col-md-4 col-sm-4 webinar-speakers-column">
      <div class="awbs-webinar-speakers-header">
        <h3>Speakers</h3>
      </div>
      <div class="awbs-webinar-speakers">
        <?php print render($node['field_expert']); ?>
      </div>
    </div>
      <div id="webinar-body" class="col-md-8 col-sm-8">
        <?php print render($node['body']); ?>
      </div>
  </div>
<?php endforeach; ?>
