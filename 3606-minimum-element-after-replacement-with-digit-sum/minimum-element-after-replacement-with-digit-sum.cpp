class Solution {
public:
    int minElement(vector<int>& nums) {
        int min_val = INT_MAX;

        for(int num : nums) {
            int current_sum = getDigitSum(num);
            if(current_sum < min_val) {
                min_val = current_sum;
            }
        }

        return min_val;
    }

    private:
        int getDigitSum(int n) {
            int sum = 0;
            while(n > 0) {
                sum += n % 10;
                n /= 10;
            }
            return sum;
        }
};