import math
from typing import List


class Solution:

  def minimumSumSubarray(self, nums: List[int], l: int, r: int) -> int:
    min_sum = math.inf
    n = len(nums)

    # Check every allowed subarray length from l to r
    for window_size in range(l, r + 1):
      # Calculate the sum of the initial window
      current_sum = sum(nums[:window_size])
      if current_sum > 0:
        min_sum = min(min_sum, current_sum)

      # Slide the window across the rest of the array
      for i in range(window_size, n):
        current_sum += nums[i] - nums[i - window_size]
        if current_sum > 0:
          min_sum = min(min_sum, current_sum)

    return -1 if min_sum == math.inf else min_sum

        