#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

// SIGKILL сигнала се не може да бъде спрян, защото се праща директо към ядрото на ОС
int main() {

    signal(SIGINT, SIG_IGN);
    signal(SIGTSTP, SIG_IGN);

    while(1){
        printf("MMS C Camp\n");
        usleep(500000);
    }

    return EXIT_SUCCESS;
}