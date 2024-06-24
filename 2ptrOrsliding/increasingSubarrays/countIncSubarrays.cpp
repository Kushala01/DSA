#include <iostream>
using namespace std;

int countIncSubarrays(int arr[], int n, int k) {
    int count = 0;
    int consecInc = 0;

    for (int i = 2; i <= n; i++) {
        if (arr[i] > arr[i - 1]) {
            consecInc++;
        } else {
            consecInc = 0;
        }int curLength = consecInc + 1;
        int reqLength = k;
        if (curLength >= reqLength && reqLength >= 2) {
            count += abs(curLength - reqLength) + 1;
        }
    }return count;
}

int main() {
    int n;
    cin >> n;
    int arr[n + 1] = {0};
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    int k;
    cin >> k;
    int result = countIncSubarrays(arr, n, k);
    if (k == 1) cout << n;
     else cout << result;
    return 0;
}