class Solution {
private:
    long long mod = 1e9 + 7;
    vector<vector<long long>> table;

    void generatePascalTriangle(int n) {
        table.assign(n+1, vector<long long>(n+1,1));
        for(int i=2; i<=n; i++) {
            for(int j=1; j<i; j++) {
                table[i][j] = (table[i-1][j-1] + table[i-1][j]) % mod;
            }
        }
    }

    long long dfs(const vector<int>& nums) {
        if(nums.size() <= 2) return 1;
        int root = nums[0];
        vector<int> left, right;

        for(size_t i=1; i<nums.size(); i++) {
            if(nums[i] < root) {
                left.push_back(nums[i]);
            } else {
                right.push_back(nums[i]);
            }
        }

        long long left_ways = dfs(left);
        long long right_ways = dfs(right);

        long long total_ways = table[left.size() + right.size()][left.size()];

        return (((total_ways * left_ways) % mod) * right_ways) % mod;
    }

public:
    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        generatePascalTriangle(n);
        long long ans = dfs(nums);
        return (ans - 1 + mod) % mod;
    }
};