// Add js for Google Events on clicked
jQuery(document).ready(function($) {
$("#block-block-rotator-rotating-block").load(function() {
  var loaded = $("section", this);
  if(loaded.attr('id') {
    ga("send", "event", "Rotating Block", "Loaded", loaded.attr('id'));
  }
});
