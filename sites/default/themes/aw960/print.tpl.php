<?php

/**
 * @file
 * Default print module template
 *
 * @ingroup print
 */
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" lang="<?php print $print['language']; ?>" xml:lang="<?php print $print['language']; ?>">
  <head>
    <?php print $print['head']; ?>
    <?php print $print['base_href']; ?>
    <title><?php print $print['title']; ?></title>
    <?php print $print['css']; ?>
    <?php print $print['scripts']; ?>
    <?php print $print['sendtoprinter']; ?>
    <?php print $print['robots_meta']; ?>
    <?php print $print['favicon']; ?>
    <link rel="canonical" href="<?php print '/'. drupal_get_path_alias('node/' . arg(1)); ?>" />
   </head>
  <body>
  <div class="print-page-wrapper">
    <?php if (!empty($print['message'])) {
      print '<div class="print-message">'. $print['message'] .'</div><p />';
    } ?>
    <div class="print-logo"><?php print $print['logo']; ?></div>
    <div class="print-site_name"><?php print 'Published on the Automation World Web site'; ?></div>
    <hr class="print-hr" />
    <p><b><?php print $title; ?></b></p>
    <div class="print-content"><?php print $print['content']; ?></div>
    <div class="print-footer"><?php print $print['footer_message']; ?></div>
    <hr class="print-hr" />
    <div class="print-source_url"><?php print '<img src = "/sites/default/themes/aw960/css/images/AWicon.png">' . str_replace ('Source URL' , 'SOURCE' ,$print['source_url'] ); ?></div>
    <div class="print-links"><?php print $print['pfp_links']; ?></div>
    <!-- <div class="print-copyright">&copy; Copyright <?php print date("Y");?> Summit Media Group, Inc. This copy is for your personal, noncommercial use only. To order presentation-ready copies for distribution to your colleagues, clients or customers click <a href="http://www.summitreprints.com">HERE</a> or use the "Reprints" tool that appears next to any article. Visit <a href="http://www.summitreprints.com">www.summitreprints.com</a> for samples and additional information. Order a reprint or license this article now.</div> -->
    <?php  //print $print['footer_scripts'];?>
  </div>
  </body>
</html>
