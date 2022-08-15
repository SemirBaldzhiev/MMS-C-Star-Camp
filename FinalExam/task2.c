#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {

    for (int i = 1; i < argc; i++){
        FILE *f = fopen(argv[i], "rb");
        if(!f){
            perror("fopen");
        }

        int masks[100];
        int bytes;
        while(fread(mask + i , sizeof(mask), 1, f)) != 0) {
            
        }

        

        fclose()
    }
    return EXIT_FAILURE;
}