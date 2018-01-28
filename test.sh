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

echo -n "- ls test with malloc :\n"
LD_PRELOAD="./libmy_malloc.so" ls