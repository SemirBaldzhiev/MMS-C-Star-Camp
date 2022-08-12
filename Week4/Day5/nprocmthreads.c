#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <pthread.h>
#include <unistd.h>

#define N 5
#define M 2

void * routine(void *arg){
    printf("My PID: %d, Thread ID: %ld\n", getpid(), pthread_self());
} 

int main() {


    for (int i = 0; i < N; i++){
        pid_t pid = fork();

        if (pid == -1){
            perror("fork");
            return EXIT_FAILURE;
        }

        if (pid == 0){


            pthread_t th[M];
            for (int j = 0; j < M; j++){

                if (pthread_create(th + j, NULL, routine, NULL)){
                    perror("thread create");
                    return EXIT_FAILURE;
                }

            }

            for (int j = 0; j < M; j++){
                if (pthread_join(th[j], NULL)){
                    perror("join");
                    return EXIT_FAILURE;
                }
            }

            exit(EXIT_SUCCESS);
        }
    }



    for  (int i = 0; i < N; i++){
        wait(NULL);
    }

    return EXIT_SUCCESS;
}