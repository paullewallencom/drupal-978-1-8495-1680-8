<?php

/**
 * @file
 *   drush integration for views_slideshow.
 */

/**
 * The jQuery Cycle plugin URI.
 */
define('JQUERY_CYCLE_DOWNLOAD_URI', 'https://github.com/downloads/malsup/cycle/jquery.cycle.all.latest.js');
define('JQUERY_CYCLE_FILE_NAME', 'jquery.cycle.all.js');

/**
 * Implementation of hook_drush_command().
 *
 * In this hook, you specify which commands your
 * drush module makes available, what it does and
 * description.
 *
 * Notice how this structure closely resembles how
 * you define menu hooks.
 *
 * See `drush topic docs-commands` for a list of recognized keys.
 *
 * @return
 *   An associative array describing your command(s).
 */
function views_slideshow_drush_command() {
  $items = array();

  // the key in the $items array is the name of the command.
  $items['jquery-cycle-plugin'] = array(
    'callback' => 'drush_jquery_cycle_plugin',
    'description' => dt("Downloads the jQuery Cycle plugin."),
    'bootstrap' => DRUSH_BOOTSTRAP_DRUSH, // No bootstrap.
    'arguments' => array(
      'path' => dt('Optional. A path where to install the jQuery Cycle plugin. If omitted Drush will use the default location.'),
    ),
    'aliases' => array('jcycle'),
  );

  return $items;
}

/**
 * Implementation of hook_drush_help().
 *
 * This function is called whenever a drush user calls
 * 'drush help <name-of-your-command>'
 *
 * @param
 *   A string with the help section (prepend with 'drush:')
 *
 * @return
 *   A string with the help text for your command.
 */
function views_slideshow_drush_help($section) {
  switch ($section) {
    case 'drush:jquery-cycle-plugin':
      return dt("Downloads the jQuery Cycle plugin from https://github.com/downloads/malsup/cycle, default location is sites/all/libraries.");
  }
}

/**
 * Command to download the jQuery Cycle plugin.
 */
function drush_jquery_cycle_plugin() {
  $args = func_get_args();
  if (!empty($args[0])) {
    $path = $args[0];
  }
  else {
    $path = 'sites/all/libraries/jquery.cycle';
  }

  // Create the path if it does not exist.
  if (!is_dir($path)) {
    drush_op('mkdir', $path);
    drush_log(dt('Directory @path was created', array('@path' => $path)), 'notice');
  }

  // Set the directory to the download location.
  $olddir = getcwd();
  chdir($path);

  $filename = basename(JQUERY_CYCLE_DOWNLOAD_URI);

  // Remove any existing jQuery Cycle plugin file
  if (is_file(JQUERY_CYCLE_FILE_NAME)) {
    drush_op('unlink', JQUERY_CYCLE_FILE_NAME);
    drush_log(dt('An existing jQuery Cycle plugin was overwritten at @path', array('@path' => $path)), 'notice');
  }

  // Download the jQuery Cycle JavaScript file
  if (!drush_shell_exec('wget ' . JQUERY_CYCLE_DOWNLOAD_URI)) {
    drush_shell_exec('curl -O ' . JQUERY_CYCLE_DOWNLOAD_URI);
  }
  
  //rename the jQuery Cycle JavaScript file to jquery.cycle.all.js
  drush_op('rename', $filename, JQUERY_CYCLE_FILE_NAME);

  // Set working directory back to the previous working directory.
  chdir($olddir);

  if (is_dir($path)) {
    drush_log(dt('jQuery Cycle plugin has been downloaded to @path', array('@path' => $path)), 'success');
  }
  else {
    drush_log(dt('Drush was unable to download the jQuery Cycle plugin to @path', array('@path' => $path)), 'error');
  }
}
