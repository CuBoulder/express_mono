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
function hook_cu_js_embed_types() {
  $custom_embeds = array();

  $custom_embeds['my_pixel'] = array(
    'label' => 'My Tracking Pixel',
    'form_callback' => 'my_pixel_form',
    'submission_callback' => 'my_pixel_form_submit',
    'renderer' => 'block',
    'default_status' => 'unpublished',
    'path' => drupal_get_path('module', 'my_module'),
    'template' => 'templates/tracking-pixel-custom-service',
  );

  return $custom_embeds;
}

/**
 * Allows you to alter the types array after type declarations have been gathered.
 *
 * @param array $types
 *   Custom embed types declared by other modules.
 */
function hook_cu_js_embed_types_alter(&$types) {
  $types['my_pixel']['label'] = 'A Different Label';
}

/**
 * Add custom statuses for embeds.
 *
 * You need to return an array with the following keys.
 *
 * array $custom_status
 *   - label: The human-readable name of your status.
 *   - operation_callback: Callback for if someone selects a change to this
 *       status. NULL if no operation.
 *   - bulk_operation_label: Label for Embed Overview bulk operation select list.
 *       NULL if no operation.
 *   - confirmation_label: Label for confirmation screen.
 *   - add_permission: String of the permission to check for when changing statuses
 *       This should map to your hook_permission(). NULL if no permission needed.
 *
 * @return array
 *   An array with your custom status definitions.
 */


/**
 * Allows you to alter the statuses array after type declarations have been gathered.
 *
 * @param array $statuses
 *   Custom embed statuses declared by other modules.
 */
function hook_cu_js_embed_status_alter(&$statuses) {
  $statuses['in_review']['add_permission'] = 'a different permission name';
}
