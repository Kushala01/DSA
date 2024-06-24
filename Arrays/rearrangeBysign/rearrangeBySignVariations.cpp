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

    int posSize = pos.size();
    int negSize = neg.size();
    int index = 0;

    if(posSize < negSize) {
        for(int i = 0; i < posSize; i++) {
            A[2 * i] = pos[i];
            A[2 * i + 1] = neg[i];
        }
        index = posSize * 2;
        for(int i = posSize; i < negSize; i++) {
            A[index] = neg[i];
            index++;
        }
    } else {
        for(int i = 0; i < negSize; i++) {
            A[2 * i] = pos[i];
            A[2 * i + 1] = neg[i];
        }
        index = negSize * 2;
        for(int i = negSize; i < posSize; i++) {
            A[index] = pos[i];
            index++;
        }
    }
    return A;
}

int main() {
    int n = 6;
    vector<int> A {1, 2, -4, -5, 3, 4};

    vector<int> ans = RearrangebySign(A, n);
    
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }

    return 0;
}

/*Time Complexity: O(2*N) { The worst case complexity is O(2*N) which is a combination of O(N) of traversing the array
 to segregate into neg and pos array and O(N) for adding the elements alternatively to the main array}.

Explanation: The second O(N) is a combination of O(min(pos, neg)) + O(leftover elements). There can be two cases: 
when only positive or only negative elements are present, O(min(pos, neg)) + O(leftover) = O(0) + O(N), 
and when equal no. of positive and negative elements are present, O(min(pos, neg)) + O(leftover) = O(N/2) + O(0). 
So, from these two cases, we can say the worst-case time complexity is O(N) for the second part, and by adding the 
first part we get the total complexity of O(2*N).

Space Complexity:  O(N/2 + N/2) = O(N) { N/2 space required for each of the positive and negative element arrays, 
where N = size of the array A}.*/