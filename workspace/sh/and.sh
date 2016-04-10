#!/bin/sh

touch file_one
rm -f file_two

if test -f file_one && echo "hello" && test -f file_two && echo " there"
then
    echo "in if"
else
    echo "in else"
fi

exit 0
