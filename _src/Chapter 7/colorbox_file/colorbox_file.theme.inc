<?php
/**
 * @file
 * Colorbox file theme functions.
 */

/**
 * Returns HTML for a Colorbox file field formatter.
 *
 * @param $variables
 *   An associative array containing:
 *   - item: A build array.
 *   - entity_id: The entity ID.
 *   - field: The field data.
 *   - display_settings: The display settings.
 *   - langcode: The language code.
 *   - path: The path to the content.
 *   - title: The title of the content.
 *
 * @ingroup themeable
 */
function theme_colorbox_file($variables) {
  $entity_id = $variables['entity_id'];
  $field = $variables['field'];
  $settings = $variables['display_settings'];
  //remove for chapter 7
  $caption = $variables['title'];
  
 //added the following switch for chapter 7
  switch ($settings['colorbox_caption']) {
    case 'title':
      $caption = $variables['title'];
      break;
    case 'mediafield':
      $caption = $variables['colorbox_file_caption'];
      break;
    default:
      $caption = '';
  }
  
  // Shorten the caption for the example styles or when caption shortening is active.
  $colorbox_style = variable_get('colorbox_style', 'default');
  $trim_length = variable_get('colorbox_caption_trim_length', 75);
  if ((variable_get('colorbox_caption_trim', 0)) && (drupal_strlen($caption) > $trim_length)) {
    $caption = drupal_substr($caption, 0, $trim_length - 5) . '...';
  }

  // Build the gallery id.
  switch ($settings['colorbox_gallery']) {
    case 'post':
      $gallery_id = 'gallery-' . $entity_id;
      break;
    case 'page':
      $gallery_id = 'gallery-all';
      break;
    case 'field_post':
      $gallery_id = 'gallery-' . $entity_id . '-' . $field['field_name'];
      break;
    case 'field_page':
      $gallery_id = 'gallery-' . $field['field_name'];
      break;
    case 'custom':
      $gallery_id = $settings['colorbox_gallery_custom'];
      break;
    default:
      $gallery_id = '';
  }

  $dimensions = explode('x', $settings['dimensions']);
  $js_settings = array(
    'initialWidth' => $dimensions[0],
    'initialHeight' => $dimensions[1],
  );

  drupal_add_js(array('colorboxFile' => $js_settings), 'setting');
  drupal_add_js(drupal_get_path('module', 'colorbox_file') . '/colorbox_file.js');

  return theme('link', array(
    'text' => drupal_render($variables['item']),
    'path' => $variables['path'],
    'options' => array(
      'html' => TRUE,
      'attributes' => array(
        'title' => $caption,
        'class' => 'colorbox-file',
        'rel' => $gallery_id,
      ),
    ),
  ));
}