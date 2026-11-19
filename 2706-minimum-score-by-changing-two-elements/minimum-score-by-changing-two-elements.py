class Solution:
    def minimizeSum(self, nums: List[int]) -> int:
        nums.sort()
        change_two_smallest = nums[-1] - nums[2]
        change_two_largest = nums[-3] - nums[0]
        change_one_each = nums[-2] - nums[1]

        return min(change_two_smallest, change_two_largest, change_one_each)
