var $ = jQuery; // I don't feel like typing jQuery() a thousand times. No one should *want* that.

jQuery(function() { // wait for DOM to load... as one does.

 if (!Modernizr.input.list) { // Ask Modernizr if the browser supports autofill dropdown lists
  $.webshims.polyfill(); // if it doesn't, then we'll shim in a polyfill.
 }

 // NEXT UP: handle navbar scrolling effect.
 var awbsNavbar = $(".navwrapper"); // grab the navwrapper DOM element
 var menuVis = VisSense(awbsNavbar[0], {
  fullyvisible: 0.2
 }); // instantiate the VisSense library, which will "listen" for changes to the elements location in the viewport.

 var vis_monitor = menuVis.monitor({ // now we'll actually monitor for changes
  strategy: new VisSense.VisMon.Strategy.EventStrategy({
   debounce: 100
  }),
  fullyvisible: function() { // when the navbar is fully visible (based on the value at instantiation), unfix the mini-bar
   $(".menubar").removeClass('active animated bounceInDown');
   $(".awbs-left-menu-header").addClass('active');
  },
  hidden: function() { // when the navbar is 'hidden' (based on the value at instantiation), affix the mini-bar
   $(".menubar").addClass('active animated  bounceInDown');
   $(".awbs-left-menu-header").removeClass('active');
  }
 }).start(); // start the actual monitor

 $("#hamburger-lg").on('click touch', function(e) { // listen for the click event on the hamburger menu
  e.preventDefault();
 });

 $("#awbs-360-click-for-details").on('click touch', function() { // listen for click event on the 360 dropdown clickable
  $(" i", this).toggleClass('opened');
  $(".awbs-360-details-dropdown-contents").toggleClass(
   'contents-active animated fadeIn');
 });

 var articleCarousel = $('.owl-carousel'); // instansiate the article image carousel
 articleCarousel.owlCarousel({
  singleItem: true,
  autoPlay: 5000, // autoplay every 5s
  slideSpeed: 1000, // 1s slide time
  paginationSpeed: 1500, // 1.5s changeout
  stopOnHover: true,
  navigation: true,
  navigationText: [
   "<img src='/sites/default/themes/awbs/images/arrowl.png'>",
   "<img src='/sites/default/themes/awbs/images/arrowr.png'>"
  ],
  theme: "owl-theme",
  // //Lazy load
  lazyLoad: true, // don't hold up page rendering waiting for images to load.
  lazyFollow: true,
  lazyEffect: "fade" // use a fade effect as elements lazy load in.
 });

 /*
  * Pertains to the in-article newsletter signup box
  */
 $("#newsletter-input-value").on('focus', function() { // listen for a focus event on the inline newsletter signup box input
  $(this).removeClass('newsletter-input-error');
  $(".newsletter-input-box").removeAttr('data-hint');
 });

 $("#newsletter-submit-button").click(function(e) { // listen for a click event on the inline newsletter signup box button
  console.log('news letter clicked');
  e.preventDefault();
  var isValid = true; // assume positive intent
  var inputVal = $("#newsletter-input-value").val();

  // if the field is empty and they hit submit, just do nothing.
  if (inputVal === "") {
   return;
  }

  if (inputVal.length < $("#newsletter-input-value").attr('minlength')) {
   $("#newsletter-input-value").addClass('newsletter-input-error');
   $(".newsletter-input-box").attr('data-hint',
    'This appears to be too short to be an email address');
   return;
  }

  // Added to make regex case insensitive and not look at anything after the @
  var xy = inputVal.indexOf("@");
  if (xy <= 0) {
   $("#newsletter-input-value").addClass('newsletter-input-error');
   $(".newsletter-input-box").attr('data-hint',
    'Please enter a valid email address');
   return;
  }

  // check for 'undesirable' email names
  var rr = /(?:info|sales|sale|help|marketing)/ig;
  var xz = inputVal.substring(0, xy);

  if (rr.test(xz)) {
   $("#newsletter-input-value").addClass('newsletter-input-error');
   $(".newsletter-input-box").attr('data-hint',
    'Please do not use emails starting with sales, info or help. Thank you.'
   );
   return;
  }

  // validate against known email patterns.
  var r =
   /([-!#-'*+/-9=?A-Z^-~]+(\.[-!#-'*+/-9=?A-Z^-~]+)*|"([]!#-[^-~ \t]|(\\[\t -~]))+")@[0-9A-Za-z]([0-9A-Za-z-]{0,61}[0-9A-Za-z])?(\.[0-9A-Za-z]([0-9A-Za-z-]{0,61}[0-9A-Za-z])?)*\.(net|org|com|info|etc|co.*|aero|coop|info|museum|name|biz|xxx|ac|af|ax|al|dz|us|as|ad|ao|ai|aq|ag|an|ar|am|aw|au|at|az|bs|bh|bd|bb|by|be|bz|bj|bm|bt|bo|ba|bw|bv|br|io|bn|bg|bf|mm|bi|kh|cm|ca|cv|ky|cf|td|cl|cn|cx|cc|co|km|cd|cg|ck|cr|ci|hr|cu|an|cy|cz|dk|dj|dm|do|tp|ec|eg|sv|uk|gq|er|ee|et|eu|fo|fj|fi|fr|gf|pf|tf|ga|gm|ge|gs|de|gh|gi|gb|gr|gl|gd|gp|gu|gt|gg|sr|gf|gn|gw|gq|pg|gy|ht|hm|va|hn|hk|hr|hu|is|in|io|id|ir|iq|ie|im|il|it|ci|jm|jp|je|jo|kz|cc|ke|ki|kn|kp|kr|kw|kg|lk|la|lv|lb|ls|lr|ly|li|lt|lc|lu|mo|mk|mg|mw|my|mv|ml|mt|fk|mp|mh|mr|mu|yt|fm|mx|md|mc|mn|me|ms|ma|mz|mm|na|nr|np|nl|an|nc|pg|nz|ni|ne|ng|nu|nf|mp|kp|no|om|pk|pw|ps|pa|pg|py|pe|ph|pm|pn|pl|pf|pt|pr|qa|re|ro|ru|rw|sh|kn|lc|vc|sv|as|sm|gs|st Arabia|sa|sn|rs|me|cs|rs|sc|sl|sg|sk|si|sb|so|za|kr|su|es|lk|sd|sr|sj|sz|se|ch|sy|tw|tj|tz|thno|tp|tl|tg|tk|to|tt|tn|tr|tm|tc|tv|ug|ua|ae|uk|us|um|vi|uy|uz|vu|va|ve|vn|vg|vi|wf|eh|ws|ye|yu|me|rs|zr|zw|zm)/ig;
  if (!r.test(inputVal)) {
   $("#newsletter-email-value").addClass('newsletter-input-error');
   $(".newsletter-input-box").attr('data-hint',
    'Please enter a valid email address');
   return;
  }

  // if all statuses are met, pass this into the subscription tool
  window.location.href = '/subscribe?email=' + encodeURIComponent(inputVal);
 });


});


/*
 * jQuery UI Autocomplete HTML Extension
 *
 * Copyright 2010, Scott González (http://scottgonzalez.com)
 * Dual licensed under the MIT or GPL Version 2 licenses.
 *
 * http://github.com/scottgonzalez/jquery-ui-extensions
 *
 * A. Telischak - made modifications to the outputted HTML to mimic previous
 * styling under higher version of JQuery UI (02/2015)
 */
(function($) {
 var proto = $.ui.autocomplete.prototype,
  initSource = proto._initSource;

 function filter(array, term) {
  var matcher = new RegExp($.ui.autocomplete.escapeRegex(term), "i");
  return $.grep(array, function(value) {
   return matcher.test($("<div>").html(value.label || value.value || value)
    .text());
  });
 }

 $.extend(proto, {
  _initSource: function() {
   if (this.options.html && $.isArray(this.options.source)) {
    this.source = function(request, response) {
     response(filter(this.options.source, request.term));
    };
   } else {
    initSource.call(this);
   }
  },

  _renderItem: function(ul, item) {
   return $("<li class='row'></li>")
    .data("item.autocomplete", item)
    // .append($("<a></a>")[this.options.html ? "html" : "text"](item.company_name))
    .append($("<a><div  class='col-sm-12 text-left ui-company'>" + item.data
     .company_name +
     "</div><div class='col-sm-12 text-left ui-address'>" + item.data.label +
     "</div></a>"))
    .appendTo(ul);
  }
 });

})(jQuery);


