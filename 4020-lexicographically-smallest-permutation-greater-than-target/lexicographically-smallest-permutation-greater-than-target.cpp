class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.length();
        vector<int> count(26,0);
        for(char c : s) {
            count[c - 'a']++;
        }
        string prefix = "";
        int i = 0;
        while(i < n && count[target[i] - 'a'] > 0) {
            prefix.push_back(target[i]);
            count[target[i] - 'a']--;
            i++;
        }
        for(int j=i; j>=0; j--) {
            if(j < i) {
                count[target[j] - 'a']++;
                prefix.pop_back();
            }
            if(j < n) {
                for(int c = target[j] - 'a' + 1; c<26; c++) {
                    if(count[c] > 0) {
                        prefix.push_back(static_cast<char>('a' + c));
                        count[c]--;

                        for(int k=0; k<26; k++) {
                            while(count[k] > 0) {
                                prefix.push_back(static_cast<char>('a' + k));
                                count[k]--;
                            }
                        }
                        return prefix;
                    }
                }
            }
        }
        return "";
    }
};