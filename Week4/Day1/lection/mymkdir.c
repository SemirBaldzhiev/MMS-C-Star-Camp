#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>


int main(int argc, char **argv) {

    for (int i = 1; i < argc; i++){
        if(mkdir(argv[i], 0754) != 0){
            fprintf(stderr, "mkdir failed!\n");
            return -1;
        }
    }
    return 0;
}