#!/usr/bin/env bash

# Disable XDebug to speed up test runs.
phpenv config-rm xdebug.ini

# Add database and settings.php file.
mysql -e 'create database drupal;'
cp $ROOT_DIR/drupal/profiles/express/tests/travis-ci/settings.travis.php $ROOT_DIR/drupal/sites/default/settings.php

# Disable sendmail from https://www.drupal.org/project/phpconfig/issues/1826652.
echo sendmail_path=`which true` >> ~/.phpenv/versions/$(phpenv version-name)/etc/php.ini

# Add PHP config that somewhat matches current prod.
phpenv config-add $ROOT_DIR/drupal/profiles/express/tests/travis-ci/config/express-php.ini
earlyexit

# Change InnoDB settings that speed things up.
# https://www.percona.com/blog/2015/02/24/mysqls-innodb_file_per_table-slowing/.
mysql -e "SET @@global.innodb_file_per_table=0;"

# https://dba.stackexchange.com/questions/12611/is-it-safe-to-use-innodb-flush-log-at-trx-commit-2.
mysql -e "SET @@global.innodb_flush_log_at_trx_commit=2;"
earlyexit

# Echo out some system info.
php -i | grep memory
cat /proc/meminfo

# 
cd ${ROOT_DIR}/drupal/profiles/express

# Install site like normal.
echo Installing Express...
$HOME/.composer/vendor/bin/drush si express --db-url=mysql://root:@127.0.0.1/drupal --account-name=admin --account-pass=admin --site-mail=admin@example.com --site-name="Express" --yes
earlyexit

# Export db so it can be imported after every suite run.
# Test runs that fill up the db with nodes can impact other tests.
echo Exporting database...
$HOME/.composer/vendor/bin/drush sql-dump --result-file=$HOME/cache/express.sql

# Check and see if testing core module is enabled.
$HOME/.composer/vendor/bin/drush pm-info travis_hosting
$HOME/.composer/vendor/bin/drush pm-info ng_hosting
$HOME/.composer/vendor/bin/drush pm-info cu_core
$HOME/.composer/vendor/bin/drush pm-info cu_ldap
$HOME/.composer/vendor/bin/drush pm-info cu_local_users
$HOME/.composer/vendor/bin/drush pm-list

exit 0
