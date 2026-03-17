class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> availableWords(wordList.begin(), wordList.end());

        queue<string> bfsQueue;
        bfsQueue.push(beginWord);

        int sequenceLength = 1;

        while(!bfsQueue.empty()) {
            sequenceLength++;

            int currentLevelSize = bfsQueue.size();
            for(int i = 0; i < currentLevelSize; i++) {
                string currentWord = bfsQueue.front();
                bfsQueue.pop();

                for(int charIndex = 0; charIndex < currentWord.size(); charIndex++) {
                    char originalChar = currentWord[charIndex];

                    for (char newChar = 'a'; newChar <= 'z'; ++newChar) {
                        currentWord[charIndex] = newChar;

                        if (!availableWords.count(currentWord)) {
                            continue;
                        }

                        if (currentWord == endWord) {
                            return sequenceLength;
                        }
                        
                        bfsQueue.push(currentWord);

                        availableWords.erase(currentWord);
                    }

                    currentWord[charIndex] = originalChar;
                }
            }
        }

        return 0;
    }
};