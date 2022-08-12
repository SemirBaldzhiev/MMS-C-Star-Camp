#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void * routine1(void * arg1){
    int n = 5;
    while(--n){
        printf("Hello world!\n");
    }
}

void * routine2(void * arg1){
    int n = 5;
    while(--n){
        printf("Hello MMS!\n");
        sleep(1);
    }
}

int main() {
    pthread_t th1, th2;
    pthread_create(&th1, NULL, routine1, NULL);  
    pthread_create(&th2, NULL, routine2, NULL); 
    sleep(5);

    pthread_join(th1, NULL);
    pthread_join(th2, NULL);

    return EXIT_SUCCESS;   

}