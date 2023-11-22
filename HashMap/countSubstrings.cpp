#include <iostream>
#include <vector>
using namespace std;

// Function to count the substrings that start and end with the same character.
int countSubstrings(const vector<vector<int>>& prefixSum, int start, int end) {
    int count = 0;
    for (int charIndex = 0; charIndex < 26; charIndex++) {
        int occurrences = prefixSum[end][charIndex] - prefixSum[start - 1][charIndex];
        count += occurrences * (occurrences + 1) / 2;
    }
    return count;
}

int main() {
    string str;
    cin >> str;
    int length = str.length();

    int queriesCount;
    cin >> queriesCount;

    vector<vector<int>> prefixSum(length + 1, vector<int>(26, 0));

    // Building prefix sum array
    for (int i = 0; i < length; i++) {
        int currentCharIndex = str[i] - 'a';
        for (int j = 0; j < 26; j++) {
            prefixSum[i + 1][j] = prefixSum[i][j] + (currentCharIndex == j);
        }
    }

    // Processing each query
    for (int i = 0; i < queriesCount; i++) {
        int leftIndex, rightIndex;
        cin >> leftIndex >> rightIndex;
        
        // Calculating and printing the result for the current query
        cout << countSubstrings(prefixSum, leftIndex, rightIndex) << endl;
    }

    return 0;
}
