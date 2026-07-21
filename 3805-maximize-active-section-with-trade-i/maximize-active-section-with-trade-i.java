class Solution {
    public int maxActiveSectionsAfterTrade(String s) {
        int totalOnes = 0;
        int i = 0;
        int prevZeroLen = Integer.MIN_VALUE;
        int maxGain = 0;

        while(i < s.length()) {
            int j = i;
            while(j < s.length() && s.charAt(j) == s.charAt(i)) {
                j++;
            }
            int curLen = j - i;

            if(s.charAt(i) == '1') {
                totalOnes += curLen;
            } else {
                maxGain = Math.max(maxGain, prevZeroLen + curLen);
                prevZeroLen = curLen;
            }
            i = j;
        }

        return totalOnes + maxGain;
    }
}