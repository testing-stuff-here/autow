/**
 * Unhides deck and body of 360 gallery nodes when someone clicks
 */
jQuery(document).ready(function($){
	
	$('h3.three-sixty-gallery-button').click(function () {
    if( $("#three-sixty-gallery-content").is(':hidden') ) {
      $('.360-content-triangle').html('&#9660;');
    }
    else {
      $('.360-content-triangle').html('&#9654;');      
    }
	  $("#three-sixty-gallery-content").toggle(400,function() {
	    /*if( $("#three-sixty-gallery-content").is(':hidden') ) {
	      //$('h3.three-sixty-gallery-button').css('background-position','0 0');        
	    }
	    else {
	      //$('h3.three-sixty-gallery-button').css('background-position','0 -48px');
	    }*/
	  }
	  );
  });	
	
	var width = $(window).width();
  if(width < 1300) {
    var newWidth = width - 120;
    $('iframe').attr('width', newWidth + 'px');
    $('iframe').attr('height', newWidth + 'px');
  }	
});