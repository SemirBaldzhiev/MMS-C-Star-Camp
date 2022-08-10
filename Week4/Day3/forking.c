#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>



int main() {

    int pid = fork();
    if (pid == 0){
        sleep(1);
        printf("Hello child\n");

    }
    else{
        printf("Hello parent\n");
        wait(NULL);
    }
    return 0;

}