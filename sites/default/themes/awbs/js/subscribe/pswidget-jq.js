var $ = jQuery;
var autoc_home; // autocomplete element for home address. loaded if user selects that option
var autochlistener; // our Autocomplete Places listener callback for home address selection
var autochtabbing;
var autochentering;
var autoc_comp; // autocomplete element for company address. loaded if user adds new company
var autocclistener;
var autocctabbing;
var autoccentering;
var modal;

var phdata = {}; // our home delivery Place data
var phcompdata = {}; // our company address Place data
// this object is watched and triggers a Ractive event if it changes.
//
var viaNewsletter = {
	userEmail: '' // filled with user email from newsletter box
};
var $ = jQuery;


function str_pad(n) {
	return String("00" + n).slice(-2);
}

// access query string from the url
var QueryString = function() {
	// This function is anonymous, is executed immediately and
	// the return value is assigned to QueryString!
	var query_string = {};
	var query = window.location.search.substring(1);
	var vars = query.split("&");
	for (var i = 0; i < vars.length; i++) {
		var pair = vars[i].split("=");
		// If first entry with this name
		if (typeof query_string[pair[0]] === "undefined") {
			query_string[pair[0]] = pair[1];
			// If second entry with this name
		} else if (typeof query_string[pair[0]] === "string") {
			var arr = [query_string[pair[0]], pair[1]];
			query_string[pair[0]] = arr;
			// If third or later entry with this name
		} else {
			query_string[pair[0]].push(pair[1]);
		}
	}
	return query_string;
}();

/**
 * UpdateQueryString
 *   Updates or adds a URL param. If the param doesn't exist, this function will
 *   add it with the defined value.
 *
 *    Not supplying a value will remove the parameter, supplying one will
 *    add/update the paramter. If no URL is supplied, it will be grabbed from
 *    window.location. This solution also takes the url's anchor into
 *    consideration.
 *
 * @param string key   the param name
 * @param string value the value to which the param will be set
 * @param string url   the url string you'll be affecting the change on.
 */
function UpdateQueryString(key, value, url) {
	if (!url) url = window.location.href;
	var re = new RegExp("([?&])" + key + "=.*?(&|#|$)(.*)", "gi"),
		hash;

	if (re.test(url)) {
		if (typeof value !== 'undefined' && value !== null)
			return url.replace(re, '$1' + key + "=" + value + '$2$3');
		else {
			hash = url.split('#');
			url = hash[0].replace(re, '$1$3').replace(/(&|\?)$/, '');
			if (typeof hash[1] !== 'undefined' && hash[1] !== null)
				url += '#' + hash[1];
			return url;
		}
	} else {
		if (typeof value !== 'undefined' && value !== null) {
			var separator = url.indexOf('?') !== -1 ? '&' : '?';
			hash = url.split('#');
			url = hash[0] + separator + key + '=' + value;
			if (typeof hash[1] !== 'undefined' && hash[1] !== null)
				url += '#' + hash[1];
			return url;
		} else
			return url;
	}
}


/**
 * Add a Google Places autocomplete instance for Company Address to the
 * "new" company panel.
 */
var initCompanyAutocomplete = function() {
	autoc_comp = new google.maps.places.Autocomplete(
		(document.getElementById('form-company-address-full')), {
			types: ['geocode']
		}
	);

	// we add an event listener to the autocomplete object, which is triggered
	// when the user selects something off of the list provided by Google.
	autocclistener = google.maps.event.addListener(autoc_comp, 'place_changed',
		onCompPlaceChanged);

	// This is a more elegant way of handling users bypassing the autocomplete
	// suggestions. It forces the API to reassess the value in the text input.
	autocctabbing = google.maps.event.addDomListener(document.getElementById(
		'form-company-address-full'), 'focusout', function() {
		google.maps.event.trigger(this, 'focus');
		google.maps.event.trigger(this, 'keydown', {
			keyCode: 13
		});
	});

};

// Initialize our Home Address autocomplete field
var initHomeAutocomplete = function() {
	// we bind the autocomplete object to the input field
	autoc_home = new google.maps.places.Autocomplete(
		(document.getElementById('form-home-delivery-address-full')), {
			types: ['geocode']
		}
	);

	// we add an event listener to the autocomplete object, which is triggered
	// when the user selects something off of the list provided by Google.
	autochlistener = google.maps.event.addListener(autoc_home, 'place_changed',
		onHomePlaceChanged);

	// This is a more elegant way of handling users bypassing the autocomplete
	// suggestions. It forces the API to reassess the value in the text input.
	autochtabbing = google.maps.event.addDomListener(document.getElementById(
		'form-home-delivery-address-full'), 'focusout', function() {
		google.maps.event.trigger(this, 'focus');
		google.maps.event.trigger(this, 'keydown', {
			keyCode: 13
		});
	});

};

