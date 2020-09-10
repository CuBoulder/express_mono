<?php

/**
 * @file
 * web_component_taxonomy_terms.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function web_component_taxonomy_terms_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
