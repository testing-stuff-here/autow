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
?>
<div id="newsletter-block-body">
  <div id="newsletter-block-body-header">
    Don't miss intelligence crucial to your job and business!
  </div>
  Click on any newsletter to view a sample.  Enter your email address below to sign up!
</div>
<div id="newsletter-group-1" class="newsletter-group">
  <div class="newsletter-row newsletter-row-1">
    <div class="newsletter-item">
      <?php print drupal_render($form['submitted']['news_insights']); ?><div class="newsletter-label"><a class="newsletter-label-link" href="http://www.automationworld.com/archive-news-insights-newsletter">News Insights</a></div>
      <div class="newsletter-description">News &amp; Analysis</div>
    </div>
    <div class="newsletter-item">
      <?php print drupal_render($form['submitted']['continuous_processing']); ?><div class="newsletter-label"><a class="newsletter-label-link" href="http://www.automationworld.com/archive-process-automation-newsletter">Continuous Processing</a></div>
      <div class="newsletter-description">Oil &amp; Gas, Chemical and More</div>
    </div>
    <div class="newsletter-item">
      <?php print drupal_render($form['submitted']['factory_automation']); ?><div class="newsletter-label"><a class="newsletter-label-link" href="http://www.automationworld.com/archive-factory-automation-newsletter">Factory Automation</a></div>
      <div class="newsletter-description">Technology for Discrete Manufacturing</div>
    </div>
  </div>
  <div class="newsletter-row newsletter-row-2">
    <div class="newsletter-item">
      <?php print drupal_render($form['submitted']['product_insights']); ?><div class="newsletter-label"><a class="newsletter-label-link" href="http://www.automationworld.com/archive-product-insights-newsletter">Product Insights</a></div>
      <div class="newsletter-description">Latest Automation Products</div>
    </div>
    <div class="newsletter-item">
      <?php print drupal_render($form['submitted']['automation_skills']); ?><div class="newsletter-label"><a class="newsletter-label-link" href="http://www.automationworld.com/archive-automation-skills-newsletter">Automation Skills</a></div>
      <div class="newsletter-description">Improve Industry Skills</div>
    </div>
    <div class="newsletter-item">
      <?php print drupal_render($form['submitted']['food_bev_pharma']); ?><div class="newsletter-label"><a class="newsletter-label-link" href="http://www.automationworld.com/archive-food-bev-pharma-newsletter">Food Bev &amp; Pharma</a></div>
      <div class="newsletter-description">Automation Applications &amp; Trends</div>
    </div>
  </div>
  <div class="newsletter-row newsletter-row-3">
    <div class="newsletter-item">
      <?php print drupal_render($form['submitted']['best_of_blogs']); ?><div class="newsletter-label"><a class="newsletter-label-link" href="http://www.automationworld.com/archive-best-blogs-newsletter">Best of Blogs</a></div>
      <div class="newsletter-description">Industrial Automation Columnists</div>
    </div>
    <div class="newsletter-item">
      <?php print drupal_render($form['submitted']['industrial_internet_of_things']); ?><div class="newsletter-label"><a class="newsletter-label-link" href="/archive-industrial-internet-things">Industrial Internet of Things</a></div>
      <div class="newsletter-description">Sponsored white papers, videos and product releases on IIoT Technologies</div>
    </div>
    <div class="newsletter-item">
      <?php print drupal_render($form['submitted']['global_edition']); ?><div class="newsletter-label"><a class="newsletter-label-link" href="http://www.automationworld.com/archive/global-edition-newsletter">Global Edition</a></div>
      <div class="newsletter-description">Global automation news</div>
    </div>
  </div>
  <div class="newsletter-row newsletter-row-4">
    <div class="newsletter-item">
      <?php print drupal_render($form['submitted']['automation_focus']); ?><div class="newsletter-label"><a class="newsletter-label-link" href="http://www.automationworld.com/archive-automation-focus-newsletter">Automation Focus</a></div>
      <div class="newsletter-description">Sponsored white papers, videos and products</div>
    </div>
    <div class="newsletter-item">
      <?php print drupal_render($form['submitted']['on_the_edge']); ?><div class="newsletter-label"><a class="newsletter-label-link" href="http://ontheedgeblog.com/edge-blog-newsletters-archive">On The Edge Blog</a></div>
      <div class="newsletter-description">Workforce Development</div>
    </div>
  </div>
</div>
<div id="newsletter-group-2" class="newsletter-group">
  <div class="newsletter-row newsletter-row-1">
    <div class="newsletter-item">
      <?php print drupal_render($form['submitted']['opconnect_newsletter']); ?><div class="newsletter-label"><a class="newsletter-label-link" href="http://www.automationworld.com/archive-opconnect-newsletter">OPConnect Newsletter</a></div>
      <div class="newsletter-description"></div>
    </div>
    <div class="newsletter-item">
      <?php print drupal_render($form['submitted']['totally_integrated_automation']); ?><div class="newsletter-label"><a class="newsletter-label-link" href="http://www.automationworld.com/archive-totally-integrated-automation-newsletter">Totally Integrated Automation</a></div>
      <div class="newsletter-description"></div>
    </div>
    <div class="newsletter-item">
      <?php print drupal_render($form['submitted']['automation_strategies']); ?><div class="newsletter-label"><a class="newsletter-label-link" href="http://www.automationworld.com/archive-automation-strategies-newsletter">Automation Strategies</a></div>
      <div class="newsletter-description"></div>
    </div>
  </div>
  <div class="newsletter-row newsletter-row-2">
    <div class="newsletter-item">
      <?php print drupal_render($form['submitted']['profinews_na']); ?><div class="newsletter-label"><a class="newsletter-label-link" href="http://www.automationworld.com/archive-profinews-na-newsletter">PROFInews NA</a></div>
      <div class="newsletter-description"></div>
    </div>
    <div class="newsletter-item">
      <?php print drupal_render($form['submitted']['device_integration_strategies']); ?><div class="newsletter-label"><a class="newsletter-label-link" href="http://www.automationworld.com/archive-fdt-device-integration-strategies-newsletter">Device Integration Strategies</a></div>
      <div class="newsletter-description"></div>
    </div>
  </div>
</div>

<div id="newsletter-submit">
  <span id="newsletter-message">Each newsletter ranges in frequency from once per month to a few times per month at most.</span>
<?php
  // Print out the main part of the form.
  // Feel free to break this up and move the pieces within the array.
?>
  <div id="newsletter-submit-email">
    <?php print drupal_render($form['submitted']['email']); ?>
    <?php print drupal_render($form['submitted']); ?>
    <?php print drupal_render_children($form); ?>
  </div>
</div>

<?php
  // Print out the navigation again at the bottom.
  if (isset($form['submission_info']) || isset($form['navigation'])) {
    unset($form['navigation']['#printed']);
    print drupal_render($form['navigation']);
  }
