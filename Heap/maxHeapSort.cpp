#include <bits/stdc++.h>
using namespace std;

void maxHeapify(vector<int>& arr, int n, int i) {
    int largest = i; // Initialize largest as root
    int left = 2 * i + 1; // left child
    int right = 2 * i + 2; // right child

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]); // Swap root and largest
        maxHeapify(arr, n, largest); // Recursively heapify the affected sub-tree
    }
}

// Function to perform heap sort
void heapSortMax(vector<int>& arr) {
    int n = arr.size();

    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        maxHeapify(arr, n, i);

    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]); // Move current root to end
        maxHeapify(arr, i, 0); // call maxHeapify on the reduced heap
    }
}

// Helper function to print an array
void printArray(const vector<int>& arr) {
    for (int i : arr)
        cout << i << " ";
    cout << endl;
}

int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7};
    heapSortMax(arr);
    cout << "Sorted array (Max Heap Sort) is \n";
    printArray(arr);
    return 0;
}