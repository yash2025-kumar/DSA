class Solution:
    def separateSquares(self, squares: List[List[int]]) -> float:
        tot_area = 0
        diff = defaultdict(int)
        for _, y, l in squares:
            tot_area += l * l
            diff[y] += l
            diff[y + l] -= l

        area = sum_l = 0
        for y, y2 in pairwise(sorted(diff)):
            sum_l += diff[y]
            tmp = area + sum_l * (y2 - y)
            if tmp * 2 >= tot_area:
                return (y * sum_l * 2 + tot_area - area * 2) / (sum_l * 2)
            area = tmp