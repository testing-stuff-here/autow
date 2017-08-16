<?php 

/*  
I created this to add a star(this will override the default field value) at the end of the title
used by Sponsored Content block
If source type is not equal to original content ( 138 )
*/
if ($output){
  if($row->field_field_term_source_type[0]['raw']['tid'] != 138){
    print '<img src="/sites/default/themes/aw960/css/images/star.png" style="width:auto !important;">';
    // this will insert the marker for disclaimer 3
    // if the marker exist in the contents of home and categories, disclamer 3 will be displayed see pw_page_alteration.module
    print '<span style="display:none;">[CustomContent/LeadGenCampaign/SupplierSubmitted]</span>';
  }
}
?>