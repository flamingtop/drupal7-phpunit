<?php

// most of the code was duplicated from scripts/run-tests.sh in your drupal installation


// Tells drupal to load the right settings.php 
// based on corresponding domain
// if you're not working with a multi-domain installation, simply hard code here
define('TEST_DOMAIN', get_test_domain());


// Mock env variables
// @see scripts/run-tests.sh
$_SERVER['HTTP_HOST'] = TEST_DOMAIN;
$_SERVER['REMOTE_ADDR'] = '127.0.0.1';
$_SERVER['SERVER_ADDR'] = '127.0.0.1';
$_SERVER['SERVER_SOFTWARE'] = 'Apache';
$_SERVER['SERVER_NAME'] = TEST_DOMAIN;
$_SERVER['REQUEST_URI'] = '/';
$_SERVER['REQUEST_METHOD'] = 'GET';
$_SERVER['SCRIPT_NAME'] = '/index.php';
$_SERVER['PHP_SELF'] = '/index.php';
$_SERVER['HTTP_USER_AGENT'] = 'PHPUnit Command Line';


chdir(realpath(dirname(__FILE__) . '/../../..'));
define('DRUPAL_ROOT', getcwd());
require_once DRUPAL_ROOT . '/includes/bootstrap.inc';
drupal_bootstrap(DRUPAL_BOOTSTRAP_FULL);

chdir(realpath(dirname(__FILE__)));




function get_test_domain() {
  $test_domain_file = dirname(__FILE__).'/TEST_DOMAIN';
  if(!file_exists($test_domain_file))
    die('Please put a TEST_DOMAIN file under all/tests/');
  $test_domain = trim(file_get_contents($test_domain_file));
  if(empty($test_domain))
    die('Please specify a proper doamin in your TEST_DOMAIN file');
  return $test_domain;
}
