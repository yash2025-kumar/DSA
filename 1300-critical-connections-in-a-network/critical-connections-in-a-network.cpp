class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
      int timestamp = 0;

      vector<int> discovery(n, 0);

      vector<int> lowest(n, 0);

      vector<vector<int>> adjacencyList(n);
      for(const auto& edge : connections) {
            int nodeA = edge[0];
            int nodeB = edge[1];
            adjacencyList[nodeA].push_back(nodeB);
            adjacencyList[nodeB].push_back(nodeA);
      } 

      vector<vector<int>> bridges;

      function<void(int, int)> findBridges = [&](int currentNode, int parentNode) -> void {
        discovery[currentNode] = lowest[currentNode] = ++timestamp;

        for(int neighbor : adjacencyList[currentNode]) {
             if (neighbor == parentNode) {
                    continue;
                }

            if(discovery[neighbor] == 0) {
                findBridges(neighbor, currentNode);

                lowest[currentNode] = min(lowest[currentNode], lowest[neighbor]);

                 if (lowest[neighbor] > discovery[currentNode]) {
                    bridges.push_back({currentNode, neighbor});
                 }
            }
            else {
                lowest[currentNode] = min(lowest[currentNode], discovery[neighbor]);
            }
        }
      };
      findBridges(0, -1);

      return bridges;
    }
};