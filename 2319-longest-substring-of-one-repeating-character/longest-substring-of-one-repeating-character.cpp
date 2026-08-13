#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Node structure representing a range in the segment tree
struct Node {
    int max_len;   // Longest identical substring in this range
    int pref_len;  // Length of identical prefix substring
    int suff_len;  // Length of identical suffix substring
    char pref_char; // Character at the beginning of this range
    char suff_char; // Character at the end of this range
    int size;       // Total size of the range covered by this node
};

class Solution {
private:
    vector<Node> tree;

    // Helper function to merge information from left and right children
    Node merge(const Node& left, const Node& right) {
        Node parent;
        parent.size = left.size + right.size;
        parent.pref_char = left.pref_char;
        parent.suff_char = right.suff_char;

        // Base prefix and suffix lengths inherited from children
        parent.pref_len = left.pref_len;
        parent.suff_len = right.suff_len;
        
        // Base max length is the maximum of the two children
        parent.max_len = max(left.max_len, right.max_len);

        // If the middle elements match, we can merge across the boundary
        if (left.suff_char == right.pref_char) {
            // Check if the left child is entirely composed of one repeating character
            if (left.pref_len == left.size) {
                parent.pref_len = left.size + right.pref_len;
            }
            // Check if the right child is entirely composed of one repeating character
            if (right.suff_len == right.size) {
                parent.suff_len = right.size + left.suff_len;
            }
            // Candidate for max_len formed by bridging the left and right components
            parent.max_len = max(parent.max_len, left.suff_len + right.pref_len);
        }

        return parent;
    }

    // Build the segment tree initially
    void build(int node, int start, int end, const string& s) {
        if (start == end) {
            tree[node] = {1, 1, 1, s[start], s[start], 1};
            return;
        }
        int mid = start + (end - start) / 2;
        build(2 * node, start, mid, s);
        build(2 * node + 1, mid + 1, end, s);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    // Update a specific index with a new character
    void update(int node, int start, int end, int idx, char val) {
        if (start == end) {
            tree[node] = {1, 1, 1, val, val, 1};
            return;
        }
        int mid = start + (end - start) / 2;
        if (idx <= mid) {
            update(2 * node, start, mid, idx, val);
        } else {
            update(2 * node + 1, mid + 1, end, idx, val);
        }
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        int n = s.length();
        int k = queryIndices.size();
        tree.resize(4 * n);

        // Step 1: Initialize the segment tree with the initial string
        build(1, 0, n - 1, s);

        vector<int> result(k);

        // Step 2: Process each query sequentially
        for (int i = 0; i < k; ++i) {
            update(1, 0, n - 1, queryIndices[i], queryCharacters[i]);
            result[i] = tree[1].max_len; // The root node always contains the overall answer
        }

        return result;
    }
};
