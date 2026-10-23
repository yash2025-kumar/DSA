class Solution {
    public int sortPermutation(int[] nums) {
        int ans = -1;
        boolean isSorted = true;

        for(int i=0; i<nums.length; i++) {
            if(nums[i] != i) {
                ans &= nums[i];
                isSorted = false;
            }
        }

        return isSorted ? 0 : ans;
    }
}