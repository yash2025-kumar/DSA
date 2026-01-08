class Solution:
    def jump(self, nums: List[int]) -> int:
      jump_count = 0
      current_jump_end = 0
      farthest_reachable = 0

      for i in range(len(nums) - 1):
        farthest_reachable = max(farthest_reachable, i + nums[i])

        if i == current_jump_end:
            jump_count += 1
            current_jump_end = farthest_reachable
            
      return jump_count 