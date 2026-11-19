#include <stdlib.h>


int cmp(const void* a, const void* b) {
    int int_a = *(const int*)a;
    int int_b = *(const int*)b;
    return (int_a > int_b) - (int_a < int_b);
}

int minimizeSum(int* nums, int numsSize) {
    
    qsort(nums, numsSize, sizeof(int), cmp);

    
    int opt1 = nums[numsSize - 1] - nums[2];
    
    
    int opt2 = nums[numsSize - 3] - nums[0];
    
    
    int opt3 = nums[numsSize - 2] - nums[1];

    
    int ans = opt1 < opt2 ? opt1 : opt2;
    return ans < opt3 ? ans : opt3;
}
