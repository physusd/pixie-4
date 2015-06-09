#!/bin/sh
i=$1
o=${1%.*}.root
echo converting $i to $o ...
dos2unix -c mac $i
root -b -q -l mca2root.C\(\"$i\",\"$o\"\)
echo done!
