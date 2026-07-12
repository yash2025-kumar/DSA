class Solution:
    def arrayRankTransform(self, arr: List[int]) -> List[int]:
        sorted_unique = sorted(set(arr))

        rank_map = {val: rank for rank, val in enumerate(sorted_unique, 1)}

        return [rank_map[num] for num in arr]