#include <bits/stdc++.h>
using namespace std;
int countSum(int a[], int n, int sum)
{
    int i, j, k;
    int count = 0;
    unordered_map<int, int> m;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            int temp = a[i] + a[j];
            if (temp < sum)
                count += m[sum - temp];
        }
        for (j = 0; j < i; j++) {
            int temp = a[i] + a[j];
            if (temp < sum)
                m[temp]++;
        }
    }
    return count;
}
int main()
{
    int arr[] = { 4, 5, 3, 1, 2, 4 };
    int S = 13;
    int N = sizeof(arr) / sizeof(arr[0]);
    cout << countSum(arr, N, S);
    return 0;
}
