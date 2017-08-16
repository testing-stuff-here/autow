<?php
/**
 * @file views-view-rss.tpl.php
 * template for feed displays that use the RSS style.
 *
 * Making this feed resemble the Joomla Feed in order for the Ap to work correctly
 */
?>
<?php print "<?xml"; ?> version="1.0" encoding="utf-8" <?php print "?>"; ?>
<rss xmlns:itunes="http://www.itunes.com/dtds/podcast-1.0.dtd" xmlns:media="http://search.yahoo.com/mrss/" version="2.0">
  <channel>
    <title><?php print $title; ?></title>
    <link><?php print $link; ?></link>
    <description><?php print $description; ?></description>
    <language><?php print $langcode; ?></language>
    <?php print $channel_elements; ?>
    <?php print $items; ?>
  </channel>
</rss>