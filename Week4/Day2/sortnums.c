#include <stdio.h>
#include <getopt.h>
#include <stdlib.h>
#include <math.h>

int comparator(const void *num1, const void*num2){
    if (fabs(*(double*)num1) > fabs(*(double*)num2)) return 1;
    else if (fabs(*(double*)num1) < fabs(*(double*)num2)) return -1;
    else return 0;  
}

int main(int argc, char **argv) {
    char in_file[100];
    char out_file[100];
    int opt;
    int flag = 0;
    while ((opt = getopt(argc, argv, "i:o:r")) != -1){
        switch(opt){
            case 'i':
                sscanf(optarg ,"%s", in_file);
                flag++;
            break;
            case 'o':
                sscanf(optarg ,"%s", out_file);
                flag++;
            break;
            case 'r':
                flag++;
            break;
        }
    }

    FILE *fr = fopen(in_file, "r");
    FILE *fw = fopen(out_file, "w");


    if (!fr){
        perror("fr fopen");
        return -1;
    }
    if (!fr){
        perror("fw fopen");
        return -1;
    }
    double arr[100];
    int i  = 0;
    while (fscanf(fr, "%lf", arr + i) != EOF){
        i++;
    }

    qsort(arr, i, sizeof(double), comparator);

    for (int j = 0; j < i; j++){
        printf("%lf", arr[j]);
    }

    if (flag == 3){
        for (int j = i - 1; j >= 0; j--){
            fprintf(fw,"%lf\n", arr[j]);
        }
    }
    else{
        for (int j = 0; j < i; j++){
            fprintf(fw,"%lf\n", arr[j]);
        }
    }

    fclose(fr);
    fclose(fw);
    
    putchar('\n');
    return 0;
}