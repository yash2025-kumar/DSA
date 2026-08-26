class Solution:
    def shortestBeautifulSubstring(self, s: str, k: int) -> str:
        n = len(s)
        if n < k:
            return ""
        
        l = 0
        countOne = 0
        min_len = float('inf')
        ans = ""

        for r in range(n):
            if s[r] == '1':
                countOne += 1

            while countOne == k:
                curr_len = r - l + 1
                curr_str = s[l:r+1]

                if curr_len < min_len:
                    min_len = curr_len
                    ans = curr_str
                elif curr_len == min_len:
                    if ans == "" or curr_str < ans:
                        ans = curr_str

                if s[l] == '1':
                    countOne -= 1
                l += 1

        return ans
