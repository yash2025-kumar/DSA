void moveZeroes(int* nums, int numsSize) {
    int nonZero = 0;
    for(int i=0; i<numsSize; i++) {
        if(nums[i] != 0) {
            nums[nonZero] = nums[i];
            nonZero++;
        }
        
    }
    for(int i=nonZero; i<numsSize; i++) {
        nums[i] = 0;
    }
}