#include <bits/stdc++.h>

using namespace std;
typedef int Integer; // Change data type to int

int countPairsWithSum(map<pair<int, int>, int>& pairCountMap, int numberOfElements) {
    int pairCount = 0;
    int currentIndex = 1;
    int currentSum = 0;

    while (currentIndex <= numberOfElements) {
        int currentNumber;
        cin >> currentNumber;
        currentSum = currentSum + currentNumber;

        int previousSum = currentSum - currentNumber;
        int targetValue = previousSum - currentNumber;
        pairCount = pairCount + pairCountMap[{currentNumber, targetValue}];

        pairCountMap[{currentNumber, currentSum}]++;

        currentIndex++;
    }

    return pairCount;
}

int main() {
    int numberOfElements;
    cin >> numberOfElements;
    map<pair<int, int>, int> pairCountMap;
    
    int count = countPairsWithSum(pairCountMap, numberOfElements);
    
    cout << count;

    return 0;
}