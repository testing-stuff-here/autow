<?php include('includes/navmenu.php'); ?>
<div class="container awbs-advertising-header">
 <?php print render($page['header']); ?>
</div>
<?php print $messages ?>
<div class="main-container container">
  <?php if ($tabs): ?><div class="tabs"><?php print render($tabs); ?></div><?php endif; ?>
  <div class="row">
    <section class="col-sm-12 col-md-8">
      <?php print render($page['content']); ?>
    </section>
    <aside class="hidden-xs hidden-sm col-md-4 awbs-sidebar-overall" role="complementary">
      <?php print render($page['sidebar_second']); ?>
    </aside>
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
       print 'var subType = "profile";'; // subtype of post (if any) (163: feature article, for example)
       print 'var postLength = "short";'; // we always treat a feature article as long

 ?>
</script>
