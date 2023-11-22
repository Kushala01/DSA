#include <iostream>
using namespace std;

int countAndCheckIncreasing(int arr[], int n, int k) {
    int count = 0;
    for (int i = 1; i <= n - k + 1; i++) {
        int start = i;
        int end = i + k - 1;
        bool check = true;
        while (start < end) {
            if (arr[start] >= arr[start + 1]) {
                check = false;
                break;
            }start++;
        }if (check)  count++;
    }return count;
}

int main() {
    int n;
    cin >> n;
    int b[n + 1] = {0};
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }int k;
    cin >> k;
    int result = countAndCheckIncreasing(b, n, k);
    cout << result;
    return 0;
}
