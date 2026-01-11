class Solution {
    public int maximalRectangle(char[][] matrix) {
        int numCols = matrix[0].length;
        int[] heights = new int[numCols];
        int maxArea = 0;

        for(char[] currentRow : matrix) {
            for (int col = 0; col < numCols; col++) {
                if(currentRow[col] == '1') {
                    heights[col] += 1;
                }
                else {
                    heights[col] = 0;
                }
            }
            maxArea = Math.max(maxArea, largestRectangleArea(heights));
        }
        return maxArea;
    }

    private int largestRectangleArea(int[] heights) {
        int maxArea = 0;
        int n = heights.length;
        Deque<Integer> stack = new ArrayDeque<>();

        int[] leftBoundary = new int[n];
        int[] rightBoundary = new int[n];

        Arrays.fill(rightBoundary, n);

        for(int i = 0; i < n; i++) {
            while (!stack.isEmpty() && heights[stack.peek()] >= heights[i]) {
                rightBoundary[stack.pop()] = i;
            }

            leftBoundary[i] = stack.isEmpty() ? -1 : stack.peek();
            stack.push(i);
        }
        for(int i = 0; i < n; i++) {
            int width = rightBoundary[i] - leftBoundary[i] - 1;
            int area = heights[i] * width;
            maxArea = Math.max(maxArea, area);
        }
        return maxArea;
    }
}