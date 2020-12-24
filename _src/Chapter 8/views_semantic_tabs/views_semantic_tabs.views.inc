<?php

/**
 * Implements hook_views_plugins
 */
function views_semantic_tabs_views_plugins() {
  $module_path = drupal_get_path('module', 'views_semantic_tabs');
  return array(
    'style' => array(
      // Views style plugin for semantic tabs.
      'views_semantic_tabs' => array(
        'title' => t('Semantic Tabs'),
        'help' => t('Displays grouped rows as semantic tabs with jQuery.'),
        'handler' => 'views_semantic_tabs_style_plugin',
        'uses row plugin' => TRUE,
        'uses grouping' => TRUE,
        'uses options' => TRUE,
        'type' => 'normal',
        'theme' => 'views_semantic_tabs',
      ),
    ),
  );
}
