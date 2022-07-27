#include <stdio.h>
#include <string.h>

int main(int argc, char* argp[]) {


    FILE *f = fopen(argp[1], "r");

    int symb_c = 0;
    int word_c = 0;

    int len = strlen(argp[2]);

    int curr_sym;
    int i = 0;

    while((curr_sym = fgetc(f)) != EOF){
        
        if (curr_sym != argp[2][symb_c]) {
            symb_c = 0;
        }
        
        if (curr_sym == argp[2][symb_c]) {
            symb_c++;
        }
        if (symb_c == len){
            word_c++;
            symb_c = 0;
        }
    }

    printf("%d\n", word_c);
    printf("%d\n", len);


    fclose(f);

    return 0;
}