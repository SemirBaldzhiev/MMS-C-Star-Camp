#include <stdio.h>
#include <getopt.h>

int main(int argc, char **argv){
    
    int opt;
    
    while ((opt = getopt(argc, argv, "a:b:X")) != -1) 
    {
        switch (opt) 
        {
            case 'a':
            printf("Option a has arg: %s\n", optarg);
            break;
            case 'b':
            printf("Option b has arg: %s\n", optarg);
            break;
            case 'X':
            printf("Option X was provided\n");
            break;
        }
    }
    return 0;
}