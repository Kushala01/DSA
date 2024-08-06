#include <bits/stdc++.h>
using namespace std;

int findContentChildren(vector<int>& greed, vector<int>& cookieSize) {
    int n = greed.size();
    int m = cookieSize.size();

    sort(greed.begin(), greed.end());
    sort(cookieSize.begin(), cookieSize.end());

    int l = 0;
    int r = 0;

    while (l < m && r < n) {
        if (greed[r] <= cookieSize[l]) {
            r++;
        }
        l++;
    }
    return r;
}

int main() {
    vector<int> greed = {1, 5, 3, 3, 4};
    vector<int> cookieSize = {4, 2, 1, 2, 1, 3};

    int ans = findContentChildren(greed, cookieSize);
    
    cout << endl << "No. of kids assigned cookies " << ans << endl;
    return 0;
}//Time Complexity: O(N logN + M logM + M)
//Space Complexity: O(1)