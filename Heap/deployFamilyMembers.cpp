#include<bits/stdc++.h>
using namespace std;

void initializePriorityQueue(priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> &pq, const vector<int> &policemen) {
    for (int i = 0; i < policemen.size(); i++) {
        pq.push({0, policemen[i]});
    }
}

int deployFamilyMembers(priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> &pq, map<int, int> &usedPositions, int totalMembers) {
    int totalDistance = 0;
    int deployedCount = 1;

    while (deployedCount <= totalMembers) {
        auto top = pq.top();
        pq.pop();
        int distance = top.first;
        int position = top.second;

        if (usedPositions[position] == 0) {
            totalDistance += distance;
            cout << "Distance: " << distance << ", Position: " << position << endl;

            if (usedPositions[position + 1] == 0) {
                pq.push({distance + 1, position + 1});
            }

            if (usedPositions[position - 1] == 0) {
                pq.push({distance + 1, position - 1});
            }

            deployedCount++;
            usedPositions[position] = 1;
        }
    }

    return totalDistance;
}

int main() {
    int numPolicemen = 2;
    int numFamilyMembers = 4;
    vector<int> policemenPositions = {7, 8};

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    map<int, int> usedPositions;

    initializePriorityQueue(pq, policemenPositions);

    int result = deployFamilyMembers(pq, usedPositions, numFamilyMembers + numPolicemen);

    cout << "Total minimum distance: " << result << endl;

    return 0;
}