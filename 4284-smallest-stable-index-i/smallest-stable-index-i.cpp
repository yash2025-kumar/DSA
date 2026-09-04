class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

        for(int i=0; i<n; i++) {
            int max_val = INT_MIN;
            for(int p=0; p<=i; p++) {
                max_val = max(max_val, nums[p]);
            }

            int min_val = INT_MAX;
            for(int p=i; p<n; p++) {
                min_val = min(min_val, nums[p]);
            }

            if(max_val - min_val <= k) {
                return i;
            }
        }

        return -1;
    }
};