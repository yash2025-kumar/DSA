class Solution {
public:
    bool isScramble(string s1, string s2) {
        int n = s1.size();

        int dp[n][n][n + 1];
        memset(dp, -1, sizeof(dp));

        function<bool(int, int, int)> dfs = [&](int i1, int i2, int length) -> bool {
             if (dp[i1][i2][length] != -1) {
                return dp[i1][i2][length] == 1;
             }

             if(length == 1) {
                return dp[i1][i2][length] = (s1[i1] == s2[i2]);
             }

             for (int splitPos = 1; splitPos < length; ++splitPos) {
                if (dfs(i1, i2, splitPos) && dfs(i1 + splitPos, i2 + splitPos, length - splitPos)) {
                     return dp[i1][i2][length] = true;
                }

                if (dfs(i1 + splitPos, i2, length - splitPos) && dfs(i1, i2 + length - splitPos, splitPos)) {
                     return dp[i1][i2][length] = true;
                }
             }
             return dp[i1][i2][length] = false;
        };
        return dfs(0, 0, n);
    }
};