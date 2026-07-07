class Solution:
    def sumAndMultiply(self, n: int) -> int:
        s = str(n).replace('0', '')
        x = int(s) if s else 0

        digit_sum = sum(int(digit) for digit in str(x))
        return x * digit_sum