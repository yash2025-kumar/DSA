

class Solution {
public:
    int distinctSubseqII(string s) {
        int MOD = 1e9 + 7;
        
        vector<long> endsIn(26, 0); 
        
        for (char c : s) {
            int index = c - 'a';
            
            
            long current_sum = 0;
            for (long count : endsIn) {
                current_sum = (current_sum + count) % MOD;
            }
            
            
            endsIn[index] = (current_sum + 1) % MOD;
        }
        
    
        long total_subsequences = 0;
        for (long count : endsIn) {
            total_subsequences = (total_subsequences + count) % MOD;
        }
        
        return total_subsequences;
    }
};
