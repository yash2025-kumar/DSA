import java.util.*;

class Solution {
    private static final int MOD = 1_000_000_007;

    public int xorAfterQueries(int[] nums, int[][] queries) {
        int n = nums.length;
        int T = (int) Math.sqrt(n);
        
        // Groups for small k to avoid redundant passes
        List<int[]>[] smallKQueries = new List[T];
        for (int i = 1; i < T; i++) smallKQueries[i] = new ArrayList<>();

        long[] finalFactors = new long[n];
        Arrays.fill(finalFactors, 1);

        for (int[] q : queries) {
            int l = q[0], r = q[1], k = q[2], v = q[3];
            if (k >= T) {
                // Large k: Direct update
                for (int i = l; i <= r; i += k) {
                    nums[i] = (int) ((1L * nums[i] * v) % MOD);
                }
            } else {
                // Small k: Store for bulk processing
                smallKQueries[k].add(q);
            }
        }

        // Process small k groups using a jump-based difference array
        for (int k = 1; k < T; k++) {
            if (smallKQueries[k].isEmpty()) continue;
            
            long[] diff = new long[n + k];
            Arrays.fill(diff, 1);
            
            for (int[] q : smallKQueries[k]) {
                int l = q[0], r = q[1], v = q[3];
                diff[l] = (diff[l] * v) % MOD;
                int nextBoundary = l + ((r - l) / k + 1) * k;
                if (nextBoundary < n + k) {
                    diff[nextBoundary] = (diff[nextBoundary] * modInverse(v)) % MOD;
                }
            }

            // Propagate prefix products with stride k
            for (int i = 0; i < n; i++) {
                if (i >= k) diff[i] = (diff[i] * diff[i - k]) % MOD;
                nums[i] = (int) ((1L * nums[i] * diff[i]) % MOD);
            }
        }

        int xorSum = 0;
        for (int val : nums) xorSum ^= val;
        return xorSum;
    }

    private long modInverse(long n) {
        return power(n, MOD - 2);
    }

    private long power(long base, long exp) {
        long res = 1;
        base %= MOD;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }
        return res;
    }
}
