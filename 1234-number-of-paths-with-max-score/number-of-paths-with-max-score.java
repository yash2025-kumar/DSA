class Solution {
    private List<String> board;
    private int boardSize;

    private int[][] maxScore;
    private int[][] pathCount;

    private final int MOD = (int) 1e9 + 7;

    public int[] pathsWithMaxScore(List<String> board) {
        this.boardSize = board.size();
        this.board = board;

        maxScore = new int[boardSize][boardSize];
        pathCount = new int[boardSize][boardSize];

        for(int[] row : maxScore) {
            Arrays.fill(row, -1);
        }

        maxScore[boardSize - 1][boardSize - 1] = 0;
        pathCount[boardSize - 1][boardSize - 1] = 1;

        for(int row = boardSize - 1; row >= 0; row--) {
            for (int col = boardSize - 1; col >= 0; col--) {
                updateFromNextCell(row, col, row + 1, col);
                updateFromNextCell(row, col, row, col + 1);
                updateFromNextCell(row, col, row + 1, col + 1);

                if(maxScore[row][col] != -1) {
                    char currentChar = board.get(row).charAt(col);
                    if(currentChar >= '0' && currentChar <= '9') {
                        maxScore[row][col] += (currentChar - '0');
                    }
                }
            }
        }

        int[] result = new int[2];

        if(maxScore[0][0] != -1) {
            result[0] = maxScore[0][0];
            result[1] = pathCount[0][0];
        }

        return result;
    }

    private void updateFromNextCell(int currentRow, int currentCol, int nextRow, int nextCol) {
        if (nextRow >= boardSize || nextCol >= boardSize) {
            return;
        }

        if(maxScore[nextRow][nextCol] == -1) {
            return;
        }

        char currentChar = board.get(currentRow).charAt(currentCol);
        if (currentChar == 'X' || currentChar == 'S') {
            return;
        }

        if (maxScore[nextRow][nextCol] > maxScore[currentRow][currentCol]) {
            maxScore[currentRow][currentCol] = maxScore[nextRow][nextCol];
            pathCount[currentRow][currentCol] = pathCount[nextRow][nextCol];
        } else if(maxScore[nextRow][nextCol] == maxScore[currentRow][currentCol]) {
            pathCount[currentRow][currentCol] = (pathCount[currentRow][currentCol] + pathCount[nextRow][nextCol]) % MOD;
        }
    }
}