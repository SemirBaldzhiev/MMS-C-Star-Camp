#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/types.h>

#define THREAD_COUNT 5

typedef struct arg {
    int n;
    int m;
    double **vec;
} arg;

void *routine(void * arg){

} 

int main() {

    int n, m;
    scanf("%d %d", &n, &m);
    double vec[n][m]

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            scanf("%lf", &vec[i][j]);
        }
    }
    char filename[100];
    scanf("%s", filename);

    pthread_t pht[THREAD_COUNT];
    arg *args = malloc(sizeof(arg));
    arg->n = n;
    arg->m = m;
    arg->vec = vec;
    for (int i = 0; i <  THREAD_COUNT; i++){
        if(pthread_create(pth + i, NULL, routine, arg)){
            perror("pthread");
            return EXIT_FAILURE;
        }
    }
    frree(arg);
    return EXIT_SUCCESS;
}