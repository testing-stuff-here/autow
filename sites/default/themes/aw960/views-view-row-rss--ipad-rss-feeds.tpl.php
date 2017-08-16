<?php
/**
* @file views-view-row-rss.tpl.php
* Default view template to display a item in an RSS feed.
*
* @ingroup views_templates
*/
?>
<item>
<title><![CDATA[ <?php print $title;?> ]]></title>
<link><?php print $link; ?></link>
<description><![CDATA[ <?php print $descriptionipad;?> ]]></description>
<media:content url="<?php print $content_media; ?>">
  <media:thumbnail url="<?php print $image_thumbnail;?>" />
  <media:text type="html" lang="en"><![CDATA[ <?php print $body; ?> ]]></media:text>
</media:content>
<guid><?php print $link; ?></guid>
<author><?php print $author_name_title; ?></author>
<contentTypeName><?php print $content_type; ?></contentTypeName>
<companyName><?php print $companyName ?></companyName>
<companyUrl><?php print $companyUrl ?></companyUrl>
<pubDate><?php print $date; ?></pubDate>
</item>