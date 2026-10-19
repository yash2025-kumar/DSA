class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int lessThanTargetCount = 0;
        int targetCount = 0;
        for(int num : nums) {
            if(num < target) {
                lessThanTargetCount++;
            }
            else if(num == target) {
                targetCount++;
            }
        }

        vector<int> result;
        for(int i=0; i<targetCount; i++) {
            result.push_back(lessThanTargetCount + i);
        }

        return result;
    }
};