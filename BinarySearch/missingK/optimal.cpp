#include <bits/stdc++.h>
using namespace std;

int missingK(vector<int> vec, int n, int k) {
    int low = 0, high = n - 1;
    int result = 0;
    while (low <= high) {
        int mid = (low + high) / 2;
        int missing = vec[mid] - (mid + 1);
        if (missing < k) {
            low = mid + 1;
        }
        else {
            result = mid;
            high = mid - 1;
        }
    }
    return k + result;
}

int main() {
    vector<int> vec = {4, 7, 9, 10};
    int n = 4, k = 4;
    int ans = missingK(vec, n, k);
    cout << "The missing number is: " << ans << "\n";
    return 0;
}
//Time Complexity: O(logN)
//Space Complexity: O(1)