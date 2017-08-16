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
  console.log('non feature');
  $(".awbs-fla-imu").append(flaImubox);
  $(".inserted-fla-imu").append($(".imuA").removeClass('hidden').addClass(
   'rightpull'));
 }

 // if this is a feature article
 if ((postType == 'article') && (subType == 'feature')) {
  console.log('feature');
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
