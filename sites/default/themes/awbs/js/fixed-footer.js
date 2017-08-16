function setCookie(cname, cvalue, exdays) {
    var d = new Date();
    d.setTime(d.getTime() + (exdays*24*60*60*1000));
    var expires = "expires="+d.toUTCString();
    document.cookie = cname + "=" + cvalue + "; " + expires;
}

function getCookie(cname) {
    var name = cname + "=";
    var ca = document.cookie.split(';');
    for(var i=0; i<ca.length; i++) {
        var c = ca[i];
        while (c.charAt(0)==' ') c = c.substring(1);
        if (c.indexOf(name) == 0) return c.substring(name.length, c.length);
    }
    return "";
}



(function () {
  jQuery(document).ready(function($){

    var randomNumber = Math.floor((Math.random() * 3) + 1);
    var flextabcookie = getCookie( "flextabcookie" );
    if (randomNumber == 1 && flextabcookie != "displayed"){
      setCookie("flextabcookie", "displayed", 1);
      $("#fixed-footer").removeClass("initial-hidden").addClass("closed");
      ga('send', 'event', 'Profinet Flex Tab Gallery',
          'Profinet gallery visible',
          'Profinet April 1st - Sept 30th 2017');
    }else{
    $('#fixed-footer').hide();
     }

    if ( $(window).width() > 768){
    $('#fixed-footer-open-tab').on('mouseover', function () {
      if ( $('#fixed-footer').is('.closed')) {
          $("#fixed-footer").addClass("expanded").removeClass("closed");
          $("#fixed-footer").removeClass("initial-bounce");
          $('.fa').removeClass('fa-angle-double-up').addClass('fa-angle-double-down');
          ga('send', 'event', 'Profinet Flex Tab Gallery',
          'Profinet gallery expanded',
          'Profinet April 1st - Sept 30th 2017');
        }
    });

  $('#fixed-footer-open-tab').on('click', function() {
      if ( $('#fixed-footer').is('.expanded')) {
          $("#fixed-footer").addClass("closed").removeClass("expanded");
          $('.fa').removeClass('fa-angle-double-down').addClass('fa-angle-double-up');
          ga('send', 'event', 'Profinet Flex Tab Gallery',
          'Profinet gallery retracted',
          'Profinet April 1st - Sept 30th 2017');
        }
    });
}else{
  $('#fixed-footer-open-tab').on('click', function() {
      if ( $('#fixed-footer').is('.closed')) {
          $("#fixed-footer").addClass("expanded").removeClass("closed");
          $('.fa').removeClass('fa-angle-double-up').addClass('fa-angle-double-down');
          ga('send', 'event', 'Profinet Flex Tab Gallery',
          'Profinet gallery expanded',
          'Profinet April 1st - Sept 30th 2017');
        }else if ( $('#fixed-footer').is('.expanded')) {
          $("#fixed-footer").addClass("closed").removeClass("expanded");
          $('.fa').removeClass('fa-angle-double-down').addClass('fa-angle-double-up');
          ga('send', 'event', 'Profinet Flex Tab Gallery',
          'Profinet gallery retracted',
          'Profinet April 1st - Sept 30th 2017');
        }
    });
}

    $('#fixed-footer-close-tab').on('click', function() {
      $('#fixed-footer').hide();
      ga('send', 'event', 'Profinet Flex Tab Gallery',
          'Profinet gallery closed',
          'Profinet April 1st - Sept 30th 2017');
    });

  });
}());
