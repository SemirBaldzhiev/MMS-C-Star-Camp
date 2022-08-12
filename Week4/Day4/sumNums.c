#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>


void * routine(void *arg){
    FILE *f = fopen((char*)arg, "r");
    double *sum = malloc(sizeof(double));
    double num;

    while (fscanf(f, "%lf", &num) != EOF){
        *sum += num;
    }
    fclose(f);
    return sum;
} 


int main(int argc, char **argv) {
    
    double total = 0;
    pthread_t pth[argc - 1];
    for (int i = 1; i < argc; i++){
        if (pthread_create(pth + (i - 1), NULL, routine, argv[i])){
            perror("pthread");
            return EXIT_FAILURE;
        }
    }

    for (int i = 0; i < argc - 1; i++){
        double *sum_ptr;
        if (pthread_join(pth[i], (void**)&sum_ptr)){
            perror("join");
            return EXIT_FAILURE;
        }

        total += *sum_ptr;
        free(sum_ptr);
    }

    printf("Sum: %.2lf\n", total);

    return EXIT_SUCCESS;
}