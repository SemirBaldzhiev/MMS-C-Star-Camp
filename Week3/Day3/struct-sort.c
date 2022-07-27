#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

char *names_list[] = {"prod1", "prod2", "prod3", "prod4", "prod5", "prod6", "prod7"};

typedef struct Product {
    unsigned id;  //4
    float price; //4
    unsigned short salesCount; //2
    char name[10];

} Product;

int compareProd(const void *ptr1, const void *ptr2){

    const Product *p1 = ptr1;
    const Product *p2 = ptr2;

    if (p1->salesCount * p1->price > p2->salesCount * p2->price) {
        return 1;
    }
    else if (p1->salesCount * p1->price < p2->salesCount * p2->price) {
        return -1;
    }

    return strcmp(p1->name, p2->name) ? strcmp(p1->name, p2->name) : p1->id - p2->id;
}

void init_random_product(Product *p){
    static int id_counter;
    p->id = id_counter++;
    p->salesCount = rand() % 1000;
    p->price = (150 + rand()%(20025 - 100)) / 100.0;
    strcpy(p->name, names_list[rand() % 7]);
}

void print_product(Product *p){
    printf("id: %d, price: %.2f, sales count: %d, name: %s\n", p->id, p->price, p->salesCount, p->name);
}

int main() {
    srand(time(NULL));
    Product *products = malloc(30 * sizeof(Product));

    if (!products){
        fprintf(stderr, "Malloc failed!\n");
    }

    for(int i = 0; i < 30; i++){
        init_random_product(products + i);
    }

    products[0].salesCount = 0;
    products[1].salesCount = 0;
    products[2].salesCount = 0;


    for (int i = 0; i < 30; i++){
        print_product(products + i);
    }


    qsort(products, 30, sizeof(Product), compareProd);
    printf("----------------------------------------------------------------\n");
    
    for (int i = 0; i < 30; i++){
        print_product(products + i);
    }

    free(products);

    return 0;
}