#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void demonstrateMaxHeap() {
    priority_queue<int> maxHeap;

    maxHeap.push(3);
    maxHeap.push(5);
    maxHeap.push(1);
    maxHeap.push(4);

    cout << "Max-Heap elements in priority order:\n";
    while (!maxHeap.empty()) {
        cout << maxHeap.top() << " "; // Print the largest element
        maxHeap.pop(); // Remove the largest element
    }
    cout << endl;
}

void demonstrateMinHeap() {
    priority_queue<int, vector<int>, greater<int>> minHeap;

    minHeap.push(3);
    minHeap.push(5);
    minHeap.push(1);
    minHeap.push(4);

    cout << "Min-Heap elements in priority order:\n";
    while (!minHeap.empty()) {
        cout << minHeap.top() << " "; // Print the smallest element
        minHeap.pop(); // Remove the smallest element
    }
    cout << endl;
}

int main() {
    cout << "Demonstrating Max-Heap:\n";
    demonstrateMaxHeap();

    cout << "\nDemonstrating Min-Heap:\n";
    demonstrateMinHeap();

    return 0;
}