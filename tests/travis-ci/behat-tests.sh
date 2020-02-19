#!/usr/bin/env bash

# Start server.
cd ${ROOT_DIR}/drupal
$HOME/.composer/vendor/bin/drush runserver 127.0.0.1:8031 > /dev/null 2>&1 &
nc -zvv 127.0.0.1 8031; out=$?; while [[ $out -ne 0 ]]; do echo "Retry hit port 8031..."; nc -zvv localhost 8031; out=$?; sleep 5; done
earlyexit

cd ${ROOT_DIR}/drupal/profiles/express

# Setting Behat environment variables is now done in behat.travis.yml for simplicity.

echo "Running Express headless tests..."
${ROOT_DIR}/drupal/profiles/express/tests/behat/bin/behat --stop-on-failure --strict --config ${ROOT_DIR}/drupal/profiles/express/tests/behat/behat.travis.yml --verbose --tags ${EXPRESS_HEADLESS_BEHAT_TAGS}
earlyexit

# Run JS Behat tests
echo "Running Express JS tests..."
${ROOT_DIR}/drupal/profiles/express/tests/behat/bin/behat --stop-on-failure --strict --config ${ROOT_DIR}/drupal/profiles/express/tests/behat/behat.travis.yml --verbose --tags ${EXPRESS_JS_BEHAT_TAGS}
earlyexit

# Run Digital Campaign Tests
# We run these seperately b/c the changes they make cause other tests to fail if they are run afterwards.
echo "Running Express Digital Campaign tests..."
# Enable test content, user, and role.
$HOME/.composer/vendor/bin/drush en cu_dc_tests -y
${ROOT_DIR}/drupal/profiles/express/tests/behat/bin/behat --stop-on-failure --strict --config ${ROOT_DIR}/drupal/profiles/express/tests/behat/behat.travis.yml --verbose --tags ${EXPRESS_DC_BEHAT_TAGS}
earlyexit

echo "Running Express Digital Campaign JS tests..."
${ROOT_DIR}/drupal/profiles/express/tests/behat/bin/behat --stop-on-failure --strict --config ${ROOT_DIR}/drupal/profiles/express/tests/behat/behat.travis.yml --verbose --tags ${EXPRESS_DC_JS_BEHAT_TAGS}
earlyexit

# Output performance logging data.
$HOME/.composer/vendor/bin/drush scr ${ROOT_DIR}/drupal/profiles/express/tests/travis-ci/log-express-performance.php

exit 0
