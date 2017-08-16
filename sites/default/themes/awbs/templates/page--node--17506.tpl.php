<?php include('includes/navmenu.php'); ?>

<div class="main-container container">
 <?php if ($tabs): ?><div class="tabs"><?php print render($tabs); ?></div><?php endif; ?>
 <div class="row">
   <section class="col-sm-12 awbs-old-prefs-page">
    <div class="row">
      <div class="col-xs-12 awbs-old-prefs-header-one">Manage newsletter preferences</div>
      <div class="col-xs-12 awbs-old-prefs-header-two">Which newsletters would you like to receive?</div>
    </div>
     <?php print render($page['content']); ?>
    </section>
    </div>
  </div>
  <footer class="footer container-fluid">
  <?php print render($page['footer']); ?>
    <!-- @TODO make middle columns links active @TODO make social links active -->
  </footer>
  <script>
  // here we pass along our post type to Javascript, in case it needs that information.
  <?php
      print 'var postType = "' . $node->type . '";';  // type of post
      print 'var subType = "subscribe";'; // subtype of post (if any) (163: feature article, for example)
      print 'var postLength = "short";'; // we always treat a feature article as long
  ?>
  </script>
