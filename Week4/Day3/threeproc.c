#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {

    int pid1 = fork();

    if (0 == pid1){
        //int pid2 = fork();

        printf("PID: %d, PPID: %d\n", getpid(), getppid());
    }
    else{

        int pid2 = fork();

        if (0 == pid2){
            int pid3 = fork();
            if (0 == pid3){
                printf("PID: %d, PPID: %d\n", getpid(), getppid());
            }
            else{
                int pid4 = fork();
                if (0 == pid4){
                    printf("PID: %d, PPID: %d\n", getpid(), getppid());
                }
                else{
                    printf("PID: %d, PPID: %d\n", getpid(), getppid());
                    wait(NULL);
                    wait(NULL);
                }
            }
        }
        else{
            
            printf("PID: %d, PPID: %d\n", getpid(), getppid());
            wait(NULL);
            wait(NULL);
        }

        wait(NULL);
        wait(NULL);

    }
    return 0;
}