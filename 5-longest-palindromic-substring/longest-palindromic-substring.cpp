class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();

        vector<vector<bool>> dp(n, vector<bool>(n, true));

        int startIndex = 0;
        int maxLength = 1;

        for(int i = n - 2; i >= 0; --i) {
            for(int j = i + 1; j < n; ++j) {
                dp[i][j] = false;

                if(s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j - 1];

                    if(dp[i][j] && maxLength < j - i + 1) {
                        maxLength = j - i + 1;
                        startIndex = i;
                    }
                }
            }
        }
        return s.substr(startIndex, maxLength);
    }
};