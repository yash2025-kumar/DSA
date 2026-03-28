class Solution {
public:
    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();
        string result(n, '\0');
        int currentIndex = 0;

        for(char ch = 'a'; ch <= 'z'; ch++) {
            while(currentIndex < n && result[currentIndex] != '\0') {
                currentIndex++;
            }

            if(currentIndex == n) {
                break;
            }

            for(int j = currentIndex; j < n; j++) {
                if(lcp[currentIndex][j] > 0) {
                    result[j] = ch;
                }
            }
        }

        if(result.find('\0') != string::npos) {
            return "";
        }

        for(int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if(result[i] == result[j]) {
                    if(i == n - 1 || j == n - 1) {
                        if(lcp[i][j] != 1) {
                            return "";
                        }
                    } else {
                        if (lcp[i][j] != lcp[i + 1][j + 1] + 1) {
                            return "";
                        }
                    }
                } else {
                    if (lcp[i][j] != 0) {
                        return "";
                    }
                }
            }
        }

        return result;
    }
};