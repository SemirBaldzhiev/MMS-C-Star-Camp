#include <stdio.h>

int main(int argc, char* argp[]) {

    FILE *f = fopen(argp[1], "r");
    
    int curr_sym;
    while ((curr_sym = fgetc(f)) != EOF) {
        printf("%c", curr_sym);
    }
    
    fclose(f);

    return 0;
}