/**
 * Normalizes data returned from Google Places Autocomplete service
 *
 * @param array d address_components object
 *
 * @return array of data with defined data points
 *  num (street_num)
 *  street (route)
 *  city (locality)
 *  county (admin_area_level_2)
 *  state (admin_area_level_1)
 *  zip (postal_code)
 *  zip_plus (postal_code_suffix)
 *
 */
function returnDataSet(d) {
	var elCount = 0; // how many elements in this array
	if (typeof d != 'undefined') {
		elCount = d.length;
	}
	var tmp; // placeholder variable we'll use as we traverse the array
	norm = []; // dump array contents,in case user has reentered data.
	// prep the elements in case of a non-complete response.
	norm.num_l = "";
	norm.num_s = "";
	norm.street_l = "";
	norm.street_s = "";
	norm.biz_l = "";
	norm.biz_s = "";
	norm.city_l = "";
	norm.city_s = "";
	norm.county_l = "";
	norm.county_s = "";
	norm.state_l = "";
	norm.state_s = "";
	norm.country_l = "";
	norm.country_s = "";
	norm.zip_l = "";
	norm.zip_s = "";
	norm.street_full = "";

	for (var x = 0; x < elCount; x++) {
		tmp = d[x];
		norm.determined_by = 'suggestion'; // create flag that user accepted suggestion
		// norm.full_input = $(
		// 	'#edit-submitted-autocompleted-address').val(); // the original input that the user saw in the box.

		if (d[x].types[0] === 'street_number') { // 330
			norm.num_l = tmp.long_name;
			norm.num_s = tmp.short_name;
		}
		if (d[x].types[0] === 'route') { // N Wabash Ave
			norm.street_l = tmp.long_name;
			norm.street_s = tmp.short_name;
		}
		if (d[x].types[0] === 'establishment') { // Summit Media Group
			norm.biz_l = tmp.long_name;
			norm.biz_s = tmp.short_name;
		}
		if (d[x].types[0] === 'locality') { // Chicago
			norm.city_l = tmp.long_name;
			norm.city_s = tmp.short_name;
		}
		if (d[x].types[0] === 'administrative_area_level_2') { // Cook County
			norm.county_l = tmp.long_name;
			norm.county_s = tmp.short_name;
		}
		if (d[x].types[0] === 'administrative_area_level_1') { // Illinois
			norm.state_l = tmp.long_name;
			norm.state_s = tmp.short_name;
		}
		if (d[x].types[0] === 'country') { // United States / US
			norm.country_l = tmp.long_name;
			norm.country_s = tmp.short_name;
		}
		if (d[x].types[0] === 'postal_code') { // 60611
			norm.zip_l = tmp.long_name;
			norm.zip_s = tmp.short_name;
		}
		if (d[x].types[0] === 'postal_code_suffix') { // 60611-1234
			norm.zip_l = norm.zip_l + '-' + tmp.long_name;
			norm.zip_s = norm.zip_s + '-' + tmp.short_name;
		}
	}
	norm.street_full = norm.num_l + ' ' + norm.street_l; // full street address
	return norm; // return the normalized array of data.
}

/**
 * EventListener called when the Home Autocomplete field changes state.
 */
function onCompPlaceChanged() {
	var y; // placeholder for returned data
	phcompdata = autoc_comp.getPlace(); // attempt to get the place object from the value entered.

	// If the phdata object is defined and has the address_components element,
	// meaning that the user took a suggestion, we'll handle that data and store
	// it for transmission.
	if ((typeof phcompdata != 'undefined') && (phcompdata.address_components)) {

		// ga('send', 'event', 'subscribe form metrics',
		// 	'Selected Google suggested home address',
		// 	'Input action');

		y = returnDataSet(phcompdata.address_components); // we normalize it so we can consistently refer to it later on.
		ractive.set('compGoogleData', y); // set the google work address object to the returned google data

	} else {
		// if autocomplete couldn't return a complete object, we'll assume it's
		// someone ignoring the suggestions and save the entire input in the
		// street_address field, and zero out the other fields, in case they
		// previous selected a suggestion.

		// ga('send', 'event', 'subscribe form metrics',
		// 	'Ignored Google suggested home address',
		// 	'Input action');
		ractive.set('compGoogleData', $("#form-company-address-full").val()); // if the google response was ignored, set the Ractive data point as a string
	}
}

