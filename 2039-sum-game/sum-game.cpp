class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();

        int leftQuestionMarks = 0;
        int leftSum = 0;
        for (int i = 0; i < n / 2; ++i) {
            if (num[i] == '?') {
                leftQuestionMarks++;
            } else {
                leftSum += num[i] - '0';
            }
        }

        int rightQuestionMarks = 0;
        int rightSum = 0;
        for (int i = n / 2; i < n; ++i) {
            if (num[i] == '?') {
                rightQuestionMarks++;
            } else {
                rightSum += num[i] - '0';
            }
        }

        int totalQuestionMarks = leftQuestionMarks + rightQuestionMarks;
        int sumDifference = leftSum - rightSum;
        int questionMarkDifference = rightQuestionMarks - leftQuestionMarks;

        return (totalQuestionMarks % 2 == 1) || (sumDifference != 9 * questionMarkDifference / 2);
    }
};