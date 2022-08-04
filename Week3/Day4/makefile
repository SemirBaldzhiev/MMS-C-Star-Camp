build: linked_list.c linked_list.h main.c
	mkdir build
	gcc -c linked_list.c
	gcc -c main.c
	gcc linked_list.o main.o -o program
	mv linked_list.o main.o program ./build


.PHONY: clean
clean:
	rm -r ./build
run: 
	./build/program
