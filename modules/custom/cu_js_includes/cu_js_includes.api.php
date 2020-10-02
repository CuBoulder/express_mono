<?php

/**
 * @file
 * API hooks for the Embed Templates module.
 */

/**
 * Add your custom embed types.
 *
 * These array definitions are split up into forms and how the data is rendered.
 *
 * array $custom_embed
 *   - label: The human-readable name of your embed type.
 *   - form_callback: This callback generates the form elements for embed creation.
 *   - submission_callback: This callback fires when the embed form is saved.
 *       Useful for doing things before an entity is created/deleted.
 *   - renderer: Machine name of the renderer to use when displaying template.
 *   - default_status: The status your embed type that is set as default on the
 *       embed add form.
 *   - path: The path of the module where the template file is located.
 *   - custom_template: You need to enter the relative path to your template file
 *       from the module root.
 *
 * @return array
 *   An array with your custom embed definitions.
 */
function hook_cu_js_includes_types() {
  $custom_includes = array();

  $custom_includes['my_pixel'] = array(
    'label' => 'My Tracking Pixel',
    'form_callback' => 'my_pixel_form',
    'submission_callback' => 'my_pixel_form_submit',
    'renderer' => 'block',
    'default_status' => 'unpublished',
    'path' => drupal_get_path('module', 'my_module'),
    'template' => 'templates/tracking-pixel-custom-service',
  );

  return $custom_includes;
}

/**
 * Allows you to alter the types array after type declarations have been gathered.
 *
 * @param array $types
 *   Custom embed types declared by other modules.
 */
function hook_cu_js_includes_types_alter(&$types) {
  $types['my_pixel']['label'] = 'A Different Label';
}
