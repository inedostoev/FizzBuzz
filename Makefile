CC=gcc
SOURCES=src/fizzbuzz.c src/fizzbuzz.h
MAIN= src/main.c
TESTMAIN=test/test.c
EXECUTABLE=fizzbuzz
TESTS=test/validOutput test/test.c test/test.sh

all: build tests

build: $(SOURCES) $(MAIN)
	$(CC) $(MAIN) $(SOURCES) -o $(EXECUTABLE)

tests: $(TESTS) $(SOURCES)
	$(CC) $(SOURCES) $(TESTMAIN) -o test/tests
	bash test/test.sh
