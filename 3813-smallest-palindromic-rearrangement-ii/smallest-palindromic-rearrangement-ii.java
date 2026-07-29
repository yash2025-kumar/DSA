import java.util.Arrays;

public class Solution {
    private static final int MAX_K = 1_000_001; // Saturated limit for k to avoid overflow

    public String smallestPalindrome(String s, int k) {
        int[] totalCounts = new int[26];
        for (char c : s.toCharArray()) {
            totalCounts[c - 'a']++;
        }

        // 1. Verify if a palindrome can even be formed
        int oddCount = 0;
        char midChar = '#';
        for (int i = 0; i < 26; i++) {
            if (totalCounts[i] % 2 != 0) {
                oddCount++;
                midChar = (char) ('a' + i);
            }
        }
        if (oddCount > 1) return "";

        // 2. Extract frequency profile needed for the left half
        int[] halfCounts = new int[26];
        int halfLen = 0;
        for (int i = 0; i < 26; i++) {
            halfCounts[i] = totalCounts[i] / 2;
            halfLen += halfCounts[i];
        }

        // 3. Precompute combinations (Pascal's triangle) with saturation capping
        int[][] C = new int[halfLen + 1][halfLen + 1];
        for (int i = 0; i <= halfLen; i++) {
            C[i][0] = 1;
            for (int j = 1; j <= i; j++) {
                long sum = (long) C[i - 1][j - 1] + C[i - 1][j];
                C[i][j] = (int) Math.min(sum, MAX_K);
            }
        }

        // 4. Calculate if the total possible unique permutations cover 'k'
        int totalPermutations = getUniquePermutations(halfCounts, halfLen, C);
        if (k > totalPermutations) return "";

        // 5. Greedily build the left half of the string
        StringBuilder leftHalf = new StringBuilder();
        int remainingLen = halfLen;

        for (int pos = 0; pos < halfLen; pos++) {
            for (int c = 0; c < 26; c++) {
                if (halfCounts[c] == 0) continue;

                // Try placing character 'c' at this index
                halfCounts[c]--;
                int ways = getUniquePermutations(halfCounts, remainingLen - 1, C);

                if (k <= ways) {
                    // Valid direction, keep character 'c'
                    leftHalf.append((char) ('a' + c));
                    remainingLen--;
                    break;
                } else {
                    // Backtrack and skip this letter block
                    k -= ways;
                    halfCounts[c]++;
                }
            }
        }

        // 6. Assemble the full mirrored palindrome
        String leftStr = leftHalf.toString();
        String rightStr = new StringBuilder(leftStr).reverse().toString();
        
        if (midChar != '#') {
            return leftStr + midChar + rightStr;
        }
        return leftStr + rightStr;
    }

    // Computes unique multi-set permutations: N! / (n1! * n2! * ... * n26!)
    private int getUniquePermutations(int[] counts, int totalLen, int[][] C) {
        long permutations = 1;
        int currentLen = totalLen;

        for (int count : counts) {
            if (count > 0) {
                permutations = (permutations * C[currentLen][count]);
                if (permutations >= MAX_K) {
                    return MAX_K; // Capped to protect against overflow
                }
                currentLen -= count;
            }
        }
        return (int) permutations;
    }
}
