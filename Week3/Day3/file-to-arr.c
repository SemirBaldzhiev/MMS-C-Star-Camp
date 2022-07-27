#include <stdio.h>
#include <stdlib.h>
int main(){

    FILE *f = fopen("numbers", "r");
    
    if (!f){
        perror("Cannot open file!\n");
        return -1;
    }
    
    int arr[100]; 
    int curr_num;
    int arrC = 0; 
    for (;fscanf(f, "%d", (arr + arrC)) != EOF; arrC++) {}

    for (int i = 0; i < arrC; i++){
        printf("%d ", arr[i]);
    }

    putchar('\n');
   
    fclose(f);

    return 0;
}