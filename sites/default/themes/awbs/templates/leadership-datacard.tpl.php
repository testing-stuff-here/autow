<?php
/**
 * @file
 *   Template file for the datacard block.
 */?>

<?php foreach($category_content as $taxonomy_tid => $data): ?>
  <script type="text/javascript">ga('send', 'event', 'Leadership - Datacard Category View', '<?php print $taxonomy_name[$taxonomy_tid]; ?>', 'Viewed', 0, {'nonInteraction': 1});</script>
  <h4><?php print $taxonomy_name[$taxonomy_tid]; ?></h4>
  <div class="ld-vote-message">Mouse over to browse these companies</div>
  <ul class="leadership-menu">
    <?php foreach($data as $content): ?>
      <?php if ($content->data_card_processed_for_angular['node']->status == 1): ?>
        <li ng-controller="leadershipLinkCtrl" leadership-link>
          <div class="icon-section">
            <img class="icon" src="<?php print $company_link_icon; ?>" width="16" height="13" />
          </div>
          <div class="link-section">
            <a onclick="ga('send', 'event', 'Leadership action', 'Profile click', '<?php print  $content->data_card_processed_for_angular['node']->title; ?>');" class="leadership-link" href="<?php print $content->alias; ?>" style="background-color:#FFF;"><?php print $content->title; ?></a>
            <?php if (isset($content->waywire_videos[$content->nid]->videos)): ?>
              <span class="youtube-amplified">
                <span class="circle">
                  <span class="triangle"></span>
                </span>
              </span>
            <?php endif; ?>
          </div>
          <leadership-data-card tid="<?php print $taxonomy_tid; ?>" nid="<?php print $content->datacard_nid; ?>" hover-state="hoverState" site="<?php $site_id; ?>"></leadership-data-card>
        </li>
      <?php endif; ?>
    <?php endforeach; ?>
  </ul>
<?php endforeach; ?>
