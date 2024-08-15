#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> insertNewInterval(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res; 
        int i = 0; 
        int n = intervals.size(); 
        
        while(i < n && intervals[i][1] < newInterval[0]){
            res.push_back(intervals[i]); 
            i = i + 1; 
        }
        
        while(i < n && intervals[i][0] <= newInterval[1]){
            newInterval[0] = min(newInterval[0], intervals[i][0]); 
            newInterval[1] = max(newInterval[1], intervals[i][1]); 
            i = i + 1; 
        }
        
        res.push_back(newInterval); 
        
        while(i < n){
            res.push_back(intervals[i]); 
            i = i + 1; 
        }
        return res; 
    }
};

int main() {
    vector<vector<int>> intervals = {{1, 2}, {3, 4}, {6, 7}, {8, 10}, {12, 16}};
    cout << "Intervals Array: ";
    for(auto interval: intervals){
        cout << "[" << interval[0] << ", "<< interval[1]<< "], ";
    }
    cout << endl;
    
    vector<int> newInterval = {5, 8};
    cout << "New Interval to be Inserted: ";
    cout << "[" << newInterval[0] << ", "<< newInterval[1]<< "]" << endl;
    
    Solution sol;
    vector<vector<int>> result = sol.insertNewInterval(intervals, newInterval);
    for(auto interval: result){
        cout << "[" << interval[0] << ", "<< interval[1]<< "], ";
    }
    cout << endl;
    
    return 0;
}//Time Complexity: O(N)
//Space Complexity: O(N)