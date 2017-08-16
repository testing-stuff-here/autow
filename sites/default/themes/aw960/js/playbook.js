// a utility function to check for the existence of a cookie
function getCookie(c_name) {
  var c_value = document.cookie;
  var c_start = c_value.indexOf(" " + c_name + "=");
  if(c_start == -1) {
    c_start = c_value.indexOf(c_name + "=")
  }
  if(c_start == -1) {
    c_value = null;
  }
  else {
    c_start = c_value.indexOf("=", c_start) + 1;
    var c_end = c_value.indexOf(";", c_start);
    if(c_end == -1) {
      c_end = c_value.length;
    }
    c_value = unescape(c_value.substring(c_start,c_end));
  }
  return c_value;
}

(function ($) {
  $(window).load(function(){
    
    // Call custom Engage event, ticket #2093
    // ewt.trackLink({name:'AW FMA Playbook Page Loaded', type:'playbook-aw_factory_machine_automation'});
    
    // If the values aren't being pre-populated by a Silverpop cookie, then we assume that the user is visiting the
    // form for the first time.  Although the default anwser for the company-type question is already set, we manually change
    // the text on the button to "- Select -" (however, the default value is still "Manufacturing")
    if(!getCookie('com.silverpop.iMA.uid')) {
  	  $("#webform-component-company-type button span:nth-child(2)").text("- Select -");
    }

    // Remove the ui-state-active class from the company-type question if the button says "- Select -"
  	function checkForChanges() {
  		if($("label[for^=ui-multiselect-edit-submitted-company-type]").hasClass("ui-state-active")) {
  			if($("#webform-component-company-type button span:nth-child(2)").text() == '- Select -') {
  				var labels = $("label[for^=ui-multiselect-edit-submitted-company-type]");
  				labels.each(function (index, element){
  					if($(element).hasClass('ui-state-active')) {
  						$(element).removeClass('ui-state-active');
  					}  					
  				});
  			}
  			setTimeout(checkForChanges, 500);
  		} else {
  			setTimeout(checkForChanges, 500);
  		}
  	}
  	$(checkForChanges);
    
  });
}(jQuery));