import java.util.*;

class Solution {
    public int minimumChanges(String s, int k) {
        int n = s.length();
        
        // 1. Precompute proper divisors for every possible substring length
        List<Integer>[] divisors = new ArrayList[n + 1];
        for (int len = 1; len <= n; len++) {
            divisors[len] = new ArrayList<>();
            for (int d = 1; d < len; d++) {
                if (len % d == 0) {
                    divisors[len].add(d);
                }
            }
        }

        // 2. Precompute cost[i][j]: min changes to make s[i..j] a semi-palindrome
        int[][] cost = new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                cost[i][j] = getSemiPalindromeCost(s, i, j, divisors[j - i + 1]);
            }
        }

        // 3. DP: dp[i][parts] = min changes to split prefix s[0..i-1] into 'parts' substrings
        int INF = 1_000_000;
        int[][] dp = new int[n + 1][k + 1];
        for (int[] row : dp) {
            Arrays.fill(row, INF);
        }
        dp[0][0] = 0;

        for (int parts = 1; parts <= k; parts++) {
            // Each semi-palindrome must have length >= 2
            for (int i = parts * 2; i <= n; i++) {
                for (int prev = (parts - 1) * 2; prev <= i - 2; prev++) {
                    if (dp[prev][parts - 1] != INF) {
                        dp[i][parts] = Math.min(dp[i][parts], dp[prev][parts - 1] + cost[prev][i - 1]);
                    }
                }
            }
        }

        return dp[n][k];
    }

    private int getSemiPalindromeCost(String s, int start, int end, List<Integer> divs) {
        int minChanges = Integer.MAX_VALUE;
        int len = end - start + 1;

        for (int d : divs) {
            int changes = 0;
            // Check each residue group modulo d
            for (int offset = 0; offset < d; offset++) {
                int left = start + offset;
                int right = start + len - d + offset;
                while (left < right) {
                    if (s.charAt(left) != s.charAt(right)) {
                        changes++;
                    }
                    left += d;
                    right -= d;
                }
            }
            minChanges = Math.min(minChanges, changes);
        }

        return minChanges;
    }
}
