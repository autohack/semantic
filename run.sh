#!/bin/bash
yacc -d backup.y
flex my.l
g++ -std=c++11 lex.yy.c y.tab.c -o my
