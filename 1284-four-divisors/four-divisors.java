class Solution {
    public int sumFourDivisors(int[] nums) {
        int totalSum = 0;

        for(int number : nums) {
            totalSum += getSumofFourDivisors(number);
        }
        return totalSum;
    }

    private int getSumofFourDivisors(int number) {
        int divisorCount = 2;
        int divisorSum = number + 1;

        for (int i = 2; i <= number / i; i++) {
            if (number % i == 0) {
                ++divisorCount;
                divisorSum += i;

                if(i * i != number) {
                    ++divisorCount;
                    divisorSum += number / i;
                }
            }
        }
        return divisorCount == 4 ? divisorSum : 0;
    }
}
              