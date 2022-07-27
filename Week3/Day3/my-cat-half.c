#include <stdio.h>

int main(int argc, char* argp[]) {

    FILE *f = fopen(argp[1], "r");
    fseek(f, 0, SEEK_END);
    int c = ftell(f);
    fseek(f, c / 2, SEEK_SET);
    int curr_sym;
    while ((curr_sym = fgetc(f)) != EOF) {
        printf("%c", curr_sym);
    }
    
    fclose(f);

    return 0;
}