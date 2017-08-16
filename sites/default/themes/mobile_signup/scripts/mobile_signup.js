(function($){  
  
  
  /* remove border around all input elements */
  if (navigator.userAgent.toLowerCase().indexOf("chrome") >= 0) {
  	$(window).load(function () {
  		$('input:-webkit-autofill').each(function () {
  			var text = $(this).val();
  			var id = $(this).attr('id');
  			$(this).after(this.outerHTML).remove();
  			$('input[id=' + id + ']').val(text);                    
  		});
  	});
  }
  
  $(document).ready(function(){
    
    // Turn autocomplete off
    $("input, select, textarea").each(function(i,e){
      $(e).attr("autocomplete", "off");
    }); 
    
    var addSelectOption = function(){
      $(".webform-component .ui-select select").each(function(i,e){
        if($(e).get(0).multiple == true){
          //$(e).get(0).prepend("<option>- Please Choose -</option>");
          if($(e).find("option").first().text() != '- Select all that apply -'){
            //$(e).prepend("<option>- Select all that apply -</option>");
            //$(e).find("option").first().attr("selected", "selected");
            var sibling = $(e).siblings(".form-select");
            //sibling.text("- Select all that apply -").css({'padding-right':'0px', 'padding-left':'30px'});
          }
        }
      });
    }
    
    setTimeout(addSelectOption, 1000);
    setTimeout(addSelectOption, 2000);
    
    setTimeout(function(){
      $(".smg_password_hidden_textfield").each(function(i,e){
        $(e).parent(".ui-input-text").each(function(i,e1){
          $(e1).hide();
        });
      });
    },200);

  });
})(jQuery);