/**
 * EventListener called when the Home Autocomplete field changes state.
 */
function onHomePlaceChanged() {
	var y; // placeholder for returned data
	phdata = autoc_home.getPlace(); // attempt to get the place object from the value entered.

	// If the phdata object is defined and has the address_components element,
	// meaning that the user took a suggestion, we'll handle that data and store
	// it for transmission.
	if ((typeof phdata != 'undefined') && (phdata.address_components)) {
		ga('send', 'event', 'AW Subscription Form',
			'Selected Google suggested home address',
			'Input action');
		y = returnDataSet(phdata.address_components); // we normalize it so we can consistently refer to it later on.
		ractive.set('homeGoogleData', y); // set the google home address object to the returned google data
	} else {
		// if autocomplete couldn't return a complete object, we'll assume it's
		// someone ignoring the suggestions and save the entire input in the
		// street_address field, and zero out the other fields, in case they
		// previous selected a suggestion.

		ga('send', 'event', 'AW Subscription Form',
			'Ignored Google suggested home address',
			'Input action');
		ractive.set('homeGoogleData', $("#form-home-delivery-address-full").val()); // if the google response was ignored, set the Ractive data point as a string
	}
}

$(function() {
	// listen for changes to the newsletter box object and fire a Ractive event
	// if changes are made. #watchthethrone
	watch(viaNewsletter, "userEmail", function() {
		ractive.togglePrevEmail();
	});

	$("#newsletter-input-value").on('focus', function() {
		$(this).removeClass('newsletter-input-error');
		$(".newsletter-input-box").removeAttr('data-hint');
	});



	$("#newsletter-submit-button").click(function() {
		var isValid = true; // assume positive intent
		var inputVal = $("#newsletter-input-value").val();

		// if the field is empty and they hit submit, just do nothing.
		if (inputVal === "") {
			return;
		}

		if (inputVal.length < $("#newsletter-input-value").attr('minlength')) {
			$("#newsletter-input-value").addClass('newsletter-input-error');
			$(".newsletter-input-box").attr('data-hint',
				'This appears to be too short to be an email address');
			return;
		}

		// Added to make regex case insensitive and not look at anything after the @
		var xy = inputVal.indexOf("@");
		if (xy <= 0) {
			$("#newsletter-input-value").addClass('newsletter-input-error');
			$(".newsletter-input-box").attr('data-hint',
				'Please enter a valid email address');
			return;
		}

		// check for 'undesirable' email names
		var rr = /(?:info|sales|sale|help|marketing)/ig;
		var xz = inputVal.substring(0, xy);

		if (rr.test(xz)) {
			$("#newsletter-input-value").addClass('newsletter-input-error');
			$(".newsletter-input-box").attr('data-hint',
				'Please do not use emails starting with sales, info or help. Thank you.'
			);
			return;
		}

		// validate against known email patterns.
		var r =
			/([-!#-'*+/-9=?A-Z^-~]+(\.[-!#-'*+/-9=?A-Z^-~]+)*|"([]!#-[^-~ \t]|(\\[\t -~]))+")@[0-9A-Za-z]([0-9A-Za-z-]{0,61}[0-9A-Za-z])?(\.[0-9A-Za-z]([0-9A-Za-z-]{0,61}[0-9A-Za-z])?)*\.(net|org|com|info|etc|co.*|aero|coop|info|museum|name|biz|xxx|ac|af|ax|al|dz|us|as|ad|ao|ai|aq|ag|an|ar|am|aw|au|at|az|bs|bh|bd|bb|by|be|bz|bj|bm|bt|bo|ba|bw|bv|br|io|bn|bg|bf|mm|bi|kh|cm|ca|cv|ky|cf|td|cl|cn|cx|cc|co|km|cd|cg|ck|cr|ci|hr|cu|an|cy|cz|dk|dj|dm|do|tp|ec|eg|sv|uk|gq|er|ee|et|eu|fo|fj|fi|fr|gf|pf|tf|ga|gm|ge|gs|de|gh|gi|gb|gr|gl|gd|gp|gu|gt|gg|sr|gf|gn|gw|gq|pg|gy|ht|hm|va|hn|hk|hr|hu|is|in|io|id|ir|iq|ie|im|il|it|ci|jm|jp|je|jo|kz|cc|ke|ki|kn|kp|kr|kw|kg|lk|la|lv|lb|ls|lr|ly|li|lt|lc|lu|mo|mk|mg|mw|my|mv|ml|mt|fk|mp|mh|mr|mu|yt|fm|mx|md|mc|mn|me|ms|ma|mz|mm|na|nr|np|nl|an|nc|pg|nz|ni|ne|ng|nu|nf|mp|kp|no|om|pk|pw|ps|pa|pg|py|pe|ph|pm|pn|pl|pf|pt|pr|qa|re|ro|ru|rw|sh|kn|lc|vc|sv|as|sm|gs|st Arabia|sa|sn|rs|me|cs|rs|sc|sl|sg|sk|si|sb|so|za|kr|su|es|lk|sd|sr|sj|sz|se|ch|sy|tw|tj|tz|thno|tp|tl|tg|tk|to|tt|tn|tr|tm|tc|tv|ug|ua|ae|uk|us|um|vi|uy|uz|vu|va|ve|vn|vg|vi|wf|eh|ws|ye|yu|me|rs|zr|zw|zm)/ig;
		if (!r.test(inputVal)) {
			$("#newsletter-email-value").addClass('newsletter-input-error');
			$(".newsletter-input-box").attr('data-hint',
				'Please enter a valid email address');
			return;
		}

		// if all statuses are met, pass this into the watched object.
		viaNewsletter.userEmail = inputVal;
		modal.open();
		setTimeout(function() {
			$("#primary-input").focus();
		}, 100);


		// TODO: add the pop open code for the subscribe tab

		// TODO: at this point, we could add an AJAX call that writes an email only
		// entry to the database, for following up on those that don't complete the
		// form out to the end.
	});



	/**
	 * This function extends the jQuery UI autocomplete widget.
	 * We apply some custom code to make the drop down use HTML in its output.
	 * the .select call calls a ractive event to suck the data into the Ractive model.
	 */
	var primaryInput = $("#primary-input").autocomplete({
		source: function(request, response) {
			$.ajax({
				url: "//leadworks.pmmimediagroup.com/api/getCompaniesByName",
				dataType: "jsonp",
				data: {
					name: request.term
				},
				delay: 500, // half second delay before we initiate the API call.
				success: function(data) { // if we receive a response with data in it.
					if (data.length < 6) {
						// set the min-height of the dropdown dynamically.
						$(".ui-autocomplete").css('min-height', (data.length *
								3.75) +
							'em');
						var uileft = $(".ui-autocomplete").css('left');
						$(".ui-autocomplete").css('left', uileft + 8 + "px");

					}
					response($.map(data, function(item) {
						return {
							label: item.company_name + ' ' + item.label,
							value: item.company_name,
							data: item
						};
					}));
				}
			});
		},
		minLength: 2, // min amount of characters need to initiate a search
		create: function() { // create the autocomplete object on the defined element
			$(".ui-autocomplete").addClass('bootstrap'); // wrap this with bootstrap as well, since it exists separately on the page from the rest of the form (actually).

			// attempt to make the dropdown width more reasonable based on its parent.
			$(".ui-front").width($(".prime-row").outerWidth() + $(
				"#primary-input + * + div").width());
			$(".ui-state-hover.ui-corner-all, .ui-state-focus.ui-corner-all").width(
				$(".prime-row").outerWidth());

		},
		select: function(event, ui) { // called when a user selects an entry
			ractive.listSelect(event, ui);
			ga('send', 'event', 'PP OEM Subscription Form',
				'User selected an entry in the company dropdown',
				'Input action');
		},
		focus: function(event, ui) { // called when the user focuses onto the input element
			ractive.set('prevKey', null);
			// hide the prompt for new company if it's no longer needed
		},
		open: function(event, ui) { // called when the list dropdown opens up
			var analytics = $(this).data('ui-autocomplete');
			var prev = (analytics.previous !== '') ? analytics.previous : "";
			ga('send', 'event', 'AW Subscription Form',
				'Company dropdown was triggered',
				'Input action');

			if ($(".ui-menu-item").length > 10) {
				ractive.set('promptScrollOnPrimaryInput', true); // yes, we should add prompting to scroll the list
				ga('send', 'event', 'AW Subscription Form',
					'Company dropdown trigger was over ten items',
					'Input action');
				$(".ui-menu-item:nth-child(10)").after(
					'<li class="longListConcern">Scroll to see more <i class="fa fa-fw fa-angle-double-down"></i></li>'
				);
			} else {
				ractive.set('promptScrollOnPrimaryInput', false); // no need to prompt scrolling the list
			}
		},
		close: function(event, ui) { // called when the list closes
		}
	});


});
