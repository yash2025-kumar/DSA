class Solution:
    def maxBuilding(self, n: int, restrictions: List[List[int]]) -> int:
        restrictions.append([1, 0])
        restrictions.append([n , n - 1])
        restrictions.sort()

        for i in range(1, len(restrictions)):
            limit = restrictions[i - 1][1] + (restrictions[i][0] - restrictions[i - 1][0])
            restrictions[i][1] = min(restrictions[i][1], limit)

        for i in range(len(restrictions) - 2, -1, -1):
            limit = restrictions[i + 1][1] + (restrictions[i + 1][0] - restrictions[i][0])
            restrictions[i][1] = min(restrictions[i][1], limit)

        max_height = 0
        for i in range(1, len(restrictions)):
            id1, h1 = restrictions[i - 1]
            id2, h2 = restrictions[i]

            dist = id2 - id1
            gap_max_height = max(h1, h2) + (dist - abs(h1 - h2)) // 2
            max_height = max(max_height, gap_max_height)

        return max_height