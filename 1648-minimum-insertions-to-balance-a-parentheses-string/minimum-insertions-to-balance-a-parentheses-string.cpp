class Solution {
public:
    int minInsertions(string s) {
        int add = 0;
        int bal = 0;

        for(char c : s) {
            if(c == '(') {
                if(bal % 2 > 0) {
                    ++add;
                    --bal;
                }
                bal += 2;
            }
            else {
                --bal;
                if(bal < 0) {
                    ++add;
                    bal += 2;
                }
            }
        }
        return add + bal;
    }
};