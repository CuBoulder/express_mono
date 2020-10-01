<?php

/**
 * Implements hook_embed_templates_types().
 *
 * @return array
 *   List of custom embed types.
 */
function cu_js_includes_cu_js_includes_types() {
  // Create a few initial embed types.
  $custom_types = array();
  $module_path = drupal_get_path('module', 'cu_js_includes');
  $default_status = 'unpublished';

  $custom_types['admithub'] = array(
    'label' => 'AdmitHub',
    'form_callback' => 'cu_js_includes_admithub_form',
    'submission_callback' => NULL,
    'renderer' => 'page_top_bottom',
    'path' => $module_path,
    'template' => 'templates/admithub',
  );

  $custom_types['livechat'] = array(
    'label' => 'LiveChat',
    'form_callback' => 'cu_js_includes_livechat_form',
    'submission_callback' => NULL,
    'renderer' => 'page_top_bottom',
    'path' => $module_path,
    'template' => 'templates/livechat',
  );

  $custom_types['statuspage'] = array(
    'label' => 'StatusPage',
    'form_callback' => 'cu_js_includes_statuspage_form',
    'submission_callback' => NULL,
    'renderer' => 'block',
    'path' => $module_path,
    'template' => 'templates/statuspage',
  );

  $custom_types['slateform'] = array(
    'label' => 'Slate Form',
    'form_callback' => 'cu_js_includes_slateform_form',
    'submission_callback' => NULL,
    'renderer' => 'block',
    'path' => $module_path,
    'template' => 'templates/slateform',
  );

  return $custom_types;
}
