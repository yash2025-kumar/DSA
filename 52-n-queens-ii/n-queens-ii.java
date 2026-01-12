class Solution {
    private int n;
    private int ans;
    private boolean[] cols = new boolean[10];
    private boolean[] dg = new boolean[20];
    private boolean[] udg = new boolean[20];

    public int totalNQueens(int n) {
        this.n = n;
        dfs(0);
        return ans;
    }

    private void dfs(int row) {
        if(row == n) {
            ++ans;
            return;
        }

        for(int col = 0; col < n; col++) {
            int mainDiagonal = row + col;
            int antiDiagonal = row - col + n;

            if(cols[col] || dg[mainDiagonal] || udg[antiDiagonal]) {
                continue;
            }

            cols[col] = true;
            dg[mainDiagonal] = true;
            udg[antiDiagonal] = true;

            dfs(row + 1);

            cols[col] = false;
            dg[mainDiagonal] = false;
            udg[antiDiagonal] = false;
        }
    }
}