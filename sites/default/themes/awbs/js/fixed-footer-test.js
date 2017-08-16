(function () {
  jQuery(document).ready(function($){
      $("#fixed-footer").removeClass("initial-hidden").addClass("closed");

    if ( $(window).width() > 768){
    $('#fixed-footer-open-tab').on('mouseover', function () {
      if ( $('#fixed-footer').is('.closed')) {
          $("#fixed-footer").addClass("expanded").removeClass("closed");
          $("#fixed-footer").removeClass("initial-bounce");
          $('.fa').removeClass('fa-angle-double-up').addClass('fa-angle-double-down');
        }
    });

  $('#fixed-footer-open-tab').on('click', function() {
      if ( $('#fixed-footer').is('.expanded')) {
          $("#fixed-footer").addClass("closed").removeClass("expanded");
          $('.fa').removeClass('fa-angle-double-down').addClass('fa-angle-double-up');
        }
    });
}else{
  $('#fixed-footer-open-tab').on('click', function() {
      if ( $('#fixed-footer').is('.closed')) {
          $("#fixed-footer").addClass("expanded").removeClass("closed");
          $('.fa').removeClass('fa-angle-double-up').addClass('fa-angle-double-down');
        }else if ( $('#fixed-footer').is('.expanded')) {
          $("#fixed-footer").addClass("closed").removeClass("expanded");
          $('.fa').removeClass('fa-angle-double-down').addClass('fa-angle-double-up');
        }
    });
}
    $('#fixed-footer-close-tab').on('click', function() {
      $('#fixed-footer').hide();
    });
  });
}());
