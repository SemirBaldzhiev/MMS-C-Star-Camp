#include <stdio.h>
#include <string.h>
#include <stdlib.h>

double sum(double *nums, unsigned count) {
    
    double sum = 0;
    for (int i = 0; i < count; i++){
        sum += nums[i];
    }
}

double max(double *nums, unsigned count){
    
    double max = -__DBL_MAX__;
    for (int i = 0; i < count; i++){
        if (nums[i] > max){
            max = nums[i];
        }
    }

    return max;
}

double min(double *nums, unsigned count){
    
    double min = __DBL_MAX__;
    for (int i = 0; i < count; i++){
        if (nums[i] < max){
            min = nums[i];
        }
    }

    return min;
}

int main(int argc, char **argv) {
    
    int nums_count = 0;

    if (atoi(argv[1])){
        nums_count = argc - 1;
    }
    else{
        nums_count = argc - 2;
    }

    double nums[nums_count];
    int index = 0;
    
    for (int i = argc - nums_count; i < argc; i++){
        nums[index++] = atoi(argv[i]);
    } 

    double sum_nums = 0;
    double max_num = 0;
    double min_num = 0;

    if (nums_count == argc - 1){
        sum_nums = sum(nums, nums_count);
        max_num = max(nums, nums_count);
        min_num = min(nums, nums_count);

        printf("Sum = %lf\n", sum_nums);
        printf("Max = %lf\n", max_num);
        printf("Min = %lf\n", min_num);
        return;

    }

    if (!strcmp(argv[1], "-s")){
        sum_nums = sum(nums, nums_count);
    }
    else if(!strcmp(argv[1], "-m")){
        min_num = min(nums, nums_count);
    }
    else if(!strcmp(argv[1], "-m")){
        max_num = max(nums, nums_count);
    }
    
    
    return 0;
}