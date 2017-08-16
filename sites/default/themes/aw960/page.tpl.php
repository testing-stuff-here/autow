<!-- other settings are in regions.php -->
<div id="page-wrapper" class="wrapper-outer">
  <div id="header-top-wrapper" class="wrapper wrapper-header-top-wrapper">
    <div class="wrapper-inner">
      <?php print $header_top_region; ?>
    </div>
  </div><!-- /#header-top-wrapper-inner, /#header-top-wrapper -->
  <div id="header" class="wrapper wrapper-header">
    <div class="wrapper-inner">
      <?php print theme('identity', $identity_vars); ?>
    </div>
  </div><!-- /#header-inner, /#header -->
  <div id="nav" class="wrapper wrapper-navigation">
    <div class="wrapper-inner">
      <?php aw960_main_menu_style($page['menu_bar']['system_main-menu']); //modifies main menu, ticket #1762 ?>
      <?php print render($page['menu_bar']); ?>
    </div>
  </div><!-- /#navigation-inner, /#navigation -->
  <div id="header-block-wrapper-inner" class="wrapper-inner">
    <?php print $header_block_region; ?>
  </div>
  <?php if ($page['content_top']) : ?>
    <div id="content-top-wrapper-inner" class="wrapper-inner">
      <?php print $content_top_region; ?>
    </div>
  <?php endif; ?>
  <div id="container" class="wrapper wrapper-container">
    <?php if ($page['margin_left']): ?>
      <div id="margin-left-wrapper" class="wrapper">
        <?php print $margin_left_region; ?>
      </div><!-- /#margin-left-wrapper -->
    <?php endif; ?>
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
      <?php print $sidebar_second_region; ?>
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
