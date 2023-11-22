#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

ll calculateCount(const vector<ll>& numbers) {
    map<pair<ll,ll>, ll> frequencyMap;  
    ll totalCount = 0;
    ll runningSum = 0;

    for (ll num : numbers) {
        runningSum += num;

        ll previousSum = runningSum - num;
        ll targetSum = previousSum - num;

        totalCount += frequencyMap[{num, targetSum}];
        frequencyMap[{num, runningSum}]++;
    }

    return totalCount;
}

int main() {
    ll n;
    cin >> n;
    vector<ll> numbers(n);

    for (ll& num : numbers) {
        cin >> num;
    }

    cout << calculateCount(numbers) << endl;

    return 0;
}
