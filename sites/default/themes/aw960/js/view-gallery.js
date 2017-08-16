function setSelected(which) {
  // Clear background colors
  jQuery("#view-gallery-minor .views-row").css('background-color', '#FFFFFF');
  // Set selected background color
  jQuery(which).css('background-color', '#D6EAF0');

  // Position selection arrow (pale blue triangle)
  this_offset = jQuery(which).offset();
  jQuery("#gallery-arrow").css('position', 'absolute').offset({'top': this_offset.top + (jQuery(which).height() / 2 - 12), 'left': this_offset.left - 13});

  // Set major image
  var src = jQuery(which).find(".views-field-field-image img").attr("src");
  if (src) {
    jQuery("#view-gallery-major-image img").attr("src", src);
  }
  else {
    jQuery("#view-gallery-major-image img").removeAttr("src");
  }

  // Set links to article
  path = jQuery(which).find(".views-field-path .field-content").html();
  jQuery("#view-gallery-major-image a").attr("href", path);
  jQuery("#view-gallery-major-title a").attr("href", path);

  // Set onclick Tracking
  for(i = 1; i <= 3; i++) {
    has_class = jQuery(which).hasClass("views-row-" + i);
    if(has_class) {
      event_name = "ga('send', 'event', 'Home Rotator Positioning', 'Article Position " + i +"']);";
      jQuery("#view-gallery-major-image a").attr("onclick", event_name);
      jQuery("#view-gallery-major-title a").attr("onclick", event_name);
    }
  }

  // Set major title
  jQuery("#view-gallery-major-title a").html(jQuery(which).find(".views-field-title .field-content").html());

  // Set major deckhead
  jQuery("#view-gallery-major-deckhead").html(jQuery(which).find(".views-field-field-deckhead .field-content").html());

  hideDeckhead();

}

function rotateGallery() {
  rotateGallery.current++;

  // Wrap around the end of the gallery
  if (rotateGallery.current >= jQuery("#view-gallery-minor .views-row").length) {
    rotateGallery.current = 0;
  }

  var which = jQuery("#view-gallery-minor .views-row").eq(rotateGallery.current);

  setSelected(which);
}

jQuery(window).bind('load', function() {
  // Set the major div to have the same height as the minor div
  jQuery("#view-gallery-major").height(jQuery("#view-gallery-minor").height());
  hideDeckhead();
});

jQuery(document).ready(function(jQuery) {
  // Set the major div to have the same height as the minor div
  jQuery("#view-gallery-major").height(jQuery("#view-gallery-minor").height());

  jQuery("#view-gallery-minor .views-row").mouseover(function() {
    // Stop auto-rotate
    clearInterval(gallery_interval);

    // Set this as the selected item
    setSelected(this);
  });

  jQuery("#view-gallery-major").mouseover(function() {
    // Stop auto-rotate
    clearInterval(gallery_interval);

    hideDeckhead();
  });

  jQuery("#view-gallery-minor .views-row").mouseout(function() {
    // Stop auto-rotate
    clearInterval(gallery_interval);

    // Set this as the selected item
    setSelected(this);

    hideDeckhead();
  });

  // Select first item
  setSelected(jQuery("#view-gallery-minor .views-row").first());

  // Start auto-rotate
  rotateGallery.current = 0;
  gallery_interval = setInterval(rotateGallery, 5000);
});

function hideDeckhead() {
  jQuery("#view-gallery-major-deckhead").show();
  var remaining_height = jQuery("#view-gallery-major").height() - jQuery("#view-gallery-major-image").outerHeight(true) - jQuery("#view-gallery-major-title").outerHeight(true);
  var deckhead_height = jQuery("#view-gallery-major-deckhead").outerHeight(true);

  if (deckhead_height < remaining_height) {
    jQuery("#view-gallery-major-deckhead").css('visibility', 'visible');
  }
  else {
    jQuery("#view-gallery-major-deckhead").css('visibility', 'hidden');
  }
}
