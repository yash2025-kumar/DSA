#include <stdbool.h>
#include <limits.h>

// Helper function to check if the array is non-decreasing
bool isNonDecreasing(int* arr, int n) {
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[i - 1]) {
            return false;
        }
    }
    return true;
}

int minimumPairRemoval(int* nums, int numsSize) {
    int ops = 0;
    int n = numsSize;

    while (!isNonDecreasing(nums, n)) {
        int minSum = INT_MAX;
        int minIndex = 0;

        // Find the adjacent pair with the minimum sum
        for (int i = 0; i < n - 1; i++) {
            int currentSum = nums[i] + nums[i + 1];
            if (currentSum < minSum) {
                minSum = currentSum;
                minIndex = i;
            }
        }

        // Replace the pair with their sum at minIndex
        nums[minIndex] = minSum;

        // Shift elements to the left to remove nums[minIndex + 1]
        for (int i = minIndex + 1; i < n - 1; i++) {
            nums[i] = nums[i + 1];
        }

        n--; // Array size decreases by 1
        ops++;
    }

    return ops;
}
