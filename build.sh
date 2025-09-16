#! /bin/sh

rm -f vol; ${CC:-tcc} -lasound vol.c -o vol
