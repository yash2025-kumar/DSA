class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        
        using ll = long long;
        using pii = pair<ll, int>; // {endTime, room}

        priority_queue<int, vector<int>, greater<int>> availableRooms;
        priority_queue<pii, vector<pii>, greater<pii>> occupiedRooms;

        for (int i = 0; i < n; i++) {
            availableRooms.push(i);
        }

        vector<int> meetingCount(n, 0);

        sort(meetings.begin(), meetings.end());

        for (auto& meeting : meetings) {
            ll startTime = meeting[0];
            ll endTime = meeting[1];

            // Free rooms that are done before this meeting starts
            while (!occupiedRooms.empty() && occupiedRooms.top().first <= startTime) {
                availableRooms.push(occupiedRooms.top().second);
                occupiedRooms.pop();
            }

            int assignedRoom;

            if (!availableRooms.empty()) {
                // Assign earliest available room
                assignedRoom = availableRooms.top();
                availableRooms.pop();
                occupiedRooms.push({endTime, assignedRoom});
            } else {
                // Delay meeting
                auto [freeTime, room] = occupiedRooms.top();
                occupiedRooms.pop();

                ll duration = endTime - startTime;
                occupiedRooms.push({freeTime + duration, room});
                assignedRoom = room;
            }

            meetingCount[assignedRoom]++;
        }

        // Find room with maximum meetings
        int mostUsedRoom = 0;
        for (int i = 1; i < n; i++) {
            if (meetingCount[i] > meetingCount[mostUsedRoom]) {
                mostUsedRoom = i;
            }
        }

        return mostUsedRoom;
    }
};

    
