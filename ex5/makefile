APPNAME = ex5
CXX = clang++
CXXFLAGS = -Wall -pg -O0

all: $(APPNAME)

$(APPNAME): ex5.o algorithm.o
	$(CXX) $(CXXFLAGS) -o $(APPNAME) ex5.o algorithm.o

ex5.o: ex5.cpp algorithm.h
	$(CXX) $(CXXFLAGS) -c ex5.cpp -o ex5.o

algorithm.o: algorithm.cpp algorithm.h
	$(CXX) $(CXXFLAGS) -c algorithm.cpp -o algorithm.o

clean:
	rm -f *.o $(APPNAME) gmon.out analysis.txt

.PHONY: all clean
