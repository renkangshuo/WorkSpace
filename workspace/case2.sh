#!/bin/sh

echo "Is it morning ? Please answer yes or no "
read timeofday

case "$timeofday" in
    yes | y | Yes | YES )
        echo "Good morning"
        echo "Up bright and early this morning"
        ;;
    [nN]*)
        echo "Good afternoon"
        ;;
    *)
        echo "sorry, asnwer not recognised"
        echo "Please answer yes or no"
        exit 1
        ;;
esac
