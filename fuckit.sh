#!/bin/bash
yacc -d my.y
flex my.l
gcc lex.yy.c y.tab.c -o my	-w
./my < input.c