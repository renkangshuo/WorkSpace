#!/bin/sh

rm -f fred*
echo > fred1
echo > fred2
mkdir fred3
echo > fred4

for file in fred*
do
    if test -d "$file" ; then
        break;
    fi
done


echo first directory starting fred was $file
rm -rf fred*
exit 0
