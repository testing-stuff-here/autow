<?php
/**
 * @file
 *   Template file for the datacard block.
 */?>

<div class="ld-header">
  <div class="ld-header-top-text">Looking for leading suppliers?</div>
  <div class="ld-header-bottom-text">Mouse over to see these companies:</div>
</div>

<?php $category_count = 0; ?>
<?php foreach($category_content as $taxonomy_tid => $data): ?>
  <?php
  $category_count++;
  $sub_count = 1;
  $category_quantity = count($data);
  $chunk = 1;
  ?>
  <script type="text/javascript">
    ga(
      'send',
      'event',
      {
        'eventCategory' : 'Leadership Action - Category',
        'eventAction'   : '<?php print $taxonomy_name[$taxonomy_tid]; ?>',
        'eventLabel'    : 'Category Viewed in Data Card Block'
      }
    );
  </script>
  <h4><?php print $taxonomy_name[$taxonomy_tid]; ?></h4>
  <ul class="leadership-menu">
    <?php foreach($data as $content): ?>
      <?php
      if (($sub_count - 1) % 5 == 0) {
        $category_count++;
      }
      $sub_count++;
      ?>
      <?php if ($content->data_card_processed_for_angular['node']->status == 1): ?>
        <li ng-controller="leadershipLinkCtrl" category-count="<?php print $category_count; ?>" leadership-link>
          <div class="icon-section">
            <img class="icon" src="<?php print $company_link_icon; ?>" width="16" height="13" />
          </div>
          <div class="link-section">
            <a onclick="ga('send','event', {'eventCategory' : 'Leadership Action - Company', 'eventAction': '<?php print  $content->data_card_processed_for_angular['node']->title; ?>', 'eventLabel' : 'Data Card to Profile Page Click'});" class="leadership-link" href="<?php print $content->alias; ?>" style="background-color:#FFF;"><?php print $content->title; ?></a>
            <?php if (isset($content->pmg_youtube_feed_videos[$content->nid]->videos)): ?>
              <span class="youtube-amplified-video-icon"></span>
            <?php endif; ?>
          </div>
          <leadership-data-card delay-video-compile="<?php print $category_count ?>"
                                tid="<?php print $taxonomy_tid; ?>"
                                nid="<?php print $content->datacard_nid; ?>"
                                site="<?php print $site_id; ?>"
                                hover-state="hoverState"></leadership-data-card>
        </li>
      <?php endif; ?>
    <?php endforeach; ?>
  </ul>
<?php endforeach; ?>
