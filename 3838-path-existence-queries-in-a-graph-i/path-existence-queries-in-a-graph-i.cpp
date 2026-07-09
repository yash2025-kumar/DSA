class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> g(n, 0);
        int component_id = 0;

        for(int i=1; i<n; ++i) {
            if(nums[i] - nums[i - 1] > maxDiff) {
                component_id++;
            }
            g[i] = component_id;
        }

        int m = queries.size();
        vector<bool> ans(m);
        for(int i=0; i<m; i++) {
            int u = queries[i][0];
            int v = queries[i][1];

            ans[i] = (g[u] == g[v]);
        }

        return ans;
    }
};