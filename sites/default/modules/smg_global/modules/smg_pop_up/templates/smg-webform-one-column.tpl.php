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

  // Print out the main part of the form.
  // Feel free to break this up and move the pieces within the array.
  //print drupal_render($form['submitted']);
?>

<div id="smg-pop-up-column-1" class="smg-pop-up-column form-wrapper">
  <?php
    foreach($form['#layout_array']['column1'] as $c1_row){
      foreach($c1_row as $c1_element){
        $c1_element_id = $c1_element['id'];
        print drupal_render($form['submitted'][$c1_element_id]);
      }
    }
  ?>
</div>

  <div class="purf__bottom-section <?php if (isset($form['my_captcha_element'])) print 'with-captcha'; ?>">
    <div id="smg-pop-up-required-note">
      * Indicates a required field
    </div>

    <div class="purf__submit-section">
      <?php

      if (isset($form['my_captcha_element'])) {
        print drupal_render($form['my_captcha_element']);
      }

      print drupal_render($form['actions']);

      ?>
    </div>
  </div>

<?php
// Always print out the entire $form. This renders the remaining pieces of the
// form that haven't yet been rendered above.
print drupal_render_children($form);
?>

<?php
  // Print out the navigation again at the bottom.
  if (isset($form['submission_info']) || isset($form['navigation'])) {
    unset($form['navigation']['#printed']);
    print drupal_render($form['navigation']);
  }
