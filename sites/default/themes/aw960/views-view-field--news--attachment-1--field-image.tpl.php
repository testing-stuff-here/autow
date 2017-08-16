<?php
 /**
  * I created this to modify this view admin/structure/views/view/news/edit/attachment_1
  * this view is in the homepage
  */
?>
<div class="container" >
<?php //limit image title to 30 characters
if($row->field_field_image[0]['raw']['alt']){
  $limit = 30;
  $summary = $row->field_field_image[0]['raw']['alt'];
  if (strlen($summary) > $limit){ 
    $summary = substr($summary, 0, $limit) . '...';
  }
  $summary_arr = explode(' ', $summary);
  //$summary_arr= str_word_count($summary,1);
  $new_summary ='';

  // this will combine the words based on pair_total

  $pair_total = 10;
  $total = count($summary_arr);
  $index=0;
  for($ctr = 0;$ctr < $total;$ctr++){
    if (isset($summary_arr[$ctr+1])){
      $word_pairs = $summary_arr[$ctr] . ' ' . $summary_arr[$ctr+1];
    } else {
      $word_pairs = $summary_arr[$ctr];
    }
    if(strlen($word_pairs)<10){      
      $new_summary .= '<div class="altword altword-' . $index . '"><span>'.$word_pairs.'</span></div>';
      $ctr++;
    } else{
      $new_summary .= '<div class="altword altword-' . $index . '"><span>'.$summary_arr[$ctr].'</span></div>';
    }
  $index++;
  }
  
  print '<a href="/' . drupal_get_path_alias( 'node/' . $row->nid) . '"><div class="alt-text alt-text-' . $index . '">' . $new_summary . '</div></a>';
}
?>
<?php print $output; //dsm($row);?>
</div>