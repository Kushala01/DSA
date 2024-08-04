#include<bits/stdc++.h>
using namespace std;

vector<pair<int, int>> initializeAndSortPairs(const vector<int>& b, const vector<int>& g) {
    int n = b.size();
    vector<pair<int, int>> pairs(n);
    for (int i = 0; i < n; i++) {
        pairs[i] = {g[i], b[i]};
    }
    sort(pairs.begin(), pairs.end());
    return pairs;
}

int findMaxScore(const vector<int>& b, const vector<int>& g, int k) {
    vector<pair<int, int>> sortedPairs = initializeAndSortPairs(b, g);
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int sumOfSelected = 0;
    int maxScore = 0;

    for (int i = sortedPairs.size() - 1; i >= 0; i--) {
        int currentG = sortedPairs[i].first;
        int currentB = sortedPairs[i].second;

        minHeap.push(currentB);
        sumOfSelected += currentB;

        if (minHeap.size() > k) {
            sumOfSelected -= minHeap.top();
            minHeap.pop();
        }

        if (minHeap.size() == k) {
            int currentScore = sumOfSelected * currentG;
            maxScore = max(maxScore, currentScore);
        }
    }
    return maxScore;
}

int main() {
    vector<int> b = {1, 3, 3, 2};
    vector<int> g = {2, 1, 3, 4};
    int k = 3;
    
    int maxScore = findMaxScore(b, g, k);
    cout << "The maximum score is: " << maxScore << endl;

    return 0;
}
/*time complexity:
-sorting: o(n log n)
-priority queue operations with in the queue: o(n log k)
therefore total time complexity=sum= o(n log n)

space complexity:o(n+k)*/