class Solution:
    def stoneGameIII(self, stoneValue: List[int]) -> str:
        n = len(stoneValue)
        memo = {}

        def dp(i):
            if i >= n:
                return 0
            if i in memo:
                return memo[i]

            res = -float('inf')
            current_sum = 0

            for k in range(1, 4):
                if i + k - 1 < n:
                    current_sum += stoneValue[i + k - 1]
                    res = max(res, current_sum - dp(i + k))

            memo[i] = res
            return res

        diff = dp(0)
        if diff > 0:
            return "Alice"
        elif diff < 0:
            return "Bob"
        else:
            return "Tie"
