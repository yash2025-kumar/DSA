#include <vector>
#include <numeric>
#include <unordered_map>

using namespace std;

class Solution {
public:
    // Union-Find find operation with path compression
    int find(vector<int>& parent, int i) {
        if (parent[i] == i) return i;
        return parent[i] = find(parent, parent[i]);
    }

    // Union-Find union operation
    void unite(vector<int>& parent, int i, int j) {
        int rootI = find(parent, i);
        int rootJ = find(parent, j);
        if (rootI != rootJ) parent[rootI] = rootJ;
    }

    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        vector<int> parent(n);
        iota(parent.begin(), parent.end(), 0);

        // 1. Group indices into components
        for (auto& swap : allowedSwaps) {
            unite(parent, swap[0], swap[1]);
        }

        // 2. Count frequencies of source elements per component
        unordered_map<int, unordered_map<int, int>> componentCounts;
        for (int i = 0; i < n; ++i) {
            int root = find(parent, i);
            componentCounts[root][source[i]]++;
        }

        // 3. Subtract matches from target to find remaining Hamming distance
        int distance = 0;
        for (int i = 0; i < n; ++i) {
            int root = find(parent, i);
            int val = target[i];
            
            if (componentCounts[root].count(val) && componentCounts[root][val] > 0) {
                componentCounts[root][val]--;
            } else {
                distance++; // No match found in this component's available source elements
            }
        }

        return distance;
    }
};
