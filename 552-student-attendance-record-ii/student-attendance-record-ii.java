class Solution {
    public int checkRecord(int n) {
        long MOD = 1_000_000_007;
       
        long[][] dp = new long[2][3];
        dp[0][0] = 1; 

        for (int i = 0; i < n; i++) {
            long[][] next = new long[2][3];
            for (int a = 0; a < 2; a++) {
                for (int l = 0; l < 3; l++) {
                    if (dp[a][l] == 0) continue;
                    
                    
                    next[a][0] = (next[a][0] + dp[a][l]) % MOD;
                    
                    
                    if (a == 0) {
                        next[1][0] = (next[1][0] + dp[a][l]) % MOD;
                    }
                    
                    
                    if (l < 2) {
                        next[a][l + 1] = (next[a][l + 1] + dp[a][l]) % MOD;
                    }
                }
            }
            dp = next;
        }

        long total = 0;
        for (int a = 0; a < 2; a++) {
            for (int l = 0; l < 3; l++) {
                total = (total + dp[a][l]) % MOD;
            }
        }
        return (int) total;
    }
}
