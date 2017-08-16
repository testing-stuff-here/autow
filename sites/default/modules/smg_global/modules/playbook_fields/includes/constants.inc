<?php
define('DEPENDENCY_LIMIT', 10000);

/// SilverPop Soap API
define('SP_USERNAME', 'playbooksubmissions@summitmediagroup.com');
define('SP_PASSWORD', 'P!ayb00k10');
define('SP_WSDL', 'http://api5.silverpop.com/SoapApi?wsdl');
define('SP_XSD', 'SilverpopApi:EngageService.ListMgmt.RecipientActions');
define('SP_RTQ', 'SilverpopApi:EngageService.ListMgmt.UserActions');
define('SP_OPT_IN', 2); // Code for an opt-in
define('DATABASE_ID', '8847490'); // Summit Media Group Audience Database
define('RELATIONAL_TABLE_ID', '9088780'); // Relational Table ID
define('SP_SCRIPT_TIME_LIMIT', 840); ///limiting to 14 minutes

define('SP_COOKIE', 'http://contentz.mkt51.net/lp/static/js/iMAWebCookie.js?5872ae98-13481d0a159-d7c8ec57ae636c7258d3eb0ef0e531f2&h=www.pages05.net');
define('SP_COOKIE_SSL', 'https://www.sc.pages05.net/lp/static/js/iMAWebCookie.js?5872ae98-13481d0a159-d7c8ec57ae636c7258d3eb0ef0e531f2&h=www.pages05.net');
define('SP_TRACKING_DOMAINS', 'www.pages05.net,automationworld.com,e.packexpo.com,e.pmmi.org,e.pp-oem.com,e.profoodtech.com,greenerpackage.com,healthcarepackaging.com,lifescienceslogistics.com,opxleadershipnetwork.org,packworld.com,page.automationworld.com,page.biz-library.com,page.healthcarepackaging.com,page.packworld.com,theautomationconference.com,totallyintegratedautomation.com,www.automationworld.com,www.healthcarepackaging.com,www.packworld.com');

/// Silverpop XML API
define('SP_XAU', 'http://api5.silverpop.com/XMLAPI');

/// Account-specific values w/ AccelWorks.
//define('PLAYBOOKS_ACCELA_BILLCODE', 48);
//define('PLAYBOOKS_ACCELA_BILLCODE', 67);

// GotoWebinars
define('GOTO_WEBINAR_API_KEY', 'RC02kdcZ1VOp2KtF0LFry3HdY1BDKFhv');
define('REDIRECT_URL_AFTER_AUTHENTICATION', 'http://dev.hcp.255elmp02.blackmesh.com/oauth/oauth.php');
define('GOTO_WEBINAR_AUTH_TOKEN', 'a3FdOFIAKU4i3VDOPyWqkrcFA0SL'); // Expires 11/06/2017
define('GOTO_WEBINAR_ORGANIZER_KEY', '300000000000371046');

// Leadworks
define('LEADWORKS_BASE_URL', 'https://cloud.pmmimediagroup.com/api/reg');
define('LEADWORKS_FIELDS_QUERY', 'https://cloud.pmmimediagroup.com/api/getFieldValues');
define('LEADWORKS_APP_USER_POST', 'https://cloud.pmmimediagroup.com/api/appUserPost');
define('LEADWORKS_APP_USER_GET', 'https://cloud.pmmimediagroup.com/api/appUserGet');
define('LEADWORKS_VALIDATE_CAMPAIGN_FIELDS','https://cloud.pmmimediagroup.com/api/validateCampaignFields');

define('DEPENDENCY_TEXT', 'Enter a dependency rule to optionally enable this field. Rules take the form \'field_key\' = \'value\'. \'=\': equals. \'!=\': does not equal. \'^=\': begins with. \'!^=\': does not begin with. \'value\' is the submit value, if given, or the display value otherwise, lowercase, with all spaces and punctuation replaced with dashes: \'United States (of America)\' -> \'united-states-of-america\'. Rules can be combined using \'and\' or \'or\'. For example: (\'field_1\' = \'foo\') and (\'field_2\' != \'bar\'). Rules can be nested: ((\'field_1\' = \'united-states\') or (\'field_2\' != \'chicago\')) and (\'field_3\' ^= \'yes\'). All field keys and values are case-sensitive. <br /><br /> Radio Button Dependencies: For a radio button dependency you input \'field_key\' checked \'radio button number\' Ex:\'display-namefield\' checked \'1\'');
