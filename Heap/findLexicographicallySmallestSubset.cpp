#include<bits/stdc++.h>
using namespace std;

// Comparator for the priority queue to ensure lexicographical order
struct Compare {
    bool operator()(pair<int, int> const& a, pair<int, int> const& b) {
        if (a.first == b.first) {
            return a.second > b.second; // If values are equal, compare based on indices
        }
        return a.first > b.first; // Compare based on values
    }
};

// Function to find the lexicographically smallest k-length subset
vector<int> findLexicographicallySmallestSubset(vector<int>& b, int k) {
    int n = b.size(); // size of array b

    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> minHeap; // Min-heap to store pairs (value, index)

    // Push the first n - k + 1 elements into the priority queue
    for (int i = 0; i < n - k + 1; i++) {
        minHeap.push({b[i], i});
    }

    vector<int> result; // Result vector to store the lexicographically smallest subset
    int nextIndex = n - k + 1; // Index to push the next element from the array
    int previousIndex = -1; // Keep track of the last chosen index

    // Iterate to select k elements
    for (int i = 0; i < k; i++) {
        while (!minHeap.empty()) {
            pair<int, int> current = minHeap.top();

            // If the current element index is valid for selection
            if (current.second > previousIndex && current.second >= i) {
                result.push_back(current.first); // Add the value to the result
                minHeap.pop(); // Remove the element from the heap
                previousIndex = current.second; // Update the previous index
                break;
            } else {
                minHeap.pop(); // Remove invalid elements
            }
        }

        // Push the next element from the array into the heap if within bounds
        if (nextIndex < n) {
            minHeap.push({b[nextIndex], nextIndex});
            nextIndex++;
        }
    }

    return result;
}

int main() {
    int n; // Size of array b
    cin >> n;

    vector<int> b(n); // Array b
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    int k; // Value of k
    cin >> k;

    // Find the lexicographically smallest k-length subset
    vector<int> result = findLexicographicallySmallestSubset(b, k);

    // Output the result
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}