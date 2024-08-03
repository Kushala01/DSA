#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int kthSmallest(int arr[], int l, int r, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap(arr + l, arr + r + 1);

        for (int i = 1; i < k; ++i) {
            minHeap.pop();
        }

        return minHeap.top();
    }
};

int main() {
    Solution sol;
    int n = 6;
    int arr[] = {7, 10, 4, 3, 20, 15};
    int k = 3;
    int l = 0;
    int r = 5;
    
    cout << "Kth smallest element is: " << sol.kthSmallest(arr, l, r, k) << endl;

    return 0;
}