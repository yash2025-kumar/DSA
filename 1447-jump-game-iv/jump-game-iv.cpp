class Solution {
public:
    int minJumps(vector<int>& arr) {
        unordered_map<int, vector<int>> valueToIndices;
        int arraySize = arr.size();

        for(int i = 0; i < arraySize; i++) {
            valueToIndices[arr[i]].push_back(i);
        }

        vector<bool> visited(arraySize);

        queue<int> bfsQueue{{0}};
        visited[0] = true;

        for(int steps = 0;; steps++) {
            int currentLevelSize = bfsQueue.size();
            for(int k = 0; k < currentLevelSize; k++) {
                int currentIndex = bfsQueue.front();
                bfsQueue.pop();

                if(currentIndex == arraySize - 1) {
                    return steps;
                }

                for(int nextIndex : valueToIndices[arr[currentIndex]]) {
                    if(!visited[nextIndex]) {
                        visited[nextIndex] = true;
                        bfsQueue.push(nextIndex);
                    }
                }

                valueToIndices[arr[currentIndex]].clear();

                vector<int> adjacentIndices = {currentIndex - 1, currentIndex + 1};
                for (int nextIndex : adjacentIndices) {
                    if (nextIndex >= 0 && nextIndex < arraySize && !visited[nextIndex]) {
                        visited[nextIndex] = true;
                        bfsQueue.push(nextIndex);
                    }
                }
            }
        }
    }
};