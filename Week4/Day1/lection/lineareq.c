#include <stdio.h>
#include <getopt.h>

int main(int argc, char **argv) {
    double x, a, b;
    int opt;

    while ((opt = getopt(argc, argv, "a:b:")) != -1) {
        switch(opt){
            case 'a': 
                sscanf(optarg, "%lf", &a);
                break;
            case 'b': 
                sscanf(optarg, "%lf", &b);
            break;
        }

    }

    x = -b / a;
    printf("X = %.2lf\n", x);
    
}