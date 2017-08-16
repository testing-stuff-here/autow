<?php

/**
 * @file
 *
 * Theme functions
 */

/**
 * Implements HOOK_theme().
 */
function om_theme() {
  //dsm($type);
  return array(
    'identity' => array(
      'variables' => array('logo' => NULL, 'site_name' => NULL, 'site_slogan' => NULL, 'front_page' => NULL),
    ),
    'region_wrapper' => array( /* @Legacy - soon will be deleted */
      'variables' => array('region' => NULL, 'region_classes' => NULL, 'region_inner' => 0),
    ),
    /* #1958 Removing Title from content elements
    'content_elements' => array(
      'variables' => array('tabs' => NULL, 'prefix' => NULL, 'title' => NULL, 'suffix' => NULL, 'action' => NULL),
    ),*/
    'content_elements' => array(
      'variables' => array('tabs' => NULL, 'prefix' => NULL, 'suffix' => NULL, 'action' => NULL),
    ),   
    'menu' => array(
      'variables' => array('menu_name' => NULL, 'menu' => NULL, 'menu_tree' => NULL),
    ),              
  );
}



/**
 * Logo, Site Name, Site Slogan
 */
function om_identity($vars) {
  if (!empty($vars['logo']) || !empty($vars['site_name']) || !empty($vars['site_slogan'])) { 
    $out = '<div id="logo-title">';
    if (!empty($vars['logo'])) $out .= '<a href="' . $vars['front_page'] . '" title="' . t('Home') . '" rel="home" id="logo"><img src="' . $vars['logo'] . '" alt="' . t('Home') . '" /></a>';
    if (!empty($vars['site_name']) || !empty($vars['site_slogan'])) { 
      $out .= '<div id="name-and-slogan">';
      if (!empty($vars['site_name'])) $out .= '<h1 id="site-name"><a href="' . $vars['front_page'] . '" title="' . t('Home') . '" rel="home">' . $vars['site_name'] . '</a></h1>';
      if (!empty($vars['site_slogan'])) $out .= '<div id="site-slogan">' . $vars['site_slogan'] . '</div>';
      $out .= '</div> <!-- /#name-and-slogan -->';
    }    
    $out .= '</div> <!-- /#logo-title -->';
    return $out;
  }
}


/**
 * Main, Secondary Menus
 *
 */
function om_menu($vars) {
  if (isset($vars['menu_tree'])) return '<div id="menubar-' . $vars['menu_name'] . '" class="menubar">' . render($vars['menu_tree']) . '</div>';
}

/**
 * Added menu-id to li classes
 *
 */
function om_menu_link(array $variables) {
  $element = $variables['element'];
  $sub_menu = '';
  
  $mlid = $element['#original_link']['mlid'];
  $element['#attributes']['class'][] = 'menu-' . $mlid;
  if ($element['#below']) $sub_menu = drupal_render($element['#below']);
  
  // OM Tools integration
  if (module_exists('om_tools')) {
    $om_tools_values = variable_get('om_tools', '');
    if (isset($om_tools_values['menu']) && ($om_tools_values['menu']['menu_classes_switch'] == 1)) {
      $class = isset($om_tools_values['menu']['menu_classes_' . $mlid]) ? $om_tools_values['menu']['menu_classes_' . $mlid]: ''; 
      $element['#localized_options']['attributes']['class'][] = $class;
    }
  }
    
  $output = l($element['#title'], trim($element['#href']), $element['#localized_options']);
  return '<li' . drupal_attributes($element['#attributes']) . '>' . $output . $sub_menu . "</li>\n";
}

/**
 * Process all region formats
 *
 * @Legacy - soon will be deleted 
 * 
 */
