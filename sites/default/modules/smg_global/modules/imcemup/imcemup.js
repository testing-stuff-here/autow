(function($) {

//add hook:load. install flash upload on first use of upload tab.
imce.hooks.load.push(function () {
  $._mup.hl(imce);
  //flash resets when it is hidden. we make upload content 1x1 instead of hiding it
  var opclick = imce.opClick;
  var upcontent = imce.ops.upload.div;
  imce.opClick = function(name) {
    var ret = opclick(name);
    if (ret == true && name == 'upload') {
      $(upcontent).removeClass('shrink');
    }
    return ret;
  };
  var opshrink = imce.opShrink;
  imce.opShrink = function(name, effect) {
    if (imce.vars.op != name) return;
    if (name == 'upload') {
      effect = 'get';//do nothing
      $(upcontent).addClass('shrink');
    }
    return opshrink(name, effect);
  };
});

//initiate flash uploader
imce.mupInit = function(opt) {
  //change format of the extension list to *.ext1;*.ext2;...
  var exts = '*.' + $.trim(imce.conf.extensions).replace(/\s+/g, ';*.');
  //create uploader
  var $inp = $('#edit-imce');
  if (!$inp.size()) return;
  var $up = $inp.parent();
  if (!$up[0].id) $up[0].id = 'edit-imce-wrapper';
  $up.uploadify($.extend($._mup.set(opt, exts), {
    fileDataName: $inp[0].name,
    buttonText: Drupal.t('Browse'),
    //select event firing just after a file is selected and queue info created.
    onSelect: function(e, qid, file) {
      if (opt.filesize && file.size > opt.filesize) {
        imce.setMessage(Drupal.t("%filename is not queued. Maximum allowed size is %maxsize bytes.", {'%filename': file.name, '%maxsize': opt.filesize}), 'error');
        $up.uploadifyCancel(qid);
        return false;
      }
    },
    //queue is over capacity
    onQueueFull: function(e, qsize) {
      return imce.setMessage(Drupal.t('You are not allowed to queue more than %num files.', {'%num': qsize}), 'error');
    },
    // file done
    onComplete: function(e, qid, file, resp, data) {
      imce.processResponse($.parseJSON(resp));
    },
    // all done
    onAllComplete: function(e, data) {
      imce.fopLoading('upload', false);
      imce.setMessage(Drupal.t('Upload queue is complete.'));
    }
  }));
  //change the function of Upload button.
  var ufunc = function(e) {
    $._mup.op(imce, opt, $up);
    return false;
  };
  $('#edit-upload').click(ufunc).removeAttr('disabled');//it is sometimes disabled for some reason
  //restore file input on failure. use settimeout as flash blockers may process the object.
  setTimeout(function() {
    if (!$('#' + $up[0].id + 'Uploader').is('object')) {
      $up.show();
      $('#edit-upload').unbind('click', ufunc);
    }
  });
};

})(jQuery);