<!-- desktop nav bar -->
<div class="mainwrapper">
  <header roll="banner" class="awbs-navbar hidden-xs hidden-sm"
          id="awbs-navbar">
    <div class="container-fluid navwrapper">
      <div class="row">
        <div class="col-xs-12">
          <div class="container">
            <div class="row awbs-logo-image">
              <div class="col-sm-4 col-sm-offset-4">
                <a href="/home"><img
                    src="<?php print '/' . drupal_get_path('theme', 'awbs') . '/images/AWLogo.png'; ?>"
                    class="img-responsive center-block"></a>
              </div>
            </div>
            <div class="row menubar">
              <ul>
                <li class="leaf"><a href="#"
                                    class="hamburger-toggle"
                                    id="hamburger-lg"><span></span></a>
                </li>
                <?php print render($primary_nav); ?>
                <li class="leaf awbs-nav-search">
                  <a href="#" id="search-lg">
                    <img src="/sites/default/themes/awbs/images/search.png"
                         class="img-responsive">
                  </a>
                </li>
              </ul>

              <div id="awbs-navbar-hamburger"
                   class="col-xs-12 awbs-navbar-dropdown-menu hamburger-menu">
                <div class="row awbs-dropdown-row">
                  <div class="col-xs-2 awbs-dropdown-row-header">
                    <strong>Magazine</strong></div>
                  <div class="col-xs-10">
                    <div class="awbs-dropdown-row-item"><a
                        href="/subscribe"
                        onclick="ga('send', 'event', 'Hamburger Menu', 'Drop Down', 'Subscribe');">Subscribe</a>
                    </div>
                    <div class="awbs-dropdown-row-item"><a
                        href="//www.pmmimediagroup.com/"
                        target="_blank"
                        onclick="ga('send', 'event', 'Hamburger Menu', 'Drop Down', 'Advertise');">Advertise</a>
                    </div>
                    <div class="awbs-dropdown-row-item"><a
                        href="/contact"
                        onclick="ga('send', 'event', 'Hamburger Menu', 'Drop Down', 'Contact');">Contact</a>
                    </div>
                    <div class="awbs-dropdown-row-item"><a
                        href="/current"
                        onclick="ga('send', 'event', 'Hamburger Menu', 'Drop Down', 'Current Issue');">Current
                        Issue</a></div>
                    <div class="awbs-dropdown-row-item"><a
                        href="/about"
                        onclick="ga('send', 'event', 'Hamburger Menu', 'Drop Down', 'About');">About</a>
                    </div>
                    <div class="awbs-dropdown-row-item"><a
                        href="/magazine"
                        onclick="ga('send', 'event', 'Hamburger Menu', 'Drop Down', 'Magazine');">Magazine</a>
                    </div>
                    <div class="awbs-dropdown-row-item"><a
                        href="/archive-magazine-issues"
                        onclick="ga('send', 'event', 'Hamburger Menu', 'Drop Down', 'Digital edition');">Digital
                        edition</a></div>
                  </div>
                </div>
                <div class="row awbs-dropdown-row">
                  <div class="col-xs-2 awbs-dropdown-row-header">
                    <strong>Conferences</strong></div>
                  <div class="col-xs-10">
                    <div class="awbs-dropdown-row-item"><a
                        href="http://www.theautomationconference.com/?webSyncID=374cd8ee-8363-0051-53b6-5e87294aa2ce&sessionGUID=34dec8ac-570e-eb0d-2140-6cec86c938ae"
                        onclick="ga('send', 'event', 'Hamburger Menu', 'Drop Down', 'Automation Conference Expo');">Automation
                        Conference & Expo</a></div>
                    <div class="awbs-dropdown-row-item"><a
                        href="/calendar-events"
                        onclick="ga('send', 'event', 'Hamburger Menu', 'Drop Down', 'All Events');">All
                        Events</a></div>
                  </div>
                </div>

                <div class="row awbs-dropdown-row">
                  <div class="col-xs-2 awbs-dropdown-row-header">
                    <strong>Playbooks</strong></div>
                  <div class="col-xs-10">
                    <div class="awbs-dropdown-row-item"><a
                        href="/playbooks/batch-process?csource=aw_utility_nav"
                        onclick="ga('send', 'event', 'Hamburger Menu', 'Drop Down', 'Batch Process Automation');">Batch
                        Process Automation</a></div>
                    <div class="awbs-dropdown-row-item"><a
                        href="/playbooks/continuous-process?csource=aw_utility_nav"
                        onclick="ga('send', 'event', 'Hamburger Menu', 'Drop Down', 'Continous Process Automation');">Continous
                        Process Automation</a></div>
                    <div class="awbs-dropdown-row-item"><a
                        href="/playbooks/factory-machine-automation-playbook?csource=aw_main"
                        onclick="ga('send', 'event', 'Hamburger Menu', 'Drop Down', 'Factory Machine Automation');">Factory
                        &amp; Machine Automation</a>
                    </div>
                  </div>
                </div>
                <div class="row awbs-dropdown-row">
                  <div class="col-xs-2 awbs-dropdown-row-header">
                    <strong>Tactical Briefs</strong></div>
                  <div class="col-xs-10">
                    <div class="awbs-dropdown-row-item"><a
                        href="/e-book-digital-manufacturing-through-plm-collaboration-data-visibility"
                        onclick="ga('send', 'event', 'Hamburger Menu', 'Drop Down', 'Collaborative Manufacturing');">Collaborative
                        Manufacturing</a></div>
                    <div class="awbs-dropdown-row-item"><a
                        href="/e-book-out-box-strategies-control-panel-optimization"
                        onclick="ga('send', 'event', 'Hamburger Menu', 'Drop Down', 'Control Panel Optimization');">Control
                        Panel Optimization</a></div>
                    <div class="awbs-dropdown-row-item"><a
                        href="/e-book-how-todays-embedded-tools-drive-tomorrows-solutions"
                        onclick="ga('send', 'event', 'Hamburger Menu', 'Drop Down', 'Embedded Systems Trends');">Embedded
                        Systems &amp; Trends</a></div>
                    <div class="awbs-dropdown-row-item"><a
                        href="/e-book-vision-based-applications-bring-new-benefits-affordability"
                        onclick="ga('send', 'event', 'Hamburger Menu', 'Drop Down', 'Embedded Vision in Manufacturing');">Embedded
                        Vision in Manufacturing</a>
                    </div>
                    <div class="awbs-dropdown-row-item read-more">
                      <a href="/tactical-briefs"
                         onclick="ga('send', 'event', 'Hamburger Menu', 'Drop Down', 'View all tactical briefs');">View
                        all</a></div>
                  </div>
                </div>
                <div class="row awbs-dropdown-row">
                  <div class="col-xs-2 awbs-dropdown-row-header">
                    <strong>Channels</strong></div>
                  <div class="col-xs-10">
                    <div class="awbs-dropdown-row-item"><a
                        href="http://www.totallyintegratedautomation.com/?webSyncID=374cd8ee-8363-0051-53b6-5e87294aa2ce&sessionGUID=34dec8ac-570e-eb0d-2140-6cec86c938ae"
                        onclick="ga('send', 'event', 'Hamburger Menu', 'Drop Down', 'Totally Integrated Automation');">Totally
                        Integrated Automation</a></div>
                    <div class="awbs-dropdown-row-item"><a
                        href="/device-integration-strategies"
                        onclick="ga('send', 'event', 'Hamburger Menu', 'Drop Down', 'Device Integration Strategies');">Device
                        Integration Strategies</a></div>
                    <div class="awbs-dropdown-row-item"><a
                        href="/360-product-review"
                        onclick="ga('send', 'event', 'Hamburger Menu', 'Drop Down', '360 Product Review');">360
                        Product Review</a></div>
                    <div class="awbs-dropdown-row-item"><a
                        href="/suppliernews"
                        onclick="ga('send', 'event', 'Hamburger Menu', 'Drop Down', 'Supplier News');">Supplier
                        News</a></div>
                    <div class="awbs-dropdown-row-item"><a
                        href="http://www.sps-magazin.de/"
                        onclick="ga('send', 'event', 'Hamburger Menu', 'Drop Down', 'SPS Magazine');">SPS
                        Magazine</a></div>
                  </div>
                </div>
                <?php print $webinar_links; ?>
                <?php print $deep_dive_links; ?>
                <div class="row awbs-dropdown-row">
                  <div class="col-xs-2 awbs-dropdown-row-header">
                    <strong>Leadership</strong></div>
                  <div class="col-xs-10">
                    <div class="awbs-dropdown-row-item"><a
                        href="/leaders"
                        onclick="ga('send', 'event', 'Hamburger Menu', 'Drop Down', 'View Leaders in Automation');">View
                        2016 Leaders in Automation</a>
                    </div>
                  </div>
                </div>
              </div>

              <div id="awbs-navbar-subscribe"
                   class="col-xs-12 awbs-navbar-dropdown-menu">
                <div class="row">
                  <div
                    class="col-xs-12 animated slideInDown awbs-navbar-subscribe-hero-content-text">
                    Looking to receive Automation World
                    magazine and newsletters?
                  </div>
                </div>
                <div class="row">
                  <div class="col-xs-6 awbs-navbar-subscribe-hero-image">
                    <img class="img-responsive center-block animated"
                         src="/sites/default/themes/awbs/images/subscribeitems.png">
                  </div>
                  <div class="col-xs-6 awbs-navbar-subscribe-hero-content">
                    <div class="row">
                      <div
                        class="col-xs-8 col-xs-offset-2 animated slideInRight">
                        <a href="/subscribe"
                           class="btn btn-sm btn-block awbs-btn"
                           onclick="ga('send', 'event', 'Hamburger Menu', 'Drop Down', 'Subscribe now');">Subscribe
                          now</a>
                      </div>
                    </div>
                  </div>
                </div>
              </div>

              <div id="awbs-navbar-aweditors"
                   class="col-xs-12 awbs-navbar-dropdown-menu">
                <div class="row">
                  <div class="col-xs-3 awbs-navbar-list-selections"
                       id="awbs-navbar-aweditors-selections">
                    <ul></ul>
                  </div>
                  <div class="col-xs-12 col-md-9"
                       id="awbs-navbar-aweditors-contents">
                    <div class="row"></div>
                  </div>
                </div>
              </div>

              <div id="awbs-navbar-products"
                   class="col-xs-12 awbs-navbar-dropdown-menu">
                <div class="row">
                  <div class="col-xs-3 awbs-navbar-list-selections"
                       id="awbs-navbar-products-selections">
                    <ul></ul>
                  </div>
                  <div class="col-xs-12 col-md-9"
                       id="awbs-navbar-products-contents">
                    <div class="row"></div>
                  </div>
                </div>
              </div>

              <div id="awbs-navbar-factory"
                   class="col-xs-12 awbs-navbar-dropdown-menu">
                <div class="row">
                  <div class="col-xs-3 awbs-navbar-list-selections"
                       id="awbs-navbar-factory-selections">
                    <ul></ul>
                  </div>
                  <div class="col-xs-12 col-md-9"
                       id="awbs-navbar-factory-contents">
                    <div class="row"></div>
                  </div>
                </div>
              </div>

              <div id="awbs-navbar-process"
                   class="col-xs-12 awbs-navbar-dropdown-menu">
                <div class="row">
                  <div class="col-xs-3 awbs-navbar-list-selections"
                       id="awbs-navbar-process-selections">
                    <ul></ul>
                  </div>
                  <div class="col-xs-12 col-md-9"
                       id="awbs-navbar-process-contents">
                    <div class="row"></div>
                  </div>
                </div>
              </div>

              <div id="awbs-navbar-engineering"
                   class="col-xs-12 awbs-navbar-dropdown-menu">
                <div class="row">
                  <div class="col-xs-3 awbs-navbar-list-selections"
                       id="awbs-navbar-engineering-selections">
                    <ul></ul>
                  </div>
                  <div class="col-xs-12 col-md-9"
                       id="awbs-navbar-engineering-contents">
                    <div class="row"></div>
                  </div>
                </div>
              </div>

              <div id="awbs-navbar-it"
                   class="col-xs-12 awbs-navbar-dropdown-menu">
                <div class="row">
                  <div class="col-xs-3 awbs-navbar-list-selections"
                       id="awbs-navbar-it-selections">
                    <ul></ul>
                  </div>
                  <div class="col-xs-12 col-md-9"
                       id="awbs-navbar-it-contents">
                    <div class="row"></div>
                  </div>
                </div>
              </div>


              <div id="awbs-navbar-operations"
                   class="col-xs-12 awbs-navbar-dropdown-menu">
                <div class="row">
                  <div class="col-xs-3 awbs-navbar-list-selections"
                       id="awbs-navbar-operations-selections">
                    <ul></ul>
                  </div>
                  <div class="col-xs-12 col-md-9"
                       id="awbs-navbar-operations-contents">
                    <div class="row"></div>
                  </div>
                </div>
              </div>

              <div id="awbs-navbar-video"
                   class="col-xs-12 awbs-navbar-dropdown-menu">
                <div class="row">
                  <div class="col-xs-3 awbs-navbar-list-selections"
                       id="awbs-navbar-video-selections">
                    <ul></ul>
                  </div>
                  <div class="col-xs-12 col-md-9"
                       id="awbs-navbar-video-contents">
                    <div class="row"></div>
                  </div>
                </div>
              </div>

              <div id="awbs-navbar-it"
                   class="col-xs-12 awbs-navbar-dropdown-menu search-menu">
                <div class="row">
                  <?php print render($search_block); ?>
                </div>
              </div>

            </div>
            <!-- menu dropdowns -->
            <div class="row">

            </div>
          </div>
        </div>
      </div>
    </div>
  </header>


  <!-- mobile nav bar -->
  <header roll="banner" class="awbs-navbar visible-xs visible-sm"
          id="awbs-mobile-navbar">

    <div class="container-fluid navwrapper">
      <div class="row">
        <div class="col-xs-1 col-xs-offset-1"><a href="#"
                                                 class="hamburger-toggle"
                                                 id="awbs-mobile-hamburger"><span></span></a>
        </div>
        <div class="col-xs-7 col-sm-8 center-block">
          <a href="/home"><img
              src="<?php print '/' . drupal_get_path('theme', 'awbs') . '/images/AWLogo.png'; ?>"
              class="img-responsive awbs-mobile-logo"></a>
        </div>
        <div class="col-xs-1 awbs-mobile-search">
          <a href="#" id="awbs-mobile-search">
            <img src="/sites/default/themes/awbs/images/magnifyingglass.png"
                 class="img-responsive center-block">
          </a>
        </div>
      </div>

      <div class="row awbs-mobile-nav-search animated">
        <?php print render($mobile_search_block); ?>
      </div>

      <div class="row awbs-mobile-nav-options animated">
          <?php
          $block = module_invoke('menu', 'block_view', 'menu-mobile-main-menu');
          print render($block['content']);
          ?>
      </div>

    </div>
  </header>
</div>
