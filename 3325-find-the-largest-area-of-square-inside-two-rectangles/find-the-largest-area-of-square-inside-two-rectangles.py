from typing import List
from itertools import combinations

class Solution:
    def largestSquareArea(self, bottomLeft: List[List[int]], topRight: List[List[int]]) -> int:
        max_square_area = 0

        for ((x1, y1), (x2, y2)), ((x3, y3), (x4, y4)) in combinations(
            zip(bottomLeft, topRight), 2
        ):
            
            intersection_width = min(x2, x4) - max(x1, x3)
            intersection_height = min(y2, y4) - max(y1, y3)

            max_square_side = min(intersection_width, intersection_height)

            if max_square_side > 0:
                square_area = max_square_side * max_square_side
                max_square_area = max(max_square_area, square_area)

        return max_square_area