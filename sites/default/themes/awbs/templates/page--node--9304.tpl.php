<?php include('includes/navmenu.php'); ?>
<div class="container awbs-advertising-header">
 <?php print render($page['header']); ?>
</div>
<div class="main-container container">
 <?php if ($tabs): ?><div class="tabs"><?php print render($tabs); ?></div><?php endif; ?>
 <div class="row">
   <section class="col-sm-12 col-md-12 awbs-subscription-page">
     <?php print render($page['content']); ?>
   </section>
 </div>
</div>
<footer class="footer container-fluid">
  <?php print render($page['footer']); ?>
  <!-- @TODO make middle columns links active @TODO make social links active -->
</footer>
