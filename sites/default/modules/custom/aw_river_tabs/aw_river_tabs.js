(function ($) {
  Drupal.behaviors.aw_river_tabs = {attach: function(context, settings) {

       active_taxonomy = $('.form-item-tab-filter #edit-tab-filter').val();

       switch(active_taxonomy) {
         case '':
          $('.views-submit-button #edit-submit-1').addClass('selected');
         break;
         case 'Manufacturing':
          $('.views-submit-button #edit-submit-2').addClass('selected');
         break;
         case 'Industry Trends':
          $('.views-submit-button #edit-submit-3').addClass('selected');
         break;
         case 'Innovation':
          $('.views-submit-button #edit-submit-4').addClass('selected');
         break;
       }

       $('.views-submit-button #edit-submit-1').click(function(e) {
         e.preventDefault();
         $('.views-exposed-widget #edit-tab-filter').val('');
         ga('send', 'event', 'Home Tab Filter', 'All Articles');
         submit_tab($(this));
       });

       $('.views-submit-button #edit-submit-2').click(function(e) {
         e.preventDefault();
         $('.views-exposed-widget #edit-tab-filter').val('Workforce');
         ga('send', 'event', 'Home Tab Filter', 'Workforce');
         submit_tab($(this));
       });

       $('.views-submit-button #edit-submit-3').click(function(e) {
         e.preventDefault();
         $('.views-exposed-widget #edit-tab-filter').val('Acquisitions');
         ga('send', 'event', 'Home Tab Filter', 'Acquisitions');
         submit_tab($(this));
        });

       $('.views-submit-button #edit-submit-4').click(function(e) {
         e.preventDefault();
         $('.views-exposed-widget #edit-tab-filter').val('Event Coverage');
         ga('send', 'event', 'Home Tab Filter', 'Event Coverage');
         submit_tab($(this));
        });

       function submit_tab(current_tab) {
         $(current_tab).siblings('.form-submit').removeClass('selected');
         $(current_tab).addClass('selected');
         $('.views-submit-button #edit-submit-home-river-of-content').click();
         $('.views-submit-button #edit-submit-category-part-1').click();
      }

  }
  };
})(jQuery);
