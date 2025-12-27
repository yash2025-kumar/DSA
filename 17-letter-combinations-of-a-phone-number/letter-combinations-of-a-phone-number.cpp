class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }

        vector<string> digitToLetters = {
            "abc",
            "def",
            "ghi",
            "jkl",
            "mno",
            "pqrs",
            "tuv",
            "wxyz",
        };

         vector<string> result = {""};

         for(char digit : digits) {
            string letters = digitToLetters[digit - '2'];

             vector<string> newCombinations;

             for (const string& existingCombination : result) {
                for (char letter : letters) {
                    newCombinations.push_back(existingCombination + letter);
                }
             }

             result = move(newCombinations);
         }
         return result;
    }
};
            