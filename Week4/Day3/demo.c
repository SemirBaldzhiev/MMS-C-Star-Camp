#include <stdio.h>
#include <stdlib.h>

int main() {

    
    FILE *f = fopen("img", "r");
    char m_num[3];
    fgets(m_num, 3, f);
    int row, col;
    fscanf(f, "%d %d", &row, &col);
    printf("%s\n", m_num);
    printf("%d %d\n", row, col);
    int arr[18]; 
    int curr_num;
    int arrC = 0; 
    for (;fscanf(f, "%d", (arr + arrC)) != EOF; arrC++) {
        if (*(arr + arrC) > 255){
            fprintf(stderr, "Invalid format\n");
            return -1;
        }
    }
    
    for (int i = 1; i <= 18; i++){
        printf("%d ", arr[i-1]);
        if (i % 3 == 0){
            putchar('\n');
        }
    }


    putchar('\n');



    
    return 0;
}