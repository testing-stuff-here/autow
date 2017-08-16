//collapsible comments
/*
jQuery(document).ready(function($){
var
pcounter=0,
ptotal=0,
$related_articles = $('<div id="related-articles-container"/>');
$related_articlesimage = $('<div class="imagearticles"><img src="/sites/default/themes/aw960/css/images/image_ad300x250_sample1.jpg" alt="AD 300x250" /></div>');
$related_articles.append('<div id="label">Related Articles</div>');
$related_articles.append($("#block-reltw-reltw-default"));
$related_articles.append($("#block-reltw-reltw-default-1"));
$('.node-type-article .node .field-name-body p').each( function(index, value) {
  ptotal++;
});
$('.node-type-article .node .field-name-body p').each( function(index, value) {
  pcounter++;
  if(ptotal<2){
  $(this).append($related_articles);
  } else{
    if(pcounter==2){
  $(this).append($related_articles);
    }
  }
  if(ptotal<4){
  $(this).append($related_articlesimage);
  } else{
    if(pcounter==4){
  $(this).append($related_articlesimage);
    }
  }
});
});

jQuery(document).ready(function($){
var
divtotal=0,
divcounter=0,
$qoutable = $("#block-block-26");
$('.section-operations #block-system-main .view-category-part-1 div.views-row').each( function(index, value) {
  divtotal++;
 });
$('.section-operations #block-system-main .view-category-part-1 div.views-row').each( function(index, value) {
  divcounter++;
  if(divtotal<3){
  $(this).append($qoutable);
  }else{
    if(divcounter==3){
  $(this).append($qoutable);
    }
  }
});
});
jQuery(document).ready(function($){
var
divtotal=0,
divcounter=0,
$qoutable = $("#block-block-27");
$('.section-control #block-system-main .view-category-part-1 div.views-row').each( function(index, value) {
  divtotal++;
 });
$('.section-control #block-system-main .view-category-part-1 div.views-row').each( function(index, value) {
  divcounter++;
  if(divtotal<3){
  $(this).append($qoutable);
  }else{
    if(divcounter==3){
  $(this).append($qoutable);
    }
  }
});
});
jQuery(document).ready(function($){
var
divtotal=0,
divcounter=0,
$qoutable = $("#block-block-28");
$('.section-informationmanagement #block-system-main .view-category-part-1 div.views-row').each( function(index, value) {
  divtotal++;
 });
$('.section-informationmanagement #block-system-main .view-category-part-1 div.views-row').each( function(index, value) {
  divcounter++;
  if(divtotal<3){
  $(this).append($qoutable);
  }else{
    if(divcounter==3){
  $(this).append($qoutable);
    }
  }
});
});
jQuery(document).ready(function($){
var
divtotal=0,
divcounter=0,
$qoutable = $("#block-block-29");
$('.section-safety #block-system-main .view-category-part-1 div.views-row').each( function(index, value) {
  divtotal++;
 });
$('.section-safety #block-system-main .view-category-part-1 div.views-row').each( function(index, value) {
  divcounter++;
  if(divtotal<3){
  $(this).append($qoutable);
  }else{
    if(divcounter==3){
  $(this).append($qoutable);
    }
  }
});
});
jQuery(document).ready(function($){
var
divtotal=0,
divcounter=0,
$qoutable = $("#block-block-30");
$('.section-security #block-system-main .view-category-part-1 div.views-row').each( function(index, value) {
  divtotal++;
 });
$('.section-security #block-system-main .view-category-part-1 div.views-row').each( function(index, value) {
  divcounter++;
  if(divtotal<3){
  $(this).append($qoutable);
  }else{
    if(divcounter==3){
  $(this).append($qoutable);
    }
  }
});
});
jQuery(document).ready(function($){
var
divtotal=0,
divcounter=0,
$qoutable = $("#block-block-32");
$('.section-energy #block-system-main .view-category-part-1 div.views-row').each( function(index, value) {
  divtotal++;
 });
$('.section-energy #block-system-main .view-category-part-1 div.views-row').each( function(index, value) {
  divcounter++;
  if(divtotal<3){
  $(this).append($qoutable);
  }else{
    if(divcounter==3){
  $(this).append($qoutable);
    }
  }
});
});
*/

var ga = ga || function () {}; // #305 Fixes _gaq error when admin logged in.

jQuery(document).ready(function($){
$('.page-home #block-views-main-story-block .views-field-body span').append($('.page-home #block-views-main-story-block .views-field-view-node span'));
});
jQuery(document).ready(function($){
$('.view-category-main-story .views-field-body span').append($('.view-category-main-story .views-field-view-node span'));
});

