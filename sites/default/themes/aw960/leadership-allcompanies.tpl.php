<div class="leadership-all-companies-list">
  <div class="ld-small-text">Browse these leading suppliers</div>

  <ul ng-controller="AllCompaniesBlockTermListCtrl" site="<?php print $site_id; ?>">
    <li ng-repeat="taxonomy in taxonomies">
      <taxonomy-list></taxonomy-list>
    </li>
  </ul>

  <div class="ie-mask ld-vote-button-wrapper">
    <a class="ld-vote-button" href="https://www.surveymonkey.com/r/T96Y6MH">VOTE NOW >></a>
  </div>

  <div class="ld-vote-prize">Win $250 VISA gift card!</div>

</div>
