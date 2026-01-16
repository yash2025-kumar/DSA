class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
       auto calculateDistances = [](vector<int>& fences, int boundary) -> unordered_set<int> {
        fences.push_back(boundary);
        fences.push_back(1);

        sort(fences.begin(), fences.end());

        unordered_set<int> distances;

        for(int i = 0; i < fences.size(); i++) {
            for (int j = 0; j < i; j++) {
                distances.insert(fences[i] - fences[j]);
            }
        }
        return distances;
       };

       unordered_set<int> horizontalDistances = calculateDistances(hFences, m);

       unordered_set<int> verticalDistances = calculateDistances(vFences, n);

       int maxSideLength = 0;
       for (int distance : horizontalDistances) {
        if (verticalDistances.count(distance)) {
            maxSideLength = max(maxSideLength, distance);
        }
       }
       
       const int MOD = 1e9 + 7;

       return maxSideLength > 0 ? (1LL * maxSideLength * maxSideLength) % MOD : -1;
    }
};