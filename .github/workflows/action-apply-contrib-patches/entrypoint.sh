#!/bin/bash

if [ $(git diff -r --quiet dev_alans..  modules/contrib) ]
then
    echo "No patches need to be applied."
else
    echo "Applying patches..."
    git apply patches/bean-integration-2127731-10.patch
fi