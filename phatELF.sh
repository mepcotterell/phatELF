#!/bin/bash

# phatELF.sh
# @author Michael Cotterell <mepcotterell@gmail.com>
# @see LICENSE

if [ $# -ne 2 ]
then
  echo "Usage: `basename $0` {infile} {outfile}"
  exit 65
fi

echo "phatELF" 
echo " - Compiling target outfile..."
g++ phatELF.cpp -o $2
echo " - Performing inception..."
objcopy --add-section .phat=$1 $2
echo " - Cleaning up..."
# anything?
echo "Done."

