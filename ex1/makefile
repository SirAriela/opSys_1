# Simple Makefile

CC = gcc
CFLAGS = -Wall -g
TARGET = program

#debug with debug info
ex_1: ex1.c
	$(CC) -o ex_1 ex1.c -ggdb

#debug without debug info
ex_1_no_debug: ex1.c
	$(CC) -o ex_1 ex1.c

#makes the core file if the executable crashes
core:
	sudo sysctl -w kernel.core_pattern=core && \
	sudo sysctl -w fs.suid_dumpable=1 && \
	bash -c 'ulimit -c unlimited && ./ex_1'
re:
	
clean:
	rm -f ex_1 core
