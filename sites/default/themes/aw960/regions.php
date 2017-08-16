<?php
/**
 * @file
 * OM Extended Regions Info
 *
 * All these will be added during preprocess page
 *
 * Properties:
 *  id     - Region ID (lower case and words separated with dash)
 *           ex. 'sidebar-first',
 *
 *  class  - Region Classes (lower case and words separated with dash)
 *           Automatically added: 'region region-region-name'
 *           ex. 'row row-1 first', 'column column-1 last',

 *  inner  - Automatically added: (0 - without, 1 - with)
 *             <div id ="region-name-inner" class="region-inner">...
 *             </div><!-- /#region-name-inner -->
 *
 *  top    - Automatically added: (0 - without, 1 - with)
 *           <div class="region-top">
 *             <div class="region-top-left"></div>
 *             <div class="region-top-right"></div>
 *           </div>
 *
 *  bottom - Automatically added: (0 - without, 1 - with)
 *           <div class="region-bottom">
 *             <div class="region-bottom-left"></div>
 *             <div class="region-bottom-right"></div>
 *           </div>
 *
 *  grids - If you turned on the 960 grid system in the .info file
 *          (12, 16, and 24 standard grids), you can automatically set
 *          the sizes of the regions just by putting the number of columns
 *          on each region (0 for disabled).
 *          Ex. 4, will output grid-4
 *
 *          Settings Override (values must be in '')
 *          Ex. '12-4', will output grid-12-4, overrides .info file when set to 16 or 24
 *              '16-4', will output grid-16-4, overrides .info file when set to 12 or 24
 *              '24-4', will output grid-24-4, overrides .info file when set to 12 or 16
 * 
 *          Depending on the presence of side bars the columns of each region can also be changed.
 *          a) 'grid'       => 16, - no side bar present
 *          b) 'grid-both   => 9,  - both side bars are present
 *          c) 'grid-first  => 12, - side bar first is present
 *          d) 'grid-second => 13, - side bar second is present
 *
 * JS and CSS for each region
 *   If you have a particular js and css for each region
 *   just place them in /js and /css folders,
 *   and name them like the region name, 
 *   ex. your_theme/js/sidebar_first.js and 
 *       your_theme/css/sidebar_first.css
 *
 */

function om_regions_get_info() {

	$regions = array();
  $regions['margin_left'] = array(
    'id'     => 'margin-left',
    'class'  => '',
    'inner'  => 0,
    'top'    => 0,
    'bottom' => 0,
    'grid'   => 0, 
  );
  $regions['header_top'] = array(
    'id'     => 'header-top',
    'class'  => '',
    'inner'  => 0,
    'top'    => 0,
    'bottom' => 0,
    'grid'   => 0, 
  ); 	
  $regions['header_block'] = array(
    'id'     => 'header-block',
    'class'  => '',
    'inner'  => 0,
    'top'    => 0,
    'bottom' => 0,
    'grid'   => 0, 
  ); 
  $regions['menu_bar'] = array(
    'id'     => 'menu-bar',
    'class'  => '',
    'inner'  => 0,
    'top'    => 0,
    'bottom' => 0,
    'grid'   => 0, 
  );
  $regions['content_top'] = array(
    'id'     => 'content-top',
    'class'  => '',
    'inner'  => 0,
    'top'    => 0,
    'bottom' => 0,
    'grid'   => 0, 
  ); 
  $regions['sidebar_second'] = array(
    'id'     => 'sidebar-second',
    'class'  => '',
    'inner'  => 0,
    'top'    => 0,
    'bottom' => 0,
    'grid'   => 0, 
  ); 
  $regions['content'] = array(
    'id'     => 'content',
    'class'  => '',
    'inner'  => 0,
    'top'    => 0,
    'bottom' => 0,
    'grid'   => 0, 
    // these can be added to any region, see description above
    //'grid-both'   => 0,
    //'grid-first'  => 0,
    //'grid-second' => 0,
  ); 
  $regions['footer'] = array(
    'id'     => 'footer',
    'class'  => '',
    'inner'  => 0,
    'top'    => 0,
    'bottom' => 0,
    'grid'   => 0, 
  ); 
  $regions['footer_bottom'] = array(
    'id'     => 'footer-bottom',
    'class'  => '',
    'inner'  => 0,
    'top'    => 0,
    'bottom' => 0,
    'grid'   => 0, 
  ); 
  $regions['footer_links'] = array(
    'id'     => 'footer-links',
    'class'  => '',
    'inner'  => 1,
    'top'    => 0,
    'bottom' => 0,
    'grid'   => 0, 
  ); 		
  return $regions;
}



