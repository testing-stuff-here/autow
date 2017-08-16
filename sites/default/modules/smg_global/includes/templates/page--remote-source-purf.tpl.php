<?php if ($logged_in): ?>
  <div id="edit-links">
    <div id="edit-node"><a href="node/<?php echo $node->nid; ?>/edit">Edit</a></div>
  </div>
<?php endif; ?>
<div id="remote-source-purf-wrapper">
  <?php if (isset($url)): ?>
    <iframe src="<?php print $url; ?>" frameborder="0" height="100%" width="100%"></iframe>
  <?php endif; ?>
</div>
<div id="purf-hidden-links">
  <?php print render($page['content']['hidden_links']); ?>
</div>