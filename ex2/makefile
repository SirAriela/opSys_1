# Makefile for Mandelbrot set checker program

# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra

# Targets
all: mandelbrot

mandelbrot: mandelbrot.c
	$(CC) $(CFLAGS) -o mandelbrot mandelbrot.c -lm

clean:
	rm -f mandelbrot *.o

.PHONY: all clean