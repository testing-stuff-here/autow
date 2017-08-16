<!DOCTYPE html>
<html lang="<?php print $language->language; ?>" dir="<?php print $language->dir; ?>"<?php print $rdf_namespaces; ?>>
<head profile="<?php print $grddl_profile; ?>">
  <?php print $head; ?>
	<title><?php print $head_title; ?></title>
	<?php print $styles; ?>
	<!--[if IE  ]><?php print om_get_ie_styles('ie'); ?><![endif]-->
	<!--[if IE 6]><?php print om_get_ie_styles('ie6'); ?><![endif]-->
	<!--[if IE 7]><?php print om_get_ie_styles('ie7'); ?><![endif]-->
	<!--[if IE 8]><?php print om_get_ie_styles('ie8'); ?><![endif]-->
	<!--[if IE 9]><?php print om_get_ie_styles('ie9'); ?><![endif]-->
	<?php print $scripts; ?>
  <!--[if lt IE 9]><script src="http://html5shiv.googlecode.com/svn/trunk/html5.js"></script><![endif]-->	
</head>
<body class="<?php print $classes; ?>" <?php print $attributes;?>>
	<div id="skip-link">
		<a href="#main-content" class="element-invisible element-focusable"><?php print t('Skip to main content'); ?></a>
	</div>
	<?php print $page_top; ?>
	<?php print $page; ?>
	<?php print $page_bottom; ?>
</body>
</html>