function om_region_wrapper($vars) {
  //dsm($vars);
  if ($vars['region']) { 
    $id           = preg_replace('/_/', '-', $vars['region']['#region']);
    $classes      = $vars['region_classes'];
    $region_inner = $vars['region_inner'];
    
    $div_prefix = '<div id="' . $id . '" class="region region-' . $id . ' ' . $classes . '">'; 
    $div_suffix = '<div class="om-clearfix"></div></div><!-- /#' . $id. ' -->'; 

    if ($region_inner == 1) { 
      $div_prefix .= '<div id="' . $id . '-inner" class="region-inner">'; 
      $div_suffix = '<div class="om-clearfix"></div></div><!-- /#' . $id . '-inner --></div><!-- /#' . $id . ' -->'; 
    }
    return $div_prefix . render($vars['region']) . $div_suffix;
  }
}

/**
 * Process all region variables
 * This is an added function to satisfy the second array argument passed through theme()
 *
 * @Legacy - soon will be deleted 
 * 
 */
function _region_vars($region = NULL, $region_classes = NULL, $region_inner = 0) {
  return array('region' => $region, 'region_classes' => $region_classes, 'region_inner' => $region_inner);
}

/**
 * Preprocess variables for region.tpl.php
 *
 * Prepare the values passed to the theme_region function to be passed into a
 * pluggable template engine. Uses the region name to generate a template file
 * suggestions. If none are found, the default region.tpl.php is used.
 *
 * @see drupal_region_class()
 * @see region.tpl.php
 */
/* 
function om_preprocess_region(&$vars) {
  // get region inner variable
  //dsm($vars);
}
*/

/**
 * Returns HTML for a breadcrumb trail.
 *
 * @param $vars
 *   An associative array containing:
 *   - breadcrumb: An array containing the breadcrumb links.
 */
function om_breadcrumb($vars) {
  $breadcrumb = $vars['breadcrumb'];

  if (!empty($breadcrumb)) {
    // Provide a navigational heading to give context for breadcrumb links to
    // screen-reader users. Make the heading invisible with .element-invisible.
    $output = '<h2 class="element-invisible">' . t('You are here') . '</h2>';

    $output .= '<div class="breadcrumb">' . implode(' » ', $breadcrumb) . '</div>';
    return $output;
  }
}

/**
 * Process all content elements
 */
function om_content_elements($vars) {
  $out = '';
  if (!empty($vars['tabs']))   $out .= '<div class="tabs">' . render($vars['tabs']) . '</div>'; 
  if (!empty($vars['prefix'])) $out .= render($vars['prefix']); 
  // #1958 if (!empty($vars['title']))  $out .= '<h1 class="title" id="page-title">' . preg_replace('/\[break\]/', '<br />', $vars['title']) . '</h1>'; 
  if (!empty($vars['suffix'])) $out .= render($vars['suffix']); 
  if (!empty($vars['action'])) $out .= '<ul class="action-links">' . render($vars['action']) . '</ul>'; 
  return $out;
}

/**
 * Converts a string to a suitable html ID attribute.
 *
 * http://www.w3.org/TR/html4/struct/global.html#h-7.5.2 specifies what makes a
 * valid ID attribute in HTML. This function:
 *
 * - Ensure an ID starts with an alpha character by optionally adding an 'id'.
 * - Replaces any character except alphanumeric characters with dashes.
 * - Converts entire string to lowercase.
 *
 * @param $string
 *   The string
 * @return
 *   The converted string
 */
function om_id_safe($string) {
  // Replace with dashes anything that isn't A-Z, numbers, dashes, or underscores.
  return strtolower(preg_replace('/[^a-zA-Z0-9-]+/', '-', $string));
}

/**
 * Process variables for html.tpl.php
 *
 * Perform final addition and modification of variables before passing into
 * the template. To customize these variables, call drupal_render() on elements
 * in $vars['page'] during THEME_preprocess_page().
 *
 * @see template_preprocess_html()
 * @see html.tpl.php
 */
