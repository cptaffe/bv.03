CC=clang
CFLAGS=-std=gnu99
BIN=comp
SRC=main.c


comp:
	$(CC) $(CFLAGS) $(SRC) -o $(BIN)

clean:
	rm $(BIN)