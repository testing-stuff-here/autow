<?php

/**
 * @file
 * Customize the display of a complete webform.
 *
 * This file may be renamed "webform-form-[nid].tpl.php" to target a specific
 * webform on your site. Or you can leave it "webform-form.tpl.php" to affect
 * all webforms on your site.
 *
 * Available variables:
 * - $form: The complete form array.
 * - $nid: The node ID of the Webform.
 *
 * The $form array contains two main pieces:
 * - $form['submitted']: The main content of the user-created form.
 * - $form['details']: Internal information stored by Webform.
 */
?>
<?php
  // If editing or viewing submissions, display the navigation at the top.
  // if (isset($form['submission_info']) || isset($form['navigation'])) {
  //   print drupal_render($form['navigation']);
  //   print drupal_render($form['submission_info']);
  // }
  // Instantiate the variables that might not be populated to avoid errors.
  $title = '';
  $heading = '';

  //print drupal_render($form['submitted']['new_issue_alert']);
  // Print out the main part of the form.
  // Feel free to break this up and move the pieces within the array.


 print '<div class="row">';
 print '<div class="col-xs-12">';
 print '<div class="preferences-header row"><div class="a col-xs-4">Newsletter</div><div class="b col-xs-2">Frequency</div><div class="c col-xs-4">Description</div><div class="d col-xs-2">Receive?</div></div>';
  // Loop through the form items
  foreach ($form['submitted'] as $item) {
    if (is_array($item)) {
      // Only search through smg_select webform components that are yes/no
      if (($item['#webform_component']['type'] == 'smg_select') && (isset($item['Yes']) || isset($item['No'])) &&  ($item['#webform_component']['form_key'] != 'automation_world_may_continue')) {
        $key = $item['#webform_component']['form_key'];
        // This generates the different sections by exploding the description
        // into different elements.  Be sure that any new items are added
        // correctly.
        $description = explode(';;',$item['#description']);
        // For styling purposes the $frequency and $blurb must have content.
        // This section puts either a non-breaking space or the string from
        // the description array in the variables.
        $frequency = ($description[0] ? $description[0] : "&nbsp;");
        $blurb = ($description[1] ? $description[1] : "&nbsp; ");
        print "<div class='preference-line row'><p class='title col-xs-4'> " . $item['#title'] . "</p>";
        if (isset($frequency)) {
          print "<p class='frequency col-xs-2'>" . $frequency . "</p>";
        }
        if (isset($blurb)) {
          print "<p class='blurb col-xs-4'>" . $blurb . "</p>";
        } else {
          print "<p class='blurb col-xs-4'></p>";
        }
        // This renders the select options that are the main part of the form
        print "<div class='yes-no col-xs-2'>";
        print drupal_render($item['Yes']);
        print drupal_render($item['No']);
        print "</div>";// class yes-no
        print "</div>";// preference line
        // Tests to see if it is a yes/no question or more options.
        $result = isset($item['Yes']);
        // If $item['Yes'] is set then remove it from the array so that
        // drupal_render($form) does not render elements that have already
        // been used.
        if(isset($item['Yes'])) {
          unset($form['submitted'][$key]);
        }
      }
    }
  }

  // Always print out the entire $form. This renders the remaining pieces of the
  // form that haven't yet been rendered above.

  $form['actions']['submit']['#value'] = 'SUBMIT';
  $form['submitted']['email']['#attributes']['class'][] = 'no-req-icon';

  print drupal_render($form['submitted']['automation_world_may_continue']);
  print drupal_render($form['submitted']['discontinuing_one_or_more_newsletters']);

  print drupal_render($form['submitted']['email']);
  print '<div align="center" style="margin-top:15px; width:100%; border-right:none;" class="g-recaptcha" data-sitekey="6LfvDAwUAAAAAHepu7nm_GJC9PUnev4XL89XLn5U"></div>';
  print drupal_render_children($form);

  // print out the fine print at the bottom
  print "<div class='row'><div class='preference-small-print col-xs-12 col-md-10 col-md-offset-1'><span>*</span> A no answer will permanently remove you from Automation World's list. ";
  print "The exception is if you subscribe to the digital edition of the magazine. If so, you must opt out from those ";
  print "mailings directly in order for us to comply with third-party auditors.</div></div>";
  //print "</div>";

  // Print out the navigation again at the bottom.
  if (isset($form['submission_info']) || isset($form['navigation'])) {
    unset($form['navigation']['#printed']);
    print drupal_render($form['navigation']);
  }

?>
</div>
</div>
<script>
jQuery(function() {
 jQuery('#block-block-66').removeClass();
});
</script>
<?php
