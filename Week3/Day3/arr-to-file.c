#include <stdio.h>

int main(){

    FILE *f = fopen("numbers", "w");

    int arr[] = {1,2,3,4,5,6,7,8};
    int c = 8;

    if (!f){
        perror("Cannot open file!\n");
        return -1;
    }

    for (int i = 0; i < c; i++){
        fprintf(f, "%d ", arr[i]);
    }

    fclose(f);

    return 0;
}