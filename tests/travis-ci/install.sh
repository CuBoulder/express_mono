#!/usr/bin/env bash

echo hello from inside the install script

# Install latest Drush 8."
#composer global require "drush/drush:8.*"
#export PATH="$HOME/.composer/vendor/bin:$PATH"


# Install latest Drush
export PATH="$HOME/.composer/vendor/bin:$PATH"
composer global require consolidation/cgr
cgr drush/drush
drush status


# Build Behat dependencies.
cd $ROOT_DIR/express_mono/tests/behat
composer install --prefer-dist --no-interaction
earlyexit

# Build Codebase.
cd $ROOT_DIR
git clone --depth 1 https://github.com/CuBoulder/d7core.git drupal
mkdir profiles && mv express_mono drupal/profiles/express

# Harden Core.
cd $ROOT_DIR/drupal/modules
rm -rf php aggregator blog book color contact translation dashboard forum locale openid overlay poll rdf search statistics toolbar tracker trigger
earlyexit

# Apply Patches.

# Setup files.
mkdir -p $ROOT_DIR/drupal/sites/default/files/styles/preview/public/gallery/ && chmod -R 777 $ROOT_DIR/drupal/sites
mkdir $ROOT_DIR/tmp && chmod -R 777 $ROOT_DIR/tmp

echo now exiting the install script

exit 0
