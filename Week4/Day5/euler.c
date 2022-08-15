#include <stdio.h>
#include <stdlib.h>

#define TIRE_COUNT 18
#define THREAD_COUNT 4

unsigned long fact(unsigned long n){
    unsigned long res = 1;
    while (n > 0) {
        res *= n--;
    }
    return res;
}

int main() {

    double sum = 0;

    for (int i = 0; i < TIRE_COUNT; i++){
        sum += 1./fact(i);
    }

    return EXIT_FAILURE;
}