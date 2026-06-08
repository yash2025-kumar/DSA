class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> result;

        for(const int&num : nums) {
            if(num < pivot) {
                result.push_back(num);
            }
        }

        for(const int&num : nums) {
            if(num == pivot) {
                result.push_back(num);
            }
        }

        for(const int&num : nums) {
            if(num > pivot) {
                result.push_back(num);
            }
        }

        return result;
    }
};