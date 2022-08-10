#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int sumD(int num) {
    int sum = 0;
    while (num){
        sum += num % 10;
        num /= 10;
    }

    return sum;
}

int main(int argc, char **argv) {


    for (int i = 1; i < argc; i++){
        pid_t pid = fork();

        if (-1 == pid){
            exit(EXIT_FAILURE);
        }

        if (0 == pid){
            int n;
            sscanf(argv[i], "%d", &n);
            printf("Sum of digits of %d is %d\n", n, sumD(n));
            exit(EXIT_SUCCESS);
        }
    }

    for (int i = 0; i < argc - 1; i++){
        wait(NULL);
    }

    return 0;
}