/*position the subscription text inside the article webform subscription h3*/
jQuery(document).ready(function($){
$('#webform-client-form-9301 #webform-component-description p').css('color','#4D4D4D');
$('#webform-client-form-9301 #webform-component-description p').css('display','inline');
$('#webform-client-form-9301 #webform-component-description p').css('font-size','0.7em');
$('#webform-client-form-9301 #webform-component-description p').css('margin-left','10px');
$('#webform-client-form-9301 #webform-component-description p').css('line-height','0');
$('#webform-client-form-9301 #webform-component-description p').css('position','relative');
$('#webform-client-form-9301 #webform-component-description p').css('top','0px');
$('.page-node #block-webform-client-block-9301 h3.title').append($('#webform-client-form-9301 #webform-component-description p'));
});
/*.page-node accordion tabs*/
/*used by comments and subscription block*/
jQuery(document).ready(function($){

$('.block-webform h3.title').click(function () {
  $(".block-webform .content").toggle('normal',function() {
    if( $(".block-webform .content").is(':hidden') ) {
      $('.block-webform h3.title').css('background-position','0 0');
    }
    else {
      $('.block-webform h3.title').css('background-position','0 -31px');
    }
   }
  );
});

$('h3.comments-tab').click(function () {
  $("#comments").toggle('normal',function() {
    if( $("#comments").is(':hidden') ) {
      $('h3.comments-tab').css('background-position','0 0');
    }
    else {
      $('h3.comments-tab').css('background-position','0 -31px');
    }
   }
  );
});

});
/*
(function($) {$(function() {
  var $comments = $('#comments');
  if (!$comments.size()) return;
  var count = $comments.find('.comment').size();
  // if (!count) return; // Do nothing when there is no comment.
  var label = Drupal.formatPlural(count, 'Comment (1)', 'Comments (@count)');
  var $legend = $(document.createElement('legend')).html('<span class="fieldset-legend">' + label + '</span>');
  var fsetclass = 'comments collapsible' + (location.href.search(/#(comment|new)/) == -1 ? ' collapsed' : '');

	var $fsetwrapout = $(document.createElement('div')).addClass('fieldset-wrapper-outer').attr('id', 'page-comments');
  var $fset = $(document.createElement('fieldset')).addClass(fsetclass);
  var $fsetwrap = $(document.createElement('div')).addClass('fieldset-wrapper');

	$fsetwrapout.insertBefore($comments).append($fset);

	$fset.append($legend).append($fsetwrap);
  $fsetwrap.append($comments);

  var attach = function() {Drupal.behaviors.collapse.attach($fset.parent(), Drupal.settings);};
  Drupal.behaviors.collapse ? attach() : $.getScript(Drupal.settings.basePath + 'misc/collapse.js', attach);
});})(jQuery);
*/

jQuery(document).ready(function($){ // this will add the hover effect in the frontpage news image block
  $("#block-views-news-block .attachment-after .views-row .views-field-field-image .field-content .container").hover(
    function () {
    jQuery("span", this).css('background','url("sites/default/themes/aw960/css/images/bghover.png")');
    },
    function () {
      jQuery("span", this).css('background','url("sites/default/themes/aw960/css/images/bg.png")');
    }
  );
});

//main menu dropdown functions
jQuery(document).ready(function($) {
  //preload images
  var image1 = $('<img />').attr('src', '/sites/default/themes/aw960/css/images/main-menu.png');
  var image2 = $('<img />').attr('src', '/sites/default/themes/aw960/css/images/main-menu-div.png');
  var image3 = $('<img />').attr('src', '/sites/default/themes/aw960/css/images/main-menu-div-red.png');

  /*$('#nav ul.menu ul.menu').show();
  $('#nav ul.menu li.top-level').each(function(i, e) {
    $(e).find('ul.menu li').each(function(j, f) {
      $(f).data('orig_top', $(f).position().top);
      $(f).css('top', -29 - $(f).position().top);
    });
  });
  $('#nav ul.menu ul.menu').hide();*/

  $('#nav ul.menu li.top-level').click(function() {
    $(this).children('ul.menu').toggle();
  });

  $('#nav ul.menu li.top-level').hover(
    function() {
      $(this).children('ul.menu').show();
    },
    function() {
      $(this).children('ul.menu').hide();
    }
  );

});

//change Informationmanagement menu in responsive design
jQuery(document).ready(function($){
  $('#nav ul.menu li.nolink').each(function(index) {
    if($(this).children('a').text() == 'Information Management'){
      $(this).children('a').html('<span id="part1">Information</span> <span id="part2">Management</span>');
    }
  });
});

