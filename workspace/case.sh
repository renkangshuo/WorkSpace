#!/bin/sh

echo "Is it morning? Please answer yes or no"
read timeofday

case "$timeofday" in
    yes)    echo "Good morning";;
    no)     echo "Good afternoon";;
y)      echo "Good morning";;
n )     echo "good afternoon";;
*)      echo "Sorry, answer not recognised";;
esac
exit 0
