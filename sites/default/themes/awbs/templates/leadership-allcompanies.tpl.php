<div class="leadership-all-companies-list col-md-12">
  <div class="ld-small-text">Browse these leading suppliers</div>

  <ul ng-controller="AllCompaniesBlockTermListCtrl" site="<?php print $site_id; ?>">
    <li ng-repeat="taxonomy in taxonomies">
      <taxonomy-list></taxonomy-list>
    </li>
  </ul>
</div>
