(function ($) {
  
Drupal.behaviors.views_semantic_tabs =  {
  attach: function(context, settings) {
      $.each(settings.views_semantic_tabs, function(id) {
        var viewname = this.viewname;
        var display = this.display;
  
        /* the selectors we have to play with, will be unique per View instance*/
        var displaySelector = '.view-id-'+ viewname +'.view-display-id-'+ display +' .view-content dl';
        $(displaySelector, context).once('views_semantic_tabs').tabs();
      });
  }
};

})(jQuery);
