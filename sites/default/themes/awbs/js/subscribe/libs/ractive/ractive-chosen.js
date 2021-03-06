! function(a, b) {
	"use strict";
	if ("undefined" != typeof module && module.exports && "function" == typeof require)
		b(require("ractive"), require("jquery"));
	else if ("function" == typeof define && define.amd) define(["ractive",
		"jquery"
	], b);
	else {
		if (!a.Ractive || !a.jQuery) throw new Error(
			"Could not find Ractive or jQuery! They must be loaded before the ractive-decorators-chosen plugin"
		);
		b(a.Ractive, a.jQuery)
	}
}("undefined" != typeof window ? window : this, function(a, b) {
	"use strict";
	var c;
	c = function(a, d) {
		var e, f = a._ractive.root,
			g = !1,
			h = {};
		if (d) {
			if (!c.type.hasOwnProperty(d)) throw new Error('Ractive Chosen type "' + d +
				'" is not defined!');
			h = c.type[d], "function" == typeof h && (h = h.call(this, a))
		}
		return a._ractive.binding && (e = f.observe(a._ractive.binding.keypath,
			function(c, d) {
				g || (g = !0, window.setTimeout(function() {
					("" === c || c !== d) && b(a).trigger("chosen:updated"), b(a).change(),
						g = !1
				}, 0))
			})), b(a).chosen(h).on("change", function() {
			g || (g = !1, f.updateModel())
		}), {
			teardown: function() {
				b(a).chosen("destroy"), e && e.cancel()
			}
		}
	}, c.type = {}, a.decorators.chosen = c
});
