<?php
/**
 * @file
 * Default theme implementation to display a block.
 *
 * Available variables:
 * - $block->subject: Block title.
 * - $content: Block content.
 * - $block->module: Module that generated the block.
 * - $block->delta: An ID for the block, unique within each module.
 * - $block->region: The block region embedding the current block.
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. The default values can be one or more of the
 *   following:
 *   - block: The current template type, i.e., "theming hook".
 *   - block-[module]: The module generating the block. For example, the user
 *     module is responsible for handling the default user navigation block. In
 *     that case the class would be 'block-user'.
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 *
 * Helper variables:
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 * - $block_zebra: Outputs 'odd' and 'even' dependent on each block region.
 * - $zebra: Same output as $block_zebra but independent of any block region.
 * - $block_id: Counter dependent on each block region.
 * - $id: Same output as $block_id but independent of any block region.
 * - $is_front: Flags true when presented in the front page.
 * - $logged_in: Flags true when the current user is a logged-in member.
 * - $is_admin: Flags true when the current user is an administrator.
 * - $block_html_id: A valid HTML ID and guaranteed unique.
 *
 * @see bootstrap_preprocess_block()
 * @see template_preprocess()
 * @see template_preprocess_block()
 * @see bootstrap_process_block()
 * @see template_process()
 *
 * @ingroup themeable
 */
?>
<section id="<?php print $block_html_id; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>

<div class="row awbs-pb-enticement-banner">
<div class="col-xs-12 col-md-10 awbs-pb-enticement-content-wrapper tactical">
<div class="row">
<div class="col-xs-12 col-md-8 awbs-pb-enticement-content-header"><a href="<?php print $content['links']['node']['#links']['node-readmore']['href']; ?>"><?php print $title; ?></a></div>

<div class="col-xs-12 col-md-2 pull-right"><img src="<?php print file_create_url($content['field_image']['#items'][0]['uri']); ?>"></div>
<div class="col-xs-12 col-md-10 awbs-pb-enticement-content-body"><?php print $content['field_deckhead']['#items'][0]['safe_value']; ?></div>

<div class="col-xs-12 col-md-4 pull-left awbs-pb-enticement-content-link"><a class="btn btn-sm btn-block awbs-btn" href="/<?php print $content['links']['node']['#links']['node-readmore']['href']; ?>">Download</a></div>

</div>
</div>

</div>

</section> <!-- /.block -->