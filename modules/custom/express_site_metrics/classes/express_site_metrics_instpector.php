<?php

/**
 * Class for gathering site metrics.
 */
class SiteMetricsInspector {

  /**
   * Build the class.
   */
  private function __construct() {

  }

  /**
   * Authenticate the request.
   *
   * @return bool
   *   Returns true if allowed, false if not.
   */
  private function isAllowedIn($token) {
    return TRUE;
  }

  /**
   * Calls all implemented hook_express_site_metrics() functions.
   *
   * @return array
   *   Metrics data in an associative array.
   */
  public static function gatherData() {
    return [];
  }

}
