#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <dirent.h>
#include <string.h>
int main(int argc, char **argv) {

    int opt; 
    struct dirent *d;
    char dir[BUFSIZ];
    if (argc == 1){
        strcpy(dir, ".");
    }
    else{
        strcpy(dir, argv[argc - 1]); // last arg is dir name
    }
    int flag = 0;
	DIR *dr = opendir(dir);
    if ((opt = getopt(argc, argv, "daf")) != -1){
        switch (opt){
            case 'f': // only files
                while ((d = readdir(dr)) != NULL) {
                    if (d->d_type == DT_REG && d->d_name[0] != '.'){
                        printf("%s\n", d->d_name);
                    }
                }
                flag++;
                break;
            case 'd': // only dir
                while ((d = readdir(dr)) != NULL) {
                    if (d->d_type == DT_DIR && d->d_name[0] != '.'){
                        printf("%s\n", d->d_name);
                    }
                }
                flag++;
                break;
            case 'a': // hidden files
                while ((d = readdir(dr)) != NULL) {
                    if ((d->d_type == DT_REG || d->d_type == DT_DIR) && d->d_name[0]){
                        printf("%s\n", d->d_name);
                    }
                }
                flag++;
                break;
        }
    }
    //if dir name is not passed default is .
    if (!flag){
        while ((d = readdir(dr)) != NULL) {
            if ((d->d_type == DT_REG || d->d_type == DT_DIR) && d->d_name[0] != '.'){
                printf("%s\n", d->d_name);
            }
        }
    }
    
    closedir(dr);
    return EXIT_SUCCESS;
}
