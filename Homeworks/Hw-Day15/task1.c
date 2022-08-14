#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define COUNT 10

typedef struct Book {
    double price;
    unsigned count_pages;
    char title[150];
    char author[100];
} Book;

int randint(int min, int max){
    return min + rand() % (max - min + 1);
}

double randreal(double min, double max){
    return min + ((double)rand() / RAND_MAX) * (max - min);
}

void init_book(Book *b){
    int author_len = randint(10, 20);
    b->author[0] = randint('A', 'Z');

    for (int i = 1; i < author_len; i++){
        b->author[i] = randint('a', 'z');
    }
    b->author[author_len] = '\0';

    int title_len = randint(10, 20);
    b->title[0] = randint('A', 'Z');
    for (int i = 1; i < title_len; i++){
        b->title[i] = randint('a', 'z');
    }
    b->title[title_len] = '\0';

    b->count_pages = randint(5, 2000);
    b->price = randreal(1.0, 1000.0);   
}


int main(int argc, char **argv) {
    srand(time(NULL));
    Book books[COUNT];
    for (int i = 0; i < COUNT; i++){
        init_book(books + i);
    }
    for (int i = 0;i < COUNT; i++){
        fprintf(stdout, "%s, %s, %d, %lf\n", 
            books[i].title, books[i].author, books[i].count_pages, books[i].price);
    }
    FILE *f = fopen(argv[1], "wb");

    if (!f){
        perror("fopen write bin");
        exit(EXIT_FAILURE);
    }

    fwrite(books, sizeof(Book), COUNT, f);

    fclose(f);
    return EXIT_SUCCESS;
}
