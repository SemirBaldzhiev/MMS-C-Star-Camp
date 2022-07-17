#include <stdio.h>

int main() {
    
    int num;
    unsigned inBase;
    unsigned outBase;

    scanf("%d", num);
    scanf("%i", inBase);
    scanf("%i", outBase);

    if (inBase < 2 || inBase > 36){
        fprintf(stderr, "Invalid input base!\n");
    }

    if (outBase < 2 || outBase > 36){
        fprintf(stderr, "Invalid output base!\n");
    }

    
    



    return 0;
}