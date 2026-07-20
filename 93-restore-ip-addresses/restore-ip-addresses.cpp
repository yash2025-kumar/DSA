class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        int length = s.size();
        vector<string> result;
        vector<string> currentSegments;

        function<void(int)> backtrack = [&](int startIndex) {
            if(startIndex >= length && currentSegments.size() == 4) {
                result.push_back(currentSegments[0] + "." + currentSegments[1] + "." + currentSegments[2] + "." + currentSegments[3]);

                return;
            }

            if(startIndex >= length || currentSegments.size() >= 4) {
                return;
            }

            int currentNumber = 0;

            for(int endIndex = startIndex; endIndex < min(length, startIndex + 3); endIndex++) {
                currentNumber = currentNumber * 10 + (s[endIndex] - '0');

                if(currentNumber > 255 || (endIndex > startIndex && s[startIndex] == '0')) {
                    break;
                }

                currentSegments.push_back(s.substr(startIndex, endIndex - startIndex + 1));

                backtrack(endIndex + 1);

                currentSegments.pop_back();
            }
        };

        backtrack(0);
        return result;
    }
};