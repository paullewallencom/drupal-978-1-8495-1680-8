(function ($) {

/**
 * Media Colorbox behavior.
 */
Drupal.behaviors.initMediaColorbox = {
  attach: function (context, settings) {
    if (!$.isFunction($.colorbox)) {
      return;
    }
    // Merge Colorbox settings with Media Colorbox settings.
    var options = jQuery.extend({}, settings.colorbox);
    jQuery.extend(options, settings.mediaColorbox);

    $('a.media-colorbox', context).once('init-media-colorbox').colorbox(options);
  }
};

})(jQuery);
