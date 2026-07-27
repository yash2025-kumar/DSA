class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxResult = 0;
        int arraySize = nums.size();

        for(int i=0; i<arraySize; i++) {
            for(int j=i+1; j<arraySize; j++) {
                maxResult = max(maxResult, (nums[i] - 1) * (nums[j] - 1));
            }
        }

        return maxResult;
    }
};