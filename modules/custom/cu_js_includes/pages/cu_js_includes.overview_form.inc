<?php

/**
 * @file
 * Form functions for cu_js_includes module.
 */

// Include confirm form file.
module_load_include('inc', 'cu_js_includes', 'pages/cu_js_includes.confirm_form');

/**
 * A listing of embed codes.
 *
 * @param array $form
 *   Empty form to be built.
 * @param array $form_state
 *   Form state that might have embed info for confirmation steps.
 *
 * @return array
 *   The fully built form shown to users.
 */
function cu_js_includes_overview_form($form, &$form_state) {

  // If set to delete embeds, then return confirmation form.
  if (isset($form_state['storage']['confirm'])) {
    // Hacky way to get action link to not display...I hate myself.
    drupal_add_css('ul.action-links {display: none;}', array('type' => 'inline'));
    return cu_js_includes_confirm($form, $form_state);
  }

  // Initialize form array.
  $form = array();

  // Set title since it doesn't stick.
  drupal_set_title('Includes');

  // Add table for listing embed codes.
  // Table alias is "tp".
  $headers = array(
    'name' => array('data' => t('Name'), 'field' => 'tp.name'),
    'type' => array('data' => t('Type'), 'field' => 'tp.type'),
    'author' => array('data' => t('Author'), 'field' => 'tp.author'),
    'updated' => array('data' => t('Updated'), 'field' => 'tp.updated', 'sort' => 'desc'),
    'edit' => array('data' => t('Edit')),
  );

  // If search has been performed, then return embeds from the search.
  if (isset($form_state['storage']['search_includes'])) {
    $embed_ids = array_map(function ($value) {
      return $value->id;
    }, $form_state['storage']['search_includes']);

    $cu_js_includes = cu_js_includes_get_embeds(array('id' => $embed_ids), $headers);
  }
  else {
    // Get existing embed codes with no conditions and a sortable header.
    $cu_js_includes = cu_js_includes_get_includes(array(), $headers);
  }

  // Build table only if embed codes exist.
  if (!empty($cu_js_includes)) {
    // Place embed codes in $form_state for submission processing.
    $form_state['cu_js_includes'] = $cu_js_includes;
    $form_state['table_headers'] = $headers;

    // Add search form.
    $form = cu_js_includes_search_form($form, $form_state);

    // Add table of embeds.
    $form = cu_js_includes_includes_table($form, $form_state);
  }
  else {
    drupal_set_message(t('No include codes exist. You can create one by clicking the action link below.'), 'warning');
  }
  return $form;
}

/**
 * Callback to generate search part of embed overview page.
 *
 * @param array $form
 *   Form that contains defaults for embed overview page.
 * @param array $form_state
 *   Form state that might have previous search terms.
 *
 * @return array
 *   Fully built search form for overview page.
 */
function cu_js_includes_search_form($form, $form_state) {
  // Add search fieldset.
  $form['search'] = array(
    '#type' => 'fieldset',
    '#title' => 'Search',
  );

  // Search by embed name.
  $form['search']['name'] = array(
    '#title' => t('Include Name'),
    '#description' => t('Search for include by name.'),
    '#type' => 'textfield',
    '#default_value' => isset($form_state['storage']['search_name']) ? $form_state['storage']['search_name'] : '',
  );

  // Search by author.
  $form['search']['author'] = array(
    '#title' => t('Include Author'),
    '#description' => t('Search for includes by the last user who updated the include.'),
    '#type' => 'textfield',
    '#default_value' => isset($form_state['storage']['search_author']) ? $form_state['storage']['search_author'] : '',
  );

  // Search by type.
  $types_options = array_flip(array_keys(cu_js_includes_get_include_types()));
  // Make values human readable.
  array_walk($types_options, function (&$value, $key) {
    $value = ucwords(str_replace('_', ' ', $key));
  });
  // Add "any" key.
  $types_options = array('any' => '-Any-') + $types_options;

  $form['search']['type'] = array(
    '#title' => t('Include Type'),
    '#description' => t('Search for includes by type.'),
    '#type' => 'select',
    '#options' => $types_options,
    '#default_value' => isset($form_state['storage']['search_type']) ? $form_state['storage']['search_type'] : '',
  );

  $form['search']['search'] = array(
    '#type' => 'submit',
    '#value' => t('Search'),
    '#submit' => array('cu_js_includes_overview_form_submit'),
  );

  // Add select list for choosing operations.
  $operations = cu_js_includes_get_operations();

  // Remove operations that user doesn't have permissions to perform.
  foreach ($operations as $key => $value) {
    if ($value['add_permission'] != NULL && !user_access($value['add_permission'])) {
      unset($operations[$key]);
    }
  }

  // Make select list into operation => label.
  array_walk($operations, function (&$value) {
    $value = $value['bulk_operation_label'];
  });

  // Add delete operation if user has permission.
  if (user_access('delete includes')) {
    $operations = $operations + array('delete' => 'Delete Include Codes');
  }

  // Only add operations fieldset if user has access to perform an operation.
  if (!empty($operations)) {
    // Add container for operations functionality.
    $form['operations'] = array(
      '#type' => 'fieldset',
      '#title' => 'Operations',
    );

    $form['operations']['select'] = array(
      '#type' => 'select',
      '#options' => $operations,
      '#default_value' => current($operations),
    );

    // Add submit button for operations.
    $form['operations']['submit'] = array(
      '#type' => 'submit',
      '#value' => t('Submit'),
    );
  }

  return $form;
}

