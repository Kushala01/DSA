#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

typedef long long int ll;

// Function to read input
void getInput(vector<ll>& values, ll& n) {
    cin >> n;
    values.resize(n);
    for (ll i = 0; i < n; i++) {
        cin >> values[i];
    }
}

// Function to find the answer
ll findMaxSumDifference(const vector<ll>& values) {
    unordered_map<ll, ll> differenceSumMap;
    ll maxSum = 0;

    for (ll i = 0; i < values.size(); i++) {
        ll diff = values[i] - i;
        differenceSumMap[diff] += values[i];
        maxSum = max(maxSum, differenceSumMap[diff]);
    }

    return maxSum;
}

int main() {
    ll n;
    vector<ll> values;

    getInput(values, n);

    ll maxSum = findMaxSumDifference(values);

    cout << maxSum << endl;

    return 0;
}