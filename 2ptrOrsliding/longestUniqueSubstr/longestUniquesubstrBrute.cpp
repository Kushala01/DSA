#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstringWithoutRepeatingCharacters(string input) {
    if(input.empty())
        return 0;

    int maxLength = INT_MIN;
    for (int start = 0; start < input.length(); start++) { // Outer loop for traversing the string
        unordered_set<char> uniqueCharacters; // Set to track unique characters in the current substring
        for (int end = start; end < input.length(); end++) { // Nested loop for different substrings starting with input[start]
            if (uniqueCharacters.find(input[end]) != uniqueCharacters.end()) { // If character is already in the set, update maxLength and break
                maxLength = max(maxLength, end - start);
                break;
            }
            uniqueCharacters.insert(input[end]); // Add current character to the set
        }
    }
    return maxLength;
}

int main() {
    string input = "takeUforward";
    cout << "The length of the longest substring without repeating characters is " << 
    lengthOfLongestSubstringWithoutRepeatingCharacters(input);
    return 0;
}
//Time Complexity: O( N2 )
//Space Complexity: O(N) where N is the size of HashSet taken for storing the elemen