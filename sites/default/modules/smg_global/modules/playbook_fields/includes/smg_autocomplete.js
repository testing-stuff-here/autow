// some jQuery trickery to make the interface work the way we want it to.
jQuery(document).ready(function($) {

 var focusables = $(":focusable"); // grab all the inputs on the page
 var norm = []; // data to be returned
 var autoclistener; // our Autocomplete Places listener callback
 var autoc; // our Autocomplete element
 var pdata = {}; // our Place data

 var initAutocomplete = function() {
  // we bind the autocomplete object to the input field
  autoc = new google.maps.places.Autocomplete(
   (document.getElementById('edit-submitted-autocompleted-address')), {
    types: ['geocode']
   }
  );

  // we add an event listener to the autocomplete object, which is triggered
  // when the user selects something off of the list provided by Google.
  autoclistener = google.maps.event.addListener(autoc, 'place_changed',
   onPlaceChanged);

  // This is a more elegant way of handling users bypassing the autocomplete
  // suggestions. It forces the API to reassess the value in the text input.
  autoctabbing = google.maps.event.addDomListener(document.getElementById(
   'edit-submitted-autocompleted-address'), 'focusout', function() {

   // if the user has inputted blank spaces, disallow that so that the form will
   // not submit until valid input is met.
   var regexp = /(^ *$)/g; // regex expression to check for a purely blank space string
   var result = regexp.test($("#edit-submitted-autocompleted-address").val()); // get the value that's current in the autocomplete field on blur
   if (result) { // if the test of the value against reg ex is true, it's blank
    $("#edit-submitted-autocompleted-address").val(''); // set the value to nothing.
   }

   google.maps.event.trigger(this, 'focus');
   google.maps.event.trigger(this, 'keydown', {
    keyCode: 13
   });
  });
 }

 // initialize the Autocomplete element.
 initAutocomplete();

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

  // we have to initialize this array for when numbers don't pass through for
  // whatever reason. further minimize randomness from google.
  norm['num_l'] = '';
  norm['num_s'] = '';
  norm['street_l'] = '';
  norm['street_s'] = '';
  norm['biz_l'] = '';
  norm['biz_s'] = '';
  norm['city_l'] = '';
  norm['city_s'] = '';
  norm['county_l'] = '';
  norm['county_s'] = '';
  norm['state_l'] = '';
  norm['state_s'] = '';
  norm['zip_l'] = '';
  norm['zip_s'] = '';
  norm['country_l'] = '';
  norm['country_s'] = '';
  norm['street_full'] = '';

  for (var x = 0; x < elCount; x++) {
   tmp = d[x];
   norm['determined_by'] = 'suggestion'; // create flag that user accepted suggestion
   norm['full_input'] = $(
    '#edit-submitted-autocompleted-address').val(); // the original input that the user saw in the box.

   if (d[x]['types'][0] === 'street_number') { // 330
    norm['num_l'] = tmp['long_name'];
    norm['num_s'] = tmp['short_name'];
   }
   if (d[x]['types'][0] === 'route') { // N Wabash Ave
    norm['street_l'] = tmp['long_name'];
    norm['street_s'] = tmp['short_name'];
   }
   if (d[x]['types'][0] === 'establishment') { // Summit Media Group
    norm['biz_l'] = tmp['long_name'];
    norm['biz_s'] = tmp['short_name'];
   }
   if (d[x]['types'][0] === 'locality') { // Chicago
    norm['city_l'] = tmp['long_name'];
    norm['city_s'] = tmp['short_name'];
   }
   if (d[x]['types'][0] === 'administrative_area_level_2') { // Cook County
    norm['county_l'] = tmp['long_name'];
    norm['county_s'] = tmp['short_name'];
   }
   if (d[x]['types'][0] === 'administrative_area_level_1') { // Illinois
    norm['state_l'] = tmp['long_name'];
    norm['state_s'] = tmp['short_name'];
   }
   if (d[x]['types'][0] === 'country') { // United States / US
    norm['country_l'] = tmp['long_name'];
    norm['country_s'] = tmp['short_name'];
   }
   if (d[x]['types'][0] === 'postal_code') { // 60611
    norm['zip_l'] = tmp['long_name'];
    norm['zip_s'] = tmp['short_name'];
   }
   if (d[x]['types'][0] === 'postal_code_suffix') { // 60611-1234
    norm['zip_l'] = norm['zip_l'] + '-' + tmp['long_name'];
    norm['zip_s'] = norm['zip_s'] + '-' + tmp['short_name'];
   }
  }
  norm['street_full'] = norm['num_l'] + ' ' + norm['street_l']; // full street address
  return norm; // return the normalized array of data.
 }

 /**
  * EventListener called when the Autocomplete field changes state.
  */
 function onPlaceChanged() {
  var y; // placeholder for returned data
  pdata = autoc.getPlace(); // attempt to get the place object from the value entered.

  // If the pdata object is defined and has the address_components element,
  // meaning that the user took a suggestion, we'll handle that data and store
  // it for transmission.

  if ((typeof pdata != 'undefined') && (pdata.address_components)) {
   y = returnDataSet(pdata.address_components); // we normalize it so we can consistently refer to it later on.

   $('input[name="submitted[street_address]"]').val(y[
    'street_full']); // 330 N Wabash
   $('input[name="submitted[city]"]').val(y['city_l']); // Chicago
   $('input[name="submitted[state]"]').val(y['state_s']); // IL
   $('input[name="submitted[zipcode]"]').val(y['zip_l']); // 60611-1234

   // If a country is presented with the result set, fill in the visible
   // form element and it's value,you so that's transferred to Silverpop
   if (typeof y['country_l'] != 'undefined') {
    $('#edit-submitted-country').val(y['country_l'].toUpperCase()); // US
    document.getElementById('webform-component-country').getElementsByTagName(
     'span')[2].textContent = y['country_l']; // United States

   } else { // Otherwise, if no country is set, set the Country to nothing to force user to fill it in.
    $('#edit-submitted-country').val('');
    document.getElementById('webform-component-country').getElementsByTagName(
     'span')[2].textContent = '- Select -';
   }
   // // If a business ('establishment') is presented with the result set, fill it in
   if (typeof y['biz_l'] != 'undefined') {
    $('#edit-submitted-company-name').val(y['biz_l']);
   }
   // fill in the method by which this address was provided
   $('input[name="submitted[user_selection_method]"]').val(y[
    'determined_by']);
   // fill in the full string that the user saw on the form.
   $('input[name="submitted[master_address_string]"]').val(y[
    'full_input']);
  } else {
   // if autocomplete couldn't return a complete object, we'll assume it's
   // someone ignoring the suggestions and save the entire input in the
   // street_address field, and zero out the other fields, in case they
   // previous selected a suggestion.
   $('input[name="submitted[street_address]"]').val($(
    '#edit-submitted-autocompleted-address').val());
   $('input[name="submitted[city]"]').val('');
   $('input[name="submitted[state]"]').val('');
   $('input[name="submitted[zipcode]"]').val('');
   $('#edit-submitted-country').val('');
   document.getElementById('webform-component-country').getElementsByTagName(
    'span')[2].textContent = '- Select -';
   $('input[name="submitted[user_selection_method]"]').val('user'); // the user determined this, not Google Autocomplete Places
   // fill in the full string that the user saw on the form.
   // in this instance, it should be the same as 'street_address', but we save
   // it anyways, for consistency's sake.
   $('input[name="submitted[master_address_string]"]').val($(
    '#edit-submitted-autocompleted-address').val());
  }
 }

 // capture keypress on the autocomplete input field, and act if the input is a
 // carriage return.
 $("#edit-submitted-autocompleted-address").on('keypress', function(e) {
  var k = e.which || e.keyCode; // could be either in a jQuery environment.
  if (k == 13) {
   e.preventDefault(); // don't submit the form on enter!
   var current = focusables.index(this), // now find where this form is
    next = focusables.eq(current + 1).length ? focusables.eq( // and who's next to it.
     current + 1) : focusables.eq(0);
   next.focus(); // and we move to the next input element.
  }
 });

});
