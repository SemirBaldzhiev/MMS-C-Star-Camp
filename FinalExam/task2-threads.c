#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <pthread.h>

int count_ones(int masks[], int count) {
    int res_count = 0;
    for (int i = 0; i < count; i++){
      while(masks[i]) {
            res_count += !!(masks[i] & 1);
            masks[i] >>= 1;
        }
    }

    return res_count;
}

void *routine(void *arg) {
    FILE *f = fopen(arg, "rb");
    if(!f){
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    int masks[100];
    int k = 0;
    while(fread(masks + k , sizeof(int), 1, f) != 0) {
        k++;
    }
    fclose(f);
    int *ones = malloc(sizeof(int));
    *ones = count_ones(masks, k + 1);
    printf("%s - %d\n",(char *)arg, *ones);

    return ones;
}

int main(int argc, char **argv) {
    int total = 0;
    pthread_t pth[argc - 1];
    for (int i = 1; i < argc; i++){
        if (pthread_create(pth + (i - 1), NULL, routine, argv[i])){
            perror("pthread");
            return EXIT_FAILURE;
        }
    }

    for (int i = 0; i < argc - 1; i++){
        int *sum_ptr;
        if (pthread_join(pth[i], (void**)&sum_ptr)){
            perror("join");
            return EXIT_FAILURE;
        }

        total += *sum_ptr;
        free(sum_ptr);
    }

    printf("Total: %d\n", total);
    return EXIT_FAILURE;
}