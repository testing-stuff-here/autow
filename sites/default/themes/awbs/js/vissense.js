/*! { "name": "vissense", "version": "0.6.1", "homepage": "https://vissense.github.io/vissense","copyright": "(c) 2015 tbk" } */ !
function(a, b, c) {
	"use strict";
	var d = a[b],
		e = c(a, a.document);
	a[b] = e, a[b].noConflict = function() {
		return a[b] = d, e
	}
}(this, "VisSense", function(a, b, c) {
	"use strict";

	function d(a, b) {
		return function() {
			var d = arguments;
			return g(function() {
				a.apply(c, d)
			}, b || 0)
		}
	}

	function e(a, b) {
		var c = q;
		return function() {
			var d = this,
				e = arguments;
			c(), c = g(function() {
				a.apply(d, e)
			}, b)
		}
	}

	function f(a, b) {
		var d = p(b),
			e = p(a);
		return d || e ? d && e ? (j(Object.keys(b), function(d) {
			a[d] === c && (a[d] = b[d])
		}), a) : d ? b : a : b
	}

	function g(a, b) {
		var c = setTimeout(function() {
			a()
		}, b || 0);
		return function() {
			clearTimeout(c)
		}
	}

	function h(a, b) {
		return function() {
			return (o(a) ? a() : a) ? b() : c
		}
	}

	function i(a, b, c) {
		for (var d = -1, e = Object.keys(b), f = e.length, g = o(c); ++d < f;) {
			var h = e[d];
			a[h] = g ? c(a[h], b[h], h, a, b) : b[h]
		}
		return a
	}

	function j(a, b, d) {
		for (var e = 0, f = a.length; f > e; e++) {
			var g = b.call(d, a[e], e, a);
			if (g !== c) return g
		}
	}

	function k(a) {
		return a
	}

	function l(a) {
		return a !== c
	}

	function m(a) {
		return a && "object" == typeof a && "number" == typeof a.length &&
			"[object Array]" === Object.prototype.toString.call(a) || !1
	}

	function n(a) {
		return a && 1 === a.nodeType || !1
	}

	function o(a) {
		return "function" == typeof a || !1
	}

	function p(a) {
		var b = typeof a;
		return "function" === b || a && "object" === b || !1
	}

	function q() {}

	function r() {
		return (new Date).getTime()
	}

	function s(a) {
		var b, d = !1;
		return function() {
			return d || (b = a.apply(c, arguments), d = !0), b
		}
	}

	function t(a, b, c) {
		var d = q,
			e = !1;
		return function() {
			var f = r(),
				h = arguments,
				i = function() {
					e = f, a.apply(c, h)
				};
			e && e + b > f ? (d(), d = g(i, b)) : (e = f, g(i, 0))
		}
	}

	function u() {
		return {
			height: a.innerHeight,
			width: a.innerWidth
		}
	}

	function v(b) {
		return a.getComputedStyle(b, null)
	}

	function w(a, b) {
		return a.getPropertyValue(b)
	}

	function x(a, b) {
		b || (b = v(a));
		var c = w(b, "display");
		if ("none" === c) return !1;
		var d = w(b, "visibility");
		if ("hidden" === d || "collapse" === d) return !1;
		var e = a.parentNode;
		return n(e) ? x(e) : !0
	}

	function y(a) {
		if (a === b) return !0;
		if (!a || !a.parentNode) return !1;
		var c = v(a);
		return x(a, c)
	}

	function z(a, b) {
		return !a || a.width <= 0 || a.height <= 0 ? !1 : a.bottom > 0 && a.right >
			0 && a.top < b.height && a.left < b.width
	}

	function A(a) {
		var b = a.getBoundingClientRect(),
			c = u();
		if (!z(b, c) || !y(a)) return 0;
		var d = 0,
			e = 0;
		return b.top >= 0 ? d = Math.min(b.height, c.height - b.top) : b.bottom > 0 &&
			(d = Math.min(c.height, b.bottom)), b.left >= 0 ? e = Math.min(b.width, c.width -
				b.left) : b.right > 0 && (e = Math.min(c.width, b.right)), Math.round(d *
				e / (b.height * b.width) * 1e3) / 1e3
	}

	function B() {
		return !F.isHidden()
	}

	function C(a, b) {
		if (!(this instanceof C)) return new C(a, b);
		if (!n(a)) throw new Error("not an element node");
		this._element = a, this._config = f(b, {
			fullyvisible: 1,
			hidden: 0,
			percentageHook: A,
			visibilityHooks: []
		}), this._config.visibilityHooks.push(function() {
			return B()
		})
	}

	function D(a, b) {
		var c = a.state(),
			d = c.percentage;
		return b && d === b.percentage && b.percentage === b.previous.percentage ?
			b : c.hidden ? C.VisState.hidden(d, b) : c.fullyvisible ? C.VisState.fullyvisible(
				d, b) : C.VisState.visible(d, b)
	}

	function E(a, b) {
		this._visobj = a, this._state = {}, this._started = !1, this._pubsub = new G,
			this._events = ["start", "stop", "update", "hidden", "visible",
				"fullyvisible", "percentagechange", "visibilitychange"
			];
		var c = f(b, {
			strategy: [new E.Strategy.PollingStrategy, new E.Strategy.EventStrategy],
			async: !1
		});
		this._strategy = new E.Strategy.CompositeStrategy(c.strategy), this._strategy
			.init(this), this._pubsub.on("update", function(a) {
				var b = a._state.percentage,
					c = a._state.previous.percentage;
				b !== c && a._pubsub.publish("percentagechange", [a, b, c])
			}), this._pubsub.on("update", function(a) {
				a._state.code !== a._state.previous.code && a._pubsub.publish(
					"visibilitychange", [a])
			}), this._pubsub.on("visibilitychange", function(a) {
				a._state.visible && !a._state.previous.visible && a._pubsub.publish(
					"visible", [a])
			}), this._pubsub.on("visibilitychange", function(a) {
				a._state.fullyvisible && a._pubsub.publish("fullyvisible", [a])
			}), this._pubsub.on("visibilitychange", function(a) {
				a._state.hidden && a._pubsub.publish("hidden", [a])
			}), j(this._events, function(a) {
				o(c[a]) && this.on(a, c[a])
			}, this)
	}
	var F = function(a, b) {
			var c = function(a, b) {
					return {
						property: a,
						event: b
					}
				},
				d = "visibilitychange",
				e = [c("webkitHidden", "webkit" + d), c("msHidden", "ms" + d), c(
					"mozHidden", "moz" + d), c("hidden", d)],
				f = j(e, function(c) {
					return a[c.property] !== b ? {
						isHidden: function() {
							return !!a[c.property] || !1
						},
						onVisibilityChange: function(b) {
							return a.addEventListener(c.event, b, !1),
								function() {
									a.removeEventListener(c.event, b, !1)
								}
						}
					} : void 0
				});
			return f || {
				isHidden: function() {
					return !1
				},
				onVisibilityChange: function() {
					return q
				}
			}
		}(b),
		G = function(a) {
			function b(a) {
				this._cache = {}, this._onAnyCache = [], this._config = f(a, {
					async: !1,
					anyTopicName: "*"
				})
			}
			var c = function(a, b, c) {
				j(b, function(a) {
					a(c)
				})
			};
			return b.prototype.on = function(b, c) {
				if (!o(c)) return q;
				var e = function(b) {
						return c.apply(a, b || [])
					},
					f = this._config.async ? d(e) : e,
					g = function(a, b, c) {
						return function() {
							var c = b.indexOf(a);
							return c > -1 ? (b.splice(c, 1), !0) : !1
						}
					};
				return b === this._config.anyTopicName ? (this._onAnyCache.push(f), g(f,
					this._onAnyCache, "*")) : (this._cache[b] || (this._cache[b] = []),
					this._cache[b].push(f), g(f, this._cache[b], b))
			}, b.prototype.publish = function(a, b) {
				var e = (this._cache[a] || []).concat(a === this._config.anyTopicName ? [] :
						this._onAnyCache),
					f = this._config.async ? d(c) : c;
				return f(a, e, b || [])
			}, b
		}();
	C.prototype.state = function() {
		var a = j(this._config.visibilityHooks, function(a) {
			return a(this._element) ? void 0 : C.VisState.hidden(0)
		}, this);
		return a || function(a, b) {
			var c = b.percentageHook(a);
			return c <= b.hidden ? C.VisState.hidden(c) : c >= b.fullyvisible ? C.VisState
				.fullyvisible(c) : C.VisState.visible(c)
		}(this._element, this._config)
	}, C.prototype.percentage = function() {
		return this.state().percentage
	}, C.prototype.element = function() {
		return this._element
	}, C.prototype.isFullyVisible = function() {
		return this.state().fullyvisible
	}, C.prototype.isVisible = function() {
		return this.state().visible
	}, C.prototype.isHidden = function() {
		return this.state().hidden
	}, C.fn = C.prototype, C.of = function(a, b) {
		return new C(a, b)
	};
	var H = {
		HIDDEN: [0, "hidden"],
		VISIBLE: [1, "visible"],
		FULLY_VISIBLE: [2, "fullyvisible"]
	};
	return C.VisState = function() {
			function a(a, b, c) {
				return c && delete c.previous, {
					code: a[0],
					state: a[1],
					percentage: b,
					previous: c || {},
					fullyvisible: a[0] === H.FULLY_VISIBLE[0],
					visible: a[0] === H.VISIBLE[0] || a[0] === H.FULLY_VISIBLE[0],
					hidden: a[0] === H.HIDDEN[0]
				}
			}
			return {
				hidden: function(b, c) {
					return a(H.HIDDEN, b, c)
				},
				visible: function(b, c) {
					return a(H.VISIBLE, b, c)
				},
				fullyvisible: function(b, c) {
					return a(H.FULLY_VISIBLE, b, c)
				}
			}
		}(), E.prototype.visobj = function() {
			return this._visobj
		}, E.prototype.state = function() {
			return this._state
		}, E.prototype.start = function(a) {
			if (this._started) return this;
			var b = f(a, {
				async: !1
			});
			return this._cancelAsyncStart && this._cancelAsyncStart(), b.async ? this.startAsync() :
				(this.update(), this._pubsub.publish("start", [this]), this._strategy.start(
					this), this._started = !0, this)
		}, E.prototype.startAsync = function(a) {
			this._cancelAsyncStart && this._cancelAsyncStart();
			var b = this,
				c = g(function() {
					b.start(i(f(a, {}), {
						async: !1
					}))
				});
			return this._cancelAsyncStart = function() {
				c(), b._cancelAsyncStart = null
			}, this
		}, E.prototype.stop = function() {
			this._cancelAsyncStart && this._cancelAsyncStart(), this._started && (this._strategy
				.stop(this), this._pubsub.publish("stop", [this])), this._started = !1
		}, E.prototype.update = function() {
			this._state = D(this._visobj, this._state), this._pubsub.publish("update", [
				this
			])
		}, E.prototype.on = function(a, b) {
			return this._pubsub.on(a, b)
		}, E.Strategy = function() {}, E.Strategy.prototype.init = q, E.Strategy.prototype
		.start = q, E.Strategy.prototype.stop = q, E.Strategy.CompositeStrategy =
		function(a) {
			this._strategies = m(a) ? a : [a]
		}, E.Strategy.CompositeStrategy.prototype = Object.create(E.Strategy.prototype),
		E.Strategy.CompositeStrategy.prototype.init = function(a) {
			j(this._strategies, function(b) {
				o(b.init) && b.init(a)
			})
		}, E.Strategy.CompositeStrategy.prototype.start = function(a) {
			j(this._strategies, function(b) {
				o(b.start) && b.start(a)
			})
		}, E.Strategy.CompositeStrategy.prototype.stop = function(a) {
			j(this._strategies, function(b) {
				o(b.stop) && b.stop(a)
			})
		}, E.Strategy.PollingStrategy = function(a) {
			this._config = f(a, {
				interval: 1e3
			}), this._started = !1
		}, E.Strategy.PollingStrategy.prototype = Object.create(E.Strategy.prototype),
		E.Strategy.PollingStrategy.prototype.start = function(a) {
			return this._started || (this._clearInterval = function(b) {
				var c = setInterval(function() {
					a.update()
				}, b);
				return function() {
					clearInterval(c)
				}
			}(this._config.interval), this._started = !0), this._started
		}, E.Strategy.PollingStrategy.prototype.stop = function() {
			return this._started ? (this._clearInterval(), this._started = !1, !0) : !1
		}, E.Strategy.EventStrategy = function(a) {
			this._config = f(a, {
					throttle: 50
				}), this._config.debounce > 0 && (this._config.throttle = +this._config.debounce),
				this._started = !1
		}, E.Strategy.EventStrategy.prototype = Object.create(E.Strategy.prototype),
		E.Strategy.EventStrategy.prototype.start = function(a) {
			return this._started || (this._removeEventListeners = function(a) {
				var b = F.onVisibilityChange(a);
				return addEventListener("scroll", a, !1), addEventListener("resize", a, !
						1), addEventListener("touchmove", a, !1),
					function() {
						removeEventListener("touchmove", a, !1), removeEventListener("resize",
							a, !1), removeEventListener("scroll", a, !1), b()
					}
			}(t(function() {
				a.update()
			}, this._config.throttle)), this._started = !0), this._started
		}, E.Strategy.EventStrategy.prototype.stop = function() {
			return this._started ? (this._removeEventListeners(), this._started = !1, !
				0) : !1
		}, C.VisMon = E, C.PubSub = G, C.fn.monitor = function(a) {
			return new E(this, a)
		}, C.Utils = {
			async: d,
			debounce: e,
			defaults: f,
			defer: g,
			extend: i,
			forEach: j,
			fireIf: h,
			identity: k,
			isArray: m,
			isDefined: l,
			isElement: n,
			isFunction: o,
			isObject: p,
			isPageVisible: B,
			isVisibleByStyling: y,
			noop: q,
			now: r,
			once: s,
			throttle: t,
			percentage: A,
			VisibilityApi: F,
			_viewport: u,
			_isInViewport: z,
			_isDisplayed: x,
			_computedStyle: v,
			_styleProperty: w
		}, C
});
