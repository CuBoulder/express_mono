#!/bin/bash

git config --global user.email "osr_web_deploy@colorado.edu"
git config --global user.name "osrwebdeploy"

echo "ACTIVE GIT BRANCH"
branch=`git branch`
echo $branch

git diff -r --quiet dev_alans.. -- modules/contrib || git apply patches/*

if git add .
then
    echo "Nothing needs to be done."
else
    git add .
    git commit -m "applying patches"
    git push origin $branch

    echo "Patches applied. Hopefully, it looks good!"
fi

echo "See ya!"
