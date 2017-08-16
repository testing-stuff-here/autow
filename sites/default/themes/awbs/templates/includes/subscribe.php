<div class="col-xs-12">
  <div id="pmmiSubscriptionWidget"></div>
</div>

 <!-- This template partial is called to inform the user of states of saving data -->
 <!-- up tp the server. -->
 <!-- {{>savingdata-template}} -->
 <script intro="slide:{'delay':2000, 'duration':1000, 'easing':'ease-in'}" outro="slide:{'delay':5000, 'easing':'ease-out'}" id="savingdata" type="text/ractive">
  <div class="row saving-data-row {{errorSavingUserData ? 'error-saving':''}} {{savedUserData ? 'completed-saving':''}}">
   <div class="col-sm-12">
   {{#if (!errorSavingUserData && !savedUserData)}}
    <i class="fa fa-fw fa-spin fa-circle-o-notch reqover"></i> Saving your info...
   {{/if}}

   {{#if errorSavingUserData && savingUserData}}
    <i class="fa fa-fw fa-exclamation-circle"></i> Error saving. Please try again.
   {{/if}}

   {{#if savedUserData && savingUserData }}
    <i class="fa fa-fw fa-check-circle-o"></i> Your information was saved.
   {{/if}}
   </div>
  </div>
 </script>

 <!-- This partial shows a brief prompt to the user when they're coming in cold. -->
 <!-- It disappears as they interact with the form. Cookied users never see this. -->
 <!-- {{>intro-template}} -->
 <script intro="slide:{'delay':5000, 'easing':'ease-in'}" id="intro" type="text/ractive">
  <div class="row spacerRow"></div>
  <div class="row">
   <div class="col-sm-12 new-intro">
    {{#unless hasPrevSuppliedEmail}}Type in your company name to start. On the next screen you can choose magazine or newsletters (or both).{{/unless}}
    {{#if hasPrevSuppliedEmail}}Great, we have your email (<strong>{{prevSuppliedEmail}}</strong>)! <br /><br />Now, please enter your company so we can complete your signup. On the next screen you can choose magazine or newsletters (or both).{{/if}}
   </div>
  </div>
 </script>

 <!-- This partial is called when a user attempts to submit a form that isn't valid. -->
 <!-- It displays for 5s and then is retracted. Used against all form states. -->
 <!-- {{>formerror-template}} -->
 <script intro-outro="slide" id="formerror" type="text/ractive">
  <div class="row" intro-outro="slide">
   <div class="col-sm-12 alert alert-danger"><i class="fa fa-fw fa-exclamation-circle fa-lg"></i>
    <span class="text-right">Please check your information and try submitting again.</span>
   </div>
  </div>
 </script>

 <!-- This partial houses the checkboxes that make up the latter part of the form states. -->
 <!-- Display logic for showing which checkboxes is handled here based on data provided -->
 <!-- from the Ractive instance. This is used against all form states. -->
 <!-- {{>checkboxalley-template}} -->
 <script id="checkboxalley" type="text/ractive">
 <div class="spacerRow"></div>

{{#unless cookiedUser}}
 {{#if isThisCanada}}
   <div class="row formRow checkrow">
   <div class="col-xs-1">
    <i class="fake-checkbox fa fa-fw {{canadaOptIn ? 'fa-check-square-o' : 'fa-square-o'}}" id="form-ca-approve-digital" on-click="toggleCanadaRule" on-enter="toggleCanadaRule" on-space="toggleCanadaRule" tabindex=9></i>
   </div>
   <div class="col-xs-11 checkbox-text">
     Please send me <em>AutomationWorld</em> newsletters and technology updates (a few times per month)
   </div>
   </div>
 {{/if}}
 {{/unless}}

 <div class="row formRow checkrow {{prefersDigitalOnly ? 'disabledRow':'' }}">
  <div class="col-xs-1">
   <i class="fake-checkbox fa fa-fw {{ prefersHomeDelivery ? 'fa-check-square-o' : 'fa-square-o'}}" id="form-home-delivery" on-click="toggleHomeDelivery" on-enter="toggleHomeDelivery" on-space="toggleHomeDelivery" tabindex=9></i>
  </div>
  <div class="col-xs-11 checkbox-text">
   I prefer home delivery of <em>AutomationWorld</em>
  </div>
 </div>

 {{#prefersHomeDelivery}}
 <div class="spacerRow"></div>
 <div class="row formRow" intro=fade outro=fade>
  <div class="col-sm-12">
   <div class="input-group">
    <input class="{{cookiedUser ? '':'first-touch'}} form-control psw-input is-must" on-focus="home-input-focus" on-blur="input-blur" type="text" value={{fullHomeAddress}} id="form-home-delivery-address-full" placeholder="Your home address" tabindex=10>
    <span class="notyet speciallabel">your home address</span>
    <div class="input-group-addon req"><i class="fa fa-fw fa-asterisk"></i>
    </div>
   </div>
  </div>
 </div>
 {{/prefersHomeDelivery}}
 </script>

 <!-- This partial is called for the cookied user form state. -->
 <!-- It displays the subscribers subscription preferences, which they can then -->
 <!-- use to select and deselect accordingly. -->
 <!-- {{>prefcenter-template}} -->
 <script intro="fade" id="prefcenter" type="text/ractive">
 {{#with userInformation}}
  <div class="row sub-prefs-panel">
   <div class="col-sm-12">

    <div class="row">
     <div class="col-sm-12 spp-header"><div><strong>Magazine</strong></div></div>
    </div>

    <div class="row">
      <div class="col-xs-1 vert">
      <i class="fake-checkbox fa fa-fw {{userPrefMagazine ? 'fa-check-square-o' : 'fa-square-o'}}" id="form-home-delivery" on-click="toggle('userPrefMagazine')" on-enter="toggle('userPrefMagazine')" on-space="toggle('userPrefMagazine')" tabindex=9></i>
      </div>
      <div class="col-xs-10">
      <div class="row">
       <div class="col-xs-12 spp-desc special-spp"><strong>Yes,</strong> I wish to receive (or continue to receive) <em>Automation World</em> magazine FREE of charge.</div>
       <div class="col-xs-12 spp-desc">Subscribers outside the U.S. will receive the digital edition.</div>
      </div>
     </div>
    </div>

    <div class="row">
     <div class="col-xs-12 spp-header"><div><strong>Newsletters</strong></div></div>
    </div>

    <div class="row">
      <div class="col-xs-1">
      <i class="fake-checkbox fa fa-fw {{userPrefNewsNews ? 'fa-check-square-o' : 'fa-square-o'}}" id="form-home-delivery" on-click="toggle('userPrefNewsNews')" on-enter="toggle('userPrefNewsNews')" on-space="toggle('userPrefNewsNews')" tabindex=9></i>
      </div>
      <div class="col-xs-10">
      <div class="row">
       <div class="col-xs-12 spp-title">News & Analysis</div>
      </div>
     </div>
    </div>

    <div class="row">
      <div class="col-xs-1">
      <i class="fake-checkbox fa fa-fw {{userPrefNewsFocus ? 'fa-check-square-o' : 'fa-square-o'}}" id="form-home-delivery" on-click="toggle('userPrefNewsFocus')" on-enter="toggle('userPrefNewsFocus')" on-space="toggle('userPrefNewsFocus')" tabindex=9></i>
      </div>
      <div class="col-xs-10">
      <div class="row">
       <div class="col-xs-12 spp-title">Continous Processing</div>
      </div>
     </div>
    </div>

    <div class="row">
      <div class="col-xs-1">
      <i class="fake-checkbox fa fa-fw {{userPrefNewsFocus ? 'fa-check-square-o' : 'fa-square-o'}}" id="form-home-delivery" on-click="toggle('userPrefNewsFocus')" on-enter="toggle('userPrefNewsFocus')" on-space="toggle('userPrefNewsFocus')" tabindex=9></i>
      </div>
      <div class="col-xs-10">
      <div class="row">
       <div class="col-xs-12 spp-title">Factory Automation</div>
      </div>
     </div>
    </div>

    <div class="row">
      <div class="col-xs-1">
      <i class="fake-checkbox fa fa-fw {{userPrefNewsFocus ? 'fa-check-square-o' : 'fa-square-o'}}" id="form-home-delivery" on-click="toggle('userPrefNewsFocus')" on-enter="toggle('userPrefNewsFocus')" on-space="toggle('userPrefNewsFocus')" tabindex=9></i>
      </div>
      <div class="col-xs-10">
      <div class="row">
       <div class="col-xs-12 spp-title">Latest Automation Products</div>
      </div>
     </div>
    </div>

    <div class="row">
      <div class="col-xs-1">
      <i class="fake-checkbox fa fa-fw {{userPrefNewsFocus ? 'fa-check-square-o' : 'fa-square-o'}}" id="form-home-delivery" on-click="toggle('userPrefNewsFocus')" on-enter="toggle('userPrefNewsFocus')" on-space="toggle('userPrefNewsFocus')" tabindex=9></i>
      </div>
      <div class="col-xs-10">
      <div class="row">
       <div class="col-xs-12 spp-title">Automation Skills</div>
      </div>
     </div>
    </div>

    <div class="row">
      <div class="col-xs-1">
      <i class="fake-checkbox fa fa-fw {{userPrefNewsFocus ? 'fa-check-square-o' : 'fa-square-o'}}" id="form-home-delivery" on-click="toggle('userPrefNewsFocus')" on-enter="toggle('userPrefNewsFocus')" on-space="toggle('userPrefNewsFocus')" tabindex=9></i>
      </div>
      <div class="col-xs-10">
      <div class="row">
       <div class="col-xs-12 spp-title">Food, Bev & Pharma</div>
      </div>
     </div>
    </div>

    <div class="row">
      <div class="col-xs-1">
      <i class="fake-checkbox fa fa-fw {{userPrefNewsFocus ? 'fa-check-square-o' : 'fa-square-o'}}" id="form-home-delivery" on-click="toggle('userPrefNewsFocus')" on-enter="toggle('userPrefNewsFocus')" on-space="toggle('userPrefNewsFocus')" tabindex=9></i>
      </div>
      <div class="col-xs-10">
      <div class="row">
       <div class="col-xs-12 spp-title">Best of Blogs</div>
      </div>
     </div>
    </div>

    <div class="row">
      <div class="col-xs-1">
      <i class="fake-checkbox fa fa-fw {{userPrefNewsFocus ? 'fa-check-square-o' : 'fa-square-o'}}" id="form-home-delivery" on-click="toggle('userPrefNewsFocus')" on-enter="toggle('userPrefNewsFocus')" on-space="toggle('userPrefNewsFocus')" tabindex=9></i>
      </div>
      <div class="col-xs-10">
      <div class="row">
       <div class="col-xs-12 spp-title">Industrial Internet of Things</div>
      </div>
     </div>
    </div>

    <div class="row">
      <div class="col-xs-1">
      <i class="fake-checkbox fa fa-fw {{userPrefNewsFocus ? 'fa-check-square-o' : 'fa-square-o'}}" id="form-home-delivery" on-click="toggle('userPrefNewsFocus')" on-enter="toggle('userPrefNewsFocus')" on-space="toggle('userPrefNewsFocus')" tabindex=9></i>
      </div>
      <div class="col-xs-10">
      <div class="row">
       <div class="col-xs-12 spp-title">Global Automation News</div>
      </div>
     </div>
    </div>

    <div class="row">
      <div class="col-xs-1">
      <i class="fake-checkbox fa fa-fw {{userPrefNewsFocus ? 'fa-check-square-o' : 'fa-square-o'}}" id="form-home-delivery" on-click="toggle('userPrefNewsFocus')" on-enter="toggle('userPrefNewsFocus')" on-space="toggle('userPrefNewsFocus')" tabindex=9></i>
      </div>
      <div class="col-xs-10">
      <div class="row">
       <div class="col-xs-12 spp-title">Workforce Development</div>
      </div>
     </div>
    </div>

   </div>
  </div>
 {{/with}}
 </script>


 <!-- Our cookied user form state. -->
 <!-- Displays a loading message until the data is in our store, then -->
 <!-- renders the form with the data prepopulated and prevalidated. -->
 <!-- {{>iscookied-template}} -->
 <script intro="fade" id="iscookied" type="text/ractive">
 {{#cookieDataLoaded}}
 <div class="col-sm-12 existing-top">
  <div class="existing-greeting">Tell us about yourself</div>
 </div>
 <div class="row spacerRow"></div>
 {{/cookieDataLoaded}}

  <div class="col-sm-12">

   {{#with userInformation}}
   {{#submitErrors}}
      {{>formerror}}
   {{/submitErrors}}
   {{#cookieDataLoaded}}


   {{#if companyData}}
   {{#with companyData}}
   <div class="row">
    <div class="col-sm-12">
     <div class="cta-sub-main">{{company_name}}</div>
    </div>
   </div>

   <div class="row">
    <div class="col-sm-12">
     <div class="cta-sub-sub-main">{{address_1}} {{address_2}}</div>
    </div>
    <div class="col-sm-12">
     <div class="cta-sub-sub-main">{{city}} {{state}} {{zipcode}}</div>
    </div>
   </div>
   {{/with}}
   {{/if}}

   {{#isBizEmail}}
   <div class="row formRow">
   <div class="col-sm-12 text-center email-warning-msg" intro=fade outro=fade>
    <i class="fa fa-fw fa-warning"></i> Sorry, emails that use
    <strong>info</strong>,
    <strong>sales</strong> or
    <strong>help</strong> are not permitted.
   </div>
   </div>
   {{/isBizEmail}}


   <div class="row firstRow" intro="fade">
   <div class="col-sm-12">
    <div class="input-group">
     <input type="text" id="form-work-email" placeholder="Work email" value={{.Email}} data-email="true" class="form-control psw-input is-must" on-focus="input-focus" on-blur="input-blur:email" tabindex=7>
     <span class="notyet speciallabel">work email</span>
     <div class="input-group-addon req"><i class="fa fa-fw fa-asterisk"></i>
     </div>
    </div>
   </div>
  </div>

   <div class="row formRow" intro="fade">
    <div class="col-sm-6">
     <div class="input-group">
      <input type="text" id="form-first-name" placeholder="First name" value={{.First_name}} minlength=2 class="form-control psw-input is-must" on-focus="input-focus" on-blur="input-blur" tabindex=2>
      <span class="notyet speciallabel">first name</span>
      <div class="input-group-addon req"><i class="fa fa-fw fa-asterisk"></i>
      </div>
     </div>
    </div>

    <div class="col-sm-6">
     <div class="input-group">
      <input type="text" id="form-last-name" placeholder="Last name" value={{.Last_name}} minlength=1 class="form-control psw-input is-must" on-focus="input-focus" on-blur="input-blur" tabindex=3>
      <span class="notyet speciallabel">last name</span>
      <div class="input-group-addon req"><i class="fa fa-fw fa-asterisk"></i>
      </div>
     </div>
    </div>
   </div>

   <div class="row formRow" intro="fade">
    <div class="col-sm-12">
     <div class="input-group">
      <input type="text" id="form-title" placeholder="Title" value={{.Title}} minlength=2 class="form-control psw-input is-must" on-focus="input-focus" on-blur="input-blur" tabindex=4>
      <span class="notyet speciallabel">title</span>
      <div class="input-group-addon req"><i class="fa fa-fw fa-asterisk"></i>
      </div>
     </div>
    </div>
    </div>

    <div class="row formRow" intro="fade">
    <div class="col-sm-12">
     <div class="input-group">
      <select value='{{selectedJobDuty}}' id="#form-job-duty" on-focus="input-focus" on-blur="select-blur:jobduties,selectedJobDuty" class="form-control psw-select is-must" tabindex=5>
       {{#jobduties}}
       <option value='{{.}}'>{{.}}</option>
       {{/jobduties}}
      </select>
      <span class="notyet speciallabel selectable">job duty</span>
      <div class="input-group-addon req"><i class="fa fa-fw fa-asterisk"></i>
      </div>
     </div>
    </div>
   </div>
   {{#otherJobDutySelected}}
   <div class="row formRow">
    <div class="col-sm-12">
     <div class="input-group">
      <input type="text" id="form-job-duty-other" placeholder="Other (please explain)" minlength=2 value={{AW_Job_Duties_Other}} class="first-touch form-control psw-input is-must" on-focus="input-focus" on-blur="input-blur" tabindex=6>
      <span class="notyet speciallabel">other (please explain)</span>
      <div class="input-group-addon req"><i class="fa fa-fw fa-asterisk"></i>
      </div>
     </div>
    </div>
   </div>
   {{/otherJobDutySelected}}


   <div class="row formRow" intro="fade">
    <div class="col-sm-12">
     <div class="input-group">
      <input type="text" id="form-direct-phone" placeholder="Direct phone number" value={{.Phone}} data-phone="true" class="form-control psw-input" on-focus="input-focus" on-blur="input-blur:phone" on-keydown="phone-formatting" tabindex=6>
      <span class="notyet speciallabel">direct phone number</span>
      <div class="input-group-addon req"><i class="fa fa-fw"></i>
      </div>
     </div>
    </div>
    </div>



   {{>checkboxalley}}

   <div class="row finalRow">
    <div class="col-sm-8">
     <a href="#" class="btn btn-sm btn-block shittiebutton" on-click="form-submit:cookied" id="form-submit-button" tabindex=11>Update my info</a>
    </div>

    <div class="col-sm-12" id="helpdesk">Stuck? <a href="mailto:help@automationworld.com?subject=Help subscribing to AutomationWorld">Email us.</a></div>
   </div>
   {{else}}
   <div class="row">
    <div class="col-xs-12 col-sm-12 col-md-12 col-md-pull-5 loading-data"><i class="fa fa-fw fa-spin fa-circle-o-notch reqover"></i> Loading your subscription information.</div>
   </div>
   {{/cookieDataLoaded}} {{/with}}
  </div>
 </script>

 <!-- Our new company form state. -->
 <!-- {{>isnew-template}} -->
 <script {{intro=slide}} id="isnew" type="text/ractive">
 <div class="existing-top">
  <div class="existing-greeting">Tell us about yourself</div>
  <a href="#" on-click="reset-form" class="change-button"><i class="fa fa-fw fa-chevron-right"></i>start over?</a>
 </div>

  {{#with userInformation}}
  <div class="row spacerRow"></div>
  {{#submitErrors}} {{>formerror}} {{/submitErrors}}

  <div class="row firstRow">
   <div class="col-sm-12">
    <div class="input-group">
     <input type="text" class="form-control psw-input is-must" value={{primeInput}} id="form-company-name" placeholder="Company name" minlength=2 on-focus="input-focus" on-blur="input-blur" tabindex=1 />
     <span class="notyet speciallabel">company name</span>
     <div class="input-group-addon req"><i class="fa fa-fw fa-asterisk"></i>
     </div>
    </div>
   </div>
  </div>

  <div class="row formRow">
   <div class="col-sm-9">
    <div class="input-group">
     <input type="text" class="first-touch form-control psw-input is-must" value={{companyAddressString}} id="form-company-address-full" placeholder="Company address" minlength=2 on-focus="input-focus" on-blur="input-blur" tabindex=2 />
     <span class="notyet speciallabel">company address</span>
     <div class="input-group-addon req"><i class="fa fa-fw fa-asterisk"></i>
     </div>
    </div>
   </div>

   <div class="col-sm-3">
    <div class="input-group">
     <input type="text" class="form-control psw-input" value={{Address_2}} id="form-company-address-two" placeholder="Ste" minlength=0 on-focus="input-focus" on-blur="input-blur" tabindex=3 />
     <span class="notyet speciallabel">suite</span>
     <div class="input-group-addon req"><i class="fa fa-fw"></i>
     </div>
    </div>
   </div>
  </div>
  {{/with}}


  {{#with userInformation}}
  <div class="row formRow">
  <div class="col-sm-12">
   <div class="input-group">
    <input type="text" id="form-work-email" placeholder="Work email" value={{Email}} data-email="true" class="first-touch form-control psw-input" on-focus="input-focus" on-blur="input-blur:email" tabindex=10>
    <span class="notyet speciallabel">work email</span>
    <div class="input-group-addon req"><i class="fa fa-fw fa-asterisk"></i>
    </div>
   </div>
  </div>
 </div>

  <div class="row formRow">
   <div class="col-sm-6">
    <div class="input-group">
     <input type="text" id="form-first-name" placeholder="First name" value={{First_name}} minlength=2 class="first-touch form-control psw-input is-must" on-focus="input-focus" on-blur="input-blur" tabindex=4>
     <span class="notyet speciallabel">first name</span>
     <div class="input-group-addon req"><i class="fa fa-fw fa-asterisk"></i>
     </div>
    </div>
   </div>

   <div class="col-sm-6">
    <div class="input-group">
     <input type="text" id="form-last-name" placeholder="Last name" value={{Last_name}} minlength=1 class="first-touch form-control psw-input is-must" on-focus="input-focus" on-blur="input-blur" tabindex=5>
     <span class="notyet speciallabel">last name</span>
     <div class="input-group-addon req"><i class="fa fa-fw fa-asterisk"></i>
     </div>
    </div>
   </div>
  </div>

  <div class="row formRow">
   <div class="col-sm-12">
    <div class="input-group">
     <input type="text" id="form-title" placeholder="Title" value={{Title}} minlength=2 class="first-touch form-control psw-input is-must" on-focus="input-focus" on-blur="input-blur" tabindex=6>
     <span class="notyet speciallabel">title</span>
     <div class="input-group-addon req"><i class="fa fa-fw fa-asterisk"></i>
     </div>
    </div>
   </div>
  </div>

   <div class="row formRow">
   <div class="col-sm-12">
    <div class="input-group">
     <select value='{{selectedJobDuty}}' id="#form-job-duty" on-focus="input-focus" on-blur="select-blur:jobduties,selectedJobDuty" class="first-touch form-control psw-select is-must" tabindex=7>
      {{#jobduties}}
      <option value='{{.}}'>{{.}}</option>
      {{/jobduties}}
     </select>
     <span class="notyet speciallabel selectable">job duty</span>
     <div class="input-group-addon req"><i class="fa fa-fw fa-asterisk"></i>
     </div>
    </div>
   </div>
  </div>

  {{#otherJobDutySelected}}
  <div class="row formRow">
   <div class="col-sm-12">
    <div class="input-group">
     <input type="text" id="form-job-duty-other" placeholder="Other (please explain)" minlength=2 value={{AW_Job_Duties_Other}} class="first-touch form-control psw-input" on-focus="input-focus" on-blur="input-blur" tabindex=8>
     <span class="notyet speciallabel">other (please explain)</span>
     <div class="input-group-addon req"><i class="fa fa-fw fa-asterisk"></i>
     </div>
    </div>
   </div>
  </div>
  {{/otherJobDutySelected}}

  {{#isBizEmail}}
  <div class="row formRow">
  <div class="col-sm-12 text-center email-warning-msg" intro=fade outro=fade>
   <i class="fa fa-fw fa-warning"></i> Sorry, emails that use
   <strong>info</strong>,
   <strong>sales</strong> or
   <strong>help</strong> are not permitted.
  </div>
  </div>
  {{/isBizEmail}}

  <div class="row formRow">
   <div class="col-sm-12">
    <div class="input-group">
     <input type="text" id="form-direct-phone" placeholder="Direct phone number" data-phone="true" value={{Phone}} class="form-control psw-input" phone=true on-focus="input-focus" on-blur="input-blur:phone" on-keydown="phone-formatting" tabindex=9>
     <span class="notyet speciallabel">direct phone number</span>
     <div class="input-group-addon req"><i class="fa fa-fw"></i>
     </div>
    </div>
   </div>
   </div>

  <div class="row formRow">
   <div class="col-sm-12">
    <div class="input-group">
     <select value="{{selectedRevenue}}" id="form-company-annual-revenue" on-focus="input-focus" on-blur="input-blur" class="first-touch form-control psw-select" on-blur="select-blur:revenues,selectedRevenue" tabindex=11>
      {{#revenues}}
      <option value='{{.}}'>{{.}}</option>
      {{/revenues}}
     </select>
     <span class="notyet speciallabel selectable">annual company revenue</span>
     <div class="input-group-addon req"><i class="fa fa-fw fa-asterisk"></i>
     </div>
    </div>
   </div>
   </div>

   <div class="row formRow">
   <div class="col-sm-12">
    <div class="input-group">
     <select value="{{selectedIndustry}}" id="form-company-industry" on-focus="input-focus" on-blur="select-blur:industries,selectedIndustry" class="first-touch form-control psw-select is-must" tabindex=12>
      {{#industries}}
      <option value='{{.}}'>{{.}}</option>
      {{/industries}}
     </select>
     <span class="notyet speciallabel selectable">select industry</span>
     <div class="input-group-addon req"><i class="fa fa-fw fa-asterisk"></i>
     </div>
    </div>
   </div>
  </div>

  {{#otherIndustrySelected}}
  <div class="row formRow">
   <div class="col-sm-12">
    <div class="input-group">
     <input type="text" id="form-company-industry-other" placeholder="Other (please explain)" minlength=2 value={{AW_Industry_Other}} class="first-touch form-control psw-input is-must" on-focus="input-focus" on-blur="input-blur" tabindex=13>
     <span class="notyet speciallabel">other (please explain)</span>
     <div class="input-group-addon req"><i class="fa fa-fw fa-asterisk"></i>
     </div>
    </div>
   </div>
  </div>
  {{/otherIndustrySelected}}

  {{>checkboxalley}}


  <div class="row finalRow">
   <div class="col-sm-8">
    <a href="#" class="btn btn-sm btn-block shittiebutton" on-click="form-submit:newcompany" id="form-submit-button" tabindex=14>SUBSCRIBE</a>
   </div>
   <div class="col-sm-12" id="helpdesk">Stuck? <a href="mailto:help@automationworld.com?subject=Help subscribing to AutomationWorld">Email us.</a></div>
  </div>



  {{/with}}

 </script>

 <!-- Our existing company form state. -->
 <!-- {{>isexisting-template}} -->
 <script id="isexisting" type="text/ractive">
 <div class="col-sm-12 existing-top">
  <div class="existing-greeting">Tell us about yourself</div>

 {{#with companyData}}

 <div class="row">
  <div class="col-sm-12">
   <div class="cta-sub-main">{{company_name}}</div>
  </div>
 </div>

 <div class="row">
  <div class="col-sm-12">
   <div class="cta-sub-sub-main">{{address_1}} {{address_2}}</div>
  </div>
  <div class="col-sm-12">
   <div class="cta-sub-sub-main">{{city}}, {{state}} {{zipcode}}</div>
  </div>
 </div>

 <div class="row spacerRow">
  <div class="col-sm-9 com-sm-offset-3"><a href="#" on-click="reset-form" class="change-button"><i class="fa fa-fw fa-chevron-right"></i>not your organization?</a>
  </div>
 </div>
 {{/with}}
 </div>

 <div class="col-sm-12">
  {{#submitErrors}} {{>formerror}} {{/submitErrors}}
  {{#with userInformation}}
  {{#isBizEmail}}
  <div class="row formRow">
  <div class="col-sm-12 email-warning-msg" intro=fade outro=fade>
   <i class="fa fa-fw fa-warning"></i> Sorry, emails that use
   <strong>info</strong>,
   <strong>sales</strong> or
   <strong>help</strong> are not permitted.
  </div>
  </div>
  {{/isBizEmail}}

  <div class="row firstRow">
  <div class="col-sm-12">
   <div class="input-group">
    <input type="text" id="form-work-email" placeholder="Work email" value={{Email}} data-email="true" class="form-control psw-input" first-touch on-focus="input-focus" on-blur="input-blur:email" tabindex=7>
    <span class="notyet speciallabel">work email</span>
    <div class="input-group-addon req"><i class="fa fa-fw fa-asterisk"></i>
    </div>
   </div>
  </div>
   </div>

   <div class="row formRow">
   <div class="col-sm-6">
    <div class="input-group">
     <input type="text" id="form-first-name" placeholder="First name" value={{First_name}} minlength=2 class="first-touch form-control psw-input is-must" on-focus="input-focus" on-blur="input-blur" tabindex=2>
     <span class="notyet speciallabel">first name</span>
     <div class="input-group-addon req"><i class="fa fa-fw fa-asterisk"></i>
     </div>
    </div>
   </div>

   <div class="col-sm-6">
    <div class="input-group">
     <input type="text" id="form-last-name" placeholder="Last name" value={{Last_name}} minlength=1 class="first-touch form-control psw-input is-must" on-focus="input-focus" on-blur="input-blur" tabindex=3>
     <span class="notyet speciallabel">last name</span>
     <div class="input-group-addon req"><i class="fa fa-fw fa-asterisk"></i>
     </div>
    </div>
   </div>
  </div>
  <div class="row formRow">
   <div class="col-sm-12">
    <div class="input-group">
     <input type="text" id="form-title" placeholder="Title" value={{Title}} minlength=2 class="first-touch form-control psw-input is-must" on-focus="input-focus" on-blur="input-blur" tabindex=4>
     <span class="notyet speciallabel">title</span>
     <div class="input-group-addon req"><i class="fa fa-fw fa-asterisk"></i>
     </div>
    </div>
   </div>
  </div>
  <div class="row formRow">
   <div class="col-sm-12">
    <div class="input-group">
     <select value='{{selectedJobDuty}}' id="#form-job-duty" on-focus="input-focus" on-blur="select-blur:jobduties,selectedJobDuty" class="first-touch form-control psw-select is-must" tabindex=5>
      {{#jobduties}}
      <option value='{{.}}'>{{.}}</option>
      {{/jobduties}}
     </select>
     <span class="notyet speciallabel selectable">job duty</span>
     <div class="input-group-addon req"><i class="fa fa-fw fa-asterisk"></i>
     </div>
    </div>
   </div>
  </div>

  {{#otherJobDutySelected}}
  <div class="row formRow">
   <div class="col-sm-12">
    <div class="input-group">
     <input type="text" id="form-job-duty-other" placeholder="Other (please explain)" minlength=2 value={{AW_Job_Duties_Other}} class="first-touch form-control psw-input is-must" on-focus="input-focus" on-blur="input-blur" tabindex=6>
     <span class="notyet speciallabel">other (please explain)</span>
     <div class="input-group-addon req"><i class="fa fa-fw fa-asterisk"></i>
     </div>
    </div>
   </div>
  </div>
  {{/otherJobDutySelected}}




  <div class="row formRow">
   <div class="col-sm-12">
    <div class="input-group">
     <input type="text" id="form-direct-phone" placeholder="Direct phone number" value={{Phone}} data-phone="true" class="form-control psw-input" on-focus="input-focus" on-blur="input-blur:phone" on-keydown="phone-formatting" tabindex=6>
     <span class="notyet speciallabel">direct phone number</span>
     <div class="input-group-addon req"><i class="fa fa-fw"></i>
     </div>
    </div>
   </div>


  </div>



  {{#if AW_Annual_Revenues === ''}}
  <div class="row formRow">
   <div class="col-sm-12">
    <div class="input-group">
     <select value="{{selectedRevenue}}" id="form-company-annual-revenue" on-focus="input-focus" on-blur="input-blur" class="first-touch form-control psw-select" on-blur="select-blur:revenues,selectedRevenue" tabindex=8>
      {{#revenues}}
      <option value='{{.}}'>{{.}}</option>
      {{/revenues}}
     </select>
     <span class="notyet speciallabel selectable">annual company revenue</span>
     <div class="input-group-addon req"><i class="fa fa-fw fa-asterisk"></i>
     </div>
    </div>
   </div>
  </div>
  {{/if}}

  {{#if (AW_Industry === '')}}
  <div class="row formRow">
  <div class="col-sm-12">
   <div class="input-group">
    <select value="{{selectedIndustry}}" id="form-company-industry" on-focus="input-focus" on-blur="select-blur:industries,selectedIndustry" class="first-touch form-control psw-select is-must" tabindex=12>
     {{#industries}}
     <option value='{{.}}'>{{.}}</option>
     {{/industries}}
    </select>
    <span class="notyet speciallabel selectable">select industry</span>
    <div class="input-group-addon req"><i class="fa fa-fw fa-asterisk"></i>
    </div>
   </div>
  </div>
 </div>

 {{#otherIndustrySelected}}
 <div class="row formRow">
  <div class="col-sm-12">
   <div class="input-group">
    <input type="text" id="form-company-industry-other" placeholder="Other (please explain)" minlength=2 value={{AW_Industry_Other}} class="first-touch form-control psw-input is-must" on-focus="input-focus" on-blur="input-blur" tabindex=13>
    <span class="notyet speciallabel">other (please explain)</span>
    <div class="input-group-addon req"><i class="fa fa-fw fa-asterisk"></i>
    </div>
   </div>
  </div>
 </div>
 {{/otherIndustrySelected}}

  {{/if}}

  {{>checkboxalley}}

  <div class="row finalRow">
   <div class="col-sm-8">
    <a href="#" class="btn btn-sm btn-block shittiebutton" on-click="form-submit:existing" id="form-submit-button" tabindex=11>SUBSCRIBE</a>
   </div>
   <div class="col-sm-12" id="helpdesk">Stuck? <a href="mailto:help@automationworld.com?subject=Help subscribing to AutomationWorld">Email us.</a></div>
  </div>
  {{/with}}

 </script>


 <!-- our primary panel when the user selects the subscribe tab -->
 <!-- all our partials are loaded within the bounds of this markup. -->
 <!-- This is not a partial so no {{>[?]}} tag here -->
 <script intro="fade" outro="fade" id="template" type="text/ractive">
 {{#if savingUserData}}
   {{>savingdata}}
 {{/if}}
  <div class="row">
  {{#unless cookiedUser}}
  {{#if showIntro}}
  <div class="row">
   <div class="col-sm-12">
    <div class="cta-main">SUBSCRIBE TO THE MAGAZINE OR E-NEWSLETTER</div>
   </div>
   <div class="col-sm-12">
    <div class="cta-sub-main uptop">Start your free subscription to AutomationWorld</div>
   </div>
  </div>
  {{/if}}
  {{/unless}}

  {{#if cookiedUser}}
  <div class="row">
   <div class="col-sm-12">
    <h3 class="cta-main maintain">MANAGE YOUR SUBSCRIPTION INFORMATION</h3>
   </div>
  </div>
  {{/if}}
  </div>

  <div class="row">

  <div class="col-md-6">
   <div class="row right-cta-wrapper">
    {{#if showIntro}}
      <div class="col-sm-10 right-cta-images">
       <img src="/sites/default/themes/awbs/images/subscribeitems.png" class="img-responsive {{showIntro ? 'small-adjustment':'hidden-sm hidden-xs'}}">
      </div>
    {{else}}
     <div class="row">
      <div class="col-sm-12">
      <div class="existing-greeting alternate">select your subscriptions</div>
       {{>prefcenter}}
      </div>
     </div>
    {{/if}}
   </div>
  </div>

  <div class="col-md-6">

   {{#showIntro}} {{>intro}} {{/showIntro}}

   <div class="row prime-row {{showIntro ? '':'hidden'}}">
    <div class="col-sm-12">
     {{#promptNew}}
     <span id="promptnew"><i class="fa fa-fw fa-bullhorn"></i>If you do not see your organization listed here, press enter to create it.</span>{{/promptNew}}
     <div class="input-group" id="primary-input-group">
      <input class="form-control psw-input" on-enter="sift-out" on-tab="sift-out" on-keyup="primary-check-content" on-focus="primary-input-focus" on-blur="primary-input-blur" id="primary-input" minlength="2" type="text" placeholder="&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;what organization do you work for?"
      value={{primeInput}} tabindex=1/>
      <span class="notyet speciallabel">what organization do you work for?</span>
      <div class="input-group-addon req prime"><i class="fa fa-fw"></i>
      </div>
     </div>
    </div>
    <div class="col-sm-12 extra-help" id="helpdesk">Stuck? <a href="mailto:help@automationworld.com?subject=Help subscribing to AutomationWorld">Email us.</a></div>
   </div>

   <div class="row">
    {{#newEntry}} {{>isnew}} {{/newEntry}} {{#existingEntry}} {{>isexisting}} {{/existingEntry}} {{#cookiedUser}} {{>iscookied}} {{/cookiedUser}}
   </div>
  </div>

  </div>
 </script>



<!-- <script src="pswidget.js"></script> --> <!-- !!! NEEDS TO BE INCLUDED WITH DRUPAL INSTANCE. !!! -->
 <script src='https://maps.googleapis.com/maps/api/js?libraries=places'></script> <!-- !!! NEEDS TO BE INCLUDED WITH DRUPAL INSTANCE. !!! -->
 <script>
 </script>
 <!-- the below code needs to be executed in order to polyfill older browsers that don't support dropdown lists. -->
 <!-- modernizer is included with the widgets code file. -->
