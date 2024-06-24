#include<bits/stdc++.h>
using namespace std;

vector<int> RearrangebySign(vector<int> A, int n) {
    vector<int> pos;
    vector<int> neg;

    for(int i = 0; i < n; i++) {
        if(A[i] > 0) 
            pos.push_back(A[i]);
        else 
            neg.push_back(A[i]);
    }

    for(int i = 0; i < n / 2; i++) {
        A[2 * i] = pos[i];
        A[2 * i + 1] = neg[i];
    }

    return A;
}

int main() {
    int n = 4;
    vector<int> A {1, 2, -4, -5};

    vector<int> ans = RearrangebySign(A, n);
    
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    return 0;
}
/*Time Complexity: O(N+N/2) { O(N) for traversing the array once for segregating positives and negatives and another O(N/2)
 for adding those elements alternatively to the array, where N = size of the array A}.

Space Complexity:  O(N/2 + N/2) = O(N) { N/2 space required for each of the positive and negative element arrays,
 where N = size of the array A}.*/