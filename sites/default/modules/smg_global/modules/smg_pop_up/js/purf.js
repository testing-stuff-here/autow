/*jslint indent: 2 */
(function ($) {
  "use strict";

  // We set several cookies in the code below.  I want to create a Date object set to a 15 minutes
  // from when the page is loaded, as an expire time for the cookie.
  // @see http://stackoverflow.com/questions/1830246/how-to-expire-a-cookie-in-30-minutes-using-jquery
  let header = '',
    popType = false,
    htmlVideo = false, // This will hold the jQuery object representing the HTML5 video
    htmlVideoElement = false, // This will hold the actual DOM element contained within the above object
    htmlWidth;

  let is_touch_device = () => {
    return 'ontouchstart' in window // works on most browsers
      || 'onmsgesturechange' in window; // works on ie10
  };

  let isTouch = is_touch_device();

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

  let purfObj = new PURFManager();

  $(document).ready(() => {
    pageLoadAction();
    autoSilverpopEvent();
  });

  function pageLoadAction() {
    documentDomain = document.domain;
    if (documentDomain.indexOf('.www') !== -1) {
      documentDomain = documentDomain.substring(1); // Will use this when setting cookies
    }

    // Delete the spUserID cookie right away
    $.cookie('spUserID', null, {path: '/', domain: documentDomain});
    Cookies.remove('spUserID', {domain: '.' + documentDomain});
    Cookies.remove('spUserID');
    $.cookie('smg_pop_up_missing_required', null, {path: '/', domain: documentDomain});
    $.cookie('smg_pop_up_auto_submit', null, {path: '/', domain: documentDomain});

    let mainContentWidth = $('body #page #main').width(); // Get the window width
    htmlWidth = $('html').width();
    if ( htmlWidth < mainContentWidth ){
      htmlWidth = mainContentWidth;
    }

    // Check to see if the 'smg-pop-up-settings' key is present in Drupal.settings.  If
    // it is, set some default values.
    // If it isn't then this page ONLY contains a separately added (or "extra") PURF.  If that's
    // the case, set the onlyExtraPurfs variable to true
    let onlyExtraPurfs = false;
    let twoColumnFull;
    let oneColumnFull;
    let twoColumn640;
    let oneColumn640;
    if ( typeof Drupal.settings["smg-pop-up-settings"] !== 'undefined' ){

      purfObj.addParameters(
        Drupal.settings["smg-pop-up-settings"].webform_nid,
        Drupal.settings["smg-pop-up-settings"].custom_questions
      );

      purfObj.purfSettings = Drupal.settings["smg-pop-up-settings"];

      // Get the jQuery objects for the two-column and one-column ctools-modal links
      twoColumnFull = $('#smg-pop-up-hidden-links #two-column a.ctools-use-modal');
      oneColumnFull = $('#smg-pop-up-hidden-links #one-column a.ctools-use-modal');
      twoColumn640 = $('#smg-pop-up-hidden-links #two-column-640 a.ctools-use-modal');
      oneColumn640 = $('#smg-pop-up-hidden-links #one-column-640 a.ctools-use-modal');

      popType = Drupal.settings["smg-pop-up-settings"].pop_type;
      purfObj.popType = popType;

      // Check for Viddler Id in the settings
      purfObj.viddlerId = (typeof Drupal.settings["smg-pop-up-settings"].viddler_id !== 'undefined') ? Drupal.settings["smg-pop-up-settings"].viddler_id : false;

      if ( !Drupal.settings["smg-pop-up-settings"].referredUser ) {
        purfObj.purfSettings.referredUser = false;
      }

      PURFGlobal.prototype.header = Drupal.settings["smg-pop-up-settings"].header_new_user; // Header New
      PURFGlobal.prototype.headerNew = Drupal.settings["smg-pop-up-settings"].header_new_user; // Header New
      PURFGlobal.prototype.headerExist = Drupal.settings["smg-pop-up-settings"].header_exist_user;

      if ( Drupal.settings["smg-pop-up-settings"].disclaimer ) {
        PURFGlobal.prototype.disclaimer = Drupal.settings["smg-pop-up-settings"].disclaimer;
      }

    }
    else {
      onlyExtraPurfs = true;
      let ctoolsModalLinkFull = $('<a></a>').addClass('ctools-use-modal').addClass('ctools-modal-smg-pop-up-style-two-column');
      let ctoolsModalLinkFullOne = $('<a></a>').addClass('ctools-use-modal').addClass('ctools-modal-smg-pop-up-640');
      let ctoolsModalLink = $('<a></a>').addClass('ctools-use-modal');
      twoColumnFull = $('<div></div>').attr('id','two-column');
      oneColumnFull = $('<div></div>').attr('id','one-column');
      twoColumn640 = $('<div></div>').attr('id','two-column-640').append(ctoolsModalLink);
      oneColumn640 = $('<div></div>').attr('id','one-column-640').append(ctoolsModalLink);
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

    let twoColumn = twoColumnFull;
    let oneColumn = oneColumnFull;

    // If device width less than 640, change viewport so that minimum scale is 1.  Also, modify the ctools-modal link
    // objects declared above to point to the 640 width links
    let deviceWidth = $(window).width();
    if ( deviceWidth < 640 ){
      let viewport = document.querySelector("meta[name=viewport]");
      viewport.setAttribute('content', 'initial-scale=1.0, width=device-width, minimum-scale=1.0, maximum-scale=1.0, user-scalable=yes');
      twoColumn = twoColumn640;
      oneColumn = oneColumn640;
    }
    else if ( deviceWidth < 770 ) {
      Drupal.settings["smg-pop-up-style-two-column"].modalSize.width = 0.9;
    }

    // Store twoColumn and oneColumn in global object
    PURFGlobal.prototype.twoColumn = twoColumn;
    PURFGlobal.prototype.oneColumn = oneColumn;

    // Get query parameter data from url and store it
    let query_string = {};
    let query = window.location.search.substring(1);
    if ( query.length ) {
      let vars = query.split("&");
      for (let i = 0; i < vars.length; i++) {
        let pair = vars[i].split("=");
        query_string[pair[0]] = decodeURIComponent(pair[1]);
      }
    }
    PURFGlobal.prototype.urlQuery = ( query.length ) ? query_string : false;

    // Look for the reader_token cookie.  If it isn't set, look for the silvepop user ID in the url
    let readerTokenCookie = $.cookie('reader_token');
    if (!readerTokenCookie) {
      if ( "spUserID" in query_string && !purfObj.purfSettings.referredUser ) {
        let userID = query_string.spUserID;
        PURFManager.prototype.userID = userID;
        Cookies.set('spUserID', userID, {expires:purfDate});
        Cookies.set('spUserID', userID, {domain: '.' + documentDomain, expires: purfDate});
      }
    }
    else {
      PURFGlobal.prototype.readerTokenCookie = readerTokenCookie;
    }

    // #2345 Look for PURF links that point to a second (or third, fourth, ...) PURF
    let extraPURFs = false;
    if (Drupal.settings.hasOwnProperty("smg-pop-up-settings-extra")){
      let extraPurf = {"ext":{}};
      for (let key in Drupal.settings["smg-pop-up-settings-extra"]) {
        if (Drupal.settings["smg-pop-up-settings-extra"].hasOwnProperty(key)) {
          let obj = Drupal.settings["smg-pop-up-settings-extra"][key];
          extraPurf.ext[key] = {
            "key" : key,
            "nid" : obj.webform_nid,
            "cust" : obj.custom_questions
          };
        }
      }

      purfObj.extraQuestions = extraPurf;

      extraPURFs = [];
      $.each(Drupal.settings["smg-pop-up-settings-extra"], function(index, value){
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

    let showPURF = true;

    // Below, we account for situations where the user clicks a PURF link BEFORE the
    // user-status AJAX call has returned.  So we show the full form by default, unless
    // the user-status call returns and overrides.
    if (popType === 'link_click' && !onlyExtraPurfs){
      if (!$( '.ctools-use-modal' ).length){
        showPURF = false;
      }
      else {
        header = purfObj.header;
        purfObj.triggerAction(purfObj.twoColumn, purfObj.popType, false, true);
      }
    }
    if (extraPURFs) {
      for (let keyExtraPURF in extraPURFs) {
        if (extraPURFs.hasOwnProperty(keyExtraPURF)) {
          extraPURFs[keyExtraPURF].triggerAction(extraPURFs[keyExtraPURF].twoColumn, extraPURFs[keyExtraPURF].popType, false, true);
        }
      }
    }

    if (showPURF) {
      jqxhr = $.getJSON( purfObj.queryURL, function (data) {
        Drupal.settings.purfUserStatus = data;

        if (Drupal.settings.hasOwnProperty("smg-pop-up-settings")) {

          // Check if the smg-pop-up-settings.layout_type property is set to "one_column"
          // (this is not likely, but if it is the case then set the purfObj.twoColumn prop
          // to point to the oneColumn object
          if (Drupal.settings["smg-pop-up-settings"].hasOwnProperty("layout_type") && Drupal.settings["smg-pop-up-settings"].layout_type === 'one_column') {
            data.columnLayoutOverride = 'one_column';
          }

          purfObj.manageActions( data );
        }

        if (extraPURFs) {
          for (let key in extraPURFs) {
            if (extraPURFs.hasOwnProperty( key )) {
              extraPURFs[key].manageActions( data, true );
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
    let urlQuery = PURFGlobal.prototype.urlQuery;
    if (urlQuery && "spopEvent" in urlQuery) {
      let uniqueLinkId = urlQuery.spopEvent;
      if (uniqueLinkId in Drupal.settings["smg-pop-up-settings-extra"]) {
        let linkSettings = Drupal.settings["smg-pop-up-settings-extra"][uniqueLinkId];
        if (!linkSettings.hasOwnProperty('silverpop_event') || !linkSettings.silverpop_event.hasOwnProperty('event')) {
          return;
        }
        let silverpopEvent = linkSettings.silverpop_event,
          silverpopEventType = silverpopEvent.event,
          silverpopEventName = silverpopEvent.node_title;
        try {
          ewt.trackLink({name:silverpopEventName, type:silverpopEventType});
        }
        catch (e) {
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
    let js = response.js;

    // Since the javascript expressions are provided as a string, I need to use special syntax to make them executable.  Please refer to:
    // http://stackoverflow.com/questions/1271516/executing-anonymous-functions-created-using-javascript-eval
    // http://stackoverflow.com/questions/939326/execute-javascript-code-stored-as-a-string
    let func = new Function('$', js);
    func(jQuery);
  };

  Drupal.ajax.prototype.commands.runPurfSilverpopEventJS = function(ajax, response, status) {
    let js = response.js;
    let func = new Function('$', js);
    func(jQuery);
  };


  // When the modal closes, IF the modal was generated by a link-click (as opposed to on page load), we redirect to the original href destination
  Drupal.ajax.prototype.commands.smgPopRedirect = function (ajax, response, status){
    let inlineLinkInfo = PURFManager.prototype.inlineLinkInfo,
      linkSettings = inlineLinkInfo.settings,
      purfLinkUniqueId = inlineLinkInfo.uniqueId,
      linkObject = inlineLinkInfo.value,
      protocol = (linkObject.hasOwnProperty('protocol') && linkObject.protocol.length > 1) ? linkObject.protocol : '',
      linkObjURL = (linkObject.url.indexOf('summitmediagroup.com') >= 0 && linkObject.url.indexOf('www') === -1) ? ('www.' + linkObject.url) : linkObject.url,
      originalLink = protocol + linkObjURL;
    window.location.href = originalLink;

    // Set timeout to refresh the page.  If should only occur when the external link redirected to above is
    // really a download - hence the page never redirected.  The refresh will cause the 'user status' logic to
    // rerun taking into account the previously submitted form.  This isn't a particularly elegant solution,
    // should be rewritten.
    setTimeout(function() {
      // #936
      let currentLocation = document.location.href,
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
    $('body > .ui-multiselect-menu').each(function(){
      $(this).appendTo('#modalContent #modal-content');
    });
  };

  // When the modal closes, this function cleans up cookies, and if popType is video_click, it plays the viddler video
  Drupal.ajax.prototype.commands.smgCloseModal = function( ajax, response, status ) {

    let body = $('body');
    body.removeClass('purf-open').addClass('purf-closed');

    $.cookie('spUserID', null, {path: '/', domain: documentDomain});
    $.cookie('smg_pop_up_missing_required', null, {path: '/', domain: documentDomain});
    if (popType === 'video_click') {
      let videoOffset = ($('div.field-name-field-viddler-id').length) ? $('div.field-name-field-viddler-id').offset().top : 40;
      $("html, body").animate({ scrollTop: (videoOffset - 150) }, 800);
      if (player) {
        try{
          player.playVideo();
        }
        catch(err) {

        }
      }
      if (htmlVideo) {
        if (typeof htmlVideoElement.play === 'function') {
          htmlVideoElement.play();
        }
      }
      viddlerVerified = true;
    }
  };

  Drupal.ajax.prototype.commands.modifyModalDimensions = function(ajax, response, status){

    // Perform some manipulations to the font-size to try to get a consistent styling between sites
    let body = $('body'),
      bodyFontSize = body.css("font-size"),
      modalContent = $('#modalContent'),
      siteWindow = $(window);

    if (bodyFontSize.indexOf("px") !== -1) {
      let bodyFontSizeInt = Number(bodyFontSize.substring(0, bodyFontSize.indexOf("px")));
      if (bodyFontSizeInt === 15) {
        body.css({'font-size':'100%'});
        modalContent.css({'font-size':'75%'});
      }
    }

    body.removeClass('purf-closed').addClass('purf-open');

    let formHeight = modalContent.find('.webform-client-form').height();

    if (formHeight < ( $(window).height() * .72 ) && purfLayoutType !== 'two-column-layout') {
      $('div.ctools-modal-content .modal-content').css({'height' : 'auto'});
      $('div.ctools-modal-content').css({'height' : 'auto', 'padding-bottom' : '13px'});
    }

    if (Drupal.settings.pmgGlobal.siteId == 'aw') {
      $("html, body").animate({ scrollTop: 0 }, "slow");
      modalContent.css({'top':'40px'});

      let initialHeight= siteWindow.height() * .8;

      modalContent.css({'height': initialHeight});

      if (purfLayoutType == 'two-column-layout') {
        $('div.ctools-modal-content').css({'width': (siteWindow.width() * .65)});
        modalContent.css({'left':'17.5%'});
      }

      $(".modal-content button.form-submit").replaceWith("<div class='form-actions'><input class='webform-submit button-primary form-submit' type='submit' name='op' value='Submit'></div>");
    }
    else {
      let winHeight = $(window).height();
      let distance = ( winHeight / 2 ) - ( modalContent.outerHeight() / 2);
      modalContent.css({top: distance});
    }

    $.each([50, 100, 1000, 2000, 3000, 4000, 5000, 6000], function (index, value) {
      let windowWidthCheck,
        modalContentWidthCheck,
        newWidth;
      setTimeout(function () {
        windowWidthCheck = $(window).width();
        modalContentWidthCheck = modalContent.outerWidth();
        newWidth = (windowWidthCheck / 2) - (modalContentWidthCheck / 2);
        modalContent.css({'left':newWidth});
      }, value);
    });

    if (popType === 'video_click' || popType === 'link_click') {
      if (!isTouch) {
        $("html, body").animate({ scrollTop: 0 }, 100);
        modalContent.animate({top:'40px'}, 100);
      }
    }

    if (htmlWidth < 1030 && htmlWidth > 640) {
      let resizeModalNewWidth = 0.9 * htmlWidth;
      modalContent.css({'font-size':'100%', 'left':(htmlWidth * 0.05)});
      setTimeout(function(){
        $('.ctools-modal-content').animate({ width:resizeModalNewWidth}, 1200);
      },1000);
    }

    // Set the modalBackdrop height to 100% of the page
    let docHeight = $(document).height();
    setTimeout(function(){
      $('#modalBackdrop').css({'height':docHeight});
    }, 900);
    setTimeout(function(){
      let timeoutDocHeight = docHeight = $(document).height();
      $('#modalBackdrop').css({'height':timeoutDocHeight});
    }, 1900);

  };

  // When the modal loads we dynamically modify the width of the multiselect widget dropdown, as well as its x,y position
  Drupal.behaviors.modifyModalElementDimensions = {
    attach: function (context, settings) {

      let multiSelectIsOpen = false,
        modalContent = $("#modalContent"),
        siteWindow = $(window);

      if (Drupal.settings.pmgGlobal.siteId == 'aw') {

        $("html, body").animate({ scrollTop: 0 }, "slow");
        modalContent.css({'top':'40px'});

        if (purfLayoutType == 'two-column-layout') {
          $('div.ctools-modal-content').css({'width': (siteWindow.width() * .65)});
          modalContent.css({'left':'17.5%'});
        }
      }

      $("#modalBackdrop").css({'height': siteWindow.height() + 100});

      let windowWidth = $(window).width(); // Get the window width
      let htmlWidth = $('html').width();
      if (htmlWidth < windowWidth) {
        htmlWidth.css({'width':windowWidth});
      }
      let moveRequired = function(){
        // Move the required-field text above the submit button (i.e. "* Indicates a required field").  This either has
        // done in javascript, or at some point in the form rendering process (or in the form template).  I'm doing it
        // in js now b/c it's easier and quicker
        let requiredNote = $('#smg-pop-up-required-note');
        if (purfLayoutType === 'two-column-layout' && windowWidth > 640) {
          requiredNote.css({'display':'inline', 'position':'absolute'});
          let formActions = modalContent.find(".form-actions");
          if (formActions.find(requiredNote).length) {
            formActions.prepend(requiredNote);
            $('div.ctools-modal-content').find('.modal-content').find(requiredNote).css({'display':'inline', 'position':'absolute'});
            $('.webform-client-form > div').not('.form-actions').find("> #smg-pop-up-required-note").remove();
          }
          else {
            formActions.prepend(requiredNote);
            $('div.ctools-modal-content').find('.modal-content').find(requiredNote).css({'display':'inline', 'position':'absolute'});
            $('.webform-client-form').find("> #smg-pop-up-required-note").remove();
          }
        }
      };
      //moveRequired();

      $(document).ready(function(){
        //setTimeout(moveRequired,500);
      });

      // @todo needs cleanup below.  many unused vars.

      let modifyModalHeight = function (addHeight) {

        // If one-column-layout make sure it's at least as long as its contents
        if (purfLayoutType === 'one-column-layout') {
          // One more check to make sure everything fits
          let innerContentsHeight = $('.modal-header').outerHeight() + $('.modal-scroll').outerHeight() + $('#modalContent .disclaimer').outerHeight();

          let newModalHeight = $('#modalContent').height();
          if (innerContentsHeight > newModalHeight) {
            $('#modalContent, .ctools-modal-content').css({'height':innerContentsHeight + 5 + 'px'});
          }
          else {
            $('.ctools-modal-content, #modal-content').css({'height':'auto'});
          }
        }

        if (windowWidth > 640 && purfLayoutType !== 'one-column-layout') {
          $('.ctools-modal-content').css({'height':'auto','padding-bottom':'15px'});
          $('#modal-content').css({'height':'auto','padding-bottom':'15px'});
        }

        if (windowWidth > 640) {
          if (purfLayoutType !== 'one-column-layout') {
            if ($('.ctools-modal-content > .clear').length === 0) {
              $('.ctools-modal-content').append('<div class="clear"></div>');
              $('.ctools-modal-content .clear').css({'clear':'both'});
            }
            if ($('#modal-content > .clear').length === 0) {
              $('#modal-content').append('<div class="clear"></div>');
              $('#modal-content .clear').css({'clear':'both'});
            }
            if ($('.popups-container > .clear').length === 0) {
              $('.popups-container').append('<div class="clear"></div>');
              $('.popups-container .clear').css({'clear':'both'});
            }
          }
        }

        if (!modalContent.length) return;
        if ((modalContent.height() - 150) < $(document).height()) {
          //let newBodyHeight = $('#modalContent').height() + 300;
          //$('body, #modalBackdrop').css({'height': newBodyHeight + 'px'});
        }

      };
      setTimeout(modifyModalHeight,1000);

      let modalEvents = $._data($(window)[0], "events");
      if (modalEvents && modalEvents.hasOwnProperty("resize")) {
        // Unbind the CTools modal resize event handler which breaks everything
        let resizeEvents = modalEvents.resize;
        for (let rE in resizeEvents) {
          if (resizeEvents.hasOwnProperty(rE)) {
            if (resizeEvents[rE].hasOwnProperty("handler")) {
              let handler = resizeEvents[rE].handler;
              let funcToString = handler.toString();
              if (funcToString.indexOf("Drupal.CTools.Modal.currentSettings") > -1) {
                $(window).unbind("resize", handler);
              }
            }
          }
        }
      }

      $(window).on('resize', function() {
        modifyModalHeight();
      });

      // Function for determining if browser is IE and if so what version, used below in
      // msieChangeWidth to make some css adjustments
      function msieversion(){
        let ua = window.navigator.userAgent;
         let msieV = ua.indexOf("MSIE ");
         if (msieV > 0) {     // If Internet Explorer, return version number
           return parseInt(ua.substring(msieV + 5, ua.indexOf(".", msieV)));
         }
         else {                // If another browser, return 0
          return false;
         }
      }

      let msie = msieversion();
      let msie9 = false;
      let msie8 = false;
      if (msie && msie === 9) {
        msie9 = true;
      }
      else if (msie === 8) {
        msie8 = true;
      }

      // If the webform returns a validation error, call the modifyModalHeight function again because
      // that adds to the height of the form.  If msie = 8, add extra height
      if ($('#modal-content').find('.messages.error').length) {
        if (!msie8) {
          modifyModalHeight(45);
        }
        else {
          let ie8FormHeight = $('#modalContent .webform-client-form').height();
          $('#modalContent .webform-client-form').css({'height':ie8FormHeight + 45 + 'px'});
          setTimeout(function(){
            modifyModalHeight(80);
          },2000);
        }
      }

      let msieChangeWidth = function () {
        if (msie9 || msie8) {
          let newWidth;
          let newLeft;
          if (windowWidth > 640 && purfLayoutType === 'two-column-layout') {
            newWidth = windowWidth * .64;
            newWidth = Math.round(newWidth);
            modalContent.css({'width': newWidth + 'px'});
            modalContent.find('.smg-pop-up-column').css({'width':'50%'});
            newLeft = (windowWidth - newWidth) / 2;
            newLeft = Math.round(newLeft);
            modalContent.css({'position':'absolute','left': newLeft + 'px'});
          }
          else if (windowWidth > 640 && purfLayoutType === 'one-column-layout') {
            newWidth = windowWidth * .38;
            newWidth = Math.round(newWidth);
            modalContent.css({'width': newWidth + 'px'});

            newLeft = (windowWidth - newWidth) / 2;
            newLeft = Math.round(newLeft);
            modalContent.css({'position':'absolute','left': newLeft + 'px'});
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

      let htmlOverflowDefault = $('html').css('overflow');
      let modifyWidgets = function(){
        $('.smg-pop-up-element.select select', context).each(function () {

          $(this).multiselect();

          // Get the multiselect button for this select element using multiselect method (http://www.erichynds.com/blog/jquery-ui-multiselect-widget)
          let button = $(this).multiselect('getButton');
          button.css('width','100%');

          // Below, we modify the position of the menu relative to the button.  The jQuery UI Multiselect library
          // has its own function that I use directly below (ie multiselect("option","position", {...})).  However, I
          // also repeat (redo) the operation using jQuery's native position() function.  On a desktop browser, the Multiselect
          // function is sufficient.  However, to get it to work on mobile, I needed to use both the multiselect fct and
          // jQuery's position fct (not sure why, but it doesn't seem to affect performance in any way)
          $(this).multiselect("option","position", {my:"left top", at:"left bottom", of:button, collision:"none"});
          let widget = $(this).multiselect('widget');

          // Set some variables @todo maybe delete
          let scrollTop = $(window).scrollTop(),
              elementOffset = (modalContent.length) ? modalContent.offset().top : 0,
              distance = (elementOffset - scrollTop);
          widget.position({my:"left top", at:"left bottom", of:button, collision:"none"});
          let buttonWidth = button.width();
          // set the width of the widget
          $(this).multiselect('widget').width(buttonWidth);

          widget.on("multiselectbeforeopen", function(event, ui){
            // Even though we set the width of the multiselect popup above, that didn't account
            // for questions that are shown conditionally (i.e. the buttons have 0 width when the
            // document initially loads) so we set the width again just before the multiselect popup
            // opens.
            let buttonBeforeOpenWidth = $(this).multiselect('getButton').width();
            $(this).multiselect('widget').width(buttonBeforeOpenWidth);
          });

          $(this).on("multiselectopen", function (event, ui) {
            if (isTouch) {
              return;
            }
            scrollTop = $(window).scrollTop();
            elementOffset = (modalContent.length) ? modalContent.offset().top : 0;
            let winHeight = $(window).height();
            distance = ( winHeight / 2 ) - ( modalContent.outerHeight() / 2);
            let currentWidget = $(this);
            if (!$(this).hasClass('ui-multiselect-menu')) {
              try {
                currentWidget = $(this).multiselect('widget');
                let currentWidgetUl = currentWidget.children("ul");
              }
              catch (err){

              }
            }
            let widgetOffset = currentWidget.offset().top;
            let widgetDistanceFromTop = (widgetOffset - scrollTop);
            let bottomOfVisibleWindow = $(window).height();
            let widgetDistanceToBottom = (bottomOfVisibleWindow - widgetDistanceFromTop);
            currentWidgetUl.css({'max-height':widgetDistanceToBottom - 15});
            multiSelectIsOpen = true;
            //modalContent.css({'position':'fixed', 'top':distance});

            //$('body').css({'overflow':'hidden'});
            //$('html').css({'overflow':'hidden'});
          });
          $(this).on("multiselectclose", function (event, ui){
            if (isTouch) {
              return;
            }
            multiSelectIsOpen = false;
            let winHeight = $(window).height();
            distance = ( winHeight / 2 ) - ( modalContent.outerHeight() / 2);
            //modalContent.css({'position':'absolute', 'top':distance});
            $('body').css({'overflow':'visible'});
            $('html').css({'overflow':htmlOverflowDefault});
          });
        });
      };
      modifyWidgets();
      setTimeout(modifyWidgets,500);
      setTimeout(modifyWidgets,1000);

      $(window).load(function(){

        modifyWidgets();

        // To be safe, I call the modifyWidgets fct several times
        setTimeout(modifyWidgets, 2000);
        setTimeout(modifyWidgets, 5000);
        setTimeout(modifyWidgets, 15000);
        setTimeout(modifyWidgets, 25000);
        setTimeout(modifyWidgets, 45000);

        let labelSize = function(){
          if ($(window).width() < 640) {
            $('div.ctools-modal-content .modal-content .form-item.webform-component > label, div.ctools-modal-content .modal-content .form-item.webform-component > label .form-required').each(function(){
              $(this, context).css('font-size','12px');
              $(this, context).css('-webkit-text-size-adjust','12px');
            });
          }
        };

        labelSize();
        setTimeout(labelSize, 3000);
        setTimeout(labelSize, 8000);
        setTimeout(labelSize, 11000);

        $(window).on("orientationchange", function(event){

          let deviceWidth = $(window).width();
          if (deviceWidth < 640) {
            let viewport = document.querySelector("meta[name=viewport]");
            viewport.setAttribute('content', 'initial-scale=1.0, width=device-width, minimum-scale=1.0, maximum-scale=1.0, user-scalable=yes');
          }

          modifyWidgets();

          labelSize();

          if(window.orientation === 90){
            setTimeout(function(){
              let modalHeight = $('#modal-content').outerHeight();
              if($('#modal-content').height() !== modalHeight + 25){
                $('#modal-content').css({'height':modalHeight + 25 + 'px'});
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
    let headerHTML;
    if (PURFGlobal.prototype.header) {
      headerHTML = '<span class="modal-header-text">' + PURFGlobal.prototype.header + '</span>';
    }

    let disclaimer = PURFGlobal.prototype.disclaimer;
    let disclaimerHTML = '';
    if (disclaimer) {
      disclaimerHTML = '<div class="disclaimer"><span class="disclaimer-text">This content is sponsored by the supplier.  Your contact information may be shared with this sponsor, as detailed in our Privacy Policy.  Your contact information will not be shared with a sponsor whose content you have not reviewed.</span></div>';
    }

    if (purfOverrideOn) {
      purfLayoutType = 'two-column-layout';
    }

    let fullNameHTML = '';
    if (spFullName) {

      $(document.body).on('click', 'a#not-sp-user', function(e) {
        e.preventDefault();
        Drupal.CTools.Modal.modal_dismiss();
        // get cookie value
        $.cookie('spUserID', null, {path: '/', domain: documentDomain});
        let url = location.protocol + '//' + location.host + location.pathname;
        window.location = url;
      });

      let link = $("<a />", {
        id : "not-sp-user",
        name : "not-sp-user",
        href : "#",
        text : "Click here."
      });
      let linkString = link.wrapAll('<div>').parent().html();
      fullNameHTML = '<div id="sp-full-name-wrapper"><span id="sp-full-name">Not ' + spFullName + '?  ' + linkString + '</span></div>';

    }

    let windowWidth = $(window).width();
    let windowWidthClass;
    if (windowWidth >= 640) {
      windowWidthClass = 'min-640';
    }
    else {
      windowWidthClass = 'max-640';
    }

    let html = '';
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

