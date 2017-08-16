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
  if (isset($form['submission_info']) || isset($form['navigation'])) {
    print drupal_render($form['navigation']);
    print drupal_render($form['submission_info']);
  }
  // Instantiate the variables that might not be populated to avoid errors.
  $title = '';
  $heading = '';

  //print drupal_render($form['submitted']['new_issue_alert']);
  // Print out the main part of the form.
  // Feel free to break this up and move the pieces within the array.

  // Create the heading section of the preferences page
  print "<h1 class='preferences'>Manage newsletter preferences</h1>";
  print "<div class='preference-wrapper'>";
  print "<div class='preference-line preference-headings'>";
  print "<p class='question'>Which newsletters would you like to receive?</p>";
  print "<span class='title heading'>Name</span>";
  print "<span class='frequency heading'>Frequency</span>";
  print "<span class='blurb heading'>Description</span>";
  print "<span class='receive heading'>Receive?</span>";
  print "</div>";

  // Loop through the form items
  foreach ($form['submitted'] as $item) {
    if (is_array($item)) {
      // Only search through smg_select webform components that are yes/no
      if (($item['#webform_component']['type'] == 'smg_select') && isset($item['Yes']) &&  ($item['#webform_component']['form_key'] != 'automation_world_may_continue')) {
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
        print "<div class='preference-line'><p class='title'> " . $item['#title'] . "</p>";
        if (isset($frequency)) {
          print "<p class='frequency'>" . $frequency . "</p>";
        }
        if (isset($blurb)) {
          print "<p class='blurb'>" . $blurb . "</p>";
        }
        // This renders the select options that are the main part of the form
        print "<div class='yes-no'>";
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
  print drupal_render_children($form);

  // print out the fine print at the bottom
  print "<div class='preference-small-print'>* A no answer will permanently remove you from Automation World's list. ";
  print "The exception is if you subscribe to the digital edition of the magazine. If so, you must opt out from those ";
  print "mailings directly in order for us to comply with third-party auditors.</div>";
  print "</div>";

  // Print out the navigation again at the bottom.
  if (isset($form['submission_info']) || isset($form['navigation'])) {
    unset($form['navigation']['#printed']);
    print drupal_render($form['navigation']);
  }

?>

<address>
  PMMI Media Group<br/>
  330 N. Wabash Ave, Suite 2401<br/>
  Chicago, IL 60611<br/>
  United States of America
</address>

<?php
