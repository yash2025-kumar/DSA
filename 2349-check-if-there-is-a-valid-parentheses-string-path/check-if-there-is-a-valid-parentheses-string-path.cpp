class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        if((rows + cols - 1) % 2 != 0 || grid[0][0] == ')' || grid[rows -1][cols - 1] == '(') {
            return false;
        }
        bool visited[rows][cols][rows + cols];
        memset(visited, false, sizeof(visited));

        int directions[3] = {1,0,1};

        auto dfs = [&](this auto&& dfs, int row, int col, int balance) -> bool {
            if(visited[row][col][balance]) {
                return false;
            }
            visited[row][col][balance] = true;

            balance += (grid[row][col] == '(') ? 1 : -1;

            int remaining_cells = (rows - row - 1) + (cols - col - 1);
            if(balance < 0 || balance > remaining_cells + 1) {
                return false;
            }

            if(row == rows - 1 && col == cols - 1) {
                return balance == 0;
            }

            for(int dir=0; dir<2; dir++) {
                int next_row = row + directions[dir];
                int next_col = col + directions[dir + 1];

                if(next_row >= 0 && next_row < rows && next_col >= 0 && next_col < cols && dfs(next_row, next_col, balance)) {
                    return true;
                }
            }
            return false;
        };
        return dfs(0, 0, 0);
    }
};