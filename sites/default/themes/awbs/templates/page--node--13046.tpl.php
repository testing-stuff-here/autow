<script type="text/javascript">
jQuery(document).ready(function($) {
var ep = 'Enter your email to start your free subscription';
$('#webform-client-form-13043 #edit-submitted-email').val(ep);
$('#webform-client-form-13043 #edit-submitted-email').focus(function() {
if ($(this).val() == ep) $(this).val('');
});
$('#webform-client-form-13043 #edit-submitted-country').multiselect({noneSelectedText: 'Select your country'}).multiselect('refresh');
});
</script>

<?php include('includes/navmenu.php'); ?>

<div class="main-container container">
 <?php if ($tabs): ?><div class="tabs"><?php print render($tabs); ?></div><?php endif; ?>
 <div class="row">
   <section class="col-sm-12 col-md-12 awbs-subscription-page">
         <div id="sub-container" class="row">
           <div class="col-xs-12 awbs-old-subscribe-header">Subscribe to Automation World magazine</div>
         </div>
        <div class="row">
         <div class="col-xs-12 col-md-6">
          <img src="/sites/default/themes/awbs/images/subscribeitems.png" class="img-responsive center-block">
         </div>
         <div class="col-xs-12 col-md-6">
          <div class="row">
           <div class="col-xs-12 col-md-10"?
           <?php
                $block = block_load('webform', 'client-block-13043');
                $block_content = _block_render_blocks(array($block));
                $build = _block_get_renderable_array($block_content);
                print drupal_render($build);
           ?>
          </div>
          </div>
         </div>
        </div>
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
  drupal_page_is_cacheable(false);
?>
</script>
<footer class="footer container-fluid">
  <?php print render($page['footer']); ?>
  <!-- @TODO make middle columns links active @TODO make social links active -->
</footer>
