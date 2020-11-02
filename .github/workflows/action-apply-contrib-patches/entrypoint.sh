#!/bin/bash

if [ "git diff -r --quiet dev_alans..$GITHUB_REF  modules/contrib" ]
then
    echo "No patches need to be applied."
else
    echo "Applying patches..."
    git apply patches/*
fi

git add .
git commit -m "applying patches"
git push $GITHUB_REF