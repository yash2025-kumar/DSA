class Solution {
public:
    long long countCommas(long long n) {
        long long total_commas = 0;
        for(long long threshold = 1000; threshold <= n; threshold *= 1000) {
            total_commas += (n - threshold + 1);
        }
        return total_commas;
    }
};