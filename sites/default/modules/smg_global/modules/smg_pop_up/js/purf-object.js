/**
 * Defines PURF object constructor
 * @file purf-object.js
 */

let spFullName = false,
  purfDate = new Date(),
  // If popType is video_click, we use the viddlerVerified variable to track when the user presses play.
  // Once we've tracked the lead (i.e. they fill out the form or we auto-submit), we set the value to true.
  viddlerVerified = false,
  // If popType is video_click, the following variables will be instantiated (which one
  // depends on whether or not the browser supports flash player)
  player = false,
  purfOverrideOn = false,
  jqxhr,
  documentDomain,
  purfLayoutType = 'two-column-layout';

purfDate.setTime(purfDate.getTime() + (15 * 60 * 1000));

function isEmpty(obj) {
  let key;
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
  this.purfNID = (typeof purfNID !== 'undefined') ? purfNID : 'FALSE';
  this.customQuestions = (typeof customQuestions !== 'undefined') ? customQuestions : this.customQuestions;
};

PURFManager.prototype.addQueryParameters = function () { return true; }; // The "return true" is to suppress jslint error @todo delete fct?

// Add function to purfManager object that will generate query URLs
PURFManager.prototype.createQueryURL = function () {

  let custom = '',
    extra = '',
    extParams,
    rCookie = '',
    rCookieQuery;

  if (this.customQuestions.length) {
    custom = 'custQ[]=' + this.customQuestions.join("&custQ[]=");
  }
  if (this.extraQuestions.hasOwnProperty("ext")) {
    extParams = decodeURIComponent(jQuery.param(this.extraQuestions));
    extra = (custom.length) ? '&' + extParams : extParams;
  }
  if (this.readerTokenCookie) {
    rCookieQuery = 'rCookie=' + this.readerTokenCookie;
    rCookie = (custom.length || extra.length) ? '&' + rCookieQuery : rCookieQuery;
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
  let extraPURFs = (typeof extra !== 'undefined') ? extra : false;
  let userData = {};
  for (let key in data) {
    if (data.hasOwnProperty(key) &&
      key !== "custom" &&
      key !== "extraPURFs" &&
      key !== "missing_required" &&
      key !== "missing_required_custom") {
      userData[key] = data[key];
    }
  }

  if (extraPURFs && data.hasOwnProperty("extra")) {
    data = data.extra[this.key];
    for (let keyUserData in userData) {
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
    if ( this.userID ) {
      // Get the user's full name, will be used in the layout defined at the bottom of this document
      spFullName = data.sp_full_name;
      // Are there any missing "required" questions (i.e. standard lead gen questions)?  If so, the data.missing_required property will be non-empty.
      // This includes dependency fields that are "visible".
      if ( typeof data.missing_required != 'undefined' ){
        // The smg_pop_up_missing_required cookie is used on the server in smg_pop_up_form_alter
        jQuery.cookie('smg_pop_up_missing_required', 1, {expires: purfDate, path: '/', domain: documentDomain});
        this.triggerAction( this.twoColumn, this.popType, false, false );
      }
      else {
        // Auto-submit IF there are no unanswered Custom questions
        if ( jQuery(data.custom.unanswered).length === 0 ){
          jQuery.cookie('spUserIDTrue', 1, {expires: purfDate, path: '/', domain: documentDomain}); // #TODO possibly delete
          this.triggerAction( 'silverpopSubmit', this.popType, this.userID, false );
        }
        else {
          // #TODO combine the conditionals below
          if( jQuery(data.custom.unanswered).length > 5 ){
            //triggerAction(twoColumn, popType);
            this.triggerAction( this.oneColumn, this.popType, false, false );
          }
          else {
            purfLayoutType = 'one-column-layout'; // used in the Drupal.theme definition below (added to modal's css classes)
            this.triggerAction( this.oneColumn, this.popType, false, false );
          }
        }
      }
    }
    // reader_token not set, and there is no spuid in the url
    else {
      if (data.hasOwnProperty("columnLayoutOverride") && data.columnLayoutOverride === 'one_column') {
        this.triggerAction(this.oneColumn, this.popType, false, false);
      }
      else {
        this.triggerAction(this.twoColumn, this.popType, false, false);
      }
    }
  }
  // The else if below is true if the reader_token IS SET AND (EITHER there are unanswered custom question OR unanswered standard-lead gen questions)
  else if (data.reader_token && (data.hasOwnProperty('missing_required') || data.hasOwnProperty('missing_required_custom'))){
    this.header = this.headerExist;
    if (!extraPURFs) {
      PURFManager.prototype.header = this.header;
    }
    if (data.hasOwnProperty('missing_required')) {  // If one or more standard lead-gen questions are missing, we always show two column form
      if (data.hasOwnProperty("standardQuestionsTotal")
        && !data.hasOwnProperty("standardQuestionsVisibleDependentsTotal")
        && data.standardQuestionsTotal == data.missing_required.length
        && !data.hasOwnProperty("columnLayoutOverride")) {
        this.triggerAction(this.twoColumn, this.popType, false, false);
      }
      else {
        purfLayoutType = 'one-column-layout';
        this.triggerAction(this.oneColumn, this.popType, false, false);
      }
    }
    else if (data.hasOwnProperty('missing_required_custom')) {
      this.triggerAction(this.oneColumn, this.popType, false, false);
    }
  }
  else {
    let token = data.reader_token_value;
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
PURFManager.prototype.triggerAction = function (actionType, popType, token, override){
  // Set defaults for some parameters in case they weren't passed in, and other variables
  token = typeof token != 'undefined' ? token : false;
  override = typeof override != 'undefined' ? override : false;
  let submitType = (actionType === 'readerTokenSubmit' || actionType === 'silverpopSubmit') ? actionType : false;
  let columnType = false;
  let _this = this;
  // Check to see if actionType is the two/one column jQuery object.  If so, set the columnType
  // let to a string value.
  if (actionType instanceof jQuery) {
    if (actionType.hasClass('ctools-modal-smg-pop-up-style-two-column') || actionType.hasClass('ctools-modal-smg-pop-up-640') || actionType.children().hasClass('ctools-modal-smg-pop-up-style-two-column') || actionType.children().hasClass('ctools-modal-smg-pop-up-640')) {
      columnType = 'twoColumn';
      purfLayoutType = 'two-column-layout';
    }
    else {
      columnType = 'oneColumn';
      purfLayoutType = 'one-column-layout';
    }
  }

  /**
   * Trigger click action on default PURF enabled link.  To be used for page load PURFs.
   * This function also checks if there are query parameters in the url, if so then it
   * rebuilds the Drupal Ajax object @see http://drupal.stackexchange.com/a/37217
   */
  let triggerActionClick = function () {
    if (PURFGlobal.prototype.urlQuery) {
      let urlWithoutQuery = actionType.attr("href");
      let urlWithQuery = urlWithoutQuery + '?' + decodeURIComponent( jQuery.param( PURFGlobal.prototype.urlQuery ) );
      actionType.attr("href", urlWithQuery);
      let element_settings = {url: urlWithQuery, progress: {type: 'throbber'}, event: 'click'};
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
    }
    else {
      triggerActionClick();
    }
  }
  else if (popType === 'link_click') {
    jQuery.each(_this.purfSettings.pop_data.inlineLinks, function(index, value){

      let uniqueId = index;
      let uniqueClass = '.purf-unique-' + uniqueId;
      // get the ad id
      let adId = value.adId;
      let valueLink = value;
      let uniqueURL = (value.url) ? value.protocol + value.url : false;
      let purfLayoutTypeClass = 'ctools-modal-smg-pop-up-style-two-column';
      let purfLayoutTypeClassRemove = 'ctools-modal-smg-pop-up-style-one-column';
      if (columnType) {
        if (columnType === 'twoColumn') {
          if (actionType.parent("#two-column-640").length) {
            purfLayoutTypeClass = 'ctools-modal-smg-pop-up-640';
          }
        }
        else if (columnType === 'oneColumn') {
          if (actionType.parent("#one-column-640").length) {
            purfLayoutTypeClass = 'ctools-modal-smg-pop-up-one-640';
            purfLayoutTypeClassRemove = 'ctools-modal-smg-pop-up-640';
          }
          else {
            purfLayoutTypeClass = 'ctools-modal-smg-pop-up-style-one-column';
            if (!purfOverrideOn) {
              purfLayoutTypeClassRemove = 'ctools-modal-smg-pop-up-style-two-column';
            }
          }
        }
      }
      jQuery(uniqueClass)
        .addClass('ctools-use-modal-processed')
        .addClass('ctools-use-modal')
        .addClass(purfLayoutTypeClass)
        .removeClass(purfLayoutTypeClassRemove)
        .each(function(){

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
            jQuery(this).removeAttr("href").hover(function(){
              jQuery(this).css({'cursor':'pointer'});
            });
            let element_settings = {};
            // The href attribute of actionType is the link to the modal build callback
            let modalCallback = '/smg-register/nojs/' + _this.purfSettings.webform_nid + '/' + _this.purfSettings.leadworks_id + '/' + _this.purfSettings.referer_nid;
            element_settings.url = modalCallback + '/' + adId + '/' + uniqueId;
            // Add additional parameters to URL
            let callbackParams = (PURFGlobal.prototype.urlQuery) ? PURFGlobal.prototype.urlQuery : {};
            if ( _this.isExtra ) {
              callbackParams.extra = true;
              callbackParams.key = uniqueId;
            }
            if ( _this.purfSettings.hasOwnProperty("additional_leadworks_ids") && _this.purfSettings["additional_leadworks_ids"] ) {
              if ( _this.purfSettings['additional_leadworks_ids'].length ) {
                callbackParams.additionalLwIds = _this.purfSettings['additional_leadworks_ids'].join();
              }
            }
            if ( override ) {
              callbackParams.override = true;
              jQuery(this).off('click').on('click', function(){
                purfOverrideOn = true;
                // Set the value as the inlineLinkInfo global param
                jqxhr.abort();
                PURFManager.prototype.inlineLinkInfo = {
                  uniqueId : index,
                  value : valueLink,
                  settings: _this.purfSettings
                };
                PURFGlobal.prototype.header = _this.header;
              });
            }
            else {
              jQuery(this).off('click').on('click', function(){
                if ( purfLayoutType === 'one-column-layout' ) {
                  jQuery(this).removeClass('ctools-modal-smg-pop-up-style-two-column');
                }
                purfOverrideOn = false;
                // Set the value as the inlineLinkInfo global param
                jqxhr.abort();
                PURFManager.prototype.inlineLinkInfo = {
                  uniqueId : index,
                  value : valueLink,
                  settings: _this.purfSettings
                };
                PURFGlobal.prototype.header = _this.header;
                if ( _this.purfSettings.hasOwnProperty("disclaimer") ){
                  PURFGlobal.prototype.disclaimer = _this.purfSettings.disclaimer;
                }
              });
            }
            if ( !isEmpty(callbackParams) ) {
              element_settings.url += '?' + decodeURIComponent( jQuery.param(callbackParams) );
            }
            element_settings.progress = {type:"throbber"};
            element_settings.event = 'click';

            // Now we need to specify the base.  This should be an ID.  If one isn't
            // set for the current href, then we use the purf unique id
            var base;
            if ( this.id ) {
              base = jQuery(this).attr("id");
            }
            else {
              jQuery(this).attr("id", uniqueId);
              base = uniqueId;
            }

            Drupal.ajax[base] = new Drupal.ajax(base, this, element_settings);
          }
          else {
            let base = jQuery(this).attr('href');
            if (Drupal.ajax.hasOwnProperty(base)) {
              delete Drupal.ajax[base];
            }
            jQuery(this).off('click').on('click', function(e){

              let currentUrl = document.location.href;

              // #936
              if (_this.purfSettings.hasOwnProperty('silverpop_event')) {
                let silverpopEventType = _this.purfSettings.silverpop_event.event;
                let silverpopEventName = _this.purfSettings.silverpop_event.node_title;
                /**
                 * @external ewt - Silverpop events
                 * @property {Function} trackLink
                 */
                ewt.trackLink({name:silverpopEventName, type:silverpopEventType});
              }

              // Use all of jQuery's event override functions to be safe
              e.preventDefault();
              e.stopPropagation();
              e.stopImmediatePropagation();
              _this.autoSubmit( submitType, token, adId ).success(function(){
                window.location.href = uniqueURL;

                // #936 In case we auto-submitted, the browser needs to refresh for any
                // silverpop cookies to register (for events to register).  But in case
                // the user navigates away from this page (in which case we'd lose the events),
                // we create an iframe that contains the current URL.  This has the same effect
                // (as far as creating cookies) as refreshing the page
                if (!window.hasOwnProperty('purfIframe')) {
                  let frame = document.createElement("iframe");
                  frame.src = currentUrl;
                  jQuery(frame).css("display","none");
                  document.body.appendChild(frame);
                  window.purfIframe = true;
                }
              });
            });
          }
        });
    });
  }
  else if ( popType === 'video_click' ) {
    let viddlerId = this.viddlerId;
    if ( viddlerId ) {
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
      player.onStateChange(function(data)
      {
        if (data == 3 || data == 1) {
          // Check if we've verified the lead already on this page
          if (!viddlerVerified) {
            // If submitType is false, then we're not auto-submitting.  Therefore we prevent the video
            // from playing, and then trigger the appropriate form.
            if (submitType === false) {
              player.pauseVideo();
              triggerActionClick();
            }
            else {
              _this.autoSubmit(submitType, token).success(function(){
                viddlerVerified = true;
              });
            }
          }
          else {
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
PURFManager.prototype.autoSubmit = function( submitType, token, adId ) {
  // Set a cookie that indicates we're autosubmitting.  We check to see if this cookie is set
  // in the playbook_fields.module before we call the playbook_fields_set_cookie function
  jQuery.cookie('smg_pop_up_auto_submit', true, {expires: purfDate, path: '/', domain: documentDomain});

  let submitUrlString = ( submitType === 'readerTokenSubmit' ) ? 'reader_token' : 'silverpop';
  let nid = this.purfNID;
  // Get the nid of the referer node
  let refererNID = this.purfSettings.referer_nid;
  let leadworks = this.purfSettings.leadworks_id;
  let submitURL = '/smg-pop-up/auto-submit/' + token + '/' + nid + '/' + leadworks + '/' + refererNID + '/' + submitUrlString;

  // If popType is link_click, then don't automatically submit.  Just return the submitURL so we can attach it to an onclick event
  let params = ( PURFGlobal.prototype.urlQuery ) ? PURFGlobal.prototype.urlQuery : {};
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
    submitURL = submitURL + '?' + decodeURIComponent( jQuery.param( params ) );
  }
  return jQuery.ajax({
    url: submitURL
  });
};

