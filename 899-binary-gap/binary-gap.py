class Solution:
    def binaryGap(self, n: int) -> int:
        max_gap = 0
        last_one_pos = -1
        current_pos = 0

        while n:
            if n & 1:
                if last_one_pos != -1:
                    max_gap = max(max_gap, current_pos - last_one_pos)
                last_one_pos = current_pos
            n >>= 1
            current_pos += 1
        return max_gap
        