// Function for determining if browser is IE and if so what version
function msieversion(){
  var ua = window.navigator.userAgent;
  var msieV = ua.indexOf("MSIE ");
  if (msieV > 0) {     // If Internet Explorer, return version number
    return parseInt(ua.substring(msieV + 5, ua.indexOf(".", msieV)));
  }
  else {                // If another browser, return 0
    return false;
  }
}

var msIEVersion = msieversion();

// Make sure this browser supports the CustomEvent constructor.
try {
  (function () {
    var testCustom = new CustomEvent('testEvent', {'detail':'test'});
  })();
}
catch (e) {
  // @see https://developer.mozilla.org/en-US/docs/Web/API/CustomEvent/CustomEvent
  (function () {
    function CustomEvent ( event, params ) {
      params = params || { bubbles: false, cancelable: false, detail: undefined };
      var evt = document.createEvent( 'CustomEvent' );
      evt.initCustomEvent( event, params.bubbles, params.cancelable, params.detail );
      return evt;
    }

    CustomEvent.prototype = window.Event.prototype;

    window.CustomEvent = CustomEvent;
  })();
}

(function($) {
  // #1001
  $(document).ready(function() {
    checkAds();
    function checkAds() {
      if (document.getElementById("adsense") != undefined) {
        if (typeof ga !== "undefined") {
          ga('send', 'event', 'Adblock', 'Unblocked', 'true', {
            nonInteraction: true
          });
        }
      }
      else {
        if (typeof ga !== "undefined") {
          ga('send', 'event', 'Adblock', 'Blocked', 'true', {
            nonInteraction: true
          });
        }
      }
    }
  });
})(jQuery);
