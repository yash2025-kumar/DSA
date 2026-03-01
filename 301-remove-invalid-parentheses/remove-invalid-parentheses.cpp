#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        int leftToRemove = 0;
        int rightToRemove = 0;
        
        for (char c : s) {
            if (c == '(') {
                leftToRemove++;
            } else if (c == ')') {
                if (leftToRemove > 0) {
                    leftToRemove--; 
                } else {
                    rightToRemove++; 
                }
            }
        }

        unordered_set<string> resultSet;
        dfs(s, 0, leftToRemove, rightToRemove, 0, 0, "", resultSet);
        return vector<string>(resultSet.begin(), resultSet.end());
    }

private:
    void dfs(const string& s, int index, int remL, int remR, int openCount, int closeCount, string currentString, unordered_set<string>& resultSet) {
        
        if (index == s.length()) {
            if (remL == 0 && remR == 0 && openCount == closeCount) {
                resultSet.insert(currentString);
            }
            return;
        }

        char currentChar = s[index];
        
        
        if (currentChar == '(' && remL > 0) {
            
            dfs(s, index + 1, remL - 1, remR, openCount, closeCount, currentString, resultSet);
        } else if (currentChar == ')' && remR > 0) {
            
            dfs(s, index + 1, remL, remR - 1, openCount, closeCount, currentString, resultSet);
        }

        

        
        if (currentChar != '(' && currentChar != ')') {
            dfs(s, index + 1, remL, remR, openCount, closeCount, currentString + currentChar, resultSet);
        } else if (currentChar == '(') {
            
            dfs(s, index + 1, remL, remR, openCount + 1, closeCount, currentString + currentChar, resultSet);
        } else if (currentChar == ')') {
            
            if (closeCount < openCount) {
                dfs(s, index + 1, remL, remR, openCount, closeCount + 1, currentString + currentChar, resultSet);
            }
        }
    }
};
