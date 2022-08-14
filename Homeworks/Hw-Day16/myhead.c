#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>


int head_file(char *filename, unsigned n){
    FILE *f = fopen(filename, "r");
    if (!f){
        perror("fopen");
        return -1;
    }

    char c;

    while (n){

        c = fgetc(f);
        if (c == EOF){
            break;
        }

        if (c == '\n'){
            n--;
        }

        printf("%c", c);
    }

    return 0;
}

int main(int argc, char **argv){
    
    int opt,flag = 1, n = 10;

    if ((opt = getopt(argc, argv, "n:")) != -1){
        switch(opt){
            case 'n':
                sscanf(optarg, "%d", &n);
                flag+=2;
                break;
        }
    }

    for (int i = flag; i < argc; i++){
        head_file(argv[i], n);
    }

    return EXIT_SUCCESS;
}