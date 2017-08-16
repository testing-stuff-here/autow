<?php
/**
 * @file views-view-fields.tpl.php
 * Default simple view template to all the fields as a row.
 *
 * - $view: The view in use.
 * - $fields: an array of $field objects. Each one contains:
 *   - $field->content: The output of the field.
 *   - $field->raw: The raw data for the field, if it exists. This is NOT output safe.
 *   - $field->class: The safe class id to use.
 *   - $field->handler: The Views field handler object controlling this field. Do not use
 *     var_export to dump this object, as it can't handle the recursion.
 *   - $field->inline: Whether or not the field should be inline.
 *   - $field->inline_html: either div or span based on the above flag.
 *   - $field->wrapper_prefix: A complete wrapper containing the inline_html to use.
 *   - $field->wrapper_suffix: The closing tag for the wrapper.
 *   - $field->separator: an optional separator that may appear before a field.
 *   - $field->label: The wrap label text to use.
 *   - $field->label_html: The full HTML of the label to use including
 *     configured element type.
 * - $row: The raw result object from the query, with all data it fetched.
 *
 * @ingroup views_templates
 */
?>
<?php //create the "posted in" section
  if (isset($row->field_field_byline) && $row->field_field_byline[0]['raw']['safe_value'] != '') {
    $fields['uid']->content = 'By ' . $row->field_field_byline[0]['raw']['safe_value'];
  } elseif (isset($row->node_uid) && ($account = user_load($row->node_uid))) {
    $fields['uid']->content = 'By ' . $account->name;
  }

  // Shorten body to a preview size
  if (isset($row->field_body)) {
    $body_summary =  text_summary($row->field_body[0]['rendered']['#markup'], 'full_html', 750);
    $body_link = l('Full Post', "node/$row->nid", array(
        'attributes' => array('class' => array('full-blog-link')),
    ));
    $fields['body']->content = $body_summary . $body_link;
  }

  // Generate taxonomoy term links: "FILED IN:"
  if(isset($row->_field_data['nid']['entity']->field_allterms['und'])) {
    $limited_terms = aw960_parse_allterms($row->_field_data['nid']['entity']->field_allterms['und'], 3, array('3', '11'));

    $fields['terms'] = (object) array(
      'wrapper_prefix' => '<div class="views-field views-field-allterms">',
      'label_html' => '',
      'content' => '<span>FILED IN:</span>' . implode(', ', $limited_terms),
      'wrapper_suffix' => '</div>',
    );
  }

  // Generate comments
  // $cids = aw960_load_comments_by_nid($row->nid);
  // $node = node_load($row->nid);
  // $comments = '';
  // foreach ($cids as $cid) {
    // $comments .= '<div class="comment-wrapper">';
    // $comment = comment_load($cid);
    // $comment_view = drupal_render(comment_view($comment, $node));
    // $comments .= '<div class="comment_view">' . $comment_view . '</div>';
    // $comments .= '</div><!-- /.comment-wrapper -->';
  // }
  // $comments_form = drupal_render(drupal_get_form('comment_node_blog_form', (object) array('nid' => $row->nid)));
  // $comments .= '<div class="comments_form">' . $comments_form . '</div>';
//
  // $fields['comment-bar'] = (object) array(
    // 'wrapper_prefix' => '<div class="comment-bar">',
    // 'label_html' => '',
    // 'content' => '<div class="comment-count">' . count($cids) . '</div>',
    // 'wrapper_suffix' => '</div>',
  // );
//
  // $fields['comments'] = (object) array(
    // 'wrapper_prefix' => '<div class="comments-wrapper">',
    // 'label_html' => '',
    // 'content' => $comments,
    // 'wrapper_suffix' => '</div><!-- /.comments-wrapper -->',
  // );

  // Define the sections of the row of content
  // and the fields which go in each
  $sections = array(
    'blog-post-top' => array('created', 'uid'),
    'blog-post-main' => array('field_image', 'title', 'field_deckhead', 'body', 'terms', 'comment-bar', 'comments'),
  );
?>

<?php foreach ($sections as $section => $ids) { ?>
  <div id="<?=$section?>">
  <?php foreach ($ids as $id) {
    $field = $fields[$id]; ?>
    <?php if (!empty($field->separator)): ?>
      <?php print $field->separator; ?>
    <?php endif; ?>

    <?php print $field->wrapper_prefix; ?>
      <?php print $field->label_html; ?>
      <?php print $field->content; ?>
    <?php print $field->wrapper_suffix; ?>
  <?php } ?>
  </div>
<?php } ?>
