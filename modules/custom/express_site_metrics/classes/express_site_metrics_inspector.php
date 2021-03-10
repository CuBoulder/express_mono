<?php

/**
 * Class for gathering site metrics.
 */
class SiteMetricsInspector {

  /**
   * Build the class.
   */
  public function __construct() {

  }

  /**
   * Calls all implemented hook_express_site_metrics() functions.
   *
   * @return array
   *   Metrics data in an associative array.
   */
  public static function gatherData($pretty = FALSE) {
    $metrics = 'Site metrics will be here.';
    return $pretty ? json_encode(['metrics' => $metrics], JSON_PRETTY_PRINT) : json_encode(['metrics' => $metrics]);
  }

}
