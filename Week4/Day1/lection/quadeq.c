#include <stdio.h>
#include <math.h>
#include <getopt.h>

int main(int argc, char **argv) {

    double a, b, c, x1, x2;
    int opt, p = 2, flag = 0;
    char fmt[16];
    while ((opt = getopt(argc, argv, "a:b:c:p:")) != -1) {
        switch(opt){
            case 'a': 
                sscanf(optarg, "%lf", &a);
                flag++;
                break;
            case 'b': 
                sscanf(optarg, "%lf", &b);
                flag++;
            break;
            case 'c': 
                sscanf(optarg, "%lf", &c);
                flag++;
            break;
            case 'p': 
                sscanf(optarg, "%d", &p);
            break;
        }

    }

    if (flag != 3){
        fprintf(stderr, "Invalid options!\n");
        return -1;
    }

    double d = b * b - 4 * a * c;

    if (d < 0) {
        fprintf(stderr ,"No real solutions!\n");
        return -1;
    }

    if (d == 0){
        x1 = x2 = (-b / (2 * a));
    }
    else{
        x1 = (-b + sqrt(d)) / (2 * a);
        x2 = (-b - sqrt(d)) / (2 * a);
    }
    sprintf(fmt, "x1/2 = %%.%dlf\n", p);
    printf(fmt, x1);
    printf(fmt, x2);

    return 0;
}
