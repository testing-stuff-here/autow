<?php if($page): ?>
  <div id="node-<?php print $node->nid; ?>">
    <?php //dsm($content); ?>
    <?php //dsm($field_top_logo); ?>
    <div class="registration-col registration-col-left">
      <div class="registration-logos">
        <?php if ($content['field_show_site_logo']) { ?>
          <span class="site-logo">
            <img src="http://www.automationworld.com/sites/default/themes/aw960/css/images/AWLogo.png" />
          </span>
        <?php } ?>
        <span class="sponsor-logo">
          <?php print render($content['field_sponsor_logo']); ?>
        </span>
      </div>
      <div class="registration-eyebrow">
        <?php print render($content['field_eyebrow']); ?>
      </div>
      <h1 class="registration-title">
        <?php print $title; ?>
      </h1>
      <div class="registration-top-copy">
        <?php print render($content['field_top_copy']); ?>
      </div>
      <div class="registration-image">
        <?php print render($content['field_image']); ?>
      </div>
      <div class="registration-body">
        <?php print render($content['body']); ?>
      </div>
      <div class="registration-disclaimer">
        <?php print render($content['field_disclaimer']); ?>
      </div>
    </div><!-- /.registration-col-left -->
    <div class="registration-col registration-col-right">
      <div class="registration-form">
        <div class="registration-form-title">
          <?php print render($content['field_form_header']); ?>
        </div>
        <div class="registration-form-inner">
          <?php print render($content['webform']); ?>
        </div>
      </div>
    </div><!-- /.registration-col-right -->
  </div>
<?php endif; ?>
<?php if($teaser): ?>
  <div id="node-<?php print $node->nid; ?>">
    <h2<?php print $title_attributes; ?>><?php print $title; ?></h2>
    <div class="body">
      <?php print render($content['body']); ?>
    </div>
  </div>
<?php endif; ?>
