class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> firstOccurrence('z' + 1, 0);
        vector<int> lastOccurrence('z' + 1, 0);

        for(int i = 0; i < word.size(); i++) {
            char currentChar = word[i];
            int position = i + 1;

            if(firstOccurrence[currentChar] == 0) {
                firstOccurrence[currentChar] = position;
            }
            lastOccurrence[currentChar] = position;
        }

        int specialCharCount = 0;

        for(int i = 0; i < 26; i++) {
            char lowerCase = 'a' + i;
            char upperCase = 'A' + i;

            if(lastOccurrence[lowerCase] > 0 && firstOccurrence[upperCase] > 0 && lastOccurrence[lowerCase] < firstOccurrence[upperCase]) {
                specialCharCount++;
            }
        }

        return specialCharCount;
    }
};