#include <bits/stdc++.h>
using namespace std;

void minHeapify(vector<int>& arr, int n, int i) {
    int smallest = i; // Initialize smallest as root
    int left = 2 * i + 1; // left child
    int right = 2 * i + 2; // right child

    // If left child is smaller than root
    if (left < n && arr[left] < arr[smallest])
        smallest = left;

    // If right child is smaller than smallest so far
    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    // If smallest is not root
    if (smallest != i) {
        swap(arr[i], arr[smallest]); // Swap root and smallest
        minHeapify(arr, n, smallest); // Recursively heapify the affected sub-tree
    }
}

void heapSortMin(vector<int>& arr) {
    int n = arr.size();

    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        minHeapify(arr, n, i);

    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]); // Move current root to end
        minHeapify(arr, i, 0); // call minHeapify on the reduced heap
    }
}

void printArray(const vector<int>& arr) {
    for (int i : arr)
        cout << i << " ";
    cout << endl;
}

int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7};
    heapSortMin(arr);
    cout << "Sorted array (Min Heap Sort) is \n";
    printArray(arr);
    return 0;
}