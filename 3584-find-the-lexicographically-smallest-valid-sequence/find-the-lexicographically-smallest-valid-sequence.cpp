class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();

        vector<int> last_idx(m, -1);

        int i = n - 1;
        int j = m - 1;
        while(i >= 0 && j >= 0) {
            if(word1[i] == word2[j]) {
                last_idx[j] = i;
                j--;
            }
            i--;
        }

        vector<int> ans;
        bool can_modify = true;
        j = 0;

        for(i=0; i<n; i++) {
            if(j == m) break;

            if(word1[i] == word2[j]) {
                ans.push_back(i);
                j++;
            }
            else if(can_modify && (j == m - 1 || i < last_idx[j + 1])) {
                can_modify = false;
                ans.push_back(i);
                j++;
            }
        }

        return ans.size() == m ? ans : vector<int>();
    }
};