#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define COUNT 2

pthread_mutex_t mux;

unsigned long long count = 0;
void * routine(void * arg1){
    for (int i =0; i < 10000; i++){
        pthread_mutex_lock(&mux);
        count++;
        pthread_mutex_unlock(&mux);
    }
}

int main() {
    pthread_t pth[COUNT];
    pthread_mutex_init(&mux, NULL);

    for (int i = 0; i< COUNT; i++){
        if (pthread_create(pth + i, NULL, routine, NULL)){
            perror("pthread");
            return EXIT_FAILURE;
        }
    }

    for (int i = 0; i < COUNT; i++){
        if(pthread_join(pth[i], NULL)){
            perror("join");
            return EXIT_FAILURE;
        }
    }
    printf("count: %llu\n", count);
    pthread_mutex_destroy(&mux);

    return EXIT_SUCCESS;   

}