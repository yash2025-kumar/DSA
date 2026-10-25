/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* selfDividingNumbers(int left, int right, int* returnSize) {
    int* result = (int*)malloc((right - left + 1) * sizeof(int));
    int count = 0;
    for(int num=left; num<=right; num++) {
        int temp = num;
        bool isSelfDividing = true;
        while(temp > 0) {
            int digit = temp % 10;
            if(digit == 0 || num % digit != 0) {
                isSelfDividing = false;
                break;
            }
            temp /= 10;
        }
        if(isSelfDividing) {
            result[count++] = num;
        }
    }
    *returnSize = count;
    return result;
}