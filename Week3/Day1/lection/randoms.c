#include <stdlib.h>
#include <time.h>

int randint(int min, int max){
    return min + rand() % (max - min + 1);
}

double randreal(double min, double max){
    return min + ((double)rand() / RAND_MAX) * (max - min);
}

void randinit(void) {
    srand(time(NULL));
}