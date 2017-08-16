/**
 * Adds onclick events to the home page river items only
 *
 * Since the home page view is a teaser view I am adding the onlick events via Javascript
 */
jQuery(document).ready(function($){
  var row_count = 15; 
  var article_position = 1;
  for (var i = 1; i <= row_count; i++) {    
    $('.view-home-river-of-content .views-row-' + i + ' .node-teaser a').attr('onclick',"_gaq.push(['_trackEvent', 'Home River Positioning', 'Article Position " + i + "']);");
  }  
});