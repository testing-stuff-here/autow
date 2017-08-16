<?php
 /**
  * This template is used to print a single field in a view. It is not
  * actually used in default Views, as this is registered as a theme
  * function which has better performance. For single overrides, the
  * template is perfectly okay.
  *
  * Variables available:
  * - $view: The view object
  * - $field: The field handler object that can process the input
  * - $row: The raw SQL result that can be used
  * - $output: The processed output that will normally be used.
  *
  * When fetching output from the $row, this construct should be used:
  * $data = $row->{$field->field_alias}
  *
  * The above will guarantee that you'll always get the correct data,
  * regardless of any changes in the aliasing that might happen if
  * the view is modified.
  */
?>
<?php
//print $output;
// Per #1566 Adding tracking events on the ad positions
?>
<?php
 $image_info = array(
  'style_name' => $row->field_field_image[0]['rendered']['#image_style'],
  'path' => $row->field_field_image[0]['rendered']['#item']['uri'],
  'alt' => $row->field_field_image[0]['rendered']['#item']['alt'],
);
$image = theme('image_style', $image_info);
$title = $row->_field_data['nid']['entity']->title;

print l($image, $row->field_field_link[0]['raw']['url'], array('html' => TRUE, 'attributes' => array('onclick' => "ga('send', 'event', 'Magazine Box', 'View Magazine', '" . $title . "');"))); ?>

