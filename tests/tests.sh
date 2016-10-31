#!/bin/sh
red=$'\e[31m'
green=$'\e[32m'
white=$'\e[39m'

mkdir output
for i in tests/input/* ; do 
  echo "crating $i.ppm file"
  tmp=$i
  out=$(cut -d '/' -f 3 <<< "$tmp")
  echo "$out"
  ./rt "$i" "output/$out.ppm"
done
