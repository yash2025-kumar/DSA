class Solution {
    public long maxTotalValue(int[] nums, int k) {
        int maxVal = nums[0];
        int minVal = nums[0];

        for(int num : nums) {
            maxVal = Math.max(maxVal, num);
            minVal = Math.min(minVal, num);
        }

        return (long) k * (maxVal - minVal);
    }
}