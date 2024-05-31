#include <iostream>
#include <unordered_map>
using namespace std;

int longestSubstringWithKDistinctCharacters(string s, int k) {
    int start = 0, end = 0;
    unordered_map<char, int> charFrequency;
    int maxLength = -1;

    while (end < s.size()) {
        charFrequency[s[end]]++;

        if (charFrequency.size() < k) {
            end++;
        } else if (charFrequency.size() == k) {
            maxLength = max(maxLength, end - start + 1);
            end++;
        } else {
            while (charFrequency.size() > k) {
                charFrequency[s[start]]--;
                if (charFrequency[s[start]] == 0) {
                    charFrequency.erase(s[start]);
                }
                start++;
            }
            end++;
        }
    }
    return maxLength;
}

int main() {
    string input = "araaci";
    int k = 2;
    cout << "The length of the longest substring with " << k << " distinct characters is " 
         << longestSubstringWithKDistinctCharacters(input, k);
    return 0;
}