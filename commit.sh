#!/usr/bin/env bash


git add $1
git status
git commit -m "$2"
git push