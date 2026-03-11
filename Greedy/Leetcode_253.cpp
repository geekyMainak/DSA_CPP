// Meeting Rooms II (Find the min number of conference rooms required?)
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool cmp(const vector<int> &a, const vector<int> &b) {
    return a[0] < b[0];
}

class Solution {
public :
    int minMeetingRooms(vector<vector<int>> &intervals) {
        int n = intervals.size();
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
        return ans;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> intervals = {
        {0, 30}, {5, 10}, {15, 20}
    };

    int result = sol.minMeetingRooms(intervals);
    cout << "Minimum number of meeting rooms required: " << result << endl;

    return 0;
}
