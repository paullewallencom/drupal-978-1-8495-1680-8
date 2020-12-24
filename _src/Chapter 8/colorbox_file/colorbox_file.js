(function ($) {

/**
 * Colorbox file behavior.
 */
Drupal.behaviors.initColorboxFile = {
  attach: function (context, settings) {
    if (!$.isFunction($.colorbox)) {
      return;
    }
    
    // Merge Colorbox settings with Colorbox file settings.
    var options = jQuery.extend({}, settings.colorbox);
    jQuery.extend(options, settings.colorboxFile);

    $('a.colorbox-file', context).once('init-colorbox-file').colorbox(options);
  }
};

})(jQuery);
