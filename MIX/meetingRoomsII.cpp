#include <bits/stdc++.h>
using namespace std;

int minMeetingRooms(vector<vector<int>>& intervals){
    vector<int> startTimes, endTimes;
    for (const auto& interval : intervals) {
        startTimes.push_back(interval[0]);
        endTimes.push_back(interval[1]);
    }

    sort(startTimes.begin(), startTimes.end());
    sort(endTimes.begin(), endTimes.end());

    int usedRooms = 0, maxRooms = 0;
    int i = 0, j = 0;

    while (i < startTimes.size()) {
        if (startTimes[i] < endTimes[j]) {
            usedRooms++;
            i++;
        } else {
            usedRooms--;
            j++;
        }
        maxRooms = max(maxRooms, usedRooms);
    }
    return maxRooms;
}

int main() {
    vector<vector<int>> intervals1 = {{0, 30}, {5, 10}, {15, 20}};
    cout << "Minimum number of conference rooms required: " << minMeetingRooms(intervals1) << endl;

    vector<vector<int>> intervals2 = {{7, 10}, {2, 4}};
    cout << "Minimum number of conference rooms required: " << minMeetingRooms(intervals2) << endl;

    return 0;
}