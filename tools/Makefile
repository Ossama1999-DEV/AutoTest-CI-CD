CC=gcc
CFLAGS=-Iinc -Wall -Wextra -Werror

SRC=src/addF.c
MAIN=src/main.c
TEST_SRC=tests/test_addF.c

all: app test

app:
	$(CC) $(CFLAGS) $(MAIN) $(SRC) -o app

test:
	$(CC) $(CFLAGS) $(TEST_SRC) $(SRC) -o test

run:
	./app

run_test:
	./test

clean:
	rm -f app test