<?php include('includes/navmenu.php'); ?>

<div class="container awbs-advertising-header">
 <?php print render($page['header']); ?>
</div>
<?php print $messages ?>
<div class="main-container container">
 <?php if ($tabs): ?><div class="tabs"><?php print render($tabs); ?></div><?php endif; ?>
 <div class="row">
   <section class="col-sm-12 col-md-12 awbs-playbook-page">
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
       print 'var subType = "playbook";'; // subtype of post (if any) (163: feature article, for example)
       print 'var postLength = "short";'; // we always treat a feature article as long

 ?>
</script>
