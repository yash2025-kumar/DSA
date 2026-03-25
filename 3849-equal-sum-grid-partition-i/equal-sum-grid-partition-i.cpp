class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int64_t totalSum = 0;
        for(const auto& row : grid) {
            totalSum = std::accumulate(row.cbegin(), row.cend(), totalSum);
        }

        if(totalSum % 2 != 0) {
            return false;
        }

        int64_t targetSum = totalSum / 2;

        int64_t currentSum = 0;
        for (int i = 0; i < m - 1; i++) {
            currentSum = std::accumulate(grid[i].cbegin(), grid[i].cend(), currentSum);
            if(currentSum == targetSum) {
                return true;
            }
        } 

        currentSum = 0;
        for (int j = 0; j < n - 1; j++) {
            for(int i = 0; i < m; i++) {
                currentSum += grid[i][j];
            }
            if (currentSum == targetSum) {
                return true;
            }
        }
        return false;
    }
};