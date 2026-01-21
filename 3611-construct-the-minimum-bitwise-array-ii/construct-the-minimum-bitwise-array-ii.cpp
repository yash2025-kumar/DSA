class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
       vector<int> result;

       for(int num : nums) {
        if(num == 2) {
            result.push_back(-1);
        }
        else {
            for (int bitPos = 1; bitPos < 32; bitPos++) {
                if (((num >> bitPos) & 1) ^ 1) {
                    result.push_back(num ^ (1 << (bitPos - 1)));
                    break;
                }
            }
        }
       } 
       return result;
    }
};