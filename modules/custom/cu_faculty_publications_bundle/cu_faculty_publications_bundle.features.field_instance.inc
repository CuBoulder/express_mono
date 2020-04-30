<?php

/**
 * @file
 * cu_faculty_publications_bundle.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function cu_faculty_publications_bundle_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance:
  // 'bean-faculty_publications-field_faculty_publication_date'.
  $field_instances['bean-faculty_publications-field_faculty_publication_date'] = array(
    'bundle' => 'faculty_publications',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'bean',
    'fences_wrapper' => 'no_wrapper',
    'field_name' => 'field_faculty_publication_date',
    'label' => 'Publication Date',
    'required' => 0,
    'settings' => array(
      'default_value' => 'now',
      'default_value2' => 'same',
      'default_value_code' => '',
      'default_value_code2' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'date',
      'settings' => array(
        'increment' => 1,
        'input_format' => 'm/d/Y - H:i:s',
        'input_format_custom' => '',
        'label_position' => 'above',
        'no_fieldset' => 0,
        'text_parts' => array(),
        'year_range' => '-3:+3',
      ),
      'type' => 'date_text',
      'weight' => 31,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Publication Date');

  return $field_instances;
}
