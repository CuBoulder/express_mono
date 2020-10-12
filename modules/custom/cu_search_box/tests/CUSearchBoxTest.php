<?php

use PHPUnit\Framework\TestCase;

$blockInfo = [
  'cu_search_box_lg' => [
      'info' => 'Small CU Search Box'
  ],
  'cu_search_box_sm' => [
      'info' => 'Small CU Search Box'
  ]
];

class CUSearchBoxTest extends TestCase {

  protected $SearchBox;
  
  public function testInfoReturnsTwoBlocks() {
    $this->SearchBox = new CUSearchBox();
    $this->assertSame($this->SearchBox->info('print_r', true), $blockInfo);
  }
}
