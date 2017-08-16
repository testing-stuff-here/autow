var ss = jQuery.LiveAddress({
    key: "19862413637956093",
    debug: false,
    waitForStreet: true,
    verifySecondary: true,
    enforceVerification: true,
    autoVerify: false,
    submitSelector: '[type=submit]:last',
    addresses: [
        {
            id: 'Address',
            street: '#smg_autocomplete_address_text',
            country: '#edit-submitted-country'
        }
    ]
});

ss.on("AddressAccepted", function (event, data, previousHandler) {
    if (!data.hasOwnProperty('response')) return;
    if (!data.response.hasOwnProperty('raw')) return;

    var rawResponse = data.response.raw[0];
    var addressComponents = rawResponse.components;
    var jsonResponse = JSON.stringify(rawResponse);
    document.querySelector("input#smg_autocomplete_address_response").value = jsonResponse;
    document.querySelector("input#smg_autocomplete_address_line_1").value = rawResponse.delivery_line_1;
    if (typeof rawResponse.delivery_line_2 !== 'undefined') {
        document.querySelector("input#smg_autocomplete_address_line_2").value = rawResponse.delivery_line_2;
    }
    if (typeof addressComponents.city_name !== 'undefined') {
        document.querySelector("input#smg_autocomplete_address_city").value = addressComponents.city_name;
    }
    if (typeof addressComponents.state_abbreviation !== 'undefined') {
        document.querySelector("input#smg_autocomplete_address_state").value = addressComponents.state_abbreviation;
    }
    if (typeof addressComponents.zipcode !== 'undefined') {
        document.querySelector("input#smg_autocomplete_address_zip").value = addressComponents.zipcode;
    }
    previousHandler(event, data);
});
