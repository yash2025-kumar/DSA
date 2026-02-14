import java.util.HashMap;
import java.util.Map;

class Solution {
    public String minWindow(String s, String t) {
        if (t.length() > s.length()) {
            return "";
        }

        // Frequency map for characters in t
        int[] freq = new int[256];
        for (char c : t.toCharArray()) {
            freq[c]++;
        }

        int left = 0, right = 0, start = 0, counter = t.length();
        int minLen = Integer.MAX_VALUE;
        int n = s.length();

        while (right < n) {
            char rightChar = s.charAt(right);
            // If the character is needed, decrement the counter
            if (freq[rightChar] > 0) {
                counter--;
            }
            // Decrement the frequency in the map (even if it's not in t, it becomes negative)
            freq[rightChar]--;
            right++;

            // When counter is 0, a valid window is found
            while (counter == 0) {
                int currentWindowLen = right - left;
                if (currentWindowLen < minLen) {
                    minLen = currentWindowLen;
                    start = left;
                }

                char leftChar = s.charAt(left);
                // If the character being removed from the left was a needed character, increment counter
                freq[leftChar]++;
                if (freq[leftChar] > 0) {
                    counter++;
                }
                left++;
            }
        }

        // If minLen is still MAX_VALUE, no valid window was found
        return minLen == Integer.MAX_VALUE ? "" : s.substring(start, start + minLen);
    }
}
