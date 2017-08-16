<?php
/**
 * @file
 * Default theme implementation to display a single Drupal page.
 *
 * The doctype, html, head and body tags are not in this template. Instead they
 * can be found in the html.tpl.php template in this directory.
 *
 * Available variables:
 *
 * General utility variables:
 * - $base_path: The base URL path of the Drupal installation. At the very
 *   least, this will always default to /.
 * - $directory: The directory the template is located in, e.g. modules/system
 *   or themes/bartik.
 * - $is_front: TRUE if the current page is the front page.
 * - $logged_in: TRUE if the user is registered and signed in.
 * - $is_admin: TRUE if the user has permission to access administration pages.
 *
 * Site identity:
 * - $front_page: The URL of the front page. Use this instead of $base_path,
 *   when linking to the front page. This includes the language domain or
 *   prefix.
 * - $logo: The path to the logo image, as defined in theme configuration.
 * - $site_name: The name of the site, empty when display has been disabled
 *   in theme settings.
 * - $site_slogan: The slogan of the site, empty when display has been disabled
 *   in theme settings.
 *
 * Navigation:
 * - $main_menu (array): An array containing the Main menu links for the
 *   site, if they have been configured.
 * - $secondary_menu (array): An array containing the Secondary menu links for
 *   the site, if they have been configured.
 * - $breadcrumb: The breadcrumb trail for the current page.
 *
 * Page content (in order of occurrence in the default page.tpl.php):
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title: The page title, for use in the actual HTML content.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 * - $messages: HTML for status and error messages. Should be displayed
 *   prominently.
 * - $tabs (array): Tabs linking to any sub-pages beneath the current page
 *   (e.g., the view and edit tabs when displaying a node).
 * - $action_links (array): Actions local to the page, such as 'Add menu' on the
 *   menu administration interface.
 * - $feed_icons: A string of all feed icons for the current page.
 * - $node: The node object, if there is an automatically-loaded node
 *   associated with the page, and the node ID is the second argument
 *   in the page's path (e.g. node/12345 and node/12345/revisions, but not
 *   comment/reply/12345).
 *
 * Regions:
 * - $page['help']: Dynamic help text, mostly for admin pages.
 * - $page['highlighted']: Items for the highlighted content region.
 * - $page['content']: The main content of the current page.
 * - $page['sidebar_first']: Items for the first sidebar.
 * - $page['sidebar_second']: Items for the second sidebar.
 * - $page['header']: Items for the header region.
 * - $page['footer']: Items for the footer region.
 *
 * @see bootstrap_preprocess_page()
 * @see template_preprocess()
 * @see template_preprocess_page()
 * @see bootstrap_process_page()
 * @see template_process()
 * @see html.tpl.php
 *
 * @ingroup themeable
 */
?>

<!-- include the navmenu and the start of our body definition -->
<?php include('includes/navmenu.php'); ?>

<div class="container awbs-advertising-header <?php if (isset($enable_expo_countdown)) print 'expo-countdown'; ?>">
  <?php if (isset($enable_expo_countdown)): ?>
      <?php print $enable_expo_countdown; ?>
      <div class="expo-countdown-border-bottom"></div>
    <?php endif; ?>
  <?php print render($page['header']); ?>
</div>

<?php print $messages ?>

