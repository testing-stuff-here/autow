<?php
/**
 * Template File for Leadership Voting Block
 */
?>
<div id="lia-ribben"></div>
<div class="vote center">Vote for the leaders in</div>
<h5 class="center"><?php print $category; ?></h5>
<?php print $companies; ?>
<script type="text/javascript">ga('send', 'event', 'Leadership Block', '<?php print $category; ?>', 'Viewed',{'nonInteraction': 1});</script>
<a href="<?php print $survey_link;?>" target="_blank" onclick="ga('send', 'event', 'Leadership Block', '<?php print $category; ?>', 'Click');"><img src="/<?php print drupal_get_path('module', 'leadership');?>/css/images/votenow_btn.png" alt="Vote Now Button" width="240" height="30"/></a>
<div class="visa center">Win a $150 VISA gift card!</div>
