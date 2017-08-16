
<?php
/**
 * @file views-view-unformatted.tpl.php
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
?>

<?php if (!$page && arg(0) !== 'print'): ?>
 <?php if (!empty($title)): ?>
   <h3><?php print $title; ?></h3>
 <?php endif; ?>
 <?php foreach ($rows as $id => $row): ?>
  <div class="<?php print $classes; ?> col-md-12 col-xs-12 awbs-teaser-box" <?php print $attributes; ?>>
   <div class="row">
    <?php print $row; ?>
  </div>
   </div>
 <?php endforeach; ?>



<?php endif; ?>
