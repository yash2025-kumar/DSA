class Solution {
    private List<Integer>[] adjacencyList;
    private boolean[] visited;

    public int countCompleteComponents(int n, int[][] edges) {
        adjacencyList = new List[n];
        visited = new boolean[n];

        Arrays.setAll(adjacencyList, index -> new ArrayList<>());

        for(int[] edge : edges) {
            int nodeA = edge[0];
            int nodeB = edge[1];
            adjacencyList[nodeA].add(nodeB);
            adjacencyList[nodeB].add(nodeA);
        }

        int completeComponentCount = 0;

        for(int node=0; node<n; node++) {
            if(!visited[node]) {
                int[] componentStats = dfs(node);
                int nodeCount = componentStats[0];
                int edgeCount = componentStats[1];

                if(nodeCount * (nodeCount - 1) == edgeCount) {
                    completeComponentCount++;
                }
            }
        }

        return completeComponentCount;
    }

    private int[] dfs(int currentNode) {
        visited[currentNode] = true;

        int nodeCount = 1;
        int degreeSum = adjacencyList[currentNode].size();

        for(int neighbor : adjacencyList[currentNode]) {
            if(!visited[neighbor]) {
                int[] neighborStats = dfs(neighbor);
                nodeCount += neighborStats[0];
                degreeSum += neighborStats[1];
            }
        }

        return new int[] {nodeCount, degreeSum};
    }
}