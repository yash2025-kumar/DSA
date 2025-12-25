class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int wordCount = words.size();

        for (int i = 0; i < wordCount;) {
            vector<string> currentLineWords = {words[i]};
            int currentLineLength = words[i].size();
            i++;

            while(i < wordCount && currentLineLength + 1 + words[i].size() <= maxWidth) {
                currentLineLength += 1 + words[i].size();
                currentLineWords.push_back(words[i]);
                i++;
            }

            if(i == wordCount || currentLineWords.size() == 1) {
                string leftJustifiedLine = currentLineWords[0];
                for (int j = 1; j < currentLineWords.size(); j++) {
                    leftJustifiedLine += " " + currentLineWords[j];
            }
            string rightPadding(maxWidth - leftJustifiedLine.size(), ' ');
                result.push_back(leftJustifiedLine + rightPadding);
                continue;
        }
        int totalWordChars = currentLineLength - (currentLineWords.size() - 1);
        int totalSpaces = maxWidth - totalWordChars;
        int baseSpaces = totalSpaces / (currentLineWords.size() - 1);
        int extraSpaces = totalSpaces % (currentLineWords.size() - 1);

        string justifiedLine;
            for (int j = 0; j < currentLineWords.size() - 1; j++) {
                justifiedLine += currentLineWords[j];
                int spacesToAdd = baseSpaces + (j < extraSpaces ? 1 : 0);
                justifiedLine += string(spacesToAdd, ' ');
            }
            justifiedLine += currentLineWords.back();

            result.push_back(justifiedLine);
        }
        return result;
    }
};