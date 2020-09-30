<?php

/**
 * @file
 * Form functions for cu_js_embed module.
 */

// Include confirm form file.
module_load_include('inc', 'cu_js_embed', 'forms/cu_js_embed.confirm_form');

/**
 * Form for adding embeds.
 *
 * @param array $form
 *   Empty form passed in to be built upon.
 * @param array $form_state
 *   State of form which might be in confirmation step.
 * @param int|null $cu_js_embed_id
 *   ID of embed if being edited or deleted.
 *
 * @return array
 *   Fully built form ready to send to user.
 */
function cu_js_embed_form($form, &$form_state, $cu_js_embed_id = NULL) {

  // If set to delete embeds, then return that form.
  if (isset($form_state['storage']['confirm'])) {
    return cu_js_embed_confirm($form, $form_state);
  }

  // Initialize default form variables.
  $form = array();
  $label = $path = '';
  $data = array();
  $cu_js_embed = NULL;
  $id = NULL;
  $size = variable_get('cu_js_embed_form_field_size', 128);

  // Load embed if it exists.
  if ($cu_js_embed_id != NULL && $cu_js_embed = entity_load_single('cu_js_embed', $cu_js_embed_id)) {
    // Grab existing values to place in form.
    $label = $cu_js_embed->name;
    $type = $cu_js_embed->type;
    $data = unserialize($cu_js_embed->data);
    $id = $cu_js_embed_id;

    // Store embed in form for form submission processing.
    $form_state['cu_js_embed'] = $cu_js_embed;

    // @todo Deal with embed templates entity not loading?
  }
  else {
    // Get type.
    $path_parts = explode('/', current_path());
    $type = array_pop($path_parts);

    // Get type definition.
    $type_definition = cu_js_embed_get_embed_type($type);
  }

  $form['embed'] = array(
    '#type' => 'fieldset',
    '#title' => t('Embed'),
    '#weight' => -10,
  );

  $form['embed']['label'] = array(
    '#title' => t('Label'),
    '#description' => t('Administrative label used in overview screen.'),
    '#type' => 'textfield',
    '#default_value' => $label,
    '#required' => TRUE,
    '#size' => $size,
  );

  // Add options for save and cancel.
  $form['actions'] = array(
    '#type' => 'actions',
    'submit' => array(
      '#type' => 'submit',
      '#value' => t('Save'),
    ),
  );
  $form['actions']['cancel'] = array(
    '#type' => 'submit',
    '#value' => t('Cancel'),
    '#submit' => array('embed_code_form_cancel'),
    '#limit_validation_errors' => array(),
  );

  // Add delete button only if editing an embed.
  if (isset($cu_js_embed) && user_access('delete embeds')) {
    $form['actions']['delete'] = array(
      '#type' => 'submit',
      '#submit' => array('cu_js_embed_form_submit'),
      '#value' => t('Delete'),
    );
  }

  // @todo possibly disable parts of form if no "Publishing Options" are available
  // to the user.

  // Get the specific parts of the embed form.
  if (!isset($form['confirm'])) {
    call_user_func_array(cu_js_embed_get_form_callback($type), array(
      &$form,
      &$form_state,
      $id,
      $data
    ));
  }

  return $form;
}

/**
 * Submit function for adding or editing an embed.
 *
 * @param array $form
 *   Fully built form shown to user.
 * @param array $form_state
 *   Ste of form with user-entered values.
 *
 * @return mixed
 *   Ends up redirecting user so nothing is really returned.
 */
function cu_js_embed_form_submit(&$form, &$form_state) {

  // If the user has chosen the delete operation, then try to delete embed.
  // Otherwise, go about trying to save embed information.
  if ($form_state['input']['op'] == 'Delete') {
    // If the user hasn't confirmed, they want to delete items, send them to confirm form.
    if (!isset($form_state['storage']['confirm'])) {
      // @todo Don't have recursive $form_state. Probably only store part of the array I need.
      $form_state['storage']['form_state'] = $form_state;
      $form_state['storage']['form'] = $form;
      // This will cause the form to be rebuilt returning to the confirm part of the form.
      $form_state['storage']['confirm'] = TRUE;
      $form_state['rebuild'] = TRUE;
      return $form_state;
    }
    else {
      // Call submission callback in case embeds need to do something for deletion.
      if ($submission_callback = cu_js_embed_get_submission_callback($form_state['cu_js_embed']->type)) {
        call_user_func($submission_callback, $form_state['cu_js_embed'], 'delete');
      }

      // Finally delete embed and redirect to the embed codes overview form.
      entity_delete('cu_js_embed', $form_state['cu_js_embed']->id);
      $form_state['redirect'] = 'admin/content/embeds';
    }
  }
  else {

    // Take type form URL or embed entity.
    if (isset($form_state['cu_js_embed'])) {
      $type = $form_state['cu_js_embed']->type;
      $renderer = $form_state['cu_js_embed']->renderer;
    }
    else {
      $path_parts = explode('/', current_path());
      $type = array_pop($path_parts);
      $renderer = cu_js_embed_get_renderer($type);
    }

    // Build data array for serialization by grabbing form values for embed type.
    $data = array();
    $options = array();

    foreach ($form['options'] as $key => $value) {
      if (strpos($key, '#') === FALSE) {
        $options[] = $key;
      }
    }

    // @todo Deal with possibility of form elements with same keys. Input values are overwritten if they have the same keys.
    foreach ($form_state['values'] as $key => $value) {
      if (in_array($key, $options)) {
        $data[$key] = $value;
      }
    }

    // Account for embed with no paths. Used for Context and Beans.
    $path = !empty($form_state['values']['path']) ? $form_state['values']['path'] : 'N/A';

    // Need user for embed overview page.
    global $user;

    // If editing an embed, add data to existing embed object.
    // Otherwise, make a new embed entity.
    if (isset($form_state['cu_js_embed']->id)) {
      $cu_js_embed = $form_state['cu_js_embed'];
      $cu_js_embed->name = $form_state['values']['label'];
      $cu_js_embed->author = $user->name  ?: 'N/A';
      $cu_js_embed->updated = REQUEST_TIME;
      $cu_js_embed->type = $type;
      $cu_js_embed->renderer = $renderer;
      $cu_js_embed->data = serialize($data);
    }
    else {
      $values = array(
        'name' => $form_state['values']['label'],
        'author' => $user->name ?: 'N/A',
        'updated' => REQUEST_TIME,
        'type' => $type,
        'renderer' => $renderer,
        'data' => serialize($data),
      );
      $cu_js_embed = entity_create('cu_js_embed', $values);
    }

    // Call submission callback in case embeds need to do something for creation/save.
    if ($submission_callback = cu_js_embed_get_submission_callback($type)) {
      call_user_func($submission_callback, $cu_js_embed, 'save');
    }

    // @todo make sure that the type + name is unique and send form error if not. Probably best to do in validation function.
    $success = $cu_js_embed->save();

    // Redirect to overview page if successful.
    // Otherwise, show error to user.
    if ($success) {
      $form_state['redirect'] = 'admin/content/embeds';
    }
    else {
      drupal_set_message('Embed code could not be saved. Please try again.', 'error');
    }
  }
}
