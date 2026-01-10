class Solution:
    def trap(self, height: List[int]) -> int:
     """
     Calculate the amount of water that can be trapped after raining.

     Args:
         height: List of non-negative integers representing elevation map

     Returns:
         Total amount of trapped rainwater
     """
     n = len(height)

     left_max = [0] * n
     right_max = [0] * n

     left_max[0] = height[0]
     right_max[n - 1] = height[n - 1]

     for i in range(1, n):
         left_max[i] = max(left_max[i - 1], height[i])  

     for i in range(n - 2, -1, -1):
         right_max[i] = max(right_max[i + 1], height[i])  

     total_water = 0
     for i in range(n):
         water_level = min(left_max[i], right_max[i])
         total_water += water_level - height[i]

     return total_water