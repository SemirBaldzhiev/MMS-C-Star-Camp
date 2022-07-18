#include <stdio.h>

#define DEBUG
#define RELEASE
#define DEVELOPM

int  main() {


    #ifdef DEBUG 
        printf("Debug mode\n");
    #else
        printf("Not debug mode\n");  
    #endif

    #if defined(DEBUG) && defined(DEVELOPMENT)
        printf("Code cant be released\n");
    #else 
        printf("Code is realesed\n");
    #endif

    #ifdef OS
        #if OS == 1
            printf("Hello Linux\n");
        #elif OS == 2
            printf("Hello Windows\n");
        #elif OS == 3
            printf("Hello MacOS\n");
        #endif
    #else 
        printf("OS not defined");
    #endif


    // #error Error Message - cant compile
    // #warning Warning message

    printf("%s\n", __FILE__);
    printf("%s\n", __TIME__);
    printf("%s\n", __TIMESTAMP__);
    printf("%d\n", __STDC__);
    #line 3
    printf("%d\n", __LINE__);

    return 0;
}