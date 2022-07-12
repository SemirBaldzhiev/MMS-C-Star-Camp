#include <stdio.h>

int main() {

    int n, max;

    scanf("%d", &max);

    while (scanf("%d", &n) != EOF) {
        
        if (n > max){
            max = n;
        }
    }

    printf("%d\n", max);
}