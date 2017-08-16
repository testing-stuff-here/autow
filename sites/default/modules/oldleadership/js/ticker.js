/**
 * Slides the Leadership company list
 */
jQuery(document).ready(function($) {
  function tick() {
    $("#oldleadership-companies li:lt(3)").slideUp( function() {
      $(this).appendTo($('#oldleadership-companies')).slideDown();
    });
  }

  var interval = setInterval(function() {
    tick();
  }, 4000);

  // If hover over the companies than stop the ticker and turn into scroll
   $("#oldleadership-companies").hover( function() {
     clearInterval(interval);
   });
});
