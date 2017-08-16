<?php if($page): ?>
  <div id="node-<?php print $node->nid; ?>">
    <div id="playbook-inner">
      <div id="social-media">
        <div class="sharethis-wrapper">
          <?php if($node->status == TRUE): ?>
            <span class='st_linkedin_hcount' displayText='LinkedIn'></span>
            <span class='st_twitter_hcount' displayText='Tweet'></span>
            <span  class='st_plusone_hcount' displayText="Google +"></span>
            <span class="st_facebook_hcount" displayText="Facebook"></span>
            <script type="text/javascript">var switchTo5x=true;</script>
            <script type="text/javascript" src="http://w.sharethis.com/button/buttons.js"></script>
            <script type="text/javascript">stLight.options({publisher:'8e3ea5bc-dfce-4ddf-8d7b-f1ddfb9b57ab'});</script>
          <?php endif; ?>
        </div>
      </div><!-- /#social-media -->
      <div id="playbook-top">
        <div id="playbook-cover">
          <?php print render($content['field_cover_image']); ?>
        </div>
        <div id="playbook-title-div">
          <?php
          /*
          SEO Fix - Remove the div wrappers
          @TODO - not sure why we are not using the regular title field here.  
          */
          ?>
            <h1 id="playbook-title"><?php print $content['field_playbook_name'][0]['#markup']; ?></h1>
          <div id="playbook-sub-title"><?php print render($content['field_sub_title']); ?></div>
          <div id="playbook-top-copy"><?php print render($content['field_top_copy']); ?></div>
        </div>
      </div><!-- /#playbook-top -->
      <div id="playbook-bottom">
        <div id="playbook-bottom-col-1" class="playbook-bottom-col">
          <div id="playbook-experts">
            <h3>Experts</h3>
            <h6>Sourced in this e-book</h6>
            <div id="playbook-experts-inner">
              <?php print render($content['field_expert']); ?>
            </div>
          </div><!-- /#playbook-experts -->
          <div id="playbook-description">
            <div id="playbook-body">
              <?php print render($content['body']); ?>
            </div>
            <div id="playbook-sponsors">
              <?php if (isset($content['field_sponsor'][0])) { ?>
                <h5>This playbook is proudly sponsored by:</h5>
              <?php } ?>
              <?php if(isset($content['field_image'])):?>
                <?php print render($content['field_image']); ?>
              <?php else: ?>
              <div id="playbook-sponsors-inner">
                <?php print render($content['field_sponsor']); ?>
              </div>
              <?php endif; ?>
            </div>
            <div id="playbook-disclaimer">
              <?php print render($content['field_disclaimer']); ?>
            </div>
          </div><!-- /#playbook-description -->
        </div><!-- /#playbook-bottom-col-1 -->
        <div id="playbook-bottom-col-2" class="playbook-bottom-col">
          <div id="playbook-form">
            <div id="playbook-form-title">
              Fill out the form below for an instant download!
            </div>
            <div id="playbook-form-inner">
              <?php print render($content['webform']); ?>
            </div>
          </div>
        </div><!-- /#playbook-bottom-col-2 -->
      </div><!-- /#playbook-bottom -->
    </div><!-- /#playbook-inner -->
  </div>
<?php endif; ?>
