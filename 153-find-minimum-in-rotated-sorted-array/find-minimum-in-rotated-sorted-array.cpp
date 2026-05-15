class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right = n - 1;
        int firstTrueIndex = -1;

        while(left <= right) {
            int mid = left + (right - left) / 2;

            if(nums[mid] <= nums[n - 1]) {
                firstTrueIndex = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }

        }

        return nums[firstTrueIndex];
    }
};