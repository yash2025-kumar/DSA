class Solution:
    def stoneGameVIII(self, stones: List[int]) -> int:
        prefix = list(accumulate(stones))

        res = prefix[-1]

        for i in range(len(stones) - 2, 0, -1):
            res = max(res, prefix[i] - res)

        return res
