class Solution:
    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        if len(s1) + len(s2) != len(s3):
            return False

        if len(s1) > len(s2):
            s1, s2 = s2, s1

        m, n = len(s1), len(s2)
        dp = [False] * (n + 1)
        dp[0] = True

        for j in range(1, n + 1):
            dp[j] = dp[j - 1] and s2[j - 1] == s3[j - 1]

        for i in range(1, m + 1):
            dp[0] = dp[0] and s1[i - 1] == s3[i - 1]
            for j in range(1, n + 1):
                up = dp[j] and s1[i - 1] == s3[i + j - 1]
                left = dp[j - 1] and s2[j - 1] == s3[i + j - 1]
                dp[j] = up or left

        return dp[n]