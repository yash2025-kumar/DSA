/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArrayByParity(int* nums, int numsSize, int* returnSize) {
    int l = 0;
    int r = numsSize - 1;
    
    while(l < r) {
        if(nums[l] % 2 == 0) {
            l++;
        }
        else if(nums[r] % 2 == 1) {
            r--;
        }
        else {
            int temp = nums[l];
            nums[l] = nums[r];
            nums[r] = temp;
            l++;
            r--;
        }
    }
    *returnSize = numsSize;
    return nums; 
}
           
            
        