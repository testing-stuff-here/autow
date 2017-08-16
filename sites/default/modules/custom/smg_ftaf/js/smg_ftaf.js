
/**
 *When a user of the Forward to a Friend mechanism clicks the mailto link or submits
 *the form on the FTAF page, this JavaScript code will fire off a Google Event
 *
 *@author Yevgeny Ananin <yananin@summitmediagroup.com>
 */

(function ($) {

  /**
   *Used to extract the value of a query parameter in the URL
   *@param sParam
   *  The parameter whose value we need to extract
   */
  var GetURLParameter = function(sParam) {
    var sPageURL = window.location.search.substring(1);
    var sURLVariables = sPageURL.split('&');
    for (var i = 0; i < sURLVariables.length; i++) {
      var sParameterName = sURLVariables[i].split('=');
      if (sParameterName[0] == sParam) {
        return sParameterName[1];
      }
    }
  }

  $(window).load(function(){
    var docURL = document.URL;
    if(docURL.indexOf('56871') != -1){
      //alert(docURL);
    }
  });

  $(window).on('load', function(){
    /*
    $('#smg_ftaf-mail-link-link').click(function () {
      ConstructGaq();
    });
    $('#smg-ftaf-form #edit-submit').click(function () {
      ConstructGaq();
    });
    */
    $('#smg_ftaf-mail-link-link').on('click', function(e) {
      var that = this;
      e.preventDefault();
      ConstructGaq();
      setTimeout(function(){location.href = that.href;}, 700);
    });
    $('#smg-ftaf-form').on('submit', function(e) {
      var form = this;
      e.preventDefault();
      ConstructGaq();
      setTimeout(function(){form.submit();}, 400);
    });
  });

  /**
   *Constructs and executes the Google events JavaScript code
   */
  function ConstructGaq() {
    //var _gaq = _gaq || [];

    //extract the title of the article for the gaq function
    var articleTitle = "'" + $('#smg_ftaf-headline').text() + "'";
    //call the GetURLParameter function to get the value of the rmedium url query parameter
    var rMedium = GetURLParameter('rmedium');
    if(rMedium == 'print_referral') {
      var rIssue = GetURLParameter('rissue');
      if(rIssue != 'false' && rIssue.length < 3){
        ga('send', 'event', 'Summit Share This', 'Print Referring NoIssue', articleTitle);
      }
      else {
        var referringString = 'Print Referring ' + rIssue;
        ga('send', 'event', 'Summit Share This', referringString, 'Link');
      }
    }
    else if(rMedium == 'playbook_referral')
    {
      var rSource = GetURLParameter('rsource');
      ga('send', 'event', 'Summit Share This', 'Playbook Referring', rSource);
    }
    else if(rMedium == 'print_qr_code'){
      var rIssue = GetURLParameter('rissue');
      var referringString = 'Print Referring ' + rIssue;
      ga('send', 'event', 'Summit Share This', referringString, 'QR Code');
    }

    // check for url parameter of medium as well as rmedium
    var rMedium = GetURLParameter('medium');
    if(rMedium == 'print_referral') {
      var rIssue = GetURLParameter('rissue');
      if(rIssue != 'false' && rIssue.length < 3){
        ga('send', 'event', 'Summit Share This', 'Print Referring NoIssue', articleTitle);
      }
      else {
        var referringString = 'Print Referring ' + rIssue;
        ga('send', 'event', 'Summit Share This', referringString, 'Link');
      }
    }
    else if(rMedium == 'playbook_referral')
    {
      var rSource = GetURLParameter('rsource');
      ga('send', 'event', 'Summit Share This', 'Playbook Referring', rSource);
    }
    else if(rMedium == 'print_qr_code'){
      var rIssue = GetURLParameter('rissue');
      var referringString = 'Print Referring ' + rIssue;
      ga('send', 'event', 'Summit Share This', referringString, 'QR Code');
    }
  }

  $(document).ready(function(){
    // Prevent user from submitting form by pressing enter.  We change the default behavior
    // so that enter keystroke generates newline character, not form submission.
    $('textarea').keyup(function (e){
      if(e.keyCode == 13){
        var curr = getCaret(this);
        var val = $(this).val();
        var end = val.length;

        $(this).val( val.substr(0, curr) + '' + val.substr(curr, end));
      }
    });/*
    $('input').keydown(function (e){
      if(e.keyCode == 13){
        e.preventDefault();
        return false;
      }
    });
    $('input').on("keypress", 'form', function (e) {
      var code = e.keyCode || e.which;
      if (code == 13) {
        e.preventDefault();
        return false;
      }
    });*/
    function getCaret(el) {
      if (el.selectionStart) {
        return el.selectionStart;
      }
      else if (document.selection) {
        el.focus();
        var r = document.selection.createRange();
        if (r == null) {
            return 0;
        }
        var re = el.createTextRange(),
        rc = re.duplicate();
        re.moveToBookmark(r.getBookmark());
        rc.setEndPoint('EndToStart', re);

        return rc.text.length;
      }
      return 0;
    }
  });

})(jQuery)
