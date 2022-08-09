#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    srand(time(NULL));
    int n, m;

    scanf("%d %d", &n, &m);

    double **matrix = malloc(n * sizeof(double*));

    if(!matrix){
        fprintf(stderr, "Malloc failed!\n");
        return -1;
    }

    for (int i = 0; i < n; i++){
        matrix[i] = malloc(m * sizeof(double));
            if(!matrix[i]){
            fprintf(stderr, "Malloc failed!\n");
            return -1;
        }

    }


    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            matrix[i][j] = (rand() % 10) / 10.0;
        }
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            printf("%.2lf ", matrix[i][j]);
        }
        putchar('\n');
    }

    for (int i = 0; i < n; i++){
        free(matrix[i]);
    }

    free(matrix);

    return 0;
}