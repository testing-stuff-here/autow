(function ($) {
  $(document).bind('pagebeforeload', function(event, data) {
      
  });
  $(document).ready(function (){
    var $windowWidth = document.documentElement.clientWidth || document.body.clientWidth;
    if($windowWidth < 640){
      //$('#header').hide();
      //$('#header').css('background', 'none');
      //$('#header img').hide();
      //$('#nav').css('background', 'none');
      //$('#header-top-wrapper').hide();
      var $searchHTML = Drupal.settings.aw960.searchHTML;
      $('ul.dl-menu > li:first-child').html($searchHTML);
      $('#dl-menu button.dl-trigger').after('<div id="responsive-header-image" style="width:165px; display:inline-block; padding-top:10px; padding-left:15px"><a href="/" alt="Home"> <img id="responsive-header-image-image" src="/sites/default/themes/aw960/images/aw_clear.png" /></a></div>');
      // make images in articles unclickable
      $('a.cboxElement').click(function(){ return false; });
    }
  });
  
  $(window).load(function(){
    var $windowWidth = document.documentElement.clientWidth || document.body.clientWidth;
    if($windowWidth < 640){
      $('a.cboxElement').click(function(){ return false; });
    }
  });
})(jQuery)