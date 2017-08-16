(function ($) {
  $(document).ready(function () {
    /**
     * #892 - Track Viddler Video Plays.
     */
    $("iframe[id^='viddler-']").each(function (i, el) {
      // Check if viddler parameter has enablejsapi and if it doesn't add it. (
      // This tells Viddler that you are allowing this video to use the api)
      if (el.src.indexOf('enablejsapi=t') == -1) {
         el.src = el.src + '&enablejsapi=t';
      }

      // Get the Viddler Id from the iframe parameter. (viddler-xxxxxxx)
      var elementId = el.id.split('-');
      var viddlerId = elementId[elementId.length - 1];

      checkForViddlerEvent(el.id, viddlerId);
    });

    /**
     * Check for a viddler event change and make any changes needed.
     *
     * @param integer id
     *   The id attribute of the iframe.
     * @param string viddlerId
     *   Viddler ID.
     */
    function checkForViddlerEvent(id, viddlerId) {
      var player = window.Viddler(id);
      var sentGoogleEvent = false;

      /**
       * When a video state changes this event fires.
       * Possible states are:
       *   - not started (-1)
       *   - ended (0)
       *   - playing (1)
       *   - paused (2)
       *   - buffering (3)
       *   - video cued (5)
       *
       * @var integer state
       *   The state.
       */
      player.onStateChange(function(state){
        if (state == 1) {
          if (sentGoogleEvent === false) {
            // Add Google Event that Video was played.
            if (typeof ga == 'function') {
              ga('send', 'event', 'Viddler Video Plays', viddlerId, window.location.pathname);
            }

            // Set to true so it won't fire twice for a video.
            sentGoogleEvent = true;
          }
        }
      });
    }

  });
})(jQuery);
