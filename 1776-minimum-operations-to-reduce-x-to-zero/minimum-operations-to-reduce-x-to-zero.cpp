class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        // Calculate the target sum for the middle subarray
        // We want to find the longest subarray with sum = totalSum - x
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        int targetSum = totalSum - x;

        // Hash map to store the first occurrence of each prefix sum
        // Key: prefix sum, Value: index where this sum first occurred
        unordered_map<int, int> prefixSumIndex = {{0, -1}};

        // Track the maximum length of subarray with target sum
        int maxLength = -1;
        int currentPrefixSum = 0;
        int n = nums.size();

        // Iterate through the array to find the longest subarray with target sum
        for (int i = 0; i < n; ++i) {
            // Update current prefix sum
            currentPrefixSum += nums[i];

            // Store the first occurrence of this prefix sum
            if (prefixSumIndex.find(currentPrefixSum) == prefixSumIndex.end()) {
                prefixSumIndex[currentPrefixSum] = i;
            }

            // Check if there exists a subarray ending at index i with sum = targetSum
            // This happens when (currentPrefixSum - targetSum) exists in our map
            if (prefixSumIndex.find(currentPrefixSum - targetSum) != prefixSumIndex.end()) {
                // Update the maximum length if we found a longer subarray
                maxLength = max(maxLength, i - prefixSumIndex[currentPrefixSum - targetSum]);
            }
        }

        // If no valid subarray found, return -1
        // Otherwise, return the minimum operations (elements from both ends)
        return maxLength == -1 ? -1 : n - maxLength;
    }
};
