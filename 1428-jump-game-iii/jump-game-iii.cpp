class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        queue<int> bfsQueue{{start}};

        while(!bfsQueue.empty()) {
            int currentIndex = bfsQueue.front();
            bfsQueue.pop();

            if(arr[currentIndex] == 0) {
                return true;
            }

            int jumpDistance = arr[currentIndex];

            arr[currentIndex] = -1;

            vector<int> nextPositions = {currentIndex + jumpDistance, currentIndex - jumpDistance};

            for (int nextIndex : nextPositions) {
                if (nextIndex >= 0 && nextIndex < arr.size() && arr[nextIndex] != -1) {
                    bfsQueue.push(nextIndex);
                }
            }
        }

        return false;
    }
};