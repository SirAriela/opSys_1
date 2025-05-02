CC=gcc
CFLAGS=-Wall -fprofile-arcs -ftest-coverage
LDFLAGS=-lgcov
OBJS=main.o dijkstra.o

all: dijkstra

dijkstra: $(OBJS)
	$(CC) $(CFLAGS) -o dijkstra $(OBJS) $(LDFLAGS)

main.o: main.c dijkstra.h
	$(CC) $(CFLAGS) -c main.c

dijkstra.o: dijkstra.c dijkstra.h
	$(CC) $(CFLAGS) -c dijkstra.c

clean:
	rm -f *.o dijkstra *.gcno *.gcda *.gcov

coverage: dijkstra
	./dijkstra < test_input.txt
	gcov main.c
	gcov dijkstra.c
