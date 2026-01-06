class Solution {
    private boolean solutionFound;

    private char[][] board;

    private List<Integer> emptyCells = new ArrayList<>();

    private boolean[][] rowUsed = new boolean[9][9];

    private boolean[][] colUsed = new boolean[9][9];

    private boolean[][][] blockUsed = new boolean[3][3][9];

    public void solveSudoku(char[][] board) {
        this.board = board;

        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                if (board[row][col] == '.') {
                    emptyCells.add(row * 9 + col);
                }
                else {
                     int digit = board[row][col] - '1';
                     rowUsed[row][digit] = true;
                     colUsed[col][digit] = true;
                     blockUsed[row / 3][col / 3][digit] = true;
                }
            }
        }
        backtrack(0);
    }
    private void backtrack(int emptyCellIndex) {
        if (emptyCellIndex == emptyCells.size()) {
            solutionFound = true;
            return;
        }
        int position = emptyCells.get(emptyCellIndex);
        int row = position / 9;
        int col = position % 9;

        for (int digit = 0; digit < 9; digit++) {
            if (!rowUsed[row][digit] && 
                !colUsed[col][digit] && 
                !blockUsed[row / 3][col / 3][digit]) {

                    rowUsed[row][digit] = true;
                    colUsed[col][digit] = true;
                    blockUsed[row / 3][col / 3][digit] = true;
                    board[row][col] = (char) (digit + '1'); 

                    backtrack(emptyCellIndex + 1);

                    rowUsed[row][digit] = false;
                    colUsed[col][digit] = false;
                    blockUsed[row / 3][col / 3][digit] = false;
                }

                if(solutionFound) {
                    return;
                }
        }
    }
}