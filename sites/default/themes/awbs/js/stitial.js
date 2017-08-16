getIframe();

function getIframe() {
  var isInt = document.getElementById('google_ads_iframe_/152023730/AW_Interstitial_0');
	if (isInt.contentWindow.document.getElementById('glade-aslot-1') != null) {
		initShadowbox();
	} else {
		setTimeout("getIframe()", 1000);
	}
  }

function loadShadowBox() {

  var href, imgsrc, newnode;
  href = 'http://googleads.g.doubleclick.net/pcs/click?xai=AKAOjsuuqk2Va8BYPO8WlpV3l5aVkwa4cdlP_hb8l5DfKbX5GAsozXv-_tJlCm0TvzXHwvLtJANJR91KooZZ7jKgnFofrwNBwYf1DuhsbTcdkPz2gEP6QMXWCpBoWWBOuOhQD9Hkjh2p9YxAfupaPUtghXnxQUev1iBjU1Y7qPps_R0837Fm8MKGWBY_bkSnZOx6MVUGxEw7Hug7KHlIqyRi1GudOAG54_4nEPLexLNIiogCItJ2JVNx-iqGcp2Rkg&sig=Cg0ArKJSzP1FkU79vVHV&adurl=https://adclick.g.doubleclick.net/pcs/click%3Fxai%3DAKAOjsvCsZ_SUryJKDI_QaXuZqj9Au20xWWq3FCvaunvv-BytLSx1ECZZRP4M9H43w9D6aQAxSimyPBWwtIKvnLva7hRA4lZz2E5o-t7jrK1alivIsnSXj2na1G1Zjof0K0BXySK5taWZdYtDoCFazBcBWpkjSFwynbPk0C1BPiza-GHpVEnwn-QcAkqY0KF_WuvTviVQRqyd7lbhz6ERpizHbj5fDbzF30%26sig%3DCg0ArKJSzB7uwYGhh1UgEAE%26urlfix%3D1%26adurl%3Dhttp://www.mouser.com/te-fsmij-illuminated-tactile-switches/%253Futm_source%253DPublitekAutomationWorld%2526utm_medium%253Ddisplay%2526utm_campaign%253Dteconnectivitytycoelectronics-te-fsmij-illuminated-tactile-switches%2526utm_content%253Dsupplier-branded-640x480&nm=2&nx=165&ny=365&mb=2';
  imgsrc = '<img src="https://tpc.googlesyndication.com/simgad/5372016095261886544" border="0" width="640" height="480" class="img_ad">';
  newnode = '<div id="advertisement-shadowbox" style="color: white;"><a href="' + href + '">' + imgsrc + '</a></div>';

  if (document.getElementById('sb-container')) {
	// If the sb-container is there, load up the interstitial
	Shadowbox.open({
	content: newnode,
	player: "html",
	handleOversize: "resize",
	title: "ADVERTISEMENT",
	width: 640,
	height: 480
    });
  } else {
	// If sb-container doesn't exist, recursive until it does
	setTimeout("loadShadowBox()", 100);
	}
  }

// Boolean flag to know if Shadowbox has been loaded
var ShadowboxOutputted = false;

// Function to check for Shadowbox and if it's not available, load it.
function initShadowbox() {
// Checks if Shadowbox is exists
if (typeof(Shadowbox) == 'undefined') {
  // Checks if Shadowbox is has been loaded previously
  if (! ShadowboxOutputted) {
	//only output the script once..
	ShadowboxOutputted = true;
	//output the script
	document.write("<scr" + "ipt type=\"text/javascript\" src=\"sites/all/libraries/shadowbox/shadowbox.js\"></scr" + "ipt>");
	}
	// Recursive until Shadowbox is loaded
	setTimeout("initShadowbox()", 100);
	} 
	else {
	// Shadowbox is loaded, do the set up for it
	Shadowbox.init({
	// Let's skip the automatic setup because we don't have any properly
	// configured link elements on the page
	skipSetup: true
	});
	// Shadowbox looks to be loaded, let's run it
	loadShadowBox();
	}
  }



