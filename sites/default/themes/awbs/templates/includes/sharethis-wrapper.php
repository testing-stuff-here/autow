<?php
/**
 * Share this wrapper.
 */
?>
<?php
// Since the new social media icons don't have the counts per the new design
// I am showing the old widget if the user is logged in. This way an editor
// can easily see the counts. - AJ

?>
<?php if (isset($node) && $node->status == TRUE): ?>
  <?php if ($logged_in): ?>
    <span class='st_twitter_hcount' displayText='Tweet'  st_via='automationworld' st_title='<?php echo $title . ' | AW'; ?>'></span>
    <span class='st_linkedin_hcount' displayText='LinkedIn'></span>
    <span class='st_facebook_hcount' displayText='Facebook'></span>
    <span class='st_email_hcount' displayText='Email article'></span>
    <span class='st_print_hcount' displayText='Print article'></span>
  <?php else: ?>
    <span class='st_floating_text'>SHARE <?= $sharetype = ($node->type == 'webinar_registration') ? 'WEBINAR:' : 'ARTICLE:'; ?></span>
    <span class='st_twitter' st_via='automationworld' st_title='<?php echo $title . ' | AW'; ?>'></span>
    <span class='st_linkedin' ></span>
    <span class='st_facebook'></span>
    <span class='st_spacer_line'></span>
    <span class='st_email'></span>
    <span class='st_print'></span>
  <?php endif; ?>
<?php endif; ?>
