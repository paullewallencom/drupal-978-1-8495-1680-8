INSTALLATION
------------
1. Place the colorbox_file directory into your Drupal modules
   directory (normally sites/all/modules).

2. Enable the module by navigating to:

     Administration » Modules

CONFIGURATION
-------------

1. For your configured media field, go to "Manage display" and choose the
   "Colorbox file" format, and configure it. Choose the view mode of the file
   using "File view mode", and the view mode used within Colorbox using
   "Colorbox view mode".

2. If you are using the Media module to display fields, configure the chosen
   view modes by navigating to:

   Administration » Configuration » Media » File types » Manage display

   If you are directly using a file field, configure the chosen view modes.
   You may want to create additional view modes using hook_entity_info_alter()
   or a module like Display suite.

KNOWN ISSUES
------------

The default theme implementation of theme_image_style() does not include "width"
and "height" attributes on the IMG tag. This causes colorbox to resize to zero.
Override the theme_image_style() to include image dimensions, e.g. with :

/**
 * Override theme_image_style().
 */
function THEME_image_style($variables) {
  $style_name = $variables['style_name'];
  $path = $variables['path'];

  $style_path = image_style_path($style_name, $path);
  if (!file_exists($style_path)) {
    $style_path = image_style_url($style_name, $path);
  }
  $variables['path'] = $style_path;

  if (is_file($style_path)) {
    if (list($width, $height, $type, $attributes) = @getimagesize($style_path)) {
      $variables['width'] = $width;
      $variables['height'] = $height;
    }
  }
  
  return theme('image', $variables);
}
