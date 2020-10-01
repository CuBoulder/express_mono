<?php

/**
 * Define site permissions in code.
 *
 * Create a secure_permissions_data module directory and place this function
 * in secure_permissions_data.module.
 *
 * @param string $role
 *   The role for which the permissions are being requested.
 *
 * @return array
 *   An array defining all the permissions for the site.
 */
function cu_js_includes_secure_permissions($role) {
  $permissions = array(
    'developer' => array(
      'administer js includes',
      'delete js includes',
      'edit admithub js includes',
      'view admithub js includes',
      'edit livechat js includes',
      'view livechat js includes',
      'edit statuspage js includes',
      'view statuspage js includes',
      'edit slateform js includes',
      'view slateform js includes',
    ),
  );

  if (isset($permissions[$role])) {
    return $permissions[$role];
  }
}
