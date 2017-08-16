<div class="row awbs-dropdown-row">
    <div class="col-xs-2 awbs-dropdown-row-header"><strong>Deep dive
            podcast</strong></div>
    <div class="col-xs-10">
      <?php foreach ($links as $link): ?>
          <div class="awbs-dropdown-row-item"><a
                      href="/<?php print $link->path; ?>"
                      onclick="ga('send', 'event', 'Hamburger Menu', 'Drop Down','<?php print $link->title ?>');"><?php print $link->title ?></a>
          </div>
      <?php endforeach; ?>
    <div class="awbs-dropdown-row-item read-more"><a href="/<?php print $view_all_link;?>" onclick="ga('send', 'event', 'Hamburger Menu', 'Drop Down', 'View all deep dives');">View all</a></div>
    </div>
</div>
