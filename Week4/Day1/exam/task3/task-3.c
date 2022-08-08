#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define PROD_COUNT 40

typedef struct Product
{
     double old_price;
     double new_price;
     unsigned int id;
     char product_type;
     char product_name[11];
} Product;

char *prod_names[] = {
    "product1",
    "product2",
    "product3",
    "product4",
    "product5",
    "product6",
    "product7",

};

void init_random_product(Product *p){
    static int id_cnt = 0;
    p->id = id_cnt++;
    p->old_price = 4.99 + ((double)rand() / RAND_MAX) * (100.45 - 4.99);
    p->new_price = 4.99 + ((double)rand() / RAND_MAX) * (100.45 - 4.99);
    p->product_type = 65 + rand() % (68 - 65 + 1);
    strcpy(p->product_name, prod_names[rand()%7]);
}

void print_product(Product *p) {
    printf("Id: %d, Name: %s, Old Price: %.2lf, New Price: %.2lf, Product Type: %c\n", 
    p->id, p->product_name, p->old_price, p->new_price, p->product_type);
}


int compare_products(const void *p1, const void *p2) {
    const Product *prod1 = p1, *prod2 = p2;
    double prod1_price_diff = prod1->new_price -prod1->old_price;
    double prod2_price_diff = prod2->new_price -prod2->old_price;
    double prce_diff = prod1_price_diff - prod2_price_diff;

    if(fabs(prce_diff) > 0.01) {
        return prce_diff*100;
    }


    if (prod1->product_type != prod2->product_type){
        return prod1->product_type - prod2->product_type;
    }

    int cmp_names = strcmp(prod1->product_name, prod2->product_name);
    if(cmp_names != 0) {
        return cmp_names;
    }

    return prod1->id - prod2->id;
}

void save_binary(const Product *products, const char *filename){
    FILE *f = fopen(filename, "wb");
    if (!f){
        perror("Could not open file\n");
        return;
    }
    fwrite(products, sizeof(Product), PROD_COUNT, f);
    fclose(f);
}

int main() {
    //printf("%lu\n", sizeof(Product));
    Product *products = malloc(sizeof(Product) * PROD_COUNT);
    srand(time(NULL));
    for(int i = 0; i < PROD_COUNT; i++) {
        init_random_product(products + i);
    }

    for (int i =0;i < PROD_COUNT; i++){
        print_product(products + i);
    }
    printf("---------------------------------------------------------\n");
    qsort(products, PROD_COUNT, sizeof(Product), compare_products);
    for (int i =0;i < PROD_COUNT; i++){
        print_product(products + i);
    }
    save_binary(products, "binary_prods");
    free(products);
    return 0;
}