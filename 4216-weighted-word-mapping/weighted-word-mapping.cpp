class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string result = "";

        for(const std::string& word : words) {
            long long total_weight = 0;

            for(char ch : word) {
                total_weight += weights[ch - 'a'];
            }

            int remainder = total_weight % 26;

            char mapped_char = 'z' - remainder;

            result += mapped_char;
        }

        return result;
    }
};