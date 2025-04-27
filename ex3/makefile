# Makefile

CC = gcc
CFLAGS = -Wall -fPIC
LDFLAGS = -shared
LIBNAME = libmandelbrot.so
APPNAME = mandelbrot_app

all: $(LIBNAME) $(APPNAME)

$(LIBNAME): mandelbrot.o
	$(CC) $(LDFLAGS) -o $(LIBNAME) mandelbrot.o

mandelbrot.o: mandelbrot.c mandelbrot.h
	$(CC) $(CFLAGS) -c mandelbrot.c -o mandelbrot.o

$(APPNAME): main.c mandelbrot.h
	$(CC) main.c -L. -lmandelbrot -lm -o $(APPNAME)

clean:
	rm -f *.o *.so $(APPNAME)
.PHONY: all clean