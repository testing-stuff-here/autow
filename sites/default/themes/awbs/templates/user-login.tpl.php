<div class="col-xs-12">
 <div class="row">
   <div class="col-xs-12 awbs-login-header text-center">
    LOG IN
   </div>
  </div>

 <div class="row">
  <div class="col-xs-12 col-sm-4 col-sm-offset-4 awbs-login-box">
   <?php
 /* split the username and password from the submit button
   so we can put in links above */

    print drupal_render($form['name']);
    print drupal_render($form['pass']);
    print drupal_render($form['form_build_id']);
    print drupal_render($form['form_id']);
    print drupal_render($form['actions']);

?>
  </div>
 </div>
</div>
