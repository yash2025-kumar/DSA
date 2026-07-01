class UnionFind {
public:
     vector<int> parent;
     int componentCount;

     UnionFind(int n) : componentCount(n), parent(n) {
        iota(parent.begin(), parent.end(), 0);
     } 

     bool unite(int a, int b) {
        int rootA = find(a);
        int rootB = find(b);

        if(rootA == rootB) {
            return false;
        }

        parent[rootA] = rootB;
        componentCount--;
        return true;
     }  

     int find(int x) {
        if(parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
     }
};

class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();

        if(grid[0][0] || grid[n-1][n-1]) {
            return 0;
        }

        queue<pair<int, int>> bfsQueue;
        int distance[n][n];
        memset(distance, 0x3f, sizeof(distance));

        for(int row=0; row<n; row++) {
            for(int col=0; col<n; col++) {
                if(grid[row][col] == 1) {
                    distance[row][col] = 0;
                    bfsQueue.emplace(row, col);
                }
            }
        }

        int directions[5] = {-1, 0, 1, 0, -1};

        while(!bfsQueue.empty()) {
            auto [currentRow, currentCol] = bfsQueue.front();
            bfsQueue.pop();

            for(int k=0; k<4; k++) {
                int nextRow = currentRow + directions[k];
                int nextCol = currentCol + directions[k + 1];

                if(nextRow >= 0 && nextRow < n && nextCol >= 0 && nextCol < n && distance[nextRow][nextCol] == 0x3f3f3f3f) {
                    distance[nextRow][nextCol] = distance[currentRow][currentCol] + 1;
                    bfsQueue.emplace(nextRow, nextCol);
                }
            }
        }

        vector<tuple<int, int, int>> cellsWithDistance;
        for(int row = 0; row < n; ++row) {
             for (int col = 0; col < n; ++col) {
                    cellsWithDistance.emplace_back(distance[row][col], row, col);
             }
        }

        sort(cellsWithDistance.begin(), cellsWithDistance.end());
        reverse(cellsWithDistance.begin(), cellsWithDistance.end());

        UnionFind uf(n * n);

        for (auto [currentDistance, row, col] : cellsWithDistance) {
            for (int k = 0; k < 4; ++k) {
                int adjacentRow = row + directions[k];
                int adjacentCol = col + directions[k + 1];

                if(adjacentRow >= 0 && adjacentRow < n && adjacentCol >= 0 && adjacentCol < n && distance[adjacentRow][adjacentCol] >= currentDistance) {
                    uf.unite(row * n + col, adjacentRow * n + adjacentCol);
                }
            }

            if(uf.find(0) == uf.find(n * n - 1)) {
                return currentDistance;
            }
        }

        return 0;
    }
};