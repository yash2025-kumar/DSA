class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adjacencyList(n);

        bool visited[n];
        memset(visited, 0, sizeof(visited));

        for(auto& road : roads) {
            int nodeA = road[0] - 1;
            int nodeB = road[1] - 1;
            int distance = road[2];

            adjacencyList[nodeA].emplace_back(nodeB, distance);
            adjacencyList[nodeB].emplace_back(nodeA, distance);
        }

        int minEdgeWeight = INT_MAX;

        function<void(int)> dfs = [&](int currentNode) {
            for (auto [neighborNode, edgeWeight] : adjacencyList[currentNode]) {
                minEdgeWeight = min(minEdgeWeight, edgeWeight);

                if(!visited[neighborNode]) {
                    visited[neighborNode] = true;
                    dfs(neighborNode);
                }
            }
        };

        visited[0] = true;
        dfs(0);

        return minEdgeWeight;
    }
};