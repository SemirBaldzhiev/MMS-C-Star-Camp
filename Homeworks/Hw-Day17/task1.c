#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/wait.h>


int randint(int min, int max){
    return min + rand() % (max - min + 1);
}

int main(int argc, char **argv) {

    time_t t;
    int n = atoi(argv[1]);

    for (int i = 0; i < n; i++){
        pid_t pid = fork();
        if (0 == pid){
            srand((int)time(&t) % getpid());
            char str[11];

            for (int i = 0; i < 10; i++){
                str[i] = randint('a', 'z');
            }
            str[10] = '\0';
            printf("%s\n", str);
            exit(EXIT_SUCCESS);
        }
    }

    for (int i = 0; i < n; i++){
        wait(NULL);
    }
    return 0;
}