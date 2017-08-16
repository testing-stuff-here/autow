<?php include('includes/navmenu.php'); ?>
<div class="container awbs-advertising-header">
 <?php print render($page['header']); ?>
</div>
 <?php print $messages ?>
<div class="main-container container">
 <?php if ($tabs): ?><div class="tabs"><?php print render($tabs); ?></div><?php endif; ?>
 <div class="row">
   <div class="col-sm-12 awbs-podcast">
     <?php print render($page['content']); ?>
   </div>
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
       print 'var subType = "podcast";'; // subtype of post (if any) (163: feature article, for example)
       print 'var postLength = "short";'; // we always treat a feature article as long

 ?>
</script>
