class Solution {
    public int maxRotateFunction(int[] nums) {
        int n = nums.length;
        long totalSum = 0;
        long currentF = 0;

        for(int i = 0; i < n; i++) {
            totalSum += nums[i];
            currentF += (long) i * nums[i];
        }

        long maxF = currentF;

        for (int i = n - 1; i > 0; i--) {
            currentF = currentF + totalSum - (long) n * nums[i];
            maxF = Math.max(maxF, currentF);
        }

        return (int) maxF;
    }
}