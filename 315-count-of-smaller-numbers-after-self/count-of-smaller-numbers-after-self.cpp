class BinaryIndexedTree {
public:
    int size;
    vector<int> tree;

    BinaryIndexedTree(int n) : size(n), tree(n + 1, 0) {}

    void update(int x, int delta) {
        while(x <= size) {
            tree[x] += delta;
            x += lowbit(x);
        }
    }

    int query(int x) {
        int sum = 0;
        while(x > 0) {
            sum += tree[x];
            x -= lowbit(x);
        }
        return sum;
    }

    int lowbit(int x) {
        return x & -x;
    }
};

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        unordered_set<int> uniqueNums(nums.begin(), nums.end());
        vector<int> sortedUnique(uniqueNums.begin(), uniqueNums.end());
        sort(sortedUnique.begin(), sortedUnique.end());

        unordered_map<int, int> valueToIndex;
        int uniqueCount = sortedUnique.size();
        for(int i=0; i<uniqueCount; i++) {
            valueToIndex[sortedUnique[i]] = i + 1;
        }

        BinaryIndexedTree* bit = new BinaryIndexedTree(uniqueCount);

        vector<int> result(nums.size());
        for(int i=nums.size()-1; i>=0; i--) {
            int compressedIndex = valueToIndex[nums[i]];
            bit->update(compressedIndex, 1);
            result[i] = bit->query(compressedIndex - 1);
        }

        return result;
    }
};