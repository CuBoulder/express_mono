<?php


$files = array_merge(glob('../src/*.php'), glob('./data/*.php'));

foreach ($files as $file) {
    include $file;
}