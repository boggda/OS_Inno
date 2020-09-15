#!/bin/bash

n=$(tail -n 1 file)
((n++))
echo $n >> file
