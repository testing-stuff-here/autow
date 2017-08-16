/**
 * @author Albert Jankowski <ajankowski@summitmediagroup.com>
 *
 * @file
 *  We want to display the get my free downloads block only if they haven't
 *  filled out any of our major forms like playbooks, etc...
 */

/**
 * Handles all the logic of displaying the get my free downloads block
 */
function aw_gmfd_events(block_id, slide_in, label_event, action, label) {
  var delay = 0;
  var slide_in_cookie_name = 'aw_gmfd_sliding_panel';
  var forms_cookie_value = get_cookie("reader_token");
  var slide_in_cookie_value = get_cookie(slide_in_cookie_name);
  var is_mobile = window.innerWidth < 992 ? true : false;


  // How fast the slide_in should be
  if (slide_in == true) {
    var delay = 5000;
  }
  // for slide box if no cookie than display
  if (is_mobile == false && slide_in == true && forms_cookie_value == null && slide_in_cookie_value == null) {
    // Set 24 Hour Cookie
    set_cookie(slide_in_cookie_name, "1", "1");
    setTimeout(sliding_panel_show(block_id), delay);
    google_event(label_event, action, label);
  }
  // for regular get my free download block
  if (is_mobile == false && slide_in == false && forms_cookie_value == null) {
    jQuery(document).ready(function($) {
      $(block_id).css('display', 'block');
    });

    google_event(label_event, action, label);
  }
}

/**
 * Shows the sliding panel
 */
function sliding_panel_show(block_id) {
  return function() {
    (function($) {
    $(block_id).show(1000).addClass('animated slideUp');

    // Change the position to slide in
    $(block_id + ' input[name="submitted[email_capture_position]"]').val(
    "Slide in");
    }(jQuery));
  }
}

/**
 * Send Google View Event
 */
function google_event(label_event, action, label) {
  if (typeof (ga) !== "undefined") {
    ga('send', 'event', label_event, action, label, 1, {'nonInteraction': 1});
  }
}

/**
 * Check if cookie exists
 */
function get_cookie(Name) {
  var re = new RegExp(Name + "=[^;]+", "i"); //construct RE to search for target name/value pair
  if (document.cookie.match(re)) //if cookie found
    return document.cookie.match(re)[0].split("=")[1] //return its value
  return null
}

/**
 * Set cookie
 */
function set_cookie(name, value, days) {
  var expireDate = new Date();
  //set "expstring" to either an explicit date (past or future)
  if (typeof days != "undefined") { //if set persistent cookie
    var expstring = expireDate.setDate(expireDate.getDate() + parseInt(days));
    document.cookie = name + "=" + value + "; expires=" + expireDate.toGMTString() + "; " + "path=/";
  }
  else //else if this is a session only cookie setting
    document.cookie = name + "=" + value + "; " + "path=/";
}

/**
 * Functions handling get my free downlaods
 */
jQuery(document).ready(function($) {
  //Hide the slide in block when close is clicked
  $('.close-slide-in').click(function() {
    // $('#sliding-panel').hide(1000);
    $('#sliding-panel').hide(1000).addClass('hidden');
  });

  // Change text in email field
  var text = 'Enter your email address here';
  $('.node-stage-one-form input[name="submitted[email]"]').val(text);
  $('.node-stage-one-form input[name="submitted[email]"]').focus(function() {
    if ($(this).val() == text) $(this).val('');
  });

  // Replace the leadsource Upper string to Slide in
  // @TODO - just incase there are other cases than Upper need to accomidate
  var sliding_panel_leadsource = $('#sliding-panel input[name="submitted[silverpop_lead_source]"]');
  if (sliding_panel_leadsource.length > 0) {
    var silver_lead_source = sliding_panel_leadsource.val().replace('Upper', 'Slide in');
    sliding_panel_leadsource.val(silver_lead_source);
  }
});
