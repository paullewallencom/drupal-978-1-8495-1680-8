<?php

/**
 * @file
 * This file is empty by default because the base theme chain (Alpha & Omega) provides
 * all the basic functionality. However, in case you wish to customize the output that Drupal
 * generates through Alpha & Omega this file is a good place to do so.
 * 
 * Alpha comes with a neat solution for keeping this file as clean as possible while the code
 * for your subtheme grows. Please read the README.txt in the /preprocess and /process subfolders
 * for more information on this topic.
 */

 /**
 * Implements hook_form_FORM_ID_alter ().
 */
function d7dev_theme_form_contact_site_form_alter(&$form, &$form_state, $form_id) {
  $form['#prefix'] = t("Please fill out the follwing form if you have any questions about the d7dev site.");
}
