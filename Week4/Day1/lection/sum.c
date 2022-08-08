#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    
    int sum = 0;
    int num;
    for (int i = 1;i < argc; i++){
        sscanf(argv[i], "%d", &num);
        sum += num;
        //sum += atoi(argv[i]);
    }

    printf("Sum = %d\n", sum);

    return 0;
}