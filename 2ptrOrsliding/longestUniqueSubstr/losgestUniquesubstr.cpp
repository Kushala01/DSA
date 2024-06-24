#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> lastIndex(256, -1); // Vector to store the last index of each character

        int start = 0, end = 0;
        int n = s.size();
        int maxLength = 0;

        while (end < n) {
            // If the character at 'end' has been seen before and is within the current window
            if (lastIndex[s[end]] != -1)
                start = max(lastIndex[s[end]] + 1, start); // Move 'start' to the right of the previous occurrence

            lastIndex[s[end]] = end; // Update the last index of the current character

            maxLength = max(maxLength, end - start + 1); // Update the maximum length of the substring
            end++;
        }
        return maxLength;
    }
};

int main() {
    string str = "takeUforward";
    Solution obj;
    cout << "The length of the longest substring without repeating characters is " 
         << obj.lengthOfLongestSubstring(str);
    return 0;
}
//Time Complexity: O( N )
//Space Complexity: O(N) where N represents the size of HashSet where we are storing our elements