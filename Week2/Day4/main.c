#include <stdio.h>
#include <string.h>

size_t mystrlen(char* str){
    size_t count;
    for(count = 0; str[count] != '\0'; count++);
    return count;
}

int mystrcmp(const char* str1, const char* str2){
    
    for (int i = 0; i < str1[i] != '\0' || str2[i] != '\0'; i++){
        if (str1[i] < str2[i]){
            return -1;
        }
        if (str1[i] > str2[i]){
            return 1;
        }
    }
    
    return 0;
}


int main(){
    // char str[] = "Hello";
    // char *str2 = "Hello";
    // char name[100] = 
    // strcpy(name, "Pesho");
    // str[3] = '\0';
    // printf("%s\n", str);
    // printf("%s\n", str2);
    // printf("%lu\n", mystrlen(str2));
    // printf("%lu\n", strlen(str2));

    //char name[100];
    // char name2[100];
    
    // fgets(name2, 100, stdin);
    // name2[strlen(name2) - 1] = '\0';
    // //printf("%s\n", name);
    // printf("%s\n", name2);

    printf("%d\n", mystrcmp("das", "aaad"));
    printf("%d\n", strcmp("das", "aaad"));

    return 0;
}