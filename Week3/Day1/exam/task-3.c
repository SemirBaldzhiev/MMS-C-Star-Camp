#include <stdio.h>

int main() {

    char num[500];
    scanf("%s", num);

    for (int i = 0; num[i] != '\0'; i++){
        if (i % 2 == 0){
            num[i] = (char)(num[i] + 17);
        }
        else{
            switch (num[i])
            {
                case '0':   num[i] = '!'; break;
                case '1': num[i] = '#';  break;
                case '2':  num[i] = '/';  break;
                case '3':   num[i] = '~'; break;
                case '4':   num[i] = '='; break;
                case '5': num[i] = (char)44; break;
                case '6': num[i] = '\\'; break;
                case '7':  num[i] = '>';  break;
                case '8': num[i] = '.'; break;
                case '9': num[i] = ','; break;
            }
        }
    }

    printf("%s\n", num);

    return 0;
}