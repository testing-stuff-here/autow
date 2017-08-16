/*
 * jQuery UI Autocomplete HTML Extension
 *
 * Copyright 2010, Scott González (http://scottgonzalez.com)
 * Dual licensed under the MIT or GPL Version 2 licenses.
 *
 * http://github.com/scottgonzalez/jquery-ui-extensions
 *
 * A. Telischak - made modifications to the outputted HTML to mimic previous
 * styling under higher version of JQuery UI (02/2015)
 */
(function($) {
	var proto = $.ui.autocomplete.prototype,
		initSource = proto._initSource;

	function filter(array, term) {
		var matcher = new RegExp($.ui.autocomplete.escapeRegex(term), "i");
		return $.grep(array, function(value) {
			return matcher.test($("<div>").html(value.label || value.value || value)
				.text());
		});
	}

	$.extend(proto, {
		_initSource: function() {
			if (this.options.html && $.isArray(this.options.source)) {
				this.source = function(request, response) {
					response(filter(this.options.source, request.term));
				};
			} else {
				initSource.call(this);
			}
		},

		_renderItem: function(ul, item) {
			return $("<li class='row'></li>")
				.data("item.autocomplete", item)
				// .append($("<a></a>")[this.options.html ? "html" : "text"](item.company_name))
				.append($("<a><div  class='col-sm-12 text-left ui-company'>" + item.data
					.company_name +
					"</div><div class='col-sm-12 text-left ui-address'>" + item.data.label +
					"</div></a>"))
				.appendTo(ul);
		}
	});

})(jQuery);
