<?php if($page): ?>
  <div id="node-<?php print $node->nid; ?>">
    <div id="pop-up-inner">
      <div id="pop-up-bottom">
        <div id="pop-up-wrapper" class="pop-up-form-wrapper">
          <div id="pop-up-form">
            <div id="pop-up-form-inner">            
              <?php print render($content['webform']); ?>
              <?php // print render($content['webform']['#form']['submitted']); ?>
              <?php //print drupal_render_children($content['webform']['#form']); ?>
            </div>
          </div>
        </div><!-- /#playbook-bottom-col-2 -->
      </div><!-- /#playbook-bottom -->
    </div><!-- /#playbook-inner -->
  </div>
<?php endif; ?>
