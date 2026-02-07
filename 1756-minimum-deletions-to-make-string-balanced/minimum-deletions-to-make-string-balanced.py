class Solution:
    def minimumDeletions(self, s: str) -> int:
      n = len(s)

      dp = [0] * (n + 1)

      b_count = 0

      for i, char in enumerate(s, 1):
          if char == 'b':
              dp[i] = dp[i -1]
              b_count += 1
          else:
              dp[i] = min(dp[i - 1] + 1, b_count)

      return dp[n]

          