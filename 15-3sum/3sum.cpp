class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        int size = nums.size();

         for (int first = 0; first < size - 2 && nums[first] <= 0; ++first) {
            if (first > 0 && nums[first] == nums[first - 1]) {
                continue;
            }
            int left = first + 1;
            int right = size - 1;

            while (left < right) {
                int currentSum = nums[first] + nums[left] + nums[right];

                if(currentSum < 0) {
                    ++left;
                }
                else if (currentSum > 0) {
                    --right;
                }
                else {
                    result.push_back({nums[first], nums[left], nums[right]});
                    ++left;
                    --right;

                    while (left < right && nums[left] == nums[left - 1]) {
                        ++left;
                    }

                    while (left < right && nums[right] == nums[right + 1]) {
                        --right;
                    }
                }
            }
         }
         return result;
    }
};