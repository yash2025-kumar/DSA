class Solution:
    def largestInteger(self, nums: List[int], k: int) -> int:
        n = len(nums)
        counts = Counter(nums)

        if k == n:
            return max(nums)

        if k == 1:
            unique_nums = [num for num, count in counts.items() if count == 1]
            return max(unique_nums) if unique_nums else -1

        ans = -1
        if counts[nums[0]] == 1:
            ans = max(ans, nums[0]) 
        if counts[nums[-1]] == 1:
            ans = max(ans, nums[-1])

        return ans