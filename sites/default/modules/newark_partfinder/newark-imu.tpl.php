<?php
/**
 * The following javascript adds the viewd google events. Puts some delay on them because
 * we are only allowed one a second.
 */
?>
<script type="text/javascript">
  jQuery(document).ready(function($){
    setTimeout(function(){
      ga('send', 'event', 'Newark Part Finder', 'Newark Part Finder IMU', 'Viewed', 0, {'nonInteraction': 1});
    }, 2000);

    setTimeout(function(){
      ga('send', 'event', 'Newark Part Finder', '<?php print $product['Product Category']; ?>', 'Viewed', 0, {'nonInteraction': 1});
    }, 1000);
  });
</script>

<img id="newark-imu-logo" src="/sites/default/modules/newark_partfinder/css/images/newark-imu-logo.png" />
<div class="newark-title">Part Finder</div>
<form method="GET" action="http://www.newark.com/webapp/wcs/stores/servlet/Search" >
    <input type="text" class="newark-text-field" name="st" placeholder="enter MFG part number or keyword">
    <input type="hidden" name="CMP" value="">
    <input type="submit" class="search-btn newark-search-button" id="searchMain" value="Search" onClick="newark_partfinder_search_term(this.form);ga('send', 'event', 'Newark Part Finder', 'Newark Part Finder IMU Search', '<?php print $product['Product Category']; ?>');">
</form>
<div class="newark-description">Millions of products for all your engineering needs.</div>
<?php print theme('imagecache_external', array(
    'path' => $product['Image URL'],
    'style_name'=> 'newark_product',
    'alt' => $product['Product Category'],
    'attributes' => array(
      'class' => 'newark-product-photo ' . drupal_clean_css_identifier($product['Product Category']),
    ),
)); ?>
<div class="newark-category">Wide selection of <?php print $product['Product Category']; ?> available today</div>
<a href="<?php print $product['Category URL']; ?>" onClick="ga('send', 'event', 'Newark Part Finder', 'Newark Part Finder IMU Click', '<?php print $product['Product Category']; ?>');"><img src="/sites/default/modules/newark_partfinder/css/images/newark_shop_now.jpg" /></a>
<div class="newark-sponsored-by clear-fix">Part Finder Sponsored By: Newark element14</div>
