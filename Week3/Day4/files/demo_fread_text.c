#include <stdio.h>
#include <stdlib.h>

int main() {


    FILE *file = fopen("test_text_file", "r");
    if (!file){
        perror("Could not open file!\n");
        exit(-1);
    }


    char arr[12];
    fread(arr, sizeof(char), 12, file);
    fwrite(arr, sizeof(char), 12, stdout);
    printf("%s", arr);
    fclose(file);
    return 0;
}