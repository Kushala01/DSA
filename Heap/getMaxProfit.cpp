#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll getMaxProfit(vector<ll>& elems, ll n, ll k) {
    vector<ll> pSum(n + 1, 0);
    for (ll i = 1; i <= n; ++i) {
        pSum[i] = pSum[i - 1] + elems[i];
    }

    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> minHeap;
    minHeap.push({0, 0});

    ll maxP = 0;

    for (ll idx = 1; idx <= n; ++idx) {
        ll r = idx - 1;
        ll l = max(idx - k, 0LL);
        bool found = false;

        ll minV = 1e18;
        while (!minHeap.empty() && !found) {
            ll sum, pos;
            tie(sum, pos) = minHeap.top();

            if (pos >= l && pos <= r) {
                minV = min(minV, sum);
                found = true;
            } else {
                minHeap.pop();
            }
        }

        if (minV != 1e18) {
            ll resV = pSum[idx] - minV;
            maxP = max(maxP, resV);
        }

        minHeap.push({pSum[idx], idx});
    }

    return maxP;
}

int main() {
    ll n, k;
    cin >> n >> k;

    vector<ll> elems(n + 1, 0);
    for (ll i = 1; i <= n; ++i) {
        cin >> elems[i];
    }

    ll res = getMaxProfit(elems, n, k);
    cout << res << endl;

    return 0;
}
