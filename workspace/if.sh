#!/bin/sh

echo -n "Is it morning? Please answer yes or no "
read timeofday

if test "$timeofday" = "yes"
then
    echo -n "Good morning"

elif test "$timeofday" = "no"
then
    echo  -n"Good afternoon"
else
    echo -n "Sorry, "$timeofday" not recognised. Enter yes or no" 
fi

exit 0
