#include <stdio.h>

#define DEBUG
#define RELEASE
#define DEVELOPMENT


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


    #define OS 1
    #if OS == 1
        printf("Hello Linux\n");
    #elif OS == 2
        printf("Hello Windows\n");
    #elif OS == 3
        printf("Hello MacOS\n");
    #endif

    #undef OS
    #define OS 2
    #if OS == 1
        printf("Hello Linux\n");
    #elif OS == 2
        printf("Hello Windows\n");
    #elif OS == 3
        printf("Hello MacOS\n");
    #endif

    #undef OS
    #define OS 3
    #if OS == 1
        printf("Hello Linux\n");
    #elif OS == 2
        printf("Hello Windows\n");
    #elif OS == 3
        printf("Hello MacOS\n");
    #endif

    return 0;
}