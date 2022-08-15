#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LAPTOPS_COUNT 5

typedef struct Laptop {
    long serialNum;
    double weight;
    double price;
    char brand[100];

} Laptop;

double randreal(double min, double max){
    return min + ((double)rand() / RAND_MAX) * (max - min);
}

int randint(int min, int max){
    return min + rand() % (max - min + 1);
}

void init_laptop(Laptop *l){
    static long sn = 0;
    l->serialNum = ++sn;
    l->brand[0] = randint('A', 'Z');
    l->brand[1] = ' ';
    int brand_sym_count = randint(8, 12);
    int k = 2;
    for (int i = 0; i < brand_sym_count; i++){
        l->brand[k] = randint('a', 'z');
        k++;
        l->brand[k] = ' ';
        k++;
    }

    l->weight = randreal(0.025, 10.0);
    l->price = randint(100.00, 5000.00);
}

double totalLaptopWeight(Laptop* laptops) {

    if (!laptops){
        return -1;
    }

    double total = 0;
    for (int i = 0; i < LAPTOPS_COUNT; i++){
        total += laptops[i].weight;
    }

    return total;
}

Laptop *minPriceItem(Laptop* laptops) {
    int min_price_index = -1;
    double min_price = __DBL_MAX__;
    for (int i = 0; i < LAPTOPS_COUNT; i++){
        double curr_price = laptops[i].price;
        if (curr_price < min_price) {
            min_price = curr_price;
            min_price_index = i;
        }
    }

    if (-1 == min_price_index){
        return NULL;
    }

    return laptops + min_price_index;
}




int main() {
    srand(time(NULL));
    Laptop *laptops = malloc(sizeof(Laptop) * LAPTOPS_COUNT);
    for (int i = 0; i < LAPTOPS_COUNT; i++){
        init_laptop(laptops + i);
    }

    for (int i = 0; i < LAPTOPS_COUNT; i++){
        printf("%lu, %s, %lf, %lf\n", laptops[i].serialNum, laptops[i].brand, laptops[i].weight, laptops[i].price);
    }

    printf("Sum weight = %lf\n", totalLaptopWeight(laptops));
    Laptop *l = minPriceItem(laptops);
    printf("Min price laptop: %lu, %s, %lf, %lf\n", l->serialNum, l->brand, l->weight, l->price);

    free(laptops);
    return EXIT_FAILURE;
}