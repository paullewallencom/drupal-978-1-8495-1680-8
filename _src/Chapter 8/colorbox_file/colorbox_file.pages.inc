<?php
/**
 * @file
 * Colorbox file pages callbacks.
 */

/**
 * Menu callback; Displays a given file inside a colorbox.
 */
function colorbox_file_callback($file, $view_mode, $langcode) {
  if (!user_access('administer files') && (file_uri_scheme($file->uri) === 'private')) {
    return MENU_ACCESS_DENIED;
  }
  print drupal_render(file_view($file, $view_mode, $langcode));
}