/**
 * Callback to generate table of embeds.
 *
 * @param array $form
 *   Form that contains defaults for embed overview page.
 * @param array $form_state
 *   Form state that will contain any embeds if they exist.
 *
 * @return array
 *   Fully built table of embeds for overview page.
 */
function cu_js_includes_includes_table($form, $form_state) {

  $rows = array();
  foreach ($form_state['cu_js_includes'] as $result) {
    $edit_link = l(t('Edit'), 'admin/content/js-includes/' . $result->type . '/' . $result->id . '/edit');
    $path_link = $result->path === 'N/A' ? 'N/A' : l(drupal_get_path_alias($result->path), $result->path);

    $author = user_load_by_name($result->author);
    $author_link = isset($author->name) ? "<a title=\"{$author->name}\" href=\"/users/{$author->name}\">{$author->name}</a>" : "N/A";

    $rows[] = array(
      'id' => $result->id,
      'name' => $result->name,
      'type' => $result->type,
      'author' => $author_link,
      'renderer' => $result->renderer,
      'updated' => format_date($result->updated, 'short'),
      'edit' => $edit_link,
    );
  }

  $form['table'] = array(
    '#type' => 'tableselect',
    '#header' => $form_state['table_headers'],
    '#options' => $rows,
    '#suffix' => empty($rows) ? 'No includes codes have been created.' : '',
    '#weight' => 10,
  );

  $form['pager'] = array(
    '#theme' => 'pager',
    '#weight' => 11,
  );

  return $form;
}

/**
 * Form submission for Embed Code overview form.
 *
 * @param array $form
 *   Form passed into submit function.
 * @param array $form_state
 *   State of form passed in with search and bulk operations.
 *
 * @return mixed
 *   Returns form state for confirmation, returned search results, or NULL for errors.
 */
function cu_js_includes_overview_form_submit(&$form, &$form_state) {
  // Declare default variables. Probably a better way to do this.
  $name = !empty($form_state['values']['name']) ? $form_state['values']['name'] : NULL;
  $renderer = !empty($form_state['values']['renderer']) ? $form_state['values']['renderer'] : NULL;
  $type = !empty($form_state['values']['type']) ? $form_state['values']['type'] : NULL;
  $author = !empty($form_state['values']['author']) ? $form_state['values']['author'] : NULL;

  // If input for search, then pass to search function.
  if ($form_state['values']['op'] === 'Search') {

    $options = array(
      'name' => $name,
      'renderer' => $renderer,
      'type' => $type,
      'author' => $author,
    );

    // Betting on !empty() working for NULL values in array.
    if (!empty($options)) {
      return cu_js_includes_form_search($form_state, $options);
    }
    else {
      drupal_set_message('No search terms entered.', 'error');
      return '';
    }
  }

  // Make sure to make the user confirm they want to proceed with bulk operation.
  if (!isset($form_state['storage']['confirm'])) {
    // @todo Don't put in whole form_state array since it adds recursively.
    $form_state['storage']['form_state'] = $form_state;
    $form_state['storage']['form'] = $form;
    // This will cause the form to be rebuilt returning to the confirm part of the form.
    $form_state['storage']['confirm'] = TRUE;
    $form_state['rebuild'] = TRUE;
    return $form_state;
  }

  // If no embed temlates are present, no need to try and perform any operation.
  if (!isset($form_state['cu_js_includes'])) {
    drupal_set_message('No include templates selected to perform operation on.', 'error');
    return NULL;
  }

  // Perform bulk operation on entities stored in $form_state from confirmation function.
  $operation = $form_state['values']['op'];

  // Check for delete operation first.
  // Didn't want to put this in hook_cu_js_includes_status() since it isn't a status.
  // @todo Refactor this if another operation doesn't fit into the add/edit screen.
  if (lcfirst($operation) == 'delete') {
    // Check for permission.
    if (!user_access('delete includes')) {
      drupal_set_message('You do not have sufficient permissions to delete these includes.', 'error');
      return NULL;
    }

    foreach ($form_state['cu_js_includes'] as $pixel) {
      // Call submission callback in case embeds need to do something for deletion.
      if ($submission_callback = cu_js_includes_get_submission_callback($pixel->type)) {
        call_user_func($submission_callback, $pixel, 'delete');
      }
      entity_delete('cu_js_includes', $pixel->id);
    }
    return NULL;
  }

  // Get statuses to check for operations.
  $operations = cu_js_includes_get_operations();

  // If operation exists act on it.
  foreach ($operations as $key => $value) {
    if ($value['confirmation_label'] == $operation) {
      // Check for permission.
      if (!user_access($value['add_permission'])) {
        return NULL;
      }

      // Switch operation machine name for label.
      $operation = $key;

      // Pass in each embed to submission/callback functions.
      foreach ($form_state['cu_js_includes'] as $include) {
        // Call submission callback in case embeds need to do something before operation.
        if ($submission_callback = cu_js_includes_get_submission_callback($include->type)) {
          call_user_func($submission_callback, $include, $operation);
        }

        // Operation callback invocation has been moved to cu_js_includes_entity_presave().
        entity_save('cu_js_includes', $include);
      }
      return NULL;
    }
  }

  // Otherwise, set an error message.
  drupal_set_message('Error performing bulk operation. ' . $operation . ' operation not found.', 'error');
  watchdog('cu_js_includes', 'Error performing bulk operation. @op operation not found.', array('@op' => $operation));
  return NULL;
}

