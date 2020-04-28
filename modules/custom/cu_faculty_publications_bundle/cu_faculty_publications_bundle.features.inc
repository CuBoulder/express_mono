<?php

/**
 * @file
 * cu_faculty_publications.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function cu_faculty_publications_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "bean_admin_ui" && $api == "bean") {
    return array("version" => "5");
  }
}