<div class="main-container container">
  <?php print render($title_suffix); ?>
  <!-- defining page content header for md+ sizing -->
  <?php if ($tabs): ?><div class="tabs"><?php print render($tabs); ?></div><?php endif; ?>

  <?php if (($page) && (arg(0) != 'home')): ?>
    <div class="row awbs-content-top">

      <?php if ((isset($node)) && ($node->type == 'blog')): ?>
        <?php $blogdata = awbs_blog_authorinfo($node); ?>
        <div class="col-xs-12">
          <div class="row awbs-blog-specialheader">
            <div class="col-xs-12 col-sm-12 col-md-7">
              <div class="row">
                <div class="hidden-xs col-sm-3 awbs-blog-headshot">
                  <?php if ($csia): ?>
                    <img src="/sites/default/themes/awbs/images/csialogo.jpg" class="img-responsive center-block csialogo">
                  <?php else: ?>
                    <img src="<?php print $blogdata['authorphoto']; ?>" class="img-responsive center-block">
                  <?php endif; ?>
                </div> <!-- 75x75 -->

                <div class="col-xs-12 col-sm-9 awbs-blog-details">
                  <div class="row">
                    <div class="col-xs-12 awbs-blog-title">
                      <?php if ($csia): ?>
                        <?php print 'CSIA Guest Blogger'; ?>
                      <?php else: ?>
                        <?php print $blogdata['blogtitle']; ?>
                      <?php endif; ?>
                    </div>

                    <?php if (isset($node_content) && ($node_content['field_byline'][0]['#markup'] <> NULL)): ?>
                      <div class="col-xs-12 awbs-blog-byline">By <span class="awbs-content-byline-text"><?php print $node_content['field_byline'][0]['#markup']; ?></span>
                        <?php if (isset($node_content['field_author_title'])) {
                          print ', ' . $node_content['field_author_title']['#items'][0]['value'] . ',';
                        } ?>
                        on <span class="awbs-content-byline-date"><?php print date("F j, Y",$node->created); ?></span>
                      </div>
                    <?php endif; ?>

                    <div class="col-xs-12 awbs-blog-social">

                      <?php if ($blogdata['authortwitter'] <> ''): ?>
                        <a href="//www.twitter.com/<?php print $blogdata['authortwitter']; ?>" class="awbs-blog-author-twitter">
                          <div class="awbs-social-button-wrapper aw-twitter" data-network="twitter">
                            <span class="awbs-social-button-icon"></span>
                            <div class="awbs-social-button-box">FOLLOW</div>
                          </div>
                        </a>
                      <?php endif; ?>

                      <?php if ($blogdata['authorlinkedin'] <> ''): ?>
                        <a href="//www.linkedin.com/in/<?php print $blogdata['authorlinkedin']; ?>" class="awbs-blog-author-linkedin">
                          <div class="awbs-social-button-wrapper aw-linkedin" data-network="linkedin">
                            <span class="awbs-social-button-icon"></span>
                            <div class="awbs-social-button-box">FOLLOW</div>
                          </div>
                        </a>
                      <?php endif; ?>

                    </div>
                  </div>
                </div>
              </div>
            </div>
          </div>
        </div>
      <?php endif; ?>

      <section>
        <div class="col-xs-12">
          <div class="row">
            <h1 class="hidden-xs hidden-sm col-md-8 awbs-content-title"><?php print render($title); ?></h1>
            <?php if ($node->type != 'video'): ?>
              <div class="hidden-xs hidden-sm col-md-8 awbs-content-deckhead">
                <?php if (isset($node_content['body']['#object']->field_deckhead)) {
                  print ($node_content['body']['#object']->field_deckhead['und']['0']['safe_value']);
                }?>
              </div>
            <?php endif; ?>

            <?php if ($node->field_term_subtype['und'][0]['tid'] == '166'): ?>
              <div class="hidden-xs hidden-sm col-md-8">
                <div class="row awbs-content-byline">
                  <div class="col-xs-12"><span class="awbs-content-byline-date"><?php print date("F j, Y",$node->created); ?></span></div>
                </div>
              </div>
            <?php endif; ?>

            <?php if ((isset($node)) && ($node->type != 'blog') && ($node->type != 'featured article')): ?>
              <?php if (isset($node_content) && ($node_content['field_byline'][0]['#markup'] <> NULL)): ?>
                <div class="hidden-xs hidden-sm col-md-8">
                  <div class="row awbs-content-byline">
                    <div class="col-md-12">By <span class="awbs-content-byline-text"><?php print $node_content['field_byline'][0]['#markup']; ?></span>
                      <?php if (isset($node_content['field_author_title'])) {
                        print ', ' . $node_content['field_author_title']['#items'][0]['value'] . ',';
                      } ?>
                      on <span class="awbs-content-byline-date"><?php print date("F j, Y",$node->created); ?></span>
                    </div>
                  </div>
                </div>
              <?php endif; ?>
            <?php endif; ?>
          </div>

          <div class="row">
            <div class="hidden-xs hidden-sm col-md-6 awbs-content-sharing">
              <div class="sharethis-wrapper row">
                <div class="col-xs-12">
                  <?php include('includes/sharethis-wrapper.php'); ?>
                </div>
              </div>
            </div>

            <?php
            if (isset($node_content)) {
              if ($node_content['field_tags'] <> NULL) { // Print something field
                $terms = awbs_parse_allterms($node->field_allterms['und'], 3);
                print '<div class="hidden-xs hidden-sm col-md-6 awbs-content-filed">FILED IN:';
                print '<div class="awbs-content-terms">' . implode(', ', $terms) . '</div>';
                print '</div>';
              }
            }?>

          </div>
        </div>
      </section>
    </div>
  <?php endif; ?>
  <!-- end page define -->

  <div class="row">
    <?php if (isset($node)): ?>
    <section class="col-sm-12 <?php if ((isset($node->field_article_length['und']) && $node->field_article_length['und'][0]['value'] != 'long') || $node->type == 'blog'): ?>col-md-8<?php else: ?>col-md-12<?php endif; ?>" style="padding:0;">
      <?php else: ?>
      <section class="col-sm-12 col-md-8" style="padding-left:20px; overflow-x: hidden; overflow-y: hidden;">
        <?php endif; ?>
        <?php print render($page['content']); ?>
      </section>

      <?php //if ( ((isset($node->field_term_subtype['und'][0]['tid'])) && ($node->field_term_subtype['und'][0]['tid'] != 163) ) || !isset($node)): ?>
      <?php if ( (isset($node)) && (in_array($node->type, array('blog', 'video', 'article'))) || (!isset($node))): ?>
        <?php if (
          !isset($node) ||
          !isset($node->field_article_length['und']) ||
          $node->field_article_length['und'][0]['value'] != 'long'
        ): ?>
          <?php if (!empty($page['sidebar_second'])): ?>
            <aside class="hidden-xs hidden-sm col-md-4 awbs-sidebar-overall" role="complementary">
              <?php print render($page['sidebar_second']); ?>
            </aside>  <!-- /#sidebar-second -->
          <?php endif; ?>
        <?php endif; ?>
      <?php endif; ?>

  </div>
</div> <!-- mainwrapper -->

<footer class="footer container-fluid">
  <?php print render($page['footer']); ?>
  <!-- @TODO make middle columns links active @TODO make social links active -->
</footer>


<?php include drupal_get_path('theme', 'awbs') . '/includes/footer/fixed-footer.php';?>

<?php
// if this is a long type article (but not feature length), inject the lia
// datacard so it can be replaced into the article body via JS.
if (
  isset($node) &&
  $node->type == 'article' &&
  isset($node->field_article_length['und']) &&
  $node->field_article_length['und'][0]['value'] == 'long'
) {
  print $liainsert;
}
?>

<script>
  // here we pass along our post type to Javascript, in case it needs that information.
  <?php
  if (isset($node)) {
    print 'var postType = "' . $node->type . '";';  // type of post
    print 'var subType = "regular";'; // subtype of post (if any) (163: feature article, for example)

    if (isset($node->field_article_length['und']) && $node->field_article_length['und'][0]['value'] != 'long') {
      print 'var postLength = "short";'; // short
    }
    else {
      print 'var postLength = "long";'; // long
    }
  }
  else {
    print 'var postType = "nonode";';
    print 'var subType = "regular";';
    print 'var postLength = "short";';
  } ?>
</script>
