
<?php if($page): ?>
 <div class="row" id="node-<?php print $node->nid; ?>">
   <div class="col-xs-12">
     <div class="row">
      <div class="col-xs-12 col-md-7">
       <div class="row">
        <div class="col-xs-12">

         <div class="row">
          <div class="col-xs-12"><?php print render($content['field_sponsor_logo']); ?></div>
         </div>

         <div class="row">
          <div class="col-xs-12 awbs-regpage-eyebrow"><?php print render($content['field_eyebrow']); ?></div>
          <div class="col-xs-12 awbs-regpage-title"><?php print $title; ?></div>
          <div class="col-xs-12 awbs-regpage-deckhead"><?php print render($content['field_top_copy']); ?></div>
         </div>

         <div class="row">
           <div class="col-xs-12 awbs-regpage-body">
            <?php print render($content['field_image']); ?>
            <?php print render($content['body']); ?>
           </div>
           <div class="col-xs-12 awbs-regpage-disclaimer">
            <?php print render($content['field_disclaimer']); ?>
           </div>
         </div>
        </div>
       </div>
      </div>
      <div class="col-xs-12 col-md-5">
       <div class="row">
        <div class="col-xs-12 awbs-regpage-form">
         <?php print '<div class="col-xs-12 awbs-regpage-form-header">' . render($content['field_form_header']) . '</div>'; ?>
         <?php print render($content['webform']); ?>
       </div>
       </div>
      </div>
     </div>
   </div>
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
