var dataCard = angular.module('dataCard', ['ngSanitize', 'smgGaEvent']);

dataCard.factory('delayFactory',['$timeout', '$rootScope', function ($timeout, $rootScope) {

  let service = { timers: {} };

  service.getTimer = function (delay) {
    if (angular.isUndefined(service.timers[delay])) {
      service.timers[delay] = {timer : false};
      let delayTime = parseInt(delay) * 6500;
      $timeout(function () {
        service.timers[delay].timer = true;
      }, delayTime)
    }

    return service.timers[delay];
  };

  return service;
}]);

dataCard.controller('DataCardCtrl', ['$scope', '$attrs', '$timeout', 'gaEventWrapper', function ($scope, $attrs, $timeout, gaEventWrapper) {

  $scope.nid = $attrs.nid; // Datacard NID
  $scope.tid = $attrs.tid; // Taxonomy ID
  $scope.site = $attrs.site; // Site ID

  if (!angular.isUndefined($attrs.delayVideoCompile)) {
    $scope.delayVideoCompile = $attrs.delayVideoCompile;
  }

  $scope.photos = [];

  // Set to true when user hovers over the company link (i.e. the <li> element
  // that this datacard is associated with).
  $scope.parentHover = false;

  // The following variable is set to true if the user is hovering the cursor over the
  // datacard
  $scope.dataCardHover = false;

  // If the information for this data card was added to Drupal.settings, then it should
  // be in Drupal.settings.leadershipDatacard[tid]
  if ( Drupal.settings.hasOwnProperty("leadershipDatacard") ) {
    if ( Drupal.settings.leadershipDatacard.hasOwnProperty($scope.tid) ) {
      for (let compNid in Drupal.settings.leadershipDatacard[$scope.tid] ) {
        if ( Drupal.settings.leadershipDatacard[$scope.tid][compNid]["datacard_nid"] == $scope.nid ) {
          let companyInfo = Drupal.settings.leadershipDatacard[$scope.tid][compNid];
          let dataCardInfo = companyInfo["data_card_processed_for_angular"];

          // Set some properties
          $scope.contactPhotoPath = (dataCardInfo.hasOwnProperty("contact_photo_path")) ? dataCardInfo["contact_photo_path"] : false;

          $scope.contactName = (dataCardInfo.hasOwnProperty("contact_name")) ? dataCardInfo["contact_name"] : "";

          $scope.contactTitle = (dataCardInfo.hasOwnProperty("contact_title")) ? dataCardInfo["contact_title"] : "";

          $scope.companyLogoPath = (dataCardInfo.hasOwnProperty("company_logo_path")) ? dataCardInfo["company_logo_path"] : false;

          $scope.companyWebsite = (companyInfo.hasOwnProperty("company_website")) ? companyInfo["company_website"] : "";

          $scope.productSummary = (dataCardInfo.hasOwnProperty("product_summary")) ? dataCardInfo["product_summary"] : "";

          $scope.companyName = (companyInfo.hasOwnProperty("title")) ? companyInfo.title : "";

          $scope.teaser = (dataCardInfo.hasOwnProperty("teaser")) ? dataCardInfo["teaser"] : "";

          if ( dataCardInfo.hasOwnProperty("product_photos") && (dataCardInfo["product_photos"].length > 0) ) {
            for (let j = 0; j < dataCardInfo["product_photos"].length; j++) {

              let photoData = dataCardInfo["product_photos"][j];

              let photoObj = {
                url: (photoData.hasOwnProperty("product_photo")) ? photoData["product_photo"] : "",
                link: (photoData.hasOwnProperty("product_link")) ? photoData["product_link"] : "",
                title: (photoData.hasOwnProperty("product_title")) ? photoData["product_title"] : ""
              };

              $scope.photos.push(photoObj);
            }
          }

          $scope.printProfileNid = (companyInfo.hasOwnProperty("print_profile_nid")) ? companyInfo["print_profile_nid"] : "";

          $scope.companyNid = (companyInfo.hasOwnProperty("nid")) ? companyInfo.nid : "#";

          // Check if the company has any PMG YouTube Feed videos
          $scope.companyHasPmgYoutubeFeedVideos = false;
          if ( 
            companyInfo.pmg_youtube_feed_videos.hasOwnProperty($scope.companyNid) 
            && companyInfo.pmg_youtube_feed_videos[$scope.companyNid].hasOwnProperty("videos") 
          ) {
            $scope.companyHasPmgYoutubeFeedVideos = true
          }

          break;
        }
      }
    }
  }

  $scope.gaEvent = function (link, category, action, label) {
    return gaEventWrapper.gaEvent(link, category, action, label);
  };

  /**
   * Handles the "leadershipHoverBegin" broadcast that is sent from the
   * leadershipLinkCtrl.  It sets the parentHover property to true so the
   * datacard knows that the user is hovering over the leadership link
   *
   */
  $scope.$on('leadershipHoverBegin', function () {
    $scope.parentHover = true;
    $scope.$digest();
  });

  /**
   * Handles the "leadershipHoverEnd" broadcast that is sent from the
   * leadershipLinkCtrl.  It sets the parentHover property to false so the
   * datacard knows that the user is not hovering over the leadership link
   *
   */
  $scope.$on('leadershipHoverEnd', function () {
    $scope.parentHover = false;
    $scope.$digest();
  });

  /**
   * Shows a comma if there is a name for the company contact, and
   * a title
   */
  $scope.contactShowComma = function () {
    return ($scope.contactName.length > 0 && $scope.contactTitle.length > 0) ? "," : "";
  };

  /**
   * Sets the parentHover value to false, called from link function
   * Useful for touch screens.
   */
  $scope.setParentHoverFalse = function () {
    $scope.parentHover = false;
  };

}]);

