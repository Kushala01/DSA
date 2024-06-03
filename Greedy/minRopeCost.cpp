#include <iostream>
#include <queue>
using namespace std;

long long minCost(long long arr[], long long n) {
    if (n == 0) return 0;

    priority_queue<long long, vector<long long>, greater<long long>> pq(arr, arr + n);

    long long total_cost = 0;

    // Merge ropes until there's only one rope left
    while (pq.size() > 1) {
        long long first = pq.top();
        pq.pop();
        long long second = pq.top();
        pq.pop();
        long long new_rope = first + second;
        total_cost += new_rope;
        pq.push(new_rope);
    }

    return total_cost;
}

int main() {
    long long arr1[] = {4, 3, 2, 6};
    long long n1 = sizeof(arr1) / sizeof(arr1[0]);
    cout << minCost(arr1, n1) << endl;  // Output: 29

    long long arr2[] = {4, 2, 7, 6, 9};
    long long n2 = sizeof(arr2) / sizeof(arr2[0]);
    cout << minCost(arr2, n2) << endl;  // Output: 62

    return 0;
}