function om_preprocess_html(&$vars) {
  global $theme; 
  global $theme_path;
  //dsm($vars);
  $info = drupal_parse_info_file($theme_path . '/' . $theme . '.info');
        
  // general grid
  $grids_allowed = array(12, 16, 24);
  if (isset($info['settings']['grid']) && in_array($info['settings']['grid'], $grids_allowed)) $vars['classes_array'][] = ' grids-' . $info['settings']['grid']; 
    
  $vars['head_title'] = preg_replace('/\[break\]/', '', $vars['head_title']);

  // browser as body class
  $browser = om_browser_get();
  if(isset($browser['browser'])){
    $vars['classes_array'][] = om_id_safe('browser-' . $browser['browser']);
    $vars['classes_array'][] = om_id_safe('browser-' . $browser['browser'] . '-' . $browser['version']);
  }
  
	// This  functionality will soon be transferred to OM Tools
  if (!module_exists('om_tools')) {

    $classes = $vars['classes_array'];
 
    if (!$vars['is_front']) {
    
      // Add unique class for each page.
      $path = drupal_get_path_alias($_GET['q']);
      
      // path title
      $classes[] = om_id_safe('page-' . $path);
      
      // default section
      list($section) = explode('/', $path, 2);

      $arg = arg(); // get all arguments
      
      // the page must be a node
      if ($arg[0] == 'node') {
      
        // a better way of getting node types for D7
        $node = menu_get_object();       
         
        $node_type = (is_object($node)) ? $node->type: '';
              
        if (($arg[1] == 'add') && isset($arg[2])) { // add node
          $section      = 'node-add';                    
          $page_type    = $arg[2];                     
          $page_type_op = $page_type . '-add';         
        }
        elseif (($arg[1] == 'add') && !isset($arg[2])) { // add any node
          $section      = 'node-add';               
          $page_type    = 'any';                    
          $page_type_op = $page_type . '-add';           
        }          
        elseif (is_numeric($arg[1]) && !isset($arg[2]) && empty($node_type)) { // not found
          $section      = 'page-not-found';              
          $page_type    = 'any';                    
          $page_type_op = $page_type . '-view';         
        }
        elseif (is_numeric($arg[1]) && !isset($arg[2])) { // view node
          // default $section                        
          $page_type    = $node_type;                  
          $page_type_op = $page_type . '-view';          
        }					
        elseif (is_numeric($arg[1]) && isset($arg[2])) { // has arg 2, like delete, edit, etc.
          $section      = 'node-' . $arg[2];               
          $page_type    = !empty($node_type) ? $node_type: 'any';                   
          $page_type_op = $page_type . '-' . $arg[2];          
        }    
        $classes[] = om_id_safe('content-type-' . $page_type);
        $classes[] = om_id_safe('content-type-' . $page_type_op);
      }       
      $classes[] = om_id_safe('section-' . $section);
    }
    $vars['classes_array'] = $classes;
    $vars['classes'] = implode(' ', $classes); // Concatenate with spaces.	
  }
}

/**
 * Process variables for html.tpl.php
 *
 * Perform final addition and modification of variables before passing into
 * the template. To customize these variables, call drupal_render() on elements
 * in $variables['page'] during THEME_preprocess_page().
 *
 * @see template_preprocess_html()
 * @see html.tpl.php
 */
