#include <stdio.h>
#include <stdlib.h>

int main() {


    FILE *file = fopen("test_int_file", "wb");
    if (!file){
        perror("Could not open file!\n");
        exit(-1);
    }


    int arr[] = {63, 64, 65, 66};
    fwrite(arr, sizeof(int), 4, file);

    fclose(file);
    return 0;
}