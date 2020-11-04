#!/bin/bash

git config --global user.email "osr_web_deploy@colorado.edu"
git config --global user.name "osrwebdeploy"

echo "ACTIVE GIT BRANCH"
git branch
echo "\n\n"

if  "git diff -r --quiet dev_alans..$GITHUB_REF  modules/contrib"
then
    echo "No patches need to be applied."
else
    echo "Applying patches..."
    git apply patches/*
    git add .
    git commit -m "applying patches"
    git push origin $GITHUB_REF

    echo "Hopefully, it looks good!"
fi

echo "See ya!"
