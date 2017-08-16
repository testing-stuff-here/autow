<?php
/**
 * @file views-view.tpl.php
 * Main view template
 *
 * Variables available:
 * - $classes_array: An array of classes determined in
 *   template_preprocess_views_view(). Default classes are:
 *     .view
 *     .view-[css_name]
 *     .view-id-[view_name]
 *     .view-display-id-[display_name]
 *     .view-dom-id-[dom_id]
 * - $classes: A string version of $classes_array for use in the class attribute
 * - $css_name: A css-safe version of the view name.
 * - $css_class: The user-specified classes names, if any
 * - $header: The view header
 * - $footer: The view footer
 * - $rows: The results of the view query, if any
 * - $empty: The empty text to display if the view is empty
 * - $pager: The pager next/prev links to display, if any
 * - $exposed: Exposed widget form/info to display
 * - $feed_icon: Feed icon to display, if any
 * - $more: A link to view more, if any
 *
 * @ingroup views_templates
 */
?>
<img id="gallery-arrow" src="/sites/default/themes/aw960/css/images/galleryarrow.png" />

<div class="<?php print $classes; ?>">
  <?php if ($header): ?>
    <div class="view-header">
      <?php print $header; ?>
    </div>
  <?php endif; ?>

  <?php if ($attachment_before): ?>
    <div class="attachment attachment-before">
      <?php print $attachment_before; ?>
    </div>
  <?php endif; ?>

  <?php if ($rows) { ?>
    <div class="view-content">
      <div id="view-gallery-major">
        <div id="view-gallery-major-image">
          <a href="#">
            <img src="<?php print image_style_url('image_rotator', $view->result[0]->field_field_image[0]['raw']['uri']); ?>" />
          </a>
        </div>
        <div id="view-gallery-major-title">
          <a href="#"><?php print $view->result[0]->node_title; ?></a>
        </div>
        <div id="view-gallery-major-deckhead">
          <?php print $view->result[0]->field_field_deckhead[0]['rendered']['#markup']; ?>
        </div>
      </div>
      <div id="view-gallery-minor">
        <?php print $rows; ?>
      </div>
    </div>
  <?php } elseif ($empty) { ?>
    <div class="view-empty">
      <?php print $empty; ?>
    </div>
  <?php } ?>

  <?php if ($pager): ?>
    <?php print $pager; ?>
  <?php endif; ?>

  <?php if ($attachment_after): ?>
    <div class="attachment attachment-after">
      <?php print $attachment_after; ?>
    </div>
  <?php endif; ?>

  <?php if ($more): ?>
    <?php print $more; ?>
  <?php endif; ?>

  <?php if ($footer): ?>
    <div class="view-footer">
      <?php print $footer; ?>
    </div>
  <?php endif; ?>

  <?php if ($feed_icon): ?>
    <div class="feed-icon">
      <?php print $feed_icon; ?>
    </div>
  <?php endif; ?>

</div><?php /* class view */ ?>
