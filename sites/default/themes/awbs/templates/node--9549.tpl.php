<?php print render($content['body']); ?>
<script>
 // here we pass along our post type to Javascript, in case it needs that information.
 <?php
       print 'var postType = "' . $node->type . '";';  // type of post
       print 'var subType = "regular";'; // subtype of post (if any) (163: feature article, for example)
       if($node->field_article_length['und'][0]['value'] != 'long') {
        print 'var postLength = "short";'; // short
       } else {
        print 'var postLength = "long";'; // long
       }
 ?>
</script>
