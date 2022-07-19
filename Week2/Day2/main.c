#include <stdio.h>
#include "randoms.h"


int main() {

    randinit();
    printf("%.2lf\n", randreal(0,1));
    printf("%.2lf\n", randreal(0,1));


    for (int i = 0; i < 5; i++){
        printf("%d\n", randint(1, 6));
        printf("%c\n", randint('a', 'z'));
        printf("%.2lf\n", randreal(1.3, 5.3));

    }
    return 0;
}