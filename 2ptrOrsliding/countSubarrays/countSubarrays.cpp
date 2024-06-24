#include <iostream>
using namespace std;

int countSubarrays(int arr[], size_t n, int k) {
    int start = 0, end = 0, count = 0, sum = 0;

    while (start < n && end < n) {
        if (sum < k) {
            end++;
            if (end >= start)
                count += end - start;
            if (end < n)
                sum += arr[end];
        } else {
            sum -= arr[start];
            start++;
        }
    }

    return count;
}

int main() {
    int array[] = {1, 11, 2, 3, 15};
    size_t size = sizeof(array) / sizeof(array[0]);
    int k = 10;
    cout << countSubarrays(array, size, k);
    return 0;
}