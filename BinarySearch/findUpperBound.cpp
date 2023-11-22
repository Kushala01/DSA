#include <bits/stdc++.h>
using namespace std;

int findUpperBound(const vector<int>& numbers, int value) {
    auto it = upper_bound(numbers.begin(), numbers.end(), value); 
    return distance(numbers.begin(), it); 
}

int main() {
    int numElements; 
    cin >> numElements; 
    vector<int> numbers(numElements); 
    for (int i = 0; i < numElements; ++i) {
        cin >> numbers[i]; 
    }
    sort(numbers.begin(), numbers.end()); 
    int upperBoundIndex = findUpperBound(numbers, 35); 
    int upperBoundValue = numbers[upperBoundIndex]; 
    cout << "Upper Bound Index: " << upperBoundIndex << '\n';
    cout << "Upper Bound Value: " << upperBoundValue << '\n';
    return 0; 
}
