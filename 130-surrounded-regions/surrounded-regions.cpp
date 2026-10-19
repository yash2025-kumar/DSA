class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();
        int directions[5] = {-1,0,1,0,-1};

        function<void(int, int)> depthFirstSearch = [&](int row, int col) {
            if(row < 0 || row >= rows || col < 0 || col >= cols || board[row][col] != 'O') {
                return;
            }

            board[row][col] = '.';
            for(int k=0; k<4; k++) {
                depthFirstSearch(row + directions[k], col + directions[k+1]);
            }
        };

        for(int i=0; i<rows; i++) {
            depthFirstSearch(i,0);
            depthFirstSearch(i, cols - 1);
        }

        for(int j=1; j<cols-1; j++) {
            depthFirstSearch(0,j);
            depthFirstSearch(rows-1, j);
        }

        for(auto& row : board) {
            for(auto&  cell : row) {
                if(cell == '.') {
                    cell = 'O';
                } else if(cell == 'O') {
                    cell = 'X';
                }
            }
        }
    }
};