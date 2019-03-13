CC=gcc
SOURCES=src/fizzbuzz.c src/fizzbuzz.h
MAIN= src/main.c
TESTMAIN=test/test.c
EXECUTABLE=fizzbuzz
TESTS=test/validOutput test/test.c test/test.sh

all: build tests

build: $(SOURCES)
	$(CC) $(MAIN) $(SOURCES) -o $(EXECUTABLE)

tests: $(TESTS)
	$(CC) $(SOURCES) $(TESTMAIN) -o test/tests
	bash test/test.sh
