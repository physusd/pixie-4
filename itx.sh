#!/bin/sh
if [ $# -ne 1 ]; then
  echo Usage:
  echo $ ./itx.sh input.itx
  exit
fi
i=$1 # input file name
o=${1%.*}.root # output file name
echo converting $i to $o ...
dos2unix -c mac $i # replace  with \r
root -b -q -l itx.C\(\"$i\",\"$o\"\)
echo done!
