class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        auto feasible = [&](long long targetTime) {
            long long totalContribution = 0;
            for (int battery : batteries) {
                totalContribution += min(static_cast<long long>(battery), targetTime);
            }
            return totalContribution >= static_cast<long long>(n) * targetTime;
        };

        long long left = 0;
        long long right = 0;
        for (int battery : batteries) {
            right += battery;
        }
        long long firstTrueIndex = -1;

        while (left <= right) {
            long long mid = left + (right - left) / 2;

            if (feasible(mid)) {
                firstTrueIndex = mid;
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return firstTrueIndex;
    }
};