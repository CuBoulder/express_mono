<?php
/**
 * @file
 * cu_saml2.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function cu_saml_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'r4032login_access_denied_message';
  $strongarm->value = 'Access denied. You must log in to view this page.';
  $export['r4032login_access_denied_message'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'r4032login_access_denied_message_type';
  $strongarm->value = 'error';
  $export['r4032login_access_denied_message_type'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'r4032login_default_redirect_code';
  $strongarm->value = '302';
  $export['r4032login_default_redirect_code'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'r4032login_display_denied_message';
  $strongarm->value = 0;
  $export['r4032login_display_denied_message'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'r4032login_match_noredirect_pages';
  $strongarm->value = '';
  $export['r4032login_match_noredirect_pages'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'r4032login_redirect_authenticated_users_to';
  $strongarm->value = '';
  $export['r4032login_redirect_authenticated_users_to'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'r4032login_user_login_path';
  $strongarm->value = 'saml_login';
  $export['r4032login_user_login_path'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'site_403';
  $strongarm->value = 'r4032login';
  $export['site_403'] = $strongarm;

  return $export;
}
