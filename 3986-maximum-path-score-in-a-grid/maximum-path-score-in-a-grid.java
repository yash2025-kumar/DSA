class Solution {
    private int[][] grid;
    private Integer[][][] memo;
    private final int INF = 1 << 30;

    public int maxPathScore(int[][] grid, int k) {
        this.grid = grid;
        int m = grid.length;
        int n = grid[0].length;
        this.memo = new Integer[m][n][k + 1];

        int result = dfs(m - 1, n - 1, k);
        return result < 0 ? -1 : result;
    }

    private int dfs(int i, int j, int k) {
        if(i < 0 || j < 0 || k < 0) return -INF;

        if(i == 0 && j == 0) return 0;

        if(memo[i][j][k] != null) return memo[i][j][k];

        int currentScore = grid[i][j];
        int remainingK = k;

        if (grid[i][j] > 0) {
            remainingK--;
        }

        int pathUp = dfs(i - 1, j, remainingK);
        int pathLeft = dfs(i, j - 1, remainingK);

        int res = currentScore + Math.max(pathUp, pathLeft);
        memo[i][j][k] = res;
        return res;
    }
}