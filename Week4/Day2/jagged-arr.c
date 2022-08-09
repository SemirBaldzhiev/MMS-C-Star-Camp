#include <stdio.h>
#include <stdlib.h>

#define ROWS 5

void print(int **jagged_arr);
void free_jagged_arr(int **jagged_arr);


int main() {

    int **jagged_arr = malloc(ROWS * sizeof(int*));

    if(!jagged_arr){
        fprintf(stderr, "Malloc failed!\n");
        return -1;
    }

    for (int i = 0; i < ROWS; i++){
        jagged_arr[i] = malloc((i+1) * sizeof(int));
        
        if(!jagged_arr[i]){
            fprintf(stderr, "Malloc failed!\n");
            return -1;
        }

    }

    for (int i = 0; i < ROWS; i++){
        for (int j = 0; j <= i; j++){
            jagged_arr[i][j] = j+1;
        }
    }

    print(jagged_arr);
    free_jagged_arr(jagged_arr);

    return 0;
}

void print(int **jagged_arr){
    for (int i = 0; i < ROWS; i++){
        for (int j = 0; j <= i; j++){
            printf("%d ", jagged_arr[i][j]);
        }
        putchar('\n');
    }
}

void free_jagged_arr(int **jagged_arr){
    for (int i = 0; i < ROWS; i++){
        free(jagged_arr[i]);
    }

    free(jagged_arr);
}