/**
 * Callback for searching for embeds from overview page.
 *
 * @param array $form_state
 *   Form state to store search results in.
 * @param array $options
 *   Options containing search terms.
 *
 * @return array
 *   The form state whether any results were found.
 */
function cu_js_includes_form_search(&$form_state, $options = array()) {

  // Setup initial query.
  $query = db_select('cu_js_includes', 'tp')
    ->fields('tp');

  // Need to combine name and path search into one.
  if ($options['name'] != NULL) {
    $or = db_or();
    $or->condition('tp.name', '%' . db_like($options['name']) . '%', 'LIKE');
  }

  if ($options['author'] != NULL) {
    $or = db_or();
    $or->condition('tp.author', '%' . db_like($options['author']) . '%', 'LIKE');
  }

  // Search by path.
  if ($options['path'] != NULL && $options['path'] != FALSE) {
    // Always add search for path in cu_js_includes table. Unthemed Pages will
    // never have an entry in the alias table.
    if (!isset($or)) {
      $or = db_or();
    }
    $or->condition('tp.path', '%' . db_like($options['path']) . '%', 'LIKE');

    // Finding system paths is a little more difficult.
    // May need to add conditions for other alias tables.
    $path_results = db_select('url_alias', 'al')
      ->fields('al', array('source'))
      ->condition('al.alias', '%' . db_like($options['path']) . '%', 'LIKE')
      ->execute()
      ->fetchCol();

    if (!empty($path_results)) {
      // If no name is passed in, we have to create the $or object.
      foreach ($path_results as $system_path) {
        $or->condition('tp.path', '%' . db_like($system_path) . '%', 'LIKE');
      }
    }
  }

  // Add search by renderer.
  if ($options['renderer'] != NULL && $options['renderer'] != 'any') {
    $query->condition('tp.renderer', $options['renderer'], '=');
  }

  // Add search by type.
  if ($options['type'] != NULL && $options['type'] != 'any') {
    $query->condition('tp.type', $options['type'], '=');
  }

  // Only add conditions if the $or object is set.
  if (isset($or)) {
    $query->condition($or);
  }
  $results = $query->execute()->fetchAllAssoc('id');

  // Load embeds to send back to form.
  if ($results) {
    $cu_js_includes = entity_load('cu_js_includes', array_keys($results));
    $form_state['storage']['search_includes'] = $cu_js_includes;
  }
  else {
    // Set message if there are no results.
    $form_state['storage']['search_includes'] = cu_js_includes_get_includes();
    drupal_set_message(t('No results matched your search. All includes are shown.'), 'error');
  }

  $form_state['storage']['search_name'] = $options['name'];
  $form_state['storage']['search_renderer'] = $options['renderer'];
  $form_state['storage']['search_type'] = $options['type'];
  $form_state['rebuild'] = TRUE;
  return $form_state;
}