/**
 * Function for validating the Magazine Subscription Form
 *//*
jQuery(document).ready(function($){

	var jVal = {
		'email' : function() {

			$('body').append('<div id="emailInfo" class="form-validation-info"></div>');

			var emailInfo = $('#emailInfo');
			var ele = $('#mag-subscription .email');
			var pos = ele.offset();

			emailInfo.css({
				top: pos.top-30,
				left: pos.left+ele.width()-136
			});

			var patt = /^.+@.+[.].{2,}$/i;

			if(!patt.test(ele.val())) {
				jVal.errors = true;
					emailInfo.removeClass('form-validation-correct').addClass('form-validation-error').html('&darr; Please insert a valid email!').show();
					ele.removeClass('normal').addClass('wrong');
		  	}
		    else {
				  ele.removeClass('form-validation-wrong').addClass('form-validation-normal');
					emailInfo.css('display','none');
			  }
		},
		'country' : function() {

			$('body').append('<div id="countryInfo" class="form-validation-info"></div>');

			var countryInfo = $('#countryInfo');
			var ele = $('#mag-subscription .country');
			var pos = ele.offset();

			countryInfo.css({
				top: pos.top-30,
				left: pos.left+ele.width()-136
			});

			country = $('#mag-subscription #country option:selected').html();

			if(country == 'Select a country') {
				jVal.errors = true;
				countryInfo.removeClass('form-validation-correct').addClass('form-validation-error').html('&darr; Please choose a country!').show();
				ele.removeClass('normal').addClass('wrong');
		  }
		  else {
			  ele.removeClass('form-validation-wrong').addClass('form-validation-normal');
				countryInfo.css('display','none');
			}
		},


		'sendIt' : function (){
			if(!jVal.errors) {

				$('#mag-subscription').submit();
			}
		}
	};

	$('#mag-subscription').submit(function() {

		jVal.errors = false;
		jVal.email();
		jVal.country();

  	if(jVal.errors == true) {
	   	return false;
  	}

	});


});

*/

