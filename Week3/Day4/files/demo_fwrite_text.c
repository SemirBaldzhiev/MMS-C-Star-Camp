#include <stdio.h>
#include <stdlib.h>

int main() {


    FILE *file = fopen("test_text_file", "w");
    if (!file){
        perror("Could not open file!\n");
        exit(-1);
    }


    char *arr = "Hello world!";
    fwrite(arr, sizeof(char), 12, file);

    fclose(file);
    return 0;
}