class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        const int MOD = 1e9 + 7;
        vector<int> bitCounts(30,0);

        for(int num : nums) {
            for(int i=0; i<30; i++) {
                if((num >> i) & 1) {
                    bitCounts[i]++;
                }
            }
        }

        long long totalSumOfSquares = 0;
        for(int step=0; step<k; step++) {
            long long currentNum = 0;

            for(int i=0; i<30; i++) {
                if(bitCounts[i] > 0) {
                    currentNum |= (1 << i);
                    bitCounts[i]--;
                }
            }

            totalSumOfSquares = (totalSumOfSquares + (currentNum * currentNum) % MOD) % MOD;
        }

        return totalSumOfSquares;
    }
};