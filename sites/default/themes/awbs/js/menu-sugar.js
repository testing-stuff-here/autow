/**
 * This file is separate from main.js as code in it lends itself more specifically
 * to the function of the navigation system.
 */

$(function () { // wait for the DOM to load...
  var menuHoverTimer; // timer for the top-level navbar menu delayed display
  var menuHoverOutTimer; // timer to delay destroying the dropdown menu being display
  var menuDataBlocks = []; // JSON blocks from the menu endpoints
  var menuItems; // items in the dropdown menus
  var menuItemIndex; // get the index of the clicked/hovered item
  var contentItemsCount; // how many content items are there for a specific subtopic in the dropdown menu?
  var contentItems = []; // the items under each subtopic
  var template; // temporarily holds the templates that are built based on content pulled from the endpoints
  var keyname; // holds the key for the data object returned from the server endpoint, as we loop through that object
  var sectionHoverTimer; // timer for each subtopic in the menu dropdowns
  var menuName = ''; // a string that holds the name of the currently 'active' top-level menu item.
  var menuElementsToGrab = [
    'aweditors', // you guessed it - these are the menu elements we're going to grab.
    'products',
    'factory',
    'process',
    'engineering',
    'operations',
    'it'
  ];
  var loadeds = []; // watches for loading status of our endpoint paylods
  var menusAreLoaded = false; // have all the menu endpoints returned data to display in the dropdown menus off of nav?

  /**
   * This function helps us get the size of the object returned from our menu
   * endpoints (i.e. - how many items were returned for a given subtopic)
   * @param  object obj The object we're trying to count
   * @return int  the count of the elements in the subtopic
   */
  Object.size = function (obj) {
    var size = 0,
      key;
    for (key in obj) {
      if (obj.hasOwnProperty(key)) {
        size++;
      }
    }
    return size;
  };

  /**
   * This will go out and pull the menu payload, returning a promise
   * when the ajax call completes
   *
   */
  function doPull() {
    var promise = $.ajax({
      url: '/awmegamenu/get-content/menuname',
      data: {
        format: 'json',
      },
      dataType: 'json',
      success: function (r) {
        menuDataBlocks = r;

      }
    });
    return promise;
  }

  doPull().then(function () {
    menusAreLoaded = true;
  });


  $(".menubar .leaf").mouseenter(function () { // listen for a hover event pairing on one of the top level navbar menu elements
    var selectionName = '';
    var _this = this;
    menuItemIndex = $(this).index();
    clearTimeout(menuHoverOutTimer);

    if (menusAreLoaded) {
      menuHoverTimer = setTimeout(function () {
        selectionName = $(_this).text().toLowerCase().replace(/ /g, "");
        showMenuContentsFor(selectionName);
        $('.menubar .leaf').not($(_this)).removeClass('active-space');
        $(_this).addClass('active-space');
        $(".awbs-navbar-dropdown-menu").not($('.awbs-navbar-dropdown-menu').eq(
          menuItemIndex)).removeClass(
          'awbs-dropdown-active');

        $(".awbs-navbar-dropdown-menu").eq(menuItemIndex).addClass(
          'awbs-dropdown-active');
      }, 500);
    }
  });

  $(".awbs-navbar-dropdown-menu").mouseenter(function () {
    clearTimeout(menuHoverOutTimer);
  });


  $(".menubar").mouseleave(function () {
    if (menusAreLoaded) {
      clearTimeout(menuHoverTimer);
      menuHoverOutTimer = setTimeout(function () {
        $(".menubar .leaf").eq(menuItemIndex).removeClass('active-space');
        $(".awbs-navbar-dropdown-menu").removeClass(
          'awbs-dropdown-active');
      }, 1000);


    }
  });

  /**
   * Load the contents for the requested dropdown
   * @param string menuNamePassback the name of the menu, pulled from the contents of the element ('products', 'aw editors')
   */
  function showMenuContentsFor(menuNamePassback) {

    var data = menuDataBlocks[menuNamePassback]; // load the prefetched data
    var firstKey; // a catch to jump to the first subtopic elements
    menuitems = Object.size(data); // determine how many elements are in the subtopic dataset
    menuName = menuNamePassback; // rename the passback variable


    $("#awbs-navbar-" + menuName + "-selections ul").empty(); // empty out the selection list
    $("#awbs-navbar-" + menuName + "-contents").empty(); // empty out the contents panel

    for (var key in data) { // loop through the data set
      if (typeof firstKey == 'undefined') { // set the first key, as for mentioned above.
        firstKey = _.snakeCase(key).toLowerCase(); // set that first key
      }
      keyname = _.snakeCase(key).toLowerCase(); // set the keyname for the next step
      contentItems[keyname] = ''; // empty the template set.
      //	console.log('path', data[key].path);
      $("#awbs-navbar-" + menuName + "-selections ul").append(
        "<li class='animated fadeInLeft'><a href='/" +
        data[key].path +
        "' class='menu-select-section' id='" + keyname +
        "'>" +
        key + "</a></li>"); // populate the selection list with subtopics

      contentItemsCount = Object.size(data[key].items); // how many boxes are there to display

      console.group('contentItems');
      for (var i = 0; i < contentItemsCount; i++) { // for each item in the item count
        template = _.template(
          '<div class="col-xs-12 col-md-3 content-item-container animated fadeInRight"> <div class="row"><div class="col-xs-12 content-item"><div class="row"><a href="<%- href %>"><div class="col-xs-12 content-item-image" style="background-image:url(<%- image %>);"></div><div class="col-xs-12 content-item-title"><%- title %></div></a></div></div></div></div>'
        ); // generate a template string
        console.log(data[key].items[i].title, "/" + data[key].items[i].href);
        contentItems[keyname] += template({
          'href': "/" + data[key].items[i].href,
          'image': data[key].items[i].image.src,
          'title': data[key].items[i].title
        }); // and compile it with the pertinent data
        console.groupEnd();
      }
    }


    $("#awbs-navbar-" + menuName + "-contents").append(contentItems[firstKey]); // append the item set for the first subtopic to the content panel
    $("#awbs-navbar-" + menuName + "-selections ul li a").eq(0).addClass(
      'active'); // mark the first item in the subtopic selection list as 'active'
  }

  // You can't use .hover on a dynamically created element, so you must use
  // mouseenter, mouseleave to mimic the behavior
  $(document).on('mouseenter', '.menu-select-section', function () { // listen for a mouseenter event on a subtopic element in the open dropdown
    var _this = this;
    sectionHoverTimer = setTimeout(function () {
      $("#awbs-navbar-" + menuName + "-contents").empty();
      $("#awbs-navbar-" + menuName + "-selections ul li a").removeClass(
        'active');
      $(_this).addClass('active');
      $("#awbs-navbar-" + menuName + "-contents").append(contentItems[$(
        _this).attr(
        'id')]);
    }, 500);
  });

  $(document).on('mouseleave', '.menu-select-section', function () { // listen for a mouseleave event on a subtopic element in the open dropdown
    clearTimeout(sectionHoverTimer);
  });

  $(".slide-active").on('click touch', function () {
    console.log('foobar');
    $('#awbs-mobile-hamburger').removeClass('active');
    el = $('.awbs-mobile-nav-options');
    el.addClass('slideOutLeft');
    $('.main-container, .footer').removeClass('slide-active');
    el.one('webkitAnimationEnd oanimationend msAnimationEnd animationend',
      function (e) {
        el.removeClass('slideOutLeft active');
      });
  });

  // mobile search button
  $("#awbs-mobile-search").on('click touch', function () {
    $('.awbs-mobile-nav-options').removeClass('active');
    $('#awbs-mobile-hamburger').removeClass('active');
    $('.main-container, .footer').removeClass('slide-active');
    var el = $('.awbs-mobile-nav-search');

    if (el.hasClass('active')) {
      el.addClass('slideOutUp');
      el.one('webkitAnimationEnd oanimationend msAnimationEnd animationend',
        function (e) {
          el.removeClass('slideOutUp active');
        });
      return;
    }
    else {
      el.addClass('slideInDown active');
      el.one('webkitAnimationEnd oanimationend msAnimationEnd animationend',
        function (e) {
          el.removeClass('slideInDown');
        });
      return;
    }
  });


  // listen for open/close events on the mobile slide out menu
  $('#awbs-mobile-hamburger, #awbs-mobile-hamburger-close').on('click touch',
    function () {
      $('.awbs-mobile-nav-search').removeClass('active');
      var el;

      if ($('#awbs-mobile-hamburger').hasClass('active')) {
        $('#awbs-mobile-hamburger').removeClass('active');
        el = $('.awbs-mobile-nav-options');
        el.addClass('slideOutLeft');
        $('.main-container, .footer').removeClass('slide-active');
        el.one('webkitAnimationEnd oanimationend msAnimationEnd animationend',
          function (e) {
            el.removeClass('slideOutLeft active');
          });
      }
      else {
        $('#awbs-mobile-hamburger').addClass('active');
        el = $('.awbs-mobile-nav-options');
        el.addClass('slideInLeft active');
        $('.main-container, .footer').addClass('slide-active');
        el.one('webkitAnimationEnd oanimationend msAnimationEnd animationend',
          function (e) {
            el.removeClass('slideInLeft');
          });
      }
    });

  //Accordion for mobile navigation
  $('.awbs-mobile-nav-options li.expanded > a')
    .on('click', function () {
      var menu = $('.awbs-mobile-nav-options');
      var menuItem = $(this).parent();
      menu.scrollTop(0);
      if (menuItem.hasClass('opened')) {
        menuItem.removeClass('opened').find('.menu').slideUp('fast');
      }
      else {
        $('.awbs-mobile-nav-options li.expanded.opened')
          .removeClass('opened')
          .find('.menu')
          .slideUp('fast');
        menuItem.addClass('opened')
          .find('.menu')
          .slideDown('fast', function () {
            var nextItem = menuItem.next();
            var nextItemTop = nextItem.position().top;
            var menuHeight = menu.height();
            var scrollNumber = nextItemTop - menuHeight + 50;
            if (menuHeight < nextItemTop + 50) {
              menu.animate({scrollTop: scrollNumber}, 250);
            }
          });
      }
      return false;
    });

});