/**
 * Creates a service that manages the hover action for pop up data cards
 */
dataCard.factory('hoverManage', ['$window', '$timeout', function ($window, $timeout) {

  function HoverManage(elem, scope, handler) {
    let element = elem[0];
    this.element = element;
    this.handler = handler;
    this.scope = scope;
    this.timer = false;
    this.timerEnd = false;
    this.leadershipLink = elem.find(".leadership-link");

    element.addEventListener('mouseover', this, false);
  }

  HoverManage.prototype.globalValues = {
    activeHover: false, // Property will point to active datacard
    isActiveHover: false
  };

  HoverManage.prototype.handleEvent = function (event) {
    switch (event.type) {
      case 'mouseover' : this.mouseOver(event); break;
      case 'mouseleave': this.mouseLeave(event); break;
      case 'mousemove': this.mouseMove(event); break;
    }
  };

  HoverManage.prototype.waitForMouseStop = function (evt, waitTime, callback) {
    let _this = this;

    function stoppedMoving() {
      _this.element.removeEventListener('mousemove', _this, false);
      callback();
    }

    function moveHandler(evt) {
      evt = evt || window.evt;
      if (_this.timer) {
        window.clearTimeout( _this.timer );
      }
      _this.timer = window.setTimeout(function () {
        stoppedMoving( evt );
      }, waitTime);
    }

    moveHandler(evt);
  };

  HoverManage.prototype.mouseMove = function (e) {
    let elemJquery = jQuery(this.element);

    this.mouseMoveXPrevious = (this.hasOwnProperty('mouseMoveX')) ? this.mouseMoveX : false;
    this.mouseMoveYPrevious = (this.hasOwnProperty('mouseMoveY')) ? this.mouseMoveY : false;
    this.mouseMoveX = (e.offsetX == undefined) ? elemJquery.offset().left : e.offsetX;
    this.mouseMoveY = (e.offsetY == undefined) ? elemJquery.offset().top : e.offsetY;
    let _this = this;

    if (this.mouseMoveXPrevious && this.mouseMoveXPrevious) {
      let diff = this.mouseMoveXPrevious - this.mouseMoveX;
      let diffX = Math.abs(diff);
      let waitTime = (diffX > 0) ? 500 : 50;

      this.waitForMouseStop( e, waitTime , function () {
        _this.startHover();
      });
    }

  };

  HoverManage.prototype.startHover = function () {

    let _this = this;

    this.firstHoverOccured = true;

    let activateHover = function () {
      _this.globalValues.activeHover = _this;
      _this.globalValues.isActiveHover = true;
      _this.scope.broadcastHoverBegin();
    };

    let activeHover = this.globalValues.activeHover;

    if (!activeHover) {
      activateHover();
    }
    else if (activeHover.instanceId == this.instanceId && !this.globalValues.isActiveHover) {
      activateHover();
    }
    else if (activeHover.instanceId != this.instanceId) {
      activeHover.endHover();
      activateHover();
    }
  };

  HoverManage.prototype.mouseOver = function (e) {

    let leadershipLinkRightOffset = this.leadershipLink.position().left + this.leadershipLink.width();

    // Get the x offset @see http://stackoverflow.com/questions/12704686/html5-with-jquery-e-offsetx-is-undefined-in-firefox
    let elemJquery = jQuery(this.element);
    let xOffset = (e.offsetX == undefined) ? (e.pageX - elemJquery.offset().left) : e.offsetX;
    if (xOffset < (leadershipLinkRightOffset + 20) && xOffset > -4) {
      this.element.addEventListener('mousemove', this, false);
      this.element.addEventListener('mouseleave', this, false);
    }
  };

  HoverManage.prototype.mouseLeave = function (e) {
    let _this = this;

    if (this.timer)
      window.clearTimeout(this.timer);

    this.timerEnd = window.setTimeout(function () {
      _this.endHover();
    }, 300);

  };

  HoverManage.prototype.endHover = function () {
    if (this.timerEnd) {
      window.clearTimeout(this.timerEnd);
    }
    this.globalValues.isActiveHover = false;
    this.scope.broadcastHoverEnd();
    this.element.removeEventListener('mouseleave', this, false);
    this.element.removeEventListener('mousemove', this, false);
  };

  HoverManage.prototype.lightboxOpened = function () {
    this.element.removeEventListener('mouseleave', this, false);
    this.element.removeEventListener('mousemove', this, false);
  };

  let instanceCounter = 0; // Used to give every object instance a unique ID
  return function (element, scope, handler) {
    let hoverInstance = new HoverManage(element, scope, handler);
    hoverInstance.instanceId = instanceCounter;
    instanceCounter++;
    return  hoverInstance;
  }

}]);

