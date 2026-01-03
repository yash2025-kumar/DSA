class Solution {
    public int numOfWays(int n) {
        final int MOD = (int) 1e9 + 7;

        long twoColorPattern = 6;
        long threeColorPattern = 6;

        for(int row = 0; row < n - 1; row++) {
            long nextTwoColorPattern = (3 * twoColorPattern + 2 * threeColorPattern) % MOD;
            long nextThreeColorPattern = (2 * twoColorPattern + 2 * threeColorPattern) % MOD;

            twoColorPattern = nextTwoColorPattern;
            threeColorPattern = nextThreeColorPattern;
        }
        return (int) ((twoColorPattern + threeColorPattern) % MOD);
    }
}