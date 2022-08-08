#include <stdio.h>
#include <stdlib.h>

typedef struct Product
{
     double old_price;
     double new_price;
     unsigned int id;
     char product_type;
     char product_name[11];
} Product;

void print_product(Product *p) {
    printf("Id: %d, Name: %s, Old Price: %.2lf, New Price: %.2lf, Product Type: %c\n", 
    p->id, p->product_name, p->old_price, p->new_price, p->product_type);
}

int main(){
    Product prods[40];

    FILE *file = fopen("binary_prods", "rb");

    fread(prods, sizeof(Product), 40, file);

    for (int i = 0; i < 40; i++){
        print_product(prods + i);
    }
    fclose(file);
}