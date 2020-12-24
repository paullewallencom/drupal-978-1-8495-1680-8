<?php
/**
 * @file
 * Contains the semantic tabs style plugin.
 */

/**
 * Semantic tabs style plugin to render rows decorated as tabs and
 * using the grouping field as the tab title.
 *
 * @ingroup views_style_plugins
 */
class views_semantic_tabs_style_plugin extends views_plugin_style {
 
  /**
   * Set default options
   */
  function option_definition() {
    $options = parent::option_definition();

    return $options;
  }

  /**
   * Options form
   */
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    $form['grouping']['#required'] = TRUE;
    $form['grouping']['#description'] = t('Grouping is required for this style.');
  }
  
  /**
   * Render the display in this style.
   */
  function render() {
   $output = parent::render();
    
    /*  set up JavaScript and CSS for tabs  */
    drupal_add_js(drupal_get_path('module', 'views_semantic_tabs') .'/js/jquery.tabs.js');
    drupal_add_js(drupal_get_path('module', 'views_semantic_tabs') .'/js/views-semantic-tabs.js');
    drupal_add_css(drupal_get_path('module', 'views_semantic_tabs') .'/css/tabs.css');

    $view_settings['display'] =  $this->view->current_display;
    $view_settings['viewname'] = $this->view->name;

    $views_semantic_tabs_id = 'views-semantic-tabs-'. $this->view->name .'-'. $this->view->current_display;

    drupal_add_js(array('views_semantic_tabs' => array($views_semantic_tabs_id  => $view_settings)), 'setting');
    $output = '<dl>' . $output . '</dl>';
    return $output;
  }
  
}