function om_process_html(&$vars) {
  global $theme; 
  global $theme_path;

  if (arg(0) == 'admin') {
    $theme = variable_get('admin_theme', 'om');
    $theme_path = drupal_get_path('theme', $theme);
  }
  
  $info = drupal_parse_info_file($theme_path . '/' . $theme . '.info');

  // addtional meta
  om_meta_get($vars, $info);
        
  // OM Grid Guides
  if (isset($info['settings']['grid_guide']) && ($info['settings']['grid_guide'] == 'on')) {
    $om_grid_buttons = '<div id="om-grid-guide-buttons"><div class="om-grid-title">OM 960 Grids</div>';
    $om_grid_buttons .= '<label><input name="om-grid-guide-button" type="radio" id="om-grid-guide-button-disabled" class="form-radio" value="" /> Disabled</label>';
    $om_grid_buttons .= '<label><input name="om-grid-guide-button" type="radio" id="om-grid-guide-button-12" class="form-radio" value="12" /> 12 Columns</label>';
    $om_grid_buttons .= '<label><input name="om-grid-guide-button" type="radio" id="om-grid-guide-button-16" class="form-radio" value="16" /> 16 Columns</label>';
    $om_grid_buttons .= '<label><input name="om-grid-guide-button" type="radio" id="om-grid-guide-button-24" class="form-radio" value="24" /> 24 Columns</label>';
    $om_grid_buttons .= '<label><input name="om-grid-guide-overlay" type="checkbox" id="om-grid-guide-overlay" class="form-checkbox" value="1" /> Overlay</label>';
    $om_grid_buttons .= '<label><input name="om-grid-guide-info" type="checkbox" id="om-grid-guide-info" class="form-checkbox" value="1" /> Info</label>';
    $om_grid_buttons .= '</div>';
  
    if (user_access('administer')) $vars['page_bottom'] .= $om_grid_buttons;
  } 
   
  // Render page_top and page_bottom into top level variables.
  date_default_timezone_set('UTC');
  $vars['page_bottom'] .= '<div id="legal"><a href="http://www.drupal.org/project/om">OM Base Theme</a> ' . date('Y') . ' | V7.x-2.x | <a href="http://www.danielhonrade.com">Daniel Honrade</a></div>';
}


/**
 * Process regions.php provided on theme
 *
 */
function om_regions_process_info($layout = NULL, $region = array(), $properties = array()) {

  if ($region) { 
    $id      = $properties['id'];
    $classes = !empty($properties['class']) ? ' ' . $properties['class']: '';
    $inner   = $properties['inner'];
    $top     = $properties['top'];
    $bottom  = $properties['bottom'];

    $excluded = array('sidebar-first', 'sidebar-second');
    // Add information about the number of sidebars.
    if (($layout == 'both') && !in_array($id, $excluded)) {
      $classes .= (isset($properties['grid-both']) && ($properties['grid-both'] != 0)) ? ' grid-' . $properties['grid-both']: '';
    }
    elseif (($layout == 'first') && !in_array($id, $excluded)) {
      $classes .= (isset($properties['grid-first']) && ($properties['grid-first'] != 0)) ? ' grid-' . $properties['grid-first']: '';
    }
    elseif (($layout == 'second') && !in_array($id, $excluded)) {
      $classes .= (isset($properties['grid-second']) && ($properties['grid-second'] != 0)) ? ' grid-' . $properties['grid-second']: '';
    }
    else {
      $classes .= (isset($properties['grid']) && ($properties['grid'] != 0)) ? ' grid-' . $properties['grid']: '';
    }
    
    $div_top     = ($top) ? '<div class="region-top"><div class="region-top-left"></div><div class="region-top-right"></div></div>': '';
    $div_bottom  = ($bottom) ? '<div class="region-bottom"><div class="region-bottom-left"></div><div class="region-bottom-right"></div></div>': '';
        
    $div_prefix = '<div id="' . $id . '" class="region region-' . $id . $classes . '">' . $div_top; 
    $div_suffix = '<div class="om-clearfix"></div>' . $div_bottom . '</div><!-- /#' . $id. ' -->'; 

    if ($inner) { 
      $div_prefix .= '<div id="' . $id . '-inner" class="region-inner">'; 
      $div_suffix = '<div class="om-clearfix"></div></div>' . $div_bottom . '</div><!-- /#' . $id . '-inner --><!-- /#' . $id . ' -->'; 
    }

    return $div_prefix . render($region) . $div_suffix;
  }
}


/**
 * Get region files
 *
 */  
function om_regions_file_get($file_name = NULL, $type = 'css') {
  global $theme;
  global $theme_path;  
  if (file_exists($theme_path . '/' . $type . '/' . $file_name . '.' . $type)) {
    $function = 'drupal_add_' . $type;
    $function($theme_path . '/' . $type . '/' . $file_name . '.' . $type);
  }  
}

    
/**
 * Override or insert variables into the page template.
 *
 */
