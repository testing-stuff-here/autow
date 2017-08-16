;(function() {
'use strict';

/**
 * Defines PURF object constructor
 * @file purf-object.js
 */

var spFullName = false,
    purfDate = new Date(),

// If popType is video_click, we use the viddlerVerified variable to track when the user presses play.
// Once we've tracked the lead (i.e. they fill out the form or we auto-submit), we set the value to true.
viddlerVerified = false,

// If popType is video_click, the following variables will be instantiated (which one
// depends on whether or not the browser supports flash player)
player = false,
    purfOverrideOn = false,
    jqxhr = void 0,
    documentDomain = void 0,
    purfLayoutType = 'two-column-layout';

purfDate.setTime(purfDate.getTime() + 15 * 60 * 1000);

function isEmpty(obj) {
  var key = void 0;
  for (key in obj) {
    if (obj.hasOwnProperty(key)) {
      return false;
    }
  }
  return true;
}

// Create a global PURF object, that will contain global properties
function PURFGlobal() {
  return this;
}

/**
 * Now add the properties to the prototype property, so that all PURFs
 * that extend PURFGlobal will share (and can override)
 * @name PURFGlobal
 * @alias PURFManager
 * @type {String | Boolean} prototype.userID
 */
PURFGlobal.prototype.queryParameters = '';
PURFGlobal.prototype.header = '';
PURFGlobal.prototype.headerNew = '';
PURFGlobal.prototype.headerExist = '';
PURFGlobal.prototype.inlineLinkInfo = {};
PURFGlobal.prototype.twoColumn = {};
PURFGlobal.prototype.oneColumn = {};
PURFGlobal.prototype.userID = false;
PURFGlobal.prototype.disclaimer = false;
PURFGlobal.prototype.readerTokenCookie = false;

// Create an object that will manage PURF variables and details
/**
 *
 * @constructor
 *
 * @name PURFManager
 * @property {Boolean} hide_purf_spop_mailings
 * @property {Object}  purfSettings
 * @property {Object}  purfSettings.pop_data
 * @property {Boolean} purfSettings.referredUser
 *
 */
function PURFManager() {
  this.purfNID = false;
  this.customQuestions = [];
  this.extraQuestions = {};
  this.queryURL = '';
  this.purfSettings = {
    "referer_nid": "",
    "leadworks_id": ""
  };
  this.viddlerId = false;
  this.popType = 'page_load';
  this.isExtra = false;
}

// Create a PURFGlobal object for PURFManager
PURFManager.prototype = new PURFGlobal();

// Function to add parameters to PURFManager object
PURFManager.prototype.addParameters = function (purfNID, customQuestions) {
  this.purfNID = typeof purfNID !== 'undefined' ? purfNID : 'FALSE';
  this.customQuestions = typeof customQuestions !== 'undefined' ? customQuestions : this.customQuestions;
};

PURFManager.prototype.addQueryParameters = function () {
  return true;
}; // The "return true" is to suppress jslint error @todo delete fct?

// Add function to purfManager object that will generate query URLs
PURFManager.prototype.createQueryURL = function () {

  var custom = '',
      extra = '',
      extParams = void 0,
      rCookie = '',
      rCookieQuery = void 0;

  if (this.customQuestions.length) {
    custom = 'custQ[]=' + this.customQuestions.join("&custQ[]=");
  }
  if (this.extraQuestions.hasOwnProperty("ext")) {
    extParams = decodeURIComponent(jQuery.param(this.extraQuestions));
    extra = custom.length ? '&' + extParams : extParams;
  }
  if (this.readerTokenCookie) {
    rCookieQuery = 'rCookie=' + this.readerTokenCookie;
    rCookie = custom.length || extra.length ? '&' + rCookieQuery : rCookieQuery;
  }
  if (custom.length || extra.length || rCookie.length) {
    this.queryParameters = '?' + custom + extra + rCookie;
  }
  this.queryURL = '/smg-pop-up/' + this.purfNID + '/user-status' + this.queryParameters;
};

/**
 * This function calls the triggerAction function, but it determines what values to pass to triggerAction.
 *
 * @param {Object} data
 * @param {Object} extra
 *
 * @param {{extraPURFs : Object}} data
 * @param {{reader_token : String}} data
 * @param {{sp_full_name : String}} data
 * @param {{missing_required : Array}} data
 * @param {{custom : Object}} data
 * @param {{unanswered : Array}} data.custom
 * @param {{standardQuestionsTotal : Number}} data
 * @param {{reader_token_value : String}} data
 * @param {{extra : Object}} data
 * @param {{columnLayoutOverride: String}} data
 */
PURFManager.prototype.manageActions = function (data, extra) {
  var extraPURFs = typeof extra !== 'undefined' ? extra : false;
  var userData = {};
  for (var key in data) {
    if (data.hasOwnProperty(key) && key !== "custom" && key !== "extraPURFs" && key !== "missing_required" && key !== "missing_required_custom") {
      userData[key] = data[key];
    }
  }

  if (extraPURFs && data.hasOwnProperty("extra")) {
    data = data.extra[this.key];
    for (var keyUserData in userData) {
      if (userData.hasOwnProperty(keyUserData)) {
        data[keyUserData] = userData[keyUserData];
      }
    }
  }

  // If the "Don't display PURF for Silverpop mailings" feature is enabled, and this _is_
  // a Silverpop mailing than force auto submission of purf
  if (this.purfSettings.hide_purf_spop_mailings && this.userID) {
    this.triggerAction('silverpopSubmit', this.popType, this.userID, false);
    return;
  }

  // Check if the reader_token is set
  if (!data.reader_token) {
    this.header = this.headerNew;
    if (!extraPURFs) {
      PURFManager.prototype.header = this.headerNew;
    }
    // Is the Silverpop user id provided as a URL parameter?
    if (this.userID) {
      // Get the user's full name, will be used in the layout defined at the bottom of this document
      spFullName = data.sp_full_name;
      // Are there any missing "required" questions (i.e. standard lead gen questions)?  If so, the data.missing_required property will be non-empty.
      // This includes dependency fields that are "visible".
      if (typeof data.missing_required != 'undefined') {
        // The smg_pop_up_missing_required cookie is used on the server in smg_pop_up_form_alter
        jQuery.cookie('smg_pop_up_missing_required', 1, { expires: purfDate, path: '/', domain: documentDomain });
        this.triggerAction(this.twoColumn, this.popType, false, false);
      } else {
        // Auto-submit IF there are no unanswered Custom questions
        if (jQuery(data.custom.unanswered).length === 0) {
          jQuery.cookie('spUserIDTrue', 1, { expires: purfDate, path: '/', domain: documentDomain }); // #TODO possibly delete
          this.triggerAction('silverpopSubmit', this.popType, this.userID, false);
        } else {
          // #TODO combine the conditionals below
          if (jQuery(data.custom.unanswered).length > 5) {
            //triggerAction(twoColumn, popType);
            this.triggerAction(this.oneColumn, this.popType, false, false);
          } else {
            purfLayoutType = 'one-column-layout'; // used in the Drupal.theme definition below (added to modal's css classes)
            this.triggerAction(this.oneColumn, this.popType, false, false);
          }
        }
      }
    }
    // reader_token not set, and there is no spuid in the url
    else {
        if (data.hasOwnProperty("columnLayoutOverride") && data.columnLayoutOverride === 'one_column') {
          this.triggerAction(this.oneColumn, this.popType, false, false);
        } else {
          this.triggerAction(this.twoColumn, this.popType, false, false);
        }
      }
  }
  // The else if below is true if the reader_token IS SET AND (EITHER there are unanswered custom question OR unanswered standard-lead gen questions)
  else if (data.reader_token && (data.hasOwnProperty('missing_required') || data.hasOwnProperty('missing_required_custom'))) {
      this.header = this.headerExist;
      if (!extraPURFs) {
        PURFManager.prototype.header = this.header;
      }
      if (data.hasOwnProperty('missing_required')) {
        // If one or more standard lead-gen questions are missing, we always show two column form
        if (data.hasOwnProperty("standardQuestionsTotal") && !data.hasOwnProperty("standardQuestionsVisibleDependentsTotal") && data.standardQuestionsTotal == data.missing_required.length && !data.hasOwnProperty("columnLayoutOverride")) {
          this.triggerAction(this.twoColumn, this.popType, false, false);
        } else {
          purfLayoutType = 'one-column-layout';
          this.triggerAction(this.oneColumn, this.popType, false, false);
        }
      } else if (data.hasOwnProperty('missing_required_custom')) {
        this.triggerAction(this.oneColumn, this.popType, false, false);
      }
    } else {
      var token = data.reader_token_value;
      this.triggerAction('readerTokenSubmit', this.popType, token, false);
    }
};

/**
 * This function implements the appropriate action based on the result of user-status query
 *
 * @param {jQuery|string} actionType
 *  - If we are auto-submitting, then this will either be readerTokenSubmit (when the reader_token is set) or silverpopSubmit (when spuid is in url)
 *  - If we are triggering a form pop-up, this will be either the the twoColumn jQuery object or the oneColumn jQuery object
 * @param {string} popType
 *  - The value should be either page_load, link_click or video_click.  In most cases, you can just pass in the popType variable that is set
 *    above.
 * @param {boolean|string} token
 *  - If we are auto submitting, then we should be passing in either the reader_token or the silverpop user Id.  Either ignore or set to false if not
 *    auto submitting
 * @param {boolean} override
 *  - Used to override the logic in hook_form_alter, to force the full form
 * @param {Array} extraPURFs
 *  - Either false if there is only one PURF on the page.  Or it contains an array of PURFManager objects
 */
PURFManager.prototype.triggerAction = function (actionType, popType, token, override) {
  // Set defaults for some parameters in case they weren't passed in, and other variables
  token = typeof token != 'undefined' ? token : false;
  override = typeof override != 'undefined' ? override : false;
  var submitType = actionType === 'readerTokenSubmit' || actionType === 'silverpopSubmit' ? actionType : false;
  var columnType = false;
  var _this = this;
  // Check to see if actionType is the two/one column jQuery object.  If so, set the columnType
  // let to a string value.
  if (actionType instanceof jQuery) {
    if (actionType.hasClass('ctools-modal-smg-pop-up-style-two-column') || actionType.hasClass('ctools-modal-smg-pop-up-640') || actionType.children().hasClass('ctools-modal-smg-pop-up-style-two-column') || actionType.children().hasClass('ctools-modal-smg-pop-up-640')) {
      columnType = 'twoColumn';
      purfLayoutType = 'two-column-layout';
    } else {
      columnType = 'oneColumn';
      purfLayoutType = 'one-column-layout';
    }
  }

  /**
   * Trigger click action on default PURF enabled link.  To be used for page load PURFs.
   * This function also checks if there are query parameters in the url, if so then it
   * rebuilds the Drupal Ajax object @see http://drupal.stackexchange.com/a/37217
   */
  var triggerActionClick = function triggerActionClick() {
    if (PURFGlobal.prototype.urlQuery) {
      var urlWithoutQuery = actionType.attr("href");
      var urlWithQuery = urlWithoutQuery + '?' + decodeURIComponent(jQuery.param(PURFGlobal.prototype.urlQuery));
      actionType.attr("href", urlWithQuery);
      var element_settings = { url: urlWithQuery, progress: { type: 'throbber' }, event: 'click' };
      Drupal.ajax[urlWithoutQuery] = new Drupal.ajax(urlWithoutQuery, actionType, element_settings);
      actionType.unbind('click');
      actionType.bind('click', function (event) {
        return Drupal.ajax[urlWithoutQuery].eventResponse(this, event);
      });
      actionType.trigger('click');
      return;
    }
    actionType.trigger('click');
  };

  if (popType === 'page_load') {
    if (submitType !== false) {
      _this.autoSubmit(submitType, token);
    } else {
      triggerActionClick();
    }
  } else if (popType === 'link_click') {
    jQuery.each(_this.purfSettings.pop_data.inlineLinks, function (index, value) {

      var uniqueId = index;
      var uniqueClass = '.purf-unique-' + uniqueId;
      // get the ad id
      var adId = value.adId;
      var valueLink = value;
      var uniqueURL = value.url ? value.protocol + value.url : false;
      var purfLayoutTypeClass = 'ctools-modal-smg-pop-up-style-two-column';
      var purfLayoutTypeClassRemove = 'ctools-modal-smg-pop-up-style-one-column';
      if (columnType) {
        if (columnType === 'twoColumn') {
          if (actionType.parent("#two-column-640").length) {
            purfLayoutTypeClass = 'ctools-modal-smg-pop-up-640';
          }
        } else if (columnType === 'oneColumn') {
          if (actionType.parent("#one-column-640").length) {
            purfLayoutTypeClass = 'ctools-modal-smg-pop-up-one-640';
            purfLayoutTypeClassRemove = 'ctools-modal-smg-pop-up-640';
          } else {
            purfLayoutTypeClass = 'ctools-modal-smg-pop-up-style-one-column';
            if (!purfOverrideOn) {
              purfLayoutTypeClassRemove = 'ctools-modal-smg-pop-up-style-two-column';
            }
          }
        }
      }
      jQuery(uniqueClass).addClass('ctools-use-modal-processed').addClass('ctools-use-modal').addClass(purfLayoutTypeClass).removeClass(purfLayoutTypeClassRemove).each(function () {

        // In case uniqueURL is false, create it using the href attribute of the PURF
        // enabled link.  uniqueURL usually won't be false, but sometimes it will, like
        // for OAS links - since we don't know the URL of the link until the page is rendered.
        if (!uniqueURL) {
          uniqueURL = jQuery(this).attr("href");
          valueLink.url = uniqueURL; // So we know where to redirect
        }

        if (submitType === false) {

          // #2317 Remove the href attribute from inline link PURFs, so users can't
          // bypass the PURF.  The value of href is stored in
          // Drupal.settings["smg-pop-up-settings"]["pop_data"].inlineLinks[purfLinkUniqueId].url
          jQuery(this).removeAttr("href").hover(function () {
            jQuery(this).css({ 'cursor': 'pointer' });
          });
          var element_settings = {};
          // The href attribute of actionType is the link to the modal build callback
          var modalCallback = '/smg-register/nojs/' + _this.purfSettings.webform_nid + '/' + _this.purfSettings.leadworks_id + '/' + _this.purfSettings.referer_nid;
          element_settings.url = modalCallback + '/' + adId + '/' + uniqueId;
          // Add additional parameters to URL
          var callbackParams = PURFGlobal.prototype.urlQuery ? PURFGlobal.prototype.urlQuery : {};
          if (_this.isExtra) {
            callbackParams.extra = true;
            callbackParams.key = uniqueId;
          }
          if (_this.purfSettings.hasOwnProperty("additional_leadworks_ids") && _this.purfSettings["additional_leadworks_ids"]) {
            if (_this.purfSettings['additional_leadworks_ids'].length) {
              callbackParams.additionalLwIds = _this.purfSettings['additional_leadworks_ids'].join();
            }
          }
          if (override) {
            callbackParams.override = true;
            jQuery(this).off('click').on('click', function () {
              purfOverrideOn = true;
              // Set the value as the inlineLinkInfo global param
              jqxhr.abort();
              PURFManager.prototype.inlineLinkInfo = {
                uniqueId: index,
                value: valueLink,
                settings: _this.purfSettings
              };
              PURFGlobal.prototype.header = _this.header;
            });
          } else {
            jQuery(this).off('click').on('click', function () {
              if (purfLayoutType === 'one-column-layout') {
                jQuery(this).removeClass('ctools-modal-smg-pop-up-style-two-column');
              }
              purfOverrideOn = false;
              // Set the value as the inlineLinkInfo global param
              jqxhr.abort();
              PURFManager.prototype.inlineLinkInfo = {
                uniqueId: index,
                value: valueLink,
                settings: _this.purfSettings
              };
              PURFGlobal.prototype.header = _this.header;
              if (_this.purfSettings.hasOwnProperty("disclaimer")) {
                PURFGlobal.prototype.disclaimer = _this.purfSettings.disclaimer;
              }
            });
          }
          if (!isEmpty(callbackParams)) {
            element_settings.url += '?' + decodeURIComponent(jQuery.param(callbackParams));
          }
          element_settings.progress = { type: "throbber" };
          element_settings.event = 'click';

          // Now we need to specify the base.  This should be an ID.  If one isn't
          // set for the current href, then we use the purf unique id
          var base;
          if (this.id) {
            base = jQuery(this).attr("id");
          } else {
            jQuery(this).attr("id", uniqueId);
            base = uniqueId;
          }

          Drupal.ajax[base] = new Drupal.ajax(base, this, element_settings);
        } else {
          var _base = jQuery(this).attr('href');
          if (Drupal.ajax.hasOwnProperty(_base)) {
            delete Drupal.ajax[_base];
          }
          jQuery(this).off('click').on('click', function (e) {

            var currentUrl = document.location.href;

            // #936
            if (_this.purfSettings.hasOwnProperty('silverpop_event')) {
              var silverpopEventType = _this.purfSettings.silverpop_event.event;
              var silverpopEventName = _this.purfSettings.silverpop_event.node_title;
              /**
               * @external ewt - Silverpop events
               * @property {Function} trackLink
               */
              ewt.trackLink({ name: silverpopEventName, type: silverpopEventType });
            }

            // Use all of jQuery's event override functions to be safe
            e.preventDefault();
            e.stopPropagation();
            e.stopImmediatePropagation();
            _this.autoSubmit(submitType, token, adId).success(function () {
              window.location.href = uniqueURL;

              // #936 In case we auto-submitted, the browser needs to refresh for any
              // silverpop cookies to register (for events to register).  But in case
              // the user navigates away from this page (in which case we'd lose the events),
              // we create an iframe that contains the current URL.  This has the same effect
              // (as far as creating cookies) as refreshing the page
              if (!window.hasOwnProperty('purfIframe')) {
                var frame = document.createElement("iframe");
                frame.src = currentUrl;
                jQuery(frame).css("display", "none");
                document.body.appendChild(frame);
                window.purfIframe = true;
              }
            });
          });
        }
      });
    });
  } else if (popType === 'video_click') {
    var viddlerId = this.viddlerId;
    if (viddlerId) {
      player = window.Viddler('viddler-' + viddlerId);

      // // This will take care of HTML5 Fallback Flash player, which works differently from Iframe
      // let playerStateTimer = setInterval(function(){
      //   if (typeof player.getPlayerState === 'function'){
      //     let playerState = player.getPlayerState();
      //     if (playerState === 3 || playerState === 1) {
      //       if (!viddlerVerified) {
      //         // If submitType is false, then we're not auto-submitting.  Therefore we prevent the video
      //         // from playing, and then trigger the appropriate form.
      //         if (submitType === false) {
      //           player.pauseVideo();
      //           triggerActionClick();
      //         }
      //         else {
      //           _this.autoSubmit(submitType, token).success(function(){
      //             viddlerVerified = true;
      //           });
      //         }
      //         clearInterval(playerStateTimer);
      //       }
      //     }
      //   }
      // }, 500);

      // // This takes care of when we're using HTML5 video player
      // htmlVideo = jQuery('.field-name-field-viddler-id video');
      // htmlVideo.on('play', function(event){
      //   htmlVideoElement = htmlVideo.get(0);
      //   if ( !viddlerVerified ) {
      //     // If submitType is false, then we're not auto-submitting.  Therefore we prevent the video
      //     // from playing, and then trigger the appropriate form.
      //     if ( submitType === false ) {
      //       htmlVideoElement.pause();
      //       triggerActionClick();
      //     }
      //     else {
      //       _this.autoSubmit(submitType, token).success(function(){
      //         viddlerVerified = true;
      //       });
      //     }
      //   }
      //   else {
      //     return;
      //   }
      // });

      // Add onStateChange event @see http://developers.viddler.com/documentation/chromeless/#toc-onstatechange
      // This will take care of Flash player when/if using an Iframe
      // Commented out the above code because we turned to using the iframe
      // code which is the recommended code to use.
      player.onStateChange(function (data) {
        if (data == 3 || data == 1) {
          // Check if we've verified the lead already on this page
          if (!viddlerVerified) {
            // If submitType is false, then we're not auto-submitting.  Therefore we prevent the video
            // from playing, and then trigger the appropriate form.
            if (submitType === false) {
              player.pauseVideo();
              triggerActionClick();
            } else {
              _this.autoSubmit(submitType, token).success(function () {
                viddlerVerified = true;
              });
            }
          } else {
            return;
          }
        }
      });
    }
  }
};

/**
 * Auto submits the user data
 *
 * @param {string} submitType This is either readerTokenSubmit or silverpopSubmit
 * @param {string} token Silverpop user id or Playbook Fields reader token
 * @param {string} adId The Leadworks ad ID
 * @returns {object} Result of AJAX call
 */
PURFManager.prototype.autoSubmit = function (submitType, token, adId) {
  // Set a cookie that indicates we're autosubmitting.  We check to see if this cookie is set
  // in the playbook_fields.module before we call the playbook_fields_set_cookie function
  jQuery.cookie('smg_pop_up_auto_submit', true, { expires: purfDate, path: '/', domain: documentDomain });

  var submitUrlString = submitType === 'readerTokenSubmit' ? 'reader_token' : 'silverpop';
  var nid = this.purfNID;
  // Get the nid of the referer node
  var refererNID = this.purfSettings.referer_nid;
  var leadworks = this.purfSettings.leadworks_id;
  var submitURL = '/smg-pop-up/auto-submit/' + token + '/' + nid + '/' + leadworks + '/' + refererNID + '/' + submitUrlString;

  // If popType is link_click, then don't automatically submit.  Just return the submitURL so we can attach it to an onclick event
  var params = PURFGlobal.prototype.urlQuery ? PURFGlobal.prototype.urlQuery : {};
  if (this.purfSettings.hasOwnProperty("additional_leadworks_ids") && this.purfSettings["additional_leadworks_ids"].length) {
    params.additionalLwIds = this.purfSettings['additional_leadworks_ids'].join();
  }
  if (this.popType === 'link_click' && typeof adId != 'undefined') {
    params.adId = adId;
  }
  if (this.isExtra) {
    params.extra = true;
    params.key = PURFManager.prototype.inlineLinkInfo.uniqueId;
  }
  if (Object.getOwnPropertyNames(params).length !== 0) {
    submitURL = submitURL + '?' + decodeURIComponent(jQuery.param(params));
  }
  return jQuery.ajax({
    url: submitURL
  });
};
'use strict';

/*jslint indent: 2 */
(function ($) {
  "use strict";

  // We set several cookies in the code below.  I want to create a Date object set to a 15 minutes
  // from when the page is loaded, as an expire time for the cookie.
  // @see http://stackoverflow.com/questions/1830246/how-to-expire-a-cookie-in-30-minutes-using-jquery

  var header = '',
      popType = false,
      htmlVideo = false,
      // This will hold the jQuery object representing the HTML5 video
  htmlVideoElement = false,
      // This will hold the actual DOM element contained within the above object
  htmlWidth = void 0;

  var is_touch_device = function is_touch_device() {
    return 'ontouchstart' in window // works on most browsers
    || 'onmsgesturechange' in window; // works on ie10
  };

  var isTouch = is_touch_device();

  /**
   *
   * Defines structure of Drupal.settings["smg-pop-up-settings-extra"]
   *
   * @name Drupal.settings["smg-pop-up-settings-extra"]
   * @property {String} webform_nid
   * @property {Array} custom_questions
   * @property {String} header_new_user
   * @property {String} header_exist_user
   * @property {Boolean} hide_purf_spop_mailings
   * @property {String} pop_type
   */

  var purfObj = new PURFManager();

  $(document).ready(function () {
    pageLoadAction();
    autoSilverpopEvent();
  });

  function pageLoadAction() {
    documentDomain = document.domain;
    if (documentDomain.indexOf('.www') !== -1) {
      documentDomain = documentDomain.substring(1); // Will use this when setting cookies
    }

    // Delete the spUserID cookie right away
    $.cookie('spUserID', null, { path: '/', domain: documentDomain });
    Cookies.remove('spUserID', { domain: '.' + documentDomain });
    Cookies.remove('spUserID');
    $.cookie('smg_pop_up_missing_required', null, { path: '/', domain: documentDomain });
    $.cookie('smg_pop_up_auto_submit', null, { path: '/', domain: documentDomain });

    var mainContentWidth = $('body #page #main').width(); // Get the window width
    htmlWidth = $('html').width();
    if (htmlWidth < mainContentWidth) {
      htmlWidth = mainContentWidth;
    }

    // Check to see if the 'smg-pop-up-settings' key is present in Drupal.settings.  If
    // it is, set some default values.
    // If it isn't then this page ONLY contains a separately added (or "extra") PURF.  If that's
    // the case, set the onlyExtraPurfs variable to true
    var onlyExtraPurfs = false;
    var twoColumnFull = void 0;
    var oneColumnFull = void 0;
    var twoColumn640 = void 0;
    var oneColumn640 = void 0;
    if (typeof Drupal.settings["smg-pop-up-settings"] !== 'undefined') {

      purfObj.addParameters(Drupal.settings["smg-pop-up-settings"].webform_nid, Drupal.settings["smg-pop-up-settings"].custom_questions);

      purfObj.purfSettings = Drupal.settings["smg-pop-up-settings"];

      // Get the jQuery objects for the two-column and one-column ctools-modal links
      twoColumnFull = $('#smg-pop-up-hidden-links #two-column a.ctools-use-modal');
      oneColumnFull = $('#smg-pop-up-hidden-links #one-column a.ctools-use-modal');
      twoColumn640 = $('#smg-pop-up-hidden-links #two-column-640 a.ctools-use-modal');
      oneColumn640 = $('#smg-pop-up-hidden-links #one-column-640 a.ctools-use-modal');

      popType = Drupal.settings["smg-pop-up-settings"].pop_type;
      purfObj.popType = popType;

      // Check for Viddler Id in the settings
      purfObj.viddlerId = typeof Drupal.settings["smg-pop-up-settings"].viddler_id !== 'undefined' ? Drupal.settings["smg-pop-up-settings"].viddler_id : false;

      if (!Drupal.settings["smg-pop-up-settings"].referredUser) {
        purfObj.purfSettings.referredUser = false;
      }

      PURFGlobal.prototype.header = Drupal.settings["smg-pop-up-settings"].header_new_user; // Header New
      PURFGlobal.prototype.headerNew = Drupal.settings["smg-pop-up-settings"].header_new_user; // Header New
      PURFGlobal.prototype.headerExist = Drupal.settings["smg-pop-up-settings"].header_exist_user;

      if (Drupal.settings["smg-pop-up-settings"].disclaimer) {
        PURFGlobal.prototype.disclaimer = Drupal.settings["smg-pop-up-settings"].disclaimer;
      }
    } else {
      onlyExtraPurfs = true;
      var ctoolsModalLinkFull = $('<a></a>').addClass('ctools-use-modal').addClass('ctools-modal-smg-pop-up-style-two-column');
      var ctoolsModalLinkFullOne = $('<a></a>').addClass('ctools-use-modal').addClass('ctools-modal-smg-pop-up-640');
      var ctoolsModalLink = $('<a></a>').addClass('ctools-use-modal');
      twoColumnFull = $('<div></div>').attr('id', 'two-column');
      oneColumnFull = $('<div></div>').attr('id', 'one-column');
      twoColumn640 = $('<div></div>').attr('id', 'two-column-640').append(ctoolsModalLink);
      oneColumn640 = $('<div></div>').attr('id', 'one-column-640').append(ctoolsModalLink);
      twoColumnFull.append(ctoolsModalLinkFull);
      oneColumn640.append(ctoolsModalLinkFullOne);
      twoColumn640.append(ctoolsModalLink);
      oneColumn640.append(ctoolsModalLink);
      popType = 'link_click';
      purfObj.popType = popType;

      purfObj.purfSettings = {
        'referredUser': false
      };
    }

    var twoColumn = twoColumnFull;
    var oneColumn = oneColumnFull;

    // If device width less than 640, change viewport so that minimum scale is 1.  Also, modify the ctools-modal link
    // objects declared above to point to the 640 width links
    var deviceWidth = $(window).width();
    if (deviceWidth < 640) {
      var viewport = document.querySelector("meta[name=viewport]");
      viewport.setAttribute('content', 'initial-scale=1.0, width=device-width, minimum-scale=1.0, maximum-scale=1.0, user-scalable=yes');
      twoColumn = twoColumn640;
      oneColumn = oneColumn640;
    } else if (deviceWidth < 770) {
      Drupal.settings["smg-pop-up-style-two-column"].modalSize.width = 0.9;
    }

    // Store twoColumn and oneColumn in global object
    PURFGlobal.prototype.twoColumn = twoColumn;
    PURFGlobal.prototype.oneColumn = oneColumn;

    // Get query parameter data from url and store it
    var query_string = {};
    var query = window.location.search.substring(1);
    if (query.length) {
      var vars = query.split("&");
      for (var i = 0; i < vars.length; i++) {
        var pair = vars[i].split("=");
        query_string[pair[0]] = decodeURIComponent(pair[1]);
      }
    }
    PURFGlobal.prototype.urlQuery = query.length ? query_string : false;

    // Look for the reader_token cookie.  If it isn't set, look for the silvepop user ID in the url
    var readerTokenCookie = $.cookie('reader_token');
    if (!readerTokenCookie) {
      if ("spUserID" in query_string && !purfObj.purfSettings.referredUser) {
        var userID = query_string.spUserID;
        PURFManager.prototype.userID = userID;
        Cookies.set('spUserID', userID, { expires: purfDate });
        Cookies.set('spUserID', userID, { domain: '.' + documentDomain, expires: purfDate });
      }
    } else {
      PURFGlobal.prototype.readerTokenCookie = readerTokenCookie;
    }

    // #2345 Look for PURF links that point to a second (or third, fourth, ...) PURF
    var extraPURFs = false;
    if (Drupal.settings.hasOwnProperty("smg-pop-up-settings-extra")) {
      var extraPurf = { "ext": {} };
      for (var key in Drupal.settings["smg-pop-up-settings-extra"]) {
        if (Drupal.settings["smg-pop-up-settings-extra"].hasOwnProperty(key)) {
          var obj = Drupal.settings["smg-pop-up-settings-extra"][key];
          extraPurf.ext[key] = {
            "key": key,
            "nid": obj.webform_nid,
            "cust": obj.custom_questions
          };
        }
      }

      purfObj.extraQuestions = extraPurf;

      extraPURFs = [];
      $.each(Drupal.settings["smg-pop-up-settings-extra"], function (index, value) {
        extraPURFs[index] = new PURFManager();
        extraPURFs[index].header = value.header_new_user;
        extraPURFs[index].headerNew = value.header_new_user;
        extraPURFs[index].headerExist = value.header_exist_user;
        extraPURFs[index].purfSettings = value;
        extraPURFs[index].purfNID = value.webform_nid;
        extraPURFs[index].popType = 'link_click';
        extraPURFs[index].key = index;
        extraPURFs[index].isExtra = true;
      });
    }

    purfObj.createQueryURL();

    var showPURF = true;

    // Below, we account for situations where the user clicks a PURF link BEFORE the
    // user-status AJAX call has returned.  So we show the full form by default, unless
    // the user-status call returns and overrides.
    if (popType === 'link_click' && !onlyExtraPurfs) {
      if (!$('.ctools-use-modal').length) {
        showPURF = false;
      } else {
        header = purfObj.header;
        purfObj.triggerAction(purfObj.twoColumn, purfObj.popType, false, true);
      }
    }
    if (extraPURFs) {
      for (var keyExtraPURF in extraPURFs) {
        if (extraPURFs.hasOwnProperty(keyExtraPURF)) {
          extraPURFs[keyExtraPURF].triggerAction(extraPURFs[keyExtraPURF].twoColumn, extraPURFs[keyExtraPURF].popType, false, true);
        }
      }
    }

    if (showPURF) {
      jqxhr = $.getJSON(purfObj.queryURL, function (data) {
        Drupal.settings.purfUserStatus = data;

        if (Drupal.settings.hasOwnProperty("smg-pop-up-settings")) {

          // Check if the smg-pop-up-settings.layout_type property is set to "one_column"
          // (this is not likely, but if it is the case then set the purfObj.twoColumn prop
          // to point to the oneColumn object
          if (Drupal.settings["smg-pop-up-settings"].hasOwnProperty("layout_type") && Drupal.settings["smg-pop-up-settings"].layout_type === 'one_column') {
            data.columnLayoutOverride = 'one_column';
          }

          purfObj.manageActions(data);
        }

        if (extraPURFs) {
          for (var _key in extraPURFs) {
            if (extraPURFs.hasOwnProperty(_key)) {
              extraPURFs[_key].manageActions(data, true);
            }
          }
        }
      });
    }
  }

  /**
   * Checks for spopEvent url query parameter.  Fires off silverpop event if necessary.
   */
  function autoSilverpopEvent() {
    var urlQuery = PURFGlobal.prototype.urlQuery;
    if (urlQuery && "spopEvent" in urlQuery) {
      var uniqueLinkId = urlQuery.spopEvent;
      if (uniqueLinkId in Drupal.settings["smg-pop-up-settings-extra"]) {
        var linkSettings = Drupal.settings["smg-pop-up-settings-extra"][uniqueLinkId];
        if (!linkSettings.hasOwnProperty('silverpop_event') || !linkSettings.silverpop_event.hasOwnProperty('event')) {
          return;
        }
        var silverpopEvent = linkSettings.silverpop_event,
            silverpopEventType = silverpopEvent.event,
            silverpopEventName = silverpopEvent.node_title;
        try {
          ewt.trackLink({ name: silverpopEventName, type: silverpopEventType });
        } catch (e) {
          console.log(e.message);
        }
      }
    }
  }

  // All of the Drupal.ajax.prototype.commands.*** functions below are called in smg_register_modal_build in smg_pop_up.module

  /**
   * The runValidationDependencyJS function will be added to the Drupal.ajax namespace.  It will be used as an ajax callback that runs the javascript
   * validation and dependency code.  This code must be supplied as a string (it will be attached to the response object), and it must be a set
   * of executable javascript/jquery expressions i.e. - $('#id').doSomething(); $('#id2').doSomethingElse();
   * To understand why I am running the validation/dependency javascript code in an ajax callback function, please read:
   * http:*www.jaypan.com/tutorial/calling-function-after-ajax-event-drupal-7.
   * To sum it up: normally on webforms on our sites, we implement the jQuery UI Multiselect code and our custom validation javascript by
   * adding it to the page with jQuery(document).ready().  This won't work for modal displays because they're rendered with an ajax callback,
   * hence after the document loads.  So I need to execute our javascript after the modal renders, by adding the function below as an ajax
   * callback, which I'm doing in the smg_register_modal_build function in smg_pop_up.module
   */
  Drupal.ajax.prototype.commands.runValidationDependencyJS = function (ajax, response, status) {
    var js = response.js;

    // Since the javascript expressions are provided as a string, I need to use special syntax to make them executable.  Please refer to:
    // http://stackoverflow.com/questions/1271516/executing-anonymous-functions-created-using-javascript-eval
    // http://stackoverflow.com/questions/939326/execute-javascript-code-stored-as-a-string
    var func = new Function('$', js);
    func(jQuery);
  };

  Drupal.ajax.prototype.commands.runPurfSilverpopEventJS = function (ajax, response, status) {
    var js = response.js;
    var func = new Function('$', js);
    func(jQuery);
  };

  // When the modal closes, IF the modal was generated by a link-click (as opposed to on page load), we redirect to the original href destination
  Drupal.ajax.prototype.commands.smgPopRedirect = function (ajax, response, status) {
    var inlineLinkInfo = PURFManager.prototype.inlineLinkInfo,
        linkSettings = inlineLinkInfo.settings,
        purfLinkUniqueId = inlineLinkInfo.uniqueId,
        linkObject = inlineLinkInfo.value,
        protocol = linkObject.hasOwnProperty('protocol') && linkObject.protocol.length > 1 ? linkObject.protocol : '',
        linkObjURL = linkObject.url.indexOf('summitmediagroup.com') >= 0 && linkObject.url.indexOf('www') === -1 ? 'www.' + linkObject.url : linkObject.url,
        originalLink = protocol + linkObjURL;
    window.location.href = originalLink;

    // Set timeout to refresh the page.  If should only occur when the external link redirected to above is
    // really a download - hence the page never redirected.  The refresh will cause the 'user status' logic to
    // rerun taking into account the previously submitted form.  This isn't a particularly elegant solution,
    // should be rewritten.
    setTimeout(function () {
      // #936
      var currentLocation = document.location.href,
          additionalParams = {};
      if (linkSettings.hasOwnProperty('silverpop_event') && linkSettings.silverpop_event.hasOwnProperty('event')) {
        additionalParams.spopEvent = purfLinkUniqueId;
      }

      if (!isEmpty(additionalParams)) {
        currentLocation += '?' + decodeURIComponent(jQuery.param(additionalParams));
      }

      window.location.href = currentLocation;
    }, 3000);
  };

  // When the modal loads, look for the jQuery UI Multiselect widgets and move them into the ctools modal.  Also, we dynamically modify the width
  // of the dropdown, and it's x,y pos
  Drupal.ajax.prototype.commands.moveMultiWidgets = function (ajax, response, status) {
    $('body > .ui-multiselect-menu').each(function () {
      $(this).appendTo('#modalContent #modal-content');
    });
  };

  // When the modal closes, this function cleans up cookies, and if popType is video_click, it plays the viddler video
  Drupal.ajax.prototype.commands.smgCloseModal = function (ajax, response, status) {

    var body = $('body');
    body.removeClass('purf-open').addClass('purf-closed');

    $.cookie('spUserID', null, { path: '/', domain: documentDomain });
    $.cookie('smg_pop_up_missing_required', null, { path: '/', domain: documentDomain });
    if (popType === 'video_click') {
      var videoOffset = $('div.field-name-field-viddler-id').length ? $('div.field-name-field-viddler-id').offset().top : 40;
      $("html, body").animate({ scrollTop: videoOffset - 150 }, 800);
      if (player) {
        try {
          player.playVideo();
        } catch (err) {}
      }
      if (htmlVideo) {
        if (typeof htmlVideoElement.play === 'function') {
          htmlVideoElement.play();
        }
      }
      viddlerVerified = true;
    }
  };

  Drupal.ajax.prototype.commands.modifyModalDimensions = function (ajax, response, status) {

    // Perform some manipulations to the font-size to try to get a consistent styling between sites
    var body = $('body'),
        bodyFontSize = body.css("font-size"),
        modalContent = $('#modalContent'),
        siteWindow = $(window);

    if (bodyFontSize.indexOf("px") !== -1) {
      var bodyFontSizeInt = Number(bodyFontSize.substring(0, bodyFontSize.indexOf("px")));
      if (bodyFontSizeInt === 15) {
        body.css({ 'font-size': '100%' });
        modalContent.css({ 'font-size': '75%' });
      }
    }

    body.removeClass('purf-closed').addClass('purf-open');

    var formHeight = modalContent.find('.webform-client-form').height();

    if (formHeight < $(window).height() * .72 && purfLayoutType !== 'two-column-layout') {
      $('div.ctools-modal-content .modal-content').css({ 'height': 'auto' });
      $('div.ctools-modal-content').css({ 'height': 'auto', 'padding-bottom': '13px' });
    }

    if (Drupal.settings.pmgGlobal.siteId == 'aw') {
      $("html, body").animate({ scrollTop: 0 }, "slow");
      modalContent.css({ 'top': '40px' });

      var initialHeight = siteWindow.height() * .8;

      modalContent.css({ 'height': initialHeight });

      if (purfLayoutType == 'two-column-layout') {
        $('div.ctools-modal-content').css({ 'width': siteWindow.width() * .65 });
        modalContent.css({ 'left': '17.5%' });
      }

      $(".modal-content button.form-submit").replaceWith("<div class='form-actions'><input class='webform-submit button-primary form-submit' type='submit' name='op' value='Submit'></div>");
    } else {
      var winHeight = $(window).height();
      var distance = winHeight / 2 - modalContent.outerHeight() / 2;
      modalContent.css({ top: distance });
    }

    $.each([50, 100, 1000, 2000, 3000, 4000, 5000, 6000], function (index, value) {
      var windowWidthCheck = void 0,
          modalContentWidthCheck = void 0,
          newWidth = void 0;
      setTimeout(function () {
        windowWidthCheck = $(window).width();
        modalContentWidthCheck = modalContent.outerWidth();
        newWidth = windowWidthCheck / 2 - modalContentWidthCheck / 2;
        modalContent.css({ 'left': newWidth });
      }, value);
    });

    if (popType === 'video_click' || popType === 'link_click') {
      if (!isTouch) {
        $("html, body").animate({ scrollTop: 0 }, 100);
        modalContent.animate({ top: '40px' }, 100);
      }
    }

    if (htmlWidth < 1030 && htmlWidth > 640) {
      var resizeModalNewWidth = 0.9 * htmlWidth;
      modalContent.css({ 'font-size': '100%', 'left': htmlWidth * 0.05 });
      setTimeout(function () {
        $('.ctools-modal-content').animate({ width: resizeModalNewWidth }, 1200);
      }, 1000);
    }

    // Set the modalBackdrop height to 100% of the page
    var docHeight = $(document).height();
    setTimeout(function () {
      $('#modalBackdrop').css({ 'height': docHeight });
    }, 900);
    setTimeout(function () {
      var timeoutDocHeight = docHeight = $(document).height();
      $('#modalBackdrop').css({ 'height': timeoutDocHeight });
    }, 1900);
  };

  // When the modal loads we dynamically modify the width of the multiselect widget dropdown, as well as its x,y position
  Drupal.behaviors.modifyModalElementDimensions = {
    attach: function attach(context, settings) {

      var multiSelectIsOpen = false,
          modalContent = $("#modalContent"),
          siteWindow = $(window);

      if (Drupal.settings.pmgGlobal.siteId == 'aw') {

        $("html, body").animate({ scrollTop: 0 }, "slow");
        modalContent.css({ 'top': '40px' });

        if (purfLayoutType == 'two-column-layout') {
          $('div.ctools-modal-content').css({ 'width': siteWindow.width() * .65 });
          modalContent.css({ 'left': '17.5%' });
        }
      }

      $("#modalBackdrop").css({ 'height': siteWindow.height() + 100 });

      var windowWidth = $(window).width(); // Get the window width
      var htmlWidth = $('html').width();
      if (htmlWidth < windowWidth) {
        htmlWidth.css({ 'width': windowWidth });
      }
      var moveRequired = function moveRequired() {
        // Move the required-field text above the submit button (i.e. "* Indicates a required field").  This either has
        // done in javascript, or at some point in the form rendering process (or in the form template).  I'm doing it
        // in js now b/c it's easier and quicker
        var requiredNote = $('#smg-pop-up-required-note');
        if (purfLayoutType === 'two-column-layout' && windowWidth > 640) {
          requiredNote.css({ 'display': 'inline', 'position': 'absolute' });
          var formActions = modalContent.find(".form-actions");
          if (formActions.find(requiredNote).length) {
            formActions.prepend(requiredNote);
            $('div.ctools-modal-content').find('.modal-content').find(requiredNote).css({ 'display': 'inline', 'position': 'absolute' });
            $('.webform-client-form > div').not('.form-actions').find("> #smg-pop-up-required-note").remove();
          } else {
            formActions.prepend(requiredNote);
            $('div.ctools-modal-content').find('.modal-content').find(requiredNote).css({ 'display': 'inline', 'position': 'absolute' });
            $('.webform-client-form').find("> #smg-pop-up-required-note").remove();
          }
        }
      };
      //moveRequired();

      $(document).ready(function () {
        //setTimeout(moveRequired,500);
      });

      // @todo needs cleanup below.  many unused vars.

      var modifyModalHeight = function modifyModalHeight(addHeight) {

        // If one-column-layout make sure it's at least as long as its contents
        if (purfLayoutType === 'one-column-layout') {
          // One more check to make sure everything fits
          var innerContentsHeight = $('.modal-header').outerHeight() + $('.modal-scroll').outerHeight() + $('#modalContent .disclaimer').outerHeight();

          var newModalHeight = $('#modalContent').height();
          if (innerContentsHeight > newModalHeight) {
            $('#modalContent, .ctools-modal-content').css({ 'height': innerContentsHeight + 5 + 'px' });
          } else {
            $('.ctools-modal-content, #modal-content').css({ 'height': 'auto' });
          }
        }

        if (windowWidth > 640 && purfLayoutType !== 'one-column-layout') {
          $('.ctools-modal-content').css({ 'height': 'auto', 'padding-bottom': '15px' });
          $('#modal-content').css({ 'height': 'auto', 'padding-bottom': '15px' });
        }

        if (windowWidth > 640) {
          if (purfLayoutType !== 'one-column-layout') {
            if ($('.ctools-modal-content > .clear').length === 0) {
              $('.ctools-modal-content').append('<div class="clear"></div>');
              $('.ctools-modal-content .clear').css({ 'clear': 'both' });
            }
            if ($('#modal-content > .clear').length === 0) {
              $('#modal-content').append('<div class="clear"></div>');
              $('#modal-content .clear').css({ 'clear': 'both' });
            }
            if ($('.popups-container > .clear').length === 0) {
              $('.popups-container').append('<div class="clear"></div>');
              $('.popups-container .clear').css({ 'clear': 'both' });
            }
          }
        }

        if (!modalContent.length) return;
        if (modalContent.height() - 150 < $(document).height()) {
          //let newBodyHeight = $('#modalContent').height() + 300;
          //$('body, #modalBackdrop').css({'height': newBodyHeight + 'px'});
        }
      };
      setTimeout(modifyModalHeight, 1000);

      var modalEvents = $._data($(window)[0], "events");
      if (modalEvents && modalEvents.hasOwnProperty("resize")) {
        // Unbind the CTools modal resize event handler which breaks everything
        var resizeEvents = modalEvents.resize;
        for (var rE in resizeEvents) {
          if (resizeEvents.hasOwnProperty(rE)) {
            if (resizeEvents[rE].hasOwnProperty("handler")) {
              var handler = resizeEvents[rE].handler;
              var funcToString = handler.toString();
              if (funcToString.indexOf("Drupal.CTools.Modal.currentSettings") > -1) {
                $(window).unbind("resize", handler);
              }
            }
          }
        }
      }

      $(window).on('resize', function () {
        modifyModalHeight();
      });

      // Function for determining if browser is IE and if so what version, used below in
      // msieChangeWidth to make some css adjustments
      function msieversion() {
        var ua = window.navigator.userAgent;
        var msieV = ua.indexOf("MSIE ");
        if (msieV > 0) {
          // If Internet Explorer, return version number
          return parseInt(ua.substring(msieV + 5, ua.indexOf(".", msieV)));
        } else {
          // If another browser, return 0
          return false;
        }
      }

      var msie = msieversion();
      var msie9 = false;
      var msie8 = false;
      if (msie && msie === 9) {
        msie9 = true;
      } else if (msie === 8) {
        msie8 = true;
      }

      // If the webform returns a validation error, call the modifyModalHeight function again because
      // that adds to the height of the form.  If msie = 8, add extra height
      if ($('#modal-content').find('.messages.error').length) {
        if (!msie8) {
          modifyModalHeight(45);
        } else {
          var ie8FormHeight = $('#modalContent .webform-client-form').height();
          $('#modalContent .webform-client-form').css({ 'height': ie8FormHeight + 45 + 'px' });
          setTimeout(function () {
            modifyModalHeight(80);
          }, 2000);
        }
      }

      var msieChangeWidth = function msieChangeWidth() {
        if (msie9 || msie8) {
          var newWidth = void 0;
          var newLeft = void 0;
          if (windowWidth > 640 && purfLayoutType === 'two-column-layout') {
            newWidth = windowWidth * .64;
            newWidth = Math.round(newWidth);
            modalContent.css({ 'width': newWidth + 'px' });
            modalContent.find('.smg-pop-up-column').css({ 'width': '50%' });
            newLeft = (windowWidth - newWidth) / 2;
            newLeft = Math.round(newLeft);
            modalContent.css({ 'position': 'absolute', 'left': newLeft + 'px' });
          } else if (windowWidth > 640 && purfLayoutType === 'one-column-layout') {
            newWidth = windowWidth * .38;
            newWidth = Math.round(newWidth);
            modalContent.css({ 'width': newWidth + 'px' });

            newLeft = (windowWidth - newWidth) / 2;
            newLeft = Math.round(newLeft);
            modalContent.css({ 'position': 'absolute', 'left': newLeft + 'px' });
          }
        }
      };

      msieChangeWidth();

      /*let intervalHandle = window.setInterval(removeCToolsResize, 100);
      function removeCToolsResize () {
        if (typeof(modalContentResize) == "function") {
          window.clearInterval(intervalHandle);
          $(window).unbind('resize',  modalContentResize);
          setTimeout(function () { modalContentResize() }, 100);
        }
      }*/

      var htmlOverflowDefault = $('html').css('overflow');
      var modifyWidgets = function modifyWidgets() {
        $('.smg-pop-up-element.select select', context).each(function () {

          $(this).multiselect();

          // Get the multiselect button for this select element using multiselect method (http://www.erichynds.com/blog/jquery-ui-multiselect-widget)
          var button = $(this).multiselect('getButton');
          button.css('width', '100%');

          // Below, we modify the position of the menu relative to the button.  The jQuery UI Multiselect library
          // has its own function that I use directly below (ie multiselect("option","position", {...})).  However, I
          // also repeat (redo) the operation using jQuery's native position() function.  On a desktop browser, the Multiselect
          // function is sufficient.  However, to get it to work on mobile, I needed to use both the multiselect fct and
          // jQuery's position fct (not sure why, but it doesn't seem to affect performance in any way)
          $(this).multiselect("option", "position", { my: "left top", at: "left bottom", of: button, collision: "none" });
          var widget = $(this).multiselect('widget');

          // Set some variables @todo maybe delete
          var scrollTop = $(window).scrollTop(),
              elementOffset = modalContent.length ? modalContent.offset().top : 0,
              distance = elementOffset - scrollTop;
          widget.position({ my: "left top", at: "left bottom", of: button, collision: "none" });
          var buttonWidth = button.width();
          // set the width of the widget
          $(this).multiselect('widget').width(buttonWidth);

          widget.on("multiselectbeforeopen", function (event, ui) {
            // Even though we set the width of the multiselect popup above, that didn't account
            // for questions that are shown conditionally (i.e. the buttons have 0 width when the
            // document initially loads) so we set the width again just before the multiselect popup
            // opens.
            var buttonBeforeOpenWidth = $(this).multiselect('getButton').width();
            $(this).multiselect('widget').width(buttonBeforeOpenWidth);
          });

          $(this).on("multiselectopen", function (event, ui) {
            if (isTouch) {
              return;
            }
            scrollTop = $(window).scrollTop();
            elementOffset = modalContent.length ? modalContent.offset().top : 0;
            var winHeight = $(window).height();
            distance = winHeight / 2 - modalContent.outerHeight() / 2;
            var currentWidget = $(this);
            if (!$(this).hasClass('ui-multiselect-menu')) {
              try {
                currentWidget = $(this).multiselect('widget');
                var _currentWidgetUl = currentWidget.children("ul");
              } catch (err) {}
            }
            var widgetOffset = currentWidget.offset().top;
            var widgetDistanceFromTop = widgetOffset - scrollTop;
            var bottomOfVisibleWindow = $(window).height();
            var widgetDistanceToBottom = bottomOfVisibleWindow - widgetDistanceFromTop;
            currentWidgetUl.css({ 'max-height': widgetDistanceToBottom - 15 });
            multiSelectIsOpen = true;
            //modalContent.css({'position':'fixed', 'top':distance});

            //$('body').css({'overflow':'hidden'});
            //$('html').css({'overflow':'hidden'});
          });
          $(this).on("multiselectclose", function (event, ui) {
            if (isTouch) {
              return;
            }
            multiSelectIsOpen = false;
            var winHeight = $(window).height();
            distance = winHeight / 2 - modalContent.outerHeight() / 2;
            //modalContent.css({'position':'absolute', 'top':distance});
            $('body').css({ 'overflow': 'visible' });
            $('html').css({ 'overflow': htmlOverflowDefault });
          });
        });
      };
      modifyWidgets();
      setTimeout(modifyWidgets, 500);
      setTimeout(modifyWidgets, 1000);

      $(window).load(function () {

        modifyWidgets();

        // To be safe, I call the modifyWidgets fct several times
        setTimeout(modifyWidgets, 2000);
        setTimeout(modifyWidgets, 5000);
        setTimeout(modifyWidgets, 15000);
        setTimeout(modifyWidgets, 25000);
        setTimeout(modifyWidgets, 45000);

        var labelSize = function labelSize() {
          if ($(window).width() < 640) {
            $('div.ctools-modal-content .modal-content .form-item.webform-component > label, div.ctools-modal-content .modal-content .form-item.webform-component > label .form-required').each(function () {
              $(this, context).css('font-size', '12px');
              $(this, context).css('-webkit-text-size-adjust', '12px');
            });
          }
        };

        labelSize();
        setTimeout(labelSize, 3000);
        setTimeout(labelSize, 8000);
        setTimeout(labelSize, 11000);

        $(window).on("orientationchange", function (event) {

          var deviceWidth = $(window).width();
          if (deviceWidth < 640) {
            var viewport = document.querySelector("meta[name=viewport]");
            viewport.setAttribute('content', 'initial-scale=1.0, width=device-width, minimum-scale=1.0, maximum-scale=1.0, user-scalable=yes');
          }

          modifyWidgets();

          labelSize();

          if (window.orientation === 90) {
            setTimeout(function () {
              var modalHeight = $('#modal-content').outerHeight();
              if ($('#modal-content').height() !== modalHeight + 25) {
                $('#modal-content').css({ 'height': modalHeight + 25 + 'px' });
              }
            }, 500);
          } else {
            $(window).scrollLeft(0);
          }
        });
      }); // end $(window).load
    }
  };

  /**
   * Provide the HTML to create the modal dialog
   */
  Drupal.theme.prototype.smg_pop_up_modal = function () {
    var headerHTML = void 0;
    if (PURFGlobal.prototype.header) {
      headerHTML = '<span class="modal-header-text">' + PURFGlobal.prototype.header + '</span>';
    }

    var disclaimer = PURFGlobal.prototype.disclaimer;
    var disclaimerHTML = '';
    if (disclaimer) {
      disclaimerHTML = '<div class="disclaimer"><span class="disclaimer-text">This content is sponsored by the supplier.  Your contact information may be shared with this sponsor, as detailed in our Privacy Policy.  Your contact information will not be shared with a sponsor whose content you have not reviewed.</span></div>';
    }

    if (purfOverrideOn) {
      purfLayoutType = 'two-column-layout';
    }

    var fullNameHTML = '';
    if (spFullName) {

      $(document.body).on('click', 'a#not-sp-user', function (e) {
        e.preventDefault();
        Drupal.CTools.Modal.modal_dismiss();
        // get cookie value
        $.cookie('spUserID', null, { path: '/', domain: documentDomain });
        var url = location.protocol + '//' + location.host + location.pathname;
        window.location = url;
      });

      var link = $("<a />", {
        id: "not-sp-user",
        name: "not-sp-user",
        href: "#",
        text: "Click here."
      });
      var linkString = link.wrapAll('<div>').parent().html();
      fullNameHTML = '<div id="sp-full-name-wrapper"><span id="sp-full-name">Not ' + spFullName + '?  ' + linkString + '</span></div>';
    }

    var windowWidth = $(window).width();
    var windowWidthClass = void 0;
    if (windowWidth >= 640) {
      windowWidthClass = 'min-640';
    } else {
      windowWidthClass = 'max-640';
    }

    var html = '';
    html += '<div id="ctools-modal" class="popups-box">';
    html += '  <div class="ctools-modal-content ctools-sample-modal-content ' + purfLayoutType + ' ' + windowWidthClass + '">';
    html += '    <div class="popups-container">';
    html += '      <div class="modal-header popups-title">';
    html += '        <span id="modal-title" class="modal-title"></span>' + headerHTML + fullNameHTML;
    html += '      </div>';
    html += '      <div class="modal-scroll"><div id="modal-content" class="modal-content popups-body"></div></div>';
    html += '      <div class="clearfix"></div>';
    html += '    </div>';
    html += disclaimerHTML;
    html += '    <div class="clearfix"></div>';
    html += '  </div>';
    return html;
  };
})(jQuery);
'use strict';

(function ($) {
  /**
   * modalContent
   * @param content string to display in the content box
   * @param css obj of css attributes
   * @param animation (fadeIn, slideDown, show)
   * @param speed (valid animation speeds slow, medium, fast or # in ms)
   */
  Drupal.CTools.Modal.modalContent = function (content, css, animation, speed) {
    // If our animation isn't set, make it just show/pop
    if (!animation) {
      animation = 'show';
    } else {
      // If our animation isn't "fadeIn" or "slideDown" then it always is show
      if (animation != 'fadeIn' && animation != 'slideDown') {
        animation = 'show';
      }
    }

    if (!speed) {
      speed = 'fast';
    }

    // Build our base attributes and allow them to be overriden
    css = jQuery.extend({
      position: 'absolute',
      left: '0px',
      margin: '0px',
      background: '#000',
      opacity: '.55'
    }, css);

    // Add opacity handling for IE.
    css.filter = 'alpha(opacity=' + 100 * css.opacity + ')';
    content.hide();

    // If we already have modalContent, remove it.
    if ($('#modalBackdrop').length) $('#modalBackdrop').remove();
    if ($('#modalContent').length) $('#modalContent').remove();

    // position code lifted from http://www.quirksmode.org/viewport/compatibility.html
    if (self.pageYOffset) {
      // all except Explorer
      var wt = self.pageYOffset;
    } else if (document.documentElement && document.documentElement.scrollTop) {
      // Explorer 6 Strict
      var wt = document.documentElement.scrollTop;
    } else if (document.body) {
      // all other Explorers
      var wt = document.body.scrollTop;
    }

    // Get our dimensions

    // Get the docHeight and (ugly hack) add 50 pixels to make sure we dont have a *visible* border below our div
    var docHeight = $(document).height() + 50;
    var docWidth = $(document).width();
    var winHeight = $(window).height();
    var winWidth = $(window).width();
    if (docHeight < winHeight) docHeight = winHeight;

    // Create our divs
    $('body').append('<div id="modalBackdrop" style="z-index: 1000; display: none;"></div><div id="modalContent" style="z-index: 1001; position: absolute;">' + $(content).html() + '</div>');

    // Keyboard and focus event handler ensures focus stays on modal elements only
    var modalEventHandler = function modalEventHandler(event) {
      var target = null;
      if (event) {
        //Mozilla
        target = event.target;
      } else {
        //IE
        event = window.event;
        target = event.srcElement;
      }

      var parents = $(target).parents().get();
      for (var i = 0; i < parents.length; ++i) {
        var position = $(parents[i]).css('position');
        if (position == 'absolute' || position == 'fixed') {
          return true;
        }
      }

      if ($(target).is('#modalContent, body') || $(target).filter('*:visible').parents('#modalContent').length) {
        // Allow the event only if target is a visible child node
        // of #modalContent.
        return true;
      } else {
        $('#modalContent').focus();
      }

      event.preventDefault();
    };
    $('body').bind('focus', modalEventHandler);
    $('body').bind('keypress', modalEventHandler);
    window.modalEventHandler = modalEventHandler;

    // Create our content div, get the dimensions, and hide it
    var modalContent = $('#modalContent').css('top', '-1000px');
    var mdcTop = wt + winHeight / 2 - modalContent.outerHeight() / 2;
    if (mdcTop < wt) {
      mdcTop = wt + 100;
    }
    var mdcLeft = winWidth / 2 - modalContent.outerWidth() / 2;
    $('#modalBackdrop').css(css).css('top', 0).css('height', docHeight + 'px').css('width', docWidth + 'px').show();
    modalContent.css({ top: mdcTop + 'px', left: mdcLeft + 'px' }).hide()[animation](speed);

    // Bind a click for closing the modalContent
    var modalContentClose = function modalContentClose() {
      close();
      return false;
    };
    $('.close').bind('click', modalContentClose);
    window.modalContentClose = modalContentClose;

    // Bind a keypress on escape for closing the modalContent
    var modalEventEscapeCloseHandler = function modalEventEscapeCloseHandler(event) {
      if (event.keyCode == 27) {
        close();
        return false;
      }
    };
    $(document).bind('keydown', modalEventEscapeCloseHandler);
    window.modalEventEscapeCloseHandler = modalEventEscapeCloseHandler;

    // Close the open modal content and backdrop
    function close() {
      // Unbind the events
      $(window).unbind('resize', modalContentResize);
      $('body').unbind('focus', modalEventHandler);
      $('body').unbind('keypress', modalEventHandler);
      $('.close').unbind('click', modalContentClose);
      $('body').unbind('keypress', modalEventEscapeCloseHandler);
      $(document).trigger('CToolsDetachBehaviors', $('#modalContent'));

      // Set our animation parameters and use them
      if (animation == 'fadeIn') animation = 'fadeOut';
      if (animation == 'slideDown') animation = 'slideUp';
      if (animation == 'show') animation = 'hide';

      // Close the content
      modalContent.hide()[animation](speed);

      // Remove the content
      $('#modalContent').remove();
      $('#modalBackdrop').remove();
    };

    // Move and resize the modalBackdrop and modalContent on resize of the window
    var modalContentResize = function modalContentResize() {

      // position code lifted from http://www.quirksmode.org/viewport/compatibility.html
      if (self.pageYOffset) {
        // all except Explorer
        var wt = self.pageYOffset;
      } else if (document.documentElement && document.documentElement.scrollTop) {
        // Explorer 6 Strict
        var wt = document.documentElement.scrollTop;
      } else if (document.body) {
        // all other Explorers
        var wt = document.body.scrollTop;
      }

      // Get our heights
      var docHeight = $(document).height();
      var docWidth = $(document).width();
      var winHeight = $(window).height();
      var winWidth = $(window).width();
      if (docHeight < winHeight) docHeight = winHeight;

      // Get where we should move content to
      var modalContent = $('#modalContent');
      var mdcTop = wt + winHeight / 2 - modalContent.outerHeight() / 2;
      if (mdcTop < wt) {
        mdcTop = wt + 100;
      }
      var mdcLeft = winWidth / 2 - modalContent.outerWidth() / 2;

      // Apply the changes
      $('#modalBackdrop').css('height', docHeight + 'px').css('width', docWidth + 'px').show();
      modalContent.css('top', mdcTop + 'px').css('left', mdcLeft + 'px').show();
    };
    $(window).bind('resize', modalContentResize);
    window.modalContentResize = modalContentResize;

    $('#modalContent').focus();
  };
})(jQuery);
}());
