#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int numbers[] = {1,2,3,4,5,6};
    int len = sizeof(numbers) / sizeof(numbers[0]);
    int sum1 = 0;
    int sum2 = 0;
    int fd[2];

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