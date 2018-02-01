#!/bin/sh
##
## EPITECH PROJECT, 2017
## malloc
## File description:
## malloc
##

if [ ! -e "libmy_malloc.so" ]; then
	make -s
fi

echo "-- TESTS --\n"
echo "- ls :\n"
LD_PRELOAD="./libmy_malloc.so" ls --color=auto
LD_PRELOAD="./libmy_malloc.so" valgrind  ./42sh
# echo "- ls -Rla:\n"
# LD_PRELOAD="./libmy_malloc.so" ls -Rla /


# gcc -I ./include/ -Wall -Wextra -fPIC main.c
