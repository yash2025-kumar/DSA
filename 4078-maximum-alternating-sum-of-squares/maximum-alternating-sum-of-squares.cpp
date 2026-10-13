class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        for(int& x : nums) {
            long long val = x;
            x = val * val;
        }
        sort(nums.begin(), nums.end());
        long long ans = 0;
        int n = nums.size();
        int m = n / 2;

        for(int i=0; i<m; i++) {
            ans -= nums[i];
        }
        for(int i=m; i<n; i++) {
            ans += nums[i];
        }

        return ans;
    }
};


