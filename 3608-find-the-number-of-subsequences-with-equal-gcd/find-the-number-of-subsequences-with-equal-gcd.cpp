class Solution {
public:
    int subsequencePairCount(vector<int>& nums) {
        int maxNum = *max_element(nums.begin(), nums.end());
        vector<vector<vector<int>>> mem(
            nums.size(), vector<vector<int>>(maxNum + 1, vector<int>(maxNum + 1, -1)));
        return solve(nums, 0, 0, 0, mem);
    }

    private:
        static constexpr  int MOD = 1'000'000'007;

        int solve(const vector<int>& nums, int i, int g1, int g2, vector<vector<vector<int>>>& mem) {
            if (i == nums.size()) return g1 > 0 && g1 == g2 ? 1 : 0;
            if (mem[i][g1][g2] != -1) return mem[i][g1][g2];

            long long ans = solve(nums, i + 1, g1, g2, mem);

            ans = (ans + solve(nums, i + 1, g1 == 0 ? nums[i] : std::gcd(g1, nums[i]), g2, mem)) % MOD;

            ans = (ans + solve(nums, i + 1, g1, g2 == 0 ? nums[i] : std::gcd(g2, nums[i]), mem)) % MOD;

            return mem[i][g1][g2] = ans;
        }
};