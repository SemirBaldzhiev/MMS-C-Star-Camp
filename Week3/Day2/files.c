#include <stdio.h>

int main() {

    FILE *file = fopen("hello", "a");
    fputc('H', file);
    fputc('E', file);
    fputc('L', file);
    fputc('L', file); 
    fputc('O', file); 
    fputc(' ', file); 
    fputs("WORLD!", file);

    fclose(file);

    return 0;
}