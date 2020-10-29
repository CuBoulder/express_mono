#!/usr/bin/env bash

echo "checking path before installation of drush"
echo $PATH

# Install latest Drush 8.
composer global require "drush/drush:8.*"
export PATH="$HOME/.config/composer/vendor/bin:$PATH"
export PATH="$HOME/.config/composer/vendor/drush/drush:$PATH"

echo "checking path after installation of drush"
echo $PATH

echo check drush status
$HOME/.config/composer/vendor/bin/drush status

cd $HOME/.config/composor/vendor/
ls -la 

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

exit 0
