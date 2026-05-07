class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();
      
        
        vector<int> result(n);
      
        
        vector<int> prefixMax(n);
        prefixMax[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            prefixMax[i] = max(prefixMax[i - 1], nums[i]);
        }
      
        
        int suffixMin = 1 << 30;
      
        
        for (int i = n - 1; i >= 0; --i) {
            
            if (prefixMax[i] > suffixMin) {
                
                result[i] = (i + 1 < n) ? result[i + 1] : prefixMax[i];
            } else {
                result[i] = prefixMax[i];
            }
          
            
            suffixMin = min(suffixMin, nums[i]);
        }
      
        return result;
    }
};
