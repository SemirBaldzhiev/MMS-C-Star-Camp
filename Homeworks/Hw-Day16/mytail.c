#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>


int tail_file(char *filename, unsigned n){
    FILE *f = fopen(filename, "r");
    if (!f){
        perror("fopen");
        return -1;
    }

    int count_lines = 1;

    char c;
    while ((c = fgetc(f)) != EOF){
        if (c == '\n') {count_lines++;}
    }

    fseek(f, 0, SEEK_SET);

    if (n > count_lines) n = count_lines;
    int act_lines = count_lines - (count_lines - n);
    while (1){
        if (act_lines == count_lines){
            break;
        }
        if(fgetc(f) == '\n') count_lines--;

    }

    while ((c = fgetc(f)) != EOF){
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
        tail_file(argv[i], n);
    }

    return EXIT_SUCCESS;
}