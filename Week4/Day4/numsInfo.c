#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <time.h>

double sum(int argc, char **argv);
double min(int argc, char **argv);
double max(int argc, char **argv);
double avg(int argc, char **argv);

int main(int argc, char **argv) {
    int fd[2];
    if (pipe(fd) == -1){
        perror("pipe");
        return EXIT_FAILURE;
    }

    pid_t pid = fork();

    if (pid == -1){
        perror("fork");
        return EXIT_FAILURE;
    }

    if (pid == 0){

        close(fd[0]);
        double sum_nums = sum(argc, argv);
        double min_num = min(argc, argv); 
        double max_num = max(argc, argv);;
        double avg_num = avg(argc, argv);;

        write(fd[1], &sum_nums, sizeof(double));
        write(fd[1], &min_num, sizeof(double));
        write(fd[1], &max_num, sizeof(double));
        write(fd[1], &avg_num, sizeof(double));
        close(fd[1]);
    }
    else{
        close(fd[1]);
        double sum_nums_child;
        double min_num_child;
        double max_num_child;
        double avg_num_child;

        read(fd[0], &sum_nums_child, sizeof(double));
        read(fd[0], &min_num_child, sizeof(double));
        read(fd[0], &max_num_child, sizeof(double));
        read(fd[0], &avg_num_child, sizeof(double));

        printf("Sum: %.2lf\n", sum_nums_child);
        printf("Min: %.2lf\n", min_num_child);
        printf("Max: %.2lf\n", max_num_child);
        printf("Avg: %.2lf\n", avg_num_child);
        wait(NULL);
        close(fd[0]);
    }

    return EXIT_SUCCESS;
}

double max(int argc, char **argv){
    double max = -__DBL_MAX__;

    for (int i = 1; i < argc; i++){
        double num;
        sscanf(argv[i], "%lf", &num);
        if (num > max) {
            max = num;
        }
    }

    return max;
}

double min(int argc, char **argv){
    double min = __DBL_MAX__;

    for (int i = 1; i < argc; i++){
        double num;
        sscanf(argv[i], "%lf", &num);
        if (num < min) {
            min = num;
        }
    }

    return min;
}

double sum(int argc, char **argv){
    double sum = 0;

    for (int i = 1; i < argc; i++){
        double num;
        sscanf(argv[i], "%lf", &num);
        sum += num;
    }

    return sum;
}

double avg(int argc, char **argv){
    return sum(argc, argv) / (argc - 1);
}