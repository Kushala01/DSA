#include <bits/stdc++.h>
using namespace std;

int countPairs(vector<int>&a, int n) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > 2 * a[j]) cnt++;
        }
    }
    return cnt;
}

int team(vector <int> & skill, int n) {
    return countPairs(skill, n);
}

int main()
{
    vector<int> a = {4, 1, 2, 3, 1};
    int n = 5;
    int cnt = team(a, n);
    cout << "The number of reverse pair is: "
         << cnt << endl;
    return 0;
}
//Time Complexity: O(N2)
//Space Complexity: O(1)