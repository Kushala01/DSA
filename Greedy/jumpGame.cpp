#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int canReach(int A[], int N) {
        int maxReach = 0;
        for (int i = 0; i < N; i++) {
            if (i > maxReach) return 0; 
            maxReach = max(maxReach, i + A[i]);
            if (maxReach >= N - 1) return 1; 
        }return 0;
    }
};

int main() {
    Solution obj;
    int N1 = 6;
    int A1[] = {1, 2, 0, 3, 0, 0};
    cout << obj.canReach(A1, N1) << endl; 
    return 0;
}