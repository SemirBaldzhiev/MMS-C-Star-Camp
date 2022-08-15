#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int count_ones(int masks[], int count) {
    int res_count = 0;
    for (int i = 0; i < count; i++){
      while(masks[i]) {
            res_count += !!(masks[i] & 1);
            masks[i] >>= 1;
        }
    }

    return res_count;
}

int main(int argc, char **argv) {

    int total = 0;
    int fd[2];
    if (pipe(fd) == -1){
        perror("pipe");
        return EXIT_FAILURE;
    }

    for (int i = 1; i < argc; i++){
        FILE *f = fopen(argv[i], "rb");
        if(!f){
            perror("fopen");
            exit(EXIT_FAILURE);
        }

        int masks[100];
        int k = 0;
        while(fread(masks + k , sizeof(int), 1, f) != 0) {
            k++;
        }

        pid_t pid = fork();
        
        if(-1 == pid) {
            perror("fork");
            exit(EXIT_FAILURE);
        }

        if(0 == pid){
            close(fd[0]);
            int ones = count_ones(masks, k + 1);
            printf("%s - %d\n", argv[i], ones);
            write(fd[1], &ones, sizeof(ones));
            close(fd[1]);
            exit(EXIT_SUCCESS);
        }
        fclose(f);
    }

    for (int i = 0; i < argc - 1; i++){
        
        wait(NULL);
        close(fd[1]);
        int curr_sum;
        read(fd[0], &curr_sum, sizeof(curr_sum));
        printf("%d\n", curr_sum);
        total += curr_sum;
        close(fd[0]);
    }

    printf("Total: %d\n", total);
    return EXIT_FAILURE;
}