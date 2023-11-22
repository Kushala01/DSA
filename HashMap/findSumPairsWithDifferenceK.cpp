#include <iostream>
#include <unordered_map>
using namespace std;

typedef long long int ll;

void getInput(ll& n, ll& k, vector<ll>& values) {
    cin >> n;
    cin >> k;
    values.resize(n);
    for (ll i = 0; i < n; i++) {
        cin >> values[i];
    }
}

ll findSumPairsWithDifferenceK(const ll n, const ll k, const vector<ll>& values) {
    unordered_map<ll, ll> valueCount;
    ll sum = 0;

    for (ll i = 0; i < n; i++) {
        ll currentMod = values[i] % k;
        ll requiredMod = (k - currentMod) % k;
        sum += valueCount[requiredMod];
        valueCount[currentMod]++;
    }
    return sum;
}

int main() {
    ll n, k;
    vector<ll> values;
    getInput(n, k, values);
    ll sum = findSumPairsWithDifferenceK(n, k, values);
    cout << sum << endl;
    return 0;
}
