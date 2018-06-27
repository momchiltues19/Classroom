#!/bin/bash

# $1 - commit

res="`git status | grep "up to date" `"

if [ -z "$res" ]; then
  git pull
fi

git add . # A_19_Momchil_Todorov

git commit -m $1

res="`git status | grep "up to date" `"

if [ -z "$res" ]; then
  git pull
fi

git push