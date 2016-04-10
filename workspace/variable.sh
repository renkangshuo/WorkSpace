#!/bin/sh

myvar="Hi there"

echo $myvar
echo " $myvar "
echo '$myvar'
echo \$myvar

echo Enter some text
read myvar

echo '$myvar' now equals $myvar

echo $$
exit 0
