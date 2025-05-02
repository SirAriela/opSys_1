# Makefile for signal communication programs

# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -Wno-unused-parameter

# Targets
all: sender receiver

sender: sender.c
	$(CC) $(CFLAGS) -o sender sender.c

receiver: receiver.c
	$(CC) $(CFLAGS) -o receiver receiver.c

clean:
	rm -f sender receiver *.o

.PHONY: all clean