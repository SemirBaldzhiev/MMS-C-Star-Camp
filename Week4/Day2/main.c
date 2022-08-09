#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    int n;
    scanf("%d", &n);
    int *arr = malloc(n * sizeof(int));

    if (!arr){
        fprintf("Malloc failed!\n");
        return -1;
    }

    srand(time(NULL));
    for (int i = 0; i < n; i++){
        arr[i] = rand() % 10;
    }

    for (int i = 0; i < n;i++){
        printf("%d ", arr[i]);
    }

    putchar('\n');
    return 0;
}