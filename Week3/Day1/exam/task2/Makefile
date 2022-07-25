CC=gcc

.PHONY: all
all: main

%.o: %.c
	$(CC) -c $< -o $@ -D COUNT=5 -D MIN=-10 -D MAX=20

main: main.o comparators.o
	$(CC) $^ -o main -D COUNT=5 -D MIN=-10 -D MAX=20

.PHONY: clean
clean:
	rm -f *.o main