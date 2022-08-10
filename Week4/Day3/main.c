#include <stdlib.h>
#include <stdio.h>
#include <getopt.h>
#include <unistd.h>
//#include <sys/types.h>
#include <fcntl.h>
//#include <sys/stat.h>
#include <string.h>


int main(int argc, char **argv) {

    int opt, n = 10, flag = 0;
    char out_file[100];
    char err_file[100];
    while ((opt = getopt(argc, argv, "n:o:e:"))!= -1){
        switch (opt)
        {
        case 'n':
            sscanf(optarg, "%d", &n);
            break;
            case 'o':
            strcpy(out_file, optarg);
            flag = 1;
            break;
            case 'e':
            strcpy(err_file, optarg);
            flag = 2;
            break;
        }
    }

    
    int *nums = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++){
        nums[i] = 1 + rand() % 10;
    }

    if (1 == flag){
        int fd = open(out_file, O_CREAT | O_APPEND | O_WRONLY, 0777);
        
        dup2(fd, STDOUT_FILENO);
        for (int i = 0; i < n;i++){
            printf("%d\n", nums[i]);
        } 
        close(fd);
            
    }
    else if (2 == flag){
        int fd = open(err_file, O_CREAT | O_APPEND | O_WRONLY, 0777);
        dup2(fd, STDERR_FILENO);
        for (int i = 0; i < n;i++){
            printf("%d\n", nums[i]);
        }
        close(fd);
    }
    free(nums);
    return 0;
}