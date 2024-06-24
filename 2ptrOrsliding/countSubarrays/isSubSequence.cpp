#include <bits/stdc++.h>
using namespace std;

bool isSubSequence(std::string A, std::string B) {
    int i = 0, j = 0;
    while (i < A.length() && j < B.length()) {
        if (A[i] == B[j]) i++;
            j++;
        }return (i == A.length());
    }

int main() {
    string s1,s2;
    cin>>s1>>s2;
    cout<<isSubSequence(s1,s2)<<endl;
}
/*Input:
A = AXY 
B = YADXCP
Output: 0 
Explanation: A is not a subsequence of B
as 'Y' appears before 'A'.*/