#include <stdio.h>

int main(int argc, char **argv) {

    printf("Arguments count: %d\n", argc);

    for (int i =0;i < argc; i++){
        printf("argv[%d] = %s\n", i, argv[i]);
    }
    
    return 0;
}