import java.util.Arrays;

class Solution {
    public int largestSubmatrix(int[][] matrix) {
        int m = matrix.length;
        int n = matrix[0].length;
        int maxArea = 0;

        // Step 1: Preprocess the matrix to store the height of consecutive 1s above each cell
        for (int i = 1; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 1) {
                    matrix[i][j] += matrix[i - 1][j];
                }
            }
        }

        // Step 2: For each row, sort the heights and calculate the largest rectangle area
        for (int i = 0; i < m; i++) {
            // Create a copy of the current row to sort it without modifying the original preprocessed matrix
            int[] currentRow = matrix[i].clone();
            // Sort the heights in ascending order
            Arrays.sort(currentRow);

            // Iterate through the sorted heights to find the largest area
            for (int j = 0; j < n; j++) {
                int height = currentRow[j];
                // The width of the rectangle for this height will be the number of elements to its right in the sorted array
                int width = n - j;
                maxArea = Math.max(maxArea, height * width);
            }
        }

        return maxArea;
    }
}
