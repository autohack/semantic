#!/bin/bash
yacc -d my.y
flex my.l
gcc lex.yy.c y.tab.c -o my
./my < input.c