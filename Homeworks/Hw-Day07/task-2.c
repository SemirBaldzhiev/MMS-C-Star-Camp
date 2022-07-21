#include <stdio.h>

int sumDigits(int num);
unsigned sumArrayDigits(const int* arr, size_t n);

int main() {

    int arr[] = {12, 34, 5, 70 };
    printf("%d\n", sumArrayDigits(arr, 4));

    return 0;
}


int sumDigits(int num){
    int sum = 0;
    while (num){
        sum += num % 10;
        num /= 10;
    }

    return sum;
}

unsigned sumArrayDigits(const int* arr, size_t n) {
    
    int arrSum = 0;
    for (int i = 0; i < n; i++){
        if (arr[i] > 0) {
            arrSum += sumDigits(arr[i]);
        }
    }

    return arrSum;
}