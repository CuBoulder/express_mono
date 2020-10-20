<?php

/**
 * Implements hook_embed_templates_types().
 *
 * @return array
 *   List of custom embed types.
 */
function cu_js_includes_get_include_types() {
  // Create a few initial embed types.
  $custom_types = array();
  $module_path = drupal_get_path('module', 'cu_js_includes');

  $custom_types['admithub'] = array(
    'label' => 'AdmitHub',
    'form_callback' => 'cu_js_includes_admithub_form',
    'renderer' => 'page_top_bottom',
    'path' => $module_path,
    'template' => 'templates/admithub',
  );

  $custom_types['livechat'] = array(
    'label' => 'LiveChat',
    'form_callback' => 'cu_js_includes_livechat_form',
    'renderer' => 'page_top_bottom',
    'path' => $module_path,
    'template' => 'templates/livechat',
  );

  $custom_types['statuspage'] = array(
    'label' => 'StatusPage',
    'form_callback' => 'cu_js_includes_statuspage_form',
    'renderer' => 'block',
    'path' => $module_path,
    'template' => 'templates/statuspage',
  );

  $custom_types['slateform'] = array(
    'label' => 'Slate Form',
    'form_callback' => 'cu_js_includes_slateform_form',
    'renderer' => 'block',
    'path' => $module_path,
    'template' => 'templates/slateform',
  );

  return $custom_types;
}

/**
 * Implements hook_node_list_groups().
 *
 * Adds grouping/labels for includes since they use the node list function.
 */
function cu_js_includes_express_node_list_groups($bundles) {
  $bundles['inlcudes']['title'] = 'Include Types';
  $bundles['inlcudes']['types'][] = 'Add AdmitHub Include';
  $bundles['inlcudes']['types'][] = 'Add LiveChat Include';
  $bundles['inlcudes']['types'][] = 'Add Slate Form Include';
  $bundles['inlcudes']['types'][] = 'Add StatusPage Include';
  return $bundles;
}