<div class="row awbs-dropdown-row">
  <div class="col-xs-2 awbs-dropdown-row-header"><strong>Webinars</strong></div>
  <div class="col-xs-10">
    <?php foreach ($nodes as $node): ?>
      <?php $alias = drupal_get_path_alias('node/' . $node->nid); ?>
      <div class="awbs-dropdown-row-item"><a href="<?php print $alias ?> " onclick="ga('send', 'event', 'Hamburger Menu', 'Drop Down','<?php print $node->title ?>');"><?php print $node->title ?></a></div>
    <?php endforeach; ?>
    <div class="awbs-dropdown-row-item read-more"><a href="/webinars" onclick="ga('send', 'event', 'Hamburger Menu', 'Drop Down', 'View all webinars');">View all</a></div>
  </div>
</div>
