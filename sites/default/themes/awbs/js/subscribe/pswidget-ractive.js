var $ = jQuery;

if (typeof ga === 'undefined') {
 var ga = function(a, b, c, d) {
  console.log('ga bypassed for ' + b);
 };
}


var ractive = new Ractive({
 el: 'pmmiSubscriptionWidget',
 template: '#template' || '',
 stripComments: true,
 data: {
  promptScrollOnPrimaryInput: false, // display a prompt to encourage the user to scroll the list?
  prevSuppliedEmail: '', //  previous supplied user email address
  hasPrevSuppliedEmail: false, // did the user provide an email earlier with the newsletter box?
  isThisCanada: false, // does the user's IP indiciate s/he's in Canada? #blamecanada
  userCountryCode: '', // what is the 2digit country code of the current user? #blamecanada
  cookiedUser: false, // is the user operating with a cookie?
  cookieDataLoaded: false, // has the cookie data record finished loading?
  userCookie: '', // what's the string from spUserID in the URL? (for reference)
  showIntro: true, // should the intro panel be showing?
  savingUserData: false, // is the form in the process of saving the user data up to the server?
  errorSavingUserData: false, // was there an error during saving the user data up to the server?
  savedUserData: false, // was the user's data successfully saved up to the server?
  prevKey: null, // store previous keypress (needed for primary input double tap)
  promptNew: false, // show the form's prompt to create a new company record?
  newEntry: false, // is the form working to generate a new company record?
  existingEntry: false, // is the form working with an existing company record?
  submitErrors: false, // were there errors during submission?
  companyData: {}, // store for company data.
  canadaOptIn: false, //  Did a Canadian opt in to the enewsletters? IMPORTANT!! Leave as false. #blamecanada
  prefersDigitalOnly: false, // Does the user prefer to not receive the magazine or digital magazine
  prefersHomeDelivery: false, // does the user prefer to receive at an address other than the company address?
  userPrefMagazine: false, // mimic whats in the cookie, but as a bool
  userPrefNewsFocus: false, // mimic whats in the cookie, but as a bool
  userPrefNewsNews: false, // mimic whats in the cookie, but as a bool
  fullHomeAddress: '', // code-built string of the full address of the current user
  otherJobDutySelected: false, // did the user select "other" from the job duty drop down?
  otherIndustrySelected: false, // did the user select "other" from the industry drop down?
  otherJobDutyExplain: '', // the explanation the user gave for chosing job duty - other
  otherIndustryExplain: '', // the explanation the user gave for choosing industry - other
  userInformation: { // a representation of the record that's returned upon requesting a cookie record using the spUserID url param. underscores are added upon receipt and removed upon depature up to the server.
   Email: "",
   AB_Split_Segment: "",
   AW_3rd_party_email: "",
   AW_Automation_Involvement: "",
   AW_Automation_Strategies: "",
   AW_Automation_Type: "",
   AW_BR_Playbook: "",
   AW_Classification: "",
   AW_Company_Size: "",
   AW_Demo_Date: "",
   AW_Engaged: "",
   AW_Industry: "",
   AW_Industry_Other: "",
   AW_Job_Duties: "",
   AW_Job_Duties_Other: "",
   AW_Mag_Pedigree: "",
   AW_Mag_Priority_Code: "",
   AW_Mag_Request: "",
   AW_Mag_Requested_Version: "",
   AW_Management: "",
   AW_Management_Level: "",
   AW_Omeda_Reader_Number: "",
   AW_Personal_Identifier: "",
   AW_Playbook_Batch_Process_Aggregate: "",
   AW_Playbook_Continuous_Process_Aggregate: "",
   AW_Playbook_Factory_and_Machine_Automation_Aggregate: "",
   AW_UPS_Data_Book: "",
   AW_Ver_Date: "",
   Address_1: "",
   Address_2: "",
   Affinity_PW_Machinery: "",
   Affinity_PW_Package_Development: "",
   Affinity_PW_Sustainability: "",
   Age_range: "",
   Agency: "",
   Annual_Company_Revenue: "",
   Assigned_NL_AW_Automation_Skills: "",
   Assigned_NL_AW_Feed_Forward: "",
   Aud_Dev_Circulation_AW: "",
   Aud_Dev_Circulation_HCP: "",
   Aud_Dev_Circulation_PW: "",
   Aud_Dev_Special_Reports_AW: "",
   Aud_Dev_Special_Reports_HCP: "",
   Aud_Dev_Special_Reports_PW: "",
   BizPage_UPS_LABS_White_Paper: "",
   Brand_AW: "",
   Brand_HCP: "",
   Brand_PMMI_for_AW: "",
   Brand_PMMI_for_PW: "",
   Brand_PP_OEM: "",
   Brand_PW: "",
   City: "",
   Comp_List_AW: "",
   Comp_List_Contract_Packaging: "",
   Comp_List_Greener: "",
   Comp_List_HCP: "",
   Comp_List_PW: "",
   Comp_List_Status: "",
   Company: "",
   Country: "",
   Custom_NL_Automation_Direct: "",
   Custom_NL_Automation_Strategies: "",
   Custom_NL_Campaign_UPS_HCP_Playbook: "",
   Custom_NL_FDT_Device_Integration_Strategies: "",
   Custom_NL_Mfg_Intelligence: "",
   Custom_NL_OPC: "",
   Custom_NL_PROFInews_NA: "",
   Custom_NL_PW_Siemens_TIA: "",
   Custom_NL_Pro_Mach_2012: "",
   Custom_NL_Siemens_TIA: "",
   Custom_NL_Siemens_TIA_Automotive_Edition: "",
   Customer_Field_CSIA_Type: "",
   Customer_Field_Cognex_Business: "",
   Customer_Field_Cognex_Industry: "",
   Customer_Field_Cognex_Involved_Machine_Vision: "",
   Customer_Field_Cognex_Upcoming_Project: "",
   Customer_Field_RedLion_Current_Meter_Supplier: "",
   Customer_Field_RedLion_Part_Number: "",
   Customer_Field_Siemens_Industry: "",
   Customer_Field_Siemens_List_Source: "",
   Customer_Field_Siemens_Region: "",
   Customer_Field_Siemens_Subset_List: "",
   Customer_Field_UPS_Industry: "",
   Customer_Field_UPS_LABS_Industry: "",
   Customer_Field_UPS_Sustainable_opt_in: "",
   Customer_Field_UPS_account: "",
   Customer_Field_UPS_employee_size: "",
   Customer_Field_UPS_opt_in: "",
   Customer_Fields_UPS_Sustainable_Industry: "",
   Customer_Lead_Gen_Form_Cognex: "",
   Customer_Lead_Gen_Form_RedLion: "",
   Customer_Lead_Gen_Form_UPS_LABS: "",
   Customer_Lead_Gen_Form_UPS_LABS_2012_Q2: "",
   Customer_Lead_Gen_Form_UPS_sustainable: "",
   Customer_Lead_Gen_Form_UPS_sustainable_2012_Q2: "",
   Customer_List_Belden: "",
   Customer_List_Emerson_Exchange: "",
   Customer_List_Epson_Surepress: "",
   Customer_List_FDT_group: "",
   Customer_List_OPC: "",
   Customer_List_Omron: "",
   Customer_List_Pro_Mach: "",
   Customer_List_Profinews: "",
   Customer_List_Siemens_AW_TIA: "",
   Customer_List_Siemens_TIA: "",
   Customer_List_UPS: "",
   Email_Capture_Content: "",
   Email_Capture_Position: "",
   Email_Capture_Source: "",
   Email_only: "",
   Email_Medium: "",
   Engaged_Legacy_AW: "",
   Engaged_Legacy_PW_HCP: "",
   Fax: "",
   First_name: "",
   Full_Name: "",
   Generic_UPS_CRO_White_Paper: "",
   HCP_3rd_party_email: "",
   HCP_Classification: "",
   HCP_Custom_Campaign_Dupont_Medical_Device: "",
   HCP_Demo_Date: "",
   HCP_Dupont_eblast: "",
   HCP_Engaged: "",
   HCP_LearningLogistics_UPS: "",
   HCP_Mag_Pedigree: "",
   HCP_Mag_Priority_Code: "",
   HCP_Mag_Request: "",
   HCP_Mag_Requested_Version: "",
   HCP_Omeda_Reader_Number: "",
   HCP_Personal_Identifier: "",
   HCP_Playbook_Nosco_Aggregate: "",
   HCP_Playbook_Serialization_Aggregate: "",
   HCP_Ver_Date: "",
   HCP_Webinar_UPS_Aggregate: "",
   HCP_iPad_Promo: "",
   Import_Check: "",
   Import_memo: "",
   Insights_Average_read_time: "",
   Insights_Common_device: "",
   Insights_Engagement_Category: "",
   Insights_common_region: "",
   Last_Clicked: "",
   Last_Engaged_Date_AW: "",
   Last_Engaged_Date_HCP: "",
   Last_Engaged_Date_PW: "",
   Last_Opened: "",
   Last_Sent: "",
   Last_name: "",
   Legacy_Creation_Date: "",
   NL_AW_Automation_Focus: "",
   NL_AW_Automation_Skills: "",
   NL_AW_Best_Of_Blogs: "",
   NL_AW_Continuous_Processing: "",
   NL_AW_Factory_Automation: "",
   NL_AW_Food_Bev_Pharma: "",
   NL_AW_Global_Edition: "",
   NL_AW_Industrial_Internet_of_Things: "",
   NL_AW_News_Insights: "",
   NL_AW_Product_Insights: "",
   NL_PP_OEM_Digital_Edition: "",
   NL_PP_OEM_Focus: "",
   NL_PP_OEM_Newsletter: "",
   NL_PW_Contract_Packaging: "",
   NL_PW_Contract_Packaging_Focus: "",
   NL_PW_Greener_Package: "",
   NL_PW_HCP_Healthcare_Packaging: "",
   NL_PW_HCP_Healthcare_Packaging_Focus: "",
   NL_PW_HCP_Quick_Hits: "",
   NL_PW_Live_from_Pack_Expo: "",
   NL_PW_Machine_Automation_Insights: "",
   NL_PW_New_Issue_Alert: "",
   NL_PW_New_Machines: "",
   NL_PW_On_the_Edge: "",
   NL_PW_Pack_Expo_Wrap: "",
   NL_PW_Package_Development: "",
   NL_PW_Packaging_Focus: "",
   NL_PW_Packaging_Insights: "",
   NL_PW_Playbook_End_of_line: "",
   NL_PW_Playbook_Flexible: "",
   NL_PW_Playbook_Labeling: "",
   NL_PW_Playbook_Package_ID: "",
   NL_PW_Playbook_Primary: "",
   NL_PW_Shelf_Impact: "",
   NL_PW_Spotlight_on_Pack_Expo: "",
   NL_PW_Spotlight_on_Pack_Expo_East: "",
   NL_PW_eClip: "",
   NL_Trade_Show_Reports: "",
   Negative_Quality_Score_PW_Behavior: "",
   Negative_Quality_Score_PW_Rank: "",
   Negative_Quality_Score_PW_Score: "",
   Opt_out_Prospecting_Email: "",
   PMMI_Attendee_Type: "",
   PMMI_Buy_Recommend: "",
   PMMI_Demo_Date: "",
   PMMI_Employer_Member_Type: "",
   PMMI_Experient_ID: "",
   PMMI_Influence: "",
   PMMI_Member_Number: "",
   PMMI_Personify_ID: "",
   PMMI_Random_Segment: "",
   PMMI_Spend_Authorize: "",
   PMMI_OptOut: "",
   PP_OEM_Annual_Revenues: "",
   PP_OEM_Company_Login: "",
   PP_OEM_Company_number: "",
   PP_OEM_Industry: "",
   PP_OEM_Job_Duties: "",
   PP_OEM_Reader_number: "",
   PP_OEM_Verification_Date: "",
   PP_OEM_Industry_Other: "",
   PP_OEM_Job_Duties_Other: "",
   PW_3rd_party_email: "",
   PW_Automation_Type: "",
   PW_Classification: "",
   PW_Comp_List_Priority_Code: "",
   PW_Custom_NL_Siemens_TIA: "",
   PW_Demo_Date: "",
   PW_Engaged: "",
   PW_HCP_Buying_influence: "",
   PW_HCP_Company_Size: "",
   PW_HCP_Contract_Packaging: "",
   PW_HCP_Industry: "",
   PW_HCP_Industry_Other: "",
   PW_HCP_Job_Duties_Multi_Select: "",
   PW_HCP_Job_Duties_Other: "",
   PW_HCP_Job_Duties_Primary: "",
   PW_HCP_Management: "",
   PW_HCP_Management_Level: "",
   PW_HCP_Perform_Contract_Packaging: "",
   PW_HCP_Private_Label: "",
   PW_HCP_Simple_Industry: "",
   PW_Mag_Pedigree: "",
   PW_Mag_Priority_Code: "",
   PW_Mag_Request: "",
   PW_Mag_Requested_Version: "",
   PW_Omeda_Reader_Number: "",
   PW_Personal_Identifier: "",
   PW_Playbook_End_of_Line_Aggregate: "",
   PW_Playbook_Flexible_Aggregate: "",
   PW_Playbook_Food_Safety_Aggregate: "",
   PW_Playbook_Labeling_Aggregate: "",
   PW_Playbook_Package_Development_Aggregate: "",
   PW_Playbook_Packaging_Machinery_Aggregate: "",
   PW_Playbook_Primary_Aggregate: "",
   PW_Showcase: "",
   PW_Survey_SI_Innovations: "",
   PW_UPS_CRO_White_Paper: "",
   PW_UPS_Data_Book: "",
   PW_Ver_Date: "",
   PW_Webinar_Mitsubishi: "",
   PW_Webinar_Omron: "",
   PW_Webinar_SAP: "",
   PW_iPad_Promo: "",
   Permission_ACHEMA: "",
   Permission_AW_360: "",
   Permission_AW_ABB: "",
   Permission_AW_Belden_Custom_Newsletter: "",
   Permission_AW_Belden_Webinar: "",
   Permission_AW_Convergence_Ebook: "",
   Permission_AW_Digital_Edition: "",
   Permission_AW_Emerson_Exchange: "",
   Permission_AW_FDT_ebook: "",
   Permission_AW_Festo_Webinar: "",
   Permission_AW_NL_Automation_Strategies: "",
   Permission_AW_TAC_Editorial: "",
   Permission_AW_TIA_Automotive_Edition: "",
   Permission_AW_TacticalBrief: "",
   Permission_AW_eplan_cobranded: "",
   Permission_HCP_Digital_Edition: "",
   Permission_HCP_Dupont_Medical_Device: "",
   Permission_HCP_Healthcare_Logistics_Minute: "",
   Permission_HCP_Healthcare_Logistics_Survey: "",
   Permission_HCP_Healthcare_Logistics_Update: "",
   Permission_HCP_Labs_WhitePaper_UPS: "",
   Permission_HCP_LearningLogistics_UPS: "",
   Permission_HCP_PMMI: "",
   Permission_HCP_RX_Update: "",
   Permission_HCP_TacticalBrief_Cryopak: "",
   Permission_HCP_Webinar_UPS: "",
   Permission_HCP_ebook_DDL: "",
   Permission_House_Editorial: "",
   Permission_Market_Line: "",
   Permission_NL_GE_2014: "",
   Permission_PW_Digital_Edition: "",
   Permission_PW_Machine_Automation_Playbook: "",
   Permission_PW_PMMI: "",
   Permission_PW_TAC_Editorial: "",
   Permission_PW_playbook_End_of_Line: "",
   Permission_PW_playbook_Flexible: "",
   Permission_PW_playbook_Food_Safety: "",
   Permission_PW_playbook_Primary: "",
   Permission_PW_playbook_Workforce_Development: "",
   Permission_PW_playbook_labeling: "",
   Permission_PW_playbook_package_dev: "",
   Permission_Playbook_Call_for_Experts: "",
   Permission_TAC_promo: "",
   Permission_TacticalBrief_SICK: "",
   Permission_AW_Batch_Process_Playbook: "",
   Permission_AW_Beckoff_Webinar: "",
   Permission_AW_CoBranded_Newsletters: "",
   Permission_AW_Continuous_Process_Playbook: "",
   Permission_AW_Dive_Deep_Video: "",
   Permission_AW_Factory_and_Machine_Automation_Playbook: "",
   Permission_AW_GE_Webinar: "",
   Permission_AW_NI_Video: "",
   Permission_AW_SICK_Machine_Safety_Newsletter: "",
   Permission_AW_ShowDaily_Schneider: "",
   Permission_AW_SpecialEnhancedContent: "",
   Permission_AW_Survey_Eaton: "",
   Permission_AW_specialevents: "",
   Permission_HCP_LifeScienceMaterials_Playbook: "",
   Permission_HCP_Serialization_Playbook: "",
   Permission_HCP_SpecialEnhancedContent: "",
   Permission_PW_CalPoly_Webinar: "",
   Permission_PW_SpecialEnhancedContent: "",
   Permission_PW_ThermoFisher_Webinar: "",
   Permissions_AW_Survey: "",
   Permissions_PW_Survey: "",
   Permissions_PW_TechMin: "",
   Phone: "",
   Promo_AW_Digital: "",
   Promo_AW_issue: "",
   Promo_HCP_Digital: "",
   Promo_HCP_issue: "",
   Promo_Leadership_AW: "",
   Promo_Leadership_PW: "",
   Promo_PP_OEM_issue: "",
   Promo_PW_Digital: "",
   Promo_PW_issue: "",
   Promo_SPS: "",
   Promo_TAC: "",
   Promo_apps: "",
   Registration_Capture_Content: "",
   Registration_History: "",
   Salesforce_Lead_ID: "",
   Segmenting: "",
   Send_Hour: "",
   State: "",
   Summit_Sales_Rep: "",
   Title: "",
   Toyota_Email: "",
   UPS_LABS_White_Paper: "",
   Unsubscribe_Reason_AW: "",
   Unsubscribe_Reason_HCP: "",
   Unsubscribe_Reason_PW: "",
   Zip: ""
  },
  /**
   * NOTE: for all drop downs it's important that the LAST value in the array is
   * ~ALWAYS~ the "other" option, in order for form logic to work properly.
   */
  selectedJobDuty: "Job duty", // default selection of the job duty drop down
  jobduties: ["Job duty", "Engineering", "Production/Manufacturing", // data to populate the job duty drop down
   "Service/Support",
   "Purchasing", "Marketing/Brand Manager", "Sales",
   "CEO/Gen Mgr/Other Senior Mgmt", "Other"
  ],
  selectedIndustry: "Select industry", // default selection of the industry drop down
  industries: ["Select industry", "Packaging Machinery OEM", // data to populate the industry drop down
   "Processing Machinery OEM",
   "Converting Machinery OEM",
   "Plastics Machinery OEM",
   "Systems Integrator",
   "Other (please specify)"
  ],
  selectedRevenue: "Annual revenue", // default selection of the revenue drop down
  revenues: ["Annual revenue", "Under $10 million", // data to populate the revenue drop down
   "$10 to $20 million",
   "$20 to $50 million",
   "Over $50 million"
  ],
  isBizEmail: false, // did the user input a disallowed, generic business email (info@, sales@, marketing@, etc)
  homeGoogleData: [], // Data store for data returned from the Home address Google places autocomplete field
  compGoogleData: [] // Data store for data returned from the Business address Google places autocomplete field
 },
 /**
  * Called when the Object, holding the email address entered on a separate
  * newsletter signup box, changes values. Object.watch triggers a call to
  * ractive.togglePrevEmail
  */
 togglePrevEmail: function() {
  if (!this.get('cookiedUser')) { // if they're already "signed in", we don't want to change their email on them.
   this.toggle('hasPrevSuppliedEmail'); // toggle the boolean
   if (this.get('hasPrevSuppliedEmail')) { // if it's now true
    // this.set('prevSuppliedEmail', viaNewsletter.userEmail); // pull the value from the object into a placeholder in our data model
    this.set('userInformation.Email', this.get('prevSuppliedEmail')); // then into the user data object, which populates the form.
   } else { // if it's now false
    this.set('prevSuppliedEmail', ''); // emptry the holder.
    this.set('userInformation.Email', ''); // ...and the form input.
   }
  }
 },
 // fired when a user selects a company from the company select dropdown list
 // sets state of the form and starts "existing company" processes.
 listSelect: function(event, ui) {
  this.set('prevKey', null);
  this.set('promptNew', false);
  this.set('existingEntry', true);
  this.set('companyData', ui.item.data);
  $("#primary-input").blur().focusout();
  ga('send', 'event', 'PP OEM Subscription Form',
   'Selected from existing company list',
   'Input action');
 },
 //validate select dropdowns
 selectValidate: function(f) {
  var _this = this; // to avoid JS scope problems.
  var feedOption = _this.get('userInformation.PP_OEM_Job_Duties'); // data provided by the API endpoint
  var optionsListValues = []; // to be populated with values from the input control
  var optionsList = $(f).children().toArray(); // a list of all options in the given select box, converted to array
  optionsList.shift(); // remove the first element (the placeholder)
  optionsList.forEach(function(i, key) { // loop through the remaining values
   optionsListValues[i.value] = key; // for "in" to work later, the value we're seeking against needs to be the key, not the value.
  });

  // if the option provided by the cookie record is in our list, it's approved,
  // and we'll mark the field as valid in the form.
  if (feedOption in optionsListValues) {
   $(f).removeClass('error').addClass('is-selected is-approved');
   $("+ * + div i", f).removeClass('fa-asterisk').fadeIn(500).addClass(
    'fa-check reqover');
   return;
  } else { // otherwise, the provided value is invalid and we'll have to mark it as invalid in the form
   $(f).addClass('error').removeClass('is-selected is-approved');
   if ($('+ * + div i', f).hasClass('fa-check')) {
    $("+ * + div i", f).removeClass('fa-check reqover').fadeIn(
     500).addClass(
     'fa-asterisk');
   }
   return;
  }
 },
 // validate that something is there in general
 generalValidate: function(f) {
  if ($(f).val() === '') {
   $(f).addClass('error').removeClass('is-approved');
   if ($('+ * + div i', f).hasClass('fa-check')) {
    $("+ * + div i", f).removeClass('fa-check reqover').fadeIn(
     500).addClass(
     'fa-asterisk');
   }
   $("+ .speciallabel", f).slideUp(500).addClass('notyet');
   return;
  }

  // check that minlength value is met
  if (($(f).val().length <= $(f).attr('minlength'))) {
   if (!$(f).hasClass('error')) {
    $(f).addClass('error').removeClass('is-approved');
    $("+ * + div i", f).removeClass('fa-check reqover').fadeIn(
     500).addClass(
     'fa-asterisk');
   }
   return;
  }

  // if the two above were there, its ok to approve.
  $(f).removeClass('error').addClass('is-approved');

  $("+ * + div i", f).removeClass('fa-asterisk').fadeIn(500).addClass(
   'fa-check reqover');

  $("+ .speciallabel", f).slideUp(500).addClass('notyet');
  return;
 },

 phoneValidate: function(f) {
  // if the field isn't empty
  if ($(f).val() !== '') {
   // if the field isnt the minimum US length and isn't empty, it's an error
   if (($(f).val().length !== 14) && ($(f).val() !== '')) {
    $(f).addClass('error').removeClass('is-approved');
    $("+ * + div i", f).removeClass('fa-check reqover').fadeIn(500).addClass(
     'fa-asterisk');
   }

   // this is not a required field, so if it's empty, leave it alone.
   if ($(f).val() === '') {
    $(f).removeClass('error');
    $("+ * + div i", f).fadeOut(500).removeClass(
     'fa-asterisk fa-check reqover');
   }

   // if the field is the proper US length, since we masked it, we'll
   // assume it's accurate and approve it.
   if ($(f).val().length === 14) {
    $(f).removeClass('error').addClass('is-approved');

    $("+ * + div i", f).removeClass('fa-asterisk').fadeIn(500).addClass(
     'fa-check reqover');

    $("+ .speciallabel", f).slideUp(500).addClass('notyet');
    return;
   }
  } else {
   $("+ * + div i", f).fadeOut(500).removeClass('fa-asterisk');
   $("+ .speciallabel", f).slideUp(500).addClass('notyet');
   return;
  }
 },
 emailValidate: function(f) {
  var val = $(f).val();
  this.set('isBizEmail', false); // set the undesirable email flag to false

  // if it's empty, it's an error
  if (val.length === 0) {
   $(f).addClass('error').removeClass('is-approved');
   $("+ * + div i", f).removeClass('fa-check reqover').fadeIn(500).addClass(
    'fa-asterisk');
   $("+ .speciallabel", f).slideUp(500).addClass('notyet');
   return;
  }

  // if it's not empty
  if (val.length > 0) {
   // but its less than five characters
   if (val.length <= 5) { // error time!
    $(f).addClass('error').removeClass('is-approved');
    $("+ * + div i", f).removeClass('fa-check reqover').fadeIn(
     500).addClass(
     'fa-asterisk');
    $("+ .speciallabel", f).slideUp(500).addClass('notyet');
   }

   // check for 'undesirable' email names
   var rr = /(?:info|sales|sale|help|marketing)/ig;

   // Added to make regex case insensitive and not look at anything after the @
   var xy = val.indexOf("@");
   if (xy <= 0) {
    $(f).addClass('error').removeClass('is-approved');
    $("+ * + div i", f).removeClass('fa-check reqover').fadeIn(
     500).addClass(
     'fa-asterisk');
    $("+ .speciallabel", f).slideUp(500).addClass('notyet');
    ga('send', 'event', 'PP OEM Subscription Form',
     'Entered an incomplete email',
     'Input action');
    return;
   }

   var xz = val.substring(0, xy);

   if (rr.test(xz)) {
    this.set('isBizEmail', true);
    $(f).addClass('error').removeClass('is-approved');
    $("+ * + div i", f).removeClass('fa-check reqover').fadeIn(
     500).addClass(
     'fa-asterisk');
    $("+ .speciallabel", f).slideUp(500).addClass('notyet');
    ga('send', 'event', 'PP OEM Subscription Form',
     'Tried to enter a marketing email',
     'Input action');
    return;
   }

   // validate against known email patterns.
   var r =
    /([-!#-'*+/-9=?A-Z^-~]+(\.[-!#-'*+/-9=?A-Z^-~]+)*|"([]!#-[^-~ \t]|(\\[\t -~]))+")@[0-9A-Za-z]([0-9A-Za-z-]{0,61}[0-9A-Za-z])?(\.[0-9A-Za-z]([0-9A-Za-z-]{0,61}[0-9A-Za-z])?)*\.(net|org|com|info|etc|co.*|aero|coop|info|museum|name|biz|xxx|ac|af|ax|al|dz|us|as|ad|ao|ai|aq|ag|an|ar|am|aw|au|at|az|bs|bh|bd|bb|by|be|bz|bj|bm|bt|bo|ba|bw|bv|br|io|bn|bg|bf|mm|bi|kh|cm|ca|cv|ky|cf|td|cl|cn|cx|cc|co|km|cd|cg|ck|cr|ci|hr|cu|an|cy|cz|dk|dj|dm|do|tp|ec|eg|sv|uk|gq|er|ee|et|eu|fo|fj|fi|fr|gf|pf|tf|ga|gm|ge|gs|de|gh|gi|gb|gr|gl|gd|gp|gu|gt|gg|sr|gf|gn|gw|gq|pg|gy|ht|hm|va|hn|hk|hr|hu|is|in|io|id|ir|iq|ie|im|il|it|ci|jm|jp|je|jo|kz|cc|ke|ki|kn|kp|kr|kw|kg|lk|la|lv|lb|ls|lr|ly|li|lt|lc|lu|mo|mk|mg|mw|my|mv|ml|mt|fk|mp|mh|mr|mu|yt|fm|mx|md|mc|mn|me|ms|ma|mz|mm|na|nr|np|nl|an|nc|pg|nz|ni|ne|ng|nu|nf|mp|kp|no|om|pk|pw|ps|pa|pg|py|pe|ph|pm|pn|pl|pf|pt|pr|qa|re|ro|ru|rw|sh|kn|lc|vc|sv|as|sm|gs|st Arabia|sa|sn|rs|me|cs|rs|sc|sl|sg|sk|si|sb|so|za|kr|su|es|lk|sd|sr|sj|sz|se|ch|sy|tw|tj|tz|thno|tp|tl|tg|tk|to|tt|tn|tr|tm|tc|tv|ug|ua|ae|uk|us|um|vi|uy|uz|vu|va|ve|vn|vg|vi|wf|eh|ws|ye|yu|me|rs|zr|zw|zm)/ig;
   if (r.test(val)) {
    $(f).removeClass('error').addClass('is-approved');
    $("+ * + div i", f).removeClass('fa-asterisk').fadeIn(500).addClass(
     'fa-check reqover');

    $("+ .speciallabel", f).slideUp(500).addClass('notyet');
    ga('send', 'event', 'PP OEM Subscription Form',
     'Entered a malformed email',
     'Input action');
    return;
   } else {
    $(f).addClass('error');
    $("+ * + div i", f).removeClass('fa-check reqover').fadeIn(
     500).addClass(
     'fa-asterisk');
    $("+ .speciallabel", f).slideUp(500).addClass('notyet');
    return;
   }
  }
 },
 /**
  * Modularizes the logic for handling various subscription delivery
  * preferences and rules.
  */
 handleHomeDeliveryPrefs: function() {
  var _this = this; // avoid JS scope issues
  // handle how to record the address on the subscriber record...
  if (_this.get('prefersHomeDelivery')) { // if they prefer home delivery
   console.debug(_this.get('homeGoogleData.street_l'));
   // we write the address for delivery to the cookie record
   // If the Google Places holder object for the home address is empty, we assume
   // that this is a resubmit without a change to the address and we save the values
   // against itself.

   _this.set('userInformation.Address_1', (typeof _this.get(
     'homeGoogleData.street_l') === 'undefined') ? _this.get(
     'userInformation.Address_1') :
    _this.get('homeGoogleData.num_l') +
    " " + _this.get('homeGoogleData.street_l'));

   _this.set('userInformation.City', (typeof _this.get(
    'homeGoogleData.city_l') === 'undefined') ? _this.get(
    'userInformation.City') : _this.get('homeGoogleData.city_l'));

   _this.set('userInformation.State', (typeof _this.get(
    'homeGoogleData.state_l') === 'undefined') ? _this.get(
    'userInformation.State') : _this.get('homeGoogleData.state_l'));

   _this.set('userInformation.Zip', (typeof _this.get('homeGoogleData.zip_l') ===
    'undefined') ? _this.get('userInformation.Zip') : _this.get(
    'homeGoogleData.zip_l'));

   _this.set('userInformation.Country', (typeof _this.get(
    'homeGoogleData.country_l') === 'undefined') ? _this.get(
    'userInformation.Country') : _this.get('homeGoogleData.country_l'));

  } else { // if they dont prefer home delivery
   // we'll copy the company data to their record.
   _this.set('userInformation.Address_1', _this.get(
    'companyData.address_1'));
   _this.set('userInformation.Address_2', _this.get(
    'companyData.address_2'));
   _this.set('userInformation.City', _this.get('companyData.city'));
   _this.set('userInformation.State', _this.get('companyData.state'));
   _this.set('userInformation.Zip', _this.get('companyData.zipcode'));
   _this.set('userInformation.Country', _this.get('companyData.country'));
  }
 },
 handleOptInFactors: function() {
  var _this = this;

  // What is their preference in regards to the actual magazine?
  if (_this.get('prefersDigitalOnly')) { // If they don't want the magazine
   _this.set("userInformation.NL_PP_OEM_Digital_Edition", "No");
  } else { // or if they do
   _this.set("userInformation.NL_PP_OEM_Digital_Edition", "Yes");
  }

  // If the subscriber is in Canada and they've opted in on the form for
  // receiving electronic newsletters, flag them as accepting. #blamecanada
  if ((_this.get('isThisCanada')) && (_this.get('canadaOptIn'))) {
   _this.set("userInformation.NL_PP_OEM_Newsletter", "Yes");
   _this.set("userInformation.NL_PP_OEM_Focus", "Yes");
  }

  // If the subscriber is in Canada and they've NOT opted in for receiving
  // eletronic newsletters, flag them as rejecting. #blamecanada
  if ((_this.get('isThisCanada')) && (!_this.get('canadaOptIn'))) {
   _this.set("userInformation.NL_PP_OEM_Newsletter", "No");
   _this.set("userInformation.NL_PP_OEM_Focus", "No");
  }

  // If the subscriber isn't in Canada, screw it - they're getting both
  // newsletters. They can opt out later.
  if (!_this.get('isThisCanada')) {
   _this.set("userInformation.NL_PP_OEM_Newsletter", "Yes");
   _this.set("userInformation.NL_PP_OEM_Focus", "Yes");
  }
 },
 /**
  * Called on initialization of the Ractive object (the form itself)
  */
 oninit: function() {
  var _this = this; // avoid JS scope issues later on
  var requestParam; // holder for the URL params
  var requestURL; // holder for the URL itself

  // ajax to get country information
  $.ajax({
   url: "//www.geoplugin.net/json.gp?jsoncallback=?", // need the jsoncallback=? to not error on return
   type: 'GET',
   contentType: 'JSON', // NOT JSONP
   dataType: 'JSON', // NOT JSONP
   success: function(data) {
    console.debug(data.geoplugin_countryName);
    _this.set('userCountryCode', data.geoplugin_countryCode); // set the country code variable
    if (data.geoplugin_countryCode === 'CA') { // if the user is in Canada, #blamecanada
     _this.set('isThisCanada', true); // set the canada variable to true #blamecanada
     ga('send', 'event', 'PP OEM Subscription Form',
      'Visitor from Canadian IP',
      'Input action');
    }
    //	_this.set('isThisCanada', true); // TODO: remove
   },
   error: function(data) { // If there's an error with the ip lookup
    console.debug('failed to geolocate ip.');
   }
  });



  var noUserData = (typeof QueryString.spUserID === 'undefined') ||
   (QueryString.spUserID === '');

  if (noUserData) {
   noUserData = (document.cookie.indexOf('reader_token') === -1); // change to reader_token
  }


  // check if an email was passed from a newsletter signup box into the subscribe form.
  // this will only work if the user isn't already "signed in".
  // since the email is the primary key for our database, we dont want them
  // overwriting their instance, and getting multiple mails/mags.
  if ((typeof QueryString.email !== 'undefined') && (QueryString.email !==
    '')) {
   _this.set('hasPrevSuppliedEmail', true);
   _this.set('prevSuppliedEmail', decodeURIComponent(QueryString.email)); // need to decode the email address from the URL
   var currentUrl = window.location.href; // browser's current URL on display
   var newUrl; // holder for the new url we'll replace it with
   newUrl = UpdateQueryString('email', '', currentUrl); // set the displayPrefs param to false
   history.replaceState(null, null, newUrl); // push the new, updated url into the browser address bar w/o reloading the page
   history.pushState(null, null, newUrl); // push that same url into the browser history
   ga('send', 'event', 'PP OEM Subscription Form',
    'New signup via newsletter box in article',
    'Input action');
  }


  // check if spUserID is to be found in the browser's URL
  if (noUserData) {
   console.debug('no cookie detected.'); // if not found
   if (_this.get('hasPrevSuppliedEmail')) {
    _this.set('userInformation.Email', _this.get('prevSuppliedEmail'));
   }
  } else { // if it was found...
   console.debug('cookie detected.');
   this.set('cookiedUser', true); // set cookie to true
   console.debug("QS", QueryString.spUserID);
   this.set('userCookie', QueryString.spUserID); // set the cookie string value
   setTimeout(function() { // super fast change out to the cookie panel
    _this.set('showIntro', false);
    ga('send', 'event', 'PP OEM Subscription Form',
     'Cookied visitor evoked preference panel',
     'Input action');
   }, 2); // we need an ever so ~slight~ delay to make this work.


   // ajax call to get cookie data
   $.ajax({
    url: '//www.pp-oem.com/api/v1/silverpop/retrieve',
    dataType: 'jsonp',
    type: 'GET',
    data: {
     spUserID: (typeof QueryString.spUserID === 'undefined') ||
      (QueryString.spUserID === '') ? '' : _this.get('userCookie')
    },
    success: function(data) { // once the cookie record successfully returns from the server
     var new_data = {}; // temporary store for the data, once we underscore it.


     if (data.Phone !== '') {
      data.Phone.replace(/[^1-9]/g, ''); // a lot of the phone numbers are "malformed". we need to fix that.

      if (data.Phone.indexOf("(", 0) === -1) { // look for opening parentheses
       data.Phone = "(" + data.Phone;
      }

      if (data.Phone.indexOf(")", 4) === -1) { // look for closing parentheses
       data.Phone = data.Phone.slice(0, 4) + ") " + data.Phone.slice(
        4, -1);
      }

      if (data.Phone.indexOf("-", 9) === -1) { // look for the dash separating exchange from local
       data.Phone = data.Phone.slice(0, 9) + "-" + data.Phone.slice(
        9, -1);
      }
     }

     // to make things easier and make JSHINT not freak out, we'll underscore
     // any spaces into our temporary store for the cookie record
     for (var key in data) {
      new_data[key.replace(/ /g, '_')] = data[key];
     }
     _this.set('cookieDataLoaded', true); // flag that the data is not ready to display


     // Set flag for home delivery option
     if (new_data.Prefers_Home_Delivery === "Yes") {
      _this.set('prefersHomeDelivery', true);
     } else {
      _this.set('prefersHomeDelivery', false);
     }


     _this.set('userInformation', new_data); // load the temporary data store into the cookie record repo
     _this.set('selectedJobDuty', new_data.PP_OEM_Job_Duties); // set the job duties value.

     requestURL =
      "//leadworks.pmmimediagroup.com/api/getCompaniesByName"; // lookup the company data

     requestParam = {
      "name": _this.get("userInformation.Company") // by the comapny name
     };
     // if this person is requesting home delivery, then call back to the server
     // and request a copy of the company data based on the pp_oem_company_number
     $.ajax({
      url: requestURL,
      type: "GET",
      data: requestParam,
      dataType: "jsonp",
      success: function(data) {
       _this.set('companyData', data[0]); // first object.
       // not currently relevant to AW
       // _this.set('userInformation.PP_OEM_Company_number', _this.get(
       // 	'companyData.pp_oem_company_number')); // save for future reference
      },
      // if there are errors, we leave the company data blank.
      fail: function(result) {
       _this.set('companyData', []);
       _this.set('companyData.company_name', _this.get(
        'userInformation.Company'));
      },
      error: function(result) {
       _this.set('companyData', []);
       _this.set('companyData.company_name', _this.get(
        'userInformation.Company'));
      }
     });


     // If home delivery flag is set, ask for the company data via an API call.
     // If not set, copy (as below) the company data from the cookie
     if (!_this.get('prefersHomeDelivery')) { // "no" to home delivery, so, IOW, delivers to company address
      // _this.set('companyData.company_name', new_data.Company);
      // _this.set('companyData.address_1', new_data.Address_1);
      // _this.set('companyData.address_2', new_data.Address_2);
      // _this.set('companyData.city', new_data.City);
      // _this.set('companyData.state', new_data.State);
      // _this.set('companyData.zipcode', new_data.Zip);
      // _this.set('companyData.country', new_data.Country);
     } else { // "yes" to home delivery, IOW, deliver to somewhere other than the company address
      // build the fake address string that sits inside the home address input
      var placedAddress = new_data.Address_1 + ", " + new_data.City +
       ", " +
       new_data.State + ", " + new_data.Country;
      _this.set('fullHomeAddress', placedAddress); // set that fake address string into the input's value


     }

     // Preferences for Magazine (Print/Digital) and e-newsletters
     if (_this.get('userInformation.NL_PP_OEM_Digital_Edition') ===
      "Yes") {
      _this.set("userPrefMagazine", true);
     } else {
      _this.set("userPrefMagazine", false);
     }

     if (_this.get('userInformation.NL_PP_OEM_Newsletter') === "Yes") {
      _this.set("userPrefNewsNews", true);
     } else {
      _this.set("userPrefNewsNews", false);
     }

     if (_this.get('userInformation.NL_PP_OEM_Focus') === "Yes") {
      _this.set("userPrefNewsFocus", true);
     } else {
      _this.set("userPrefNewsFocus", false);
     }
    }
   }).then(function() {
    // prevalidate
    setTimeout(function() {
     $(".psw-input").each(function(i, g) {
      if ($(g).hasClass('is-must')) _this.generalValidate(g);
      if ($(g).data('phone')) _this.phoneValidate(g);
      if ($(g).data('email')) _this.emailValidate(g);
     });
     $(".psw-select").each(function(i, g) {
      _this.selectValidate(g);
     });
    });
   });
  }

  /**
   * Once the subscribe dropdown has been opened automagically by code in the
   * Drupal instance, we need to change the status in our code so that it does
   * not open up again if the user reloads, saves to a bookmark, etc.
   *
   * First we use a history.replaceState to change the value of the param, then
   * we push that state into the browser history so it's as if the browser never
   * saw the true value to begin with.
   */
  if ((typeof QueryString.displayPrefs !== 'undefined') && (QueryString.displayPrefs ===
    'true')) {
   // $('#pmmiSubscriptionWidget').slideToggle(); // then slide the div up
   // $('#subscribe').toggleClass('active'); // and turn off its active state.
   var currentEUrl = window.location.href; // browser's current URL on display
   var newEUrl; // holder for the new url we'll replace it with
   newEUrl = UpdateQueryString('displayPrefs', 'false', currentEUrl); // set the displayPrefs param to false
   history.replaceState(null, null, newEUrl); // push the new, updated url into the browser address bar w/o reloading the page
   history.pushState(null, null, newEUrl); // push that same url into the browser history
  }

 }
});


/**
 * Observes changes that will modify the form status (new v existing company)
 */
ractive.observe('newEntry', function(newValue, oldValue, keypath) {
 var _this = this;
 if (newValue === true) {
  ractive.animate('showIntro', false);
  ractive.set('existingEntry', false);

  setTimeout(function() {
   _this.generalValidate($("#form-company-name"));
  }, 5);

  setTimeout(function() {
   if (_this.get('hasPrevSuppliedEmail')) {
    $("#form-work-email + * + div i").removeClass('fa-asterisk').addClass(
     'fa-check reqover');
   }
  }, 5);
 }

 if ((!ractive.get('newEntry')) && (!ractive.get('existingEntry')) && (!
   ractive.get('cookiedUser'))) {
  ractive.animate('showIntro', true);
  ga('send', 'event', 'AW Subscription Form',
   'Backed out of new/existing selection',
   'Input action');
 }
 ga('send', 'event', 'AW Subscription Form',
  'New company entry',
  'Input action');
});


ractive.observe('cookiedUser', function(newValue, oldValue, keypath) {
 if (newValue === true) {
  ractive.animate('showIntro', false);
  ractive.set('newEntry', false);
  ractive.set('existingEntry', false);
 }

 if ((!ractive.get('newEntry')) && (!ractive.get('existingEntry')) && (!
   ractive.get('cookiedUser'))) {
  ractive.animate('showIntro', true);
 }
});

/**
 * Observes changes that will modify the form status (new v existing company)
 */
ractive.observe('existingEntry', function(newValue, oldValue, keypath) {
 var _this = this;
 if (newValue === true) {
  ractive.animate('showIntro', false);
  ractive.set('newEntry', false);

  setTimeout(function() {
   if (_this.get('hasPrevSuppliedEmail')) {
    $("#form-work-email + * + div i").removeClass('fa-asterisk').addClass(
     'fa-check reqover');
   }
  }, 5);
 }

 if ((!ractive.get('newEntry')) && (!ractive.get('existingEntry')) && (!
   ractive.get('cookiedUser'))) {
  ractive.animate('showIntro', true);
  ga('send', 'event', 'AW Subscription Form',
   'Backed out of new/existing selection',
   'Input action');
 }
 ga('send', 'event', 'AW Subscription Form',
  'Existing company entry',
  'Input action');
});

/**
 * Listens for the reset-form action. returns all state booleans to default and
 * then resets the data model to avoid artifacts.
 */
ractive.on('reset-form', function() {
 ractive.set('existingEntry', false);
 ractive.set('newEntry', false);
 ractive.fire('reset-form-data');
 ractive.animate('showIntro', true);
 ga('send', 'event', 'PP OEM Subscription Form',
  'Reset form data',
  'Input action');
 $("#primary-input").focus();
});

/**
 * Keeps the primary input from doing anything when there's no content, if
 * there is content, then it handles the double tap to lock down fast typers.
 */
ractive.on('sift-out', function(event) {
 console.log('sift out');
 var hasContent = ($("#primary-input").val() !== '') ? true : false;
 var char = event.original.which;
 if (!this.get('showIntro')) {
  $("#existing-first-name").focus();
  return;
 }

 if (hasContent) {
  if ((char === 13) || (char === 9)) {
   if ((this.get('prevKey') === 13) || (this.get('prevKey') === 9)) {
    this.set('promptNew', false);
    this.set('prevKey', null);
    this.set('newEntry', true);
    this.set('companyData', {});
    $("#primary-input").blur().focusout();
   } else {
    this.set('promptNew', true);
    this.set('prevKey', char);
   }
  }
  this.set('prevKey', char);
  return;
 } else { // no content
  if ((char === 13) || (char === 9)) {
   this.set('promptNew', true);
  }
  return;
 }
});

/**
 * Listens for the blur (focus out) on the primary form input
 */
ractive.on('primary-input-blur', function(f) {
 $("+ .speciallabel", f.node).slideUp(500).addClass('notyet'); // remove the drop down label.
 this.set('prevKey', null); // reset the key tracker
 this.set('promptNew', false); // reset prompting to enter a new business
});

/**
 * Listens for the primary form input to take focus
 */

ractive.on('primary-input-focus', function(f) {
 $("+ .speciallabel", f.node).slideDown(500).removeClass('notyet'); // display the drop down label.
 this.set('prevKey', null); // reset the key tracker
 this.set('promptNew', false); // reset prompting to enter a new business
});


/**
 * Checks if the primary input has content inside of it or not
 */
ractive.on('primary-check-content', function(event) {
 if (event.original.which === 8) {
  if ($("#primary-input").val() === '') { // if the content is empty...
   this.set('newEntry', false); // all the states revert to original form
   this.set('existingEntry', false);
   this.set('prevKey', false);
  }
 }
});

/**
 * Listens for the blur event on a select dropdown
 */
ractive.on('select-blur', function(f, id) {
 var list = id.split(','); // split the two arguments passed to the event (the array that fills the input and the variable that holds the selected value)
 var array_list = this.get(list[0]); // get JUST the filler array

 if (this.get(list[1]) !== array_list[0]) { // if the value is not the same as the first value in the array(namely, the label)
  $(f.node).addClass('is-selected is-approved');
  $("+ * + div i", f.node).removeClass('fa-asterisk').fadeIn(500).addClass(
   'fa-check reqover'); // mark as valid
 } else {
  $(f.node).removeClass('is-selected is-approved');
  $(f.node).addClass('error'); // ** makes the error handling mimic the text input fields **
  $("+ * + div i", f.node).removeClass('fa-check reqover').fadeIn(
   500).addClass(
   'fa-asterisk'); // mark as still required
 }

 $("+ .speciallabel", f.node).slideUp(500).addClass('notyet'); // remove the drop down label.
});


/**
 * Listens for a focus event on a regular input
 */
ractive.on('input-focus', function(f) {
 // $(f.node)
 $(f.node).removeClass('error').removeClass('first-touch is-approved');
 $("+ .speciallabel", f.node).slideDown(500).removeClass('notyet');
 if (f.node.id === 'form-company-address-full') {
  initCompanyAutocomplete();
 }
});

/**
 * Listens for the focus event off of the "Home Address" Google input.
 */
ractive.on('home-input-focus', function(f) {
 $(f.node).removeClass('error').removeClass('first-touch is-approved');
 $("+ .speciallabel", f.node).slideDown(500).removeClass('notyet');
 initHomeAutocomplete();
});

/**
 * Listens for the blur off of a text input
 */
ractive.on('input-blur', function(f, type) {
 var _this = this;
 // error checking for general required field
 if ($(f.node).hasClass('is-must')) {
  _this.generalValidate(f.node);
 }

 // error checking logic for phone number
 if (type === 'phone') {
  _this.phoneValidate(f.node);
 }

 // error checking logic for email
 if (type === 'email') {
  _this.emailValidate(f.node);
 }

 $("+ .speciallabel", f.node).slideUp(500).addClass('notyet'); // slide the label drop down flag away
});

/**
 * Performs the submit functionality for our forms. Specific logic is broken
 * into individual blocks, and a general submission is executed at the end.
 *
 * After the submission, the form updates or adds its user id param to the url,
 * reloads to the cookie panel (if it wasn't already there) and rolls itself up.
 *
 * specificForm here takes one of three arguments (string):
 *  "newcompany", "existing" or "cookied"
 */
ractive.on('form-submit', function(x, specificForm) {
 var _this = this; // define this for inner scopes
 var obUserData = {}; // userInformation (cookie) to be passed back to server
 var isReadyToGo = true; // assume positive intent
 var totalErrorCount = $(".error").length || $(".first-touch").length; // count either errors or first-touches that need attention

 if (totalErrorCount) { // if something needs attention
  isReadyToGo = false; // our assumption was false
  this.set('submitErrors', true);
  // $(".error").each(function(index, key) {
  // });
  // $(".first-touch").each(function(index, key) {
  // });

  window.setTimeout(function() { // show the warning message for 5s then disappear it
   _this.set('submitErrors', false);
  }, 5000);
  ga('send', 'event', 'AW Subscription Form',
   'Errors on form submit',
   'Input action');
 } else { // thunderbirds are go!
  _this.set('savingUserData', true); // start notifying user of save.
  _this.set('userInformation.Company', _this.get('primeInput') || _this.get(
   'companyData.company_name')); // Company name
  _this.set('Brand_AW', "Yes"); // always and forever, per AJ. 03/10/2015
  _this.set('userInformation.Full_Name', _this.get(
   'userInformation.First_name') + ' ' + _this.get(
   'userInformation.Last_name'));


  if (_this.get('prefersHomeDelivery')) {

  }
  ga('send', 'event', 'AW Subscription Form',
   'Valid form submit',
   'Input action');

  /**
   * Handle form submission specifics for "new" companies
   */
  if (specificForm === 'newcompany') {
   // Set the address block for the new company
   _this.set('companyData.companyname', _this.get('userInformation.Company'));
   _this.set('companyData.addr', _this.get('compGoogleData.num_l') + " " +
    _this.get('compGoogleData.street_l'));
   _this.set('companyData.addr2', _this.get('userInformation.Address_2'));
   _this.set('companyData.city', _this.get('compGoogleData.city_l'));
   _this.set('companyData.state', _this.get('compGoogleData.state_l'));
   _this.set('companyData.zip', _this.get('compGoogleData.zip_l'));
   _this.set('companyData.country', _this.get('compGoogleData.country_l'));
   _this.set('companyData.pp_oem_industry', _this.get(
    'selectedIndustry'));
   _this.set('companyData.pp_oem_annual_revenues', _this.get(
    'selectedRevenue'));
   // Endpoint requires an email address...
   _this.set('companyData.email', _this.get('userInformation.Email'));

   // write the new company data to the unnormalized data table. we'll process
   // this information later on via Hoovers.
   $.ajax({
    url: '//leadworks.pmmimediagroup.com/api/companyUnnormalizedAdd',
    data: _this.get('companyData'),
    crossDomain: true,
    dataType: 'json',
    type: 'POST',
    success: function(data) {},
    fail: function(result) {}
   });

   // handle opt-in opt-out logic
   _this.handleOptInFactors();

   // Pass Canadian location variable up to the server #blamecanada
   _this.set('userInformation.Canadian_Subscriber', _this.get('isThisCanada'));
   // If the subscriber is Canadian, will say whether they opted in or out.
   // For non-Canucks, will always be false. #blamecanada
   _this.set('userInformation.Canadian_OptIn_OptOut', _this.get(
    'canadaOptIn'));
   // Did the subscriber opt to only receive newsletters?
   _this.set('userInformation.Magazine_OutIn_OptOut', _this.get(
    'userPrefMagazine'));

   // pass off to handle shipping prefs.
   _this.handleHomeDeliveryPrefs();
   ga('send', 'event', 'AW Subscription Form',
    'Valid new form submit',
    'Input action');
  }

  /**
   * Handle form submission specifics for "new" companies. This data will later
   * be passed off to Hoovers.
   */
  if (specificForm === 'newcompany') {
   _this.set('userInformation.AW_Industry', _this.get('selectedIndustry'));
   _this.set('userInformation.AW_Job_Duties', _this.get('selectedJobDuty'));
   _this.set('userInformation.AW_Annual_Revenues', _this.get(
    'selectedRevenue'));
  }


  /**
   * Handle form submission specifics for "existing" companies
   */
  if (specificForm === 'existing') {

   // set the industry of the subscriber
   _this.set('userInformation.AW_Industry', _this.get(
    'companyData.aw_industry'));

   // Not currently relevant to AW
   // set the PP_OEM company number (referencer)
   // _this.set('userInformation.PP_OEM_Company_number', _this.get(
   // 	'companyData.aw_company_number'));

   // set the revenue of the subscriber's company, based either on existing
   // data or if it was lacking, from what they input.
   _this.set('userInformation.PP_OEM_Annual_Revenues', ((_this.get(
    'companyData.pp_oem_annual_revenues') !== "") ? _this.get(
    'companyData.pp_oem_annual_revenues') : _this.get('selectedRevenue')));

   // set the subscribers job duty
   _this.set('userInformation.PP_OEM_Job_Duties', _this.get(
    'selectedJobDuty'));

   // handle opt-in opt-out logic
   _this.handleOptInFactors();

   // Pass Canadian location variable up to the server #blamecanada
   _this.set('userInformation.Canadian_Subscriber', _this.get('isThisCanada'));
   // If the subscriber is Canadian, will say whether they opted in or out.
   // For non-Canucks, will always be false. #blamecanada
   _this.set('userInformation.Canadian_OptIn_OptOut', _this.get(
    'canadaOptIn'));
   // Did the subscriber opt to only receive newsletters?
   _this.set('userInformation.Magazine_OutIn_OptOut', _this.get(
    'userPrefMagazine'));

   // pass off to handle shipping prefs.
   _this.handleHomeDeliveryPrefs();
   ga('send', 'event', 'PP OEM Subscription Form',
    'Valid existing form submit',
    'Input action');
  }

  /**
   * Handle form submission specifics for "cookied" users
   */
  if (specificForm === 'cookied') {
   // set the subscribers job duty
   _this.set('userInformation.PP_OEM_Job_Duties', _this.get(
    'selectedJobDuty'));

   // Preferences for Magazine (Print/Digital) and e-newsletters
   // Inside the cookie panel, we've already (previosly) handled Canada checking
   // and opting for specifics (newsletters only). Now we simply ask for their
   // current preferences and record them.
   //
   // Can't use the handleOptInFactors function here, as the rules no longer
   // apply. Legal opt in/opt outs have theoretically already occured at a
   // previous date.

   // Magazine
   if (_this.get('userPrefMagazine')) {
    _this.set("userInformation.NL_PP_OEM_Digital_Edition", "Yes");
   } else {
    _this.set("userInformation.NL_PP_OEM_Digital_Edition", "No");
   }

   // Newsletter #1
   if (_this.get('userPrefNewsNews')) {
    _this.set("userInformation.NL_PP_OEM_Newsletter", "Yes");
   } else {
    _this.set("userInformation.NL_PP_OEM_Newsletter", "No");
   }

   // Focus Newsletters
   if (_this.get('userPrefNewsFocus')) {
    _this.set("userInformation.NL_PP_OEM_Focus", "Yes");
   } else {
    _this.set("userInformation.NL_PP_OEM_Focus", "No");
   }

   // pass off to handle shipping prefs.
   _this.handleHomeDeliveryPrefs();

   ga('send', 'event', 'PP OEM Subscription Form',
    'Valid cookied form submit',
    'Input action');
  }

  // Always set to YES... per AJ, 03/09/2015
  _this.set('userInformation.Brand_PP_OEM', "Yes");
  // Because someone said to.
  _this.set('userInformation.form_id', 'PP_OEM Magazine Signup Form');



  // Always set to the date of the submit, per AJ, 03/30/2015
  var date = new Date(); // grab date
  var day = date.getDate(); // get day
  var monthIndex = date.getMonth() + 1; // get month (month is 0 based in JS)
  var year = date.getFullYear(); // get four digit year

  // set the value to a MM/DD/YYYY format string (use str_pad to add leading zeros)
  _this.set('userInformation.PP_OEM_Verification_Date', str_pad(monthIndex) +
   '/' +
   str_pad(day) + '/' + year);

  // Since we don't have a stage 1 or stage 2
  _this.set('userInformation.Email_only', 'Converted');



  var cd = _this.get('userInformation'); // get cookie data stored in ractive
  for (var key in cd) {
   obUserData[key.replace(/_/g, ' ')] = cd[key];
  }

  // attempt to perform the write up to the server via an AJAX POST call.
  $.ajax({
   url: '//www.pp-oem.com/api/v1/silverpop/post',
   crossDomain: true,
   type: "POST",
   dataType: "json",
   data: obUserData,
   success: function(data) {
    _this.set('savedUserData', true); // was the save successful - yes.

    setTimeout(function() { // set a 3s timeout
     _this.set('savingUserData', false); // then close the save dropdown
     _this.set('savedUserData', false); // and turn off the saved flag.
    }, 3000);


    // Make sure the spUserID in the url is accurate.
    var currentUrl = window.location.href; // the current url
    var newUrl; // where the replacement url will be written
    newUrl = UpdateQueryString('spUserID', data.spUserID, currentUrl); // change the spUserID param to the value returned from the server
    history.replaceState(null, null, newUrl); // replace the URL in the browser address bar
    history.pushState(null, null, newUrl); // push that same url into the browser history

    // once we're to this point, everyone should be cookied, so we'll
    // go ahead and make the cookies appear.
    QueryString.spUserID = data.spUserID; // we can rewrite the URL, and we know the data's there, but we have to trick the Query checker into believing this.
    ga('send', 'event', 'PP OEM Subscription Form',
     'Server successfully accepted form',
     'Form action');
    _this.oninit(); // once those data points are in place, we reinit the ractive object, and it handles it as if there was a cookie.

   },
   fail: function(result) {
    _this.set('savingUserData', false);

   },
   error: function(result) { // what to do if there was an error with the form-submit AJAX call.
    _this.set('errorSavingUserData', true); // was there an error saving the data - yes
    setTimeout(function() { // set a timer for 3s
     _this.set('errorSavingUserData', false); // then turn off the error flag
     _this.set('savingUserData', false); // and close down the save drop down box
    }, 3000);
    ga('send', 'event', 'PP OEM Subscription Form',
     'Server failed to accepted form',
     'Form action');
    console.log("error", result); // send the error to console in case of needing to remote debug.
   }
  });
 }
});


/**
 * Handles formatting the phone input field text to meet US phone format style.
 */
ractive.on('phone-formatting', function(e) {
 var f = e;
 var p = $(f.node).val().length;
 var tabindex;

 if ((e.original.keyCode === 37) || (e.original.keyCode === 38) || (e.original
   .keyCode === 39) || (e.original.keyCode === 40)) {
  return;
 }

 if ((p === 14) && (e.original.keyCode !== 8) && (e.original.keyCode !== 9)) {
  e.original.preventDefault();
 }

 if ((e.original.keyCode === 9) && (!e.original.shiftKey)) {
  tabindex = $(f.node).attr('tabindex') + 1;
  $('[tabindex=' + tabindex + ']').focus();
 }

 if ((e.original.keyCode === 9) && (e.original.shiftKey)) {
  tabindex = $(f.node).attr('tabindex') - 1;
  $('[tabindex=' + tabindex + ']').focus();
 }

 if ($(f.node).hasClass('error')) {
  $(f.node).removeClass('error');
 }

 if ((!e.original.shiftKey) && ((e.original.keyCode >= 48 && e.original.keyCode <=
   57) || (e.original.keyCode >=
   96 && e
   .keyCode <=
   105) || (e.original.keyCode === 8) || (e.original.keyCode === 9))) { //0-9 only (top and keypad)
  if (e.original.keyCode !== 8) { // if someone isn't typing a backspace
   if (p === 3) { // add opening (
    $(f.node).val('(' + $(f.node).val());
    //this.set('value', '(' + this.get('value'));
    p = $(f.node).val().length; // reevaluate to hook in the ) when going forward
   }
   if (p === 4) { // add closing )
    $(f.node).val($(f.node).val() + ') ');
    //this.set('value', this.get('value') + ') ');
   }
   if (p === 9) { // add -
    $(f.node).val($(f.node).val() + '-');
    //this.set('value', this.get('value') + '-');
   }
  } else if (e.original.keyCode === 8) { // if someone is typing a backspace
   if (p === 7) { // if we're at (333) 3 and someone hits backspace, handle up to )
    $(f.node).val($(f.node).val().slice(1, -3));
    //this.set('value', this.get('value').slice(1, -3)); //.slice(1,3));
   } else
   if (p === 11) { // if we're at (333) 333- and someone hits back space, handle 3-
    $(f.node).val($(f.node).val().slice(0, -2));
    //this.set('value', this.get('value').slice(0, -2));
   }
   return;
  } else {
   e.original.preventDefault();
  }
 } else {
  e.original.preventDefault();
 }
});

/**
 * Resets the Home Address Google Places Autocomplete field value
 */
ractive.observe('prefersHomeDelivery', function() {
 this.set('fullHomeAddress', '');
});

/**
 * Listens for the selected job duty and if its the last option in the list
 * (should always be 'other') then it triggers the "other" text input box to
 * display to the user.
 */
ractive.observe('selectedJobDuty', function() {
 var jd = this.get('jobduties');
 var l = jd.length - 1;

 if (this.get('selectedJobDuty') === jd[l]) {
  this.set('otherJobDutySelected', true);
 } else {
  this.set('otherJobDutySelected', false);
 }

});

/**
 * Listens for the selected industry and if its the last option in the list
 * (should always be 'other') then it triggers the "other" text input box to
 * display to the user.
 */
ractive.observe('selectedIndustry', function() {
 var jd = this.get('industries');
 var l = jd.length - 1;

 if (this.get('selectedIndustry') === jd[l]) {
  this.set('otherIndustrySelected', true);
 } else {
  this.set('otherIndustrySelected', false);
 }

});

/**
 * Listens to the Home Delivery checkbox and changes the option in the data
 * model as well as the boolean flag in the Ractive state.
 */
ractive.on('toggleHomeDelivery', function() {
 this.toggle('prefersHomeDelivery');
 ga('send', 'event', 'PP OEM Subscription Form',
  'Set home delivery to ' + this.get('prefersHomeDelivery'),
  'Input action');
 if (this.get('prefersHomeDelivery')) {
  this.set('userInformation.Prefers_Home_Delivery', "Yes");
 } else {
  this.set('userInformation.Prefers_Home_Delivery', "No");
 }
});

/**
 * Listens to the Newsletters only checkbox and changes the option in the data
 * model as well as the boolean flag in the Ractive state.
 */
ractive.on('toggleDigitalOnly', function() {
 this.toggle('prefersDigitalOnly');
 //console.log('toggle!');
 ga('send', 'event', 'PP OEM Subscription Form',
  'Set magazine opt-in to ' + this.get('prefersDigitalOnly'),
  'Input action');
 if (this.get('prefersDigitalOnly')) {
  this.set('prefersHomeDelivery', false);
 }
});

/**
 * Listens if a Canadian user toggles the Canada-only opt-in/opt-out checkbox.
 * #blamecanada
 */
ractive.on('toggleCanadaRule', function() {
 this.toggle('canadaOptIn');
 ga('send', 'event', 'PP OEM Subscription Form',
  'Canada-only opt-in set to  ' + this.get('canadaOptIn'),
  'Input action');
});

/**
 * CURRENTLY UNUSED
 */
ractive.on('handle-newsletter-select', function(i, id) {
 var newsletters = this.get('enewsletters');
 newsletters[id].selected = !newsletters[id].selected;
 this.animate('enewsletters', newsletters);
});

/**
 * CURRENTLY UNUSED
 */
ractive.on('handle-newsletter-allnone', function(i, setTo) {
 var newsletters = this.get('enewsletters');
 newsletters.forEach(function(obj, index) {
  obj.selected = setTo;
 });
 this.set('enewsletters', newsletters);
});

/**
 * Resets the form and its data model(s) to their default state.
 */
ractive.on('reset-form-data', function() {
 this.reset({
  savedUserData: false,
  errorSavingUserData: false,
  savingUserData: false,
  isThisCanada: false, // blame canada
  userCountryCode: '', // blame canada
  canadaOptIn: false, // IMPORTANT. Leave as false.
  companyData: {},
  prefersDigitalOnly: false,
  prefersHomeDelivery: false,
  otherJobDutySelected: false,
  otherIndustrySelected: false,
  userPrefMagazine: false, // mimic whats in the cookie, but as a bool
  userPrefNewsFocus: false, // " "
  userPrefNewsNews: false, // "
  otherJobDutyExplain: '',
  otherIndustryExplain: '',
  selectedJobDuty: "Job duty",
  jobduties: ["Job duty", "Engineering", "Production/Manufacturing",
   "Service/Support",
   "Purchasing", "Marketing/Brand Manager", "Sales",
   "CEO/Gen Mgr/Other Senior Mgmt", "Other"
  ],
  selectedIndustry: "Select industry",
  industries: ["Select industry", "Packaging Machinery OEM",
   "Processing Machinery OEM",
   "Converting Machinery OEM",
   "Plastics Machinery OEM",
   "Systems Integrator",
   "Other (please specify)"
  ],
  selectedRevenue: "Annual revenue",
  revenues: ["Annual revenue", "Under $10 million",
   "$10 to $20 million",
   "$20 to $50 million",
   "Over $50 million"
  ],
  pnewsletters: [{
   "title": "Packaging and Processing OEM",
   "frequency": "Quarterly",
   "code": "print",
   "desc": "something something OEM",
   "selected": true
  }],
  enewsletters: [{
   "title": "Newsletter #1",
   "frequency": '2x/month',
   "code": "xx-1",
   "desc": "Systems impactful envisioneer expedite platforms, leverage; best-of-breed, 'back-end architect?'",
   "selected": true
  }, {
   "title": "Newsletter #2",
   "frequency": 'infrequent',
   "code": "xx-1",
   "desc": "Transparent, experiences; strategize social benchmark global peer-to-peer platforms.",
   "selected": false
  }, {
   "title": "Newsletter #3",
   "frequency": '4x/month',
   "code": "xx-1",
   "desc": "Rich-clientAPIs 24/7, authentic iterate disintermediate interactive visualize webservices real-time enable back-end, rich-clientAPIs robust wikis productize.",
   "selected": true
  }]
 });
});
