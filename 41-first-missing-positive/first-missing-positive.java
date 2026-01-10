class Solution {
    public int firstMissingPositive(int[] nums) {
        int arrayLength = nums.length;

        for(int currentIndex = 0; currentIndex < arrayLength; currentIndex++) {
            while(nums[currentIndex] > 0 &&
                  nums[currentIndex] <= arrayLength &&
                  nums[currentIndex] != nums[nums[currentIndex] - 1]) {
              int targetIndex = nums[currentIndex] - 1;
              swap(nums, currentIndex, targetIndex);
                  }
        }
    
         for (int index = 0; index < arrayLength; index++) {
            if (nums[index] != index + 1) {
                return index + 1;
            }
         }
         return arrayLength + 1;
    }

    private void swap(int[] nums, int firstIndex, int secondIndex) {
        int temp = nums[firstIndex];
        nums[firstIndex] = nums[secondIndex];
        nums[secondIndex] = temp;
    }
}