dataCard.controller('leadershipLinkCtrl', ['$scope', '$rootScope', 'hoverManage', function ($scope, $rootScope, hoverManage) {

  $scope.hoverOn = false;

  $scope.broadcastHoverBegin = function () {
    $scope.$broadcast('leadershipHoverBegin',{});
    $scope.hoverOn = true;
  };

  $scope.broadcastHoverEnd = function () {
    $scope.$broadcast('leadershipHoverEnd', {});
    $scope.hoverOn = false;
  };

  $scope.startHoverManage = function (element) {
    let hoverManager;
    hoverManager = hoverManage(element, this, function () {});
    $scope.hoverManager = hoverManager;
  };

  // Catches an event moving up the scope hierarchy when a user opens a lighbox video
  $scope.$on('smgLightboxOpen', function (elem) {
    $scope.hoverManager.lightboxOpened();
  });

}]);

dataCard.directive('leadershipLink', [function () {
  return {
    restrict: 'A',
    scope: true,
    controller: 'leadershipLinkCtrl',
    link: function (scope, elem, attrs) {

      scope.startHoverManage(elem);

      elem.find('a.leadership-link').each(function (i,el) {

        let leaderLink = jQuery(el);
        if ( !leaderLink.hasClass('touchstart-off') )
          leaderLink.addClass('touchstart-off');

        leaderLink.on('touchstart', function (e) {
          if ( leaderLink.hasClass('touchstart-off') ) {
            e.preventDefault();
            e.stopPropagation();
            e.stopImmediatePropagation();
            leaderLink.addClass('touchstart-begin').removeClass('touchstart-off');
            scope.broadcastHoverBegin();
          }
          else {
            window.location.href = leaderLink.attr("href");
          }
        });

      });
    }
  };
}]);

/**
 * Directive that defines the pop-up data card
 */
