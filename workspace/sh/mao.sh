#!/bin/sh

rm -f fred
if test -f fred ; then
    :
else
    echo file fred did not exist
fi

exit 0
