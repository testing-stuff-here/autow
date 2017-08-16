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
<?php print $messages ?>
<div class="hidden-xs hidden-sm col-xs-12 container awbs-advertising-header">
  <?php print render($page['header']);  ?>
</div>
<div class="col-xs-12 wir-banner">
  <picture>
    <source srcset="/sites/default/themes/awbs/images/SASR/siemens_header_1400x84.png" media="(min-width: 1400px)">
    <source srcset="/sites/default/themes/awbs/images/SASR/siemens_header_1199x84.png" media="(min-width: 1199px)">
    <source srcset="/sites/default/themes/awbs/images/SASR/siemens_header_990x84.png" media="(min-width: 990px)">
    <img src="/sites/default/themes/awbs/images/SASR/siemens_header_375x84.png" class="img-responsive center-block animated fadeIn">
  </picture>
</div>



<div class="main-container container">
  <?php print render($title_suffix); ?>
  <!-- defining page content header for md+ sizing -->
  <?php if ($tabs): ?><div class="tabs"><?php print render($tabs); ?></div><?php endif; ?>

  <?php if (($page) && (arg(0) != 'home')): ?>
    <div class="row awbs-content-top">
      <section>
        <div class="col-xs-12">
          <div class="row">
            <h1 class="col-md-8 awbs-wir-title"><?php print render($title); ?></h1>
            <?php if ((isset($node)) && ($node->type != 'blog') && ($node->type != 'featured article')): ?>
              <?php if (isset($node_content) && ($node_content['field_byline'][0]['#markup'] <> NULL)): ?>
                <div class="hidden-xs hidden-sm col-md-8">
                  <div class="row awbs-content-byline wir-byline">
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
            <div class="col-xs-12 awbs-content-sharing">
              <div class="sharethis-wrapper row">
                <div class="col-xs-12">
                  <?php if($node->status == TRUE): ?>
                    <?php include('includes/sharethis-wrapper.php'); ?>
                  <?php endif; ?>
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

    <section class="col-sm-12 col-md-8" style="padding-left:20px; margin-bottom:10px; overflow-x: hidden; overflow-y: hidden;">
      <div class="block-image-wir">
        <?php print render($page['content']);?>
        <div>
    </section>
  </div>
</div> <!-- mainwrapper -->


<footer class="footer container-fluid">
  <?php print render($page['footer']); ?>
  <!-- @TODO make middle columns links active @TODO make social links active -->
</footer>

<script>
  // here we pass along our post type to Javascript, in case it needs that information.
  <?php
  if (isset($node)) {
    print 'var postType = "' . $node->type . '";';  // type of post
    print 'var subType = "regular";'; // subtype of post (if any) (163: feature article, for example)

    if ($node->field_article_length['und'][0]['value'] != 'long') {
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