#include <bits/stdc++.h>
using namespace std;

bool canWePlace(vector<int> &stalls, int dist, int cows) {
    int n = stalls.size(); 
    int cntCows = 1; 
    int last = stalls[0]; 
    for (int i = 1; i < n; i++) {
        if (stalls[i] - last >= dist) {
            cntCows++;
            last = stalls[i];
        }
        if (cntCows >= cows) return true;
    }
    return false;
}
int aggressiveCows(vector<int> &stalls, int k) {
    int n = stalls.size();
    sort(stalls.begin(), stalls.end());
    int low = stalls[0], high = stalls[n - 1] - stalls[0];
    int result = high;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (canWePlace(stalls, mid, k) == true) {
            result= mid;
            low = mid + 1;
        }
        else high = mid - 1;
    }
    return result;
}

int main(){
    vector<int> stalls = {0, 3, 4, 7, 10, 9};
    int k = 4;
    int ans = aggressiveCows(stalls, k);
    cout << "The maximum possible minimum distance is: " << ans << "\n";
    return 0;
}
//Time Complexity: O(NlogN) + O(N * log(max(stalls[])-min(stalls[])))
//Space Complexity: O(1)