function om_preprocess_page(&$vars) {
  global $user;
  global $theme; 
  global $theme_path;
  //dsm($vars);
  // Better processing of regions
  if (file_exists($theme_path . '/regions.php')) {
    include_once $theme_path . '/regions.php';

    $regions_system = $vars['page'];    
    $regions = om_regions_get_info();
    foreach ($regions as $region => $properties) {
      // this will just load non-empty regions
      if (isset($regions_system[$region]) && !empty($regions_system[$region])) {
        om_regions_file_get($region, 'css');
        om_regions_file_get($region, 'js');     
        $vars[$region . '_region'] = om_regions_process_info($vars['layout'], $vars['page'][$region], $properties);
        $vars[$region . '_grid'] = isset($properties['grid']) ? $properties['grid']: '';
      }
      else {
        $vars[$region . '_region'] = '';
      }
    }
  }
  
  // additional info settings  
  $info = drupal_parse_info_file($theme_path . '/' . $theme . '.info');

  // calculates middle wrapper width
  $grid        = isset($info['settings']['grid']) ? $info['settings']['grid']: 0;
  $grid_first  = isset($vars['sidebar_first_grid']) ? $vars['sidebar_first_grid']: 0;
  $grid_second = isset($vars['sidebar_second_grid']) ? $vars['sidebar_second_grid']: 0;    
  $vars['wrapper_middle_grid'] = ($grid != 0) ? ' grid-' . ($grid - ($grid_first + $grid_second)): '';

  // OM Grid Guides
  if (user_access('administer') && isset($info['settings']['grid_guide']) && ($info['settings']['grid_guide'] == 'on')) drupal_add_js(drupal_get_path('theme', 'om') . '/js/om_grids.js'); 

  // adding grid css
  $grids_allowed = array(12, 16, 24);
  if (isset($info['settings']['grid']) && in_array($info['settings']['grid'], $grids_allowed)) drupal_add_css(drupal_get_path('theme', 'om') . '/css/om_grids.css', array('group' => CSS_THEME)); 

  // activates om offline countdown
  if ($user->uid == 0) om_offline($vars, $info);
        
  // OM Tools integration
  $om_tools_values = variable_get('om_tools', '');
  $vars['title'] = drupal_get_title();
  if (module_exists('om_tools')) {
    $node = menu_get_object();        
    if ($node) {
      $node_type = (is_object($node)) ? $node->type: '';
      if (isset($om_tools_values['node']) && ($om_tools_values['node']['node_type_titles_switch'] == 1) && !empty($node_type)) {
        if ($om_tools_values['node']['node_' . $node_type . '_titles'] == 1) $vars['title'] = drupal_set_title('');
      }
    }
  }
  // OM Maximenu integration  
  if (!isset($vars['main_menu_tree']) && empty($vars['main_menu_tree'])) $vars['main_menu_tree'] = menu_tree('main-menu'); 

  // Generate menu tree from source of primary links
  $vars['main_menu_vars']        = ($vars['main_menu']) ? array('menu_name' => 'main-menu', 'menu' => $vars['main_menu'], 'menu_tree' => $vars['main_menu_tree']) : array();
  $vars['secondary_menu_tree']   = menu_tree('user-menu');
  $vars['secondary_menu_vars']   = ($vars['secondary_menu']) ? array('menu_name' => 'secondary-menu', 'menu' => $vars['secondary_menu'], 'menu_tree' => $vars['secondary_menu_tree']) : array();
  $vars['identity_vars']         = array('logo' => $vars['logo'], 'site_name' => $vars['site_name'], 'site_slogan' => $vars['site_slogan'], 'front_page' => $vars['front_page']);
  /* #1958 Removing Title from content_elements
  $vars['content_elements_vars'] = array('tabs' => $vars['tabs'], 'prefix' => $vars['title_prefix'], 'title' => $vars['title'], 'suffix' => $vars['title_suffix'], 'action' => $vars['action_links']);*/
  $vars['content_elements_vars'] = array('tabs' => $vars['tabs'], 'prefix' => $vars['title_prefix'], 'suffix' => $vars['title_suffix'], 'action' => $vars['action_links']);  
  //dsm($vars);
}

 
/**
 * Adding additional classes to blocks.
 */
