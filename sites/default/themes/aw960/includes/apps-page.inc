<?php drupal_add_css(drupal_get_path('theme','aw960') . '/css/apps-page.css'); ?>
<div id="page-wrapper" class="wrapper-outer">
  <div id="app-page-header">
    <div id="app-header-logo">
      <img src="<?php print $app_header_logo; ?>">
    </div>
    <div id="app-header-home">
      <a href="/"><img src="<?php print $app_header_home; ?>" ></a>
    </div>
  </div>
  <div id="container" class="wrapper wrapper-container">
    <div id="container-inner" class="wrapper-inner">
      <?php //print theme('region_wrapper', _region_vars($page['quicklinks'], $quicklinks_classes, 0)); ?>
      <div id="main" class="wrapper wrapper-main">
        <?php //print $breadcrumb; ?>
        <div id="main-inner" class="wrapper wrapper-main-inner">
          <?php if (aw960_show_title($title)) : ?>
            <div id="category-title-wrapper">
              <h1 class="category-title">
                <?php print $title;?>
              </h1>
              <?php if($rss_link!="#"): ?>
                <a class="rssfeed" href="<?php print $rss_link; ?>" target="_blank"><img src="/sites/default/themes/aw960/css/images/icon_rss.png" /></a>
              <?php endif; ?> 
            </div><!-- /#category-title-wrapper -->
          <?php endif; ?> 
          <?php print theme('content_elements', $content_elements_vars); ?>
          <?php print render($page['help']); ?>
          <?php print $messages; ?>
          <?php print $content_region; ?>
          <?php //print $feed_icons; ?>
        </div><!-- /#main-inner -->
      </div><!-- /#main -->
      <div class="clearfix"></div>
    </div>
  </div><!-- /#container-inner, /#container -->
  <div id="footer-wrapper" class="wrapper wrapper-footer-wrapper">
    <div class="wrapper-inner">
      <?php print $footer_region; ?>
    </div>
  </div><!-- /#footer-wrapper-inner, /#footer-wrapper -->
  <div id="footer-wrapper-bottom" class="wrapper wrapper-footer-wrapper-bottom">
    <div class="wrapper-inner">
      <?php print $footer_bottom_region; ?>
    </div>
  </div><!-- /#footer-wrapper-bottom-inner, /#footer-wrapper-bottom -->  
  <?php print $footer_links_region ?>
</div><!-- /#page-wrapper -->
