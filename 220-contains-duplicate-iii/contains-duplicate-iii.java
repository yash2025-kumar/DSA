class Solution {
    public boolean containsNearbyAlmostDuplicate(int[] nums, int indexDiff, int valueDiff) {
        TreeSet<Long> slidingWindow = new TreeSet<>();
      
        // Iterate through each element in the array
        for (int currentIndex = 0; currentIndex < nums.length; currentIndex++) {
            // Find the smallest element in the window that is >= (nums[i] - valueDiff)
            // This helps us check if there exists an element in range [nums[i] - valueDiff, nums[i] + valueDiff]
            Long ceilingValue = slidingWindow.ceiling((long) nums[currentIndex] - (long) valueDiff);
          
            // If such element exists and it's <= (nums[i] + valueDiff), 
            // then we found two elements satisfying the value difference condition
            if (ceilingValue != null && ceilingValue <= (long) nums[currentIndex] + (long) valueDiff) {
                return true;
            }
          
            // Add current element to the sliding window
            slidingWindow.add((long) nums[currentIndex]);
          
            // Maintain the sliding window size by removing the element that's now outside the index range
            // This ensures all elements in the window satisfy the index difference constraint
            if (currentIndex >= indexDiff) {
                slidingWindow.remove((long) nums[currentIndex - indexDiff]);
            }
        }
      
        // No pair of elements found that satisfies both conditions
        return false;
    }
}