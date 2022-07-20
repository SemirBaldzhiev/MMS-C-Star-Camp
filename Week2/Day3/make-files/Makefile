CC=gcc

.PHONY: all
all: program

%.o: %.c
	$(CC) -c $< -o $@

program: main.o hello.o
	$(CC) $^ -o program

.PHONY: clean
clean:
	rm -f *.o program
