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
  // if (isset($form['submission_info']) || isset($form['navigation'])) {
  //   print drupal_render($form['navigation']);
  //   print drupal_render($form['submission_info']);
  // }

  // Print out the main part of the form.
  // Feel free to break this up and move the pieces within the array.
?>

<div class="row">

<div class="col-xs-12 col-md-4">
 <div class="row">
  <div class="col-xs-12">
 	 <img alt="Automation World Magazine Cover" src="/sites/default/themes/awbs/images/subscribeitems.png" class="img-responsive center-block"/>
 </div>
</div>

<div class="row awbs-old-subscribe-cta">
 <div class="col-xs-12">
 <div class="cta-text">FREE Subscription Application</div>
 <p>Automation World magazine is available free of charge to qualified subscribers. Qualified subscribers in the U.S. will receive the printed edition. (Qualified subscribers outside the U.S. will receive the digital edition, sent by email.)</p>
</div>
</div>

</div>

<div class="col-xs-12 col-md-7 col-md-offset-1">
  <div id="form-top" class="row">
    <div class="col-xs-12">
     <?php print drupal_render($form['submitted']['aw_mag_request']); ?>
   </div>
  </div>
  <div class="row">
   <div class="col-xs-12">
  <!--<div id="form-middle">-->
  <span id="user-information">
     <?php $form['submitted']['email']['#attributes']['class'][] = 'awbs-input no-req-icon'; ?>
      <?php print drupal_render($form['submitted']['email']); ?>
      <?php $form['submitted']['first_name']['#attributes']['class'][] = 'awbs-input no-req-icon'; ?>
      <?php print drupal_render($form['submitted']['first_name']); ?>
      <?php $form['submitted']['last_name']['#attributes']['class'][] = 'awbs-input no-req-icon'; ?>
      <?php print drupal_render($form['submitted']['last_name']); ?>
      <?php $form['submitted']['title']['#attributes']['class'][] = 'awbs-input no-req-icon'; ?>
      <?php print drupal_render($form['submitted']['title']); ?>
      <?php $form['submitted']['company']['#attributes']['class'][] = 'awbs-input no-req-icon'; ?>
      <?php print drupal_render($form['submitted']['company']); ?>
      <?php $form['submitted']['address']['#attributes']['class'][] = 'awbs-input no-req-icon'; ?>
      <?php print drupal_render($form['submitted']['address']); ?>
      <?php $form['submitted']['city']['#attributes']['class'][] = 'awbs-input no-req-icon'; ?>
      <?php print drupal_render($form['submitted']['city']); ?>
     <span id="user-information-mid">
      <?php $form['submitted']['state_province']['#attributes']['class'][] = 'awbs-select no-req-icon shorty'; ?>
      <?php print drupal_render($form['submitted']['state_province']); ?>
      <?php $form['submitted']['zip']['#attributes']['class'][] = 'awbs-input no-req-icon shorty'; ?>
      <?php print drupal_render($form['submitted']['zip']); ?>
      <?php $form['submitted']['country']['#attributes']['class'][] = 'awbs-select no-req-icon shorty'; ?>
      <?php print drupal_render($form['submitted']['country']); ?>
      <?php $form['submitted']['phone']['#attributes']['class'][] = 'awbs-input no-req-icon shorty'; ?>
      <?php print drupal_render($form['submitted']['phone']); ?>
    </span>
  </span>
  <span id="user-details">
      <?php print drupal_render($form['submitted']['automation_type']); ?>
      <?php print drupal_render($form['submitted']['industry']); ?>
      <?php print drupal_render($form['submitted']['other_industry']); ?>
      <?php print drupal_render($form['submitted']['job_duties']); ?>
      <?php print drupal_render($form['submitted']['other_job_duties']); ?>
      <?php print drupal_render($form['submitted']['systems_integration']); ?>
      <?php print drupal_render($form['submitted']['employed_count']); ?>
      <span id="user-details-radio"><?php print drupal_render($form['submitted']['corporate_position']); ?></span>
      <?php print drupal_render($form['submitted']['receive_app']); ?>
      <?php print drupal_render($form['submitted']['create_a_password']); ?>
      <?php print drupal_render($form['submitted']['personal_identifier']); ?>
  </span>
    </div>
   </div>
  <!--</div>-->
  <div id="form-bottom" class="row">
   <div class="col-xs-12">
   <div align="center" style="margin-top:15px; border-right:none;" class="g-recaptcha" data-sitekey="6LfvDAwUAAAAAHepu7nm_GJC9PUnev4XL89XLn5U"></div>
    <?php print drupal_render($form['actions']); ?>
    <?php print drupal_render($form['submitted']['disclaimer']); ?>
   </div>
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
?>
 </div>
</div>
