class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> lookup;
        for(const auto& pair : knowledge) {
            lookup[pair[0]] = pair[1];
        }
        string result = "";
        string current_key = "";
        bool inside_bracket = false;

        for(char c : s) {
            if(c == '(') {
                inside_bracket = true;
            }
            else if(c == ')') {
                inside_bracket = false;

                if(lookup.count(current_key)) {
                    result += lookup[current_key];
                }
                else {
                    result += "?";
                }
                current_key = "";
            }
            else if(inside_bracket) {
                current_key += c;
            }
            else {
                result += c;
            }
        }
        return result;
    }
};