dataCard.directive('leadershipDataCard', ['$window', '$timeout', 'delayFactory', function ($window, $timeout, delayFactory) {

  let dataCardTpl = Drupal.settings.smgAngularTemplates.dataCard;

  return {
    restrict: 'E',
    replace: true,
    scope: true,
    controller: 'DataCardCtrl',
    link: function (scope, elem) {

      scope.currentDataCardHover = false;
      scope.compileVideo = angular.isUndefined(scope.delayVideoCompile) ?
        {timer : true} :
        delayFactory.getTimer(scope.delayVideoCompile);

      elem.on({
        mouseenter: function () { scope.dataCardHover = true; },
        mouseleave: function () { scope.dataCardHover = false; }
      });

      // Utility function for getting the distance to the bottom of the page
      // from a given element
      scope.getDistanceToBottom = function( element ) {
        let scrollTop = angular.element($window).scrollTop(),
            liOffset = element.offset().top,
            distance = liOffset - scrollTop;
        let bottomOfVisibleWindow = angular.element($window).height();
        let distanceToBottomOfPage = bottomOfVisibleWindow - distance;

        return distanceToBottomOfPage;
      };

      scope.checkTouchEvent = function( e ) {
        let rect = elem[0].getBoundingClientRect();

        if ( jQuery(e.target).hasClass('touchstart-begin') )
          return false;

        let yOffset = e.pageY - jQuery(window).scrollTop();
        if ((yOffset <= rect.bottom && yOffset >= rect.top) && (e.pageX <= rect.right && e.pageX >= rect.left)) {
          scope.currentDataCardHover = true;
        }
        else {
          scope.currentDataCardHover = false;
          scope.$apply();
        }

      };

      let calculateDataCardWidth = function () {
        let windowWidth = angular.element($window).width();
        if (!scope.site == 'ppoem' || windowWidth > 900) {
          return (windowWidth > 500) ? "534px" : "90%";
        }
        else {
          return (windowWidth * .58) + "px";
        }
      };

      scope.$watch('compileVideo.timer', function (newValue) {
        if (!newValue) return;
        $timeout(function () {
          let watchersToRemove = [
            "companyWebsite",
            "companyLogoPath",
            "contactPhotoPath",
            "companyHasPmgYoutubeFeedVideos",
            "compileVideo.timer"
          ];
          scope.$$watchers.forEach(function (value, index) {
            if (watchersToRemove.indexOf(value.exp) > -1) {
              scope.$$watchers.splice(index, 1);
            }
          });
        });
      });

      scope.$watch('parentHover', function() {
        if ( scope.parentHover ) {

          // Now we show the datacard, but first must calculate the top position and width

          let dataCardWidth = calculateDataCardWidth();
          // The top absolute position of the datacard, which we might modify below
          let topPosition = '-50%';

          // Set the width of the datacard FIRST, that way when we calculate the height below,
          // it will be accurate
          elem.css({"visibility":"hidden"});
          elem.css({"width":dataCardWidth, "display":"block"});

          // Get the datacard height
          let dataCardHeight = elem.outerHeight();
          // Below, we check to see if there's a video widget in this datacard.  If there is,
          // and the videoWidget-video has a width of zero, then the widget has rendered yet, so
          // we can't trust the full height of the datacard that we calculated above.  Therefore
          // we just add 225px.
          if (elem.find(".videoWidget").length || elem.find("compile-video-widget").length) {
            let videoWidget = elem.find(".videoWidget");
            if (!videoWidget.find(".videoWidget-video").width()) {
              dataCardHeight = elem.find(".dataCard-top").outerHeight() + 245;
            }
          }

          // Get distance of parent li link from top of browser window
          let distanceToBottom = scope.getDistanceToBottom(elem.parent());

          /**
           * This function is used to calculate where to put the arrow
           * @returns {number}
           *  Pixels that represent the distance from the top of the datacard
           *  to the half-way point of the data card's parent li
           */
          let calculatePosArrow = function() {
            // Get the height of the parent li
            let heightOfParentLi = elem.parent().outerHeight(true);
            // Get the distance of the data card to the bottom of window
            let dataCardDistance = scope.getDistanceToBottom(elem);
            // Get the distance b/w datacard and parent li
            let distanceDataCardLi = dataCardDistance - distanceToBottom;

            return distanceDataCardLi + (heightOfParentLi * 0.5);
          };

          // If the datacard height is bigger than the distance to the bottom of
          // the page then it will go below the fold of the page, so we recalculate
          // its top position
          if ((dataCardHeight + 10) > distanceToBottom) {
            topPosition = (dataCardHeight - distanceToBottom + 20) * -1;
            topPosition+="px";
          }

          elem.css({top:topPosition, visibility:"visible"});

          // Set the top position of the right arrow
          let distanceArrow = calculatePosArrow();
          let dataCardArrow = elem.find(".dataCard-after-arrow");
          if ( parseInt(distanceArrow) > (dataCardHeight - 20) ) {
            dataCardArrow.css({"display":"none"});
          }
          else {
            dataCardArrow.css({"display":"block"});
            scope.currentDataCardHover = true;

            document.addEventListener('touchstart', scope.checkTouchEvent, true);
          }

          dataCardArrow.css({top:distanceArrow});

        }
        else {
          if ( !scope.dataCardHover ){
            elem.css({display:""}); // Revert to default css style
            scope.currentDataCardHover = false;
          }
        }
      });

      scope.$watch('dataCardHover', function () {
        if ( !scope.dataCardHover && !scope.parentHover ) {
          elem.css({display:""});
        }
      });

      scope.$watch('currentDataCardHover', function () {
        if ( !scope.currentDataCardHover ) {
          document.removeEventListener('touchstart', scope.checkTouchEvent, true);
          elem.css({display:""});

          // Set the data card's parent hover value to false
          scope.setParentHoverFalse();

          elem.siblings('.touchstart-begin').each(function (i,e) {
            jQuery(e).removeClass('touchstart-begin').addClass('touchstart-off');
          });
          elem.siblings('.link-section').each(function (i,e) {
            jQuery(e).find('a.leadership-link').removeClass('touchstart-begin').addClass('touchstart-off');
          });
        }
      });
    },
    templateUrl: dataCardTpl
  };
}]);

