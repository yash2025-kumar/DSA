int countDominantElements(int* nums, int numsSize) {
    if(numsSize == 0) return 0;
    if(numsSize == 1) return 1;

    int count = 0;

    if(nums[0] >= nums[1]) {
        count++;
    }

    for(int i=1; i<numsSize-1; i++) {
        if(2LL * nums[i] >= (long long )nums[i-1] + nums[i+1]) {
            count++;
        }
    }

    if(nums[numsSize-1] >= nums[numsSize-2]) {
        count++;
    }

    return count;
}