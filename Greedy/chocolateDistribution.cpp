#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long findMinDiff(vector<long long>& a, long long n, long long m) {
    if (m == 0 || n == 0) return 0;
    sort(a.begin(), a.end());
    if (n < m) return -1;
    
    long long min_diff = LLONG_MAX;
    
    for (long long i = 0; i + m - 1 < n; i++) {
        long long diff = a[i + m - 1] - a[i];
        min_diff = min(min_diff, diff);
    }
    return min_diff;
}

int main() {
    vector<long long> A = {3, 4, 1, 9, 56, 7, 9, 12};
    long long N = A.size();
    long long M = 5;
    cout << findMinDiff(A, N, M) << endl;
    return 0;
}