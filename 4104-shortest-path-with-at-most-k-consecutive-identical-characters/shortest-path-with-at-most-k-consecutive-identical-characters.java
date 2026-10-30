import java.util.*;

class Solution {
    public int shortestPath(int n, int[][] edges, String labels, int k) {
        // Build the adjacency list: g[u] stores list of {v, weight}
        List<int[]>[] g = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            g[i] = new ArrayList<>();
        }
        for (int[] e : edges) {
            g[e[0]].add(new int[]{e[1], e[2]});
        }
        
        // d[u][c] stores the minimum cost to reach node u with a run of c identical characters
        int[][] d = new int[n][k + 1];
        for (int[] row : d) {
            Arrays.fill(row, Integer.MAX_VALUE);
        }
        
        // PriorityQueue stores int[]: {cost, node, consecutive_count}
        PriorityQueue<int[]> q = new PriorityQueue<>((a, b) -> Integer.compare(a[0], b[0]));
        
        // Start at node 0 with cost 0 and initial character run of 1
        q.offer(new int[]{0, 0, 1});
        d[0][1] = 0;
        
        while (!q.isEmpty()) {
            int[] curr = q.poll();
            int cost = curr[0], u = curr[1], c = curr[2];
            
            // Skip if we found a better path to this state already
            if (cost > d[u][c]) continue;
            
            // If we reached the target node n - 1, return the minimum cost
            if (u == n - 1) return cost;
            
            // Explore neighbors
            for (int[] edge : g[u]) {
                int v = edge[0];
                int w = edge[1];
                
                // Calculate next consecutive count
                int nextCount = (labels.charAt(u) == labels.charAt(v)) ? c + 1 : 1;
                
                // Check constraint: at most k consecutive identical characters
                if (nextCount <= k) {
                    if (cost + w < d[v][nextCount]) {
                        d[v][nextCount] = cost + w;
                        q.offer(new int[]{d[v][nextCount], v, nextCount});
                    }
                }
            }
        }
        
        return -1; // If no valid path to node n - 1 exists
    }
}
