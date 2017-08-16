(function ($) {
  Drupal.behaviors.AdvertFix = {
    attach: function (context, settings) {
    setTimeout(function() {
      var imu_1 = document.getElementById('google_ads_iframe_/152023730/aw_imu_1_0').contentWindow.document.getElementById('aw0');
      var imu_2 = document.getElementById('google_ads_iframe_/152023730/aw_imu_2_0').contentWindow.document.getElementById('aw0');
      imu_1 = '<div id="mobile_imu">ADVERTISEMENT<a href="' + imu_1.href + '">' + imu_1.innerHTML + '"</a></div>';
      imu_2 = '<div id="mobile_imu">ADVERTISEMENT<a href="' + imu_2.href + '">' + imu_2.innerHTML + '"</a></div>';
      if (Drupal.settings.AdvertFix.isFront === true && document.documentElement.clientWidth < 992) {
        $(imu_1).insertAfter('.view-home-river-of-content .views-row-2');
        $(imu_2).insertAfter('.view-home-river-of-content .views-row-5');
      }
      if (Drupal.settings.AdvertFix.isArticle === true && document.documentElement.clientWidth < 992) {
        $(imu_1).insertAfter('.awbs-body-text p:nth-child(2)');
        $(imu_2).insertAfter('.awbs-companies-mentioned');
      }}, 2000);
    }
  };
}(jQuery));