CXX = gcc
CXXFLAGS = -Wall -Wextra -pedantic -std=c99 -Iinclude

all: test clean run

test: main.o saxml.o
	$(CXX) $(CXXFLAGS) main.o saxml.o -o test

main.o:
	$(CXX) $(CXXFLAGS) -c tests/main.c

saxml.o:
	$(CXX) $(CXXFLAGS) -c src/saxml.c

.PHONY: clean run

run:
	./test
clean:
	rm -rf *.o