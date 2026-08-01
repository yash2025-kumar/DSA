class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();

        if(n % 2 == 0) return true;

        vector<int> dp = nums;

        for(int diff = 1; diff < n; diff++) {
            for(int i = 0; i + diff < n; i++) {
                int j = i + diff;
                dp[i] = max(nums[i] - dp[i + 1], nums[j] - dp[i]);
            }
        }

        return dp[0] >= 0;
    }
};