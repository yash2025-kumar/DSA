class Solution:
    def numberOfSubmatrices(self, grid: List[List[str]]) -> int:
        rows, cols = len(grid), len(grid[0])
        sumX = [[0] * (cols + 1) for _ in range(rows + 1)]
        sumY = [[0] * (cols + 1) for _ in range(rows + 1)]

        count = 0

        for i in range(rows):
            for j in range(cols):
                x = 1 if grid[i][j] == 'X' else 0
                y = 1 if grid[i][j] == 'Y' else 0

                sumX[i+1][j+1] = x + sumX[i][j+1] + sumX[i+1][j] - sumX[i][j]
                sumY[i+1][j+1] = y + sumY[i][j+1] + sumY[i+1][j] - sumY[i][j]

                if sumX[i+1][j+1] == sumY[i+1][j+1] and sumX[i+1][j+1] > 0:
                    count += 1

        return count