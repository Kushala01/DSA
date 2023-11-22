#include <bits/stdc++.h>
using namespace std;

int findMinMemorySum(const vector<long long>& v, int m) {
    int i = 0, j = 0;
    int currSum = 0, maxSum = 0;
    //int totalSum = accumulate(v.begin(), v.end(), 0);
    int totalSum = 0;
    for (int i = 0; i < v.size(); i++) {
        totalSum += v[i];
    }

    while (j < v.size()) {
        currSum += v[j];
        if (j - i + 1 == m) {
            maxSum = max(maxSum, currSum);
            currSum -= v[i];
            i++;
        }
        j++;
    }

    return totalSum - maxSum;
}

int main() {
    vector<long long> v{10, 4, 8, 13, 20};
    int m = 2;

    int result = findMinMemorySum(v, m);
    cout << result << endl;

    return 0;
}
