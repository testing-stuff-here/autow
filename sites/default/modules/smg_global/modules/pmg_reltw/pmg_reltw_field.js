(function ($) {
  Drupal.behaviors.Reltw = {
    attach: function (context) {
      $('.pmg_reltw-field-wrapper:not(.pmg_reltw-field-wrapper-processed)', context)
        .addClass('pmg_reltw-field-wrapper-processed').each(function () {
        var pmg_reltw_id = $(this).attr('id').replace(/^pmg_reltw-field-(\d+)$/, "$1");
        Drupal.ReltwField.initialize(pmg_reltw_id);
      });

    }
  };


  Drupal.ReltwField = {}

  Drupal.ReltwField.context = function () {
    return $("form .pmg_reltw-field-wrapper");
  };

  Drupal.ReltwField.initialize = function (pmg_reltw_id) {
    // Prevent JS errors when Hierarchical Select is loaded dynamically.
    Drupal.ReltwField.attachBindings(pmg_reltw_id);
  }
  
  Drupal.ReltwField.attachBindings = function (pmg_reltw_id) {
    $('#pmg_reltw-field-' + pmg_reltw_id)

      .find('select').live('change', {'pmg_reltw_id': pmg_reltw_id}, function (event) {
      Drupal.ReltwField.update(event.data.pmg_reltw_id, {
        opString: 'Update',
        select_id: $(this).attr('id')
      });
    })

  }

  Drupal.ReltwField.update = function (pmg_reltw_id, settings) {
    var post = $('form:has(#pmg_reltw-field-' + pmg_reltw_id + ')', Drupal.ReltwField.context).formToArray();

    var group_id = '';
    group_id = $('#' + settings.select_id).closest('fieldset.pmg_reltw_group').attr('id');

    post.push({name: 'pmg_reltw_id', value: pmg_reltw_id});
    post.push({name: 'group_id', value: group_id});
    post.push({name: 'op', value: settings.opString});

    var url = Drupal.settings.ReltwField.settings["pmg_reltw_id-" + pmg_reltw_id].ajax_url;

    // Construct the object that contains the options for a callback to the
    // server. If a client-side cache is found however, it's possible that this
    // won't be used.
    var ajaxOptions = {
      url: url,
      type: 'POST',
      dataType: 'json',
      data: post,
      beforeSend: function () {
        // TODO - nice to have
        //#Drupal.ReltwField.triggerEvents(pmg_reltw_id, 'before-' + updateType, settings);
        //#Drupal.ReltwField.disableForm(pmg_reltw_id);
      },
      error: function (XMLHttpRequest, textStatus, errorThrown) {
        // TODO - nice to have
        // When invalid HTML is received in Safari, jQuery calls this function.
        //#Drupal.ReltwField.throwError(pmg_reltw_id, Drupal.t('Received an invalid response from the server.'));
      },
      success: function (response, status) {

        // An invalid response may be returned by the server, in case of a PHP
        // error. Detect this and let the user know.
        if (response === null || response.length == 0) {
          Drupal.ReltwField.throwError(pmg_reltw_id, Drupal.t('Received an invalid response from the server.'));
          return;
        }

        for (var i in response) {
          if (response[i]['command'] && Drupal.ajax.prototype.commands[response[i]['command']]) {
            //Drupal.ajax.prototype.commands[response[i]['command']](this, response[i], status, group_id);
            Drupal.ajax.prototype.commands[response[i]['command']](this, response[i], status, 'pmg_reltw-field-' + pmg_reltw_id);
          }
        }


      }
    };

    $.ajax(ajaxOptions);
  }

  Drupal.ajax.prototype.commands.pmg_reltwFieldUpdate = function (ajax, response, status, group_id) {
    // Replace the old HTML with the (relevant part of) retrieved HTML.
    $('#' + group_id, Drupal.ReltwField.context)
      .replaceWith($(response.output + 'text'));
  };


  Drupal.ReltwField.throwError = function (pmg_reltw_id, message) {
    // Show the error to the user.
    alert(message);

    // TODO - nice to have
    // Log the error. 
    //# Drupal.HierarchicalSelect.log(pmg_reltw_id, [ message ]);

    // TODO - nice to have
    // Re-enable the form to allow the user to retry, but reset the selection to
    // the level label if possible, otherwise the "<none>" option if possible.
    /*
     var $select = $('#pmg_reltw-field-' + pmg_reltw_id +'-wrapper .hierarchical-select .selects select:first');
     var levelLabelOption = $('option[value^=label_]', $select).val();
     if (levelLabelOption !== undefined) {
     $select.val(levelLabelOption);
     }
     else {
     var noneOption = $('option[value=none]', $select).val();
     if (noneOption !== undefined) {
     $select.val(noneOption);
     }
     }
     Drupal.HierarchicalSelect.enableForm(pmg_reltw_id);
     // */
  };

})(jQuery);


