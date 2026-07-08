class Solution:
    def sumAndMultiply(self, s: str, queries: List[List[int]]) -> List[int]:
        MOD = 10**9 + 7
        n = len(s)

        prefix_sum = [0] * (n + 1)
        prefix_val = [0] * (n + 1)

        count_nonzero = [0] * (n + 1)

        pow10 = [1] * (n + 1)
        for i in range(1, n + 1):
            pow10[i] = (pow10[i - 1] * 10) % MOD

        for i, char in enumerate(s):
            digit = int(char)

            if digit == 0:
                prefix_sum[i + 1] = prefix_sum[i]
                prefix_val[i + 1] = prefix_val[i]
                count_nonzero[i + 1] = count_nonzero[i]
            else:
                prefix_sum[i + 1] = (prefix_sum[i] + digit) % MOD
                prefix_val[i + 1] = (prefix_val[i] * 10 + digit) % MOD
                count_nonzero[i + 1] = count_nonzero[i] + 1

        ans = []

        for l, r in queries:
            nz_count = count_nonzero[r + 1] - count_nonzero[l]

            if nz_count == 0:
                ans.append(0)
                continue

            digit_sum = (prefix_sum[r + 1] - prefix_sum[l]) % MOD

            x = (prefix_val[r + 1] - (prefix_val[l] * pow10[nz_count]) % MOD) % MOD

            query_ans = (x * digit_sum) % MOD
            ans.append(query_ans)

        return ans
