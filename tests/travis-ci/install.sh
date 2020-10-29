#!/usr/bin/env bash

cd /
echo "slash /"
ls -la
cd $HOME
echo "HOME"
echo $HOME
ls -la
cd $ROOT_DIR
echo "ROOT_DIR"
echo $ROOT_DIR
ls -la
cd $TRAVIS_BUILD_DIR
echo "TRAVIS_BUILD_DIR"
echo $TRAVIS_BUILD_DIR
ls -la

chmod -R 777 /user/bin/local

# Install latest Drush 8.
COMPOSER_HOME=/opt/drush COMPOSER_BIN_DIR=/usr/local/bin COMPOSER_VENDOR_DIR=/opt/drush/8 composer require drush/drush:^8
export PATH="$HOME/.config/composer/vendor/bin:$PATH"
export PATH="$HOME/.config/composer/vendor/drush/drush:$PATH"

echo check drush status using entire old path
$HOME/.config/composer/vendor/bin/drush status

echo check drush status using word drush
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

exit 0
