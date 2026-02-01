class Solution {
    public int minimumCost(int[] nums) {
       int firstElement = nums[0];

       int smallest = 100;
       int secondSmallest = 100;

       for(int i = 1; i < nums.length; i++) {
          if(nums[i] < smallest) {
            secondSmallest = smallest;
            smallest = nums[i];
          }
          else if(nums[i] < secondSmallest) {
            secondSmallest = nums[i];
          }
       }
       return firstElement + smallest + secondSmallest;  
    }
}