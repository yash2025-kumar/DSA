class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i=0; i<n; i++) {
            if(i != nums[i]) return i;
        }
        return n;
    }
};

//     int missingNumber(vector<int>& nums) {
//         int n = nums.size();
//         for(int i=0; i<=n; i++) {
//             bool flag = false; // false means i isn't present in array
//             for(int ele : nums) {
//                 if(ele == i) {
//                     flag = true;
//                     break;
//                 }
//             }
//             if(flag == false) return i;
//         }
//         return 35235; // TC - O(n^2)
//     }
// };