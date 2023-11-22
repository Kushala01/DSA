#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll findMinCost(vector<ll> costs, ll n, ll x, ll y) {
    vector<ll> prefixSum(n + 1, 0);
    for (ll i = 1; i <= n; i++) {
        if (i - y >= 1) {
            prefixSum[i] = costs[i] + prefixSum[i - y];
        } else {
            prefixSum[i] = costs[i];
        }
    }
    ll minCost = LLONG_MAX;
    for (ll i = 1; i <= n; i++) {
        ll startIndex = i - (x - 1) * y;
        if (startIndex >= 1) {
            ll currentCost = prefixSum[i];
            if (startIndex - y >= 1) {
                currentCost -= prefixSum[startIndex - y];
            }
            minCost = min(currentCost, minCost);
        }
    }
    return minCost;
}

int main() {
    ll n;
    cin >> n;
    vector<ll> costs(n + 1, 0);
    for (ll i = 1; i <= n; i++) {
        cin >> costs[i];
    }
    ll x, y;
    cin >> x >> y;
    ll result = findMinCost(costs, n, x, y);
    cout << result << endl;
    return 0;
}
