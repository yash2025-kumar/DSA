class Solution {
    public int numDecodings(String s) {
        int n = s.length();
        int dp1 = 1;
        int dp2 = 0;

        for(int i = n - 1; i >= 0; i--) {
            int currentWays = 0;
            char currentChar = s.charAt(i);

            if(currentChar != '0') {
                currentWays += dp1;
            }

            if(i + 1 < n) {
                char nextChar = s.charAt(i + 1);
                if (currentChar == '1' || (currentChar == '2' && nextChar < '7')) {
                    currentWays += dp2;
                }
            }
            
            dp2 = dp1;
            dp1 = currentWays;
        }
        return dp1;
    }
}