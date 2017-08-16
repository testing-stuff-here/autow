/**
 * Used for modifing the 360 gallery item to fit based on the width of the screen
 */

var width = getWidth();
var targetWidth = "900";
var targetHeight = "900";

if(width) {
  if(width < 1300) {
    var newWidth = width - 35;
    var targetWidth = newWidth;
	  var targetHeight = newWidth;
  }
}

/**
 * Returns the widh of the screen
 */
function getWidth() {
 if (self.innerWidth) {
    return self.innerWidth;
 }
 else if (document.documentElement && document.documentElement.clientHeight){
     return document.documentElement.clientWidth;
 }
 else if (document.body) {
     return document.body.clientWidth;
 }
 return 0;
}