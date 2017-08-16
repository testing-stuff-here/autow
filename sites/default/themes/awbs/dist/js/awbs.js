/*! jQuery UI - v1.11.2 - 2014-10-16
 * http://jqueryui.com
 * Includes: core.js, widget.js, mouse.js, position.js, accordion.js, autocomplete.js, button.js, datepicker.js, dialog.js, draggable.js, droppable.js, effect.js, effect-blind.js, effect-bounce.js, effect-clip.js, effect-drop.js, effect-explode.js, effect-fade.js, effect-fold.js, effect-highlight.js, effect-puff.js, effect-pulsate.js, effect-scale.js, effect-shake.js, effect-size.js, effect-slide.js, effect-transfer.js, menu.js, progressbar.js, resizable.js, selectable.js, selectmenu.js, slider.js, sortable.js, spinner.js, tabs.js, tooltip.js
 * Copyright 2014 jQuery Foundation and other contributors; Licensed MIT */

(function(e) {
 "function" == typeof define && define.amd ? define(["jquery"], e) : e(jQuery)
})(function(e) {
 function t(t, s) {
  var n, a, o, r = t.nodeName.toLowerCase();
  return "area" === r ? (n = t.parentNode, a = n.name, t.href && a && "map" ===
   n.nodeName.toLowerCase() ? (o = e("img[usemap='#" + a + "']")[0], !!o &&
    i(o)) : !1) : (/input|select|textarea|button|object/.test(r) ? !t.disabled :
   "a" === r ? t.href || s : s) && i(t)
 }

 function i(t) {
  return e.expr.filters.visible(t) && !e(t).parents().addBack().filter(
   function() {
    return "hidden" === e.css(this, "visibility")
   }).length
 }

 function s(e) {
  for (var t, i; e.length && e[0] !== document;) {
   if (t = e.css("position"), ("absolute" === t || "relative" === t ||
     "fixed" === t) && (i = parseInt(e.css("zIndex"), 10), !isNaN(i) && 0 !==
     i)) return i;
   e = e.parent()
  }
  return 0
 }

 function n() {
  this._curInst = null, this._keyEvent = !1, this._disabledInputs = [], this._datepickerShowing = !
   1, this._inDialog = !1, this._mainDivId = "ui-datepicker-div", this._inlineClass =
   "ui-datepicker-inline", this._appendClass = "ui-datepicker-append", this._triggerClass =
   "ui-datepicker-trigger", this._dialogClass = "ui-datepicker-dialog", this._disableClass =
   "ui-datepicker-disabled", this._unselectableClass =
   "ui-datepicker-unselectable", this._currentClass =
   "ui-datepicker-current-day", this._dayOverClass =
   "ui-datepicker-days-cell-over", this.regional = [], this.regional[""] = {
    closeText: "Done",
    prevText: "Prev",
    nextText: "Next",
    currentText: "Today",
    monthNames: ["January", "February", "March", "April", "May", "June",
     "July", "August", "September", "October", "November", "December"
    ],
    monthNamesShort: ["Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug",
     "Sep", "Oct", "Nov", "Dec"
    ],
    dayNames: ["Sunday", "Monday", "Tuesday", "Wednesday", "Thursday",
     "Friday", "Saturday"
    ],
    dayNamesShort: ["Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"],
    dayNamesMin: ["Su", "Mo", "Tu", "We", "Th", "Fr", "Sa"],
    weekHeader: "Wk",
    dateFormat: "mm/dd/yy",
    firstDay: 0,
    isRTL: !1,
    showMonthAfterYear: !1,
    yearSuffix: ""
   }, this._defaults = {
    showOn: "focus",
    showAnim: "fadeIn",
    showOptions: {},
    defaultDate: null,
    appendText: "",
    buttonText: "...",
    buttonImage: "",
    buttonImageOnly: !1,
    hideIfNoPrevNext: !1,
    navigationAsDateFormat: !1,
    gotoCurrent: !1,
    changeMonth: !1,
    changeYear: !1,
    yearRange: "c-10:c+10",
    showOtherMonths: !1,
    selectOtherMonths: !1,
    showWeek: !1,
    calculateWeek: this.iso8601Week,
    shortYearCutoff: "+10",
    minDate: null,
    maxDate: null,
    duration: "fast",
    beforeShowDay: null,
    beforeShow: null,
    onSelect: null,
    onChangeMonthYear: null,
    onClose: null,
    numberOfMonths: 1,
    showCurrentAtPos: 0,
    stepMonths: 1,
    stepBigMonths: 12,
    altField: "",
    altFormat: "",
    constrainInput: !0,
    showButtonPanel: !1,
    autoSize: !1,
    disabled: !1
   }, e.extend(this._defaults, this.regional[""]), this.regional.en = e.extend(!
    0, {}, this.regional[""]), this.regional["en-US"] = e.extend(!0, {}, this
    .regional.en), this.dpDiv = a(e("<div id='" + this._mainDivId +
    "' class='ui-datepicker ui-widget ui-widget-content ui-helper-clearfix ui-corner-all'></div>"
   ))
 }

 function a(t) {
  var i =
   "button, .ui-datepicker-prev, .ui-datepicker-next, .ui-datepicker-calendar td a";
  return t.delegate(i, "mouseout", function() {
   e(this).removeClass("ui-state-hover"), -1 !== this.className.indexOf(
    "ui-datepicker-prev") && e(this).removeClass(
    "ui-datepicker-prev-hover"), -1 !== this.className.indexOf(
    "ui-datepicker-next") && e(this).removeClass(
    "ui-datepicker-next-hover")
  }).delegate(i, "mouseover", o)
 }

 function o() {
  e.datepicker._isDisabledDatepicker(v.inline ? v.dpDiv.parent()[0] : v.input[
   0]) || (e(this).parents(".ui-datepicker-calendar").find("a").removeClass(
    "ui-state-hover"), e(this).addClass("ui-state-hover"), -1 !== this.className
   .indexOf("ui-datepicker-prev") && e(this).addClass(
    "ui-datepicker-prev-hover"), -1 !== this.className.indexOf(
    "ui-datepicker-next") && e(this).addClass("ui-datepicker-next-hover"))
 }

 function r(t, i) {
  e.extend(t, i);
  for (var s in i) null == i[s] && (t[s] = i[s]);
  return t
 }

 function h(e) {
  return function() {
   var t = this.element.val();
   e.apply(this, arguments), this._refresh(), t !== this.element.val() &&
    this._trigger("change")
  }
 }
 e.ui = e.ui || {}, e.extend(e.ui, {
   version: "1.11.2",
   keyCode: {
    BACKSPACE: 8,
    COMMA: 188,
    DELETE: 46,
    DOWN: 40,
    END: 35,
    ENTER: 13,
    ESCAPE: 27,
    HOME: 36,
    LEFT: 37,
    PAGE_DOWN: 34,
    PAGE_UP: 33,
    PERIOD: 190,
    RIGHT: 39,
    SPACE: 32,
    TAB: 9,
    UP: 38
   }
  }), e.fn.extend({
   scrollParent: function(t) {
    var i = this.css("position"),
     s = "absolute" === i,
     n = t ? /(auto|scroll|hidden)/ : /(auto|scroll)/,
     a = this.parents().filter(function() {
      var t = e(this);
      return s && "static" === t.css("position") ? !1 : n.test(t.css(
       "overflow") + t.css("overflow-y") + t.css("overflow-x"))
     }).eq(0);
    return "fixed" !== i && a.length ? a : e(this[0].ownerDocument ||
     document)
   },
   uniqueId: function() {
    var e = 0;
    return function() {
     return this.each(function() {
      this.id || (this.id = "ui-id-" + ++e)
     })
    }
   }(),
   removeUniqueId: function() {
    return this.each(function() {
     /^ui-id-\d+$/.test(this.id) && e(this).removeAttr("id")
    })
   }
  }), e.extend(e.expr[":"], {
   data: e.expr.createPseudo ? e.expr.createPseudo(function(t) {
    return function(i) {
     return !!e.data(i, t)
    }
   }) : function(t, i, s) {
    return !!e.data(t, s[3])
   },
   focusable: function(i) {
    return t(i, !isNaN(e.attr(i, "tabindex")))
   },
   tabbable: function(i) {
    var s = e.attr(i, "tabindex"),
     n = isNaN(s);
    return (n || s >= 0) && t(i, !n)
   }
  }), e("<a>").outerWidth(1).jquery || e.each(["Width", "Height"], function(t,
   i) {
   function s(t, i, s, a) {
    return e.each(n, function() {
     i -= parseFloat(e.css(t, "padding" + this)) || 0, s && (i -=
      parseFloat(e.css(t, "border" + this + "Width")) || 0), a && (i -=
      parseFloat(e.css(t, "margin" + this)) || 0)
    }), i
   }
   var n = "Width" === i ? ["Left", "Right"] : ["Top", "Bottom"],
    a = i.toLowerCase(),
    o = {
     innerWidth: e.fn.innerWidth,
     innerHeight: e.fn.innerHeight,
     outerWidth: e.fn.outerWidth,
     outerHeight: e.fn.outerHeight
    };
   e.fn["inner" + i] = function(t) {
    return void 0 === t ? o["inner" + i].call(this) : this.each(function() {
     e(this).css(a, s(this, t) + "px")
    })
   }, e.fn["outer" + i] = function(t, n) {
    return "number" != typeof t ? o["outer" + i].call(this, t) : this.each(
     function() {
      e(this).css(a, s(this, t, !0, n) + "px")
     })
   }
  }), e.fn.addBack || (e.fn.addBack = function(e) {
   return this.add(null == e ? this.prevObject : this.prevObject.filter(e))
  }), e("<a>").data("a-b", "a").removeData("a-b").data("a-b") && (e.fn.removeData =
   function(t) {
    return function(i) {
     return arguments.length ? t.call(this, e.camelCase(i)) : t.call(this)
    }
   }(e.fn.removeData)), e.ui.ie = !!/msie [\w.]+/.exec(navigator.userAgent.toLowerCase()),
  e.fn.extend({
   focus: function(t) {
    return function(i, s) {
     return "number" == typeof i ? this.each(function() {
      var t = this;
      setTimeout(function() {
       e(t).focus(), s && s.call(t)
      }, i)
     }) : t.apply(this, arguments)
    }
   }(e.fn.focus),
   disableSelection: function() {
    var e = "onselectstart" in document.createElement("div") ? "selectstart" :
     "mousedown";
    return function() {
     return this.bind(e + ".ui-disableSelection", function(e) {
      e.preventDefault()
     })
    }
   }(),
   enableSelection: function() {
    return this.unbind(".ui-disableSelection")
   },
   zIndex: function(t) {
    if (void 0 !== t) return this.css("zIndex", t);
    if (this.length)
     for (var i, s, n = e(this[0]); n.length && n[0] !== document;) {
      if (i = n.css("position"), ("absolute" === i || "relative" === i ||
        "fixed" === i) && (s = parseInt(n.css("zIndex"), 10), !isNaN(s) && 0 !==
        s)) return s;
      n = n.parent()
     }
    return 0
   }
  }), e.ui.plugin = {
   add: function(t, i, s) {
    var n, a = e.ui[t].prototype;
    for (n in s) a.plugins[n] = a.plugins[n] || [], a.plugins[n].push([i, s[n]])
   },
   call: function(e, t, i, s) {
    var n, a = e.plugins[t];
    if (a && (s || e.element[0].parentNode && 11 !== e.element[0].parentNode.nodeType))
     for (n = 0; a.length > n; n++) e.options[a[n][0]] && a[n][1].apply(e.element,
      i)
   }
  };
 var l = 0,
  u = Array.prototype.slice;
 e.cleanData = function(t) {
  return function(i) {
   var s, n, a;
   for (a = 0; null != (n = i[a]); a++) try {
    s = e._data(n, "events"), s && s.remove && e(n).triggerHandler("remove")
   } catch (o) {}
   t(i)
  }
 }(e.cleanData), e.widget = function(t, i, s) {
  var n, a, o, r, h = {},
   l = t.split(".")[0];
  return t = t.split(".")[1], n = l + "-" + t, s || (s = i, i = e.Widget), e.expr[
   ":"][n.toLowerCase()] = function(t) {
   return !!e.data(t, n)
  }, e[l] = e[l] || {}, a = e[l][t], o = e[l][t] = function(e, t) {
   return this._createWidget ? (arguments.length && this._createWidget(e, t),
    void 0) : new o(e, t)
  }, e.extend(o, a, {
   version: s.version,
   _proto: e.extend({}, s),
   _childConstructors: []
  }), r = new i, r.options = e.widget.extend({}, r.options), e.each(s,
   function(t, s) {
    return e.isFunction(s) ? (h[t] = function() {
     var e = function() {
       return i.prototype[t].apply(this, arguments)
      },
      n = function(e) {
       return i.prototype[t].apply(this, e)
      };
     return function() {
      var t, i = this._super,
       a = this._superApply;
      return this._super = e, this._superApply = n, t = s.apply(this,
       arguments), this._super = i, this._superApply = a, t
     }
    }(), void 0) : (h[t] = s, void 0)
   }), o.prototype = e.widget.extend(r, {
   widgetEventPrefix: a ? r.widgetEventPrefix || t : t
  }, h, {
   constructor: o,
   namespace: l,
   widgetName: t,
   widgetFullName: n
  }), a ? (e.each(a._childConstructors, function(t, i) {
   var s = i.prototype;
   e.widget(s.namespace + "." + s.widgetName, o, i._proto)
  }), delete a._childConstructors) : i._childConstructors.push(o), e.widget.bridge(
   t, o), o
 }, e.widget.extend = function(t) {
  for (var i, s, n = u.call(arguments, 1), a = 0, o = n.length; o > a; a++)
   for (i in n[a]) s = n[a][i], n[a].hasOwnProperty(i) && void 0 !== s && (t[
    i] = e.isPlainObject(s) ? e.isPlainObject(t[i]) ? e.widget.extend({}, t[
    i], s) : e.widget.extend({}, s) : s);
  return t
 }, e.widget.bridge = function(t, i) {
  var s = i.prototype.widgetFullName || t;
  e.fn[t] = function(n) {
   var a = "string" == typeof n,
    o = u.call(arguments, 1),
    r = this;
   return n = !a && o.length ? e.widget.extend.apply(null, [n].concat(o)) :
    n, a ? this.each(function() {
     var i, a = e.data(this, s);
     return "instance" === n ? (r = a, !1) : a ? e.isFunction(a[n]) && "_" !==
      n.charAt(0) ? (i = a[n].apply(a, o), i !== a && void 0 !== i ? (r = i &&
       i.jquery ? r.pushStack(i.get()) : i, !1) : void 0) : e.error(
       "no such method '" + n + "' for " + t + " widget instance") : e.error(
       "cannot call methods on " + t + " prior to initialization; " +
       "attempted to call method '" + n + "'")
    }) : this.each(function() {
     var t = e.data(this, s);
     t ? (t.option(n || {}), t._init && t._init()) : e.data(this, s, new i(
      n, this))
    }), r
  }
 }, e.Widget = function() {}, e.Widget._childConstructors = [], e.Widget.prototype = {
  widgetName: "widget",
  widgetEventPrefix: "",
  defaultElement: "<div>",
  options: {
   disabled: !1,
   create: null
  },
  _createWidget: function(t, i) {
   i = e(i || this.defaultElement || this)[0], this.element = e(i), this.uuid =
    l++, this.eventNamespace = "." + this.widgetName + this.uuid, this.bindings =
    e(), this.hoverable = e(), this.focusable = e(), i !== this && (e.data(i,
      this.widgetFullName, this), this._on(!0, this.element, {
      remove: function(e) {
       e.target === i && this.destroy()
      }
     }), this.document = e(i.style ? i.ownerDocument : i.document || i),
     this.window = e(this.document[0].defaultView || this.document[0].parentWindow)
    ), this.options = e.widget.extend({}, this.options, this._getCreateOptions(),
     t), this._create(), this._trigger("create", null, this._getCreateEventData()),
    this._init()
  },
  _getCreateOptions: e.noop,
  _getCreateEventData: e.noop,
  _create: e.noop,
  _init: e.noop,
  destroy: function() {
   this._destroy(), this.element.unbind(this.eventNamespace).removeData(this
     .widgetFullName).removeData(e.camelCase(this.widgetFullName)), this.widget()
    .unbind(this.eventNamespace).removeAttr("aria-disabled").removeClass(
     this.widgetFullName + "-disabled " + "ui-state-disabled"), this.bindings
    .unbind(this.eventNamespace), this.hoverable.removeClass(
     "ui-state-hover"), this.focusable.removeClass("ui-state-focus")
  },
  _destroy: e.noop,
  widget: function() {
   return this.element
  },
  option: function(t, i) {
   var s, n, a, o = t;
   if (0 === arguments.length) return e.widget.extend({}, this.options);
   if ("string" == typeof t)
    if (o = {}, s = t.split("."), t = s.shift(), s.length) {
     for (n = o[t] = e.widget.extend({}, this.options[t]), a = 0; s.length -
      1 > a; a++) n[s[a]] = n[s[a]] || {}, n = n[s[a]];
     if (t = s.pop(), 1 === arguments.length) return void 0 === n[t] ? null :
      n[t];
     n[t] = i
    } else {
     if (1 === arguments.length) return void 0 === this.options[t] ? null :
      this.options[t];
     o[t] = i
    }
   return this._setOptions(o), this
  },
  _setOptions: function(e) {
   var t;
   for (t in e) this._setOption(t, e[t]);
   return this
  },
  _setOption: function(e, t) {
   return this.options[e] = t, "disabled" === e && (this.widget().toggleClass(
    this.widgetFullName + "-disabled", !!t), t && (this.hoverable.removeClass(
    "ui-state-hover"), this.focusable.removeClass("ui-state-focus"))), this
  },
  enable: function() {
   return this._setOptions({
    disabled: !1
   })
  },
  disable: function() {
   return this._setOptions({
    disabled: !0
   })
  },
  _on: function(t, i, s) {
   var n, a = this;
   "boolean" != typeof t && (s = i, i = t, t = !1), s ? (i = n = e(i), this.bindings =
     this.bindings.add(i)) : (s = i, i = this.element, n = this.widget()), e
    .each(s, function(s, o) {
     function r() {
      return t || a.options.disabled !== !0 && !e(this).hasClass(
       "ui-state-disabled") ? ("string" == typeof o ? a[o] : o).apply(a,
       arguments) : void 0
     }
     "string" != typeof o && (r.guid = o.guid = o.guid || r.guid || e.guid++);
     var h = s.match(/^([\w:-]*)\s*(.*)$/),
      l = h[1] + a.eventNamespace,
      u = h[2];
     u ? n.delegate(u, l, r) : i.bind(l, r)
    })
  },
  _off: function(t, i) {
   i = (i || "").split(" ").join(this.eventNamespace + " ") + this.eventNamespace,
    t.unbind(i).undelegate(i), this.bindings = e(this.bindings.not(t).get()),
    this.focusable = e(this.focusable.not(t).get()), this.hoverable = e(this
     .hoverable.not(t).get())
  },
  _delay: function(e, t) {
   function i() {
    return ("string" == typeof e ? s[e] : e).apply(s, arguments)
   }
   var s = this;
   return setTimeout(i, t || 0)
  },
  _hoverable: function(t) {
   this.hoverable = this.hoverable.add(t), this._on(t, {
    mouseenter: function(t) {
     e(t.currentTarget).addClass("ui-state-hover")
    },
    mouseleave: function(t) {
     e(t.currentTarget).removeClass("ui-state-hover")
    }
   })
  },
  _focusable: function(t) {
   this.focusable = this.focusable.add(t), this._on(t, {
    focusin: function(t) {
     e(t.currentTarget).addClass("ui-state-focus")
    },
    focusout: function(t) {
     e(t.currentTarget).removeClass("ui-state-focus")
    }
   })
  },
  _trigger: function(t, i, s) {
   var n, a, o = this.options[t];
   if (s = s || {}, i = e.Event(i), i.type = (t === this.widgetEventPrefix ?
     t : this.widgetEventPrefix + t).toLowerCase(), i.target = this.element[
     0], a = i.originalEvent)
    for (n in a) n in i || (i[n] = a[n]);
   return this.element.trigger(i, s), !(e.isFunction(o) && o.apply(this.element[
    0], [i].concat(s)) === !1 || i.isDefaultPrevented())
  }
 }, e.each({
  show: "fadeIn",
  hide: "fadeOut"
 }, function(t, i) {
  e.Widget.prototype["_" + t] = function(s, n, a) {
   "string" == typeof n && (n = {
    effect: n
   });
   var o, r = n ? n === !0 || "number" == typeof n ? i : n.effect || i : t;
   n = n || {}, "number" == typeof n && (n = {
     duration: n
    }), o = !e.isEmptyObject(n), n.complete = a, n.delay && s.delay(n.delay),
    o && e.effects && e.effects.effect[r] ? s[t](n) : r !== t && s[r] ? s[r]
    (n.duration, n.easing, a) : s.queue(function(i) {
     e(this)[t](), a && a.call(s[0]), i()
    })
  }
 }), e.widget;
 var d = !1;
 e(document).mouseup(function() {
   d = !1
  }), e.widget("ui.mouse", {
   version: "1.11.2",
   options: {
    cancel: "input,textarea,button,select,option",
    distance: 1,
    delay: 0
   },
   _mouseInit: function() {
    var t = this;
    this.element.bind("mousedown." + this.widgetName, function(e) {
     return t._mouseDown(e)
    }).bind("click." + this.widgetName, function(i) {
     return !0 === e.data(i.target, t.widgetName + ".preventClickEvent") ?
      (e.removeData(i.target, t.widgetName + ".preventClickEvent"), i.stopImmediatePropagation(), !
       1) : void 0
    }), this.started = !1
   },
   _mouseDestroy: function() {
    this.element.unbind("." + this.widgetName), this._mouseMoveDelegate &&
     this.document.unbind("mousemove." + this.widgetName, this._mouseMoveDelegate)
     .unbind("mouseup." + this.widgetName, this._mouseUpDelegate)
   },
   _mouseDown: function(t) {
    if (!d) {
     this._mouseMoved = !1, this._mouseStarted && this._mouseUp(t), this._mouseDownEvent =
      t;
     var i = this,
      s = 1 === t.which,
      n = "string" == typeof this.options.cancel && t.target.nodeName ? e(t.target)
      .closest(this.options.cancel).length : !1;
     return s && !n && this._mouseCapture(t) ? (this.mouseDelayMet = !this.options
      .delay, this.mouseDelayMet || (this._mouseDelayTimer = setTimeout(
       function() {
        i.mouseDelayMet = !0
       }, this.options.delay)), this._mouseDistanceMet(t) && this._mouseDelayMet(
       t) && (this._mouseStarted = this._mouseStart(t) !== !1, !this._mouseStarted) ?
      (t.preventDefault(), !0) : (!0 === e.data(t.target, this.widgetName +
        ".preventClickEvent") && e.removeData(t.target, this.widgetName +
        ".preventClickEvent"), this._mouseMoveDelegate = function(e) {
        return i._mouseMove(e)
       }, this._mouseUpDelegate = function(e) {
        return i._mouseUp(e)
       }, this.document.bind("mousemove." + this.widgetName, this._mouseMoveDelegate)
       .bind("mouseup." + this.widgetName, this._mouseUpDelegate), t.preventDefault(),
       d = !0, !0)) : !0
    }
   },
   _mouseMove: function(t) {
    if (this._mouseMoved) {
     if (e.ui.ie && (!document.documentMode || 9 > document.documentMode) &&
      !t.button) return this._mouseUp(t);
     if (!t.which) return this._mouseUp(t)
    }
    return (t.which || t.button) && (this._mouseMoved = !0), this._mouseStarted ?
     (this._mouseDrag(t), t.preventDefault()) : (this._mouseDistanceMet(t) &&
      this._mouseDelayMet(t) && (this._mouseStarted = this._mouseStart(this._mouseDownEvent,
       t) !== !1, this._mouseStarted ? this._mouseDrag(t) : this._mouseUp(t)), !
      this._mouseStarted)
   },
   _mouseUp: function(t) {
    return this.document.unbind("mousemove." + this.widgetName, this._mouseMoveDelegate)
     .unbind("mouseup." + this.widgetName, this._mouseUpDelegate), this._mouseStarted &&
     (this._mouseStarted = !1, t.target === this._mouseDownEvent.target && e
      .data(t.target, this.widgetName + ".preventClickEvent", !0), this._mouseStop(
       t)), d = !1, !1
   },
   _mouseDistanceMet: function(e) {
    return Math.max(Math.abs(this._mouseDownEvent.pageX - e.pageX), Math.abs(
     this._mouseDownEvent.pageY - e.pageY)) >= this.options.distance
   },
   _mouseDelayMet: function() {
    return this.mouseDelayMet
   },
   _mouseStart: function() {},
   _mouseDrag: function() {},
   _mouseStop: function() {},
   _mouseCapture: function() {
    return !0
   }
  }),
  function() {
   function t(e, t, i) {
    return [parseFloat(e[0]) * (p.test(e[0]) ? t / 100 : 1), parseFloat(e[1]) *
     (p.test(e[1]) ? i / 100 : 1)
    ]
   }

   function i(t, i) {
    return parseInt(e.css(t, i), 10) || 0
   }

   function s(t) {
    var i = t[0];
    return 9 === i.nodeType ? {
     width: t.width(),
     height: t.height(),
     offset: {
      top: 0,
      left: 0
     }
    } : e.isWindow(i) ? {
     width: t.width(),
     height: t.height(),
     offset: {
      top: t.scrollTop(),
      left: t.scrollLeft()
     }
    } : i.preventDefault ? {
     width: 0,
     height: 0,
     offset: {
      top: i.pageY,
      left: i.pageX
     }
    } : {
     width: t.outerWidth(),
     height: t.outerHeight(),
     offset: t.offset()
    }
   }
   e.ui = e.ui || {};
   var n, a, o = Math.max,
    r = Math.abs,
    h = Math.round,
    l = /left|center|right/,
    u = /top|center|bottom/,
    d = /[\+\-]\d+(\.[\d]+)?%?/,
    c = /^\w+/,
    p = /%$/,
    f = e.fn.position;
   e.position = {
     scrollbarWidth: function() {
      if (void 0 !== n) return n;
      var t, i, s = e(
        "<div style='display:block;position:absolute;width:50px;height:50px;overflow:hidden;'><div style='height:100px;width:auto;'></div></div>"
       ),
       a = s.children()[0];
      return e("body").append(s), t = a.offsetWidth, s.css("overflow",
        "scroll"), i = a.offsetWidth, t === i && (i = s[0].clientWidth), s.remove(),
       n = t - i
     },
     getScrollInfo: function(t) {
      var i = t.isWindow || t.isDocument ? "" : t.element.css("overflow-x"),
       s = t.isWindow || t.isDocument ? "" : t.element.css("overflow-y"),
       n = "scroll" === i || "auto" === i && t.width < t.element[0].scrollWidth,
       a = "scroll" === s || "auto" === s && t.height < t.element[0].scrollHeight;
      return {
       width: a ? e.position.scrollbarWidth() : 0,
       height: n ? e.position.scrollbarWidth() : 0
      }
     },
     getWithinInfo: function(t) {
      var i = e(t || window),
       s = e.isWindow(i[0]),
       n = !!i[0] && 9 === i[0].nodeType;
      return {
       element: i,
       isWindow: s,
       isDocument: n,
       offset: i.offset() || {
        left: 0,
        top: 0
       },
       scrollLeft: i.scrollLeft(),
       scrollTop: i.scrollTop(),
       width: s || n ? i.width() : i.outerWidth(),
       height: s || n ? i.height() : i.outerHeight()
      }
     }
    }, e.fn.position = function(n) {
     if (!n || !n.of) return f.apply(this, arguments);
     n = e.extend({}, n);
     var p, m, g, v, y, b, _ = e(n.of),
      x = e.position.getWithinInfo(n.within),
      w = e.position.getScrollInfo(x),
      k = (n.collision || "flip").split(" "),
      T = {};
     return b = s(_), _[0].preventDefault && (n.at = "left top"), m = b.width,
      g = b.height, v = b.offset, y = e.extend({}, v), e.each(["my", "at"],
       function() {
        var e, t, i = (n[this] || "").split(" ");
        1 === i.length && (i = l.test(i[0]) ? i.concat(["center"]) : u.test(i[
         0]) ? ["center"].concat(i) : ["center", "center"]), i[0] = l.test(i[
         0]) ? i[0] : "center", i[1] = u.test(i[1]) ? i[1] : "center", e = d.exec(
         i[0]), t = d.exec(i[1]), T[this] = [e ? e[0] : 0, t ? t[0] : 0], n[
         this] = [c.exec(i[0])[0], c.exec(i[1])[0]]
       }), 1 === k.length && (k[1] = k[0]), "right" === n.at[0] ? y.left += m :
      "center" === n.at[0] && (y.left += m / 2), "bottom" === n.at[1] ? y.top +=
      g : "center" === n.at[1] && (y.top += g / 2), p = t(T.at, m, g), y.left +=
      p[0], y.top += p[1], this.each(function() {
       var s, l, u = e(this),
        d = u.outerWidth(),
        c = u.outerHeight(),
        f = i(this, "marginLeft"),
        b = i(this, "marginTop"),
        D = d + f + i(this, "marginRight") + w.width,
        S = c + b + i(this, "marginBottom") + w.height,
        M = e.extend({}, y),
        C = t(T.my, u.outerWidth(), u.outerHeight());
       "right" === n.my[0] ? M.left -= d : "center" === n.my[0] && (M.left -=
         d / 2), "bottom" === n.my[1] ? M.top -= c : "center" === n.my[1] &&
        (M.top -= c / 2), M.left += C[0], M.top += C[1], a || (M.left = h(M.left),
         M.top = h(M.top)), s = {
         marginLeft: f,
         marginTop: b
        }, e.each(["left", "top"], function(t, i) {
         e.ui.position[k[t]] && e.ui.position[k[t]][i](M, {
          targetWidth: m,
          targetHeight: g,
          elemWidth: d,
          elemHeight: c,
          collisionPosition: s,
          collisionWidth: D,
          collisionHeight: S,
          offset: [p[0] + C[0], p[1] + C[1]],
          my: n.my,
          at: n.at,
          within: x,
          elem: u
         })
        }), n.using && (l = function(e) {
         var t = v.left - M.left,
          i = t + m - d,
          s = v.top - M.top,
          a = s + g - c,
          h = {
           target: {
            element: _,
            left: v.left,
            top: v.top,
            width: m,
            height: g
           },
           element: {
            element: u,
            left: M.left,
            top: M.top,
            width: d,
            height: c
           },
           horizontal: 0 > i ? "left" : t > 0 ? "right" : "center",
           vertical: 0 > a ? "top" : s > 0 ? "bottom" : "middle"
          };
         d > m && m > r(t + i) && (h.horizontal = "center"), c > g && g > r(
           s + a) && (h.vertical = "middle"), h.important = o(r(t), r(i)) >
          o(r(s), r(a)) ? "horizontal" : "vertical", n.using.call(this, e, h)
        }), u.offset(e.extend(M, {
         using: l
        }))
      })
    }, e.ui.position = {
     fit: {
      left: function(e, t) {
       var i, s = t.within,
        n = s.isWindow ? s.scrollLeft : s.offset.left,
        a = s.width,
        r = e.left - t.collisionPosition.marginLeft,
        h = n - r,
        l = r + t.collisionWidth - a - n;
       t.collisionWidth > a ? h > 0 && 0 >= l ? (i = e.left + h + t.collisionWidth -
         a - n, e.left += h - i) : e.left = l > 0 && 0 >= h ? n : h > l ? n +
        a - t.collisionWidth : n : h > 0 ? e.left += h : l > 0 ? e.left -= l :
        e.left = o(e.left - r, e.left)
      },
      top: function(e, t) {
       var i, s = t.within,
        n = s.isWindow ? s.scrollTop : s.offset.top,
        a = t.within.height,
        r = e.top - t.collisionPosition.marginTop,
        h = n - r,
        l = r + t.collisionHeight - a - n;
       t.collisionHeight > a ? h > 0 && 0 >= l ? (i = e.top + h + t.collisionHeight -
         a - n, e.top += h - i) : e.top = l > 0 && 0 >= h ? n : h > l ? n + a -
        t.collisionHeight : n : h > 0 ? e.top += h : l > 0 ? e.top -= l : e.top =
        o(e.top - r, e.top)
      }
     },
     flip: {
      left: function(e, t) {
       var i, s, n = t.within,
        a = n.offset.left + n.scrollLeft,
        o = n.width,
        h = n.isWindow ? n.scrollLeft : n.offset.left,
        l = e.left - t.collisionPosition.marginLeft,
        u = l - h,
        d = l + t.collisionWidth - o - h,
        c = "left" === t.my[0] ? -t.elemWidth : "right" === t.my[0] ? t.elemWidth :
        0,
        p = "left" === t.at[0] ? t.targetWidth : "right" === t.at[0] ? -t.targetWidth :
        0,
        f = -2 * t.offset[0];
       0 > u ? (i = e.left + c + p + f + t.collisionWidth - o - a, (0 > i ||
        r(u) > i) && (e.left += c + p + f)) : d > 0 && (s = e.left - t.collisionPosition
        .marginLeft + c + p + f - h, (s > 0 || d > r(s)) && (e.left += c + p +
         f))
      },
      top: function(e, t) {
       var i, s, n = t.within,
        a = n.offset.top + n.scrollTop,
        o = n.height,
        h = n.isWindow ? n.scrollTop : n.offset.top,
        l = e.top - t.collisionPosition.marginTop,
        u = l - h,
        d = l + t.collisionHeight - o - h,
        c = "top" === t.my[1],
        p = c ? -t.elemHeight : "bottom" === t.my[1] ? t.elemHeight : 0,
        f = "top" === t.at[1] ? t.targetHeight : "bottom" === t.at[1] ? -t.targetHeight :
        0,
        m = -2 * t.offset[1];
       0 > u ? (s = e.top + p + f + m + t.collisionHeight - o - a, e.top + p +
         f + m > u && (0 > s || r(u) > s) && (e.top += p + f + m)) : d > 0 &&
        (i = e.top - t.collisionPosition.marginTop + p + f + m - h, e.top + p +
         f + m > d && (i > 0 || d > r(i)) && (e.top += p + f + m))
      }
     },
     flipfit: {
      left: function() {
       e.ui.position.flip.left.apply(this, arguments), e.ui.position.fit.left
        .apply(this, arguments)
      },
      top: function() {
       e.ui.position.flip.top.apply(this, arguments), e.ui.position.fit.top.apply(
        this, arguments)
      }
     }
    },
    function() {
     var t, i, s, n, o, r = document.getElementsByTagName("body")[0],
      h = document.createElement("div");
     t = document.createElement(r ? "div" : "body"), s = {
      visibility: "hidden",
      width: 0,
      height: 0,
      border: 0,
      margin: 0,
      background: "none"
     }, r && e.extend(s, {
      position: "absolute",
      left: "-1000px",
      top: "-1000px"
     });
     for (o in s) t.style[o] = s[o];
     t.appendChild(h), i = r || document.documentElement, i.insertBefore(t, i.firstChild),
      h.style.cssText = "position: absolute; left: 10.7432222px;", n = e(h).offset()
      .left, a = n > 10 && 11 > n, t.innerHTML = "", i.removeChild(t)
    }()
  }(), e.ui.position, e.widget("ui.accordion", {
   version: "1.11.2",
   options: {
    active: 0,
    animate: {},
    collapsible: !1,
    event: "click",
    header: "> li > :first-child,> :not(li):even",
    heightStyle: "auto",
    icons: {
     activeHeader: "ui-icon-triangle-1-s",
     header: "ui-icon-triangle-1-e"
    },
    activate: null,
    beforeActivate: null
   },
   hideProps: {
    borderTopWidth: "hide",
    borderBottomWidth: "hide",
    paddingTop: "hide",
    paddingBottom: "hide",
    height: "hide"
   },
   showProps: {
    borderTopWidth: "show",
    borderBottomWidth: "show",
    paddingTop: "show",
    paddingBottom: "show",
    height: "show"
   },
   _create: function() {
    var t = this.options;
    this.prevShow = this.prevHide = e(), this.element.addClass(
      "ui-accordion ui-widget ui-helper-reset").attr("role", "tablist"), t.collapsible ||
     t.active !== !1 && null != t.active || (t.active = 0), this._processPanels(),
     0 > t.active && (t.active += this.headers.length), this._refresh()
   },
   _getCreateEventData: function() {
    return {
     header: this.active,
     panel: this.active.length ? this.active.next() : e()
    }
   },
   _createIcons: function() {
    var t = this.options.icons;
    t && (e("<span>").addClass("ui-accordion-header-icon ui-icon " + t.header)
     .prependTo(this.headers), this.active.children(
      ".ui-accordion-header-icon").removeClass(t.header).addClass(t.activeHeader),
     this.headers.addClass("ui-accordion-icons"))
   },
   _destroyIcons: function() {
    this.headers.removeClass("ui-accordion-icons").children(
     ".ui-accordion-header-icon").remove()
   },
   _destroy: function() {
    var e;
    this.element.removeClass("ui-accordion ui-widget ui-helper-reset").removeAttr(
      "role"), this.headers.removeClass(
      "ui-accordion-header ui-accordion-header-active ui-state-default ui-corner-all ui-state-active ui-state-disabled ui-corner-top"
     ).removeAttr("role").removeAttr("aria-expanded").removeAttr(
      "aria-selected").removeAttr("aria-controls").removeAttr("tabIndex").removeUniqueId(),
     this._destroyIcons(), e = this.headers.next().removeClass(
      "ui-helper-reset ui-widget-content ui-corner-bottom ui-accordion-content ui-accordion-content-active ui-state-disabled"
     ).css("display", "").removeAttr("role").removeAttr("aria-hidden").removeAttr(
      "aria-labelledby").removeUniqueId(), "content" !== this.options.heightStyle &&
     e.css("height", "")
   },
   _setOption: function(e, t) {
    return "active" === e ? (this._activate(t), void 0) : ("event" === e &&
     (this.options.event && this._off(this.headers, this.options.event),
      this._setupEvents(t)), this._super(e, t), "collapsible" !== e || t ||
     this.options.active !== !1 || this._activate(0), "icons" === e && (
      this._destroyIcons(), t && this._createIcons()), "disabled" === e &&
     (this.element.toggleClass("ui-state-disabled", !!t).attr(
      "aria-disabled", t), this.headers.add(this.headers.next()).toggleClass(
      "ui-state-disabled", !!t)), void 0)
   },
   _keydown: function(t) {
    if (!t.altKey && !t.ctrlKey) {
     var i = e.ui.keyCode,
      s = this.headers.length,
      n = this.headers.index(t.target),
      a = !1;
     switch (t.keyCode) {
      case i.RIGHT:
      case i.DOWN:
       a = this.headers[(n + 1) % s];
       break;
      case i.LEFT:
      case i.UP:
       a = this.headers[(n - 1 + s) % s];
       break;
      case i.SPACE:
      case i.ENTER:
       this._eventHandler(t);
       break;
      case i.HOME:
       a = this.headers[0];
       break;
      case i.END:
       a = this.headers[s - 1]
     }
     a && (e(t.target).attr("tabIndex", -1), e(a).attr("tabIndex", 0), a.focus(),
      t.preventDefault())
    }
   },
   _panelKeyDown: function(t) {
    t.keyCode === e.ui.keyCode.UP && t.ctrlKey && e(t.currentTarget).prev().focus()
   },
   refresh: function() {
    var t = this.options;
    this._processPanels(), t.active === !1 && t.collapsible === !0 || !this.headers
     .length ? (t.active = !1, this.active = e()) : t.active === !1 ? this._activate(
      0) : this.active.length && !e.contains(this.element[0], this.active[0]) ?
     this.headers.length === this.headers.find(".ui-state-disabled").length ?
     (t.active = !1, this.active = e()) : this._activate(Math.max(0, t.active -
      1)) : t.active = this.headers.index(this.active), this._destroyIcons(),
     this._refresh()
   },
   _processPanels: function() {
    var e = this.headers,
     t = this.panels;
    this.headers = this.element.find(this.options.header).addClass(
      "ui-accordion-header ui-state-default ui-corner-all"), this.panels =
     this.headers.next().addClass(
      "ui-accordion-content ui-helper-reset ui-widget-content ui-corner-bottom"
     ).filter(":not(.ui-accordion-content-active)").hide(), t && (this._off(
      e.not(this.headers)), this._off(t.not(this.panels)))
   },
   _refresh: function() {
    var t, i = this.options,
     s = i.heightStyle,
     n = this.element.parent();
    this.active = this._findActive(i.active).addClass(
      "ui-accordion-header-active ui-state-active ui-corner-top").removeClass(
      "ui-corner-all"), this.active.next().addClass(
      "ui-accordion-content-active").show(), this.headers.attr("role", "tab")
     .each(function() {
      var t = e(this),
       i = t.uniqueId().attr("id"),
       s = t.next(),
       n = s.uniqueId().attr("id");
      t.attr("aria-controls", n), s.attr("aria-labelledby", i)
     }).next().attr("role", "tabpanel"), this.headers.not(this.active).attr({
      "aria-selected": "false",
      "aria-expanded": "false",
      tabIndex: -1
     }).next().attr({
      "aria-hidden": "true"
     }).hide(), this.active.length ? this.active.attr({
      "aria-selected": "true",
      "aria-expanded": "true",
      tabIndex: 0
     }).next().attr({
      "aria-hidden": "false"
     }) : this.headers.eq(0).attr("tabIndex", 0), this._createIcons(), this._setupEvents(
      i.event), "fill" === s ? (t = n.height(), this.element.siblings(
      ":visible").each(function() {
      var i = e(this),
       s = i.css("position");
      "absolute" !== s && "fixed" !== s && (t -= i.outerHeight(!0))
     }), this.headers.each(function() {
      t -= e(this).outerHeight(!0)
     }), this.headers.next().each(function() {
      e(this).height(Math.max(0, t - e(this).innerHeight() + e(this).height()))
     }).css("overflow", "auto")) : "auto" === s && (t = 0, this.headers.next()
      .each(function() {
       t = Math.max(t, e(this).css("height", "").height())
      }).height(t))
   },
   _activate: function(t) {
    var i = this._findActive(t)[0];
    i !== this.active[0] && (i = i || this.active[0], this._eventHandler({
     target: i,
     currentTarget: i,
     preventDefault: e.noop
    }))
   },
   _findActive: function(t) {
    return "number" == typeof t ? this.headers.eq(t) : e()
   },
   _setupEvents: function(t) {
    var i = {
     keydown: "_keydown"
    };
    t && e.each(t.split(" "), function(e, t) {
     i[t] = "_eventHandler"
    }), this._off(this.headers.add(this.headers.next())), this._on(this.headers,
     i), this._on(this.headers.next(), {
     keydown: "_panelKeyDown"
    }), this._hoverable(this.headers), this._focusable(this.headers)
   },
   _eventHandler: function(t) {
    var i = this.options,
     s = this.active,
     n = e(t.currentTarget),
     a = n[0] === s[0],
     o = a && i.collapsible,
     r = o ? e() : n.next(),
     h = s.next(),
     l = {
      oldHeader: s,
      oldPanel: h,
      newHeader: o ? e() : n,
      newPanel: r
     };
    t.preventDefault(), a && !i.collapsible || this._trigger(
     "beforeActivate", t, l) === !1 || (i.active = o ? !1 : this.headers.index(
     n), this.active = a ? e() : n, this._toggle(l), s.removeClass(
     "ui-accordion-header-active ui-state-active"), i.icons && s.children(
     ".ui-accordion-header-icon").removeClass(i.icons.activeHeader).addClass(
     i.icons.header), a || (n.removeClass("ui-corner-all").addClass(
      "ui-accordion-header-active ui-state-active ui-corner-top"), i.icons &&
     n.children(".ui-accordion-header-icon").removeClass(i.icons.header).addClass(
      i.icons.activeHeader), n.next().addClass(
      "ui-accordion-content-active")))
   },
   _toggle: function(t) {
    var i = t.newPanel,
     s = this.prevShow.length ? this.prevShow : t.oldPanel;
    this.prevShow.add(this.prevHide).stop(!0, !0), this.prevShow = i, this.prevHide =
     s, this.options.animate ? this._animate(i, s, t) : (s.hide(), i.show(),
      this._toggleComplete(t)), s.attr({
      "aria-hidden": "true"
     }), s.prev().attr("aria-selected", "false"), i.length && s.length ? s.prev()
     .attr({
      tabIndex: -1,
      "aria-expanded": "false"
     }) : i.length && this.headers.filter(function() {
      return 0 === e(this).attr("tabIndex")
     }).attr("tabIndex", -1), i.attr("aria-hidden", "false").prev().attr({
      "aria-selected": "true",
      tabIndex: 0,
      "aria-expanded": "true"
     })
   },
   _animate: function(e, t, i) {
    var s, n, a, o = this,
     r = 0,
     h = e.length && (!t.length || e.index() < t.index()),
     l = this.options.animate || {},
     u = h && l.down || l,
     d = function() {
      o._toggleComplete(i)
     };
    return "number" == typeof u && (a = u), "string" == typeof u && (n = u),
     n = n || u.easing || l.easing, a = a || u.duration || l.duration, t.length ?
     e.length ? (s = e.show().outerHeight(), t.animate(this.hideProps, {
      duration: a,
      easing: n,
      step: function(e, t) {
       t.now = Math.round(e)
      }
     }), e.hide().animate(this.showProps, {
      duration: a,
      easing: n,
      complete: d,
      step: function(e, i) {
       i.now = Math.round(e), "height" !== i.prop ? r += i.now :
        "content" !== o.options.heightStyle && (i.now = Math.round(s - t.outerHeight() -
         r), r = 0)
      }
     }), void 0) : t.animate(this.hideProps, a, n, d) : e.animate(this.showProps,
      a, n, d)
   },
   _toggleComplete: function(e) {
    var t = e.oldPanel;
    t.removeClass("ui-accordion-content-active").prev().removeClass(
     "ui-corner-top").addClass("ui-corner-all"), t.length && (t.parent()[0]
     .className = t.parent()[0].className), this._trigger("activate", null,
     e)
   }
  }), e.widget("ui.menu", {
   version: "1.11.2",
   defaultElement: "<ul>",
   delay: 300,
   options: {
    icons: {
     submenu: "ui-icon-carat-1-e"
    },
    items: "> *",
    menus: "ul",
    position: {
     my: "left-1 top",
     at: "right top"
    },
    role: "menu",
    blur: null,
    focus: null,
    select: null
   },
   _create: function() {
    this.activeMenu = this.element, this.mouseHandled = !1, this.element.uniqueId()
     .addClass("ui-menu ui-widget ui-widget-content").toggleClass(
      "ui-menu-icons", !!this.element.find(".ui-icon").length).attr({
      role: this.options.role,
      tabIndex: 0
     }), this.options.disabled && this.element.addClass("ui-state-disabled")
     .attr("aria-disabled", "true"), this._on({
      "mousedown .ui-menu-item": function(e) {
       e.preventDefault()
      },
      "click .ui-menu-item": function(t) {
       var i = e(t.target);
       !this.mouseHandled && i.not(".ui-state-disabled").length && (this.select(
         t), t.isPropagationStopped() || (this.mouseHandled = !0), i.has(
         ".ui-menu").length ? this.expand(t) : !this.element.is(":focus") &&
        e(this.document[0].activeElement).closest(".ui-menu").length && (
         this.element.trigger("focus", [!0]), this.active && 1 === this.active
         .parents(".ui-menu").length && clearTimeout(this.timer)))
      },
      "mouseenter .ui-menu-item": function(t) {
       if (!this.previousFilter) {
        var i = e(t.currentTarget);
        i.siblings(".ui-state-active").removeClass("ui-state-active"),
         this.focus(t, i)
       }
      },
      mouseleave: "collapseAll",
      "mouseleave .ui-menu": "collapseAll",
      focus: function(e, t) {
       var i = this.active || this.element.find(this.options.items).eq(0);
       t || this.focus(e, i)
      },
      blur: function(t) {
       this._delay(function() {
        e.contains(this.element[0], this.document[0].activeElement) ||
         this.collapseAll(t)
       })
      },
      keydown: "_keydown"
     }), this.refresh(), this._on(this.document, {
      click: function(e) {
       this._closeOnDocumentClick(e) && this.collapseAll(e), this.mouseHandled = !
        1
      }
     })
   },
   _destroy: function() {
    this.element.removeAttr("aria-activedescendant").find(".ui-menu").addBack()
     .removeClass(
      "ui-menu ui-widget ui-widget-content ui-menu-icons ui-front").removeAttr(
      "role").removeAttr("tabIndex").removeAttr("aria-labelledby").removeAttr(
      "aria-expanded").removeAttr("aria-hidden").removeAttr("aria-disabled")
     .removeUniqueId().show(), this.element.find(".ui-menu-item").removeClass(
      "ui-menu-item").removeAttr("role").removeAttr("aria-disabled").removeUniqueId()
     .removeClass("ui-state-hover").removeAttr("tabIndex").removeAttr("role")
     .removeAttr("aria-haspopup").children().each(function() {
      var t = e(this);
      t.data("ui-menu-submenu-carat") && t.remove()
     }), this.element.find(".ui-menu-divider").removeClass(
      "ui-menu-divider ui-widget-content")
   },
   _keydown: function(t) {
    var i, s, n, a, o = !0;
    switch (t.keyCode) {
     case e.ui.keyCode.PAGE_UP:
      this.previousPage(t);
      break;
     case e.ui.keyCode.PAGE_DOWN:
      this.nextPage(t);
      break;
     case e.ui.keyCode.HOME:
      this._move("first", "first", t);
      break;
     case e.ui.keyCode.END:
      this._move("last", "last", t);
      break;
     case e.ui.keyCode.UP:
      this.previous(t);
      break;
     case e.ui.keyCode.DOWN:
      this.next(t);
      break;
     case e.ui.keyCode.LEFT:
      this.collapse(t);
      break;
     case e.ui.keyCode.RIGHT:
      this.active && !this.active.is(".ui-state-disabled") && this.expand(t);
      break;
     case e.ui.keyCode.ENTER:
     case e.ui.keyCode.SPACE:
      this._activate(t);
      break;
     case e.ui.keyCode.ESCAPE:
      this.collapse(t);
      break;
     default:
      o = !1, s = this.previousFilter || "", n = String.fromCharCode(t.keyCode),
       a = !1, clearTimeout(this.filterTimer), n === s ? a = !0 : n = s + n,
       i = this._filterMenuItems(n), i = a && -1 !== i.index(this.active.next()) ?
       this.active.nextAll(".ui-menu-item") : i, i.length || (n = String.fromCharCode(
        t.keyCode), i = this._filterMenuItems(n)), i.length ? (this.focus(t,
        i), this.previousFilter = n, this.filterTimer = this._delay(
        function() {
         delete this.previousFilter
        }, 1e3)) : delete this.previousFilter
    }
    o && t.preventDefault()
   },
   _activate: function(e) {
    this.active.is(".ui-state-disabled") || (this.active.is(
     "[aria-haspopup='true']") ? this.expand(e) : this.select(e))
   },
   refresh: function() {
    var t, i, s = this,
     n = this.options.icons.submenu,
     a = this.element.find(this.options.menus);
    this.element.toggleClass("ui-menu-icons", !!this.element.find(".ui-icon")
      .length), a.filter(":not(.ui-menu)").addClass(
      "ui-menu ui-widget ui-widget-content ui-front").hide().attr({
      role: this.options.role,
      "aria-hidden": "true",
      "aria-expanded": "false"
     }).each(function() {
      var t = e(this),
       i = t.parent(),
       s = e("<span>").addClass("ui-menu-icon ui-icon " + n).data(
        "ui-menu-submenu-carat", !0);
      i.attr("aria-haspopup", "true").prepend(s), t.attr("aria-labelledby",
       i.attr("id"))
     }), t = a.add(this.element), i = t.find(this.options.items), i.not(
      ".ui-menu-item").each(function() {
      var t = e(this);
      s._isDivider(t) && t.addClass("ui-widget-content ui-menu-divider")
     }), i.not(".ui-menu-item, .ui-menu-divider").addClass("ui-menu-item").uniqueId()
     .attr({
      tabIndex: -1,
      role: this._itemRole()
     }), i.filter(".ui-state-disabled").attr("aria-disabled", "true"), this.active &&
     !e.contains(this.element[0], this.active[0]) && this.blur()
   },
   _itemRole: function() {
    return {
     menu: "menuitem",
     listbox: "option"
    }[this.options.role]
   },
   _setOption: function(e, t) {
    "icons" === e && this.element.find(".ui-menu-icon").removeClass(this.options
     .icons.submenu).addClass(t.submenu), "disabled" === e && this.element.toggleClass(
     "ui-state-disabled", !!t).attr("aria-disabled", t), this._super(e, t)
   },
   focus: function(e, t) {
    var i, s;
    this.blur(e, e && "focus" === e.type), this._scrollIntoView(t), this.active =
     t.first(), s = this.active.addClass("ui-state-focus").removeClass(
      "ui-state-active"), this.options.role && this.element.attr(
      "aria-activedescendant", s.attr("id")), this.active.parent().closest(
      ".ui-menu-item").addClass("ui-state-active"), e && "keydown" === e.type ?
     this._close() : this.timer = this._delay(function() {
      this._close()
     }, this.delay), i = t.children(".ui-menu"), i.length && e && /^mouse/.test(
      e.type) && this._startOpening(i), this.activeMenu = t.parent(), this._trigger(
      "focus", e, {
       item: t
      })
   },
   _scrollIntoView: function(t) {
    var i, s, n, a, o, r;
    this._hasScroll() && (i = parseFloat(e.css(this.activeMenu[0],
      "borderTopWidth")) || 0, s = parseFloat(e.css(this.activeMenu[0],
      "paddingTop")) || 0, n = t.offset().top - this.activeMenu.offset().top -
     i - s, a = this.activeMenu.scrollTop(), o = this.activeMenu.height(),
     r = t.outerHeight(), 0 > n ? this.activeMenu.scrollTop(a + n) : n + r >
     o && this.activeMenu.scrollTop(a + n - o + r))
   },
   blur: function(e, t) {
    t || clearTimeout(this.timer), this.active && (this.active.removeClass(
     "ui-state-focus"), this.active = null, this._trigger("blur", e, {
     item: this.active
    }))
   },
   _startOpening: function(e) {
    clearTimeout(this.timer), "true" === e.attr("aria-hidden") && (this.timer =
     this._delay(function() {
      this._close(), this._open(e)
     }, this.delay))
   },
   _open: function(t) {
    var i = e.extend({
     of: this.active
    }, this.options.position);
    clearTimeout(this.timer), this.element.find(".ui-menu").not(t.parents(
     ".ui-menu")).hide().attr("aria-hidden", "true"), t.show().removeAttr(
     "aria-hidden").attr("aria-expanded", "true").position(i)
   },
   collapseAll: function(t, i) {
    clearTimeout(this.timer), this.timer = this._delay(function() {
     var s = i ? this.element : e(t && t.target).closest(this.element.find(
      ".ui-menu"));
     s.length || (s = this.element), this._close(s), this.blur(t), this.activeMenu =
      s
    }, this.delay)
   },
   _close: function(e) {
    e || (e = this.active ? this.active.parent() : this.element), e.find(
     ".ui-menu").hide().attr("aria-hidden", "true").attr("aria-expanded",
     "false").end().find(".ui-state-active").not(".ui-state-focus").removeClass(
     "ui-state-active")
   },
   _closeOnDocumentClick: function(t) {
    return !e(t.target).closest(".ui-menu").length
   },
   _isDivider: function(e) {
    return !/[^\-\u2014\u2013\s]/.test(e.text())
   },
   collapse: function(e) {
    var t = this.active && this.active.parent().closest(".ui-menu-item",
     this.element);
    t && t.length && (this._close(), this.focus(e, t))
   },
   expand: function(e) {
    var t = this.active && this.active.children(".ui-menu ").find(this.options
     .items).first();
    t && t.length && (this._open(t.parent()), this._delay(function() {
     this.focus(e, t)
    }))
   },
   next: function(e) {
    this._move("next", "first", e)
   },
   previous: function(e) {
    this._move("prev", "last", e)
   },
   isFirstItem: function() {
    return this.active && !this.active.prevAll(".ui-menu-item").length
   },
   isLastItem: function() {
    return this.active && !this.active.nextAll(".ui-menu-item").length
   },
   _move: function(e, t, i) {
    var s;
    this.active && (s = "first" === e || "last" === e ? this.active["first" ===
     e ? "prevAll" : "nextAll"](".ui-menu-item").eq(-1) : this.active[e +
     "All"](".ui-menu-item").eq(0)), s && s.length && this.active || (s =
     this.activeMenu.find(this.options.items)[t]()), this.focus(i, s)
   },
   nextPage: function(t) {
    var i, s, n;
    return this.active ? (this.isLastItem() || (this._hasScroll() ? (s =
     this.active.offset().top, n = this.element.height(), this.active.nextAll(
      ".ui-menu-item").each(function() {
      return i = e(this), 0 > i.offset().top - s - n
     }), this.focus(t, i)) : this.focus(t, this.activeMenu.find(this.options
     .items)[this.active ? "last" : "first"]())), void 0) : (this.next(t),
     void 0)
   },
   previousPage: function(t) {
    var i, s, n;
    return this.active ? (this.isFirstItem() || (this._hasScroll() ? (s =
     this.active.offset().top, n = this.element.height(), this.active.prevAll(
      ".ui-menu-item").each(function() {
      return i = e(this), i.offset().top - s + n > 0
     }), this.focus(t, i)) : this.focus(t, this.activeMenu.find(this.options
     .items).first())), void 0) : (this.next(t), void 0)
   },
   _hasScroll: function() {
    return this.element.outerHeight() < this.element.prop("scrollHeight")
   },
   select: function(t) {
    this.active = this.active || e(t.target).closest(".ui-menu-item");
    var i = {
     item: this.active
    };
    this.active.has(".ui-menu").length || this.collapseAll(t, !0), this._trigger(
     "select", t, i)
   },
   _filterMenuItems: function(t) {
    var i = t.replace(/[\-\[\]{}()*+?.,\\\^$|#\s]/g, "\\$&"),
     s = RegExp("^" + i, "i");
    return this.activeMenu.find(this.options.items).filter(".ui-menu-item").filter(
     function() {
      return s.test(e.trim(e(this).text()))
     })
   }
  }), e.widget("ui.autocomplete", {
   version: "1.11.2",
   defaultElement: "<input>",
   options: {
    appendTo: null,
    autoFocus: !1,
    delay: 300,
    minLength: 1,
    position: {
     my: "left top",
     at: "left bottom",
     collision: "none"
    },
    source: null,
    change: null,
    close: null,
    focus: null,
    open: null,
    response: null,
    search: null,
    select: null
   },
   requestIndex: 0,
   pending: 0,
   _create: function() {
    var t, i, s, n = this.element[0].nodeName.toLowerCase(),
     a = "textarea" === n,
     o = "input" === n;
    this.isMultiLine = a ? !0 : o ? !1 : this.element.prop(
      "isContentEditable"), this.valueMethod = this.element[a || o ? "val" :
      "text"], this.isNewMenu = !0, this.element.addClass(
      "ui-autocomplete-input").attr("autocomplete", "off"), this._on(this.element, {
      keydown: function(n) {
       if (this.element.prop("readOnly")) return t = !0, s = !0, i = !0,
        void 0;
       t = !1, s = !1, i = !1;
       var a = e.ui.keyCode;
       switch (n.keyCode) {
        case a.PAGE_UP:
         t = !0, this._move("previousPage", n);
         break;
        case a.PAGE_DOWN:
         t = !0, this._move("nextPage", n);
         break;
        case a.UP:
         t = !0, this._keyEvent("previous", n);
         break;
        case a.DOWN:
         t = !0, this._keyEvent("next", n);
         break;
        case a.ENTER:
         this.menu.active && (t = !0, n.preventDefault(), this.menu.select(
          n));
         break;
        case a.TAB:
         this.menu.active && this.menu.select(n);
         break;
        case a.ESCAPE:
         this.menu.element.is(":visible") && (this.isMultiLine || this._value(
          this.term), this.close(n), n.preventDefault());
         break;
        default:
         i = !0, this._searchTimeout(n)
       }
      },
      keypress: function(s) {
       if (t) return t = !1, (!this.isMultiLine || this.menu.element.is(
        ":visible")) && s.preventDefault(), void 0;
       if (!i) {
        var n = e.ui.keyCode;
        switch (s.keyCode) {
         case n.PAGE_UP:
          this._move("previousPage", s);
          break;
         case n.PAGE_DOWN:
          this._move("nextPage", s);
          break;
         case n.UP:
          this._keyEvent("previous", s);
          break;
         case n.DOWN:
          this._keyEvent("next", s)
        }
       }
      },
      input: function(e) {
       return s ? (s = !1, e.preventDefault(), void 0) : (this._searchTimeout(
        e), void 0)
      },
      focus: function() {
       this.selectedItem = null, this.previous = this._value()
      },
      blur: function(e) {
       return this.cancelBlur ? (delete this.cancelBlur, void 0) : (
        clearTimeout(this.searching), this.close(e), this._change(e),
        void 0)
      }
     }), this._initSource(), this.menu = e("<ul>").addClass(
      "ui-autocomplete ui-front").appendTo(this._appendTo()).menu({
      role: null
     }).hide().menu("instance"), this._on(this.menu.element, {
      mousedown: function(t) {
       t.preventDefault(), this.cancelBlur = !0, this._delay(function() {
        delete this.cancelBlur
       });
       var i = this.menu.element[0];
       e(t.target).closest(".ui-menu-item").length || this._delay(function() {
        var t = this;
        this.document.one("mousedown", function(s) {
         s.target === t.element[0] || s.target === i || e.contains(i,
          s.target) || t.close()
        })
       })
      },
      menufocus: function(t, i) {
       var s, n;
       return this.isNewMenu && (this.isNewMenu = !1, t.originalEvent &&
        /^mouse/.test(t.originalEvent.type)) ? (this.menu.blur(), this.document
        .one("mousemove", function() {
         e(t.target).trigger(t.originalEvent)
        }), void 0) : (n = i.item.data("ui-autocomplete-item"), !1 !==
        this._trigger("focus", t, {
         item: n
        }) && t.originalEvent && /^key/.test(t.originalEvent.type) &&
        this._value(n.value), s = i.item.attr("aria-label") || n.value, s &&
        e.trim(s).length && (this.liveRegion.children().hide(), e("<div>")
         .text(s).appendTo(this.liveRegion)), void 0)
      },
      menuselect: function(e, t) {
       var i = t.item.data("ui-autocomplete-item"),
        s = this.previous;
       this.element[0] !== this.document[0].activeElement && (this.element
        .focus(), this.previous = s, this._delay(function() {
         this.previous = s, this.selectedItem = i
        })), !1 !== this._trigger("select", e, {
        item: i
       }) && this._value(i.value), this.term = this._value(), this.close(
        e), this.selectedItem = i
      }
     }), this.liveRegion = e("<span>", {
      role: "status",
      "aria-live": "assertive",
      "aria-relevant": "additions"
     }).addClass("ui-helper-hidden-accessible").appendTo(this.document[0].body),
     this._on(this.window, {
      beforeunload: function() {
       this.element.removeAttr("autocomplete")
      }
     })
   },
   _destroy: function() {
    clearTimeout(this.searching), this.element.removeClass(
      "ui-autocomplete-input").removeAttr("autocomplete"), this.menu.element
     .remove(), this.liveRegion.remove()
   },
   _setOption: function(e, t) {
    this._super(e, t), "source" === e && this._initSource(), "appendTo" ===
     e && this.menu.element.appendTo(this._appendTo()), "disabled" === e &&
     t && this.xhr && this.xhr.abort()
   },
   _appendTo: function() {
    var t = this.options.appendTo;
    return t && (t = t.jquery || t.nodeType ? e(t) : this.document.find(t).eq(
      0)), t && t[0] || (t = this.element.closest(".ui-front")), t.length ||
     (t = this.document[0].body), t
   },
   _initSource: function() {
    var t, i, s = this;
    e.isArray(this.options.source) ? (t = this.options.source, this.source =
     function(i, s) {
      s(e.ui.autocomplete.filter(t, i.term))
     }) : "string" == typeof this.options.source ? (i = this.options.source,
     this.source = function(t, n) {
      s.xhr && s.xhr.abort(), s.xhr = e.ajax({
       url: i,
       data: t,
       dataType: "json",
       success: function(e) {
        n(e)
       },
       error: function() {
        n([])
       }
      })
     }) : this.source = this.options.source
   },
   _searchTimeout: function(e) {
    clearTimeout(this.searching), this.searching = this._delay(function() {
     var t = this.term === this._value(),
      i = this.menu.element.is(":visible"),
      s = e.altKey || e.ctrlKey || e.metaKey || e.shiftKey;
     (!t || t && !i && !s) && (this.selectedItem = null, this.search(null,
      e))
    }, this.options.delay)
   },
   search: function(e, t) {
    return e = null != e ? e : this._value(), this.term = this._value(), e.length <
     this.options.minLength ? this.close(t) : this._trigger("search", t) !==
     !1 ? this._search(e) : void 0
   },
   _search: function(e) {
    this.pending++, this.element.addClass("ui-autocomplete-loading"), this.cancelSearch = !
     1, this.source({
      term: e
     }, this._response())
   },
   _response: function() {
    var t = ++this.requestIndex;
    return e.proxy(function(e) {
     t === this.requestIndex && this.__response(e), this.pending--, this.pending ||
      this.element.removeClass("ui-autocomplete-loading")
    }, this)
   },
   __response: function(e) {
    e && (e = this._normalize(e)), this._trigger("response", null, {
     content: e
    }), !this.options.disabled && e && e.length && !this.cancelSearch ? (
     this._suggest(e), this._trigger("open")) : this._close()
   },
   close: function(e) {
    this.cancelSearch = !0, this._close(e)
   },
   _close: function(e) {
    this.menu.element.is(":visible") && (this.menu.element.hide(), this.menu
     .blur(), this.isNewMenu = !0, this._trigger("close", e))
   },
   _change: function(e) {
    this.previous !== this._value() && this._trigger("change", e, {
     item: this.selectedItem
    })
   },
   _normalize: function(t) {
    return t.length && t[0].label && t[0].value ? t : e.map(t, function(t) {
     return "string" == typeof t ? {
      label: t,
      value: t
     } : e.extend({}, t, {
      label: t.label || t.value,
      value: t.value || t.label
     })
    })
   },
   _suggest: function(t) {
    var i = this.menu.element.empty();
    this._renderMenu(i, t), this.isNewMenu = !0, this.menu.refresh(), i.show(),
     this._resizeMenu(), i.position(e.extend({
      of: this.element
     }, this.options.position)), this.options.autoFocus && this.menu.next()
   },
   _resizeMenu: function() {
    var e = this.menu.element;
    e.outerWidth(Math.max(e.width("").outerWidth() + 1, this.element.outerWidth()))
   },
   _renderMenu: function(t, i) {
    var s = this;
    e.each(i, function(e, i) {
     s._renderItemData(t, i)
    })
   },
   _renderItemData: function(e, t) {
    return this._renderItem(e, t).data("ui-autocomplete-item", t)
   },
   _renderItem: function(t, i) {
    return e("<li>").text(i.label).appendTo(t)
   },
   _move: function(e, t) {
    return this.menu.element.is(":visible") ? this.menu.isFirstItem() &&
     /^previous/.test(e) || this.menu.isLastItem() && /^next/.test(e) ? (
      this.isMultiLine || this._value(this.term), this.menu.blur(), void 0) :
     (this.menu[e](t), void 0) : (this.search(null, t), void 0)
   },
   widget: function() {
    return this.menu.element
   },
   _value: function() {
    return this.valueMethod.apply(this.element, arguments)
   },
   _keyEvent: function(e, t) {
    (!this.isMultiLine || this.menu.element.is(":visible")) && (this._move(e,
     t), t.preventDefault())
   }
  }), e.extend(e.ui.autocomplete, {
   escapeRegex: function(e) {
    return e.replace(/[\-\[\]{}()*+?.,\\\^$|#\s]/g, "\\$&")
   },
   filter: function(t, i) {
    var s = RegExp(e.ui.autocomplete.escapeRegex(i), "i");
    return e.grep(t, function(e) {
     return s.test(e.label || e.value || e)
    })
   }
  }), e.widget("ui.autocomplete", e.ui.autocomplete, {
   options: {
    messages: {
     noResults: "No search results.",
     results: function(e) {
      return e + (e > 1 ? " results are" : " result is") +
       " available, use up and down arrow keys to navigate."
     }
    }
   },
   __response: function(t) {
    var i;
    this._superApply(arguments), this.options.disabled || this.cancelSearch ||
     (i = t && t.length ? this.options.messages.results(t.length) : this.options
      .messages.noResults, this.liveRegion.children().hide(), e("<div>").text(
       i).appendTo(this.liveRegion))
   }
  }), e.ui.autocomplete;
 var c, p = "ui-button ui-widget ui-state-default ui-corner-all",
  f =
  "ui-button-icons-only ui-button-icon-only ui-button-text-icons ui-button-text-icon-primary ui-button-text-icon-secondary ui-button-text-only",
  m = function() {
   var t = e(this);
   setTimeout(function() {
    t.find(":ui-button").button("refresh")
   }, 1)
  },
  g = function(t) {
   var i = t.name,
    s = t.form,
    n = e([]);
   return i && (i = i.replace(/'/g, "\\'"), n = s ? e(s).find("[name='" + i +
     "'][type=radio]") : e("[name='" + i + "'][type=radio]", t.ownerDocument)
    .filter(function() {
     return !this.form
    })), n
  };
 e.widget("ui.button", {
  version: "1.11.2",
  defaultElement: "<button>",
  options: {
   disabled: null,
   text: !0,
   label: null,
   icons: {
    primary: null,
    secondary: null
   }
  },
  _create: function() {
   this.element.closest("form").unbind("reset" + this.eventNamespace).bind(
     "reset" + this.eventNamespace, m), "boolean" != typeof this.options.disabled ?
    this.options.disabled = !!this.element.prop("disabled") : this.element.prop(
     "disabled", this.options.disabled), this._determineButtonType(), this.hasTitle = !
    !this.buttonElement.attr("title");
   var t = this,
    i = this.options,
    s = "checkbox" === this.type || "radio" === this.type,
    n = s ? "" : "ui-state-active";
   null === i.label && (i.label = "input" === this.type ? this.buttonElement
     .val() : this.buttonElement.html()), this._hoverable(this.buttonElement),
    this.buttonElement.addClass(p).attr("role", "button").bind("mouseenter" +
     this.eventNamespace,
     function() {
      i.disabled || this === c && e(this).addClass("ui-state-active")
     }).bind("mouseleave" + this.eventNamespace, function() {
     i.disabled || e(this).removeClass(n)
    }).bind("click" + this.eventNamespace, function(e) {
     i.disabled && (e.preventDefault(), e.stopImmediatePropagation())
    }), this._on({
     focus: function() {
      this.buttonElement.addClass("ui-state-focus")
     },
     blur: function() {
      this.buttonElement.removeClass("ui-state-focus")
     }
    }), s && this.element.bind("change" + this.eventNamespace, function() {
     t.refresh()
    }), "checkbox" === this.type ? this.buttonElement.bind("click" + this.eventNamespace,
     function() {
      return i.disabled ? !1 : void 0
     }) : "radio" === this.type ? this.buttonElement.bind("click" + this.eventNamespace,
     function() {
      if (i.disabled) return !1;
      e(this).addClass("ui-state-active"), t.buttonElement.attr(
       "aria-pressed", "true");
      var s = t.element[0];
      g(s).not(s).map(function() {
       return e(this).button("widget")[0]
      }).removeClass("ui-state-active").attr("aria-pressed", "false")
     }) : (this.buttonElement.bind("mousedown" + this.eventNamespace,
     function() {
      return i.disabled ? !1 : (e(this).addClass("ui-state-active"), c =
       this, t.document.one("mouseup", function() {
        c = null
       }), void 0)
     }).bind("mouseup" + this.eventNamespace, function() {
     return i.disabled ? !1 : (e(this).removeClass("ui-state-active"),
      void 0)
    }).bind("keydown" + this.eventNamespace, function(t) {
     return i.disabled ? !1 : ((t.keyCode === e.ui.keyCode.SPACE || t.keyCode ===
      e.ui.keyCode.ENTER) && e(this).addClass("ui-state-active"), void 0)
    }).bind("keyup" + this.eventNamespace + " blur" + this.eventNamespace,
     function() {
      e(this).removeClass("ui-state-active")
     }), this.buttonElement.is("a") && this.buttonElement.keyup(function(t) {
     t.keyCode === e.ui.keyCode.SPACE && e(this).click()
    })), this._setOption("disabled", i.disabled), this._resetButton()
  },
  _determineButtonType: function() {
   var e, t, i;
   this.type = this.element.is("[type=checkbox]") ? "checkbox" : this.element
    .is("[type=radio]") ? "radio" : this.element.is("input") ? "input" :
    "button", "checkbox" === this.type || "radio" === this.type ? (e = this
     .element.parents().last(), t = "label[for='" + this.element.attr("id") +
     "']", this.buttonElement = e.find(t), this.buttonElement.length || (e =
      e.length ? e.siblings() : this.element.siblings(), this.buttonElement =
      e.filter(t), this.buttonElement.length || (this.buttonElement = e.find(
       t))), this.element.addClass("ui-helper-hidden-accessible"), i = this
     .element.is(":checked"), i && this.buttonElement.addClass(
      "ui-state-active"), this.buttonElement.prop("aria-pressed", i)) :
    this.buttonElement = this.element
  },
  widget: function() {
   return this.buttonElement
  },
  _destroy: function() {
   this.element.removeClass("ui-helper-hidden-accessible"), this.buttonElement
    .removeClass(p + " ui-state-active " + f).removeAttr("role").removeAttr(
     "aria-pressed").html(this.buttonElement.find(".ui-button-text").html()),
    this.hasTitle || this.buttonElement.removeAttr("title")
  },
  _setOption: function(e, t) {
   return this._super(e, t), "disabled" === e ? (this.widget().toggleClass(
    "ui-state-disabled", !!t), this.element.prop("disabled", !!t), t && (
    "checkbox" === this.type || "radio" === this.type ? this.buttonElement
    .removeClass("ui-state-focus") : this.buttonElement.removeClass(
     "ui-state-focus ui-state-active")), void 0) : (this._resetButton(),
    void 0)
  },
  refresh: function() {
   var t = this.element.is("input, button") ? this.element.is(":disabled") :
    this.element.hasClass("ui-button-disabled");
   t !== this.options.disabled && this._setOption("disabled", t), "radio" ===
    this.type ? g(this.element[0]).each(function() {
     e(this).is(":checked") ? e(this).button("widget").addClass(
      "ui-state-active").attr("aria-pressed", "true") : e(this).button(
      "widget").removeClass("ui-state-active").attr("aria-pressed",
      "false")
    }) : "checkbox" === this.type && (this.element.is(":checked") ? this.buttonElement
     .addClass("ui-state-active").attr("aria-pressed", "true") : this.buttonElement
     .removeClass("ui-state-active").attr("aria-pressed", "false"))
  },
  _resetButton: function() {
   if ("input" === this.type) return this.options.label && this.element.val(
    this.options.label), void 0;
   var t = this.buttonElement.removeClass(f),
    i = e("<span></span>", this.document[0]).addClass("ui-button-text").html(
     this.options.label).appendTo(t.empty()).text(),
    s = this.options.icons,
    n = s.primary && s.secondary,
    a = [];
   s.primary || s.secondary ? (this.options.text && a.push(
     "ui-button-text-icon" + (n ? "s" : s.primary ? "-primary" :
      "-secondary")), s.primary && t.prepend(
     "<span class='ui-button-icon-primary ui-icon " + s.primary +
     "'></span>"), s.secondary && t.append(
     "<span class='ui-button-icon-secondary ui-icon " + s.secondary +
     "'></span>"), this.options.text || (a.push(n ? "ui-button-icons-only" :
     "ui-button-icon-only"), this.hasTitle || t.attr("title", e.trim(i)))) :
    a.push("ui-button-text-only"), t.addClass(a.join(" "))
  }
 }), e.widget("ui.buttonset", {
  version: "1.11.2",
  options: {
   items: "button, input[type=button], input[type=submit], input[type=reset], input[type=checkbox], input[type=radio], a, :data(ui-button)"
  },
  _create: function() {
   this.element.addClass("ui-buttonset")
  },
  _init: function() {
   this.refresh()
  },
  _setOption: function(e, t) {
   "disabled" === e && this.buttons.button("option", e, t), this._super(e,
    t)
  },
  refresh: function() {
   var t = "rtl" === this.element.css("direction"),
    i = this.element.find(this.options.items),
    s = i.filter(":ui-button");
   i.not(":ui-button").button(), s.button("refresh"), this.buttons = i.map(
    function() {
     return e(this).button("widget")[0]
    }).removeClass("ui-corner-all ui-corner-left ui-corner-right").filter(
    ":first").addClass(t ? "ui-corner-right" : "ui-corner-left").end().filter(
    ":last").addClass(t ? "ui-corner-left" : "ui-corner-right").end().end()
  },
  _destroy: function() {
   this.element.removeClass("ui-buttonset"), this.buttons.map(function() {
    return e(this).button("widget")[0]
   }).removeClass("ui-corner-left ui-corner-right").end().button("destroy")
  }
 }), e.ui.button, e.extend(e.ui, {
  datepicker: {
   version: "1.11.2"
  }
 });
 var v;
 e.extend(n.prototype, {
   markerClassName: "hasDatepicker",
   maxRows: 4,
   _widgetDatepicker: function() {
    return this.dpDiv
   },
   setDefaults: function(e) {
    return r(this._defaults, e || {}), this
   },
   _attachDatepicker: function(t, i) {
    var s, n, a;
    s = t.nodeName.toLowerCase(), n = "div" === s || "span" === s, t.id || (
      this.uuid += 1, t.id = "dp" + this.uuid), a = this._newInst(e(t), n),
     a.settings = e.extend({}, i || {}), "input" === s ? this._connectDatepicker(
      t, a) : n && this._inlineDatepicker(t, a)
   },
   _newInst: function(t, i) {
    var s = t[0].id.replace(/([^A-Za-z0-9_\-])/g, "\\\\$1");
    return {
     id: s,
     input: t,
     selectedDay: 0,
     selectedMonth: 0,
     selectedYear: 0,
     drawMonth: 0,
     drawYear: 0,
     inline: i,
     dpDiv: i ? a(e("<div class='" + this._inlineClass +
      " ui-datepicker ui-widget ui-widget-content ui-helper-clearfix ui-corner-all'></div>"
     )) : this.dpDiv
    }
   },
   _connectDatepicker: function(t, i) {
    var s = e(t);
    i.append = e([]), i.trigger = e([]), s.hasClass(this.markerClassName) ||
     (this._attachments(s, i), s.addClass(this.markerClassName).keydown(this
      ._doKeyDown).keypress(this._doKeyPress).keyup(this._doKeyUp), this._autoSize(
      i), e.data(t, "datepicker", i), i.settings.disabled && this._disableDatepicker(
      t))
   },
   _attachments: function(t, i) {
    var s, n, a, o = this._get(i, "appendText"),
     r = this._get(i, "isRTL");
    i.append && i.append.remove(), o && (i.append = e("<span class='" + this
      ._appendClass + "'>" + o + "</span>"), t[r ? "before" : "after"](i.append)),
     t.unbind("focus", this._showDatepicker), i.trigger && i.trigger.remove(),
     s = this._get(i, "showOn"), ("focus" === s || "both" === s) && t.focus(
      this._showDatepicker), ("button" === s || "both" === s) && (n = this._get(
      i, "buttonText"), a = this._get(i, "buttonImage"), i.trigger = e(this
      ._get(i, "buttonImageOnly") ? e("<img/>").addClass(this._triggerClass)
      .attr({
       src: a,
       alt: n,
       title: n
      }) : e("<button type='button'></button>").addClass(this._triggerClass)
      .html(a ? e("<img/>").attr({
       src: a,
       alt: n,
       title: n
      }) : n)), t[r ? "before" : "after"](i.trigger), i.trigger.click(
      function() {
       return e.datepicker._datepickerShowing && e.datepicker._lastInput ===
        t[0] ? e.datepicker._hideDatepicker() : e.datepicker._datepickerShowing &&
        e.datepicker._lastInput !== t[0] ? (e.datepicker._hideDatepicker(),
         e.datepicker._showDatepicker(t[0])) : e.datepicker._showDatepicker(
         t[0]), !1
      }))
   },
   _autoSize: function(e) {
    if (this._get(e, "autoSize") && !e.inline) {
     var t, i, s, n, a = new Date(2009, 11, 20),
      o = this._get(e, "dateFormat");
     o.match(/[DM]/) && (t = function(e) {
      for (i = 0, s = 0, n = 0; e.length > n; n++) e[n].length > i && (i =
       e[n].length, s = n);
      return s
     }, a.setMonth(t(this._get(e, o.match(/MM/) ? "monthNames" :
      "monthNamesShort"))), a.setDate(t(this._get(e, o.match(/DD/) ?
      "dayNames" : "dayNamesShort")) + 20 - a.getDay())), e.input.attr(
      "size", this._formatDate(e, a).length)
    }
   },
   _inlineDatepicker: function(t, i) {
    var s = e(t);
    s.hasClass(this.markerClassName) || (s.addClass(this.markerClassName).append(
      i.dpDiv), e.data(t, "datepicker", i), this._setDate(i, this._getDefaultDate(
      i), !0), this._updateDatepicker(i), this._updateAlternate(i), i.settings
     .disabled && this._disableDatepicker(t), i.dpDiv.css("display",
      "block"))
   },
   _dialogDatepicker: function(t, i, s, n, a) {
    var o, h, l, u, d, c = this._dialogInst;
    return c || (this.uuid += 1, o = "dp" + this.uuid, this._dialogInput = e(
       "<input type='text' id='" + o +
       "' style='position: absolute; top: -100px; width: 0px;'/>"), this._dialogInput
      .keydown(this._doKeyDown), e("body").append(this._dialogInput), c =
      this._dialogInst = this._newInst(this._dialogInput, !1), c.settings = {},
      e.data(this._dialogInput[0], "datepicker", c)), r(c.settings, n || {}),
     i = i && i.constructor === Date ? this._formatDate(c, i) : i, this._dialogInput
     .val(i), this._pos = a ? a.length ? a : [a.pageX, a.pageY] : null, this
     ._pos || (h = document.documentElement.clientWidth, l = document.documentElement
      .clientHeight, u = document.documentElement.scrollLeft || document.body
      .scrollLeft, d = document.documentElement.scrollTop || document.body.scrollTop,
      this._pos = [h / 2 - 100 + u, l / 2 - 150 + d]), this._dialogInput.css(
      "left", this._pos[0] + 20 + "px").css("top", this._pos[1] + "px"), c.settings
     .onSelect = s, this._inDialog = !0, this.dpDiv.addClass(this._dialogClass),
     this._showDatepicker(this._dialogInput[0]), e.blockUI && e.blockUI(this
      .dpDiv), e.data(this._dialogInput[0], "datepicker", c), this
   },
   _destroyDatepicker: function(t) {
    var i, s = e(t),
     n = e.data(t, "datepicker");
    s.hasClass(this.markerClassName) && (i = t.nodeName.toLowerCase(), e.removeData(
      t, "datepicker"), "input" === i ? (n.append.remove(), n.trigger.remove(),
      s.removeClass(this.markerClassName).unbind("focus", this._showDatepicker)
      .unbind("keydown", this._doKeyDown).unbind("keypress", this._doKeyPress)
      .unbind("keyup", this._doKeyUp)) : ("div" === i || "span" === i) && s
     .removeClass(this.markerClassName).empty())
   },
   _enableDatepicker: function(t) {
    var i, s, n = e(t),
     a = e.data(t, "datepicker");
    n.hasClass(this.markerClassName) && (i = t.nodeName.toLowerCase(),
     "input" === i ? (t.disabled = !1, a.trigger.filter("button").each(
      function() {
       this.disabled = !1
      }).end().filter("img").css({
      opacity: "1.0",
      cursor: ""
     })) : ("div" === i || "span" === i) && (s = n.children("." + this._inlineClass),
      s.children().removeClass("ui-state-disabled"), s.find(
       "select.ui-datepicker-month, select.ui-datepicker-year").prop(
       "disabled", !1)), this._disabledInputs = e.map(this._disabledInputs,
      function(e) {
       return e === t ? null : e
      }))
   },
   _disableDatepicker: function(t) {
    var i, s, n = e(t),
     a = e.data(t, "datepicker");
    n.hasClass(this.markerClassName) && (i = t.nodeName.toLowerCase(),
     "input" === i ? (t.disabled = !0, a.trigger.filter("button").each(
      function() {
       this.disabled = !0
      }).end().filter("img").css({
      opacity: "0.5",
      cursor: "default"
     })) : ("div" === i || "span" === i) && (s = n.children("." + this._inlineClass),
      s.children().addClass("ui-state-disabled"), s.find(
       "select.ui-datepicker-month, select.ui-datepicker-year").prop(
       "disabled", !0)), this._disabledInputs = e.map(this._disabledInputs,
      function(e) {
       return e === t ? null : e
      }), this._disabledInputs[this._disabledInputs.length] = t)
   },
   _isDisabledDatepicker: function(e) {
    if (!e) return !1;
    for (var t = 0; this._disabledInputs.length > t; t++)
     if (this._disabledInputs[t] === e) return !0;
    return !1
   },
   _getInst: function(t) {
    try {
     return e.data(t, "datepicker")
    } catch (i) {
     throw "Missing instance data for this datepicker"
    }
   },
   _optionDatepicker: function(t, i, s) {
    var n, a, o, h, l = this._getInst(t);
    return 2 === arguments.length && "string" == typeof i ? "defaults" === i ?
     e.extend({}, e.datepicker._defaults) : l ? "all" === i ? e.extend({}, l
      .settings) : this._get(l, i) : null : (n = i || {}, "string" == typeof i &&
      (n = {}, n[i] = s), l && (this._curInst === l && this._hideDatepicker(),
       a = this._getDateDatepicker(t, !0), o = this._getMinMaxDate(l, "min"),
       h = this._getMinMaxDate(l, "max"), r(l.settings, n), null !== o &&
       void 0 !== n.dateFormat && void 0 === n.minDate && (l.settings.minDate =
        this._formatDate(l, o)), null !== h && void 0 !== n.dateFormat &&
       void 0 === n.maxDate && (l.settings.maxDate = this._formatDate(l, h)),
       "disabled" in n && (n.disabled ? this._disableDatepicker(t) : this._enableDatepicker(
        t)), this._attachments(e(t), l), this._autoSize(l), this._setDate(l,
        a), this._updateAlternate(l), this._updateDatepicker(l)), void 0)
   },
   _changeDatepicker: function(e, t, i) {
    this._optionDatepicker(e, t, i)
   },
   _refreshDatepicker: function(e) {
    var t = this._getInst(e);
    t && this._updateDatepicker(t)
   },
   _setDateDatepicker: function(e, t) {
    var i = this._getInst(e);
    i && (this._setDate(i, t), this._updateDatepicker(i), this._updateAlternate(
     i))
   },
   _getDateDatepicker: function(e, t) {
    var i = this._getInst(e);
    return i && !i.inline && this._setDateFromField(i, t), i ? this._getDate(
     i) : null
   },
   _doKeyDown: function(t) {
    var i, s, n, a = e.datepicker._getInst(t.target),
     o = !0,
     r = a.dpDiv.is(".ui-datepicker-rtl");
    if (a._keyEvent = !0, e.datepicker._datepickerShowing) switch (t.keyCode) {
     case 9:
      e.datepicker._hideDatepicker(), o = !1;
      break;
     case 13:
      return n = e("td." + e.datepicker._dayOverClass + ":not(." + e.datepicker
       ._currentClass + ")", a.dpDiv), n[0] && e.datepicker._selectDay(t.target,
       a.selectedMonth, a.selectedYear, n[0]), i = e.datepicker._get(a,
       "onSelect"), i ? (s = e.datepicker._formatDate(a), i.apply(a.input ?
       a.input[0] : null, [s, a])) : e.datepicker._hideDatepicker(), !1;
     case 27:
      e.datepicker._hideDatepicker();
      break;
     case 33:
      e.datepicker._adjustDate(t.target, t.ctrlKey ? -e.datepicker._get(a,
       "stepBigMonths") : -e.datepicker._get(a, "stepMonths"), "M");
      break;
     case 34:
      e.datepicker._adjustDate(t.target, t.ctrlKey ? +e.datepicker._get(a,
       "stepBigMonths") : +e.datepicker._get(a, "stepMonths"), "M");
      break;
     case 35:
      (t.ctrlKey || t.metaKey) && e.datepicker._clearDate(t.target), o = t.ctrlKey ||
       t.metaKey;
      break;
     case 36:
      (t.ctrlKey || t.metaKey) && e.datepicker._gotoToday(t.target), o = t.ctrlKey ||
       t.metaKey;
      break;
     case 37:
      (t.ctrlKey || t.metaKey) && e.datepicker._adjustDate(t.target, r ? 1 :
        -1, "D"), o = t.ctrlKey || t.metaKey, t.originalEvent.altKey && e.datepicker
       ._adjustDate(t.target, t.ctrlKey ? -e.datepicker._get(a,
        "stepBigMonths") : -e.datepicker._get(a, "stepMonths"), "M");
      break;
     case 38:
      (t.ctrlKey || t.metaKey) && e.datepicker._adjustDate(t.target, -7,
       "D"), o = t.ctrlKey || t.metaKey;
      break;
     case 39:
      (t.ctrlKey || t.metaKey) && e.datepicker._adjustDate(t.target, r ? -1 :
        1, "D"), o = t.ctrlKey || t.metaKey, t.originalEvent.altKey && e.datepicker
       ._adjustDate(t.target, t.ctrlKey ? +e.datepicker._get(a,
        "stepBigMonths") : +e.datepicker._get(a, "stepMonths"), "M");
      break;
     case 40:
      (t.ctrlKey || t.metaKey) && e.datepicker._adjustDate(t.target, 7, "D"),
       o = t.ctrlKey || t.metaKey;
      break;
     default:
      o = !1
    } else 36 === t.keyCode && t.ctrlKey ? e.datepicker._showDatepicker(
     this) : o = !1;
    o && (t.preventDefault(), t.stopPropagation())
   },
   _doKeyPress: function(t) {
    var i, s, n = e.datepicker._getInst(t.target);
    return e.datepicker._get(n, "constrainInput") ? (i = e.datepicker._possibleChars(
      e.datepicker._get(n, "dateFormat")), s = String.fromCharCode(null ==
      t.charCode ? t.keyCode : t.charCode), t.ctrlKey || t.metaKey || " " >
     s || !i || i.indexOf(s) > -1) : void 0
   },
   _doKeyUp: function(t) {
    var i, s = e.datepicker._getInst(t.target);
    if (s.input.val() !== s.lastVal) try {
     i = e.datepicker.parseDate(e.datepicker._get(s, "dateFormat"), s.input ?
      s.input.val() : null, e.datepicker._getFormatConfig(s)), i && (e.datepicker
      ._setDateFromField(s), e.datepicker._updateAlternate(s), e.datepicker
      ._updateDatepicker(s))
    } catch (n) {}
    return !0
   },
   _showDatepicker: function(t) {
    if (t = t.target || t, "input" !== t.nodeName.toLowerCase() && (t = e(
      "input", t.parentNode)[0]), !e.datepicker._isDisabledDatepicker(t) &&
     e.datepicker._lastInput !== t) {
     var i, n, a, o, h, l, u;
     i = e.datepicker._getInst(t), e.datepicker._curInst && e.datepicker._curInst !==
      i && (e.datepicker._curInst.dpDiv.stop(!0, !0), i && e.datepicker._datepickerShowing &&
       e.datepicker._hideDatepicker(e.datepicker._curInst.input[0])), n = e.datepicker
      ._get(i, "beforeShow"), a = n ? n.apply(t, [t, i]) : {}, a !== !1 && (
       r(i.settings, a), i.lastVal = null, e.datepicker._lastInput = t, e.datepicker
       ._setDateFromField(i), e.datepicker._inDialog && (t.value = ""), e.datepicker
       ._pos || (e.datepicker._pos = e.datepicker._findPos(t), e.datepicker._pos[
        1] += t.offsetHeight), o = !1, e(t).parents().each(function() {
        return o |= "fixed" === e(this).css("position"), !o
       }), h = {
        left: e.datepicker._pos[0],
        top: e.datepicker._pos[1]
       }, e.datepicker._pos = null, i.dpDiv.empty(), i.dpDiv.css({
        position: "absolute",
        display: "block",
        top: "-1000px"
       }), e.datepicker._updateDatepicker(i), h = e.datepicker._checkOffset(
        i, h, o), i.dpDiv.css({
        position: e.datepicker._inDialog && e.blockUI ? "static" : o ?
         "fixed" : "absolute",
        display: "none",
        left: h.left + "px",
        top: h.top + "px"
       }), i.inline || (l = e.datepicker._get(i, "showAnim"), u = e.datepicker
        ._get(i, "duration"), i.dpDiv.css("z-index", s(e(t)) + 1), e.datepicker
        ._datepickerShowing = !0, e.effects && e.effects.effect[l] ? i.dpDiv
        .show(l, e.datepicker._get(i, "showOptions"), u) : i.dpDiv[l ||
         "show"](l ? u : null), e.datepicker._shouldFocusInput(i) && i.input
        .focus(), e.datepicker._curInst = i))
    }
   },
   _updateDatepicker: function(t) {
    this.maxRows = 4, v = t, t.dpDiv.empty().append(this._generateHTML(t)),
     this._attachHandlers(t);
    var i, s = this._getNumberOfMonths(t),
     n = s[1],
     a = 17,
     r = t.dpDiv.find("." + this._dayOverClass + " a");
    r.length > 0 && o.apply(r.get(0)), t.dpDiv.removeClass(
      "ui-datepicker-multi-2 ui-datepicker-multi-3 ui-datepicker-multi-4").width(
      ""), n > 1 && t.dpDiv.addClass("ui-datepicker-multi-" + n).css("width",
      a * n + "em"), t.dpDiv[(1 !== s[0] || 1 !== s[1] ? "add" : "remove") +
      "Class"]("ui-datepicker-multi"), t.dpDiv[(this._get(t, "isRTL") ?
      "add" : "remove") + "Class"]("ui-datepicker-rtl"), t === e.datepicker._curInst &&
     e.datepicker._datepickerShowing && e.datepicker._shouldFocusInput(t) &&
     t.input.focus(), t.yearshtml && (i = t.yearshtml, setTimeout(function() {
      i === t.yearshtml && t.yearshtml && t.dpDiv.find(
        "select.ui-datepicker-year:first").replaceWith(t.yearshtml), i = t
       .yearshtml = null
     }, 0))
   },
   _shouldFocusInput: function(e) {
    return e.input && e.input.is(":visible") && !e.input.is(":disabled") &&
     !e.input.is(":focus")
   },
   _checkOffset: function(t, i, s) {
    var n = t.dpDiv.outerWidth(),
     a = t.dpDiv.outerHeight(),
     o = t.input ? t.input.outerWidth() : 0,
     r = t.input ? t.input.outerHeight() : 0,
     h = document.documentElement.clientWidth + (s ? 0 : e(document).scrollLeft()),
     l = document.documentElement.clientHeight + (s ? 0 : e(document).scrollTop());
    return i.left -= this._get(t, "isRTL") ? n - o : 0, i.left -= s && i.left ===
     t.input.offset().left ? e(document).scrollLeft() : 0, i.top -= s && i.top ===
     t.input.offset().top + r ? e(document).scrollTop() : 0, i.left -= Math.min(
      i.left, i.left + n > h && h > n ? Math.abs(i.left + n - h) : 0), i.top -=
     Math.min(i.top, i.top + a > l && l > a ? Math.abs(a + r) : 0), i
   },
   _findPos: function(t) {
    for (var i, s = this._getInst(t), n = this._get(s, "isRTL"); t && (
      "hidden" === t.type || 1 !== t.nodeType || e.expr.filters.hidden(t));)
     t = t[n ? "previousSibling" : "nextSibling"];
    return i = e(t).offset(), [i.left, i.top]
   },
   _hideDatepicker: function(t) {
    var i, s, n, a, o = this._curInst;
    !o || t && o !== e.data(t, "datepicker") || this._datepickerShowing && (
     i = this._get(o, "showAnim"), s = this._get(o, "duration"), n =
     function() {
      e.datepicker._tidyDialog(o)
     }, e.effects && (e.effects.effect[i] || e.effects[i]) ? o.dpDiv.hide(i,
      e.datepicker._get(o, "showOptions"), s, n) : o.dpDiv["slideDown" ===
      i ? "slideUp" : "fadeIn" === i ? "fadeOut" : "hide"](i ? s : null, n),
     i || n(), this._datepickerShowing = !1, a = this._get(o, "onClose"), a &&
     a.apply(o.input ? o.input[0] : null, [o.input ? o.input.val() : "", o]),
     this._lastInput = null, this._inDialog && (this._dialogInput.css({
      position: "absolute",
      left: "0",
      top: "-100px"
     }), e.blockUI && (e.unblockUI(), e("body").append(this.dpDiv))), this._inDialog = !
     1)
   },
   _tidyDialog: function(e) {
    e.dpDiv.removeClass(this._dialogClass).unbind(".ui-datepicker-calendar")
   },
   _checkExternalClick: function(t) {
    if (e.datepicker._curInst) {
     var i = e(t.target),
      s = e.datepicker._getInst(i[0]);
     (i[0].id !== e.datepicker._mainDivId && 0 === i.parents("#" + e.datepicker
       ._mainDivId).length && !i.hasClass(e.datepicker.markerClassName) && !
      i.closest("." + e.datepicker._triggerClass).length && e.datepicker._datepickerShowing &&
      (!e.datepicker._inDialog || !e.blockUI) || i.hasClass(e.datepicker.markerClassName) &&
      e.datepicker._curInst !== s) && e.datepicker._hideDatepicker()
    }
   },
   _adjustDate: function(t, i, s) {
    var n = e(t),
     a = this._getInst(n[0]);
    this._isDisabledDatepicker(n[0]) || (this._adjustInstDate(a, i + ("M" ===
     s ? this._get(a, "showCurrentAtPos") : 0), s), this._updateDatepicker(
     a))
   },
   _gotoToday: function(t) {
    var i, s = e(t),
     n = this._getInst(s[0]);
    this._get(n, "gotoCurrent") && n.currentDay ? (n.selectedDay = n.currentDay,
     n.drawMonth = n.selectedMonth = n.currentMonth, n.drawYear = n.selectedYear =
     n.currentYear) : (i = new Date, n.selectedDay = i.getDate(), n.drawMonth =
     n.selectedMonth = i.getMonth(), n.drawYear = n.selectedYear = i.getFullYear()
    ), this._notifyChange(n), this._adjustDate(s)
   },
   _selectMonthYear: function(t, i, s) {
    var n = e(t),
     a = this._getInst(n[0]);
    a["selected" + ("M" === s ? "Month" : "Year")] = a["draw" + ("M" === s ?
      "Month" : "Year")] = parseInt(i.options[i.selectedIndex].value, 10),
     this._notifyChange(a), this._adjustDate(n)
   },
   _selectDay: function(t, i, s, n) {
    var a, o = e(t);
    e(n).hasClass(this._unselectableClass) || this._isDisabledDatepicker(o[0]) ||
     (a = this._getInst(o[0]), a.selectedDay = a.currentDay = e("a", n).html(),
      a.selectedMonth = a.currentMonth = i, a.selectedYear = a.currentYear =
      s, this._selectDate(t, this._formatDate(a, a.currentDay, a.currentMonth,
       a.currentYear)))
   },
   _clearDate: function(t) {
    var i = e(t);
    this._selectDate(i, "")
   },
   _selectDate: function(t, i) {
    var s, n = e(t),
     a = this._getInst(n[0]);
    i = null != i ? i : this._formatDate(a), a.input && a.input.val(i), this
     ._updateAlternate(a), s = this._get(a, "onSelect"), s ? s.apply(a.input ?
      a.input[0] : null, [i, a]) : a.input && a.input.trigger("change"), a.inline ?
     this._updateDatepicker(a) : (this._hideDatepicker(), this._lastInput =
      a.input[0], "object" != typeof a.input[0] && a.input.focus(), this._lastInput =
      null)
   },
   _updateAlternate: function(t) {
    var i, s, n, a = this._get(t, "altField");
    a && (i = this._get(t, "altFormat") || this._get(t, "dateFormat"), s =
     this._getDate(t), n = this.formatDate(i, s, this._getFormatConfig(t)),
     e(a).each(function() {
      e(this).val(n)
     }))
   },
   noWeekends: function(e) {
    var t = e.getDay();
    return [t > 0 && 6 > t, ""]
   },
   iso8601Week: function(e) {
    var t, i = new Date(e.getTime());
    return i.setDate(i.getDate() + 4 - (i.getDay() || 7)), t = i.getTime(),
     i.setMonth(0), i.setDate(1), Math.floor(Math.round((t - i) / 864e5) / 7) +
     1
   },
   parseDate: function(t, i, s) {
    if (null == t || null == i) throw "Invalid arguments";
    if (i = "object" == typeof i ? "" + i : i + "", "" === i) return null;
    var n, a, o, r, h = 0,
     l = (s ? s.shortYearCutoff : null) || this._defaults.shortYearCutoff,
     u = "string" != typeof l ? l : (new Date).getFullYear() % 100 +
     parseInt(l, 10),
     d = (s ? s.dayNamesShort : null) || this._defaults.dayNamesShort,
     c = (s ? s.dayNames : null) || this._defaults.dayNames,
     p = (s ? s.monthNamesShort : null) || this._defaults.monthNamesShort,
     f = (s ? s.monthNames : null) || this._defaults.monthNames,
     m = -1,
     g = -1,
     v = -1,
     y = -1,
     b = !1,
     _ = function(e) {
      var i = t.length > n + 1 && t.charAt(n + 1) === e;
      return i && n++, i
     },
     x = function(e) {
      var t = _(e),
       s = "@" === e ? 14 : "!" === e ? 20 : "y" === e && t ? 4 : "o" === e ?
       3 : 2,
       n = "y" === e ? s : 1,
       a = RegExp("^\\d{" + n + "," + s + "}"),
       o = i.substring(h).match(a);
      if (!o) throw "Missing number at position " + h;
      return h += o[0].length, parseInt(o[0], 10)
     },
     w = function(t, s, n) {
      var a = -1,
       o = e.map(_(t) ? n : s, function(e, t) {
        return [
         [t, e]
        ]
       }).sort(function(e, t) {
        return -(e[1].length - t[1].length)
       });
      if (e.each(o, function(e, t) {
        var s = t[1];
        return i.substr(h, s.length).toLowerCase() === s.toLowerCase() ? (a =
         t[0], h += s.length, !1) : void 0
       }), -1 !== a) return a + 1;
      throw "Unknown name at position " + h
     },
     k = function() {
      if (i.charAt(h) !== t.charAt(n)) throw "Unexpected literal at position " +
       h;
      h++
     };
    for (n = 0; t.length > n; n++)
     if (b) "'" !== t.charAt(n) || _("'") ? k() : b = !1;
     else switch (t.charAt(n)) {
      case "d":
       v = x("d");
       break;
      case "D":
       w("D", d, c);
       break;
      case "o":
       y = x("o");
       break;
      case "m":
       g = x("m");
       break;
      case "M":
       g = w("M", p, f);
       break;
      case "y":
       m = x("y");
       break;
      case "@":
       r = new Date(x("@")), m = r.getFullYear(), g = r.getMonth() + 1, v =
        r.getDate();
       break;
      case "!":
       r = new Date((x("!") - this._ticksTo1970) / 1e4), m = r.getFullYear(),
        g = r.getMonth() + 1, v = r.getDate();
       break;
      case "'":
       _("'") ? k() : b = !0;
       break;
      default:
       k()
     }
    if (i.length > h && (o = i.substr(h), !/^\s+/.test(o))) throw "Extra/unparsed characters found in date: " +
     o;
    if (-1 === m ? m = (new Date).getFullYear() : 100 > m && (m += (new Date)
      .getFullYear() - (new Date).getFullYear() % 100 + (u >= m ? 0 : -100)),
     y > -1)
     for (g = 1, v = y;;) {
      if (a = this._getDaysInMonth(m, g - 1), a >= v) break;
      g++, v -= a
     }
    if (r = this._daylightSavingAdjust(new Date(m, g - 1, v)), r.getFullYear() !==
     m || r.getMonth() + 1 !== g || r.getDate() !== v) throw "Invalid date";
    return r
   },
   ATOM: "yy-mm-dd",
   COOKIE: "D, dd M yy",
   ISO_8601: "yy-mm-dd",
   RFC_822: "D, d M y",
   RFC_850: "DD, dd-M-y",
   RFC_1036: "D, d M y",
   RFC_1123: "D, d M yy",
   RFC_2822: "D, d M yy",
   RSS: "D, d M y",
   TICKS: "!",
   TIMESTAMP: "@",
   W3C: "yy-mm-dd",
   _ticksTo1970: 1e7 * 60 * 60 * 24 * (718685 + Math.floor(492.5) - Math.floor(
    19.7) + Math.floor(4.925)),
   formatDate: function(e, t, i) {
    if (!t) return "";
    var s, n = (i ? i.dayNamesShort : null) || this._defaults.dayNamesShort,
     a = (i ? i.dayNames : null) || this._defaults.dayNames,
     o = (i ? i.monthNamesShort : null) || this._defaults.monthNamesShort,
     r = (i ? i.monthNames : null) || this._defaults.monthNames,
     h = function(t) {
      var i = e.length > s + 1 && e.charAt(s + 1) === t;
      return i && s++, i
     },
     l = function(e, t, i) {
      var s = "" + t;
      if (h(e))
       for (; i > s.length;) s = "0" + s;
      return s
     },
     u = function(e, t, i, s) {
      return h(e) ? s[t] : i[t]
     },
     d = "",
     c = !1;
    if (t)
     for (s = 0; e.length > s; s++)
      if (c) "'" !== e.charAt(s) || h("'") ? d += e.charAt(s) : c = !1;
      else switch (e.charAt(s)) {
       case "d":
        d += l("d", t.getDate(), 2);
        break;
       case "D":
        d += u("D", t.getDay(), n, a);
        break;
       case "o":
        d += l("o", Math.round((new Date(t.getFullYear(), t.getMonth(), t.getDate())
          .getTime() - new Date(t.getFullYear(), 0, 0).getTime()) / 864e5),
         3);
        break;
       case "m":
        d += l("m", t.getMonth() + 1, 2);
        break;
       case "M":
        d += u("M", t.getMonth(), o, r);
        break;
       case "y":
        d += h("y") ? t.getFullYear() : (10 > t.getYear() % 100 ? "0" : "") +
         t.getYear() % 100;
        break;
       case "@":
        d += t.getTime();
        break;
       case "!":
        d += 1e4 * t.getTime() + this._ticksTo1970;
        break;
       case "'":
        h("'") ? d += "'" : c = !0;
        break;
       default:
        d += e.charAt(s)
      }
    return d
   },
   _possibleChars: function(e) {
    var t, i = "",
     s = !1,
     n = function(i) {
      var s = e.length > t + 1 && e.charAt(t + 1) === i;
      return s && t++, s
     };
    for (t = 0; e.length > t; t++)
     if (s) "'" !== e.charAt(t) || n("'") ? i += e.charAt(t) : s = !1;
     else switch (e.charAt(t)) {
      case "d":
      case "m":
      case "y":
      case "@":
       i += "0123456789";
       break;
      case "D":
      case "M":
       return null;
      case "'":
       n("'") ? i += "'" : s = !0;
       break;
      default:
       i += e.charAt(t)
     }
    return i
   },
   _get: function(e, t) {
    return void 0 !== e.settings[t] ? e.settings[t] : this._defaults[t]
   },
   _setDateFromField: function(e, t) {
    if (e.input.val() !== e.lastVal) {
     var i = this._get(e, "dateFormat"),
      s = e.lastVal = e.input ? e.input.val() : null,
      n = this._getDefaultDate(e),
      a = n,
      o = this._getFormatConfig(e);
     try {
      a = this.parseDate(i, s, o) || n
     } catch (r) {
      s = t ? "" : s
     }
     e.selectedDay = a.getDate(), e.drawMonth = e.selectedMonth = a.getMonth(),
      e.drawYear = e.selectedYear = a.getFullYear(), e.currentDay = s ? a.getDate() :
      0, e.currentMonth = s ? a.getMonth() : 0, e.currentYear = s ? a.getFullYear() :
      0, this._adjustInstDate(e)
    }
   },
   _getDefaultDate: function(e) {
    return this._restrictMinMax(e, this._determineDate(e, this._get(e,
     "defaultDate"), new Date))
   },
   _determineDate: function(t, i, s) {
    var n = function(e) {
      var t = new Date;
      return t.setDate(t.getDate() + e), t
     },
     a = function(i) {
      try {
       return e.datepicker.parseDate(e.datepicker._get(t, "dateFormat"), i,
        e.datepicker._getFormatConfig(t))
      } catch (s) {}
      for (var n = (i.toLowerCase().match(/^c/) ? e.datepicker._getDate(t) :
         null) || new Date, a = n.getFullYear(), o = n.getMonth(), r = n.getDate(),
        h = /([+\-]?[0-9]+)\s*(d|D|w|W|m|M|y|Y)?/g, l = h.exec(i); l;) {
       switch (l[2] || "d") {
        case "d":
        case "D":
         r += parseInt(l[1], 10);
         break;
        case "w":
        case "W":
         r += 7 * parseInt(l[1], 10);
         break;
        case "m":
        case "M":
         o += parseInt(l[1], 10), r = Math.min(r, e.datepicker._getDaysInMonth(
          a, o));
         break;
        case "y":
        case "Y":
         a += parseInt(l[1], 10), r = Math.min(r, e.datepicker._getDaysInMonth(
          a, o))
       }
       l = h.exec(i)
      }
      return new Date(a, o, r)
     },
     o = null == i || "" === i ? s : "string" == typeof i ? a(i) : "number" ==
     typeof i ? isNaN(i) ? s : n(i) : new Date(i.getTime());
    return o = o && "Invalid Date" == "" + o ? s : o, o && (o.setHours(0), o
     .setMinutes(0), o.setSeconds(0), o.setMilliseconds(0)), this._daylightSavingAdjust(
     o)
   },
   _daylightSavingAdjust: function(e) {
    return e ? (e.setHours(e.getHours() > 12 ? e.getHours() + 2 : 0), e) :
     null
   },
   _setDate: function(e, t, i) {
    var s = !t,
     n = e.selectedMonth,
     a = e.selectedYear,
     o = this._restrictMinMax(e, this._determineDate(e, t, new Date));
    e.selectedDay = e.currentDay = o.getDate(), e.drawMonth = e.selectedMonth =
     e.currentMonth = o.getMonth(), e.drawYear = e.selectedYear = e.currentYear =
     o.getFullYear(), n === e.selectedMonth && a === e.selectedYear || i ||
     this._notifyChange(e), this._adjustInstDate(e), e.input && e.input.val(
      s ? "" : this._formatDate(e))
   },
   _getDate: function(e) {
    var t = !e.currentYear || e.input && "" === e.input.val() ? null : this._daylightSavingAdjust(
     new Date(e.currentYear, e.currentMonth, e.currentDay));
    return t
   },
   _attachHandlers: function(t) {
    var i = this._get(t, "stepMonths"),
     s = "#" + t.id.replace(/\\\\/g, "\\");
    t.dpDiv.find("[data-handler]").map(function() {
     var t = {
      prev: function() {
       e.datepicker._adjustDate(s, -i, "M")
      },
      next: function() {
       e.datepicker._adjustDate(s, +i, "M")
      },
      hide: function() {
       e.datepicker._hideDatepicker()
      },
      today: function() {
       e.datepicker._gotoToday(s)
      },
      selectDay: function() {
       return e.datepicker._selectDay(s, +this.getAttribute("data-month"), +
        this.getAttribute("data-year"), this), !1
      },
      selectMonth: function() {
       return e.datepicker._selectMonthYear(s, this, "M"), !1
      },
      selectYear: function() {
       return e.datepicker._selectMonthYear(s, this, "Y"), !1
      }
     };
     e(this).bind(this.getAttribute("data-event"), t[this.getAttribute(
      "data-handler")])
    })
   },
   _generateHTML: function(e) {
    var t, i, s, n, a, o, r, h, l, u, d, c, p, f, m, g, v, y, b, _, x, w, k,
     T, D, S, M, C, N, A, P, I, z, H, F, E, O, j, W, L = new Date,
     R = this._daylightSavingAdjust(new Date(L.getFullYear(), L.getMonth(),
      L.getDate())),
     Y = this._get(e, "isRTL"),
     B = this._get(e, "showButtonPanel"),
     J = this._get(e, "hideIfNoPrevNext"),
     q = this._get(e, "navigationAsDateFormat"),
     K = this._getNumberOfMonths(e),
     V = this._get(e, "showCurrentAtPos"),
     U = this._get(e, "stepMonths"),
     Q = 1 !== K[0] || 1 !== K[1],
     G = this._daylightSavingAdjust(e.currentDay ? new Date(e.currentYear, e
      .currentMonth, e.currentDay) : new Date(9999, 9, 9)),
     X = this._getMinMaxDate(e, "min"),
     $ = this._getMinMaxDate(e, "max"),
     Z = e.drawMonth - V,
     et = e.drawYear;
    if (0 > Z && (Z += 12, et--), $)
     for (t = this._daylightSavingAdjust(new Date($.getFullYear(), $.getMonth() -
       K[0] * K[1] + 1, $.getDate())), t = X && X > t ? X : t; this._daylightSavingAdjust(
       new Date(et, Z, 1)) > t;) Z--, 0 > Z && (Z = 11, et--);
    for (e.drawMonth = Z, e.drawYear = et, i = this._get(e, "prevText"), i =
     q ? this.formatDate(i, this._daylightSavingAdjust(new Date(et, Z - U, 1)),
      this._getFormatConfig(e)) : i, s = this._canAdjustMonth(e, -1, et, Z) ?
     "<a class='ui-datepicker-prev ui-corner-all' data-handler='prev' data-event='click' title='" +
     i + "'><span class='ui-icon ui-icon-circle-triangle-" + (Y ? "e" : "w") +
     "'>" + i + "</span></a>" : J ? "" :
     "<a class='ui-datepicker-prev ui-corner-all ui-state-disabled' title='" +
     i + "'><span class='ui-icon ui-icon-circle-triangle-" + (Y ? "e" : "w") +
     "'>" + i + "</span></a>", n = this._get(e, "nextText"), n = q ? this.formatDate(
      n, this._daylightSavingAdjust(new Date(et, Z + U, 1)), this._getFormatConfig(
       e)) : n, a = this._canAdjustMonth(e, 1, et, Z) ?
     "<a class='ui-datepicker-next ui-corner-all' data-handler='next' data-event='click' title='" +
     n + "'><span class='ui-icon ui-icon-circle-triangle-" + (Y ? "w" : "e") +
     "'>" + n + "</span></a>" : J ? "" :
     "<a class='ui-datepicker-next ui-corner-all ui-state-disabled' title='" +
     n + "'><span class='ui-icon ui-icon-circle-triangle-" + (Y ? "w" : "e") +
     "'>" + n + "</span></a>", o = this._get(e, "currentText"), r = this._get(
      e, "gotoCurrent") && e.currentDay ? G : R, o = q ? this.formatDate(o,
      r, this._getFormatConfig(e)) : o, h = e.inline ? "" :
     "<button type='button' class='ui-datepicker-close ui-state-default ui-priority-primary ui-corner-all' data-handler='hide' data-event='click'>" +
     this._get(e, "closeText") + "</button>", l = B ?
     "<div class='ui-datepicker-buttonpane ui-widget-content'>" + (Y ? h :
      "") + (this._isInRange(e, r) ?
      "<button type='button' class='ui-datepicker-current ui-state-default ui-priority-secondary ui-corner-all' data-handler='today' data-event='click'>" +
      o + "</button>" : "") + (Y ? "" : h) + "</div>" : "", u = parseInt(
      this._get(e, "firstDay"), 10), u = isNaN(u) ? 0 : u, d = this._get(e,
      "showWeek"), c = this._get(e, "dayNames"), p = this._get(e,
      "dayNamesMin"), f = this._get(e, "monthNames"), m = this._get(e,
      "monthNamesShort"), g = this._get(e, "beforeShowDay"), v = this._get(e,
      "showOtherMonths"), y = this._get(e, "selectOtherMonths"), b = this._getDefaultDate(
      e), _ = "", w = 0; K[0] > w; w++) {
     for (k = "", this.maxRows = 4, T = 0; K[1] > T; T++) {
      if (D = this._daylightSavingAdjust(new Date(et, Z, e.selectedDay)), S =
       " ui-corner-all", M = "", Q) {
       if (M += "<div class='ui-datepicker-group", K[1] > 1) switch (T) {
        case 0:
         M += " ui-datepicker-group-first", S = " ui-corner-" + (Y ?
          "right" : "left");
         break;
        case K[1] - 1:
         M += " ui-datepicker-group-last", S = " ui-corner-" + (Y ? "left" :
          "right");
         break;
        default:
         M += " ui-datepicker-group-middle", S = ""
       }
       M += "'>"
      }
      for (M +=
       "<div class='ui-datepicker-header ui-widget-header ui-helper-clearfix" +
       S + "'>" + (/all|left/.test(S) && 0 === w ? Y ? a : s : "") + (
        /all|right/.test(S) && 0 === w ? Y ? s : a : "") + this._generateMonthYearHeader(
        e, Z, et, X, $, w > 0 || T > 0, f, m) +
       "</div><table class='ui-datepicker-calendar'><thead>" + "<tr>", C = d ?
       "<th class='ui-datepicker-week-col'>" + this._get(e, "weekHeader") +
       "</th>" : "", x = 0; 7 > x; x++) N = (x + u) % 7, C +=
       "<th scope='col'" + ((x + u + 6) % 7 >= 5 ?
        " class='ui-datepicker-week-end'" : "") + ">" + "<span title='" + c[
        N] + "'>" + p[N] + "</span></th>";
      for (M += C + "</tr></thead><tbody>", A = this._getDaysInMonth(et, Z),
       et === e.selectedYear && Z === e.selectedMonth && (e.selectedDay =
        Math.min(e.selectedDay, A)), P = (this._getFirstDayOfMonth(et, Z) -
        u + 7) % 7, I = Math.ceil((P + A) / 7), z = Q ? this.maxRows > I ?
       this.maxRows : I : I, this.maxRows = z, H = this._daylightSavingAdjust(
        new Date(et, Z, 1 - P)), F = 0; z > F; F++) {
       for (M += "<tr>", E = d ? "<td class='ui-datepicker-week-col'>" +
        this._get(e, "calculateWeek")(H) + "</td>" : "", x = 0; 7 > x; x++) O =
        g ? g.apply(e.input ? e.input[0] : null, [H]) : [!0, ""], j = H.getMonth() !==
        Z, W = j && !y || !O[0] || X && X > H || $ && H > $, E +=
        "<td class='" + ((x + u + 6) % 7 >= 5 ? " ui-datepicker-week-end" :
         "") + (j ? " ui-datepicker-other-month" : "") + (H.getTime() === D.getTime() &&
         Z === e.selectedMonth && e._keyEvent || b.getTime() === H.getTime() &&
         b.getTime() === D.getTime() ? " " + this._dayOverClass : "") + (W ?
         " " + this._unselectableClass + " ui-state-disabled" : "") + (j &&
         !v ? "" : " " + O[1] + (H.getTime() === G.getTime() ? " " + this._currentClass :
          "") + (H.getTime() === R.getTime() ? " ui-datepicker-today" : "")) +
        "'" + (j && !v || !O[2] ? "" : " title='" + O[2].replace(/'/g,
         "&#39;") + "'") + (W ? "" :
         " data-handler='selectDay' data-event='click' data-month='" + H.getMonth() +
         "' data-year='" + H.getFullYear() + "'") + ">" + (j && !v ?
         "&#xa0;" : W ? "<span class='ui-state-default'>" + H.getDate() +
         "</span>" : "<a class='ui-state-default" + (H.getTime() === R.getTime() ?
          " ui-state-highlight" : "") + (H.getTime() === G.getTime() ?
          " ui-state-active" : "") + (j ? " ui-priority-secondary" : "") +
         "' href='#'>" + H.getDate() + "</a>") + "</td>", H.setDate(H.getDate() +
         1), H = this._daylightSavingAdjust(H);
       M += E + "</tr>"
      }
      Z++, Z > 11 && (Z = 0, et++), M += "</tbody></table>" + (Q ? "</div>" +
       (K[0] > 0 && T === K[1] - 1 ?
        "<div class='ui-datepicker-row-break'></div>" : "") : ""), k += M
     }
     _ += k
    }
    return _ += l, e._keyEvent = !1, _
   },
   _generateMonthYearHeader: function(e, t, i, s, n, a, o, r) {
    var h, l, u, d, c, p, f, m, g = this._get(e, "changeMonth"),
     v = this._get(e, "changeYear"),
     y = this._get(e, "showMonthAfterYear"),
     b = "<div class='ui-datepicker-title'>",
     _ = "";
    if (a || !g) _ += "<span class='ui-datepicker-month'>" + o[t] +
     "</span>";
    else {
     for (h = s && s.getFullYear() === i, l = n && n.getFullYear() === i, _ +=
      "<select class='ui-datepicker-month' data-handler='selectMonth' data-event='change'>",
      u = 0; 12 > u; u++)(!h || u >= s.getMonth()) && (!l || n.getMonth() >=
      u) && (_ += "<option value='" + u + "'" + (u === t ?
      " selected='selected'" : "") + ">" + r[u] + "</option>");
     _ += "</select>"
    }
    if (y || (b += _ + (!a && g && v ? "" : "&#xa0;")), !e.yearshtml)
     if (e.yearshtml = "", a || !v) b += "<span class='ui-datepicker-year'>" +
      i + "</span>";
     else {
      for (d = this._get(e, "yearRange").split(":"), c = (new Date).getFullYear(),
       p = function(e) {
        var t = e.match(/c[+\-].*/) ? i + parseInt(e.substring(1), 10) : e.match(
         /[+\-].*/) ? c + parseInt(e, 10) : parseInt(e, 10);
        return isNaN(t) ? c : t
       }, f = p(d[0]), m = Math.max(f, p(d[1] || "")), f = s ? Math.max(f, s
        .getFullYear()) : f, m = n ? Math.min(m, n.getFullYear()) : m, e.yearshtml +=
       "<select class='ui-datepicker-year' data-handler='selectYear' data-event='change'>"; m >=
       f; f++) e.yearshtml += "<option value='" + f + "'" + (f === i ?
       " selected='selected'" : "") + ">" + f + "</option>";
      e.yearshtml += "</select>", b += e.yearshtml, e.yearshtml = null
     }
    return b += this._get(e, "yearSuffix"), y && (b += (!a && g && v ? "" :
     "&#xa0;") + _), b += "</div>"
   },
   _adjustInstDate: function(e, t, i) {
    var s = e.drawYear + ("Y" === i ? t : 0),
     n = e.drawMonth + ("M" === i ? t : 0),
     a = Math.min(e.selectedDay, this._getDaysInMonth(s, n)) + ("D" === i ?
      t : 0),
     o = this._restrictMinMax(e, this._daylightSavingAdjust(new Date(s, n, a)));
    e.selectedDay = o.getDate(), e.drawMonth = e.selectedMonth = o.getMonth(),
     e.drawYear = e.selectedYear = o.getFullYear(), ("M" === i || "Y" === i) &&
     this._notifyChange(e)
   },
   _restrictMinMax: function(e, t) {
    var i = this._getMinMaxDate(e, "min"),
     s = this._getMinMaxDate(e, "max"),
     n = i && i > t ? i : t;
    return s && n > s ? s : n
   },
   _notifyChange: function(e) {
    var t = this._get(e, "onChangeMonthYear");
    t && t.apply(e.input ? e.input[0] : null, [e.selectedYear, e.selectedMonth +
     1, e
    ])
   },
   _getNumberOfMonths: function(e) {
    var t = this._get(e, "numberOfMonths");
    return null == t ? [1, 1] : "number" == typeof t ? [1, t] : t
   },
   _getMinMaxDate: function(e, t) {
    return this._determineDate(e, this._get(e, t + "Date"), null)
   },
   _getDaysInMonth: function(e, t) {
    return 32 - this._daylightSavingAdjust(new Date(e, t, 32)).getDate()
   },
   _getFirstDayOfMonth: function(e, t) {
    return new Date(e, t, 1).getDay()
   },
   _canAdjustMonth: function(e, t, i, s) {
    var n = this._getNumberOfMonths(e),
     a = this._daylightSavingAdjust(new Date(i, s + (0 > t ? t : n[0] * n[1]),
      1));
    return 0 > t && a.setDate(this._getDaysInMonth(a.getFullYear(), a.getMonth())),
     this._isInRange(e, a)
   },
   _isInRange: function(e, t) {
    var i, s, n = this._getMinMaxDate(e, "min"),
     a = this._getMinMaxDate(e, "max"),
     o = null,
     r = null,
     h = this._get(e, "yearRange");
    return h && (i = h.split(":"), s = (new Date).getFullYear(), o =
      parseInt(i[0], 10), r = parseInt(i[1], 10), i[0].match(/[+\-].*/) && (
       o += s), i[1].match(/[+\-].*/) && (r += s)), (!n || t.getTime() >= n.getTime()) &&
     (!a || t.getTime() <= a.getTime()) && (!o || t.getFullYear() >= o) && (!
      r || r >= t.getFullYear())
   },
   _getFormatConfig: function(e) {
    var t = this._get(e, "shortYearCutoff");
    return t = "string" != typeof t ? t : (new Date).getFullYear() % 100 +
     parseInt(t, 10), {
      shortYearCutoff: t,
      dayNamesShort: this._get(e, "dayNamesShort"),
      dayNames: this._get(e, "dayNames"),
      monthNamesShort: this._get(e, "monthNamesShort"),
      monthNames: this._get(e, "monthNames")
     }
   },
   _formatDate: function(e, t, i, s) {
    t || (e.currentDay = e.selectedDay, e.currentMonth = e.selectedMonth, e.currentYear =
     e.selectedYear);
    var n = t ? "object" == typeof t ? t : this._daylightSavingAdjust(new Date(
     s, i, t)) : this._daylightSavingAdjust(new Date(e.currentYear, e.currentMonth,
     e.currentDay));
    return this.formatDate(this._get(e, "dateFormat"), n, this._getFormatConfig(
     e))
   }
  }), e.fn.datepicker = function(t) {
   if (!this.length) return this;
   e.datepicker.initialized || (e(document).mousedown(e.datepicker._checkExternalClick),
     e.datepicker.initialized = !0), 0 === e("#" + e.datepicker._mainDivId).length &&
    e("body").append(e.datepicker.dpDiv);
   var i = Array.prototype.slice.call(arguments, 1);
   return "string" != typeof t || "isDisabled" !== t && "getDate" !== t &&
    "widget" !== t ? "option" === t && 2 === arguments.length && "string" ==
    typeof arguments[1] ? e.datepicker["_" + t + "Datepicker"].apply(e.datepicker, [
     this[0]
    ].concat(i)) : this.each(function() {
     "string" == typeof t ? e.datepicker["_" + t + "Datepicker"].apply(e.datepicker, [
      this
     ].concat(i)) : e.datepicker._attachDatepicker(this, t)
    }) : e.datepicker["_" + t + "Datepicker"].apply(e.datepicker, [this[0]].concat(
     i))
  }, e.datepicker = new n, e.datepicker.initialized = !1, e.datepicker.uuid =
  (new Date).getTime(), e.datepicker.version = "1.11.2", e.datepicker, e.widget(
   "ui.draggable", e.ui.mouse, {
    version: "1.11.2",
    widgetEventPrefix: "drag",
    options: {
     addClasses: !0,
     appendTo: "parent",
     axis: !1,
     connectToSortable: !1,
     containment: !1,
     cursor: "auto",
     cursorAt: !1,
     grid: !1,
     handle: !1,
     helper: "original",
     iframeFix: !1,
     opacity: !1,
     refreshPositions: !1,
     revert: !1,
     revertDuration: 500,
     scope: "default",
     scroll: !0,
     scrollSensitivity: 20,
     scrollSpeed: 20,
     snap: !1,
     snapMode: "both",
     snapTolerance: 20,
     stack: !1,
     zIndex: !1,
     drag: null,
     start: null,
     stop: null
    },
    _create: function() {
     "original" === this.options.helper && this._setPositionRelative(), this.options
      .addClasses && this.element.addClass("ui-draggable"), this.options.disabled &&
      this.element.addClass("ui-draggable-disabled"), this._setHandleClassName(),
      this._mouseInit()
    },
    _setOption: function(e, t) {
     this._super(e, t), "handle" === e && (this._removeHandleClassName(),
      this._setHandleClassName())
    },
    _destroy: function() {
     return (this.helper || this.element).is(".ui-draggable-dragging") ? (
      this.destroyOnClear = !0, void 0) : (this.element.removeClass(
       "ui-draggable ui-draggable-dragging ui-draggable-disabled"), this._removeHandleClassName(),
      this._mouseDestroy(), void 0)
    },
    _mouseCapture: function(t) {
     var i = this.options;
     return this._blurActiveElement(t), this.helper || i.disabled || e(t.target)
      .closest(".ui-resizable-handle").length > 0 ? !1 : (this.handle = this._getHandle(
       t), this.handle ? (this._blockFrames(i.iframeFix === !0 ? "iframe" :
       i.iframeFix), !0) : !1)
    },
    _blockFrames: function(t) {
     this.iframeBlocks = this.document.find(t).map(function() {
      var t = e(this);
      return e("<div>").css("position", "absolute").appendTo(t.parent()).outerWidth(
       t.outerWidth()).outerHeight(t.outerHeight()).offset(t.offset())[0]
     })
    },
    _unblockFrames: function() {
     this.iframeBlocks && (this.iframeBlocks.remove(), delete this.iframeBlocks)
    },
    _blurActiveElement: function(t) {
     var i = this.document[0];
     if (this.handleElement.is(t.target)) try {
      i.activeElement && "body" !== i.activeElement.nodeName.toLowerCase() &&
       e(i.activeElement).blur()
     } catch (s) {}
    },
    _mouseStart: function(t) {
     var i = this.options;
     return this.helper = this._createHelper(t), this.helper.addClass(
       "ui-draggable-dragging"), this._cacheHelperProportions(), e.ui.ddmanager &&
      (e.ui.ddmanager.current = this), this._cacheMargins(), this.cssPosition =
      this.helper.css("position"), this.scrollParent = this.helper.scrollParent(!
       0), this.offsetParent = this.helper.offsetParent(), this.hasFixedAncestor =
      this.helper.parents().filter(function() {
       return "fixed" === e(this).css("position")
      }).length > 0, this.positionAbs = this.element.offset(), this._refreshOffsets(
       t), this.originalPosition = this.position = this._generatePosition(t, !
       1), this.originalPageX = t.pageX, this.originalPageY = t.pageY, i.cursorAt &&
      this._adjustOffsetFromHelper(i.cursorAt), this._setContainment(), this._trigger(
       "start", t) === !1 ? (this._clear(), !1) : (this._cacheHelperProportions(),
       e.ui.ddmanager && !i.dropBehaviour && e.ui.ddmanager.prepareOffsets(
        this, t), this._normalizeRightBottom(), this._mouseDrag(t, !0), e.ui.ddmanager &&
       e.ui.ddmanager.dragStart(this, t), !0)
    },
    _refreshOffsets: function(e) {
     this.offset = {
      top: this.positionAbs.top - this.margins.top,
      left: this.positionAbs.left - this.margins.left,
      scroll: !1,
      parent: this._getParentOffset(),
      relative: this._getRelativeOffset()
     }, this.offset.click = {
      left: e.pageX - this.offset.left,
      top: e.pageY - this.offset.top
     }
    },
    _mouseDrag: function(t, i) {
     if (this.hasFixedAncestor && (this.offset.parent = this._getParentOffset()),
      this.position = this._generatePosition(t, !0), this.positionAbs = this._convertPositionTo(
       "absolute"), !i) {
      var s = this._uiHash();
      if (this._trigger("drag", t, s) === !1) return this._mouseUp({}), !1;
      this.position = s.position
     }
     return this.helper[0].style.left = this.position.left + "px", this.helper[
       0].style.top = this.position.top + "px", e.ui.ddmanager && e.ui.ddmanager
      .drag(this, t), !1
    },
    _mouseStop: function(t) {
     var i = this,
      s = !1;
     return e.ui.ddmanager && !this.options.dropBehaviour && (s = e.ui.ddmanager
       .drop(this, t)), this.dropped && (s = this.dropped, this.dropped = !1),
      "invalid" === this.options.revert && !s || "valid" === this.options.revert &&
      s || this.options.revert === !0 || e.isFunction(this.options.revert) &&
      this.options.revert.call(this.element, s) ? e(this.helper).animate(this
       .originalPosition, parseInt(this.options.revertDuration, 10),
       function() {
        i._trigger("stop", t) !== !1 && i._clear()
       }) : this._trigger("stop", t) !== !1 && this._clear(), !1
    },
    _mouseUp: function(t) {
     return this._unblockFrames(), e.ui.ddmanager && e.ui.ddmanager.dragStop(
       this, t), this.handleElement.is(t.target) && this.element.focus(), e.ui
      .mouse.prototype._mouseUp.call(this, t)
    },
    cancel: function() {
     return this.helper.is(".ui-draggable-dragging") ? this._mouseUp({}) :
      this._clear(), this
    },
    _getHandle: function(t) {
     return this.options.handle ? !!e(t.target).closest(this.element.find(
      this.options.handle)).length : !0
    },
    _setHandleClassName: function() {
     this.handleElement = this.options.handle ? this.element.find(this.options
      .handle) : this.element, this.handleElement.addClass(
      "ui-draggable-handle")
    },
    _removeHandleClassName: function() {
     this.handleElement.removeClass("ui-draggable-handle")
    },
    _createHelper: function(t) {
     var i = this.options,
      s = e.isFunction(i.helper),
      n = s ? e(i.helper.apply(this.element[0], [t])) : "clone" === i.helper ?
      this.element.clone().removeAttr("id") : this.element;
     return n.parents("body").length || n.appendTo("parent" === i.appendTo ?
       this.element[0].parentNode : i.appendTo), s && n[0] === this.element[0] &&
      this._setPositionRelative(), n[0] === this.element[0] ||
      /(fixed|absolute)/.test(n.css("position")) || n.css("position",
       "absolute"), n
    },
    _setPositionRelative: function() {
     /^(?:r|a|f)/.test(this.element.css("position")) || (this.element[0].style
      .position = "relative")
    },
    _adjustOffsetFromHelper: function(t) {
     "string" == typeof t && (t = t.split(" ")), e.isArray(t) && (t = {
       left: +t[0],
       top: +t[1] || 0
      }), "left" in t && (this.offset.click.left = t.left + this.margins.left),
      "right" in t && (this.offset.click.left = this.helperProportions.width -
       t.right + this.margins.left), "top" in t && (this.offset.click.top = t
       .top + this.margins.top), "bottom" in t && (this.offset.click.top =
       this.helperProportions.height - t.bottom + this.margins.top)
    },
    _isRootNode: function(e) {
     return /(html|body)/i.test(e.tagName) || e === this.document[0]
    },
    _getParentOffset: function() {
     var t = this.offsetParent.offset(),
      i = this.document[0];
     return "absolute" === this.cssPosition && this.scrollParent[0] !== i &&
      e.contains(this.scrollParent[0], this.offsetParent[0]) && (t.left +=
       this.scrollParent.scrollLeft(), t.top += this.scrollParent.scrollTop()
      ), this._isRootNode(this.offsetParent[0]) && (t = {
       top: 0,
       left: 0
      }), {
       top: t.top + (parseInt(this.offsetParent.css("borderTopWidth"), 10) ||
        0),
       left: t.left + (parseInt(this.offsetParent.css("borderLeftWidth"), 10) ||
        0)
      }
    },
    _getRelativeOffset: function() {
     if ("relative" !== this.cssPosition) return {
      top: 0,
      left: 0
     };
     var e = this.element.position(),
      t = this._isRootNode(this.scrollParent[0]);
     return {
      top: e.top - (parseInt(this.helper.css("top"), 10) || 0) + (t ? 0 :
       this.scrollParent.scrollTop()),
      left: e.left - (parseInt(this.helper.css("left"), 10) || 0) + (t ? 0 :
       this.scrollParent.scrollLeft())
     }
    },
    _cacheMargins: function() {
     this.margins = {
      left: parseInt(this.element.css("marginLeft"), 10) || 0,
      top: parseInt(this.element.css("marginTop"), 10) || 0,
      right: parseInt(this.element.css("marginRight"), 10) || 0,
      bottom: parseInt(this.element.css("marginBottom"), 10) || 0
     }
    },
    _cacheHelperProportions: function() {
     this.helperProportions = {
      width: this.helper.outerWidth(),
      height: this.helper.outerHeight()
     }
    },
    _setContainment: function() {
     var t, i, s, n = this.options,
      a = this.document[0];
     return this.relativeContainer = null, n.containment ? "window" === n.containment ?
      (this.containment = [e(window).scrollLeft() - this.offset.relative.left -
       this.offset.parent.left, e(window).scrollTop() - this.offset.relative
       .top - this.offset.parent.top, e(window).scrollLeft() + e(window).width() -
       this.helperProportions.width - this.margins.left, e(window).scrollTop() +
       (e(window).height() || a.body.parentNode.scrollHeight) - this.helperProportions
       .height - this.margins.top
      ], void 0) : "document" === n.containment ? (this.containment = [0, 0,
       e(a).width() - this.helperProportions.width - this.margins.left, (e(a)
        .height() || a.body.parentNode.scrollHeight) - this.helperProportions
       .height - this.margins.top
      ], void 0) : n.containment.constructor === Array ? (this.containment =
       n.containment, void 0) : ("parent" === n.containment && (n.containment =
       this.helper[0].parentNode), i = e(n.containment), s = i[0], s && (t =
       /(scroll|auto)/.test(i.css("overflow")), this.containment = [(
         parseInt(i.css("borderLeftWidth"), 10) || 0) + (parseInt(i.css(
         "paddingLeft"), 10) || 0), (parseInt(i.css("borderTopWidth"), 10) ||
         0) + (parseInt(i.css("paddingTop"), 10) || 0), (t ? Math.max(s.scrollWidth,
         s.offsetWidth) : s.offsetWidth) - (parseInt(i.css(
         "borderRightWidth"), 10) || 0) - (parseInt(i.css("paddingRight"),
         10) || 0) - this.helperProportions.width - this.margins.left - this
        .margins.right, (t ? Math.max(s.scrollHeight, s.offsetHeight) : s.offsetHeight) -
        (parseInt(i.css("borderBottomWidth"), 10) || 0) - (parseInt(i.css(
         "paddingBottom"), 10) || 0) - this.helperProportions.height - this.margins
        .top - this.margins.bottom
       ], this.relativeContainer = i), void 0) : (this.containment = null,
       void 0)
    },
    _convertPositionTo: function(e, t) {
     t || (t = this.position);
     var i = "absolute" === e ? 1 : -1,
      s = this._isRootNode(this.scrollParent[0]);
     return {
      top: t.top + this.offset.relative.top * i + this.offset.parent.top * i -
       ("fixed" === this.cssPosition ? -this.offset.scroll.top : s ? 0 : this
        .offset.scroll.top) * i,
      left: t.left + this.offset.relative.left * i + this.offset.parent.left *
       i - ("fixed" === this.cssPosition ? -this.offset.scroll.left : s ? 0 :
        this.offset.scroll.left) * i
     }
    },
    _generatePosition: function(e, t) {
     var i, s, n, a, o = this.options,
      r = this._isRootNode(this.scrollParent[0]),
      h = e.pageX,
      l = e.pageY;
     return r && this.offset.scroll || (this.offset.scroll = {
      top: this.scrollParent.scrollTop(),
      left: this.scrollParent.scrollLeft()
     }), t && (this.containment && (this.relativeContainer ? (s = this.relativeContainer
        .offset(), i = [this.containment[0] + s.left, this.containment[1] +
         s.top, this.containment[2] + s.left, this.containment[3] + s.top
        ]) : i = this.containment, e.pageX - this.offset.click.left < i[0] &&
       (h = i[0] + this.offset.click.left), e.pageY - this.offset.click.top <
       i[1] && (l = i[1] + this.offset.click.top), e.pageX - this.offset.click
       .left > i[2] && (h = i[2] + this.offset.click.left), e.pageY - this.offset
       .click.top > i[3] && (l = i[3] + this.offset.click.top)), o.grid && (
       n = o.grid[1] ? this.originalPageY + Math.round((l - this.originalPageY) /
        o.grid[1]) * o.grid[1] : this.originalPageY, l = i ? n - this.offset
       .click.top >= i[1] || n - this.offset.click.top > i[3] ? n : n - this
       .offset.click.top >= i[1] ? n - o.grid[1] : n + o.grid[1] : n, a = o.grid[
        0] ? this.originalPageX + Math.round((h - this.originalPageX) / o.grid[
        0]) * o.grid[0] : this.originalPageX, h = i ? a - this.offset.click.left >=
       i[0] || a - this.offset.click.left > i[2] ? a : a - this.offset.click
       .left >= i[0] ? a - o.grid[0] : a + o.grid[0] : a), "y" === o.axis &&
      (h = this.originalPageX), "x" === o.axis && (l = this.originalPageY)), {
      top: l - this.offset.click.top - this.offset.relative.top - this.offset
       .parent.top + ("fixed" === this.cssPosition ? -this.offset.scroll.top :
        r ? 0 : this.offset.scroll.top),
      left: h - this.offset.click.left - this.offset.relative.left - this.offset
       .parent.left + ("fixed" === this.cssPosition ? -this.offset.scroll.left :
        r ? 0 : this.offset.scroll.left)
     }
    },
    _clear: function() {
     this.helper.removeClass("ui-draggable-dragging"), this.helper[0] ===
      this.element[0] || this.cancelHelperRemoval || this.helper.remove(),
      this.helper = null, this.cancelHelperRemoval = !1, this.destroyOnClear &&
      this.destroy()
    },
    _normalizeRightBottom: function() {
     "y" !== this.options.axis && "auto" !== this.helper.css("right") && (
      this.helper.width(this.helper.width()), this.helper.css("right",
       "auto")), "x" !== this.options.axis && "auto" !== this.helper.css(
      "bottom") && (this.helper.height(this.helper.height()), this.helper.css(
      "bottom", "auto"))
    },
    _trigger: function(t, i, s) {
     return s = s || this._uiHash(), e.ui.plugin.call(this, t, [i, s, this], !
       0), /^(drag|start|stop)/.test(t) && (this.positionAbs = this._convertPositionTo(
       "absolute"), s.offset = this.positionAbs), e.Widget.prototype._trigger
      .call(this, t, i, s)
    },
    plugins: {},
    _uiHash: function() {
     return {
      helper: this.helper,
      position: this.position,
      originalPosition: this.originalPosition,
      offset: this.positionAbs
     }
    }
   }), e.ui.plugin.add("draggable", "connectToSortable", {
   start: function(t, i, s) {
    var n = e.extend({}, i, {
     item: s.element
    });
    s.sortables = [], e(s.options.connectToSortable).each(function() {
     var i = e(this).sortable("instance");
     i && !i.options.disabled && (s.sortables.push(i), i.refreshPositions(),
      i._trigger("activate", t, n))
    })
   },
   stop: function(t, i, s) {
    var n = e.extend({}, i, {
     item: s.element
    });
    s.cancelHelperRemoval = !1, e.each(s.sortables, function() {
     var e = this;
     e.isOver ? (e.isOver = 0, s.cancelHelperRemoval = !0, e.cancelHelperRemoval = !
      1, e._storedCSS = {
       position: e.placeholder.css("position"),
       top: e.placeholder.css("top"),
       left: e.placeholder.css("left")
      }, e._mouseStop(t), e.options.helper = e.options._helper) : (e.cancelHelperRemoval = !
      0, e._trigger("deactivate", t, n))
    })
   },
   drag: function(t, i, s) {
    e.each(s.sortables, function() {
     var n = !1,
      a = this;
     a.positionAbs = s.positionAbs, a.helperProportions = s.helperProportions,
      a.offset.click = s.offset.click, a._intersectsWith(a.containerCache) &&
      (n = !0, e.each(s.sortables, function() {
       return this.positionAbs = s.positionAbs, this.helperProportions =
        s.helperProportions, this.offset.click = s.offset.click, this !==
        a && this._intersectsWith(this.containerCache) && e.contains(a.element[
         0], this.element[0]) && (n = !1), n
      })), n ? (a.isOver || (a.isOver = 1, a.currentItem = i.helper.appendTo(
         a.element).data("ui-sortable-item", !0), a.options._helper = a.options
        .helper, a.options.helper = function() {
         return i.helper[0]
        }, t.target = a.currentItem[0], a._mouseCapture(t, !0), a._mouseStart(
         t, !0, !0), a.offset.click.top = s.offset.click.top, a.offset.click
        .left = s.offset.click.left, a.offset.parent.left -= s.offset.parent
        .left - a.offset.parent.left, a.offset.parent.top -= s.offset.parent
        .top - a.offset.parent.top, s._trigger("toSortable", t), s.dropped =
        a.element, e.each(s.sortables, function() {
         this.refreshPositions()
        }), s.currentItem = s.element, a.fromOutside = s), a.currentItem &&
       (a._mouseDrag(t), i.position = a.position)) : a.isOver && (a.isOver =
       0, a.cancelHelperRemoval = !0, a.options._revert = a.options.revert,
       a.options.revert = !1, a._trigger("out", t, a._uiHash(a)), a._mouseStop(
        t, !0), a.options.revert = a.options._revert, a.options.helper = a
       .options._helper, a.placeholder && a.placeholder.remove(), s._refreshOffsets(
        t), i.position = s._generatePosition(t, !0), s._trigger(
        "fromSortable", t), s.dropped = !1, e.each(s.sortables, function() {
        this.refreshPositions()
       }))
    })
   }
  }), e.ui.plugin.add("draggable", "cursor", {
   start: function(t, i, s) {
    var n = e("body"),
     a = s.options;
    n.css("cursor") && (a._cursor = n.css("cursor")), n.css("cursor", a.cursor)
   },
   stop: function(t, i, s) {
    var n = s.options;
    n._cursor && e("body").css("cursor", n._cursor)
   }
  }), e.ui.plugin.add("draggable", "opacity", {
   start: function(t, i, s) {
    var n = e(i.helper),
     a = s.options;
    n.css("opacity") && (a._opacity = n.css("opacity")), n.css("opacity", a.opacity)
   },
   stop: function(t, i, s) {
    var n = s.options;
    n._opacity && e(i.helper).css("opacity", n._opacity)
   }
  }), e.ui.plugin.add("draggable", "scroll", {
   start: function(e, t, i) {
    i.scrollParentNotHidden || (i.scrollParentNotHidden = i.helper.scrollParent(!
     1)), i.scrollParentNotHidden[0] !== i.document[0] && "HTML" !== i.scrollParentNotHidden[
     0].tagName && (i.overflowOffset = i.scrollParentNotHidden.offset())
   },
   drag: function(t, i, s) {
    var n = s.options,
     a = !1,
     o = s.scrollParentNotHidden[0],
     r = s.document[0];
    o !== r && "HTML" !== o.tagName ? (n.axis && "x" === n.axis || (s.overflowOffset
      .top + o.offsetHeight - t.pageY < n.scrollSensitivity ? o.scrollTop =
      a = o.scrollTop + n.scrollSpeed : t.pageY - s.overflowOffset.top < n.scrollSensitivity &&
      (o.scrollTop = a = o.scrollTop - n.scrollSpeed)), n.axis && "y" === n
     .axis || (s.overflowOffset.left + o.offsetWidth - t.pageX < n.scrollSensitivity ?
      o.scrollLeft = a = o.scrollLeft + n.scrollSpeed : t.pageX - s.overflowOffset
      .left < n.scrollSensitivity && (o.scrollLeft = a = o.scrollLeft - n.scrollSpeed)
     )) : (n.axis && "x" === n.axis || (t.pageY - e(r).scrollTop() < n.scrollSensitivity ?
     a = e(r).scrollTop(e(r).scrollTop() - n.scrollSpeed) : e(window).height() -
     (t.pageY - e(r).scrollTop()) < n.scrollSensitivity && (a = e(r).scrollTop(
      e(r).scrollTop() + n.scrollSpeed))), n.axis && "y" === n.axis || (t.pageX -
     e(r).scrollLeft() < n.scrollSensitivity ? a = e(r).scrollLeft(e(r).scrollLeft() -
      n.scrollSpeed) : e(window).width() - (t.pageX - e(r).scrollLeft()) <
     n.scrollSensitivity && (a = e(r).scrollLeft(e(r).scrollLeft() + n.scrollSpeed))
    )), a !== !1 && e.ui.ddmanager && !n.dropBehaviour && e.ui.ddmanager.prepareOffsets(
     s, t)
   }
  }), e.ui.plugin.add("draggable", "snap", {
   start: function(t, i, s) {
    var n = s.options;
    s.snapElements = [], e(n.snap.constructor !== String ? n.snap.items ||
     ":data(ui-draggable)" : n.snap).each(function() {
     var t = e(this),
      i = t.offset();
     this !== s.element[0] && s.snapElements.push({
      item: this,
      width: t.outerWidth(),
      height: t.outerHeight(),
      top: i.top,
      left: i.left
     })
    })
   },
   drag: function(t, i, s) {
    var n, a, o, r, h, l, u, d, c, p, f = s.options,
     m = f.snapTolerance,
     g = i.offset.left,
     v = g + s.helperProportions.width,
     y = i.offset.top,
     b = y + s.helperProportions.height;
    for (c = s.snapElements.length - 1; c >= 0; c--) h = s.snapElements[c].left -
     s.margins.left, l = h + s.snapElements[c].width, u = s.snapElements[c].top -
     s.margins.top, d = u + s.snapElements[c].height, h - m > v || g > l + m ||
     u - m > b || y > d + m || !e.contains(s.snapElements[c].item.ownerDocument,
      s.snapElements[c].item) ? (s.snapElements[c].snapping && s.options.snap
      .release && s.options.snap.release.call(s.element, t, e.extend(s._uiHash(), {
       snapItem: s.snapElements[c].item
      })), s.snapElements[c].snapping = !1) : ("inner" !== f.snapMode && (n =
       m >= Math.abs(u - b), a = m >= Math.abs(d - y), o = m >= Math.abs(h -
        v), r = m >= Math.abs(l - g), n && (i.position.top = s._convertPositionTo(
        "relative", {
         top: u - s.helperProportions.height,
         left: 0
        }).top), a && (i.position.top = s._convertPositionTo("relative", {
        top: d,
        left: 0
       }).top), o && (i.position.left = s._convertPositionTo("relative", {
        top: 0,
        left: h - s.helperProportions.width
       }).left), r && (i.position.left = s._convertPositionTo("relative", {
        top: 0,
        left: l
       }).left)), p = n || a || o || r, "outer" !== f.snapMode && (n = m >=
       Math.abs(u - y), a = m >= Math.abs(d - b), o = m >= Math.abs(h - g),
       r = m >= Math.abs(l - v), n && (i.position.top = s._convertPositionTo(
        "relative", {
         top: u,
         left: 0
        }).top), a && (i.position.top = s._convertPositionTo("relative", {
        top: d - s.helperProportions.height,
        left: 0
       }).top), o && (i.position.left = s._convertPositionTo("relative", {
        top: 0,
        left: h
       }).left), r && (i.position.left = s._convertPositionTo("relative", {
        top: 0,
        left: l - s.helperProportions.width
       }).left)), !s.snapElements[c].snapping && (n || a || o || r || p) &&
      s.options.snap.snap && s.options.snap.snap.call(s.element, t, e.extend(
       s._uiHash(), {
        snapItem: s.snapElements[c].item
       })), s.snapElements[c].snapping = n || a || o || r || p)
   }
  }), e.ui.plugin.add("draggable", "stack", {
   start: function(t, i, s) {
    var n, a = s.options,
     o = e.makeArray(e(a.stack)).sort(function(t, i) {
      return (parseInt(e(t).css("zIndex"), 10) || 0) - (parseInt(e(i).css(
       "zIndex"), 10) || 0)
     });
    o.length && (n = parseInt(e(o[0]).css("zIndex"), 10) || 0, e(o).each(
     function(t) {
      e(this).css("zIndex", n + t)
     }), this.css("zIndex", n + o.length))
   }
  }), e.ui.plugin.add("draggable", "zIndex", {
   start: function(t, i, s) {
    var n = e(i.helper),
     a = s.options;
    n.css("zIndex") && (a._zIndex = n.css("zIndex")), n.css("zIndex", a.zIndex)
   },
   stop: function(t, i, s) {
    var n = s.options;
    n._zIndex && e(i.helper).css("zIndex", n._zIndex)
   }
  }), e.ui.draggable, e.widget("ui.resizable", e.ui.mouse, {
   version: "1.11.2",
   widgetEventPrefix: "resize",
   options: {
    alsoResize: !1,
    animate: !1,
    animateDuration: "slow",
    animateEasing: "swing",
    aspectRatio: !1,
    autoHide: !1,
    containment: !1,
    ghost: !1,
    grid: !1,
    handles: "e,s,se",
    helper: !1,
    maxHeight: null,
    maxWidth: null,
    minHeight: 10,
    minWidth: 10,
    zIndex: 90,
    resize: null,
    start: null,
    stop: null
   },
   _num: function(e) {
    return parseInt(e, 10) || 0
   },
   _isNumber: function(e) {
    return !isNaN(parseInt(e, 10))
   },
   _hasScroll: function(t, i) {
    if ("hidden" === e(t).css("overflow")) return !1;
    var s = i && "left" === i ? "scrollLeft" : "scrollTop",
     n = !1;
    return t[s] > 0 ? !0 : (t[s] = 1, n = t[s] > 0, t[s] = 0, n)
   },
   _create: function() {
    var t, i, s, n, a, o = this,
     r = this.options;
    if (this.element.addClass("ui-resizable"), e.extend(this, {
      _aspectRatio: !!r.aspectRatio,
      aspectRatio: r.aspectRatio,
      originalElement: this.element,
      _proportionallyResizeElements: [],
      _helper: r.helper || r.ghost || r.animate ? r.helper ||
       "ui-resizable-helper" : null
     }), this.element[0].nodeName.match(
      /canvas|textarea|input|select|button|img/i) && (this.element.wrap(e(
       "<div class='ui-wrapper' style='overflow: hidden;'></div>").css({
       position: this.element.css("position"),
       width: this.element.outerWidth(),
       height: this.element.outerHeight(),
       top: this.element.css("top"),
       left: this.element.css("left")
      })), this.element = this.element.parent().data("ui-resizable", this.element
       .resizable("instance")), this.elementIsWrapper = !0, this.element.css({
       marginLeft: this.originalElement.css("marginLeft"),
       marginTop: this.originalElement.css("marginTop"),
       marginRight: this.originalElement.css("marginRight"),
       marginBottom: this.originalElement.css("marginBottom")
      }), this.originalElement.css({
       marginLeft: 0,
       marginTop: 0,
       marginRight: 0,
       marginBottom: 0
      }), this.originalResizeStyle = this.originalElement.css("resize"),
      this.originalElement.css("resize", "none"), this._proportionallyResizeElements
      .push(this.originalElement.css({
       position: "static",
       zoom: 1,
       display: "block"
      })), this.originalElement.css({
       margin: this.originalElement.css("margin")
      }), this._proportionallyResize()), this.handles = r.handles || (e(
      ".ui-resizable-handle", this.element).length ? {
      n: ".ui-resizable-n",
      e: ".ui-resizable-e",
      s: ".ui-resizable-s",
      w: ".ui-resizable-w",
      se: ".ui-resizable-se",
      sw: ".ui-resizable-sw",
      ne: ".ui-resizable-ne",
      nw: ".ui-resizable-nw"
     } : "e,s,se"), this.handles.constructor === String)
     for ("all" === this.handles && (this.handles = "n,e,s,w,se,sw,ne,nw"),
      t = this.handles.split(","), this.handles = {}, i = 0; t.length > i; i++
     ) s = e.trim(t[i]), a = "ui-resizable-" + s, n = e(
       "<div class='ui-resizable-handle " + a + "'></div>"), n.css({
       zIndex: r.zIndex
      }), "se" === s && n.addClass("ui-icon ui-icon-gripsmall-diagonal-se"),
      this.handles[s] = ".ui-resizable-" + s, this.element.append(n);
    this._renderAxis = function(t) {
      var i, s, n, a;
      t = t || this.element;
      for (i in this.handles) this.handles[i].constructor === String && (
       this.handles[i] = this.element.children(this.handles[i]).first().show()
      ), this.elementIsWrapper && this.originalElement[0].nodeName.match(
       /textarea|input|select|button/i) && (s = e(this.handles[i], this.element),
       a = /sw|ne|nw|se|n|s/.test(i) ? s.outerHeight() : s.outerWidth(), n = [
        "padding", /ne|nw|n/.test(i) ? "Top" : /se|sw|s/.test(i) ? "Bottom" :
        /^e$/.test(i) ? "Right" : "Left"
       ].join(""), t.css(n, a), this._proportionallyResize()), e(this.handles[
       i]).length
     }, this._renderAxis(this.element), this._handles = e(
      ".ui-resizable-handle", this.element).disableSelection(), this._handles
     .mouseover(function() {
      o.resizing || (this.className && (n = this.className.match(
        /ui-resizable-(se|sw|ne|nw|n|e|s|w)/i)), o.axis = n && n[1] ? n[1] :
       "se")
     }), r.autoHide && (this._handles.hide(), e(this.element).addClass(
      "ui-resizable-autohide").mouseenter(function() {
      r.disabled || (e(this).removeClass("ui-resizable-autohide"), o._handles
       .show())
     }).mouseleave(function() {
      r.disabled || o.resizing || (e(this).addClass(
       "ui-resizable-autohide"), o._handles.hide())
     })), this._mouseInit()
   },
   _destroy: function() {
    this._mouseDestroy();
    var t, i = function(t) {
     e(t).removeClass(
      "ui-resizable ui-resizable-disabled ui-resizable-resizing").removeData(
      "resizable").removeData("ui-resizable").unbind(".resizable").find(
      ".ui-resizable-handle").remove()
    };
    return this.elementIsWrapper && (i(this.element), t = this.element, this
     .originalElement.css({
      position: t.css("position"),
      width: t.outerWidth(),
      height: t.outerHeight(),
      top: t.css("top"),
      left: t.css("left")
     }).insertAfter(t), t.remove()), this.originalElement.css("resize",
     this.originalResizeStyle), i(this.originalElement), this
   },
   _mouseCapture: function(t) {
    var i, s, n = !1;
    for (i in this.handles) s = e(this.handles[i])[0], (s === t.target || e.contains(
     s, t.target)) && (n = !0);
    return !this.options.disabled && n
   },
   _mouseStart: function(t) {
    var i, s, n, a = this.options,
     o = this.element;
    return this.resizing = !0, this._renderProxy(), i = this._num(this.helper
      .css("left")), s = this._num(this.helper.css("top")), a.containment &&
     (i += e(a.containment).scrollLeft() || 0, s += e(a.containment).scrollTop() ||
      0), this.offset = this.helper.offset(), this.position = {
      left: i,
      top: s
     }, this.size = this._helper ? {
      width: this.helper.width(),
      height: this.helper.height()
     } : {
      width: o.width(),
      height: o.height()
     }, this.originalSize = this._helper ? {
      width: o.outerWidth(),
      height: o.outerHeight()
     } : {
      width: o.width(),
      height: o.height()
     }, this.sizeDiff = {
      width: o.outerWidth() - o.width(),
      height: o.outerHeight() - o.height()
     }, this.originalPosition = {
      left: i,
      top: s
     }, this.originalMousePosition = {
      left: t.pageX,
      top: t.pageY
     }, this.aspectRatio = "number" == typeof a.aspectRatio ? a.aspectRatio :
     this.originalSize.width / this.originalSize.height || 1, n = e(
      ".ui-resizable-" + this.axis).css("cursor"), e("body").css("cursor",
      "auto" === n ? this.axis + "-resize" : n), o.addClass(
      "ui-resizable-resizing"), this._propagate("start", t), !0
   },
   _mouseDrag: function(t) {
    var i, s, n = this.originalMousePosition,
     a = this.axis,
     o = t.pageX - n.left || 0,
     r = t.pageY - n.top || 0,
     h = this._change[a];
    return this._updatePrevProperties(), h ? (i = h.apply(this, [t, o, r]),
     this._updateVirtualBoundaries(t.shiftKey), (this._aspectRatio || t.shiftKey) &&
     (i = this._updateRatio(i, t)), i = this._respectSize(i, t), this._updateCache(
      i), this._propagate("resize", t), s = this._applyChanges(), !this._helper &&
     this._proportionallyResizeElements.length && this._proportionallyResize(),
     e.isEmptyObject(s) || (this._updatePrevProperties(), this._trigger(
      "resize", t, this.ui()), this._applyChanges()), !1) : !1
   },
   _mouseStop: function(t) {
    this.resizing = !1;
    var i, s, n, a, o, r, h, l = this.options,
     u = this;
    return this._helper && (i = this._proportionallyResizeElements, s = i.length &&
      /textarea/i.test(i[0].nodeName), n = s && this._hasScroll(i[0], "left") ?
      0 : u.sizeDiff.height, a = s ? 0 : u.sizeDiff.width, o = {
       width: u.helper.width() - a,
       height: u.helper.height() - n
      }, r = parseInt(u.element.css("left"), 10) + (u.position.left - u.originalPosition
       .left) || null, h = parseInt(u.element.css("top"), 10) + (u.position.top -
       u.originalPosition.top) || null, l.animate || this.element.css(e.extend(
       o, {
        top: h,
        left: r
       })), u.helper.height(u.size.height), u.helper.width(u.size.width),
      this._helper && !l.animate && this._proportionallyResize()), e("body")
     .css("cursor", "auto"), this.element.removeClass(
      "ui-resizable-resizing"), this._propagate("stop", t), this._helper &&
     this.helper.remove(), !1
   },
   _updatePrevProperties: function() {
    this.prevPosition = {
     top: this.position.top,
     left: this.position.left
    }, this.prevSize = {
     width: this.size.width,
     height: this.size.height
    }
   },
   _applyChanges: function() {
    var e = {};
    return this.position.top !== this.prevPosition.top && (e.top = this.position
      .top + "px"), this.position.left !== this.prevPosition.left && (e.left =
      this.position.left + "px"), this.size.width !== this.prevSize.width &&
     (e.width = this.size.width + "px"), this.size.height !== this.prevSize.height &&
     (e.height = this.size.height + "px"), this.helper.css(e), e
   },
   _updateVirtualBoundaries: function(e) {
    var t, i, s, n, a, o = this.options;
    a = {
     minWidth: this._isNumber(o.minWidth) ? o.minWidth : 0,
     maxWidth: this._isNumber(o.maxWidth) ? o.maxWidth : 1 / 0,
     minHeight: this._isNumber(o.minHeight) ? o.minHeight : 0,
     maxHeight: this._isNumber(o.maxHeight) ? o.maxHeight : 1 / 0
    }, (this._aspectRatio || e) && (t = a.minHeight * this.aspectRatio, s =
     a.minWidth / this.aspectRatio, i = a.maxHeight * this.aspectRatio, n =
     a.maxWidth / this.aspectRatio, t > a.minWidth && (a.minWidth = t), s >
     a.minHeight && (a.minHeight = s), a.maxWidth > i && (a.maxWidth = i),
     a.maxHeight > n && (a.maxHeight = n)), this._vBoundaries = a
   },
   _updateCache: function(e) {
    this.offset = this.helper.offset(), this._isNumber(e.left) && (this.position
      .left = e.left), this._isNumber(e.top) && (this.position.top = e.top),
     this._isNumber(e.height) && (this.size.height = e.height), this._isNumber(
      e.width) && (this.size.width = e.width)
   },
   _updateRatio: function(e) {
    var t = this.position,
     i = this.size,
     s = this.axis;
    return this._isNumber(e.height) ? e.width = e.height * this.aspectRatio :
     this._isNumber(e.width) && (e.height = e.width / this.aspectRatio),
     "sw" === s && (e.left = t.left + (i.width - e.width), e.top = null),
     "nw" === s && (e.top = t.top + (i.height - e.height), e.left = t.left +
      (i.width - e.width)), e
   },
   _respectSize: function(e) {
    var t = this._vBoundaries,
     i = this.axis,
     s = this._isNumber(e.width) && t.maxWidth && t.maxWidth < e.width,
     n = this._isNumber(e.height) && t.maxHeight && t.maxHeight < e.height,
     a = this._isNumber(e.width) && t.minWidth && t.minWidth > e.width,
     o = this._isNumber(e.height) && t.minHeight && t.minHeight > e.height,
     r = this.originalPosition.left + this.originalSize.width,
     h = this.position.top + this.size.height,
     l = /sw|nw|w/.test(i),
     u = /nw|ne|n/.test(i);
    return a && (e.width = t.minWidth), o && (e.height = t.minHeight), s &&
     (e.width = t.maxWidth), n && (e.height = t.maxHeight), a && l && (e.left =
      r - t.minWidth), s && l && (e.left = r - t.maxWidth), o && u && (e.top =
      h - t.minHeight), n && u && (e.top = h - t.maxHeight), e.width || e.height ||
     e.left || !e.top ? e.width || e.height || e.top || !e.left || (e.left =
      null) : e.top = null, e
   },
   _getPaddingPlusBorderDimensions: function(e) {
    for (var t = 0, i = [], s = [e.css("borderTopWidth"), e.css(
      "borderRightWidth"), e.css("borderBottomWidth"), e.css(
      "borderLeftWidth")], n = [e.css("paddingTop"), e.css("paddingRight"),
      e.css("paddingBottom"), e.css("paddingLeft")
     ]; 4 > t; t++) i[t] = parseInt(s[t], 10) || 0, i[t] += parseInt(n[t],
     10) || 0;
    return {
     height: i[0] + i[2],
     width: i[1] + i[3]
    }
   },
   _proportionallyResize: function() {
    if (this._proportionallyResizeElements.length)
     for (var e, t = 0, i = this.helper || this.element; this._proportionallyResizeElements
      .length > t; t++) e = this._proportionallyResizeElements[t], this.outerDimensions ||
      (this.outerDimensions = this._getPaddingPlusBorderDimensions(e)), e.css({
       height: i.height() - this.outerDimensions.height || 0,
       width: i.width() - this.outerDimensions.width || 0
      })
   },
   _renderProxy: function() {
    var t = this.element,
     i = this.options;
    this.elementOffset = t.offset(), this._helper ? (this.helper = this.helper ||
      e("<div style='overflow:hidden;'></div>"), this.helper.addClass(this._helper)
      .css({
       width: this.element.outerWidth() - 1,
       height: this.element.outerHeight() - 1,
       position: "absolute",
       left: this.elementOffset.left + "px",
       top: this.elementOffset.top + "px",
       zIndex: ++i.zIndex
      }), this.helper.appendTo("body").disableSelection()) : this.helper =
     this.element
   },
   _change: {
    e: function(e, t) {
     return {
      width: this.originalSize.width + t
     }
    },
    w: function(e, t) {
     var i = this.originalSize,
      s = this.originalPosition;
     return {
      left: s.left + t,
      width: i.width - t
     }
    },
    n: function(e, t, i) {
     var s = this.originalSize,
      n = this.originalPosition;
     return {
      top: n.top + i,
      height: s.height - i
     }
    },
    s: function(e, t, i) {
     return {
      height: this.originalSize.height + i
     }
    },
    se: function(t, i, s) {
     return e.extend(this._change.s.apply(this, arguments), this._change.e.apply(
      this, [t, i, s]))
    },
    sw: function(t, i, s) {
     return e.extend(this._change.s.apply(this, arguments), this._change.w.apply(
      this, [t, i, s]))
    },
    ne: function(t, i, s) {
     return e.extend(this._change.n.apply(this, arguments), this._change.e.apply(
      this, [t, i, s]))
    },
    nw: function(t, i, s) {
     return e.extend(this._change.n.apply(this, arguments), this._change.w.apply(
      this, [t, i, s]))
    }
   },
   _propagate: function(t, i) {
    e.ui.plugin.call(this, t, [i, this.ui()]), "resize" !== t && this._trigger(
     t, i, this.ui())
   },
   plugins: {},
   ui: function() {
    return {
     originalElement: this.originalElement,
     element: this.element,
     helper: this.helper,
     position: this.position,
     size: this.size,
     originalSize: this.originalSize,
     originalPosition: this.originalPosition
    }
   }
  }), e.ui.plugin.add("resizable", "animate", {
   stop: function(t) {
    var i = e(this).resizable("instance"),
     s = i.options,
     n = i._proportionallyResizeElements,
     a = n.length && /textarea/i.test(n[0].nodeName),
     o = a && i._hasScroll(n[0], "left") ? 0 : i.sizeDiff.height,
     r = a ? 0 : i.sizeDiff.width,
     h = {
      width: i.size.width - r,
      height: i.size.height - o
     },
     l = parseInt(i.element.css("left"), 10) + (i.position.left - i.originalPosition
      .left) || null,
     u = parseInt(i.element.css("top"), 10) + (i.position.top - i.originalPosition
      .top) || null;
    i.element.animate(e.extend(h, u && l ? {
     top: u,
     left: l
    } : {}), {
     duration: s.animateDuration,
     easing: s.animateEasing,
     step: function() {
      var s = {
       width: parseInt(i.element.css("width"), 10),
       height: parseInt(i.element.css("height"), 10),
       top: parseInt(i.element.css("top"), 10),
       left: parseInt(i.element.css("left"), 10)
      };
      n && n.length && e(n[0]).css({
       width: s.width,
       height: s.height
      }), i._updateCache(s), i._propagate("resize", t)
     }
    })
   }
  }), e.ui.plugin.add("resizable", "containment", {
   start: function() {
    var t, i, s, n, a, o, r, h = e(this).resizable("instance"),
     l = h.options,
     u = h.element,
     d = l.containment,
     c = d instanceof e ? d.get(0) : /parent/.test(d) ? u.parent().get(0) :
     d;
    c && (h.containerElement = e(c), /document/.test(d) || d === document ?
     (h.containerOffset = {
      left: 0,
      top: 0
     }, h.containerPosition = {
      left: 0,
      top: 0
     }, h.parentData = {
      element: e(document),
      left: 0,
      top: 0,
      width: e(document).width(),
      height: e(document).height() || document.body.parentNode.scrollHeight
     }) : (t = e(c), i = [], e(["Top", "Right", "Left", "Bottom"]).each(
       function(e, s) {
        i[e] = h._num(t.css("padding" + s))
       }), h.containerOffset = t.offset(), h.containerPosition = t.position(),
      h.containerSize = {
       height: t.innerHeight() - i[3],
       width: t.innerWidth() - i[1]
      }, s = h.containerOffset, n = h.containerSize.height, a = h.containerSize
      .width, o = h._hasScroll(c, "left") ? c.scrollWidth : a, r = h._hasScroll(
       c) ? c.scrollHeight : n, h.parentData = {
       element: c,
       left: s.left,
       top: s.top,
       width: o,
       height: r
      }))
   },
   resize: function(t) {
    var i, s, n, a, o = e(this).resizable("instance"),
     r = o.options,
     h = o.containerOffset,
     l = o.position,
     u = o._aspectRatio || t.shiftKey,
     d = {
      top: 0,
      left: 0
     },
     c = o.containerElement,
     p = !0;
    c[0] !== document && /static/.test(c.css("position")) && (d = h), l.left <
     (o._helper ? h.left : 0) && (o.size.width = o.size.width + (o._helper ?
       o.position.left - h.left : o.position.left - d.left), u && (o.size.height =
       o.size.width / o.aspectRatio, p = !1), o.position.left = r.helper ? h
      .left : 0), l.top < (o._helper ? h.top : 0) && (o.size.height = o.size
      .height + (o._helper ? o.position.top - h.top : o.position.top), u &&
      (o.size.width = o.size.height * o.aspectRatio, p = !1), o.position.top =
      o._helper ? h.top : 0), n = o.containerElement.get(0) === o.element.parent()
     .get(0), a = /relative|absolute/.test(o.containerElement.css("position")),
     n && a ? (o.offset.left = o.parentData.left + o.position.left, o.offset
      .top = o.parentData.top + o.position.top) : (o.offset.left = o.element
      .offset().left, o.offset.top = o.element.offset().top), i = Math.abs(o
      .sizeDiff.width + (o._helper ? o.offset.left - d.left : o.offset.left -
       h.left)), s = Math.abs(o.sizeDiff.height + (o._helper ? o.offset.top -
      d.top : o.offset.top - h.top)), i + o.size.width >= o.parentData.width &&
     (o.size.width = o.parentData.width - i, u && (o.size.height = o.size.width /
      o.aspectRatio, p = !1)), s + o.size.height >= o.parentData.height && (
      o.size.height = o.parentData.height - s, u && (o.size.width = o.size.height *
       o.aspectRatio, p = !1)), p || (o.position.left = o.prevPosition.left,
      o.position.top = o.prevPosition.top, o.size.width = o.prevSize.width,
      o.size.height = o.prevSize.height)
   },
   stop: function() {
    var t = e(this).resizable("instance"),
     i = t.options,
     s = t.containerOffset,
     n = t.containerPosition,
     a = t.containerElement,
     o = e(t.helper),
     r = o.offset(),
     h = o.outerWidth() - t.sizeDiff.width,
     l = o.outerHeight() - t.sizeDiff.height;
    t._helper && !i.animate && /relative/.test(a.css("position")) && e(this)
     .css({
      left: r.left - n.left - s.left,
      width: h,
      height: l
     }), t._helper && !i.animate && /static/.test(a.css("position")) && e(
      this).css({
      left: r.left - n.left - s.left,
      width: h,
      height: l
     })
   }
  }), e.ui.plugin.add("resizable", "alsoResize", {
   start: function() {
    var t = e(this).resizable("instance"),
     i = t.options,
     s = function(t) {
      e(t).each(function() {
       var t = e(this);
       t.data("ui-resizable-alsoresize", {
        width: parseInt(t.width(), 10),
        height: parseInt(t.height(), 10),
        left: parseInt(t.css("left"), 10),
        top: parseInt(t.css("top"), 10)
       })
      })
     };
    "object" != typeof i.alsoResize || i.alsoResize.parentNode ? s(i.alsoResize) :
     i.alsoResize.length ? (i.alsoResize = i.alsoResize[0], s(i.alsoResize)) :
     e.each(i.alsoResize, function(e) {
      s(e)
     })
   },
   resize: function(t, i) {
    var s = e(this).resizable("instance"),
     n = s.options,
     a = s.originalSize,
     o = s.originalPosition,
     r = {
      height: s.size.height - a.height || 0,
      width: s.size.width - a.width || 0,
      top: s.position.top - o.top || 0,
      left: s.position.left - o.left || 0
     },
     h = function(t, s) {
      e(t).each(function() {
       var t = e(this),
        n = e(this).data("ui-resizable-alsoresize"),
        a = {},
        o = s && s.length ? s : t.parents(i.originalElement[0]).length ? [
         "width", "height"
        ] : ["width", "height", "top", "left"];
       e.each(o, function(e, t) {
        var i = (n[t] || 0) + (r[t] || 0);
        i && i >= 0 && (a[t] = i || null)
       }), t.css(a)
      })
     };
    "object" != typeof n.alsoResize || n.alsoResize.nodeType ? h(n.alsoResize) :
     e.each(n.alsoResize, function(e, t) {
      h(e, t)
     })
   },
   stop: function() {
    e(this).removeData("resizable-alsoresize")
   }
  }), e.ui.plugin.add("resizable", "ghost", {
   start: function() {
    var t = e(this).resizable("instance"),
     i = t.options,
     s = t.size;
    t.ghost = t.originalElement.clone(), t.ghost.css({
     opacity: .25,
     display: "block",
     position: "relative",
     height: s.height,
     width: s.width,
     margin: 0,
     left: 0,
     top: 0
    }).addClass("ui-resizable-ghost").addClass("string" == typeof i.ghost ?
     i.ghost : ""), t.ghost.appendTo(t.helper)
   },
   resize: function() {
    var t = e(this).resizable("instance");
    t.ghost && t.ghost.css({
     position: "relative",
     height: t.size.height,
     width: t.size.width
    })
   },
   stop: function() {
    var t = e(this).resizable("instance");
    t.ghost && t.helper && t.helper.get(0).removeChild(t.ghost.get(0))
   }
  }), e.ui.plugin.add("resizable", "grid", {
   resize: function() {
    var t, i = e(this).resizable("instance"),
     s = i.options,
     n = i.size,
     a = i.originalSize,
     o = i.originalPosition,
     r = i.axis,
     h = "number" == typeof s.grid ? [s.grid, s.grid] : s.grid,
     l = h[0] || 1,
     u = h[1] || 1,
     d = Math.round((n.width - a.width) / l) * l,
     c = Math.round((n.height - a.height) / u) * u,
     p = a.width + d,
     f = a.height + c,
     m = s.maxWidth && p > s.maxWidth,
     g = s.maxHeight && f > s.maxHeight,
     v = s.minWidth && s.minWidth > p,
     y = s.minHeight && s.minHeight > f;
    s.grid = h, v && (p += l), y && (f += u), m && (p -= l), g && (f -= u),
     /^(se|s|e)$/.test(r) ? (i.size.width = p, i.size.height = f) : /^(ne)$/
     .test(r) ? (i.size.width = p, i.size.height = f, i.position.top = o.top -
      c) : /^(sw)$/.test(r) ? (i.size.width = p, i.size.height = f, i.position
      .left = o.left - d) : ((0 >= f - u || 0 >= p - l) && (t = i._getPaddingPlusBorderDimensions(
       this)), f - u > 0 ? (i.size.height = f, i.position.top = o.top - c) :
      (f = u - t.height, i.size.height = f, i.position.top = o.top + a.height -
       f), p - l > 0 ? (i.size.width = p, i.position.left = o.left - d) : (p =
       u - t.height, i.size.width = p, i.position.left = o.left + a.width -
       p))
   }
  }), e.ui.resizable, e.widget("ui.dialog", {
   version: "1.11.2",
   options: {
    appendTo: "body",
    autoOpen: !0,
    buttons: [],
    closeOnEscape: !0,
    closeText: "Close",
    dialogClass: "",
    draggable: !0,
    hide: null,
    height: "auto",
    maxHeight: null,
    maxWidth: null,
    minHeight: 150,
    minWidth: 150,
    modal: !1,
    position: {
     my: "center",
     at: "center",
     of: window,
     collision: "fit",
     using: function(t) {
      var i = e(this).css(t).offset().top;
      0 > i && e(this).css("top", t.top - i)
     }
    },
    resizable: !0,
    show: null,
    title: null,
    width: 300,
    beforeClose: null,
    close: null,
    drag: null,
    dragStart: null,
    dragStop: null,
    focus: null,
    open: null,
    resize: null,
    resizeStart: null,
    resizeStop: null
   },
   sizeRelatedOptions: {
    buttons: !0,
    height: !0,
    maxHeight: !0,
    maxWidth: !0,
    minHeight: !0,
    minWidth: !0,
    width: !0
   },
   resizableRelatedOptions: {
    maxHeight: !0,
    maxWidth: !0,
    minHeight: !0,
    minWidth: !0
   },
   _create: function() {
    this.originalCss = {
      display: this.element[0].style.display,
      width: this.element[0].style.width,
      minHeight: this.element[0].style.minHeight,
      maxHeight: this.element[0].style.maxHeight,
      height: this.element[0].style.height
     }, this.originalPosition = {
      parent: this.element.parent(),
      index: this.element.parent().children().index(this.element)
     }, this.originalTitle = this.element.attr("title"), this.options.title =
     this.options.title || this.originalTitle, this._createWrapper(), this.element
     .show().removeAttr("title").addClass(
      "ui-dialog-content ui-widget-content").appendTo(this.uiDialog), this._createTitlebar(),
     this._createButtonPane(), this.options.draggable && e.fn.draggable &&
     this._makeDraggable(), this.options.resizable && e.fn.resizable && this
     ._makeResizable(), this._isOpen = !1, this._trackFocus()
   },
   _init: function() {
    this.options.autoOpen && this.open()
   },
   _appendTo: function() {
    var t = this.options.appendTo;
    return t && (t.jquery || t.nodeType) ? e(t) : this.document.find(t ||
     "body").eq(0)
   },
   _destroy: function() {
    var e, t = this.originalPosition;
    this._destroyOverlay(), this.element.removeUniqueId().removeClass(
      "ui-dialog-content ui-widget-content").css(this.originalCss).detach(),
     this.uiDialog.stop(!0, !0).remove(), this.originalTitle && this.element
     .attr("title", this.originalTitle), e = t.parent.children().eq(t.index),
     e.length && e[0] !== this.element[0] ? e.before(this.element) : t.parent
     .append(this.element)
   },
   widget: function() {
    return this.uiDialog
   },
   disable: e.noop,
   enable: e.noop,
   close: function(t) {
    var i, s = this;
    if (this._isOpen && this._trigger("beforeClose", t) !== !1) {
     if (this._isOpen = !1, this._focusedElement = null, this._destroyOverlay(),
      this._untrackInstance(), !this.opener.filter(":focusable").focus().length
     ) try {
      i = this.document[0].activeElement, i && "body" !== i.nodeName.toLowerCase() &&
       e(i).blur()
     } catch (n) {}
     this._hide(this.uiDialog, this.options.hide, function() {
      s._trigger("close", t)
     })
    }
   },
   isOpen: function() {
    return this._isOpen
   },
   moveToTop: function() {
    this._moveToTop()
   },
   _moveToTop: function(t, i) {
    var s = !1,
     n = this.uiDialog.siblings(".ui-front:visible").map(function() {
      return +e(this).css("z-index")
     }).get(),
     a = Math.max.apply(null, n);
    return a >= +this.uiDialog.css("z-index") && (this.uiDialog.css(
     "z-index", a + 1), s = !0), s && !i && this._trigger("focus", t), s
   },
   open: function() {
    var t = this;
    return this._isOpen ? (this._moveToTop() && this._focusTabbable(), void 0) :
     (this._isOpen = !0, this.opener = e(this.document[0].activeElement),
      this._size(), this._position(), this._createOverlay(), this._moveToTop(
       null, !0), this.overlay && this.overlay.css("z-index", this.uiDialog.css(
       "z-index") - 1), this._show(this.uiDialog, this.options.show,
       function() {
        t._focusTabbable(), t._trigger("focus")
       }), this._makeFocusTarget(), this._trigger("open"), void 0)
   },
   _focusTabbable: function() {
    var e = this._focusedElement;
    e || (e = this.element.find("[autofocus]")), e.length || (e = this.element
     .find(":tabbable")), e.length || (e = this.uiDialogButtonPane.find(
     ":tabbable")), e.length || (e = this.uiDialogTitlebarClose.filter(
     ":tabbable")), e.length || (e = this.uiDialog), e.eq(0).focus()
   },
   _keepFocus: function(t) {
    function i() {
     var t = this.document[0].activeElement,
      i = this.uiDialog[0] === t || e.contains(this.uiDialog[0], t);
     i || this._focusTabbable()
    }
    t.preventDefault(), i.call(this), this._delay(i)
   },
   _createWrapper: function() {
    this.uiDialog = e("<div>").addClass(
     "ui-dialog ui-widget ui-widget-content ui-corner-all ui-front " + this
     .options.dialogClass).hide().attr({
     tabIndex: -1,
     role: "dialog"
    }).appendTo(this._appendTo()), this._on(this.uiDialog, {
     keydown: function(t) {
      if (this.options.closeOnEscape && !t.isDefaultPrevented() && t.keyCode &&
       t.keyCode === e.ui.keyCode.ESCAPE) return t.preventDefault(), this
       .close(t), void 0;
      if (t.keyCode === e.ui.keyCode.TAB && !t.isDefaultPrevented()) {
       var i = this.uiDialog.find(":tabbable"),
        s = i.filter(":first"),
        n = i.filter(":last");
       t.target !== n[0] && t.target !== this.uiDialog[0] || t.shiftKey ?
        t.target !== s[0] && t.target !== this.uiDialog[0] || !t.shiftKey ||
        (this._delay(function() {
         n.focus()
        }), t.preventDefault()) : (this._delay(function() {
         s.focus()
        }), t.preventDefault())
      }
     },
     mousedown: function(e) {
      this._moveToTop(e) && this._focusTabbable()
     }
    }), this.element.find("[aria-describedby]").length || this.uiDialog.attr({
     "aria-describedby": this.element.uniqueId().attr("id")
    })
   },
   _createTitlebar: function() {
    var t;
    this.uiDialogTitlebar = e("<div>").addClass(
      "ui-dialog-titlebar ui-widget-header ui-corner-all ui-helper-clearfix"
     ).prependTo(this.uiDialog), this._on(this.uiDialogTitlebar, {
      mousedown: function(t) {
       e(t.target).closest(".ui-dialog-titlebar-close") || this.uiDialog.focus()
      }
     }), this.uiDialogTitlebarClose = e("<button type='button'></button>").button({
      label: this.options.closeText,
      icons: {
       primary: "ui-icon-closethick"
      },
      text: !1
     }).addClass("ui-dialog-titlebar-close").appendTo(this.uiDialogTitlebar),
     this._on(this.uiDialogTitlebarClose, {
      click: function(e) {
       e.preventDefault(), this.close(e)
      }
     }), t = e("<span>").uniqueId().addClass("ui-dialog-title").prependTo(
      this.uiDialogTitlebar), this._title(t), this.uiDialog.attr({
      "aria-labelledby": t.attr("id")
     })
   },
   _title: function(e) {
    this.options.title || e.html("&#160;"), e.text(this.options.title)
   },
   _createButtonPane: function() {
    this.uiDialogButtonPane = e("<div>").addClass(
      "ui-dialog-buttonpane ui-widget-content ui-helper-clearfix"), this.uiButtonSet =
     e("<div>").addClass("ui-dialog-buttonset").appendTo(this.uiDialogButtonPane),
     this._createButtons()
   },
   _createButtons: function() {
    var t = this,
     i = this.options.buttons;
    return this.uiDialogButtonPane.remove(), this.uiButtonSet.empty(), e.isEmptyObject(
     i) || e.isArray(i) && !i.length ? (this.uiDialog.removeClass(
     "ui-dialog-buttons"), void 0) : (e.each(i, function(i, s) {
      var n, a;
      s = e.isFunction(s) ? {
       click: s,
       text: i
      } : s, s = e.extend({
       type: "button"
      }, s), n = s.click, s.click = function() {
       n.apply(t.element[0], arguments)
      }, a = {
       icons: s.icons,
       text: s.showText
      }, delete s.icons, delete s.showText, e("<button></button>", s).button(
       a).appendTo(t.uiButtonSet)
     }), this.uiDialog.addClass("ui-dialog-buttons"), this.uiDialogButtonPane
     .appendTo(this.uiDialog), void 0)
   },
   _makeDraggable: function() {
    function t(e) {
     return {
      position: e.position,
      offset: e.offset
     }
    }
    var i = this,
     s = this.options;
    this.uiDialog.draggable({
     cancel: ".ui-dialog-content, .ui-dialog-titlebar-close",
     handle: ".ui-dialog-titlebar",
     containment: "document",
     start: function(s, n) {
      e(this).addClass("ui-dialog-dragging"), i._blockFrames(), i._trigger(
       "dragStart", s, t(n))
     },
     drag: function(e, s) {
      i._trigger("drag", e, t(s))
     },
     stop: function(n, a) {
      var o = a.offset.left - i.document.scrollLeft(),
       r = a.offset.top - i.document.scrollTop();
      s.position = {
        my: "left top",
        at: "left" + (o >= 0 ? "+" : "") + o + " " + "top" + (r >= 0 ?
         "+" : "") + r,
        of: i.window
       }, e(this).removeClass("ui-dialog-dragging"), i._unblockFrames(),
       i._trigger("dragStop", n, t(a))
     }
    })
   },
   _makeResizable: function() {
    function t(e) {
     return {
      originalPosition: e.originalPosition,
      originalSize: e.originalSize,
      position: e.position,
      size: e.size
     }
    }
    var i = this,
     s = this.options,
     n = s.resizable,
     a = this.uiDialog.css("position"),
     o = "string" == typeof n ? n : "n,e,s,w,se,sw,ne,nw";
    this.uiDialog.resizable({
     cancel: ".ui-dialog-content",
     containment: "document",
     alsoResize: this.element,
     maxWidth: s.maxWidth,
     maxHeight: s.maxHeight,
     minWidth: s.minWidth,
     minHeight: this._minHeight(),
     handles: o,
     start: function(s, n) {
      e(this).addClass("ui-dialog-resizing"), i._blockFrames(), i._trigger(
       "resizeStart", s, t(n))
     },
     resize: function(e, s) {
      i._trigger("resize", e, t(s))
     },
     stop: function(n, a) {
      var o = i.uiDialog.offset(),
       r = o.left - i.document.scrollLeft(),
       h = o.top - i.document.scrollTop();
      s.height = i.uiDialog.height(), s.width = i.uiDialog.width(), s.position = {
        my: "left top",
        at: "left" + (r >= 0 ? "+" : "") + r + " " + "top" + (h >= 0 ?
         "+" : "") + h,
        of: i.window
       }, e(this).removeClass("ui-dialog-resizing"), i._unblockFrames(),
       i._trigger("resizeStop", n, t(a))
     }
    }).css("position", a)
   },
   _trackFocus: function() {
    this._on(this.widget(), {
     focusin: function(t) {
      this._makeFocusTarget(), this._focusedElement = e(t.target)
     }
    })
   },
   _makeFocusTarget: function() {
    this._untrackInstance(), this._trackingInstances().unshift(this)
   },
   _untrackInstance: function() {
    var t = this._trackingInstances(),
     i = e.inArray(this, t); - 1 !== i && t.splice(i, 1)
   },
   _trackingInstances: function() {
    var e = this.document.data("ui-dialog-instances");
    return e || (e = [], this.document.data("ui-dialog-instances", e)), e
   },
   _minHeight: function() {
    var e = this.options;
    return "auto" === e.height ? e.minHeight : Math.min(e.minHeight, e.height)
   },
   _position: function() {
    var e = this.uiDialog.is(":visible");
    e || this.uiDialog.show(), this.uiDialog.position(this.options.position),
     e || this.uiDialog.hide()
   },
   _setOptions: function(t) {
    var i = this,
     s = !1,
     n = {};
    e.each(t, function(e, t) {
     i._setOption(e, t), e in i.sizeRelatedOptions && (s = !0), e in i.resizableRelatedOptions &&
      (n[e] = t)
    }), s && (this._size(), this._position()), this.uiDialog.is(
     ":data(ui-resizable)") && this.uiDialog.resizable("option", n)
   },
   _setOption: function(e, t) {
    var i, s, n = this.uiDialog;
    "dialogClass" === e && n.removeClass(this.options.dialogClass).addClass(
     t), "disabled" !== e && (this._super(e, t), "appendTo" === e && this.uiDialog
     .appendTo(this._appendTo()), "buttons" === e && this._createButtons(),
     "closeText" === e && this.uiDialogTitlebarClose.button({
      label: "" + t
     }), "draggable" === e && (i = n.is(":data(ui-draggable)"), i && !t &&
      n.draggable("destroy"), !i && t && this._makeDraggable()), "position" ===
     e && this._position(), "resizable" === e && (s = n.is(
       ":data(ui-resizable)"), s && !t && n.resizable("destroy"), s &&
      "string" == typeof t && n.resizable("option", "handles", t), s || t ===
      !1 || this._makeResizable()), "title" === e && this._title(this.uiDialogTitlebar
      .find(".ui-dialog-title")))
   },
   _size: function() {
    var e, t, i, s = this.options;
    this.element.show().css({
      width: "auto",
      minHeight: 0,
      maxHeight: "none",
      height: 0
     }), s.minWidth > s.width && (s.width = s.minWidth), e = this.uiDialog.css({
      height: "auto",
      width: s.width
     }).outerHeight(), t = Math.max(0, s.minHeight - e), i = "number" ==
     typeof s.maxHeight ? Math.max(0, s.maxHeight - e) : "none", "auto" ===
     s.height ? this.element.css({
      minHeight: t,
      maxHeight: i,
      height: "auto"
     }) : this.element.height(Math.max(0, s.height - e)), this.uiDialog.is(
      ":data(ui-resizable)") && this.uiDialog.resizable("option",
      "minHeight", this._minHeight())
   },
   _blockFrames: function() {
    this.iframeBlocks = this.document.find("iframe").map(function() {
     var t = e(this);
     return e("<div>").css({
      position: "absolute",
      width: t.outerWidth(),
      height: t.outerHeight()
     }).appendTo(t.parent()).offset(t.offset())[0]
    })
   },
   _unblockFrames: function() {
    this.iframeBlocks && (this.iframeBlocks.remove(), delete this.iframeBlocks)
   },
   _allowInteraction: function(t) {
    return e(t.target).closest(".ui-dialog").length ? !0 : !!e(t.target).closest(
     ".ui-datepicker").length
   },
   _createOverlay: function() {
    if (this.options.modal) {
     var t = !0;
     this._delay(function() {
      t = !1
     }), this.document.data("ui-dialog-overlays") || this._on(this.document, {
      focusin: function(e) {
       t || this._allowInteraction(e) || (e.preventDefault(), this._trackingInstances()[
        0]._focusTabbable())
      }
     }), this.overlay = e("<div>").addClass("ui-widget-overlay ui-front").appendTo(
      this._appendTo()), this._on(this.overlay, {
      mousedown: "_keepFocus"
     }), this.document.data("ui-dialog-overlays", (this.document.data(
      "ui-dialog-overlays") || 0) + 1)
    }
   },
   _destroyOverlay: function() {
    if (this.options.modal && this.overlay) {
     var e = this.document.data("ui-dialog-overlays") - 1;
     e ? this.document.data("ui-dialog-overlays", e) : this.document.unbind(
       "focusin").removeData("ui-dialog-overlays"), this.overlay.remove(),
      this.overlay = null
    }
   }
  }), e.widget("ui.droppable", {
   version: "1.11.2",
   widgetEventPrefix: "drop",
   options: {
    accept: "*",
    activeClass: !1,
    addClasses: !0,
    greedy: !1,
    hoverClass: !1,
    scope: "default",
    tolerance: "intersect",
    activate: null,
    deactivate: null,
    drop: null,
    out: null,
    over: null
   },
   _create: function() {
    var t, i = this.options,
     s = i.accept;
    this.isover = !1, this.isout = !0, this.accept = e.isFunction(s) ? s :
     function(e) {
      return e.is(s)
     }, this.proportions = function() {
      return arguments.length ? (t = arguments[0], void 0) : t ? t : t = {
       width: this.element[0].offsetWidth,
       height: this.element[0].offsetHeight
      }
     }, this._addToManager(i.scope), i.addClasses && this.element.addClass(
      "ui-droppable")
   },
   _addToManager: function(t) {
    e.ui.ddmanager.droppables[t] = e.ui.ddmanager.droppables[t] || [], e.ui.ddmanager
     .droppables[t].push(this)
   },
   _splice: function(e) {
    for (var t = 0; e.length > t; t++) e[t] === this && e.splice(t, 1)
   },
   _destroy: function() {
    var t = e.ui.ddmanager.droppables[this.options.scope];
    this._splice(t), this.element.removeClass(
     "ui-droppable ui-droppable-disabled")
   },
   _setOption: function(t, i) {
    if ("accept" === t) this.accept = e.isFunction(i) ? i : function(e) {
     return e.is(i)
    };
    else if ("scope" === t) {
     var s = e.ui.ddmanager.droppables[this.options.scope];
     this._splice(s), this._addToManager(i)
    }
    this._super(t, i)
   },
   _activate: function(t) {
    var i = e.ui.ddmanager.current;
    this.options.activeClass && this.element.addClass(this.options.activeClass),
     i && this._trigger("activate", t, this.ui(i))
   },
   _deactivate: function(t) {
    var i = e.ui.ddmanager.current;
    this.options.activeClass && this.element.removeClass(this.options.activeClass),
     i && this._trigger("deactivate", t, this.ui(i))
   },
   _over: function(t) {
    var i = e.ui.ddmanager.current;
    i && (i.currentItem || i.element)[0] !== this.element[0] && this.accept.call(
     this.element[0], i.currentItem || i.element) && (this.options.hoverClass &&
     this.element.addClass(this.options.hoverClass), this._trigger("over",
      t, this.ui(i)))
   },
   _out: function(t) {
    var i = e.ui.ddmanager.current;
    i && (i.currentItem || i.element)[0] !== this.element[0] && this.accept.call(
     this.element[0], i.currentItem || i.element) && (this.options.hoverClass &&
     this.element.removeClass(this.options.hoverClass), this._trigger("out",
      t, this.ui(i)))
   },
   _drop: function(t, i) {
    var s = i || e.ui.ddmanager.current,
     n = !1;
    return s && (s.currentItem || s.element)[0] !== this.element[0] ? (this.element
     .find(":data(ui-droppable)").not(".ui-draggable-dragging").each(
      function() {
       var i = e(this).droppable("instance");
       return i.options.greedy && !i.options.disabled && i.options.scope ===
        s.options.scope && i.accept.call(i.element[0], s.currentItem || s.element) &&
        e.ui.intersect(s, e.extend(i, {
         offset: i.element.offset()
        }), i.options.tolerance, t) ? (n = !0, !1) : void 0
      }), n ? !1 : this.accept.call(this.element[0], s.currentItem || s.element) ?
     (this.options.activeClass && this.element.removeClass(this.options.activeClass),
      this.options.hoverClass && this.element.removeClass(this.options.hoverClass),
      this._trigger("drop", t, this.ui(s)), this.element) : !1) : !1
   },
   ui: function(e) {
    return {
     draggable: e.currentItem || e.element,
     helper: e.helper,
     position: e.position,
     offset: e.positionAbs
    }
   }
  }), e.ui.intersect = function() {
   function e(e, t, i) {
    return e >= t && t + i > e
   }
   return function(t, i, s, n) {
    if (!i.offset) return !1;
    var a = (t.positionAbs || t.position.absolute).left + t.margins.left,
     o = (t.positionAbs || t.position.absolute).top + t.margins.top,
     r = a + t.helperProportions.width,
     h = o + t.helperProportions.height,
     l = i.offset.left,
     u = i.offset.top,
     d = l + i.proportions().width,
     c = u + i.proportions().height;
    switch (s) {
     case "fit":
      return a >= l && d >= r && o >= u && c >= h;
     case "intersect":
      return a + t.helperProportions.width / 2 > l && d > r - t.helperProportions
       .width / 2 && o + t.helperProportions.height / 2 > u && c > h - t.helperProportions
       .height / 2;
     case "pointer":
      return e(n.pageY, u, i.proportions().height) && e(n.pageX, l, i.proportions()
       .width);
     case "touch":
      return (o >= u && c >= o || h >= u && c >= h || u > o && h > c) && (a >=
       l && d >= a || r >= l && d >= r || l > a && r > d);
     default:
      return !1
    }
   }
  }(), e.ui.ddmanager = {
   current: null,
   droppables: {
    "default": []
   },
   prepareOffsets: function(t, i) {
    var s, n, a = e.ui.ddmanager.droppables[t.options.scope] || [],
     o = i ? i.type : null,
     r = (t.currentItem || t.element).find(":data(ui-droppable)").addBack();
    e: for (s = 0; a.length > s; s++)
     if (!(a[s].options.disabled || t && !a[s].accept.call(a[s].element[0],
       t.currentItem || t.element))) {
      for (n = 0; r.length > n; n++)
       if (r[n] === a[s].element[0]) {
        a[s].proportions().height = 0;
        continue e
       }
      a[s].visible = "none" !== a[s].element.css("display"), a[s].visible &&
       ("mousedown" === o && a[s]._activate.call(a[s], i), a[s].offset = a[s]
        .element.offset(), a[s].proportions({
         width: a[s].element[0].offsetWidth,
         height: a[s].element[0].offsetHeight
        }))
     }
   },
   drop: function(t, i) {
    var s = !1;
    return e.each((e.ui.ddmanager.droppables[t.options.scope] || []).slice(),
     function() {
      this.options && (!this.options.disabled && this.visible && e.ui.intersect(
       t, this, this.options.tolerance, i) && (s = this._drop.call(this, i) ||
       s), !this.options.disabled && this.visible && this.accept.call(this
       .element[0], t.currentItem || t.element) && (this.isout = !0, this.isover = !
       1, this._deactivate.call(this, i)))
     }), s
   },
   dragStart: function(t, i) {
    t.element.parentsUntil("body").bind("scroll.droppable", function() {
     t.options.refreshPositions || e.ui.ddmanager.prepareOffsets(t, i)
    })
   },
   drag: function(t, i) {
    t.options.refreshPositions && e.ui.ddmanager.prepareOffsets(t, i), e.each(
     e.ui.ddmanager.droppables[t.options.scope] || [],
     function() {
      if (!this.options.disabled && !this.greedyChild && this.visible) {
       var s, n, a, o = e.ui.intersect(t, this, this.options.tolerance, i),
        r = !o && this.isover ? "isout" : o && !this.isover ? "isover" :
        null;
       r && (this.options.greedy && (n = this.options.scope, a = this.element
        .parents(":data(ui-droppable)").filter(function() {
         return e(this).droppable("instance").options.scope === n
        }), a.length && (s = e(a[0]).droppable("instance"), s.greedyChild =
         "isover" === r)), s && "isover" === r && (s.isover = !1, s.isout = !
        0, s._out.call(s, i)), this[r] = !0, this["isout" === r ? "isover" :
        "isout"] = !1, this["isover" === r ? "_over" : "_out"].call(this,
        i), s && "isout" === r && (s.isout = !1, s.isover = !0, s._over.call(
        s, i)))
      }
     })
   },
   dragStop: function(t, i) {
    t.element.parentsUntil("body").unbind("scroll.droppable"), t.options.refreshPositions ||
     e.ui.ddmanager.prepareOffsets(t, i)
   }
  }, e.ui.droppable;
 var y = "ui-effects-",
  b = e;
 e.effects = {
   effect: {}
  },
  function(e, t) {
   function i(e, t, i) {
    var s = d[t.type] || {};
    return null == e ? i || !t.def ? null : t.def : (e = s.floor ? ~~e :
     parseFloat(e), isNaN(e) ? t.def : s.mod ? (e + s.mod) % s.mod : 0 > e ?
     0 : e > s.max ? s.max : e)
   }

   function s(i) {
    var s = l(),
     n = s._rgba = [];
    return i = i.toLowerCase(), f(h, function(e, a) {
      var o, r = a.re.exec(i),
       h = r && a.parse(r),
       l = a.space || "rgba";
      return h ? (o = s[l](h), s[u[l].cache] = o[u[l].cache], n = s._rgba =
       o._rgba, !1) : t
     }), n.length ? ("0,0,0,0" === n.join() && e.extend(n, a.transparent), s) :
     a[i]
   }

   function n(e, t, i) {
    return i = (i + 1) % 1, 1 > 6 * i ? e + 6 * (t - e) * i : 1 > 2 * i ? t :
     2 > 3 * i ? e + 6 * (t - e) * (2 / 3 - i) : e
   }
   var a, o =
    "backgroundColor borderBottomColor borderLeftColor borderRightColor borderTopColor color columnRuleColor outlineColor textDecorationColor textEmphasisColor",
    r = /^([\-+])=\s*(\d+\.?\d*)/,
    h = [{
     re: /rgba?\(\s*(\d{1,3})\s*,\s*(\d{1,3})\s*,\s*(\d{1,3})\s*(?:,\s*(\d?(?:\.\d+)?)\s*)?\)/,
     parse: function(e) {
      return [e[1], e[2], e[3], e[4]]
     }
    }, {
     re: /rgba?\(\s*(\d+(?:\.\d+)?)\%\s*,\s*(\d+(?:\.\d+)?)\%\s*,\s*(\d+(?:\.\d+)?)\%\s*(?:,\s*(\d?(?:\.\d+)?)\s*)?\)/,
     parse: function(e) {
      return [2.55 * e[1], 2.55 * e[2], 2.55 * e[3], e[4]]
     }
    }, {
     re: /#([a-f0-9]{2})([a-f0-9]{2})([a-f0-9]{2})/,
     parse: function(e) {
      return [parseInt(e[1], 16), parseInt(e[2], 16), parseInt(e[3], 16)]
     }
    }, {
     re: /#([a-f0-9])([a-f0-9])([a-f0-9])/,
     parse: function(e) {
      return [parseInt(e[1] + e[1], 16), parseInt(e[2] + e[2], 16), parseInt(
       e[3] + e[3], 16)]
     }
    }, {
     re: /hsla?\(\s*(\d+(?:\.\d+)?)\s*,\s*(\d+(?:\.\d+)?)\%\s*,\s*(\d+(?:\.\d+)?)\%\s*(?:,\s*(\d?(?:\.\d+)?)\s*)?\)/,
     space: "hsla",
     parse: function(e) {
      return [e[1], e[2] / 100, e[3] / 100, e[4]]
     }
    }],
    l = e.Color = function(t, i, s, n) {
     return new e.Color.fn.parse(t, i, s, n)
    },
    u = {
     rgba: {
      props: {
       red: {
        idx: 0,
        type: "byte"
       },
       green: {
        idx: 1,
        type: "byte"
       },
       blue: {
        idx: 2,
        type: "byte"
       }
      }
     },
     hsla: {
      props: {
       hue: {
        idx: 0,
        type: "degrees"
       },
       saturation: {
        idx: 1,
        type: "percent"
       },
       lightness: {
        idx: 2,
        type: "percent"
       }
      }
     }
    },
    d = {
     "byte": {
      floor: !0,
      max: 255
     },
     percent: {
      max: 1
     },
     degrees: {
      mod: 360,
      floor: !0
     }
    },
    c = l.support = {},
    p = e("<p>")[0],
    f = e.each;
   p.style.cssText = "background-color:rgba(1,1,1,.5)", c.rgba = p.style.backgroundColor
    .indexOf("rgba") > -1, f(u, function(e, t) {
     t.cache = "_" + e, t.props.alpha = {
      idx: 3,
      type: "percent",
      def: 1
     }
    }), l.fn = e.extend(l.prototype, {
     parse: function(n, o, r, h) {
      if (n === t) return this._rgba = [null, null, null, null], this;
      (n.jquery || n.nodeType) && (n = e(n).css(o), o = t);
      var d = this,
       c = e.type(n),
       p = this._rgba = [];
      return o !== t && (n = [n, o, r, h], c = "array"), "string" === c ?
       this.parse(s(n) || a._default) : "array" === c ? (f(u.rgba.props,
        function(e, t) {
         p[t.idx] = i(n[t.idx], t)
        }), this) : "object" === c ? (n instanceof l ? f(u, function(e, t) {
        n[t.cache] && (d[t.cache] = n[t.cache].slice())
       }) : f(u, function(t, s) {
        var a = s.cache;
        f(s.props, function(e, t) {
         if (!d[a] && s.to) {
          if ("alpha" === e || null == n[e]) return;
          d[a] = s.to(d._rgba)
         }
         d[a][t.idx] = i(n[e], t, !0)
        }), d[a] && 0 > e.inArray(null, d[a].slice(0, 3)) && (d[a][3] = 1,
         s.from && (d._rgba = s.from(d[a])))
       }), this) : t
     },
     is: function(e) {
      var i = l(e),
       s = !0,
       n = this;
      return f(u, function(e, a) {
       var o, r = i[a.cache];
       return r && (o = n[a.cache] || a.to && a.to(n._rgba) || [], f(a.props,
        function(e, i) {
         return null != r[i.idx] ? s = r[i.idx] === o[i.idx] : t
        })), s
      }), s
     },
     _space: function() {
      var e = [],
       t = this;
      return f(u, function(i, s) {
       t[s.cache] && e.push(i)
      }), e.pop()
     },
     transition: function(e, t) {
      var s = l(e),
       n = s._space(),
       a = u[n],
       o = 0 === this.alpha() ? l("transparent") : this,
       r = o[a.cache] || a.to(o._rgba),
       h = r.slice();
      return s = s[a.cache], f(a.props, function(e, n) {
       var a = n.idx,
        o = r[a],
        l = s[a],
        u = d[n.type] || {};
       null !== l && (null === o ? h[a] = l : (u.mod && (l - o > u.mod / 2 ?
        o += u.mod : o - l > u.mod / 2 && (o -= u.mod)), h[a] = i((l -
        o) * t + o, n)))
      }), this[n](h)
     },
     blend: function(t) {
      if (1 === this._rgba[3]) return this;
      var i = this._rgba.slice(),
       s = i.pop(),
       n = l(t)._rgba;
      return l(e.map(i, function(e, t) {
       return (1 - s) * n[t] + s * e
      }))
     },
     toRgbaString: function() {
      var t = "rgba(",
       i = e.map(this._rgba, function(e, t) {
        return null == e ? t > 2 ? 1 : 0 : e
       });
      return 1 === i[3] && (i.pop(), t = "rgb("), t + i.join() + ")"
     },
     toHslaString: function() {
      var t = "hsla(",
       i = e.map(this.hsla(), function(e, t) {
        return null == e && (e = t > 2 ? 1 : 0), t && 3 > t && (e = Math.round(
         100 * e) + "%"), e
       });
      return 1 === i[3] && (i.pop(), t = "hsl("), t + i.join() + ")"
     },
     toHexString: function(t) {
      var i = this._rgba.slice(),
       s = i.pop();
      return t && i.push(~~(255 * s)), "#" + e.map(i, function(e) {
       return e = (e || 0).toString(16), 1 === e.length ? "0" + e : e
      }).join("")
     },
     toString: function() {
      return 0 === this._rgba[3] ? "transparent" : this.toRgbaString()
     }
    }), l.fn.parse.prototype = l.fn, u.hsla.to = function(e) {
     if (null == e[0] || null == e[1] || null == e[2]) return [null, null,
      null, e[3]
     ];
     var t, i, s = e[0] / 255,
      n = e[1] / 255,
      a = e[2] / 255,
      o = e[3],
      r = Math.max(s, n, a),
      h = Math.min(s, n, a),
      l = r - h,
      u = r + h,
      d = .5 * u;
     return t = h === r ? 0 : s === r ? 60 * (n - a) / l + 360 : n === r ? 60 *
      (a - s) / l + 120 : 60 * (s - n) / l + 240, i = 0 === l ? 0 : .5 >= d ?
      l / u : l / (2 - u), [Math.round(t) % 360, i, d, null == o ? 1 : o]
    }, u.hsla.from = function(e) {
     if (null == e[0] || null == e[1] || null == e[2]) return [null, null,
      null, e[3]
     ];
     var t = e[0] / 360,
      i = e[1],
      s = e[2],
      a = e[3],
      o = .5 >= s ? s * (1 + i) : s + i - s * i,
      r = 2 * s - o;
     return [Math.round(255 * n(r, o, t + 1 / 3)), Math.round(255 * n(r, o, t)),
      Math.round(255 * n(r, o, t - 1 / 3)), a
     ]
    }, f(u, function(s, n) {
     var a = n.props,
      o = n.cache,
      h = n.to,
      u = n.from;
     l.fn[s] = function(s) {
      if (h && !this[o] && (this[o] = h(this._rgba)), s === t) return this[o]
       .slice();
      var n, r = e.type(s),
       d = "array" === r || "object" === r ? s : arguments,
       c = this[o].slice();
      return f(a, function(e, t) {
       var s = d["object" === r ? e : t.idx];
       null == s && (s = c[t.idx]), c[t.idx] = i(s, t)
      }), u ? (n = l(u(c)), n[o] = c, n) : l(c)
     }, f(a, function(t, i) {
      l.fn[t] || (l.fn[t] = function(n) {
       var a, o = e.type(n),
        h = "alpha" === t ? this._hsla ? "hsla" : "rgba" : s,
        l = this[h](),
        u = l[i.idx];
       return "undefined" === o ? u : ("function" === o && (n = n.call(
        this, u), o = e.type(n)), null == n && i.empty ? this : (
        "string" === o && (a = r.exec(n), a && (n = u + parseFloat(a[2]) *
         ("+" === a[1] ? 1 : -1))), l[i.idx] = n, this[h](l)))
      })
     })
    }), l.hook = function(t) {
     var i = t.split(" ");
     f(i, function(t, i) {
      e.cssHooks[i] = {
       set: function(t, n) {
        var a, o, r = "";
        if ("transparent" !== n && ("string" !== e.type(n) || (a = s(n)))) {
         if (n = l(a || n), !c.rgba && 1 !== n._rgba[3]) {
          for (o = "backgroundColor" === i ? t.parentNode : t;
           ("" === r || "transparent" === r) && o && o.style;) try {
           r = e.css(o, "backgroundColor"), o = o.parentNode
          } catch (h) {}
          n = n.blend(r && "transparent" !== r ? r : "_default")
         }
         n = n.toRgbaString()
        }
        try {
         t.style[i] = n
        } catch (h) {}
       }
      }, e.fx.step[i] = function(t) {
       t.colorInit || (t.start = l(t.elem, i), t.end = l(t.end), t.colorInit = !
        0), e.cssHooks[i].set(t.elem, t.start.transition(t.end, t.pos))
      }
     })
    }, l.hook(o), e.cssHooks.borderColor = {
     expand: function(e) {
      var t = {};
      return f(["Top", "Right", "Bottom", "Left"], function(i, s) {
       t["border" + s + "Color"] = e
      }), t
     }
    }, a = e.Color.names = {
     aqua: "#00ffff",
     black: "#000000",
     blue: "#0000ff",
     fuchsia: "#ff00ff",
     gray: "#808080",
     green: "#008000",
     lime: "#00ff00",
     maroon: "#800000",
     navy: "#000080",
     olive: "#808000",
     purple: "#800080",
     red: "#ff0000",
     silver: "#c0c0c0",
     teal: "#008080",
     white: "#ffffff",
     yellow: "#ffff00",
     transparent: [null, null, null, 0],
     _default: "#ffffff"
    }
  }(b),
  function() {
   function t(t) {
    var i, s, n = t.ownerDocument.defaultView ? t.ownerDocument.defaultView.getComputedStyle(
      t, null) : t.currentStyle,
     a = {};
    if (n && n.length && n[0] && n[n[0]])
     for (s = n.length; s--;) i = n[s], "string" == typeof n[i] && (a[e.camelCase(
      i)] = n[i]);
    else
     for (i in n) "string" == typeof n[i] && (a[i] = n[i]);
    return a
   }

   function i(t, i) {
    var s, a, o = {};
    for (s in i) a = i[s], t[s] !== a && (n[s] || (e.fx.step[s] || !isNaN(
     parseFloat(a))) && (o[s] = a));
    return o
   }
   var s = ["add", "remove", "toggle"],
    n = {
     border: 1,
     borderBottom: 1,
     borderColor: 1,
     borderLeft: 1,
     borderRight: 1,
     borderTop: 1,
     borderWidth: 1,
     margin: 1,
     padding: 1
    };
   e.each(["borderLeftStyle", "borderRightStyle", "borderBottomStyle",
    "borderTopStyle"
   ], function(t, i) {
    e.fx.step[i] = function(e) {
     ("none" !== e.end && !e.setAttr || 1 === e.pos && !e.setAttr) && (b.style(
      e.elem, i, e.end), e.setAttr = !0)
    }
   }), e.fn.addBack || (e.fn.addBack = function(e) {
    return this.add(null == e ? this.prevObject : this.prevObject.filter(e))
   }), e.effects.animateClass = function(n, a, o, r) {
    var h = e.speed(a, o, r);
    return this.queue(function() {
     var a, o = e(this),
      r = o.attr("class") || "",
      l = h.children ? o.find("*").addBack() : o;
     l = l.map(function() {
      var i = e(this);
      return {
       el: i,
       start: t(this)
      }
     }), a = function() {
      e.each(s, function(e, t) {
       n[t] && o[t + "Class"](n[t])
      })
     }, a(), l = l.map(function() {
      return this.end = t(this.el[0]), this.diff = i(this.start, this.end),
       this
     }), o.attr("class", r), l = l.map(function() {
      var t = this,
       i = e.Deferred(),
       s = e.extend({}, h, {
        queue: !1,
        complete: function() {
         i.resolve(t)
        }
       });
      return this.el.animate(this.diff, s), i.promise()
     }), e.when.apply(e, l.get()).done(function() {
      a(), e.each(arguments, function() {
       var t = this.el;
       e.each(this.diff, function(e) {
        t.css(e, "")
       })
      }), h.complete.call(o[0])
     })
    })
   }, e.fn.extend({
    addClass: function(t) {
     return function(i, s, n, a) {
      return s ? e.effects.animateClass.call(this, {
       add: i
      }, s, n, a) : t.apply(this, arguments)
     }
    }(e.fn.addClass),
    removeClass: function(t) {
     return function(i, s, n, a) {
      return arguments.length > 1 ? e.effects.animateClass.call(this, {
       remove: i
      }, s, n, a) : t.apply(this, arguments)
     }
    }(e.fn.removeClass),
    toggleClass: function(t) {
     return function(i, s, n, a, o) {
      return "boolean" == typeof s || void 0 === s ? n ? e.effects.animateClass
       .call(this, s ? {
        add: i
       } : {
        remove: i
       }, n, a, o) : t.apply(this, arguments) : e.effects.animateClass.call(
        this, {
         toggle: i
        }, s, n, a)
     }
    }(e.fn.toggleClass),
    switchClass: function(t, i, s, n, a) {
     return e.effects.animateClass.call(this, {
      add: i,
      remove: t
     }, s, n, a)
    }
   })
  }(),
  function() {
   function t(t, i, s, n) {
    return e.isPlainObject(t) && (i = t, t = t.effect), t = {
      effect: t
     }, null == i && (i = {}), e.isFunction(i) && (n = i, s = null, i = {}), (
      "number" == typeof i || e.fx.speeds[i]) && (n = s, s = i, i = {}), e.isFunction(
      s) && (n = s, s = null), i && e.extend(t, i), s = s || i.duration, t.duration =
     e.fx.off ? 0 : "number" == typeof s ? s : s in e.fx.speeds ? e.fx.speeds[
      s] : e.fx.speeds._default, t.complete = n || i.complete, t
   }

   function i(t) {
    return !t || "number" == typeof t || e.fx.speeds[t] ? !0 : "string" !=
     typeof t || e.effects.effect[t] ? e.isFunction(t) ? !0 : "object" !=
     typeof t || t.effect ? !1 : !0 : !0
   }
   e.extend(e.effects, {
    version: "1.11.2",
    save: function(e, t) {
     for (var i = 0; t.length > i; i++) null !== t[i] && e.data(y + t[i], e[
      0].style[t[i]])
    },
    restore: function(e, t) {
     var i, s;
     for (s = 0; t.length > s; s++) null !== t[s] && (i = e.data(y + t[s]),
      void 0 === i && (i = ""), e.css(t[s], i))
    },
    setMode: function(e, t) {
     return "toggle" === t && (t = e.is(":hidden") ? "show" : "hide"), t
    },
    getBaseline: function(e, t) {
     var i, s;
     switch (e[0]) {
      case "top":
       i = 0;
       break;
      case "middle":
       i = .5;
       break;
      case "bottom":
       i = 1;
       break;
      default:
       i = e[0] / t.height
     }
     switch (e[1]) {
      case "left":
       s = 0;
       break;
      case "center":
       s = .5;
       break;
      case "right":
       s = 1;
       break;
      default:
       s = e[1] / t.width
     }
     return {
      x: s,
      y: i
     }
    },
    createWrapper: function(t) {
     if (t.parent().is(".ui-effects-wrapper")) return t.parent();
     var i = {
       width: t.outerWidth(!0),
       height: t.outerHeight(!0),
       "float": t.css("float")
      },
      s = e("<div></div>").addClass("ui-effects-wrapper").css({
       fontSize: "100%",
       background: "transparent",
       border: "none",
       margin: 0,
       padding: 0
      }),
      n = {
       width: t.width(),
       height: t.height()
      },
      a = document.activeElement;
     try {
      a.id
     } catch (o) {
      a = document.body
     }
     return t.wrap(s), (t[0] === a || e.contains(t[0], a)) && e(a).focus(),
      s = t.parent(), "static" === t.css("position") ? (s.css({
       position: "relative"
      }), t.css({
       position: "relative"
      })) : (e.extend(i, {
       position: t.css("position"),
       zIndex: t.css("z-index")
      }), e.each(["top", "left", "bottom", "right"], function(e, s) {
       i[s] = t.css(s), isNaN(parseInt(i[s], 10)) && (i[s] = "auto")
      }), t.css({
       position: "relative",
       top: 0,
       left: 0,
       right: "auto",
       bottom: "auto"
      })), t.css(n), s.css(i).show()
    },
    removeWrapper: function(t) {
     var i = document.activeElement;
     return t.parent().is(".ui-effects-wrapper") && (t.parent().replaceWith(
      t), (t[0] === i || e.contains(t[0], i)) && e(i).focus()), t
    },
    setTransition: function(t, i, s, n) {
     return n = n || {}, e.each(i, function(e, i) {
      var a = t.cssUnit(i);
      a[0] > 0 && (n[i] = a[0] * s + a[1])
     }), n
    }
   }), e.fn.extend({
    effect: function() {
     function i(t) {
      function i() {
       e.isFunction(a) && a.call(n[0]), e.isFunction(t) && t()
      }
      var n = e(this),
       a = s.complete,
       r = s.mode;
      (n.is(":hidden") ? "hide" === r : "show" === r) ? (n[r](), i()) : o.call(
       n[0], s, i)
     }
     var s = t.apply(this, arguments),
      n = s.mode,
      a = s.queue,
      o = e.effects.effect[s.effect];
     return e.fx.off || !o ? n ? this[n](s.duration, s.complete) : this.each(
      function() {
       s.complete && s.complete.call(this)
      }) : a === !1 ? this.each(i) : this.queue(a || "fx", i)
    },
    show: function(e) {
     return function(s) {
      if (i(s)) return e.apply(this, arguments);
      var n = t.apply(this, arguments);
      return n.mode = "show", this.effect.call(this, n)
     }
    }(e.fn.show),
    hide: function(e) {
     return function(s) {
      if (i(s)) return e.apply(this, arguments);
      var n = t.apply(this, arguments);
      return n.mode = "hide", this.effect.call(this, n)
     }
    }(e.fn.hide),
    toggle: function(e) {
     return function(s) {
      if (i(s) || "boolean" == typeof s) return e.apply(this, arguments);
      var n = t.apply(this, arguments);
      return n.mode = "toggle", this.effect.call(this, n)
     }
    }(e.fn.toggle),
    cssUnit: function(t) {
     var i = this.css(t),
      s = [];
     return e.each(["em", "px", "%", "pt"], function(e, t) {
      i.indexOf(t) > 0 && (s = [parseFloat(i), t])
     }), s
    }
   })
  }(),
  function() {
   var t = {};
   e.each(["Quad", "Cubic", "Quart", "Quint", "Expo"], function(e, i) {
    t[i] = function(t) {
     return Math.pow(t, e + 2)
    }
   }), e.extend(t, {
    Sine: function(e) {
     return 1 - Math.cos(e * Math.PI / 2)
    },
    Circ: function(e) {
     return 1 - Math.sqrt(1 - e * e)
    },
    Elastic: function(e) {
     return 0 === e || 1 === e ? e : -Math.pow(2, 8 * (e - 1)) * Math.sin((
      80 * (e - 1) - 7.5) * Math.PI / 15)
    },
    Back: function(e) {
     return e * e * (3 * e - 2)
    },
    Bounce: function(e) {
     for (var t, i = 4;
      ((t = Math.pow(2, --i)) - 1) / 11 > e;);
     return 1 / Math.pow(4, 3 - i) - 7.5625 * Math.pow((3 * t - 2) / 22 - e,
      2)
    }
   }), e.each(t, function(t, i) {
    e.easing["easeIn" + t] = i, e.easing["easeOut" + t] = function(e) {
     return 1 - i(1 - e)
    }, e.easing["easeInOut" + t] = function(e) {
     return .5 > e ? i(2 * e) / 2 : 1 - i(-2 * e + 2) / 2
    }
   })
  }(), e.effects, e.effects.effect.blind = function(t, i) {
   var s, n, a, o = e(this),
    r = /up|down|vertical/,
    h = /up|left|vertical|horizontal/,
    l = ["position", "top", "bottom", "left", "right", "height", "width"],
    u = e.effects.setMode(o, t.mode || "hide"),
    d = t.direction || "up",
    c = r.test(d),
    p = c ? "height" : "width",
    f = c ? "top" : "left",
    m = h.test(d),
    g = {},
    v = "show" === u;
   o.parent().is(".ui-effects-wrapper") ? e.effects.save(o.parent(), l) : e.effects
    .save(o, l), o.show(), s = e.effects.createWrapper(o).css({
     overflow: "hidden"
    }), n = s[p](), a = parseFloat(s.css(f)) || 0, g[p] = v ? n : 0, m || (o.css(
     c ? "bottom" : "right", 0).css(c ? "top" : "left", "auto").css({
     position: "absolute"
    }), g[f] = v ? a : n + a), v && (s.css(p, 0), m || s.css(f, a + n)), s.animate(
     g, {
      duration: t.duration,
      easing: t.easing,
      queue: !1,
      complete: function() {
       "hide" === u && o.hide(), e.effects.restore(o, l), e.effects.removeWrapper(
        o), i()
      }
     })
  }, e.effects.effect.bounce = function(t, i) {
   var s, n, a, o = e(this),
    r = ["position", "top", "bottom", "left", "right", "height", "width"],
    h = e.effects.setMode(o, t.mode || "effect"),
    l = "hide" === h,
    u = "show" === h,
    d = t.direction || "up",
    c = t.distance,
    p = t.times || 5,
    f = 2 * p + (u || l ? 1 : 0),
    m = t.duration / f,
    g = t.easing,
    v = "up" === d || "down" === d ? "top" : "left",
    y = "up" === d || "left" === d,
    b = o.queue(),
    _ = b.length;
   for ((u || l) && r.push("opacity"), e.effects.save(o, r), o.show(), e.effects
    .createWrapper(o), c || (c = o["top" === v ? "outerHeight" : "outerWidth"]
     () / 3), u && (a = {
     opacity: 1
    }, a[v] = 0, o.css("opacity", 0).css(v, y ? 2 * -c : 2 * c).animate(a, m,
     g)), l && (c /= Math.pow(2, p - 1)), a = {}, a[v] = 0, s = 0; p > s; s++)
    n = {}, n[v] = (y ? "-=" : "+=") + c, o.animate(n, m, g).animate(a, m, g),
    c = l ? 2 * c : c / 2;
   l && (n = {
    opacity: 0
   }, n[v] = (y ? "-=" : "+=") + c, o.animate(n, m, g)), o.queue(function() {
    l && o.hide(), e.effects.restore(o, r), e.effects.removeWrapper(o), i()
   }), _ > 1 && b.splice.apply(b, [1, 0].concat(b.splice(_, f + 1))), o.dequeue()
  }, e.effects.effect.clip = function(t, i) {
   var s, n, a, o = e(this),
    r = ["position", "top", "bottom", "left", "right", "height", "width"],
    h = e.effects.setMode(o, t.mode || "hide"),
    l = "show" === h,
    u = t.direction || "vertical",
    d = "vertical" === u,
    c = d ? "height" : "width",
    p = d ? "top" : "left",
    f = {};
   e.effects.save(o, r), o.show(), s = e.effects.createWrapper(o).css({
    overflow: "hidden"
   }), n = "IMG" === o[0].tagName ? s : o, a = n[c](), l && (n.css(c, 0), n.css(
    p, a / 2)), f[c] = l ? a : 0, f[p] = l ? 0 : a / 2, n.animate(f, {
    queue: !1,
    duration: t.duration,
    easing: t.easing,
    complete: function() {
     l || o.hide(), e.effects.restore(o, r), e.effects.removeWrapper(o), i()
    }
   })
  }, e.effects.effect.drop = function(t, i) {
   var s, n = e(this),
    a = ["position", "top", "bottom", "left", "right", "opacity", "height",
     "width"
    ],
    o = e.effects.setMode(n, t.mode || "hide"),
    r = "show" === o,
    h = t.direction || "left",
    l = "up" === h || "down" === h ? "top" : "left",
    u = "up" === h || "left" === h ? "pos" : "neg",
    d = {
     opacity: r ? 1 : 0
    };
   e.effects.save(n, a), n.show(), e.effects.createWrapper(n), s = t.distance ||
    n["top" === l ? "outerHeight" : "outerWidth"](!0) / 2, r && n.css(
     "opacity", 0).css(l, "pos" === u ? -s : s), d[l] = (r ? "pos" === u ?
     "+=" : "-=" : "pos" === u ? "-=" : "+=") + s, n.animate(d, {
     queue: !1,
     duration: t.duration,
     easing: t.easing,
     complete: function() {
      "hide" === o && n.hide(), e.effects.restore(n, a), e.effects.removeWrapper(
       n), i()
     }
    })
  }, e.effects.effect.explode = function(t, i) {
   function s() {
    b.push(this), b.length === d * c && n()
   }

   function n() {
    p.css({
     visibility: "visible"
    }), e(b).remove(), m || p.hide(), i()
   }
   var a, o, r, h, l, u, d = t.pieces ? Math.round(Math.sqrt(t.pieces)) : 3,
    c = d,
    p = e(this),
    f = e.effects.setMode(p, t.mode || "hide"),
    m = "show" === f,
    g = p.show().css("visibility", "hidden").offset(),
    v = Math.ceil(p.outerWidth() / c),
    y = Math.ceil(p.outerHeight() / d),
    b = [];
   for (a = 0; d > a; a++)
    for (h = g.top + a * y, u = a - (d - 1) / 2, o = 0; c > o; o++) r = g.left +
     o * v, l = o - (c - 1) / 2, p.clone().appendTo("body").wrap("<div></div>")
     .css({
      position: "absolute",
      visibility: "visible",
      left: -o * v,
      top: -a * y
     }).parent().addClass("ui-effects-explode").css({
      position: "absolute",
      overflow: "hidden",
      width: v,
      height: y,
      left: r + (m ? l * v : 0),
      top: h + (m ? u * y : 0),
      opacity: m ? 0 : 1
     }).animate({
      left: r + (m ? 0 : l * v),
      top: h + (m ? 0 : u * y),
      opacity: m ? 1 : 0
     }, t.duration || 500, t.easing, s)
  }, e.effects.effect.fade = function(t, i) {
   var s = e(this),
    n = e.effects.setMode(s, t.mode || "toggle");
   s.animate({
    opacity: n
   }, {
    queue: !1,
    duration: t.duration,
    easing: t.easing,
    complete: i
   })
  }, e.effects.effect.fold = function(t, i) {
   var s, n, a = e(this),
    o = ["position", "top", "bottom", "left", "right", "height", "width"],
    r = e.effects.setMode(a, t.mode || "hide"),
    h = "show" === r,
    l = "hide" === r,
    u = t.size || 15,
    d = /([0-9]+)%/.exec(u),
    c = !!t.horizFirst,
    p = h !== c,
    f = p ? ["width", "height"] : ["height", "width"],
    m = t.duration / 2,
    g = {},
    v = {};
   e.effects.save(a, o), a.show(), s = e.effects.createWrapper(a).css({
     overflow: "hidden"
    }), n = p ? [s.width(), s.height()] : [s.height(), s.width()], d && (u =
     parseInt(d[1], 10) / 100 * n[l ? 0 : 1]), h && s.css(c ? {
     height: 0,
     width: u
    } : {
     height: u,
     width: 0
    }), g[f[0]] = h ? n[0] : u, v[f[1]] = h ? n[1] : 0, s.animate(g, m, t.easing)
    .animate(v, m, t.easing, function() {
     l && a.hide(), e.effects.restore(a, o), e.effects.removeWrapper(a), i()
    })
  }, e.effects.effect.highlight = function(t, i) {
   var s = e(this),
    n = ["backgroundImage", "backgroundColor", "opacity"],
    a = e.effects.setMode(s, t.mode || "show"),
    o = {
     backgroundColor: s.css("backgroundColor")
    };
   "hide" === a && (o.opacity = 0), e.effects.save(s, n), s.show().css({
    backgroundImage: "none",
    backgroundColor: t.color || "#ffff99"
   }).animate(o, {
    queue: !1,
    duration: t.duration,
    easing: t.easing,
    complete: function() {
     "hide" === a && s.hide(), e.effects.restore(s, n), i()
    }
   })
  }, e.effects.effect.size = function(t, i) {
   var s, n, a, o = e(this),
    r = ["position", "top", "bottom", "left", "right", "width", "height",
     "overflow", "opacity"
    ],
    h = ["position", "top", "bottom", "left", "right", "overflow", "opacity"],
    l = ["width", "height", "overflow"],
    u = ["fontSize"],
    d = ["borderTopWidth", "borderBottomWidth", "paddingTop", "paddingBottom"],
    c = ["borderLeftWidth", "borderRightWidth", "paddingLeft", "paddingRight"],
    p = e.effects.setMode(o, t.mode || "effect"),
    f = t.restore || "effect" !== p,
    m = t.scale || "both",
    g = t.origin || ["middle", "center"],
    v = o.css("position"),
    y = f ? r : h,
    b = {
     height: 0,
     width: 0,
     outerHeight: 0,
     outerWidth: 0
    };
   "show" === p && o.show(), s = {
     height: o.height(),
     width: o.width(),
     outerHeight: o.outerHeight(),
     outerWidth: o.outerWidth()
    }, "toggle" === t.mode && "show" === p ? (o.from = t.to || b, o.to = t.from ||
     s) : (o.from = t.from || ("show" === p ? b : s), o.to = t.to || ("hide" ===
     p ? b : s)), a = {
     from: {
      y: o.from.height / s.height,
      x: o.from.width / s.width
     },
     to: {
      y: o.to.height / s.height,
      x: o.to.width / s.width
     }
    }, ("box" === m || "both" === m) && (a.from.y !== a.to.y && (y = y.concat(
      d), o.from = e.effects.setTransition(o, d, a.from.y, o.from), o.to = e.effects
     .setTransition(o, d, a.to.y, o.to)), a.from.x !== a.to.x && (y = y.concat(
      c), o.from = e.effects.setTransition(o, c, a.from.x, o.from), o.to = e.effects
     .setTransition(o, c, a.to.x, o.to))), ("content" === m || "both" === m) &&
    a.from.y !== a.to.y && (y = y.concat(u).concat(l), o.from = e.effects.setTransition(
     o, u, a.from.y, o.from), o.to = e.effects.setTransition(o, u, a.to.y, o.to)),
    e.effects.save(o, y), o.show(), e.effects.createWrapper(o), o.css(
     "overflow", "hidden").css(o.from), g && (n = e.effects.getBaseline(g, s),
     o.from.top = (s.outerHeight - o.outerHeight()) * n.y, o.from.left = (s.outerWidth -
      o.outerWidth()) * n.x, o.to.top = (s.outerHeight - o.to.outerHeight) * n
     .y, o.to.left = (s.outerWidth - o.to.outerWidth) * n.x), o.css(o.from), (
     "content" === m || "both" === m) && (d = d.concat(["marginTop",
      "marginBottom"
     ]).concat(u), c = c.concat(["marginLeft", "marginRight"]), l = r.concat(d)
     .concat(c), o.find("*[width]").each(function() {
      var i = e(this),
       s = {
        height: i.height(),
        width: i.width(),
        outerHeight: i.outerHeight(),
        outerWidth: i.outerWidth()
       };
      f && e.effects.save(i, l), i.from = {
        height: s.height * a.from.y,
        width: s.width * a.from.x,
        outerHeight: s.outerHeight * a.from.y,
        outerWidth: s.outerWidth * a.from.x
       }, i.to = {
        height: s.height * a.to.y,
        width: s.width * a.to.x,
        outerHeight: s.height * a.to.y,
        outerWidth: s.width * a.to.x
       }, a.from.y !== a.to.y && (i.from = e.effects.setTransition(i, d, a.from
        .y, i.from), i.to = e.effects.setTransition(i, d, a.to.y, i.to)), a.from
       .x !== a.to.x && (i.from = e.effects.setTransition(i, c, a.from.x, i.from),
        i.to = e.effects.setTransition(i, c, a.to.x, i.to)), i.css(i.from), i
       .animate(i.to, t.duration, t.easing, function() {
        f && e.effects.restore(i, l)
       })
     })), o.animate(o.to, {
     queue: !1,
     duration: t.duration,
     easing: t.easing,
     complete: function() {
      0 === o.to.opacity && o.css("opacity", o.from.opacity), "hide" === p &&
       o.hide(), e.effects.restore(o, y), f || ("static" === v ? o.css({
        position: "relative",
        top: o.to.top,
        left: o.to.left
       }) : e.each(["top", "left"], function(e, t) {
        o.css(t, function(t, i) {
         var s = parseInt(i, 10),
          n = e ? o.to.left : o.to.top;
         return "auto" === i ? n + "px" : s + n + "px"
        })
       })), e.effects.removeWrapper(o), i()
     }
    })
  }, e.effects.effect.scale = function(t, i) {
   var s = e(this),
    n = e.extend(!0, {}, t),
    a = e.effects.setMode(s, t.mode || "effect"),
    o = parseInt(t.percent, 10) || (0 === parseInt(t.percent, 10) ? 0 : "hide" ===
     a ? 0 : 100),
    r = t.direction || "both",
    h = t.origin,
    l = {
     height: s.height(),
     width: s.width(),
     outerHeight: s.outerHeight(),
     outerWidth: s.outerWidth()
    },
    u = {
     y: "horizontal" !== r ? o / 100 : 1,
     x: "vertical" !== r ? o / 100 : 1
    };
   n.effect = "size", n.queue = !1, n.complete = i, "effect" !== a && (n.origin =
    h || ["middle", "center"], n.restore = !0), n.from = t.from || ("show" ===
    a ? {
     height: 0,
     width: 0,
     outerHeight: 0,
     outerWidth: 0
    } : l), n.to = {
    height: l.height * u.y,
    width: l.width * u.x,
    outerHeight: l.outerHeight * u.y,
    outerWidth: l.outerWidth * u.x
   }, n.fade && ("show" === a && (n.from.opacity = 0, n.to.opacity = 1),
    "hide" === a && (n.from.opacity = 1, n.to.opacity = 0)), s.effect(n)
  }, e.effects.effect.puff = function(t, i) {
   var s = e(this),
    n = e.effects.setMode(s, t.mode || "hide"),
    a = "hide" === n,
    o = parseInt(t.percent, 10) || 150,
    r = o / 100,
    h = {
     height: s.height(),
     width: s.width(),
     outerHeight: s.outerHeight(),
     outerWidth: s.outerWidth()
    };
   e.extend(t, {
    effect: "scale",
    queue: !1,
    fade: !0,
    mode: n,
    complete: i,
    percent: a ? o : 100,
    from: a ? h : {
     height: h.height * r,
     width: h.width * r,
     outerHeight: h.outerHeight * r,
     outerWidth: h.outerWidth * r
    }
   }), s.effect(t)
  }, e.effects.effect.pulsate = function(t, i) {
   var s, n = e(this),
    a = e.effects.setMode(n, t.mode || "show"),
    o = "show" === a,
    r = "hide" === a,
    h = o || "hide" === a,
    l = 2 * (t.times || 5) + (h ? 1 : 0),
    u = t.duration / l,
    d = 0,
    c = n.queue(),
    p = c.length;
   for ((o || !n.is(":visible")) && (n.css("opacity", 0).show(), d = 1), s = 1; l >
    s; s++) n.animate({
    opacity: d
   }, u, t.easing), d = 1 - d;
   n.animate({
    opacity: d
   }, u, t.easing), n.queue(function() {
    r && n.hide(), i()
   }), p > 1 && c.splice.apply(c, [1, 0].concat(c.splice(p, l + 1))), n.dequeue()
  }, e.effects.effect.shake = function(t, i) {
   var s, n = e(this),
    a = ["position", "top", "bottom", "left", "right", "height", "width"],
    o = e.effects.setMode(n, t.mode || "effect"),
    r = t.direction || "left",
    h = t.distance || 20,
    l = t.times || 3,
    u = 2 * l + 1,
    d = Math.round(t.duration / u),
    c = "up" === r || "down" === r ? "top" : "left",
    p = "up" === r || "left" === r,
    f = {},
    m = {},
    g = {},
    v = n.queue(),
    y = v.length;
   for (e.effects.save(n, a), n.show(), e.effects.createWrapper(n), f[c] = (p ?
     "-=" : "+=") + h, m[c] = (p ? "+=" : "-=") + 2 * h, g[c] = (p ? "-=" :
     "+=") + 2 * h, n.animate(f, d, t.easing), s = 1; l > s; s++) n.animate(m,
    d, t.easing).animate(g, d, t.easing);
   n.animate(m, d, t.easing).animate(f, d / 2, t.easing).queue(function() {
    "hide" === o && n.hide(), e.effects.restore(n, a), e.effects.removeWrapper(
     n), i()
   }), y > 1 && v.splice.apply(v, [1, 0].concat(v.splice(y, u + 1))), n.dequeue()
  }, e.effects.effect.slide = function(t, i) {
   var s, n = e(this),
    a = ["position", "top", "bottom", "left", "right", "width", "height"],
    o = e.effects.setMode(n, t.mode || "show"),
    r = "show" === o,
    h = t.direction || "left",
    l = "up" === h || "down" === h ? "top" : "left",
    u = "up" === h || "left" === h,
    d = {};
   e.effects.save(n, a), n.show(), s = t.distance || n["top" === l ?
    "outerHeight" : "outerWidth"](!0), e.effects.createWrapper(n).css({
    overflow: "hidden"
   }), r && n.css(l, u ? isNaN(s) ? "-" + s : -s : s), d[l] = (r ? u ? "+=" :
    "-=" : u ? "-=" : "+=") + s, n.animate(d, {
    queue: !1,
    duration: t.duration,
    easing: t.easing,
    complete: function() {
     "hide" === o && n.hide(), e.effects.restore(n, a), e.effects.removeWrapper(
      n), i()
    }
   })
  }, e.effects.effect.transfer = function(t, i) {
   var s = e(this),
    n = e(t.to),
    a = "fixed" === n.css("position"),
    o = e("body"),
    r = a ? o.scrollTop() : 0,
    h = a ? o.scrollLeft() : 0,
    l = n.offset(),
    u = {
     top: l.top - r,
     left: l.left - h,
     height: n.innerHeight(),
     width: n.innerWidth()
    },
    d = s.offset(),
    c = e("<div class='ui-effects-transfer'></div>").appendTo(document.body).addClass(
     t.className).css({
     top: d.top - r,
     left: d.left - h,
     height: s.innerHeight(),
     width: s.innerWidth(),
     position: a ? "fixed" : "absolute"
    }).animate(u, t.duration, t.easing, function() {
     c.remove(), i()
    })
  }, e.widget("ui.progressbar", {
   version: "1.11.2",
   options: {
    max: 100,
    value: 0,
    change: null,
    complete: null
   },
   min: 0,
   _create: function() {
    this.oldValue = this.options.value = this._constrainedValue(), this.element
     .addClass("ui-progressbar ui-widget ui-widget-content ui-corner-all").attr({
      role: "progressbar",
      "aria-valuemin": this.min
     }), this.valueDiv = e(
      "<div class='ui-progressbar-value ui-widget-header ui-corner-left'></div>"
     ).appendTo(this.element), this._refreshValue()
   },
   _destroy: function() {
    this.element.removeClass(
     "ui-progressbar ui-widget ui-widget-content ui-corner-all").removeAttr(
     "role").removeAttr("aria-valuemin").removeAttr("aria-valuemax").removeAttr(
     "aria-valuenow"), this.valueDiv.remove()
   },
   value: function(e) {
    return void 0 === e ? this.options.value : (this.options.value = this._constrainedValue(
     e), this._refreshValue(), void 0)
   },
   _constrainedValue: function(e) {
    return void 0 === e && (e = this.options.value), this.indeterminate = e ===
     !1, "number" != typeof e && (e = 0), this.indeterminate ? !1 : Math.min(
      this.options.max, Math.max(this.min, e))
   },
   _setOptions: function(e) {
    var t = e.value;
    delete e.value, this._super(e), this.options.value = this._constrainedValue(
     t), this._refreshValue()
   },
   _setOption: function(e, t) {
    "max" === e && (t = Math.max(this.min, t)), "disabled" === e && this.element
     .toggleClass("ui-state-disabled", !!t).attr("aria-disabled", t), this._super(
      e, t)
   },
   _percentage: function() {
    return this.indeterminate ? 100 : 100 * (this.options.value - this.min) /
     (this.options.max - this.min)
   },
   _refreshValue: function() {
    var t = this.options.value,
     i = this._percentage();
    this.valueDiv.toggle(this.indeterminate || t > this.min).toggleClass(
      "ui-corner-right", t === this.options.max).width(i.toFixed(0) + "%"),
     this.element.toggleClass("ui-progressbar-indeterminate", this.indeterminate),
     this.indeterminate ? (this.element.removeAttr("aria-valuenow"), this.overlayDiv ||
      (this.overlayDiv = e("<div class='ui-progressbar-overlay'></div>").appendTo(
       this.valueDiv))) : (this.element.attr({
      "aria-valuemax": this.options.max,
      "aria-valuenow": t
     }), this.overlayDiv && (this.overlayDiv.remove(), this.overlayDiv =
      null)), this.oldValue !== t && (this.oldValue = t, this._trigger(
      "change")), t === this.options.max && this._trigger("complete")
   }
  }), e.widget("ui.selectable", e.ui.mouse, {
   version: "1.11.2",
   options: {
    appendTo: "body",
    autoRefresh: !0,
    distance: 0,
    filter: "*",
    tolerance: "touch",
    selected: null,
    selecting: null,
    start: null,
    stop: null,
    unselected: null,
    unselecting: null
   },
   _create: function() {
    var t, i = this;
    this.element.addClass("ui-selectable"), this.dragged = !1, this.refresh =
     function() {
      t = e(i.options.filter, i.element[0]), t.addClass("ui-selectee"), t.each(
       function() {
        var t = e(this),
         i = t.offset();
        e.data(this, "selectable-item", {
         element: this,
         $element: t,
         left: i.left,
         top: i.top,
         right: i.left + t.outerWidth(),
         bottom: i.top + t.outerHeight(),
         startselected: !1,
         selected: t.hasClass("ui-selected"),
         selecting: t.hasClass("ui-selecting"),
         unselecting: t.hasClass("ui-unselecting")
        })
       })
     }, this.refresh(), this.selectees = t.addClass("ui-selectee"), this._mouseInit(),
     this.helper = e("<div class='ui-selectable-helper'></div>")
   },
   _destroy: function() {
    this.selectees.removeClass("ui-selectee").removeData("selectable-item"),
     this.element.removeClass("ui-selectable ui-selectable-disabled"), this._mouseDestroy()
   },
   _mouseStart: function(t) {
    var i = this,
     s = this.options;
    this.opos = [t.pageX, t.pageY], this.options.disabled || (this.selectees =
     e(s.filter, this.element[0]), this._trigger("start", t), e(s.appendTo)
     .append(this.helper), this.helper.css({
      left: t.pageX,
      top: t.pageY,
      width: 0,
      height: 0
     }), s.autoRefresh && this.refresh(), this.selectees.filter(
      ".ui-selected").each(function() {
      var s = e.data(this, "selectable-item");
      s.startselected = !0, t.metaKey || t.ctrlKey || (s.$element.removeClass(
       "ui-selected"), s.selected = !1, s.$element.addClass(
       "ui-unselecting"), s.unselecting = !0, i._trigger("unselecting",
       t, {
        unselecting: s.element
       }))
     }), e(t.target).parents().addBack().each(function() {
      var s, n = e.data(this, "selectable-item");
      return n ? (s = !t.metaKey && !t.ctrlKey || !n.$element.hasClass(
        "ui-selected"), n.$element.removeClass(s ? "ui-unselecting" :
        "ui-selected").addClass(s ? "ui-selecting" : "ui-unselecting"), n
       .unselecting = !s, n.selecting = s, n.selected = s, s ? i._trigger(
        "selecting", t, {
         selecting: n.element
        }) : i._trigger("unselecting", t, {
        unselecting: n.element
       }), !1) : void 0
     }))
   },
   _mouseDrag: function(t) {
    if (this.dragged = !0, !this.options.disabled) {
     var i, s = this,
      n = this.options,
      a = this.opos[0],
      o = this.opos[1],
      r = t.pageX,
      h = t.pageY;
     return a > r && (i = r, r = a, a = i), o > h && (i = h, h = o, o = i),
      this.helper.css({
       left: a,
       top: o,
       width: r - a,
       height: h - o
      }), this.selectees.each(function() {
       var i = e.data(this, "selectable-item"),
        l = !1;
       i && i.element !== s.element[0] && ("touch" === n.tolerance ? l = !(
         i.left > r || a > i.right || i.top > h || o > i.bottom) : "fit" ===
        n.tolerance && (l = i.left > a && r > i.right && i.top > o && h >
         i.bottom), l ? (i.selected && (i.$element.removeClass(
         "ui-selected"), i.selected = !1), i.unselecting && (i.$element.removeClass(
         "ui-unselecting"), i.unselecting = !1), i.selecting || (i.$element
         .addClass("ui-selecting"), i.selecting = !0, s._trigger(
          "selecting", t, {
           selecting: i.element
          }))) : (i.selecting && ((t.metaKey || t.ctrlKey) && i.startselected ?
         (i.$element.removeClass("ui-selecting"), i.selecting = !1, i.$element
          .addClass("ui-selected"), i.selected = !0) : (i.$element.removeClass(
          "ui-selecting"), i.selecting = !1, i.startselected && (i.$element
          .addClass("ui-unselecting"), i.unselecting = !0), s._trigger(
          "unselecting", t, {
           unselecting: i.element
          }))), i.selected && (t.metaKey || t.ctrlKey || i.startselected ||
         (i.$element.removeClass("ui-selected"), i.selected = !1, i.$element
          .addClass("ui-unselecting"), i.unselecting = !0, s._trigger(
           "unselecting", t, {
            unselecting: i.element
           })))))
      }), !1
    }
   },
   _mouseStop: function(t) {
    var i = this;
    return this.dragged = !1, e(".ui-unselecting", this.element[0]).each(
     function() {
      var s = e.data(this, "selectable-item");
      s.$element.removeClass("ui-unselecting"), s.unselecting = !1, s.startselected = !
       1, i._trigger("unselected", t, {
        unselected: s.element
       })
     }), e(".ui-selecting", this.element[0]).each(function() {
     var s = e.data(this, "selectable-item");
     s.$element.removeClass("ui-selecting").addClass("ui-selected"), s.selecting = !
      1, s.selected = !0, s.startselected = !0, i._trigger("selected", t, {
       selected: s.element
      })
    }), this._trigger("stop", t), this.helper.remove(), !1
   }
  }), e.widget("ui.selectmenu", {
   version: "1.11.2",
   defaultElement: "<select>",
   options: {
    appendTo: null,
    disabled: null,
    icons: {
     button: "ui-icon-triangle-1-s"
    },
    position: {
     my: "left top",
     at: "left bottom",
     collision: "none"
    },
    width: null,
    change: null,
    close: null,
    focus: null,
    open: null,
    select: null
   },
   _create: function() {
    var e = this.element.uniqueId().attr("id");
    this.ids = {
     element: e,
     button: e + "-button",
     menu: e + "-menu"
    }, this._drawButton(), this._drawMenu(), this.options.disabled && this.disable()
   },
   _drawButton: function() {
    var t = this,
     i = this.element.attr("tabindex");
    this.label = e("label[for='" + this.ids.element + "']").attr("for", this
     .ids.button), this._on(this.label, {
     click: function(e) {
      this.button.focus(), e.preventDefault()
     }
    }), this.element.hide(), this.button = e("<span>", {
     "class": "ui-selectmenu-button ui-widget ui-state-default ui-corner-all",
     tabindex: i || this.options.disabled ? -1 : 0,
     id: this.ids.button,
     role: "combobox",
     "aria-expanded": "false",
     "aria-autocomplete": "list",
     "aria-owns": this.ids.menu,
     "aria-haspopup": "true"
    }).insertAfter(this.element), e("<span>", {
     "class": "ui-icon " + this.options.icons.button
    }).prependTo(this.button), this.buttonText = e("<span>", {
     "class": "ui-selectmenu-text"
    }).appendTo(this.button), this._setText(this.buttonText, this.element.find(
     "option:selected").text()), this._resizeButton(), this._on(this.button,
     this._buttonEvents), this.button.one("focusin", function() {
     t.menuItems || t._refreshMenu()
    }), this._hoverable(this.button), this._focusable(this.button)
   },
   _drawMenu: function() {
    var t = this;
    this.menu = e("<ul>", {
      "aria-hidden": "true",
      "aria-labelledby": this.ids.button,
      id: this.ids.menu
     }), this.menuWrap = e("<div>", {
      "class": "ui-selectmenu-menu ui-front"
     }).append(this.menu).appendTo(this._appendTo()), this.menuInstance =
     this.menu.menu({
      role: "listbox",
      select: function(e, i) {
       e.preventDefault(), t._setSelection(), t._select(i.item.data(
        "ui-selectmenu-item"), e)
      },
      focus: function(e, i) {
       var s = i.item.data("ui-selectmenu-item");
       null != t.focusIndex && s.index !== t.focusIndex && (t._trigger(
         "focus", e, {
          item: s
         }), t.isOpen || t._select(s, e)), t.focusIndex = s.index, t.button
        .attr("aria-activedescendant", t.menuItems.eq(s.index).attr("id"))
      }
     }).menu("instance"), this.menu.addClass("ui-corner-bottom").removeClass(
      "ui-corner-all"), this.menuInstance._off(this.menu, "mouseleave"),
     this.menuInstance._closeOnDocumentClick = function() {
      return !1
     }, this.menuInstance._isDivider = function() {
      return !1
     }
   },
   refresh: function() {
    this._refreshMenu(), this._setText(this.buttonText, this._getSelectedItem()
     .text()), this.options.width || this._resizeButton()
   },
   _refreshMenu: function() {
    this.menu.empty();
    var e, t = this.element.find("option");
    t.length && (this._parseOptions(t), this._renderMenu(this.menu, this.items),
     this.menuInstance.refresh(), this.menuItems = this.menu.find("li").not(
      ".ui-selectmenu-optgroup"), e = this._getSelectedItem(), this.menuInstance
     .focus(null, e), this._setAria(e.data("ui-selectmenu-item")), this._setOption(
      "disabled", this.element.prop("disabled")))
   },
   open: function(e) {
    this.options.disabled || (this.menuItems ? (this.menu.find(
      ".ui-state-focus").removeClass("ui-state-focus"), this.menuInstance.focus(
      null, this._getSelectedItem())) : this._refreshMenu(), this.isOpen = !
     0, this._toggleAttr(), this._resizeMenu(), this._position(), this._on(
      this.document, this._documentClick), this._trigger("open", e))
   },
   _position: function() {
    this.menuWrap.position(e.extend({
     of: this.button
    }, this.options.position))
   },
   close: function(e) {
    this.isOpen && (this.isOpen = !1, this._toggleAttr(), this.range = null,
     this._off(this.document), this._trigger("close", e))
   },
   widget: function() {
    return this.button
   },
   menuWidget: function() {
    return this.menu
   },
   _renderMenu: function(t, i) {
    var s = this,
     n = "";
    e.each(i, function(i, a) {
     a.optgroup !== n && (e("<li>", {
      "class": "ui-selectmenu-optgroup ui-menu-divider" + (a.element.parent(
       "optgroup").prop("disabled") ? " ui-state-disabled" : ""),
      text: a.optgroup
     }).appendTo(t), n = a.optgroup), s._renderItemData(t, a)
    })
   },
   _renderItemData: function(e, t) {
    return this._renderItem(e, t).data("ui-selectmenu-item", t)
   },
   _renderItem: function(t, i) {
    var s = e("<li>");
    return i.disabled && s.addClass("ui-state-disabled"), this._setText(s, i
     .label), s.appendTo(t)
   },
   _setText: function(e, t) {
    t ? e.text(t) : e.html("&#160;")
   },
   _move: function(e, t) {
    var i, s, n = ".ui-menu-item";
    this.isOpen ? i = this.menuItems.eq(this.focusIndex) : (i = this.menuItems
      .eq(this.element[0].selectedIndex), n += ":not(.ui-state-disabled)"),
     s = "first" === e || "last" === e ? i["first" === e ? "prevAll" :
      "nextAll"](n).eq(-1) : i[e + "All"](n).eq(0), s.length && this.menuInstance
     .focus(t, s)
   },
   _getSelectedItem: function() {
    return this.menuItems.eq(this.element[0].selectedIndex)
   },
   _toggle: function(e) {
    this[this.isOpen ? "close" : "open"](e)
   },
   _setSelection: function() {
    var e;
    this.range && (window.getSelection ? (e = window.getSelection(), e.removeAllRanges(),
     e.addRange(this.range)) : this.range.select(), this.button.focus())
   },
   _documentClick: {
    mousedown: function(t) {
     this.isOpen && (e(t.target).closest(".ui-selectmenu-menu, #" + this.ids
      .button).length || this.close(t))
    }
   },
   _buttonEvents: {
    mousedown: function() {
     var e;
     window.getSelection ? (e = window.getSelection(), e.rangeCount && (this
      .range = e.getRangeAt(0))) : this.range = document.selection.createRange()
    },
    click: function(e) {
     this._setSelection(), this._toggle(e)
    },
    keydown: function(t) {
     var i = !0;
     switch (t.keyCode) {
      case e.ui.keyCode.TAB:
      case e.ui.keyCode.ESCAPE:
       this.close(t), i = !1;
       break;
      case e.ui.keyCode.ENTER:
       this.isOpen && this._selectFocusedItem(t);
       break;
      case e.ui.keyCode.UP:
       t.altKey ? this._toggle(t) : this._move("prev", t);
       break;
      case e.ui.keyCode.DOWN:
       t.altKey ? this._toggle(t) : this._move("next", t);
       break;
      case e.ui.keyCode.SPACE:
       this.isOpen ? this._selectFocusedItem(t) : this._toggle(t);
       break;
      case e.ui.keyCode.LEFT:
       this._move("prev", t);
       break;
      case e.ui.keyCode.RIGHT:
       this._move("next", t);
       break;
      case e.ui.keyCode.HOME:
      case e.ui.keyCode.PAGE_UP:
       this._move("first", t);
       break;
      case e.ui.keyCode.END:
      case e.ui.keyCode.PAGE_DOWN:
       this._move("last", t);
       break;
      default:
       this.menu.trigger(t), i = !1
     }
     i && t.preventDefault()
    }
   },
   _selectFocusedItem: function(e) {
    var t = this.menuItems.eq(this.focusIndex);
    t.hasClass("ui-state-disabled") || this._select(t.data(
     "ui-selectmenu-item"), e)
   },
   _select: function(e, t) {
    var i = this.element[0].selectedIndex;
    this.element[0].selectedIndex = e.index, this._setText(this.buttonText,
     e.label), this._setAria(e), this._trigger("select", t, {
     item: e
    }), e.index !== i && this._trigger("change", t, {
     item: e
    }), this.close(t)
   },
   _setAria: function(e) {
    var t = this.menuItems.eq(e.index).attr("id");
    this.button.attr({
     "aria-labelledby": t,
     "aria-activedescendant": t
    }), this.menu.attr("aria-activedescendant", t)
   },
   _setOption: function(e, t) {
    "icons" === e && this.button.find("span.ui-icon").removeClass(this.options
      .icons.button).addClass(t.button), this._super(e, t), "appendTo" === e &&
     this.menuWrap.appendTo(this._appendTo()), "disabled" === e && (this.menuInstance
      .option("disabled", t), this.button.toggleClass("ui-state-disabled", t)
      .attr("aria-disabled", t), this.element.prop("disabled", t), t ? (this
       .button.attr("tabindex", -1), this.close()) : this.button.attr(
       "tabindex", 0)), "width" === e && this._resizeButton()
   },
   _appendTo: function() {
    var t = this.options.appendTo;
    return t && (t = t.jquery || t.nodeType ? e(t) : this.document.find(t).eq(
      0)), t && t[0] || (t = this.element.closest(".ui-front")), t.length ||
     (t = this.document[0].body), t
   },
   _toggleAttr: function() {
    this.button.toggleClass("ui-corner-top", this.isOpen).toggleClass(
      "ui-corner-all", !this.isOpen).attr("aria-expanded", this.isOpen),
     this.menuWrap.toggleClass("ui-selectmenu-open", this.isOpen), this.menu
     .attr("aria-hidden", !this.isOpen)
   },
   _resizeButton: function() {
    var e = this.options.width;
    e || (e = this.element.show().outerWidth(), this.element.hide()), this.button
     .outerWidth(e)
   },
   _resizeMenu: function() {
    this.menu.outerWidth(Math.max(this.button.outerWidth(), this.menu.width(
     "").outerWidth() + 1))
   },
   _getCreateOptions: function() {
    return {
     disabled: this.element.prop("disabled")
    }
   },
   _parseOptions: function(t) {
    var i = [];
    t.each(function(t, s) {
     var n = e(s),
      a = n.parent("optgroup");
     i.push({
      element: n,
      index: t,
      value: n.attr("value"),
      label: n.text(),
      optgroup: a.attr("label") || "",
      disabled: a.prop("disabled") || n.prop("disabled")
     })
    }), this.items = i
   },
   _destroy: function() {
    this.menuWrap.remove(), this.button.remove(), this.element.show(), this.element
     .removeUniqueId(), this.label.attr("for", this.ids.element)
   }
  }), e.widget("ui.slider", e.ui.mouse, {
   version: "1.11.2",
   widgetEventPrefix: "slide",
   options: {
    animate: !1,
    distance: 0,
    max: 100,
    min: 0,
    orientation: "horizontal",
    range: !1,
    step: 1,
    value: 0,
    values: null,
    change: null,
    slide: null,
    start: null,
    stop: null
   },
   numPages: 5,
   _create: function() {
    this._keySliding = !1, this._mouseSliding = !1, this._animateOff = !0,
     this._handleIndex = null, this._detectOrientation(), this._mouseInit(),
     this._calculateNewMax(), this.element.addClass("ui-slider ui-slider-" +
      this.orientation + " ui-widget" + " ui-widget-content" +
      " ui-corner-all"), this._refresh(), this._setOption("disabled", this.options
      .disabled), this._animateOff = !1
   },
   _refresh: function() {
    this._createRange(), this._createHandles(), this._setupEvents(), this._refreshValue()
   },
   _createHandles: function() {
    var t, i, s = this.options,
     n = this.element.find(".ui-slider-handle").addClass(
      "ui-state-default ui-corner-all"),
     a =
     "<span class='ui-slider-handle ui-state-default ui-corner-all' tabindex='0'></span>",
     o = [];
    for (i = s.values && s.values.length || 1, n.length > i && (n.slice(i).remove(),
      n = n.slice(0, i)), t = n.length; i > t; t++) o.push(a);
    this.handles = n.add(e(o.join("")).appendTo(this.element)), this.handle =
     this.handles.eq(0), this.handles.each(function(t) {
      e(this).data("ui-slider-handle-index", t)
     })
   },
   _createRange: function() {
    var t = this.options,
     i = "";
    t.range ? (t.range === !0 && (t.values ? t.values.length && 2 !== t.values
     .length ? t.values = [t.values[0], t.values[0]] : e.isArray(t.values) &&
     (t.values = t.values.slice(0)) : t.values = [this._valueMin(), this._valueMin()]
    ), this.range && this.range.length ? this.range.removeClass(
     "ui-slider-range-min ui-slider-range-max").css({
     left: "",
     bottom: ""
    }) : (this.range = e("<div></div>").appendTo(this.element), i =
     "ui-slider-range ui-widget-header ui-corner-all"), this.range.addClass(
     i + ("min" === t.range || "max" === t.range ? " ui-slider-range-" + t
      .range : ""))) : (this.range && this.range.remove(), this.range =
     null)
   },
   _setupEvents: function() {
    this._off(this.handles), this._on(this.handles, this._handleEvents),
     this._hoverable(this.handles), this._focusable(this.handles)
   },
   _destroy: function() {
    this.handles.remove(), this.range && this.range.remove(), this.element.removeClass(
     "ui-slider ui-slider-horizontal ui-slider-vertical ui-widget ui-widget-content ui-corner-all"
    ), this._mouseDestroy()
   },
   _mouseCapture: function(t) {
    var i, s, n, a, o, r, h, l, u = this,
     d = this.options;
    return d.disabled ? !1 : (this.elementSize = {
      width: this.element.outerWidth(),
      height: this.element.outerHeight()
     }, this.elementOffset = this.element.offset(), i = {
      x: t.pageX,
      y: t.pageY
     }, s = this._normValueFromMouse(i), n = this._valueMax() - this._valueMin() +
     1, this.handles.each(function(t) {
      var i = Math.abs(s - u.values(t));
      (n > i || n === i && (t === u._lastChangedValue || u.values(t) === d
       .min)) && (n = i, a = e(this), o = t)
     }), r = this._start(t, o), r === !1 ? !1 : (this._mouseSliding = !0,
      this._handleIndex = o, a.addClass("ui-state-active").focus(), h = a.offset(),
      l = !e(t.target).parents().addBack().is(".ui-slider-handle"), this._clickOffset =
      l ? {
       left: 0,
       top: 0
      } : {
       left: t.pageX - h.left - a.width() / 2,
       top: t.pageY - h.top - a.height() / 2 - (parseInt(a.css(
        "borderTopWidth"), 10) || 0) - (parseInt(a.css("borderBottomWidth"),
        10) || 0) + (parseInt(a.css("marginTop"), 10) || 0)
      }, this.handles.hasClass("ui-state-hover") || this._slide(t, o, s),
      this._animateOff = !0, !0))
   },
   _mouseStart: function() {
    return !0
   },
   _mouseDrag: function(e) {
    var t = {
      x: e.pageX,
      y: e.pageY
     },
     i = this._normValueFromMouse(t);
    return this._slide(e, this._handleIndex, i), !1
   },
   _mouseStop: function(e) {
    return this.handles.removeClass("ui-state-active"), this._mouseSliding = !
     1, this._stop(e, this._handleIndex), this._change(e, this._handleIndex),
     this._handleIndex = null, this._clickOffset = null, this._animateOff = !
     1, !1
   },
   _detectOrientation: function() {
    this.orientation = "vertical" === this.options.orientation ? "vertical" :
     "horizontal"
   },
   _normValueFromMouse: function(e) {
    var t, i, s, n, a;
    return "horizontal" === this.orientation ? (t = this.elementSize.width,
      i = e.x - this.elementOffset.left - (this._clickOffset ? this._clickOffset
       .left : 0)) : (t = this.elementSize.height, i = e.y - this.elementOffset
      .top - (this._clickOffset ? this._clickOffset.top : 0)), s = i / t, s >
     1 && (s = 1), 0 > s && (s = 0), "vertical" === this.orientation && (s =
      1 - s), n = this._valueMax() - this._valueMin(), a = this._valueMin() +
     s * n, this._trimAlignValue(a)
   },
   _start: function(e, t) {
    var i = {
     handle: this.handles[t],
     value: this.value()
    };
    return this.options.values && this.options.values.length && (i.value =
     this.values(t), i.values = this.values()), this._trigger("start", e, i)
   },
   _slide: function(e, t, i) {
    var s, n, a;
    this.options.values && this.options.values.length ? (s = this.values(t ?
       0 : 1), 2 === this.options.values.length && this.options.range === !0 &&
      (0 === t && i > s || 1 === t && s > i) && (i = s), i !== this.values(t) &&
      (n = this.values(), n[t] = i, a = this._trigger("slide", e, {
       handle: this.handles[t],
       value: i,
       values: n
      }), s = this.values(t ? 0 : 1), a !== !1 && this.values(t, i))) : i !==
     this.value() && (a = this._trigger("slide", e, {
      handle: this.handles[t],
      value: i
     }), a !== !1 && this.value(i))
   },
   _stop: function(e, t) {
    var i = {
     handle: this.handles[t],
     value: this.value()
    };
    this.options.values && this.options.values.length && (i.value = this.values(
     t), i.values = this.values()), this._trigger("stop", e, i)
   },
   _change: function(e, t) {
    if (!this._keySliding && !this._mouseSliding) {
     var i = {
      handle: this.handles[t],
      value: this.value()
     };
     this.options.values && this.options.values.length && (i.value = this.values(
      t), i.values = this.values()), this._lastChangedValue = t, this._trigger(
      "change", e, i)
    }
   },
   value: function(e) {
    return arguments.length ? (this.options.value = this._trimAlignValue(e),
     this._refreshValue(), this._change(null, 0), void 0) : this._value()
   },
   values: function(t, i) {
    var s, n, a;
    if (arguments.length > 1) return this.options.values[t] = this._trimAlignValue(
     i), this._refreshValue(), this._change(null, t), void 0;
    if (!arguments.length) return this._values();
    if (!e.isArray(arguments[0])) return this.options.values && this.options
     .values.length ? this._values(t) : this.value();
    for (s = this.options.values, n = arguments[0], a = 0; s.length > a; a +=
     1) s[a] = this._trimAlignValue(n[a]), this._change(null, a);
    this._refreshValue()
   },
   _setOption: function(t, i) {
    var s, n = 0;
    switch ("range" === t && this.options.range === !0 && ("min" === i ? (
      this.options.value = this._values(0), this.options.values = null) :
     "max" === i && (this.options.value = this._values(this.options.values.length -
      1), this.options.values = null)), e.isArray(this.options.values) && (
     n = this.options.values.length), "disabled" === t && this.element.toggleClass(
     "ui-state-disabled", !!i), this._super(t, i), t) {
     case "orientation":
      this._detectOrientation(), this.element.removeClass(
       "ui-slider-horizontal ui-slider-vertical").addClass("ui-slider-" +
       this.orientation), this._refreshValue(), this.handles.css(
       "horizontal" === i ? "bottom" : "left", "");
      break;
     case "value":
      this._animateOff = !0, this._refreshValue(), this._change(null, 0),
       this._animateOff = !1;
      break;
     case "values":
      for (this._animateOff = !0, this._refreshValue(), s = 0; n > s; s += 1)
       this._change(null, s);
      this._animateOff = !1;
      break;
     case "step":
     case "min":
     case "max":
      this._animateOff = !0, this._calculateNewMax(), this._refreshValue(),
       this._animateOff = !1;
      break;
     case "range":
      this._animateOff = !0, this._refresh(), this._animateOff = !1
    }
   },
   _value: function() {
    var e = this.options.value;
    return e = this._trimAlignValue(e)
   },
   _values: function(e) {
    var t, i, s;
    if (arguments.length) return t = this.options.values[e], t = this._trimAlignValue(
     t);
    if (this.options.values && this.options.values.length) {
     for (i = this.options.values.slice(), s = 0; i.length > s; s += 1) i[s] =
      this._trimAlignValue(i[s]);
     return i
    }
    return []
   },
   _trimAlignValue: function(e) {
    if (this._valueMin() >= e) return this._valueMin();
    if (e >= this._valueMax()) return this._valueMax();
    var t = this.options.step > 0 ? this.options.step : 1,
     i = (e - this._valueMin()) % t,
     s = e - i;
    return 2 * Math.abs(i) >= t && (s += i > 0 ? t : -t), parseFloat(s.toFixed(
     5))
   },
   _calculateNewMax: function() {
    var e = (this.options.max - this._valueMin()) % this.options.step;
    this.max = this.options.max - e
   },
   _valueMin: function() {
    return this.options.min
   },
   _valueMax: function() {
    return this.max
   },
   _refreshValue: function() {
    var t, i, s, n, a, o = this.options.range,
     r = this.options,
     h = this,
     l = this._animateOff ? !1 : r.animate,
     u = {};
    this.options.values && this.options.values.length ? this.handles.each(
     function(s) {
      i = 100 * ((h.values(s) - h._valueMin()) / (h._valueMax() - h._valueMin())),
       u["horizontal" === h.orientation ? "left" : "bottom"] = i + "%", e(
        this).stop(1, 1)[l ? "animate" : "css"](u, r.animate), h.options.range ===
       !0 && ("horizontal" === h.orientation ? (0 === s && h.range.stop(1,
        1)[l ? "animate" : "css"]({
        left: i + "%"
       }, r.animate), 1 === s && h.range[l ? "animate" : "css"]({
        width: i - t + "%"
       }, {
        queue: !1,
        duration: r.animate
       })) : (0 === s && h.range.stop(1, 1)[l ? "animate" : "css"]({
        bottom: i + "%"
       }, r.animate), 1 === s && h.range[l ? "animate" : "css"]({
        height: i - t + "%"
       }, {
        queue: !1,
        duration: r.animate
       }))), t = i
     }) : (s = this.value(), n = this._valueMin(), a = this._valueMax(), i =
     a !== n ? 100 * ((s - n) / (a - n)) : 0, u["horizontal" === this.orientation ?
      "left" : "bottom"] = i + "%", this.handle.stop(1, 1)[l ? "animate" :
      "css"](u, r.animate), "min" === o && "horizontal" === this.orientation &&
     this.range.stop(1, 1)[l ? "animate" : "css"]({
      width: i + "%"
     }, r.animate), "max" === o && "horizontal" === this.orientation &&
     this.range[l ? "animate" : "css"]({
      width: 100 - i + "%"
     }, {
      queue: !1,
      duration: r.animate
     }), "min" === o && "vertical" === this.orientation && this.range.stop(
      1, 1)[l ? "animate" : "css"]({
      height: i + "%"
     }, r.animate), "max" === o && "vertical" === this.orientation && this.range[
      l ? "animate" : "css"]({
      height: 100 - i + "%"
     }, {
      queue: !1,
      duration: r.animate
     }))
   },
   _handleEvents: {
    keydown: function(t) {
     var i, s, n, a, o = e(t.target).data("ui-slider-handle-index");
     switch (t.keyCode) {
      case e.ui.keyCode.HOME:
      case e.ui.keyCode.END:
      case e.ui.keyCode.PAGE_UP:
      case e.ui.keyCode.PAGE_DOWN:
      case e.ui.keyCode.UP:
      case e.ui.keyCode.RIGHT:
      case e.ui.keyCode.DOWN:
      case e.ui.keyCode.LEFT:
       if (t.preventDefault(), !this._keySliding && (this._keySliding = !0,
         e(t.target).addClass("ui-state-active"), i = this._start(t, o), i ===
         !1)) return
     }
     switch (a = this.options.step, s = n = this.options.values && this.options
      .values.length ? this.values(o) : this.value(), t.keyCode) {
      case e.ui.keyCode.HOME:
       n = this._valueMin();
       break;
      case e.ui.keyCode.END:
       n = this._valueMax();
       break;
      case e.ui.keyCode.PAGE_UP:
       n = this._trimAlignValue(s + (this._valueMax() - this._valueMin()) /
        this.numPages);
       break;
      case e.ui.keyCode.PAGE_DOWN:
       n = this._trimAlignValue(s - (this._valueMax() - this._valueMin()) /
        this.numPages);
       break;
      case e.ui.keyCode.UP:
      case e.ui.keyCode.RIGHT:
       if (s === this._valueMax()) return;
       n = this._trimAlignValue(s + a);
       break;
      case e.ui.keyCode.DOWN:
      case e.ui.keyCode.LEFT:
       if (s === this._valueMin()) return;
       n = this._trimAlignValue(s - a)
     }
     this._slide(t, o, n)
    },
    keyup: function(t) {
     var i = e(t.target).data("ui-slider-handle-index");
     this._keySliding && (this._keySliding = !1, this._stop(t, i), this._change(
      t, i), e(t.target).removeClass("ui-state-active"))
    }
   }
  }), e.widget("ui.sortable", e.ui.mouse, {
   version: "1.11.2",
   widgetEventPrefix: "sort",
   ready: !1,
   options: {
    appendTo: "parent",
    axis: !1,
    connectWith: !1,
    containment: !1,
    cursor: "auto",
    cursorAt: !1,
    dropOnEmpty: !0,
    forcePlaceholderSize: !1,
    forceHelperSize: !1,
    grid: !1,
    handle: !1,
    helper: "original",
    items: "> *",
    opacity: !1,
    placeholder: !1,
    revert: !1,
    scroll: !0,
    scrollSensitivity: 20,
    scrollSpeed: 20,
    scope: "default",
    tolerance: "intersect",
    zIndex: 1e3,
    activate: null,
    beforeStop: null,
    change: null,
    deactivate: null,
    out: null,
    over: null,
    receive: null,
    remove: null,
    sort: null,
    start: null,
    stop: null,
    update: null
   },
   _isOverAxis: function(e, t, i) {
    return e >= t && t + i > e
   },
   _isFloating: function(e) {
    return /left|right/.test(e.css("float")) || /inline|table-cell/.test(e.css(
     "display"))
   },
   _create: function() {
    var e = this.options;
    this.containerCache = {}, this.element.addClass("ui-sortable"), this.refresh(),
     this.floating = this.items.length ? "x" === e.axis || this._isFloating(
      this.items[0].item) : !1, this.offset = this.element.offset(), this._mouseInit(),
     this._setHandleClassName(), this.ready = !0
   },
   _setOption: function(e, t) {
    this._super(e, t), "handle" === e && this._setHandleClassName()
   },
   _setHandleClassName: function() {
    this.element.find(".ui-sortable-handle").removeClass(
     "ui-sortable-handle"), e.each(this.items, function() {
     (this.instance.options.handle ? this.item.find(this.instance.options.handle) :
      this.item).addClass("ui-sortable-handle")
    })
   },
   _destroy: function() {
    this.element.removeClass("ui-sortable ui-sortable-disabled").find(
     ".ui-sortable-handle").removeClass("ui-sortable-handle"), this._mouseDestroy();
    for (var e = this.items.length - 1; e >= 0; e--) this.items[e].item.removeData(
     this.widgetName + "-item");
    return this
   },
   _mouseCapture: function(t, i) {
    var s = null,
     n = !1,
     a = this;
    return this.reverting ? !1 : this.options.disabled || "static" === this.options
     .type ? !1 : (this._refreshItems(t), e(t.target).parents().each(
       function() {
        return e.data(this, a.widgetName + "-item") === a ? (s = e(this), !1) :
         void 0
       }), e.data(t.target, a.widgetName + "-item") === a && (s = e(t.target)),
      s ? !this.options.handle || i || (e(this.options.handle, s).find("*").addBack()
       .each(function() {
        this === t.target && (n = !0)
       }), n) ? (this.currentItem = s, this._removeCurrentsFromItems(), !0) :
      !1 : !1)
   },
   _mouseStart: function(t, i, s) {
    var n, a, o = this.options;
    if (this.currentContainer = this, this.refreshPositions(), this.helper =
     this._createHelper(t), this._cacheHelperProportions(), this._cacheMargins(),
     this.scrollParent = this.helper.scrollParent(), this.offset = this.currentItem
     .offset(), this.offset = {
      top: this.offset.top - this.margins.top,
      left: this.offset.left - this.margins.left
     }, e.extend(this.offset, {
      click: {
       left: t.pageX - this.offset.left,
       top: t.pageY - this.offset.top
      },
      parent: this._getParentOffset(),
      relative: this._getRelativeOffset()
     }), this.helper.css("position", "absolute"), this.cssPosition = this.helper
     .css("position"), this.originalPosition = this._generatePosition(t),
     this.originalPageX = t.pageX, this.originalPageY = t.pageY, o.cursorAt &&
     this._adjustOffsetFromHelper(o.cursorAt), this.domPosition = {
      prev: this.currentItem.prev()[0],
      parent: this.currentItem.parent()[0]
     }, this.helper[0] !== this.currentItem[0] && this.currentItem.hide(),
     this._createPlaceholder(), o.containment && this._setContainment(), o.cursor &&
     "auto" !== o.cursor && (a = this.document.find("body"), this.storedCursor =
      a.css("cursor"), a.css("cursor", o.cursor), this.storedStylesheet = e(
       "<style>*{ cursor: " + o.cursor + " !important; }</style>").appendTo(
       a)), o.opacity && (this.helper.css("opacity") && (this._storedOpacity =
      this.helper.css("opacity")), this.helper.css("opacity", o.opacity)), o
     .zIndex && (this.helper.css("zIndex") && (this._storedZIndex = this.helper
      .css("zIndex")), this.helper.css("zIndex", o.zIndex)), this.scrollParent[
      0] !== document && "HTML" !== this.scrollParent[0].tagName && (this.overflowOffset =
      this.scrollParent.offset()), this._trigger("start", t, this._uiHash()),
     this._preserveHelperProportions || this._cacheHelperProportions(), !s)
     for (n = this.containers.length - 1; n >= 0; n--) this.containers[n]._trigger(
      "activate", t, this._uiHash(this));
    return e.ui.ddmanager && (e.ui.ddmanager.current = this), e.ui.ddmanager &&
     !o.dropBehaviour && e.ui.ddmanager.prepareOffsets(this, t), this.dragging = !
     0, this.helper.addClass("ui-sortable-helper"), this._mouseDrag(t), !0
   },
   _mouseDrag: function(t) {
    var i, s, n, a, o = this.options,
     r = !1;
    for (this.position = this._generatePosition(t), this.positionAbs = this._convertPositionTo(
      "absolute"), this.lastPositionAbs || (this.lastPositionAbs = this.positionAbs),
     this.options.scroll && (this.scrollParent[0] !== document && "HTML" !==
      this.scrollParent[0].tagName ? (this.overflowOffset.top + this.scrollParent[
        0].offsetHeight - t.pageY < o.scrollSensitivity ? this.scrollParent[
        0].scrollTop = r = this.scrollParent[0].scrollTop + o.scrollSpeed :
       t.pageY - this.overflowOffset.top < o.scrollSensitivity && (this.scrollParent[
        0].scrollTop = r = this.scrollParent[0].scrollTop - o.scrollSpeed),
       this.overflowOffset.left + this.scrollParent[0].offsetWidth - t.pageX <
       o.scrollSensitivity ? this.scrollParent[0].scrollLeft = r = this.scrollParent[
        0].scrollLeft + o.scrollSpeed : t.pageX - this.overflowOffset.left <
       o.scrollSensitivity && (this.scrollParent[0].scrollLeft = r = this.scrollParent[
        0].scrollLeft - o.scrollSpeed)) : (t.pageY - e(document).scrollTop() <
       o.scrollSensitivity ? r = e(document).scrollTop(e(document).scrollTop() -
        o.scrollSpeed) : e(window).height() - (t.pageY - e(document).scrollTop()) <
       o.scrollSensitivity && (r = e(document).scrollTop(e(document).scrollTop() +
        o.scrollSpeed)), t.pageX - e(document).scrollLeft() < o.scrollSensitivity ?
       r = e(document).scrollLeft(e(document).scrollLeft() - o.scrollSpeed) :
       e(window).width() - (t.pageX - e(document).scrollLeft()) < o.scrollSensitivity &&
       (r = e(document).scrollLeft(e(document).scrollLeft() + o.scrollSpeed))
      ), r !== !1 && e.ui.ddmanager && !o.dropBehaviour && e.ui.ddmanager.prepareOffsets(
       this, t)), this.positionAbs = this._convertPositionTo("absolute"),
     this.options.axis && "y" === this.options.axis || (this.helper[0].style
      .left = this.position.left + "px"), this.options.axis && "x" === this.options
     .axis || (this.helper[0].style.top = this.position.top + "px"), i =
     this.items.length - 1; i >= 0; i--)
     if (s = this.items[i], n = s.item[0], a = this._intersectsWithPointer(s),
      a && s.instance === this.currentContainer && n !== this.currentItem[0] &&
      this.placeholder[1 === a ? "next" : "prev"]()[0] !== n && !e.contains(
       this.placeholder[0], n) && ("semi-dynamic" === this.options.type ? !e
       .contains(this.element[0], n) : !0)) {
      if (this.direction = 1 === a ? "down" : "up", "pointer" !== this.options
       .tolerance && !this._intersectsWithSides(s)) break;
      this._rearrange(t, s), this._trigger("change", t, this._uiHash());
      break
     }
    return this._contactContainers(t), e.ui.ddmanager && e.ui.ddmanager.drag(
      this, t), this._trigger("sort", t, this._uiHash()), this.lastPositionAbs =
     this.positionAbs, !1
   },
   _mouseStop: function(t, i) {
    if (t) {
     if (e.ui.ddmanager && !this.options.dropBehaviour && e.ui.ddmanager.drop(
       this, t), this.options.revert) {
      var s = this,
       n = this.placeholder.offset(),
       a = this.options.axis,
       o = {};
      a && "x" !== a || (o.left = n.left - this.offset.parent.left - this.margins
        .left + (this.offsetParent[0] === document.body ? 0 : this.offsetParent[
         0].scrollLeft)), a && "y" !== a || (o.top = n.top - this.offset.parent
        .top - this.margins.top + (this.offsetParent[0] === document.body ?
         0 : this.offsetParent[0].scrollTop)), this.reverting = !0, e(this.helper)
       .animate(o, parseInt(this.options.revert, 10) || 500, function() {
        s._clear(t)
       })
     } else this._clear(t, i);
     return !1
    }
   },
   cancel: function() {
    if (this.dragging) {
     this._mouseUp({
       target: null
      }), "original" === this.options.helper ? this.currentItem.css(this._storedCSS)
      .removeClass("ui-sortable-helper") : this.currentItem.show();
     for (var t = this.containers.length - 1; t >= 0; t--) this.containers[t]
      ._trigger("deactivate", null, this._uiHash(this)), this.containers[t].containerCache
      .over && (this.containers[t]._trigger("out", null, this._uiHash(this)),
       this.containers[t].containerCache.over = 0)
    }
    return this.placeholder && (this.placeholder[0].parentNode && this.placeholder[
      0].parentNode.removeChild(this.placeholder[0]), "original" !== this.options
     .helper && this.helper && this.helper[0].parentNode && this.helper.remove(),
     e.extend(this, {
      helper: null,
      dragging: !1,
      reverting: !1,
      _noFinalSort: null
     }), this.domPosition.prev ? e(this.domPosition.prev).after(this.currentItem) :
     e(this.domPosition.parent).prepend(this.currentItem)), this
   },
   serialize: function(t) {
    var i = this._getItemsAsjQuery(t && t.connected),
     s = [];
    return t = t || {}, e(i).each(function() {
     var i = (e(t.item || this).attr(t.attribute || "id") || "").match(t.expression ||
      /(.+)[\-=_](.+)/);
     i && s.push((t.key || i[1] + "[]") + "=" + (t.key && t.expression ? i[
      1] : i[2]))
    }), !s.length && t.key && s.push(t.key + "="), s.join("&")
   },
   toArray: function(t) {
    var i = this._getItemsAsjQuery(t && t.connected),
     s = [];
    return t = t || {}, i.each(function() {
     s.push(e(t.item || this).attr(t.attribute || "id") || "")
    }), s
   },
   _intersectsWith: function(e) {
    var t = this.positionAbs.left,
     i = t + this.helperProportions.width,
     s = this.positionAbs.top,
     n = s + this.helperProportions.height,
     a = e.left,
     o = a + e.width,
     r = e.top,
     h = r + e.height,
     l = this.offset.click.top,
     u = this.offset.click.left,
     d = "x" === this.options.axis || s + l > r && h > s + l,
     c = "y" === this.options.axis || t + u > a && o > t + u,
     p = d && c;
    return "pointer" === this.options.tolerance || this.options.forcePointerForContainers ||
     "pointer" !== this.options.tolerance && this.helperProportions[this.floating ?
      "width" : "height"] > e[this.floating ? "width" : "height"] ? p : t +
     this.helperProportions.width / 2 > a && o > i - this.helperProportions.width /
     2 && s + this.helperProportions.height / 2 > r && h > n - this.helperProportions
     .height / 2
   },
   _intersectsWithPointer: function(e) {
    var t = "x" === this.options.axis || this._isOverAxis(this.positionAbs.top +
      this.offset.click.top, e.top, e.height),
     i = "y" === this.options.axis || this._isOverAxis(this.positionAbs.left +
      this.offset.click.left, e.left, e.width),
     s = t && i,
     n = this._getDragVerticalDirection(),
     a = this._getDragHorizontalDirection();
    return s ? this.floating ? a && "right" === a || "down" === n ? 2 : 1 :
     n && ("down" === n ? 2 : 1) : !1
   },
   _intersectsWithSides: function(e) {
    var t = this._isOverAxis(this.positionAbs.top + this.offset.click.top, e
      .top + e.height / 2, e.height),
     i = this._isOverAxis(this.positionAbs.left + this.offset.click.left, e.left +
      e.width / 2, e.width),
     s = this._getDragVerticalDirection(),
     n = this._getDragHorizontalDirection();
    return this.floating && n ? "right" === n && i || "left" === n && !i : s &&
     ("down" === s && t || "up" === s && !t)
   },
   _getDragVerticalDirection: function() {
    var e = this.positionAbs.top - this.lastPositionAbs.top;
    return 0 !== e && (e > 0 ? "down" : "up")
   },
   _getDragHorizontalDirection: function() {
    var e = this.positionAbs.left - this.lastPositionAbs.left;
    return 0 !== e && (e > 0 ? "right" : "left")
   },
   refresh: function(e) {
    return this._refreshItems(e), this._setHandleClassName(), this.refreshPositions(),
     this
   },
   _connectWith: function() {
    var e = this.options;
    return e.connectWith.constructor === String ? [e.connectWith] : e.connectWith
   },
   _getItemsAsjQuery: function(t) {
    function i() {
     r.push(this)
    }
    var s, n, a, o, r = [],
     h = [],
     l = this._connectWith();
    if (l && t)
     for (s = l.length - 1; s >= 0; s--)
      for (a = e(l[s]), n = a.length - 1; n >= 0; n--) o = e.data(a[n], this
       .widgetFullName), o && o !== this && !o.options.disabled && h.push([
       e.isFunction(o.options.items) ? o.options.items.call(o.element) : e(
        o.options.items, o.element).not(".ui-sortable-helper").not(
        ".ui-sortable-placeholder"), o
      ]);
    for (h.push([e.isFunction(this.options.items) ? this.options.items.call(
      this.element, null, {
       options: this.options,
       item: this.currentItem
      }) : e(this.options.items, this.element).not(".ui-sortable-helper").not(
      ".ui-sortable-placeholder"), this]), s = h.length - 1; s >= 0; s--) h[
     s][0].each(i);
    return e(r)
   },
   _removeCurrentsFromItems: function() {
    var t = this.currentItem.find(":data(" + this.widgetName + "-item)");
    this.items = e.grep(this.items, function(e) {
     for (var i = 0; t.length > i; i++)
      if (t[i] === e.item[0]) return !1;
     return !0
    })
   },
   _refreshItems: function(t) {
    this.items = [], this.containers = [this];
    var i, s, n, a, o, r, h, l, u = this.items,
     d = [
      [e.isFunction(this.options.items) ? this.options.items.call(this.element[
       0], t, {
       item: this.currentItem
      }) : e(this.options.items, this.element), this]
     ],
     c = this._connectWith();
    if (c && this.ready)
     for (i = c.length - 1; i >= 0; i--)
      for (n = e(c[i]), s = n.length - 1; s >= 0; s--) a = e.data(n[s], this
       .widgetFullName), a && a !== this && !a.options.disabled && (d.push(
       [e.isFunction(a.options.items) ? a.options.items.call(a.element[0],
        t, {
         item: this.currentItem
        }) : e(a.options.items, a.element), a]), this.containers.push(a));
    for (i = d.length - 1; i >= 0; i--)
     for (o = d[i][1], r = d[i][0], s = 0, l = r.length; l > s; s++) h = e(r[
      s]), h.data(this.widgetName + "-item", o), u.push({
      item: h,
      instance: o,
      width: 0,
      height: 0,
      left: 0,
      top: 0
     })
   },
   refreshPositions: function(t) {
    this.offsetParent && this.helper && (this.offset.parent = this._getParentOffset());
    var i, s, n, a;
    for (i = this.items.length - 1; i >= 0; i--) s = this.items[i], s.instance !==
     this.currentContainer && this.currentContainer && s.item[0] !== this.currentItem[
      0] || (n = this.options.toleranceElement ? e(this.options.toleranceElement,
       s.item) : s.item, t || (s.width = n.outerWidth(), s.height = n.outerHeight()),
      a = n.offset(), s.left = a.left, s.top = a.top);
    if (this.options.custom && this.options.custom.refreshContainers) this.options
     .custom.refreshContainers.call(this);
    else
     for (i = this.containers.length - 1; i >= 0; i--) a = this.containers[i]
      .element.offset(), this.containers[i].containerCache.left = a.left,
      this.containers[i].containerCache.top = a.top, this.containers[i].containerCache
      .width = this.containers[i].element.outerWidth(), this.containers[i].containerCache
      .height = this.containers[i].element.outerHeight();
    return this
   },
   _createPlaceholder: function(t) {
    t = t || this;
    var i, s = t.options;
    s.placeholder && s.placeholder.constructor !== String || (i = s.placeholder,
      s.placeholder = {
       element: function() {
        var s = t.currentItem[0].nodeName.toLowerCase(),
         n = e("<" + s + ">", t.document[0]).addClass(i || t.currentItem[0]
          .className + " ui-sortable-placeholder").removeClass(
          "ui-sortable-helper");
        return "tr" === s ? t.currentItem.children().each(function() {
          e("<td>&#160;</td>", t.document[0]).attr("colspan", e(this).attr(
           "colspan") || 1).appendTo(n)
         }) : "img" === s && n.attr("src", t.currentItem.attr("src")), i ||
         n.css("visibility", "hidden"), n
       },
       update: function(e, n) {
        (!i || s.forcePlaceholderSize) && (n.height() || n.height(t.currentItem
          .innerHeight() - parseInt(t.currentItem.css("paddingTop") || 0,
           10) - parseInt(t.currentItem.css("paddingBottom") || 0, 10)), n.width() ||
         n.width(t.currentItem.innerWidth() - parseInt(t.currentItem.css(
          "paddingLeft") || 0, 10) - parseInt(t.currentItem.css(
          "paddingRight") || 0, 10)))
       }
      }), t.placeholder = e(s.placeholder.element.call(t.element, t.currentItem)),
     t.currentItem.after(t.placeholder), s.placeholder.update(t, t.placeholder)
   },
   _contactContainers: function(t) {
    var i, s, n, a, o, r, h, l, u, d, c = null,
     p = null;
    for (i = this.containers.length - 1; i >= 0; i--)
     if (!e.contains(this.currentItem[0], this.containers[i].element[0]))
      if (this._intersectsWith(this.containers[i].containerCache)) {
       if (c && e.contains(this.containers[i].element[0], c.element[0]))
        continue;
       c = this.containers[i], p = i
      } else this.containers[i].containerCache.over && (this.containers[i]._trigger(
        "out", t, this._uiHash(this)), this.containers[i].containerCache.over =
       0);
    if (c)
     if (1 === this.containers.length) this.containers[p].containerCache.over ||
      (this.containers[p]._trigger("over", t, this._uiHash(this)), this.containers[
       p].containerCache.over = 1);
     else {
      for (n = 1e4, a = null, u = c.floating || this._isFloating(this.currentItem),
       o = u ? "left" : "top", r = u ? "width" : "height", d = u ? "clientX" :
       "clientY", s = this.items.length - 1; s >= 0; s--) e.contains(this.containers[
        p].element[0], this.items[s].item[0]) && this.items[s].item[0] !==
       this.currentItem[0] && (h = this.items[s].item.offset()[o], l = !1, t[
         d] - h > this.items[s][r] / 2 && (l = !0), n > Math.abs(t[d] - h) &&
        (n = Math.abs(t[d] - h), a = this.items[s], this.direction = l ?
         "up" : "down"));
      if (!a && !this.options.dropOnEmpty) return;
      if (this.currentContainer === this.containers[p]) return this.currentContainer
       .containerCache.over || (this.containers[p]._trigger("over", t, this
        ._uiHash()), this.currentContainer.containerCache.over = 1), void 0;
      a ? this._rearrange(t, a, null, !0) : this._rearrange(t, null, this.containers[
        p].element, !0), this._trigger("change", t, this._uiHash()), this.containers[
        p]._trigger("change", t, this._uiHash(this)), this.currentContainer =
       this.containers[p], this.options.placeholder.update(this.currentContainer,
        this.placeholder), this.containers[p]._trigger("over", t, this._uiHash(
        this)), this.containers[p].containerCache.over = 1
     }
   },
   _createHelper: function(t) {
    var i = this.options,
     s = e.isFunction(i.helper) ? e(i.helper.apply(this.element[0], [t, this
      .currentItem
     ])) : "clone" === i.helper ? this.currentItem.clone() : this.currentItem;
    return s.parents("body").length || e("parent" !== i.appendTo ? i.appendTo :
     this.currentItem[0].parentNode)[0].appendChild(s[0]), s[0] === this.currentItem[
     0] && (this._storedCSS = {
     width: this.currentItem[0].style.width,
     height: this.currentItem[0].style.height,
     position: this.currentItem.css("position"),
     top: this.currentItem.css("top"),
     left: this.currentItem.css("left")
    }), (!s[0].style.width || i.forceHelperSize) && s.width(this.currentItem
     .width()), (!s[0].style.height || i.forceHelperSize) && s.height(this.currentItem
     .height()), s
   },
   _adjustOffsetFromHelper: function(t) {
    "string" == typeof t && (t = t.split(" ")), e.isArray(t) && (t = {
      left: +t[0],
      top: +t[1] || 0
     }), "left" in t && (this.offset.click.left = t.left + this.margins.left),
     "right" in t && (this.offset.click.left = this.helperProportions.width -
      t.right + this.margins.left), "top" in t && (this.offset.click.top = t
      .top + this.margins.top), "bottom" in t && (this.offset.click.top =
      this.helperProportions.height - t.bottom + this.margins.top)
   },
   _getParentOffset: function() {
    this.offsetParent = this.helper.offsetParent();
    var t = this.offsetParent.offset();
    return "absolute" === this.cssPosition && this.scrollParent[0] !==
     document && e.contains(this.scrollParent[0], this.offsetParent[0]) && (
      t.left += this.scrollParent.scrollLeft(), t.top += this.scrollParent.scrollTop()
     ), (this.offsetParent[0] === document.body || this.offsetParent[0].tagName &&
      "html" === this.offsetParent[0].tagName.toLowerCase() && e.ui.ie) && (
      t = {
       top: 0,
       left: 0
      }), {
      top: t.top + (parseInt(this.offsetParent.css("borderTopWidth"), 10) ||
       0),
      left: t.left + (parseInt(this.offsetParent.css("borderLeftWidth"), 10) ||
       0)
     }
   },
   _getRelativeOffset: function() {
    if ("relative" === this.cssPosition) {
     var e = this.currentItem.position();
     return {
      top: e.top - (parseInt(this.helper.css("top"), 10) || 0) + this.scrollParent
       .scrollTop(),
      left: e.left - (parseInt(this.helper.css("left"), 10) || 0) + this.scrollParent
       .scrollLeft()
     }
    }
    return {
     top: 0,
     left: 0
    }
   },
   _cacheMargins: function() {
    this.margins = {
     left: parseInt(this.currentItem.css("marginLeft"), 10) || 0,
     top: parseInt(this.currentItem.css("marginTop"), 10) || 0
    }
   },
   _cacheHelperProportions: function() {
    this.helperProportions = {
     width: this.helper.outerWidth(),
     height: this.helper.outerHeight()
    }
   },
   _setContainment: function() {
    var t, i, s, n = this.options;
    "parent" === n.containment && (n.containment = this.helper[0].parentNode), (
     "document" === n.containment || "window" === n.containment) && (this.containment = [
     0 - this.offset.relative.left - this.offset.parent.left, 0 - this.offset
     .relative.top - this.offset.parent.top, e("document" === n.containment ?
      document : window).width() - this.helperProportions.width - this.margins
     .left, (e("document" === n.containment ? document : window).height() ||
      document.body.parentNode.scrollHeight) - this.helperProportions.height -
     this.margins.top
    ]), /^(document|window|parent)$/.test(n.containment) || (t = e(n.containment)[
     0], i = e(n.containment).offset(), s = "hidden" !== e(t).css(
     "overflow"), this.containment = [i.left + (parseInt(e(t).css(
      "borderLeftWidth"), 10) || 0) + (parseInt(e(t).css("paddingLeft"),
      10) || 0) - this.margins.left, i.top + (parseInt(e(t).css(
      "borderTopWidth"), 10) || 0) + (parseInt(e(t).css("paddingTop"), 10) ||
      0) - this.margins.top, i.left + (s ? Math.max(t.scrollWidth, t.offsetWidth) :
      t.offsetWidth) - (parseInt(e(t).css("borderLeftWidth"), 10) || 0) -
     (parseInt(e(t).css("paddingRight"), 10) || 0) - this.helperProportions
     .width - this.margins.left, i.top + (s ? Math.max(t.scrollHeight, t.offsetHeight) :
      t.offsetHeight) - (parseInt(e(t).css("borderTopWidth"), 10) || 0) -
     (parseInt(e(t).css("paddingBottom"), 10) || 0) - this.helperProportions
     .height - this.margins.top
    ])
   },
   _convertPositionTo: function(t, i) {
    i || (i = this.position);
    var s = "absolute" === t ? 1 : -1,
     n = "absolute" !== this.cssPosition || this.scrollParent[0] !==
     document && e.contains(this.scrollParent[0], this.offsetParent[0]) ?
     this.scrollParent : this.offsetParent,
     a = /(html|body)/i.test(n[0].tagName);
    return {
     top: i.top + this.offset.relative.top * s + this.offset.parent.top * s -
      ("fixed" === this.cssPosition ? -this.scrollParent.scrollTop() : a ? 0 :
       n.scrollTop()) * s,
     left: i.left + this.offset.relative.left * s + this.offset.parent.left *
      s - ("fixed" === this.cssPosition ? -this.scrollParent.scrollLeft() :
       a ? 0 : n.scrollLeft()) * s
    }
   },
   _generatePosition: function(t) {
    var i, s, n = this.options,
     a = t.pageX,
     o = t.pageY,
     r = "absolute" !== this.cssPosition || this.scrollParent[0] !==
     document && e.contains(this.scrollParent[0], this.offsetParent[0]) ?
     this.scrollParent : this.offsetParent,
     h = /(html|body)/i.test(r[0].tagName);
    return "relative" !== this.cssPosition || this.scrollParent[0] !==
     document && this.scrollParent[0] !== this.offsetParent[0] || (this.offset
      .relative = this._getRelativeOffset()), this.originalPosition && (this
      .containment && (t.pageX - this.offset.click.left < this.containment[0] &&
       (a = this.containment[0] + this.offset.click.left), t.pageY - this.offset
       .click.top < this.containment[1] && (o = this.containment[1] + this.offset
        .click.top), t.pageX - this.offset.click.left > this.containment[2] &&
       (a = this.containment[2] + this.offset.click.left), t.pageY - this.offset
       .click.top > this.containment[3] && (o = this.containment[3] + this.offset
        .click.top)), n.grid && (i = this.originalPageY + Math.round((o -
        this.originalPageY) / n.grid[1]) * n.grid[1], o = this.containment ?
       i - this.offset.click.top >= this.containment[1] && i - this.offset.click
       .top <= this.containment[3] ? i : i - this.offset.click.top >= this.containment[
        1] ? i - n.grid[1] : i + n.grid[1] : i, s = this.originalPageX +
       Math.round((a - this.originalPageX) / n.grid[0]) * n.grid[0], a =
       this.containment ? s - this.offset.click.left >= this.containment[0] &&
       s - this.offset.click.left <= this.containment[2] ? s : s - this.offset
       .click.left >= this.containment[0] ? s - n.grid[0] : s + n.grid[0] :
       s)), {
      top: o - this.offset.click.top - this.offset.relative.top - this.offset
       .parent.top + ("fixed" === this.cssPosition ? -this.scrollParent.scrollTop() :
        h ? 0 : r.scrollTop()),
      left: a - this.offset.click.left - this.offset.relative.left - this.offset
       .parent.left + ("fixed" === this.cssPosition ? -this.scrollParent.scrollLeft() :
        h ? 0 : r.scrollLeft())
     }
   },
   _rearrange: function(e, t, i, s) {
    i ? i[0].appendChild(this.placeholder[0]) : t.item[0].parentNode.insertBefore(
     this.placeholder[0], "down" === this.direction ? t.item[0] : t.item[0]
     .nextSibling), this.counter = this.counter ? ++this.counter : 1;
    var n = this.counter;
    this._delay(function() {
     n === this.counter && this.refreshPositions(!s)
    })
   },
   _clear: function(e, t) {
    function i(e, t, i) {
     return function(s) {
      i._trigger(e, s, t._uiHash(t))
     }
    }
    this.reverting = !1;
    var s, n = [];
    if (!this._noFinalSort && this.currentItem.parent().length && this.placeholder
     .before(this.currentItem), this._noFinalSort = null, this.helper[0] ===
     this.currentItem[0]) {
     for (s in this._storedCSS)("auto" === this._storedCSS[s] || "static" ===
      this._storedCSS[s]) && (this._storedCSS[s] = "");
     this.currentItem.css(this._storedCSS).removeClass("ui-sortable-helper")
    } else this.currentItem.show();
    for (this.fromOutside && !t && n.push(function(e) {
      this._trigger("receive", e, this._uiHash(this.fromOutside))
     }), !this.fromOutside && this.domPosition.prev === this.currentItem.prev()
     .not(".ui-sortable-helper")[0] && this.domPosition.parent === this.currentItem
     .parent()[0] || t || n.push(function(e) {
      this._trigger("update", e, this._uiHash())
     }), this !== this.currentContainer && (t || (n.push(function(e) {
      this._trigger("remove", e, this._uiHash())
     }), n.push(function(e) {
      return function(t) {
       e._trigger("receive", t, this._uiHash(this))
      }
     }.call(this, this.currentContainer)), n.push(function(e) {
      return function(t) {
       e._trigger("update", t, this._uiHash(this))
      }
     }.call(this, this.currentContainer)))), s = this.containers.length - 1; s >=
     0; s--) t || n.push(i("deactivate", this, this.containers[s])), this.containers[
     s].containerCache.over && (n.push(i("out", this, this.containers[s])),
     this.containers[s].containerCache.over = 0);
    if (this.storedCursor && (this.document.find("body").css("cursor", this.storedCursor),
      this.storedStylesheet.remove()), this._storedOpacity && this.helper.css(
      "opacity", this._storedOpacity), this._storedZIndex && this.helper.css(
      "zIndex", "auto" === this._storedZIndex ? "" : this._storedZIndex),
     this.dragging = !1, t || this._trigger("beforeStop", e, this._uiHash()),
     this.placeholder[0].parentNode.removeChild(this.placeholder[0]), this.cancelHelperRemoval ||
     (this.helper[0] !== this.currentItem[0] && this.helper.remove(), this.helper =
      null), !t) {
     for (s = 0; n.length > s; s++) n[s].call(this, e);
     this._trigger("stop", e, this._uiHash())
    }
    return this.fromOutside = !1, !this.cancelHelperRemoval
   },
   _trigger: function() {
    e.Widget.prototype._trigger.apply(this, arguments) === !1 && this.cancel()
   },
   _uiHash: function(t) {
    var i = t || this;
    return {
     helper: i.helper,
     placeholder: i.placeholder || e([]),
     position: i.position,
     originalPosition: i.originalPosition,
     offset: i.positionAbs,
     item: i.currentItem,
     sender: t ? t.element : null
    }
   }
  }), e.widget("ui.spinner", {
   version: "1.11.2",
   defaultElement: "<input>",
   widgetEventPrefix: "spin",
   options: {
    culture: null,
    icons: {
     down: "ui-icon-triangle-1-s",
     up: "ui-icon-triangle-1-n"
    },
    incremental: !0,
    max: null,
    min: null,
    numberFormat: null,
    page: 10,
    step: 1,
    change: null,
    spin: null,
    start: null,
    stop: null
   },
   _create: function() {
    this._setOption("max", this.options.max), this._setOption("min", this.options
      .min), this._setOption("step", this.options.step), "" !== this.value() &&
     this._value(this.element.val(), !0), this._draw(), this._on(this._events),
     this._refresh(), this._on(this.window, {
      beforeunload: function() {
       this.element.removeAttr("autocomplete")
      }
     })
   },
   _getCreateOptions: function() {
    var t = {},
     i = this.element;
    return e.each(["min", "max", "step"], function(e, s) {
     var n = i.attr(s);
     void 0 !== n && n.length && (t[s] = n)
    }), t
   },
   _events: {
    keydown: function(e) {
     this._start(e) && this._keydown(e) && e.preventDefault()
    },
    keyup: "_stop",
    focus: function() {
     this.previous = this.element.val()
    },
    blur: function(e) {
     return this.cancelBlur ? (delete this.cancelBlur, void 0) : (this._stop(),
      this._refresh(), this.previous !== this.element.val() && this._trigger(
       "change", e), void 0)
    },
    mousewheel: function(e, t) {
     if (t) {
      if (!this.spinning && !this._start(e)) return !1;
      this._spin((t > 0 ? 1 : -1) * this.options.step, e), clearTimeout(this
       .mousewheelTimer), this.mousewheelTimer = this._delay(function() {
       this.spinning && this._stop(e)
      }, 100), e.preventDefault()
     }
    },
    "mousedown .ui-spinner-button": function(t) {
     function i() {
      var e = this.element[0] === this.document[0].activeElement;
      e || (this.element.focus(), this.previous = s, this._delay(function() {
       this.previous = s
      }))
     }
     var s;
     s = this.element[0] === this.document[0].activeElement ? this.previous :
      this.element.val(), t.preventDefault(), i.call(this), this.cancelBlur = !
      0, this._delay(function() {
       delete this.cancelBlur, i.call(this)
      }), this._start(t) !== !1 && this._repeat(null, e(t.currentTarget).hasClass(
       "ui-spinner-up") ? 1 : -1, t)
    },
    "mouseup .ui-spinner-button": "_stop",
    "mouseenter .ui-spinner-button": function(t) {
     return e(t.currentTarget).hasClass("ui-state-active") ? this._start(t) ===
      !1 ? !1 : (this._repeat(null, e(t.currentTarget).hasClass(
       "ui-spinner-up") ? 1 : -1, t), void 0) : void 0
    },
    "mouseleave .ui-spinner-button": "_stop"
   },
   _draw: function() {
    var e = this.uiSpinner = this.element.addClass("ui-spinner-input").attr(
     "autocomplete", "off").wrap(this._uiSpinnerHtml()).parent().append(
     this._buttonHtml());
    this.element.attr("role", "spinbutton"), this.buttons = e.find(
      ".ui-spinner-button").attr("tabIndex", -1).button().removeClass(
      "ui-corner-all"), this.buttons.height() > Math.ceil(.5 * e.height()) &&
     e.height() > 0 && e.height(e.height()), this.options.disabled && this.disable()
   },
   _keydown: function(t) {
    var i = this.options,
     s = e.ui.keyCode;
    switch (t.keyCode) {
     case s.UP:
      return this._repeat(null, 1, t), !0;
     case s.DOWN:
      return this._repeat(null, -1, t), !0;
     case s.PAGE_UP:
      return this._repeat(null, i.page, t), !0;
     case s.PAGE_DOWN:
      return this._repeat(null, -i.page, t), !0
    }
    return !1
   },
   _uiSpinnerHtml: function() {
    return
     "<span class='ui-spinner ui-widget ui-widget-content ui-corner-all'></span>"
   },
   _buttonHtml: function() {
    return
     "<a class='ui-spinner-button ui-spinner-up ui-corner-tr'><span class='ui-icon " +
     this.options.icons.up + "'>&#9650;</span>" + "</a>" +
     "<a class='ui-spinner-button ui-spinner-down ui-corner-br'>" +
     "<span class='ui-icon " + this.options.icons.down + "'>&#9660;</span>" +
     "</a>"
   },
   _start: function(e) {
    return this.spinning || this._trigger("start", e) !== !1 ? (this.counter ||
     (this.counter = 1), this.spinning = !0, !0) : !1
   },
   _repeat: function(e, t, i) {
    e = e || 500, clearTimeout(this.timer), this.timer = this._delay(
     function() {
      this._repeat(40, t, i)
     }, e), this._spin(t * this.options.step, i)
   },
   _spin: function(e, t) {
    var i = this.value() || 0;
    this.counter || (this.counter = 1), i = this._adjustValue(i + e * this._increment(
     this.counter)), this.spinning && this._trigger("spin", t, {
     value: i
    }) === !1 || (this._value(i), this.counter++)
   },
   _increment: function(t) {
    var i = this.options.incremental;
    return i ? e.isFunction(i) ? i(t) : Math.floor(t * t * t / 5e4 - t * t /
     500 + 17 * t / 200 + 1) : 1
   },
   _precision: function() {
    var e = this._precisionOf(this.options.step);
    return null !== this.options.min && (e = Math.max(e, this._precisionOf(
     this.options.min))), e
   },
   _precisionOf: function(e) {
    var t = "" + e,
     i = t.indexOf(".");
    return -1 === i ? 0 : t.length - i - 1
   },
   _adjustValue: function(e) {
    var t, i, s = this.options;
    return t = null !== s.min ? s.min : 0, i = e - t, i = Math.round(i / s.step) *
     s.step, e = t + i, e = parseFloat(e.toFixed(this._precision())), null !==
     s.max && e > s.max ? s.max : null !== s.min && s.min > e ? s.min : e
   },
   _stop: function(e) {
    this.spinning && (clearTimeout(this.timer), clearTimeout(this.mousewheelTimer),
     this.counter = 0, this.spinning = !1, this._trigger("stop", e))
   },
   _setOption: function(e, t) {
    if ("culture" === e || "numberFormat" === e) {
     var i = this._parse(this.element.val());
     return this.options[e] = t, this.element.val(this._format(i)), void 0
    }("max" === e || "min" === e || "step" === e) && "string" == typeof t &&
     (t = this._parse(t)), "icons" === e && (this.buttons.first().find(
       ".ui-icon").removeClass(this.options.icons.up).addClass(t.up), this.buttons
      .last().find(".ui-icon").removeClass(this.options.icons.down).addClass(
       t.down)), this._super(e, t), "disabled" === e && (this.widget().toggleClass(
       "ui-state-disabled", !!t), this.element.prop("disabled", !!t), this.buttons
      .button(t ? "disable" : "enable"))
   },
   _setOptions: h(function(e) {
    this._super(e)
   }),
   _parse: function(e) {
    return "string" == typeof e && "" !== e && (e = window.Globalize && this
     .options.numberFormat ? Globalize.parseFloat(e, 10, this.options.culture) :
     +e), "" === e || isNaN(e) ? null : e
   },
   _format: function(e) {
    return "" === e ? "" : window.Globalize && this.options.numberFormat ?
     Globalize.format(e, this.options.numberFormat, this.options.culture) :
     e
   },
   _refresh: function() {
    this.element.attr({
     "aria-valuemin": this.options.min,
     "aria-valuemax": this.options.max,
     "aria-valuenow": this._parse(this.element.val())
    })
   },
   isValid: function() {
    var e = this.value();
    return null === e ? !1 : e === this._adjustValue(e)
   },
   _value: function(e, t) {
    var i;
    "" !== e && (i = this._parse(e), null !== i && (t || (i = this._adjustValue(
     i)), e = this._format(i))), this.element.val(e), this._refresh()
   },
   _destroy: function() {
    this.element.removeClass("ui-spinner-input").prop("disabled", !1).removeAttr(
     "autocomplete").removeAttr("role").removeAttr("aria-valuemin").removeAttr(
     "aria-valuemax").removeAttr("aria-valuenow"), this.uiSpinner.replaceWith(
     this.element)
   },
   stepUp: h(function(e) {
    this._stepUp(e)
   }),
   _stepUp: function(e) {
    this._start() && (this._spin((e || 1) * this.options.step), this._stop())
   },
   stepDown: h(function(e) {
    this._stepDown(e)
   }),
   _stepDown: function(e) {
    this._start() && (this._spin((e || 1) * -this.options.step), this._stop())
   },
   pageUp: h(function(e) {
    this._stepUp((e || 1) * this.options.page)
   }),
   pageDown: h(function(e) {
    this._stepDown((e || 1) * this.options.page)
   }),
   value: function(e) {
    return arguments.length ? (h(this._value).call(this, e), void 0) : this._parse(
     this.element.val())
   },
   widget: function() {
    return this.uiSpinner
   }
  }), e.widget("ui.tabs", {
   version: "1.11.2",
   delay: 300,
   options: {
    active: null,
    collapsible: !1,
    event: "click",
    heightStyle: "content",
    hide: null,
    show: null,
    activate: null,
    beforeActivate: null,
    beforeLoad: null,
    load: null
   },
   _isLocal: function() {
    var e = /#.*$/;
    return function(t) {
     var i, s;
     t = t.cloneNode(!1), i = t.href.replace(e, ""), s = location.href.replace(
      e, "");
     try {
      i = decodeURIComponent(i)
     } catch (n) {}
     try {
      s = decodeURIComponent(s)
     } catch (n) {}
     return t.hash.length > 1 && i === s
    }
   }(),
   _create: function() {
    var t = this,
     i = this.options;
    this.running = !1, this.element.addClass(
      "ui-tabs ui-widget ui-widget-content ui-corner-all").toggleClass(
      "ui-tabs-collapsible", i.collapsible), this._processTabs(), i.active =
     this._initialActive(), e.isArray(i.disabled) && (i.disabled = e.unique(
      i.disabled.concat(e.map(this.tabs.filter(".ui-state-disabled"),
       function(e) {
        return t.tabs.index(e)
       }))).sort()), this.active = this.options.active !== !1 && this.anchors
     .length ? this._findActive(i.active) : e(), this._refresh(), this.active
     .length && this.load(i.active)
   },
   _initialActive: function() {
    var t = this.options.active,
     i = this.options.collapsible,
     s = location.hash.substring(1);
    return null === t && (s && this.tabs.each(function(i, n) {
     return e(n).attr("aria-controls") === s ? (t = i, !1) : void 0
    }), null === t && (t = this.tabs.index(this.tabs.filter(
     ".ui-tabs-active"))), (null === t || -1 === t) && (t = this.tabs.length ?
     0 : !1)), t !== !1 && (t = this.tabs.index(this.tabs.eq(t)), -1 === t &&
     (t = i ? !1 : 0)), !i && t === !1 && this.anchors.length && (t = 0), t
   },
   _getCreateEventData: function() {
    return {
     tab: this.active,
     panel: this.active.length ? this._getPanelForTab(this.active) : e()
    }
   },
   _tabKeydown: function(t) {
    var i = e(this.document[0].activeElement).closest("li"),
     s = this.tabs.index(i),
     n = !0;
    if (!this._handlePageNav(t)) {
     switch (t.keyCode) {
      case e.ui.keyCode.RIGHT:
      case e.ui.keyCode.DOWN:
       s++;
       break;
      case e.ui.keyCode.UP:
      case e.ui.keyCode.LEFT:
       n = !1, s--;
       break;
      case e.ui.keyCode.END:
       s = this.anchors.length - 1;
       break;
      case e.ui.keyCode.HOME:
       s = 0;
       break;
      case e.ui.keyCode.SPACE:
       return t.preventDefault(), clearTimeout(this.activating), this._activate(
        s), void 0;
      case e.ui.keyCode.ENTER:
       return t.preventDefault(), clearTimeout(this.activating), this._activate(
        s === this.options.active ? !1 : s), void 0;
      default:
       return
     }
     t.preventDefault(), clearTimeout(this.activating), s = this._focusNextTab(
      s, n), t.ctrlKey || (i.attr("aria-selected", "false"), this.tabs.eq(s)
      .attr("aria-selected", "true"), this.activating = this._delay(
       function() {
        this.option("active", s)
       }, this.delay))
    }
   },
   _panelKeydown: function(t) {
    this._handlePageNav(t) || t.ctrlKey && t.keyCode === e.ui.keyCode.UP &&
     (t.preventDefault(), this.active.focus())
   },
   _handlePageNav: function(t) {
    return t.altKey && t.keyCode === e.ui.keyCode.PAGE_UP ? (this._activate(
      this._focusNextTab(this.options.active - 1, !1)), !0) : t.altKey && t.keyCode ===
     e.ui.keyCode.PAGE_DOWN ? (this._activate(this._focusNextTab(this.options
      .active + 1, !0)), !0) : void 0
   },
   _findNextTab: function(t, i) {
    function s() {
     return t > n && (t = 0), 0 > t && (t = n), t
    }
    for (var n = this.tabs.length - 1; - 1 !== e.inArray(s(), this.options.disabled);)
     t = i ? t + 1 : t - 1;
    return t
   },
   _focusNextTab: function(e, t) {
    return e = this._findNextTab(e, t), this.tabs.eq(e).focus(), e
   },
   _setOption: function(e, t) {
    return "active" === e ? (this._activate(t), void 0) : "disabled" === e ?
     (this._setupDisabled(t), void 0) : (this._super(e, t), "collapsible" ===
      e && (this.element.toggleClass("ui-tabs-collapsible", t), t || this.options
       .active !== !1 || this._activate(0)), "event" === e && this._setupEvents(
       t), "heightStyle" === e && this._setupHeightStyle(t), void 0)
   },
   _sanitizeSelector: function(e) {
    return e ? e.replace(/[!"$%&'()*+,.\/:;<=>?@\[\]\^`{|}~]/g, "\\$&") : ""
   },
   refresh: function() {
    var t = this.options,
     i = this.tablist.children(":has(a[href])");
    t.disabled = e.map(i.filter(".ui-state-disabled"), function(e) {
      return i.index(e)
     }), this._processTabs(), t.active !== !1 && this.anchors.length ? this.active
     .length && !e.contains(this.tablist[0], this.active[0]) ? this.tabs.length ===
     t.disabled.length ? (t.active = !1, this.active = e()) : this._activate(
      this._findNextTab(Math.max(0, t.active - 1), !1)) : t.active = this.tabs
     .index(this.active) : (t.active = !1, this.active = e()), this._refresh()
   },
   _refresh: function() {
    this._setupDisabled(this.options.disabled), this._setupEvents(this.options
     .event), this._setupHeightStyle(this.options.heightStyle), this.tabs.not(
     this.active).attr({
     "aria-selected": "false",
     "aria-expanded": "false",
     tabIndex: -1
    }), this.panels.not(this._getPanelForTab(this.active)).hide().attr({
     "aria-hidden": "true"
    }), this.active.length ? (this.active.addClass(
     "ui-tabs-active ui-state-active").attr({
     "aria-selected": "true",
     "aria-expanded": "true",
     tabIndex: 0
    }), this._getPanelForTab(this.active).show().attr({
     "aria-hidden": "false"
    })) : this.tabs.eq(0).attr("tabIndex", 0)
   },
   _processTabs: function() {
    var t = this,
     i = this.tabs,
     s = this.anchors,
     n = this.panels;
    this.tablist = this._getList().addClass(
     "ui-tabs-nav ui-helper-reset ui-helper-clearfix ui-widget-header ui-corner-all"
    ).attr("role", "tablist").delegate("> li", "mousedown" + this.eventNamespace,
     function(t) {
      e(this).is(".ui-state-disabled") && t.preventDefault()
     }).delegate(".ui-tabs-anchor", "focus" + this.eventNamespace, function() {
     e(this).closest("li").is(".ui-state-disabled") && this.blur()
    }), this.tabs = this.tablist.find("> li:has(a[href])").addClass(
     "ui-state-default ui-corner-top").attr({
     role: "tab",
     tabIndex: -1
    }), this.anchors = this.tabs.map(function() {
     return e("a", this)[0]
    }).addClass("ui-tabs-anchor").attr({
     role: "presentation",
     tabIndex: -1
    }), this.panels = e(), this.anchors.each(function(i, s) {
     var n, a, o, r = e(s).uniqueId().attr("id"),
      h = e(s).closest("li"),
      l = h.attr("aria-controls");
     t._isLocal(s) ? (n = s.hash, o = n.substring(1), a = t.element.find(t
       ._sanitizeSelector(n))) : (o = h.attr("aria-controls") || e({}).uniqueId()[
       0].id, n = "#" + o, a = t.element.find(n), a.length || (a = t._createPanel(
       o), a.insertAfter(t.panels[i - 1] || t.tablist)), a.attr(
       "aria-live", "polite")), a.length && (t.panels = t.panels.add(a)),
      l && h.data("ui-tabs-aria-controls", l), h.attr({
       "aria-controls": o,
       "aria-labelledby": r
      }), a.attr("aria-labelledby", r)
    }), this.panels.addClass(
     "ui-tabs-panel ui-widget-content ui-corner-bottom").attr("role",
     "tabpanel"), i && (this._off(i.not(this.tabs)), this._off(s.not(this.anchors)),
     this._off(n.not(this.panels)))
   },
   _getList: function() {
    return this.tablist || this.element.find("ol,ul").eq(0)
   },
   _createPanel: function(t) {
    return e("<div>").attr("id", t).addClass(
     "ui-tabs-panel ui-widget-content ui-corner-bottom").data(
     "ui-tabs-destroy", !0)
   },
   _setupDisabled: function(t) {
    e.isArray(t) && (t.length ? t.length === this.anchors.length && (t = !0) :
     t = !1);
    for (var i, s = 0; i = this.tabs[s]; s++) t === !0 || -1 !== e.inArray(s,
      t) ? e(i).addClass("ui-state-disabled").attr("aria-disabled", "true") :
     e(i).removeClass("ui-state-disabled").removeAttr("aria-disabled");
    this.options.disabled = t
   },
   _setupEvents: function(t) {
    var i = {};
    t && e.each(t.split(" "), function(e, t) {
     i[t] = "_eventHandler"
    }), this._off(this.anchors.add(this.tabs).add(this.panels)), this._on(!
     0, this.anchors, {
      click: function(e) {
       e.preventDefault()
      }
     }), this._on(this.anchors, i), this._on(this.tabs, {
     keydown: "_tabKeydown"
    }), this._on(this.panels, {
     keydown: "_panelKeydown"
    }), this._focusable(this.tabs), this._hoverable(this.tabs)
   },
   _setupHeightStyle: function(t) {
    var i, s = this.element.parent();
    "fill" === t ? (i = s.height(), i -= this.element.outerHeight() - this.element
     .height(), this.element.siblings(":visible").each(function() {
      var t = e(this),
       s = t.css("position");
      "absolute" !== s && "fixed" !== s && (i -= t.outerHeight(!0))
     }), this.element.children().not(this.panels).each(function() {
      i -= e(this).outerHeight(!0)
     }), this.panels.each(function() {
      e(this).height(Math.max(0, i - e(this).innerHeight() + e(this).height()))
     }).css("overflow", "auto")) : "auto" === t && (i = 0, this.panels.each(
     function() {
      i = Math.max(i, e(this).height("").height())
     }).height(i))
   },
   _eventHandler: function(t) {
    var i = this.options,
     s = this.active,
     n = e(t.currentTarget),
     a = n.closest("li"),
     o = a[0] === s[0],
     r = o && i.collapsible,
     h = r ? e() : this._getPanelForTab(a),
     l = s.length ? this._getPanelForTab(s) : e(),
     u = {
      oldTab: s,
      oldPanel: l,
      newTab: r ? e() : a,
      newPanel: h
     };
    t.preventDefault(), a.hasClass("ui-state-disabled") || a.hasClass(
     "ui-tabs-loading") || this.running || o && !i.collapsible || this._trigger(
     "beforeActivate", t, u) === !1 || (i.active = r ? !1 : this.tabs.index(
      a), this.active = o ? e() : a, this.xhr && this.xhr.abort(), l.length ||
     h.length || e.error("jQuery UI Tabs: Mismatching fragment identifier."),
     h.length && this.load(this.tabs.index(a), t), this._toggle(t, u))
   },
   _toggle: function(t, i) {
    function s() {
     a.running = !1, a._trigger("activate", t, i)
    }

    function n() {
     i.newTab.closest("li").addClass("ui-tabs-active ui-state-active"), o.length &&
      a.options.show ? a._show(o, a.options.show, s) : (o.show(), s())
    }
    var a = this,
     o = i.newPanel,
     r = i.oldPanel;
    this.running = !0, r.length && this.options.hide ? this._hide(r, this.options
      .hide,
      function() {
       i.oldTab.closest("li").removeClass("ui-tabs-active ui-state-active"),
        n()
      }) : (i.oldTab.closest("li").removeClass(
      "ui-tabs-active ui-state-active"), r.hide(), n()), r.attr(
      "aria-hidden", "true"), i.oldTab.attr({
      "aria-selected": "false",
      "aria-expanded": "false"
     }), o.length && r.length ? i.oldTab.attr("tabIndex", -1) : o.length &&
     this.tabs.filter(function() {
      return 0 === e(this).attr("tabIndex")
     }).attr("tabIndex", -1), o.attr("aria-hidden", "false"), i.newTab.attr({
      "aria-selected": "true",
      "aria-expanded": "true",
      tabIndex: 0
     })
   },
   _activate: function(t) {
    var i, s = this._findActive(t);
    s[0] !== this.active[0] && (s.length || (s = this.active), i = s.find(
     ".ui-tabs-anchor")[0], this._eventHandler({
     target: i,
     currentTarget: i,
     preventDefault: e.noop
    }))
   },
   _findActive: function(t) {
    return t === !1 ? e() : this.tabs.eq(t)
   },
   _getIndex: function(e) {
    return "string" == typeof e && (e = this.anchors.index(this.anchors.filter(
     "[href$='" + e + "']"))), e
   },
   _destroy: function() {
    this.xhr && this.xhr.abort(), this.element.removeClass(
      "ui-tabs ui-widget ui-widget-content ui-corner-all ui-tabs-collapsible"
     ), this.tablist.removeClass(
      "ui-tabs-nav ui-helper-reset ui-helper-clearfix ui-widget-header ui-corner-all"
     ).removeAttr("role"), this.anchors.removeClass("ui-tabs-anchor").removeAttr(
      "role").removeAttr("tabIndex").removeUniqueId(), this.tablist.unbind(
      this.eventNamespace), this.tabs.add(this.panels).each(function() {
      e.data(this, "ui-tabs-destroy") ? e(this).remove() : e(this).removeClass(
       "ui-state-default ui-state-active ui-state-disabled ui-corner-top ui-corner-bottom ui-widget-content ui-tabs-active ui-tabs-panel"
      ).removeAttr("tabIndex").removeAttr("aria-live").removeAttr(
       "aria-busy").removeAttr("aria-selected").removeAttr(
       "aria-labelledby").removeAttr("aria-hidden").removeAttr(
       "aria-expanded").removeAttr("role")
     }), this.tabs.each(function() {
      var t = e(this),
       i = t.data("ui-tabs-aria-controls");
      i ? t.attr("aria-controls", i).removeData("ui-tabs-aria-controls") :
       t.removeAttr("aria-controls")
     }), this.panels.show(), "content" !== this.options.heightStyle && this.panels
     .css("height", "")
   },
   enable: function(t) {
    var i = this.options.disabled;
    i !== !1 && (void 0 === t ? i = !1 : (t = this._getIndex(t), i = e.isArray(
     i) ? e.map(i, function(e) {
     return e !== t ? e : null
    }) : e.map(this.tabs, function(e, i) {
     return i !== t ? i : null
    })), this._setupDisabled(i))
   },
   disable: function(t) {
    var i = this.options.disabled;
    if (i !== !0) {
     if (void 0 === t) i = !0;
     else {
      if (t = this._getIndex(t), -1 !== e.inArray(t, i)) return;
      i = e.isArray(i) ? e.merge([t], i).sort() : [t]
     }
     this._setupDisabled(i)
    }
   },
   load: function(t, i) {
    t = this._getIndex(t);
    var s = this,
     n = this.tabs.eq(t),
     a = n.find(".ui-tabs-anchor"),
     o = this._getPanelForTab(n),
     r = {
      tab: n,
      panel: o
     };
    this._isLocal(a[0]) || (this.xhr = e.ajax(this._ajaxSettings(a, i, r)),
     this.xhr && "canceled" !== this.xhr.statusText && (n.addClass(
      "ui-tabs-loading"), o.attr("aria-busy", "true"), this.xhr.success(
      function(e) {
       setTimeout(function() {
        o.html(e), s._trigger("load", i, r)
       }, 1)
      }).complete(function(e, t) {
      setTimeout(function() {
       "abort" === t && s.panels.stop(!1, !0), n.removeClass(
         "ui-tabs-loading"), o.removeAttr("aria-busy"), e === s.xhr &&
        delete s.xhr
      }, 1)
     })))
   },
   _ajaxSettings: function(t, i, s) {
    var n = this;
    return {
     url: t.attr("href"),
     beforeSend: function(t, a) {
      return n._trigger("beforeLoad", i, e.extend({
       jqXHR: t,
       ajaxSettings: a
      }, s))
     }
    }
   },
   _getPanelForTab: function(t) {
    var i = e(t).attr("aria-controls");
    return this.element.find(this._sanitizeSelector("#" + i))
   }
  }), e.widget("ui.tooltip", {
   version: "1.11.2",
   options: {
    content: function() {
     var t = e(this).attr("title") || "";
     return e("<a>").text(t).html()
    },
    hide: !0,
    items: "[title]:not([disabled])",
    position: {
     my: "left top+15",
     at: "left bottom",
     collision: "flipfit flip"
    },
    show: !0,
    tooltipClass: null,
    track: !1,
    close: null,
    open: null
   },
   _addDescribedBy: function(t, i) {
    var s = (t.attr("aria-describedby") || "").split(/\s+/);
    s.push(i), t.data("ui-tooltip-id", i).attr("aria-describedby", e.trim(s.join(
     " ")))
   },
   _removeDescribedBy: function(t) {
    var i = t.data("ui-tooltip-id"),
     s = (t.attr("aria-describedby") || "").split(/\s+/),
     n = e.inArray(i, s); - 1 !== n && s.splice(n, 1), t.removeData(
     "ui-tooltip-id"), s = e.trim(s.join(" ")), s ? t.attr(
     "aria-describedby", s) : t.removeAttr("aria-describedby")
   },
   _create: function() {
    this._on({
      mouseover: "open",
      focusin: "open"
     }), this.tooltips = {}, this.parents = {}, this.options.disabled &&
     this._disable(), this.liveRegion = e("<div>").attr({
      role: "log",
      "aria-live": "assertive",
      "aria-relevant": "additions"
     }).addClass("ui-helper-hidden-accessible").appendTo(this.document[0].body)
   },
   _setOption: function(t, i) {
    var s = this;
    return "disabled" === t ? (this[i ? "_disable" : "_enable"](), this.options[
     t] = i, void 0) : (this._super(t, i), "content" === t && e.each(this.tooltips,
     function(e, t) {
      s._updateContent(t.element)
     }), void 0)
   },
   _disable: function() {
    var t = this;
    e.each(this.tooltips, function(i, s) {
     var n = e.Event("blur");
     n.target = n.currentTarget = s.element[0], t.close(n, !0)
    }), this.element.find(this.options.items).addBack().each(function() {
     var t = e(this);
     t.is("[title]") && t.data("ui-tooltip-title", t.attr("title")).removeAttr(
      "title")
    })
   },
   _enable: function() {
    this.element.find(this.options.items).addBack().each(function() {
     var t = e(this);
     t.data("ui-tooltip-title") && t.attr("title", t.data(
      "ui-tooltip-title"))
    })
   },
   open: function(t) {
    var i = this,
     s = e(t ? t.target : this.element).closest(this.options.items);
    s.length && !s.data("ui-tooltip-id") && (s.attr("title") && s.data(
      "ui-tooltip-title", s.attr("title")), s.data("ui-tooltip-open", !0),
     t && "mouseover" === t.type && s.parents().each(function() {
      var t, s = e(this);
      s.data("ui-tooltip-open") && (t = e.Event("blur"), t.target = t.currentTarget =
       this, i.close(t, !0)), s.attr("title") && (s.uniqueId(), i.parents[
       this.id] = {
       element: this,
       title: s.attr("title")
      }, s.attr("title", ""))
     }), this._updateContent(s, t))
   },
   _updateContent: function(e, t) {
    var i, s = this.options.content,
     n = this,
     a = t ? t.type : null;
    return "string" == typeof s ? this._open(t, e, s) : (i = s.call(e[0],
     function(i) {
      e.data("ui-tooltip-open") && n._delay(function() {
       t && (t.type = a), this._open(t, e, i)
      })
     }), i && this._open(t, e, i), void 0)
   },
   _open: function(t, i, s) {
    function n(e) {
     u.of = e, o.is(":hidden") || o.position(u)
    }
    var a, o, r, h, l, u = e.extend({}, this.options.position);
    if (s) {
     if (a = this._find(i)) return a.tooltip.find(".ui-tooltip-content").html(
      s), void 0;
     i.is("[title]") && (t && "mouseover" === t.type ? i.attr("title", "") :
       i.removeAttr("title")), a = this._tooltip(i), o = a.tooltip, this._addDescribedBy(
       i, o.attr("id")), o.find(".ui-tooltip-content").html(s), this.liveRegion
      .children().hide(), s.clone ? (l = s.clone(), l.removeAttr("id").find(
       "[id]").removeAttr("id")) : l = s, e("<div>").html(l).appendTo(this.liveRegion),
      this.options.track && t && /^mouse/.test(t.type) ? (this._on(this.document, {
       mousemove: n
      }), n(t)) : o.position(e.extend({
       of: i
      }, this.options.position)), o.hide(), this._show(o, this.options.show),
      this.options.show && this.options.show.delay && (h = this.delayedShow =
       setInterval(function() {
        o.is(":visible") && (n(u.of), clearInterval(h))
       }, e.fx.interval)), this._trigger("open", t, {
       tooltip: o
      }), r = {
       keyup: function(t) {
        if (t.keyCode === e.ui.keyCode.ESCAPE) {
         var s = e.Event(t);
         s.currentTarget = i[0], this.close(s, !0)
        }
       }
      }, i[0] !== this.element[0] && (r.remove = function() {
       this._removeTooltip(o)
      }), t && "mouseover" !== t.type || (r.mouseleave = "close"), t &&
      "focusin" !== t.type || (r.focusout = "close"), this._on(!0, i, r)
    }
   },
   close: function(t) {
    var i, s = this,
     n = e(t ? t.currentTarget : this.element),
     a = this._find(n);
    a && (i = a.tooltip, a.closing || (clearInterval(this.delayedShow), n.data(
      "ui-tooltip-title") && !n.attr("title") && n.attr("title", n.data(
      "ui-tooltip-title")), this._removeDescribedBy(n), a.hiding = !0, i.stop(!
      0), this._hide(i, this.options.hide, function() {
      s._removeTooltip(e(this))
     }), n.removeData("ui-tooltip-open"), this._off(n,
      "mouseleave focusout keyup"), n[0] !== this.element[0] && this._off(
      n, "remove"), this._off(this.document, "mousemove"), t &&
     "mouseleave" === t.type && e.each(this.parents, function(t, i) {
      e(i.element).attr("title", i.title), delete s.parents[t]
     }), a.closing = !0, this._trigger("close", t, {
      tooltip: i
     }), a.hiding || (a.closing = !1)))
   },
   _tooltip: function(t) {
    var i = e("<div>").attr("role", "tooltip").addClass(
      "ui-tooltip ui-widget ui-corner-all ui-widget-content " + (this.options
       .tooltipClass || "")),
     s = i.uniqueId().attr("id");
    return e("<div>").addClass("ui-tooltip-content").appendTo(i), i.appendTo(
     this.document[0].body), this.tooltips[s] = {
     element: t,
     tooltip: i
    }
   },
   _find: function(e) {
    var t = e.data("ui-tooltip-id");
    return t ? this.tooltips[t] : null
   },
   _removeTooltip: function(e) {
    e.remove(), delete this.tooltips[e.attr("id")]
   },
   _destroy: function() {
    var t = this;
    e.each(this.tooltips, function(i, s) {
     var n = e.Event("blur"),
      a = s.element;
     n.target = n.currentTarget = a[0], t.close(n, !0), e("#" + i).remove(),
      a.data("ui-tooltip-title") && (a.attr("title") || a.attr("title", a.data(
       "ui-tooltip-title")), a.removeData("ui-tooltip-title"))
    }), this.liveRegion.remove()
   }
  })
});

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

!function(a){var b=function(){window.asyncWebshims||(window.asyncWebshims={cfg:[],ready:[]})},c=function(){window.jQuery&&(a(jQuery),a=function(){return window.webshims})};window.webshims={setOptions:function(){b(),window.asyncWebshims.cfg.push(arguments)},ready:function(){b(),window.asyncWebshims.ready.push(arguments)},activeLang:function(a){b(),window.asyncWebshims.lang=a},polyfill:function(a){b(),window.asyncWebshims.polyfill=a},_curScript:function(){var a,b,c,d,e,f=document.currentScript;if(!f){try{throw new Error("")}catch(g){for(c=(g.sourceURL||g.stack||"").split("\n"),e=/(?:fil|htt|wid|abo|app|res)(.)+/i,b=0;b<c.length;b++)if(d=c[b].match(e)){c=d[0].replace(/[\:\s\(]+[\d\:\)\(\s]+$/,"");break}}for(a=document.scripts||document.getElementsByTagName("script"),b=0;b<a.length&&(!a[b].getAttribute("src")||(f=a[b],"interactive"!=a[b].readyState&&c!=a[b].src));b++);}return f}()},window.webshim=window.webshims,window.webshims.timer=setInterval(c,0),c(),"function"==typeof define&&define.amd&&define("polyfiller",["jquery"],a)}(function(a){"use strict";function b(a){return document.createElement(a)}var c,d,e=window.navigator,f=window.webshims,g="dom-support",h=a.event.special,i=a([]),j=window.asyncWebshims,k={},l=window.Object,m=function(a){return a+"\n//# sourceURL="+this.url},n=function(a){return q.enhanceAuto||"auto"!=a?a:!1},o={matchmedia:"matchMedia",xhr2:"filereader",promise:"es6",URL:"url"},p="capture"in b("input");clearInterval(f.timer),k.advancedObjectProperties=k.objectAccessor=k.ES5=!!("create"in l&&"seal"in l),!k.ES5||"toJSON"in Date.prototype||(k.ES5=!1),d=a.support.hrefNormalized===!1?f._curScript.getAttribute("src",4):f._curScript.src,d=d.split("?")[0].slice(0,d.lastIndexOf("/")+1)+"shims/",a.extend(f,{version:"1.15.5",cfg:{enhanceAuto:window.Audio&&(!window.matchMedia||matchMedia("(min-device-width: 721px)").matches),waitReady:!0,loadStyles:!0,wsdoc:document,wspopover:{appendTo:"auto",hideOnBlur:!0},ajax:{},loadScript:function(b,c){a.ajax(a.extend({},q.ajax,{url:b,success:c,dataType:"script",cache:!0,global:!1,dataFilter:m}))},basePath:d},support:k,bugs:{},modules:{},features:{},featureList:[],setOptions:function(b,c){"string"==typeof b&&arguments.length>1?q[b]=a.isPlainObject(c)?a.extend(!0,q[b]||{},c):c:"object"==typeof b&&a.extend(!0,q,b)},_getAutoEnhance:n,addPolyfill:function(b,c){c=c||{};var d=c.f||b;r[d]||(r[d]=[],f.featureList.push(d),q[d]={}),r[d].push(b),c.options=a.extend(q[d],c.options),y(b,c),c.methodNames&&a.each(c.methodNames,function(a,b){f.addMethodName(b)})},polyfill:function(){return function(a){a||(a=f.featureList),"string"==typeof a&&(a=a.split(" "));return f._polyfill(a)}}(),_polyfill:function(b){var d,e,f=[];c.run||(d=-1!==a.inArray("forms-ext",b),c(),e=d&&!v["form-number-date-ui"].test()||!p&&-1!==a.inArray("mediacapture",b),d&&-1==a.inArray("forms",b)&&b.push("forms"),q.loadStyles&&w.loadCSS("styles/shim"+(e?"-ext":"")+".css")),q.waitReady&&(a.readyWait++,t(b,function(){a.ready(!0)})),a.each(b,function(a,b){return b=o[b]||b,r[b]?(b!==r[b][0]&&t(r[b],function(){s(b,!0)}),void(f=f.concat(r[b]))):void s(b,!0)}),x(f),a.each(b,function(a,b){var c=q[b];c&&("mediaelement"==b&&(c.replaceUI=n(c.replaceUI))&&c.plugins.unshift("mediacontrols"),c.plugins&&c.plugins.length&&x(q[b].plugins))})},reTest:function(){var b,c=function(c,d){var e=v[d],f=d+"Ready";!e||e.loaded||(e.test&&a.isFunction(e.test)?e.test([]):e.test)||(h[f]&&delete h[f],r[e.f],b.push(d))};return function(d){"string"==typeof d&&(d=d.split(" ")),b=[],a.each(d,c),x(b)}}(),isReady:function(b,c){if(b+="Ready",c){if(h[b]&&h[b].add)return!0;h[b]=a.extend(h[b]||{},{add:function(a){a.handler.call(this,b)}}),a(document).triggerHandler(b)}return!(!h[b]||!h[b].add)||!1},ready:function(b,c){var d=arguments[2];if("string"==typeof b&&(b=b.split(" ")),d||(b=a.map(a.grep(b,function(a){return!s(a)}),function(a){return a+"Ready"})),!b.length)return void c(a,f,window,document);var e=b.shift(),g=function(){t(b,c,!0)};a(document).one(e,g)},capturingEvents:function(b,c){document.addEventListener&&("string"==typeof b&&(b=[b]),a.each(b,function(b,d){var e=function(b){return b=a.event.fix(b),c&&f.capturingEventPrevented&&f.capturingEventPrevented(b),a.event.dispatch.call(this,b)};h[d]=h[d]||{},h[d].setup||h[d].teardown||a.extend(h[d],{setup:function(){this.addEventListener(d,e,!0)},teardown:function(){this.removeEventListener(d,e,!0)}})}))},register:function(b,c){var d=v[b];if(!d)return void f.error("can't find module: "+b);d.loaded=!0;var e=function(){c(a,f,window,document,void 0,d.options),s(b,!0)};d.d&&d.d.length?t(d.d,e):e()},c:{},loader:{addModule:function(b,c){v[b]=c,c.name=c.name||b,c.c||(c.c=[]),a.each(c.c,function(a,c){f.c[c]||(f.c[c]=[]),f.c[c].push(b)})},loadList:function(){var b=[],c=function(c,d){"string"==typeof d&&(d=[d]),a.merge(b,d),w.loadScript(c,!1,d)},d=function(c,d){if(s(c)||-1!=a.inArray(c,b))return!0;var e,f=v[c];return f?(e=f.test&&a.isFunction(f.test)?f.test(d):f.test,e?(s(c,!0),!0):!1):!0},e=function(b,c){if(b.d&&b.d.length){var e=function(b,e){d(e,c)||-1!=a.inArray(e,c)||c.push(e)};a.each(b.d,function(b,c){v[c]?v[c].loaded||e(b,c):r[c]&&(a.each(r[c],e),t(r[c],function(){s(c,!0)}))}),b.noAutoCallback||(b.noAutoCallback=!0)}};return function(g){var h,i,j,k,l=[],m=function(d,e){return k=e,a.each(f.c[e],function(c,d){return-1==a.inArray(d,l)||-1!=a.inArray(d,b)?(k=!1,!1):void 0}),k?(c("combos/"+k,f.c[k]),!1):void 0};for(i=0;i<g.length;i++)h=v[g[i]],h&&!d(h.name,g)&&(h.css&&q.loadStyles&&w.loadCSS(h.css),h.loadInit&&h.loadInit(),e(h,g),h.loaded||l.push(h.name),h.loaded=!0);for(i=0,j=l.length;j>i;i++)k=!1,h=l[i],-1==a.inArray(h,b)&&("noCombo"!=q.debug&&a.each(v[h].c,m),k||c(v[h].src||h,h))}}(),makePath:function(a){return-1!=a.indexOf("//")||0===a.indexOf("/")?a:(-1==a.indexOf(".")&&(a+=".js"),q.addCacheBuster&&(a+=q.addCacheBuster),q.basePath+a)},loadCSS:function(){var b,c={};return function(d){d=this.makePath(d),c[d]||(b=b||a("link, style")[0]||a("script")[0],c[d]=1,a('<link rel="stylesheet" />').insertBefore(b).attr({href:d}))}}(),loadScript:function(){var b={};return function(c,d,e,f){if(f||(c=w.makePath(c)),!b[c]){var g=function(){d&&d(),e&&("string"==typeof e&&(e=e.split(" ")),a.each(e,function(a,b){v[b]&&(v[b].afterLoad&&v[b].afterLoad(),s(v[b].noAutoCallback?b+"FileLoaded":b,!0))}))};b[c]=1,q.loadScript(c,g,a.noop)}}}()}});var q=f.cfg,r=f.features,s=f.isReady,t=f.ready,u=f.addPolyfill,v=f.modules,w=f.loader,x=w.loadList,y=w.addModule,z=f.bugs,A=[],B={warn:1,error:1},C=a.fn,D=b("video");f.addMethodName=function(a){a=a.split(":");var b=a[1];1==a.length?(b=a[0],a=a[0]):a=a[0],C[a]=function(){return this.callProp(b,arguments)}},C.callProp=function(b,c){var d;return c||(c=[]),this.each(function(){var e=a.prop(this,b);if(e&&e.apply){if(d=e.apply(this,c),void 0!==d)return!1}else f.warn(b+" is not a method of "+this)}),void 0!==d?d:this},f.activeLang=function(){"language"in e||(e.language=e.browserLanguage||"");var b=a.attr(document.documentElement,"lang")||e.language;return t("webshimLocalization",function(){f.activeLang(b)}),function(a){if(a)if("string"==typeof a)b=a;else if("object"==typeof a){var c=arguments,d=this;t("webshimLocalization",function(){f.activeLang.apply(d,c)})}return b}}(),f.errorLog=[],a.each(["log","error","warn","info"],function(a,b){f[b]=function(a){(B[b]&&q.debug!==!1||q.debug)&&(f.errorLog.push(a),window.console&&console.log&&void 0)}}),function(){a.isDOMReady=a.isReady;var b=function(){a.isDOMReady=!0,s("DOM",!0),setTimeout(function(){s("WINDOWLOAD",!0)},9999)};c=function(){if(!c.run){if((q.debug||!("crossDomain"in q.ajax)&&location.protocol.indexOf("http"))&&(q.ajax.crossDomain=!0),!a.isDOMReady&&q.waitReady){var d=a.ready;a.ready=function(a){return a!==!0&&document.body&&b(),d.apply(this,arguments)},a.ready.promise=d.promise}q.readyEvt?a(document).one(q.readyEvt,b):a(b)}c.run=!0},a(window).on("load",function(){b(),setTimeout(function(){s("WINDOWLOAD",!0)},9)});var d=[],e=function(){1==this.nodeType&&f.triggerDomUpdate(this)};a.extend(f,{addReady:function(a){var b=function(b,c){f.ready("DOM",function(){a(b,c)})};d.push(b),q.wsdoc&&b(q.wsdoc,i)},triggerDomUpdate:function(b){if(!b||!b.nodeType)return void(b&&b.jquery&&b.each(function(){f.triggerDomUpdate(this)}));var c=b.nodeType;if(1==c||9==c){var e=b!==document?a(b):i;a.each(d,function(a,c){c(b,e)})}}}),C.clonePolyfill=C.clone,C.htmlPolyfill=function(b){if(!arguments.length)return a(this.clonePolyfill()).html();var c=C.html.call(this,b);return c===this&&a.isDOMReady&&this.each(e),c},C.jProp=function(){return this.pushStack(a(C.prop.apply(this,arguments)||[]))},a.each(["after","before","append","prepend","replaceWith"],function(b,c){C[c+"Polyfill"]=function(b){return b=a(b),C[c].call(this,b),a.isDOMReady&&b.each(e),this}}),a.each(["insertAfter","insertBefore","appendTo","prependTo","replaceAll"],function(b,c){C[c.replace(/[A-Z]/,function(a){return"Polyfill"+a})]=function(){return C[c].apply(this,arguments),a.isDOMReady&&f.triggerDomUpdate(this),this}}),C.updatePolyfill=function(){return a.isDOMReady&&f.triggerDomUpdate(this),this},a.each(["getNativeElement","getShadowElement","getShadowFocusElement"],function(a,b){C[b]=function(){return this.pushStack(this)}})}(),l.create&&(f.objectCreate=function(b,c,d){var e=l.create(b);return d&&(e.options=a.extend(!0,{},e.options||{},d),d=e.options),e._create&&a.isFunction(e._create)&&e._create(d),e}),y("swfmini",{test:function(){return window.swfobject&&!window.swfmini&&(window.swfmini=window.swfobject),"swfmini"in window},c:[16,7,2,8,1,12,23]}),v.swfmini.test(),y("sizzle",{test:a.expr.filters}),u("es5",{test:!(!k.ES5||!Function.prototype.bind),d:["sizzle"]}),u("dom-extend",{f:g,noAutoCallback:!0,d:["es5"],c:[16,7,2,15,30,3,8,4,9,10,25,31,34]}),b("picture"),u("picture",{test:"picturefill"in window||!!window.HTMLPictureElement||"respimage"in window,d:["matchMedia"],c:[18],loadInit:function(){s("picture",!0)}}),u("matchMedia",{test:!(!window.matchMedia||!matchMedia("all").addListener),c:[18]}),u("sticky",{test:-1!=(a(b("b")).attr("style","position: -webkit-sticky; position: sticky").css("position")||"").indexOf("sticky"),d:["es5","matchMedia"]}),u("es6",{test:!!(Math.imul&&Number.MIN_SAFE_INTEGER&&l.is&&window.Promise&&Promise.all),d:["es5"]}),u("geolocation",{test:"geolocation"in e,options:{destroyWrite:!0},c:[21]}),function(){u("canvas",{src:"excanvas",test:"getContext"in b("canvas"),options:{type:"flash"},noAutoCallback:!0,loadInit:function(){var a=this.options.type;!a||-1===a.indexOf("flash")||v.swfmini.test()&&!swfmini.hasFlashPlayerVersion("9.0.0")||(this.src="flash"==a?"FlashCanvas/flashcanvas":"FlashCanvasPro/flashcanvas")},methodNames:["getContext"],d:[g]})}();var E="getUserMedia"in e;u("usermedia-core",{f:"usermedia",test:E&&window.URL,d:["url",g]}),u("usermedia-shim",{f:"usermedia",test:!!(E||e.webkitGetUserMedia||e.mozGetUserMedia||e.msGetUserMedia),d:["url","mediaelement",g]}),u("mediacapture",{test:p,d:["swfmini","usermedia",g,"filereader","forms","canvas"]}),function(){var c,d,h="form-shim-extend",i="formvalidation",j="form-number-date-api",l=!1,m=!1,o=!1,p={},r=b("progress"),s=b("output"),t=function(){var d,f,g="1(",j=b("input");if(f=a('<fieldset><textarea required="" /></fieldset>')[0],k.inputtypes=p,a.each(["range","date","datetime-local","month","color","number"],function(a,b){j.setAttribute("type",b),p[b]=j.type==b&&(j.value=g)&&j.value!=g}),k.datalist=!!("options"in b("datalist")&&window.HTMLDataListElement),k[i]="checkValidity"in j,k.fieldsetelements="elements"in f,k.fieldsetdisabled="disabled"in f){try{f.querySelector(":invalid")&&(f.disabled=!0,d=!f.querySelector(":invalid")&&f.querySelector(":disabled"))}catch(n){}k.fieldsetdisabled=!!d}if(k[i]&&(m=!(k.fieldsetdisabled&&k.fieldsetelements&&"value"in r&&"value"in s),o=m&&/Android/i.test(e.userAgent),l=window.opera||z.bustedValidity||m||!k.datalist,!l&&p.number)){l=!0;try{j.type="number",j.value="",j.stepUp(),l="1"!=j.value}catch(q){}}return z.bustedValidity=l,c=k[i]&&!l?"form-native-extend":h,t=a.noop,!1},w=function(b){var c=!0;return b._types||(b._types=b.types.split(" ")),a.each(b._types,function(a,b){return b in p&&!p[b]?(c=!1,!1):void 0}),c};f.validationMessages=f.validityMessages={langSrc:"i18n/formcfg-",availableLangs:"ar ca cs el es fa fr he hi hu it ja lt nl no pl pt pt-BR pt-PT ru sv zh-CN zh-TW".split(" ")},f.formcfg=a.extend({},f.validationMessages),f.inputTypes={},u("form-core",{f:"forms",test:t,d:["es5"],options:{placeholderType:"value",messagePopover:{},list:{popover:{constrainWidth:!0}},iVal:{sel:".ws-validate",handleBubble:"hide",recheckDelay:400}},methodNames:["setCustomValidity","checkValidity","setSelectionRange"],c:[16,7,2,8,1,15,30,3,31]}),d=q.forms,u("form-native-extend",{f:"forms",test:function(b){return t(),!k[i]||l||-1==a.inArray(j,b||[])||v[j].test()},d:["form-core",g,"form-message"],c:[6,5,14,29]}),u(h,{f:"forms",test:function(){return t(),k[i]&&!l},d:["form-core",g,"sizzle"],c:[16,15,28]}),u(h+"2",{f:"forms",test:function(){return t(),k[i]&&!m},d:[h],c:[27]}),u("form-message",{f:"forms",test:function(a){return t(),!(d.customMessages||!k[i]||l||!v[c].test(a))},d:[g],c:[16,7,15,30,3,8,4,14,28]}),u(j,{f:"forms-ext",options:{types:"date time range number"},test:function(){t();var a=!l;return a&&(a=w(this.options)),a},methodNames:["stepUp","stepDown"],d:["forms",g],c:[6,5,17,14,28,29,33]}),y("range-ui",{options:{},noAutoCallback:!0,test:function(){return!!C.rangeUI},d:["es5"],c:[6,5,9,10,17,11]}),u("form-number-date-ui",{f:"forms-ext",test:function(){var a=this.options;return a.replaceUI=n(a.replaceUI),t(),!a.replaceUI&&o&&(a.replaceUI=!0),!a.replaceUI&&w(a)},d:["forms",g,j,"range-ui"],options:{widgets:{calculateWidth:!0,animate:!0}},c:[6,5,9,10,17,11]}),u("form-datalist",{f:"forms",test:function(){return t(),o&&(d.customDatalist=!0),k.datalist&&!d.fD},d:["form-core",g],c:[16,7,6,2,9,15,30,31,28,33]})}();var F="FileReader"in window&&"FormData"in window;return u("filereader-xhr",{f:"filereader",test:F,d:[g,"swfmini"],c:[25,27]}),u("canvas-blob",{f:"filereader",methodNames:["toBlob"],test:!(F&&!b("canvas").toBlob)}),u("details",{test:"open"in b("details"),d:[g],options:{text:"Details"},c:[21,22]}),u("url",{test:function(){var a=!1;try{a=new URL("b","http://a"),a=!(!a.searchParams||"http://a/b"!=a.href)}catch(b){}return a},d:["es5"]}),function(){f.mediaelement={};var c=b("track");if(k.mediaelement="canPlayType"in D,k.texttrackapi="addTextTrack"in D,k.track="kind"in c,b("audio"),!(z.track=!k.texttrackapi))try{z.track=!("oncuechange"in D.addTextTrack("metadata"))}catch(d){}u("mediaelement-core",{f:"mediaelement",noAutoCallback:!0,options:{jme:{},plugins:[],vars:{},params:{},attrs:{},changeSWF:a.noop},methodNames:["play","pause","canPlayType","mediaLoad:load"],d:["swfmini"],c:[16,7,2,8,1,12,13,23]}),u("mediaelement-jaris",{f:"mediaelement",d:["mediaelement-core",g],test:function(){var a=this.options;return!k.mediaelement||f.mediaelement.loadSwf?!1:(a.preferFlash&&!v.swfmini.test()&&(a.preferFlash=!1),!(a.preferFlash&&swfmini.hasFlashPlayerVersion("11.3")))},c:[21,25]}),u("track",{options:{positionDisplay:!0,override:z.track},test:function(){var a=this.options;return a.override=n(a.override),!a.override&&!z.track},d:["mediaelement",g],methodNames:["addTextTrack"],c:[21,12,13,22,34]}),y("jmebase",{src:"jme/base",c:[98,99,97]}),a.each([["mediacontrols",{c:[98,99],css:"jme/controls.css"}],["playlist",{c:[98,97]}],["alternate-media"]],function(b,c){y(c[0],a.extend({src:"jme/"+c[0],d:["jmebase"]},c[1]))}),y("track-ui",{d:["track",g]})}(),u("feature-dummy",{test:!0,loaded:!0,c:A}),f.$=a,a.webshims=f,a.webshim=webshim,f.callAsync=function(){f.callAsync=a.noop,j&&(j.cfg&&(j.cfg.length||(j.cfg=[[j.cfg]]),a.each(j.cfg,function(a,b){f.setOptions.apply(f,b)})),j.ready&&a.each(j.ready,function(a,b){f.ready.apply(f,b)}),j.lang&&f.activeLang(j.lang),"polyfill"in j&&f.polyfill(j.polyfill)),f.isReady("jquery",!0)},f.callAsync(),f});
/**
 * DEVELOPED BY
 * GIL LOPES BUENO
 * gilbueno.mail@gmail.com
 *
 * WORKS WITH:
 * IE8*, IE 9+, FF 4+, SF 5+, WebKit, CH 7+, OP 12+, BESEN, Rhino 1.7+
 * For IE8 (and other legacy browsers) WatchJS will use dirty checking
 *
 * FORK:
 * https://github.com/melanke/Watch.JS
 */

"use strict";
(function(factory) {
	if (typeof exports === 'object') {
		// Node. Does not work with strict CommonJS, but
		// only CommonJS-like enviroments that support module.exports,
		// like Node.
		module.exports = factory();
	} else if (typeof define === 'function' && define.amd) {
		// AMD. Register as an anonymous module.
		define(factory);
	} else {
		// Browser globals
		window.WatchJS = factory();
		window.watch = window.WatchJS.watch;
		window.unwatch = window.WatchJS.unwatch;
		window.callWatchers = window.WatchJS.callWatchers;
	}
}(function() {

	var WatchJS = {
			noMore: false, // use WatchJS.suspend(obj) instead
			useDirtyCheck: false // use only dirty checking to track changes.
		},
		lengthsubjects = [];

	var dirtyChecklist = [];
	var pendingChanges = []; // used coalesce changes from defineProperty and __defineSetter__

	var supportDefineProperty = false;
	try {
		supportDefineProperty = Object.defineProperty && Object.defineProperty({},
			'x', {});
	} catch (ex) { /* not supported */ }

	var isFunction = function(functionToCheck) {
		var getType = {};
		return functionToCheck && getType.toString.call(functionToCheck) ==
			'[object Function]';
	};

	var isInt = function(x) {
		return x % 1 === 0;
	};

	var isArray = function(obj) {
		return Object.prototype.toString.call(obj) === '[object Array]';
	};

	var isObject = function(obj) {
		return {}.toString.apply(obj) === '[object Object]';
	};

	var getObjDiff = function(a, b) {
		var aplus = [],
			bplus = [];

		if (!(typeof a == "string") && !(typeof b == "string")) {

			if (isArray(a)) {
				for (var i = 0; i < a.length; i++) {
					if (b[i] === undefined) aplus.push(i);
				}
			} else {
				for (var i in a) {
					if (a.hasOwnProperty(i)) {
						if (b[i] === undefined) {
							aplus.push(i);
						}
					}
				}
			}

			if (isArray(b)) {
				for (var j = 0; j < b.length; j++) {
					if (a[j] === undefined) bplus.push(j);
				}
			} else {
				for (var j in b) {
					if (b.hasOwnProperty(j)) {
						if (a[j] === undefined) {
							bplus.push(j);
						}
					}
				}
			}
		}

		return {
			added: aplus,
			removed: bplus
		}
	};

	var clone = function(obj) {

		if (null == obj || "object" != typeof obj) {
			return obj;
		}

		var copy = obj.constructor();

		for (var attr in obj) {
			copy[attr] = obj[attr];
		}

		return copy;

	}

	var defineGetAndSet = function(obj, propName, getter, setter) {
		try {
			Object.observe(obj, function(changes) {
				changes.forEach(function(change) {
					if (change.name === propName) {
						setter(change.object[change.name]);
					}
				});
			});
		} catch (e) {
			try {
				Object.defineProperty(obj, propName, {
					get: getter,
					set: function(value) {
						setter.call(this, value, true); // coalesce changes
					},
					enumerable: true,
					configurable: true
				});
			} catch (e2) {
				try {
					Object.prototype.__defineGetter__.call(obj, propName, getter);
					Object.prototype.__defineSetter__.call(obj, propName, function(value) {
						setter.call(this, value, true); // coalesce changes
					});
				} catch (e3) {
					observeDirtyChanges(obj, propName, setter);
					//throw new Error("watchJS error: browser not supported :/")
				}
			}
		}
	};

	var defineProp = function(obj, propName, value) {
		try {
			Object.defineProperty(obj, propName, {
				enumerable: false,
				configurable: true,
				writable: false,
				value: value
			});
		} catch (error) {
			obj[propName] = value;
		}
	};

	var observeDirtyChanges = function(obj, propName, setter) {
		dirtyChecklist[dirtyChecklist.length] = {
			prop: propName,
			object: obj,
			orig: clone(obj[propName]),
			callback: setter
		}
	}

	var watch = function() {

		if (isFunction(arguments[1])) {
			watchAll.apply(this, arguments);
		} else if (isArray(arguments[1])) {
			watchMany.apply(this, arguments);
		} else {
			watchOne.apply(this, arguments);
		}

	};


	var watchAll = function(obj, watcher, level, addNRemove) {

		if ((typeof obj == "string") || (!(obj instanceof Object) && !isArray(obj))) { //accepts only objects and array (not string)
			return;
		}

		if (isArray(obj)) {
			defineWatcher(obj, "__watchall__", watcher, level); // watch all changes on the array
			if (level === undefined || level > 0) {
				for (var prop = 0; prop < obj.length; prop++) { // watch objects in array
					watchAll(obj[prop], watcher, level, addNRemove);
				}
			}
		} else {
			var prop, props = [];
			for (prop in obj) { //for each attribute if obj is an object
				if (prop == "$val" || (!supportDefineProperty && prop === 'watchers')) {
					continue;
				}

				if (Object.prototype.hasOwnProperty.call(obj, prop)) {
					props.push(prop); //put in the props
				}
			}
			watchMany(obj, props, watcher, level, addNRemove); //watch all items of the props
		}


		if (addNRemove) {
			pushToLengthSubjects(obj, "$$watchlengthsubjectroot", watcher, level);
		}
	};


	var watchMany = function(obj, props, watcher, level, addNRemove) {

		if ((typeof obj == "string") || (!(obj instanceof Object) && !isArray(obj))) { //accepts only objects and array (not string)
			return;
		}

		for (var i = 0; i < props.length; i++) { //watch each property
			var prop = props[i];
			watchOne(obj, prop, watcher, level, addNRemove);
		}

	};

	var watchOne = function(obj, prop, watcher, level, addNRemove) {
		if ((typeof obj == "string") || (!(obj instanceof Object) && !isArray(obj))) { //accepts only objects and array (not string)
			return;
		}

		if (isFunction(obj[prop])) { //dont watch if it is a function
			return;
		}
		if (obj[prop] != null && (level === undefined || level > 0)) {
			watchAll(obj[prop], watcher, level !== undefined ? level - 1 : level); //recursively watch all attributes of this
		}

		defineWatcher(obj, prop, watcher, level);

		if (addNRemove && (level === undefined || level > 0)) {
			pushToLengthSubjects(obj, prop, watcher, level);
		}

	};

	var unwatch = function() {

		if (isFunction(arguments[1])) {
			unwatchAll.apply(this, arguments);
		} else if (isArray(arguments[1])) {
			unwatchMany.apply(this, arguments);
		} else {
			unwatchOne.apply(this, arguments);
		}

	};

	var unwatchAll = function(obj, watcher) {

		if (obj instanceof String || (!(obj instanceof Object) && !isArray(obj))) { //accepts only objects and array (not string)
			return;
		}

		if (isArray(obj)) {
			var props = ['__watchall__'];
			for (var prop = 0; prop < obj.length; prop++) { //for each item if obj is an array
				props.push(prop); //put in the props
			}
			unwatchMany(obj, props, watcher); //watch all itens of the props
		} else {
			var unwatchPropsInObject = function(obj2) {
				var props = [];
				for (var prop2 in obj2) { //for each attribute if obj is an object
					if (obj2.hasOwnProperty(prop2)) {
						if (obj2[prop2] instanceof Object) {
							unwatchPropsInObject(obj2[prop2]); //recurs into object props
						} else {
							props.push(prop2); //put in the props
						}
					}
				}
				unwatchMany(obj2, props, watcher); //unwatch all of the props
			};
			unwatchPropsInObject(obj);
		}
	};


	var unwatchMany = function(obj, props, watcher) {

		for (var prop2 in props) { //watch each attribute of "props" if is an object
			if (props.hasOwnProperty(prop2)) {
				unwatchOne(obj, props[prop2], watcher);
			}
		}
	};

	var timeouts = [],
		timerID = null;

	function clearTimerID() {
		timerID = null;
		for (var i = 0; i < timeouts.length; i++) {
			timeouts[i]();
		}
		timeouts.length = 0;
	}
	var getTimerID = function() {
		if (!timerID) {
			timerID = setTimeout(clearTimerID);
		}
		return timerID;
	}
	var registerTimeout = function(fn) { // register function to be called on timeout
		if (timerID == null) getTimerID();
		timeouts[timeouts.length] = fn;
	}

	// Track changes made to an array, object or an object's property
	// and invoke callback with a single change object containing type, value, oldvalue and array splices
	// Syntax:
	//      trackChange(obj, callback, recursive, addNRemove)
	//      trackChange(obj, prop, callback, recursive, addNRemove)
	var trackChange = function() {
		var fn = (isFunction(arguments[2])) ? trackProperty : trackObject;
		fn.apply(this, arguments);
	}

	// track changes made to an object and invoke callback with a single change object containing type, value and array splices
	var trackObject = function(obj, callback, recursive, addNRemove) {
		var change = null,
			lastTimerID = -1;
		var isArr = isArray(obj);
		var level, fn = function(prop, action, newValue, oldValue) {
			var timerID = getTimerID();
			if (lastTimerID !== timerID) { // check if timer has changed since last update
				lastTimerID = timerID;
				change = {
					type: 'update'
				}
				change['value'] = obj;
				change['splices'] = null;
				registerTimeout(function() {
					callback.call(this, change);
					change = null;
				});
			}
			// create splices for array changes
			if (isArr && obj === this && change !== null) {
				if (action === 'pop' || action === 'shift') {
					newValue = [];
					oldValue = [oldValue];
				} else if (action === 'push' || action === 'unshift') {
					newValue = [newValue];
					oldValue = [];
				} else if (action !== 'splice') {
					return; // return here - for reverse and sort operations we don't need to return splices. a simple update will do
				}
				if (!change.splices) change.splices = [];
				change.splices[change.splices.length] = {
					index: prop,
					deleteCount: oldValue ? oldValue.length : 0,
					addedCount: newValue ? newValue.length : 0,
					added: newValue,
					deleted: oldValue
				};
			}

		}
		level = (recursive == true) ? undefined : 0;
		watchAll(obj, fn, level, addNRemove);
	}

	// track changes made to the property of an object and invoke callback with a single change object containing type, value, oldvalue and splices
	var trackProperty = function(obj, prop, callback, recursive, addNRemove) {
		if (obj && prop) {
			watchOne(obj, prop, function(prop, action, newvalue, oldvalue) {
				var change = {
					type: 'update'
				}
				change['value'] = newvalue;
				change['oldvalue'] = oldvalue;
				if (recursive && isObject(newvalue) || isArray(newvalue)) {
					trackObject(newvalue, callback, recursive, addNRemove);
				}
				callback.call(this, change);
			}, 0)

			if (recursive && isObject(obj[prop]) || isArray(obj[prop])) {
				trackObject(obj[prop], callback, recursive, addNRemove);
			}
		}
	}


	var defineWatcher = function(obj, prop, watcher, level) {
		var newWatcher = false;
		var isArr = isArray(obj);

		if (!obj.watchers) {
			defineProp(obj, "watchers", {});
			if (isArr) {
				// watch array functions
				watchFunctions(obj, function(index, action, newValue, oldValue) {
					addPendingChange(obj, index, action, newValue, oldValue);
					if (level !== 0 && newValue && (isObject(newValue) || isArray(
							newValue))) {
						var i, n, ln, wAll, watchList = obj.watchers[prop];
						if ((wAll = obj.watchers['__watchall__'])) {
							watchList = watchList ? watchList.concat(wAll) : wAll;
						}
						ln = watchList ? watchList.length : 0;
						for (i = 0; i < ln; i++) {
							if (action !== 'splice') {
								watchAll(newValue, watchList[i], (level === undefined) ? level :
									level - 1);
							} else {
								// watch spliced values
								for (n = 0; n < newValue.length; n++) {
									watchAll(newValue[n], watchList[i], (level === undefined) ? level :
										level - 1);
								}
							}
						}
					}
				});
			}
		}

		if (!obj.watchers[prop]) {
			obj.watchers[prop] = [];
			if (!isArr) newWatcher = true;
		}

		for (var i = 0; i < obj.watchers[prop].length; i++) {
			if (obj.watchers[prop][i] === watcher) {
				return;
			}
		}

		obj.watchers[prop].push(watcher); //add the new watcher to the watchers array

		if (newWatcher) {
			var val = obj[prop];
			var getter = function() {
				return val;
			};

			var setter = function(newval, delayWatcher) {
				var oldval = val;
				val = newval;
				if (level !== 0 && obj[prop] && (isObject(obj[prop]) || isArray(obj[
						prop])) && !obj[prop].watchers) {
					// watch sub properties
					var i, ln = obj.watchers[prop].length;
					for (i = 0; i < ln; i++) {
						watchAll(obj[prop], obj.watchers[prop][i], (level === undefined) ?
							level : level - 1);
					}
				}

				//watchFunctions(obj, prop);

				if (isSuspended(obj, prop)) {
					resume(obj, prop);
					return;
				}

				if (!WatchJS.noMore) { // this does not work with Object.observe
					//if (JSON.stringify(oldval) !== JSON.stringify(newval)) {
					if (oldval !== newval) {
						if (!delayWatcher) {
							callWatchers(obj, prop, "set", newval, oldval);
						} else {
							addPendingChange(obj, prop, "set", newval, oldval);
						}
						WatchJS.noMore = false;
					}
				}
			};

			if (WatchJS.useDirtyCheck) {
				observeDirtyChanges(obj, prop, setter);
			} else {
				defineGetAndSet(obj, prop, getter, setter);
			}
		}

	};

	var callWatchers = function(obj, prop, action, newval, oldval) {
		if (prop !== undefined) {
			var ln, wl, watchList = obj.watchers[prop];
			if ((wl = obj.watchers['__watchall__'])) {
				watchList = watchList ? watchList.concat(wl) : wl;
			}
			ln = watchList ? watchList.length : 0;
			for (var wr = 0; wr < ln; wr++) {
				watchList[wr].call(obj, prop, action, newval, oldval);
			}
		} else {
			for (var prop in obj) { //call all
				if (obj.hasOwnProperty(prop)) {
					callWatchers(obj, prop, action, newval, oldval);
				}
			}
		}
	};

	var methodNames = ['pop', 'push', 'reverse', 'shift', 'sort', 'slice',
		'unshift', 'splice'
	];
	var defineArrayMethodWatcher = function(obj, original, methodName, callback) {
		defineProp(obj, methodName, function() {
			var index = 0;
			var i, newValue, oldValue, response;
			// get values before splicing array
			if (methodName === 'splice') {
				var start = arguments[0];
				var end = start + arguments[1];
				oldValue = obj.slice(start, end);
				newValue = [];
				for (i = 2; i < arguments.length; i++) {
					newValue[i - 2] = arguments[i];
				}
				index = start;
			} else {
				newValue = arguments.length > 0 ? arguments[0] : undefined;
			}

			response = original.apply(obj, arguments);
			if (methodName !== 'slice') {
				if (methodName === 'pop') {
					oldValue = response;
					index = obj.length;
				} else if (methodName === 'push') {
					index = obj.length - 1;
				} else if (methodName === 'shift') {
					oldValue = response;
				} else if (methodName !== 'unshift' && newValue === undefined) {
					newValue = response;
				}
				callback.call(obj, index, methodName, newValue, oldValue)
			}
			return response;
		});
	};

	var watchFunctions = function(obj, callback) {

		if (!isFunction(callback) || !obj || (obj instanceof String) || (!isArray(
				obj))) {
			return;
		}

		for (var i = methodNames.length, methodName; i--;) {
			methodName = methodNames[i];
			defineArrayMethodWatcher(obj, obj[methodName], methodName, callback);
		}

	};

	var unwatchOne = function(obj, prop, watcher) {
		if (obj.watchers[prop]) {
			if (watcher === undefined) {
				delete obj.watchers[prop]; // remove all property watchers
			} else {
				for (var i = 0; i < obj.watchers[prop].length; i++) {
					var w = obj.watchers[prop][i];

					if (w == watcher) {
						obj.watchers[prop].splice(i, 1);
					}
				}
			}
		}
		removeFromLengthSubjects(obj, prop, watcher);
		removeFromDirtyChecklist(obj, prop);
	};

	// suspend watchers until next update cycle
	var suspend = function(obj, prop) {
		if (obj.watchers) {
			var name = '__wjs_suspend__' + (prop !== undefined ? prop : '');
			obj.watchers[name] = true;
		}
	}

	var isSuspended = function(obj, prop) {
		return obj.watchers && (obj.watchers['__wjs_suspend__'] ||
			obj.watchers['__wjs_suspend__' + prop]);
	}

	// resumes preivously suspended watchers
	var resume = function(obj, prop) {
		registerTimeout(function() {
			delete obj.watchers['__wjs_suspend__'];
			delete obj.watchers['__wjs_suspend__' + prop];
		})
	}

	var pendingTimerID = null;
	var addPendingChange = function(obj, prop, mode, newval, oldval) {
		pendingChanges[pendingChanges.length] = {
			obj: obj,
			prop: prop,
			mode: mode,
			newval: newval,
			oldval: oldval
		};
		if (pendingTimerID === null) {
			pendingTimerID = setTimeout(applyPendingChanges);
		}
	};


	var applyPendingChanges = function() {
		// apply pending changes
		var change = null;
		pendingTimerID = null;
		for (var i = 0; i < pendingChanges.length; i++) {
			change = pendingChanges[i];
			callWatchers(change.obj, change.prop, change.mode, change.newval, change.oldval);
		}
		if (change) {
			pendingChanges = [];
			change = null;
		}
	}

	var loop = function() {

		// check for new or deleted props
		for (var i = 0; i < lengthsubjects.length; i++) {

			var subj = lengthsubjects[i];

			if (subj.prop === "$$watchlengthsubjectroot") {

				var difference = getObjDiff(subj.obj, subj.actual);

				if (difference.added.length || difference.removed.length) {
					if (difference.added.length) {
						watchMany(subj.obj, difference.added, subj.watcher, subj.level - 1,
							true);
					}

					subj.watcher.call(subj.obj, "root", "differentattr", difference, subj.actual);
				}
				subj.actual = clone(subj.obj);


			} else {

				var difference = getObjDiff(subj.obj[subj.prop], subj.actual);

				if (difference.added.length || difference.removed.length) {
					if (difference.added.length) {
						for (var j = 0; j < subj.obj.watchers[subj.prop].length; j++) {
							watchMany(subj.obj[subj.prop], difference.added, subj.obj.watchers[
								subj.prop][j], subj.level - 1, true);
						}
					}

					callWatchers(subj.obj, subj.prop, "differentattr", difference, subj.actual);
				}

				subj.actual = clone(subj.obj[subj.prop]);

			}

		}

		// start dirty check
		var n, value;
		if (dirtyChecklist.length > 0) {
			for (var i = 0; i < dirtyChecklist.length; i++) {
				n = dirtyChecklist[i];
				value = n.object[n.prop];
				if (!compareValues(n.orig, value)) {
					n.orig = clone(value);
					n.callback(value);
				}
			}
		}

	};

	var compareValues = function(a, b) {
		var i, state = true;
		if (a !== b) {
			if (isObject(a)) {
				for (i in a) {
					if (!supportDefineProperty && i === 'watchers') continue;
					if (a[i] !== b[i]) {
						state = false;
						break;
					};
				}
			} else {
				state = false;
			}
		}
		return state;
	}

	var pushToLengthSubjects = function(obj, prop, watcher, level) {

		var actual;

		if (prop === "$$watchlengthsubjectroot") {
			actual = clone(obj);
		} else {
			actual = clone(obj[prop]);
		}

		lengthsubjects.push({
			obj: obj,
			prop: prop,
			actual: actual,
			watcher: watcher,
			level: level
		});
	};

	var removeFromLengthSubjects = function(obj, prop, watcher) {

		for (var i = 0; i < lengthsubjects.length; i++) {
			var subj = lengthsubjects[i];

			if (subj.obj == obj && subj.prop == prop && subj.watcher == watcher) {
				lengthsubjects.splice(i, 1);
			}
		}

	};

	var removeFromDirtyChecklist = function(obj, prop) {
		var notInUse;
		for (var i = 0; i < dirtyChecklist.length; i++) {
			var n = dirtyChecklist[i];
			var watchers = n.object.watchers;
			notInUse = (
				n.object == obj && n.prop == prop && watchers && (!watchers[prop] ||
					watchers[prop].length == 0)
			);
			if (notInUse) {
				dirtyChecklist.splice(i, 1);
			}
		}

	};

	setInterval(loop, 50);

	WatchJS.watch = watch;
	WatchJS.unwatch = unwatch;
	WatchJS.callWatchers = callWatchers;
	WatchJS.suspend = suspend; // suspend watchers
	WatchJS.onChange = trackChange; // track changes made to object or  it's property and return a single change object

	return WatchJS;

}));

/* Modernizr 2.8.3 (Custom Build) | MIT & BSD
 * Build: http://modernizr.com/download/#-fontface-backgroundsize-borderimage-borderradius-boxshadow-flexbox-flexboxlegacy-hsla-multiplebgs-opacity-rgba-textshadow-cssanimations-csscolumns-generatedcontent-cssgradients-cssreflections-csstransforms-csstransforms3d-csstransitions-applicationcache-canvas-canvastext-draganddrop-hashchange-history-audio-video-indexeddb-input-inputtypes-localstorage-postmessage-sessionstorage-websockets-websqldatabase-webworkers-geolocation-inlinesvg-smil-svg-svgclippaths-touch-webgl-shiv-mq-cssclasses-prefixed-teststyles-testprop-testallprops-hasevent-prefixes-domprefixes-contenteditable-css_lastchild-css_mask-css_overflow_scrolling-css_regions-css_resize-css_shapes-css_vhunit-css_vmaxunit-css_vminunit-css_vwunit-dom_dataset-script_async-svg_filters-load
 */
;
window.Modernizr = function(a, b, c) {
		function D(a) {
			j.cssText = a
		}

		function E(a, b) {
			return D(n.join(a + ";") + (b || ""))
		}

		function F(a, b) {
			return typeof a === b
		}

		function G(a, b) {
			return !!~("" + a).indexOf(b)
		}

		function H(a, b) {
			for (var d in a) {
				var e = a[d];
				if (!G(e, "-") && j[e] !== c) return b == "pfx" ? e : !0
			}
			return !1
		}

		function I(a, b, d) {
			for (var e in a) {
				var f = b[a[e]];
				if (f !== c) return d === !1 ? a[e] : F(f, "function") ? f.bind(d || b) :
					f
			}
			return !1
		}

		function J(a, b, c) {
			var d = a.charAt(0).toUpperCase() + a.slice(1),
				e = (a + " " + p.join(d + " ") + d).split(" ");
			return F(b, "string") || F(b, "undefined") ? H(e, b) : (e = (a + " " + q.join(
				d + " ") + d).split(" "), I(e, b, c))
		}

		function K() {
			e.input = function(c) {
				for (var d = 0, e = c.length; d < e; d++) u[c[d]] = c[d] in k;
				return u.list && (u.list = !!b.createElement("datalist") && !!a.HTMLDataListElement),
					u
			}(
				"autocomplete autofocus list placeholder max min multiple pattern required step"
				.split(" ")), e.inputtypes = function(a) {
				for (var d = 0, e, f, h, i = a.length; d < i; d++) k.setAttribute("type",
					f = a[d]), e = k.type !== "text", e && (k.value = l, k.style.cssText =
					"position:absolute;visibility:hidden;", /^range$/.test(f) && k.style.WebkitAppearance !==
					c ? (g.appendChild(k), h = b.defaultView, e = h.getComputedStyle && h.getComputedStyle(
						k, null).WebkitAppearance !== "textfield" && k.offsetHeight !== 0, g.removeChild(
						k)) : /^(search|tel)$/.test(f) || (/^(url|email)$/.test(f) ? e = k.checkValidity &&
						k.checkValidity() === !1 : e = k.value != l)), t[a[d]] = !!e;
				return t
			}(
				"search tel url email datetime date month week time datetime-local number range color"
				.split(" "))
		}
		var d = "2.8.3",
			e = {},
			f = !0,
			g = b.documentElement,
			h = "modernizr",
			i = b.createElement(h),
			j = i.style,
			k = b.createElement("input"),
			l = ":)",
			m = {}.toString,
			n = " -webkit- -moz- -o- -ms- ".split(" "),
			o = "Webkit Moz O ms",
			p = o.split(" "),
			q = o.toLowerCase().split(" "),
			r = {
				svg: "http://www.w3.org/2000/svg"
			},
			s = {},
			t = {},
			u = {},
			v = [],
			w = v.slice,
			x, y = function(a, c, d, e) {
				var f, i, j, k, l = b.createElement("div"),
					m = b.body,
					n = m || b.createElement("body");
				if (parseInt(d, 10))
					while (d--) j = b.createElement("div"), j.id = e ? e[d] : h + (d + 1), l.appendChild(
						j);
				return f = ["&#173;", '<style id="s', h, '">', a, "</style>"].join(""), l.id =
					h, (m ? l : n).innerHTML += f, n.appendChild(l), m || (n.style.background =
						"", n.style.overflow = "hidden", k = g.style.overflow, g.style.overflow =
						"hidden", g.appendChild(n)), i = c(l, a), m ? l.parentNode.removeChild(l) :
					(n.parentNode.removeChild(n), g.style.overflow = k), !!i
			},
			z = function(b) {
				var c = a.matchMedia || a.msMatchMedia;
				if (c) return c(b) && c(b).matches || !1;
				var d;
				return y("@media " + b + " { #" + h + " { position: absolute; } }",
					function(b) {
						d = (a.getComputedStyle ? getComputedStyle(b, null) : b.currentStyle)[
							"position"] == "absolute"
					}), d
			},
			A = function() {
				function d(d, e) {
					e = e || b.createElement(a[d] || "div"), d = "on" + d;
					var f = d in e;
					return f || (e.setAttribute || (e = b.createElement("div")), e.setAttribute &&
						e.removeAttribute && (e.setAttribute(d, ""), f = F(e[d], "function"), F(
							e[d], "undefined") || (e[d] = c), e.removeAttribute(d))), e = null, f
				}
				var a = {
					select: "input",
					change: "input",
					submit: "form",
					reset: "form",
					error: "img",
					load: "img",
					abort: "img"
				};
				return d
			}(),
			B = {}.hasOwnProperty,
			C;
		!F(B, "undefined") && !F(B.call, "undefined") ? C = function(a, b) {
			return B.call(a, b)
		} : C = function(a, b) {
			return b in a && F(a.constructor.prototype[b], "undefined")
		}, Function.prototype.bind || (Function.prototype.bind = function(b) {
			var c = this;
			if (typeof c != "function") throw new TypeError;
			var d = w.call(arguments, 1),
				e = function() {
					if (this instanceof e) {
						var a = function() {};
						a.prototype = c.prototype;
						var f = new a,
							g = c.apply(f, d.concat(w.call(arguments)));
						return Object(g) === g ? g : f
					}
					return c.apply(b, d.concat(w.call(arguments)))
				};
			return e
		}), s.flexbox = function() {
			return J("flexWrap")
		}, s.flexboxlegacy = function() {
			return J("boxDirection")
		}, s.canvas = function() {
			var a = b.createElement("canvas");
			return !!a.getContext && !!a.getContext("2d")
		}, s.canvastext = function() {
			return !!e.canvas && !!F(b.createElement("canvas").getContext("2d").fillText,
				"function")
		}, s.webgl = function() {
			return !!a.WebGLRenderingContext
		}, s.touch = function() {
			var c;
			return "ontouchstart" in a || a.DocumentTouch && b instanceof DocumentTouch ?
				c = !0 : y(["@media (", n.join("touch-enabled),("), h, ")",
					"{#modernizr{top:9px;position:absolute}}"
				].join(""), function(a) {
					c = a.offsetTop === 9
				}), c
		}, s.geolocation = function() {
			return "geolocation" in navigator
		}, s.postmessage = function() {
			return !!a.postMessage
		}, s.websqldatabase = function() {
			return !!a.openDatabase
		}, s.indexedDB = function() {
			return !!J("indexedDB", a)
		}, s.hashchange = function() {
			return A("hashchange", a) && (b.documentMode === c || b.documentMode > 7)
		}, s.history = function() {
			return !!a.history && !!history.pushState
		}, s.draganddrop = function() {
			var a = b.createElement("div");
			return "draggable" in a || "ondragstart" in a && "ondrop" in a
		}, s.websockets = function() {
			return "WebSocket" in a || "MozWebSocket" in a
		}, s.rgba = function() {
			return D("background-color:rgba(150,255,150,.5)"), G(j.backgroundColor,
				"rgba")
		}, s.hsla = function() {
			return D("background-color:hsla(120,40%,100%,.5)"), G(j.backgroundColor,
				"rgba") || G(j.backgroundColor, "hsla")
		}, s.multiplebgs = function() {
			return D("background:url(https://),url(https://),red url(https://)"),
				/(url\s*\(.*?){3}/.test(j.background)
		}, s.backgroundsize = function() {
			return J("backgroundSize")
		}, s.borderimage = function() {
			return J("borderImage")
		}, s.borderradius = function() {
			return J("borderRadius")
		}, s.boxshadow = function() {
			return J("boxShadow")
		}, s.textshadow = function() {
			return b.createElement("div").style.textShadow === ""
		}, s.opacity = function() {
			return E("opacity:.55"), /^0.55$/.test(j.opacity)
		}, s.cssanimations = function() {
			return J("animationName")
		}, s.csscolumns = function() {
			return J("columnCount")
		}, s.cssgradients = function() {
			var a = "background-image:",
				b = "gradient(linear,left top,right bottom,from(#9f9),to(white));",
				c = "linear-gradient(left top,#9f9, white);";
			return D((a + "-webkit- ".split(" ").join(b + a) + n.join(c + a)).slice(0, -
				a.length)), G(j.backgroundImage, "gradient")
		}, s.cssreflections = function() {
			return J("boxReflect")
		}, s.csstransforms = function() {
			return !!J("transform")
		}, s.csstransforms3d = function() {
			var a = !!J("perspective");
			return a && "webkitPerspective" in g.style && y(
				"@media (transform-3d),(-webkit-transform-3d){#modernizr{left:9px;position:absolute;height:3px;}}",
				function(b, c) {
					a = b.offsetLeft === 9 && b.offsetHeight === 3
				}), a
		}, s.csstransitions = function() {
			return J("transition")
		}, s.fontface = function() {
			var a;
			return y('@font-face {font-family:"font";src:url("https://")}', function(c,
				d) {
				var e = b.getElementById("smodernizr"),
					f = e.sheet || e.styleSheet,
					g = f ? f.cssRules && f.cssRules[0] ? f.cssRules[0].cssText : f.cssText ||
					"" : "";
				a = /src/i.test(g) && g.indexOf(d.split(" ")[0]) === 0
			}), a
		}, s.generatedcontent = function() {
			var a;
			return y(["#", h, "{font:0/0 a}#", h, ':after{content:"', l,
				'";visibility:hidden;font:3px/1 a}'
			].join(""), function(b) {
				a = b.offsetHeight >= 3
			}), a
		}, s.video = function() {
			var a = b.createElement("video"),
				c = !1;
			try {
				if (c = !!a.canPlayType) c = new Boolean(c), c.ogg = a.canPlayType(
					'video/ogg; codecs="theora"').replace(/^no$/, ""), c.h264 = a.canPlayType(
					'video/mp4; codecs="avc1.42E01E"').replace(/^no$/, ""), c.webm = a.canPlayType(
					'video/webm; codecs="vp8, vorbis"').replace(/^no$/, "")
			} catch (d) {}
			return c
		}, s.audio = function() {
			var a = b.createElement("audio"),
				c = !1;
			try {
				if (c = !!a.canPlayType) c = new Boolean(c), c.ogg = a.canPlayType(
					'audio/ogg; codecs="vorbis"').replace(/^no$/, ""), c.mp3 = a.canPlayType(
					"audio/mpeg;").replace(/^no$/, ""), c.wav = a.canPlayType(
					'audio/wav; codecs="1"').replace(/^no$/, ""), c.m4a = (a.canPlayType(
					"audio/x-m4a;") || a.canPlayType("audio/aac;")).replace(/^no$/, "")
			} catch (d) {}
			return c
		}, s.localstorage = function() {
			try {
				return localStorage.setItem(h, h), localStorage.removeItem(h), !0
			} catch (a) {
				return !1
			}
		}, s.sessionstorage = function() {
			try {
				return sessionStorage.setItem(h, h), sessionStorage.removeItem(h), !0
			} catch (a) {
				return !1
			}
		}, s.webworkers = function() {
			return !!a.Worker
		}, s.applicationcache = function() {
			return !!a.applicationCache
		}, s.svg = function() {
			return !!b.createElementNS && !!b.createElementNS(r.svg, "svg").createSVGRect
		}, s.inlinesvg = function() {
			var a = b.createElement("div");
			return a.innerHTML = "<svg/>", (a.firstChild && a.firstChild.namespaceURI) ==
				r.svg
		}, s.smil = function() {
			return !!b.createElementNS && /SVGAnimate/.test(m.call(b.createElementNS(r.svg,
				"animate")))
		}, s.svgclippaths = function() {
			return !!b.createElementNS && /SVGClipPath/.test(m.call(b.createElementNS(r
				.svg, "clipPath")))
		};
		for (var L in s) C(s, L) && (x = L.toLowerCase(), e[x] = s[L](), v.push((e[x] ?
			"" : "no-") + x));
		return e.input || K(), e.addTest = function(a, b) {
				if (typeof a == "object")
					for (var d in a) C(a, d) && e.addTest(d, a[d]);
				else {
					a = a.toLowerCase();
					if (e[a] !== c) return e;
					b = typeof b == "function" ? b() : b, typeof f != "undefined" && f && (g.className +=
						" " + (b ? "" : "no-") + a), e[a] = b
				}
				return e
			}, D(""), i = k = null,
			function(a, b) {
				function l(a, b) {
					var c = a.createElement("p"),
						d = a.getElementsByTagName("head")[0] || a.documentElement;
					return c.innerHTML = "x<style>" + b + "</style>", d.insertBefore(c.lastChild,
						d.firstChild)
				}

				function m() {
					var a = s.elements;
					return typeof a == "string" ? a.split(" ") : a
				}

				function n(a) {
					var b = j[a[h]];
					return b || (b = {}, i++, a[h] = i, j[i] = b), b
				}

				function o(a, c, d) {
					c || (c = b);
					if (k) return c.createElement(a);
					d || (d = n(c));
					var g;
					return d.cache[a] ? g = d.cache[a].cloneNode() : f.test(a) ? g = (d.cache[
							a] = d.createElem(a)).cloneNode() : g = d.createElem(a), g.canHaveChildren &&
						!e.test(a) && !g.tagUrn ? d.frag.appendChild(g) : g
				}

				function p(a, c) {
					a || (a = b);
					if (k) return a.createDocumentFragment();
					c = c || n(a);
					var d = c.frag.cloneNode(),
						e = 0,
						f = m(),
						g = f.length;
					for (; e < g; e++) d.createElement(f[e]);
					return d
				}

				function q(a, b) {
					b.cache || (b.cache = {}, b.createElem = a.createElement, b.createFrag =
							a.createDocumentFragment, b.frag = b.createFrag()), a.createElement =
						function(c) {
							return s.shivMethods ? o(c, a, b) : b.createElem(c)
						}, a.createDocumentFragment = Function("h,f",
							"return function(){var n=f.cloneNode(),c=n.createElement;h.shivMethods&&(" +
							m().join().replace(/[\w\-]+/g, function(a) {
								return b.createElem(a), b.frag.createElement(a), 'c("' + a + '")'
							}) + ");return n}")(s, b.frag)
				}

				function r(a) {
					a || (a = b);
					var c = n(a);
					return s.shivCSS && !g && !c.hasCSS && (c.hasCSS = !!l(a,
						"article,aside,dialog,figcaption,figure,footer,header,hgroup,main,nav,section{display:block}mark{background:#FF0;color:#000}template{display:none}"
					)), k || q(a, c), a
				}
				var c = "3.7.0",
					d = a.html5 || {},
					e = /^<|^(?:button|map|select|textarea|object|iframe|option|optgroup)$/i,
					f =
					/^(?:a|b|code|div|fieldset|h1|h2|h3|h4|h5|h6|i|label|li|ol|p|q|span|strong|style|table|tbody|td|th|tr|ul)$/i,
					g, h = "_html5shiv",
					i = 0,
					j = {},
					k;
				(function() {
					try {
						var a = b.createElement("a");
						a.innerHTML = "<xyz></xyz>", g = "hidden" in a, k = a.childNodes.length ==
							1 || function() {
								b.createElement("a");
								var a = b.createDocumentFragment();
								return typeof a.cloneNode == "undefined" || typeof a.createDocumentFragment ==
									"undefined" || typeof a.createElement == "undefined"
							}()
					} catch (c) {
						g = !0, k = !0
					}
				})();
				var s = {
					elements: d.elements ||
						"abbr article aside audio bdi canvas data datalist details dialog figcaption figure footer header hgroup main mark meter nav output progress section summary template time video",
					version: c,
					shivCSS: d.shivCSS !== !1,
					supportsUnknownElements: k,
					shivMethods: d.shivMethods !== !1,
					type: "default",
					shivDocument: r,
					createElement: o,
					createDocumentFragment: p
				};
				a.html5 = s, r(b)
			}(this, b), e._version = d, e._prefixes = n, e._domPrefixes = q, e._cssomPrefixes =
			p, e.mq = z, e.hasEvent = A, e.testProp = function(a) {
				return H([a])
			}, e.testAllProps = J, e.testStyles = y, e.prefixed = function(a, b, c) {
				return b ? J(a, b, c) : J(a, "pfx")
			}, g.className = g.className.replace(/(^|\s)no-js(\s|$)/, "$1$2") + (f ?
				" js " + v.join(" ") : ""), e
	}(this, this.document),
	function(a, b, c) {
		function d(a) {
			return "[object Function]" == o.call(a)
		}

		function e(a) {
			return "string" == typeof a
		}

		function f() {}

		function g(a) {
			return !a || "loaded" == a || "complete" == a || "uninitialized" == a
		}

		function h() {
			var a = p.shift();
			q = 1, a ? a.t ? m(function() {
				("c" == a.t ? B.injectCss : B.injectJs)(a.s, 0, a.a, a.x, a.e, 1)
			}, 0) : (a(), h()) : q = 0
		}

		function i(a, c, d, e, f, i, j) {
			function k(b) {
				if (!o && g(l.readyState) && (u.r = o = 1, !q && h(), l.onload = l.onreadystatechange =
						null, b)) {
					"img" != a && m(function() {
						t.removeChild(l)
					}, 50);
					for (var d in y[c]) y[c].hasOwnProperty(d) && y[c][d].onload()
				}
			}
			var j = j || B.errorTimeout,
				l = b.createElement(a),
				o = 0,
				r = 0,
				u = {
					t: d,
					s: c,
					e: f,
					a: i,
					x: j
				};
			1 === y[c] && (r = 1, y[c] = []), "object" == a ? l.data = c : (l.src = c,
					l.type = a), l.width = l.height = "0", l.onerror = l.onload = l.onreadystatechange =
				function() {
					k.call(this, r)
				}, p.splice(e, 0, u), "img" != a && (r || 2 === y[c] ? (t.insertBefore(l,
					s ? null : n), m(k, j)) : y[c].push(l))
		}

		function j(a, b, c, d, f) {
			return q = 0, b = b || "j", e(a) ? i("c" == b ? v : u, a, b, this.i++, c, d,
				f) : (p.splice(this.i++, 0, a), 1 == p.length && h()), this
		}

		function k() {
			var a = B;
			return a.loader = {
				load: j,
				i: 0
			}, a
		}
		var l = b.documentElement,
			m = a.setTimeout,
			n = b.getElementsByTagName("script")[0],
			o = {}.toString,
			p = [],
			q = 0,
			r = "MozAppearance" in l.style,
			s = r && !!b.createRange().compareNode,
			t = s ? l : n.parentNode,
			l = a.opera && "[object Opera]" == o.call(a.opera),
			l = !!b.attachEvent && !l,
			u = r ? "object" : l ? "script" : "img",
			v = l ? "script" : u,
			w = Array.isArray || function(a) {
				return "[object Array]" == o.call(a)
			},
			x = [],
			y = {},
			z = {
				timeout: function(a, b) {
					return b.length && (a.timeout = b[0]), a
				}
			},
			A, B;
		B = function(a) {
				function b(a) {
					var a = a.split("!"),
						b = x.length,
						c = a.pop(),
						d = a.length,
						c = {
							url: c,
							origUrl: c,
							prefixes: a
						},
						e, f, g;
					for (f = 0; f < d; f++) g = a[f].split("="), (e = z[g.shift()]) && (c = e(
						c, g));
					for (f = 0; f < b; f++) c = x[f](c);
					return c
				}

				function g(a, e, f, g, h) {
					var i = b(a),
						j = i.autoCallback;
					i.url.split(".").pop().split("?").shift(), i.bypass || (e && (e = d(e) ?
							e : e[a] || e[g] || e[a.split("/").pop().split("?")[0]]), i.instead ?
						i.instead(a, e, f, g, h) : (y[i.url] ? i.noexec = !0 : y[i.url] = 1, f.load(
								i.url, i.forceCSS || !i.forceJS && "css" == i.url.split(".").pop().split(
									"?").shift() ? "c" : c, i.noexec, i.attrs, i.timeout), (d(e) || d(j)) &&
							f.load(function() {
								k(), e && e(i.origUrl, h, g), j && j(i.origUrl, h, g), y[i.url] = 2
							})))
				}

				function h(a, b) {
					function c(a, c) {
						if (a) {
							if (e(a)) c || (j = function() {
								var a = [].slice.call(arguments);
								k.apply(this, a), l()
							}), g(a, j, b, 0, h);
							else if (Object(a) === a)
								for (n in m = function() {
										var b = 0,
											c;
										for (c in a) a.hasOwnProperty(c) && b++;
										return b
									}(), a) a.hasOwnProperty(n) && (!c && !--m && (d(j) ? j = function() {
									var a = [].slice.call(arguments);
									k.apply(this, a), l()
								} : j[n] = function(a) {
									return function() {
										var b = [].slice.call(arguments);
										a && a.apply(this, b), l()
									}
								}(k[n])), g(a[n], j, b, n, h))
						} else !c && l()
					}
					var h = !!a.test,
						i = a.load || a.both,
						j = a.callback || f,
						k = j,
						l = a.complete || f,
						m, n;
					c(h ? a.yep : a.nope, !!i), i && c(i)
				}
				var i, j, l = this.yepnope.loader;
				if (e(a)) g(a, 0, l, 0);
				else if (w(a))
					for (i = 0; i < a.length; i++) j = a[i], e(j) ? g(j, 0, l, 0) : w(j) ? B(j) :
						Object(j) === j && h(j, l);
				else Object(a) === a && h(a, l)
			}, B.addPrefix = function(a, b) {
				z[a] = b
			}, B.addFilter = function(a) {
				x.push(a)
			}, B.errorTimeout = 1e4, null == b.readyState && b.addEventListener && (b.readyState =
				"loading", b.addEventListener("DOMContentLoaded", A = function() {
					b.removeEventListener("DOMContentLoaded", A, 0), b.readyState =
						"complete"
				}, 0)), a.yepnope = k(), a.yepnope.executeStack = h, a.yepnope.injectJs =
			function(a, c, d, e, i, j) {
				var k = b.createElement("script"),
					l, o, e = e || B.errorTimeout;
				k.src = a;
				for (o in d) k.setAttribute(o, d[o]);
				c = j ? h : c || f, k.onreadystatechange = k.onload = function() {
					!l && g(k.readyState) && (l = 1, c(), k.onload = k.onreadystatechange =
						null)
				}, m(function() {
					l || (l = 1, c(1))
				}, e), i ? k.onload() : n.parentNode.insertBefore(k, n)
			}, a.yepnope.injectCss = function(a, c, d, e, g, i) {
				var e = b.createElement("link"),
					j, c = i ? h : c || f;
				e.href = a, e.rel = "stylesheet", e.type = "text/css";
				for (j in d) e.setAttribute(j, d[j]);
				g || (n.parentNode.insertBefore(e, n), m(c, 0))
			}
	}(this, document), Modernizr.load = function() {
		yepnope.apply(window, [].slice.call(arguments, 0))
	}, Modernizr.addTest("contenteditable", "contentEditable" in document.documentElement),
	Modernizr.addTest("lastchild", function() {
		return Modernizr.testStyles(
			"#modernizr div {width:100px} #modernizr :last-child{width:200px;display:block}",
			function(a) {
				return a.lastChild.offsetWidth > a.firstChild.offsetWidth
			}, 2)
	}), Modernizr.addTest("overflowscrolling", function() {
		return Modernizr.testAllProps("overflowScrolling")
	}), Modernizr.addTest("cssresize", Modernizr.testAllProps("resize")),
	Modernizr.addTest("cssmask", Modernizr.testAllProps("maskRepeat")), Modernizr.addTest(
		"regions",
		function() {
			var a = Modernizr.prefixed("flowFrom"),
				b = Modernizr.prefixed("flowInto");
			if (!a || !b) return !1;
			var c = document.createElement("div"),
				d = document.createElement("div"),
				e = document.createElement("div"),
				f = "modernizr_flow_for_regions_check";
			d.innerText = "M", c.style.cssText =
				"top: 150px; left: 150px; padding: 0px;", e.style.cssText =
				"width: 50px; height: 50px; padding: 42px;", e.style[a] = f, c.appendChild(
					d), c.appendChild(e), document.documentElement.appendChild(c);
			var g, h, i = d.getBoundingClientRect();
			return d.style[b] = f, g = d.getBoundingClientRect(), h = g.left - i.left,
				document.documentElement.removeChild(c), d = e = c = undefined, h == 42
		}), Modernizr.addTest("shapes", Modernizr.testAllProps("shapeOutside",
		"content-box", !0)), Modernizr.addTest("cssvwunit", function() {
		var a;
		return Modernizr.testStyles("#modernizr { width: 50vw; }", function(b, c) {
			var d = parseInt(window.innerWidth / 2, 10),
				e = parseInt((window.getComputedStyle ? getComputedStyle(b, null) : b.currentStyle)
					.width, 10);
			a = e == d
		}), a
	}), Modernizr.addTest("dataset", function() {
		var a = document.createElement("div");
		return a.setAttribute("data-a-b", "c"), !!a.dataset && a.dataset.aB === "c"
	}), Modernizr.addTest("cssvminunit", function() {
		var a;
		return Modernizr.testStyles("#modernizr { width: 50vmin; }", function(b, c) {
			var d = window.innerWidth / 100,
				e = window.innerHeight / 100,
				f = parseInt((window.getComputedStyle ? getComputedStyle(b, null) : b.currentStyle)
					.width, 10);
			a = parseInt(Math.min(d, e) * 50, 10) == f
		}), a
	}), Modernizr.addTest("scriptasync", "async" in document.createElement(
		"script")), Modernizr.addTest("cssvhunit", function() {
		var a;
		return Modernizr.testStyles("#modernizr { height: 50vh; }", function(b, c) {
			var d = parseInt(window.innerHeight / 2, 10),
				e = parseInt((window.getComputedStyle ? getComputedStyle(b, null) : b.currentStyle)
					.height, 10);
			a = e == d
		}), a
	}), Modernizr.addTest("cssvmaxunit", function() {
		var a;
		return Modernizr.testStyles("#modernizr { width: 50vmax; }", function(b, c) {
			var d = window.innerWidth / 100,
				e = window.innerHeight / 100,
				f = parseInt((window.getComputedStyle ? getComputedStyle(b, null) : b.currentStyle)
					.width, 10);
			a = parseInt(Math.max(d, e) * 50, 10) == f
		}), a
	}), Modernizr.addTest("svgfilters", function() {
		var a = !1;
		try {
			a = typeof SVGFEColorMatrixElement !== undefined && SVGFEColorMatrixElement
				.SVG_FECOLORMATRIX_TYPE_SATURATE == 2
		} catch (b) {}
		return a
	});

/**
 * @license
 * lodash 3.8.0 (Custom Build) lodash.com/license | Underscore.js 1.8.3 underscorejs.org/LICENSE
 * Build: `lodash modern -o ./lodash.js`
 */
;
(function() {
	function n(n, t) {
		if (n !== t) {
			var r = n === n,
				e = t === t;
			if (n > t || !r || n === w && e) return 1;
			if (n < t || !e || t === w && r) return -1
		}
		return 0
	}

	function t(n, t, r) {
		for (var e = n.length, u = r ? e : -1; r ? u-- : ++u < e;)
			if (t(n[u], u, n)) return u;
		return -1
	}

	function r(n, t, r) {
		if (t !== t) return p(n, r);
		r -= 1;
		for (var e = n.length; ++r < e;)
			if (n[r] === t) return r;
		return -1
	}

	function e(n) {
		return typeof n == "function" || false
	}

	function u(n) {
		return typeof n == "string" ? n : null == n ? "" : n + ""
	}

	function o(n) {
		return n.charCodeAt(0)
	}

	function i(n, t) {
		for (var r = -1, e = n.length; ++r < e && -1 < t.indexOf(n.charAt(r)););
		return r
	}

	function f(n, t) {
		for (var r = n.length; r-- && -1 < t.indexOf(n.charAt(r)););
		return r
	}

	function a(t, r) {
		return n(t.a, r.a) || t.b - r.b
	}

	function c(n) {
		return $n[n]
	}

	function l(n) {
		return Ln[n]
	}

	function s(n) {
		return "\\" + Mn[n]
	}

	function p(n, t, r) {
		var e = n.length;
		for (t += r ? 0 : -1; r ? t-- : ++t < e;) {
			var u = n[t];
			if (u !== u) return t
		}
		return -1
	}

	function h(n) {
		return !!n && typeof n == "object"
	}

	function _(n) {
		return 160 >= n && 9 <= n && 13 >= n || 32 == n || 160 == n || 5760 == n ||
			6158 == n || 8192 <= n && (8202 >= n || 8232 == n || 8233 == n || 8239 ==
				n || 8287 == n || 12288 == n || 65279 == n);

	}

	function v(n, t) {
		for (var r = -1, e = n.length, u = -1, o = []; ++r < e;) n[r] === t && (n[r] =
			z, o[++u] = r);
		return o
	}

	function g(n) {
		for (var t = -1, r = n.length; ++t < r && _(n.charCodeAt(t)););
		return t
	}

	function y(n) {
		for (var t = n.length; t-- && _(n.charCodeAt(t)););
		return t
	}

	function d(n) {
		return zn[n]
	}

	function m(_) {
		function $n(n) {
			if (h(n) && !(To(n) || n instanceof Bn)) {
				if (n instanceof zn) return n;
				if (Ge.call(n, "__chain__") && Ge.call(n, "__wrapped__")) return Lr(n)
			}
			return new zn(n)
		}

		function Ln() {}

		function zn(n, t, r) {
			this.__wrapped__ = n, this.__actions__ = r || [],
				this.__chain__ = !!t
		}

		function Bn(n) {
			this.__wrapped__ = n, this.__actions__ = null, this.__dir__ = 1, this.__filtered__ =
				false, this.__iteratees__ = null, this.__takeCount__ = Iu, this.__views__ =
				null
		}

		function Mn() {
			this.__data__ = {}
		}

		function Dn(n) {
			var t = n ? n.length : 0;
			for (this.data = {
					hash: du(null),
					set: new lu
				}; t--;) this.push(n[t])
		}

		function Pn(n, t) {
			var r = n.data;
			return (typeof t == "string" || se(t) ? r.set.has(t) : r.hash[t]) ? 0 : -
				1
		}

		function qn(n, t) {
			var r = -1,
				e = n.length;
			for (t || (t = Ue(e)); ++r < e;) t[r] = n[r];
			return t
		}

		function Kn(n, t) {
			for (var r = -1, e = n.length; ++r < e && false !== t(n[r], r, n););
			return n
		}

		function Vn(n, t) {
			for (var r = -1, e = n.length; ++r < e;)
				if (!t(n[r], r, n)) return false;
			return true
		}

		function Gn(n, t) {
			for (var r = -1, e = n.length, u = -1, o = []; ++r < e;) {
				var i = n[r];
				t(i, r, n) && (o[++u] = i)
			}
			return o
		}

		function Jn(n, t) {
			for (var r = -1, e = n.length, u = Ue(e); ++r < e;) u[r] = t(n[r], r, n);
			return u
		}

		function Xn(n, t, r, e) {
			var u = -1,
				o = n.length;
			for (e && o && (r = n[++u]); ++u < o;) r = t(r, n[u], u, n);
			return r
		}

		function Hn(n, t) {
			for (var r = -1, e = n.length; ++r < e;)
				if (t(n[r], r, n)) return true;
			return false
		}

		function Qn(n, t) {
			return n === w ? t : n
		}

		function nt(n, t, r, e) {
			return n !== w && Ge.call(e, r) ? n : t
		}

		function tt(n, t, r) {
			var e = Ko(t);
			fu.apply(e, Zu(t));
			for (var u = -1, o = e.length; ++u < o;) {
				var i = e[u],
					f = n[i],
					a = r(f, t[i], i, n, t);
				(a === a ? a === f : f !== f) && (f !== w || i in n) || (n[i] = a)
			}
			return n
		}

		function rt(n, t) {
			for (var r = -1, e = null == n, u = !e && jr(n), o = u && n.length, i = t
					.length, f = Ue(i); ++r < i;) {
				var a = t[r];
				f[r] = u ? kr(a, o) ? n[a] : w : e ? w : n[a]
			}
			return f
		}

		function et(n, t, r) {
			r || (r = {});
			for (var e = -1, u = t.length; ++e < u;) {
				var o = t[e];
				r[o] = n[o]
			}
			return r
		}

		function ut(n, t, r) {
			var e = typeof n;
			return "function" == e ? t === w ? n : zt(n, t, r) : null == n ? Re :
				"object" == e ? wt(n) : t === w ? Te(n) : bt(n, t);

		}

		function ot(n, t, r, e, u, o, i) {
			var f;
			if (r && (f = u ? r(n, e, u) : r(n)), f !== w) return f;
			if (!se(n)) return n;
			if (e = To(n)) {
				if (f = wr(n), !t) return qn(n, f)
			} else {
				var a = Xe.call(n),
					c = a == K;
				if (a != Y && a != B && (!c || u)) return Nn[a] ? xr(n, a, t) : u ? n : {};
				if (f = br(c ? {} : n), !t) return $u(f, n)
			}
			for (o || (o = []), i || (i = []), u = o.length; u--;)
				if (o[u] == n) return i[u];
			return o.push(n), i.push(f), (e ? Kn : ht)(n, function(e, u) {
				f[u] = ot(e, t, r, u, n, o, i)
			}), f
		}

		function it(n, t, r) {
			if (typeof n != "function") throw new Pe(L);
			return su(function() {
				n.apply(w, r)
			}, t)
		}

		function ft(n, t) {
			var e = n ? n.length : 0,
				u = [];
			if (!e) return u;
			var o = -1,
				i = mr(),
				f = i == r,
				a = f && 200 <= t.length ? qu(t) : null,
				c = t.length;
			a && (i = Pn, f = false, t = a);
			n: for (; ++o < e;)
				if (a = n[o], f && a === a) {
					for (var l = c; l--;)
						if (t[l] === a) continue n;
					u.push(a)
				} else 0 > i(t, a, 0) && u.push(a);
			return u
		}

		function at(n, t) {
			var r = true;
			return zu(n, function(n, e, u) {
				return r = !!t(n, e, u)
			}), r
		}

		function ct(n, t) {
			var r = [];
			return zu(n, function(n, e, u) {
				t(n, e, u) && r.push(n)
			}), r
		}

		function lt(n, t, r, e) {
			var u;
			return r(n, function(n, r, o) {
				return t(n, r, o) ? (u = e ? r : n, false) : void 0
			}), u
		}

		function st(n, t, r) {
			for (var e = -1, u = n.length, o = -1, i = []; ++e < u;) {
				var f = n[e];
				if (h(f) && jr(f) && (r || To(f) || ae(f))) {
					t && (f = st(f, t, r));
					for (var a = -1, c = f.length; ++a < c;) i[++o] = f[a]
				} else r || (i[++o] = f)
			}
			return i
		}

		function pt(n, t) {
			Mu(n, t, me)
		}

		function ht(n, t) {
			return Mu(n, t, Ko)
		}

		function _t(n, t) {
			return Du(n, t, Ko)
		}

		function vt(n, t) {
			for (var r = -1, e = t.length, u = -1, o = []; ++r < e;) {
				var i = t[r];
				No(n[i]) && (o[++u] = i)
			}
			return o
		}

		function gt(n, t, r) {
			if (null != n) {
				r !== w && r in Fr(n) && (t = [r]), r = -1;
				for (var e = t.length; null != n && ++r < e;) n = n[t[r]];
				return r && r == e ? n : w
			}
		}

		function yt(n, t, r, e, u, o) {
			if (n === t) return true;
			var i = typeof n,
				f = typeof t;
			if ("function" != i && "object" != i && "function" != f && "object" != f ||
				null == n || null == t) n = n !== n && t !== t;
			else n: {
				var i = yt,
					f = To(n),
					a = To(t),
					c = M,
					l = M;
				f || (c = Xe.call(n), c == B ? c = Y : c != Y && (f = ge(n))), a || (l =
					Xe.call(t), l == B ? l = Y : l != Y && ge(t));
				var s = c == Y,
					a = l == Y,
					l = c == l;
				if (!l || f || s) {
					if (!e && (c = s && Ge.call(n, "__wrapped__"), a = a && Ge.call(t,
							"__wrapped__"), c || a)) {
						n = i(c ? n.value() : n, a ? t.value() : t, r, e, u, o);
						break n
					}
					if (l) {
						for (u || (u = []), o || (o = []), c = u.length; c--;)
							if (u[c] == n) {
								n = o[c] == t;
								break n
							}
						u.push(n), o.push(t), n = (f ? _r : gr)(n, t, i, r, e, u, o), u.pop(),
							o.pop()
					} else n = false
				} else n = vr(n, t, c)
			}
			return n
		}

		function dt(n, t, r, e, u) {
			for (var o = -1, i = t.length, f = !u; ++o < i;)
				if (f && e[o] ? r[o] !== n[t[o]] : !(t[o] in n)) return false;
			for (o = -1; ++o < i;) {
				var a = t[o],
					c = n[a],
					l = r[o];
				if (f && e[o] ? a = c !== w || a in n : (a = u ? u(c, l, a) : w, a === w &&
						(a = yt(l, c, u, true))), !a) return false
			}
			return true
		}

		function mt(n, t) {
			var r = -1,
				e = jr(n) ? Ue(n.length) : [];
			return zu(n, function(n, u, o) {
				e[++r] = t(n, u, o)
			}), e
		}

		function wt(n) {
			var t = Ko(n),
				r = t.length;
			if (!r) return Ie(true);

			if (1 == r) {
				var e = t[0],
					u = n[e];
				if (Cr(u)) return function(n) {
					return null == n ? false : n[e] === u && (u !== w || e in Fr(n))
				}
			}
			for (var o = Ue(r), i = Ue(r); r--;) u = n[t[r]], o[r] = u, i[r] = Cr(u);
			return function(n) {
				return null != n && dt(Fr(n), t, o, i)
			}
		}

		function bt(n, t) {
			var r = To(n),
				e = Er(n) && Cr(t),
				u = n + "";
			return n = $r(n),
				function(o) {
					if (null == o) return false;
					var i = u;
					if (o = Fr(o), !(!r && e || i in o)) {
						if (o = 1 == n.length ? o : gt(o, It(n, 0, -1)), null == o) return
							false;
						i = Pr(n), o = Fr(o)
					}
					return o[i] === t ? t !== w || i in o : yt(t, o[i], null, true)
				}
		}

		function xt(n, t, r, e, u) {
			if (!se(n)) return n;

			var o = jr(t) && (To(t) || ge(t));
			if (!o) {
				var i = Ko(t);
				fu.apply(i, Zu(t))
			}
			return Kn(i || t, function(f, a) {
				if (i && (a = f, f = t[a]), h(f)) {
					e || (e = []), u || (u = []);
					n: {
						for (var c = a, l = e, s = u, p = l.length, _ = t[c]; p--;)
							if (l[p] == _) {
								n[c] = s[p];
								break n
							}
						var p = n[c],
							v = r ? r(p, _, c, n, t) : w,
							g = v === w;
						g && (v = _, jr(_) && (To(_) || ge(_)) ? v = To(p) ? p : jr(p) ? qn(
									p) : [] : Fo(_) || ae(_) ? v = ae(p) ? ye(p) : Fo(p) ? p : {} :
								g = false), l.push(_), s.push(v), g ? n[c] = xt(v, _, r, l, s) :
							(v === v ? v !== p : p === p) && (n[c] = v)
					}
				} else c = n[a], l = r ? r(c, f, a, n, t) : w, (s = l === w) && (l = f), !
					o && l === w || !s && (l === l ? l === c : c !== c) || (n[a] = l);

			}), n
		}

		function At(n) {
			return function(t) {
				return null == t ? w : t[n]
			}
		}

		function jt(n) {
			var t = n + "";
			return n = $r(n),
				function(r) {
					return gt(r, n, t)
				}
		}

		function kt(n, t) {
			for (var r = n ? t.length : 0; r--;) {
				var e = parseFloat(t[r]);
				if (e != u && kr(e)) {
					var u = e;
					pu.call(n, e, 1)
				}
			}
		}

		function Ot(n, t) {
			return n + uu(Ou() * (t - n + 1))
		}

		function Et(n, t, r, e, u) {
			return u(n, function(n, u, o) {
				r = e ? (e = false, n) : t(r, n, u, o)
			}), r
		}

		function It(n, t, r) {
			var e = -1,
				u = n.length;
			for (t = null == t ? 0 : +t || 0, 0 > t && (t = -t > u ? 0 : u + t), r =
				r === w || r > u ? u : +r || 0, 0 > r && (r += u), u = t > r ? 0 : r - t >>>
				0, t >>>= 0,
				r = Ue(u); ++e < u;) r[e] = n[e + t];
			return r
		}

		function Rt(n, t) {
			var r;
			return zu(n, function(n, e, u) {
				return r = t(n, e, u), !r
			}), !!r
		}

		function Ct(n, t) {
			var r = n.length;
			for (n.sort(t); r--;) n[r] = n[r].c;
			return n
		}

		function Wt(t, r, e) {
			var u = dr(),
				o = -1;
			return r = Jn(r, function(n) {
				return u(n)
			}), t = mt(t, function(n) {
				return {
					a: Jn(r, function(t) {
						return t(n)
					}),
					b: ++o,
					c: n
				}
			}), Ct(t, function(t, r) {
				var u;
				n: {
					u = -1;
					for (var o = t.a, i = r.a, f = o.length, a = e.length; ++u < f;) {
						var c = n(o[u], i[u]);
						if (c) {
							u = u < a ? c * (e[u] ? 1 : -1) : c;
							break n
						}
					}
					u = t.b - r.b
				}
				return u
			})
		}

		function St(n, t) {
			var r = 0;
			return zu(n, function(n, e, u) {
				r += +t(n, e, u) || 0
			}), r
		}

		function Tt(n, t) {
			var e = -1,
				u = mr(),
				o = n.length,
				i = u == r,
				f = i && 200 <= o,
				a = f ? qu() : null,
				c = [];
			a ? (u = Pn, i = false) : (f = false, a = t ? [] : c);
			n: for (; ++e < o;) {
				var l = n[e],
					s = t ? t(l, e, n) : l;
				if (i && l === l) {
					for (var p = a.length; p--;)
						if (a[p] === s) continue n;
					t && a.push(s), c.push(l)
				} else 0 > u(a, s, 0) && ((t || f) && a.push(s), c.push(l))
			}
			return c
		}

		function Ut(n, t) {
			for (var r = -1, e = t.length, u = Ue(e); ++r < e;) u[r] = n[t[r]];
			return u
		}

		function Nt(n, t, r, e) {
			for (var u = n.length, o = e ? u : -1;
				(e ? o-- : ++o < u) && t(n[o], o, n););
			return r ? It(n, e ? 0 : o, e ? o + 1 : u) : It(n, e ? o + 1 : 0, e ? u :
				o)
		}

		function Ft(n, t) {
			var r = n;
			r instanceof Bn && (r = r.value());
			for (var e = -1, u = t.length; ++e < u;) {
				var r = [r],
					o = t[e];
				fu.apply(r, o.args), r = o.func.apply(o.thisArg, r)
			}
			return r
		}

		function $t(n, t, r) {
			var e = 0,
				u = n ? n.length : e;
			if (typeof t == "number" && t === t && u <= Wu) {
				for (; e < u;) {
					var o = e + u >>> 1,
						i = n[o];
					(r ? i <= t : i < t) ? e = o + 1: u = o
				}
				return u
			}
			return Lt(n, t, Re, r)
		}

		function Lt(n, t, r, e) {
			t = r(t);
			for (var u = 0, o = n ? n.length : 0, i = t !== t, f = t === w; u < o;) {
				var a = uu((u + o) / 2),
					c = r(n[a]),
					l = c === c;
				(i ? l || e : f ? l && (e || c !== w) : e ? c <= t : c < t) ? u = a + 1:
					o = a;

			}
			return xu(o, Cu)
		}

		function zt(n, t, r) {
			if (typeof n != "function") return Re;
			if (t === w) return n;
			switch (r) {
				case 1:
					return function(r) {
						return n.call(t, r)
					};
				case 3:
					return function(r, e, u) {
						return n.call(t, r, e, u)
					};
				case 4:
					return function(r, e, u, o) {
						return n.call(t, r, e, u, o)
					};
				case 5:
					return function(r, e, u, o, i) {
						return n.call(t, r, e, u, o, i)
					}
			}
			return function() {
				return n.apply(t, arguments)
			}
		}

		function Bt(n) {
			return tu.call(n, 0)
		}

		function Mt(n, t, r) {
			for (var e = r.length, u = -1, o = bu(n.length - e, 0), i = -1, f = t.length,
					a = Ue(o + f); ++i < f;) a[i] = t[i];

			for (; ++u < e;) a[r[u]] = n[u];
			for (; o--;) a[i++] = n[u++];
			return a
		}

		function Dt(n, t, r) {
			for (var e = -1, u = r.length, o = -1, i = bu(n.length - u, 0), f = -1, a =
					t.length, c = Ue(i + a); ++o < i;) c[o] = n[o];
			for (i = o; ++f < a;) c[i + f] = t[f];
			for (; ++e < u;) c[i + r[e]] = n[o++];
			return c
		}

		function Pt(n, t) {
			return function(r, e, u) {
				var o = t ? t() : {};
				if (e = dr(e, u, 3), To(r)) {
					u = -1;
					for (var i = r.length; ++u < i;) {
						var f = r[u];
						n(o, f, e(f, u, r), r)
					}
				} else zu(r, function(t, r, u) {
					n(o, t, e(t, r, u), u)
				});
				return o
			}
		}

		function qt(n) {
			return fe(function(t, r) {
				var e = -1,
					u = null == t ? 0 : r.length,
					o = 2 < u && r[u - 2],
					i = 2 < u && r[2],
					f = 1 < u && r[u - 1];

				for (typeof o == "function" ? (o = zt(o, f, 5), u -= 2) : (o = typeof f ==
						"function" ? f : null, u -= o ? 1 : 0), i && Or(r[0], r[1], i) && (o =
						3 > u ? null : o, u = 1); ++e < u;)(i = r[e]) && n(t, i, o);
				return t
			})
		}

		function Kt(n, t) {
			return function(r, e) {
				var u = r ? Yu(r) : 0;
				if (!Rr(u)) return n(r, e);
				for (var o = t ? u : -1, i = Fr(r);
					(t ? o-- : ++o < u) && false !== e(i[o], o, i););
				return r
			}
		}

		function Vt(n) {
			return function(t, r, e) {
				var u = Fr(t);
				e = e(t);
				for (var o = e.length, i = n ? o : -1; n ? i-- : ++i < o;) {
					var f = e[i];
					if (false === r(u[f], f, u)) break
				}
				return t
			}
		}

		function Yt(n, t) {
			function r() {
				return (this && this !== Yn && this instanceof r ? e : n).apply(t,
					arguments);

			}
			var e = Gt(n);
			return r
		}

		function Zt(n) {
			return function(t) {
				var r = -1;
				t = Oe(be(t));
				for (var e = t.length, u = ""; ++r < e;) u = n(u, t[r], r);
				return u
			}
		}

		function Gt(n) {
			return function() {
				var t = Lu(n.prototype),
					r = n.apply(t, arguments);
				return se(r) ? r : t
			}
		}

		function Jt(n) {
			function t(r, e, u) {
				return u && Or(r, e, u) && (e = null), r = hr(r, n, null, null, null,
					null, null, e), r.placeholder = t.placeholder, r
			}
			return t
		}

		function Xt(n, t) {
			return function(r, e, u) {
				u && Or(r, e, u) && (e = null);
				var i = dr(),
					f = null == e;
				if (i === ut && f || (f = false, e = i(e, u, 3)), f) {
					if (e = To(r), e || !ve(r)) return n(e ? r : Nr(r));

					e = o
				}
				return yr(r, e, t)
			}
		}

		function Ht(n, r) {
			return function(e, u, o) {
				return u = dr(u, o, 3), To(e) ? (u = t(e, u, r), -1 < u ? e[u] : w) :
					lt(e, u, n)
			}
		}

		function Qt(n) {
			return function(r, e, u) {
				return r && r.length ? (e = dr(e, u, 3), t(r, e, n)) : -1
			}
		}

		function nr(n) {
			return function(t, r, e) {
				return r = dr(r, e, 3), lt(t, r, n, true)
			}
		}

		function tr(n) {
			return function() {
				var t = arguments.length;
				if (!t) return function() {
					return arguments[0]
				};
				for (var r, e = n ? t : -1, u = 0, o = Ue(t); n ? e-- : ++e < t;) {
					var i = o[u++] = arguments[e];
					if (typeof i != "function") throw new Pe(L);
					var f = r ? "" : Vu(i);

					r = "wrapper" == f ? new zn([]) : r
				}
				for (e = r ? -1 : t; ++e < t;) i = o[e], f = Vu(i), r = (u = "wrapper" ==
						f ? Ku(i) : null) && Ir(u[0]) && u[1] == (R | k | E | C) && !u[4].length &&
					1 == u[9] ? r[Vu(u[0])].apply(r, u[3]) : 1 == i.length && Ir(i) ? r[f]
					() : r.thru(i);
				return function() {
					var n = arguments;
					if (r && 1 == n.length && To(n[0])) return r.plant(n[0]).value();
					for (var e = 0, n = o[e].apply(this, n); ++e < t;) n = o[e].call(this,
						n);
					return n
				}
			}
		}

		function rr(n, t) {
			return function(r, e, u) {
				return typeof e == "function" && u === w && To(r) ? n(r, e) : t(r, zt(e,
					u, 3))
			}
		}

		function er(n) {
			return function(t, r, e) {
				return (typeof r != "function" || e !== w) && (r = zt(r, e, 3)), n(t, r,
					me)
			}
		}

		function ur(n) {
			return function(t, r, e) {
				return (typeof r != "function" || e !== w) && (r = zt(r, e, 3)), n(t, r)
			}
		}

		function or(n) {
			return function(t, r, e) {
				var u = {};
				return r = dr(r, e, 3), ht(t, function(t, e, o) {
					o = r(t, e, o), e = n ? o : e, t = n ? t : o, u[e] = t
				}), u
			}
		}

		function ir(n) {
			return function(t, r, e) {
				return t = u(t), (n ? t : "") + lr(t, r, e) + (n ? "" : t)
			}
		}

		function fr(n) {
			var t = fe(function(r, e) {
				var u = v(e, t.placeholder);
				return hr(r, n, null, e, u)
			});
			return t
		}

		function ar(n, t) {
			return function(r, e, u, o) {
				var i = 3 > arguments.length;
				return typeof e == "function" && o === w && To(r) ? n(r, e, u, i) : Et(
					r, dr(e, o, 4), u, i, t)
			}
		}

		function cr(n, t, r, e, u, o, i, f, a, c) {
			function l() {
				for (var b = arguments.length, j = b, k = Ue(b); j--;) k[j] = arguments[
					j];
				if (e && (k = Mt(k, e, u)), o && (k = Dt(k, o, i)), _ || y) {
					var j = l.placeholder,
						O = v(k, j),
						b = b - O.length;
					if (b < c) {
						var R = f ? qn(f) : null,
							b = bu(c - b, 0),
							C = _ ? O : null,
							O = _ ? null : O,
							W = _ ? k : null,
							k = _ ? null : k;
						return t |= _ ? E : I, t &= ~(_ ? I : E), g || (t &= ~(x | A)), k = [
							n, t, r, W, C, k, O, R, a, b
						], R = cr.apply(w, k), Ir(n) && Gu(R, k), R.placeholder = j, R
					}
				}
				if (j = p ? r : this,
					h && (n = j[m]), f)
					for (R = k.length, b = xu(f.length, R), C = qn(k); b--;) O = f[b], k[b] =
						kr(O, R) ? C[O] : w;
				return s && a < k.length && (k.length = a), (this && this !== Yn &&
					this instanceof l ? d || Gt(n) : n).apply(j, k)
			}
			var s = t & R,
				p = t & x,
				h = t & A,
				_ = t & k,
				g = t & j,
				y = t & O,
				d = !h && Gt(n),
				m = n;
			return l
		}

		function lr(n, t, r) {
			return n = n.length, t = +t, n < t && mu(t) ? (t -= n, r = null == r ?
				" " : r + "", je(r, ru(t / r.length)).slice(0, t)) : ""
		}

		function sr(n, t, r, e) {
			function u() {
				for (var t = -1, f = arguments.length, a = -1, c = e.length, l = Ue(f +
						c); ++a < c;) l[a] = e[a];
				for (; f--;) l[a++] = arguments[++t];
				return (this && this !== Yn && this instanceof u ? i : n).apply(o ? r :
					this, l);

			}
			var o = t & x,
				i = Gt(n);
			return u
		}

		function pr(n) {
			return function(t, r, e, u) {
				var o = dr(e);
				return o === ut && null == e ? $t(t, r, n) : Lt(t, r, o(e, u, 1), n)
			}
		}

		function hr(n, t, r, e, u, o, i, f) {
			var a = t & A;
			if (!a && typeof n != "function") throw new Pe(L);
			var c = e ? e.length : 0;
			if (c || (t &= ~(E | I), e = u = null), c -= u ? u.length : 0, t & I) {
				var l = e,
					s = u;
				e = u = null
			}
			var p = a ? null : Ku(n);
			return r = [n, t, r, e, u, l, s, o, i, f], p && (e = r[1], t = p[1], f =
				e | t, u = t == R && e == k || t == R && e == C && r[7].length <= p[8] ||
				t == (R | C) && e == k, (f < R || u) && (t & x && (r[2] = p[2], f |= e &
						x ? 0 : j), (e = p[3]) && (u = r[3], r[3] = u ? Mt(u, e, p[4]) : qn(e),
						r[4] = u ? v(r[3], z) : qn(p[4])), (e = p[5]) && (u = r[5], r[5] = u ?
						Dt(u, e, p[6]) : qn(e), r[6] = u ? v(r[5], z) : qn(p[6])), (e = p[7]) &&
					(r[7] = qn(e)), t & R && (r[8] = null == r[8] ? p[8] : xu(r[8], p[8])),
					null == r[9] && (r[9] = p[9]), r[0] = p[0], r[1] = f), t = r[1], f = r[
					9]), r[9] = null == f ? a ? 0 : n.length : bu(f - c, 0) || 0, (p ? Pu :
				Gu)(t == x ? Yt(r[0], r[2]) : t != E && t != (x | E) || r[4].length ?
				cr.apply(w, r) : sr.apply(w, r), r)
		}

		function _r(n, t, r, e, u, o, i) {
			var f = -1,
				a = n.length,
				c = t.length,
				l = true;
			if (a != c && (!u || c <= a)) return false;
			for (; l && ++f < a;) {
				var s = n[f],
					p = t[f],
					l = w;
				if (e && (l = u ? e(p, s, f) : e(s, p, f)),
					l === w)
					if (u)
						for (var h = c; h-- && (p = t[h], !(l = s && s === p || r(s, p, e, u,
								o, i))););
					else l = s && s === p || r(s, p, e, u, o, i)
			}
			return !!l
		}

		function vr(n, t, r) {
			switch (r) {
				case D:
				case P:
					return +n == +t;
				case q:
					return n.name == t.name && n.message == t.message;
				case V:
					return n != +n ? t != +t : n == +t;
				case Z:
				case G:
					return n == t + ""
			}
			return false
		}

		function gr(n, t, r, e, u, o, i) {
			var f = Ko(n),
				a = f.length,
				c = Ko(t).length;
			if (a != c && !u) return false;
			for (var c = u, l = -1; ++l < a;) {
				var s = f[l],
					p = u ? s in t : Ge.call(t, s);
				if (p) {
					var h = n[s],
						_ = t[s],
						p = w;
					e && (p = u ? e(_, h, s) : e(h, _, s)), p === w && (p = h && h === _ ||
						r(h, _, e, u, o, i));

				}
				if (!p) return false;
				c || (c = "constructor" == s)
			}
			return c || (r = n.constructor, e = t.constructor, !(r != e &&
						"constructor" in n && "constructor" in t) || typeof r == "function" &&
					r instanceof r && typeof e == "function" && e instanceof e) ? true :
				false
		}

		function yr(n, t, r) {
			var e = r ? Iu : Eu,
				u = e,
				o = u;
			return zu(n, function(n, i, f) {
				i = t(n, i, f), ((r ? i < u : i > u) || i === e && i === o) && (u = i,
					o = n)
			}), o
		}

		function dr(n, t, r) {
			var e = $n.callback || Ee,
				e = e === Ee ? ut : e;
			return r ? e(n, t, r) : e
		}

		function mr(n, t, e) {
			var u = $n.indexOf || Dr,
				u = u === Dr ? r : u;
			return n ? u(n, t, e) : u
		}

		function wr(n) {
			var t = n.length,
				r = new n.constructor(t);

			return t && "string" == typeof n[0] && Ge.call(n, "index") && (r.index =
				n.index, r.input = n.input), r
		}

		function br(n) {
			return n = n.constructor, typeof n == "function" && n instanceof n || (n =
				Be), new n
		}

		function xr(n, t, r) {
			var e = n.constructor;
			switch (t) {
				case J:
					return Bt(n);
				case D:
				case P:
					return new e(+n);
				case X:
				case H:
				case Q:
				case nn:
				case tn:
				case rn:
				case en:
				case un:
				case on:
					return t = n.buffer, new e(r ? Bt(t) : t, n.byteOffset, n.length);
				case V:
				case G:
					return new e(n);
				case Z:
					var u = new e(n.source, kn.exec(n));
					u.lastIndex = n.lastIndex
			}
			return u;

		}

		function Ar(n, t, r) {
			return null == n || Er(t, n) || (t = $r(t), n = 1 == t.length ? n : gt(n,
				It(t, 0, -1)), t = Pr(t)), t = null == n ? n : n[t], null == t ? w : t.apply(
				n, r)
		}

		function jr(n) {
			return null != n && Rr(Yu(n))
		}

		function kr(n, t) {
			return n = +n, t = null == t ? Tu : t, -1 < n && 0 == n % 1 && n < t
		}

		function Or(n, t, r) {
			if (!se(r)) return false;
			var e = typeof t;
			return ("number" == e ? jr(r) && kr(t, r.length) : "string" == e && t in
				r) ? (t = r[t], n === n ? n === t : t !== t) : false
		}

		function Er(n, t) {
			var r = typeof n;
			return "string" == r && dn.test(n) || "number" == r ? true : To(n) ?
				false : !yn.test(n) || null != t && n in Fr(t);

		}

		function Ir(n) {
			var t = Vu(n);
			return !!t && n === $n[t] && t in Bn.prototype
		}

		function Rr(n) {
			return typeof n == "number" && -1 < n && 0 == n % 1 && n <= Tu
		}

		function Cr(n) {
			return n === n && !se(n)
		}

		function Wr(n, t) {
			n = Fr(n);
			for (var r = -1, e = t.length, u = {}; ++r < e;) {
				var o = t[r];
				o in n && (u[o] = n[o])
			}
			return u
		}

		function Sr(n, t) {
			var r = {};
			return pt(n, function(n, e, u) {
				t(n, e, u) && (r[e] = n)
			}), r
		}

		function Tr(n) {
			var t;
			if (!h(n) || Xe.call(n) != Y || !(Ge.call(n, "constructor") || (t = n.constructor,
					typeof t != "function" || t instanceof t))) return false;
			var r;
			return pt(n, function(n, t) {
				r = t
			}), r === w || Ge.call(n, r)
		}

		function Ur(n) {
			for (var t = me(n), r = t.length, e = r && n.length, u = $n.support, u =
					e && Rr(e) && (To(n) || u.nonEnumArgs && ae(n)), o = -1, i = []; ++o <
				r;) {
				var f = t[o];
				(u && kr(f, e) || Ge.call(n, f)) && i.push(f)
			}
			return i
		}

		function Nr(n) {
			return null == n ? [] : jr(n) ? se(n) ? n : Be(n) : we(n)
		}

		function Fr(n) {
			return se(n) ? n : Be(n)
		}

		function $r(n) {
			if (To(n)) return n;
			var t = [];
			return u(n).replace(mn, function(n, r, e, u) {
				t.push(e ? u.replace(An, "$1") : r || n)
			}), t
		}

		function Lr(n) {
			return n instanceof Bn ? n.clone() : new zn(n.__wrapped__, n.__chain__,
				qn(n.__actions__));

		}

		function zr(n, t, r) {
			return n && n.length ? ((r ? Or(n, t, r) : null == t) && (t = 1), It(n, 0 >
				t ? 0 : t)) : []
		}

		function Br(n, t, r) {
			var e = n ? n.length : 0;
			return e ? ((r ? Or(n, t, r) : null == t) && (t = 1), t = e - (+t || 0),
				It(n, 0, 0 > t ? 0 : t)) : []
		}

		function Mr(n) {
			return n ? n[0] : w
		}

		function Dr(n, t, e) {
			var u = n ? n.length : 0;
			if (!u) return -1;
			if (typeof e == "number") e = 0 > e ? bu(u + e, 0) : e;
			else if (e) return e = $t(n, t), n = n[e], (t === t ? t === n : n !== n) ?
				e : -1;
			return r(n, t, e || 0)
		}

		function Pr(n) {
			var t = n ? n.length : 0;
			return t ? n[t - 1] : w
		}

		function qr(n) {
			return zr(n, 1)
		}

		function Kr(n, t, e, u) {
			if (!n || !n.length) return [];
			null != t && typeof t != "boolean" && (u = e, e = Or(n, t, u) ? null : t,
				t = false);
			var o = dr();
			if ((o !== ut || null != e) && (e = o(e, u, 3)), t && mr() == r) {
				t = e;
				var i;
				e = -1, u = n.length;
				for (var o = -1, f = []; ++e < u;) {
					var a = n[e],
						c = t ? t(a, e, n) : a;
					e && i === c || (i = c, f[++o] = a)
				}
				n = f
			} else n = Tt(n, e);
			return n
		}

		function Vr(n) {
			if (!n || !n.length) return [];
			var t = -1,
				r = 0;
			n = Gn(n, function(n) {
				return jr(n) ? (r = bu(n.length, r), true) : void 0
			});
			for (var e = Ue(r); ++t < r;) e[t] = Jn(n, At(t));
			return e
		}

		function Yr(n, t, r) {
			return n && n.length ? (n = Vr(n), null == t ? n : (t = zt(t, r, 4),
				Jn(n, function(n) {
					return Xn(n, t, w, true)
				}))) : []
		}

		function Zr(n, t) {
			var r = -1,
				e = n ? n.length : 0,
				u = {};
			for (!e || t || To(n[0]) || (t = []); ++r < e;) {
				var o = n[r];
				t ? u[o] = t[r] : o && (u[o[0]] = o[1])
			}
			return u
		}

		function Gr(n) {
			return n = $n(n), n.__chain__ = true, n
		}

		function Jr(n, t, r) {
			return t.call(r, n)
		}

		function Xr(n, t, r) {
			var e = To(n) ? Vn : at;
			return r && Or(n, t, r) && (t = null), (typeof t != "function" || r !== w) &&
				(t = dr(t, r, 3)), e(n, t)
		}

		function Hr(n, t, r) {
			var e = To(n) ? Gn : ct;
			return t = dr(t, r, 3), e(n, t)
		}

		function Qr(n, t, r, e) {
			var u = n ? Yu(n) : 0;
			return Rr(u) || (n = we(n),
				u = n.length), u ? (r = typeof r != "number" || e && Or(t, r, e) ? 0 :
				0 > r ? bu(u + r, 0) : r || 0, typeof n == "string" || !To(n) && ve(n) ?
				r < u && -1 < n.indexOf(t, r) : -1 < mr(n, t, r)) : false
		}

		function ne(n, t, r) {
			var e = To(n) ? Jn : mt;
			return t = dr(t, r, 3), e(n, t)
		}

		function te(n, t, r) {
			return (r ? Or(n, t, r) : null == t) ? (n = Nr(n), t = n.length, 0 < t ?
				n[Ot(0, t - 1)] : w) : (n = re(n), n.length = xu(0 > t ? 0 : +t || 0, n
				.length), n)
		}

		function re(n) {
			n = Nr(n);
			for (var t = -1, r = n.length, e = Ue(r); ++t < r;) {
				var u = Ot(0, t);
				t != u && (e[t] = e[u]), e[u] = n[t]
			}
			return e
		}

		function ee(n, t, r) {
			var e = To(n) ? Hn : Rt;
			return r && Or(n, t, r) && (t = null), (typeof t != "function" || r !== w) &&
				(t = dr(t, r, 3)), e(n, t)
		}

		function ue(n, t) {
			var r;
			if (typeof t != "function") {
				if (typeof n != "function") throw new Pe(L);
				var e = n;
				n = t, t = e
			}
			return function() {
				return 0 < --n && (r = t.apply(this, arguments)), 1 >= n && (t = null),
					r
			}
		}

		function oe(n, t, r) {
			function e() {
				var r = t - (wo() - c);
				0 >= r || r > t ? (f && eu(f), r = p, f = s = p = w, r && (h = wo(), a =
					n.apply(l, i), s || f || (i = l = null))) : s = su(e, r)
			}

			function u() {
				s && eu(s), f = s = p = w, (v || _ !== t) && (h = wo(), a = n.apply(l,
					i), s || f || (i = l = null))
			}

			function o() {
				if (i = arguments, c = wo(), l = this, p = v && (s || !g), !1 === _) var
					r = g && !s;
				else {
					f || g || (h = c);
					var o = _ - (c - h),
						y = 0 >= o || o > _;
					y ? (f && (f = eu(f)), h = c, a = n.apply(l, i)) : f || (f = su(u, o))
				}
				return y && s ? s = eu(s) : s || t === _ || (s = su(e, t)), r && (y =
					true, a = n.apply(l, i)), !y || s || f || (i = l = null), a
			}
			var i, f, a, c, l, s, p, h = 0,
				_ = false,
				v = true;
			if (typeof n != "function") throw new Pe(L);
			if (t = 0 > t ? 0 : +t || 0, true === r) var g = true,
				v = false;
			else se(r) && (g = r.leading, _ = "maxWait" in r && bu(+r.maxWait || 0, t),
				v = "trailing" in r ? r.trailing : v);
			return o.cancel = function() {
				s && eu(s), f && eu(f), f = s = p = w
			}, o
		}

		function ie(n, t) {
			function r() {
				var e = arguments,
					u = r.cache,
					o = t ? t.apply(this, e) : e[0];

				return u.has(o) ? u.get(o) : (e = n.apply(this, e), u.set(o, e), e)
			}
			if (typeof n != "function" || t && typeof t != "function") throw new Pe(L);
			return r.cache = new ie.Cache, r
		}

		function fe(n, t) {
			if (typeof n != "function") throw new Pe(L);
			return t = bu(t === w ? n.length - 1 : +t || 0, 0),
				function() {
					for (var r = arguments, e = -1, u = bu(r.length - t, 0), o = Ue(u); ++e <
						u;) o[e] = r[t + e];
					switch (t) {
						case 0:
							return n.call(this, o);
						case 1:
							return n.call(this, r[0], o);
						case 2:
							return n.call(this, r[0], r[1], o)
					}
					for (u = Ue(t + 1), e = -1; ++e < t;) u[e] = r[e];
					return u[t] = o, n.apply(this, u);

				}
		}

		function ae(n) {
			return h(n) && jr(n) && Xe.call(n) == B
		}

		function ce(n) {
			return !!n && 1 === n.nodeType && h(n) && -1 < Xe.call(n).indexOf(
				"Element")
		}

		function le(n) {
			return h(n) && typeof n.message == "string" && Xe.call(n) == q
		}

		function se(n) {
			var t = typeof n;
			return "function" == t || !!n && "object" == t
		}

		function pe(n) {
			return null == n ? false : Xe.call(n) == K ? Qe.test(Ze.call(n)) : h(n) &&
				En.test(n)
		}

		function he(n) {
			return typeof n == "number" || h(n) && Xe.call(n) == V
		}

		function _e(n) {
			return h(n) && Xe.call(n) == Z
		}

		function ve(n) {
			return typeof n == "string" || h(n) && Xe.call(n) == G;

		}

		function ge(n) {
			return h(n) && Rr(n.length) && !!Un[Xe.call(n)]
		}

		function ye(n) {
			return et(n, me(n))
		}

		function de(n) {
			return vt(n, me(n))
		}

		function me(n) {
			if (null == n) return [];
			se(n) || (n = Be(n));
			for (var t = n.length, t = t && Rr(t) && (To(n) || Fu.nonEnumArgs && ae(n)) &&
					t || 0, r = n.constructor, e = -1, r = typeof r == "function" && r.prototype ===
					n, u = Ue(t), o = 0 < t; ++e < t;) u[e] = e + "";
			for (var i in n) o && kr(i, t) || "constructor" == i && (r || !Ge.call(n,
				i)) || u.push(i);
			return u
		}

		function we(n) {
			return Ut(n, Ko(n))
		}

		function be(n) {
			return (n = u(n)) && n.replace(In, c).replace(xn, "");

		}

		function xe(n) {
			return (n = u(n)) && bn.test(n) ? n.replace(wn, "\\$&") : n
		}

		function Ae(n, t, r) {
			return r && Or(n, t, r) && (t = 0), ku(n, t)
		}

		function je(n, t) {
			var r = "";
			if (n = u(n), t = +t, 1 > t || !n || !mu(t)) return r;
			do t % 2 && (r += n), t = uu(t / 2), n += n; while (t);
			return r
		}

		function ke(n, t, r) {
			var e = n;
			return (n = u(n)) ? (r ? Or(e, t, r) : null == t) ? n.slice(g(n), y(n) +
				1) : (t += "", n.slice(i(n, t), f(n, t) + 1)) : n
		}

		function Oe(n, t, r) {
			return r && Or(n, t, r) && (t = null), n = u(n), n.match(t || Wn) || []
		}

		function Ee(n, t, r) {
			return r && Or(n, t, r) && (t = null), h(n) ? Ce(n) : ut(n, t)
		}

		function Ie(n) {
			return function() {
				return n
			}
		}

		function Re(n) {
			return n
		}

		function Ce(n) {
			return wt(ot(n, true))
		}

		function We(n, t, r) {
			if (null == r) {
				var e = se(t),
					u = e && Ko(t);
				((u = u && u.length && vt(t, u)) ? u.length : e) || (u = false, r = t, t =
					n, n = this)
			}
			u || (u = vt(t, Ko(t)));
			var o = true,
				e = -1,
				i = No(n),
				f = u.length;
			false === r ? o = false : se(r) && "chain" in r && (o = r.chain);
			for (; ++e < f;) {
				r = u[e];
				var a = t[r];
				n[r] = a, i && (n.prototype[r] = function(t) {
					return function() {
						var r = this.__chain__;
						if (o || r) {
							var e = n(this.__wrapped__);
							return (e.__actions__ = qn(this.__actions__)).push({
								func: t,
								args: arguments,
								thisArg: n
							}), e.__chain__ = r, e
						}
						return r = [this.value()], fu.apply(r, arguments), t.apply(n, r)
					}
				}(a))
			}
			return n
		}

		function Se() {}

		function Te(n) {
			return Er(n) ? At(n) : jt(n)
		}
		_ = _ ? Zn.defaults(Yn.Object(), _, Zn.pick(Yn, Tn)) : Yn;
		var Ue = _.Array,
			Ne = _.Date,
			Fe = _.Error,
			$e = _.Function,
			Le = _.Math,
			ze = _.Number,
			Be = _.Object,
			Me = _.RegExp,
			De = _.String,
			Pe = _.TypeError,
			qe = Ue.prototype,
			Ke = Be.prototype,
			Ve = De.prototype,
			Ye = (Ye = _.window) && Ye.document,
			Ze = $e.prototype.toString,
			Ge = Ke.hasOwnProperty,
			Je = 0,
			Xe = Ke.toString,
			He = _._,
			Qe = Me("^" + xe(Xe).replace(
				/toString|(function).*?(?=\\\()| for .+?(?=\\\])/g, "$1.*?") + "$"),
			nu = pe(nu = _.ArrayBuffer) && nu,
			tu = pe(tu = nu && new nu(0).slice) && tu,
			ru = Le.ceil,
			eu = _.clearTimeout,
			uu = Le.floor,
			ou = pe(ou = Be.getOwnPropertySymbols) && ou,
			iu = pe(iu = Be.getPrototypeOf) && iu,
			fu = qe.push,
			au = pe(au = Be.preventExtensions) && au,
			cu = Ke.propertyIsEnumerable,
			lu = pe(lu = _.Set) && lu,
			su = _.setTimeout,
			pu = qe.splice,
			hu = pe(hu = _.Uint8Array) && hu,
			_u = pe(_u = _.WeakMap) && _u,
			vu = function() {
				try {
					var n = pe(n = _.Float64Array) && n,
						t = new n(new nu(10), 0, 1) && n
				} catch (r) {}
				return t
			}(),
			gu = function() {
				var n = au && pe(n = Be.assign) && n;
				try {
					if (n) {
						var t = au({
							1: 0
						});
						t[0] = 1
					}
				} catch (r) {
					try {
						n(t, "xo")
					} catch (e) {}
					return !t[1] && n
				}
				return false
			}(),
			yu = pe(yu = Ue.isArray) && yu,
			du = pe(du = Be.create) && du,
			mu = _.isFinite,
			wu = pe(wu = Be.keys) && wu,
			bu = Le.max,
			xu = Le.min,
			Au = pe(Au = Ne.now) && Au,
			ju = pe(ju = ze.isFinite) && ju,
			ku = _.parseInt,
			Ou = Le.random,
			Eu = ze.NEGATIVE_INFINITY,
			Iu = ze.POSITIVE_INFINITY,
			Ru = Le.pow(2, 32) - 1,
			Cu = Ru - 1,
			Wu = Ru >>> 1,
			Su = vu ? vu.BYTES_PER_ELEMENT : 0,
			Tu = Le.pow(2, 53) - 1,
			Uu = _u && new _u,
			Nu = {},
			Fu = $n.support = {};

		! function(n) {
			function t() {
				this.x = n
			}
			var r = arguments,
				e = [];
			t.prototype = {
				valueOf: n,
				y: n
			};
			for (var u in new t) e.push(u);
			Fu.funcDecomp = /\bthis\b/.test(function() {
				return this
			}), Fu.funcNames = typeof $e.name == "string";
			try {
				Fu.dom = 11 === Ye.createDocumentFragment().nodeType
			} catch (o) {
				Fu.dom = false
			}
			try {
				Fu.nonEnumArgs = !cu.call(r, 1)
			} catch (i) {
				Fu.nonEnumArgs = true
			}
		}(1, 0), $n.templateSettings = {
			escape: _n,
			evaluate: vn,
			interpolate: gn,
			variable: "",
			imports: {
				_: $n
			}
		};
		var $u = gu || function(n, t) {
				return null == t ? n : et(t, Zu(t), et(t, Ko(t), n))
			},
			Lu = function() {
				function n() {}
				return function(t) {
					if (se(t)) {
						n.prototype = t;
						var r = new n;
						n.prototype = null
					}
					return r || _.Object()
				}
			}(),
			zu = Kt(ht),
			Bu = Kt(_t, true),
			Mu = Vt(),
			Du = Vt(true),
			Pu = Uu ? function(n, t) {
				return Uu.set(n, t), n
			} : Re;
		tu || (Bt = nu && hu ? function(n) {
			var t = n.byteLength,
				r = vu ? uu(t / Su) : 0,
				e = r * Su,
				u = new nu(t);
			if (r) {
				var o = new vu(u, 0, r);
				o.set(new vu(n, 0, r))
			}
			return t != e && (o = new hu(u, e), o.set(new hu(n, e))), u
		} : Ie(null));
		var qu = du && lu ? function(n) {
				return new Dn(n)
			} : Ie(null),
			Ku = Uu ? function(n) {
				return Uu.get(n)
			} : Se,
			Vu = function() {
				return Fu.funcNames ? "constant" == Ie.name ? At("name") : function(n) {
					for (var t = n.name, r = Nu[t], e = r ? r.length : 0; e--;) {
						var u = r[e],
							o = u.func;
						if (null == o || o == n) return u.name
					}
					return t
				} : Ie("")
			}(),
			Yu = At("length"),
			Zu = ou ? function(n) {
				return ou(Fr(n))
			} : Ie([]),
			Gu = function() {
				var n = 0,
					t = 0;
				return function(r, e) {
					var u = wo(),
						o = U - (u - t);
					if (t = u, 0 < o) {
						if (++n >= T) return r
					} else n = 0;
					return Pu(r, e)
				}
			}(),
			Ju = fe(function(n, t) {
				return jr(n) ? ft(n, st(t, false, true)) : []
			}),
			Xu = Qt(),
			Hu = Qt(true),
			Qu = fe(function(t, r) {
				r = st(r);
				var e = rt(t, r);
				return kt(t, r.sort(n)), e
			}),
			no = pr(),
			to = pr(true),
			ro = fe(function(n) {
				return Tt(st(n, false, true));

			}),
			eo = fe(function(n, t) {
				return jr(n) ? ft(n, t) : []
			}),
			uo = fe(Vr),
			oo = fe(function(n) {
				var t = n.length,
					r = n[t - 2],
					e = n[t - 1];
				return 2 < t && typeof r == "function" ? t -= 2 : (r = 1 < t && typeof e ==
					"function" ? (--t, e) : w, e = w), n.length = t, Yr(n, r, e)
			}),
			io = fe(function(n, t) {
				return rt(n, st(t))
			}),
			fo = Pt(function(n, t, r) {
				Ge.call(n, r) ? ++n[r] : n[r] = 1
			}),
			ao = Ht(zu),
			co = Ht(Bu, true),
			lo = rr(Kn, zu),
			so = rr(function(n, t) {
				for (var r = n.length; r-- && false !== t(n[r], r, n););
				return n
			}, Bu),
			po = Pt(function(n, t, r) {
				Ge.call(n, r) ? n[r].push(t) : n[r] = [t]
			}),
			ho = Pt(function(n, t, r) {
				n[r] = t
			}),
			_o = fe(function(n, t, r) {
				var e = -1,
					u = typeof t == "function",
					o = Er(t),
					i = jr(n) ? Ue(n.length) : [];
				return zu(n, function(n) {
					var f = u ? t : o && null != n && n[t];
					i[++e] = f ? f.apply(n, r) : Ar(n, t, r)
				}), i
			}),
			vo = Pt(function(n, t, r) {
				n[r ? 0 : 1].push(t)
			}, function() {
				return [
					[],
					[]
				]
			}),
			go = ar(Xn, zu),
			yo = ar(function(n, t, r, e) {
				var u = n.length;
				for (e && u && (r = n[--u]); u--;) r = t(r, n[u], u, n);
				return r
			}, Bu),
			mo = fe(function(n, t) {
				if (null == n) return [];
				var r = t[2];
				return r && Or(t[0], t[1], r) && (t.length = 1), Wt(n, st(t), [])
			}),
			wo = Au || function() {
				return (new Ne).getTime();

			},
			bo = fe(function(n, t, r) {
				var e = x;
				if (r.length) var u = v(r, bo.placeholder),
					e = e | E;
				return hr(n, e, t, r, u)
			}),
			xo = fe(function(n, t) {
				t = t.length ? st(t) : de(n);
				for (var r = -1, e = t.length; ++r < e;) {
					var u = t[r];
					n[u] = hr(n[u], x, n)
				}
				return n
			}),
			Ao = fe(function(n, t, r) {
				var e = x | A;
				if (r.length) var u = v(r, Ao.placeholder),
					e = e | E;
				return hr(t, e, n, r, u)
			}),
			jo = Jt(k),
			ko = Jt(O),
			Oo = fe(function(n, t) {
				return it(n, 1, t)
			}),
			Eo = fe(function(n, t, r) {
				return it(n, t, r)
			}),
			Io = tr(),
			Ro = tr(true),
			Co = fr(E),
			Wo = fr(I),
			So = fe(function(n, t) {
				return hr(n, C, null, null, null, st(t));

			}),
			To = yu || function(n) {
				return h(n) && Rr(n.length) && Xe.call(n) == M
			};
		Fu.dom || (ce = function(n) {
			return !!n && 1 === n.nodeType && h(n) && !Fo(n)
		});
		var Uo = ju || function(n) {
				return typeof n == "number" && mu(n)
			},
			No = e(/x/) || hu && !e(hu) ? function(n) {
				return Xe.call(n) == K
			} : e,
			Fo = iu ? function(n) {
				if (!n || Xe.call(n) != Y) return false;
				var t = n.valueOf,
					r = pe(t) && (r = iu(t)) && iu(r);
				return r ? n == r || iu(n) == r : Tr(n)
			} : Tr,
			$o = qt(function(n, t, r) {
				return r ? tt(n, t, r) : $u(n, t)
			}),
			Lo = fe(function(n) {
				var t = n[0];
				return null == t ? t : (n.push(Qn), $o.apply(w, n))
			}),
			zo = nr(ht),
			Bo = nr(_t),
			Mo = er(Mu),
			Do = er(Du),
			Po = ur(ht),
			qo = ur(_t),
			Ko = wu ? function(n) {
				var t = null != n && n.constructor;
				return typeof t == "function" && t.prototype === n || typeof n !=
					"function" && jr(n) ? Ur(n) : se(n) ? wu(n) : []
			} : Ur,
			Vo = or(true),
			Yo = or(),
			Zo = qt(xt),
			Go = fe(function(n, t) {
				if (null == n) return {};
				if ("function" != typeof t[0]) return t = Jn(st(t), De), Wr(n, ft(me(n),
					t));
				var r = zt(t[0], t[1], 3);
				return Sr(n, function(n, t, e) {
					return !r(n, t, e)
				})
			}),
			Jo = fe(function(n, t) {
				return null == n ? {} : "function" == typeof t[0] ? Sr(n, zt(t[0], t[1],
					3)) : Wr(n, st(t))
			}),
			Xo = Zt(function(n, t, r) {
				return t = t.toLowerCase(), n + (r ? t.charAt(0).toUpperCase() + t.slice(
					1) : t);

			}),
			Ho = Zt(function(n, t, r) {
				return n + (r ? "-" : "") + t.toLowerCase()
			}),
			Qo = ir(),
			ni = ir(true);
		8 != ku(Sn + "08") && (Ae = function(n, t, r) {
			return (r ? Or(n, t, r) : null == t) ? t = 0 : t && (t = +t), n = ke(n),
				ku(n, t || (On.test(n) ? 16 : 10))
		});
		var ti = Zt(function(n, t, r) {
				return n + (r ? "_" : "") + t.toLowerCase()
			}),
			ri = Zt(function(n, t, r) {
				return n + (r ? " " : "") + (t.charAt(0).toUpperCase() + t.slice(1))
			}),
			ei = fe(function(n, t) {
				try {
					return n.apply(w, t)
				} catch (r) {
					return le(r) ? r : new Fe(r)
				}
			}),
			ui = fe(function(n, t) {
				return function(r) {
					return Ar(r, n, t)
				}
			}),
			oi = fe(function(n, t) {
				return function(r) {
					return Ar(n, r, t)
				}
			}),
			ii = Xt(function(n) {
				for (var t = -1, r = n.length, e = Eu; ++t < r;) {
					var u = n[t];
					u > e && (e = u)
				}
				return e
			}),
			fi = Xt(function(n) {
				for (var t = -1, r = n.length, e = Iu; ++t < r;) {
					var u = n[t];
					u < e && (e = u)
				}
				return e
			}, true);
		return $n.prototype = Ln.prototype, zn.prototype = Lu(Ln.prototype), zn.prototype
			.constructor = zn, Bn.prototype = Lu(Ln.prototype), Bn.prototype.constructor =
			Bn, Mn.prototype["delete"] = function(n) {
				return this.has(n) && delete this.__data__[n]
			}, Mn.prototype.get = function(n) {
				return "__proto__" == n ? w : this.__data__[n];

			}, Mn.prototype.has = function(n) {
				return "__proto__" != n && Ge.call(this.__data__, n)
			}, Mn.prototype.set = function(n, t) {
				return "__proto__" != n && (this.__data__[n] = t), this
			}, Dn.prototype.push = function(n) {
				var t = this.data;
				typeof n == "string" || se(n) ? t.set.add(n) : t.hash[n] = true
			}, ie.Cache = Mn, $n.after = function(n, t) {
				if (typeof t != "function") {
					if (typeof n != "function") throw new Pe(L);
					var r = n;
					n = t, t = r
				}
				return n = mu(n = +n) ? n : 0,
					function() {
						return 1 > --n ? t.apply(this, arguments) : void 0
					}
			}, $n.ary = function(n, t, r) {
				return r && Or(n, t, r) && (t = null),
					t = n && null == t ? n.length : bu(+t || 0, 0), hr(n, R, null, null,
						null, null, t)
			}, $n.assign = $o, $n.at = io, $n.before = ue, $n.bind = bo, $n.bindAll =
			xo, $n.bindKey = Ao, $n.callback = Ee, $n.chain = Gr, $n.chunk = function(
				n, t, r) {
				t = (r ? Or(n, t, r) : null == t) ? 1 : bu(+t || 1, 1), r = 0;
				for (var e = n ? n.length : 0, u = -1, o = Ue(ru(e / t)); r < e;) o[++u] =
					It(n, r, r += t);
				return o
			}, $n.compact = function(n) {
				for (var t = -1, r = n ? n.length : 0, e = -1, u = []; ++t < r;) {
					var o = n[t];
					o && (u[++e] = o)
				}
				return u
			}, $n.constant = Ie, $n.countBy = fo, $n.create = function(n, t, r) {
				var e = Lu(n);
				return r && Or(n, t, r) && (t = null),
					t ? $u(e, t) : e
			}, $n.curry = jo, $n.curryRight = ko, $n.debounce = oe, $n.defaults = Lo,
			$n.defer = Oo, $n.delay = Eo, $n.difference = Ju, $n.drop = zr, $n.dropRight =
			Br, $n.dropRightWhile = function(n, t, r) {
				return n && n.length ? Nt(n, dr(t, r, 3), true, true) : []
			}, $n.dropWhile = function(n, t, r) {
				return n && n.length ? Nt(n, dr(t, r, 3), true) : []
			}, $n.fill = function(n, t, r, e) {
				var u = n ? n.length : 0;
				if (!u) return [];
				for (r && typeof r != "number" && Or(n, t, r) && (r = 0, e = u), u = n.length,
					r = null == r ? 0 : +r || 0, 0 > r && (r = -r > u ? 0 : u + r), e = e ===
					w || e > u ? u : +e || 0, 0 > e && (e += u), u = r > e ? 0 : e >>> 0, r >>>=
					0; r < u;) n[r++] = t;

				return n
			}, $n.filter = Hr, $n.flatten = function(n, t, r) {
				var e = n ? n.length : 0;
				return r && Or(n, t, r) && (t = false), e ? st(n, t) : []
			}, $n.flattenDeep = function(n) {
				return n && n.length ? st(n, true) : []
			}, $n.flow = Io, $n.flowRight = Ro, $n.forEach = lo, $n.forEachRight = so,
			$n.forIn = Mo, $n.forInRight = Do, $n.forOwn = Po, $n.forOwnRight = qo, $n
			.functions = de, $n.groupBy = po, $n.indexBy = ho, $n.initial = function(n) {
				return Br(n, 1)
			}, $n.intersection = function() {
				for (var n = [], t = -1, e = arguments.length, u = [], o = mr(), i = o ==
						r, f = []; ++t < e;) {
					var a = arguments[t];
					jr(a) && (n.push(a),
						u.push(i && 120 <= a.length ? qu(t && a) : null))
				}
				if (e = n.length, 2 > e) return f;
				var i = n[0],
					c = -1,
					l = i ? i.length : 0,
					s = u[0];
				n: for (; ++c < l;)
					if (a = i[c], 0 > (s ? Pn(s, a) : o(f, a, 0))) {
						for (t = e; --t;) {
							var p = u[t];
							if (0 > (p ? Pn(p, a) : o(n[t], a, 0))) continue n
						}
						s && s.push(a), f.push(a)
					}
				return f
			}, $n.invert = function(n, t, r) {
				r && Or(n, t, r) && (t = null), r = -1;
				for (var e = Ko(n), u = e.length, o = {}; ++r < u;) {
					var i = e[r],
						f = n[i];
					t ? Ge.call(o, f) ? o[f].push(i) : o[f] = [i] : o[f] = i
				}
				return o
			}, $n.invoke = _o, $n.keys = Ko, $n.keysIn = me, $n.map = ne, $n.mapKeys =
			Vo, $n.mapValues = Yo, $n.matches = Ce,
			$n.matchesProperty = function(n, t) {
				return bt(n, ot(t, true))
			}, $n.memoize = ie, $n.merge = Zo, $n.method = ui, $n.methodOf = oi, $n.mixin =
			We, $n.negate = function(n) {
				if (typeof n != "function") throw new Pe(L);
				return function() {
					return !n.apply(this, arguments)
				}
			}, $n.omit = Go, $n.once = function(n) {
				return ue(2, n)
			}, $n.pairs = function(n) {
				for (var t = -1, r = Ko(n), e = r.length, u = Ue(e); ++t < e;) {
					var o = r[t];
					u[t] = [o, n[o]]
				}
				return u
			}, $n.partial = Co, $n.partialRight = Wo, $n.partition = vo, $n.pick = Jo,
			$n.pluck = function(n, t) {
				return ne(n, Te(t))
			}, $n.property = Te,
			$n.propertyOf = function(n) {
				return function(t) {
					return gt(n, $r(t), t + "")
				}
			}, $n.pull = function() {
				var n = arguments,
					t = n[0];
				if (!t || !t.length) return t;
				for (var r = 0, e = mr(), u = n.length; ++r < u;)
					for (var o = 0, i = n[r]; - 1 < (o = e(t, i, o));) pu.call(t, o, 1);
				return t
			}, $n.pullAt = Qu, $n.range = function(n, t, r) {
				r && Or(n, t, r) && (t = r = null), n = +n || 0, r = null == r ? 1 : +r ||
					0, null == t ? (t = n, n = 0) : t = +t || 0;
				var e = -1;
				t = bu(ru((t - n) / (r || 1)), 0);
				for (var u = Ue(t); ++e < t;) u[e] = n, n += r;
				return u
			}, $n.rearg = So, $n.reject = function(n, t, r) {
				var e = To(n) ? Gn : ct;
				return t = dr(t, r, 3),
					e(n, function(n, r, e) {
						return !t(n, r, e)
					})
			}, $n.remove = function(n, t, r) {
				var e = [];
				if (!n || !n.length) return e;
				var u = -1,
					o = [],
					i = n.length;
				for (t = dr(t, r, 3); ++u < i;) r = n[u], t(r, u, n) && (e.push(r), o.push(
					u));
				return kt(n, o), e
			}, $n.rest = qr, $n.restParam = fe, $n.set = function(n, t, r) {
				if (null == n) return n;
				var e = t + "";
				t = null != n[e] || Er(t, n) ? [e] : $r(t);
				for (var e = -1, u = t.length, o = u - 1, i = n; null != i && ++e < u;) {
					var f = t[e];
					se(i) && (e == o ? i[f] = r : null == i[f] && (i[f] = kr(t[e + 1]) ? [] : {})),
						i = i[f]
				}
				return n
			}, $n.shuffle = re, $n.slice = function(n, t, r) {
				var e = n ? n.length : 0;

				return e ? (r && typeof r != "number" && Or(n, t, r) && (t = 0, r = e),
					It(n, t, r)) : []
			}, $n.sortBy = function(n, t, r) {
				if (null == n) return [];
				r && Or(n, t, r) && (t = null);
				var e = -1;
				return t = dr(t, r, 3), n = mt(n, function(n, r, u) {
					return {
						a: t(n, r, u),
						b: ++e,
						c: n
					}
				}), Ct(n, a)
			}, $n.sortByAll = mo, $n.sortByOrder = function(n, t, r, e) {
				return null == n ? [] : (e && Or(t, r, e) && (r = null), To(t) || (t =
					null == t ? [] : [t]), To(r) || (r = null == r ? [] : [r]), Wt(n, t, r))
			}, $n.spread = function(n) {
				if (typeof n != "function") throw new Pe(L);
				return function(t) {
					return n.apply(this, t)
				}
			}, $n.take = function(n, t, r) {
				return n && n.length ? ((r ? Or(n, t, r) : null == t) && (t = 1), It(n, 0,
					0 > t ? 0 : t)) : []
			}, $n.takeRight = function(n, t, r) {
				var e = n ? n.length : 0;
				return e ? ((r ? Or(n, t, r) : null == t) && (t = 1), t = e - (+t || 0),
					It(n, 0 > t ? 0 : t)) : []
			}, $n.takeRightWhile = function(n, t, r) {
				return n && n.length ? Nt(n, dr(t, r, 3), false, true) : []
			}, $n.takeWhile = function(n, t, r) {
				return n && n.length ? Nt(n, dr(t, r, 3)) : []
			}, $n.tap = function(n, t, r) {
				return t.call(r, n), n
			}, $n.throttle = function(n, t, r) {
				var e = true,
					u = true;
				if (typeof n != "function") throw new Pe(L);
				return false === r ? e = false : se(r) && (e = "leading" in r ? !!r.leading :
						e,
						u = "trailing" in r ? !!r.trailing : u), Fn.leading = e, Fn.maxWait = +
					t, Fn.trailing = u, oe(n, t, Fn)
			}, $n.thru = Jr, $n.times = function(n, t, r) {
				if (n = uu(n), 1 > n || !mu(n)) return [];
				var e = -1,
					u = Ue(xu(n, Ru));
				for (t = zt(t, r, 1); ++e < n;) e < Ru ? u[e] = t(e) : t(e);
				return u
			}, $n.toArray = function(n) {
				var t = n ? Yu(n) : 0;
				return Rr(t) ? t ? qn(n) : [] : we(n)
			}, $n.toPlainObject = ye, $n.transform = function(n, t, r, e) {
				var u = To(n) || ge(n);
				return t = dr(t, e, 4), null == r && (u || se(n) ? (e = n.constructor, r =
					u ? To(n) ? new e : [] : Lu(No(e) && e.prototype)) : r = {}), (u ? Kn :
					ht)(n, function(n, e, u) {
					return t(r, n, e, u)
				}), r
			}, $n.union = ro, $n.uniq = Kr, $n.unzip = Vr, $n.unzipWith = Yr, $n.values =
			we, $n.valuesIn = function(n) {
				return Ut(n, me(n))
			}, $n.where = function(n, t) {
				return Hr(n, wt(t))
			}, $n.without = eo, $n.wrap = function(n, t) {
				return t = null == t ? Re : t, hr(t, E, null, [n], [])
			}, $n.xor = function() {
				for (var n = -1, t = arguments.length; ++n < t;) {
					var r = arguments[n];
					if (jr(r)) var e = e ? ft(e, r).concat(ft(r, e)) : r
				}
				return e ? Tt(e) : []
			}, $n.zip = uo, $n.zipObject = Zr, $n.zipWith = oo, $n.backflow = Ro, $n.collect =
			ne, $n.compose = Ro, $n.each = lo, $n.eachRight = so,
			$n.extend = $o, $n.iteratee = Ee, $n.methods = de, $n.object = Zr, $n.select =
			Hr, $n.tail = qr, $n.unique = Kr, We($n, $n), $n.add = function(n, t) {
				return (+n || 0) + (+t || 0)
			}, $n.attempt = ei, $n.camelCase = Xo, $n.capitalize = function(n) {
				return (n = u(n)) && n.charAt(0).toUpperCase() + n.slice(1)
			}, $n.clone = function(n, t, r, e) {
				return t && typeof t != "boolean" && Or(n, t, r) ? t = false : typeof t ==
					"function" && (e = r, r = t, t = false), r = typeof r == "function" &&
					zt(r, e, 1), ot(n, t, r)
			}, $n.cloneDeep = function(n, t, r) {
				return t = typeof t == "function" && zt(t, r, 1), ot(n, true, t)
			}, $n.deburr = be,
			$n.endsWith = function(n, t, r) {
				n = u(n), t += "";
				var e = n.length;
				return r = r === w ? e : xu(0 > r ? 0 : +r || 0, e), r -= t.length, 0 <=
					r && n.indexOf(t, r) == r
			}, $n.escape = function(n) {
				return (n = u(n)) && hn.test(n) ? n.replace(sn, l) : n
			}, $n.escapeRegExp = xe, $n.every = Xr, $n.find = ao, $n.findIndex = Xu,
			$n.findKey = zo, $n.findLast = co, $n.findLastIndex = Hu, $n.findLastKey =
			Bo, $n.findWhere = function(n, t) {
				return ao(n, wt(t))
			}, $n.first = Mr, $n.get = function(n, t, r) {
				return n = null == n ? w : gt(n, $r(t), t + ""), n === w ? r : n
			}, $n.has = function(n, t) {
				if (null == n) return false;
				var r = Ge.call(n, t);

				return r || Er(t) || (t = $r(t), n = 1 == t.length ? n : gt(n, It(t, 0, -
					1)), t = Pr(t), r = null != n && Ge.call(n, t)), r
			}, $n.identity = Re, $n.includes = Qr, $n.indexOf = Dr, $n.inRange =
			function(n, t, r) {
				return t = +t || 0, "undefined" === typeof r ? (r = t, t = 0) : r = +r ||
					0, n >= xu(t, r) && n < bu(t, r)
			}, $n.isArguments = ae, $n.isArray = To, $n.isBoolean = function(n) {
				return true === n || false === n || h(n) && Xe.call(n) == D
			}, $n.isDate = function(n) {
				return h(n) && Xe.call(n) == P
			}, $n.isElement = ce, $n.isEmpty = function(n) {
				return null == n ? true : jr(n) && (To(n) || ve(n) || ae(n) || h(n) && No(
					n.splice)) ? !n.length : !Ko(n).length;

			}, $n.isEqual = function(n, t, r, e) {
				return r = typeof r == "function" && zt(r, e, 3), !r && Cr(n) && Cr(t) ?
					n === t : (e = r ? r(n, t) : w, e === w ? yt(n, t, r) : !!e)
			}, $n.isError = le, $n.isFinite = Uo, $n.isFunction = No, $n.isMatch =
			function(n, t, r, e) {
				var u = Ko(t),
					o = u.length;
				if (!o) return true;
				if (null == n) return false;
				if (r = typeof r == "function" && zt(r, e, 3), n = Fr(n), !r && 1 == o) {
					var i = u[0];
					if (e = t[i], Cr(e)) return e === n[i] && (e !== w || i in n)
				}
				for (var i = Ue(o), f = Ue(o); o--;) e = i[o] = t[u[o]], f[o] = Cr(e);
				return dt(n, u, i, f, r)
			}, $n.isNaN = function(n) {
				return he(n) && n != +n
			}, $n.isNative = pe,
			$n.isNull = function(n) {
				return null === n
			}, $n.isNumber = he, $n.isObject = se, $n.isPlainObject = Fo, $n.isRegExp =
			_e, $n.isString = ve, $n.isTypedArray = ge, $n.isUndefined = function(n) {
				return n === w
			}, $n.kebabCase = Ho, $n.last = Pr, $n.lastIndexOf = function(n, t, r) {
				var e = n ? n.length : 0;
				if (!e) return -1;
				var u = e;
				if (typeof r == "number") u = (0 > r ? bu(e + r, 0) : xu(r || 0, e - 1)) +
					1;
				else if (r) return u = $t(n, t, true) - 1, n = n[u], (t === t ? t === n :
					n !== n) ? u : -1;
				if (t !== t) return p(n, u, true);
				for (; u--;)
					if (n[u] === t) return u;
				return -1
			}, $n.max = ii, $n.min = fi, $n.noConflict = function() {
				return _._ = He, this
			}, $n.noop = Se, $n.now = wo, $n.pad = function(n, t, r) {
				n = u(n), t = +t;
				var e = n.length;
				return e < t && mu(t) ? (e = (t - e) / 2, t = uu(e), e = ru(e), r = lr("",
					e, r), r.slice(0, t) + n + r) : n
			}, $n.padLeft = Qo, $n.padRight = ni, $n.parseInt = Ae, $n.random =
			function(n, t, r) {
				r && Or(n, t, r) && (t = r = null);
				var e = null == n,
					u = null == t;
				return null == r && (u && typeof n == "boolean" ? (r = n, n = 1) : typeof t ==
						"boolean" && (r = t, u = true)), e && u && (t = 1, u = false), n = +n ||
					0, u ? (t = n, n = 0) : t = +t || 0, r || n % 1 || t % 1 ? (r = Ou(), xu(
						n + r * (t - n + parseFloat("1e-" + ((r + "").length - 1))), t)) : Ot(n,
						t)
			}, $n.reduce = go,
			$n.reduceRight = yo, $n.repeat = je, $n.result = function(n, t, r) {
				var e = null == n ? w : n[t];
				return e === w && (null == n || Er(t, n) || (t = $r(t), n = 1 == t.length ?
						n : gt(n, It(t, 0, -1)), e = null == n ? w : n[Pr(t)]), e = e === w ?
					r : e), No(e) ? e.call(n) : e
			}, $n.runInContext = m, $n.size = function(n) {
				var t = n ? Yu(n) : 0;
				return Rr(t) ? t : Ko(n).length
			}, $n.snakeCase = ti, $n.some = ee, $n.sortedIndex = no, $n.sortedLastIndex =
			to, $n.startCase = ri, $n.startsWith = function(n, t, r) {
				return n = u(n), r = null == r ? 0 : xu(0 > r ? 0 : +r || 0, n.length), n
					.lastIndexOf(t, r) == r
			}, $n.sum = function(n, t, r) {
				r && Or(n, t, r) && (t = null);

				var e = dr(),
					u = null == t;
				if (e === ut && u || (u = false, t = e(t, r, 3)), u) {
					for (n = To(n) ? n : Nr(n), t = n.length, r = 0; t--;) r += +n[t] || 0;
					n = r
				} else n = St(n, t);
				return n
			}, $n.template = function(n, t, r) {
				var e = $n.templateSettings;
				r && Or(n, t, r) && (t = r = null), n = u(n), t = tt($u({}, r || t), e,
					nt), r = tt($u({}, t.imports), e.imports, nt);
				var o, i, f = Ko(r),
					a = Ut(r, f),
					c = 0;
				r = t.interpolate || Rn;
				var l = "__p+='";
				r = Me((t.escape || Rn).source + "|" + r.source + "|" + (r === gn ? jn :
					Rn).source + "|" + (t.evaluate || Rn).source + "|$", "g");
				var p = "sourceURL" in t ? "//# sourceURL=" + t.sourceURL + "\n" : "";

				if (n.replace(r, function(t, r, e, u, f, a) {
						return e || (e = u), l += n.slice(c, a).replace(Cn, s), r && (o = true,
								l += "'+__e(" + r + ")+'"), f && (i = true, l += "';" + f +
								";\n__p+='"), e && (l += "'+((__t=(" + e + "))==null?'':__t)+'"), c =
							a + t.length, t
					}), l += "';", (t = t.variable) || (l = "with(obj){" + l + "}"), l = (i ?
						l.replace(fn, "") : l).replace(an, "$1").replace(cn, "$1;"), l =
					"function(" + (t || "obj") + "){" + (t ? "" : "obj||(obj={});") +
					"var __t,__p=''" + (o ? ",__e=_.escape" : "") + (i ?
						",__j=Array.prototype.join;function print(){__p+=__j.call(arguments,'')}" :
						";") + l + "return __p}",
					t = ei(function() {
						return $e(f, p + "return " + l).apply(w, a)
					}), t.source = l, le(t)) throw t;
				return t
			}, $n.trim = ke, $n.trimLeft = function(n, t, r) {
				var e = n;
				return (n = u(n)) ? n.slice((r ? Or(e, t, r) : null == t) ? g(n) : i(n, t +
					"")) : n
			}, $n.trimRight = function(n, t, r) {
				var e = n;
				return (n = u(n)) ? (r ? Or(e, t, r) : null == t) ? n.slice(0, y(n) + 1) :
					n.slice(0, f(n, t + "") + 1) : n
			}, $n.trunc = function(n, t, r) {
				r && Or(n, t, r) && (t = null);
				var e = W;
				if (r = S, null != t)
					if (se(t)) {
						var o = "separator" in t ? t.separator : o,
							e = "length" in t ? +t.length || 0 : e;
						r = "omission" in t ? u(t.omission) : r
					} else e = +t || 0;

				if (n = u(n), e >= n.length) return n;
				if (e -= r.length, 1 > e) return r;
				if (t = n.slice(0, e), null == o) return t + r;
				if (_e(o)) {
					if (n.slice(e).search(o)) {
						var i, f = n.slice(0, e);
						for (o.global || (o = Me(o.source, (kn.exec(o) || "") + "g")), o.lastIndex =
							0; n = o.exec(f);) i = n.index;
						t = t.slice(0, null == i ? e : i)
					}
				} else n.indexOf(o, e) != e && (o = t.lastIndexOf(o), -1 < o && (t = t.slice(
					0, o)));
				return t + r
			}, $n.unescape = function(n) {
				return (n = u(n)) && pn.test(n) ? n.replace(ln, d) : n
			}, $n.uniqueId = function(n) {
				var t = ++Je;
				return u(n) + t
			}, $n.words = Oe, $n.all = Xr, $n.any = ee, $n.contains = Qr,
			$n.detect = ao, $n.foldl = go, $n.foldr = yo, $n.head = Mr, $n.include =
			Qr, $n.inject = go, We($n, function() {
				var n = {};
				return ht($n, function(t, r) {
					$n.prototype[r] || (n[r] = t)
				}), n
			}(), false), $n.sample = te, $n.prototype.sample = function(n) {
				return this.__chain__ || null != n ? this.thru(function(t) {
					return te(t, n)
				}) : te(this.value())
			}, $n.VERSION = b, Kn("bind bindKey curry curryRight partial partialRight"
				.split(" "),
				function(n) {
					$n[n].placeholder = $n
				}), Kn(["dropWhile", "filter", "map", "takeWhile"], function(n, t) {
				var r = t != $,
					e = t == N;
				Bn.prototype[n] = function(n, u) {
					var o = this.__filtered__,
						i = o && e ? new Bn(this) : this.clone();
					return (i.__iteratees__ || (i.__iteratees__ = [])).push({
						done: false,
						count: 0,
						index: 0,
						iteratee: dr(n, u, 1),
						limit: -1,
						type: t
					}), i.__filtered__ = o || r, i
				}
			}), Kn(["drop", "take"], function(n, t) {
				var r = n + "While";
				Bn.prototype[n] = function(r) {
					var e = this.__filtered__,
						u = e && !t ? this.dropWhile() : this.clone();
					return r = null == r ? 1 : bu(uu(r) || 0, 0), e ? t ? u.__takeCount__ =
						xu(u.__takeCount__, r) : Pr(u.__iteratees__).limit = r : (u.__views__ ||
							(u.__views__ = [])).push({
							size: r,
							type: n + (0 > u.__dir__ ? "Right" : "")
						}), u
				}, Bn.prototype[n + "Right"] = function(t) {
					return this.reverse()[n](t).reverse()
				}, Bn.prototype[n + "RightWhile"] = function(n, t) {
					return this.reverse()[r](n, t).reverse()
				}
			}), Kn(["first", "last"], function(n, t) {
				var r = "take" + (t ? "Right" : "");
				Bn.prototype[n] = function() {
					return this[r](1).value()[0]
				}
			}), Kn(["initial", "rest"], function(n, t) {
				var r = "drop" + (t ? "" : "Right");
				Bn.prototype[n] = function() {
					return this[r](1)
				}
			}), Kn(["pluck", "where"], function(n, t) {
				var r = t ? "filter" : "map",
					e = t ? wt : Te;
				Bn.prototype[n] = function(n) {
					return this[r](e(n));

				}
			}), Bn.prototype.compact = function() {
				return this.filter(Re)
			}, Bn.prototype.reject = function(n, t) {
				return n = dr(n, t, 1), this.filter(function(t) {
					return !n(t)
				})
			}, Bn.prototype.slice = function(n, t) {
				n = null == n ? 0 : +n || 0;
				var r = this;
				return 0 > n ? r = this.takeRight(-n) : n && (r = this.drop(n)), t !== w &&
					(t = +t || 0, r = 0 > t ? r.dropRight(-t) : r.take(t - n)), r
			}, Bn.prototype.toArray = function() {
				return this.drop(0)
			}, ht(Bn.prototype, function(n, t) {
				var r = $n[t];
				if (r) {
					var e = /^(?:filter|map|reject)|While$/.test(t),
						u = /^(?:first|last)$/.test(t);
					$n.prototype[t] = function() {
						function t(n) {
							return n = [n], fu.apply(n, o), r.apply($n, n)
						}
						var o = arguments,
							i = this.__chain__,
							f = this.__wrapped__,
							a = !!this.__actions__.length,
							c = f instanceof Bn,
							l = o[0],
							s = c || To(f);
						return s && e && typeof l == "function" && 1 != l.length && (c = s =
								false), c = c && !a, u && !i ? c ? n.call(f) : r.call($n, this.value()) :
							s ? (f = n.apply(c ? f : new Bn(this), o), u || !a && !f.__actions__ ||
								(f.__actions__ || (f.__actions__ = [])).push({
									func: Jr,
									args: [t],
									thisArg: $n
								}), new zn(f, i)) : this.thru(t)
					}
				}
			}), Kn("concat join pop push replace shift sort splice split unshift".split(
				" "), function(n) {
				var t = (/^(?:replace|split)$/.test(n) ? Ve : qe)[n],
					r = /^(?:push|sort|unshift)$/.test(n) ? "tap" : "thru",
					e = /^(?:join|pop|replace|shift)$/.test(n);
				$n.prototype[n] = function() {
					var n = arguments;
					return e && !this.__chain__ ? t.apply(this.value(), n) : this[r](
						function(r) {
							return t.apply(r, n)
						})
				}
			}), ht(Bn.prototype, function(n, t) {
				var r = $n[t];
				if (r) {
					var e = r.name;
					(Nu[e] || (Nu[e] = [])).push({
						name: t,
						func: r
					})
				}
			}), Nu[cr(null, A).name] = [{
				name: "wrapper",
				func: null
			}], Bn.prototype.clone = function() {
				var n = this.__actions__,
					t = this.__iteratees__,
					r = this.__views__,
					e = new Bn(this.__wrapped__);

				return e.__actions__ = n ? qn(n) : null, e.__dir__ = this.__dir__, e.__filtered__ =
					this.__filtered__, e.__iteratees__ = t ? qn(t) : null, e.__takeCount__ =
					this.__takeCount__, e.__views__ = r ? qn(r) : null, e
			}, Bn.prototype.reverse = function() {
				if (this.__filtered__) {
					var n = new Bn(this);
					n.__dir__ = -1, n.__filtered__ = true
				} else n = this.clone(), n.__dir__ *= -1;
				return n
			}, Bn.prototype.value = function() {
				var n = this.__wrapped__.value();
				if (!To(n)) return Ft(n, this.__actions__);
				var t, r = this.__dir__,
					e = 0 > r;
				t = n.length;
				for (var u = this.__views__, o = 0, i = -1, f = u ? u.length : 0; ++i < f;) {
					var a = u[i],
						c = a.size;
					switch (a.type) {
						case "drop":
							o += c;
							break;
						case "dropRight":
							t -= c;
							break;
						case "take":
							t = xu(t, o + c);
							break;
						case "takeRight":
							o = bu(o, t - c)
					}
				}
				t = {
						start: o,
						end: t
					}, u = t.start, o = t.end, t = o - u, u = e ? o : u - 1, o = xu(t, this.__takeCount__),
					f = (i = this.__iteratees__) ? i.length : 0, a = 0, c = [];
				n: for (; t-- && a < o;) {
					for (var u = u + r, l = -1, s = n[u]; ++l < f;) {
						var p = i[l],
							h = p.iteratee,
							_ = p.type;
						if (_ == N) {
							if (p.done && (e ? u > p.index : u < p.index) && (p.count = 0, p.done =
									false), p.index = u, !(p.done || (_ = p.limit, p.done = -1 < _ ? p.count++
									>= _ : !h(s)))) continue n
						} else if (p = h(s),
							_ == $) s = p;
						else if (!p) {
							if (_ == F) continue n;
							break n
						}
					}
					c[a++] = s
				}
				return c
			}, $n.prototype.chain = function() {
				return Gr(this)
			}, $n.prototype.commit = function() {
				return new zn(this.value(), this.__chain__)
			}, $n.prototype.plant = function(n) {
				for (var t, r = this; r instanceof Ln;) {
					var e = Lr(r);
					t ? u.__wrapped__ = e : t = e;
					var u = e,
						r = r.__wrapped__
				}
				return u.__wrapped__ = n, t
			}, $n.prototype.reverse = function() {
				var n = this.__wrapped__;
				return n instanceof Bn ? (this.__actions__.length && (n = new Bn(this)),
					new zn(n.reverse(), this.__chain__)) : this.thru(function(n) {
					return n.reverse()
				})
			}, $n.prototype.toString = function() {
				return this.value() + ""
			}, $n.prototype.run = $n.prototype.toJSON = $n.prototype.valueOf = $n.prototype
			.value = function() {
				return Ft(this.__wrapped__, this.__actions__)
			}, $n.prototype.collect = $n.prototype.map, $n.prototype.head = $n.prototype
			.first, $n.prototype.select = $n.prototype.filter, $n.prototype.tail = $n.prototype
			.rest, $n
	}
	var w, b = "3.8.0",
		x = 1,
		A = 2,
		j = 4,
		k = 8,
		O = 16,
		E = 32,
		I = 64,
		R = 128,
		C = 256,
		W = 30,
		S = "...",
		T = 150,
		U = 16,
		N = 0,
		F = 1,
		$ = 2,
		L = "Expected a function",
		z = "__lodash_placeholder__",
		B = "[object Arguments]",
		M = "[object Array]",
		D = "[object Boolean]",
		P = "[object Date]",
		q = "[object Error]",
		K = "[object Function]",
		V = "[object Number]",
		Y = "[object Object]",
		Z = "[object RegExp]",
		G = "[object String]",
		J = "[object ArrayBuffer]",
		X = "[object Float32Array]",
		H = "[object Float64Array]",
		Q = "[object Int8Array]",
		nn = "[object Int16Array]",
		tn = "[object Int32Array]",
		rn = "[object Uint8Array]",
		en = "[object Uint8ClampedArray]",
		un = "[object Uint16Array]",
		on = "[object Uint32Array]",
		fn = /\b__p\+='';/g,
		an = /\b(__p\+=)''\+/g,
		cn = /(__e\(.*?\)|\b__t\))\+'';/g,
		ln = /&(?:amp|lt|gt|quot|#39|#96);/g,
		sn = /[&<>"'`]/g,
		pn = RegExp(ln.source),
		hn = RegExp(sn.source),
		_n = /<%-([\s\S]+?)%>/g,
		vn = /<%([\s\S]+?)%>/g,
		gn = /<%=([\s\S]+?)%>/g,
		yn = /\.|\[(?:[^[\]]*|(["'])(?:(?!\1)[^\n\\]|\\.)*?\1)\]/,
		dn = /^\w*$/,
		mn = /[^.[\]]+|\[(?:(-?\d+(?:\.\d+)?)|(["'])((?:(?!\2)[^\n\\]|\\.)*?)\2)\]/g,
		wn = /[.*+?^${}()|[\]\/\\]/g,
		bn = RegExp(wn.source),
		xn = /[\u0300-\u036f\ufe20-\ufe23]/g,
		An = /\\(\\)?/g,
		jn = /\$\{([^\\}]*(?:\\.[^\\}]*)*)\}/g,
		kn = /\w*$/,
		On = /^0[xX]/,
		En = /^\[object .+?Constructor\]$/,
		In = /[\xc0-\xd6\xd8-\xde\xdf-\xf6\xf8-\xff]/g,
		Rn = /($^)/,
		Cn = /['\n\r\u2028\u2029\\]/g,
		Wn = RegExp(
			"[A-Z\\xc0-\\xd6\\xd8-\\xde]+(?=[A-Z\\xc0-\\xd6\\xd8-\\xde][a-z\\xdf-\\xf6\\xf8-\\xff]+)|[A-Z\\xc0-\\xd6\\xd8-\\xde]?[a-z\\xdf-\\xf6\\xf8-\\xff]+|[A-Z\\xc0-\\xd6\\xd8-\\xde]+|[0-9]+",
			"g"),
		Sn =
		" \t\x0b\f\xa0\ufeff\n\r\u2028\u2029\u1680\u180e\u2000\u2001\u2002\u2003\u2004\u2005\u2006\u2007\u2008\u2009\u200a\u202f\u205f\u3000",
		Tn =
		"Array ArrayBuffer Date Error Float32Array Float64Array Function Int8Array Int16Array Int32Array Math Number Object RegExp Set String _ clearTimeout document isFinite parseInt setTimeout TypeError Uint8Array Uint8ClampedArray Uint16Array Uint32Array WeakMap window"
		.split(" "),
		Un = {};

	Un[X] = Un[H] = Un[Q] = Un[nn] = Un[tn] = Un[rn] = Un[en] = Un[un] = Un[on] =
		true, Un[B] = Un[M] = Un[J] = Un[D] = Un[P] = Un[q] = Un[K] = Un[
			"[object Map]"] = Un[V] = Un[Y] = Un[Z] = Un["[object Set]"] = Un[G] = Un[
			"[object WeakMap]"] = false;
	var Nn = {};
	Nn[B] = Nn[M] = Nn[J] = Nn[D] = Nn[P] = Nn[X] = Nn[H] = Nn[Q] = Nn[nn] = Nn[
			tn] = Nn[V] = Nn[Y] = Nn[Z] = Nn[G] = Nn[rn] = Nn[en] = Nn[un] = Nn[on] =
		true, Nn[q] = Nn[K] = Nn["[object Map]"] = Nn["[object Set]"] = Nn[
			"[object WeakMap]"] = false;
	var Fn = {
			leading: false,
			maxWait: 0,
			trailing: false
		},
		$n = {
			"\xc0": "A",
			"\xc1": "A",
			"\xc2": "A",
			"\xc3": "A",
			"\xc4": "A",
			"\xc5": "A",
			"\xe0": "a",
			"\xe1": "a",
			"\xe2": "a",
			"\xe3": "a",
			"\xe4": "a",
			"\xe5": "a",
			"\xc7": "C",
			"\xe7": "c",
			"\xd0": "D",
			"\xf0": "d",
			"\xc8": "E",
			"\xc9": "E",
			"\xca": "E",
			"\xcb": "E",
			"\xe8": "e",
			"\xe9": "e",
			"\xea": "e",
			"\xeb": "e",
			"\xcc": "I",
			"\xcd": "I",
			"\xce": "I",
			"\xcf": "I",
			"\xec": "i",
			"\xed": "i",
			"\xee": "i",
			"\xef": "i",
			"\xd1": "N",
			"\xf1": "n",
			"\xd2": "O",
			"\xd3": "O",
			"\xd4": "O",
			"\xd5": "O",
			"\xd6": "O",
			"\xd8": "O",
			"\xf2": "o",
			"\xf3": "o",
			"\xf4": "o",
			"\xf5": "o",
			"\xf6": "o",
			"\xf8": "o",
			"\xd9": "U",
			"\xda": "U",
			"\xdb": "U",
			"\xdc": "U",
			"\xf9": "u",
			"\xfa": "u",
			"\xfb": "u",
			"\xfc": "u",
			"\xdd": "Y",
			"\xfd": "y",
			"\xff": "y",
			"\xc6": "Ae",
			"\xe6": "ae",
			"\xde": "Th",
			"\xfe": "th",
			"\xdf": "ss"
		},
		Ln = {
			"&": "&amp;",
			"<": "&lt;",
			">": "&gt;",
			'"': "&quot;",
			"'": "&#39;",
			"`": "&#96;"
		},
		zn = {
			"&amp;": "&",
			"&lt;": "<",
			"&gt;": ">",
			"&quot;": '"',
			"&#39;": "'",
			"&#96;": "`"
		},
		Bn = {
			"function": true,
			object: true
		},
		Mn = {
			"\\": "\\",
			"'": "'",
			"\n": "n",
			"\r": "r",
			"\u2028": "u2028",
			"\u2029": "u2029"
		},
		Dn = Bn[typeof exports] && exports && !exports.nodeType && exports,
		Pn = Bn[typeof module] && module && !module.nodeType && module,
		qn = Bn[typeof self] && self && self.Object && self,
		Kn = Bn[typeof window] && window && window.Object && window,
		Vn = Pn && Pn.exports === Dn && Dn,
		Yn = Dn && Pn && typeof global == "object" && global && global.Object &&
		global || Kn !== (this && this.window) && Kn || qn || this,
		Zn = m();

	typeof define == "function" && typeof define.amd == "object" && define.amd ?
		(Yn._ = Zn, define(function() {
			return Zn
		})) : Dn && Pn ? Vn ? (Pn.exports = Zn)._ = Zn : Dn._ = Zn : Yn._ = Zn
}).call(this);

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

/*
 *  jQuery OwlCarousel v1.3.3
 *
 *  Copyright (c) 2013 Bartosz Wojciechowski
 *  http://www.owlgraphic.com/owlcarousel/
 *
 *  Licensed under MIT
 *
 */

/*JS Lint helpers: */
/*global dragMove: false, dragEnd: false, $, jQuery, alert, window, document */
/*jslint nomen: true, continue:true */

if (typeof Object.create !== "function") {
    Object.create = function (obj) {
        function F() {}
        F.prototype = obj;
        return new F();
    };
}
(function ($, window, document) {

    var Carousel = {
        init : function (options, el) {
            var base = this;

            base.$elem = $(el);
            base.options = $.extend({}, $.fn.owlCarousel.options, base.$elem.data(), options);

            base.userOptions = options;
            base.loadContent();
        },

        loadContent : function () {
            var base = this, url;

            function getData(data) {
                var i, content = "";
                if (typeof base.options.jsonSuccess === "function") {
                    base.options.jsonSuccess.apply(this, [data]);
                } else {
                    for (i in data.owl) {
                        if (data.owl.hasOwnProperty(i)) {
                            content += data.owl[i].item;
                        }
                    }
                    base.$elem.html(content);
                }
                base.logIn();
            }

            if (typeof base.options.beforeInit === "function") {
                base.options.beforeInit.apply(this, [base.$elem]);
            }

            if (typeof base.options.jsonPath === "string") {
                url = base.options.jsonPath;
                $.getJSON(url, getData);
            } else {
                base.logIn();
            }
        },

        logIn : function () {
            var base = this;

            base.$elem.data("owl-originalStyles", base.$elem.attr("style"));
            base.$elem.data("owl-originalClasses", base.$elem.attr("class"));

            base.$elem.css({opacity: 0});
            base.orignalItems = base.options.items;
            base.checkBrowser();
            base.wrapperWidth = 0;
            base.checkVisible = null;
            base.setVars();
        },

        setVars : function () {
            var base = this;
            if (base.$elem.children().length === 0) {return false; }
            base.baseClass();
            base.eventTypes();
            base.$userItems = base.$elem.children();
            base.itemsAmount = base.$userItems.length;
            base.wrapItems();
            base.$owlItems = base.$elem.find(".owl-item");
            base.$owlWrapper = base.$elem.find(".owl-wrapper");
            base.playDirection = "next";
            base.prevItem = 0;
            base.prevArr = [0];
            base.currentItem = 0;
            base.customEvents();
            base.onStartup();
        },

        onStartup : function () {
            var base = this;
            base.updateItems();
            base.calculateAll();
            base.buildControls();
            base.updateControls();
            base.response();
            base.moveEvents();
            base.stopOnHover();
            base.owlStatus();

            if (base.options.transitionStyle !== false) {
                base.transitionTypes(base.options.transitionStyle);
            }
            if (base.options.autoPlay === true) {
                base.options.autoPlay = 5000;
            }
            base.play();

            base.$elem.find(".owl-wrapper").css("display", "block");

            if (!base.$elem.is(":visible")) {
                base.watchVisibility();
            } else {
                base.$elem.css("opacity", 1);
            }
            base.onstartup = false;
            base.eachMoveUpdate();
            if (typeof base.options.afterInit === "function") {
                base.options.afterInit.apply(this, [base.$elem]);
            }
        },

        eachMoveUpdate : function () {
            var base = this;

            if (base.options.lazyLoad === true) {
                base.lazyLoad();
            }
            if (base.options.autoHeight === true) {
                base.autoHeight();
            }
            base.onVisibleItems();

            if (typeof base.options.afterAction === "function") {
                base.options.afterAction.apply(this, [base.$elem]);
            }
        },

        updateVars : function () {
            var base = this;
            if (typeof base.options.beforeUpdate === "function") {
                base.options.beforeUpdate.apply(this, [base.$elem]);
            }
            base.watchVisibility();
            base.updateItems();
            base.calculateAll();
            base.updatePosition();
            base.updateControls();
            base.eachMoveUpdate();
            if (typeof base.options.afterUpdate === "function") {
                base.options.afterUpdate.apply(this, [base.$elem]);
            }
        },

        reload : function () {
            var base = this;
            window.setTimeout(function () {
                base.updateVars();
            }, 0);
        },

        watchVisibility : function () {
            var base = this;

            if (base.$elem.is(":visible") === false) {
                base.$elem.css({opacity: 0});
                window.clearInterval(base.autoPlayInterval);
                window.clearInterval(base.checkVisible);
            } else {
                return false;
            }
            base.checkVisible = window.setInterval(function () {
                if (base.$elem.is(":visible")) {
                    base.reload();
                    base.$elem.animate({opacity: 1}, 200);
                    window.clearInterval(base.checkVisible);
                }
            }, 500);
        },

        wrapItems : function () {
            var base = this;
            base.$userItems.wrapAll("<div class=\"owl-wrapper\">").wrap("<div class=\"owl-item\"></div>");
            base.$elem.find(".owl-wrapper").wrap("<div class=\"owl-wrapper-outer\">");
            base.wrapperOuter = base.$elem.find(".owl-wrapper-outer");
            base.$elem.css("display", "block");
        },

        baseClass : function () {
            var base = this,
                hasBaseClass = base.$elem.hasClass(base.options.baseClass),
                hasThemeClass = base.$elem.hasClass(base.options.theme);

            if (!hasBaseClass) {
                base.$elem.addClass(base.options.baseClass);
            }

            if (!hasThemeClass) {
                base.$elem.addClass(base.options.theme);
            }
        },

        updateItems : function () {
            var base = this, width, i;

            if (base.options.responsive === false) {
                return false;
            }
            if (base.options.singleItem === true) {
                base.options.items = base.orignalItems = 1;
                base.options.itemsCustom = false;
                base.options.itemsDesktop = false;
                base.options.itemsDesktopSmall = false;
                base.options.itemsTablet = false;
                base.options.itemsTabletSmall = false;
                base.options.itemsMobile = false;
                return false;
            }

            width = $(base.options.responsiveBaseWidth).width();

            if (width > (base.options.itemsDesktop[0] || base.orignalItems)) {
                base.options.items = base.orignalItems;
            }
            if (base.options.itemsCustom !== false) {
                //Reorder array by screen size
                base.options.itemsCustom.sort(function (a, b) {return a[0] - b[0]; });

                for (i = 0; i < base.options.itemsCustom.length; i += 1) {
                    if (base.options.itemsCustom[i][0] <= width) {
                        base.options.items = base.options.itemsCustom[i][1];
                    }
                }

            } else {

                if (width <= base.options.itemsDesktop[0] && base.options.itemsDesktop !== false) {
                    base.options.items = base.options.itemsDesktop[1];
                }

                if (width <= base.options.itemsDesktopSmall[0] && base.options.itemsDesktopSmall !== false) {
                    base.options.items = base.options.itemsDesktopSmall[1];
                }

                if (width <= base.options.itemsTablet[0] && base.options.itemsTablet !== false) {
                    base.options.items = base.options.itemsTablet[1];
                }

                if (width <= base.options.itemsTabletSmall[0] && base.options.itemsTabletSmall !== false) {
                    base.options.items = base.options.itemsTabletSmall[1];
                }

                if (width <= base.options.itemsMobile[0] && base.options.itemsMobile !== false) {
                    base.options.items = base.options.itemsMobile[1];
                }
            }

            //if number of items is less than declared
            if (base.options.items > base.itemsAmount && base.options.itemsScaleUp === true) {
                base.options.items = base.itemsAmount;
            }
        },

        response : function () {
            var base = this,
                smallDelay,
                lastWindowWidth;

            if (base.options.responsive !== true) {
                return false;
            }
            lastWindowWidth = $(window).width();

            base.resizer = function () {
                if ($(window).width() !== lastWindowWidth) {
                    if (base.options.autoPlay !== false) {
                        window.clearInterval(base.autoPlayInterval);
                    }
                    window.clearTimeout(smallDelay);
                    smallDelay = window.setTimeout(function () {
                        lastWindowWidth = $(window).width();
                        base.updateVars();
                    }, base.options.responsiveRefreshRate);
                }
            };
            $(window).resize(base.resizer);
        },

        updatePosition : function () {
            var base = this;
            base.jumpTo(base.currentItem);
            if (base.options.autoPlay !== false) {
                base.checkAp();
            }
        },

        appendItemsSizes : function () {
            var base = this,
                roundPages = 0,
                lastItem = base.itemsAmount - base.options.items;

            base.$owlItems.each(function (index) {
                var $this = $(this);
                $this
                    .css({"width": base.itemWidth})
                    .data("owl-item", Number(index));

                if (index % base.options.items === 0 || index === lastItem) {
                    if (!(index > lastItem)) {
                        roundPages += 1;
                    }
                }
                $this.data("owl-roundPages", roundPages);
            });
        },

        appendWrapperSizes : function () {
            var base = this,
                width = base.$owlItems.length * base.itemWidth;

            base.$owlWrapper.css({
                "width": width * 2,
                "left": 0
            });
            base.appendItemsSizes();
        },

        calculateAll : function () {
            var base = this;
            base.calculateWidth();
            base.appendWrapperSizes();
            base.loops();
            base.max();
        },

        calculateWidth : function () {
            var base = this;
            base.itemWidth = Math.round(base.$elem.width() / base.options.items);
        },

        max : function () {
            var base = this,
                maximum = ((base.itemsAmount * base.itemWidth) - base.options.items * base.itemWidth) * -1;
            if (base.options.items > base.itemsAmount) {
                base.maximumItem = 0;
                maximum = 0;
                base.maximumPixels = 0;
            } else {
                base.maximumItem = base.itemsAmount - base.options.items;
                base.maximumPixels = maximum;
            }
            return maximum;
        },

        min : function () {
            return 0;
        },

        loops : function () {
            var base = this,
                prev = 0,
                elWidth = 0,
                i,
                item,
                roundPageNum;

            base.positionsInArray = [0];
            base.pagesInArray = [];

            for (i = 0; i < base.itemsAmount; i += 1) {
                elWidth += base.itemWidth;
                base.positionsInArray.push(-elWidth);

                if (base.options.scrollPerPage === true) {
                    item = $(base.$owlItems[i]);
                    roundPageNum = item.data("owl-roundPages");
                    if (roundPageNum !== prev) {
                        base.pagesInArray[prev] = base.positionsInArray[i];
                        prev = roundPageNum;
                    }
                }
            }
        },

        buildControls : function () {
            var base = this;
            if (base.options.navigation === true || base.options.pagination === true) {
                base.owlControls = $("<div class=\"owl-controls\"/>").toggleClass("clickable", !base.browser.isTouch).appendTo(base.$elem);
            }
            if (base.options.pagination === true) {
                base.buildPagination();
            }
            if (base.options.navigation === true) {
                base.buildButtons();
            }
        },

        buildButtons : function () {
            var base = this,
                buttonsWrapper = $("<div class=\"owl-buttons\"/>");
            base.owlControls.append(buttonsWrapper);

            base.buttonPrev = $("<div/>", {
                "class" : "owl-prev",
                "html" : base.options.navigationText[0] || ""
            });

            base.buttonNext = $("<div/>", {
                "class" : "owl-next",
                "html" : base.options.navigationText[1] || ""
            });

            buttonsWrapper
                .append(base.buttonPrev)
                .append(base.buttonNext);

            buttonsWrapper.on("touchstart.owlControls mousedown.owlControls", "div[class^=\"owl\"]", function (event) {
                event.preventDefault();
            });

            buttonsWrapper.on("touchend.owlControls mouseup.owlControls", "div[class^=\"owl\"]", function (event) {
                event.preventDefault();
                if ($(this).hasClass("owl-next")) {
                    base.next();
                } else {
                    base.prev();
                }
            });
        },

        buildPagination : function () {
            var base = this;

            base.paginationWrapper = $("<div class=\"owl-pagination\"/>");
            base.owlControls.append(base.paginationWrapper);

            base.paginationWrapper.on("touchend.owlControls mouseup.owlControls", ".owl-page", function (event) {
                event.preventDefault();
                if (Number($(this).data("owl-page")) !== base.currentItem) {
                    base.goTo(Number($(this).data("owl-page")), true);
                }
            });
        },

        updatePagination : function () {
            var base = this,
                counter,
                lastPage,
                lastItem,
                i,
                paginationButton,
                paginationButtonInner;

            if (base.options.pagination === false) {
                return false;
            }

            base.paginationWrapper.html("");

            counter = 0;
            lastPage = base.itemsAmount - base.itemsAmount % base.options.items;

            for (i = 0; i < base.itemsAmount; i += 1) {
                if (i % base.options.items === 0) {
                    counter += 1;
                    if (lastPage === i) {
                        lastItem = base.itemsAmount - base.options.items;
                    }
                    paginationButton = $("<div/>", {
                        "class" : "owl-page"
                    });
                    paginationButtonInner = $("<span></span>", {
                        "text": base.options.paginationNumbers === true ? counter : "",
                        "class": base.options.paginationNumbers === true ? "owl-numbers" : ""
                    });
                    paginationButton.append(paginationButtonInner);

                    paginationButton.data("owl-page", lastPage === i ? lastItem : i);
                    paginationButton.data("owl-roundPages", counter);

                    base.paginationWrapper.append(paginationButton);
                }
            }
            base.checkPagination();
        },
        checkPagination : function () {
            var base = this;
            if (base.options.pagination === false) {
                return false;
            }
            base.paginationWrapper.find(".owl-page").each(function () {
                if ($(this).data("owl-roundPages") === $(base.$owlItems[base.currentItem]).data("owl-roundPages")) {
                    base.paginationWrapper
                        .find(".owl-page")
                        .removeClass("active");
                    $(this).addClass("active");
                }
            });
        },

        checkNavigation : function () {
            var base = this;

            if (base.options.navigation === false) {
                return false;
            }
            if (base.options.rewindNav === false) {
                if (base.currentItem === 0 && base.maximumItem === 0) {
                    base.buttonPrev.addClass("disabled");
                    base.buttonNext.addClass("disabled");
                } else if (base.currentItem === 0 && base.maximumItem !== 0) {
                    base.buttonPrev.addClass("disabled");
                    base.buttonNext.removeClass("disabled");
                } else if (base.currentItem === base.maximumItem) {
                    base.buttonPrev.removeClass("disabled");
                    base.buttonNext.addClass("disabled");
                } else if (base.currentItem !== 0 && base.currentItem !== base.maximumItem) {
                    base.buttonPrev.removeClass("disabled");
                    base.buttonNext.removeClass("disabled");
                }
            }
        },

        updateControls : function () {
            var base = this;
            base.updatePagination();
            base.checkNavigation();
            if (base.owlControls) {
                if (base.options.items >= base.itemsAmount) {
                    base.owlControls.hide();
                } else {
                    base.owlControls.show();
                }
            }
        },

        destroyControls : function () {
            var base = this;
            if (base.owlControls) {
                base.owlControls.remove();
            }
        },

        next : function (speed) {
            var base = this;

            if (base.isTransition) {
                return false;
            }

            base.currentItem += base.options.scrollPerPage === true ? base.options.items : 1;
            if (base.currentItem > base.maximumItem + (base.options.scrollPerPage === true ? (base.options.items - 1) : 0)) {
                if (base.options.rewindNav === true) {
                    base.currentItem = 0;
                    speed = "rewind";
                } else {
                    base.currentItem = base.maximumItem;
                    return false;
                }
            }
            base.goTo(base.currentItem, speed);
        },

        prev : function (speed) {
            var base = this;

            if (base.isTransition) {
                return false;
            }

            if (base.options.scrollPerPage === true && base.currentItem > 0 && base.currentItem < base.options.items) {
                base.currentItem = 0;
            } else {
                base.currentItem -= base.options.scrollPerPage === true ? base.options.items : 1;
            }
            if (base.currentItem < 0) {
                if (base.options.rewindNav === true) {
                    base.currentItem = base.maximumItem;
                    speed = "rewind";
                } else {
                    base.currentItem = 0;
                    return false;
                }
            }
            base.goTo(base.currentItem, speed);
        },

        goTo : function (position, speed, drag) {
            var base = this,
                goToPixel;

            if (base.isTransition) {
                return false;
            }
            if (typeof base.options.beforeMove === "function") {
                base.options.beforeMove.apply(this, [base.$elem]);
            }
            if (position >= base.maximumItem) {
                position = base.maximumItem;
            } else if (position <= 0) {
                position = 0;
            }

            base.currentItem = base.owl.currentItem = position;
            if (base.options.transitionStyle !== false && drag !== "drag" && base.options.items === 1 && base.browser.support3d === true) {
                base.swapSpeed(0);
                if (base.browser.support3d === true) {
                    base.transition3d(base.positionsInArray[position]);
                } else {
                    base.css2slide(base.positionsInArray[position], 1);
                }
                base.afterGo();
                base.singleItemTransition();
                return false;
            }
            goToPixel = base.positionsInArray[position];

            if (base.browser.support3d === true) {
                base.isCss3Finish = false;

                if (speed === true) {
                    base.swapSpeed("paginationSpeed");
                    window.setTimeout(function () {
                        base.isCss3Finish = true;
                    }, base.options.paginationSpeed);

                } else if (speed === "rewind") {
                    base.swapSpeed(base.options.rewindSpeed);
                    window.setTimeout(function () {
                        base.isCss3Finish = true;
                    }, base.options.rewindSpeed);

                } else {
                    base.swapSpeed("slideSpeed");
                    window.setTimeout(function () {
                        base.isCss3Finish = true;
                    }, base.options.slideSpeed);
                }
                base.transition3d(goToPixel);
            } else {
                if (speed === true) {
                    base.css2slide(goToPixel, base.options.paginationSpeed);
                } else if (speed === "rewind") {
                    base.css2slide(goToPixel, base.options.rewindSpeed);
                } else {
                    base.css2slide(goToPixel, base.options.slideSpeed);
                }
            }
            base.afterGo();
        },

        jumpTo : function (position) {
            var base = this;
            if (typeof base.options.beforeMove === "function") {
                base.options.beforeMove.apply(this, [base.$elem]);
            }
            if (position >= base.maximumItem || position === -1) {
                position = base.maximumItem;
            } else if (position <= 0) {
                position = 0;
            }
            base.swapSpeed(0);
            if (base.browser.support3d === true) {
                base.transition3d(base.positionsInArray[position]);
            } else {
                base.css2slide(base.positionsInArray[position], 1);
            }
            base.currentItem = base.owl.currentItem = position;
            base.afterGo();
        },

        afterGo : function () {
            var base = this;

            base.prevArr.push(base.currentItem);
            base.prevItem = base.owl.prevItem = base.prevArr[base.prevArr.length - 2];
            base.prevArr.shift(0);

            if (base.prevItem !== base.currentItem) {
                base.checkPagination();
                base.checkNavigation();
                base.eachMoveUpdate();

                if (base.options.autoPlay !== false) {
                    base.checkAp();
                }
            }
            if (typeof base.options.afterMove === "function" && base.prevItem !== base.currentItem) {
                base.options.afterMove.apply(this, [base.$elem]);
            }
        },

        stop : function () {
            var base = this;
            base.apStatus = "stop";
            window.clearInterval(base.autoPlayInterval);
        },

        checkAp : function () {
            var base = this;
            if (base.apStatus !== "stop") {
                base.play();
            }
        },

        play : function () {
            var base = this;
            base.apStatus = "play";
            if (base.options.autoPlay === false) {
                return false;
            }
            window.clearInterval(base.autoPlayInterval);
            base.autoPlayInterval = window.setInterval(function () {
                base.next(true);
            }, base.options.autoPlay);
        },

        swapSpeed : function (action) {
            var base = this;
            if (action === "slideSpeed") {
                base.$owlWrapper.css(base.addCssSpeed(base.options.slideSpeed));
            } else if (action === "paginationSpeed") {
                base.$owlWrapper.css(base.addCssSpeed(base.options.paginationSpeed));
            } else if (typeof action !== "string") {
                base.$owlWrapper.css(base.addCssSpeed(action));
            }
        },

        addCssSpeed : function (speed) {
            return {
                "-webkit-transition": "all " + speed + "ms ease",
                "-moz-transition": "all " + speed + "ms ease",
                "-o-transition": "all " + speed + "ms ease",
                "transition": "all " + speed + "ms ease"
            };
        },

        removeTransition : function () {
            return {
                "-webkit-transition": "",
                "-moz-transition": "",
                "-o-transition": "",
                "transition": ""
            };
        },

        doTranslate : function (pixels) {
            return {
                "-webkit-transform": "translate3d(" + pixels + "px, 0px, 0px)",
                "-moz-transform": "translate3d(" + pixels + "px, 0px, 0px)",
                "-o-transform": "translate3d(" + pixels + "px, 0px, 0px)",
                "-ms-transform": "translate3d(" + pixels + "px, 0px, 0px)",
                "transform": "translate3d(" + pixels + "px, 0px,0px)"
            };
        },

        transition3d : function (value) {
            var base = this;
            base.$owlWrapper.css(base.doTranslate(value));
        },

        css2move : function (value) {
            var base = this;
            base.$owlWrapper.css({"left" : value});
        },

        css2slide : function (value, speed) {
            var base = this;

            base.isCssFinish = false;
            base.$owlWrapper.stop(true, true).animate({
                "left" : value
            }, {
                duration : speed || base.options.slideSpeed,
                complete : function () {
                    base.isCssFinish = true;
                }
            });
        },

        checkBrowser : function () {
            var base = this,
                translate3D = "translate3d(0px, 0px, 0px)",
                tempElem = document.createElement("div"),
                regex,
                asSupport,
                support3d,
                isTouch;

            tempElem.style.cssText = "  -moz-transform:" + translate3D +
                                  "; -ms-transform:"     + translate3D +
                                  "; -o-transform:"      + translate3D +
                                  "; -webkit-transform:" + translate3D +
                                  "; transform:"         + translate3D;
            regex = /translate3d\(0px, 0px, 0px\)/g;
            asSupport = tempElem.style.cssText.match(regex);
            support3d = (asSupport !== null && asSupport.length === 1);

            isTouch = "ontouchstart" in window || window.navigator.msMaxTouchPoints;

            base.browser = {
                "support3d" : support3d,
                "isTouch" : isTouch
            };
        },

        moveEvents : function () {
            var base = this;
            if (base.options.mouseDrag !== false || base.options.touchDrag !== false) {
                base.gestures();
                base.disabledEvents();
            }
        },

        eventTypes : function () {
            var base = this,
                types = ["s", "e", "x"];

            base.ev_types = {};

            if (base.options.mouseDrag === true && base.options.touchDrag === true) {
                types = [
                    "touchstart.owl mousedown.owl",
                    "touchmove.owl mousemove.owl",
                    "touchend.owl touchcancel.owl mouseup.owl"
                ];
            } else if (base.options.mouseDrag === false && base.options.touchDrag === true) {
                types = [
                    "touchstart.owl",
                    "touchmove.owl",
                    "touchend.owl touchcancel.owl"
                ];
            } else if (base.options.mouseDrag === true && base.options.touchDrag === false) {
                types = [
                    "mousedown.owl",
                    "mousemove.owl",
                    "mouseup.owl"
                ];
            }

            base.ev_types.start = types[0];
            base.ev_types.move = types[1];
            base.ev_types.end = types[2];
        },

        disabledEvents :  function () {
            var base = this;
            base.$elem.on("dragstart.owl", function (event) { event.preventDefault(); });
            base.$elem.on("mousedown.disableTextSelect", function (e) {
                return $(e.target).is('input, textarea, select, option');
            });
        },

        gestures : function () {
            /*jslint unparam: true*/
            var base = this,
                locals = {
                    offsetX : 0,
                    offsetY : 0,
                    baseElWidth : 0,
                    relativePos : 0,
                    position: null,
                    minSwipe : null,
                    maxSwipe: null,
                    sliding : null,
                    dargging: null,
                    targetElement : null
                };

            base.isCssFinish = true;

            function getTouches(event) {
                if (event.touches !== undefined) {
                    return {
                        x : event.touches[0].pageX,
                        y : event.touches[0].pageY
                    };
                }

                if (event.touches === undefined) {
                    if (event.pageX !== undefined) {
                        return {
                            x : event.pageX,
                            y : event.pageY
                        };
                    }
                    if (event.pageX === undefined) {
                        return {
                            x : event.clientX,
                            y : event.clientY
                        };
                    }
                }
            }

            function swapEvents(type) {
                if (type === "on") {
                    $(document).on(base.ev_types.move, dragMove);
                    $(document).on(base.ev_types.end, dragEnd);
                } else if (type === "off") {
                    $(document).off(base.ev_types.move);
                    $(document).off(base.ev_types.end);
                }
            }

            function dragStart(event) {
                var ev = event.originalEvent || event || window.event,
                    position;

                if (ev.which === 3) {
                    return false;
                }
                if (base.itemsAmount <= base.options.items) {
                    return;
                }
                if (base.isCssFinish === false && !base.options.dragBeforeAnimFinish) {
                    return false;
                }
                if (base.isCss3Finish === false && !base.options.dragBeforeAnimFinish) {
                    return false;
                }

                if (base.options.autoPlay !== false) {
                    window.clearInterval(base.autoPlayInterval);
                }

                if (base.browser.isTouch !== true && !base.$owlWrapper.hasClass("grabbing")) {
                    base.$owlWrapper.addClass("grabbing");
                }

                base.newPosX = 0;
                base.newRelativeX = 0;

                $(this).css(base.removeTransition());

                position = $(this).position();
                locals.relativePos = position.left;

                locals.offsetX = getTouches(ev).x - position.left;
                locals.offsetY = getTouches(ev).y - position.top;

                swapEvents("on");

                locals.sliding = false;
                locals.targetElement = ev.target || ev.srcElement;
            }

            function dragMove(event) {
                var ev = event.originalEvent || event || window.event,
                    minSwipe,
                    maxSwipe;

                base.newPosX = getTouches(ev).x - locals.offsetX;
                base.newPosY = getTouches(ev).y - locals.offsetY;
                base.newRelativeX = base.newPosX - locals.relativePos;

                if (typeof base.options.startDragging === "function" && locals.dragging !== true && base.newRelativeX !== 0) {
                    locals.dragging = true;
                    base.options.startDragging.apply(base, [base.$elem]);
                }

                if ((base.newRelativeX > 8 || base.newRelativeX < -8) && (base.browser.isTouch === true)) {
                    if (ev.preventDefault !== undefined) {
                        ev.preventDefault();
                    } else {
                        ev.returnValue = false;
                    }
                    locals.sliding = true;
                }

                if ((base.newPosY > 10 || base.newPosY < -10) && locals.sliding === false) {
                    $(document).off("touchmove.owl");
                }

                minSwipe = function () {
                    return base.newRelativeX / 5;
                };

                maxSwipe = function () {
                    return base.maximumPixels + base.newRelativeX / 5;
                };

                base.newPosX = Math.max(Math.min(base.newPosX, minSwipe()), maxSwipe());
                if (base.browser.support3d === true) {
                    base.transition3d(base.newPosX);
                } else {
                    base.css2move(base.newPosX);
                }
            }

            function dragEnd(event) {
                var ev = event.originalEvent || event || window.event,
                    newPosition,
                    handlers,
                    owlStopEvent;

                ev.target = ev.target || ev.srcElement;

                locals.dragging = false;

                if (base.browser.isTouch !== true) {
                    base.$owlWrapper.removeClass("grabbing");
                }

                if (base.newRelativeX < 0) {
                    base.dragDirection = base.owl.dragDirection = "left";
                } else {
                    base.dragDirection = base.owl.dragDirection = "right";
                }

                if (base.newRelativeX !== 0) {
                    newPosition = base.getNewPosition();
                    base.goTo(newPosition, false, "drag");
                    if (locals.targetElement === ev.target && base.browser.isTouch !== true) {
                        $(ev.target).on("click.disable", function (ev) {
                            ev.stopImmediatePropagation();
                            ev.stopPropagation();
                            ev.preventDefault();
                            $(ev.target).off("click.disable");
                        });
                        handlers = $._data(ev.target, "events").click;
                        owlStopEvent = handlers.pop();
                        handlers.splice(0, 0, owlStopEvent);
                    }
                }
                swapEvents("off");
            }
            base.$elem.on(base.ev_types.start, ".owl-wrapper", dragStart);
        },

        getNewPosition : function () {
            var base = this,
                newPosition = base.closestItem();

            if (newPosition > base.maximumItem) {
                base.currentItem = base.maximumItem;
                newPosition  = base.maximumItem;
            } else if (base.newPosX >= 0) {
                newPosition = 0;
                base.currentItem = 0;
            }
            return newPosition;
        },
        closestItem : function () {
            var base = this,
                array = base.options.scrollPerPage === true ? base.pagesInArray : base.positionsInArray,
                goal = base.newPosX,
                closest = null;

            $.each(array, function (i, v) {
                if (goal - (base.itemWidth / 20) > array[i + 1] && goal - (base.itemWidth / 20) < v && base.moveDirection() === "left") {
                    closest = v;
                    if (base.options.scrollPerPage === true) {
                        base.currentItem = $.inArray(closest, base.positionsInArray);
                    } else {
                        base.currentItem = i;
                    }
                } else if (goal + (base.itemWidth / 20) < v && goal + (base.itemWidth / 20) > (array[i + 1] || array[i] - base.itemWidth) && base.moveDirection() === "right") {
                    if (base.options.scrollPerPage === true) {
                        closest = array[i + 1] || array[array.length - 1];
                        base.currentItem = $.inArray(closest, base.positionsInArray);
                    } else {
                        closest = array[i + 1];
                        base.currentItem = i + 1;
                    }
                }
            });
            return base.currentItem;
        },

        moveDirection : function () {
            var base = this,
                direction;
            if (base.newRelativeX < 0) {
                direction = "right";
                base.playDirection = "next";
            } else {
                direction = "left";
                base.playDirection = "prev";
            }
            return direction;
        },

        customEvents : function () {
            /*jslint unparam: true*/
            var base = this;
            base.$elem.on("owl.next", function () {
                base.next();
            });
            base.$elem.on("owl.prev", function () {
                base.prev();
            });
            base.$elem.on("owl.play", function (event, speed) {
                base.options.autoPlay = speed;
                base.play();
                base.hoverStatus = "play";
            });
            base.$elem.on("owl.stop", function () {
                base.stop();
                base.hoverStatus = "stop";
            });
            base.$elem.on("owl.goTo", function (event, item) {
                base.goTo(item);
            });
            base.$elem.on("owl.jumpTo", function (event, item) {
                base.jumpTo(item);
            });
        },

        stopOnHover : function () {
            var base = this;
            if (base.options.stopOnHover === true && base.browser.isTouch !== true && base.options.autoPlay !== false) {
                base.$elem.on("mouseover", function () {
                    base.stop();
                });
                base.$elem.on("mouseout", function () {
                    if (base.hoverStatus !== "stop") {
                        base.play();
                    }
                });
            }
        },

        lazyLoad : function () {
            var base = this,
                i,
                $item,
                itemNumber,
                $lazyImg,
                follow;

            if (base.options.lazyLoad === false) {
                return false;
            }
            for (i = 0; i < base.itemsAmount; i += 1) {
                $item = $(base.$owlItems[i]);

                if ($item.data("owl-loaded") === "loaded") {
                    continue;
                }

                itemNumber = $item.data("owl-item");
                $lazyImg = $item.find(".lazyOwl");

                if (typeof $lazyImg.data("src") !== "string") {
                    $item.data("owl-loaded", "loaded");
                    continue;
                }
                if ($item.data("owl-loaded") === undefined) {
                    $lazyImg.hide();
                    $item.addClass("loading").data("owl-loaded", "checked");
                }
                if (base.options.lazyFollow === true) {
                    follow = itemNumber >= base.currentItem;
                } else {
                    follow = true;
                }
                if (follow && itemNumber < base.currentItem + base.options.items && $lazyImg.length) {
                    base.lazyPreload($item, $lazyImg);
                }
            }
        },

        lazyPreload : function ($item, $lazyImg) {
            var base = this,
                iterations = 0,
                isBackgroundImg;

            if ($lazyImg.prop("tagName") === "DIV") {
                $lazyImg.css("background-image", "url(" + $lazyImg.data("src") + ")");
                isBackgroundImg = true;
            } else {
                $lazyImg[0].src = $lazyImg.data("src");
            }

            function showImage() {
                $item.data("owl-loaded", "loaded").removeClass("loading");
                $lazyImg.removeAttr("data-src");
                if (base.options.lazyEffect === "fade") {
                    $lazyImg.fadeIn(400);
                } else {
                    $lazyImg.show();
                }
                if (typeof base.options.afterLazyLoad === "function") {
                    base.options.afterLazyLoad.apply(this, [base.$elem]);
                }
            }

            function checkLazyImage() {
                iterations += 1;
                if (base.completeImg($lazyImg.get(0)) || isBackgroundImg === true) {
                    showImage();
                } else if (iterations <= 100) {//if image loads in less than 10 seconds 
                    window.setTimeout(checkLazyImage, 100);
                } else {
                    showImage();
                }
            }

            checkLazyImage();
        },

        autoHeight : function () {
            var base = this,
                $currentimg = $(base.$owlItems[base.currentItem]).find("img"),
                iterations;

            function addHeight() {
                var $currentItem = $(base.$owlItems[base.currentItem]).height();
                base.wrapperOuter.css("height", $currentItem + "px");
                if (!base.wrapperOuter.hasClass("autoHeight")) {
                    window.setTimeout(function () {
                        base.wrapperOuter.addClass("autoHeight");
                    }, 0);
                }
            }

            function checkImage() {
                iterations += 1;
                if (base.completeImg($currentimg.get(0))) {
                    addHeight();
                } else if (iterations <= 100) { //if image loads in less than 10 seconds 
                    window.setTimeout(checkImage, 100);
                } else {
                    base.wrapperOuter.css("height", ""); //Else remove height attribute
                }
            }

            if ($currentimg.get(0) !== undefined) {
                iterations = 0;
                checkImage();
            } else {
                addHeight();
            }
        },

        completeImg : function (img) {
            var naturalWidthType;

            if (!img.complete) {
                return false;
            }
            naturalWidthType = typeof img.naturalWidth;
            if (naturalWidthType !== "undefined" && img.naturalWidth === 0) {
                return false;
            }
            return true;
        },

        onVisibleItems : function () {
            var base = this,
                i;

            if (base.options.addClassActive === true) {
                base.$owlItems.removeClass("active");
            }
            base.visibleItems = [];
            for (i = base.currentItem; i < base.currentItem + base.options.items; i += 1) {
                base.visibleItems.push(i);

                if (base.options.addClassActive === true) {
                    $(base.$owlItems[i]).addClass("active");
                }
            }
            base.owl.visibleItems = base.visibleItems;
        },

        transitionTypes : function (className) {
            var base = this;
            //Currently available: "fade", "backSlide", "goDown", "fadeUp"
            base.outClass = "owl-" + className + "-out";
            base.inClass = "owl-" + className + "-in";
        },

        singleItemTransition : function () {
            var base = this,
                outClass = base.outClass,
                inClass = base.inClass,
                $currentItem = base.$owlItems.eq(base.currentItem),
                $prevItem = base.$owlItems.eq(base.prevItem),
                prevPos = Math.abs(base.positionsInArray[base.currentItem]) + base.positionsInArray[base.prevItem],
                origin = Math.abs(base.positionsInArray[base.currentItem]) + base.itemWidth / 2,
                animEnd = 'webkitAnimationEnd oAnimationEnd MSAnimationEnd animationend';

            base.isTransition = true;

            base.$owlWrapper
                .addClass('owl-origin')
                .css({
                    "-webkit-transform-origin" : origin + "px",
                    "-moz-perspective-origin" : origin + "px",
                    "perspective-origin" : origin + "px"
                });
            function transStyles(prevPos) {
                return {
                    "position" : "relative",
                    "left" : prevPos + "px"
                };
            }

            $prevItem
                .css(transStyles(prevPos, 10))
                .addClass(outClass)
                .on(animEnd, function () {
                    base.endPrev = true;
                    $prevItem.off(animEnd);
                    base.clearTransStyle($prevItem, outClass);
                });

            $currentItem
                .addClass(inClass)
                .on(animEnd, function () {
                    base.endCurrent = true;
                    $currentItem.off(animEnd);
                    base.clearTransStyle($currentItem, inClass);
                });
        },

        clearTransStyle : function (item, classToRemove) {
            var base = this;
            item.css({
                "position" : "",
                "left" : ""
            }).removeClass(classToRemove);

            if (base.endPrev && base.endCurrent) {
                base.$owlWrapper.removeClass('owl-origin');
                base.endPrev = false;
                base.endCurrent = false;
                base.isTransition = false;
            }
        },

        owlStatus : function () {
            var base = this;
            base.owl = {
                "userOptions"   : base.userOptions,
                "baseElement"   : base.$elem,
                "userItems"     : base.$userItems,
                "owlItems"      : base.$owlItems,
                "currentItem"   : base.currentItem,
                "prevItem"      : base.prevItem,
                "visibleItems"  : base.visibleItems,
                "isTouch"       : base.browser.isTouch,
                "browser"       : base.browser,
                "dragDirection" : base.dragDirection
            };
        },

        clearEvents : function () {
            var base = this;
            base.$elem.off(".owl owl mousedown.disableTextSelect");
            $(document).off(".owl owl");
            $(window).off("resize", base.resizer);
        },

        unWrap : function () {
            var base = this;
            if (base.$elem.children().length !== 0) {
                base.$owlWrapper.unwrap();
                base.$userItems.unwrap().unwrap();
                if (base.owlControls) {
                    base.owlControls.remove();
                }
            }
            base.clearEvents();
            base.$elem
                .attr("style", base.$elem.data("owl-originalStyles") || "")
                .attr("class", base.$elem.data("owl-originalClasses"));
        },

        destroy : function () {
            var base = this;
            base.stop();
            window.clearInterval(base.checkVisible);
            base.unWrap();
            base.$elem.removeData();
        },

        reinit : function (newOptions) {
            var base = this,
                options = $.extend({}, base.userOptions, newOptions);
            base.unWrap();
            base.init(options, base.$elem);
        },

        addItem : function (htmlString, targetPosition) {
            var base = this,
                position;

            if (!htmlString) {return false; }

            if (base.$elem.children().length === 0) {
                base.$elem.append(htmlString);
                base.setVars();
                return false;
            }
            base.unWrap();
            if (targetPosition === undefined || targetPosition === -1) {
                position = -1;
            } else {
                position = targetPosition;
            }
            if (position >= base.$userItems.length || position === -1) {
                base.$userItems.eq(-1).after(htmlString);
            } else {
                base.$userItems.eq(position).before(htmlString);
            }

            base.setVars();
        },

        removeItem : function (targetPosition) {
            var base = this,
                position;

            if (base.$elem.children().length === 0) {
                return false;
            }
            if (targetPosition === undefined || targetPosition === -1) {
                position = -1;
            } else {
                position = targetPosition;
            }

            base.unWrap();
            base.$userItems.eq(position).remove();
            base.setVars();
        }

    };

    $.fn.owlCarousel = function (options) {
        return this.each(function () {
            if ($(this).data("owl-init") === true) {
                return false;
            }
            $(this).data("owl-init", true);
            var carousel = Object.create(Carousel);
            carousel.init(options, this);
            $.data(this, "owlCarousel", carousel);
        });
    };

    $.fn.owlCarousel.options = {

        items : 5,
        itemsCustom : false,
        itemsDesktop : [1199, 4],
        itemsDesktopSmall : [979, 3],
        itemsTablet : [768, 2],
        itemsTabletSmall : false,
        itemsMobile : [479, 1],
        singleItem : false,
        itemsScaleUp : false,

        slideSpeed : 200,
        paginationSpeed : 800,
        rewindSpeed : 1000,

        autoPlay : false,
        stopOnHover : false,

        navigation : false,
        navigationText : ["prev", "next"],
        rewindNav : true,
        scrollPerPage : false,

        pagination : true,
        paginationNumbers : false,

        responsive : true,
        responsiveRefreshRate : 200,
        responsiveBaseWidth : window,

        baseClass : "owl-carousel",
        theme : "owl-theme",

        lazyLoad : false,
        lazyFollow : true,
        lazyEffect : "fade",

        autoHeight : false,

        jsonPath : false,
        jsonSuccess : false,

        dragBeforeAnimFinish : true,
        mouseDrag : true,
        touchDrag : true,

        addClassActive : false,
        transitionStyle : false,

        beforeUpdate : false,
        afterUpdate : false,
        beforeInit : false,
        afterInit : false,
        beforeMove : false,
        afterMove : false,
        afterAction : false,
        startDragging : false,
        afterLazyLoad: false
    };
}(jQuery, window, document));
var $ = jQuery; // I don't feel like typing jQuery() a thousand times. No one should *want* that.

jQuery(function() { // wait for DOM to load... as one does.

 if (!Modernizr.input.list) { // Ask Modernizr if the browser supports autofill dropdown lists
  $.webshims.polyfill(); // if it doesn't, then we'll shim in a polyfill.
 }

 // NEXT UP: handle navbar scrolling effect.
 var awbsNavbar = $(".navwrapper"); // grab the navwrapper DOM element
 var menuVis = VisSense(awbsNavbar[0], {
  fullyvisible: 0.2
 }); // instantiate the VisSense library, which will "listen" for changes to the elements location in the viewport.

 var vis_monitor = menuVis.monitor({ // now we'll actually monitor for changes
  strategy: new VisSense.VisMon.Strategy.EventStrategy({
   debounce: 100
  }),
  fullyvisible: function() { // when the navbar is fully visible (based on the value at instantiation), unfix the mini-bar
   $(".menubar").removeClass('active animated bounceInDown');
   $(".awbs-left-menu-header").addClass('active');
  },
  hidden: function() { // when the navbar is 'hidden' (based on the value at instantiation), affix the mini-bar
   $(".menubar").addClass('active animated  bounceInDown');
   $(".awbs-left-menu-header").removeClass('active');
  }
 }).start(); // start the actual monitor

 $("#hamburger-lg").on('click touch', function(e) { // listen for the click event on the hamburger menu
  e.preventDefault();
 });

 $("#awbs-360-click-for-details").on('click touch', function() { // listen for click event on the 360 dropdown clickable
  $(" i", this).toggleClass('opened');
  $(".awbs-360-details-dropdown-contents").toggleClass(
   'contents-active animated fadeIn');
 });

 var articleCarousel = $('.owl-carousel'); // instansiate the article image carousel
 articleCarousel.owlCarousel({
  singleItem: true,
  autoPlay: 5000, // autoplay every 5s
  slideSpeed: 1000, // 1s slide time
  paginationSpeed: 1500, // 1.5s changeout
  stopOnHover: true,
  navigation: true,
  navigationText: [
   "<img src='/sites/default/themes/awbs/images/arrowl.png'>",
   "<img src='/sites/default/themes/awbs/images/arrowr.png'>"
  ],
  theme: "owl-theme",
  // //Lazy load
  lazyLoad: true, // don't hold up page rendering waiting for images to load.
  lazyFollow: true,
  lazyEffect: "fade" // use a fade effect as elements lazy load in.
 });

 /*
  * Pertains to the in-article newsletter signup box
  */
 $("#newsletter-input-value").on('focus', function() { // listen for a focus event on the inline newsletter signup box input
  $(this).removeClass('newsletter-input-error');
  $(".newsletter-input-box").removeAttr('data-hint');
 });

 $("#newsletter-submit-button").click(function(e) { // listen for a click event on the inline newsletter signup box button
  void 0;
  e.preventDefault();
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

  // if all statuses are met, pass this into the subscription tool
  window.location.href = '/subscribe?email=' + encodeURIComponent(inputVal);
 });


});


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



var $ = jQuery; // listen for a mouseenter event on a subtopic element in the open dropdown

$(function() { // wait for DOM to load... as one does.
 var longArticleWordCount; // placeholder that fills with the word count for the article
 var pCount; // how many paragraph tags are there in the article
 var wordCount; // what's the word count of the article?

 // numeric states
 if ((typeof postLength !== 'undefined') && (typeof postType !== 'undefined')) {
  longArticleWordCount = (postLength == 'long') ? true : false;
  pCount = _.size($(".awbs-body-text p"));
  wordCount = 0;
 }
 // lodash templates
 var rpullquote = _.template(
  '<div class="inserted-pullquote col-xs-12 col-md-5 awbs-plug-pullquote rightpull"></div>'
 );
 var lpullquote = _.template(
  '<div class="inserted-pullquote col-xs-12 col-md-5 awbs-plug-pullquote leftpull"></div>'
 );
 var lpullimage = _.template(
  '<div class="inserted-pullimage col-xs-12 col-md-4 awbs-plug-pullimage leftpull"></div>'
 );
 var rpullimage = _.template(
  '<div class="inserted-pullimage col-xs-12 col-md-4 awbs-plug-pullimage rightpull"></div>'
 );
 var imubox = _.template(
  '<div class="inserted-imu col-xs-12 col-md-4 awbs-plug-imu leftpull"></div>'
 );
 var featureImubox = _.template(
  '<div class="inserted-feature-imu col-xs-12 col-md-4 awbs-plug-imu rightpull"></div>'
 );
 var shortArticleEOCImubox = _.template(
  '<div class="row"><div class="inserted-eoc-imu col-xs-12 col-md-6 col-md-push-3 awbs-plug-imu center-block"></div></div>'
 );
 var flaImubox = _.template(
  '<div class="row"><div class="inserted-fla-imu awbs-plug-fla-imu col-xs-12 col-md-12"></div></div>'
 );
 var signupbox = _.template(
  '<div class="inserted-signup col-xs-12 col-md-3 awbs-plug-signup leftpull"></div>'
 );
 var blogsignupbox = _.template(
  '<div class="inserted-signup col-xs-12 col-md-4 awbs-plug-signup leftpull"></div>'
 );
 var sidebar = _.template(
  '<div class="inserted-sidebar awbs-plug-sidebar col-xs-12 col-sm-12 col-md-12 col-lg-12"></div>'
 );
 var altimage = _.template(
  '<div class="inserted-altimage col-xs-12 col-sm-12 col-md-5 img-responsive center-block awbs-plug-altimg leftpull"></div>'
 );
 var liabox = _.template(
  '<div class="inserted-liabox hidden-xs hidden-sm col-md-4 center-block awbs-plug-liabox leftpull"></div>'
 );

 // boolean states
 var definedQuote = false; // did we find a {*pullquote*} tag in the content body?
 var definedIMU = false; // did we find a {*imu*} tag in the content body?
 var definedSignup = false; // did we find a {*signup*} tag in the content body?
 // FeatureIMU does not have a define because the feature IMU is always in the
 // upper right corner of the content area, per the original design.

 // insertion variables
 var insertParagraph; // what paragraph will the given floating chunk be assigned into

 // Let's go through each p tag under the body-text
 _.each($(".awbs-body-text p, .awbs-body-text ul, .awbs-body-text ol"),
  function(paragraphText, paragraphNumber) {
   // if we come across a pullquote mustache
   if (paragraphText.innerHTML.indexOf("{*PULLQUOTE*}") >= 0) {
    definedQuote = true; // set that we've found a pullquote
    paragraphText.innerHTML = paragraphText.innerHTML.replace(
     '{*PULLQUOTE*}', pullquote);
    $(".inserted-pullquote").append($(".pullquote").removeClass('hidden'));
   }

   // if we come across an IMU mustache
   if (paragraphText.innerHTML.indexOf("{*IMU*}") >= 0) {
    if (longArticleWordCount) {
     definedIMU = true; // set that we've found an IMU
     paragraphText.innerHTML = paragraphText.innerHTML.replace('{*IMU*}',
      imubox);
     $(".inserted-imu").append($(".imuB").removeClass('hidden'));
    } else {
     paragraphText.innerHTML = paragraphText.innerHTML.replace('{*IMU*}',
      '');
    }
   }

   // if we come across a signup mustache
   // if (paragraphText.innerHTML.indexOf("{*SIGNUP*}") >= 0) {
   //  definedSignup = true; // set that we've found an IMU
   //  paragraphText.innerHTML = paragraphText.innerHTML.replace('{*SIGNUP*}',
   //   signupbox);
   //  $(".inserted-signup").append($(".signup").removeClass('hidden'));
   // }

   // if we come across a sidebar mustache
   if (paragraphText.innerHTML.indexOf("{*SIDEBAR*}") >= 0) {
    paragraphText.innerHTML = paragraphText.innerHTML.replace(
     '{*SIDEBAR*}', sidebar);
    $(".inserted-sidebar").append($(".sidebar").removeClass('hidden'))
     .unwrap();
   }


   // if we come across a left pullquote mustache
   if (paragraphText.innerHTML.indexOf("{*LPULLQUOTE*}") >= 0) {
    paragraphText.innerHTML = paragraphText.innerHTML.replace(
     '{*LPULLQUOTE*}', lpullquote);
    $(".inserted-pullquote").append($(".pullquote").removeClass('hidden'));
   }

   // if we come across a right pullquote mustache
   if (paragraphText.innerHTML.indexOf("{*RPULLQUOTE*}") >= 0) {
    paragraphText.innerHTML = paragraphText.innerHTML.replace(
     '{*RPULLQUOTE*}', rpullquote);
    $(".inserted-pullquote").append($(".pullquote").removeClass('hidden'));
   }

   // if we come across a left pullimage mustache
   if (paragraphText.innerHTML.indexOf("{*LPULLIMAGE*}") >= 0) {
    paragraphText.innerHTML = paragraphText.innerHTML.replace(
     '{*LPULLIMAGE*}', lpullimage);
    $(".inserted-pullimage").append($(".pullimage").removeClass('hidden'));
   }

   // if we come across a right pullimage mustache
   if (paragraphText.innerHTML.indexOf("{*RPULLIMAGE*}") >= 0) {
    paragraphText.innerHTML = paragraphText.innerHTML.replace(
     '{*RPULLIMAGE*}', rpullimage);
    $(".inserted-pullimage").append($(".pullimage").removeClass('hidden'));
   }

   // how many total words are there in this piece?
   wordCount = wordCount + paragraphText.innerHTML.length;
  });


 // If this an article and not a feature article
 if ((postType == 'article') && (subType !== 'feature')) {
  if ((!definedIMU) && (longArticleWordCount)) {
   var imuInsertPoint = parseInt(pCount * 0.75) - 1;
   insertParagraph = $(".awbs-body-text p")[imuInsertPoint];
   $(insertParagraph).prepend(imubox);
   $(".inserted-imu").append($(".imuB").removeClass('hidden'));

   var liaInsertPoint = parseInt(pCount * 0.25) - 1;
   insertParagraph = $(".awbs-body-text p")[liaInsertPoint];
   $(insertParagraph).prepend(liabox);
   // because of some very poor html class definition and structuring,
   // this is how we have to scoot out the unneeded boxes.
   // Wrappers, people, wrappers. Not just for candy bars.
   $(".inline-lia-datacard h4").not(':eq(0)').css('display', 'none');
   $(".inline-lia-datacard .leadership-menu").not(':eq(0)').css('display',
    'none');
   $(".inline-lia-datacard .ld-vote-message").not(':eq(0)').css('display',
    'none');
   $(".inline-lia-datacard script").not(':eq(0)').css('display', 'none');
   $(".inserted-liabox").append($(".inline-lia-datacard").removeClass(
    'hidden'));
  }
 }

 // Per D. Greenfield on 06/18/2016, blog posts should _always_ have a pullquote
 if ((postType == 'blog')) {
  var pqInsertPoint = parseInt(pCount * 0.5);
  insertParagraph = $(".awbs-body-text p")[pqInsertPoint];
  $(insertParagraph).append(lpullquote);
  $(".inserted-pullquote").append($(".pullquote").removeClass("hidden"));
 }

 //if this is a short article(not blog)
 if ((postType == 'article') && (!longArticleWordCount)) {
  $("#awbs-main-content").after(shortArticleEOCImubox);
  $(".inserted-eoc-imu").append($(".imuB").removeClass('hidden'));
  $(".imuB img").addClass('center-block awbs-imu-imageWrap');
 }

 // if this is is a long article, we drop the IMU next to the image/carousel
 if ((postType == 'article') && (longArticleWordCount) && (subType !==
   'feature')) {
  void 0;
  $(".awbs-fla-imu").append(flaImubox);
  $(".inserted-fla-imu").append($(".imuA").removeClass('hidden').addClass(
   'rightpull'));
 }

 // if this is a feature article
 if ((postType == 'article') && (subType == 'feature')) {
  void 0;
  var featureImuInsertPoint = 0;
  insertParagraph = $(".awbs-body-text p")[featureImuInsertPoint];
  $(insertParagraph).prepend(featureImubox);
  $(".inserted-feature-imu").append($(".imuA").removeClass('hidden'));
 }

 //	if there isn't a signup box location defined and this is a long article
 // if ((!definedSignup) && (longArticleWordCount)) {
 //  var signupInsertPoint = parseInt(pCount * 0.75);
 //  insertParagraph = $(".awbs-body-text p")[signupInsertPoint];
 //  $(insertParagraph).prepend(signupbox);
 //  $(".inserted-signup").append($(".signup").removeClass('hidden'));
 // }

 // if ((!definedSignup) && (postType == 'blog')) {
 //  var blogSignupInsertPoint = parseInt(pCount * 0.5);
 //  insertParagraph = $(".awbs-body-text p")[blogSignupInsertPoint];
 //  $(insertParagraph).prepend(blogsignupbox);
 //  $(".inserted-signup").append($(".signup").removeClass('hidden'));
 // }
});

(function($) {
  $(document).ready(function() {
    var mrJimPowers = $(".page-node-18775");
    if (mrJimPowers.length) {
      var companyDropdown = mrJimPowers.find(".awbs-360-details-dropdown-company"),
        company = companyDropdown.find("a"),
        companyName = company[0].innerHTML;
      company.replaceWith("<span style='color: #c60000 !important;'>" + companyName + "</span>");
    }

    // #1049
    var webformPage = $(".node-type-webform");
    if (webformPage.length) {
      webformPage.find('.webform-component-smg_email').find('input').addClass('form-control');
      webformPage.find('.webform-component-select').find('.ui-widget').css({'width':'100%'});
    }
  });
})(jQuery);

(function ($) {
  $(document).ready(function(){
    $(".awbs-body-text p:nth-of-type(4)").append($("#block-dfp-native"));
    $(".companies-article").append($("#blueconic-offer"));


    // if($("#block-smgrelated-smgrelated-default").length > 0) {
    //   $("#block-smgrelated-smgrelated-default").prepend($("#blueconic-offer"));
    // }
    // else {
    //     $(".awbs-body-text").append($("#blueconic-offer"));
    // }
  });
})(jQuery);

/**
 * This file is separate from main.js as code in it lends itself more specifically
 * to the function of the navigation system.
 */

$(function () { // wait for the DOM to load...
  var menuHoverTimer; // timer for the top-level navbar menu delayed display
  var menuHoverOutTimer; // timer to delay destroying the dropdown menu being display
  var menuDataBlocks = []; // JSON blocks from the menu endpoints
  var menuItems; // items in the dropdown menus
  var menuItemIndex; // get the index of the clicked/hovered item
  var contentItemsCount; // how many content items are there for a specific subtopic in the dropdown menu?
  var contentItems = []; // the items under each subtopic
  var template; // temporarily holds the templates that are built based on content pulled from the endpoints
  var keyname; // holds the key for the data object returned from the server endpoint, as we loop through that object
  var sectionHoverTimer; // timer for each subtopic in the menu dropdowns
  var menuName = ''; // a string that holds the name of the currently 'active' top-level menu item.
  var menuElementsToGrab = [
    'aweditors', // you guessed it - these are the menu elements we're going to grab.
    'products',
    'factory',
    'process',
    'engineering',
    'operations',
    'it'
  ];
  var loadeds = []; // watches for loading status of our endpoint paylods
  var menusAreLoaded = false; // have all the menu endpoints returned data to display in the dropdown menus off of nav?

  /**
   * This function helps us get the size of the object returned from our menu
   * endpoints (i.e. - how many items were returned for a given subtopic)
   * @param  object obj The object we're trying to count
   * @return int  the count of the elements in the subtopic
   */
  Object.size = function (obj) {
    var size = 0,
      key;
    for (key in obj) {
      if (obj.hasOwnProperty(key)) {
        size++;
      }
    }
    return size;
  };

  /**
   * This will go out and pull the menu payload, returning a promise
   * when the ajax call completes
   *
   */
  function doPull() {
    var promise = $.ajax({
      url: '/awmegamenu/get-content/menuname',
      data: {
        format: 'json',
      },
      dataType: 'json',
      success: function (r) {
        menuDataBlocks = r;

      }
    });
    return promise;
  }

  doPull().then(function () {
    menusAreLoaded = true;
  });


  $(".menubar .leaf").mouseenter(function () { // listen for a hover event pairing on one of the top level navbar menu elements
    var selectionName = '';
    var _this = this;
    menuItemIndex = $(this).index();
    clearTimeout(menuHoverOutTimer);

    if (menusAreLoaded) {
      menuHoverTimer = setTimeout(function () {
        selectionName = $(_this).text().toLowerCase().replace(/ /g, "");
        showMenuContentsFor(selectionName);
        $('.menubar .leaf').not($(_this)).removeClass('active-space');
        $(_this).addClass('active-space');
        $(".awbs-navbar-dropdown-menu").not($('.awbs-navbar-dropdown-menu').eq(
          menuItemIndex)).removeClass(
          'awbs-dropdown-active');

        $(".awbs-navbar-dropdown-menu").eq(menuItemIndex).addClass(
          'awbs-dropdown-active');
      }, 500);
    }
  });

  $(".awbs-navbar-dropdown-menu").mouseenter(function () {
    clearTimeout(menuHoverOutTimer);
  });


  $(".menubar").mouseleave(function () {
    if (menusAreLoaded) {
      clearTimeout(menuHoverTimer);
      menuHoverOutTimer = setTimeout(function () {
        $(".menubar .leaf").eq(menuItemIndex).removeClass('active-space');
        $(".awbs-navbar-dropdown-menu").removeClass(
          'awbs-dropdown-active');
      }, 1000);


    }
  });

  /**
   * Load the contents for the requested dropdown
   * @param string menuNamePassback the name of the menu, pulled from the contents of the element ('products', 'aw editors')
   */
  function showMenuContentsFor(menuNamePassback) {

    var data = menuDataBlocks[menuNamePassback]; // load the prefetched data
    var firstKey; // a catch to jump to the first subtopic elements
    menuitems = Object.size(data); // determine how many elements are in the subtopic dataset
    menuName = menuNamePassback; // rename the passback variable


    $("#awbs-navbar-" + menuName + "-selections ul").empty(); // empty out the selection list
    $("#awbs-navbar-" + menuName + "-contents").empty(); // empty out the contents panel

    for (var key in data) { // loop through the data set
      if (typeof firstKey == 'undefined') { // set the first key, as for mentioned above.
        firstKey = _.snakeCase(key).toLowerCase(); // set that first key
      }
      keyname = _.snakeCase(key).toLowerCase(); // set the keyname for the next step
      contentItems[keyname] = ''; // empty the template set.
      //	console.log('path', data[key].path);
      $("#awbs-navbar-" + menuName + "-selections ul").append(
        "<li class='animated fadeInLeft'><a href='/" +
        data[key].path +
        "' class='menu-select-section' id='" + keyname +
        "'>" +
        key + "</a></li>"); // populate the selection list with subtopics

      contentItemsCount = Object.size(data[key].items); // how many boxes are there to display

      void 0;
      for (var i = 0; i < contentItemsCount; i++) { // for each item in the item count
        template = _.template(
          '<div class="col-xs-12 col-md-3 content-item-container animated fadeInRight"> <div class="row"><div class="col-xs-12 content-item"><div class="row"><a href="<%- href %>"><div class="col-xs-12 content-item-image" style="background-image:url(<%- image %>);"></div><div class="col-xs-12 content-item-title"><%- title %></div></a></div></div></div></div>'
        ); // generate a template string
        void 0;
        contentItems[keyname] += template({
          'href': "/" + data[key].items[i].href,
          'image': data[key].items[i].image.src,
          'title': data[key].items[i].title
        }); // and compile it with the pertinent data
        void 0;
      }
    }


    $("#awbs-navbar-" + menuName + "-contents").append(contentItems[firstKey]); // append the item set for the first subtopic to the content panel
    $("#awbs-navbar-" + menuName + "-selections ul li a").eq(0).addClass(
      'active'); // mark the first item in the subtopic selection list as 'active'
  }

  // You can't use .hover on a dynamically created element, so you must use
  // mouseenter, mouseleave to mimic the behavior
  $(document).on('mouseenter', '.menu-select-section', function () { // listen for a mouseenter event on a subtopic element in the open dropdown
    var _this = this;
    sectionHoverTimer = setTimeout(function () {
      $("#awbs-navbar-" + menuName + "-contents").empty();
      $("#awbs-navbar-" + menuName + "-selections ul li a").removeClass(
        'active');
      $(_this).addClass('active');
      $("#awbs-navbar-" + menuName + "-contents").append(contentItems[$(
        _this).attr(
        'id')]);
    }, 500);
  });

  $(document).on('mouseleave', '.menu-select-section', function () { // listen for a mouseleave event on a subtopic element in the open dropdown
    clearTimeout(sectionHoverTimer);
  });

  $(".slide-active").on('click touch', function () {
    void 0;
    $('#awbs-mobile-hamburger').removeClass('active');
    el = $('.awbs-mobile-nav-options');
    el.addClass('slideOutLeft');
    $('.main-container, .footer').removeClass('slide-active');
    el.one('webkitAnimationEnd oanimationend msAnimationEnd animationend',
      function (e) {
        el.removeClass('slideOutLeft active');
      });
  });

  // mobile search button
  $("#awbs-mobile-search").on('click touch', function () {
    $('.awbs-mobile-nav-options').removeClass('active');
    $('#awbs-mobile-hamburger').removeClass('active');
    $('.main-container, .footer').removeClass('slide-active');
    var el = $('.awbs-mobile-nav-search');

    if (el.hasClass('active')) {
      el.addClass('slideOutUp');
      el.one('webkitAnimationEnd oanimationend msAnimationEnd animationend',
        function (e) {
          el.removeClass('slideOutUp active');
        });
      return;
    }
    else {
      el.addClass('slideInDown active');
      el.one('webkitAnimationEnd oanimationend msAnimationEnd animationend',
        function (e) {
          el.removeClass('slideInDown');
        });
      return;
    }
  });


  // listen for open/close events on the mobile slide out menu
  $('#awbs-mobile-hamburger, #awbs-mobile-hamburger-close').on('click touch',
    function () {
      $('.awbs-mobile-nav-search').removeClass('active');
      var el;

      if ($('#awbs-mobile-hamburger').hasClass('active')) {
        $('#awbs-mobile-hamburger').removeClass('active');
        el = $('.awbs-mobile-nav-options');
        el.addClass('slideOutLeft');
        $('.main-container, .footer').removeClass('slide-active');
        el.one('webkitAnimationEnd oanimationend msAnimationEnd animationend',
          function (e) {
            el.removeClass('slideOutLeft active');
          });
      }
      else {
        $('#awbs-mobile-hamburger').addClass('active');
        el = $('.awbs-mobile-nav-options');
        el.addClass('slideInLeft active');
        $('.main-container, .footer').addClass('slide-active');
        el.one('webkitAnimationEnd oanimationend msAnimationEnd animationend',
          function (e) {
            el.removeClass('slideInLeft');
          });
      }
    });

  //Accordion for mobile navigation
  $('.awbs-mobile-nav-options li.expanded > a')
    .on('click', function () {
      var menu = $('.awbs-mobile-nav-options');
      var menuItem = $(this).parent();
      menu.scrollTop(0);
      if (menuItem.hasClass('opened')) {
        menuItem.removeClass('opened').find('.menu').slideUp('fast');
      }
      else {
        $('.awbs-mobile-nav-options li.expanded.opened')
          .removeClass('opened')
          .find('.menu')
          .slideUp('fast');
        menuItem.addClass('opened')
          .find('.menu')
          .slideDown('fast', function () {
            var nextItem = menuItem.next();
            var nextItemTop = nextItem.position().top;
            var menuHeight = menu.height();
            var scrollNumber = nextItemTop - menuHeight + 50;
            if (menuHeight < nextItemTop + 50) {
              menu.animate({scrollTop: scrollNumber}, 250);
            }
          });
      }
      return false;
    });

});
