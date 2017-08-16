<?php
/**
 * @file views-view-unformatted.tpl.php
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 *
 * I created this to create the More Headlines section  based onthe category views
 */
?>
<?php if (!empty($title)): ?>
  <h3><?php print $title; ?></h3> 
<?php endif; ?>

<?php $row_ctr = 0;$args  = arg();  ?>
<?php foreach ($rows as $id => $row): ?>
  <?php $row_ctr++; ?>
  
  <?php if ($row_ctr <=10): ?>
    <div class="<?php print $classes_array[$id]; ?>">
      <?php print $row; ?>
    </div>
  <?php endif; ?>
  
  <?php if ($row_ctr >10): ?>
    
    <?php //insert pager container 
      if ($row_ctr ==11):?>
        <div id="pager-container">[insert-pager-within]</div>
        <h2 class="headline-title">More Headines</h2>
      <?php endif; ?>
      <div class="more-headlines">
        <div class="<?php print $classes_array[$id]; ?>">
          <?php print $row; ?>
        </div>
      </div>
  <?php endif; ?>
      
<?php endforeach; ?>