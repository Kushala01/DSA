#include <bits/stdc++.h>
using namespace std;

int numberOfGasStationsRequired(long double dist, vector<int> &arr) {
    int n = arr.size();
    int cnt = 0;
    for (int i = 1; i < n; i++) {
        int numberInBetween = ((arr[i] - arr[i - 1]) / dist);
        if ((arr[i] - arr[i - 1]) == (dist * numberInBetween)) {
            numberInBetween--;
        }
        cnt += numberInBetween;
    }
    return cnt;
}

long double minimiseMaxDistance(vector<int> &arr, int k) {
    int n = arr.size();
    long double low = 0;
    long double high = 0;

    for (int i = 0; i < n - 1; i++) {
        high = max(high, (long double)(arr[i + 1] - arr[i]));
    }

    long double diff = 1e-6;
    long double result = high;
    while (high - low > diff) {
        long double mid = (low + high) / 2.0;
        int cnt = numberOfGasStationsRequired(mid, arr);
        if (cnt > k) {
            low = mid;
        } else {
            high = mid;
            result = mid;
        }
    }
    return result;
}
//high = mid-1: Similarly, We have used this operation to eliminate the right half. 
//But if we apply the same here, we might ignore several decimal numbers and possibly the actual answer.
//So, we will use this: high = mid.

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 4;
    long double ans = minimiseMaxDistance(arr, k);
    cout << "The answer is: " << ans << "\n";
    return 0;
}
//Time Complexity: O(n*log(Len)) + O(n)
//Space Complexity: O(1) 