function om_preprocess_block(&$vars) {

  $blocks = _block_load_blocks();
  $region = $vars['block']->region;
  $vars['classes_array'][] = drupal_html_class('block-' . $vars['block_zebra']);
  $vars['classes_array'][] = drupal_html_class('block-' . $vars['block_id']);
  if (isset($blocks[$region])) $vars['classes_array'][] = drupal_html_class('block-group-' . count($blocks[$region])); 
    
  if ($vars['block_id'] == 1) $vars['classes_array'][] = drupal_html_class('block-first');
  if (isset($blocks[$region]) && ($vars['block_id'] == count($blocks[$region]))) $vars['classes_array'][] = drupal_html_class('block-last');

} 


/**
 * Act on blocks prior to rendering.
 *
 *
function om_block_list_alter(&$blocks) {
  //dsm($blocks);
}
*/

/**
 * Get Browsers Name and Version
 *
 */
function om_browser_get($agent = NULL) {
  // Default known browsers
  $known_browsers = array('msie', 'firefox', 'safari', 'webkit', 'opera', 'netscape', 'konqueror', 'gecko');
  $agent = strtolower($agent ? $agent : $_SERVER['HTTP_USER_AGENT']);
  $pattern = '#(?<browser>' . join('|', $known_browsers) . ')[/ ]+(?<version>[0-9]+(?:\.[0-9]+)?)#';
  if (!preg_match_all($pattern, $agent, $matches)) return array();
  $i = count($matches['browser'])-1;
  $out = array();
  $out['browser'] = $matches['browser'][$i];
  $out['version'] = $matches['version'][$i];  
  return $out;
}


/**
 * Additional Meta from Info file
 *
 */
function om_offline(&$vars, $info) { 

  if (isset($info['settings']['offline']['switch']) && ($info['settings']['offline']['switch'] == 'on')) {

    $today   = getdate();
    $year    = (isset($info['settings']['countdown']['year']) && !empty($info['settings']['countdown']['year'])) ? $info['settings']['countdown']['year']: $today['year'];
    $month   = (isset($info['settings']['countdown']['month']) && !empty($info['settings']['countdown']['month'])) ? $info['settings']['countdown']['month']: 1;
    $days    = (isset($info['settings']['countdown']['days']) && !empty($info['settings']['countdown']['days'])) ? $info['settings']['countdown']['days']: 1;      
    $hours   = (isset($info['settings']['countdown']['hours']) && !empty($info['settings']['countdown']['hours'])) ? $info['settings']['countdown']['hours']: 1;      
    $minutes = (isset($info['settings']['countdown']['minutes']) && !empty($info['settings']['countdown']['minutes'])) ? $info['settings']['countdown']['minutes']: 1;      
    $seconds = (isset($info['settings']['countdown']['seconds']) && !empty($info['settings']['countdown']['seconds'])) ? $info['settings']['countdown']['seconds']: 1;      
            
    // hour, minute, second, month, day, year
    $now = (($today['year'] * 12 * 30 * 24 * 60 * 60) + ($today['mon'] * 30 * 24 * 60 * 60) + ($today['mday'] * 24 * 60 * 60)) + (($today['hours'] * 24 * 60 * 60) + ($today['minutes'] * 60 ) + $today['seconds']);
    //print $today['year'] . ' ' .  ($today['mon'] * 30) . ' ' . $today['mday'] . ' ' . ($today['hours'] * 24 * 60 * 60) . ' ' . ($today['minutes'] * 60) . ' ' . $today['seconds'] . '<br />';
    //print $now . '<br />';
    $settings_time = (($year * 12 * 30 * 24 * 60 * 60) + ($month * 30 * 24 * 60 * 60) + ($days * 24 * 60 * 60)) + (($hours * 24 * 60 * 60) + ($minutes * 60) + $seconds);
    //print $year . ' ' .  ($month * 30) . ' ' . $days . ' ' . ($hours * 24 * 60 * 60) . ' ' . ($minutes * 60) . ' ' . $seconds . '<br />';
    //print $settings_time;
    
    if ($now < $settings_time) {
      $vars['footer_region'] = om_offline_content($vars, $info);

      $countdown = '';
      $countdown .= 'jQuery(document).ready(function ($) {';
      $countdown .= '	 var onlineDay = new Date(' . $year . ', ' . $month . '-1, ' . $days . ', ' . $hours . ', ' . $minutes . ', ' . $seconds . ');';	

      $countdown .= '	 $("#om-launch-content #om-launch-counter").countdown({until: onlineDay, onExpiry: launch, alwaysExpire: true});';
      $countdown .= '	 $("body").prepend($("#om-launch-content"));';
      $countdown .= '	 $(".wrapper-outer").remove();';
      $countdown .= '	 function launch() { document.location.href = ""; };';
      $countdown .= '});';
      drupal_add_js(drupal_get_path('theme', 'om') . '/js/jquery.countdown.js'); 
      drupal_add_js($countdown, "inline"); 
      drupal_add_css(drupal_get_path('theme', 'om') . '/css/om_offline.css', array('group' => CSS_THEME));       
    } 
  }
}


