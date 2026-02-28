class Solution {
    public int concatenatedBinary(int n) {
        final int MOD = 1_000_000_007;
        long ans = 0;
        int shift = 0;

        for(int i = 1; i <= n; i++) {
             if ((i & (i - 1)) == 0) {
                shift++;
            }

            ans = ((ans << shift) | i) % MOD;
        }

        return (int) ans;
    }
}