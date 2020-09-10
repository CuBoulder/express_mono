<?php

/**
 * @file
 * web_component_taxonomy_terms.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function web_component_taxonomy_terms_taxonomy_default_vocabularies() {
  return array(
    'web_component_data_options' => array(
      'name' => 'Web Component Data Options',
      'machine_name' => 'web_component_data_options',
      'description' => 'Specific data that can be shown in a web component',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'web_components' => array(
      'name' => 'Web Components',
      'machine_name' => 'web_components',
      'description' => 'A list of Available Web components',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
