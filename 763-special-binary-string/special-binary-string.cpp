class Solution {
public:
    string makeLargestSpecial(string s) {
        if (s.empty()) {
            return s;
        }

        vector<string> specialSubstrings;

        int balance = 0;
        int startPos = 0;

        for(int currentPos = 0; currentPos < s.size(); currentPos++) {
            balance += (s[currentPos] == '1') ? 1 : -1;

            if(balance == 0) {
                string innerPart = s.substr(startPos + 1, currentPos - startPos - 1);
                string processedSpecial = "1" + makeLargestSpecial(innerPart) + "0";
                specialSubstrings.push_back(processedSpecial);

                startPos = currentPos + 1;
            }
        }

        sort(specialSubstrings.begin(), specialSubstrings.end(), greater<string>());

        string result = "";
        for(const string& substring : specialSubstrings) {
            result += substring;
        }

        return result;
    }
};