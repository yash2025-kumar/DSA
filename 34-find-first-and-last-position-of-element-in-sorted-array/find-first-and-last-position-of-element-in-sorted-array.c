/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 int firstOccurence(int* nums, int numsSize, int target) {
    int l = 0, h = numsSize - 1, ans = -1;
    while(l <= h) {
        int mid = (l + h) / 2;
        if(nums[mid] == target) {
            ans = mid;
            h = mid - 1;
        }
        else if(nums[mid] < target) l = mid + 1;
        else h = mid - 1;
    }
    return ans;
 }

 int lastOccurence(int* nums, int numsSize, int target) {
    int l = 0, h = numsSize - 1, ans = -1;
    while(l <= h) {
        int mid = (l + h) / 2;
        if(nums[mid] == target) {
            ans = mid;
            l = mid + 1;
        }
        else if(nums[mid] < target) {
            l = mid + 1;
        }
        else h = mid - 1;
    }
    return ans;
 }

int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    int *res = malloc(2*sizeof(int));
    *returnSize = 2;
    int a = firstOccurence(nums, numsSize, target);
    int b = lastOccurence(nums, numsSize, target);
    res[0] = a;
    res[1] = b;
    return res;
}