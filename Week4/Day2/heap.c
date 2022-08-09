#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    srand(time(NULL));
    int n;
    scanf("%d", &n);
    double *arr = malloc(n * sizeof(double));

    if (!arr){
        fprintf(stderr ,"Malloc failed!\n");
        return -1;
    }
    int i;
    for (i = 0; i < n; i++) {
        arr[i] = ((double)rand() / RAND_MAX) * 1.0;
    }

    int m;
    scanf("%d", &m);
    arr = realloc(arr, (n + m) * sizeof(double));

    if (!arr){
        fprintf(stderr ,"First realloc failed!\n");
        return -1;
    }

    for (int j = 0; j < m; j++){
        arr[i++] = 1.0 + ((double)rand() / RAND_MAX) * 1.0;
    }

    int p;
    scanf("%d", &p);
    arr = realloc(arr, (n + m + p) * sizeof(double));
    
    if (!arr){
        fprintf(stderr ,"Second realloc failed!\n");
        return -1;
    }

    for (int j = 0; j < p; j++){
        arr[i++] = 2.0 + ((double)rand() / RAND_MAX) * 1.0;
    }

    for (int i = 0; i < n + m + p; i++){
        printf("%.2lf ", arr[i]);
    }
    putchar('\n');

    free(arr);
    return 0;
}