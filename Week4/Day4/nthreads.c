#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

//#define COUNT 5

void * routine(void * arg1){
    sleep(rand() % 10);
    int num = rand() % 100;
    printf("Num: %d\n", num);
}

unsigned long long count = 0;
void * routine2(void * arg1){
    for (int i =0; i < 10000; i++){
        count++;
    }
}

int main() {
    pthread_t pth[COUNT];

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

    return EXIT_SUCCESS;   

}