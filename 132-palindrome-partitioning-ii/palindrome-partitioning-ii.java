class Solution {
    public int minCut(String s) {
        if(s == null || s.length() <= 1) {
            return 0;
        }

        int n = s.length();
        boolean[][] isPalin = new boolean[n][n];
        int[] dp = new int[n];

        for(int len=1; len<=n; len++) {
            for(int i=0; i<=n-len; i++) {
                int j = i + len - 1;
                if(s.charAt(i) == s.charAt(j)) {
                    if(len <= 2 || isPalin[i+1][j-1]) {
                        isPalin[i][j] = true;
                    }
                }
            }
        }

        for(int i=0; i<n; i++) {
            if(isPalin[0][i]) {
                dp[i] = 0; 
            }
            else {
                int minCuts = i;
                for(int j=0; j<i; j++) {
                    if(isPalin[j+1][i]) {
                        minCuts = Math.min(minCuts, dp[j] + 1);
                    }
                }
                dp[i] = minCuts;
            }
        }

        return dp[n-1];
    }
}