# Simple Makefile

CC = gcc
CFLAGS = -Wall -g
TARGET = program

#debug with debug info
ex_1: ex_1.c
	$(CC) -o ex_1 ex_1.c -ggdb

#debug without debug info
# ex_1_no_debug.c: ex_1.c
# 	$(CC) -o ex_1 ex_1.c
clean:
	rm -f ex_1
