<?php

/**
 * @file
 * web_component_taxonomy_terms.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function web_component_taxonomy_terms_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance:
  // 'taxonomy_term-web_component_data_options-field_web_component'.
  $field_instances['taxonomy_term-web_component_data_options-field_web_component'] = array(
    'bundle' => 'web_component_data_options',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'The Web Component that this data option belongs to',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'fences_wrapper' => 'div_div_div',
    'field_name' => 'field_web_component',
    'label' => 'Web Component',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'taxonomy',
      'settings' => array(
        'autocomplete_path' => 'taxonomy/autocomplete',
        'size' => 60,
      ),
      'type' => 'taxonomy_autocomplete',
      'weight' => 31,
    ),
  );

  // Exported field_instance: 'taxonomy_term-web_components-field_api_endpoint'.
  $field_instances['taxonomy_term-web_components-field_api_endpoint'] = array(
    'bundle' => 'web_components',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'The endpoint to fetch data into the Vue app',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'fences_wrapper' => 'no_wrapper',
    'field_name' => 'field_api_endpoint',
    'label' => 'API Endpoint',
    'required' => 0,
    'settings' => array(
      'linkit' => array(
        'button_text' => 'Search',
        'enable' => 0,
        'profile' => '',
      ),
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 32,
    ),
  );

  // Exported field_instance: 'taxonomy_term-web_components-field_wc_name'.
  $field_instances['taxonomy_term-web_components-field_wc_name'] = array(
    'bundle' => 'web_components',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'This is the name of the Web component as defined in Vue',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'fences_wrapper' => 'no_wrapper',
    'field_name' => 'field_wc_name',
    'label' => 'WC Name',
    'required' => 1,
    'settings' => array(
      'linkit' => array(
        'button_text' => 'Search',
        'enable' => 0,
        'profile' => '',
      ),
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 31,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('API Endpoint');
  t('The Web Component that this data option belongs to');
  t('The endpoint to fetch data into the Vue app');
  t('This is the name of the Web component as defined in Vue');
  t('WC Name');
  t('Web Component');

  return $field_instances;
}
