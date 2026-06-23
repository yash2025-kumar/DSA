class Solution:
    def shortestPalindrome(self, s: str) -> str:
        if not s or s == s[::-1]:
            return s

        rev_s = s[::-1]
        combined = s + '#' + rev_s

        lps = [0] * len(combined)
        for i in range(1, len(combined)):
            j = lps[i - 1]
            while j > 0 and combined[i] != combined[j]:
                j = lps[j - 1]
            if combined[i] == combined[j]:
                j += 1
            lps[i] = j

        palindrome_len = lps[-1]

        return rev_s[:len(s) - palindrome_len] + s