<?php include('includes/navmenu.php'); ?>
<div class="main-container container">
 <div class="row">
   <section class="col-sm-12 col-md-12 awbs-subscription-page">
      <?php include('includes/subscribe.php'); ?>
   </section>
 </div>
</div>
<script>
<?php
      print 'var postType = "' . $node->type . '";';  // type of post
      print 'var subType = "regular";'; // subtype of post (if any) (163: feature article, for example)
      if($node->field_article_length['und'][0]['value'] != 'long') {
       print 'var postLength = "short";'; // short
      } else {
       print 'var postLength = "long";'; // long
      }
?>
</script>
<footer class="footer container-fluid">
  <?php print render($page['footer']); ?>
  <!-- @TODO make middle columns links active @TODO make social links active -->
</footer>
