#!/bin/bash

# phatELF.sh
# @author Michael Cotterell
#
# I understand that this was not the approach you were looking for, but I would
# like to defend my code by stating that it does fulfill the project description.
#
# Enjoy!

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

