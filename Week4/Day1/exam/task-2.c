#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long decimalToBinary(int decimalnum)
{
    long binarynum = 0;
    int rem, temp = 1;

    while (decimalnum!=0)
    {
        rem = decimalnum%2;
        decimalnum = decimalnum / 2;
        binarynum = binarynum + rem*temp;
        temp = temp * 10;
    }
    return binarynum;
}

int main(int argc, char *argp[]){

    if (!strcmp(argp[2], "-H")){
        FILE *f = fopen(argp[1], "r");
        if (!f){
            perror("Couldnot open file!\n");
            return -1;
        }

        int curr_sym;
        while ((curr_sym = fgetc(f)) != EOF) {
            printf("%x ", curr_sym);
        }
        putchar('\n');
        fclose(f);
    }
    else if (!strcmp(argp[2], "-B")){
        FILE *f = fopen(argp[1], "r");
        if (!f){
            perror("Couldnot open file!\n");
            return -1;
        }

        int curr_sym;
        while ((curr_sym = fgetc(f)) != EOF) {
            printf("%lu ", decimalToBinary(curr_sym));
        }
        putchar('\n');
        fclose(f);
    }

    return 0;
}