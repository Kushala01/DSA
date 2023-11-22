#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int countOccurrences(int arr[], int n) {
    unordered_map<ll, ll> frequencyMap;
    int count = 0;
    for (int i = 1; i <= n; i++) {
        int currentElement = arr[i];
        int rightElement = arr[arr[arr[i]];
        int previousOccurrences = frequencyMap[rightElement];
        count += previousOccurrences;
        int leftElement = arr[arr[arr[i]];
        frequencyMap[leftElement]++;
    }
    return count;
}

int main() {
    int n;
    cin >> n;
    int arr[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    int result = countOccurrences(arr, n);

    cout << result;
    return 0;
}
