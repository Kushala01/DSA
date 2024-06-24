#include <bits/stdc++.h>
using namespace std;

int longestIncreasingSubsequence(vector<int>& nums) {
    vector<int> dp;

    for (int num : nums) {
        auto it = lower_bound(dp.begin(), dp.end(), num);
        if (it == dp.end()) {
            dp.push_back(num);
        } else {
            *it = num;
        }
    }

    return dp.size();
}

int main() {
    vector<int> arr = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << "The length of the longest increasing subsequence is " << longestIncreasingSubsequence(arr) << endl;
    return 0;
}
