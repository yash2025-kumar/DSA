class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.length();
        vector<int> count(26,0);
        for(char c : s) {
            count[c - 'a']++;
        }
        int odd_count = 0;
        char mid_char = '#';
        for(int i=0; i<26; i++) {
            if(count[i] % 2 != 0) {
                odd_count++;
                mid_char = 'a' + i;
            }
        }
        if(odd_count > 1) return "";

        int half_len = n / 2;
        string current_half = "";
        string best_half = "";

        auto dfs = [&](auto& self, int idx, bool is_greater) -> bool {
            if(idx == half_len) {
                if(!is_greater) {
                    string full_pal = current_half;
                    if(n % 2 != 0) full_pal += mid_char;
                    string right = current_half;
                    reverse(right.begin(), right.end());
                    full_pal += right;

                    if(full_pal > target) {
                        best_half = current_half;
                        return true;
                    }
                    return false;
                }
                best_half = current_half;
                return true;
            }

            char min_allowed = is_greater ? 'a' : target[idx];

            for(char c=min_allowed; c <= 'z'; c++) {
                if(count[c - 'a'] >= 2) {
                    count[c - 'a'] -= 2;
                    current_half.push_back(c);

                    bool next_greater = is_greater || (c > target[idx]);
                    if(self(self, idx + 1, next_greater)) {
                        return true;
                    }

                    current_half.pop_back();
                    count[c - 'a'] += 2;
                }
            }
            return false;
        };

        if(dfs(dfs, 0, false)) {
            string result = best_half;
            if (n % 2 != 0) result += mid_char;
            string right = best_half;
            reverse(right.begin(), right.end());
            result += right;
            return result;
        }

        return "";
    }
};