/**
 * OM Offline Screen
 * 
 * - Logo
 * - Site Name
 * - Message
 * - Login
 *
 */
function om_offline_content(&$vars, $info) { 
  global $theme_path;
  $login_form = drupal_get_form('user_login');
  $out = '<div id="om-launch-content">';
  $out .= '<div id="logo"><a href="' . $vars['front_page'] . '" title="' . t('Home') . '" rel="home"><img src="' . $theme_path . '/logo.png" alt="' . t('Home') . '" /></a></div>';
  $out .= '<h1 id="site-name"><a href="' . $vars['front_page'] . '" title="' . t('Home') . '" rel="home">' . $vars['site_name'] . '</a></h1>';
  $out .= '<p>' . $info['settings']['offline']['message'] . ' ' . $vars['feed_icons'] .'</p>'; 
  $out .= '<div id="om-launch-counter"></div>';
  $out .= drupal_render($login_form);
  $out .= '</div>';
  
  return $out;
}


/**
 * Additional Meta from Info file
 *
 */
function om_meta_get(&$vars, $info) { 

  $meta = isset($info['head']['meta']) ? $info['head']['meta']: FALSE; 
  if ($meta) {
    foreach ($meta as $name => $contents) {
      if (is_array($contents)) {
        $content = '';
        $ctotal = count($contents);
        $ccount = 0;
        foreach ($contents as $ckey => $cval) {
          $ccount++;
          $csep = ($ctotal != $ccount) ? ', ': '';
          $content .= $ckey . '=' . $cval . $csep;   
        }
      }
      else {
        $content = $contents;
      }
      $diff_keys = array('cleartype', 'X-UA-Compatible');
      $name_key = (!in_array($name, $diff_keys)) ? 'name': 'http-equiv';
      $vars['head'] .= '<meta ' . $name_key . '="' . $name . '" content="' . $content . '"/>' . "\n";  
    }
  } 
}

 
/**
 * Generates IE CSS links for LTR and RTL languages.
 */

function om_get_ie_styles($ie) {
  global $language;
  global $theme; 
  $query_string = '?' . variable_get('css_js_query_string', '0');
  $iecss = '<link type="text/css" rel="stylesheet" media="all" href="' . base_path() . drupal_get_path('theme', $theme) . '/css/' . $ie . '.css' . $query_string . '"  />';
  if ($language->direction == LANGUAGE_RTL) $iecss .= '<style type="text/css" media="all">@import "' . base_path() . drupal_get_path('theme', $theme) . '/css/ie-rtl.css";</style>';
  return $iecss;
}
