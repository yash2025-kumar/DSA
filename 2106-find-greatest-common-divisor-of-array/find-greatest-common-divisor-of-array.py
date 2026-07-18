class Solution:
    def findGCD(self, nums: List[int]) -> int:
        min_value = min(nums)
        max_value = max(nums)

        return gcd(max_value, min_value)