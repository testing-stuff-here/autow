(function ($) {
  /**
   * modalContent
   * @param content string to display in the content box
   * @param css obj of css attributes
   * @param animation (fadeIn, slideDown, show)
   * @param speed (valid animation speeds slow, medium, fast or # in ms)
   */
  Drupal.CTools.Modal.modalContent = function (content, css, animation, speed) {
    // If our animation isn't set, make it just show/pop
    if (!animation) {
      animation = 'show';
    }
    else {
      // If our animation isn't "fadeIn" or "slideDown" then it always is show
      if (animation != 'fadeIn' && animation != 'slideDown') {
        animation = 'show';
      }
    }

    if (!speed) {
      speed = 'fast';
    }

    // Build our base attributes and allow them to be overriden
    css = jQuery.extend({
      position: 'absolute',
      left: '0px',
      margin: '0px',
      background: '#000',
      opacity: '.55'
    }, css);

    // Add opacity handling for IE.
    css.filter = 'alpha(opacity=' + (100 * css.opacity) + ')';
    content.hide();

    // If we already have modalContent, remove it.
    if ($('#modalBackdrop').length) $('#modalBackdrop').remove();
    if ($('#modalContent').length) $('#modalContent').remove();

    // position code lifted from http://www.quirksmode.org/viewport/compatibility.html
    if (self.pageYOffset) { // all except Explorer
      var wt = self.pageYOffset;
    } else if (document.documentElement && document.documentElement.scrollTop) { // Explorer 6 Strict
      var wt = document.documentElement.scrollTop;
    } else if (document.body) { // all other Explorers
      var wt = document.body.scrollTop;
    }

    // Get our dimensions

    // Get the docHeight and (ugly hack) add 50 pixels to make sure we dont have a *visible* border below our div
    var docHeight = $(document).height() + 50;
    var docWidth = $(document).width();
    var winHeight = $(window).height();
    var winWidth = $(window).width();
    if (docHeight < winHeight) docHeight = winHeight;

    // Create our divs
    $('body').append('<div id="modalBackdrop" style="z-index: 1000; display: none;"></div><div id="modalContent" style="z-index: 1001; position: absolute;">' + $(content).html() + '</div>');

    // Keyboard and focus event handler ensures focus stays on modal elements only
    let modalEventHandler = function (event) {
      let target = null;
      if (event) { //Mozilla
        target = event.target;
      } else { //IE
        event = window.event;
        target = event.srcElement;
      }

      var parents = $(target).parents().get();
      for (var i = 0; i < parents.length; ++i) {
        var position = $(parents[i]).css('position');
        if (position == 'absolute' || position == 'fixed') {
          return true;
        }
      }

      if ($(target).is('#modalContent, body') || $(target).filter('*:visible').parents('#modalContent').length) {
        // Allow the event only if target is a visible child node
        // of #modalContent.
        return true;
      }
      else {
        $('#modalContent').focus();
      }

      event.preventDefault();
    };
    $('body').bind('focus', modalEventHandler);
    $('body').bind('keypress', modalEventHandler);
    window.modalEventHandler = modalEventHandler;

    // Create our content div, get the dimensions, and hide it
    var modalContent = $('#modalContent').css('top', '-1000px');
    var mdcTop = wt + ( winHeight / 2 ) - (  modalContent.outerHeight() / 2);
    if (mdcTop < wt) {
      mdcTop = wt + 100;
    }
    var mdcLeft = ( winWidth / 2 ) - ( modalContent.outerWidth() / 2);
    $('#modalBackdrop').css(css).css('top', 0).css('height', docHeight + 'px').css('width', docWidth + 'px').show();
    modalContent.css({top: mdcTop + 'px', left: mdcLeft + 'px'}).hide()[animation](speed);

    // Bind a click for closing the modalContent
    let modalContentClose = function () {
      close();
      return false;
    };
    $('.close').bind('click', modalContentClose);
    window.modalContentClose = modalContentClose;

    // Bind a keypress on escape for closing the modalContent
    let modalEventEscapeCloseHandler = function (event) {
      if (event.keyCode == 27) {
        close();
        return false;
      }
    };
    $(document).bind('keydown', modalEventEscapeCloseHandler);
    window.modalEventEscapeCloseHandler = modalEventEscapeCloseHandler;

    // Close the open modal content and backdrop
    function close() {
      // Unbind the events
      $(window).unbind('resize', modalContentResize);
      $('body').unbind('focus', modalEventHandler);
      $('body').unbind('keypress', modalEventHandler);
      $('.close').unbind('click', modalContentClose);
      $('body').unbind('keypress', modalEventEscapeCloseHandler);
      $(document).trigger('CToolsDetachBehaviors', $('#modalContent'));

      // Set our animation parameters and use them
      if (animation == 'fadeIn') animation = 'fadeOut';
      if (animation == 'slideDown') animation = 'slideUp';
      if (animation == 'show') animation = 'hide';

      // Close the content
      modalContent.hide()[animation](speed);

      // Remove the content
      $('#modalContent').remove();
      $('#modalBackdrop').remove();
    };

    // Move and resize the modalBackdrop and modalContent on resize of the window
    let modalContentResize = function () {

      // position code lifted from http://www.quirksmode.org/viewport/compatibility.html
      if (self.pageYOffset) { // all except Explorer
        var wt = self.pageYOffset;
      } else if (document.documentElement && document.documentElement.scrollTop) { // Explorer 6 Strict
        var wt = document.documentElement.scrollTop;
      } else if (document.body) { // all other Explorers
        var wt = document.body.scrollTop;
      }

      // Get our heights
      var docHeight = $(document).height();
      var docWidth = $(document).width();
      var winHeight = $(window).height();
      var winWidth = $(window).width();
      if (docHeight < winHeight) docHeight = winHeight;

      // Get where we should move content to
      var modalContent = $('#modalContent');
      var mdcTop = wt + ( winHeight / 2 ) - ( modalContent.outerHeight() / 2);
      if (mdcTop < wt) {
        mdcTop = wt + 100;
      }
      var mdcLeft = ( winWidth / 2 ) - ( modalContent.outerWidth() / 2);

      // Apply the changes
      $('#modalBackdrop').css('height', docHeight + 'px').css('width', docWidth + 'px').show();
      modalContent.css('top', mdcTop + 'px').css('left', mdcLeft + 'px').show();
    };
    $(window).bind('resize', modalContentResize);
    window.modalContentResize = modalContentResize;

    $('#modalContent').focus();
  };
})(jQuery);