jQuery(document).ready(function($){

	/**
	 * Fumction for validating form fields. It ads a div tag with an error message without reloading the page if it fails validation.
	 * If it fails it sets ValidationError field to true.
	 *
	 * @param id: the id of the html element
	 * @type: the type of validation it is
	 *    - length: test how many items are displayed in the field
	 *    - country: tests drowp down fields that deal with countries
	 *
	 */
	var ValidationError = null;

	jQuery.fn.validate = function(settings,to) {
		settings = jQuery.extend({
			id: null,
			type: "length",
			length: 3,
			top_position: 0,
			left_position: 0,
			message: '',
			error: false,
			multiselect: false,
			callback: function() { }
		}, settings);
		return  this.each(function() {

			// append the error div to the body.  It will be hidden
      if(settings.id) {
				$('body').append('<div id="' + settings.id + 'Info" class="form-validation-info"></div>');
				var Info = $('#' + settings.id + 'Info');
			}
			else {
				$('body').append('<div id="' + this.id + 'Info" class="form-validation-info"></div>');
				var Info = $('#' + this.id + 'Info');
			}

			var ele = $(this);
			var pos = ele.offset();

			//Get the position and set it
			Info.css({
				top: pos.top+settings.top_position,
				left: pos.left+ele.width()+settings.left_position
			});

			switch(settings.type) {
			 	/**
				 * Test Length of Field
				 */
				case 'length':

					//Verify that is less than the length field
					if(ele.val().length < settings.length) {
						validation_fail(Info, ele, settings.message);
					}
					else {
						validation_pass(Info, ele);
					}
				  break;

	    	/**
	       * Test if field is blank
	       */
			  case 'is_blank':
          if(ele.val() == '' || ele.val() == null) {
	          validation_fail(Info, ele, settings.message);
          }
					else {
						validation_pass(Info, ele);
					}
			    break;

			 /**
			  * Test if a field is a vaild email address
			  */
			  case 'email':
					var patt = /^.+@.+[.].{2,}$/i;

					if(!patt.test(ele.val())) {
						validation_fail(Info, ele, settings.message);
          }
					else {
						validation_pass(Info, ele);
					}
			    break;
			}
		});
	};

	/**
	 * Function for showing the error div if validation fails
	 *
	 * @param Info - the Info Div
	 * @param ele - the element
	 * @param message - the message to be displayed in the Info Div
	 */
	function validation_fail(Info, ele, message) {
		ValidationError = true;
		Info.removeClass('form-validation-correct').addClass('form-validation-error').html(message).show();
		ele.removeClass('form-validation-normal');
	}
	/**
	 * Function for hiding the error div if validation passes
	 *
	 * @param Info - the Info Div
	 * @param ele - the element
	 */
	function validation_pass(Info, ele) {
		//Hide the info div
	  ele.addClass('form-validation-normal');
		Info.css('display','none');
	}
	// *** Validate Enticement Block
	$('#newsletter-enticement-block .email').change(function(){
		$(this).validate({
			id: 'newsletter-enticement-block-email',
		  type: "email",
		  top_position: -30,
		  left_position: -130,
		  message: '&darr; Please insert a valid email!',
	  })
	 }
  );
	$('#newsletter-enticement-block').submit(function() {

		ValidationError = false;
		$('#newsletter-enticement-block .email').validate({
			id: 'newsletter-enticement-block-email',
			type: "email",
		  top_position: -30,
		  left_position: -130,
		  message: '&darr; Please insert a valid email!',
		});

  	if(ValidationError == true) {
	   	return false;
  	}
	});

	// *** Validate Newsletter Block
	$('#all-newsletter-signup-form .email').change(function(){
		$(this).validate({
			id: 'all-newsletter-signup-form-email',
		  type: "email",
		  top_position: -30,
		  left_position: -130,
		  message: '&darr; Please insert a valid email!',
	  })
	 }
  );
	$('#all-newsletter-signup-form form').submit(function() {

		ValidationError = false;
		$('#all-newsletter-signup-form .email').validate({
			id: 'all-newsletter-signup-form-email',
			type: "email",
		  top_position: -30,
		  left_position: -130,
		  message: '&darr; Please insert a valid email!',
		});

  	if(ValidationError == true) {
	   	return false;
  	}
	});


	// *** Validate Magazine Subscription Form
	$('#mag-subscription .email').change(function(){
		$(this).validate({
			id: 'mag-subscription-email',
		  type: "email",
		  top_position: -30,
		  left_position: -130,
		  message: '&darr; Please insert a valid email!',
	  })
	 }
  );
	$('#mag-subscription .country').change(function(){
		$(this).validate({
			id: 'mag-subscription-country',
		  type: "is_blank",
		  top_position: -30,
		  left_position: -136,
		  message: '&darr; Please choose a country!',
	  })
	 }
  );
	$('#mag-subscription').submit(function() {

		ValidationError = false;
		$('#mag-subscription .email').validate({
			id: 'mag-subscription-email',
			type: "email",
		  top_position: -30,
		  left_position: -130,
		  message: '&darr; Please insert a valid email!',
		});
		$('#mag-subscription .country').validate({
			id: 'mag-subscription-country',
			type: "is_blank",
		  top_position: -30,
		  left_position: -136,
		  message: '&darr; Please choose a country!',
		});

  	if(ValidationError == true) {
	   	return false;
  	}
	});

	// *** Validate Magazine Subscription on subscribe page
	$('#subscribe-page-form .email').change(function(){
		$(this).validate({
			id: 'subscribe-page-form-email',
		  type: "email",
		  top_position: -30,
		  left_position: -130,
		  message: '&darr; Please insert a valid email!',
	  })
	 }
  );
	$('#subscribe-page-form .country').change(function(){
		$(this).validate({
			id: 'subscribe-page-form-country',
		  type: "is_blank",
		  top_position: -30,
		  left_position: -136,
		  message: '&darr; Please choose a country!',
	  })
	 }
  );
	$('#subscribe-page-form').submit(function() {

		ValidationError = false;
		$('#subscribe-page-form .email').validate({
			id: 'subscribe-page-form-email',
			type: "email",
		  top_position: -30,
		  left_position: -130,
		  message: '&darr; Please insert a valid email!',
		});
		$('#subscribe-page-form .country').validate({
			id: 'subscribe-page-form-country',
			type: "is_blank",
		  top_position: -30,
		  left_position: -136,
		  message: '&darr; Please choose a country!',
		});

  	if(ValidationError == true) {
	   	return false;
  	}
	});

});

/**
 * Function for changing the text of the comment section
 */
jQuery(document).ready(function($){

  $('#comment-form  .form-item-mail .description').html('Email will not be displayed, it\'s just for notification if someone else comments on this same article.');

	$('#comment-form .form-item-homepage').remove();

});

jQuery(document).ready(function($) {
  // Toggle comment bar
  $(".comment-bar").click(function() {
    $(this).next().toggle(300);
  });

  // #60 Traffic Accelerator
  // Add bounce to the block and laters a blue pulse
  $('#block-block-62').addClass('animated bounce');
  $('#block-block-62').one('webkitAnimationEnd mozAnimationEnd MSAnimationEnd oanimationend animationend', function() {
    $(this).removeClass('animated');
    $(this).addClass('bluePulse');
  });
});

/**
 * #323
 */
(function($) {
  $(document).ready(function() {
    $("#edit-search-block-form--2").on("click", function() {
      if ($(this).val() === "Search ...") {
        $(this).val("");
      }
    });
    $("#edit-search-block-form--2").on("blur", function() {
      var _this = $(this);
      setTimeout(function() {
        _this.val("Search ...");
      }, 2000);
    });
  });
})(jQuery);
