

<!-- include the navmenu and the start of our body definition -->
<?php include('includes/navmenu.php'); ?>
<?php print $messages ?>
<?php $hero_image_url = file_create_url($node_content['field_image']['#items'][0]['uri']); ?>
<div class="container-fluid awbs-featured-article-hero-image" style="background-image:url(<?php print $hero_image_url; ?>)">

</div>
<div class="main-container container awbs-featured-article-content">
 <?php if ($tabs): ?><div class="tabs"><?php print render($tabs); ?></div><?php endif; ?>
 <div class="row">
   <section <?php //print $content_column_class; ?> class="col-sm-12 col-md-12">
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
       print 'var subType = "feature";'; // subtype of post (if any) (163: feature article, for example)
       print 'var postLength = "long";'; // we always treat a feature article as long

 ?>
</script>
