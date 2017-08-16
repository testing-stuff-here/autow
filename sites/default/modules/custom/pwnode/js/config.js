(function ($) {
Drupal.behaviors.pwnode = {
  attach: function(context, settings) {
    $('.node .fied-slideshow').show();
    var $slideshow = $('#slideshow').cycle({
      fx:   'fade', 
      speed:  'fast',
      pager:  '#slideshow #nav',
      timeout: 0, 
      next:   '.next', 
      prev:   '.prev',
      pagerAnchorBuilder: function(idx, slide) {
       // return sel string for existing anchor
        return '#slideshow #nav li:eq(' + (idx) + ') a';
      }
    });
    //grab the api
    var root = $(".scrollable").scrollable({ circular: false,vertical: true,speed:  'fast'}).navigator().autoscroll({interval: 5000});
    window.api = root.data("scrollable");
    $(".scrollable").scrollable({ vertical: true ,speed:  'fast'});
    //viddler popup
    $(document).ready(function(){$(".node .fied-slideshow .viddler_field").colorbox({width:"50%", inline:true, href:"#inline_viddler"});});
    //image colorbox
    $(document).ready(function(){$("a[rel='slideshow-image']").colorbox();});
    //image thumb colorbox
    $(document).ready(function(){$("a[rel='slideshow-image-thumb']").colorbox();});
    //image link colorbox
    $(document).ready(function(){$("a[rel='slideshow-image-link']").colorbox();});
    //slideshow-link 
    $(document).ready(function(){$("a[rel='slideshow-link']").colorbox();});
    
    if($('.scrollable').html()){
      var size  = api.getSize() - 1;
      api.onSeek(function(){
        index = api.getIndex();   
        $slideshow.cycle(index);
        //this will seek the first item and stop the cycle when last item reached
        if(index==size){setTimeout('api.seekTo(0, "fast");api.stop();',5000);}
      });
      //hover pause
      $('.node .fied-slideshow').hover( function () {api.stop();},function () { api.play();});
     }

    //long title fix
    $(document).bind('cbox_complete', function(){
      if($('#cboxTitle').height() > 20){
        $("#cboxTitle").hide();
        $('<div style="padding:16px 10px 0 10px;">'+$("#cboxTitle").html()+"</div>").css({color: $(".cboxTitle").css('color')}).insertAfter(".cboxPhoto");
        $.fn.colorbox.resize();
      } 
    });
     
  }
};
})(jQuery);