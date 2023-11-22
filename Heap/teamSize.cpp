#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> values = {17, 12, 10, 2, 7, 2, 11, 20};
    int selectCount = 4, teamSize = 3;

    priority_queue<int> frontQueue;
    priority_queue<int> backQueue;
    int frontIndex = 0, backIndex = values.size() - 1;

    for(int i = 0; i < selectCount; i++) {
        frontQueue.push(values[i]);
        frontIndex++;
    }

    while(selectCount-- && frontIndex <= backIndex) {
        backQueue.push(values[backIndex]);
        backIndex--;
    }
    backIndex++; // Adjustment for index after loop

    int totalValue = 0;
    while(teamSize--) {
        if(!frontQueue.empty() && !backQueue.empty()) {
            totalValue += max(frontQueue.top(), backQueue.top());

            if(backQueue.top() > frontQueue.top()) {
                backQueue.pop();

                if(frontIndex <= backIndex) {
                    backQueue.push(values[backIndex]);
                    backIndex--;
                }

            } else {
                frontQueue.pop();

                if(frontIndex <= backIndex) {
                    frontQueue.push(values[frontIndex]);
                    frontIndex++;
                }

            }

        } else if(!frontQueue.empty()) {
            totalValue += frontQueue.top();
            frontQueue.pop();

            if(frontIndex <= backIndex) {
                frontQueue.push(values[frontIndex]);
                frontIndex++;
            }

        } else if(!backQueue.empty()) {
            totalValue += backQueue.top();
            backQueue.pop();

            if(frontIndex <= backIndex) {
                backQueue.push(values[backIndex]);
                backIndex--;
            }

        }
    }

    cout << totalValue << endl; 
}
