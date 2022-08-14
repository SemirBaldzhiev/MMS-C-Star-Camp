#include <stdio.h>
#include <stdlib.h>

int cat_file(char *filename){
    FILE *f = fopen(filename, "r");

    if (!f){
        perror("fopen");
        return -1;
    }
    char c;
    while ((c = fgetc(f)) != EOF){
        fprintf(stdout, "%c",c);
    }

    return 0;
}

int main(int argc, char **argv) {

    for (int i = 1; i < argc; i++){
        if(cat_file(argv[i])){
            perror("mycat failed");
            return EXIT_FAILURE;
        }
    }

    return EXIT_SUCCESS;
}
