// Meeting Rooms (Find the possibility of meeting?)
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public :
    bool minMeetingRooms(vector<vector<int>> &intervals) {
        int n = intervals.size();
        if(n == 0)  return true;
        int count = 0, ans = 0;

        vector<int> start(n);
        vector<int> end(n);

        for(int i = 0; i < n; i++) {
            start[i] = intervals[i][0];
            end[i] = intervals[i][1];
        }     
        
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());

        int i = 0, j = 0;

        while(i < n && j < n) {
            if(start[i] < end[j]) {
                // a meeting is starting
                count++;
                ans = max(ans, count);
                i++;
            } else if(start[i] > end[j]) {
                // a meeting is ended
                count--;
                j++;
            } else {
                i++;
                j++;
            }
        }
        return ans == 1;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> intervals1 = {{1, 5}, {6, 10}, {11, 15}};
    vector<vector<int>> intervals2 = {{0, 30}, {5, 10}, {15, 20}};

    cout << "Can all meetings be held in one room (Case 1)? " 
         << (sol.minMeetingRooms(intervals1) ? "Yes" : "No") << endl;

    cout << "Can all meetings be held in one room (Case 2)? " 
         << (sol.minMeetingRooms(intervals2) ? "Yes" : "No") << endl;

    return 0;
}
