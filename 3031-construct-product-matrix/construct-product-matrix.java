class Solution {
    public int[][] constructProductMatrix(int[][] grid) {
        final int MOD = 12345;

        int rows = grid.length;
        int cols = grid[0].length;

        int[][] productMatrix = new int[rows][cols];

        long suffixProduct = 1;
        for (int i = rows - 1; i >= 0; i--) {
            for (int j = cols - 1; j >= 0; j--) {
                productMatrix[i][j] = (int) suffixProduct;
                suffixProduct = (suffixProduct * grid[i][j]) % MOD;
            }
        }
        long prefixProduct = 1;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                productMatrix[i][j] = (int) ((productMatrix[i][j] * prefixProduct) % MOD);
                prefixProduct = (prefixProduct * grid[i][j]) % MOD;
            }
        }
        return productMatrix;
    }
}