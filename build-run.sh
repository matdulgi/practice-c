#!/bin/bash

if [ ! -f $1 ]; then
  echo no input source
fi

if [ -z $2]; then
  gcc $1 -o out/a.out; out/a.out
else 
  if [ ! -d $2]; then
    echo invalid path
  else 
    gcc $1 -o $2; $2
  fi
fi
