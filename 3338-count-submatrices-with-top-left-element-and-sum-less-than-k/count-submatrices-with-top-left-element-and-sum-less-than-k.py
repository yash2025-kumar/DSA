class Solution(object):
    def countSubmatrices(self, grid: list[list[int]], k: int) -> int:
        """
        :type grid: List[List[int]]
        :type k: int
        :rtype: int
        """
        m = len(grid)
        n = len(grid[0])
        result = 0

        # Calculate 2D prefix sums in-place and count valid submatrices
        for i in range(m):
            for j in range(n):
                # Add sum from above
                if i > 0:
                    grid[i][j] += grid[i-1][j]
                # Add sum from left
                if j > 0:
                    grid[i][j] += grid[i][j-1]
                # Subtract overlap if both above and left sums were added
                if i > 0 and j > 0:
                    grid[i][j] -= grid[i-1][j-1]
                
                # Check if the current submatrix sum is less than or equal to k
                if grid[i][j] <= k:
                    result += 1
        
        return result


        