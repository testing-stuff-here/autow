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
 //dsm($form);
?>

<?php
  // If editing or viewing submissions, display the navigation at the top.
  if (isset($form['submission_info']) || isset($form['navigation'])) {
    print drupal_render($form['navigation']);
    print drupal_render($form['submission_info']);
  }

  // Print out the main part of the form.
  // Feel free to break this up and move the pieces within the array.
?>
  <div id="form-top">
    <?php print drupal_render($form['submitted']['aw_mag_request']); ?>
  </div>
  <!--<div id="form-middle">-->
    <div id="left-col" class="form-bottom-col two-column-registration">
      <?php print drupal_render($form['submitted']['email']); ?>
      <?php print drupal_render($form['submitted']['first_name']); ?>
      <?php print drupal_render($form['submitted']['last_name']); ?>
      <?php print drupal_render($form['submitted']['title']); ?>
      <?php print drupal_render($form['submitted']['company']); ?>
      <?php print drupal_render($form['submitted']['address']); ?>
      <?php print drupal_render($form['submitted']['city']); ?>
      <?php print drupal_render($form['submitted']['state_province']); ?>
      <?php print drupal_render($form['submitted']['zip']); ?>
      <?php print drupal_render($form['submitted']['country']); ?>
      <?php print drupal_render($form['submitted']['phone']); ?>
    </div>
    <div id="right-col" class="form-bottom-col two-column-registration">
      <?php print drupal_render($form['submitted']['automation_type']); ?>
      <?php print drupal_render($form['submitted']['industry']); ?>
      <?php print drupal_render($form['submitted']['other_industry']); ?>
      <?php print drupal_render($form['submitted']['job_duties']); ?>
      <?php print drupal_render($form['submitted']['other_job_duties']); ?>
      <?php print drupal_render($form['submitted']['corporate_position']); ?>
      <?php print drupal_render($form['submitted']['receive_app']); ?>
      <?php print drupal_render($form['submitted']['create_a_password']); ?>
      <?php print drupal_render($form['submitted']['personal_identifier']); ?>
    </div>
  <!--</div>-->
  <div id="form-bottom">
    <?php print drupal_render($form['actions']); ?>
    <?php print drupal_render($form['submitted']['disclaimer']); ?>
  </div>
<?php
  //print drupal_render($form['actions']);
  print drupal_render($form['submitted']);

  // Always print out the entire $form. This renders the remaining pieces of the
  // form that haven't yet been rendered above.
  print drupal_render_children($form);

  // Print out the navigation again at the bottom.
  if (isset($form['submission_info']) || isset($form['navigation'])) {
    unset($form['navigation']['#printed']);
    print drupal_render($form['navigation']);
  }

