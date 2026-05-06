CC=gcc
CFLAGS=-Iinc

all: app test

app:
	$(CC) $(CFLAGS) src/main.c src/addF.c -o app

test:
	$(CC) $(CFLAGS) tests/test_addF.c src/addF.c -o test

run:
	./app

run_test:
	./test