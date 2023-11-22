#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

bool areEquivalentStrings(string str1, string str2) {
    unordered_map<char, ll> evenCount1, oddCount1, evenCount2, oddCount2;

    for (ll i = 0; i < str1.size(); i++) {
        char ch = str1[i];
        if (i % 2 == 0) {
            evenCount1[ch]++;
        } else {
            oddCount1[ch]++;
        }
    }

    for (ll i = 0; i < str2.size(); i++) {
        char ch = str2[i];
        if (i % 2 == 0) {
            evenCount2[ch]++;
        } else {
            oddCount2[ch]++;
        }
    }
    return (oddCount1 == oddCount2) && (evenCount1 == evenCount2);
}

int main() {
    ll n;
    cin >> n;
    vector<string> strings1, strings2;
    for (ll i = 0; i < n; i++) {
        string s;
        cin >> s;
        strings1.push_back(s);
    }
    cin >> n;
    for (ll i = 0; i < n; i++) {
        string s;
        cin >> s;
        strings2.push_back(s);
    }
    for (ll i = 0; i < n; i++) {
        if (areEquivalentStrings(strings1[i], strings2[i])) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}
