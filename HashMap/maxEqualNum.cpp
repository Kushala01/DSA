#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main() {
    ll n;
    cin >> n;
    ll elements[n + 1];
    ll k;
    cin >> k;
    for (ll i = 1; i <= n; i++) {
        cin >> elements[i];
    }
    ll frequencyChange[200005] = {0};
    // Calculate frequency changes
    for (ll i = 1; i <= n; i++) {
        ll left = elements[i] - k;
        ll right = elements[i] + k;
        frequencyChange[left] = frequencyChange[left] + 1;
        frequencyChange[right + 1] = frequencyChange[right + 1] - 1;
    }
    ll maxFrequency = 1;
    // Calculate prefix sum
    for (ll i = 1; i <= 200000; i++) {
        frequencyChange[i] = frequencyChange[i - 1] + frequencyChange[i];
        maxFrequency = max(frequencyChange[i], maxFrequency);
    }
    cout << maxFrequency;
    return 0;
}
