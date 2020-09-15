#!/bin/bash

while true
do
  if [ -e file.lock ]
  then
    sleep 2
  else
    ln file file.lock
    n=$(tail -n 1 file)
    ((n++))
    echo $n >> file
    rm file.lock
    break
  fi
done
