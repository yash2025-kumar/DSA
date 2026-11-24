class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        int ans = 0;

        for(int i=0; i<n; i++) {
            long long prod = 1;
            long long l = 1;
            int g = 0;

            for(int j=i; j<n; j++) {
                if(prod > LLONG_MAX / nums[j]) {
                    break;
                }
                prod *= nums[j];
                g = gcd(g, nums[j]);
                l = lcm(l, static_cast<long long>(nums[j]));

                if(prod == l * g) {
                    ans = max(ans, j - i + 1);
                }
            }
        }

        return ans;
    }
};