<?php
/**
 * Adding Fixed footer
 */

$path = current_path();
$alias = drupal_lookup_path('alias', $path);
if ($alias == 'flextab-showcase') {
  drupal_add_js(drupal_get_path('theme', 'awbs') . '/js/fixed-footer-test.js', array(
    'type' => 'file',
    'async' => TRUE,
  ));
} else {
  drupal_add_js(drupal_get_path('theme', 'awbs') . '/js/fixed-footer.js', array(
    'type' => 'file',
    'async' => TRUE,
  ));
}

if($path == 'node/16109') {
  $class = 'siemens';
  $folder = 'siemens';
}
else {
  $class = 'profinet';
  $folder = 'profinet';
}
?>

<div id="fixed-footer" class="initial-hidden initial-bounce  <?php print $class; ?>">
  <div id="fixed-footer-open-tab">
    <i class="fa chevron-arrow fa-angle-double-up"></i>
    <img src="/sites/default/themes/awbs/includes/flex_gallery/profinet/UpdatedProfinetTab.png">
  </div>

  <div class="tab-border" id="fixed-footer-close-tab">X</div>
  <div id="fixed-footer-border"></div>
  <div id="fixed-footer-content">
    <iframe src="/sites/default/themes/awbs/includes/flex_gallery/<?php print $folder; ?>/index.html" width="100%" height="400" scrolling="no"></iframe>
  </div>
</div>
