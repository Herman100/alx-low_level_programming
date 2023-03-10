#!/bin/bash

C_FILES=$(find . -maxdepth 1 -type f -name '*.c')

for FILE in $C_FILES; do
  gcc -c "$FILE"
done

ar rcs liball.a *.o

rm -f *.o
