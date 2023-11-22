
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main() {
    int n;
    cin >> n;
    int arr[n + 1];
    int i = 1;
    while (i <= n) {
        cin >> arr[i];
        i++;
    }
    unordered_map<ll, ll> frequencyMap; 
    int count = 0;
    i = 1;
    while (i <= n) {
        int currentElement = arr[i];
        int rightElement = arr[arr[arr[i]]];
        int previousOccurrences = frequencyMap[rightElement]; 
        count += previousOccurrences; 
        int leftElement = arr[arr[arr[i]]];
        frequencyMap[leftElement]++; 
        i++;
    }
    cout << count;
    return 0;
}