dataCard.directive('compileDataCard', ['$compile', function ($compile) {
  return {
    restrict: 'E',
    scope: {
      nid: '@',
      tid: '@',
      site: '@'
    },
    replace: true,
    link: function (scope, elem, attrs) {

      // Create an object.  Upon the interpolation of the nid and tid values (determined
      // by the $observe fcts below), the values of the interpValues obj will be changed.
      // Subsequently the $watchCollection fct will determine when both values are set.
      scope.interpValues = {
        interpNid: false,
        interpTid: false,
        interpSite: false
      };

      attrs.$observe('nid', function (newValue) {
        scope.interpValues.interpNid = newValue;
      });

      attrs.$observe('tid', function (newValue) {
        scope.interpValues.interpTid = newValue;
      });

      attrs.$observe('site', function (newValue) {
        scope.interpValues.interpSite = newValue;
      });

      let listener = scope.$watchCollection(
        'interpValues',
        /**
         * @param {object} newValues
         */
        function (newValues) {
          if ( newValues.interpTid && newValues.interpTid && newValues.interpSite ) {
            let dataCardTplWrap = angular.element(
              '<leadership-data-card nid="' + scope.nid + '" tid="' + scope.tid + '" site="' + scope.site + '"></leadership-data-card>'
            );
            let compiledDataCardTpl = $compile(dataCardTplWrap)(scope);
            elem.replaceWith(compiledDataCardTpl);

            listener();
          }
        }
      );

    }
  };
}]);

dataCard.directive('compileVideoWidget', ['$compile', '$window', function ($compile, $window) {
  return {
    restrict: 'E',
    scope: {
      nid: '@',
      tid: '@',
      hover: '=',
      compileVideoWidget: '='
    },
    replace: true,
    link: function (scope, elem) {

      let w = angular.element($window),
        isCompiled = false;

      if (angular.isUndefined(scope.compileVideoWidget)) {
        scope.compileVideoWidget = true;
      }

      let compileWidget = function () {
        let videoWidgetTpl = angular.element(
          '<video-widget datacard="true" nid="' + scope.nid + '" tid="' + scope.tid + '" ></video-widget>'
        );
        if (w.width() > 480) {
          let compiledWidget = $compile(videoWidgetTpl)(scope);
          elem.replaceWith(compiledWidget);
          isCompiled = true;
        }
      };

      let disableWatchers = function () {
        scope.$$watchers = [];
      };

      let watch1 = scope.$watch('hover', function (newValue) {
        if (!newValue || isCompiled) return;
        compileWidget();
        watch1();
        disableWatchers();
      });

      let watch2 = scope.$watch('compileVideoWidget', function (newValue) {
        if (!newValue || isCompiled) return;
        compileWidget();
        watch2();
        disableWatchers();
      });

    }
  }
}]);

dataCard.directive('smgAnchorGaEvent',[function () {
  return {
    restrict: 'A',
    link: function (scope, element, attrs) {
      angular.element(element).click(function (event) {
        event.preventDefault();
        event.stopPropagation();
      });
    }
  };
}]);

// will be loaded in smg_angular module
window.smgAngularDependencies.push('dataCard');
