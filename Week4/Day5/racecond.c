#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>

#define N 5
pthread_mutex_t mux;
sem_t sem;

int num = 0;

void* routine(void *arg){

    sleep(5);
    for (int i = 0; i < 1000000; i++){
        pthread_mutex_lock(&mux);
        num++;
        pthread_mutex_unlock(&mux);
    }
}

int main() {

    pthread_t th[N];
    pthread_mutex_init(&mux, NULL);
    sem_init(&sem, 0, 1);
    for (int j = 0; j < N; j++){

        if (pthread_create(th + j, NULL, routine, NULL)){
            perror("thread create");
            return EXIT_FAILURE;
        }

    }

    for (int j = 0; j < N; j++){
        if (pthread_join(th[j], NULL)){
            perror("join");
            return EXIT_FAILURE;
        }
    }
    pthread_mutex_destroy(&mux);
    sem_destroy(&sem);
    printf("Num: %d\n", num);
}