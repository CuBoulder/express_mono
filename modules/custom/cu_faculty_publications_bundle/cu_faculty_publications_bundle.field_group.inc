<?php

/**
 * @file
 * cu_faculty_publications_bundle.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function cu_faculty_publications_bundle_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_faculty_pub_manual_data|bean|faculty_publications|form';
  $field_group->group_name = 'group_faculty_pub_manual_data';
  $field_group->entity_type = 'bean';
  $field_group->bundle = 'faculty_publications';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Filter Manually',
    'weight' => '6',
    'children' => array(
      0 => 'field_faculty_pub_department',
      1 => 'field_faculty_publication_email',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-faculty-pub-manual-data field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_faculty_pub_manual_data|bean|faculty_publications|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_faculty_pub_person_data|bean|faculty_publications|form';
  $field_group->group_name = 'group_faculty_pub_person_data';
  $field_group->entity_type = 'bean';
  $field_group->bundle = 'faculty_publications';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Filter with Person Data',
    'weight' => '7',
    'children' => array(
      0 => 'field_faculty_publication_name',
      1 => 'field_people_list_person_type',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-faculty-pub-person-data field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_faculty_pub_person_data|bean|faculty_publications|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Filter Manually');
  t('Filter with Person Data');

  return $field_groups;
}
