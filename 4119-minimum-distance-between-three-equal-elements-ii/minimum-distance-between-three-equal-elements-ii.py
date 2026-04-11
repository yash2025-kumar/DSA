from collections import defaultdict
import math

class Solution:
    def minimumDistance(self, nums: list[int]) -> int:
        # Group indices for each value in the array
        index_groups = defaultdict(list)
        for idx, val in enumerate(nums):
            index_groups[val].append(idx)
        
        min_total_dist = float('inf')
        
        # Iterate through the grouped indices
        for indices in index_groups.values():
            # We need at least 3 occurrences to form a triplet
            if len(indices) < 3:
                continue
            
            # Check every consecutive triplet (i, j, k)
            # Based on simplified formula: dist = 2 * (k - i)
            for h in range(len(indices) - 2):
                dist = 2 * (indices[h + 2] - indices[h])
                if dist < min_total_dist:
                    min_total_dist = dist
                    
        return min_total_dist if min_total_dist != float('inf') else -1

        