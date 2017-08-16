/**
 * Adds functionality that allows us to wrap the google analytics event
 * syntax in a function, so that we can put it into an ng-click directive
 *
 * @author Yevgeny Ananin <yananin@summitmediagroup.com>
 *
 */

var smgGaEvent = angular.module('smgGaEvent', []);

smgGaEvent.factory('gaEventWrapper', ['$timeout', function ($timeout) {
  return {
    gaEvent: function (link, category, action, label) {

      // If check if there is a prefix in the url and add it if none.
      var prefix = 'http://';
      if (link.substr(0,1) !== '/' &&  !/^(f|ht)tps?:\/\//i.test(link)) {
        link = prefix + link;
      }

      var ga = window.ga || false;

      if (!ga) {
        window.location.href = link; // No GA event, just redirect
      }
      else {
        ga('send', 'event', category, action, label);
        // Add prefix if necessary
        $timeout( function () {
          window.location.href = link;
        }, 100);
      }
    }
  };
}]);
