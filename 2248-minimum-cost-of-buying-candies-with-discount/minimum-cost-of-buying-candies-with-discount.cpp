class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.rbegin(), cost.rend());
        int totalCost = 0;

        for(int i = 0; i < cost.size(); i += 3) {
            totalCost += cost[i];

            if(i + 1 < cost.size()) {
                totalCost += cost[i + 1];
            }
        }
        return totalCost;
    }
};