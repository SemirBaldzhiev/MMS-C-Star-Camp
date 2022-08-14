#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    int len = argc - 1;
    int numbers[len];
    int sum1 = 0;
    int sum2 = 0;
    int fd[2];

    for (int i = 1; i < len; i++){
        numbers[i - 1] = atoi(argv[i]);
    }

    pipe(fd);
    pid_t pid = fork();
    if (0 == pid){
        close(fd[0]);
        for (int i = 0; i < len / 2; i++){
            sum1 += numbers[i];
        }
        printf("Sum1 = %d\n", sum1);
        write(fd[1], &sum1, sizeof(sum1));
        close(fd[1]);
    }
    else{
        close(fd[1]);
        for (int i = len / 2; i < len; i++){
            sum2 += numbers[i];
        }
        printf("Sum2 = %d\n", sum2);
        wait(NULL);
        int sum_child;
        read(fd[0], &sum_child, sizeof(sum_child));
        int total = sum2 + sum_child;
        printf("Total = %d\n", total);
        close(fd[0]);
    }
    return 0;
}
